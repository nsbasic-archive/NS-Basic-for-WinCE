// NSListSubItems.h : Declaration of the CNSListSubItems

#ifndef __NSLISTSUBITEMS_H_
#define __NSLISTSUBITEMS_H_

#include "resource.h"       // main symbols

class   CNSListView;
class   CNSListItem;

/////////////////////////////////////////////////////////////////////////////
// CNSListSubItems
class ATL_NO_VTABLE CNSListSubItems : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSListSubItems, &CLSID_NSListSubItems>,
	public ISupportErrorInfo,
    public INSComCtlInt,
    public INSListSubItemsInt,
	public IDispatchImpl<INSListSubItems, &IID_INSListSubItems, &LIBID_COMCTLLib>
{
public:
	CNSListSubItems() {
        m_pListView = NULL;
        m_pListItem = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSLISTSUBITEMS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSListSubItems)
	COM_INTERFACE_ENTRY(INSListSubItems)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)
    COM_INTERFACE_ENTRY(INSListSubItemsInt)
END_COM_MAP()

CNSListView*                            m_pListView;
CNSListItem*                            m_pListItem;
// CSimpleArray<CComPtr<INSListSubItem> >  m_arrListSubItems;
ccSimpleArray<CComPtr<INSListSubItem> >  m_arrListSubItems;

int     FindItem(VARIANT Index,long* piSubItem = NULL);

// Helpers
HRESULT _Remove(VARIANT Index);

// INSListSubItemsInt
    STDMETHOD(ColumnRemoveUpdate)(long lSubIndex);
    STDMETHOD(ColumnInsertUpdate)(long lSubIndex);
    STDMETHOD(ColumnsClear)();

// INSComCtlInt
    STDMETHOD(NSTerminate)();
    STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSListSubItems
public:
	STDMETHOD(get_ItemIfExists)(/*[in]*/ long Index, /*[out, retval]*/ INSListSubItem* *pVal);
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(get_ListItem)(/*[out, retval]*/ INSListItem* *pVal);
	STDMETHOD(get_DefinedCount)(/*[out, retval]*/ long *pVal);
	STDMETHOD(RemoveByIndex)(/*[in]*/ long Index);
	STDMETHOD(get_ItemByIndex)(/*[in]*/ long Index, /*[out, retval]*/ INSListSubItem* *pVal);
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT Index, /*[out, retval]*/ INSListSubItem* *pVal);
	STDMETHOD(Remove)(/*[in]*/ VARIANT Index);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(Clear)();
};

#endif //__NSLISTSUBITEMS_H_
