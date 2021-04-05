// NSFont.cpp : Implementation of CNSFont
#include "stdafx.h"
#include "ComCtl.h"
#include "NSFont.h"

_ATL_FUNC_INFO g_FontEvents[] = {
    {CC_STDCALL,    VT_EMPTY,   0, NULL }
};

/////////////////////////////////////////////////////////////////////////////
// CNSFont

STDMETHODIMP CNSFont::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INSFont
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
// static 
HRESULT CNSFont::CreateNSFont(INSFont** ppObj) {
    CComObject<CNSFont>*    p = NULL;
    HRESULT hr = CComObject<CNSFont>::CreateInstance(&p);
    if (FAILED(hr)) return hr;

    hr = p->QueryInterface(IID_INSFont,(void**)ppObj);
    if (FAILED(hr)) {
        delete p;
    }
    return hr;
}

HRESULT CNSFont::FinalConstruct() {
    HDC hDC = ::GetDC(NULL);
    lf.lfHeight = -(long)( ((double)8 * (double)GetDeviceCaps(hDC, LOGPIXELSY)) / 72.0 ); //  -MulDiv(8, GetDeviceCaps(hDC, LOGPIXELSY), 72);
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
    lf.lfPitchAndFamily = FF_DONTCARE;
    lf.lfQuality = DEFAULT_QUALITY;
    lf.lfWeight = 400;
    ReleaseDC(NULL,hDC);
    return S_OK;
}
void    CNSFont::FinalRelease() {

}

STDMETHODIMP CNSFont::get_Bold(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (lf.lfWeight > 400)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSFont::put_Bold(VARIANT_BOOL newVal) {
	lf.lfWeight = newVal?700:400;
    Fire_OnFontChange();
	return S_OK;
}

STDMETHODIMP CNSFont::get_Italic(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (lf.lfItalic)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSFont::put_Italic(VARIANT_BOOL newVal) {
    lf.lfItalic = (newVal)?(BYTE)TRUE:BYTE(FALSE);
    Fire_OnFontChange();
	return S_OK;
}

STDMETHODIMP CNSFont::get_Name(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    ccBSTR  bstr;
    bstr = lf.lfFaceName;
    return bstr.CopyTo(pVal);
}

STDMETHODIMP CNSFont::put_Name(BSTR newVal) {
	ccBSTR bstr(newVal);
    HRESULT hr = bstr.CopyToBuff(lf.lfFaceName,LF_FACESIZE);
    if (!FAILED(hr)) Fire_OnFontChange();
    return hr;
}

STDMETHODIMP CNSFont::get_Underline(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (lf.lfUnderline)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSFont::put_Underline(VARIANT_BOOL newVal) {
	lf.lfUnderline = (BYTE)newVal;
    Fire_OnFontChange();
	return S_OK;
}

STDMETHODIMP CNSFont::get_Strikethru(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (lf.lfStrikeOut)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CNSFont::put_Strikethru(VARIANT_BOOL newVal) {
	lf.lfStrikeOut = (BYTE)newVal;
    Fire_OnFontChange();
	return S_OK;
}

STDMETHODIMP CNSFont::get_Charset(short *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (short)(WORD)lf.lfCharSet;
	return S_OK;
}

STDMETHODIMP CNSFont::put_Charset(short newVal) {
	lf.lfCharSet = (BYTE)newVal;
    Fire_OnFontChange();
	return S_OK;
}

STDMETHODIMP CNSFont::get_Size(double *pVal) {
	if (!pVal) return E_POINTER;
    HDC hDC = ::GetDC(NULL);
    *pVal = -((double)lf.lfHeight * 72.0) / (double)GetDeviceCaps(hDC, LOGPIXELSY);
    ReleaseDC(NULL,hDC);
	return S_OK;
}

STDMETHODIMP CNSFont::put_Size(double newVal) {
    HDC hDC = ::GetDC(NULL);
	lf.lfHeight = - (long)((newVal * (double)GetDeviceCaps(hDC, LOGPIXELSY)) / 72.0);
    ReleaseDC(NULL,hDC);
    Fire_OnFontChange();
	return S_OK;
}

STDMETHODIMP CNSFont::get_hFont(OLE_HANDLE *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (OLE_HANDLE)CreateFontIndirect(&lf);
    if (*pVal) return S_OK;
	return E_FAIL;
}
