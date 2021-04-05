// UrlImage.cpp : implementation file
//

#include "stdafx.h"
#include "NSCEPictureBox.h"
#include "UrlImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUrlImage

IMPLEMENT_DYNCREATE(CUrlImage, CWinThread)

CUrlImage::CUrlImage()
{
	m_strAgent = TEXT("NSBasic CE UrlImage");
	m_lURLFlags = INTERNET_FLAG_PASSIVE | INTERNET_FLAG_DONT_CACHE;
	m_bPush = FALSE;
	m_dwStatus = 0;
	m_bAutoDelete = FALSE;
	m_pNotifyWnd = NULL;
	m_DataArray.SetSize(0);
	m_dwHeaderBufferLength = 4096;
	m_dwReadBufferLength = 8192;
	m_lImageLoadBufferSize = m_dwReadBufferLength;
	m_dwSeperatorBufferLength = 1024;
	m_dwContentLength = 0;
	m_pHeaderBuffer = NULL;
	m_pReadBuffer = NULL;
	m_pSeperatorBuffer = NULL;
	m_pImageData = NULL;
	m_bFirstTime = TRUE;
	m_bLookingForHeader = FALSE;
	m_bLookingForSeperator = FALSE;
	m_hInternet = NULL;
	m_hInternetOpenUrl = NULL;
	m_bAbort = FALSE;
	m_bInQuery = FALSE;

	m_strUrl.Empty();
	m_strUser.Empty();
	m_strPassword.Empty();
	m_strHeaders.Empty();
}

CUrlImage::~CUrlImage()
{
	Abort();

	if (NULL != m_hInternetOpenUrl)
	{
		HINTERNET hInternetOpenUrl = m_hInternetOpenUrl;
		m_hInternetOpenUrl = NULL;
		if (!InternetCloseHandle(hInternetOpenUrl))
		{
			AfxMessageBox(TEXT("InternetCloseHandle error 3"));
		}
	}

	if (NULL != m_hInternet)
	{
		HINTERNET hInternet = m_hInternet;
		m_hInternet = NULL;
		if (!InternetCloseHandle(hInternet))
		{
			AfxMessageBox(TEXT("InternetCloseHandle error 4"));
		}
	}

	if (NULL != m_pImageData)
	{
		delete m_pImageData;
		m_pImageData = NULL;
	}

	for (long lIndex = m_DataArray.GetUpperBound(); lIndex > -1; lIndex--)
	{
		delete m_DataArray[lIndex];
		m_DataArray.RemoveAt(lIndex);
	}

	if (NULL != m_pHeaderBuffer)
	{
		delete m_pHeaderBuffer;
		m_pHeaderBuffer = NULL;
	}

	if (NULL != m_pReadBuffer)
	{
		delete m_pReadBuffer;
		m_pReadBuffer = NULL;
	}

	if (NULL != m_pHeaderBuffer)
	{
		delete m_pSeperatorBuffer;
		m_pSeperatorBuffer = NULL;
	}
}

BOOL CUrlImage::InitInstance()
{
	return TRUE;
}

int CUrlImage::ExitInstance()
{
	if (NULL != m_pImageData)
	{
		if ((NULL != m_pNotifyWnd) && ::IsWindow(m_pNotifyWnd->GetSafeHwnd()))
		{
			CUrlImageData *pImageData = m_pImageData;
			m_pImageData = NULL;
			m_pNotifyWnd->PostMessage(m_message, 2, (LPARAM)pImageData);
		}
		else
		{
			delete m_pImageData;
			m_pImageData = NULL;
		}
	}

	if ((NULL != m_pNotifyWnd) && ::IsWindow(m_pNotifyWnd->GetSafeHwnd()))
	{
		m_pNotifyWnd->PostMessage(m_message, 1, (LPARAM)this);
	}
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUrlImage, CWinThread)
	//{{AFX_MSG_MAP(CUrlImage)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUrlImage message handlers

int CUrlImage::Run() 
{
	DWORD dwTotalBytes = 0;
	if (m_hInternetOpenUrl)
	{
		if ((m_dwStatus > 199) && (m_dwStatus < 400))
		{
			BOOL bReturn = FALSE;

			DWORD dwBytesRead = 0;
			DWORD dwBytesAvailable = 0;
			DWORD dwBytesToRead = 0;

			while (HaveMoreData(dwBytesAvailable))
			{
				if ((0 == dwBytesAvailable) || m_bAbort)
				{
					break;
				}

				dwTotalBytes += dwBytesAvailable;
				dwBytesToRead = dwBytesAvailable;
				if (dwBytesToRead > m_dwReadBufferLength)
				{
					dwBytesToRead = m_dwReadBufferLength;
				}

				while ((dwBytesAvailable > 0) && !m_bAbort)
				{
					bReturn = InternetReadFile(m_hInternetOpenUrl, 
						m_pReadBuffer, 
						dwBytesToRead, 
						&dwBytesRead);

					switch (m_nScheme)
					{
						case INTERNET_SCHEME_HTTP:
						case INTERNET_SCHEME_HTTPS:
							if (!Process(dwBytesRead))
							{
								m_bAbort = TRUE;
							}
							break;
						case INTERNET_SCHEME_FTP:
							if (!ProcessFtp(dwBytesRead))
							{
								m_bAbort = TRUE;
							}
							break;
						default:
							break;
					}
					dwBytesAvailable -= dwBytesRead;
				}
			}
		}
	}

	return ExitInstance();
}

DWORD CUrlImage::Prep() 
{
	long lReturn = 0;
	DWORD dwStatusSize = sizeof(m_dwStatus);
	LPTSTR lpszUser = NULL;
	LPTSTR lpszPassword = NULL;
	LPTSTR lpszUrl = NULL;
	DWORD dwUrlLength;
	URL_COMPONENTS uc;

	memset(&uc, 0 , sizeof(URL_COMPONENTS));
	uc.dwStructSize = sizeof(URL_COMPONENTS);
	uc.dwExtraInfoLength = 255;
	uc.dwHostNameLength = 255;
	uc.dwPasswordLength = 255;
	uc.dwSchemeLength = 255;
	uc.dwUrlPathLength = 255;
	uc.dwUserNameLength = 255;

	if (InternetCrackUrl(m_strUrl, 0, 0, &uc))
	{
		if (m_lImageLoadBufferSize > 0)
		{
			m_dwReadBufferLength = m_lImageLoadBufferSize;
		}
		m_nScheme = uc.nScheme;
		switch (uc.nScheme)
		{
			case INTERNET_SCHEME_HTTP:
			case INTERNET_SCHEME_HTTPS:
				break;
			case INTERNET_SCHEME_FTP:
				dwUrlLength = m_strUser.GetLength() + m_strPassword.GetLength() + uc.dwExtraInfoLength + uc.dwHostNameLength + uc.dwSchemeLength + uc.dwUrlPathLength + 10;
				lpszUrl = new TCHAR[dwUrlLength];

				uc.dwPasswordLength = m_strPassword.GetLength();
				lpszPassword = (LPTSTR)(LPCTSTR)m_strPassword;
				uc.lpszPassword = lpszPassword;
				uc.dwUserNameLength = m_strUser.GetLength();
				lpszUser = (LPTSTR)(LPCTSTR)m_strUser;
				uc.lpszUserName = lpszUser;;

				if (InternetCreateUrl(&uc, 0, lpszUrl, &dwUrlLength))
				{
					m_strUrl = lpszUrl;
				}

				delete lpszUrl;
				lpszUrl = NULL;
				break;
			default:
				return 0;
				break;
		}
	}

	m_hInternet = InternetOpen(m_strAgent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (m_hInternet)
	{
		bool bContinue = true;
		bool bDone = false;
		while (bContinue)
		{
			m_hInternetOpenUrl = InternetOpenUrl(m_hInternet, m_strUrl, NULL, 
				0, m_lURLFlags, 0);

			if (!m_hInternetOpenUrl)
			{
				bContinue = false;
			}
			else
			{
				CString strAuth;
				CString strTest;
				switch (m_nScheme)
				{
					default:
						bContinue = false;
						break;
					case INTERNET_SCHEME_HTTP:
					case INTERNET_SCHEME_HTTPS:
						HttpQueryInfo(m_hInternetOpenUrl, HTTP_QUERY_FLAG_NUMBER | 
									  HTTP_QUERY_STATUS_CODE, &m_dwStatus, &dwStatusSize, 0);

						switch (m_dwStatus)
						{
							default:
								bContinue = false;
								break;
							case HTTP_STATUS_DENIED:     //Server Authentication Required
								if (!InternetCloseHandle(m_hInternetOpenUrl))
								{
									AfxMessageBox(TEXT("InternetCloseHandle error"));
								}

								m_hInternetOpenUrl = NULL;

								memset(&uc, 0 , sizeof(URL_COMPONENTS));
								uc.dwStructSize = sizeof(URL_COMPONENTS);
								uc.dwExtraInfoLength = 255;
								uc.dwHostNameLength = 255;
								uc.dwPasswordLength = 255;
								uc.dwSchemeLength = 255;
								uc.dwUrlPathLength = 255;
								uc.dwUserNameLength = 255;

								if (InternetCrackUrl(m_strUrl, 0, 0, &uc))
								{

									dwUrlLength = m_strUser.GetLength() + m_strPassword.GetLength() + uc.dwExtraInfoLength + uc.dwHostNameLength + uc.dwSchemeLength + uc.dwUrlPathLength + 10;
									lpszUrl = new TCHAR[dwUrlLength];

									uc.dwPasswordLength = m_strPassword.GetLength();
									lpszPassword = (LPTSTR)(LPCTSTR)m_strPassword;
									uc.lpszPassword = lpszPassword;
									uc.dwUserNameLength = m_strUser.GetLength();
									lpszUser = (LPTSTR)(LPCTSTR)m_strUser;
									uc.lpszUserName = lpszUser;;

									if (InternetCreateUrl(&uc, 0, lpszUrl, &dwUrlLength))
									{
										m_strUrl = lpszUrl;
									}

									delete lpszUrl;
									lpszUrl = NULL;
								}

								if (bDone)
								{
									bContinue = false;
								}
								bDone = true;
								break;
						}
						break;
				}
			}
		}

		if (m_hInternetOpenUrl)
		{
			if (NULL == m_pSeperatorBuffer)
			{
				m_pSeperatorBuffer = new BYTE[m_dwSeperatorBufferLength];
			}

			if (NULL == m_pHeaderBuffer)
			{
				m_pHeaderBuffer = new BYTE[m_dwHeaderBufferLength];
			}

			if (NULL == m_pReadBuffer)
			{
				m_pReadBuffer = new BYTE[m_dwReadBufferLength];
			}

			m_dwHeaderLength = m_dwHeaderBufferLength;
			char *lpCL = NULL;
			switch (m_nScheme)
			{
				default:
					m_dwStatus = 200;
					m_dwHeaderLength = 0;
					break;
				case INTERNET_SCHEME_HTTP:
				case INTERNET_SCHEME_HTTPS:
					if (!HttpQueryInfo(m_hInternetOpenUrl, 
						HTTP_QUERY_RAW_HEADERS_CRLF,
						(LPVOID)m_pHeaderBuffer, 
						&m_dwHeaderLength,
						0))
					{
						m_dwHeaderLength = 0;
					}
				
					if (m_pHeaderBuffer[1] == 0)
					{
						m_strHeaders = (LPCWSTR)m_pHeaderBuffer; 
						LPBYTE pHeaderBuffer;
						pHeaderBuffer = new BYTE[m_dwHeaderLength + 1];
						memcpy(pHeaderBuffer, m_pHeaderBuffer, m_dwHeaderLength);
						wcstombs((char *)m_pHeaderBuffer, (WCHAR *)pHeaderBuffer, wcslen((WCHAR *)pHeaderBuffer));
						delete pHeaderBuffer;
					}
					else
					{
						m_strHeaders = (LPCSTR)m_pHeaderBuffer; 
					}

					lpCL = strstr((char *)&m_pHeaderBuffer[0], "Content-type: ");
					if (NULL == lpCL)
					{
						lpCL = strstr((char *)&m_pHeaderBuffer[0], "Content-Type: ");
					}
					if (NULL != lpCL)                       
					{
						lpCL += 14;       
						if (0 == strncmp(lpCL, "multipart/x-mixed-replace;boundary=", 35))
						{
							m_bPush = TRUE;
						}
					}
					break;
			}
		}
	}

	return m_dwStatus;
}

DWORD CUrlImage::GetUrl(CWnd *pNotifyWnd, UINT message, LPCTSTR lpszUrl, LPCTSTR lpszUser, LPCTSTR lpszPassword, long lURLFlags, LPCTSTR lpszAgent, long lImageLoadBufferSize)
{
	DWORD dwReturn = 0;

	m_pNotifyWnd = pNotifyWnd;

	m_message = message;
	m_strUrl = lpszUrl;
	m_strUser = lpszUser;
	m_strPassword = lpszPassword;
	m_lURLFlags = lURLFlags;
	m_strAgent = lpszAgent;
	m_lImageLoadBufferSize = lImageLoadBufferSize;

	dwReturn = Prep();

	if ((m_dwStatus > 199) && (m_dwStatus < 400))
	{
		if (m_bPush)
		{
			CreateThread();
		}
		else
		{
			Run();
		}
	}
	else
	{
		ExitInstance();
	}

	return dwReturn;
}

BOOL CUrlImage::Process(DWORD dwBufferLength)
{
	BOOL bReturn = TRUE;

	LPBYTE lpCR = NULL;
	LPBYTE lpBuffer = NULL;
	DWORD dwBufferIndex = 0;
	DWORD dwBytesLeft = 0;
	while (dwBufferIndex < dwBufferLength)
	{
		lpBuffer = &m_pReadBuffer[dwBufferIndex];
		dwBytesLeft = dwBufferLength - dwBufferIndex;
		if (m_bFirstTime)
		{
			m_bLookingForHeader = false;
			m_dwContentLength = 0;
			if (m_dwHeaderLength > 0)
			{
				char *lpCL = strstr((char *)&m_pHeaderBuffer[0], "Content-type: ");
				if (NULL == lpCL)
				{
					lpCL = strstr((char *)&m_pHeaderBuffer[0], "Content-Type: ");
				}
				if (NULL != lpCL)                       
				{
					lpCL += 14;       
					if (0 == strncmp(lpCL, "multipart/x-mixed-replace;boundary=", 35))
					{
						lpCL += 35;
						m_pSeperatorBuffer[0] = '\n';
						m_pSeperatorBuffer[1] = '-';
						m_pSeperatorBuffer[2] = '-';
						m_dwSeperatorLength = 3;
						lpCR = (LPBYTE)memchr(lpCL, '\r', dwBytesLeft);
						if (NULL != lpCR)
						{
							memcpy(&m_pSeperatorBuffer[m_dwSeperatorLength], lpCL, lpCR - (LPBYTE)lpCL);
							m_dwSeperatorLength += lpCR - (LPBYTE)lpCL;
							m_pSeperatorBuffer[m_dwSeperatorLength] = '\n';
							m_dwSeperatorLength++;
							m_bLookingForHeader = true;
						}
					}
					else
					{
						char *lpCL = strstr((char *)&m_pHeaderBuffer[0], "Content-Length: ");
						if (NULL != lpCL)                       
						{
							lpCL += 16;       
							m_dwContentLength = atol((const char *)lpCL);
						}
					}
				}
			}

			m_bFirstTime = false;
			m_dwHeaderLength = 0;

			continue;
		}

		if (m_bLookingForHeader)
		{
			lpCR = (LPBYTE)memchr(lpBuffer, '\n', dwBytesLeft);
			if (NULL == lpCR) 
			{
				memcpy(&m_pHeaderBuffer[m_dwHeaderLength], lpBuffer, (lpCR - lpBuffer) + 1);
				m_dwHeaderLength += (lpCR - lpBuffer) + 1;
				dwBufferIndex  += (lpCR - lpBuffer) + 1;
			}
			else
			{
				if ((lpCR == lpBuffer) && (m_dwHeaderLength > 0))
				{
					m_bLookingForHeader = false;

					char *lpCL = strstr((char *)&m_pHeaderBuffer[0], "Content-Length: ");
					if (NULL != lpCL)                       
					{
						lpCL += 16;
						m_dwContentLength = atol((const char *)lpCL);
					}
					else
					{
						m_dwContentLength = 0;
					}
				}
				memcpy(&m_pHeaderBuffer[m_dwHeaderLength], lpBuffer, (lpCR - lpBuffer) + 1);
				m_dwHeaderLength += (lpCR - lpBuffer) + 1;
				dwBufferIndex += (lpCR - lpBuffer) + 1;
			}

			continue;
		}

		if (NULL == m_pImageData)
		{
			m_pImageData = new CUrlImageData;
			m_pImageData->m_pUrlImage = this;
			m_pImageData->AllocateArray(m_dwContentLength);
		}

		DWORD dwBytes = dwBytesLeft;
		if ((m_pImageData->m_dwByteArrayIndex + dwBytes) > m_pImageData->m_dwByteArrayLength)
		{
			dwBytes = m_pImageData->m_dwByteArrayLength - m_pImageData->m_dwByteArrayIndex;
		}

		dwBufferIndex += dwBytes;
		if (m_pImageData->AddDataToArray(lpBuffer, dwBytes))
		{
			if ((NULL != m_pNotifyWnd) && ::IsWindow(m_pNotifyWnd->GetSafeHwnd()))
			{
				CUrlImageData *pImageData = m_pImageData;
				m_pImageData = NULL;
				m_pNotifyWnd->PostMessage(m_message, 2, (LPARAM)pImageData);
			}
			else
			{
				bReturn = FALSE;
				delete m_pImageData;
				m_pImageData = NULL;
			}
			m_bLookingForHeader = true;
			m_dwHeaderLength = 0;
			m_dwContentLength = 0;
			continue;
		}
	}

	return bReturn;
}

BOOL CUrlImage::ProcessFtp(DWORD dwBufferLength)
{
	BOOL bReturn = TRUE;

	if (0 < dwBufferLength)
	{
		if (NULL == m_pImageData)
		{
			m_pImageData = new CUrlImageData;
			m_pImageData->m_pUrlImage = this;
			m_pImageData->AllocateArray(dwBufferLength);
		}
		else
		{
			m_pImageData->ReallocateArray(dwBufferLength);
		}

		m_pImageData->AddDataToArray(m_pReadBuffer, dwBufferLength);
	}
	return bReturn;
}

void CUrlImage::Abort(BOOL bClearNotifyWnd)
{
	if (bClearNotifyWnd)
	{
		m_pNotifyWnd = NULL;
	}

	m_bAbort = TRUE;

	if (NULL != m_hInternetOpenUrl)
	{
		HINTERNET hInternetOpenUrl = m_hInternetOpenUrl;
		m_hInternetOpenUrl = NULL;
		if (!InternetCloseHandle(hInternetOpenUrl))
		{
			AfxMessageBox(TEXT("InternetCloseHandle error 1"));
		}
	}

	StopThread();

	if (NULL != m_hInternet)
	{
		HINTERNET hInternet = m_hInternet;
		m_hInternet = NULL;
		if (!InternetCloseHandle(hInternet))
		{
			AfxMessageBox(TEXT("InternetCloseHandle error 2"));
		}
	}

	if (bClearNotifyWnd)
	{
		m_bAutoDelete = TRUE;
	}

}

BOOL CUrlImage::HaveMoreData(DWORD &dwBytesAvailable)
{
	BOOL bReturn;

	m_bInQuery = TRUE;
	bReturn = InternetQueryDataAvailable(m_hInternetOpenUrl,
				&dwBytesAvailable, 
				0, 
				0);
	m_bInQuery = FALSE;
	return bReturn;
}

void CUrlImage::StopThread()
{
	DWORD dwExitCode;

	if (GetExitCodeThread(m_hThread, &dwExitCode))
	{
		if (dwExitCode == STILL_ACTIVE)
		{
			BOOL ok = TerminateThread(m_hThread, 0);
		}
	}
}

