// NSListSubItem.h : Declaration of the CNSListSubItem

#ifndef __NSLISTSUBITEM_H_
#define __NSLISTSUBITEM_H_

#include "resource.h"       // main symbols

class CNSListView;
class CNSListItem;
class CNSListSubItems;

/////////////////////////////////////////////////////////////////////////////
// CNSListSubItem
class ATL_NO_VTABLE CNSListSubItem : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSListSubItem, &CLSID_NSListSubItem>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSListSubItem, &IID_INSListSubItem, &LIBID_COMCTLLib>
{
public:
	CNSListSubItem() {
        m_lSubItemIndex = -1;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSLISTSUBITEM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSListSubItem)
	COM_INTERFACE_ENTRY(INSListSubItem)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)
END_COM_MAP()

CNSListView*        m_pListView;
CNSListItem*        m_pListItem;
CNSListSubItems*    m_pListSubItems;
LONG                m_lSubItemIndex;
ccVariant           m_vTag;

// ccBSTR              m_bstrText;
// ccVariant           m_vIcon;






// INSComCtlInt
    STDMETHOD(NSTerminate)();
    STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSListSubItem
public:
	STDMETHOD(get_IsSubItem)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(get_ListItem)(/*[out, retval]*/ INSListItem* *pVal);
    STDMETHOD(CorrectIndexIfGreater)(long lSubIndex,long lCorrection);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
    STDMETHOD(putref_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Key)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Index)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Index)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Icon)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Icon)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Text)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Text)(/*[in]*/ BSTR newVal);
};

#endif //__NSLISTSUBITEM_H_
