// NSBImageList.cpp : Implementation of CNSBImageList
#include "stdafx.h"
#include "ComCtl.h"
#include "NSBImageList.h"
#include "NSBListImage.h"

_ATL_FUNC_INFO g_ImageListEvents[] = {
    {CC_STDCALL,    VT_EMPTY,   0, NULL }
};

/////////////////////////////////////////////////////////////////////////////
// CNSBImageList

STDMETHODIMP CNSBImageList::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSBImageList
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
// static      
HRESULT CNSBImageList::CreateNSBImageList(int x,int y,REFIID iid,void** ppObj) {
    CComObject<CNSBImageList>*  pil = NULL;

    HRESULT hr = CComObject<CNSBImageList>::CreateInstance(&pil);
    if (FAILED(hr)) return hr;

    hr = pil->QueryInterface(iid,ppObj);
    if (FAILED(hr)) {
        delete pil;
        return hr;
    }
    return pil->CreateList(x,y);
}

int CNSBImageList::FindItem(VARIANT Index) {
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
        if (vIndex.lVal < 1 || vIndex.lVal > m_arrImages.GetSize()) return -1;
        return (vIndex.lVal - 1);
    } else {
        int i;
        ccBSTR  bstrKey;
        for (i = 0; i < m_arrImages.GetSize(); i++) {
            bstrKey.Empty();
            hr = m_arrImages[i]->get_Key(&bstrKey);
            if (FAILED(hr)) return -1;
            if (_WCompareStr(bstrKey,vIndex.bstrVal) == S_OK) return i;
        }
        // If not found try again numeric
        hr = vIndex.ChangeType(VT_I4);
        if (!FAILED(hr)) {
            if (vIndex.lVal < 1 || vIndex.lVal > m_arrImages.GetSize()) return -1;
            return (vIndex.lVal - 1);
        }
    }
    return -1;
}

HRESULT CNSBImageList::AddItemObjects(long nCount,BSTR bstrKey,bool bNoKeys) {
    if (nCount > 0) {
        int i;
        CComObject<CNSBListImage>*  pli;
        HRESULT hr;
        CComPtr<INSBListImage>      spLI;

        for (i = 0; i < nCount; i++) {
            pli = NULL;
            hr = CComObject<CNSBListImage>::CreateInstance(&pli);
            if (FAILED(hr)) return hr;
            spLI.Release();
            hr = pli->QueryInterface(IID_INSBListImage,(void**)&spLI);
            if (FAILED(hr)) {
                delete pli;
                return hr;
            }
            if (!m_arrImages.Add(spLI)) {
                return E_OUTOFMEMORY;
            }
            // Only if everything is ok we set up the new image item
            pli->m_pImageList = this;
            if (!bNoKeys) {
                pli->m_bstrKey = bstrKey;
            }
        }
    }
    return S_OK;
}
HRESULT CNSBImageList::RemoveItemObject(long nIndex) {
    if (nIndex < m_arrImages.GetSize() && nIndex >= 0) {
        NSTERMINATE(m_arrImages[(int)nIndex]);
        m_arrImages.RemoveAt((int)nIndex);
    }
    return S_OK;
}

HRESULT CNSBImageList::CreateList(int x,int y) {
    if (m_hList) ImageList_Destroy(m_hList);
    m_hList = ImageList_Create(x,y,ILC_COLORDDB|ILC_MASK,0,1);
    if (!m_hList) {
        m_hList = ImageList_Create(x,y,ILC_COLOR|ILC_MASK,0,1);
    }
    if (!m_hList) return E_OUTOFMEMORY;
    ImageList_SetBkColor(m_hList,m_crBackColor);
    return S_OK;
}

HRESULT CNSBImageList::FinalConstruct() {
    return CreateList(16,16);
}
void    CNSBImageList::FinalRelease() {
    if (m_hList) ImageList_Destroy(m_hList);
}

STDMETHODIMP CNSBImageList::get_Height(long *pVal) {
	if (!pVal) return E_POINTER;
    if (m_hList) {
        *pVal = 0;
        return S_OK;
    }
    int x = 0,y = 0;
    ImageList_GetIconSize(m_hList,&x,&y);
    *pVal = y;
	return S_OK;
}

STDMETHODIMP CNSBImageList::put_Height(long newVal) {
	if (m_hList) {
        int x = 0,y = 0;
        ImageList_GetIconSize(m_hList,&x,&y);
        y = (int)newVal;
        ImageList_SetIconSize(m_hList,x,y);

        for (int i = m_arrImages.GetSize() - 1; i >= 0; i--) {
            RemoveItemObject(i);
        }
    }
    Fire_OnImageListChanged();
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_Width(long *pVal) {
	if (!pVal) return E_POINTER;
    if (m_hList) {
        *pVal = 0;
        return S_OK;
    }
    int x = 0,y = 0;
    ImageList_GetIconSize(m_hList,&x,&y);
    *pVal = x;
	return S_OK;
}

STDMETHODIMP CNSBImageList::put_Width(long newVal) {
	if (m_hList) {
        int x = 0,y = 0;
        ImageList_GetIconSize(m_hList,&x,&y);
        x = (int)newVal;
        ImageList_SetIconSize(m_hList,x,y);

        for (int i = m_arrImages.GetSize() - 1; i >= 0; i--) {
            RemoveItemObject(i);
        }
    }
    Fire_OnImageListChanged();
	return S_OK;
}

STDMETHODIMP CNSBImageList::LoadBitmap(BSTR bstrBmp, VARIANT Key, long *plIndex) {
    if (!plIndex) return E_POINTER;
    if (!m_hList) CreateList(16,16);

    int nOldCount = ImageList_GetImageCount(m_hList);

    HBITMAP hBmp;
	int iAdd;

    #ifdef _WIN32_WCE
        hBmp = SHLoadDIBitmap(bstrBmp);
    #else
        hBmp = (HBITMAP)LoadImage(NULL,bstrBmp,IMAGE_BITMAP,0,0,0x0040 | 0x0010);
    #endif
    // Default size | load from file
    ccBSTR  bstr;
    bstr = L"Failed to load: ";
    bstr.AppendBSTR(bstrBmp);

    if (!hBmp) return ReprotCOMErrorInfo(bstr,IID_INSBImageList,L"ListView");
	
    if (m_bUseMaskColor) {
        iAdd = ::ImageList_AddMasked(m_hList, hBmp, m_crMaskColor);
    } else {
	    iAdd = ::ImageList_Add(m_hList, hBmp, NULL );
    }
	::DeleteObject(hBmp);
	if (iAdd == -1) {
		return ReprotCOMErrorInfo(bstr,IID_INSBImageList,L"ListView");
	}
    int nNewCount = ImageList_GetImageCount(m_hList);

    ccVariant   vKey(Key);
    
    HRESULT hr = AddItemObjects(nNewCount - nOldCount, (BSTR)vKey,vKey.IsOmitted());

    if (FAILED(hr)) return hr;

    if (plIndex) *plIndex = (long)iAdd + 1;
    Fire_OnImageListChanged();
	return S_OK;
}

STDMETHODIMP CNSBImageList::Remove(VARIANT Index) {
    if (m_hList) {
        int i = FindItem(Index);
        if (i >= 0) {
	        ImageList_Remove(m_hList,i);
            RemoveItemObject(i);
        }
    }
    Fire_OnImageListChanged();
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_hImageList(OLE_HANDLE *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (OLE_HANDLE)m_hList;
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_Count(long *pVal) {
	if (!pVal) return E_POINTER;
    if (!m_hList) *pVal = 0;
    else *pVal = ImageList_GetImageCount(m_hList);
	return S_OK;
}

STDMETHODIMP CNSBImageList::Clear() {
    if (!m_hList) return E_UNEXPECTED;
	for (int i = m_arrImages.GetSize() - 1; i >= 0; i--) {
        RemoveItemObject(i);
    }
    ImageList_Remove(m_hList,-1);
    Fire_OnImageListChanged();
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_Item(VARIANT Index, INSBListImage **pVal) {
	if (!pVal) return E_POINTER;
    int i = FindItem(Index);
    if (i < 0) return DISP_E_BADINDEX;
    *pVal = m_arrImages[i];
    if (*pVal) (*pVal)->AddRef();
	return S_OK;
}



STDMETHODIMP CNSBImageList::get_BackColor(OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_crBackColor;
	return S_OK;
}

STDMETHODIMP CNSBImageList::put_BackColor(OLE_COLOR newVal) {
	m_crBackColor = newVal;
    Fire_OnImageListChanged();
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_MaskColor(OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_crMaskColor;
	return S_OK;
}

STDMETHODIMP CNSBImageList::put_MaskColor(OLE_COLOR newVal) {
	m_crMaskColor = newVal;
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_UseMaskColor(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bUseMaskColor;
	return S_OK;
}

STDMETHODIMP CNSBImageList::put_UseMaskColor(VARIANT_BOOL newVal) {
	m_bUseMaskColor = newVal;
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    return m_vTag.CopyTo(pVal);
}

STDMETHODIMP CNSBImageList::put_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}
STDMETHODIMP CNSBImageList::putref_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}

STDMETHODIMP CNSBImageList::get_ImageIndex(VARIANT Index, long *pVal) {
	if (!pVal) return E_POINTER;
    int i = FindItem(Index);
    *pVal = (long)i + 1;
	return S_OK;
}

STDMETHODIMP CNSBImageList::AddIcon(VARIANT vData, VARIANT vKey, VARIANT_BOOL bCursor, long *plIndex) {
    return E_NOTIMPL;
    /*
	ccVariant   vIconData;
    HRESULT hr = vIcondata.ToValue(vData);
    if (FAILED(hr)) return hr;

    if (v.vt == (VT_UI1 | VT_ARRAY)) {
        // Icon data

    } else {
        hr = vIconData.ChangeType(VT_BSTR);
        if (FAILED(hr)) return hr;
        // Load icon file

    }

	return S_OK;
    */
}

STDMETHODIMP CNSBImageList::LoadResource(VARIANT vFile, VARIANT vIndex, VARIANT vType, VARIANT vKey, long *plIndex) {
    if (!plIndex) return E_POINTER;
    if (!m_hList) CreateList(16,16);

    int nOldCount = ImageList_GetImageCount(m_hList);

	ccVariant vModule(vFile);
    ccVariant vResIdx(vIndex);
    ccVariant vResType(vType);
    ccVariant vKeyName(vKey);

    HINSTANCE   hinstModule;
    HRESULT     hr;

    if (vModule.IsOmitted()) {
        hinstModule = (HINSTANCE)::GetCurrentProcess();
    } else {
        hr = vModule.ChangeType(VT_BSTR);
        if (FAILED(hr)) return hr;

        hinstModule = LoadLibrary((BSTR)vModule);
        if (!hinstModule) return ReprotCOMErrorInfo(L"Cannot load the specified EXE or DLL",IID_INSBImageList,L"ListView");
    }

    int nType = (int)vResType; // defaults to 0 - Bitmap, 1 - Icon, 2 - Cursor
    
    hr = vResIdx.ToValue();
    if (FAILED(hr)) goto LoadResource_Finalize;

    LPTSTR  szResID;

    if (vResIdx.vt == VT_BSTR) {
        szResID = (BSTR)vResIdx;
    } else {
        hr = vResIdx.ChangeType(VT_I4);
        if (FAILED(hr)) goto LoadResource_Finalize;
        szResID = MAKEINTRESOURCE((WORD)(long)vResIdx);
    }

    HBITMAP hBmp;
    HICON   hIcon;
    int     iAdd;
    int     nNewCount;

    switch (nType) {
        case 0: // Bitmap
            hBmp = ::LoadBitmap(hinstModule,szResID);
            if (!hBmp) {
                hr = ReprotCOMErrorInfo(L"Failed to load the specified bitmap resource.",IID_INSBImageList,L"ListView");
                goto LoadResource_Finalize;
            }
            if (m_bUseMaskColor) {
                iAdd = ::ImageList_AddMasked(m_hList, hBmp, m_crMaskColor);
            } else {
	            iAdd = ::ImageList_Add(m_hList, hBmp, NULL );
            }
	        ::DeleteObject(hBmp);
	        if (iAdd == -1) {
		        hr = ReprotCOMErrorInfo(L"Failed to load the specified bitmap resource.",IID_INSBImageList,L"ListView");
                goto LoadResource_Finalize;
	        }
            nNewCount = ImageList_GetImageCount(m_hList);
    
            hr = AddItemObjects(nNewCount - nOldCount, (BSTR)vKeyName,vKeyName.IsOmitted());

            if (FAILED(hr)) goto LoadResource_Finalize;

            if (plIndex) *plIndex = (long)iAdd + 1;
        break;
        case 1: // Icon
        case 2: // Cursor
            if (nType == 1) {
                hIcon = ::LoadIcon(hinstModule,szResID);
            } else {
                hIcon = (HICON)::LoadCursor(hinstModule,szResID);
            }
            if (!hIcon) {
                hr = ReprotCOMErrorInfo(L"Failed to load the specified icon/cursor resource.",IID_INSBImageList,L"ListView");
                goto LoadResource_Finalize;
            }
            iAdd = ::ImageList_AddIcon(m_hList, hIcon);
            ::DeleteObject(hIcon);

            if (iAdd == -1) {
		        hr = ReprotCOMErrorInfo(L"Failed to load the specified icon/cursor resource.",IID_INSBImageList,L"ListView");
                goto LoadResource_Finalize;
	        }
            nNewCount = ImageList_GetImageCount(m_hList);
    
            hr = AddItemObjects(nNewCount - nOldCount, (BSTR)vKeyName,vKeyName.IsOmitted());

            if (FAILED(hr)) goto LoadResource_Finalize;

            if (plIndex) *plIndex = (long)iAdd + 1;
        break;
    }


    Fire_OnImageListChanged();
    
  LoadResource_Finalize:
    if (!vModule.IsOmitted()) FreeLibrary(hinstModule);

	return hr;
}
