#if !defined(AFX_URLIMAGE_H__C2AD3A4F_BD2A_4C1D_A9C6_95A205449796__INCLUDED_)
#define AFX_URLIMAGE_H__C2AD3A4F_BD2A_4C1D_A9C6_95A205449796__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UrlImage.h : header file
//

#include <wininet.h>
#include "UrlImageData.h"


/////////////////////////////////////////////////////////////////////////////
// CUrlImage thread

class CUrlImage : public CWinThread
{
	DECLARE_DYNCREATE(CUrlImage)
protected:

// Attributes
public:
	CUrlImage();           // protected constructor used by dynamic creation

// Operations
public:
	INTERNET_SCHEME m_nScheme;
	CString m_strHeaders;
	DWORD m_dwStatus;
	void Abort(BOOL bClearNotifyWnd = FALSE);
	DWORD m_dwHeaderBufferLength;
	DWORD m_dwReadBufferLength;
	DWORD m_dwSeperatorBufferLength;
	DWORD GetUrl(CWnd *pNotifyWnd, UINT message, LPCTSTR lpszUrl, LPCTSTR lpszUser, LPCTSTR lpszPassword, long lURLFlags, LPCTSTR lpszAgent, long lImageLoadBufferSize);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUrlImage)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
	virtual ~CUrlImage();
protected:

	// Generated message map functions
	//{{AFX_MSG(CUrlImage)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	static void CALLBACK InternetStatusCallback(HINTERNET hInternet, DWORD dwContext, DWORD dwInternetStatus, LPVOID lpvStatusInformation, DWORD dwStatusInformationLength);
	DWORD Prep();
	void StopThread();
	BOOL HaveMoreData(DWORD& dwBytesAvailable);
	BOOL m_bInQuery;
	BOOL m_bAbort;
	BOOL m_bPush;
	HINTERNET m_hInternet;
	HINTERNET m_hInternetOpenUrl;
	CUrlImageData *m_pImageData;
	BOOL m_bFirstTime;
	BOOL m_bLookingForHeader;
	BOOL m_bLookingForSeperator;
	BOOL Process(DWORD dwBufferLength);
	BOOL ProcessFtp(DWORD dwBufferLength);
	DWORD m_dwHeaderLength;
	DWORD m_dwSeperatorLength;
	DWORD m_dwContentLength;
	long m_lURLFlags;
	long m_lImageLoadBufferSize;
	CCriticalSection m_csLock;
	CTypedPtrArray<CPtrArray, CUrlImageData *> m_DataArray;
	CWnd *m_pNotifyWnd;
	UINT m_message;
	CString m_strUrl;
	CString m_strUser;
	CString m_strPassword;
	CString m_strAgent;
	LPBYTE m_pHeaderBuffer;
	LPBYTE m_pReadBuffer;
	LPBYTE m_pSeperatorBuffer;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_URLIMAGE_H__C2AD3A4F_BD2A_4C1D_A9C6_95A205449796__INCLUDED_)
