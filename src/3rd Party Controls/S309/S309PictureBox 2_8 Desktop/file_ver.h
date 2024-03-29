// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
//		File:		file_ver.h
//					----------
//
//		Content:	Declaration of class CFileVersionInfo and inline funcs.
//					Manages the retrieval of various information from a
//					Win32 file image.
//
//
//
//		Created:		01/24/2002
//						Thomas Weller
//
//		Last modified:	02/02/2002
//						Thomas Weller
//
//
// ----------------------------------------------------------------------------
//
//	Remarks
//	-------
//
//	- The "version.lib" library module must be added to project settings.
//
//	- A file's version resource may contain more than one version info block.
//	  If so, only the first one will be retrieved.
//
//	- Functions marked as "// inline" are defined in file_ver.inl.
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#if !defined(AFX_FILE_VER_H__BBB1EB1A_076F_405A_B71D_FDFA4256E34A__INCLUDED_)
#define AFX_FILE_VER_H__BBB1EB1A_076F_405A_B71D_FDFA4256E34A__INCLUDED_



//-----------------------------------------------------------------------------
//		includes
//-----------------------------------------------------------------------------

#include <winver.h>		// Win32 API File Installation Library

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




//*****************************************************************************
//*****************************************************************************
//
//							Constants
//							---------
//
//*****************************************************************************
//*****************************************************************************

// OS_xxx: various types of operating systems.
// Indices are intended to correspond to an application supplied string 
// resource which contains a list of names.
// See the GetTargetOs member function for details.
// *********************************************************************
#define OS_DOS					0
#define OS_WIN16				1
#define OS_WIN32				2
#define OS_WIN16_DOS			3
#define OS_WIN32_DOS			3
#define OS_OS216				5
#define OS_OS232				5
#define OS_WINNT				7
#define OS_WIN32_NT				8
#define OS_UNKNOWN				9




// FT_xxx: various file types.
// Indices are intended to correspond to an application supplied string 
// resource which contains a list of names.
// See the GetFiletype member function for details.
// *********************************************************************
#define FT_DRV_DISPLAY			 0
#define FT_DRV_INSTALLABLE		 1
#define FT_DRV_KEYBOARD			 2
#define FT_DRV_LANGUAGE			 3
#define FT_DRV_MOUSE			 4
#define FT_DRV_NETWORK			 5
#define FT_DRV_PRINTER			 6
#define FT_DRV_SOUND			 7
#define FT_DRV_SYSTEM			 8
#define FT_DRV_UNKNOWN			 9
#define FT_FONT_RASTER			10
#define FT_FONT_TRUETYPE		11
#define FT_FONT_VECTOR			12
#define FT_FONT_UNKNOWN			13
#define FT_APP					14
#define FT_DLL					15
#define FT_STATIC_LIB			16
#define FT_VXD					17
#define FT_UNKNOWN				18
#define FT_FIRST				FT_DRV_DISPLAY
#define FT_LAST					FT_UNKNOWN



// SFI_xxx: specific parts of information from a file's version info block.
// Indices correspond to m_lpszStringFileInfos[] string array.
// See GetVersionInfo member function for usage.
//*************************************************************************
#define SFI_COMPANYNAME			 0
#define SFI_FILEDESCRIPTION		 1
#define SFI_FILEVERSION			 2
#define SFI_INTERNALNAME		 3
#define SFI_LEGALCOPYRIGHT		 4
#define SFI_ORIGINALFILENAME	 5
#define SFI_PRODUCTNAME			 6
#define SFI_PRODUCTVERSION		 7
#define SFI_COMMENTS			 8
#define SFI_LEGALTRADEMARKS		 9
#define SFI_PRIVATEBUILD		10
#define SFI_SPECIALBUILD		11
#define SFI_FIRST				SFI_COMPANYNAME
#define SFI_LAST				SFI_SPECIALBUILD

		
		
		
//*****************************************************************************
//*****************************************************************************
//
//					CFileVersionInfo class declaration
//					----------------------------------
//
//*****************************************************************************
//*****************************************************************************

class CFileVersionInfo  
{
// Construction/destruction
public:
	CFileVersionInfo();
	CFileVersionInfo(const CFileVersionInfo& fvi);
	CFileVersionInfo(LPCTSTR lpszFile);
	~CFileVersionInfo();

// Operations
public:
	BOOL		ReadVersionInfo(const CString& strFile);
	BOOL		RefreshVersionInfo();						// inline		
	void		Clear();

// Attributes
public:

	const CString&	GetFilename()				const;		// inline
	BOOL			IsValid()					const;		// inline

	// Language and Charset
	// ********************
	WORD		GetCharSet()					const;		// inline
	CString		GetCharSetName()				const;		// inline
	WORD		GetLanguageId ()				const;		// inline
	CString		GetLanguageName()				const;		// inline

	// File Version
	// ************
	DWORD		GetMajorFileVersion()			const;		// inline
	DWORD		GetMinorFileVersion()			const;		// inline
	CString		GetFileVersionString()			const;		// inline
	CString		GetMajorFileVersionString()		const;		// inline
	CString		GetMinorFileVersionString()		const;		// inline

	// Product Version
	// ***************
	DWORD		GetMajorProductVersion()		const;		// inline
	DWORD		GetMinorProductVersion()		const;		// inline
	CString		GetProductVersionString()		const;		// inline
	CString		GetMajorProductVersionString()	const;		// inline
	CString		GetMinorProductVersionString()	const;		// inline

	// Date
	// ****
	FILETIME	GetFileDate()					const;		// inline

	// Operating System
	// ****************
	CString		GetTargetOs(UINT nID)			const;
	DWORD		GetTargetOs()					const;		// inline

	// Filetype
	// ********
	CString		GetFileType(UINT nID)			const;
	DWORD		GetFileType()					const;		// inline
	DWORD		GetFileSubtype()				const;		// inline

	CString		GetVersionInfo(int nIndex)			const;
	BOOL		IsVersionInfoAvailable(int nIndex)	const;

	// Boolean file attributes
	// ***********************
	BOOL		IsDebugVersion()				const;		// inline
	BOOL		IsPatched()						const;		// inline
	BOOL		IsPreRelease()					const;		// inline
	BOOL		IsPrivateBuild()				const;		// inline
	BOOL		IsSpecialBuild()				const;		// inline

// Implementation
protected:
	CString				m_strFilename;
	LPBYTE				m_pVersionInfo;
	DWORD				m_dwTransInfo;
	VS_FIXEDFILEINFO	m_fixedFileInfo;

	BOOL		IsFlagSet(DWORD dwFlag)			const;		// inline

// Static data members
private:
	static const LPCTSTR m_lpszFmtStringFileInfo;
	static const LPCTSTR m_lpszStringFileInfos[];

};	// CFileVersionInfo


#include "file_ver.inl"		// CFileVersionInfo inline functions



#endif // !defined(AFX_FILE_VER_H__BBB1EB1A_076F_405A_B71D_FDFA4256E34A__INCLUDED_)
