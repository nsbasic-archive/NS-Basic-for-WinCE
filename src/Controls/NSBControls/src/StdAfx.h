// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__56D65FE1_6034_45A8_A2A9_FF4EC654E1B4__INCLUDED_)
#define AFX_STDAFX_H__56D65FE1_6034_45A8_A2A9_FF4EC654E1B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED
#define _WIN32_IE   0x0400

#define TPOOLLIBRARY_PACKEDCOMTYPES

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>
#include <commctrl.h>
#include <TPoolLibrary/osspecific.h>
#include <TPoolLibrary/automationhlp.h>
#include <TPoolLibrary/ccSimpleArray.h>

#include "miscmacros.h"
#include <ocidl.h>	// Added by ClassView

#define LIBID_COMCTLLib LIBID_NSBControlsLib

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__56D65FE1_6034_45A8_A2A9_FF4EC654E1B4__INCLUDED)
