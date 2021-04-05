// NSComCtlColl.cpp : Implementation of CNSComCtlColl
#include "stdafx.h"
#include "ComCtl.h"
#include "NSComCtlColl.h"

/////////////////////////////////////////////////////////////////////////////
// CNSComCtlColl

STDMETHODIMP CNSComCtlColl::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSComCtlColl
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// static  
CNSComCtlColl*  CNSComCtlColl::CreateColl(void** pObj) {
    CComObject<CNSComCtlColl>*     p = NULL;
    HRESULT hr = CComObject<CNSComCtlColl>::CreateInstance(&p);
    if (FAILED(hr)) return NULL;

    hr = p->QueryInterface(IID_INSComCtlColl,pObj);
    if (FAILED(hr)) {
        delete p;
        return NULL;
    }
    return p;
}

HRESULT CNSComCtlColl::AddObject(IDispatch* p) {
    ccVariant v;
    v = p;
    if (!m_arrItems.Add(v)) return E_OUTOFMEMORY;
    return S_OK;
}
HRESULT CNSComCtlColl::AddBSTR(BSTR bstr) {
    ccVariant v;
    v = bstr;
    if (!m_arrItems.Add(v)) return E_OUTOFMEMORY;
    return S_OK;
}
HRESULT CNSComCtlColl::AddVariant(VARIANT v) {
    ccVariant vVar;
    vVar = v;
    if (!m_arrItems.Add(vVar)) return E_OUTOFMEMORY;
    return S_OK;
}

STDMETHODIMP CNSComCtlColl::get_Count(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_arrItems.GetSize();
	return S_OK;
}

STDMETHODIMP CNSComCtlColl::get_Item(long Index, VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    if (Index < 1 || Index >= m_arrItems.GetSize()) return DISP_E_BADINDEX;
    return m_arrItems[(int)Index].CopyTo(pVal);
}

STDMETHODIMP CNSComCtlColl::get__NewEnum(IUnknown **pVal) {
	if (!pVal) return E_POINTER;

    HRESULT hr;

    typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;

    enumvar* p = new enumvar;

    if (!m_arrItems.GetSize()) {
        hr = p->Init(NULL, NULL, NULL, AtlFlagCopy);
    } else {
	    hr = p->Init(&m_arrItems[0], (&m_arrItems[m_arrItems.GetSize()-1] + 1), NULL, AtlFlagCopy);
    }

    if (SUCCEEDED(hr)) hr = p->QueryInterface(IID_IEnumVARIANT, (void**)pVal);
    if (FAILED(hr)) {
		delete p;
        return hr;
    }
	return S_OK;
}
