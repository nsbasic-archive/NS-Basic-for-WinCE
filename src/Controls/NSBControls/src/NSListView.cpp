// NSListView.cpp : Implementation of CNSListView

#include "stdafx.h"
#include "ComCtl.h"
#include "NSListView.h"
#include "NSColumnHeaders.h"
#include "NSListItems.h"
#include "NSBImageList.h"
#include "NSListViewEvent.h"
#include "NSFont.h"
#include "NSComCtlColl.h"
#ifdef _WIN32_WCE
    #pragma comment(lib, "commctrl.lib")
#else
    #pragma comment(lib, "comctl32.lib")
#endif

#ifdef _WIN32_WCE
    // #define _ERRORS_ON_CE
    // Uncomment the above to cause the properties not supported by CE to rise errors.
#endif 

#define GETEXSTYLEPROP(pVal,style) \
    if (!pVal) return E_POINTER; \
	DWORD dwExStyle = ListView_GetExtendedListViewStyle(m_ctlSysListView32.m_hWnd); \
    dwExStyle = dwExStyle & style; \
    if (dwExStyle) *pVal = VARIANT_TRUE; \
    else *pVal = VARIANT_FALSE; \
    return (*pVal)?VARIANT_TRUE:VARIANT_FALSE;

#define PUTEXSTYLEPROP(newVal,style) \
    DWORD dwExStyle = ListView_GetExtendedListViewStyle(m_ctlSysListView32.m_hWnd); \
    dwExStyle = dwExStyle & ~style; \
    ListView_SetExtendedListViewStyle(m_ctlSysListView32.m_hWnd,dwExStyle | (newVal?style:0)); \
	return S_OK;

/////////////////////////////////////////////////////////////////////////////
// CNSListView

/*
This code is currently not used, but may be some changes in future would make use of it
LRESULT CNSListView::OnGetDispInfo(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLVDISPINFO*   pdi = (NMLVDISPINFO*)pnmh;
    if (!pdi) return 0;

    // Here we dispatch whatever is requested
    if (pdi->item.iSubItem) {

    } else {

    }


    pdi->item.lParam;
    pdi->item.lParam;
    return 0;


}
*/

// Event handlers
VOID __stdcall  CNSListView::OnFontChange() {
    if (m_spFont) {
        HFONT   hFont = NULL;
        HRESULT hr = m_spFont->get_hFont((OLE_HANDLE*)&hFont);
        if (!FAILED(hr)) {
            m_ctlSysListView32.SetFont(hFont);
            if (m_hFont) ::DeleteObject(m_hFont);
            m_hFont = hFont;
            _FullRedraw();
        }
    }
}
VOID __stdcall  CNSListView::OnIconsChange() {
    _SetIconImageList();
}
VOID __stdcall  CNSListView::OnSmallIconsChange() {
    _SetSmallIconImageList();
}
VOID __stdcall  CNSListView::OnHeaderIconsChange() {
    _SetHeaderIconImageList();
}

// Windows messsage handlers
LRESULT CNSListView::_OnColumnClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 1;

    ccVariant   v;
    v = (long)pnm->iSubItem;
    HRESULT hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);
    if (FAILED(hr)) return 0;

    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnColumnClick(spEvent);

    return 0;
}
LRESULT CNSListView::_OnBeginLabelEdit(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLVDISPINFO* pnm = (NMLVDISPINFO*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 2;

    ccVariant   v;
    v = (long)pnm->item.iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)0;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);
    if (FAILED(hr)) return 0;

    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnBeginLabelEdit(spEvent);
    
    if (lve->m_bCancel) return (LRESULT)TRUE;
    return 0;
}
LRESULT CNSListView::_OnEndLabelEdit(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLVDISPINFO* pnm = (NMLVDISPINFO*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 3;

    ccVariant   v;
    v = (long)pnm->item.iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)0;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);
    if (FAILED(hr)) return 0;

    if (pnm->item.pszText) lve->m_bstrText = pnm->item.pszText;
    else lve->m_bstrText = L"";

    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnEndLabelEdit(spEvent);
    
    if (lve->m_bCancel) return (LRESULT)FALSE;
    return (LRESULT)TRUE;
}
LRESULT CNSListView::_OnItemActivate(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 4;

    ccVariant   v;
    v = (long)pnm->iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)pnm->iSubItem;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);

    CComPtr<INSListSubItems>    spSubItems;
    hr = lve->m_spItem->get_SubItems(&spSubItems);
    if (!FAILED(hr)) {
        spSubItems->get_Item(v,&lve->m_spSubItem);
    }
    
    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnItemActivate(spEvent);

    return 0;
}
LRESULT CNSListView::_OnKeyDown(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLVKEYDOWN* pnm = (NMLVKEYDOWN*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 5;
    lve->m_lKey = (long)(DWORD)pnm->wVKey;

    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnKeyDown(spEvent);

    return 0;
}
LRESULT CNSListView::_OnMarqueeBegin(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 6;

    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnMarqueeBegin(spEvent);

    if (lve->m_bCancel) return 1;

    return 0;
}
LRESULT CNSListView::_OnClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 7;

    ccVariant   v;
    v = (long)pnm->iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)pnm->iSubItem;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);

    CComPtr<INSListSubItems>    spSubItems;
    hr = lve->m_spItem->get_SubItems(&spSubItems);
    if (!FAILED(hr)) {
        spSubItems->get_Item(v,&lve->m_spSubItem);
    }
    
    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnClick(spEvent);

    return 0;
}
LRESULT CNSListView::_OnDblClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 8;

    ccVariant   v;
    v = (long)pnm->iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)pnm->iSubItem;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);

    CComPtr<INSListSubItems>    spSubItems;
    hr = lve->m_spItem->get_SubItems(&spSubItems);
    if (!FAILED(hr)) {
        spSubItems->get_Item(v,&lve->m_spSubItem);
    }
    
    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnDblClick(spEvent);

    return 0;
}
LRESULT CNSListView::_OnRClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 9;

    ccVariant   v;
    v = (long)pnm->iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)pnm->iSubItem;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);

    CComPtr<INSListSubItems>    spSubItems;
    hr = lve->m_spItem->get_SubItems(&spSubItems);
    if (!FAILED(hr)) {
        spSubItems->get_Item(v,&lve->m_spSubItem);
    }
    
    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnRClick(spEvent);

    return 0;
}
LRESULT CNSListView::_OnRDblClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 10;

    ccVariant   v;
    v = (long)pnm->iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)pnm->iSubItem;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);

    CComPtr<INSListSubItems>    spSubItems;
    hr = lve->m_spItem->get_SubItems(&spSubItems);
    if (!FAILED(hr)) {
        spSubItems->get_Item(v,&lve->m_spSubItem);
    }
    
    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnRDblClick(spEvent);

    return 0;
}
LRESULT CNSListView::_OnReturn(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 11;

    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnReturn(spEvent);
    
    return 0;
}
LRESULT CNSListView::_OnItemChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled) {
    NMLISTVIEW* pnm = (NMLISTVIEW*)pnmh;
    if (!pnm) return 0;

    CComPtr<INSListViewEvent>   spEvent;
    CNSListViewEvent* lve = CNSListViewEvent::CreateListEvent(&spEvent);
    if (!lve) return 0;
    lve->m_lEvent = 12;

    ccVariant   v;
    v = (long)pnm->iItem + 1;
    HRESULT hr = m_pListItems->get_Item(v,&lve->m_spItem);
    if (FAILED(hr)) return 0;

    v = (long)pnm->iSubItem;
    hr = m_pColumnHeaders->get_Item(v,&lve->m_spColumn);

    CComPtr<INSListSubItems>    spSubItems;
    hr = lve->m_spItem->get_SubItems(&spSubItems);
    if (!FAILED(hr)) {
        spSubItems->get_Item(v,&lve->m_spSubItem);
    }
    
    QueryInterface(IID_INSListView,(void**)&lve->m_spListView);

    Fire_OnItemChanged(spEvent);

    return 0;
}


HRESULT CNSListView::_RemoveSubItemsWithIndex(long lSubItem) {
    if (lSubItem < 1) return S_OK;
    if (!m_pListItems) return E_UNEXPECTED;
    int i;
    HRESULT hr;
    CComPtr<INSListSubItems>    spSubItems;
    CComPtr<INSListSubItemsInt> spSubItemsInt;

    for (i = 0; i < m_pListItems->m_arrListItems.GetSize(); i++) {
        if (!m_pListItems->m_arrListItems[i]) continue; // Next item
        spSubItems.Release();

        hr = m_pListItems->m_arrListItems[i]->get_SubItems(&spSubItems);
        if (FAILED(hr)) continue; // Next item

        spSubItemsInt.Release();
        hr = spSubItems->QueryInterface(IID_INSListSubItemsInt,(void**)&spSubItemsInt);
        if (FAILED(hr)) continue;

        hr = spSubItemsInt->ColumnRemoveUpdate(lSubItem);
        if (FAILED(hr)) continue;

    }
    return S_OK;
}
HRESULT CNSListView::_IncrementSubItemsWithIndexAndAbove(long lSubItem) {
    if (lSubItem < 1) return S_OK;
    if (!m_pListItems) return E_UNEXPECTED;
    int i;
    HRESULT hr;
    CComPtr<INSListSubItems>    spSubItems;
    CComPtr<INSListSubItemsInt> spSubItemsInt;

    for (i = 0; i < m_pListItems->m_arrListItems.GetSize(); i++) {
        if (!m_pListItems->m_arrListItems[i]) continue; // Next item
        spSubItems.Release();

        hr = m_pListItems->m_arrListItems[i]->get_SubItems(&spSubItems);
        if (FAILED(hr)) continue; // Next item

        spSubItemsInt.Release();
        hr = spSubItems->QueryInterface(IID_INSListSubItemsInt,(void**)&spSubItemsInt);
        if (FAILED(hr)) continue;

        hr = spSubItemsInt->ColumnInsertUpdate(lSubItem);
        if (FAILED(hr)) continue;

    }
    return S_OK;
}
HRESULT CNSListView::_RemoveAllSubItems() {
    if (!m_pListItems) return E_UNEXPECTED;
    int i;
    HRESULT hr;
    CComPtr<INSListSubItems>    spSubItems;
    CComPtr<INSListSubItemsInt> spSubItemsInt;

    for (i = 0; i < m_pListItems->m_arrListItems.GetSize(); i++) {
        if (!m_pListItems->m_arrListItems[i]) continue; // Next item
        spSubItems.Release();

        hr = m_pListItems->m_arrListItems[i]->get_SubItems(&spSubItems);
        if (FAILED(hr)) continue; // Next item

        spSubItemsInt.Release();
        hr = spSubItems->QueryInterface(IID_INSListSubItemsInt,(void**)&spSubItemsInt);
        if (FAILED(hr)) continue;

        hr = spSubItemsInt->ColumnsClear();
        if (FAILED(hr)) continue;

    }
    return S_OK;
}
long    CNSListView::_FindImageIndex(VARIANT Index,int nList) {
    ccVariant vIndex = Index;
    vIndex.ToValue();
    HRESULT hr;
    if (vIndex.IsNumeric()) {
        return ((long)vIndex - 1);
    } else {
        long lIndex = 0;
        if (!nList) {
            if (m_spIcons) {
                hr = m_spIcons->get_ImageIndex(Index,&lIndex);
                if (!FAILED(hr) && lIndex > 0) return lIndex - 1;
            }
            if (m_spSmallIcons) {
                hr = m_spSmallIcons->get_ImageIndex(Index,&lIndex);
                if (!FAILED(hr) && lIndex > 0) return lIndex - 1;
            }
        } else if (nList == 1) {
            if (m_spIcons) {
                hr = m_spIcons->get_ImageIndex(Index,&lIndex);
                if (!FAILED(hr) && lIndex > 0) return lIndex - 1;
            }
        } else if (nList == 2) {
            if (m_spSmallIcons) {
                hr = m_spSmallIcons->get_ImageIndex(Index,&lIndex);
                if (!FAILED(hr) && lIndex > 0) return lIndex - 1;
            }
        } else if (nList == 3) {
            if (m_spHeaderIcons) {
                hr = m_spHeaderIcons->get_ImageIndex(Index,&lIndex);
                if (!FAILED(hr) && lIndex > 0) return lIndex - 1;
            }
        }
        return lIndex - 1;
    }
}
void    CNSListView::_FullRedraw() {
    m_ctlSysListView32.InvalidateRect(NULL);
    HWND hwndHeader = ListView_GetHeader(m_ctlSysListView32.m_hWnd);
    ::InvalidateRect(hwndHeader,NULL,TRUE);
}
void    CNSListView::_ReSort() {
    if (m_bSorted) {
        if (m_lSortKey < 0) {
            DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
            if (m_SortOrder == lvwDescending) {
                m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~(LVS_SORTDESCENDING|LVS_SORTASCENDING)) | LVS_SORTDESCENDING); 
            } else {
                m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~(LVS_SORTDESCENDING|LVS_SORTASCENDING)) | LVS_SORTASCENDING); 
            }
        } else {
            ListView_SortItems(m_ctlSysListView32.m_hWnd,CompareItemsProc,(LPARAM)this);
        }
    }
}

LRESULT CNSListView::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/) {
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
		InitCommonControls();
        m_ctlSysListView32.Create(m_hWnd, rc);
        DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
        m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle | LVS_SHAREIMAGELISTS)); 
        dwStyle = m_ctlSysListView32.GetWindowLong(GWL_EXSTYLE);
        m_ctlSysListView32.SetWindowLong(GWL_EXSTYLE, (dwStyle | WS_EX_CLIENTEDGE)); 

        //dwStyle = GetWindowLong(GWL_STYLE);
        //SetWindowLong(GWL_EXSTYLE, (dwStyle | WS_EX_CLIENTEDGE)); 
        
        _SetIconImageList();
        _SetSmallIconImageList();
        _SetHeaderIconImageList();

        // Create the initial row
        m_pColumnHeaders->AddInitialColumn();

        HRESULT hr;
        if (m_spFont) {
            hr = ((IDispEventSimpleImpl<0,CNSListView,&DIID__INSFontEvents>*)this)->DispEventAdvise((IUnknown*)(INSFont*)m_spFont,&DIID__INSFontEvents);
        }
        if (m_spIcons) {
            hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventAdvise((IUnknown*)(INSBImageList*)m_spIcons,&DIID__INSBImageListEvents);
        }
        if (m_spSmallIcons) {
            hr = ((IDispEventSimpleImpl<2,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventAdvise((IUnknown*)(INSBImageList*)m_spSmallIcons,&DIID__INSBImageListEvents);
        }
        if (m_spHeaderIcons) {
            hr = ((IDispEventSimpleImpl<3,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventAdvise((IUnknown*)(INSBImageList*)m_spHeaderIcons,&DIID__INSBImageListEvents);
        }

		return 0;
}
LRESULT CNSListView::OnDestroy(UINT,WPARAM,LPARAM,BOOL&) {
    HRESULT hr;
    if (m_spFont) {
        hr = ((IDispEventSimpleImpl<0,CNSListView,&DIID__INSFontEvents>*)this)->DispEventUnadvise((IUnknown*)(INSFont*)m_spFont,&DIID__INSFontEvents);
    }
    if (m_spIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventUnadvise((IUnknown*)(INSBImageList*)m_spIcons,&DIID__INSBImageListEvents);
    }
    if (m_spSmallIcons) {
        hr = ((IDispEventSimpleImpl<2,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventUnadvise((IUnknown*)(INSBImageList*)m_spSmallIcons,&DIID__INSBImageListEvents);
    }
    if (m_spHeaderIcons) {
        hr = ((IDispEventSimpleImpl<3,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventUnadvise((IUnknown*)(INSBImageList*)m_spHeaderIcons,&DIID__INSBImageListEvents);
    }
    return 0;
}



HRESULT CNSListView::_SetIconImageList() {
    if (!m_spIcons) {
        ListView_SetImageList(m_ctlSysListView32.m_hWnd,NULL,LVSIL_NORMAL);
        return S_FALSE;
    }
    HIMAGELIST  hil = NULL;
    HRESULT hr = m_spIcons->get_hImageList((OLE_HANDLE*)&hil);
    if (FAILED(hr)) return E_FAIL;
    ListView_SetImageList(m_ctlSysListView32.m_hWnd,hil,LVSIL_NORMAL);
    return S_OK;
}
HRESULT CNSListView::_SetSmallIconImageList() {
    if (!m_spSmallIcons) {
        ListView_SetImageList(m_ctlSysListView32.m_hWnd,NULL,LVSIL_SMALL);
        return S_FALSE;
    }
    HIMAGELIST  hil = NULL;
    HRESULT hr = m_spSmallIcons->get_hImageList((OLE_HANDLE*)&hil);
    if (FAILED(hr)) return E_FAIL;
    ListView_SetImageList(m_ctlSysListView32.m_hWnd,hil,LVSIL_SMALL);
    return S_OK;
}
HRESULT CNSListView::_SetHeaderIconImageList() {
    HWND hwndHeader = ListView_GetHeader(m_ctlSysListView32.m_hWnd);
    if (hwndHeader) {
        if (!m_spHeaderIcons) {
            Header_SetImageList(hwndHeader,NULL);
            return S_FALSE;
        }
        HIMAGELIST  hil = NULL;
        HRESULT hr = m_spHeaderIcons->get_hImageList((OLE_HANDLE*)&hil);
        if (FAILED(hr)) return E_FAIL;
        Header_SetImageList(hwndHeader,hil);
    }
    return S_OK;
}


HRESULT     CNSListView::FinalConstruct() {
    HRESULT hr = CComObject<CNSColumnHeaders>::CreateInstance(&m_pColumnHeaders);
    if (FAILED(hr)) return hr;

    hr = m_pColumnHeaders->QueryInterface(IID_INSColumnHeaders,(void**)&m_spColumnHeaders);
    if (FAILED(hr)) {
        delete m_pColumnHeaders;
        return hr;
    }
    m_pColumnHeaders->m_pListView = this;

    hr = CComObject<CNSListItems>::CreateInstance(&m_pListItems);
    if (FAILED(hr)) return hr;

    hr = m_pListItems->QueryInterface(IID_INSListItems,(void**)&m_spListItems);
    if (FAILED(hr)) {
        delete m_pListItems;
        return hr;
    }
    m_pListItems->m_pListView = this;

    // Create empty Image lists for the small icons and Icons

    hr = CNSBImageList::CreateNSBImageList(32,32,IID_INSBImageList,(void**)&m_spIcons);
    if (FAILED(hr)) return hr;

    hr = CNSBImageList::CreateNSBImageList(16,16,IID_INSBImageList,(void**)&m_spSmallIcons);
    if (FAILED(hr)) return hr;

    hr = CNSBImageList::CreateNSBImageList(16,16,IID_INSBImageList,(void**)&m_spHeaderIcons);
    if (FAILED(hr)) return hr;

    hr = CNSFont::CreateNSFont(&m_spFont);
    if (FAILED(hr)) return hr;

    return S_OK;
}
void        CNSListView::FinalRelease() {
    NSTERMINATE(m_spColumnHeaders);
    NSTERMINATE(m_spListItems);

    m_spColumnHeaders.Release();
    m_spListItems.Release();
    m_spIcons.Release();
    m_spSmallIcons.Release();

    if (m_hFont) ::DeleteObject(m_hFont);
}

STDMETHODIMP CNSListView::get_ColumnHeaders(INSColumnHeaders **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spColumnHeaders;
    (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListView::get_View(NSListViewConstants *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    *pVal = (NSListViewConstants)(dwStyle & LVS_TYPEMASK);
	return S_OK;
}

STDMETHODIMP CNSListView::put_View(NSListViewConstants newVal) {
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    DWORD   dwView = (DWORD)newVal;

    if ((dwStyle & LVS_TYPEMASK) != dwView) { 
        m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~LVS_TYPEMASK) | dwView); 
    } 
	return S_OK;
}

STDMETHODIMP CNSListView::get_ListItems(INSListItems **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spListItems;
    (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListView::get_HideSelection(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    *pVal = (dwStyle & LVS_SHOWSELALWAYS)?VARIANT_FALSE:VARIANT_TRUE;
	return (*pVal)?VARIANT_TRUE:VARIANT_FALSE;
}

STDMETHODIMP CNSListView::put_HideSelection(VARIANT_BOOL newVal) {
	DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~LVS_SHOWSELALWAYS) | ((newVal)?0:LVS_SHOWSELALWAYS)); 
	return S_OK;
}

STDMETHODIMP CNSListView::get_MultiSelect(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    *pVal = (dwStyle & LVS_SINGLESEL)?VARIANT_FALSE:VARIANT_TRUE;
    return (*pVal)?VARIANT_TRUE:VARIANT_FALSE;
}

STDMETHODIMP CNSListView::put_MultiSelect(VARIANT_BOOL newVal) {
	DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~LVS_SINGLESEL) | ((newVal)?0:LVS_SINGLESEL)); 
	return S_OK;
}

STDMETHODIMP CNSListView::get_SortOrder(NSListSortOrderConstants *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_SortOrder;
	return S_OK;
}

STDMETHODIMP CNSListView::put_SortOrder(NSListSortOrderConstants newVal) {
    m_SortOrder = newVal;
    _ReSort();
	return S_OK;
}

STDMETHODIMP CNSListView::get_Arrange(NSListArrangeConstants *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);

    switch (dwStyle & (LVS_ALIGNLEFT | LVS_ALIGNTOP | LVS_AUTOARRANGE)) {
        case (LVS_ALIGNLEFT | LVS_AUTOARRANGE):
            *pVal = lvwAutoLeft;
        break;
        case (LVS_ALIGNTOP | LVS_AUTOARRANGE):
            *pVal = lvwAutoTop;
        break;
        default:
            *pVal = lvwNone;
    }
	return S_OK;
}

STDMETHODIMP CNSListView::put_Arrange(NSListArrangeConstants newVal) {
	DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    dwStyle = dwStyle & ~(LVS_ALIGNLEFT | LVS_ALIGNTOP | LVS_AUTOARRANGE);

    switch (newVal) {
        case lvwAutoLeft:
            m_ctlSysListView32.SetWindowLong(GWL_STYLE, dwStyle | LVS_ALIGNLEFT | LVS_AUTOARRANGE); 
        break;
        case lvwAutoTop:
            m_ctlSysListView32.SetWindowLong(GWL_STYLE, dwStyle | LVS_ALIGNTOP | LVS_AUTOARRANGE); 
        break;
        default:
            m_ctlSysListView32.SetWindowLong(GWL_STYLE, dwStyle); 

    }
	return S_OK;
}

STDMETHODIMP CNSListView::get_HideColumnHeaders(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    if (dwStyle & LVS_NOCOLUMNHEADER) {
        *pVal = VARIANT_TRUE;
        return S_OK;
    } else {
        *pVal = VARIANT_FALSE;
        return S_FALSE;
    }
}

STDMETHODIMP CNSListView::put_HideColumnHeaders(VARIANT_BOOL newVal) {
	DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~(LVS_NOCOLUMNHEADER)) | ((newVal)?LVS_NOCOLUMNHEADER:0)); 
	return S_OK;
}

STDMETHODIMP CNSListView::get_LabelEdit(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    *pVal = (dwStyle & LVS_EDITLABELS)?VARIANT_TRUE:VARIANT_FALSE;
	return (*pVal)?VARIANT_TRUE:VARIANT_FALSE;
}

STDMETHODIMP CNSListView::put_LabelEdit(VARIANT_BOOL newVal) {
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~LVS_EDITLABELS) | ((newVal)?LVS_EDITLABELS:0)); 
	return S_OK;
}

STDMETHODIMP CNSListView::get_LabelWrap(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    *pVal = (dwStyle & LVS_NOLABELWRAP)?VARIANT_FALSE:VARIANT_TRUE;
	return (*pVal)?VARIANT_TRUE:VARIANT_FALSE;
}

STDMETHODIMP CNSListView::put_LabelWrap(VARIANT_BOOL newVal) {
	DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~LVS_NOLABELWRAP) | ((newVal)?0:LVS_NOLABELWRAP)); 
	return S_OK;
}

// static 
int CALLBACK CNSListView::CompareItemsProc(LPARAM lp1,LPARAM lp2,LPARAM lp) {
    CNSListView*    pThis = (CNSListView*)lp;
    if (!lp) return 0; // All are equivalent in this case

    int LS = -1,GT = 1;
    if (pThis->m_SortOrder == lvwDescending) {
        LS = 1;
        GT = -1;
    }

    CComPtr<INSListItem>    spItem1;
    CComPtr<INSListItem>    spItem2;

    spItem1 = (INSListItem*)lp1;
    spItem2 = (INSListItem*)lp2;

    if (!spItem1) return LS;
    if (!spItem2) return GT;

    ccBSTR      bstr1,bstr2;
    ccVariant   v1,v2;
    HRESULT hr;

    NSListSortTypeConstants SortType = lvwTextSort;

    // Get the SortType
    if (pThis->m_lSortKey < pThis->m_pColumnHeaders->m_arrColumnHeaders.GetSize() &&
        pThis->m_lSortKey >= 0) {

        CComPtr<INSColumnHeader>    spColumn;
        spColumn = pThis->m_pColumnHeaders->m_arrColumnHeaders[(int)pThis->m_lSortKey];
        if (spColumn) {
            spColumn->get_SortType(&SortType);
        }
    }

    if (pThis->m_lSortKey < 1) {
        if ((int)SortType > 1) {
            // Get from the Item
            v1.Clear();
            v2.Clear();
            spItem1->get_Tag(&v1);
            spItem2->get_Tag(&v2);
            bstr1 = v1;
            bstr2 = v2;
        } else {
            // Get from the Item
            spItem1->get_Text(&bstr1);
            spItem2->get_Text(&bstr2);
        }
    } else {
        // Get from the subitem
        CComPtr<INSListSubItems>    spSubs1;
        CComPtr<INSListSubItems>    spSubs2;

        hr = spItem1->get_SubItems(&spSubs1);
        if (FAILED(hr)) return LS;
        hr = spItem2->get_SubItems(&spSubs2);
        if (FAILED(hr)) return GT;

        CComPtr<INSListSubItem>     spSub1;
        CComPtr<INSListSubItem>     spSub2;

        ccVariant vIndex;
        vIndex = pThis->m_lSortKey;

        HRESULT hr1 = spSubs1->get_ItemIfExists(vIndex,&spSub1);
        HRESULT hr2 = spSubs2->get_ItemIfExists(vIndex,&spSub2);
        if (FAILED(hr1) && FAILED(hr2)) return 0;
        if (FAILED(hr1)) return LS;
        if (FAILED(hr2)) return GT;

        if ((int)SortType > 1) {
            v1.Clear();
            v2.Clear();
            spSub1->get_Tag(&v1);
            spSub2->get_Tag(&v2);
            bstr1 = v1;
            bstr2 = v2;
        } else {
            spSub1->get_Text(&bstr1);
            spSub2->get_Text(&bstr2);
        }
    }

    if (!bstr1 && !bstr2) return 0;
    if (!bstr1) return LS;
    if (!bstr2) return GT;

    if (!bstr1.Length() && !bstr2.Length()) return 0;
    if (!bstr1.Length()) return LS;
    if (!bstr2.Length()) return GT;

    int n;
    
    if (((int)SortType % 2) == 0) {
        // And now comparison is needed
        n = wcscmp(bstr1,bstr2);
        if (n < 0) return LS;
        if (n > 0) return GT;
        return 0;
    } else {
        ccVariant v1,v2;
        v1 = bstr1;
        v2 = bstr2;
        HRESULT hr1 = v1.ChangeType(VT_R8);
        HRESULT hr2 = v2.ChangeType(VT_R8);

        if (FAILED(hr1) && FAILED(hr2)) {
            // String comparison
            n = wcscmp(bstr1,bstr2);
            if (n < 0) {
                return LS;
            } else if (n > 0) {
                return GT;
            } else {
                return 0;
            }
        }
        if (FAILED(hr1)) return LS;
        if (FAILED(hr2)) return GT;

        if (v1.dblVal < v2.dblVal) return LS;
        else if (v1.dblVal > v2.dblVal) return GT;
        else return 0;
    }
}

STDMETHODIMP CNSListView::get_Sorted(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bSorted;
    return S_OK;
}

STDMETHODIMP CNSListView::put_Sorted(VARIANT_BOOL newVal) {
    m_bSorted = newVal;
    _ReSort();
    return S_OK;	
}

STDMETHODIMP CNSListView::get_Checkboxes(VARIANT_BOOL *pVal) {
    GETEXSTYLEPROP(pVal,LVS_EX_CHECKBOXES)
}
STDMETHODIMP CNSListView::put_Checkboxes(VARIANT_BOOL newVal) {
    PUTEXSTYLEPROP(newVal,LVS_EX_CHECKBOXES);
    FireViewChange();
    _FullRedraw();
}

STDMETHODIMP CNSListView::get_FullRowSelect(VARIANT_BOOL *pVal) {
    GETEXSTYLEPROP(pVal,LVS_EX_FULLROWSELECT)
}
STDMETHODIMP CNSListView::put_FullRowSelect(VARIANT_BOOL newVal) {
    PUTEXSTYLEPROP(newVal,LVS_EX_FULLROWSELECT);
    FireViewChange();
    _FullRedraw();
}

STDMETHODIMP CNSListView::get_GridLines(VARIANT_BOOL *pVal) {
    GETEXSTYLEPROP(pVal,LVS_EX_GRIDLINES)
}
STDMETHODIMP CNSListView::put_GridLines(VARIANT_BOOL newVal) {
    PUTEXSTYLEPROP(newVal,LVS_EX_GRIDLINES);
    FireViewChange();
    _FullRedraw();
}

STDMETHODIMP CNSListView::get_AllowColumnReorder(VARIANT_BOOL *pVal) {
    GETEXSTYLEPROP(pVal,LVS_EX_HEADERDRAGDROP)
}
STDMETHODIMP CNSListView::put_AllowColumnReorder(VARIANT_BOOL newVal) {
    PUTEXSTYLEPROP(newVal,LVS_EX_HEADERDRAGDROP);
    FireViewChange();
    _FullRedraw();
}

STDMETHODIMP CNSListView::get_SubItemImages(VARIANT_BOOL *pVal) {
	GETEXSTYLEPROP(pVal,LVS_EX_SUBITEMIMAGES)
}
STDMETHODIMP CNSListView::put_SubItemImages(VARIANT_BOOL newVal) {
	PUTEXSTYLEPROP(newVal,LVS_EX_SUBITEMIMAGES);
    FireViewChange();
    _FullRedraw();
}

STDMETHODIMP CNSListView::get_TrackSelect(VARIANT_BOOL *pVal) {
	GETEXSTYLEPROP(pVal,LVS_EX_TRACKSELECT)
}
STDMETHODIMP CNSListView::put_TrackSelect(VARIANT_BOOL newVal) {
	PUTEXSTYLEPROP(newVal,LVS_EX_TRACKSELECT);
    FireViewChange();
    _FullRedraw();
}

STDMETHODIMP CNSListView::get_UnderlineCold(VARIANT_BOOL *pVal) {
    #ifdef _WIN32_WCE
        return S_OK;
        // return ReprotCOMErrorInfo(L"Not supported under CE.",IID_INSListView,L"ListView");
    #else
	    GETEXSTYLEPROP(pVal,LVS_EX_UNDERLINECOLD)
    #endif
}
STDMETHODIMP CNSListView::put_UnderlineCold(VARIANT_BOOL newVal) {
    #ifdef _WIN32_WCE
        return S_OK;
        // return ReprotCOMErrorInfo(L"Not supported under CE.",IID_INSListView,L"ListView");
    #else
	    PUTEXSTYLEPROP(newVal,LVS_EX_UNDERLINECOLD);
        FireViewChange();
        _FullRedraw();
    #endif
}

STDMETHODIMP CNSListView::get_UnderlineHot(VARIANT_BOOL *pVal) {
    #ifdef _WIN32_WCE
        return S_OK;
        // return ReprotCOMErrorInfo(L"Not supported under CE.",IID_INSListView,L"ListView");
    #else
	    GETEXSTYLEPROP(pVal,LVS_EX_UNDERLINEHOT)
    #endif
}
STDMETHODIMP CNSListView::put_UnderlineHot(VARIANT_BOOL newVal) {
    #ifdef _WIN32_WCE
        return S_OK;
        // return ReprotCOMErrorInfo(L"Not supported under CE.",IID_INSListView,L"ListView");
    #else
	    PUTEXSTYLEPROP(newVal,LVS_EX_UNDERLINEHOT);
        FireViewChange();
        _FullRedraw();
    #endif
}

STDMETHODIMP CNSListView::get_SmallIcons(INSBImageList **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_spSmallIcons) return E_FAIL;
    return m_spSmallIcons->QueryInterface(IID_INSBImageList,(void**)pVal);
}

STDMETHODIMP CNSListView::putref_SmallIcons(INSBImageList *newVal) {
    HRESULT hr;
    if (m_spSmallIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventUnadvise((IUnknown*)(INSBImageList*)m_spSmallIcons,&DIID__INSBImageListEvents);
    }
    m_spSmallIcons.Release();
    _SetSmallIconImageList();
    if (!newVal) {
        hr = CNSBImageList::CreateNSBImageList(16,16,IID_INSBImageList,(void**)&m_spSmallIcons);
        if (FAILED(hr)) return hr;
    } else {
        hr = newVal->QueryInterface(IID_INSBImageList,(void**)&m_spSmallIcons);
        if (FAILED(hr)) return hr;
    }
    if (m_spSmallIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventAdvise((IUnknown*)(INSBImageList*)m_spSmallIcons,&DIID__INSBImageListEvents);
    }
    return _SetSmallIconImageList();
}

STDMETHODIMP CNSListView::get_Icons(INSBImageList **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_spIcons) return E_FAIL;
    return m_spIcons->QueryInterface(IID_INSBImageList,(void**)pVal);
}

STDMETHODIMP CNSListView::putref_Icons(INSBImageList *newVal) {
	HRESULT hr;
    if (m_spIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventUnadvise((IUnknown*)(INSBImageList*)m_spIcons,&DIID__INSBImageListEvents);
    }
    m_spIcons.Release();
    _SetIconImageList();
    if (!newVal) {
        hr = CNSBImageList::CreateNSBImageList(32,32,IID_INSBImageList,(void**)&m_spIcons);
        if (FAILED(hr)) return hr;
    } else {
        hr = newVal->QueryInterface(IID_INSBImageList,(void**)&m_spIcons);
        if (FAILED(hr)) return hr;
    }
    if (m_spIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventAdvise((IUnknown*)(INSBImageList*)m_spIcons,&DIID__INSBImageListEvents);
    }
    return _SetIconImageList();
}

STDMETHODIMP CNSListView::UpdateIcons() {
	_SetIconImageList();
    _SetSmallIconImageList();
	return S_OK;
}

STDMETHODIMP CNSListView::get_SortHeaders(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    *pVal = (dwStyle & LVS_NOSORTHEADER)?VARIANT_FALSE:VARIANT_TRUE;
	return (*pVal)?VARIANT_TRUE:VARIANT_FALSE;
}

STDMETHODIMP CNSListView::put_SortHeaders(VARIANT_BOOL newVal) {
	DWORD   dwStyle = m_ctlSysListView32.GetWindowLong(GWL_STYLE);
    m_ctlSysListView32.SetWindowLong(GWL_STYLE, (dwStyle & ~LVS_NOSORTHEADER) | ((newVal)?0:LVS_NOSORTHEADER)); 
    FireViewChange();
    _FullRedraw();
	return S_OK;
}

STDMETHODIMP CNSListView::get_SortKey(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lSortKey;
	return S_OK;
}

STDMETHODIMP CNSListView::put_SortKey(long newVal) {
	m_lSortKey = newVal;
    _ReSort();
	return S_OK;
}

STDMETHODIMP CNSListView::get_CustomSort(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bCustomSort;
	return S_OK;
}

STDMETHODIMP CNSListView::put_CustomSort(VARIANT_BOOL newVal) {
	m_bCustomSort = newVal;
	return S_OK;
}

STDMETHODIMP CNSListView::get_ColumnHeaderIcons(INSBImageList **pVal) {
	if (!pVal) return E_POINTER;
    if (!m_spHeaderIcons) return E_FAIL;
    return m_spHeaderIcons->QueryInterface(IID_INSBImageList,(void**)pVal);
}

STDMETHODIMP CNSListView::putref_ColumnHeaderIcons(INSBImageList *newVal) {
	HRESULT hr;
    if (m_spHeaderIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventUnadvise((IUnknown*)(INSBImageList*)m_spHeaderIcons,&DIID__INSBImageListEvents);
    }
    m_spHeaderIcons.Release();
    _SetHeaderIconImageList();
    if (!newVal) {
        hr = CNSBImageList::CreateNSBImageList(16,16,IID_INSBImageList,(void**)&m_spHeaderIcons);
        if (FAILED(hr)) return hr;
    } else {
        hr = newVal->QueryInterface(IID_INSBImageList,(void**)&m_spHeaderIcons);
        if (FAILED(hr)) return hr;
    }
    if (m_spHeaderIcons) {
        hr = ((IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>*)this)->DispEventAdvise((IUnknown*)(INSBImageList*)m_spHeaderIcons,&DIID__INSBImageListEvents);
    }
    return _SetHeaderIconImageList();
}

STDMETHODIMP CNSListView::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    return m_vTag.CopyTo(pVal);
}

STDMETHODIMP CNSListView::put_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}
STDMETHODIMP CNSListView::putref_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}

STDMETHODIMP CNSListView::get_BackColor(OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ListView_GetBkColor(m_ctlSysListView32.m_hWnd);
	return S_OK;
}

STDMETHODIMP CNSListView::put_BackColor(OLE_COLOR newVal) {
	ListView_SetBkColor(m_ctlSysListView32.m_hWnd,(COLORREF)newVal);
    FireViewChange();
    _FullRedraw();
	return S_OK;
}

STDMETHODIMP CNSListView::get_TextBackColor(OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ListView_GetTextBkColor(m_ctlSysListView32.m_hWnd);
	return S_OK;
}

STDMETHODIMP CNSListView::put_TextBackColor(OLE_COLOR newVal) {
	ListView_SetTextBkColor(m_ctlSysListView32.m_hWnd,(COLORREF)newVal);
    FireViewChange();
    _FullRedraw();
	return S_OK;
}

STDMETHODIMP CNSListView::get_TextColor(OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ListView_GetTextColor(m_ctlSysListView32.m_hWnd);
	return S_OK;
}

STDMETHODIMP CNSListView::put_TextColor(OLE_COLOR newVal) {
	ListView_SetTextColor(m_ctlSysListView32.m_hWnd,(COLORREF)newVal);
    FireViewChange();
    _FullRedraw();
	return S_OK;
}

STDMETHODIMP CNSListView::get_Font(INSFont **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spFont;
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListView::putref_Font(INSFont *newVal) {
    HRESULT hr;
    if (m_spFont) {
        hr = ((IDispEventSimpleImpl<0,CNSListView,&DIID__INSFontEvents>*)this)->DispEventUnadvise((IUnknown*)(INSFont*)m_spFont,&DIID__INSFontEvents);
    }
	m_spFont = newVal;
    if (m_spFont) {
        hr = ((IDispEventSimpleImpl<0,CNSListView,&DIID__INSFontEvents>*)this)->DispEventAdvise((IUnknown*)(INSFont*)m_spFont,&DIID__INSFontEvents);
    }
    OnFontChange();
	return S_OK;
}


BOOL    CNSListView::_CompareItem(BSTR bstr,IDispatch* pItem,VARIANT_BOOL bTags,int nPartial) {
    DISPCALLER  dc;
    dc = pItem;
    ccVariant   v;
    HRESULT     hr;
    if (dc.IsValid()) {
        if (bTags) {
            v <= dc.GetProperty(TEXT("Tag"));
        } else {
            v <= dc.GetProperty(TEXT("Text"));
        }
        if (v.vt != VT_ERROR) {
            hr = v.ChangeType(VT_BSTR);
            if (FAILED(hr)) return FALSE;
            if (v.bstrVal) {
                ::CharUpperBuff(v.bstrVal,wcslen(v.bstrVal));
                if (!nPartial) {
                    if (wcscmp(bstr,v.bstrVal) == 0) return TRUE;
                } else if (nPartial == 1) {
                    if (wcsstr(v.bstrVal,bstr) == v.bstrVal) return TRUE;
                } else {
                    if (wcsstr(bstr,v.bstrVal)) return TRUE;
                }
            }
        }

    }
    return FALSE;
}
STDMETHODIMP CNSListView::FindItems(BSTR                    Text, 
                                    VARIANT_BOOL            bSubItems, 
                                    VARIANT_BOOL            bTags, 
                                    NSListViewFindConstants nPartial, 
                                    INSComCtlColl           **ppObj) {
    if (!ppObj) return E_POINTER;
    *ppObj = NULL;

    // Enum the items and the subitems
    if (!m_pListItems) return E_UNEXPECTED;

    CNSComCtlColl*  pColl = CNSComCtlColl::CreateColl((void**)ppObj);
    if (!pColl) return E_OUTOFMEMORY;

    ccBSTR  bstr(Text);
    if (!bstr.Length()) return S_FALSE; // Empty collection

    HRESULT hr;

    ::CharUpperBuff(bstr.m_str,bstr.Length());

    int     i;
    long    j,jCount;
    CComPtr<INSListSubItems>        spSubItems;
    CComPtr<INSListSubItem>         spSubItem;

    for (i = 0; i < m_pListItems->m_arrListItems.GetSize(); i++) {
        if (m_pListItems->m_arrListItems[i]) {
            if (_CompareItem(bstr,m_pListItems->m_arrListItems[i],bTags,(int)nPartial)) {
                pColl->AddObject((IDispatch*)(INSListItem*)m_pListItems->m_arrListItems[i]);
            }
            spSubItems.Release();
            if (bSubItems) {
                hr = m_pListItems->m_arrListItems[i]->get_SubItems(&spSubItems);
                if (!FAILED(hr)) {
                    hr = spSubItems->get_DefinedCount(&jCount);
                    if (!FAILED(hr)) {
                        for (j = 1;j <= jCount;j++) {
                            spSubItem.Release();
                            hr = spSubItems->get_ItemByIndex(j,&spSubItem);
                            if (!FAILED(hr)) {
                                if (_CompareItem(bstr,spSubItem,bTags,(int)nPartial)) {
                                    pColl->AddObject((IDispatch*)(INSListSubItem*)spSubItem);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
	return S_OK;
}

STDMETHODIMP CNSListView::UnSelectAll() {
    if (m_pListItems) {
        for (int i = 0; i < m_pListItems->m_arrListItems.GetSize(); i++) {
            if (m_pListItems->m_arrListItems[i]) {
                m_pListItems->m_arrListItems[i]->put_Selected(VARIANT_FALSE);
            }
        }
    }
	return S_OK;
}

STDMETHODIMP CNSListView::get_SelectedItems(INSComCtlColl **pVal) {
	if (!pVal) return E_POINTER;

    CNSComCtlColl*  pColl = CNSComCtlColl::CreateColl((void**)pVal);
    if (!pColl) return E_OUTOFMEMORY;

    VARIANT_BOOL    b;
    for (int i = 0; i < m_pListItems->m_arrListItems.GetSize(); i++) {
        if (m_pListItems->m_arrListItems[i]) {
            b = VARIANT_FALSE;
            m_pListItems->m_arrListItems[i]->get_Selected(&b);
            if (b) {
                pColl->AddObject((IDispatch*)(INSListItem*)m_pListItems->m_arrListItems[i]);
            }
        }
    }
	return S_OK;
}

STDMETHODIMP CNSListView::get_Columns(INSColumnHeaders **pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_spColumnHeaders;
    (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CNSListView::SetFocus() {
	m_ctlSysListView32.SetFocus();
	return S_OK;
}

STDMETHODIMP CNSListView::get_Width(long *pVal) {
    if (!pVal) return E_POINTER;
    *pVal = m_rcPos.right - m_rcPos.left;
	return S_OK;
}

STDMETHODIMP CNSListView::put_Width(long newVal) {
	RECT rc = m_rcPos;
    rc.right = rc.left + newVal;
    SetObjectRects(&rc,&rc);
	return S_OK;
}

STDMETHODIMP CNSListView::get_Height(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_rcPos.bottom - m_rcPos.top;
	return S_OK;
}

STDMETHODIMP CNSListView::put_Height(long newVal) {
	RECT rc = m_rcPos;
    rc.bottom = rc.top + newVal;
    SetObjectRects(&rc,&rc);
	return S_OK;
}

STDMETHODIMP CNSListView::get_Top(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_rcPos.top;
	return S_OK;
}

STDMETHODIMP CNSListView::put_Top(long newVal) {
	RECT rc = m_rcPos;
    rc.top = newVal;
    rc.bottom = rc.top + m_rcPos.bottom - m_rcPos.top;
    SetObjectRects(&rc,&rc);
	return S_OK;
}

STDMETHODIMP CNSListView::get_Left(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_rcPos.left;
	return S_OK;
}

STDMETHODIMP CNSListView::put_Left(long newVal) {
	RECT rc = m_rcPos;
    rc.left = newVal;
    rc.right = rc.left + m_rcPos.right - m_rcPos.left;
    SetObjectRects(&rc,&rc);
	return S_OK;
}

STDMETHODIMP CNSListView::get_Visible(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (VARIANT_BOOL)IsWindowVisible();
	return S_OK;
}

STDMETHODIMP CNSListView::put_Visible(VARIANT_BOOL newVal) {
    ShowWindow(newVal?SW_SHOW:SW_HIDE);
	return S_OK;
}
