// RAS.h : Declaration of the CRAS

#ifndef __RAS_H_
#define __RAS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRAS
class ATL_NO_VTABLE CRAS : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRAS, &CLSID_RAS>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CRAS>,
    public IProvideClassInfo2Impl<&CLSID_RAS, &DIID__IRASEvents, &LIBID_DESKLib>,
	public IDispatchImpl<IRAS, &IID_IRAS, &LIBID_DESKLib>
{
public:
	CRAS() {
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RAS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRAS)
	COM_INTERFACE_ENTRY(IRAS)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CRAS)
END_CONNECTION_POINT_MAP()

CComBSTR    m_bstrPhoneBook;


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRAS
public:
	STDMETHOD(get_Entry)(/*[in]*/ BSTR bstrName, /*[out, retval]*/ IDispatch* *pVal);
	STDMETHOD(get_Connections)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(get_Version)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Entries)(/*[out, retval]*/ IUnknown **pVal);
	STDMETHOD(get_PhoneBook)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_PhoneBook)(/*[in]*/ BSTR newVal);
};

#endif //__RAS_H_
