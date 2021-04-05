// NSListItem.h : Declaration of the CNSListItem

#ifndef __NSLISTITEM_H_
#define __NSLISTITEM_H_

#include "resource.h"       // main symbols
class   CNSListView;
class   CNSListSubItems;

/////////////////////////////////////////////////////////////////////////////
// CNSListItem
class ATL_NO_VTABLE CNSListItem : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSListItem, &CLSID_NSListItem>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSListItem, &IID_INSListItem, &LIBID_COMCTLLib>
{
public:
	CNSListItem() {
        m_pListView = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSLISTITEM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSListItem)
	COM_INTERFACE_ENTRY(INSListItem)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)
END_COM_MAP()

CNSListView*                    m_pListView;
ccBSTR                          m_bstrKey;
ccVariant                       m_vTag;
CComObject<CNSListSubItems>*    m_pListSubItems;
CComPtr<INSListSubItems>        m_spListSubItems;

// ccBSTR                          m_bstrText;
// ccVariant                       m_vIcon;
// ccVariant                       m_vSmallIcon;

int FindMyItem();

// INSComCtlInt
    STDMETHOD(NSTerminate)();
    STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSListItem
public:
	STDMETHOD(get_Index)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Y)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Y)(/*[in]*/ long newVal);
	STDMETHOD(get_X)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_X)(/*[in]*/ long newVal);
	STDMETHOD(get_IsSubItem)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_ListItem)(/*[out, retval]*/ INSListItem* *pVal);
	STDMETHOD(EnsureVisible)(/*[in,defaultvalue(0)]*/ VARIANT_BOOL bPartialOk);
	STDMETHOD(StartLabelEdit)();
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(get_Checked)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Checked)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_SubItems)(/*[out, retval]*/ INSListSubItems* *pVal);
	STDMETHOD(get_Icon)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Icon)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Indent)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Indent)(/*[in]*/ long newVal);
	STDMETHOD(get_Selected)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Selected)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Text)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Text)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
    STDMETHOD(putref_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Key)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Key)(/*[in]*/ BSTR newVal);
};

#endif //__NSLISTITEM_H_
