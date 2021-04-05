// Timer.cpp : Implementation of CTimer
#include "stdafx.h"
#include "Desk.h"
#include "Timer.h"

TCHAR   g_szCTimerWndClassName[] = TEXT("NSBasic3003200620");
#define TIMER_ID                   667

/////////////////////////////////////////////////////////////////////////////
// CTimer

STDMETHODIMP CTimer::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ITimer
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CTimer::FinalConstruct() {
    WNDCLASS    wc;
    ZeroMemory(&wc,sizeof(WNDCLASS));

    if (!::GetClassInfo(_Module.GetModuleInstance(),g_szCTimerWndClassName,&wc)) {
        // We need to register the class
        wc.lpfnWndProc = TimerWindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = _Module.GetModuleInstance();
		wc.hIcon = NULL;
		wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = g_szCTimerWndClassName;
        if (!RegisterClass(&wc)) return E_FAIL;
    }
    // We have the class
    m_hWndTimer = ::CreateWindowEx(0,g_szCTimerWndClassName,NULL,WS_POPUP,0,0,0,0,NULL,NULL,_Module.GetModuleInstance(),(LPVOID)this);
    if (!m_hWndTimer) return E_FAIL;
    return S_OK;
}
void    CTimer::FinalRelease() {
    // We may need to kill the timers

    // Destroy the window
    ::DestroyWindow(m_hWndTimer);
}
LRESULT CTimer::WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL& bDone) {
    CComPtr<IDispatch> spThis;
    switch (uMsg) {
        case WM_TIMER:
            if (wParam == TIMER_ID) {
                if (QueryInterface(IID_IDispatch,(void**)&spThis) == S_OK) {
                    Fire_OnTimer(spThis);
                }
                Fire_Interval();
            }
            bDone = TRUE;
        break;
        case WM_DESTROY:
            ::KillTimer(hwnd,TIMER_ID);
        break;
    }
    return 0;
}
LRESULT CALLBACK CTimer::TimerWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
    CTimer* pThis = (CTimer*)::GetWindowLong(hwnd,GWL_USERDATA);
    BOOL    bDone = FALSE;
    LRESULT lr;
    switch (uMsg) {
        case WM_CREATE:
            ::SetWindowLong(hwnd,GWL_USERDATA,(LONG)((LPCREATESTRUCT)lParam)->lpCreateParams);
            pThis = (CTimer*)::GetWindowLong(hwnd,GWL_USERDATA);
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

STDMETHODIMP CTimer::get_Interval(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lInterval;
	return S_OK;
}

STDMETHODIMP CTimer::put_Interval(long newVal) {
    if (newVal > 0) {
        m_lInterval = newVal;
        return S_OK;
    }
	return E_INVALIDARG;
}

STDMETHODIMP CTimer::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    ::VariantCopy(pVal,&m_vTag);
	return S_OK;
}

STDMETHODIMP CTimer::put_Tag(VARIANT newVal) {
	m_vTag.Clear();
    ::VariantCopyInd(&m_vTag,&newVal);
	return S_OK;
}

STDMETHODIMP CTimer::get_Version(long *pVal) {
    if (!pVal) return E_POINTER;
	*pVal = 201;
	return S_OK;
}


STDMETHODIMP CTimer::Start(long lInterval) {
    ::KillTimer(m_hWndTimer,TIMER_ID);
    if (lInterval > 0) m_lInterval = lInterval;
    if (!::SetTimer(m_hWndTimer,TIMER_ID,(UINT)m_lInterval,NULL)) return Error(IDS_E_TIMEFAILED);
	return S_OK;
}

STDMETHODIMP CTimer::Stop() {
    ::KillTimer(m_hWndTimer,TIMER_ID);
	return S_OK;
}
