// NSListItems.cpp : Implementation of CNSListItems
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSListItems.h"
#include "NSListItem.h"

/////////////////////////////////////////////////////////////////////////////
// CNSListItems

STDMETHODIMP CNSListItems::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSListItems
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CNSListItems::FinalConstruct() {
    return S_OK;
}
void    CNSListItems::FinalRelease() {
    for (int i = 0; i < m_arrListItems.GetSize(); i++) {
        NSTERMINATE(m_arrListItems[i]);
    }
    m_arrListItems.RemoveAll();
}

int CNSListItems::FindItem(VARIANT Index) {
    if (!m_pListView) return -1;
    ccVariant   vIndex(Index);
    HRESULT     hr;
    BOOL        bNumeric;
    vIndex.ToValue();
    if (vIndex.IsNumeric()) {
        hr = vIndex.ChangeType(VT_I4);
        bNumeric = TRUE;
    } else {
        hr = vIndex.ChangeType(VT_BSTR);
        bNumeric = FALSE;
    }
    if (FAILED(hr)) return -1;

    if (!bNumeric) {
        int i;
        ccBSTR  bstrKey;
        for (i = 0; i < m_arrListItems.GetSize(); i++) {
            bstrKey.Empty();
            hr = m_arrListItems[i]->get_Key(&bstrKey);
            if (FAILED(hr)) continue;
            if (_WCompareStr(bstrKey,vIndex.bstrVal) == S_OK) return i;
        }
        // if not found by name try number
        hr = vIndex.ChangeType(VT_BSTR);
        if (FAILED(hr)) return -1;
    }

    
    if (vIndex.lVal < 1 || vIndex.lVal > m_arrListItems.GetSize()) return -1;
    // Get the item from the listview by index and then find the corresponding array index
    LVITEM lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));
    lvi.iItem = vIndex.lVal - 1;
    lvi.mask = LVIF_PARAM;
    if (ListView_GetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi)) {
        int i;
        for (i = 0; i < m_arrListItems.GetSize(); i++) {
            if ((INSListItem*)m_arrListItems[i] == (INSListItem*)lvi.lParam) return i;
        }
    } 
    return -1;
    
}

// INSComCtlInt
STDMETHODIMP    CNSListItems::NSTerminate() {
    for (int i = 0; i < m_arrListItems.GetSize(); i++) {
        NSTERMINATE(m_arrListItems[i]);
    }
    m_pListView = NULL;
    return S_OK;
    //// **** ////
}
STDMETHODIMP    CNSListItems::NSInitialize() {
    return S_OK;
}

STDMETHODIMP CNSListItems::get_Count(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (long)m_arrListItems.GetSize();
	return S_OK;
}

STDMETHODIMP CNSListItems::Clear() {
	for (int i = 0; i < m_arrListItems.GetSize(); i++) {
        NSTERMINATE(m_arrListItems[i]);
    }
    m_arrListItems.RemoveAll();
    if (m_pListView) {
        ListView_DeleteAllItems(m_pListView->m_ctlSysListView32.m_hWnd);
    }
	return S_OK;
}

STDMETHODIMP CNSListItems::Remove(VARIANT Index) {
    if (!m_pListView) return E_UNEXPECTED;
    int iItem = FindItem(Index);
    if (iItem < 0) return DISP_E_BADINDEX;

    LVFINDINFO lvfi;
    ZeroMemory(&lvfi,sizeof(LVFINDINFO));
    lvfi.flags = LVFI_PARAM;
    lvfi.lParam = (LPARAM)(INSListItem*)m_arrListItems[iItem];
    LONG iIndex = ListView_FindItem(m_pListView->m_ctlSysListView32.m_hWnd,-1,&lvfi);
    if (iIndex >= 0) {
        ListView_DeleteItem(m_pListView->m_ctlSysListView32.m_hWnd,iIndex);
    }
    NSTERMINATE(m_arrListItems[iItem]);
    m_arrListItems.RemoveAt(iItem);

	return S_OK;
}

STDMETHODIMP CNSListItems::get_Item(VARIANT Index, INSListItem **pVal) {
	if (!pVal) return E_POINTER;
    int iItem = FindItem(Index);
    if (iItem < 0) return DISP_E_BADINDEX;

    *pVal = m_arrListItems[iItem];
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListItems::Add(VARIANT Index, VARIANT Key, VARIANT Text, VARIANT Icon, VARIANT Indent, INSListItem **ppObj) {
	if (!ppObj) return E_POINTER;
	if (!m_pListView) return E_UNEXPECTED;
    int nCount = m_arrListItems.GetSize();

    CComObject<CNSListItem>*            pli = NULL;
    HRESULT hr = CComObject<CNSListItem>::CreateInstance(&pli);
    if (FAILED(hr)) return hr;

    CComPtr<INSListItem>                spLI;
    hr = pli->QueryInterface(IID_INSListItem,(void**)&spLI);
    if (FAILED(hr)) {
        delete pli;
        return hr;
    }

    ccVariant   vIndex(Index),
                vKey(Key),
                vText(Text),
                vIcon(Icon),
                vIndent(Indent);

    LVITEM      lvi;
    ZeroMemory(&lvi,sizeof(LVITEM));

    if (!vIndent.IsOmitted()) {
        lvi.iIndent = (int)vIndent;
        lvi.mask |= LVIF_INDENT;
    }
    if (!vIndex.IsOmitted()) {
        lvi.iItem = ((int)vIndex - 1);
        if (lvi.iItem < 0 || lvi.iItem > m_arrListItems.GetSize()) return DISP_E_BADINDEX;
    } else {
        lvi.iItem = (long)m_arrListItems.GetSize();
    }
    if (!vIcon.IsOmitted()) {
        lvi.iImage = (int)m_pListView->_FindImageIndex(vIcon,0);
        lvi.mask |= LVIF_IMAGE;
    }
    ccBSTR  bstrText;
    lvi.mask |= LVIF_TEXT;
    if (!vText.IsOmitted()) {
        bstrText = vText;
        lvi.pszText = (BSTR)bstrText;
    } else {
        lvi.pszText = L"";
    }

    // Set the interface pointer only if we have the item's object under control
    // We are  not using this pointer for calls now, but better be careful to make it valid.
    lvi.lParam = (LPARAM)(INSListItem*)spLI;
    lvi.mask |= LVIF_PARAM;

    int nNewIndex = ListView_InsertItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi);

    if (nNewIndex < 0) {
        return ReprotCOMErrorInfo(L"Failed to add item.",IID_INSListItems,L"ListView");
    }

    if (!m_arrListItems.Add(spLI)) return E_OUTOFMEMORY;

    bstrText = vKey;
    if (!vKey.IsOmitted()) pli->m_bstrKey = bstrText;

    pli->m_pListView = m_pListView;

    NSINITIALIZE(spLI);

    *ppObj = (INSListItem*)spLI;
    (*ppObj)->AddRef();

	return S_OK;
}

STDMETHODIMP CNSListItems::get__NewEnum(IUnknown **pVal) {
	if (!pVal) return E_POINTER;

    long    i;
    HRESULT hr;

    CSimpleArray<CComVariant> arrEnum;
    CComVariant v;
    // Copy the array
    for (i = 0;i < m_arrListItems.GetSize(); i++) {
        v = (IDispatch*)(INSListItem*)m_arrListItems[i];
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

STDMETHODIMP CNSListItems::get_ListView(INSListView **pVal) {
	if (!m_pListView) return E_UNEXPECTED;
	if (!pVal) return E_POINTER;
    return m_pListView->QueryInterface(IID_INSListView,(void**)pVal);
}
