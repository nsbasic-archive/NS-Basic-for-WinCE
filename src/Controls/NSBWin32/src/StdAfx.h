// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__CF672A49_E92F_4A16_9AD3_4EA0FA90CCB5__INCLUDED_)
#define AFX_STDAFX_H__CF672A49_E92F_4A16_9AD3_4EA0FA90CCB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#define WINVER 0x401

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
// #include <atlctl.h>
#include <commctrl.h>
#include <ras.h>
#include <raserror.h>
#include <shlobj.h>

#define  TPOOLLIBRARY_PACKEDCOMTYPES
#define  CC_BINTOHEX_ROUTINES

#include <TPoolLibrary/osspecific.h>
#include <TPoolLibrary/automationhlp.h>
#include <TPoolLibrary/ccBuffer.h>
#include <TPoolLibrary/safearrayhelper.h>
#include <TPoolLibrary/ccmisc.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__CF672A49_E92F_4A16_9AD3_4EA0FA90CCB5__INCLUDED)
