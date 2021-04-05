// API.h : Declaration of the CAPI

#ifndef __API_H_
#define __API_H_

#include "resource.h"       // main symbols
#include "DeskCP.h"

/////////////////////////////////////////////////////////////////////////////
// CAPI
class ATL_NO_VTABLE CAPI : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CAPI, &CLSID_API>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CAPI>,
	public IDispatchImpl<IAPI, &IID_IAPI, &LIBID_DESKLib>,
    public IProvideClassInfo2Impl<&CLSID_API, &DIID__IAPIEvents, &LIBID_DESKLib>,
	public CProxy_IAPIEvents< CAPI >
{
public:
	CAPI()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_API)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

static  LRESULT CALLBACK APIWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL& bDone);

HWND    m_hWndApi;

BEGIN_COM_MAP(CAPI)
	COM_INTERFACE_ENTRY(IAPI)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CAPI)
CONNECTION_POINT_ENTRY(DIID__IAPIEvents)
END_CONNECTION_POINT_MAP()

HRESULT ShellCreateLink(LPTSTR	lpszPathTarget,
				           LPTSTR	lpszPathLink
				           );

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IAPI
public:
	STDMETHOD(get_OSType)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_WindowParent)(/*[in]*/ long lWnd, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_WindowParent)(/*[in]*/ long lWnd, /*[in]*/ long newVal);
	STDMETHOD(get_LocalTime)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_LocalTime)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_SystemTime)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_SystemTime)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Ticks)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_WindowLong)(/*[in]*/ long lWnd,/*[in]*/ long lVal, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_WindowLong)(/*[in]*/ long lWnd,/*[in]*/ long lVal, /*[in]*/ long newVal);
	STDMETHOD(get_SystemVersion)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_CursorPos)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Version)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_ClipText)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ClipText)(/*[in]*/ BSTR newVal);
	STDMETHOD(FindWindowByClass)(/*[in]*/ BSTR bClass, /*[out,retval]*/ long *lRet);
	STDMETHOD(GetShortcutTarget)(/*[in]*/ BSTR bstrShortcut, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(GetSpecialFolder)(/*[in]*/ VARIANT vType, /*[out,retval]*/ BSTR *pRet);
	STDMETHOD(AddToRecent)(/*[in]*/ BSTR bstrPath);
	STDMETHOD(CreateShortcut)(/*[in]*/ BSTR bShortcut, /*[in]*/ BSTR bTarget);
	STDMETHOD(get_SystemParameters)(VARIANT vType, /*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_SystemParameters)(VARIANT vType, /*[in]*/ VARIANT newVal);
    STDMETHOD(putref_SystemParameters)(VARIANT vType, /*[in]*/ VARIANT newVal);
	STDMETHOD(GetPowerStatus)(/*[in]*/ VARIANT v,/*[out,retval]*/ VARIANT* pvResult);
	STDMETHOD(GetStorageStatus)(long lInfo, /*[in]*/ VARIANT v,/*[out,retval]*/ VARIANT* pvResult);
	STDMETHOD(GetMemoryStatus)(/*[in]*/ long lType,/*[out,retval]*/ VARIANT* pResult);
	STDMETHOD(SendKeys)(/*[in]*/ BSTR bstrKeys,/*[in]*/ VARIANT_BOOL bSilent);
	STDMETHOD(GetAsyncKeyState)(/*[in]*/ long lKey, /*[out,retval]*/ long *plRet);
	STDMETHOD(ShowWindow)(/*[in]*/ long lWnd, /*[in]*/ long lFlag);
	STDMETHOD(get_ClassName)(/*[in]*/ long lWnd, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(GetWindow)(/*[in]*/ long lWnd, /*[in]*/ long lType, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_TopMost)(/*[in]*/ long lWnd, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_TopMost)(/*[in]*/ long lWnd, /*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_SystemColor)(/*[in]*/ long lColor, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_SystemColor)(/*[in]*/ long lColor, /*[in]*/ long newVal);
	STDMETHOD(get_WindowText)(/*[in]*/ long lWnd, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_WindowText)(/*[in]*/ long lWnd, /*[in]*/ BSTR newVal);
	STDMETHOD(get_EnableKeyboard)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_EnableKeyboard)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Capture)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Capture)(/*[in]*/ long newVal);
	STDMETHOD(get_Focus)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Focus)(/*[in]*/ long newVal);
	STDMETHOD(get_ForegroundWindow)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ForegroundWindow)(/*[in]*/ long newVal);
	STDMETHOD(PostMessage)(/*[in]*/ long lWnd, /*[in]*/ long lMsg, /*[in]*/ long wParam, /*[in]*/ long lParam, /*[out,retval]*/ long *plRet);
	STDMETHOD(ChildWindowFromPoint)(/*[in]*/ long lWnd, /*[in]*/ long lXpos, /*[in]*/ long lYpos, /*[out,retval]*/ long *plRet);
	STDMETHOD(WindowFromPoint)(/*[in]*/ long lXpos, /*[in]*/ long lYpos, /*[out,retval]*/ long *plRet);
	STDMETHOD(SendMessageText)(/*[in]*/ long lWnd, /*[in]*/ long lMsg, /*[in]*/ long wParam, /*[in]*/ BSTR bText, /*[out,retval]*/ long *plRet);
	STDMETHOD(SendMessage)(/*[in]*/ long lWnd, /*[in]*/ long lMsg, /*[in]*/ long wParam, /*[in]*/ long lParam, /*[out,retval]*/ long *plRet);
	STDMETHOD(ReleaseCapture)();
	STDMETHOD(FindWindow)(/*[in]*/ BSTR bstrTitle,/*[out,retval]*/ long* plhWnd);
};

#endif //__API_H_
