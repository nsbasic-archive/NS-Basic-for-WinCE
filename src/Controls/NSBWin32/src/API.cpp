// API.cpp : Implementation of CAPI
#include "stdafx.h"
#include "Desk.h"
#include "API.h"
#include "APIPosPoint.h"

// For compatibility with old SDK-s
typedef struct _api_MEMORYSTATUSEX {
    DWORD dwLength; 
    DWORD dwMemoryLoad; 
    DWORDLONG ullTotalPhys; 
    DWORDLONG ullAvailPhys; 
    DWORDLONG ullTotalPageFile; 
    DWORDLONG ullAvailPageFile; 
    DWORDLONG ullTotalVirtual; 
    DWORDLONG ullAvailVirtual; 
    DWORDLONG ullAvailExtendedVirtual;
} api_MEMORYSTATUSEX; 

TCHAR   g_szCAPIWndClassName[] = TEXT("NSBasic0404200624");

/////////////////////////////////////////////////////////////////////////////
// CAPI

STDMETHODIMP CAPI::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAPI
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CAPI::FinalConstruct() {
    WNDCLASS    wc;
    ZeroMemory(&wc,sizeof(WNDCLASS));

    if (!::GetClassInfo(_Module.GetModuleInstance(),g_szCAPIWndClassName,&wc)) {
        // We need to register the class
        wc.lpfnWndProc = APIWindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = _Module.GetModuleInstance();
		wc.hIcon = NULL;
		wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = g_szCAPIWndClassName;
        if (!RegisterClass(&wc)) return E_FAIL;
    }
    // We have the class
    m_hWndApi = ::CreateWindowEx(0,g_szCAPIWndClassName,NULL,WS_POPUP,0,0,0,0,NULL,NULL,_Module.GetModuleInstance(),(LPVOID)this);
    if (!m_hWndApi) return E_FAIL;
    return S_OK;
}
void    CAPI::FinalRelease() {
    // We may need to kill the timers

    // Destroy the window
    ::DestroyWindow(m_hWndApi);
}

LRESULT CAPI::WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL& bDone) {
    switch (uMsg) {
      #ifdef _WIN32_WCE
        case WM_HIBERNATE:
            Fire_Hibernate();
        break;
      #endif
        case WM_SYSCOLORCHANGE:
            Fire_ColorChange();
        break;
        case WM_FONTCHANGE:
            Fire_FontChange();
        break;
        case WM_PALETTECHANGED:
            Fire_PaletteChange();
        break;
        case WM_SETTINGCHANGE:
            Fire_SettingsChange((long)wParam);
        break;
    }
    return 0;
}
LRESULT CALLBACK CAPI::APIWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
    CAPI* pThis = (CAPI*)::GetWindowLong(hwnd,GWL_USERDATA);
    BOOL    bDone = FALSE;
    LRESULT lr;
    switch (uMsg) {
        case WM_CREATE:
            ::SetWindowLong(hwnd,GWL_USERDATA,(LONG)((LPCREATESTRUCT)lParam)->lpCreateParams);
            pThis = (CAPI*)::GetWindowLong(hwnd,GWL_USERDATA);
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

STDMETHODIMP CAPI::FindWindow(BSTR bstrTitle, long *plhWnd) {
    if (!plhWnd) return E_POINTER;
	*plhWnd = (long)::FindWindow(NULL,bstrTitle);
	return S_OK;
}

STDMETHODIMP CAPI::ReleaseCapture() {
	::ReleaseCapture();
	return S_OK;
}

STDMETHODIMP CAPI::SendMessage(long lWnd, long lMsg, long wParam, long lParam, long *plRet) {
    if (!plRet) return E_POINTER;
	if (!::IsWindow((HWND)lWnd)) {
		return Error(IDS_E_NOTAWINDOW);
	}
	*plRet = ::SendMessage( (HWND)lWnd, lMsg, wParam, lParam );
	return S_OK;
}

STDMETHODIMP CAPI::SendMessageText(long lWnd, long lMsg, long wParam, BSTR bText, long *plRet) {
    if (!plRet) return E_POINTER;
	if( !::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	*plRet = ::SendMessage( (HWND)lWnd, lMsg, wParam, (LPARAM)bText);
	return S_OK;
}

STDMETHODIMP CAPI::WindowFromPoint(long lXpos, long lYpos, long *plRet) {
    if (!plRet) return E_POINTER;
	POINT pt;

	pt.x = lXpos;
	pt.y = lYpos;
	*plRet = (LONG)::WindowFromPoint(pt);
	return S_OK;
}

STDMETHODIMP CAPI::ChildWindowFromPoint(long lWnd, long lXpos, long lYpos, long *plRet) {
    if (!plRet) return E_POINTER;
	POINT pt;

	if( ! ::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	pt.x = lXpos;
	pt.y = lYpos;
	*plRet = (LONG)::ChildWindowFromPoint((HWND)lWnd, pt);
	return S_OK;
}

STDMETHODIMP CAPI::PostMessage(long lWnd, long lMsg, long wParam, long lParam, long *plRet) {
    if (!plRet) return E_POINTER;
	if( ! ::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	*plRet = ::PostMessage( (HWND)lWnd, lMsg, wParam, lParam );
	return S_OK;
}

STDMETHODIMP CAPI::get_ForegroundWindow(long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = (long)::GetForegroundWindow();
	return S_OK;
}

STDMETHODIMP CAPI::put_ForegroundWindow(long newVal) {
	if (!::IsWindow((HWND)newVal)) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::SetForegroundWindow((HWND)newVal);
	return S_OK;
}

STDMETHODIMP CAPI::get_Focus(long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = (long)::GetFocus();
	return S_OK;
}

STDMETHODIMP CAPI::put_Focus(long newVal) {
	if (!::IsWindow( (HWND)newVal)) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::SetFocus( (HWND)newVal );
	return S_OK;
}

STDMETHODIMP CAPI::get_Capture(long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = (long)::GetCapture();
	return S_OK;
}

STDMETHODIMP CAPI::put_Capture(long newVal) {
	if (!::IsWindow((HWND)newVal)) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::SetCapture((HWND)newVal);
	return S_OK;
}

STDMETHODIMP CAPI::get_EnableKeyboard(VARIANT_BOOL *pVal) {
    #ifdef _WIN32_WCE
        if (!pVal) return E_POINTER;
        DWORD dw = ::GetKeyboardStatus();
        if ( !(dw & 0x0002) ) {
            *pVal = VARIANT_FALSE;
            return S_FALSE;
        } else {
            *pVal = VARIANT_TRUE;
            return S_OK;
        }
    #else
        if (pVal) *pVal = VARIANT_TRUE;
	    return S_OK;
    #endif
}

STDMETHODIMP CAPI::put_EnableKeyboard(VARIANT_BOOL newVal) {
    #ifdef _WIN32_WCE
        ::EnableHardwareKeyboard((BOOL)newVal);
	    return S_OK;
    #else
	    return S_OK;
    #endif
}

STDMETHODIMP CAPI::get_WindowText(long lWnd, BSTR *pVal) {
    if (!pVal) return E_POINTER;
    if ( ! ::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
    int nLen = ::GetWindowTextLength((HWND)lWnd);
    ccBSTR  bstr;
    if (!bstr.Alloc((UINT)nLen)) return E_OUTOFMEMORY;
	::GetWindowText( (HWND)lWnd, bstr, nLen + 1);
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CAPI::put_WindowText(long lWnd, BSTR newVal) {
	if ( ! ::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::SetWindowText((HWND)lWnd, newVal );
	return S_OK;
}

STDMETHODIMP CAPI::get_SystemColor(long lColor, long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = ::GetSysColor( lColor + 0x40000000 );
	return S_OK;
}

STDMETHODIMP CAPI::put_SystemColor(long lColor, long newVal) {
	lColor += 0x40000000;
	::SetSysColors( 1, (const int *)&lColor, (DWORD *)&newVal );
	return S_OK;
}

STDMETHODIMP CAPI::get_TopMost(long lWnd, VARIANT_BOOL *pVal) {
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CAPI::put_TopMost(long lWnd, VARIANT_BOOL newVal) {
	if ( ! ::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	if (newVal)
		::SetWindowPos( (HWND)lWnd, HWND_TOPMOST, 0, 0, 0, 0,
						SWP_NOMOVE | SWP_NOSIZE );
	else
		::SetWindowPos( (HWND)lWnd, HWND_NOTOPMOST, 0, 0, 0, 0,
						SWP_NOMOVE | SWP_NOSIZE );
	return S_OK;
}

STDMETHODIMP CAPI::GetWindow(long lWnd, long lType, long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = (long)::GetWindow((HWND)lWnd,lType);
	return S_OK;
}

STDMETHODIMP CAPI::get_ClassName(long lWnd, BSTR *pVal) {
	ccBSTR  bstr;
    if (!bstr.Alloc(256)) return E_OUTOFMEMORY;
	if( ! ::IsWindow( (HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::GetClassName((HWND)lWnd, bstr,256);
    bstr.Compact();
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CAPI::ShowWindow(long lWnd, long lFlag) {
	if (!::IsWindow( (HWND)lWnd )) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::ShowWindow( (HWND)lWnd, lFlag );
	return S_OK;
}

STDMETHODIMP CAPI::GetAsyncKeyState(long lKey, long *plRet) {
    if (!plRet) return E_POINTER;
	*plRet = (long)::GetAsyncKeyState(lKey);
	return S_OK;
}

STDMETHODIMP CAPI::SendKeys(BSTR bstrKeys, VARIANT_BOOL bSilent) {
	ULONG iLen, i;
	DWORD dwFlags, dwOrig = 0;
	WCHAR wch;
    MSG mmsg;
	BOOL bShift, bCtrl, bAlt;
    ccBSTR  bstr = bstrKeys;


	iLen = bstr.Length();
	if (!iLen) return Error(IDS_E_EMPTYSTRING);

    #ifdef _WIN32_WCE
	    if (bSilent)  dwOrig = KEYEVENTF_SILENT;
	    else dwOrig = 0;
    #endif

	bShift = bCtrl = bAlt = FALSE;

	for( i = 0; i < iLen; i++ ) {
		wch = bstr[i];
		dwFlags = dwOrig;
		if (wch == 16) {
			if (bShift) {
				bShift = FALSE;
				dwFlags |= KEYEVENTF_KEYUP;
			} else bShift = TRUE;
		}
		if (wch == 17) {
			if (bCtrl) {
				bCtrl = FALSE;
				dwFlags |= KEYEVENTF_KEYUP;
			} else bCtrl = TRUE;
		}
		if (wch == 18) {
			if (bAlt) {
				bAlt = FALSE;
				dwFlags |= KEYEVENTF_KEYUP;
			} else bAlt = TRUE;
		}
		keybd_event( (BYTE)wch, 0, dwFlags, 0 );

        while( ::PeekMessage( &mmsg, NULL, 0, 0, PM_NOREMOVE ) ) {
			::GetMessage( &mmsg, NULL, 0, 0 );
			::TranslateMessage( &mmsg );
			::DispatchMessage( &mmsg );
		}

	}
	return S_OK;
}

STDMETHODIMP CAPI::GetMemoryStatus(long lType, VARIANT *pRet) {
    if (!pRet) return E_POINTER;
	if (lType >= 7 && lType < 0) {
		return Error(IDS_E_MEMSTATTYPE);
	}
    #ifdef _WIN32_WCE
        MEMORYSTATUS ms;
        GlobalMemoryStatus( &ms );
	    if( lType == 0 )  pRet->lVal = (long)ms.dwTotalPhys;
	    if( lType == 1 )  pRet->lVal = (long)ms.dwAvailPhys;
	    if( lType == 2 )  pRet->lVal = (long)ms.dwTotalPageFile;
	    if( lType == 3 )  pRet->lVal = (long)ms.dwAvailPageFile;
	    if( lType == 4 )  pRet->lVal = (long)ms.dwTotalVirtual;
	    if( lType == 5 )  pRet->lVal = (long)ms.dwAvailVirtual;
	    if( lType == 6 )  pRet->lVal = (long)ms.dwMemoryLoad;
        pRet->vt = VT_I4;
	    return S_OK;
    #else
        HINSTANCE hLib = LoadLibrary(TEXT("Kernel32.dll"));
        typedef BOOL (WINAPI *PFNGETMEMSTATUS)(LPVOID);
        if (hLib) {
            PFNGETMEMSTATUS pfnEx = (PFNGETMEMSTATUS)GetProcAddress(hLib,"GlobalMemoryStatusEx");
            if (pfnEx) {
                api_MEMORYSTATUSEX msex;
                ZeroMemory(&msex,sizeof(api_MEMORYSTATUSEX));
                msex.dwLength = sizeof(api_MEMORYSTATUSEX);
                (*pfnEx)(&msex);
                if( lType == 0 )  pRet->dblVal = (double)(__int64)msex.ullTotalPhys;
	            if( lType == 1 )  pRet->dblVal = (double)(__int64)msex.ullAvailPhys;
	            if( lType == 2 )  pRet->dblVal = (double)(__int64)msex.ullTotalPageFile;
	            if( lType == 3 )  pRet->dblVal = (double)(__int64)msex.ullAvailPageFile;
	            if( lType == 4 )  pRet->dblVal = (double)(__int64)msex.ullTotalVirtual;
	            if( lType == 5 )  pRet->dblVal = (double)(__int64)msex.ullAvailVirtual;
	            if( lType == 6 )  pRet->dblVal = (double)(__int64)msex.dwMemoryLoad;
                // <winbase.h>
                pRet->vt = VT_R8;
                FreeLibrary(hLib);
                return S_OK;
            } 
            FreeLibrary(hLib);
        } 
        MEMORYSTATUS ms;
        GlobalMemoryStatus( &ms );
        if( lType == 0 )  pRet->lVal = (long)ms.dwTotalPhys;
	    if( lType == 1 )  pRet->lVal = (long)ms.dwAvailPhys;
	    if( lType == 2 )  pRet->lVal = (long)ms.dwTotalPageFile;
	    if( lType == 3 )  pRet->lVal = (long)ms.dwAvailPageFile;
	    if( lType == 4 )  pRet->lVal = (long)ms.dwTotalVirtual;
	    if( lType == 5 )  pRet->lVal = (long)ms.dwAvailVirtual;
	    if( lType == 6 )  pRet->lVal = (long)ms.dwMemoryLoad;
        pRet->vt = VT_I4;
	    return S_OK;
    #endif

}

STDMETHODIMP CAPI::GetStorageStatus(long lInfo, VARIANT v, VARIANT *pvResult) {
    ccVariant   vType = v;
    ccBSTR      bstr;
    HRESULT hr = vType.ChangeType(VT_BSTR);
    if (!FAILED(hr)) bstr = vType.bstrVal;
    if (vType.IsOmitted()) bstr.Empty();

    ccVariant   vResult;
    ULARGE_INTEGER uliFreeBytesAvailable;
    ULARGE_INTEGER uliTotalNumberOfBytes;
    ULARGE_INTEGER uliTotalNumberOfFreeBytes;
    BOOL    b,bSkip = FALSE;

    if (!bstr.Length()) {
	    #ifdef _WIN32_WCE
            STORE_INFORMATION si;
            b = GetStoreInformation( &si );
	        if (lInfo == 0) vResult = (long)si.dwStoreSize;
	        else vResult = (long)si.dwFreeSize;
            bSkip = TRUE;
        #else
            b = GetDiskFreeSpaceEx(NULL,&uliFreeBytesAvailable,&uliTotalNumberOfBytes,&uliTotalNumberOfFreeBytes);
        #endif
    } else {
        b = GetDiskFreeSpaceEx(bstr,&uliFreeBytesAvailable,&uliTotalNumberOfBytes,&uliTotalNumberOfFreeBytes);
    }
    if (!bSkip) {
        if (lInfo == 0) vResult = (double)(__int64)uliTotalNumberOfBytes.QuadPart;
        if (lInfo == 1) vResult = (double)(__int64)uliTotalNumberOfFreeBytes.QuadPart;
        if (lInfo == 2) vResult = (double)(__int64)uliFreeBytesAvailable.QuadPart;
    }

    return vResult.CopyTo(pvResult);
}

STDMETHODIMP CAPI::GetPowerStatus(VARIANT v, VARIANT *pvResult) {
    ccVariant vType = v;
    long lType = 0;
    if (!vType.IsOmitted()) {
        vType.ChangeType(VT_I4);
        lType = vType.lVal;
    }
    ccVariant vResult;

	#ifdef _WIN32_WCE
        SYSTEM_POWER_STATUS_EX sps;
        GetSystemPowerStatusEx(&sps,TRUE);
	    if( lType == 0 )  vResult = (long)sps.ACLineStatus;
	    if( lType == 1 )  vResult = (long)sps.BatteryFlag;
	    if( lType == 2 )  vResult = (long)sps.BatteryLifePercent;
	    if( lType == 3 )  vResult = (long)sps.BatteryLifeTime;
	    if( lType == 4 )  vResult = (long)sps.BatteryFullLifeTime;
	    if( lType == 5 )  vResult = (long)sps.BackupBatteryFlag;
	    if( lType == 6 )  vResult = (long)sps.BackupBatteryLifePercent;
	    if( lType == 7 )  vResult = (long)sps.BackupBatteryLifeTime;
	    if( lType == 8 )  vResult = (long)sps.BackupBatteryFullLifeTime;
    #else
        SYSTEM_POWER_STATUS sps;
        GetSystemPowerStatus(&sps);
        if( lType == 0 )  vResult = (long)sps.ACLineStatus;
	    if( lType == 1 )  vResult = (long)sps.BatteryFlag;
	    if( lType == 2 )  vResult = (long)sps.BatteryLifePercent;
	    if( lType == 3 )  vResult = (long)sps.BatteryLifeTime;
	    if( lType == 4 )  vResult = (long)sps.BatteryFullLifeTime;
    #endif

    return vResult.CopyTo(pvResult);
}

#ifdef _WIN32_WCE
long _g_lSPIs[] = {
    SPI_GETWORKAREA,
    SPI_GETWAKEUPIDLETIMEOUT,
    SPI_GETEXTERNALIDLETIMEOUT,
    SPI_GETBATTERYIDLETIMEOUT,
    SPI_GETPLATFORMTYPE,
    SPI_GETOEMINFO
};
#else
long _g_lSPIs[] = {
    SPI_GETWORKAREA
};
#endif
// SPI_GETPOWEROFFTIMEOUT - screen off
STDMETHODIMP CAPI::get_SystemParameters(VARIANT v, VARIANT *pVal) {
    ccVariant vType = v;
    long lType = 0;
    if (!vType.IsOmitted()) {
        vType.ChangeType(VT_I4);
        lType = vType.lVal;
    }
    ccVariant vResult;
    CComObject<CAPIPosPoint>*   pSize;
    HRESULT                     hr;
    ccBSTR                      bstr;


    switch (lType) {
        case 0:
            hr = CComObject<CAPIPosPoint>::CreateInstance(&pSize);
            if (FAILED(hr)) return hr;
            hr = pSize->QueryInterface(IID_IDispatch,(void**)&vResult.pdispVal);
            if (FAILED(hr)) {
                delete pSize;
                return hr;
            }
            vResult.vt = VT_DISPATCH;
            if (!SystemParametersInfo(SPI_GETWORKAREA,0,&pSize->m_l,0)) {
                return Error(IDS_E_SYSPARAMFAILED);
            }
        break;
      #ifdef _WIN32_WCE
        case 1:
        case 2:
        case 3:
            if (!SystemParametersInfo(_g_lSPIs[lType], 0, &vResult.lVal, 0 )) return Error(IDS_E_SYSPARAMFAILED);
            vResult.vt = VT_I4;
        break;
        case 4:
        case 5:
            if (!bstr.Alloc(256)) return E_OUTOFMEMORY;
            if (!SystemParametersInfo(_g_lSPIs[lType], 256, bstr,0)) return Error(IDS_E_SYSPARAMFAILED);
            bstr.Compact();
            hr = bstr.CopyTo(&vResult);
            if (FAILED(hr)) return hr;
        break;
      #endif
        default:
            return Error(IDS_E_SYSPARAMFAILED);
    }

	return vResult.CopyTo(pVal);	
}
#ifdef _WIN32_WCE
long _g_lSETSPIs[] = {
    SPI_SETWORKAREA,
    SPI_SETWAKEUPIDLETIMEOUT,
    SPI_SETEXTERNALIDLETIMEOUT,
    SPI_SETBATTERYIDLETIMEOUT
};
#else
long _g_lSETSPIs[] = {
    SPI_SETWORKAREA
};
#endif
STDMETHODIMP CAPI::put_SystemParameters(VARIANT v, VARIANT newVal) {
    ccVariant vType = v;
    long lType = 0;
    if (!vType.IsOmitted()) {
        vType.ChangeType(VT_I4);
        lType = vType.lVal;
    }
    ccVariant vResult;
    ccVariant vVal;
    HRESULT   hr;
    hr = ::VariantCopyInd(&vVal,&newVal);
    if (FAILED(hr)) return hr;
    CComPtr<IAPIPosPoint>   spSize;
    RECT    rc;
    

    switch (lType) {
        case 0:
            if (vVal.vt == VT_UNKNOWN || vVal.vt == VT_DISPATCH) {
                hr = vVal.punkVal->QueryInterface(IID_IAPIPosPoint,(void**)&spSize);
                if (FAILED(hr)) return Error(IDS_E_NOTPTRECT);
                hr = spSize->get_Value(0,&rc.left);
                if (FAILED(hr)) return hr;
                hr = spSize->get_Value(1,&rc.top);
                if (FAILED(hr)) return hr;
                hr = spSize->get_Value(2,&rc.right);
                if (FAILED(hr)) return hr;
                hr = spSize->get_Value(3,&rc.bottom);
                if (FAILED(hr)) return hr;
                if (!SystemParametersInfo(_g_lSETSPIs[lType],0,&rc,0)) return Error(IDS_E_SYSPARAMFAILED);
            } else {
                if (!SystemParametersInfo(_g_lSETSPIs[lType],0,NULL,0)) return Error(IDS_E_SYSPARAMFAILED);
            }
        break;
        case 1:
        case 2:
        case 3:
            hr = vVal.ChangeType(VT_I4);
            if (FAILED(hr)) return hr;
            if (!SystemParametersInfo(_g_lSETSPIs[lType],(UINT)v.lVal,NULL,0)) return Error(IDS_E_SYSPARAMFAILED);
        break;
        default:
            return Error(IDS_E_SYSPARAMFAILED);
    }
	return S_OK;
}
STDMETHODIMP CAPI::putref_SystemParameters(VARIANT v, VARIANT newVal) {
    return put_SystemParameters(v,newVal);
}

#ifdef _WIN32_WCE
    HRESULT CAPI::ShellCreateLink(LPTSTR	lpszPathTarget,
				                  LPTSTR	lpszPathLink
				               ) {
        if (::SHCreateShortcut( lpszPathLink, lpszPathTarget)) return S_OK;
        return Error(IDS_E_OPERATIONFAILED);
    }
#else
    HRESULT CAPI::ShellCreateLink(LPTSTR	lpszPathTarget,
				                  LPTSTR	lpszPathLink
				               ) { 
        HRESULT hr;
        CComPtr<IShellLink> spLink; 
	    CComPtr<IPersistFile> spPersistFile; 
 
        hr = CoCreateInstance(CLSID_ShellLink, NULL, 
            CLSCTX_INPROC_SERVER, IID_IShellLink, (void**)&spLink); 
        if (SUCCEEDED(hr)) { 
            spLink->SetPath(lpszPathTarget); 
            hr = spLink->QueryInterface(IID_IPersistFile, (void**)&spPersistFile); 
 
            if (SUCCEEDED(hr)) { 
                hr = spPersistFile->Save(lpszPathLink, TRUE); 
                hr = spPersistFile->SaveCompleted(lpszPathLink); 
            } 
        } 
        return hr; 
    } 
#endif

STDMETHODIMP CAPI::CreateShortcut(BSTR bShortcut, BSTR bTarget) {
	return ShellCreateLink(bTarget,bShortcut);
}

STDMETHODIMP CAPI::AddToRecent(BSTR bstrPath) {
	::SHAddToRecentDocs( SHARD_PATH, bstrPath);
	return S_OK;
}

STDMETHODIMP CAPI::GetSpecialFolder(VARIANT vType, BSTR *pRet) {
    if (!pRet) return E_POINTER;
	LPITEMIDLIST        pidl;
    CComPtr<IMalloc>    spMalloc;
    ccBSTR              bstr;
    ccVariant           v = vType;
    HRESULT             hr;

    hr = v.ChangeType(VT_I4);
    if (FAILED(hr)) return hr;

    hr = SHGetSpecialFolderLocation(NULL,v.lVal,&pidl);
    if (FAILED(hr)) return hr;

    hr = SHGetMalloc(&spMalloc);
    if (FAILED(hr)) return hr;
    
    if (!bstr.Alloc(MAX_PATH * 2)) return E_OUTOFMEMORY;
    if (!SHGetPathFromIDList(pidl,bstr)) return Error(IDS_E_STDPATHFAILED);

    spMalloc->Free(pidl);
    
    bstr.Compact();
    return bstr.CopyTo(pRet);
}

STDMETHODIMP CAPI::GetShortcutTarget(BSTR bstrShortcut, BSTR *pVal) {
    if (!pVal || !bstrShortcut) return E_POINTER;
    ccBSTR      bstr;

  #ifdef _WIN32_WCE
    if (!bstr.Alloc(300)) return E_OUTOFMEMORY;
	if (!::SHGetShortcutTarget(bstrShortcut,bstr,300)) {
		return Error(IDS_E_QUERYSHORTCUTFAILED);
	}
    bstr.Compact();
	return bstr.CopyTo(pVal);
  #else
    HRESULT hr;
    CComPtr<IShellLink> spLink; 
	CComPtr<IPersistFile> spPersistFile; 
 
    hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink,(void**)&spLink); 
    if (SUCCEEDED(hr)) { 
        hr = spLink->QueryInterface(IID_IPersistFile, (void**)&spPersistFile);
        if (SUCCEEDED(hr)) {
            hr = spPersistFile->Load(bstrShortcut,0);
            if (SUCCEEDED(hr)) {
                if (!bstr.Alloc(MAX_PATH * 2)) return E_OUTOFMEMORY;
                hr = spLink->GetPath(bstr,MAX_PATH * 2,NULL,0);
            }
        }
    } 
    if (FAILED(hr)) return hr;
    bstr.Compact();
    return bstr.CopyTo(pVal);
  #endif
}

STDMETHODIMP CAPI::FindWindowByClass(BSTR bClass, long *lRet) {
    if (!lRet) return E_POINTER;
	*lRet = (long)::FindWindow(bClass,NULL);
	return S_OK;
}

STDMETHODIMP CAPI::get_ClipText(BSTR *pVal) {
    if (!pVal) return E_POINTER;

	HANDLE  hData;
	ccBSTR  bstrData = TEXT("");
    LPWSTR  pszData;

    if (!::OpenClipboard( this->m_hWndApi)) return Error(IDS_E_OPENCLIPFAILED);
    hData = ::GetClipboardData(CF_UNICODETEXT);
    if (hData) {
        // There is something
        #ifdef _WIN32_WCE
            pszData = (BSTR)LocalLock(hData);
        #else
            pszData = (BSTR)GlobalLock(hData);
        #endif
        if (pszData) bstrData = pszData;
        #ifdef _WIN32_WCE
            LocalUnlock(hData);
        #else
            GlobalUnlock(hData);
        #endif
    }
    ::CloseClipboard();

    return bstrData.CopyTo(pVal);
}

STDMETHODIMP CAPI::put_ClipText(BSTR newVal) {
    ccBSTR  bstr = newVal;
    HANDLE  hData;
	BSTR    pszData;
    HRESULT hr;

    if (!::OpenClipboard( this->m_hWndApi)) return Error(IDS_E_OPENCLIPFAILED);
    ::EmptyClipboard();
    #ifdef _WIN32_WCE
        hData = LocalAlloc( LPTR, (bstr.Length() + 4) * sizeof(WCHAR));
    #else
        hData = GlobalAlloc( GHND, (bstr.Length() + 4) * sizeof(WCHAR));
    #endif
    if (!hData) return E_OUTOFMEMORY;
    #ifdef _WIN32_WCE
        pszData = (BSTR)LocalLock(hData);
    #else
        pszData = (BSTR)GlobalLock(hData);
    #endif
    if (pszData) {
        hr = bstr.CopyToBuff(pszData,bstr.Length() + 4);
    }
    #ifdef _WIN32_WCE
        LocalUnlock(hData);
    #else
        GlobalUnlock(hData);
    #endif
    ::SetClipboardData(CF_UNICODETEXT,hData);
    ::CloseClipboard();
	return hr;
}

STDMETHODIMP CAPI::get_Version(long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = 201;
	return S_OK;
}

STDMETHODIMP CAPI::get_CursorPos(VARIANT *pVal) {
    // This should provide compatible syntax with the previous version
    // in NSBasic but provides more convenient way to access the data.
    if (!pVal) return E_POINTER;
    POINT   pt;

    if (!GetCursorPos(&pt)) return Error(IDS_E_CANTGETPOS);

    CComObject<CAPIPosPoint>*    pPt = NULL;
    HRESULT hr = CComObject<CAPIPosPoint>::CreateInstance(&pPt);
    if (FAILED(hr)) return hr;

    ccVariant v;

    hr = pPt->QueryInterface(IID_IDispatch,(void**)&v.pdispVal);
    if (FAILED(hr)) {
        delete pPt;
        return hr;
    }
    v.vt = VT_DISPATCH;

    pPt->m_l[0] = pt.x;
    pPt->m_l[1] = pt.y;

    return ::VariantCopy(pVal,&v);
}

STDMETHODIMP CAPI::get_SystemVersion(long *pVal) {
    if (!pVal) return E_POINTER;
	OSVERSIONINFO ovi;
	ZeroMemory(&ovi,sizeof(OSVERSIONINFO));
	ovi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&ovi);
	*pVal = MAKELONG(LOWORD(ovi.dwMinorVersion),LOWORD(ovi.dwMajorVersion));
	return S_OK;
}

STDMETHODIMP CAPI::get_WindowLong(long lWnd, long lVal, long *pVal) {
    if (!pVal) return E_POINTER;
	if (!::IsWindow((HWND)lWnd)) {
		return Error(IDS_E_NOTAWINDOW);
	}
	*pVal = ::GetWindowLong((HWND)lWnd,lVal);
	return S_OK;
}

STDMETHODIMP CAPI::put_WindowLong(long lWnd, long lVal, long newVal) {
	if (!::IsWindow((HWND)lWnd)) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::SetWindowLong((HWND)lWnd,lVal,newVal);
	return S_OK;
}

STDMETHODIMP CAPI::get_Ticks(VARIANT *pVal) {
    if (!pVal) return E_POINTER;
    pVal->vt = VT_UI4;
	pVal->ulVal = (UINT)GetTickCount();
	return S_OK;
}

STDMETHODIMP CAPI::get_SystemTime(VARIANT *pVal) {
    if (!pVal) return E_POINTER;
	SYSTEMTIME st;
	GetSystemTime(&st);
    ::VariantInit(pVal);
	SystemTimeToVariantTime(&st,&pVal->dblVal);
	pVal->vt = VT_DATE;
	return S_OK;
}

STDMETHODIMP CAPI::put_SystemTime(VARIANT newVal) {
	SYSTEMTIME st;

    ccVariant  v = newVal;
    HRESULT hr;
    hr = v.ChangeType(VT_DATE);
    if (FAILED(hr)) return hr;

	if (!VariantTimeToSystemTime(v.dblVal,&st)) {
		return Error(IDS_E_INVALIDTIME);
	}
	SetSystemTime(&st);
	return S_OK;
}

STDMETHODIMP CAPI::get_LocalTime(VARIANT *pVal) {
    if (!pVal) return E_POINTER;
	SYSTEMTIME st;
	GetLocalTime(&st);
    ::VariantInit(pVal);
	SystemTimeToVariantTime(&st,&pVal->dblVal);
	pVal->vt = VT_DATE;
	return S_OK;
}

STDMETHODIMP CAPI::put_LocalTime(VARIANT newVal) {
	SYSTEMTIME st;
    ccVariant  v = newVal;
    HRESULT hr;
    hr = v.ChangeType(VT_DATE);
    if (FAILED(hr)) return hr;

	if (!VariantTimeToSystemTime(v.dblVal,&st)) {
		return Error(IDS_E_INVALIDTIME);
	}
	SetLocalTime(&st);
	return S_OK;
}

STDMETHODIMP CAPI::get_WindowParent(long lWnd, long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = (long)::GetParent( (HWND)lWnd );
	return S_OK;
}

STDMETHODIMP CAPI::put_WindowParent(long lWnd, long newVal) {
	if (!::IsWindow((HWND)lWnd ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	if( ! ::IsWindow( (HWND)newVal ) ) {
		return Error(IDS_E_NOTAWINDOW);
	}
	::SetParent( (HWND)lWnd, (HWND)newVal );
	return S_OK;
}

STDMETHODIMP CAPI::get_OSType(VARIANT *pVal) {
    if (!pVal) return E_POINTER;
    OSVERSIONINFO   ovi;
    ZeroMemory(&ovi,sizeof(OSVERSIONINFO));
    ovi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (!GetVersionEx(&ovi)) return Error(IDS_E_OSVERFAILED);
    // <winbase.h>
    ccVariant v;
    switch (ovi.dwPlatformId) {
        case VER_PLATFORM_WIN32_WINDOWS:
            v = TEXT("9x");
        break;
        case VER_PLATFORM_WIN32_NT:
            v = TEXT("NT");
        break;
        #ifdef _WIN32_WCE
            case VER_PLATFORM_WIN32_CE:
                v = TEXT("CE");
            break;
        #endif
    }
    return ::VariantCopy(pVal,&v);
}
