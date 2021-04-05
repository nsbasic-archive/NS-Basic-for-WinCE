// UrlImageData.cpp: implementation of the CUrlImageData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NSCEPictureBox.h"
#include "UrlImageData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUrlImageData::CUrlImageData()
{
	m_dwByteArrayLength = 0;
	m_dwByteArrayIndex = 0;
	m_pByteArray = NULL;
	m_pUrlImage = NULL;
}

CUrlImageData::~CUrlImageData()
{
	if (m_pByteArray != NULL)
	{
		delete m_pByteArray;
		m_pByteArray = NULL;
		m_dwByteArrayLength = 0;
		m_dwByteArrayIndex = 0;
	}
}

BOOL CUrlImageData::AllocateArray(DWORD dwLength)
{
	if (m_pByteArray != NULL)
	{
		delete m_pByteArray;
		m_pByteArray = NULL;
	}

	m_dwByteArrayLength = 0;
	m_dwByteArrayIndex = 0;

	m_pByteArray = new BYTE[dwLength];
	if (m_pByteArray != NULL)
	{
		m_dwByteArrayLength = dwLength;
		m_dwByteArrayIndex = 0;

		return TRUE;
	}

	return FALSE;
}

BOOL CUrlImageData::ReallocateArray(DWORD dwLength)
{
	LPBYTE pByteArray = m_pByteArray;

	m_pByteArray = new BYTE[m_dwByteArrayLength + dwLength];

	if (NULL != m_pByteArray) 
	{
		if (NULL == pByteArray)
		{
			m_dwByteArrayLength = dwLength;
			m_dwByteArrayIndex = 0;
		}
		else
		{
			memcpy(m_pByteArray, pByteArray, m_dwByteArrayLength); 
			delete pByteArray;
			m_dwByteArrayLength += dwLength;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CUrlImageData::AddDataToArray(LPBYTE pData, DWORD dwLength)
{
	DWORD dwMaxLength = dwLength;
	if ((m_dwByteArrayIndex + dwMaxLength) > m_dwByteArrayLength)
	{
		dwMaxLength = m_dwByteArrayLength - m_dwByteArrayIndex;
	}

	memcpy(&m_pByteArray[m_dwByteArrayIndex], pData, dwMaxLength);

	m_dwByteArrayIndex += dwMaxLength;

	return (m_dwByteArrayIndex == m_dwByteArrayLength);
}
