// NSListItem.cpp : Implementation of CNSListItem
#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSListItem.h"
#include "NSListSubItems.h"

/////////////////////////////////////////////////////////////////////////////
// CNSListItem

STDMETHODIMP CNSListItem::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSListItem
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

int CNSListItem::FindMyItem() {
    if (m_pListView) {
        CComPtr<INSListItem>    spItem;
        HRESULT hr = QueryInterface(IID_INSListItem,(void**)&spItem);
        if (FAILED(hr)) return - 1;

        LVFINDINFO lvfi;
        ZeroMemory(&lvfi,sizeof(LVFINDINFO));
        lvfi.flags = LVFI_PARAM;
        lvfi.lParam = (LPARAM)(INSListItem*)spItem;
        LONG iIndex = ListView_FindItem(m_pListView->m_ctlSysListView32.m_hWnd,-1,&lvfi);
        if (iIndex >= 0) {
            return iIndex;
        }
    }
    return -1;
}

HRESULT CNSListItem::FinalConstruct() {
    HRESULT hr = CComObject<CNSListSubItems>::CreateInstance(&m_pListSubItems);
    if (FAILED(hr)) return hr;

    hr = m_pListSubItems->QueryInterface(IID_INSListSubItems,(void**)&m_spListSubItems);
    if (FAILED(hr)) {
        delete m_pListSubItems;
        m_pListSubItems = NULL;
        return hr;
    }

    // INITIALIZATION IS REQUIRED
    return S_OK;
}
void    CNSListItem::FinalRelease() {
    NSTERMINATE(m_spListSubItems);
    m_spListSubItems.Release();
}



// INSComCtlInt
STDMETHODIMP    CNSListItem::NSTerminate() {
    m_pListView = NULL;
    NSTERMINATE(m_spListSubItems);
    return S_OK;
    //// **** ////
}
STDMETHODIMP    CNSListItem::NSInitialize() {
    if (m_pListSubItems) {
        m_pListSubItems->m_pListView = m_pListView;
        m_pListSubItems->m_pListItem = this;
        NSINITIALIZE(m_spListSubItems);
    }
    return S_OK;
}

STDMETHODIMP CNSListItem::get_Key(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrKey.CopyTo(pVal);
}

STDMETHODIMP CNSListItem::put_Key(BSTR newVal) {
	m_bstrKey = newVal;
	return S_OK;
}

STDMETHODIMP CNSListItem::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    return m_vTag.CopyTo(pVal);
}

STDMETHODIMP CNSListItem::put_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}
STDMETHODIMP CNSListItem::putref_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}

STDMETHODIMP CNSListItem::get_Text(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        LVITEM  lvi;
        ZeroMemory(&lvi,sizeof(LVITEM));
        lvi.mask = LVIF_TEXT;
        TCHAR   _l[2048];
        _l[0] = TEXT('\0');
        lvi.pszText = _l;
        lvi.cchTextMax = 2048;
        LRESULT lTextLen = SendMessage(m_pListView->m_ctlSysListView32.m_hWnd,LVM_GETITEMTEXT,(WPARAM)iIndex,(LPARAM)&lvi);
        ccBSTR  bstr;
        _l[2048-1] = TEXT('\0'); // Well, make sure nothing wrong would happen.
        if (lTextLen) bstr = lvi.pszText;
        return bstr.CopyTo(pVal);
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::put_Text(BSTR newVal) {
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        ccBSTR  bstr = newVal;
        ListView_SetItemText(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,0,bstr);
        return S_OK;
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::get_Selected(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        if (ListView_GetItemState(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,LVIS_SELECTED) & LVIS_SELECTED) {
            *pVal = VARIANT_TRUE;
            return S_OK;
        } else {
            *pVal = VARIANT_FALSE;
            return S_FALSE;
        }
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::put_Selected(VARIANT_BOOL newVal) {
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        if (newVal) {
            ListView_SetItemState(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,LVIS_SELECTED,LVIS_SELECTED);
        } else {
            ListView_SetItemState(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,0,LVIS_SELECTED);
        }
        return S_OK;
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::get_Indent(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        LVITEM  lvi;
        ZeroMemory(&lvi,sizeof(LVITEM));
        lvi.mask = LVIF_INDENT;
        lvi.iItem = iIndex;

        if (ListView_GetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi)) {
            *pVal = lvi.iIndent;
            return S_OK;
        } else {
            return E_FAIL;
        }
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::put_Indent(long newVal) {
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        LVITEM  lvi;
        ZeroMemory(&lvi,sizeof(LVITEM));
        lvi.mask = LVIF_INDENT;
        lvi.iItem = iIndex;
        lvi.iIndent = (int)newVal;

        if (ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi)) {
            return S_OK;
        } else {
            return E_FAIL;
        }
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::get_Icon(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    ccVariant   v;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        LVITEM  lvi;
        ZeroMemory(&lvi,sizeof(LVITEM));
        lvi.mask = LVIF_IMAGE;
        lvi.iItem = iIndex;

        if (ListView_GetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi)) {
            v = (long)(lvi.iImage + 1);
            return v.CopyTo(pVal);
        } else {
            return E_FAIL;
        }
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::put_Icon(VARIANT newVal) {
	int iIndex = FindMyItem();
    if (!m_pListView) return E_UNEXPECTED;
    if (iIndex >= 0) {
        LVITEM      lvi;
        ccVariant   v(newVal);
        ZeroMemory(&lvi,sizeof(LVITEM));
        lvi.mask = LVIF_IMAGE;
        lvi.iItem = iIndex;
        lvi.iImage = (int)m_pListView->_FindImageIndex(v,0);
        if (ListView_SetItem(m_pListView->m_ctlSysListView32.m_hWnd,&lvi)) {
            return S_OK;
        } else {
            return E_FAIL;
        }
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::get_SubItems(INSListSubItems **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spListSubItems;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListItem::get_Checked(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        if (NSLV_GetCheckState(m_pListView->m_ctlSysListView32.m_hWnd,iIndex)) {
            *pVal = VARIANT_TRUE;
            return S_OK;
        } else {
            *pVal = VARIANT_FALSE;
            return S_FALSE;
        }
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::put_Checked(VARIANT_BOOL newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        NSLV_SetCheckState(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,(BOOL)newVal);
        return S_OK;
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
}

STDMETHODIMP CNSListItem::get_ListView(INSListView **pVal) {
	if (!m_pListView) return E_UNEXPECTED;
	if (!pVal) return E_POINTER;
    return m_pListView->QueryInterface(IID_INSListView,(void**)pVal);
}

STDMETHODIMP CNSListItem::StartLabelEdit() {
	if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    m_pListView->m_ctlSysListView32.SetFocus();
    if (!ListView_EditLabel(m_pListView->m_ctlSysListView32.m_hWnd,iIndex)) {
        return ReprotCOMErrorInfo(L"Operation failed.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::EnsureVisible(VARIANT_BOOL bPartialOk) {
	if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    m_pListView->m_ctlSysListView32.SetFocus();
    if (!ListView_EnsureVisible(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,(BOOL)bPartialOk)) {
        return ReprotCOMErrorInfo(L"Operation failed.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::get_ListItem(INSListItem **pVal) {
	if (!pVal) return E_POINTER;
    return QueryInterface(IID_INSListItem,(void**)pVal);
}

STDMETHODIMP CNSListItem::get_IsSubItem(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = VARIANT_FALSE;
	return S_OK;
}


STDMETHODIMP CNSListItem::get_X(long *pVal) {
    if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        POINT pt;
        ListView_GetItemPosition(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,&pt);
        *pVal = (long)pt.x;
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::put_X(long newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        POINT pt;
        ListView_GetItemPosition(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,&pt);
        ListView_SetItemPosition(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,newVal,pt.y);
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::get_Y(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        POINT pt;
        ListView_GetItemPosition(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,&pt);
        *pVal = (long)pt.y;
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::put_Y(long newVal) {
	if (!m_pListView) return E_UNEXPECTED;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        POINT pt;
        ListView_GetItemPosition(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,&pt);
        ListView_SetItemPosition(m_pListView->m_ctlSysListView32.m_hWnd,iIndex,pt.x,newVal);
    } else {
        return ReprotCOMErrorInfo(L"The object no longer corresponds to an existing item.",IID_INSListItem,L"ListView");
    }
	return S_OK;
}

STDMETHODIMP CNSListItem::get_Index(long *pVal) {
	if (!pVal) return E_POINTER;
    int iIndex = FindMyItem();
    if (iIndex >= 0) {
        *pVal = (long)iIndex + 1;
        return S_OK;
    } else {
        return E_FAIL;
    }
}
