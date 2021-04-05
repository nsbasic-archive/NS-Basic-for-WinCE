// UrlImageData.h: interface for the CUrlImageData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_URLIMAGEDATA_H__1F34D99F_7686_49E6_B4EE_712C12793C39__INCLUDED_)
#define AFX_URLIMAGEDATA_H__1F34D99F_7686_49E6_B4EE_712C12793C39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUrlImageData : public CObject  
{
public:
	BOOL AddDataToArray(LPBYTE pData, DWORD dwLength);
	BOOL AllocateArray(DWORD dwLength);
	BOOL ReallocateArray(DWORD dwLength);
	DWORD m_dwByteArrayLength;
	DWORD m_dwByteArrayIndex;
	LPBYTE m_pByteArray;
	CUrlImageData();
	virtual ~CUrlImageData();
	LPVOID m_pUrlImage;
};

#endif // !defined(AFX_URLIMAGEDATA_H__1F34D99F_7686_49E6_B4EE_712C12793C39__INCLUDED_)
