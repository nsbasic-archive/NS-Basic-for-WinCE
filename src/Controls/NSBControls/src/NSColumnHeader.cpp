// NSColumnHeader.cpp : Implementation of CNSColumnHeader
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSColumnHeaders.h"
#include "NSColumnHeader.h"
#include "NSColumnItems.h"

/////////////////////////////////////////////////////////////////////////////
// CNSColumnHeader

STDMETHODIMP CNSColumnHeader::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSColumnHeader
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

int CNSColumnHeader::FindMyIndex() {
    if (m_pColumnHeaders) {
        int i;
        CComPtr<INSColumnHeader>    spCH;
        HRESULT hr = QueryInterface(IID_INSColumnHeader,(void**)&spCH);
        if (FAILED(hr)) return -1;
        for (i = 0; i < m_pColumnHeaders->m_arrColumnHeaders.GetSize(); i++) {
            if ((INSColumnHeader*)spCH == (INSColumnHeader*)m_pColumnHeaders->m_arrColumnHeaders[i]) {
                return i;
            }
        }
    }
    return -1;
}
long    CNSColumnHeader::GetMySubIndex() {
    if (!m_pListView) return -1;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return -1;

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_SUBITEM;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

    return (long)lvc.iSubItem;
}

HRESULT     CNSColumnHeader::FinalConstruct() {
    CComObject<CNSColumnItems>* p = NULL;
    HRESULT hr = CComObject<CNSColumnItems>::CreateInstance(&p);
    if (FAILED(hr)) return hr;
    hr = p->QueryInterface(IID_INSColumnItems,(void**)&m_spColumnItems);
    if (FAILED(hr)) {
        delete p;
        return hr;
    }
    p->m_pColumnHeader = this;
    
    return S_OK;
}
void        CNSColumnHeader::FinalRelease() {
    m_bstrKey.Empty();
}

// INSComCtlInt
STDMETHODIMP CNSColumnHeader::NSTerminate() {
    m_pListView = NULL;
    m_pColumnHeaders = NULL;
    return S_OK;
}
STDMETHODIMP CNSColumnHeader::NSInitialize() {
    return S_OK;
}

// INSColumnHeader
STDMETHODIMP CNSColumnHeader::get_Text(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    TCHAR       _l[2048];
    _l[0] = TEXT('\0');
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_TEXT;
    lvc.pszText = _l;
    lvc.cchTextMax = 2048;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;
    _l[2048 - 1] = TEXT('\0');

    ccBSTR bstr;
    bstr = _l;
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CNSColumnHeader::put_Text(BSTR newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    ccBSTR bstr;
    bstr = newVal;
    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_TEXT;
    lvc.pszText = (BSTR)bstr;
    if (!ListView_SetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Alignment(NSListColumnAlignment *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

    *pVal = (NSListColumnAlignment)(lvc.fmt & 0x3);

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_Alignment(NSListColumnAlignment newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;

    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

    lvc.mask = LVCF_FMT;
    lvc.fmt = (lvc.fmt & ~0x3) | (newVal & 0x3); //// **** ///////////////////
    if (!ListView_SetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Index(long *pVal) {
    if (!pVal) return E_POINTER;
	int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");
    *pVal = (long)nColumn;
	return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_Index(long newVal) {
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Key(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrKey.CopyTo(pVal);
}

STDMETHODIMP CNSColumnHeader::put_Key(BSTR newVal) {
	m_bstrKey = newVal;
	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_SubItemIndex(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_SUBITEM;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

    *pVal = (long)lvc.iSubItem;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_SubItemIndex(long newVal) {
	if (!m_pListView || !m_pColumnHeaders) return E_UNEXPECTED;
    long iSubItem = GetMySubIndex();
    if (newVal == iSubItem) return S_OK;

    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_SUBITEM;
    lvc.iSubItem = (int)newVal;
    if (!ListView_SetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    return m_vTag.CopyTo(pVal);
}

STDMETHODIMP CNSColumnHeader::put_Tag(VARIANT newVal) {
	m_vTag = newVal;
    return S_OK;
}
STDMETHODIMP CNSColumnHeader::putref_Tag(VARIANT newVal) {
	m_vTag = newVal;
    return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Icon(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_IMAGE;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;
    ccVariant   v;
    v = (long)lvc.iImage;

    return v.CopyTo(pVal);
}

STDMETHODIMP CNSColumnHeader::put_Icon(VARIANT newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    ccVariant   vImage;
    vImage = newVal;

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;
    int nFmt = lvc.fmt;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_IMAGE | LVCF_FMT;
    lvc.fmt = nFmt | LVCFMT_IMAGE;
    lvc.iImage = (int)m_pListView->_FindImageIndex(vImage,3);
    if (!ListView_SetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Position(long *pVal) {
    if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_ORDER;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;
    
    *pVal = lvc.iOrder;

    return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_Position(long newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_ORDER;
    lvc.iOrder = (int)newVal;
    if (!ListView_SetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_ListView(INSListView **pVal) {
    if (!m_pListView) return E_UNEXPECTED;
	if (!pVal) return E_POINTER;
    return m_pListView->QueryInterface(IID_INSListView,(void**)pVal);
}

STDMETHODIMP CNSColumnHeader::get_ColumnItems(INSColumnItems **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spColumnItems;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_SortType(NSListSortTypeConstants *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_SortType;
	return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_SortType(NSListSortTypeConstants newVal) {
	m_SortType = newVal;
	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_Width(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    *pVal = (long)ListView_GetColumnWidth(m_pListView->m_ctlSysListView32.m_hWnd,nColumn);
    return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_Width(long newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    if (!ListView_SetColumnWidth(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,(int)newVal)) return E_FAIL;
	return S_OK;
}

STDMETHODIMP CNSColumnHeader::get_ShowImage(VARIANT_BOOL *pVal) {
    if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;
    *pVal = (lvc.fmt & LVCFMT_IMAGE)?VARIANT_TRUE:VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CNSColumnHeader::put_ShowImage(VARIANT_BOOL newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int nColumn = FindMyIndex();
    if (nColumn < 0) return ReprotCOMErrorInfo(L"The column no longer exists.",IID_INSColumnHeader,L"ListView");

    LVCOLUMN    lvc;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT;
    if (!ListView_GetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;
    int nFmt = lvc.fmt;
    ZeroMemory(&lvc,sizeof(LVCOLUMN));
    lvc.mask = LVCF_FMT;
    if (newVal) {
        lvc.fmt = nFmt | LVCFMT_IMAGE;
    } else {
        lvc.fmt = nFmt & (~LVCFMT_IMAGE);
    }
    
    if (!ListView_SetColumn(m_pListView->m_ctlSysListView32.m_hWnd,nColumn,&lvc)) return E_FAIL;

	return S_OK;
}
