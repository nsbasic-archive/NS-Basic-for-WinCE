// VNSBView.cpp : implementation of the CVNSBView class
//

#include "stdafx.h"
#include "VNSB.h"

#include "VNSBDoc.h"
#include "VNSBView.h"

#include "PropEditorDlg.h"
#include "SelectObjectDlg.h"
#include "CodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVNSBView

IMPLEMENT_DYNCREATE(CVNSBView, CView)

BEGIN_MESSAGE_MAP(CVNSBView, CView)
	//{{AFX_MSG_MAP(CVNSBView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PROPERTIES, OnUpdateEditProperties)
	ON_COMMAND(ID_EDIT_SELECT_OBJECT, OnEditSelectObject)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SELECT_OBJECT, OnUpdateEditSelectObject)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_COMMAND(ID_EDIT_PREFS, OnEditPrefs)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PREFS, OnUpdateEditPrefs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVNSBView construction/destruction

CVNSBView::CVNSBView()
{
   m_nGrid = 0;
} // CVNSBView

CVNSBView::~CVNSBView()
{
   for( int i = 0; i < m_aViewObjects.GetSize(); i++ )
      delete m_aViewObjects[i];
   m_aViewObjects.RemoveAll();
}

BOOL CVNSBView::PreCreateWindow( CREATESTRUCT& cs )
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow( cs );
}

/////////////////////////////////////////////////////////////////////////////
// CVNSBView drawing

void CVNSBView::OnDraw( CDC* pDC )
{
	CVNSBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
   m_nGrid = pDoc->m_nGrid;
   static BOOL bBreak;

   CRect rect;
   GetClientRect( rect );
   CBitmap bitPattern;
   bitPattern.LoadBitmap( IDB_BACKGROUND );
   CBrush pattern;
   BITMAP bits;
   bitPattern.GetBitmap( &bits );
#if 0 // _WIN32_WCE >= 211
   pattern.CreatePatternBrush( &bitPattern );
   pDC->FillRect( rect, &pattern );
#else
   CDC CompDC;
   CompDC.CreateCompatibleDC( pDC );
   CBitmap *pOldBits = CompDC.SelectObject( &bitPattern );
   for( int i = 0, j = 0; j < ( rect.bottom / abs( m_nGrid ) ); i++, j = i / ( rect.right / abs( m_nGrid ) ) )
      pDC->BitBlt( ( i % ( rect.right / abs( m_nGrid ) ) ) * abs( m_nGrid ) + ( abs( m_nGrid ) - bits.bmWidth ),
                   j * abs( m_nGrid ) + ( abs( m_nGrid ) - bits.bmWidth ), bits.bmWidth, bits.bmHeight,
                   &CompDC, 0, 0, SRCCOPY );
   CompDC.SelectObject( pOldBits );
   CompDC.DeleteDC();
#endif
} // OnDraw

/////////////////////////////////////////////////////////////////////////////
// CVNSBView diagnostics

#ifdef _DEBUG
void CVNSBView::AssertValid() const
{
	CView::AssertValid();
}

void CVNSBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVNSBDoc* CVNSBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVNSBDoc)));
	return (CVNSBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVNSBView message handlers

void CVNSBView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	AddViewObjects( TRUE );
} // OnInitialUpdate

void CVNSBView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
   CVNSBDoc *pDoc = GetDocument();
//   CString strMessage;
//   strMessage.Format( _T( "OnUpdate: %d %d %d" ), lHint, LOWORD( lHint ), HIWORD( lHint ) );
//   AfxMessageBox( strMessage );
   switch( LOWORD( lHint ) )
   {
   case HINT_SWITCH_FORM:
      Select();
      AddViewObjects( TRUE );
      break;
   case HINT_OBJECT_ADD:
      Select();
   case HINT_OBJECT_PASTE:
      AddViewObject( pDoc->m_pForm->m_aObjects[HIWORD( lHint )] );
      break;
   case HINT_OBJECT_DEL:
      break;
   }
} // OnUpdate

void CVNSBView::AddViewObject( CNSBFormObject *pFormOb )
{
//   CString strMessage;
//   strMessage.Format( _T( "AddViewObject: %s %s %d" ), pFormOb->m_strObjectName, pFormOb->m_strObjectType, pFormOb->m_nObjectID );
//   AfxMessageBox( strMessage );
   CNSBFormObjectView *pNewOb = new CNSBFormObjectView( pFormOb, this );
//   int nObNum = ( pViewOb->m_nObjectID - NSB_OBJECT_ID );
//   CRect rect = CRect( 10, 10 + nObNum * 35, 100, 30 + nObNum * 35 );
   m_aViewObjects.Add( pNewOb );
   Select( pNewOb, TRUE );
} // AddViewObject

void CVNSBView::Select( CNSBFormObjectView *pViewOb, BOOL bAdd )
{
   if( !bAdd && ( !pViewOb || !pViewOb->m_bSelected ) )
   {
      for( int i = 0; i < m_aSelection.GetSize(); i++ )
         m_aSelection[i]->Select( FALSE );
      m_aSelection.RemoveAll();
   }

   if( !pViewOb )
      return;

   if( !pViewOb->m_bSelected )
   {
      pViewOb->Select( TRUE );
      m_aSelection.Add( pViewOb );
   }
   else if( bAdd )
   {
      for( int i = 0; i < m_aSelection.GetSize(); i++ )
      {
         if( m_aSelection[i]->GetDlgCtrlID() == pViewOb->GetDlgCtrlID() )
         {
            m_aSelection.RemoveAt( i );
            break;
         }
      }
      pViewOb->Select( FALSE );
   }
} // Select

void CVNSBView::Select( CString &strObjectName, BOOL bAdd )
{
   CNSBForm *pForm = GetDocument()->m_pForm;
   INT nID = -1;
   for( int i = 0; i < m_aViewObjects.GetSize(); i++ )
      if( m_aViewObjects[i]->m_pFormOb->m_strObjectName == strObjectName )
      {
         Select( m_aViewObjects[i], bAdd );
         return;
      }
} // Select

void CVNSBView::FormObjectDrag( CPoint ptDelta, int nDragHandle )
{
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
      m_aSelection[i]->DoDrag( ptDelta, m_nGrid, nDragHandle );
} // FormObjectDrag

void CVNSBView::OnLButtonDown( UINT nFlags, CPoint point )
{
   Select( NULL );
   CView::OnLButtonDown( nFlags, point );
} // OnLButtonDown

void CVNSBView::OnLButtonDblClk( UINT nFlags, CPoint point )
{
   SelectionEditProperties();
   CView::OnLButtonDblClk( nFlags, point );
} // OnLButtonDblClk

void CVNSBView::SelectionChangeRect()
{
   CNSBForm *pForm = GetDocument()->m_pForm;

   // Iterate through the current selection, updating each bounding rectangle
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
   {
      CRect rect;
      m_aSelection[i]->GetWindowRect( rect );
      rect.DeflateRect( SELECT_INDENT, SELECT_INDENT );
      ScreenToClient( rect );
      m_aSelection[i]->m_pFormOb->SetRect( rect );
   }
} // SelectionChangeRect

void CVNSBView::SelectionEditProperties()
{
   CPropEditorDlg dlg;
	if( m_aSelection.GetSize() > 0 )
	   if( m_aSelection[0]->m_pFormOb->m_pComObDesc != NULL )
		   dlg.m_pComObDesc = m_aSelection[0]->m_pFormOb->m_pComObDesc;
   BOOL bNameCopy = TRUE;
   while( bNameCopy )
   {
      // Open dialog
      if( ( dlg.m_pView = GetSelectionView() ) != NULL )
         dlg.DoModal();

      // Check to see if object has a unique name
      if( m_aSelection.GetSize() == 1
          && !GetDocument()->UniqueObjectName( m_aSelection[0]->m_pFormOb->m_strObjectName ) )
      {
         MessageBox( _T( "Objects must have unique names" ), _T( "VNSB" ) );
         continue;
      }
      bNameCopy = FALSE;
   }

// TODO:  Add an else clause here, to notify user that multiple object selections cannot
//        edit properties, via a beep of some sort
} // SelectionEditProperties

void CVNSBView::OnEditProperties() 
{
   SelectionEditProperties();
} // OnEditProperties

void CVNSBView::OnUpdateEditProperties( CCmdUI* pCmdUI ) 
{
   CString strText1, strText2;
#ifdef _POCKET
   strText1.LoadString( IDS_EDIT_PROPERTIES_POCKET );
#else
   strText1.LoadString( IDS_EDIT_PROPERTIES );
#endif

   switch( m_aSelection.GetSize() )
   {
   case 0:
      pCmdUI->SetText( GetDocument()->m_pForm->m_strName + _T( " " ) + strText1 );
      break;
   case 1:
      m_aSelection[0]->GetWindowText( strText2 );
      pCmdUI->SetText( strText2 + _T( " " ) + strText1 );
      break;
   default:
      pCmdUI->SetText( strText1 );
      pCmdUI->Enable( FALSE );
      return;
   }
   pCmdUI->Enable();
} // OnUpdateEditProperties

void CVNSBView::SelectionFormObjects( CNSBFormObjectArray &arrFormObs )
{
   CNSBForm *pForm = GetDocument()->m_pForm;

   if( m_aSelection.GetSize() == 0 )
   {
      arrFormObs.Add( pForm->m_pOutput );
      return;
   }
   // Compile list of form objects from selected view objects
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
      arrFormObs.Add( m_aSelection[i]->m_pFormOb );
} // SelectionFormObjects

void CVNSBView::AddViewObjects( BOOL bDestroy )
{
   if( bDestroy )
   {
      for( int i = 0; i < m_aViewObjects.GetSize(); i++ )
         m_aViewObjects[i]->DestroyWindow();
      m_aViewObjects.RemoveAll();
   }
   CVNSBDoc *pDoc = (CVNSBDoc *)GetDocument();
   if( pDoc->m_pForm == NULL )
      return;
   for( int i = 0; i < pDoc->m_pForm->m_aObjects.GetSize(); i++ )
      if( pDoc->m_pForm->m_aObjects[i] )
         AddViewObject( pDoc->m_pForm->m_aObjects[i] );
   Select();
} // AddViewObjects

void CVNSBView::OnEditSelectObject() 
{
   CSelectObjectDlg dlg;

   CVNSBDoc *pDoc = (CVNSBDoc *)GetDocument();
   for( int i = 0; i < pDoc->m_pForm->m_aObjects.GetSize(); i++ )
      dlg.m_aObjectNames.Add( pDoc->m_pForm->m_aObjects[i]->m_strObjectName );

   if( dlg.DoModal() == IDOK )
   {
      Select();
      for( i = 0; i < dlg.m_aObjectNames.GetSize(); i++ )
         Select( dlg.m_aObjectNames[i], TRUE );
   }
} // OnEditSelectObject

void CVNSBView::OnUpdateEditSelectObject( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( m_aViewObjects.GetSize() > 0 );
} // OnUpdateEditSelectObject


// Clipboard
void CVNSBView::OnEditClear() 
{
   CNSBForm *pForm = GetDocument()->m_pForm;
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
   {
      pForm->DeleteFormObject( m_aSelection[i]->m_pFormOb );
      m_aSelection[i]->m_pFormOb = NULL;
      for( int j = 0; j < m_aViewObjects.GetSize(); j++ )
         if( m_aViewObjects[j] == m_aSelection[i] )
         {
            m_aViewObjects.RemoveAt( j );
            break;
         }
      m_aSelection[i]->DestroyWindow();
      delete m_aSelection[i];
      GetDocument()->SetModifiedFlag();
   }
   m_aSelection.RemoveAll();
} // OnEditClear

void CVNSBView::OnUpdateEditClear( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( m_aSelection.GetSize() > 0 );
} // OnUpdateEditClear

void CVNSBView::OnEditCopy()
{
   m_aClipboard.RemoveAll();
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
      m_aClipboard.Add( new CNSBFormObject( m_aSelection[i]->m_pFormOb ) );
} // OnEditCopy

void CVNSBView::OnUpdateEditCopy( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( m_aSelection.GetSize() > 0 );
} // OnUpdateEditCopy

void CVNSBView::OnEditCut()
{
   m_aClipboard.RemoveAll();
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
      m_aClipboard.Add( new CNSBFormObject( m_aSelection[i]->m_pFormOb ) );
   OnEditClear();
} // OnEditCut

void CVNSBView::OnUpdateEditCut( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( m_aSelection.GetSize() > 0 );
} // OnUpdateEditCut

void CVNSBView::OnEditPaste()
{
   CVNSBDoc *pDoc = GetDocument();
   CNSBForm *pForm = pDoc->m_pForm;
   Select();
   for( int i = 0; i < m_aClipboard.GetSize(); i++ )
   {
      int nObject = pForm->PasteFormObject( m_aClipboard[i] );
      pDoc->UpdateAllViews( NULL, MAKEWPARAM( HINT_OBJECT_PASTE, nObject ) );
   }
   pDoc->SetModifiedFlag();
} // OnEditPaste

void CVNSBView::OnUpdateEditPaste( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( m_aClipboard.GetSize() > 0 );
} // OnUpdateEditPaste

void CVNSBView::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
//afxDump << _T( "nChar: " ) << nChar << _T( " nRepCnt: " ) << nRepCnt << _T( " nFlags: " ) << nFlags << _T( "\n" );
   switch( nChar )
   {
   case 0xD:  // Return Key
      SelectionEditProperties();
      break;
   case 0x25: // Left Arrow
      SelectionMove( ( ( m_nGrid > 0 ) ? -( m_nGrid + 1 ) : -1 ), 0 );
      break;
   case 0x26: // Up Arrow
      SelectionMove( 0, ( ( m_nGrid > 0 ) ? -( m_nGrid + 1 ) : -1 ) );
      break;
   case 0x27: // Right Arrow
      SelectionMove( ( ( m_nGrid > 0 ) ? ( m_nGrid / 2 ) + 1 : 1 ), 0 );
      break;
   case 0x28: // Down Arrow
      SelectionMove( 0, ( ( m_nGrid > 0 ) ? ( m_nGrid / 2 ) + 1 : 1 ) );
      break;
   case 0x2E: // Delete Key
   case 0x8:  // Backspace Key
      OnEditClear();
      break;
   }
	CView::OnKeyDown( nChar, nRepCnt, nFlags );
}

void CVNSBView::SelectionMove( int cx, int cy )
{
   for( int i = 0; i < m_aSelection.GetSize(); i++ )
      m_aSelection[i]->DoMove( cx, cy, m_nGrid );
} // SelectionMove

CWnd* CVNSBView::GetSelectionView()
{
   if( m_aSelection.GetSize() == 0 )
      return this;
   else if( m_aSelection.GetSize() == 1 )
      return m_aSelection[0];
   else
      return NULL;
} // GetSelectionView

CNSBFormObject* CVNSBView::GetFormObject()
{
   return GetDocument()->m_pForm->m_pOutput;
} // GetFormObject

void CVNSBView::ChangeProperty( CString &strKey, CString strVal )
{
   CNSBFormObject *pFormOb = GetDocument()->m_pForm->m_pOutput;
   pFormOb->m_mapProperties[strKey] = strVal;
} // ChangeProperty

void CVNSBView::OnEditPrefs() 
{
   CPrefsDlg dlg;
   if( m_nGrid <= 0 )
   {
      dlg.m_nGrid = -m_nGrid;
      dlg.m_bGridSnap = FALSE;
   }
   else
   {
      dlg.m_nGrid = m_nGrid;
      dlg.m_bGridSnap = TRUE;
   }
   if( dlg.DoModal() )
   {
      m_nGrid = dlg.m_nGrid;
      if( !dlg.m_bGridSnap )
         m_nGrid *= -1;
      GetDocument()->m_nGrid = m_nGrid;
      // Let's monkey with the registry...
      HKEY hKey;
      DWORD dwDisp;
      RegCreateKeyEx( HKEY_CURRENT_USER, _T( "Software\\NSBasic\\NSBasic" ), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp );
      DWORD dwGrid = m_nGrid;
      RegSetValueEx( hKey, _T( "Grid" ), 0, REG_DWORD, (unsigned char *)&dwGrid, sizeof( DWORD ) );
      RegCloseKey( hKey );
      GetDocument()->SetModifiedFlag();
      Invalidate();
   }
} // OnEditPrefs

void CVNSBView::OnUpdateEditPrefs(CCmdUI* pCmdUI) 
{
   pCmdUI->Enable();
} // OnUpdateEditPrefs

