// NSColumnItems.h : Declaration of the CNSColumnItems

#ifndef __NSCOLUMNITEMS_H_
#define __NSCOLUMNITEMS_H_

#include "resource.h"       // main symbols

class   CNSColumnHeader;

/////////////////////////////////////////////////////////////////////////////
// CNSColumnItems
class ATL_NO_VTABLE CNSColumnItems : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSColumnItems, &CLSID_NSColumnItems>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSColumnItems, &IID_INSColumnItems, &LIBID_COMCTLLib>
{
public:
	CNSColumnItems() {
        m_pColumnHeader = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSCOLUMNITEMS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNSColumnItems)
	COM_INTERFACE_ENTRY(INSColumnItems)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)
END_COM_MAP()

CNSColumnHeader*    m_pColumnHeader;

// INSComCtlInt
    STDMETHOD(NSTerminate)();
    STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSColumnItems
public:
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT Index, /*[out, retval]*/ IDispatch* *pVal);
};

#endif //__NSCOLUMNITEMS_H_
