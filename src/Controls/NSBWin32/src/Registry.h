// Registry.h : Declaration of the CRegistry

#ifndef __REGISTRY_H_
#define __REGISTRY_H_

#include "resource.h"       // main symbols

// Behavior flags
#define NSBASIC_REGISTRY_BINASHEX       0x0000
#define NSBASIC_REGISTRY_BINASBYTES     0x0001
#define NSBASIC_REGISTRY_HEXWITHSPACES  0x0002
#define NSBASIC_REGISTRY_ENDENUMEMPTY   0x0004


/////////////////////////////////////////////////////////////////////////////
// CRegistry
class ATL_NO_VTABLE CRegistry : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRegistry, &CLSID_Registry>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CRegistry>,
    public IProvideClassInfo2Impl<&CLSID_Registry, &DIID__IRegistryEvents, &LIBID_DESKLib>,
	public IDispatchImpl<IRegistry, &IID_IRegistry, &LIBID_DESKLib>
{
public:
	CRegistry()	{
        m_hkRoot = NULL;
        m_lType  = REG_SZ;
        m_dwBehavior = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_REGISTRY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRegistry)
	COM_INTERFACE_ENTRY(IRegistry)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CRegistry)
END_CONNECTION_POINT_MAP()

HKEY        m_hkRoot;
ccBSTR      m_bstrPath;
ccBSTR      m_bstrValName;
long        m_lType;
DWORD       m_dwBehavior;



// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRegistry
public:
	STDMETHOD(get_ReturnEmptyForEnumEnd)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ReturnEmptyForEnumEnd)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_HexWithSpaces)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HexWithSpaces)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_UseRawBinary)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_UseRawBinary)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Value)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Value)(/*[in]*/ VARIANT newVal);
	STDMETHOD(DeleteValue)();
	STDMETHOD(DeletePath)();
	STDMETHOD(CreatePath)();
	STDMETHOD(GetValueName)(/*[in]*/ long lVal,/*[out,retval]*/ BSTR* bstrVal);
	STDMETHOD(GetPathName)(/*[in]*/ long lPath,/*[out,retval]*/ BSTR* bstrPath);
	STDMETHOD(get_ValueType)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ValueType)(/*[in]*/ long newVal);
	STDMETHOD(get_Version)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Name)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Path)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Path)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Key)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Key)(/*[in]*/ long newVal);

private:

};

#endif //__REGISTRY_H_
