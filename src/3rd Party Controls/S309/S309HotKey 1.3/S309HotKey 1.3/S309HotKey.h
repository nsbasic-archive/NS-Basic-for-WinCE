#if !defined(AFX_S309HOTKEY_H__95299E21_49EF_11D3_AE2E_00608CC1DD62__INCLUDED_)
#define AFX_S309HOTKEY_H__95299E21_49EF_11D3_AE2E_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309HotKey.h : main header file for S309HOTKEY.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyApp : See S309HotKey.cpp for implementation.

class CS309HotKeyApp : public COleControlModule
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

#endif // !defined(AFX_S309HOTKEY_H__95299E21_49EF_11D3_AE2E_00608CC1DD62__INCLUDED)
