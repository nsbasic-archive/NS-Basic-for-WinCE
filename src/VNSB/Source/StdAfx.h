// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__33B0A298_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_STDAFX_H__33B0A298_C462_11D2_BD63_00A0C9962E16__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if _WIN32_WCE >= 211
//#  define VERSION_211
#endif


#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcoll.h>
#include <afxtempl.h>
#if _WIN32_WCE < 211
#  include <afxdisp.h>
#endif
#if _WIN32_WCE >= 211
#  include <Oleauto.h>
#  include <afxdtctl.h>
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__33B0A298_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
