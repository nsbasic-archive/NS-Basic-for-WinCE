// Tray.cpp : Implementation of CTray
#include "stdafx.h"
#include "Desk.h"
#include "Tray.h"

TCHAR   g_szCTrayWndClassName[] = TEXT("NSBasic3103200618");

/*
typedef struct _NOTIFYICONDATAEX { 
    DWORD cbSize; 
    HWND hWnd; 
    UINT uID; 
    UINT uFlags; 
    UINT uCallbackMessage; 
    HICON hIcon; 
    TCHAR szTip[64];
    DWORD dwState; //Version 5.0
    DWORD dwStateMask; //Version 5.0
    TCHAR szInfo[256]; //Version 5.0
    union {
        UINT  uTimeout; //Version 5.0
        UINT  uVersion; //Version 5.0
    } DUMMYUNIONNAME;
    TCHAR szInfoTitle[64]; //Version 5.0
    DWORD dwInfoFlags; //Version 5.0
} NOTIFYICONDATAEX, *PNOTIFYICONDATAEX;
*/

/////////////////////////////////////////////////////////////////////////////
// CTray

STDMETHODIMP CTray::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ITray
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CTray::FinalConstruct() {
    WNDCLASS    wc;
    ZeroMemory(&wc,sizeof(WNDCLASS));

    if (!::GetClassInfo(_Module.GetModuleInstance(),g_szCTrayWndClassName,&wc)) {
        // We need to register the class
        wc.lpfnWndProc = TrayWindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = _Module.GetModuleInstance();
		wc.hIcon = NULL;
		wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = g_szCTrayWndClassName;
        if (!RegisterClass(&wc)) return E_FAIL;
    }
    // We have the class
    m_hWndTray = ::CreateWindowEx(0,g_szCTrayWndClassName,NULL,WS_POPUP,0,0,0,0,NULL,NULL,_Module.GetModuleInstance(),(LPVOID)this);
    if (!m_hWndTray) return E_FAIL;
    return S_OK;
}
void    CTray::FinalRelease() {
    // We may need to kill the timers

    // Destroy the window
    ::DestroyWindow(m_hWndTray);
}

LRESULT CTray::WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL& bDone) {
    CComPtr<IDispatch>  spThis;
    NOTIFYICONDATA      nid;
    int                 n;
    switch (uMsg) {
        case WM_CREATE:
            m_hImageList = ImageList_Create( 16, 16, ILC_COLOR, 0, 32 );
		    m_lIconAdded = 0;
            m_uTaskBarRecreated = RegisterWindowMessage(TEXT("TaskbarCreated"));
		    bDone = TRUE;
		break;
        case WM_COMMAND:
            bDone = TRUE;
            if (QueryInterface(IID_IDispatch,(void**)&spThis) == S_OK) {
                if (wParam == 1000 && lParam == WM_LBUTTONDOWN) {
			        Fire_Click(spThis);
                } else if (wParam == 1000 && lParam == WM_RBUTTONDOWN) {
                    Fire_RClick(spThis);
                } else if (wParam == 1000 && lParam == WM_LBUTTONDBLCLK) {
                    Fire_DblClick(spThis);
                } else if (wParam == 1000 && lParam == WM_RBUTTONDBLCLK) {
                    Fire_RDblClick(spThis);
                } else if (wParam == 1000 && lParam == WM_KEYDOWN) {
                    Fire_KeyDown(spThis);
                }
            }
        break;
        case WM_DESTROY:
            if (m_lIconAdded) {
			    ZeroMemory( &nid, sizeof(NOTIFYICONDATA) );
			    nid.cbSize  = sizeof(NOTIFYICONDATA);
			    nid.hWnd    = hwnd;
			    nid.uID     = 1000;
			    nid.uCallbackMessage = WM_COMMAND;
			    Shell_NotifyIcon(NIM_DELETE, &nid);
		    }
		    if (m_hImageList) ImageList_Destroy(m_hImageList);
        break;
        default:
            if (uMsg == m_uTaskBarRecreated) {
                if (m_lIconAdded) {
                    // Add the icon again
                    ZeroMemory(&nid,sizeof(NOTIFYICONDATA));
	                nid.cbSize  = sizeof(NOTIFYICONDATA);
	                nid.hWnd    = m_hWndTray;
	                nid.uID     = 1000;
	                nid.uFlags  = NIF_ICON | NIF_MESSAGE;
	                nid.uCallbackMessage = WM_COMMAND;
	                nid.hIcon = ::ImageList_GetIcon(m_hImageList,m_lIconAdded - 1,ILD_NORMAL);
                    if (m_bstrTip.Length()) {
                        nid.uFlags |= NIF_TIP;
                        for (n = 0;n < 62 && m_bstrTip[n];n++) {
                            nid.szTip[n] = m_bstrTip[n];
                        }
                        nid.szTip[n] = L'\0';
                    }
	                Shell_NotifyIcon(NIM_ADD, &nid );
                }
            }
    }
    return 0;
}
LRESULT CALLBACK CTray::TrayWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
    CTray* pThis = (CTray*)::GetWindowLong(hwnd,GWL_USERDATA);
    BOOL    bDone = FALSE;
    LRESULT lr;
    switch (uMsg) {
        case WM_CREATE:
            ::SetWindowLong(hwnd,GWL_USERDATA,(LONG)((LPCREATESTRUCT)lParam)->lpCreateParams);
            pThis = (CTray*)::GetWindowLong(hwnd,GWL_USERDATA);
            if (pThis) return pThis->WindowProc(hwnd,uMsg,wParam,lParam,bDone);
            else return -1;
        break;
        case WM_DESTROY:
            if (pThis) pThis->WindowProc(hwnd,uMsg,wParam,lParam,bDone);
            SetWindowLong(hwnd,GWL_USERDATA,NULL);
            return 0;
        break;
        default:
            if (pThis) {
                lr = pThis->WindowProc(hwnd,uMsg,wParam,lParam,bDone);
                if (bDone) return lr;
            }
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

STDMETHODIMP CTray::get_Version(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = 201;
	return S_OK;
}

STDMETHODIMP CTray::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    ::VariantCopy(pVal,&m_vTag);
	return S_OK;
}

STDMETHODIMP CTray::put_Tag(VARIANT newVal) {
	m_vTag.Clear();
    ::VariantCopyInd(&m_vTag,&newVal);
	return S_OK;
}

STDMETHODIMP CTray::get_Image(long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = m_lIconAdded;
	return S_OK;
}

STDMETHODIMP CTray::put_Image(long newVal) {
	NOTIFYICONDATA  nid;
	HICON           hIcon;
	int             iCmd;

	if (!newVal && !m_lIconAdded ) return S_OK;

	if(!newVal && m_lIconAdded ) {
		ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
		nid.cbSize = sizeof(NOTIFYICONDATA);
		nid.hWnd = m_hWndTray;
		nid.uID = 1000;
		nid.uCallbackMessage = WM_COMMAND;
		Shell_NotifyIcon( NIM_DELETE, &nid );
		m_lIconAdded = 0;
		return S_OK;
	}

	hIcon = ::ImageList_GetIcon(m_hImageList,newVal - 1,ILD_NORMAL);
	if (!hIcon) {
		return Error(IDS_E_INVALIDIMAGEINDEX);
	}
	if (!m_lIconAdded) iCmd = NIM_ADD;
	else iCmd = NIM_MODIFY;
	ZeroMemory(&nid,sizeof(NOTIFYICONDATA));
	nid.cbSize  = sizeof(NOTIFYICONDATA);
	nid.hWnd    = m_hWndTray;
	nid.uID     = 1000;
	nid.uFlags  = NIF_ICON | NIF_MESSAGE;
	nid.uCallbackMessage = WM_COMMAND;
	nid.hIcon = hIcon;

    if (m_bstrTip.Length()) {
        nid.uFlags |= NIF_TIP;
        int n;
        for (n = 0;n < 62 && m_bstrTip[n];n++) {
            nid.szTip[n] = m_bstrTip[n];
        }
        nid.szTip[n] = L'\0';
    }


	Shell_NotifyIcon( iCmd, &nid );
	m_lIconAdded = newVal;

	return S_OK;
}

STDMETHODIMP CTray::AddImage(BSTR bstrImage, long *plAdded) {
	HBITMAP hBmp;
	int iAdd;

    #ifdef _WIN32_WCE
        hBmp = SHLoadDIBitmap(bstrImage);
    #else
        hBmp = (HBITMAP)LoadImage(NULL,bstrImage,IMAGE_BITMAP,0,0,0x0040 | 0x0010);
    #endif
    // Default size | load from file
    if (!hBmp) return Error(IDS_E_IMAGELOADFAILED);
	
	iAdd = ::ImageList_Add(m_hImageList, hBmp, NULL );
	::DeleteObject(hBmp);
	if (iAdd == -1) {
		return Error(IDS_E_IMAGEADDFAILED);
	}
    if (plAdded) *plAdded = (long)iAdd;
	return S_OK;
}

STDMETHODIMP CTray::RemoveImage(long lImage) {
	if (lImage < 1) {
		return Error( IDS_E_INVALIDIMAGEINDEX);
	}
	ImageList_Remove(m_hImageList,lImage - 1 );
	return S_OK;
}

STDMETHODIMP CTray::get_Tip(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bstrTip.Copy();
	return S_OK;
}

STDMETHODIMP CTray::put_Tip(BSTR newVal) {
	m_bstrTip = newVal;
	return S_OK;
}
