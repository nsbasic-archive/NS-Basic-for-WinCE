// NSComDlgFlags.h : Declaration of the CNSComDlgFlags

#ifndef __NSCOMDLGFLAGS_H_
#define __NSCOMDLGFLAGS_H_

#include "resource.h"       // main symbols
#include "NSComDlg.h"       // Main class

/////////////////////////////////////////////////////////////////////////////
// CNSComDlgFlags
class ATL_NO_VTABLE CNSComDlgFlags : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNSComDlgFlags, &CLSID_NSComDlgFlags>,
	public ISupportErrorInfo,
	public IDispatchImpl<INSComDlgFlags, &IID_INSComDlgFlags, &LIBID_DESKLib>
{
public:
	CNSComDlgFlags() {
        m_pParent = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSCOMDLGFLAGS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNSComDlgFlags)
	COM_INTERFACE_ENTRY(INSComDlgFlags)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

CNSComDlg*          m_pParent;
CComPtr<IUnknown>   m_spParent; // Hold in memory

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// INSComDlgFlags
public:
	STDMETHOD(get_PrinterFonts)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_PrinterFonts)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(SetDefaults)();
	STDMETHOD(get_Value)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Value)(/*[in]*/ long newVal);
	STDMETHOD(get_WYSIWYG)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_WYSIWYG)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_TTOnly)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_TTOnly)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ScreenFonts)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ScreenFonts)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ScalableOnly)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ScalableOnly)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoVectorFonts)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoVectorFonts)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoStyleSel)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoStyleSel)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoSizeSel)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoSizeSel)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoSimulations)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoSimulations)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoFaceSel)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoFaceSel)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_LimitSize)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_LimitSize)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ForceFontExist)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ForceFontExist)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FixedPitchOnly)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FixedPitchOnly)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Effects)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Effects)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ANSIOnly)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ANSIOnly)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_RGBInit)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_RGBInit)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_PreventFullOpen)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_PreventFullOpen)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FullOpen)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FullOpen)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ShareAware)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ShareAware)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ReadOnly)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ReadOnly)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_PathMustExist)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_PathMustExist)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_OverwritePrompt)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_OverwritePrompt)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoValidate)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoValidate)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoReadOnlyReturn)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoReadOnlyReturn)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoDereferenceLinks)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoDereferenceLinks)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_NoChangeDir)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_NoChangeDir)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_HideReadOnly)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HideReadOnly)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_HelpButton)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HelpButton)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FileMustExist)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FileMustExist)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ExtensionDifferent)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_CreatePrompt)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CreatePrompt)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_MultiSelect)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_MultiSelect)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(Clear)();
};

#endif //__NSCOMDLGFLAGS_H_
