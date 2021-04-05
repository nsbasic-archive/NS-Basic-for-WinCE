
#include "stdafx.h"
#include "Res.h"

#ifndef UNUSED
#  define UNUSED(var)		var
#endif

#undef HPC_EMU
#ifdef _WIN32_WCE_EMULATION
#ifdef WIN32_PLATFORM_HPC
#define HPC_EMU 
#endif // WIN32_PLATFORM_HPC
#endif // _WIN32_WCE_EMULATION

#ifdef HPC_EMU
	typedef LPVOID (__stdcall *LockResourceProc)(HGLOBAL);
#endif HPC_EMU

BOOL CeVersionInfo::Load(LPBYTE pDataIn)
{
	memset(&m_fileInfo, 0, sizeof m_fileInfo);

	BYTE* pData = pDataIn;

	WORD wLength = (*((WORD*)pData));		pData += sizeof WORD;
	WORD wValueLength = (*((WORD*)pData));	pData += sizeof WORD;
	WORD wType = (*((WORD*)pData));			pData += sizeof WORD;

	if (0 != wcsncmp((wchar_t*) pData, OLESTR("VS_VERSION_INFO"), 15))
	{
		OutputDebugString(_T("Invalid KEY expected VS_VERSION_INFO\n"));
		return FALSE;
	}

	// skip over the key and it's null terminator
	pData += (15+1) * sizeof (wchar_t);

	// put back on a DWORD boundry,
	// this is PADDING1
	pData += (pData-pDataIn) % sizeof DWORD;

	// this value is optional, it is only present if
	// wValueLength is non-zero
	if (wValueLength != 0)
	{
		// get the structure
		memcpy(&m_fileInfo, pData, sizeof m_fileInfo);
		
		if (0xfeef04bd != m_fileInfo.dwSignature)
			// not a valid VS_FIXEDFILEINFO structure...
			return FALSE;

		// put back on a DWORD boundry, this is only required
		// if there is a VALUE,
		// this is PADDING2
		pData += sizeof m_fileInfo;

		// force to DWORD boundry
		pData += (pData-pDataIn) % sizeof DWORD;

		// Trace the fileInfo
		/*
		TRACE("dwStrucVersion:     %08x\n", m_fileInfo.dwStrucVersion);
		TRACE("dwFileVersionMS:    %08x\n", m_fileInfo.dwFileVersionMS);
		TRACE("dwFileVersionLS:    %08x\n", m_fileInfo.dwFileVersionLS);
		TRACE("dwProductVersionMS: %08x\n", m_fileInfo.dwProductVersionMS);
		TRACE("dwProductVersionLS: %08x\n", m_fileInfo.dwProductVersionLS); 
		TRACE("dwFileFlagsMask:    %08x\n", m_fileInfo.dwFileFlagsMask);
		TRACE("dwFileFlags:        %08x\n", m_fileInfo.dwFileFlags);
		TRACE("dwFileOS:           %08x\n", m_fileInfo.dwFileOS); 
		TRACE("dwFileType:         %08x\n", m_fileInfo.dwFileType);
		TRACE("dwFileSubtype:      %08x\n", m_fileInfo.dwFileSubtype);
		TRACE("dwFileDateMS:       %08x\n", m_fileInfo.dwFileDateMS); 
		TRACE("dwFileDateLS:       %08x\n", m_fileInfo.dwFileDateLS); 
		*/
	}

	memset(&m_vfi, 0, sizeof m_vfi);
	memset(&m_sfi, 0, sizeof m_sfi);

	// rip through the children, these are either StringFileInfo or VersionFileInfo
	while (pDataIn + wLength > pData)
	{
		BYTE* pDataInfoStart = pData;

		WORD  wChildLength = (*((WORD*)pData));			pData += sizeof WORD;
		WORD  wChildValueLength = (*((WORD*)pData));	pData += sizeof WORD;
		WORD  wChildType = (*((WORD*)pData));			pData += sizeof WORD;

		if (0 == wcsncmp((wchar_t*) pData, OLESTR("VarFileInfo"), 11))
		{
//			OutputDebugString(_T("VarFileInfo Structure\n"));
			pData += 12 * sizeof(wchar_t);
			pData += (pData-pDataIn) % sizeof DWORD;

			WORD  wVerLength = (*((WORD*)pData));		pData += sizeof WORD;
			WORD  wVerValueLength = (*((WORD*)pData));	pData += sizeof WORD;
			WORD  wVerType = (*((WORD*)pData));			pData += sizeof WORD;

			wchar_t szKey[64];
			for (int ii = 0;   ; pData += sizeof(wchar_t), ii++)
			{
				szKey[ii] = *((wchar_t*) pData);
				if (szKey[ii] == 0)
					break;
			}

			pData += (pData-pDataIn) % sizeof DWORD;
			for (ii = 0; ii < wVerValueLength; ii++)
			{
				m_vfi.m_var[m_vfi.m_wCnt].m_dwValue[ii] = ((WORD*)pData)[ii];
				// print each word
				//TRACE(_T("%04hx"), m_vfi.m_var[ii].m_dwValue);
			}

			m_vfi.m_var[m_vfi.m_wCnt].m_wCnt = ii;
			m_vfi.m_wCnt++;
		}
		else if (0 == wcsncmp((wchar_t*) pData, OLESTR("StringFileInfo"), 14))
		{
//			OutputDebugString(_T("StringFileInfo Structure\n"));
			pData += 15 * sizeof(wchar_t);
			pData += (pData-pDataIn) % sizeof DWORD;

			// Start of a string table...
			BYTE* pStringTableStart = pData;

			WORD  wStrTabLength = (*((WORD*)pData));		pData += sizeof WORD;
			WORD  wStrTabValueLength = (*((WORD*)pData));	pData += sizeof WORD;
			WORD  wStrTabType = (*((WORD*)pData));			pData += sizeof WORD;

			wchar_t szLang[9];
			// extract the language information
			for (int ii = 0;  ; pData += sizeof(wchar_t), ii++)
			{
				szLang[ii] = *((wchar_t*) pData);
				if (szLang[ii] == 0)
				{
					pData += sizeof(wchar_t);
					break;
				}
			}

			m_sfi.m_st[m_sfi.m_wCnt].m_dwKey = wcstol(szLang, NULL, 16);
			wcscmp(m_sfi.m_st[m_sfi.m_wCnt].m_wszKey, szLang);

			// align on DWORD
			pData += (pData-pDataIn) % sizeof DWORD;

			// extract the String children
			while (pStringTableStart + wStrTabLength > pData)
			{
				BYTE* pStringStart = pData;
				WORD  wStrLength = (*((WORD*)pData));		pData += sizeof WORD;
				WORD  wStrValueLength = (*((WORD*)pData));	pData += sizeof WORD;
				WORD  wStrType = (*((WORD*)pData));			pData += sizeof WORD;

				wchar_t szDesc[64];
				for (int jj=0; ; pData += sizeof(wchar_t), jj++)
				{
					szDesc[jj] = *((wchar_t*) pData);
					if (szDesc[jj] == 0)
					{
						// skip past the null terminator
						pData += sizeof(wchar_t);
						break;
					}
				}
				//CString strDesc(szDesc);

				pData += (pData-pDataIn) % sizeof DWORD;

				wchar_t szString[256];
				if (wStrValueLength != 0)
				{
					if (0 == *((wchar_t*) pData))
						pData += sizeof DWORD;

					for (jj=0; ; pData += sizeof(wchar_t), jj++)
					{
						szString[jj] = *((wchar_t*) pData);
						if (szString[jj] == 0)
							break;
					}
				}
				else
					szString[0] = 0;

				if (!wcscmp(szDesc, OLESTR("CompanyName")))
					wcscpy(m_wszCompanyName, szString);
				else if (!wcscmp(szDesc, OLESTR("FileDescription")))
					wcscpy(m_wszFileDescription, szString);
				else if (!wcscmp(szDesc, OLESTR("FileVersion")))
					wcscpy(m_wszFileVersion, szString);
				else if (!wcscmp(szDesc, OLESTR("InternalName")))
					wcscpy(m_wszInternalName, szString);
				else if (!wcscmp(szDesc, OLESTR("OriginalFilename")))
					wcscpy(m_wszOriginalFilename, szString);
				else if (!wcscmp(szDesc, OLESTR("ProductName")))
					wcscpy(m_wszProductName, szString);
				else if (!wcscmp(szDesc, OLESTR("ProductVersion")))
					wcscpy(m_wszProductVersion, szString);
				else if (!wcscmp(szDesc, OLESTR("LegalCopyright")))
					wcscpy(m_wszFileCopyright, szString);
				

				//CString strString(szString);
				//OutputDebugStringW(szDesc);
				//OutputDebugStringW(L" - ");
				//OutputDebugStringW(szString);
				//OutputDebugStringW(L"\n");

				wcscpy(m_sfi.m_st[m_sfi.m_wCnt].m_sp[m_sfi.m_st[m_sfi.m_wCnt].m_wCnt].m_wszKey, szDesc);
				wcscpy(m_sfi.m_st[m_sfi.m_wCnt].m_sp[m_sfi.m_st[m_sfi.m_wCnt].m_wCnt].m_wszValue, szString);
				m_sfi.m_st[m_sfi.m_wCnt].m_wCnt++;

				pData = pStringStart + wStrLength;
				pData += (pData-pDataIn) % sizeof DWORD;
			}

			m_sfi.m_st[m_sfi.m_wCnt].m_wCnt++;
			m_sfi.m_wCnt++;
		}
		else
		{
			OutputDebugString(_T("Corrupt VS_VERSION_INFO...\n"));
		}

		// on to the next child
		pData = pDataInfoStart + wChildLength;
		pData += (pData-pDataIn) % sizeof(DWORD);
	}

	return TRUE;
}

CeVersionInfo::CeVersionInfo()
{
	memset(&m_fileInfo, 0, sizeof m_fileInfo);

	m_wszCompanyName[0] = 0;
	m_wszFileDescription[0] = 0;
	m_wszFileVersion[0] = 0;
	m_wszInternalName[0] = 0;
	m_wszOriginalFilename[0] = 0;
	m_wszProductName[0] = 0;
	m_wszProductVersion[0] = 0; 
}

CeResource::CeResource(HINSTANCE hInst)
{
	m_hInst = hInst;
}

CeResource::CeResource(LPCTSTR lpsz)
{
	Load(lpsz);
}

CeResource::~CeResource()
{
	if (m_hInst)
	{
		::FreeLibrary(m_hInst);
		m_hInst = NULL;
	}
}


// Methods for retrieving resources
bool CeResource::Load(LPCTSTR lpLibFileName)
{
#ifdef LoadLibraryEx

	// open the data file so that we don't need to load all the
	// modules' dependecies
	Attach (::LoadLibraryEx(lpLibFileName, NULL, LOAD_LIBRARY_AS_DATAFILE|DONT_RESOLVE_DLL_REFERENCES));

#else // LoadLibraryEx

	Attach(::LoadLibrary(lpLibFileName));

#endif

	return (m_hInst != NULL);
}

HRSRC CeResource::FindResource(LPCTSTR lpName, LPCTSTR lpType, WORD wLanguage)
{
	UNUSED(wLanguage);
	return ::FindResource(m_hInst, lpName, lpType);
}

HRSRC CeResource::FindResource(UINT nName, LPCTSTR lpType, WORD wLanguage)
{
	UNUSED(wLanguage);
	return ::FindResource(m_hInst, MAKEINTRESOURCE(nName), lpType);
}

LPVOID CeResource::LoadResource(HRSRC hRsrc, DWORD& dwSize)
{
	LPVOID pData = NULL;
	dwSize = ::SizeofResource(m_hInst, hRsrc);

	HGLOBAL hMem = ::LoadResource(m_hInst, hRsrc);
	if (hMem)
	{
#ifdef HPC_EMU
		LockResourceProc procLockResource;
		HINSTANCE hInst = LoadLibrary(TEXT("coredll.dll"));
		if (NULL != hInst)
		{
			procLockResource = (LockResourceProc)GetProcAddress(hInst, TEXT("LockResouce"));
			if (NULL != procLockResource)
			{
				pData = procLockResource(hMem);
			}
			FreeLibrary(hInst);
		}
#else // HPC_EMU
		pData = ::LockResource(hMem);
#endif // HPC_EMU
	}
	return pData;
}
// Methods for enumerating resources

