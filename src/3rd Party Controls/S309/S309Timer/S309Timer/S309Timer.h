#if !defined(AFX_S309TIMER_H__0C993DAC_484A_11D3_AE2D_00608CC1DD62__INCLUDED_)
#define AFX_S309TIMER_H__0C993DAC_484A_11D3_AE2D_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309Timer.h : main header file for S309TIMER.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CS309TimerApp : See S309Timer.cpp for implementation.

class CS309TimerApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309TIMER_H__0C993DAC_484A_11D3_AE2D_00608CC1DD62__INCLUDED)
