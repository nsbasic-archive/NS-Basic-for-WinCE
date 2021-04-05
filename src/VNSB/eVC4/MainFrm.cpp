// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "VNSB.h"

#include "VNSBDoc.h"
#include "VNSBView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Array tbSTDButton contains relevant buttons of bitmap IDB_STD_SMALL_COLOR
static TBBUTTON tbButtons[] = {
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	{3, ID_EDIT_CUT,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{4, ID_EDIT_COPY,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{5, ID_EDIT_PASTE,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	{6, ID_FORM_EXIT,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0,  0}
};
const int nNumButtons = sizeof(tbButtons)/sizeof(TBBUTTON);
const int nNumImages = 7;
const DWORD dwAdornmentFlags = 0; // exit button

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_HELPINFO()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
#ifdef _POCKET
   SetWindowText( _T( "BASIC Visual Designer" ) );
   if( !m_wndCommandBar.Create( this ) ||
       !m_wndCommandBar.InsertMenuBar( IDR_MAINFRAME_POCKET ) ||
       !m_wndCommandBar.AddAdornments() )
   {
      TRACE0( "Unable to create CommandBar\n" );
      return -1;
   }
   ShowDoneButton( true );
#else
	// Add the buttons and adornments to the CommandBar.
	if (
#ifndef _WIN32_WCE_PSPC 
      !InsertButtons(tbButtons, nNumButtons, IDR_MAINFRAME, nNumImages ) ||
#endif
	    !AddAdornments( dwAdornmentFlags | CMDBAR_HELP ) )
   {
		TRACE0("Failed to add toolbar buttons\n");
		return -1;
	}
#endif

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::SetObjectsMenu()
{
	CVNSBDoc *pDoc = (CVNSBDoc *)GetActiveDocument();
#ifdef VNSB_STANDALONE
	CMenu *pAddMenu = AfxGetMainWnd()->GetMenu()->GetSubMenu( 2 );
#else
	CMenu *pAddMenu = AfxGetMainWnd()->GetMenu()->GetSubMenu( 2 );
#endif

   // Insert objects
   // Output object is always 0, so lets start with 1
   for( int i = 1, j = 1; i < NUM_NSBOBJECTS; i++ )
   {
//      if( !( pDoc->AddObjectList[i].m_nFlag & NSBOB_TYPE_NSB ) )
//         continue;
#if _WIN32_WCE < 211
      if( !( pDoc->AddObjectList[i].m_nFlag & 211 ) )
         continue;
#endif
#ifdef _POCKET
      pAddMenu->InsertMenu( i + 2, MF_STRING | MF_BYPOSITION, pDoc->AddObjectList[i].m_nObjectID, pDoc->AddObjectList[i].m_strUserType );
#else
      CString strItem;
      if( j < 10 )
      {
         strItem.Format( _T( "&%d %s" ), j, pDoc->AddObjectList[i].m_strUserType );
         pAddMenu->AppendMenu( MF_STRING, pDoc->AddObjectList[i].m_nObjectID, strItem );
      }
      else
      {
         strItem.Format( _T( "&%s" ), pDoc->AddObjectList[i].m_strUserType );
         pAddMenu->AppendMenu( MF_STRING, pDoc->AddObjectList[i].m_nObjectID, strItem );
      }
#endif
      j++;
   }
} // SetObjectsMenu

BOOL CMainFrame::OnHelpInfo(HELPINFO* pHelpInfo) 
{
   CFrameWnd::OnHelp();
	return TRUE;
}

void CMainFrame::OnClose() 
{
#ifndef _DEBUG
   ( (CVNSBDoc *)GetActiveDocument() )->DoFormExit();
#else
   CFrameWnd::OnClose();
#endif
} // OnClose
