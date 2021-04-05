// NSFont.h : Declaration of the CNSFont

#ifndef __NSFONT_H_
#define __NSFONT_H_

#include "resource.h"       // main symbols
#include "ComCtlCP.h"

/////////////////////////////////////////////////////////////////////////////
// CNSFont
class ATL_NO_VTABLE CNSFont : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSFont, &CLSID_NSFont>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CNSFont>,
	public IDispatchImpl<INSFont, &IID_INSFont, &LIBID_COMCTLLib>,
	public CProxy_INSFontEvents< CNSFont >
{
public:
	CNSFont() {
        ZeroMemory(&lf,sizeof(LOGFONT));
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSFONT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSFont)
	COM_INTERFACE_ENTRY(INSFont)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CNSFont)
CONNECTION_POINT_ENTRY(DIID__INSFontEvents)
END_CONNECTION_POINT_MAP()

LOGFONT         lf;

static HRESULT CreateNSFont(INSFont** ppObj);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSFont
public:
	STDMETHOD(get_hFont)(/*[out, retval]*/ OLE_HANDLE *pVal);
	STDMETHOD(get_Size)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_Size)(/*[in]*/ double newVal);
	STDMETHOD(get_Charset)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Charset)(/*[in]*/ short newVal);
	STDMETHOD(get_Strikethru)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Strikethru)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Underline)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Underline)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Name)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Italic)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Italic)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Bold)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Bold)(/*[in]*/ VARIANT_BOOL newVal);
};

#endif //__NSFONT_H_
