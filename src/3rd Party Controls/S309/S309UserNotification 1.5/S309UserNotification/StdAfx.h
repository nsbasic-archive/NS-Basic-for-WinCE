#if !defined(AFX_STDAFX_H__E4A5759D_BD6F_11D2_AE1A_00608CC01367__INCLUDED_)
#define AFX_STDAFX_H__E4A5759D_BD6F_11D2_AE1A_00608CC01367__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxctl.h>         // MFC support for ActiveX Controls

#include <afxtempl.h>

#ifdef UNDER_CE
	#ifdef WIN32_PLATFORM_PSPC
		#if WIN32_PLATFORM_PSPC > 300
			#define S309_HAVE_ALERTS
		#endif // WIN32_PLATFORM_PSPC > 300
	#endif // WIN32_PLATFORM_PSPC
#endif // UNDER_CE

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E4A5759D_BD6F_11D2_AE1A_00608CC01367__INCLUDED_)
