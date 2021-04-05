// RASConState.h : Declaration of the CRASConState

#ifndef __RASCONSTATE_H_
#define __RASCONSTATE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRASConState
class ATL_NO_VTABLE CRASConState : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRASConState, &CLSID_RASConState>,
	public ISupportErrorInfo,
	public IDispatchImpl<IRASConState, &IID_IRASConState, &LIBID_DESKLib>
{
public:
	CRASConState() {
        m_hConn = NULL;
        ZeroMemory(&m_rcs,sizeof(RASCONNSTATUS));
        m_rcs.dwSize = sizeof(RASCONNSTATUS);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RASCONSTATE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRASConState)
	COM_INTERFACE_ENTRY(IRASConState)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

HRASCONN        m_hConn;
RASCONNSTATUS   m_rcs;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRASConState
public:
	STDMETHOD(Refresh)();
	STDMETHOD(get_DeviceName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_DeviceType)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ErrorNumber)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_State)(/*[out, retval]*/ long *pVal);
};

#endif //__RASCONSTATE_H_
