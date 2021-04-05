// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__74F9A861_66D1_4EDC_B73F_A20FF5C9C72E__INCLUDED_)
#define AFX_STDAFX_H__74F9A861_66D1_4EDC_B73F_A20FF5C9C72E__INCLUDED_

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
#include <atlctl.h>
#include <ocidl.h>	// Added by ClassView

#include <Commdlg.h>

// Corrections for Windows CE
#ifndef OFN_ENABLESIZING
    #define OFN_ENABLESIZING    0x00800000
#endif
#ifndef CC_SHOWHELP
    #define CC_SHOWHELP              0x00000008
#endif



#define  TPOOLLIBRARY_PACKEDCOMTYPES

#include <TPoolLibrary/osspecific.h>
#include <TPoolLibrary/automationhlp.h>
#include <TPoolLibrary/ccBuffer.h>
#include <TPoolLibrary/safearrayhelper.h>
#include <TPoolLibrary/ccmisc.h>
#include <TPoolLibrary/safeComDlg.h>

#define LIBID_DESKLib   LIBID_NSBComDlgLib

// WIN32_PLATFORM_PSPC - Pocket PC
// WIN32_PLATFORM_WFSP - smartphone

#include "whichplatform.h"

#define  REPORT_RESERROR(id,iid) ReprotCOMErrorInfo(_Module.m_hInstResource,id,iid,L"NSBComDlg");
#define  REPORT_ERROR(str,iid) ReprotCOMErrorInfo(str,iid,L"NSBComDlg");

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__74F9A861_66D1_4EDC_B73F_A20FF5C9C72E__INCLUDED)
