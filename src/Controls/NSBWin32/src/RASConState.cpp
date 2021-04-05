// RASConState.cpp : Implementation of CRASConState
#include "stdafx.h"
#include "Desk.h"
#include "RASConState.h"

/////////////////////////////////////////////////////////////////////////////
// CRASConState

STDMETHODIMP CRASConState::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRASConState
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CRASConState::get_State(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (long)m_rcs.rasconnstate;
	return S_OK;
}

STDMETHODIMP CRASConState::get_ErrorNumber(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (long)m_rcs.dwError;
	return S_OK;
}

STDMETHODIMP CRASConState::get_DeviceType(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    ccBSTR bstr(RAS_MaxDeviceType + 1,m_rcs.szDeviceType);
    bstr.Compact();
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CRASConState::get_DeviceName(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    ccBSTR bstr(RAS_MaxDeviceName + 1,m_rcs.szDeviceName);
    bstr.Compact();
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CRASConState::Refresh() {
    if (!m_hConn) return Error(IDS_E_CONNOTACTIVE);
    m_rcs.dwSize = sizeof(RASCONNSTATUS);
    if (::RasGetConnectStatus(m_hConn,&m_rcs) != ERROR_SUCCESS) return Error(IDS_E_CONSTATEFAILED);
	return S_OK;
}
