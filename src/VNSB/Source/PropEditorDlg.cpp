// PropEditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "PropEditorDlg.h"

#include "NSBForm.h"
#include "VNSBDoc.h"
#include "VNSBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropEditorDlg dialog


CPropEditorDlg::CPropEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPropEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropEditorDlg)
	//}}AFX_DATA_INIT
}


void CPropEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropEditorDlg)
	DDX_Control(pDX, IDC_OBJECT_NAME, m_cObjectName);
	DDX_Control(pDX, IDC_EDITLIST, m_cEditList);
	DDX_Control(pDX, IDC_CHOOSE, m_cChoose);
	DDX_Control(pDX, IDC_EDITMULTI, m_cEditMulti);
	DDX_Control(pDX, IDC_NUMBER, m_cNumber);
	DDX_Control(pDX, IDC_PROPERTIES, m_cProperties);
	DDX_Control(pDX, IDC_EDITSINGLE, m_cEditSingle);
	DDX_Control(pDX, IDC_LIST, m_cList);
	//}}AFX_DATA_MAP
#if _WIN32_WCE >= 211
	DDX_Control(pDX, IDC_DATE, m_cDate);
	DDX_Control(pDX, IDC_TIME, m_cTime);
#endif
}


BEGIN_MESSAGE_MAP(CPropEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CPropEditorDlg)
	ON_CBN_SELCHANGE(IDC_PROPERTIES, OnSelchangeProperties)
	ON_EN_CHANGE(IDC_EDITSINGLE, OnChangeProperty)
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHOOSE, OnChoose)
	ON_CBN_SELCHANGE(IDC_EDITLIST, OnChangeProperty)
	ON_EN_CHANGE(IDC_OBJECT_NAME, OnChangeObjectName)
	ON_CBN_SELCHANGE(IDC_LIST, OnChangeProperty)
	ON_EN_CHANGE(IDC_NUMBER, OnChangeProperty)
	ON_EN_CHANGE(IDC_EDITMULTI, OnChangeProperty)
	ON_CBN_EDITCHANGE(IDC_EDITLIST, OnChangeProperty)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE, OnChangeProperty)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TIME, OnChangeProperty)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

NSBProperty CPropEditorDlg::NSBPropertyList[NUM_NSBPROPERTIES] = NSB_PROPERTIES;

/////////////////////////////////////////////////////////////////////////////
// CPropEditorDlg message handlers

BOOL CPropEditorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
   POSITION pos;
   CString strKey, strVal;

   if( m_pView->IsKindOf( RUNTIME_CLASS( CVNSBView ) ) )
   {
      m_pFormOb = ( (CVNSBView *)m_pView )->GetFormObject();
      m_cObjectName.EnableWindow( FALSE );
   }
   else
   {
      m_pFormOb = ( (CNSBFormObjectView *)m_pView )->GetFormObject();
      m_strObjectName = m_pFormOb->m_strObjectName;
   }

   SetWindowText( m_pFormOb->m_strObjectName + _T( " Properties" ) );

   if( m_pFormOb->m_nObjectType == NSBOB_COM_OB )
   {
      WORD nVal;
      if( m_pComObDesc->m_mapProperties.IsEmpty() )
         m_pComObDesc->GetProperties();
      pos = m_pComObDesc->m_mapProperties.GetStartPosition();
      while( pos != NULL )
      {
         m_pComObDesc->m_mapProperties.GetNextAssoc( pos, strKey, nVal );
         if( !m_pFormOb->m_mapProperties.Lookup( strKey, strVal ) )
            m_cProperties.AddString( strKey );
      }
   }
   m_cObjectName.SetWindowText( m_pFormOb->m_strObjectName );
   pos = m_pFormOb->m_mapProperties.GetStartPosition();
   while( pos != NULL )
   {
      m_pFormOb->m_mapProperties.GetNextAssoc( pos, strKey, strVal );
      m_cProperties.AddString( strKey );
   }
   m_nVisibleEditor = 0;
   m_cProperties.SetCurSel( 0 );
   m_bPropertyDirty = FALSE;
   OnSelchangeProperties();
   CRect rect;
   GetClientRect( &rect );
   INT nScreenX = GetSystemMetrics( SM_CXSCREEN );
   INT nScreenY = GetSystemMetrics( SM_CYSCREEN );
//   SetWindowPos( &wndTopMost, ( nScreenX - rect.right ) / 2, ( nScreenY - rect.bottom ) / 2, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW );
   SetWindowPos( &wndTop, ( nScreenX - rect.right ) / 2, ( nScreenY - rect.bottom ) / 2, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW );
   SetActiveWindow();
   return TRUE;
} // OnInitDialog

void CPropEditorDlg::OnSelchangeProperties()
{
   WORD nType;
   OnApply();
   CString strKey, strVal;
   COleDateTime when;
   m_cProperties.GetWindowText( strKey );
   if( !m_pFormOb->m_mapProperties.Lookup( strKey, strVal ) )
      strVal.Empty();

   // If some editor is visible, hide it.
   if( m_nVisibleEditor )
   {
      GetDlgItem( m_nVisibleEditor )->ShowWindow( SW_HIDE );
      m_cChoose.ShowWindow( SW_HIDE );
   }

   nType = 0;
   if( m_pFormOb->m_nObjectType == NSBOB_COM_OB )
   {
      m_pComObDesc->m_mapProperties.Lookup( strKey, nType );
   }
   if( m_pFormOb->m_nObjectType != NSBOB_COM_OB || nType == 0 )
   {
      for( int i = 0; i < NUM_NSBPROPERTIES; i++ )
         if( NSBPropertyList[i].m_strName == strKey )
            if( m_pFormOb->HasProperty( NSBPropertyList[i].m_nPropertyID ) )
               break;
      nType = NSBPropertyList[i].m_nType;
   }
   m_strProperty.Empty();
   switch( nType )
   {
   case NSBP_TYPE_STRING1:
      m_cEditSingle.SetWindowText( strVal );
      m_cEditSingle.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_EDITSINGLE;
      break;
   case NSBP_TYPE_STRINGN:
      m_cEditMulti.SetWindowText( strVal );
      m_cEditMulti.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_EDITMULTI;
      break;
   case NSBP_TYPE_BOOL:
      m_cList.ResetContent();
      m_cList.AddString( _T( "TRUE" ) );
      m_cList.AddString( _T( "FALSE" ) );
      m_cList.SelectString( -1, strVal );
      m_cList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_LIST;
      break;
   case NSBP_TYPE_ALIGNMENT:
      m_cList.ResetContent();
      m_cList.AddString( _T( "0 -- Left" ) );
      m_cList.AddString( _T( "1 -- Right" ) );
      m_cList.AddString( _T( "2 -- Center" ) );
      m_cList.SetCurSel( _wtoi( strVal ) );
      m_cList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_LIST;
      break;
   case NSBP_TYPE_STYLE:
      m_cList.ResetContent();
      m_cList.AddString( _T( "0 -- Allow Input" ) );
      m_cList.AddString( _T( "2 -- Read-Only" ) );
      m_cList.SetCurSel( _wtoi( strVal ) );
      m_cList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_LIST;
      break;
   case NSBP_TYPE_STRINGLIST:
      m_cEditMulti.SetWindowText( strVal );
      m_cEditMulti.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_EDITMULTI;
      break;
   case NSBP_TYPE_SCROLLBARS:
      m_cList.ResetContent();
      m_cList.AddString( _T( "0 -- None" ) );
      m_cList.AddString( _T( "1 -- Horizontal" ) );
      m_cList.AddString( _T( "2 -- Vertical" ) );
      m_cList.AddString( _T( "3 -- Both" ) );
      m_cList.SetCurSel( _wtoi( strVal ) );
      m_cList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_LIST;
      break;
   case NSBP_TYPE_FONTNAME:  // GetDeviceContext
      {
         CDC *pDC = GetDC();
         m_cEditList.ResetContent();
         EnumFontFamilies( pDC->m_hDC, NULL, &CPropEditorDlg::EnumFontFamProc, (long)&m_cEditList );
         m_cEditList.SetWindowText( strVal );
         m_cEditList.ShowWindow( SW_SHOW );
         m_nVisibleEditor = IDC_EDITLIST;
         ReleaseDC( pDC );
      }
      break;
   case NSBP_TYPE_FONTSIZE:
      {
         INT j;
         CString strSize;
         m_cEditList.ResetContent();
         for( j = 6; j < 19; j++ )
         {
            strSize.Format( _T( "%d" ), j );
            m_cEditList.AddString( (LPCTSTR)strSize );
         }
      }
      m_cEditList.SetWindowText( strVal );
      m_cEditList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_EDITLIST;
      break;
   case NSBP_TYPE_COLOR:
      m_cEditList.ResetContent();
      m_cEditList.AddString( _T( "12632256 -- GRAY" ) );
      m_cEditList.AddString( _T( "vbBLACK" ) );
      m_cEditList.AddString( _T( "vbBLUE" ) );
      m_cEditList.AddString( _T( "vbCYAN" ) );
      m_cEditList.AddString( _T( "vbGREEN" ) );
      m_cEditList.AddString( _T( "vbMAGENTA" ) );
      m_cEditList.AddString( _T( "vbRED" ) );
      m_cEditList.AddString( _T( "vbWHITE" ) );
      m_cEditList.AddString( _T( "vbYELLOW" ) );
      m_cEditList.SetWindowText( strVal );
      m_cEditList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_EDITLIST;
#if defined(_WIN32_WCE_PSPC) || _WIN32_WCE < 210
      break;
#endif
      m_cChoose.ShowWindow( SW_SHOW );
      break;
   case NSBP_TYPE_INT:
      m_cNumber.SetWindowText( strVal );
      m_cNumber.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_NUMBER; // m_cNumber.GetDlgCtrlID();
      break;
   case NSBP_TYPE_DATE: // DTS_SHORTDATEFORMAT | DTS_LONGDATEFORMAT
#if _WIN32_WCE >= 211
      if( strVal == _T( "-1" ) )
         when.GetCurrentTime();
      else
         when.ParseDateTime( strVal, VAR_DATEVALUEONLY );
      m_cDate.SetTime( when );
      m_cDate.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_DATE;
#endif
      break;
   case NSBP_TYPE_TIME: // DTS_TIMEFORMAT
#if _WIN32_WCE >= 211
      if( strVal == _T( "-1" ) )
         when.GetCurrentTime();
      else
         when.ParseDateTime( strVal, VAR_TIMEVALUEONLY );
      m_cDate.SetTime( when );
      m_cTime.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_TIME;
#endif
      break;
   case NSBP_TYPE_BORDERSTYLE:
      m_cList.ResetContent();
      m_cList.AddString( _T( "0 -- No Border" ) );
      m_cList.AddString( _T( "1 -- Border" ) );
      m_cList.SetCurSel( _wtoi( strVal ) );
      m_cList.ShowWindow( SW_SHOW );
      m_nVisibleEditor = IDC_LIST;
      break;
   }
   m_strProperty = strKey;
} // OnSelchangeProperties

void CPropEditorDlg::OnChangeProperty() 
{
   if( !m_strProperty.IsEmpty() )
      m_bPropertyDirty = TRUE;
} // OnChangeProperty

void CPropEditorDlg::OnApply() 
{
   CString strValue;
   COleDateTime when;

   if( !m_bPropertyDirty )
      return;
   m_bPropertyDirty = FALSE;
   GetDlgItem( m_nVisibleEditor )->GetWindowText( strValue );
   if( strValue.IsEmpty() )
      return;

   switch( m_nVisibleEditor )
   {
   case IDC_LIST:
   case IDC_EDITLIST:
      strValue = FilterProperty( strValue );
      break;
   case IDC_EDITMULTI:
//      if( m_strProperty == _T( "List" ) )
//      {
         strValue.TrimLeft();
         strValue.TrimRight();
//      }
      break;
#if _WIN32_WCE >= 210
   case IDC_DATE:
      ( (CDateTimeCtrl *)GetDlgItem( m_nVisibleEditor ) )->GetTime( when );
      strValue.Format( _T( "%d/%d/%d" ), when.GetMonth(), when.GetDay(), when.GetYear() );
      break;
   case IDC_TIME:
      ( (CDateTimeCtrl *)GetDlgItem( m_nVisibleEditor ) )->GetTime( when );
      strValue.Format( _T( "%02d:%02d:%02d" ), when.GetHour(), when.GetMinute(), when.GetSecond() );
      break;
#endif
   default:
      break;
   }

   if( m_pView->IsKindOf( RUNTIME_CLASS( CVNSBView ) ) )
      ( (CVNSBView *)m_pView )->ChangeProperty( m_strProperty, strValue );
   else
      ( (CNSBFormObjectView *)m_pView )->ChangeProperty( m_strProperty, strValue );
} // OnApply

void CPropEditorDlg::OnClose() 
{
   OnApply();
   if( m_pFormOb->m_strObjectName.IsEmpty() )
   {
      m_pFormOb->m_strObjectName = m_strObjectName;
      m_pView->SetWindowText( m_strObjectName );
      m_pView->RedrawWindow();
   }
	CDialog::OnClose();
} // OnClose

void CPropEditorDlg::OnChoose() 
{
   switch( m_nVisibleEditor )
   {
   case IDC_NUMBER:
   case IDC_EDITLIST:
#if _WIN32_WCE >= 211
#  ifndef _WIN32_WCE_PSPC
      {
         CColorDialog dlg;
         CString strVal;
         m_pFormOb->m_mapProperties.Lookup( m_strProperty, strVal );
         dlg.m_cc.rgbResult = _wtoi( strVal );
         dlg.m_cc.Flags = dlg.m_cc.Flags | CC_RGBINIT;
         if( dlg.DoModal() == IDOK )
         {
            CString strColor;
            strColor.Format( _T( "%d" ), dlg.m_cc.rgbResult );
            CWnd *pWnd = GetDlgItem( m_nVisibleEditor );
            pWnd->SetWindowText( strColor );
         }
      }
#  endif
#endif
      break;
   default:
      ;
   }
} // OnChoose

CString CPropEditorDlg::FilterProperty( CString &strProperty )
{
   INT nIndex = strProperty.Find( _T( " -- " ) );
   if( nIndex >= 0 )
      return strProperty.Left( nIndex );
   return strProperty;
} // FilterProperty

void CPropEditorDlg::OnChangeObjectName() 
{
   // Don't do anything for "<Formname> Output"
   if( m_pView->IsKindOf( RUNTIME_CLASS( CVNSBView ) ) )
      return;

   CString strText;
   m_cObjectName.GetWindowText( strText );
#if _WIN32_WCE < 211
   if( CStringReplace( strText, _T( " " ), _T( "_" ) ) > 0 ) 
#else
   if( strText.Replace( _T( ' ' ), _T( '_' ) ) > 0 )
#endif
   {
      m_cObjectName.SetWindowText( strText );
      m_cObjectName.SetSel( strText.GetLength(), strText.GetLength(), 0 );
      return;
   }
   m_pFormOb->m_strObjectName = strText;
   m_pView->SetWindowText( strText );
   m_pView->RedrawWindow();
   SetWindowText( strText + _T( " Properties" ) );
} // OnChangeObjectName

void CPropEditorDlg::OnOK()
{
   OnClose();
   EndDialog( IDOK );
} // OnOK

int CALLBACK CPropEditorDlg::EnumFontFamProc( const LOGFONT *lplf,
                                              const TEXTMETRIC *lpntm, unsigned long FontType,
                                              LPARAM lParam )
{
	CComboBox *pEditor = (CComboBox *)lParam;
	pEditor->AddString( lplf->lfFaceName );
	return 1;
} // EnumFontFamProc

//DEL void CPropEditorDlg::OnCancel()
//DEL {
//DEL    OnClose();
//DEL } // OnCancel
