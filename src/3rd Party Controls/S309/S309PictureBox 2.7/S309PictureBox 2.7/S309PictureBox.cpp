// S309PictureBox.cpp : Implementation of CS309PictureBoxApp and DLL registration.

#include "stdafx.h"
#include "S309PictureBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CS309PictureBoxApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xd4d7c4b5, 0x2cc5, 0x11d3, { 0xae, 0x29, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };
const WORD _wVerMajor = 2;
const WORD _wVerMinor = 7;


////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxApp::InitInstance - DLL initialization

BOOL CS309PictureBoxApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxApp::ExitInstance - DLL termination

int CS309PictureBoxApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

//#ifdef _WIN32_WCE_PSPC
#ifdef _MIPS_
#if _WIN32_WCE < 300
//	AfxMessageBox(TEXT("S309PictureBox.ocx\r(c) Copyright 1999-2000 Software 309"), MB_OK, 0 );
#endif // _WIN32_WCE < 300
#endif // _MIPS_
//#endif
	
	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

#ifndef UNDER_CE	
	TCHAR szControl[] = TEXT("S309.PictureBox.1");  // this should be the only parameter to change

	TCHAR szPrefix[] = TEXT("SOFTWARE\\Microsoft\\Windows CE Tools\\Platform Manager\\{F384D888-F9AA-11D1-BB9E-00A0C9C9CCEE}\\");
	TCHAR szSuffix[] = TEXT("\\{F384D894-F9AA-11D1-BB9E-00A0C9C9CCEE}\\{B646D410-60A0-11D2-8B91-006008B0E597}");
	TCHAR szPlatforms[5][255];

	strcpy(szPlatforms[0], TEXT("{0B7D1301-289F-11D2-974F-00A0240918F0}")); // hpc 2.0
	strcpy(szPlatforms[1], TEXT("{74239C21-1DCA-11D2-9747-00A0240918F0}")); // hpc pro 2.11
	strcpy(szPlatforms[2], TEXT("{458BFDB0-A6A6-11D2-BBCF-00A0C9C9CCEE}")); // ppc 2.11
	strcpy(szPlatforms[3], TEXT("{6D5C6210-E14B-11D2-B72A-0000F8026CEE}")); // pocket pc
	strcpy(szPlatforms[4], TEXT("{0F9D255B-97DA-4641-A8E6-7A7411D2472F}")); // hpc 2000
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
					for (short i = 0; i < 5; i++)
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
