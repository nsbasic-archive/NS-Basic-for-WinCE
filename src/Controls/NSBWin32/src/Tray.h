// Tray.h : Declaration of the CTray

#ifndef __TRAY_H_
#define __TRAY_H_

#include "resource.h"       // main symbols
#include "DeskCP.h"

/////////////////////////////////////////////////////////////////////////////
// CTray
class ATL_NO_VTABLE CTray : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CTray, &CLSID_Tray>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CTray>,
	public IDispatchImpl<ITray, &IID_ITray, &LIBID_DESKLib>,
    public IProvideClassInfo2Impl<&CLSID_Tray, &DIID__ITrayEvents, &LIBID_DESKLib>,
    public CProxy_ITrayEvents< CTray >
{
public:
    CTray() {
        m_hImageList        = NULL;
        m_hWndTray          = NULL;
        m_lIconAdded        = 0;
        m_uTaskBarRecreated = 0;
        m_bstrTip = TEXT("");
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TRAY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

static  LRESULT CALLBACK TrayWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL& bDone);

BEGIN_COM_MAP(CTray)
	COM_INTERFACE_ENTRY(ITray)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CTray)
CONNECTION_POINT_ENTRY(DIID__ITrayEvents)
END_CONNECTION_POINT_MAP()

HWND            m_hWndTray;
CComVariant     m_vTag;
HIMAGELIST      m_hImageList;
long            m_lIconAdded;
UINT            m_uTaskBarRecreated;
CComBSTR        m_bstrTip;


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ITray
public:
	STDMETHOD(get_Tip)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Tip)(/*[in]*/ BSTR newVal);
	STDMETHOD(RemoveImage)(/*[in]*/ long lImage);
	STDMETHOD(AddImage)(/*[in]*/ BSTR bstrImage,/*[out,retval]*/ long* plAdded);
	STDMETHOD(get_Image)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Image)(/*[in]*/ long newVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Version)(/*[out, retval]*/ long *pVal);
};

#endif //__TRAY_H_
