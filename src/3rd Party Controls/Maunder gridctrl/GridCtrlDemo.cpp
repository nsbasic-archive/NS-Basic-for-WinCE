// GridCtrlDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GridCtrlDemo.h"
#include "GridCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoApp

BEGIN_MESSAGE_MAP(CGridCtrlDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CGridCtrlDemoApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoApp construction

CGridCtrlDemoApp::CGridCtrlDemoApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGridCtrlDemoApp object

CGridCtrlDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoApp initialization

BOOL CGridCtrlDemoApp::InitInstance()
{
	// Standard initialization
#if !defined(_WIN32_WCE) && (_MFC_VER < 0x0700) 
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#endif

	CGridCtrlDemoDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
