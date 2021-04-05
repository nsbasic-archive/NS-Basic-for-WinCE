// EVCDemo.h : main header file for the EVCDEMO application
//

#if !defined(AFX_EVCDEMO_H__4D44998C_10D8_460F_9FDD_C49B86463EE5__INCLUDED_)
#define AFX_EVCDEMO_H__4D44998C_10D8_460F_9FDD_C49B86463EE5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEVCDemoApp:
// See EVCDemo.cpp for the implementation of this class
//

class CEVCDemoApp : public CWinApp
{
public:
	CEVCDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEVCDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEVCDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EVCDEMO_H__4D44998C_10D8_460F_9FDD_C49B86463EE5__INCLUDED_)
