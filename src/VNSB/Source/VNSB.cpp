// VNSB.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VNSB.h"

#include "MainFrm.h"

#include "VNSBDoc.h"
#include "VNSBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

unsigned long giSerialNumber;
bool gbProtectedFile;	//Is the file protected (not editable?)

int CStringReplace( CString &strDest, LPCTSTR lpszTarget, LPCTSTR lpszSource )
{
#if _WIN32_WCE < 211
   int i, n = strDest.Find( lpszTarget ), len = _tcslen( lpszTarget );
   i = 0;
   while( n >= 0 )
   {
      strDest = strDest.Left( n ) + lpszSource + strDest.Mid( n + len );
      n = strDest.Find( lpszTarget );
      i++;
   }
   return i;
#else
   return strDest.Replace( lpszTarget, lpszSource );
#endif
}

#ifdef _POCKET
HANDLE ghMutex;
#endif


/////////////////////////////////////////////////////////////////////////////
// CVNSBApp

BEGIN_MESSAGE_MAP(CVNSBApp, CWinApp)
	//{{AFX_MSG_MAP(CVNSBApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVNSBApp construction

CVNSBApp::CVNSBApp( LPCTSTR lpszHelpName )
	: CWinApp( lpszHelpName )
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVNSBApp object

// WCE MFC apps require the application name to be specified in the CWinApp 
// constructor. A help contents filename may also be specified.

CVNSBApp theApp( _T( "VNSB.htp" ) );

/////////////////////////////////////////////////////////////////////////////
// CVNSBApp initialization

void SetWaitCursor( BOOL bWait )
{
   HCURSOR hCur;

   if( bWait )
      //SetCursor((HICON)LoadImage(NULL, IDC_WAIT,IMAGE_ICON,0,0,LR_DEFAULTCOLOR));
      hCur = LoadCursorW( NULL, IDC_WAIT );
	else
#if(_WIN32_WCE != 200)  //**MARCH99 - no arrow cursor in HPC
      hCur = LoadCursorW( NULL, IDC_ARROW );
#else
      hCur = NULL;
#endif

   SetCursor( hCur );	
} // SetWaitCursor

BOOL CVNSBApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

   //SetCursor( LoadCursorW( NULL, MAKEINTRESOURCE( 32512 ) ) );	
   SetWaitCursor( FALSE );

   // Set serial number
   CString strPrefsFile;
   strPrefsFile.LoadString( IDS_PREFS_FILE );
   CFile filePrefs;
   BOOL bOpen = filePrefs.Open( strPrefsFile, CFile::modeRead | CFile::shareDenyWrite );
   if( !bOpen )
   {
      strPrefsFile.LoadString( IDS_NO_PREFS_FILE );
      MessageBox( NULL, strPrefsFile, _T( "VNSB" ), MB_ICONSTOP | MB_ICONERROR | MB_OK );
      return FALSE;
   }
   else
   {
      CString strText, strItem;
      char pBuf[100];

      UINT nLength = filePrefs.Read( pBuf, 100 );
      filePrefs.Close();
      LPTSTR lpszText = strText.GetBuffer( 100 );
      mbstowcs( lpszText, pBuf, nLength );
      strText.ReleaseBuffer( nLength );
      strText = strText.Mid( wcslen( _T( "Serial:" ) ) );
	  // MMD 2002-10-15 This is not needed in VNSB
	  /*
      if( ( _stscanf( strText, _T( "%lu" ), &giSerialNumber ) != 1 )
          || ( ( ( giSerialNumber - 3000003 ) % 71 ) != 0 ) )
      {
         MessageBox( NULL, _T( "Demo or Runtime version cannot open VNSB" ),
                     _T( "VNSB" ), MB_ICONSTOP | MB_ICONERROR | MB_OK );
         return FALSE;
      }
	  */
   }

#ifndef _DEBUG
   if( !VNSBParseCommandLine() )
   {
      MessageBox( NULL, _T( "Open VNSB only from NSBasic/CE" ), _T( "VNSB" ), MB_ICONSTOP | MB_ICONERROR | MB_OK );
      return FALSE;
   }
#else
   m_strMagicFileName = _T( "\\Hammer.nsb" );
   m_strRealFileName = _T( "\\Hammer.nsb" );
#endif

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey( _T("NSBasic") );

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CVNSBDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CVNSBView));
	AddDocTemplate(pDocTemplate);

#ifndef _DEBUG
   // Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
   ParseCommandLine( cmdInfo );

	// Dispatch commands specified on the command line
	if( !ProcessShellCommand( cmdInfo ) )
		return FALSE;
#else
//   OpenDocumentFile( m_lpCmdLine );
   OpenDocumentFile( _T( "\\Temp\\NSB_TEMP.nsb" ) );
#endif

   if( gbProtectedFile )
   {
      m_pMainWnd->ShowWindow( SW_HIDE );
      MessageBox( NULL, _T( "This file is protected and cannot be opened with VNSB.  Launch it directly instead." ), _T( "VNSB" ), MB_ICONSTOP | MB_ICONERROR | MB_OK );
      return FALSE;
   }
   // The one and only window has been initialized, so show and update it.
   // Load pause fix...
   m_pMainWnd->ShowWindow( SW_SHOWNORMAL );
   m_pMainWnd->UpdateWindow();
   if( m_strRealFileName.IsEmpty() )
      ( (CMainFrame *)m_pMainWnd )->GetActiveDocument()->SetTitle( _T( "Untitled" ) );
   else
      ( (CMainFrame *)m_pMainWnd )->GetActiveDocument()->SetTitle( m_strRealFileName );
   ( (CMainFrame *)m_pMainWnd )->SetObjectsMenu();

#ifdef _POCKET
   ghMutex = ::CreateMutex( NULL, FALSE, _T( "NS Basic,BASIC Editor" ) );
#endif

   return TRUE;
} // InitInstance



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CVNSBApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CVNSBApp commands
// Added for WCE apps

//DEL BOOL CAboutDlg::OnInitDialog() 
//DEL {
//DEL 	CDialog::OnInitDialog();
//DEL 
//DEL    CenterWindow();
//DEL    CString strVersion;
//DEL    CWnd *wndVersion = GetDlgItem( IDC_ABOUT_VERSION );
//DEL    wndVersion->GetWindowText( strVersion );
//DEL    strVersion.Format( _T( "%s (%s %s)" ), strVersion, _T( __DATE__ ), _T( __TIME__ ) );
//DEL    wndVersion->SetWindowText( strVersion );
//DEL 	
//DEL 	return TRUE;  // return TRUE unless you set the focus to a control
//DEL 	              // EXCEPTION: OCX Property Pages should return FALSE
//DEL }

BOOL CVNSBApp::VNSBParseCommandLine()
{
   CString strTemp, strTemp2 = CString( m_lpCmdLine );
   _stscanf( strTemp2, _T( "\"%[^\"]\" \"%[^\"]\"" ),
             strTemp.GetBuffer( 256 ),
             m_strRealFileName.GetBuffer( 256 ) );
   strTemp.ReleaseBuffer();
   m_strRealFileName.ReleaseBuffer();

#ifdef _DEBUG
   _tcscpy( m_lpCmdLine, _T( "\\Temp\\NSB_TEMP.nsb" ) );
   strTemp = CString( m_lpCmdLine );
#else
   m_lpCmdLine[strTemp.GetLength() + 1] = _T( '\0' );
#endif
   if( strTemp.IsEmpty() )
      return FALSE;

   // Parse Magic File Path for File Name
   INT i = strTemp.Find( _T( "\\" ) );
   while( i >= 0 )
   {
      strTemp = strTemp.Right( strTemp.GetLength() - ( i + 1 ) );
      i = strTemp.Find( _T( "\\" ) );
   }
   m_strMagicFileName = strTemp;
   return TRUE;   
} // ParseCommandLine

