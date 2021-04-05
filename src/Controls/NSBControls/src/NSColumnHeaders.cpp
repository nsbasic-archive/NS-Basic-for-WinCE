// NSColumnHeaders.cpp : Implementation of CNSColumnHeaders
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSColumnHeaders.h"
#include "NSColumnHeader.h"

/////////////////////////////////////////////////////////////////////////////
// CNSColumnHeaders

STDMETHODIMP CNSColumnHeaders::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSColumnHeaders
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

int CNSColumnHeaders::FindBySubItemIndex(long lSubItemIndex) {
    int     i;
    HRESULT hr;
    long    lSubItem;
    for (i = 0; i < m_arrColumnHeaders.GetSize(); i++) {
        hr = m_arrColumnHeaders[i]->get_SubItemIndex(&lSubItem);
        if (FAILED(hr)) return -1;
        if (lSubItem == lSubItemIndex) return i;
    }
    return -1;
}

HRESULT     CNSColumnHeaders::AddInitialColumn() {
    CComObject<CNSColumnHeader>*        pch = NULL;
    HRESULT hr = CComObject<CNSColumnHeader>::CreateInstance(&pch);
    if (FAILED(hr)) return hr;

    CComPtr<INSColumnHeader>        spCH;
    hr = pch->QueryInterface(IID_INSColumnHeader,(void**)&spCH);
    if (FAILED(hr)) {
        delete pch;
        return hr;
    }
    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_WIDTH | LVCF_TEXT | LVCF_IMAGE;
    lvc.fmt = LVCFMT_LEFT;
    lvc.iSubItem = 0;
    lvc.cx = 100;
    lvc.pszText = L"";
    lvc.iImage = -1;

    int nNewIndex = ListView_InsertColumn(m_pListView->m_ctlSysListView32.m_hWnd,0,&lvc);

    if (nNewIndex < 0) {
        return ReprotCOMErrorInfo(L"Failed to add column.",IID_INSColumnHeaders,L"ListView");
    }

    if (!m_arrColumnHeaders.Insert(spCH,0)) return E_OUTOFMEMORY;

    ccBSTR  bstrText = TEXT("main");
    pch->m_bstrKey = bstrText;
    pch->m_pListView = m_pListView;
    pch->m_pColumnHeaders = this;

    NSINITIALIZE(spCH);

	return S_OK;

}

int CNSColumnHeaders::FindItem(VARIANT Index) {
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

    if (bNumeric) {
        if (vIndex.lVal < 0 || vIndex.lVal >= m_arrColumnHeaders.GetSize()) return -1;
        return (vIndex.lVal);
    } else {
        int i;
        ccBSTR  bstrKey;
        for (i = 0; i < m_arrColumnHeaders.GetSize(); i++) {
            bstrKey.Empty();
            hr = m_arrColumnHeaders[i]->get_Key(&bstrKey);
            if (FAILED(hr)) return -1;
            if (_WCompareStr(bstrKey,vIndex.bstrVal) == S_OK) return i;
        }
        // If not found try again numeric
        hr = vIndex.ChangeType(VT_I4);
        if (!FAILED(hr)) {
            if (vIndex.lVal < 0 || vIndex.lVal >= m_arrColumnHeaders.GetSize()) return -1;
            return (vIndex.lVal);
        }
    }
    return -1;
}

HRESULT CNSColumnHeaders::FinalConstruct() {
    return S_OK;
}
void    CNSColumnHeaders::FinalRelease() {
    for (int i = 0; i < m_arrColumnHeaders.GetSize(); i++) {
        NSTERMINATE(m_arrColumnHeaders[i]);
    }
    m_arrColumnHeaders.RemoveAll();
}


// INSComCtlInt
STDMETHODIMP    CNSColumnHeaders::NSTerminate() {
    for (int i = 0; i < m_arrColumnHeaders.GetSize(); i++) {
        NSTERMINATE(m_arrColumnHeaders[i]);
    }
    m_pListView = NULL;
    return S_OK;
    //// **** ////
}
STDMETHODIMP    CNSColumnHeaders::NSInitialize() {
    return S_OK;
}

// INSColumnHeaders
STDMETHODIMP CNSColumnHeaders::get_Count(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;

    *pVal = (long)(m_arrColumnHeaders.GetSize() - 1);
    
	return S_OK;
}

STDMETHODIMP CNSColumnHeaders::Clear() {
    if (!m_pListView) return E_UNEXPECTED;
    for (int i = m_arrColumnHeaders.GetSize() - 1; i >= 0; i--) {
        NSTERMINATE(m_arrColumnHeaders[i]);
        ListView_DeleteColumn(m_pListView->m_ctlSysListView32.m_hWnd,i);
    }
    m_arrColumnHeaders.RemoveAll();

    m_pListView->_RemoveAllSubItems();

    return AddInitialColumn();
}

STDMETHODIMP CNSColumnHeaders::get_Item(VARIANT Index,INSColumnHeader **pVal) {
    if (!pVal) return E_POINTER;

    int nIndex = FindItem(Index);
    if (nIndex < 0) return DISP_E_BADINDEX;

    *pVal = m_arrColumnHeaders[nIndex];
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSColumnHeaders::Remove(VARIANT Index) {
    if (!m_pListView) return E_UNEXPECTED;
	int nIndex = FindItem(Index);
    if (nIndex < 1) return DISP_E_BADINDEX;

    NSTERMINATE(m_arrColumnHeaders[nIndex]);
    ListView_DeleteColumn(m_pListView->m_ctlSysListView32.m_hWnd,nIndex);
    m_arrColumnHeaders[nIndex].Release();
    m_arrColumnHeaders.RemoveAt(nIndex);

    // Update the SubIndices of the other columns
    for (int i = nIndex; i < m_arrColumnHeaders.GetSize();i++) {
        m_arrColumnHeaders[i]->put_SubItemIndex((long)i);
    }
    // Update the subitems
    m_pListView->_RemoveSubItemsWithIndex(nIndex);

	return S_OK;
}

STDMETHODIMP CNSColumnHeaders::get__NewEnum(IUnknown **pVal) {
	if (!pVal) return E_POINTER;

    long    i;
    HRESULT hr;

    CSimpleArray<CComVariant> arrEnum;
    CComVariant v;
    // Copy the array
    for (i = 0;i < m_arrColumnHeaders.GetSize(); i++) {
        v = (IDispatch*)(INSColumnHeader*)m_arrColumnHeaders[i];
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

STDMETHODIMP CNSColumnHeaders::Add( VARIANT         Index, 
                                    VARIANT         Key, 
                                    VARIANT         Text, 
                                    VARIANT         Width, 
                                    VARIANT         Alignment, 
                                    VARIANT         Icon, 
                                    INSColumnHeader **ppObj) {
    if (!ppObj) return E_POINTER;
	if (!m_pListView) return E_UNEXPECTED;
    int nCount = m_arrColumnHeaders.GetSize();

    CComObject<CNSColumnHeader>*        pch = NULL;
    HRESULT hr = CComObject<CNSColumnHeader>::CreateInstance(&pch);
    if (FAILED(hr)) return hr;

    CComPtr<INSColumnHeader>        spCH;
    hr = pch->QueryInterface(IID_INSColumnHeader,(void**)&spCH);
    if (FAILED(hr)) {
        delete pch;
        return hr;
    }

    ccVariant   vIndex(Index),
                vKey(Key),
                vText(Text),
                vWidth(Width),
                vAlignment(Alignment),
                vIcon(Icon);

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));

    lvc.mask |= LVCF_FMT;
    if (!vAlignment.IsOmitted()) {
        lvc.fmt = (int)vAlignment;
    } else {
        lvc.fmt = LVCFMT_LEFT;
    }

    lvc.mask |= LVCF_WIDTH;
    if (!vWidth.IsOmitted()) {
        lvc.cx = (int)vWidth;
    } else {
        lvc.cx = (int)50;
    }

    if (!vIndex.IsOmitted()) {
        nCount = (long)vIndex;
        if (nCount < 1 || nCount > m_arrColumnHeaders.GetSize()) return DISP_E_BADINDEX;
    }
    
    if (!vIcon.IsOmitted()) {
        lvc.iImage = (int)m_pListView->_FindImageIndex(vIcon,3);
        lvc.mask |= LVCF_IMAGE;
    }

    ccBSTR  bstrText;
    lvc.mask |= LVCF_TEXT;
    if (!vText.IsOmitted()) {
        bstrText = vText;
        lvc.pszText = (BSTR)bstrText;
    } else {
        lvc.pszText = L"";
    }

    lvc.iSubItem = nCount;
    lvc.mask |= LVCF_SUBITEM;
    

    int nNewIndex = ListView_InsertColumn(m_pListView->m_ctlSysListView32.m_hWnd,nCount,&lvc);

    if (nNewIndex < 0) {
        return ReprotCOMErrorInfo(L"Failed to add column.",IID_INSColumnHeaders,L"ListView");
    }

    if (!m_arrColumnHeaders.Insert(spCH,nCount)) return E_OUTOFMEMORY;

    bstrText = vKey;
    if (!vKey.IsOmitted()) pch->m_bstrKey = bstrText;

    pch->m_pListView = m_pListView;
    pch->m_pColumnHeaders = this;

    NSINITIALIZE(spCH);

    *ppObj = (INSColumnHeader*)spCH;
    (*ppObj)->AddRef();

    // Update the columns
    for (int i = nCount + 1; i < m_arrColumnHeaders.GetSize();i++) {
        m_arrColumnHeaders[i]->put_SubItemIndex((long)i);
    }
    // Update the subitems
    m_pListView->_IncrementSubItemsWithIndexAndAbove(nCount);

	return S_OK;
}

STDMETHODIMP CNSColumnHeaders::get_ListView(INSListView **pVal) {
	if (!m_pListView) return E_UNEXPECTED;
	if (!pVal) return E_POINTER;
    return m_pListView->QueryInterface(IID_INSListView,(void**)pVal);
}
