#ifndef __Res_h__
#define __Res_h__

typedef struct tagVS_FIXEDFILEINFO_CE
{
    DWORD   dwSignature;            /* e.g. 0xfeef04bd */
    DWORD   dwStrucVersion;         /* e.g. 0x00000042 = "0.42" */
    DWORD   dwFileVersionMS;        /* e.g. 0x00030075 = "3.75" */
    DWORD   dwFileVersionLS;        /* e.g. 0x00000031 = "0.31" */
    DWORD   dwProductVersionMS;     /* e.g. 0x00030010 = "3.10" */
    DWORD   dwProductVersionLS;     /* e.g. 0x00000031 = "0.31" */
    DWORD   dwFileFlagsMask;        /* = 0x3F for version "0.42" */
    DWORD   dwFileFlags;            /* e.g. VFF_DEBUG | VFF_PRERELEASE */
    DWORD   dwFileOS;               /* e.g. VOS_DOS_WINDOWS16 */
    DWORD   dwFileType;             /* e.g. VFT_DRIVER */
    DWORD   dwFileSubtype;          /* e.g. VFT2_DRV_KEYBOARD */
    DWORD   dwFileDateMS;           /* e.g. 0 */
    DWORD   dwFileDateLS;           /* e.g. 0 */
}
VS_FIXEDFILEINFO_CE;


#define MAX_VAR				16
#define MAX_VAR_INFO		16
#define MAX_STRING_TABLE	16
#define MAX_STRING_PAIR		16
#define MAX_STRING_LENGTH	128

class CeVar
{
public:
	WORD m_wCnt;
	DWORD m_dwValue[MAX_VAR];
};

class CeVarFileInfo
{
public:
	WORD m_wCnt;
	CeVar m_var[MAX_VAR_INFO];
};

class CeStringPair
{
public:
	WCHAR m_wszKey[MAX_STRING_LENGTH];
	WCHAR m_wszValue[MAX_STRING_LENGTH];
};

class CeStringTable
{
public:
	WCHAR m_wszKey[MAX_STRING_LENGTH];
	DWORD m_dwKey;
	WORD m_wCnt;
	CeStringPair m_sp[MAX_STRING_PAIR];
};

class CeStringFileInfo
{
public:
	WORD m_wCnt;
	CeStringTable m_st[MAX_STRING_TABLE];
};


class CeVersionInfo
{
public:
	VS_FIXEDFILEINFO_CE m_fileInfo;
	CeVarFileInfo m_vfi;
	CeStringFileInfo m_sfi;

	WCHAR m_wszCompanyName[MAX_STRING_LENGTH];
	WCHAR m_wszFileDescription[MAX_STRING_LENGTH];
	WCHAR m_wszFileVersion[MAX_STRING_LENGTH];
	WCHAR m_wszInternalName[MAX_STRING_LENGTH];
	WCHAR m_wszOriginalFilename[MAX_STRING_LENGTH];
	WCHAR m_wszProductName[MAX_STRING_LENGTH];
	WCHAR m_wszProductVersion[MAX_STRING_LENGTH];
	WCHAR m_wszFileCopyright[MAX_STRING_LENGTH];


	BOOL Load(LPBYTE pDataIn);
	CeVersionInfo();
};


class CeResource
{
private:
	HINSTANCE m_hInst;

public:
	void Attach(HINSTANCE hInst)
		{ m_hInst = hInst; }
	HINSTANCE Detach()
		{ HINSTANCE h = m_hInst; m_hInst = NULL; return h; }

	struct SCallbackArray
	{
		SCallbackArray()
			{ wCnt = 0; }

		WORD rgwRes[16];
		WORD wCnt;
	};

	CeResource(HINSTANCE hInst = NULL);
	CeResource(LPCTSTR lpsz);
	~CeResource();

// Methods for retrieving resources
	bool Load(LPCTSTR lpLibFileName);
	HRSRC FindResource(LPCTSTR lpName, LPCTSTR lpType, WORD wLanguage=0);
	HRSRC FindResource(UINT nName, LPCTSTR lpType, WORD wLanguage=0);
	LPVOID LoadResource(HRSRC hRsrc, DWORD& dwSize);
};


#endif // __Res_h__
