// APIPosPoint.cpp : Implementation of CAPIPosPoint
#include "stdafx.h"
#include "Desk.h"
#include "APIPosPoint.h"

/////////////////////////////////////////////////////////////////////////////
// CAPIPosPoint

STDMETHODIMP CAPIPosPoint::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAPIPosPoint
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CAPIPosPoint::get_X(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_l[0];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_X(long newVal) {
	m_l[0] = newVal;
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::get_Y(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_l[1];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_Y(long newVal) {
	m_l[1] = newVal;
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::get_Left(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_l[0];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_Left(long newVal) {
	m_l[0] = newVal;
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::get_Top(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_l[1];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_Top(long newVal) {
	m_l[1] = newVal;

	return S_OK;
}

STDMETHODIMP CAPIPosPoint::get_Right(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_l[2];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_Right(long newVal) {
	m_l[2] = newVal;
    return S_OK;
}

STDMETHODIMP CAPIPosPoint::get_Bottom(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_l[3];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_Bottom(long newVal) {
	m_l[3] = newVal;
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::get_Value(long lIndex, long *pVal) {
    if (!pVal) return E_POINTER;
	if (lIndex < 0 || lIndex > 3) return E_INVALIDARG;
    *pVal = m_l[lIndex];
	return S_OK;
}

STDMETHODIMP CAPIPosPoint::put_Value(long lIndex, long newVal) {
	if (lIndex < 0 || lIndex > 3) return E_INVALIDARG;
    m_l[lIndex] = newVal;
	return S_OK;
}
