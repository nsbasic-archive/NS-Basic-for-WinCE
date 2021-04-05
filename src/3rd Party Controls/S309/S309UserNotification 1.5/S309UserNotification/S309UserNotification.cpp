// S309UserNotification.cpp : Implementation of CS309UserNotificationApp and DLL registration.

#include "stdafx.h"
#include "S309UserNotification.h"
#ifdef UNDER_CE
#include <notify.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CS309UserNotificationApp NEAR theApp;

// {B9FF41CD-2B29-493a-8103-0599885C3836}
const GUID CDECL BASED_CODE _tlid =
{ 0xb9ff41cd, 0x2b29, 0x493a, { 0x81, 0x3, 0x5, 0x99, 0x88, 0x5c, 0x38, 0x36 } };
//		{ 0xe4a57596, 0xbd6f, 0x11d2, { 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 5;


////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationApp::InitInstance - DLL initialization

BOOL CS309UserNotificationApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationApp::ExitInstance - DLL termination

int CS309UserNotificationApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

#ifdef _MIPS_
#if _WIN32_WCE < 300
//	AfxMessageBox(TEXT("S309UserNotification.ocx\r(c) Copyright 1999-2000 Software 309"), MB_OK, 0 );
#endif // _WIN32_WCE < 300
#endif // _MIPS_

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

#ifndef UNDER_CE	
	TCHAR szControl[] = TEXT("S309.UserNotification.1.5");  // this should be the only parameter to change

	TCHAR szPrefix[] = TEXT("SOFTWARE\\Microsoft\\Windows CE Tools\\Platform Manager\\{F384D888-F9AA-11D1-BB9E-00A0C9C9CCEE}\\");
	TCHAR szSuffix[] = TEXT("\\{F384D894-F9AA-11D1-BB9E-00A0C9C9CCEE}\\{B646D410-60A0-11D2-8B91-006008B0E597}");
	TCHAR szPlatforms[6][255];

	strcpy(szPlatforms[0], TEXT("{0B7D1301-289F-11D2-974F-00A0240918F0}")); // hpc 2.0
	strcpy(szPlatforms[1], TEXT("{74239C21-1DCA-11D2-9747-00A0240918F0}")); // hpc pro 2.11
	strcpy(szPlatforms[2], TEXT("{458BFDB0-A6A6-11D2-BBCF-00A0C9C9CCEE}")); // ppc 2.11
	strcpy(szPlatforms[3], TEXT("{6D5C6210-E14B-11D2-B72A-0000F8026CEE}")); // pocket pc
	strcpy(szPlatforms[4], TEXT("{0F9D255B-97DA-4641-A8E6-7A7411D2472F}")); // hpc 2000
	strcpy(szPlatforms[5], TEXT("{DE9660AC-85D3-4C63-A6AF-46A3B3B83737}")); // Pocket PC 2002
	TCHAR szKey[255];
	TCHAR szDescription[255];
	TCHAR szUUID[255];

	HKEY hKey1;
	HKEY hKey2;
	HKEY hKey3;
	long hRes;

	DWORD dwType;
	DWORD dwSize;
	hRes = ::RegOpenKeyEx(HKEY_CLASSES_ROOT, szControl, 0, KEY_ALL_ACCESS, &hKey1);
	if (hRes == ERROR_SUCCESS)
	{
		dwSize = 255;
		hRes = RegQueryValueEx(hKey1, TEXT(""), 0, &dwType, (BYTE *)&szDescription, &dwSize);
		if (hRes == ERROR_SUCCESS)
		{
			hRes = ::RegOpenKeyEx(hKey1, TEXT("CLSID"), 0, KEY_ALL_ACCESS, &hKey2);
			if (hRes == ERROR_SUCCESS)
			{
				dwSize = 255;
				hRes = RegQueryValueEx(hKey2, TEXT(""), 0, &dwType, (BYTE *)&szUUID, &dwSize);
				if (hRes == ERROR_SUCCESS)
				{
					for (short i = 0; i < 6; i++)
					{
						strcpy(szKey, szPrefix);
						strcat(szKey, szPlatforms[i]);
						strcat(szKey, szSuffix);

						hRes = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, szKey, 0, KEY_ALL_ACCESS, &hKey3);
						if (hRes == ERROR_SUCCESS)
						{                          
							hRes = ::RegSetValueEx(hKey3, szUUID, 0, REG_SZ, (BYTE *)szDescription, (strlen(szDescription) + 1) * sizeof(TCHAR)); 
							::RegCloseKey(hKey3);
						}
					}
				}
				::RegCloseKey(hKey2);
			}
		}
		::RegCloseKey(hKey1);
	}
#endif

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
