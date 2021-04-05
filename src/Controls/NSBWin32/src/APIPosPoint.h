// APIPosPoint.h : Declaration of the CAPIPosPoint

#ifndef __APIPOSPOINT_H_
#define __APIPOSPOINT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAPIPosPoint
class ATL_NO_VTABLE CAPIPosPoint : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CAPIPosPoint, &CLSID_APIPosPoint>,
	public ISupportErrorInfo,
	public IDispatchImpl<IAPIPosPoint, &IID_IAPIPosPoint, &LIBID_DESKLib>
{
public:
	CAPIPosPoint() {
        ZeroMemory(&m_l,sizeof(long) * 4);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_APIPOSPOINT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CAPIPosPoint)
	COM_INTERFACE_ENTRY(IAPIPosPoint)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

LONG    m_l[4];

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IAPIPosPoint
public:
	STDMETHOD(get_Value)(/*[in]*/ long lIndex, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_Value)(/*[in]*/ long lIndex, /*[in]*/ long newVal);
	STDMETHOD(get_Bottom)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Bottom)(/*[in]*/ long newVal);
	STDMETHOD(get_Right)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Right)(/*[in]*/ long newVal);
	STDMETHOD(get_Top)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Top)(/*[in]*/ long newVal);
	STDMETHOD(get_Left)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Left)(/*[in]*/ long newVal);
	STDMETHOD(get_Y)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Y)(/*[in]*/ long newVal);
	STDMETHOD(get_X)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_X)(/*[in]*/ long newVal);
};

#endif //__APIPOSPOINT_H_
