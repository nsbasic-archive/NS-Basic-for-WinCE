// NSColumnHeaders.h : Declaration of the CNSColumnHeaders

#ifndef __NSCOLUMNHEADERS_H_
#define __NSCOLUMNHEADERS_H_

#include "resource.h"       // main symbols

class CNSListView;

/////////////////////////////////////////////////////////////////////////////
// CNSColumnHeaders
class ATL_NO_VTABLE CNSColumnHeaders : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSColumnHeaders, &CLSID_NSColumnHeaders>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSColumnHeaders, &IID_INSColumnHeaders, &LIBID_COMCTLLib>
{
public:
	CNSColumnHeaders() {
        m_pListView = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSCOLUMNHEADERS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSColumnHeaders)
	COM_INTERFACE_ENTRY(INSColumnHeaders)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)    
END_COM_MAP()

CNSListView*                                m_pListView;
// CSimpleArray<CComPtr<INSColumnHeader> >     m_arrColumnHeaders;
ccSimpleArray<CComPtr<INSColumnHeader> >     m_arrColumnHeaders;

int FindItem(VARIANT Index);
int FindBySubItemIndex(long lSubItemIndex);

HRESULT     AddInitialColumn();

// INSComCtlInt
STDMETHOD(NSTerminate)();
STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSColumnHeaders
public:
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(Add)(/*[in,optional]*/ VARIANT Index,/*[in,optional]*/ VARIANT Key,/*[in,optional]*/ VARIANT Text,/*[in,optional]*/VARIANT Width,/*[in,optional]*/ VARIANT Alignment,/*[in,optional]*/ VARIANT Icon, /*[out,retval]*/ INSColumnHeader** ppObj);
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown **pVal);
	STDMETHOD(Remove)(/*[in]*/ VARIANT Index);
	STDMETHOD(get_Item)(VARIANT Index,/*[out, retval]*/ INSColumnHeader **pVal);
	STDMETHOD(Clear)();
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
};

#endif //__NSCOLUMNHEADERS_H_
