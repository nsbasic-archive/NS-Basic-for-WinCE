// S309PictureBox.cpp : Implementation of CS309PictureBoxApp and DLL registration.

#include "stdafx.h"
#include "S309PictureBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CS309PictureBoxApp NEAR theApp;

// {8F4A927F-908E-4e3a-99A5-24E5582F3FEA}
const GUID CDECL BASED_CODE _tlid =
		{ 0x8f4a927f, 0x908e, 0x4e3a, { 0x99, 0xa5, 0x24, 0xe5, 0x58, 0x2f, 0x3f, 0xea } };
//		{ 0xd4d7c4b5, 0x2cc5, 0x11d3, { 0xae, 0x29, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };
const WORD _wVerMajor = 2;
const WORD _wVerMinor = 8;


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

void RegisterControl(BOOL bDelete)
{
	HKEY hKey1;
	HKEY hKey2;
	long hRes;

	DWORD dwType;
	DWORD dwSize;
	DWORD dwDisposition;

	TCHAR szVersionX[] = _S309_CONTROL_VERSION_ ;

#ifndef UNDER_CE	
	HKEY hKey3;
	TCHAR szPrefix[] = TEXT("SOFTWARE\\Microsoft\\Windows CE Tools\\Platform Manager\\{F384D888-F9AA-11D1-BB9E-00A0C9C9CCEE}\\");
	TCHAR szSuffix[] = TEXT("\\{F384D894-F9AA-11D1-BB9E-00A0C9C9CCEE}\\{B646D410-60A0-11D2-8B91-006008B0E597}");
	TCHAR szPlatforms[6][255];

	_tcscpy(szPlatforms[0], TEXT("{0B7D1301-289F-11D2-974F-00A0240918F0}")); // hpc 2.0
	_tcscpy(szPlatforms[1], TEXT("{74239C21-1DCA-11D2-9747-00A0240918F0}")); // hpc pro 2.11
	_tcscpy(szPlatforms[2], TEXT("{458BFDB0-A6A6-11D2-BBCF-00A0C9C9CCEE}")); // ppc 2.11
	_tcscpy(szPlatforms[3], TEXT("{6D5C6210-E14B-11D2-B72A-0000F8026CEE}")); // pocket pc
	_tcscpy(szPlatforms[4], TEXT("{0F9D255B-97DA-4641-A8E6-7A7411D2472F}")); // hpc 2000
	_tcscpy(szPlatforms[5], TEXT("{DE9660AC-85D3-4C63-A6AF-46A3B3B83737}")); // Pocket PC 2002
	TCHAR szKey[255];
	TCHAR szDescription[255];
	TCHAR szUUID[255];

	hRes = ::RegOpenKeyEx(HKEY_CLASSES_ROOT, szVersionX, 0, KEY_ALL_ACCESS, &hKey1);
	if (ERROR_SUCCESS == hRes)
	{
		dwSize = 255;
		hRes = RegQueryValueEx(hKey1, TEXT(""), 0, &dwType, (BYTE *)&szDescription, &dwSize);
		if (ERROR_SUCCESS == hRes)
		{
			hRes = ::RegOpenKeyEx(hKey1, TEXT("CLSID"), 0, KEY_ALL_ACCESS, &hKey2);
			if (ERROR_SUCCESS == hRes)
			{
				dwSize = 255;
				hRes = RegQueryValueEx(hKey2, TEXT(""), 0, &dwType, (BYTE *)&szUUID, &dwSize);
				if (ERROR_SUCCESS == hRes)
				{
					for (short i = 0; i < 6; i++)
					{
						_tcscpy(szKey, szPrefix);
						_tcscat(szKey, szPlatforms[i]);
						_tcscat(szKey, szSuffix);

						hRes = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, szKey, 0, KEY_ALL_ACCESS, &hKey3);
						if (ERROR_SUCCESS == hRes)
						{                  
							if (bDelete)
							{
								hRes = ::RegDeleteValue(hKey3, szUUID);
							}
							else
							{
								hRes = ::RegSetValueEx(hKey3, szUUID, 0, REG_SZ, (BYTE *)szDescription, (_tcslen(szDescription) + 1) * sizeof(TCHAR)); 
							}
							::RegCloseKey(hKey3);
						}
					}
				}
				::RegCloseKey(hKey2);
			}
		}
		::RegCloseKey(hKey1);
	}
#endif // UNDER_CE

	BOOL bVersion1 = FALSE;
	TCHAR szVersion1[255] = _S309_CONTROL_BASE_;
	_tcscat(szVersion1, TEXT(".1"));
	hRes = ::RegOpenKeyEx(HKEY_CLASSES_ROOT, szVersion1, 0, KEY_ALL_ACCESS, &hKey1);
	if (ERROR_SUCCESS == hRes)
	{
		bVersion1 = TRUE;
		::RegCloseKey(hKey1);
	}

	if (bDelete)
	{
		TCHAR szSubKey[255] = _S309_CONTROL_BASE_;
		_tcscat(szSubKey, TEXT("\\CurVer"));
		hRes = ::RegOpenKeyEx(HKEY_CLASSES_ROOT,szSubKey, 0, KEY_ALL_ACCESS, &hKey1);
		if (ERROR_SUCCESS == hRes)
		{
			TCHAR szCLSID[255];
			dwSize = 255;
			hRes = RegQueryValueEx(hKey1, TEXT(""), 0, &dwType, (BYTE *)&szCLSID, &dwSize);
			if (ERROR_SUCCESS == hRes)
			{
				if (0 == _tcsicmp(szVersionX, szCLSID))
				{
					if (bVersion1)
					{
						hRes = ::RegSetValueEx(hKey1, TEXT(""), 0, REG_SZ, (BYTE *)szVersion1, (_tcslen(szVersion1) + 1) * sizeof(TCHAR)); 
						::RegCloseKey(hKey1);
						if (ERROR_SUCCESS != hRes)
						{
							hRes = ::RegDeleteKey(HKEY_CLASSES_ROOT, szSubKey);
							hRes = ::RegDeleteKey(HKEY_CLASSES_ROOT, _S309_CONTROL_BASE_);
						}
					}
					else
					{
						::RegCloseKey(hKey1);
						hRes = ::RegDeleteKey(HKEY_CLASSES_ROOT, szSubKey);
						hRes = ::RegDeleteKey(HKEY_CLASSES_ROOT, _S309_CONTROL_BASE_);
					}
				}
				else
				{
					::RegCloseKey(hKey1);
				}
			}
			else
			{
				::RegCloseKey(hKey1);
			}
		}
	}
	else
	{
#ifndef UNDER_CE	
		hRes = ::RegCreateKeyEx(HKEY_CLASSES_ROOT, _S309_CONTROL_BASE_, 0, TEXT(""), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey1, &dwDisposition);
#else // UNDER_CE
		hRes = ::RegCreateKeyEx(HKEY_CLASSES_ROOT, _S309_CONTROL_BASE_, 0, TEXT(""), 0, 0, NULL, &hKey1, &dwDisposition);
#endif // UNDER_CE
		if (ERROR_SUCCESS == hRes)
		{
			hRes = ::RegSetValueEx(hKey1, TEXT(""), 0, REG_SZ, (BYTE *)_S309_CONTROL_DESCRIPTION_, (_tcslen(_S309_CONTROL_DESCRIPTION_) + 1) * sizeof(TCHAR)); 
#ifndef UNDER_CE	
			hRes = ::RegCreateKeyEx(hKey1, TEXT("CurVer"), 0, TEXT(""), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey2, &dwDisposition);
#else // UNDER_CE
			hRes = ::RegCreateKeyEx(hKey1, TEXT("CurVer"), 0, TEXT(""), 0, 0, NULL, &hKey2, &dwDisposition);
#endif // UNDER_CE
			if (ERROR_SUCCESS == hRes)
			{
				hRes = ::RegSetValueEx(hKey2, TEXT(""), 0, REG_SZ, (BYTE *)szVersionX, (_tcslen(szVersionX) + 1) * sizeof(TCHAR)); 
				::RegCloseKey(hKey2);
			}
			::RegCloseKey(hKey1);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);
	
	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	RegisterControl(FALSE);

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

	RegisterControl(TRUE);

	return NOERROR;
}
