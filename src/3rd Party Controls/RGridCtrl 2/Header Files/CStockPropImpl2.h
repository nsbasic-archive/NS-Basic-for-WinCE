#ifndef __CSTOCKPROPIMPL2_H__
#define __CSTOCKPROPIMPL2_H__


#pragma pack(push, _ATL_PACKING)


template < class T, class InterfaceName, const IID* piid, const GUID* plibid, WORD wMajor = 1, WORD wMinor = 0>
class ATL_NO_VTABLE CStockPropImpl2 : public IDispatchImpl< InterfaceName, piid, plibid, wMajor, wMinor >
{
public:
	// Font
	HRESULT STDMETHODCALLTYPE put_Font(IFontDisp* pFont)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::put_Font\n"));
		T* pT = (T*) this;
		if (pT->FireOnRequestEdit(DISPID_FONT) == S_FALSE)
			return S_FALSE;
		pT->m_pFont = 0;
		if (pFont)
		{
			CComQIPtr<IFont, &IID_IFont> p(pFont);
			if (p)
			{
				CComPtr<IFont> pFont;
				p->Clone(&pFont);
				if (pFont)
					pFont->QueryInterface(IID_IFontDisp, (void**) &pT->m_pFont);
			}
		}
		pT->m_bRequiresSave = TRUE;
		pT->FireOnChanged(DISPID_FONT);
		pT->FireViewChange();
		pT->SendOnDataChange(NULL);
		return S_OK;
	}
	HRESULT STDMETHODCALLTYPE putref_Font(IFontDisp* pFont)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::putref_Font\n"));
		T* pT = (T*) this;
		if (pT->FireOnRequestEdit(DISPID_FONT) == S_FALSE)
			return S_FALSE;
		pT->m_pFont = pFont;
		pT->m_bRequiresSave = TRUE;
		pT->FireOnChanged(DISPID_FONT);
		pT->FireViewChange();
		pT->SendOnDataChange(NULL);
		return S_OK;
	}
	HRESULT STDMETHODCALLTYPE get_Font(IFontDisp** ppFont)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::get_Font\n"));
		T* pT = (T*) this;
		*ppFont = pT->m_pFont;
		if (*ppFont != NULL)
			(*ppFont)->AddRef();
		return S_OK;
	}
	// Picture
	HRESULT STDMETHODCALLTYPE put_Picture(IPictureDisp* pPicture)
	{
#if defined(_WIN32_WCE)
// WinCE: No OleLoadPicture
		RETAILMSG(1, (TEXT("CStockPropImpl2::put_Picture: Not implemented\r\n")));
		return E_NOTIMPL;
#else
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::put_Picture\n"));
		T* pT = (T*) this;
		if (pT->FireOnRequestEdit(DISPID_PICTURE) == S_FALSE)
			return S_FALSE;
		pT->m_pPicture = 0;
		if (pPicture)
		{
			CComQIPtr<IPersistStream, &IID_IPersistStream> p(pPicture);
			if (p)
			{
				ULARGE_INTEGER l;
				p->GetSizeMax(&l);
				HGLOBAL hGlob = GlobalAlloc(GHND, l.LowPart);
				if (hGlob)
				{
					CComPtr<IStream> spStream;
					CreateStreamOnHGlobal(hGlob, TRUE, &spStream);
					if (spStream)
					{
						if (SUCCEEDED(p->Save(spStream, FALSE)))
						{
							LARGE_INTEGER l;
							l.QuadPart = 0;
							spStream->Seek(l, STREAM_SEEK_SET, NULL);
							OleLoadPicture(spStream, l.LowPart, FALSE, IID_IPictureDisp, (void**)&pT->m_pPicture);
						}
						spStream.Release();
					}
					GlobalFree(hGlob);
				}
			}
		}
		pT->m_bRequiresSave = TRUE;
		pT->FireOnChanged(DISPID_PICTURE);
		pT->FireViewChange();
		pT->SendOnDataChange(NULL);
		return S_OK;
#endif // _WIN32_WCE
	}
	HRESULT STDMETHODCALLTYPE putref_Picture(IPictureDisp* pPicture)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::putref_Picture\n"));
		T* pT = (T*) this;
		if (pT->FireOnRequestEdit(DISPID_PICTURE) == S_FALSE)
			return S_FALSE;
		pT->m_pPicture = pPicture;
		pT->m_bRequiresSave = TRUE;
		pT->FireOnChanged(DISPID_PICTURE);
		pT->FireViewChange();
		pT->SendOnDataChange(NULL);
		return S_OK;
	}
	HRESULT STDMETHODCALLTYPE get_Picture(IPictureDisp** ppPicture)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::get_Picture\n"));
		T* pT = (T*) this;
		*ppPicture = pT->m_pPicture;
		if (*ppPicture != NULL)
			(*ppPicture)->AddRef();
		return S_OK;
	}
	// MouseIcon
	HRESULT STDMETHODCALLTYPE put_MouseIcon(IPictureDisp* pPicture)
	{
#if defined(_WIN32_WCE)
// WinCE: No OleLoadPicture, etc.
		RETAILMSG(1, (TEXT("CStockPropImpl2::put_MouseIcon: Not implemented\r\n")));
		return E_NOTIMPL;
#else // _WIN32_WCE
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::put_MouseIcon\n"));
		T* pT = (T*) this;
		if (pT->FireOnRequestEdit(DISPID_MOUSEICON) == S_FALSE)
			return S_FALSE;
		pT->m_pMouseIcon = 0;
		if (pPicture)
		{
			CComQIPtr<IPersistStream, &IID_IPersistStream> p(pPicture);
			if (p)
			{
				ULARGE_INTEGER l;
				p->GetSizeMax(&l);
				HGLOBAL hGlob = GlobalAlloc(GHND, l.LowPart);
				if (hGlob)
				{
					CComPtr<IStream> spStream;
					CreateStreamOnHGlobal(hGlob, TRUE, &spStream);
					if (spStream)
					{
						if (SUCCEEDED(p->Save(spStream, FALSE)))
						{
							LARGE_INTEGER l;
							l.QuadPart = 0;
							spStream->Seek(l, STREAM_SEEK_SET, NULL);
							OleLoadPicture(spStream, l.LowPart, FALSE, IID_IPictureDisp, (void**)&pT->m_pMouseIcon);
						}
						spStream.Release();
					}
					GlobalFree(hGlob);
				}
			}
		}
		pT->m_bRequiresSave = TRUE;
		pT->FireOnChanged(DISPID_MOUSEICON);
		pT->FireViewChange();
		pT->SendOnDataChange(NULL);
		return S_OK;
#endif //_WIN32_WCE
	}
	HRESULT STDMETHODCALLTYPE putref_MouseIcon(IPictureDisp* pPicture)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::putref_MouseIcon\n"));
		T* pT = (T*) this;
		if (pT->FireOnRequestEdit(DISPID_MOUSEICON) == S_FALSE)
			return S_FALSE;
		pT->m_pMouseIcon = pPicture;
		pT->m_bRequiresSave = TRUE;
		pT->FireOnChanged(DISPID_MOUSEICON);
		pT->FireViewChange();
		pT->SendOnDataChange(NULL);
		return S_OK;
	}
	HRESULT STDMETHODCALLTYPE get_MouseIcon(IPictureDisp** ppPicture)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::get_MouseIcon\n"));
		T* pT = (T*) this;
		*ppPicture = pT->m_pMouseIcon;
		if (*ppPicture != NULL)
			(*ppPicture)->AddRef();
		return S_OK;
	}
	IMPLEMENT_STOCKPROP(OLE_COLOR, BackColor, clrBackColor, DISPID_BACKCOLOR)
	IMPLEMENT_STOCKPROP(OLE_COLOR, BorderColor, clrBorderColor, DISPID_BORDERCOLOR)
	IMPLEMENT_STOCKPROP(OLE_COLOR, FillColor, clrFillColor, DISPID_FILLCOLOR)
	IMPLEMENT_STOCKPROP(OLE_COLOR, ForeColor, clrForeColor, DISPID_FORECOLOR)
	IMPLEMENT_BOOL_STOCKPROP(AutoSize, bAutoSize, DISPID_AUTOSIZE)
	IMPLEMENT_BOOL_STOCKPROP(Valid, bValid, DISPID_VALID)
	IMPLEMENT_BOOL_STOCKPROP(Enabled, bEnabled, DISPID_ENABLED)
	IMPLEMENT_BOOL_STOCKPROP(TabStop, bTabStop, DISPID_TABSTOP)
	IMPLEMENT_BOOL_STOCKPROP(BorderVisible, bBorderVisible, DISPID_BORDERVISIBLE)
	IMPLEMENT_BSTR_STOCKPROP(Text, bstrText, DISPID_TEXT)
	IMPLEMENT_BSTR_STOCKPROP(Caption, bstrCaption, DISPID_CAPTION)
	HRESULT STDMETHODCALLTYPE put_Window(long /*hWnd*/)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::put_Window\n"));
		return E_FAIL;
	}
	HRESULT STDMETHODCALLTYPE get_Window(long* phWnd)
	{
		ATLTRACE2(atlTraceControls,2,_T("CStockPropImpl2::get_Window\n"));
		T* pT = (T*) this;
		*phWnd = (long)pT->m_hWnd;
		return S_OK;
	}
	IMPLEMENT_STOCKPROP(LONG, BackStyle, nBackStyle, DISPID_BACKSTYLE)
	IMPLEMENT_STOCKPROP(LONG, BorderStyle, nBorderStyle, DISPID_BORDERSTYLE)
	IMPLEMENT_STOCKPROP(LONG, BorderWidth, nBorderWidth, DISPID_BORDERWIDTH)
	IMPLEMENT_STOCKPROP(LONG, DrawMode, nDrawMode, DISPID_DRAWMODE)
	IMPLEMENT_STOCKPROP(LONG, DrawStyle, nDrawStyle, DISPID_DRAWSTYLE)
	IMPLEMENT_STOCKPROP(LONG, DrawWidth, nDrawWidth, DISPID_DRAWWIDTH)
	IMPLEMENT_STOCKPROP(LONG, FillStyle, nFillStyle, DISPID_FILLSTYLE)
	IMPLEMENT_STOCKPROP(SHORT, Appearance, nAppearance, DISPID_APPEARANCE)
	IMPLEMENT_STOCKPROP(LONG, MousePointer, nMousePointer, DISPID_MOUSEPOINTER)
	IMPLEMENT_STOCKPROP(LONG, ReadyState, nReadyState, DISPID_READYSTATE)
};


#pragma pack(pop)


#endif // _ATLCTL_IMPL