// NSComDlg.cpp : Implementation of CNSComDlg

#include "stdafx.h"
#include "Desk.h"
#include "NSComDlg.h"
#include "NSComDlgFlags.h"
#include "ComDlgMiniEnum.h"

#ifdef _WIN32_WCE
    #pragma comment(lib, "commdlg.lib")
#else
    #pragma comment(lib, "comdlg32.lib")
#endif

// #include <Cderr.h>

/////////////////////////////////////////////////////////////////////////////
// CNSComDlg

HRESULT CNSComDlg::FinalConstruct() {
    m_hIcon = ::LoadIcon(_Module.m_hInstResource,MAKEINTRESOURCE(IDI_ICON1));
    return S_OK;
}
void    CNSComDlg::FinalRelease() {
    
}


STDMETHODIMP CNSComDlg::get_FileName(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrFileName.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_FileName(BSTR newVal) {
	m_bstrFileName = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_DialogTitle(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrDialogTitle.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_DialogTitle(BSTR newVal) {
	m_bstrDialogTitle = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Filter(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrFilter.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_Filter(BSTR newVal) {
	m_bstrFilter = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_DefaultExt(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrDefaultExt.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_DefaultExt(BSTR newVal) {
	m_bstrDefaultExt = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_InitDir(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrInitDir.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_InitDir(BSTR newVal) {
	m_bstrInitDir = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Color(OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_oclrColor;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_Color(OLE_COLOR newVal) {
	m_oclrColor = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Flags(INSComDlgFlags **pVal) {
	if (!pVal) return E_POINTER;
    CComObject<CNSComDlgFlags>*     pFlags = NULL;
    HRESULT hr = CComObject<CNSComDlgFlags>::CreateInstance(&pFlags);
    if (FAILED(hr)) return hr;

    hr = pFlags->QueryInterface(IID_INSComDlgFlags,(void**)pVal);
    if (FAILED(hr)) {
        delete pFlags;
        return hr;
    }

    pFlags->m_pParent = this;
    hr = QueryInterface(IID_IUnknown,(void**)&pFlags->m_spParent);
    if (FAILED(hr)) {
        (*pVal)->Release();
        *pVal = NULL;
        return hr;
    }

	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FontName(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrFontName.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_FontName(BSTR newVal) {
	m_bstrFontName = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FontBold(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bFontBold;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_FontBold(VARIANT_BOOL newVal) {
	m_bFontBold = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FontItalic(VARIANT_BOOL *pVal) {
    if (!pVal) return E_POINTER;
    *pVal = m_bFontItalic;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_FontItalic(VARIANT_BOOL newVal) {
	m_bFontItalic = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FontStrikeThru(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bFontStrikeThru;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_FontStrikeThru(VARIANT_BOOL newVal) {
	m_bFontStrikeThru = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FontUnderLine(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bFontUnderLine;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_FontUnderLine(VARIANT_BOOL newVal) {
	m_bFontUnderLine = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Min(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lMin;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_Min(long newVal) {
	m_lMin = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Max(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lMax;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_Max(long newVal) {
	m_lMax = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_CancelError(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bCancelError;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_CancelError(VARIANT_BOOL newVal) {
	m_bCancelError = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FilterIndex(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lFilterIndex;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_FilterIndex(long newVal) {
	m_lFilterIndex = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FontSize(double *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_dblFontSize;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_FontSize(double newVal) {
	m_dblFontSize = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FileTitle(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    return m_bstrFileTitle.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_FileTitle(BSTR newVal) {
	m_bstrFileTitle = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::ShowOpen(VARIANT_BOOL *pbResult) {
	OPENFILENAME    ofn;
    HRESULT         hr;
    ZeroMemory(&ofn,sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);

    ccBSTR  bstrFilter = m_bstrFilter;
    hr = bstrFilter.Append(TEXT("|"));
    if (FAILED(hr)) return hr;
    ULONG   i,len = bstrFilter.Length();
    for (i = 0; i < len; i++) {
        if (bstrFilter.m_str[i] == TEXT('|')) {
            bstrFilter.m_str[i] = TEXT('\0');
        }
    }

    ccBSTR  bstrFileName;
    if (m_dwFlags_File & OFN_ALLOWMULTISELECT) {
        if (!bstrFileName.Alloc(0x8000,m_bstrFileName)) return E_OUTOFMEMORY;
        ofn.nMaxFile = 0x8000;
        len = bstrFileName.Length();
        if (len > 0) {
            for (i = 0;i < len;i++) {
                if (bstrFileName.m_str[i] == TEXT('|')) {
                    bstrFileName.m_str[i] = TEXT('\0');
                    break;
                }
            }
        }
    } else {
        if (!bstrFileName.Alloc(0x1000,m_bstrFileName)) return E_OUTOFMEMORY;
        ofn.nMaxFile = 0x1000;
    }

    ccBSTR  bstrFileTitle;
    if (!bstrFileTitle.Alloc(0x1000)) return E_OUTOFMEMORY;

    ofn.hwndOwner = NULL;
    if (IsWindow()) {
        ofn.hwndOwner = m_hWnd;
    } else {
        if (m_spClientSite) {
            CComPtr<IOleWindow> spWnd;
            hr = m_spClientSite->QueryInterface(IID_IOleWindow,(void**)&spWnd);
            if (!FAILED(hr)) {
                HWND    hWnd = NULL;
                hr = spWnd->GetWindow(&hWnd);
                if (!FAILED(hr)) {
                    ofn.hwndOwner = hWnd;
                }
            }
        }
    }
    



    ofn.lpstrFilter = (LPTSTR)(BSTR)bstrFilter;
    if (m_bstrFilter.Length()) ofn.nFilterIndex = 1;
    ofn.lpstrFile = (LPTSTR)(BSTR)bstrFileName;
    ofn.lpstrFileTitle = (LPTSTR)(BSTR)bstrFileTitle;
    ofn.nMaxFileTitle = 0x1000;
    ofn.lpstrInitialDir = (LPTSTR)(BSTR)m_bstrInitDir;
    ofn.lpstrTitle = (LPTSTR)(BSTR)((m_bstrDialogTitle.Length())?m_bstrDialogTitle:NULL);
    ofn.Flags = m_dwFlags_File;
    ofn.lpstrDefExt = (LPTSTR)(BSTR)m_bstrDefaultExt;

    if (!::GetOpenFileName(&ofn)) {
        if (m_bCancelError) return REPORT_RESERROR(IDS_E_OFNCANCEL,IID_INSComDlg);
        if (pbResult) *pbResult = VARIANT_FALSE;
        return S_FALSE;
    }
    if (pbResult) *pbResult = VARIANT_TRUE;

    // Transfer the information
    if (ofn.Flags & OFN_ALLOWMULTISELECT) {
        if (ofn.nFileOffset > 0) {
            if (!m_bstrInitDir.Alloc(ofn.nFileOffset,(LPCOLESTR)ofn.lpstrFile)) return E_OUTOFMEMORY;
            m_bstrInitDir.Compact();
            bstrFileName.m_str[ofn.nFileOffset-1] = TEXT('|');
            for (i = ofn.nFileOffset;;i++) {
                if (!bstrFileName.m_str[i]) {
                    bstrFileName.m_str[i] = TEXT('|');
                } else {
                    continue;
                }
                if (!bstrFileName.m_str[i+1]) {
                    bstrFileName.m_str[i] = TEXT('\0');
                    break;
                }
            }
            hr = bstrFileName.Compact();
            if (FAILED(hr)) return hr;
        } else {
            //////
        }
    } else {
        if (!m_bstrInitDir.Alloc(ofn.nFileOffset,ofn.lpstrFile)) return E_OUTOFMEMORY;
        hr = m_bstrInitDir.Compact();
        if (FAILED(hr)) return hr;
    }
    hr = bstrFileTitle.Compact();
    if (FAILED(hr)) return hr;
    m_bstrFileTitle = bstrFileTitle.CompactPtr();
    m_bstrFileName = bstrFileName.CompactPtr();
    m_lFilterIndex = (LONG)ofn.nFilterIndex;
    m_dwFlags_File = ofn.Flags;

	return S_OK;
}

STDMETHODIMP CNSComDlg::ShowSave(VARIANT_BOOL *pbResult) {
	OPENFILENAME    ofn;
    HRESULT         hr;
    ZeroMemory(&ofn,sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);

    ccBSTR  bstrFilter = m_bstrFilter;
    hr = bstrFilter.Append(TEXT("|"));
    if (FAILED(hr)) return hr;
    ULONG   i,len = bstrFilter.Length();
    for (i = 0; i < len; i++) {
        if (bstrFilter.m_str[i] == TEXT('|')) {
            bstrFilter.m_str[i] = TEXT('\0');
        }
    }

    ccBSTR  bstrFileName;
    
    if (!bstrFileName.Alloc(0x1000,m_bstrFileName)) return E_OUTOFMEMORY;
    ofn.nMaxFile = 0x1000;

    ccBSTR  bstrFileTitle;
    if (!bstrFileTitle.Alloc(0x1000)) return E_OUTOFMEMORY;

    ofn.hwndOwner = NULL;
    if (IsWindow()) {
        ofn.hwndOwner = m_hWnd;
    } else {
        if (m_spClientSite) {
            CComPtr<IOleWindow> spWnd;
            hr = m_spClientSite->QueryInterface(IID_IOleWindow,(void**)&spWnd);
            if (!FAILED(hr)) {
                HWND    hWnd = NULL;
                hr = spWnd->GetWindow(&hWnd);
                if (!FAILED(hr)) {
                    ofn.hwndOwner = hWnd;
                }
            }
        }
    }


    ofn.lpstrFilter = (LPTSTR)(BSTR)bstrFilter;
    if (m_bstrFilter.Length()) ofn.nFilterIndex = 1;
    ofn.lpstrFile = (LPTSTR)(BSTR)bstrFileName;
    ofn.lpstrFileTitle = (LPTSTR)(BSTR)bstrFileTitle;
    ofn.nMaxFileTitle = 0x1000;
    ofn.lpstrInitialDir = (LPTSTR)(BSTR)m_bstrInitDir;
    ofn.lpstrTitle = (LPTSTR)(BSTR)((m_bstrDialogTitle.Length())?m_bstrDialogTitle:NULL);
    ofn.Flags = RESETBITS(m_dwFlags_File,OFN_ALLOWMULTISELECT);
    ofn.lpstrDefExt = (LPTSTR)(BSTR)m_bstrDefaultExt;

    if (!::GetSaveFileName(&ofn)) {
        // DWORD dw = CommDlgExtendedError(); // <cderr.h>
        if (m_bCancelError) return REPORT_RESERROR(IDS_E_OFNCANCEL,IID_INSComDlg);
        if (pbResult) *pbResult = VARIANT_FALSE;
        return S_FALSE;
    }
    if (pbResult) *pbResult = VARIANT_TRUE;

    // Transfer the information

    if (!m_bstrInitDir.Alloc(ofn.nFileOffset,ofn.lpstrFile)) return E_OUTOFMEMORY;
    hr = m_bstrInitDir.Compact();
    if (FAILED(hr)) return hr;
    
    hr = bstrFileName.Compact();
    if (FAILED(hr)) return hr;

    m_bstrFileName = bstrFileName;
    m_bstrFileTitle = ofn.lpstrFileTitle;

    m_lFilterIndex = (LONG)ofn.nFilterIndex;
    m_dwFlags_File = ofn.Flags;

	return S_OK;
}



STDMETHODIMP CNSComDlg::ShowColor(VARIANT_BOOL *pbResult) {
    CHOOSECOLOR_SC cc;
    HRESULT     hr;
    ZeroMemory(&cc,sizeof(CHOOSECOLOR_SC));

    cc.lStructSize = sizeof(CHOOSECOLOR_SC);
    cc.rgbResult = m_oclrColor;
    cc.lpCustColors = m_clrColors;
    cc.Flags = m_dwFlags_Color;

    cc.hwndOwner = NULL;
    if (IsWindow()) {
        cc.hwndOwner = m_hWnd;
    } else {
        if (m_spClientSite) {
            CComPtr<IOleWindow> spWnd;
            hr = m_spClientSite->QueryInterface(IID_IOleWindow,(void**)&spWnd);
            if (!FAILED(hr)) {
                HWND    hWnd = NULL;
                hr = spWnd->GetWindow(&hWnd);
                if (!FAILED(hr)) {
                    cc.hwndOwner = hWnd;
                }
            }
        }
    }


    if (!ChooseColor_SC(&cc)) {
        if (m_bCancelError) return REPORT_RESERROR(IDS_E_CCCANCEL,IID_INSComDlg);
        if (pbResult) *pbResult = VARIANT_FALSE;
        return S_FALSE;
    }
    if (pbResult) *pbResult = VARIANT_TRUE;
    m_oclrColor = cc.rgbResult;
    m_dwFlags_Color = cc.Flags;

	return S_OK;
}

#define __XABS(x) ( ((x) >= 0)?(x):-(x) )
#define __XCEIL(x) ( ( (long)((x) + 0.5) > (long)(x) )?(long)((x) + 0.5):(long)(x) )

STDMETHODIMP CNSComDlg::ShowFont(VARIANT_BOOL *pbResult) {
	LOGFONT     lf;
    CHOOSEFONT_SC  cf;
    HRESULT     hr;

    ZeroMemory(&lf,sizeof(LOGFONT));
    ZeroMemory(&cf,sizeof(CHOOSEFONT_SC));

    cf.lStructSize = sizeof(CHOOSEFONT_SC);

    // Transfer data - first to LOGFONT
    lf.lfCharSet = (BYTE)m_lCharset;
    HDC hDC = GetDC();
    lf.lfHeight = - __XCEIL( ( ( __XABS(m_dblFontSize) * (double)GetDeviceCaps(hDC, LOGPIXELSY) ) / (double)72.0) );

    
    lf.lfWeight = m_bFontBold?700:400;
    lf.lfItalic = (BYTE)m_bFontItalic;
    lf.lfUnderline = (BYTE)m_bFontUnderLine;
    lf.lfStrikeOut = (BYTE)m_bFontStrikeThru;
    lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
    lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    lf.lfQuality = DEFAULT_QUALITY;
    lf.lfPitchAndFamily = FF_DONTCARE;
    if (m_bstrFontName.Length() > 0) {
        m_bstrFontName.CopyToBuff(lf.lfFaceName,LF_FACESIZE-1);
    }

    // Transfer data - to CHOOSEFONT now
    cf.hwndOwner = NULL;
    if (IsWindow()) {
        cf.hwndOwner = m_hWnd;
    } else {
        if (m_spClientSite) {
            CComPtr<IOleWindow> spWnd;
            hr = m_spClientSite->QueryInterface(IID_IOleWindow,(void**)&spWnd);
            if (!FAILED(hr)) {
                HWND    hWnd = NULL;
                hr = spWnd->GetWindow(&hWnd);
                if (!FAILED(hr)) {
                    cf.hwndOwner = hWnd;
                }
            }
        }
    }
    cf.hDC = hDC;
    cf.lpLogFont = &lf;
    cf.iPointSize = (INT)(m_dblFontSize * 10);
    cf.Flags = m_dwFlags_Font;
    cf.rgbColors = m_oclrColor;
    cf.nSizeMin = (INT)m_lMin;
    cf.nSizeMax = (INT)m_lMax;

    if (!ChooseFont_SC(&cf)) {
        //DWORD dw = CommDlgExtendedError(); // <cderr.h>
        if (m_bCancelError) {
            ReleaseDC(hDC);
            return REPORT_RESERROR(IDS_E_CFCANCEL,IID_INSComDlg);
        }
        if (pbResult) *pbResult = VARIANT_FALSE;
        ReleaseDC(hDC);
        return S_FALSE;
    }
    if (pbResult) *pbResult = VARIANT_TRUE;

    // Transfer the information back
    m_lCharset = lf.lfCharSet;
    m_bFontBold = (lf.lfWeight >= FW_BOLD)?VARIANT_TRUE:VARIANT_FALSE;
    m_bFontItalic = (VARIANT_BOOL)lf.lfItalic;
    m_bFontStrikeThru = (VARIANT_BOOL)lf.lfStrikeOut;
    m_bFontUnderLine = (VARIANT_BOOL)lf.lfUnderline;
    m_bstrFontName = lf.lfFaceName;
    m_dblFontSize = ((double)__XABS(cf.iPointSize) / 10.0);
    // hDC = GetDC();
    // m_dblFontSize = (((double)__XABS(lf.lfHeight)) * 72.0) / (double)GetDeviceCaps(hDC, LOGPIXELSY);
    // ReleaseDC(hDC);
    m_oclrColor = cf.rgbColors;
    ReleaseDC(hDC);
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Charset(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lCharset;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_Charset(long newVal) {
	m_lCharset = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_Action(VARIANT *pVal) {
	if (!pVal) return E_POINTER;
    ccVariant   v;
    v = m_lAction;
    return v.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_Action(VARIANT newVal) {
	ccVariant   v;
    HRESULT hr = v.ToValue(&newVal);
    if (FAILED(hr)) return hr;
    if (v.vt == VT_BSTR) {
        if (_tcsicmp(v.bstrVal,TEXT("File")) == 0) {
            m_lAction = 1;
        } else if (_tcsicmp(v.bstrVal,TEXT("Color")) == 0) {
            m_lAction = 2;
        } else if (_tcsicmp(v.bstrVal,TEXT("Font")) == 0) {
            m_lAction = 3;
        } else {
            return DISP_E_TYPEMISMATCH;
        }
    } else {
        hr = v.ChangeType(VT_I4);
        if (FAILED(hr)) return hr;
        m_lAction = v.lVal;
    }

	return S_OK;
}

STDMETHODIMP CNSComDlg::get_FileNames(IComDlgMiniEnum **pVal) {
    if (!pVal) return E_POINTER;

	CComObject<CComDlgMiniEnum>*  penum = NULL;
    HRESULT hr = CComObject<CComDlgMiniEnum>::CreateInstance(&penum);
    if (FAILED(hr)) return hr;

    hr = penum->QueryInterface(IID_IComDlgMiniEnum,(void**)pVal);
    if (FAILED(hr)) {
        delete penum;
        return hr;
    }

    ccBSTR      bstr;
    ccVariant   v;
    ULONG i,len = m_bstrFileName.Length();
    if (!len) return S_OK;

    BSTR bstrStart = m_bstrFileName.m_str;

    for (i = 0;i < len + 1;i++) {
        if (m_bstrFileName.m_str[i] == L'|' || m_bstrFileName.m_str[i] == L'\0' || i == len) {
            
            bstr.Empty();
            v.Clear();
            hr = bstr.Append(bstrStart,(&m_bstrFileName.m_str[i] - bstrStart));
            if (FAILED(hr)) return hr;

            v = bstr;
            if (bstrStart != m_bstrFileName.m_str) {
                if (!penum->arrItems.Add(v)) return E_OUTOFMEMORY;
            }

            bstrStart = &m_bstrFileName.m_str[i+1];
        }
    }
	return S_OK;
}

STDMETHODIMP CNSComDlg::Reset(VARIANT vAction) {
	ccVariant v;
    HRESULT hr = ::VariantCopyInd(&v,&vAction);
    if (FAILED(hr)) return hr;

    if (!v.IsOmitted()) {
        if (v.vt == VT_BSTR) {
            if (_tcsicmp(v.bstrVal,TEXT("File")) == 0) {
                m_lAction = 1;
            } else if (_tcsicmp(v.bstrVal,TEXT("Color")) == 0) {
                m_lAction = 2;
            } else if (_tcsicmp(v.bstrVal,TEXT("Font")) == 0) {
                m_lAction = 3;
            } else {
                return DISP_E_TYPEMISMATCH;
            }
        } else {
            hr = v.ChangeType(VT_I4);
            if (FAILED(hr)) return hr;
            m_lAction = v.lVal;
        }
    }
    switch (m_lAction) {
        case 1: //File
            m_bstrFileName = TEXT("");
            m_bstrDialogTitle.Empty();
            m_bstrDefaultExt.Empty();
            m_bstrInitDir = TEXT("");
            m_bstrFilter = TEXT("All files|*.*");
            #ifdef _WIN32_WCE
                m_dwFlags_File = 0;
            #else
                m_dwFlags_File = OFN_ENABLESIZING | OFN_EXPLORER | OFN_LONGNAMES;
            #endif
            m_lFilterIndex = 0;
            m_bstrFileTitle = TEXT("");
        break;
        case 2: // Color
            m_oclrColor = 0;
            m_dwFlags_Color = CC_ANYCOLOR | CC_RGBINIT;
        break;
        case 3: // Font
            m_bstrFontName.Empty();
            m_lMin = 8;
            m_lMax = 72;
            m_bFontBold = VARIANT_FALSE;
            m_bFontItalic = VARIANT_FALSE;
            m_bFontStrikeThru = VARIANT_FALSE;
            m_bFontUnderLine = VARIANT_FALSE;
            m_dblFontSize = 8.0;
            m_lCharset = DEFAULT_CHARSET;
            m_dwFlags_Font = CF_INITTOLOGFONTSTRUCT | CF_BOTH;
        break;
    }
    m_bCancelError = VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CNSComDlg::get_CustomColors(long index, OLE_COLOR *pVal) {
	if (!pVal) return E_POINTER;
    // <winerror.h>
    if (index < 0 || index > 15) return DISP_E_BADINDEX;
    *pVal = m_clrColors[index];
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_CustomColors(long index, OLE_COLOR newVal) {
	if (index < 0 || index > 15) return DISP_E_BADINDEX;
    m_clrColors[index] = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_IsPocketPC(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = VARIANT_FALSE;
    if (WhichPlatform() & WPLATFORM_POCKETPCKIND) *pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_HelpFile(BSTR *pVal) {
	return m_bstrHelpFile.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_HelpFile(BSTR newVal) {
	m_bstrHelpFile = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_HelpCommand(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_lHelpCommand;
	return S_OK;
}

STDMETHODIMP CNSComDlg::put_HelpCommand(long newVal) {
	m_lHelpCommand = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_HelpContext(VARIANT *pVal) {
	return m_vHelpContext.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_HelpContext(VARIANT newVal) {
	m_vHelpContext = newVal;
	return S_OK;
}

STDMETHODIMP CNSComDlg::get_HelpKey(BSTR *pVal) {
	return m_bstrHelpKey.CopyTo(pVal);
}

STDMETHODIMP CNSComDlg::put_HelpKey(BSTR newVal) {
	m_bstrHelpKey = newVal;
	return S_OK;
}
// <winuser.h>
STDMETHODIMP CNSComDlg::ShowHelp() {
    BOOL        b;
    ccVariant   v;
    #ifdef _WIN32_WCE
        // CE
        ccBSTR  bstrHelpFile = L"file:";
        bstrHelpFile.Append(m_bstrHelpFile);
        if (m_lHelpCommand == 0x01) {
            v = m_vHelpContext;
            if (!FAILED(v.ChangeType(VT_BSTR))) {
                bstrHelpFile.Append(L"#");
                bstrHelpFile.Append((BSTR)v);
            }
        }

    	PROCESS_INFORMATION rProcInfo;

	    b = CreateProcess(_T("PegHelp.exe"), (LPWSTR)bstrHelpFile,
		       NULL, NULL, FALSE, 0, NULL, NULL, NULL, &rProcInfo);
        if (!b) return REPORT_RESERROR(IDS_E_HELPERR,IID_INSComDlg);
        return S_OK;
    #else
        // Desktop
        switch (m_lHelpCommand) {
            case HELP_CONTEXT:
            case HELP_CONTEXTPOPUP:
                b = WinHelp(m_bstrHelpFile,m_lHelpCommand,(DWORD)(BSTR)m_vHelpContext);
            break;
            case HELP_QUIT:
            case HELP_INDEX:
            // case HELP_CONTENTS:
            case HELP_HELPONHELP:
            case HELP_FORCEFILE:
                b = WinHelp(m_bstrHelpFile,m_lHelpCommand,0);
            break;
            case HELP_KEY:
            case HELP_PARTIALKEY:
                b = WinHelp(m_bstrHelpFile,m_lHelpCommand,(DWORD)(BSTR)m_bstrHelpKey);
            break;
            default:
                return REPORT_RESERROR(IDS_E_UNSUPPORTEDHELPCMD,IID_INSComDlg);
        }
        if (!b) return REPORT_RESERROR(IDS_E_HELPERR,IID_INSComDlg);
    #endif
	return S_OK;
}
