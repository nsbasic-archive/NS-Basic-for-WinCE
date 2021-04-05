// ComDlgMiniEnum.h : Declaration of the CComDlgMiniEnum

#ifndef __COMDLGMINIENUM_H_
#define __COMDLGMINIENUM_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComDlgMiniEnum
class ATL_NO_VTABLE CComDlgMiniEnum : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CComDlgMiniEnum, &CLSID_ComDlgMiniEnum>,
	public ISupportErrorInfo,
	public IDispatchImpl<IComDlgMiniEnum, &IID_IComDlgMiniEnum, &LIBID_DESKLib>
{
public:
	CComDlgMiniEnum()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMDLGMINIENUM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CComDlgMiniEnum)
	COM_INTERFACE_ENTRY(IComDlgMiniEnum)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

CSimpleArray<ccVariant>   arrItems;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IComDlgMiniEnum
public:
    STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Item)(/*[in]*/ long lIndex, /*[out, retval]*/ VARIANT *pVal);
};

#endif //__COMDLGMINIENUM_H_
