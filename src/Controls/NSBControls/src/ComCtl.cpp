// ComCtl.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To merge the proxy/stub code into the object DLL, add the file 
//      dlldatax.c to the project.  Make sure precompiled headers 
//      are turned off for this file, and add _MERGE_PROXYSTUB to the 
//      defines for the project.  
//
//      If you are not running WinNT4.0 or Win95 with DCOM, then you
//      need to remove the following define from dlldatax.c
//      #define _WIN32_WINNT 0x0400
//
//      Further, if you are running MIDL without /Oicf switch, you also 
//      need to remove the following define from dlldatax.c.
//      #define USE_STUBLESS_PROXY
//
//      Modify the custom build rule for ComCtl.idl by adding the following 
//      files to the Outputs.
//          ComCtl_p.c
//          dlldata.c
//      To build a separate proxy/stub DLL, 
//      run nmake -f ComCtlps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "ComCtl.h"
#include "dlldatax.h"

#include "ComCtl_i.c"
#include "NSListView.h"
#include "NSBImageList.h"
#include "NSBListImage.h"
#include "NSColumnHeaders.h"
#include "NSColumnHeader.h"
#include "NSListItems.h"
#include "NSListItem.h"
#include "NSListSubItems.h"
#include "NSListSubItem.h"
#include "NSListViewEvent.h"
#include "NSFont.h"
#include "NSColumnItems.h"
#include "NSComCtlColl.h"

#ifdef _MERGE_PROXYSTUB
extern "C" HINSTANCE hProxyDll;
#endif

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_NSListView, CNSListView)
OBJECT_ENTRY(CLSID_NSBImageList, CNSBImageList)
OBJECT_ENTRY_NON_CREATEABLE(CNSBListImage)
OBJECT_ENTRY_NON_CREATEABLE(CNSColumnHeaders)
OBJECT_ENTRY_NON_CREATEABLE(CNSColumnHeader)
OBJECT_ENTRY_NON_CREATEABLE(CNSListItems)
OBJECT_ENTRY_NON_CREATEABLE(CNSListItem)
OBJECT_ENTRY_NON_CREATEABLE(CNSListSubItems)
OBJECT_ENTRY_NON_CREATEABLE(CNSListSubItem)
OBJECT_ENTRY_NON_CREATEABLE(CNSListViewEvent)
OBJECT_ENTRY(CLSID_NSFont, CNSFont)
OBJECT_ENTRY_NON_CREATEABLE(CNSColumnItems)
OBJECT_ENTRY_NON_CREATEABLE(CNSComCtlColl)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HANDLE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    lpReserved;
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, (HINSTANCE)hInstance, &LIBID_COMCTLLib);
        #ifdef _WIN32_WCE
			#if _WIN32_WCE >= 300
                DisableThreadLibraryCalls((HINSTANCE)hInstance);
            #endif
		#else
            DisableThreadLibraryCalls((HINSTANCE)hInstance);
		#endif
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllCanUnloadNow() != S_OK)
        return S_FALSE;
#endif
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hRes = PrxDllRegisterServer();
    if (FAILED(hRes))
        return hRes;
#endif
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    PrxDllUnregisterServer();
#endif
    return _Module.UnregisterServer(TRUE);
}


