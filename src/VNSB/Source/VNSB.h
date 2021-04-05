// VNSB.h : main header file for the VNSB application
//

#if !defined(AFX_VNSB_H__33B0A296_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_VNSB_H__33B0A296_C462_11D2_BD63_00A0C9962E16__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#if ( defined( _WIN32_WCE_PSPC ) && ( _WIN32_WCE >= 300 ) )
#  define _POCKET
#else
#  undef _POCKET
#endif

#include "resource.h"       // main symbols
#include "NSBObjects.h"

#define PARSE_STATE_DEFAULT_FORM       0
#define PARSE_STATE_NEW_FORM           1
#define PARSE_STATE_NUM_OBJECTS        2
#define PARSE_STATE_NEW_OBJECT         3
#define PARSE_STATE_OBJECT_PROPERTY    4
#define PARSE_STATE_SHOWMENU           5
#define PARSE_STATE_OUTPUT_PROPERTY    6
#define PARSE_STATE_END_FORM           7
#define PARSE_STATE_SETMENU            8
#define PARSE_STATE_GRID_SIZE          9
#define PARSE_STATE_EXIT               10
#define PARSE_STATE_ERROR              10

/////////////////////////////////////////////////////////////////////////////
// CVNSBApp:
// See VNSB.cpp for the implementation of this class
//


class CVNSBApp : public CWinApp
{
public:
	CString m_strMagicFileName;
	BOOL VNSBParseCommandLine();
	CString m_strRealFileName;
	CVNSBApp( LPCTSTR lpszHelpName );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVNSBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVNSBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

int CStringReplace( CString &strDest, LPCTSTR lpszTarget, LPCTSTR lpszSource );

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VNSB_H__33B0A296_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
