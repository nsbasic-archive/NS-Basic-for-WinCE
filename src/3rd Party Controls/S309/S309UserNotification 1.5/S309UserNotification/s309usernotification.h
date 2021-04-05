#if !defined(AFX_S309USERNOTIFICATION_H__E4A5759F_BD6F_11D2_AE1A_00608CC01367__INCLUDED_)
#define AFX_S309USERNOTIFICATION_H__E4A5759F_BD6F_11D2_AE1A_00608CC01367__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309UserNotification.h : main header file for S309USERNOTIFICATION.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationApp : See S309UserNotification.cpp for implementation.

class CS309UserNotificationApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309USERNOTIFICATION_H__E4A5759F_BD6F_11D2_AE1A_00608CC01367__INCLUDED)
