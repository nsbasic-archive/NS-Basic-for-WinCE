#if !defined(AFX_S309PICTUREBOX_H__D4D7C4BE_2CC5_11D3_AE29_00608CC1DD62__INCLUDED_)
#define AFX_S309PICTUREBOX_H__D4D7C4BE_2CC5_11D3_AE29_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309PictureBox.h : main header file for S309PICTUREBOX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxApp : See S309PictureBox.cpp for implementation.

class CS309PictureBoxApp : public COleControlModule
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

#endif // !defined(AFX_S309PICTUREBOX_H__D4D7C4BE_2CC5_11D3_AE29_00608CC1DD62__INCLUDED)
