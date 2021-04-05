// MiniEnum.cpp : Implementation of CMiniEnum
#include "stdafx.h"
#include "Desk.h"
#include "MiniEnum.h"

/////////////////////////////////////////////////////////////////////////////
// CMiniEnum

STDMETHODIMP CMiniEnum::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMiniEnum
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

void    CMiniEnum::FinalRelease() {
    arrItems.RemoveAll();
}

STDMETHODIMP CMiniEnum::get_Item(long lIndex, VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    if (lIndex < 1 || lIndex > arrItems.GetSize()) return DISP_E_BADINDEX;
    ::VariantCopyInd(pVal,&arrItems[lIndex - 1]);
	return S_OK;
}

STDMETHODIMP CMiniEnum::get_Count(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (long)arrItems.GetSize();
	return S_OK;
}

STDMETHODIMP CMiniEnum::get__NewEnum(IUnknown **pVal) {
	// Create the IEnumVariant enumerator
    typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;
	enumvar*    p = new enumvar;
    HRESULT     hr;

    // Transfer the info to it
    if (!arrItems.GetSize()) {
        hr = p->Init(NULL, NULL, NULL, AtlFlagCopy);
    } else {
	    hr = p->Init(&arrItems[0], (&arrItems[arrItems.GetSize()-1] + 1), NULL, AtlFlagCopy);
    }

    if (SUCCEEDED(hr)) hr = p->QueryInterface(IID_IEnumVARIANT, (void**)pVal);
	if (FAILED(hr)) delete p;

	return S_OK;
}
