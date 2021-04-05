// NSBImageList.h : Declaration of the CNSBImageList

#ifndef __NSBIMAGELIST_H_
#define __NSBIMAGELIST_H_

#include "resource.h"       // main symbols
#include "ComCtlCP.h"

/////////////////////////////////////////////////////////////////////////////
// CNSBImageList
class ATL_NO_VTABLE CNSBImageList : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSBImageList, &CLSID_NSBImageList>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CNSBImageList>,
	public IDispatchImpl<INSBImageList, &IID_INSBImageList, &LIBID_COMCTLLib>,
	public CProxy_INSBImageListEvents< CNSBImageList >
{
public:
	CNSBImageList()	{
        m_hList = NULL;
        m_bUseMaskColor = VARIANT_TRUE;
        m_crMaskColor = RGB(255,255,255);
        m_crBackColor = (COLORREF)::GetSysColor(COLOR_3DFACE);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSBIMAGELIST)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSBImageList)
	COM_INTERFACE_ENTRY(INSBImageList)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CNSBImageList)
CONNECTION_POINT_ENTRY(DIID__INSBImageListEvents)
END_CONNECTION_POINT_MAP()

HIMAGELIST                              m_hList;
// CSimpleArray<CComPtr<INSBListImage> >   m_arrImages;
ccSimpleArray<CComPtr<INSBListImage> >   m_arrImages;
ccVariant                               m_vTag;
VARIANT_BOOL                            m_bUseMaskColor;
COLORREF                                m_crMaskColor;
COLORREF                                m_crBackColor;

HRESULT     CreateList(int x,int y);

HRESULT     AddItemObjects(long nCount, BSTR bstrKey,bool bNoKeys);
HRESULT     RemoveItemObject(long nIndex);
int         FindItem(VARIANT Index);

static      HRESULT CreateNSBImageList(int x,int y,REFIID iid,void** ppObj);


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSBImageList
public:
	STDMETHOD(LoadResource)(/*[in,optional]*/ VARIANT vFile,/*[in,optional]*/ VARIANT vIndex,/*[in,optional]*/ VARIANT vType,/*[in,optional]*/ VARIANT vKey,/*[out,retval]*/ long* plIndex);
	STDMETHOD(AddIcon)(/*[in]*/ VARIANT vData,/*[in,optional]*/ VARIANT vKey,/*[in,defaultvalue(0)]*/ VARIANT_BOOL bCursor,/*[out,retval]*/ long* plIndex);
	STDMETHOD(get_ImageIndex)(/*[in]*/ VARIANT Index, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
    STDMETHOD(putref_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_UseMaskColor)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_UseMaskColor)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_MaskColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_MaskColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_BackColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_BackColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT Index, /*[out, retval]*/ INSBListImage* *pVal);
	STDMETHOD(Clear)();
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_hImageList)(/*[out, retval]*/ OLE_HANDLE *pVal);
	STDMETHOD(Remove)(/*[in]*/ VARIANT Index);
	STDMETHOD(LoadBitmap)(/*[in]*/ BSTR bstrBmp,/*[in,optional]*/ VARIANT Key,/*[out,retval]*/ long* plIndex);
	STDMETHOD(get_Width)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Width)(/*[in]*/ long newVal);
	STDMETHOD(get_Height)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Height)(/*[in]*/ long newVal);
};

#endif //__NSBIMAGELIST_H_
