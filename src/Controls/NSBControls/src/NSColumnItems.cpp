// NSColumnItems.cpp : Implementation of CNSColumnItems
#include "stdafx.h"
#include "ComCtl.h"
#include "NSColumnHeader.h"
#include "NSListView.h"
#include "NSListItems.h"
#include "NSListItem.h"
#include "NSColumnItems.h"

/////////////////////////////////////////////////////////////////////////////
// CNSColumnItems

STDMETHODIMP CNSColumnItems::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSColumnItems
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// INSComCtlInt
STDMETHODIMP    CNSColumnItems::NSTerminate() {
    m_pColumnHeader = NULL;
    return S_OK;
}
STDMETHODIMP    CNSColumnItems::NSInitialize() {
    return S_OK;
}

STDMETHODIMP CNSColumnItems::get_Item(VARIANT Index, IDispatch **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pColumnHeader || 
        !m_pColumnHeader->m_pListView || 
        !m_pColumnHeader->m_pListView->m_pListItems) return E_UNEXPECTED;
    
    long nColumnIndex = (long)m_pColumnHeader->FindMyIndex();
    if (nColumnIndex == 0) {
        return m_pColumnHeader->m_pListView->m_pListItems->get_Item(Index,(INSListItem**)pVal);
    } else if (nColumnIndex > 0) {
        CComPtr<INSListItem>    spListItem;
        HRESULT hr = m_pColumnHeader->m_pListView->m_pListItems->get_Item(Index,&spListItem);
        if (FAILED(hr)) return hr;
        CComPtr<INSListSubItems>    spSubItems;
        hr = spListItem->get_SubItems(&spSubItems);
        if (FAILED(hr)) return hr;
        ccVariant vIndex(nColumnIndex);
        return spSubItems->get_Item(vIndex,(INSListSubItem**)pVal);
    } else {
        return E_UNEXPECTED;
    }
}

STDMETHODIMP CNSColumnItems::get_Count(long *pVal) {
    if (!pVal) return E_POINTER;
	if (!m_pColumnHeader || !m_pColumnHeader->m_pListView || !m_pColumnHeader->m_pListView->m_pListItems) return E_UNEXPECTED;
    return m_pColumnHeader->m_pListView->m_pListItems->get_Count(pVal);
}

STDMETHODIMP CNSColumnItems::get__NewEnum(IUnknown **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pColumnHeader) return E_POINTER;
    long nColumnIndex = (long)m_pColumnHeader->FindMyIndex();

    long    i;
    HRESULT hr;

    CSimpleArray<CComVariant> arrEnum;
    CComVariant v;
    CComPtr<INSListItem>        spListItem;
    CComPtr<INSListSubItem>     spListSubItem;
    CComPtr<INSListSubItems>    spListSubItems;

    if (nColumnIndex == 0) {
        for (i = 0;i < m_pColumnHeader->m_pListView->m_pListItems->m_arrListItems.GetSize(); i++) {
            v = (IDispatch*)(INSListItem*)m_pColumnHeader->m_pListView->m_pListItems->m_arrListItems[i];
            if (!arrEnum.Add(v)) {
                arrEnum.RemoveAll();
                return E_OUTOFMEMORY;
            }
            v.Clear();        
        }
    } else if (nColumnIndex > 0) {
        for (i = 0;i < m_pColumnHeader->m_pListView->m_pListItems->m_arrListItems.GetSize(); i++) {
            spListItem.Release();
            spListItem = m_pColumnHeader->m_pListView->m_pListItems->m_arrListItems[i];
            spListSubItems.Release();
            hr = spListItem->get_SubItems(&spListSubItems);
            if (!FAILED(hr)) {
                spListSubItem.Release();
                hr = spListSubItems->get_ItemIfExists(nColumnIndex,&spListSubItem);
                if (!FAILED(hr)) {
                    v = (IDispatch*)(INSListSubItem*)spListSubItem;
                    if (!arrEnum.Add(v)) {
                        arrEnum.RemoveAll();
                        return E_OUTOFMEMORY;
                    }
                    v.Clear();        
                }
            }
        }
    } else {
        return E_UNEXPECTED;
    }

    typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;

    enumvar* p = new enumvar;

    if (!arrEnum.GetSize()) {
        hr = p->Init(NULL, NULL, NULL, AtlFlagCopy);
    } else {
	    hr = p->Init(&arrEnum[0], (&arrEnum[arrEnum.GetSize()-1] + 1), NULL, AtlFlagCopy);
    }

    if (SUCCEEDED(hr)) hr = p->QueryInterface(IID_IEnumVARIANT, (void**)pVal);
    if (FAILED(hr)) {
		delete p;
        return hr;
    }
	return S_OK;

}
