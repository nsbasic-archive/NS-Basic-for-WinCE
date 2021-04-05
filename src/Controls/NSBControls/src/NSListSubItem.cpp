// NSListSubItem.cpp : Implementation of CNSListSubItem
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSListItem.h"
#include "NSListSubItems.h"
#include "NSListSubItem.h"
#include "NSColumnHeaders.h"

/////////////////////////////////////////////////////////////////////////////
// CNSListSubItem

STDMETHODIMP CNSListSubItem::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSListSubItem
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


HRESULT CNSListSubItem::FinalConstruct() {
    return S_OK;
}
void    CNSListSubItem::FinalRelease() {
    m_pListView     = NULL;
    m_pListItem     = NULL;
    m_pListSubItems = NULL;
}

STDMETHODIMP    CNSListSubItem::CorrectIndexIfGreater(long lSubIndex,long lCorrection) {
    if (m_lSubItemIndex > lSubIndex) m_lSubItemIndex += lCorrection;
    return S_OK;
}

STDMETHODIMP    CNSListSubItem::NSTerminate() {
    m_pListView     = NULL;
    m_pListItem     = NULL;
    m_pListSubItems = NULL;
    return S_OK;
}
STDMETHODIMP    CNSListSubItem::NSInitialize() {
    return S_OK;
}

STDMETHODIMP CNSListSubItem::get_Text(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListItem || !m_pListView) return E_UNEXPECTED;
    int nItem  = m_pListItem->FindMyItem();
    if (nItem < 0) return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListSubItem,L"ListView");

    LVITEM  lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.iItem = nItem;
    lvi.iSubItem = (int)m_lSubItemIndex;
    lvi.mask = LVIF_TEXT;
    TCHAR   _l[2048];
    lvi.pszText = _l;
    _l[0] = TEXT('\0');
    lvi.cchTextMax = 2048;

    ccBSTR bstr;
    ListView_GetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
    
    _l[2048 - 1] = TEXT('\0');
    bstr = lvi.pszText;
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CNSListSubItem::put_Text(BSTR newVal) {
    if (!m_pListItem || !m_pListView) return E_UNEXPECTED;
    int nItem  = m_pListItem->FindMyItem();
    if (nItem < 0) return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListSubItem,L"ListView");

    LVITEM  lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.iItem = nItem;
    lvi.iSubItem = (int)m_lSubItemIndex;
    lvi.mask = LVIF_TEXT;
    lvi.pszText = newVal;

    ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
    
    return S_OK;
}

STDMETHODIMP CNSListSubItem::get_Icon(VARIANT *pVal) {
    if (!pVal) return E_POINTER;
	if (!m_pListItem || !m_pListView) return E_UNEXPECTED;
    int nItem  = m_pListItem->FindMyItem();
    if (nItem < 0) return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListSubItem,L"ListView");

    LVITEM  lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.iItem = nItem;
    lvi.iSubItem = (int)m_lSubItemIndex;
    lvi.mask = LVIF_IMAGE;

    ListView_GetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
    ccVariant vImage;
    vImage = (long)(lvi.iImage + 1);
    return vImage.CopyTo(pVal);
}

STDMETHODIMP CNSListSubItem::put_Icon(VARIANT newVal) {
	if (!m_pListItem || !m_pListView) return E_UNEXPECTED;
    int nItem  = m_pListItem->FindMyItem();
    if (nItem < 0) return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListSubItem,L"ListView");

    ccVariant vImage(newVal);
    LVITEM  lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.iItem = nItem;
    lvi.iSubItem = (int)m_lSubItemIndex;
    lvi.mask = LVIF_IMAGE;
    lvi.iImage = (int)m_pListView->_FindImageIndex(vImage,2);

    ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
    
    return S_OK;
}

STDMETHODIMP CNSListSubItem::get_Index(VARIANT *pVal) {
    if (!pVal) return E_POINTER;
    ccVariant vIndex;
    vIndex = m_lSubItemIndex;
    return vIndex.CopyTo(pVal);
}

STDMETHODIMP CNSListSubItem::put_Index(VARIANT newVal) {
    if (!m_pListView || !m_pListSubItems) return E_UNEXPECTED;
    if (!m_pListView->m_pColumnHeaders) return E_UNEXPECTED;

    CComPtr<INSListSubItem> spSubItem;
    HRESULT hr = QueryInterface(IID_INSListSubItem,(void**)&spSubItem);
    if (FAILED(hr)) return hr;

    long    iSubItemAssigned = -1; // To what iSubItemIndex the newVal actually refers

    int iArrayIndex = m_pListSubItems->FindItem(newVal,&iSubItemAssigned);
    if (iArrayIndex >= 0) {
        // An item with the same subindex exists
        // Is it this one - if so we do not need to do anything
        if ( (INSListSubItem*)spSubItem == (INSListSubItem*)m_pListSubItems->m_arrListSubItems[iArrayIndex] ) return S_OK;
        
        // If it is not we will remove it - because this item will replace it
        ccVariant vTempIndex;
        vTempIndex = iSubItemAssigned;
        m_pListSubItems->_Remove(vTempIndex);
        // We do not check for an error, because it is not fatal if the item is not removed - it will 
        // cause a little mess though.
    }
    
    if (iSubItemAssigned < 1) return DISP_E_BADINDEX;
    // Now make a change in this subitem

    int nItem  = m_pListItem->FindMyItem();
    if (nItem < 0) return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListSubItem,L"ListView");
        
    // First we need to retrieve the current subitem information 
    LVITEM  lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.mask = LVIF_IMAGE | LVIF_TEXT;
    lvi.iItem = nItem;
    lvi.iSubItem = m_lSubItemIndex;
    TCHAR   _l[2048];
    _l[0] = TEXT('\0');
    lvi.pszText = _l;
    lvi.cchTextMax = 2048;

    ListView_GetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
    _l[2048-1] = TEXT('\0');

    // Now set it back to the new index
    lvi.iSubItem = iSubItemAssigned;
    ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
    
    // Now remove the original subitem
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.mask = LVIF_IMAGE | LVIF_TEXT;
    lvi.iItem = nItem;
    lvi.iSubItem = m_lSubItemIndex;
    lvi.pszText = NULL;
    lvi.iImage = 0;
    ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);

    m_lSubItemIndex = iSubItemAssigned;

	return S_OK;
}

STDMETHODIMP CNSListSubItem::get_Key(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumnIndex = m_pListView->m_pColumnHeaders->FindBySubItemIndex(m_lSubItemIndex);
    if (nColumnIndex < 0) return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListSubItem,L"ListView");
    return m_pListView->m_pColumnHeaders->m_arrColumnHeaders[nColumnIndex]->get_Key(pVal);
}

STDMETHODIMP CNSListSubItem::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    return m_vTag.CopyTo(pVal);
}

STDMETHODIMP CNSListSubItem::put_Tag(VARIANT newVal) {
	m_vTag = newVal;
    return m_vTag.ToValue();
}

STDMETHODIMP CNSListSubItem::putref_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}

STDMETHODIMP CNSListSubItem::get_ListItem(INSListItem **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListItem) return E_UNEXPECTED;
    return m_pListItem->QueryInterface(IID_INSListItem,(void**)pVal);
}

STDMETHODIMP CNSListSubItem::get_ListView(INSListView **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    return m_pListView->QueryInterface(IID_INSListView,(void**)pVal);
}

STDMETHODIMP CNSListSubItem::get_IsSubItem(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = VARIANT_TRUE;
	return S_OK;
}
