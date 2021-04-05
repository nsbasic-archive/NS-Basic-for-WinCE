// NSListViewEvent.cpp : Implementation of CNSListViewEvent
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListViewEvent.h"

/////////////////////////////////////////////////////////////////////////////
// CNSListViewEvent

STDMETHODIMP CNSListViewEvent::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSListViewEvent
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// static 
CNSListViewEvent* CNSListViewEvent::CreateListEvent(INSListViewEvent** ppObj) {
    CComObject<CNSListViewEvent>*   p = NULL;
    HRESULT hr = CComObject<CNSListViewEvent>::CreateInstance(&p);
    if (FAILED(hr)) return NULL;

    hr = p->QueryInterface(IID_INSListViewEvent,(void**)ppObj);
    if (FAILED(hr)) {
        delete p;
        return NULL;
    }
    return p;
}

STDMETHODIMP CNSListViewEvent::get_Column(INSColumnHeader **pVal) {
	if (!pVal) return E_POINTER;
    // if (!m_spColumn) ReprotCOMErrorInfo(L"This event member is invalid for the current event.",IID_INSListViewEvent,L"ListView");
    *pVal = m_spColumn;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::get_Item(INSListItem **pVal) {
	if (!pVal) return E_POINTER;
    // if (!m_spColumn) ReprotCOMErrorInfo(L"This event member is invalid for the current event.",IID_INSListViewEvent,L"ListView");
    *pVal = m_spItem;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::get_SubItem(INSListSubItem **pVal) {
	if (!pVal) return E_POINTER;
    // if (!m_spColumn) ReprotCOMErrorInfo(L"This event member is invalid for the current event.",IID_INSListViewEvent,L"ListView");
    *pVal = m_spSubItem;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::get_Event(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lEvent;
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::get_Text(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrText.CopyTo(pVal);
}

STDMETHODIMP CNSListViewEvent::get_Cancel(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bCancel;
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::put_Cancel(VARIANT_BOOL newVal) {
	m_bCancel = newVal;
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::get_Key(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lKey;
	return S_OK;
}

STDMETHODIMP CNSListViewEvent::get_ListView(INSListView **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spListView;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}
