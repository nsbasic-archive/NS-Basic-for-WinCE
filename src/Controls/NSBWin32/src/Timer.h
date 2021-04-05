// Timer.h : Declaration of the CTimer

#ifndef __TIMER_H_
#define __TIMER_H_

#include "resource.h"       // main symbols
#include "DeskCP.h"

/////////////////////////////////////////////////////////////////////////////
// CTimer
class ATL_NO_VTABLE CTimer : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CTimer, &CLSID_Timer>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CTimer>,
	public IDispatchImpl<ITimer, &IID_ITimer, &LIBID_DESKLib>,
    public IProvideClassInfo2Impl<&CLSID_Timer, &DIID__ITimerEvents, &LIBID_DESKLib>,
	public CProxy_ITimerEvents< CTimer >
{
public:
	CTimer() {
        m_hWndTimer = NULL;
        m_lInterval = 1000;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TIMER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

static  LRESULT CALLBACK TimerWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL& bDone);

BEGIN_COM_MAP(CTimer)
	COM_INTERFACE_ENTRY(ITimer)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CTimer)
    CONNECTION_POINT_ENTRY(DIID__ITimerEvents)
END_CONNECTION_POINT_MAP()

HWND            m_hWndTimer;
CComVariant     m_vTag;
long            m_lInterval;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ITimer
public:
	STDMETHOD(Stop)();
	STDMETHOD(Start)(/*[in,defaultvalue(0)]*/ long lInterval);
	STDMETHOD(get_Version)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Interval)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Interval)(/*[in]*/ long newVal);
};

#endif //__TIMER_H_
