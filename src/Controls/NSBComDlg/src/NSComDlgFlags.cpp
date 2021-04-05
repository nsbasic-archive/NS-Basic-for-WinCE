// NSComDlgFlags.cpp : Implementation of CNSComDlgFlags
#include "stdafx.h"
#include "Desk.h"
#include "NSComDlgFlags.h"

/////////////////////////////////////////////////////////////////////////////
// CNSComDlgFlags

STDMETHODIMP CNSComDlgFlags::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSComDlgFlags
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CNSComDlgFlags::Clear() {
	m_pParent->m_dwFlags_Color = 0; // CC_ANYCOLOR;
    m_pParent->m_dwFlags_File = 0; // OFN_ENABLESIZING | OFN_EXPLORER | OFN_LONGNAMES;
    m_pParent->m_dwFlags_Font = 0; //CF_EFFECTS | CF_INITTOLOGFONTSTRUCT;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_MultiSelect(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_ALLOWMULTISELECT)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_MultiSelect(VARIANT_BOOL newVal) {
    m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_ALLOWMULTISELECT):RESETBITS(m_pParent->m_dwFlags_File,OFN_ALLOWMULTISELECT));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_CreatePrompt(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_CREATEPROMPT)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_CreatePrompt(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_CREATEPROMPT):RESETBITS(m_pParent->m_dwFlags_File,OFN_CREATEPROMPT));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ExtensionDifferent(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_EXTENSIONDIFFERENT)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_FileMustExist(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_FILEMUSTEXIST)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_FileMustExist(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_FILEMUSTEXIST):RESETBITS(m_pParent->m_dwFlags_File,OFN_FILEMUSTEXIST));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_HelpButton(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    switch (m_pParent->m_lAction) {
        case 1:
            *pVal = (m_pParent->m_dwFlags_File & OFN_SHOWHELP)?VARIANT_TRUE:VARIANT_FALSE;
        break;
        case 2:
            *pVal = (m_pParent->m_dwFlags_Font & CF_SHOWHELP)?VARIANT_TRUE:VARIANT_FALSE;
        break;
        case 3:
            *pVal = (m_pParent->m_dwFlags_Color & CC_SHOWHELP)?VARIANT_TRUE:VARIANT_FALSE;
        break;
        default:
            *pVal = (m_pParent->m_dwFlags_File & OFN_SHOWHELP)?VARIANT_TRUE:VARIANT_FALSE;
            *pVal = (m_pParent->m_dwFlags_Font & CF_SHOWHELP)?VARIANT_TRUE:VARIANT_FALSE;
            *pVal = (m_pParent->m_dwFlags_Color & CC_SHOWHELP)?VARIANT_TRUE:VARIANT_FALSE;
    }
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_HelpButton(VARIANT_BOOL newVal) {
    switch (m_pParent->m_lAction) {
        case 1:
            m_pParent->m_dwFlags_File = (newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_SHOWHELP):RESETBITS(m_pParent->m_dwFlags_File,OFN_SHOWHELP);
        break;
        case 2:
            m_pParent->m_dwFlags_Color = (newVal)?SETBITS(m_pParent->m_dwFlags_File,CC_SHOWHELP):RESETBITS(m_pParent->m_dwFlags_File,CC_SHOWHELP);
        break;
        case 3:
            m_pParent->m_dwFlags_Font = (newVal)?SETBITS(m_pParent->m_dwFlags_File,CF_SHOWHELP):RESETBITS(m_pParent->m_dwFlags_File,CF_SHOWHELP);
        break;
        default:
            m_pParent->m_dwFlags_File = (newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_SHOWHELP):RESETBITS(m_pParent->m_dwFlags_File,OFN_SHOWHELP);
            m_pParent->m_dwFlags_Font = (newVal)?SETBITS(m_pParent->m_dwFlags_File,CF_SHOWHELP):RESETBITS(m_pParent->m_dwFlags_File,CF_SHOWHELP);
            m_pParent->m_dwFlags_Color = (newVal)?SETBITS(m_pParent->m_dwFlags_File,CC_SHOWHELP):RESETBITS(m_pParent->m_dwFlags_File,CC_SHOWHELP);
    }
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_HideReadOnly(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_HIDEREADONLY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_HideReadOnly(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_HIDEREADONLY):RESETBITS(m_pParent->m_dwFlags_File,OFN_HIDEREADONLY));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoChangeDir(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_NOCHANGEDIR)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoChangeDir(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_NOCHANGEDIR):RESETBITS(m_pParent->m_dwFlags_File,OFN_NOCHANGEDIR));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoDereferenceLinks(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_NODEREFERENCELINKS)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoDereferenceLinks(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_NODEREFERENCELINKS):RESETBITS(m_pParent->m_dwFlags_File,OFN_NODEREFERENCELINKS));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoReadOnlyReturn(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_NOREADONLYRETURN)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoReadOnlyReturn(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_NOREADONLYRETURN):RESETBITS(m_pParent->m_dwFlags_File,OFN_NOREADONLYRETURN));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoValidate(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_NOVALIDATE)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoValidate(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_NOVALIDATE):RESETBITS(m_pParent->m_dwFlags_File,OFN_NOVALIDATE));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_OverwritePrompt(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_OVERWRITEPROMPT)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_OverwritePrompt(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_OVERWRITEPROMPT):RESETBITS(m_pParent->m_dwFlags_File,OFN_OVERWRITEPROMPT));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_PathMustExist(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_PATHMUSTEXIST)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_PathMustExist(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_PATHMUSTEXIST):RESETBITS(m_pParent->m_dwFlags_File,OFN_PATHMUSTEXIST));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ReadOnly(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_READONLY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_ReadOnly(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_READONLY):RESETBITS(m_pParent->m_dwFlags_File,OFN_READONLY));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ShareAware(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_File & OFN_SHAREAWARE)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_ShareAware(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_File = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_File,OFN_SHAREAWARE):RESETBITS(m_pParent->m_dwFlags_File,OFN_SHAREAWARE));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_FullOpen(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Color & CC_FULLOPEN)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_FullOpen(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Color = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Color,CC_FULLOPEN):RESETBITS(m_pParent->m_dwFlags_Color,CC_FULLOPEN));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_PreventFullOpen(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Color & CC_PREVENTFULLOPEN)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_PreventFullOpen(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Color = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Color,CC_PREVENTFULLOPEN):RESETBITS(m_pParent->m_dwFlags_Color,CC_PREVENTFULLOPEN));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_RGBInit(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Color & CC_RGBINIT)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_RGBInit(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Color = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Color,CC_RGBINIT):RESETBITS(m_pParent->m_dwFlags_Color,CC_RGBINIT));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ANSIOnly(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_ANSIONLY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_ANSIOnly(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_ANSIONLY):RESETBITS(m_pParent->m_dwFlags_Font,CF_ANSIONLY));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_Effects(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_EFFECTS)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_Effects(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_EFFECTS):RESETBITS(m_pParent->m_dwFlags_Font,CF_EFFECTS));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_FixedPitchOnly(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_FIXEDPITCHONLY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_FixedPitchOnly(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_FIXEDPITCHONLY):RESETBITS(m_pParent->m_dwFlags_Font,CF_FIXEDPITCHONLY));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ForceFontExist(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_FORCEFONTEXIST)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_ForceFontExist(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_FORCEFONTEXIST):RESETBITS(m_pParent->m_dwFlags_Font,CF_FORCEFONTEXIST));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_LimitSize(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_LIMITSIZE)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_LimitSize(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_LIMITSIZE):RESETBITS(m_pParent->m_dwFlags_Font,CF_LIMITSIZE));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoFaceSel(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_NOFACESEL)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoFaceSel(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_NOFACESEL):RESETBITS(m_pParent->m_dwFlags_Font,CF_NOFACESEL));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoSimulations(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_NOSIMULATIONS)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoSimulations(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_NOSIMULATIONS):RESETBITS(m_pParent->m_dwFlags_Font,CF_NOSIMULATIONS));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoSizeSel(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_NOSIZESEL)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoSizeSel(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_NOSIZESEL):RESETBITS(m_pParent->m_dwFlags_Font,CF_NOSIZESEL));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoStyleSel(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_NOSTYLESEL)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoStyleSel(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_NOSTYLESEL):RESETBITS(m_pParent->m_dwFlags_Font,CF_NOSTYLESEL));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_NoVectorFonts(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_NOVERTFONTS)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_NoVectorFonts(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_NOVERTFONTS):RESETBITS(m_pParent->m_dwFlags_Font,CF_NOVERTFONTS));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ScalableOnly(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_SCALABLEONLY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_ScalableOnly(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_SCALABLEONLY):RESETBITS(m_pParent->m_dwFlags_Font,CF_SCALABLEONLY));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_ScreenFonts(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_SCREENFONTS)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_ScreenFonts(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_SCREENFONTS):RESETBITS(m_pParent->m_dwFlags_Font,CF_SCREENFONTS));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_TTOnly(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_TTONLY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_TTOnly(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_TTONLY):RESETBITS(m_pParent->m_dwFlags_Font,CF_TTONLY));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_WYSIWYG(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_WYSIWYG)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_WYSIWYG(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_WYSIWYG):RESETBITS(m_pParent->m_dwFlags_Font,CF_WYSIWYG));
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_Value(long *pVal) {
	if (!pVal) return E_POINTER;
    switch (m_pParent->m_lAction) {
        case 1:
            *pVal = m_pParent->m_dwFlags_File;
        break;
        case 2:
            *pVal = m_pParent->m_dwFlags_Color;
        break;
        case 3:
            *pVal = m_pParent->m_dwFlags_Font;
        break;
        default:
            *pVal = m_pParent->m_dwFlags_Color | m_pParent->m_dwFlags_File | m_pParent->m_dwFlags_Font;
    }
    
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::put_Value(long newVal) {
    switch (m_pParent->m_lAction) {
        case 1:
            m_pParent->m_dwFlags_File = newVal;
        break;
        case 2:
            m_pParent->m_dwFlags_Color = newVal | CC_RGBINIT;
        break;
        case 3:
            m_pParent->m_dwFlags_Font = newVal | CF_INITTOLOGFONTSTRUCT;
        break;
        default:
	        m_pParent->m_dwFlags_Color = newVal;
            m_pParent->m_dwFlags_File = newVal;
            m_pParent->m_dwFlags_Font = newVal;
    }
	return S_OK;
}

STDMETHODIMP CNSComDlgFlags::SetDefaults() {
    #ifdef _WIN32_WCE
        m_pParent->m_dwFlags_File = 0;
    #else
        m_pParent->m_dwFlags_File = OFN_ENABLESIZING | OFN_EXPLORER | OFN_LONGNAMES;
    #endif
    m_pParent->m_dwFlags_Color = CC_ANYCOLOR | CC_RGBINIT;
    m_pParent->m_dwFlags_Font = CF_INITTOLOGFONTSTRUCT | CF_BOTH;
    return S_OK;
}

STDMETHODIMP CNSComDlgFlags::get_PrinterFonts(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_pParent->m_dwFlags_Font & CF_PRINTERFONTS)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CNSComDlgFlags::put_PrinterFonts(VARIANT_BOOL newVal) {
	m_pParent->m_dwFlags_Font = (DWORD)((newVal)?SETBITS(m_pParent->m_dwFlags_Font,CF_PRINTERFONTS):RESETBITS(m_pParent->m_dwFlags_Font,CF_PRINTERFONTS));
	return S_OK;
}

