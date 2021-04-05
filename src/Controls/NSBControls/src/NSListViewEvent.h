// NSListViewEvent.h : Declaration of the CNSListViewEvent

#ifndef __NSLISTVIEWEVENT_H_
#define __NSLISTVIEWEVENT_H_

#include "resource.h"       // main symbols
#include "ComCtlCP.h"

/////////////////////////////////////////////////////////////////////////////
// CNSListViewEvent
class ATL_NO_VTABLE CNSListViewEvent : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSListViewEvent, &CLSID_NSListViewEvent>,
	public ISupportErrorInfo,
	public IDispatchImpl<INSListViewEvent, &IID_INSListViewEvent, &LIBID_COMCTLLib>,
	public CProxy_INSListViewEvents< CNSListViewEvent >,
	public IConnectionPointContainerImpl<CNSListViewEvent>
{
public:
	CNSListViewEvent() {
        m_lEvent = 0;
        m_bCancel = VARIANT_FALSE;
        m_lKey = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSLISTVIEWEVENT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNSListViewEvent)
	COM_INTERFACE_ENTRY(INSListViewEvent)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

CComPtr<INSColumnHeader>        m_spColumn;
CComPtr<INSListItem>            m_spItem;
CComPtr<INSListSubItem>         m_spSubItem;
CComPtr<INSListView>            m_spListView;
long                            m_lEvent;
ccBSTR                          m_bstrText;
VARIANT_BOOL                    m_bCancel;
long                            m_lKey;

static CNSListViewEvent* CreateListEvent(INSListViewEvent** ppObj);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSListViewEvent
public:
	STDMETHOD(get_Cancel)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Cancel)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Text)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Event)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_SubItem)(/*[out, retval]*/ INSListSubItem* *pVal);
	STDMETHOD(get_Item)(/*[out, retval]*/ INSListItem* *pVal);
	STDMETHOD(get_Column)(/*[out, retval]*/ INSColumnHeader* *pVal);
public :
	STDMETHOD(get_ListView)(/*[out, retval]*/ INSListView* *pVal);
	STDMETHOD(get_Key)(/*[out, retval]*/ long *pVal);

BEGIN_CONNECTION_POINT_MAP(CNSListViewEvent)
	CONNECTION_POINT_ENTRY(DIID__INSListViewEvents)
END_CONNECTION_POINT_MAP()

};

#endif //__NSLISTVIEWEVENT_H_
