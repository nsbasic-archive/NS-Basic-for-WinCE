// MiniEnum.h : Declaration of the CMiniEnum

#ifndef __MINIENUM_H_
#define __MINIENUM_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMiniEnum
class ATL_NO_VTABLE CMiniEnum : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CMiniEnum, &CLSID_MiniEnum>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMiniEnum, &IID_IMiniEnum, &LIBID_DESKLib>
{
public:
	CMiniEnum()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MINIENUM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

void    FinalRelease();

BEGIN_COM_MAP(CMiniEnum)
	COM_INTERFACE_ENTRY(IMiniEnum)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

CSimpleArray<CComVariant>   arrItems;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMiniEnum
public:
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown* *pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Item)(/*[in]*/ long lIndex, /*[out, retval]*/ VARIANT *pVal);
};

#endif //__MINIENUM_H_
