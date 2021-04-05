// NSBCE Stub.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#define BUFLEN	1000

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	SHELLEXECUTEINFO info;
	wchar_t doc[BUFLEN];
	memset(&info,0,sizeof(SHELLEXECUTEINFO));

	if (LoadString(hInstance, IDS_PROGRAMSTRING, doc, BUFLEN))
	{
		wchar_t selfName[BUFLEN];


		if (GetModuleFileName(hInstance, &(selfName[1]), BUFLEN - 2))
		{
			int k;
			HKEY key;

			selfName[0] = '"';
			for (k = 0; selfName[k]; ++k) {}
			selfName[k] = '"';
			selfName[k + 1] = 0;
			info.lpParameters = selfName;

			info.cbSize=sizeof(SHELLEXECUTEINFO);
			info.fMask = SEE_MASK_FLAG_NO_UI; //SEE_MASK_NOCLOSEPROCESS;
			info.hwnd = NULL;
			info.lpVerb = L"Open";
			info.lpFile = L"\\Program Files\\NS Basic\\Basic.exe";
			//info.lpFile = L"\\Basic.exe";	// DIKEO for test only
			//info.lpFile = L"\\My Documents\\BASIC Samples\\QSketch.nsb";
			//info.lpParameters = L"\"\\My Documents\\BASIC Samples\\QSketch.nsb\"";
			info.nShow = SW_SHOWNORMAL;

			// Try to get key from registry
			if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CLASSES_ROOT, L"nsbfile\\Shell\\Open\\Command",
					0, 0, &key))
			{
				wchar_t name[256];
				wchar_t value[256];
				wchar_t *s;
				DWORD nameSize = 256;
				DWORD valueSize = 256;
				DWORD type;

				if (ERROR_SUCCESS == RegEnumValue(key, 0, name, &nameSize, NULL, &type, (LPBYTE)value, &valueSize))
				{
					for (s = &value[0]; *s && '"' != *s; ++s) {}
					++s;
					info.lpFile = s;
					for (; *s && '"' != *s; ++s) {}
					*s = 0;

					if (!ShellExecuteEx(&info))
					{
						MessageBox(NULL, L"Cannot find NSBasic.exe.  Please reinstall.", L"ERROR", MB_OK);
					}
				}
				else
				{
					MessageBox(NULL, L"Could not retrieve registry value for NSBasic.  Please reinstall.", L"ERROR", MB_OK);
				}

				RegCloseKey(key);
			}
			else
			{
				MessageBox(NULL, L"Could not find registry for NSBasic.  Please reinstall.", L"ERROR", MB_OK);
			}
		}
		else
		{
			MessageBox(NULL, L"This program requires Windows CE 2.0 or later.  Please consult your documentation.", L"ERROR", MB_OK);
		}

	}
	else
	{
		MessageBox(NULL, L"NSBasic program is not present in executable.", L"ERROR", MB_OK);
	}
	return 0;
}

