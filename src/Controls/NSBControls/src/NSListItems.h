// NSListItems.h : Declaration of the CNSListItems

#ifndef __NSLISTITEMS_H_
#define __NSLISTITEMS_H_

#include "resource.h"       // main symbols

class CNSListView;

/////////////////////////////////////////////////////////////////////////////
// CNSListItems
class ATL_NO_VTABLE CNSListItems : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSListItems, &CLSID_NSListItems>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSListItems, &IID_INSListItems, &LIBID_COMCTLLib>
{
public:
	CNSListItems() {
        m_pListView = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSLISTITEMS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSListItems)
	COM_INTERFACE_ENTRY(INSListItems)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)
END_COM_MAP()

CNSListView*                                m_pListView;
// CSimpleArray<CComPtr<INSListItem> >         m_arrListItems;
ccSimpleArray<CComPtr<INSListItem> >         m_arrListItems;

int FindItem(VARIANT Index);

// INSComCtlInt
    STDMETHOD(NSTerminate)();
    STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSListItems
public:
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(Add)(/*[in,optional]*/ VARIANT Index,/*[in,optional]*/ VARIANT Key,/*[in,optional]*/ VARIANT Text,/*[in,optional]*/ VARIANT Icon,/*[in,optional]*/ VARIANT Indent,/*[out,retval]*/ INSListItem** ppObj);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT Index, /*[out, retval]*/ INSListItem* *pVal);
	STDMETHOD(Remove)(/*[in]*/ VARIANT Index);
	STDMETHOD(Clear)();
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
};

#endif //__NSLISTITEMS_H_
