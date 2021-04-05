// RASEntry.cpp : Implementation of CRASEntry
#include "stdafx.h"
#include "Desk.h"
#include "RASEntry.h"
#include "RASConState.h"

/////////////////////////////////////////////////////////////////////////////
// CRASEntry

STDMETHODIMP CRASEntry::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRASEntry
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
HRESULT      CRASEntry::FindHConn() {
    ccBuffer        lprn(0x10000,0x100);
	DWORD           dwSize,dwEntries;
	
	DWORD           i;

	dwEntries = 0;
	dwSize = sizeof(RASCONN);
	
	if (!lprn.Prepare(dwSize)) return E_OUTOFMEMORY;

    // Note that we need to set the struct size for the first entry only before the call
	((LPRASCONN)lprn.GetPtr())->dwSize = sizeof(RASCONN);

    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
    if (::RasEnumConnections((LPRASCONN)lprn.GetPtr(), &dwSize, &dwEntries) != ERROR_SUCCESS) {
        // Attempt to enlarge the buffer as needed
        lprn.Commit(0);
        if (!lprn.Prepare(dwSize)) return E_OUTOFMEMORY;
        ((LPRASCONN)lprn.GetPtr())->dwSize = sizeof(RASCONN);
        if (::RasEnumConnections( (LPRASCONN)lprn.GetPtr(), &dwSize, &dwEntries) != ERROR_SUCCESS) {
            return E_FAIL;
        }
    }
    lprn.Commit(dwEntries * sizeof(RASCONN));
    // If we are here we are successful up to this point
    
    // Find ourselves in there
    for (i = 0; i < dwEntries;i++) {
        if (_tcsicmp( ((LPRASCONN)lprn.GetPtr())[i].szEntryName,m_rasEntryParams.szEntryName ) == 0) {
            m_hConn = ((LPRASCONN)lprn.GetPtr())[i].hrasconn;
            break;
        }
    }

    return S_OK;
}

STDMETHODIMP CRASEntry::get_Name(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ::SysAllocString(m_rasEntryParams.szEntryName);
    return (*pVal)?S_OK:E_OUTOFMEMORY;
}
STDMETHODIMP CRASEntry::put_Name(BSTR newVal) {
	ccBSTR  bstr = newVal;
    bstr.CopyToBuff(m_rasEntryParams.szEntryName,RAS_MaxEntryName+1);
	return S_OK;
}

STDMETHODIMP CRASEntry::get_CallbackNumber(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ::SysAllocString(m_rasEntryParams.szCallbackNumber);
    return (*pVal)?S_OK:E_OUTOFMEMORY;
}

STDMETHODIMP CRASEntry::put_CallbackNumber(BSTR newVal) {
	ccBSTR  bstr = newVal;
    bstr.CopyToBuff(m_rasEntryParams.szCallbackNumber,RAS_MaxCallbackNumber + 1);
	return S_OK;
}

STDMETHODIMP CRASEntry::get_UserName(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ::SysAllocString(m_rasEntryParams.szUserName);
    return (*pVal)?S_OK:E_OUTOFMEMORY;
}

STDMETHODIMP CRASEntry::put_UserName(BSTR newVal) {
	ccBSTR  bstr = newVal;
    bstr.CopyToBuff(m_rasEntryParams.szUserName,UNLEN + 1);
	return S_OK;
}

STDMETHODIMP CRASEntry::get_Domain(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ::SysAllocString(m_rasEntryParams.szDomain);
    return (*pVal)?S_OK:E_OUTOFMEMORY;
}

STDMETHODIMP CRASEntry::put_Domain(BSTR newVal) {
	ccBSTR  bstr = newVal;
    bstr.CopyToBuff(m_rasEntryParams.szDomain,DNLEN + 1);
	return S_OK;
}

STDMETHODIMP CRASEntry::put_Password(BSTR newVal) {
	ccBSTR  bstr = newVal;
    bstr.CopyToBuff(m_rasEntryParams.szPassword,PWLEN + 1);
	return S_OK;
}

STDMETHODIMP CRASEntry::Validate(VARIANT_BOOL *pbResult) {
    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
	DWORD dwStatus = RasValidateEntryName(book,m_rasEntryParams.szEntryName);
    if (pbResult) {
        if (dwStatus == ERROR_SUCCESS) {
            *pbResult = VARIANT_TRUE;
        } else {
            *pbResult = VARIANT_FALSE;
        }
        return S_OK;
    } else {
        if (dwStatus == ERROR_SUCCESS) {
            return S_OK;
        } else {
            return Error(IDS_E_INVALIDENTRYNAME);
        }
    }
}
STDMETHODIMP CRASEntry::get_PhoneNumber(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = ::SysAllocString(m_rasEntryParams.szPhoneNumber);
    return (*pVal)?S_OK:E_OUTOFMEMORY;
}
STDMETHODIMP CRASEntry::put_PhoneNumber(BSTR newVal) {
	ccBSTR  bstr = newVal;
    bstr.CopyToBuff(m_rasEntryParams.szPhoneNumber,RAS_MaxPhoneNumber + 1);
	return S_OK;
}
STDMETHODIMP CRASEntry::Connect() {
	DWORD dwStatus;
    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
    dwStatus = ::RasDial( NULL, book, &m_rasEntryParams, NULL, NULL, &m_hConn);
	if (dwStatus == ERROR_SUCCESS) return S_OK;	
	return S_OK;
}
STDMETHODIMP CRASEntry::Disconnect() {
	if (!m_hConn) return Error(IDS_E_NOTCONNECTED);
    DWORD dw = RasHangUp(m_hConn);
    if (dw == ERROR_SUCCESS) {
        m_hConn = NULL; // Clean up for any following calls
        return S_OK;
    } else {
        ccBSTR  bstrErr;
        bstrErr.LoadString(_Module.m_hInstResource,IDS_E_CANNOTHANGUP);
        TCHAR _l[64];
        _itow((int)dw,_l,10);
        bstrErr.Append(_l);
        return Error(bstrErr);
    }
    
	return S_OK;
}

STDMETHODIMP CRASEntry::Load() {
	DWORD dwStatus;
    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
    m_rasEntryParams.dwSize = sizeof(RASDIALPARAMS);
    dwStatus = ::RasGetEntryDialParams(book, &m_rasEntryParams,&m_bHasPassword);
	if (!dwStatus) return S_OK;
	return Error(IDS_E_RETRIEVEENTRYFAILED);
}

STDMETHODIMP CRASEntry::Update() {
	DWORD dwStatus;
    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
	dwStatus = RasSetEntryDialParams(book,&m_rasEntryParams,!m_bHasPassword);
	if (dwStatus == ERROR_SUCCESS) return S_OK;
	return Error(IDS_E_UPDATEENTRYFAILED);
}

STDMETHODIMP CRASEntry::Delete() {
	DWORD dwStatus;
    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
	dwStatus = RasDeleteEntry(book,m_rasEntryParams.szEntryName);
	
	if (dwStatus == ERROR_SUCCESS) return S_OK;
	return Error(IDS_E_DELETEENTRYFAILED);
}

STDMETHODIMP CRASEntry::get_HasPassword(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (VARIANT_BOOL)m_bHasPassword;
	return S_OK;
}

STDMETHODIMP CRASEntry::put_HasPassword(VARIANT_BOOL newVal) {
	m_bHasPassword = (BOOL)newVal;
    return S_OK;
}

STDMETHODIMP CRASEntry::get_IsActive(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = VARIANT_FALSE;
    if (!m_hConn) FindHConn();
    if (m_hConn) *pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CRASEntry::get_Status(IDispatch **pVal) {
    if (!pVal) return E_POINTER;
    HRESULT     hr;

	CComObject<CRASConState>*      pState = NULL;
    hr = CComObject<CRASConState>::CreateInstance(&pState);
    if (FAILED(hr)) return E_OUTOFMEMORY;
    hr = pState->QueryInterface(IID_IDispatch,(void**)pVal);
    if (FAILED(hr)) {
        delete pState;
        return E_OUTOFMEMORY;
    }
    if (!m_hConn) FindHConn();
    pState->m_hConn = m_hConn;
    pState->Refresh();

	return S_OK;
}
// This one is to here just in case
STDMETHODIMP CRASEntry::ResetState() {
	FindHConn();
	return S_OK;
}
