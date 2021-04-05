// NSComCtlColl.h : Declaration of the CNSComCtlColl

#ifndef __NSCOMCTLCOLL_H_
#define __NSCOMCTLCOLL_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNSComCtlColl
class ATL_NO_VTABLE CNSComCtlColl : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSComCtlColl, &CLSID_NSComCtlColl>,
	public ISupportErrorInfo,
	public IDispatchImpl<INSComCtlColl, &IID_INSComCtlColl, &LIBID_COMCTLLib>
{
public:
	CNSComCtlColl()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSCOMCTLCOLL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNSComCtlColl)
	COM_INTERFACE_ENTRY(INSComCtlColl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

ccSimpleArray<ccVariant>    m_arrItems;

static  CNSComCtlColl*  CreateColl(void** pObj);

HRESULT AddObject(IDispatch* p);
HRESULT AddBSTR(BSTR bstr);
HRESULT AddVariant(VARIANT v);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSComCtlColl
public:
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(get_Item)(/*[in]*/ long Index, /*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
};

#endif //__NSCOMCTLCOLL_H_
