// NSColumnHeader.h : Declaration of the CNSColumnHeader

#ifndef __NSCOLUMNHEADER_H_
#define __NSCOLUMNHEADER_H_

#include "resource.h"       // main symbols

class CNSColumnHeaders;
class CNSListView;

/////////////////////////////////////////////////////////////////////////////
// CNSColumnHeader
class ATL_NO_VTABLE CNSColumnHeader : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSColumnHeader, &CLSID_NSColumnHeader>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSColumnHeader, &IID_INSColumnHeader, &LIBID_COMCTLLib>
{
public:
	CNSColumnHeader() {
        m_pListView = NULL;
        m_pColumnHeaders = NULL;
        m_SortType = lvwTextSort;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSCOLUMNHEADER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT     FinalConstruct();
void        FinalRelease();

BEGIN_COM_MAP(CNSColumnHeader)
	COM_INTERFACE_ENTRY(INSColumnHeader)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)    
END_COM_MAP()

CNSListView*                m_pListView;
CNSColumnHeaders*           m_pColumnHeaders;
ccBSTR                      m_bstrKey;
ccVariant                   m_vTag;
CComPtr<INSColumnItems>     m_spColumnItems;
NSListSortTypeConstants     m_SortType;

int     FindMyIndex();
long    GetMySubIndex();

// INSComCtlInt
    STDMETHOD(NSTerminate)();
    STDMETHOD(NSInitialize)();

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSColumnHeader
public:
	STDMETHOD(get_ShowImage)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ShowImage)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Width)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Width)(/*[in]*/ long newVal);
	STDMETHOD(get_SortType)(/*[out, retval]*/ NSListSortTypeConstants *pVal);
	STDMETHOD(put_SortType)(/*[in]*/ NSListSortTypeConstants newVal);
	STDMETHOD(get_ColumnItems)(/*[out, retval]*/ INSColumnItems* *pVal);
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(get_Position)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Position)(/*[in]*/ long newVal);
	STDMETHOD(get_Icon)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Icon)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
    STDMETHOD(putref_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_SubItemIndex)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_SubItemIndex)(/*[in]*/ long newVal);
	STDMETHOD(get_Key)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Key)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Index)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Index)(/*[in]*/ long newVal);
	STDMETHOD(get_Alignment)(/*[out, retval]*/ NSListColumnAlignment *pVal);
	STDMETHOD(put_Alignment)(/*[in]*/ NSListColumnAlignment newVal);
	STDMETHOD(get_Text)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Text)(/*[in]*/ BSTR newVal);
};

#endif //__NSCOLUMNHEADER_H_
