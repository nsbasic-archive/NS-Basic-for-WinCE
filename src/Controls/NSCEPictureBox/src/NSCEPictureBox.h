#if !defined(AFX_NSCEPICTUREBOX_H__88E44DD7_87D4_42F4_950B_0FE6A3599881__INCLUDED_)
#define AFX_NSCEPICTUREBOX_H__88E44DD7_87D4_42F4_950B_0FE6A3599881__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// NSCEPictureBox.h : main header file for NSCEPICTUREBOX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxApp : See NSCEPictureBox.cpp for implementation.

class CNSCEPictureBoxApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NSCEPICTUREBOX_H__88E44DD7_87D4_42F4_950B_0FE6A3599881__INCLUDED)
