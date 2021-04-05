// NSBListImage.cpp : Implementation of CNSBListImage
#include "stdafx.h"
#include "ComCtl.h"
#include "NSBListImage.h"
#include "NSBImageList.h"

/////////////////////////////////////////////////////////////////////////////
// CNSBListImage

STDMETHODIMP CNSBListImage::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSBListImage
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
int CNSBListImage::FindMyIndex() {
    if (m_pImageList) {
        int i;
        CComPtr<INSBListImage>    spLI;
        HRESULT hr = QueryInterface(IID_INSBListImage,(void**)&spLI);
        if (FAILED(hr)) return -1;
        for (i = 0; i < m_pImageList->m_arrImages.GetSize(); i++) {
            if ((INSBListImage*)spLI == (INSBListImage*)m_pImageList->m_arrImages[i]) {
                return i;
            }
        }
    }
    return -1;
}

STDMETHODIMP CNSBListImage::get_Key(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrKey.CopyTo(pVal);
}

STDMETHODIMP CNSBListImage::put_Key(BSTR newVal) {
	m_bstrKey = newVal;
	return S_OK;
}

STDMETHODIMP CNSBListImage::get_Tag(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    return m_vTag.CopyTo(pVal);
}

STDMETHODIMP CNSBListImage::put_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}
STDMETHODIMP CNSBListImage::putref_Tag(VARIANT newVal) {
	m_vTag = newVal;
	return S_OK;
}

STDMETHODIMP CNSBListImage::get_Index(long *pVal) {
	if (!pVal) return E_POINTER;
    int iIndex = FindMyIndex();
    if (iIndex < 0) return ReprotCOMErrorInfo(L"The image no longer exists.",IID_INSBListImage,L"ListView");
    *pVal = (long)iIndex + 1;
	return S_OK;
}

