// RASEntry.h : Declaration of the CRASEntry

#ifndef __RASENTRY_H_
#define __RASENTRY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRASEntry
class ATL_NO_VTABLE CRASEntry : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRASEntry, &CLSID_RASEntry>,
	public ISupportErrorInfo,
	public IDispatchImpl<IRASEntry, &IID_IRASEntry, &LIBID_DESKLib>
{
public:
	CRASEntry() {
        ZeroMemory(&m_rasEntryParams,sizeof(RASDIALPARAMS));
        m_rasEntryParams.dwSize = sizeof(RASDIALPARAMS);
        m_hConn = NULL;
        m_bHasPassword = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RASENTRY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRASEntry)
	COM_INTERFACE_ENTRY(IRASEntry)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

RASDIALPARAMS m_rasEntryParams;
ccBSTR        m_bstrPhoneBook;
HRASCONN      m_hConn;
BOOL          m_bHasPassword;

HRESULT       FindHConn();

//HWND          m_hWnd;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRASEntry
public:
	STDMETHOD(ResetState)();
	STDMETHOD(get_Status)(/*[out, retval]*/ IDispatch* *pVal);
	STDMETHOD(get_IsActive)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_HasPassword)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HasPassword)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(Delete)();
	STDMETHOD(Update)();
	STDMETHOD(Load)();
	STDMETHOD(Disconnect)();
	STDMETHOD(Connect)();
	STDMETHOD(get_PhoneNumber)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_PhoneNumber)(/*[in]*/ BSTR newVal);
	STDMETHOD(Validate)(/*[out,retval]*/ VARIANT_BOOL* pbResult);
	STDMETHOD(put_Password)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Domain)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Domain)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_UserName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_UserName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_CallbackNumber)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_CallbackNumber)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Name)(/*[in]*/ BSTR newVal);
};

#endif //__RASENTRY_H_
