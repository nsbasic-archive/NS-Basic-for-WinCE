// RAS.cpp : Implementation of CRAS
#include "stdafx.h"
#include "Desk.h"
#include "RAS.h"
#include "MiniEnum.h"
#include "RASEntry.h"

/////////////////////////////////////////////////////////////////////////////
// CRAS

STDMETHODIMP CRAS::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRAS
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CRAS::get_PhoneBook(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bstrPhoneBook.Copy();

	return S_OK;
}

STDMETHODIMP CRAS::put_PhoneBook(BSTR newVal) {
	m_bstrPhoneBook = newVal;
	return S_OK;
}

STDMETHODIMP CRAS::get_Entries(IUnknown **pVal) {
    if (!pVal) return E_POINTER;

	// LPRASENTRYNAME  lprn;
    // LPBYTE          lprn;
    ccBuffer        lprn(0x10000,0x100);
	DWORD           dwSize,dwEntries;
	
	DWORD           i;
    HRESULT         hr;

	dwEntries = 0;
	dwSize = sizeof(RASENTRYNAME);
	
	if (!lprn.Prepare(dwSize)) return E_OUTOFMEMORY;

    // Note that we need to set the struct size for the first entry only before the call
	((LPRASENTRYNAME)lprn.GetPtr())->dwSize = sizeof(RASENTRYNAME);

    BSTR  book = ((m_bstrPhoneBook.Length() > 0)?(BSTR)m_bstrPhoneBook:(BSTR)NULL);
    if (::RasEnumEntries( NULL, book,(LPRASENTRYNAME)lprn.GetPtr(), &dwSize, &dwEntries) != ERROR_SUCCESS) {
        // Attempt to enlarge the buffer as needed
        lprn.Commit(0);
        if (!lprn.Prepare(dwSize)) return E_OUTOFMEMORY;
        ((LPRASENTRYNAME)lprn.GetPtr())->dwSize = sizeof(RASENTRYNAME);
        if (::RasEnumEntries( NULL, book,(LPRASENTRYNAME)lprn.GetPtr(), &dwSize, &dwEntries) != ERROR_SUCCESS) {
            return Error(IDS_E_RASENUMFAILED);
        }
    }
    lprn.Commit(dwEntries * sizeof(RASENTRYNAME));
    // If we are here we are successful up to this point
    CComObject<CMiniEnum>*  penum = NULL;
    hr = CComObject<CMiniEnum>::CreateInstance(&penum);
    if (FAILED(hr)) return hr;
    hr = penum->QueryInterface(IID_IUnknown,(void**)pVal);
    if (FAILED(hr)) {
        delete penum;
        return hr;
    }

    CComVariant                 vItem;

    CComObject<CRASEntry>*      pEntry;


    for (i = 0; i < dwEntries;i++) {
        vItem.Clear();
        
        hr = CComObject<CRASEntry>::CreateInstance(&pEntry);
        if (FAILED(hr)) {
            (*pVal)->Release();
            return E_OUTOFMEMORY;
        }
        hr = pEntry->QueryInterface(IID_IDispatch,(void**)&vItem.pdispVal);
        if (FAILED(hr)) {
            (*pVal)->Release();
            delete pEntry;
            return E_OUTOFMEMORY;
        }
        vItem.vt = VT_DISPATCH;
        pEntry->put_Name( ((LPRASENTRYNAME)lprn.GetPtr())[i].szEntryName );
        pEntry->m_bstrPhoneBook = m_bstrPhoneBook;
        pEntry->Load();
        pEntry->ResetState();

        if (!penum->arrItems.Add(vItem)) {
            (*pVal)->Release();
            return E_OUTOFMEMORY;
        }
    }
    return S_OK;
}

STDMETHODIMP CRAS::get_Version(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = 201;
	return S_OK;
}

STDMETHODIMP CRAS::get_Connections(IUnknown **pVal) {
	if (!pVal) return E_POINTER;

	// LPRASENTRYNAME  lprn;
    // LPBYTE          lprn;
    ccBuffer        lprn(0x10000,0x100);
	DWORD           dwSize,dwEntries;
	
	DWORD           i;
    HRESULT         hr;

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
            return Error(IDS_E_RASENUMFAILED);
        }
    }
    lprn.Commit(dwEntries * sizeof(RASCONN));
    // If we are here we are successful up to this point
    CComObject<CMiniEnum>*  penum = NULL;
    hr = CComObject<CMiniEnum>::CreateInstance(&penum);
    if (FAILED(hr)) return hr;
    hr = penum->QueryInterface(IID_IUnknown,(void**)pVal);
    if (FAILED(hr)) {
        delete penum;
        return hr;
    }

    CComVariant                 vItem;

    CComObject<CRASEntry>*      pEntry;


    for (i = 0; i < dwEntries;i++) {
        vItem.Clear();
        
        hr = CComObject<CRASEntry>::CreateInstance(&pEntry);
        if (FAILED(hr)) {
            (*pVal)->Release();
            return E_OUTOFMEMORY;
        }
        hr = pEntry->QueryInterface(IID_IDispatch,(void**)&vItem.pdispVal);
        if (FAILED(hr)) {
            (*pVal)->Release();
            delete pEntry;
            return E_OUTOFMEMORY;
        }
        vItem.vt = VT_DISPATCH;
        pEntry->put_Name( ((LPRASCONN)lprn.GetPtr())[i].szEntryName );
        #ifndef _WIN32_WCE
            pEntry->m_bstrPhoneBook = ((LPRASCONN)lprn.GetPtr())[i].szPhonebook;
        #endif
        pEntry->Load();
        pEntry->m_hConn = ((LPRASCONN)lprn.GetPtr())[i].hrasconn;

        if (!penum->arrItems.Add(vItem)) {
            (*pVal)->Release();
            return E_OUTOFMEMORY;
        }
    }
    return S_OK;
}

STDMETHODIMP CRAS::get_Entry(BSTR bstrName, IDispatch **pVal) {
    if (!pVal) return E_POINTER;
    HRESULT     hr;

	CComObject<CRASEntry>*      pEntry = NULL;
    hr = CComObject<CRASEntry>::CreateInstance(&pEntry);
    if (FAILED(hr)) return E_OUTOFMEMORY;
    hr = pEntry->QueryInterface(IID_IDispatch,(void**)pVal);
    if (FAILED(hr)) {
        delete pEntry;
        return E_OUTOFMEMORY;
    }
    pEntry->put_Name(bstrName);
    pEntry->m_bstrPhoneBook = m_bstrPhoneBook;
    hr = pEntry->Load();
    if (FAILED(hr)) {
        (*pVal)->Release();
        return hr;
    }
	return S_OK;
}
