// NSBListImage.h : Declaration of the CNSBListImage

#ifndef __NSBLISTIMAGE_H_
#define __NSBLISTIMAGE_H_

#include "resource.h"       // main symbols

class CNSBImageList;

/////////////////////////////////////////////////////////////////////////////
// CNSBListImage
class ATL_NO_VTABLE CNSBListImage : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSBListImage, &CLSID_NSBListImage>,
	public ISupportErrorInfo,
    public INSComCtlInt,
	public IDispatchImpl<INSBListImage, &IID_INSBListImage, &LIBID_COMCTLLib>
{
public:
	CNSBListImage() {
        m_pImageList = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSBLISTIMAGE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNSBListImage)
	COM_INTERFACE_ENTRY(INSBListImage)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(INSComCtlInt)
END_COM_MAP()

CNSBImageList*      m_pImageList;
ccBSTR              m_bstrKey;
ccVariant           m_vTag;

int FindMyIndex();

// INSComCtlInt
    STDMETHOD(NSTerminate)() { m_pImageList = NULL; return S_OK; }
    STDMETHOD(NSInitialize)() { return S_OK; }

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSBListImage
public:
	STDMETHOD(get_Index)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
    STDMETHOD(putref_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Key)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Key)(/*[in]*/ BSTR newVal);
};

#endif //__NSBLISTIMAGE_H_
