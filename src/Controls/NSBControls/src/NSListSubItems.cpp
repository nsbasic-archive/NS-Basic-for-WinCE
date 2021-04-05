// NSListSubItems.cpp : Implementation of CNSListSubItems
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSListItem.h"
#include "NSListSubItems.h"
#include "NSListSubItem.h"
#include "NSColumnHeaders.h"

/////////////////////////////////////////////////////////////////////////////
// CNSListSubItems

STDMETHODIMP CNSListSubItems::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSListSubItems
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CNSListSubItems::ColumnRemoveUpdate(long lSubIndex) {
    long    i;
    HRESULT hr;

    // First delete the item with lSubIndex
    ccVariant vSubIndex = lSubIndex;
    i = (long)FindItem(vSubIndex);
    if (i >= 0) {
        NSTERMINATE(m_arrListSubItems[i]);
        m_arrListSubItems.RemoveAt((int)i);
    }

    for (i = m_arrListSubItems.GetSize() - 1; i >= 0; i--) {
        if (m_arrListSubItems[i]) {
            hr = m_arrListSubItems[i]->CorrectIndexIfGreater(lSubIndex,-1);
            if (FAILED(hr)) continue;
        }
    }
    return S_OK;
}
STDMETHODIMP CNSListSubItems::ColumnInsertUpdate(long lSubIndex) {
    long    i;
    HRESULT hr;

    for (i = m_arrListSubItems.GetSize() - 1; i >= 0; i--) {
        if (m_arrListSubItems[i]) {
            hr = m_arrListSubItems[i]->CorrectIndexIfGreater(lSubIndex-1,1);
            if (FAILED(hr)) continue;
        }
    }
    return S_OK;
}
STDMETHODIMP CNSListSubItems::ColumnsClear() {
    for (int i = 0; i < m_arrListSubItems.GetSize(); i++) {
        NSTERMINATE(m_arrListSubItems[i]);
    }
    m_arrListSubItems.RemoveAll();
    return S_OK;
}

int     CNSListSubItems::FindItem(VARIANT Index,long* piSubItem) {
    if (!m_pListView) return -1;
    ccVariant   vIndex(Index);
    HRESULT     hr;
    vIndex.ToValue();
    long        lIndexSearched = -1;
    if (vIndex.IsNumeric()) {
        lIndexSearched = (long)vIndex;
    } else {
        hr = vIndex.ChangeType(VT_BSTR);
        if (!FAILED(hr)) {
            // Search for that key in the columns collection
            CComPtr<INSColumnHeader>    spColumnHeader;
            hr = m_pListView->m_spColumnHeaders->get_Item(vIndex,&spColumnHeader);
            if (FAILED(hr)) return -1;
            hr = spColumnHeader->get_SubItemIndex(&lIndexSearched);
            if (FAILED(hr)) return -1;
        }
    }
    if (piSubItem) *piSubItem = lIndexSearched;
    if (lIndexSearched >= 0) {
        long        iSubitem;
        ccVariant   vSubItem;
        // Find item by its Index == iSubitem
        for (int i = 0; i < m_arrListSubItems.GetSize(); i++) {
            if (!m_arrListSubItems[i]) continue;
            hr = m_arrListSubItems[i]->get_Index(&vSubItem);
            if (!FAILED(hr)) {
                iSubitem = (long)vSubItem;
                if (iSubitem == (long)lIndexSearched) {
                    return i;
                }
            }
        }
    }
    return -1;
}

HRESULT CNSListSubItems::FinalConstruct() {
    return S_OK;
}
void    CNSListSubItems::FinalRelease() {
    m_pListView = NULL;
    m_pListItem = NULL;
    for (int i =0; i < m_arrListSubItems.GetSize(); i++) {
        NSTERMINATE(m_arrListSubItems[i]);
    }
    m_arrListSubItems.RemoveAll();
}

STDMETHODIMP    CNSListSubItems::NSTerminate() {
    m_pListView = NULL;
    m_pListItem = NULL;
    for (int i =0; i < m_arrListSubItems.GetSize(); i++) {
        NSTERMINATE(m_arrListSubItems[i]);
    }
    m_arrListSubItems.RemoveAll();
    return S_OK;
}
STDMETHODIMP    CNSListSubItems::NSInitialize() {
    return S_OK;
}

STDMETHODIMP CNSListSubItems::Clear() {
    long        iSubItem;
    HRESULT     hr;
    LVITEM      lvi;
    ccVariant   vSubItem;
    // Clear up all the subitems
	for (int i = 0; i < m_arrListSubItems.GetSize(); i++) {
        if (m_pListView) {
            if (m_arrListSubItems[i]) {
                hr = m_arrListSubItems[i]->get_Index(&vSubItem);
                if (!FAILED(hr)) {
                    iSubItem = (long)vSubItem;
                    ZeroMemory(&lvi,sizeof(LVITEM));
                    lvi.mask = LVIF_IMAGE | LVIF_PARAM | LVIF_TEXT;
                    lvi.iImage = -1;
                    lvi.pszText = NULL;
                    lvi.lParam = 0;
                    lvi.iItem = m_pListItem->FindMyItem();
                    lvi.iSubItem = iSubItem;
                    if (lvi.iItem >= 0) {
                        ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
                    }
                }
            }
        }
        NSTERMINATE(m_arrListSubItems[i]);
    }
    m_arrListSubItems.RemoveAll();
	return S_OK;
}

STDMETHODIMP CNSListSubItems::get_Count(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    *pVal = (long)m_pListView->m_pColumnHeaders->m_arrColumnHeaders.GetSize();
    // TODO: Add your implementation code here

	return S_OK;
}
HRESULT CNSListSubItems::_Remove(VARIANT Index) {
    long iArrayIndex = FindItem(Index);
    HRESULT hr;
    if (iArrayIndex < 0) return S_FALSE; // No error returned - it is possible that there is no such subitem defined ever
    // If the item exists - remove it
    if (m_pListView && m_pListItem) {
        long iSubItem;
        if (m_arrListSubItems[iArrayIndex]) {
            ccVariant vSubItem;
            hr = m_arrListSubItems[iArrayIndex]->get_Index(&vSubItem);
            if (FAILED(hr)) return hr;
            iSubItem = (long)vSubItem;
            LVITEM  lvi;
            ZeroMemory(&lvi,sizeof(LVITEM));
            lvi.mask = LVIF_IMAGE | LVIF_PARAM | LVIF_TEXT;
            lvi.iImage = -1;
            lvi.pszText = NULL;
            lvi.lParam = 0;
            lvi.iItem = m_pListItem->FindMyItem();
            lvi.iSubItem = iSubItem;
            if (lvi.iItem >= 0) {
                ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
            }
        }
    }
    NSTERMINATE(m_arrListSubItems[iArrayIndex]);
    m_arrListSubItems.RemoveAt(iArrayIndex);
	return S_OK;
}
STDMETHODIMP CNSListSubItems::Remove(VARIANT Index) {
	return _Remove(Index);
}

/**
    Index is actually iSubItem or a column Key
 */
STDMETHODIMP CNSListSubItems::get_Item(VARIANT Index, INSListSubItem **pVal) {
    if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    long iArrayIndex = FindItem(Index);
    HRESULT hr;
    if (iArrayIndex < 0) {
        long        iSubItem = -1;
        ccVariant   vIndex(Index);
        vIndex.ToValue();
        if (vIndex.IsNumeric()) {
            iSubItem = (long)vIndex; // Numeric
        } else {
            // String key - find it in the columns
            hr = vIndex.ChangeType(VT_BSTR);
            if (!FAILED(hr)) {
                // Search for that key in the columns collection
                CComPtr<INSColumnHeader>    spColumnHeader;
                hr = m_pListView->m_spColumnHeaders->get_Item(vIndex,&spColumnHeader);
                if (FAILED(hr)) return E_FAIL;
                hr = spColumnHeader->get_SubItemIndex(&iSubItem);
                if (FAILED(hr)) return E_FAIL;
            }
        }
        // Create an item for it
        if (iSubItem > 0) {
            // Create an item for this
            CComObject<CNSListSubItem>*     plsi = NULL;
            hr = CComObject<CNSListSubItem>::CreateInstance(&plsi);
            if (FAILED(hr)) return hr;
            CComPtr<INSListSubItem>         spSubItem;
            hr = plsi->QueryInterface(IID_INSListSubItem,(void**)&spSubItem);
            if (FAILED(hr)) {
                delete plsi;
                return hr;
            }
            // Initialize the item
            plsi->m_lSubItemIndex = iSubItem;
            plsi->m_pListItem = m_pListItem;
            plsi->m_pListView = m_pListView;
            plsi->m_pListSubItems = this;
            NSINITIALIZE(spSubItem);
            // Put it in the array
            if (!m_arrListSubItems.Add(spSubItem)) return E_OUTOFMEMORY;
            *pVal = spSubItem;
            if (*pVal) (*pVal)->AddRef();
            return S_OK;
        } else {
            return DISP_E_BADINDEX;
        }
    } else {
        // Return the existing entry
        *pVal = m_arrListSubItems[iArrayIndex];
        if (*pVal) (*pVal)->AddRef();
        return S_OK;
    }
}

STDMETHODIMP CNSListSubItems::get__NewEnum(IUnknown **pVal) {
	if (!pVal) return E_POINTER;

    long    i;
    HRESULT hr;

    CSimpleArray<CComVariant> arrEnum;
    CComVariant v;
    // Copy the array
    for (i = 0;i < m_arrListSubItems.GetSize(); i++) {
        v = (IDispatch*)(INSListSubItem*)m_arrListSubItems[i];
        if (!arrEnum.Add(v)) {
            arrEnum.RemoveAll();
            return E_OUTOFMEMORY;
        }
        v.Clear();        
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

STDMETHODIMP CNSListSubItems::get_ItemByIndex(long Index, INSListSubItem **pVal) {
    if (!pVal) return E_POINTER;

    if (Index < 1 || Index > m_arrListSubItems.GetSize()) return DISP_E_BADINDEX;

    *pVal = m_arrListSubItems[Index - 1];
    if (*pVal) (*pVal)->AddRef();

	return S_OK;
}

STDMETHODIMP CNSListSubItems::RemoveByIndex(long Index) {
	if (Index < 1 || Index > m_arrListSubItems.GetSize()) return DISP_E_BADINDEX;

    if (m_pListView && m_pListItem) {
        long iSubItem;
        if (m_arrListSubItems[(int)Index]) {
            ccVariant vSubItem;
            HRESULT hr = m_arrListSubItems[(int)Index]->get_Index(&vSubItem);
            if (FAILED(hr)) return hr;
            iSubItem = (long)vSubItem;
            LVITEM  lvi;
            ZeroMemory(&lvi,sizeof(LVITEM));
            lvi.mask = LVIF_IMAGE | LVIF_PARAM | LVIF_TEXT;
            lvi.iImage = 0;
            lvi.pszText = NULL;
            lvi.lParam = 0;
            lvi.iItem = m_pListItem->FindMyItem();
            lvi.iSubItem = iSubItem;
            if (lvi.iItem >= 0) {
                ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);
            }
        }
    }
    NSTERMINATE(m_arrListSubItems[(int)Index]);
    m_arrListSubItems.RemoveAt((int)Index);
	return S_OK;
}

STDMETHODIMP CNSListSubItems::get_DefinedCount(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_arrListSubItems.GetSize();
	return S_OK;
}

STDMETHODIMP CNSListSubItems::get_ListItem(INSListItem **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListItem) return E_UNEXPECTED;
    return m_pListItem->QueryInterface(IID_INSListItem,(void**)pVal);
}

STDMETHODIMP CNSListSubItems::get_ListView(INSListView **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    return m_pListView->QueryInterface(IID_INSListView,(void**)pVal);
}

STDMETHODIMP CNSListSubItems::get_ItemIfExists(long Index, INSListSubItem **pVal) {
	if (!pVal) return E_POINTER;
    ccVariant vIndex(Index);
    long iArrayIndex = FindItem(vIndex);
    if (iArrayIndex >= 0) {
        // Return the existing entry
        *pVal = m_arrListSubItems[iArrayIndex];
        if (*pVal) (*pVal)->AddRef();
        return S_OK;
    }
    *pVal = NULL;
	return DISP_E_BADINDEX;
}
