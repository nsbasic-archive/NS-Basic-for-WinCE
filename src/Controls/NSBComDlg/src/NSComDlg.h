// NSComDlg.h : Declaration of the CNSComDlg

#ifndef __NSCOMDLG_H_
#define __NSCOMDLG_H_

#include "resource.h"       // main symbols
#include <atlctl.h>

class CNSComDlg;
typedef CWinTraits<WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0> CHiddenControlWinTraits;
typedef CComControl<CNSComDlg,CWindowImpl<CNSComDlg,CWindow,CHiddenControlWinTraits> >  CHiddenCtl;

/////////////////////////////////////////////////////////////////////////////
// CNSComDlg
class ATL_NO_VTABLE CNSComDlg : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<INSComDlg, &IID_INSComDlg, &LIBID_DESKLib>,
	// public CComControl<CNSComDlg,CHiddenCtl >,
    public CHiddenCtl,
	public IPersistStreamInitImpl<CNSComDlg>,
	public IOleControlImpl<CNSComDlg>,
	public IOleObjectImpl<CNSComDlg>,
	public IOleInPlaceActiveObjectImpl<CNSComDlg>,
	public IViewObjectExImpl<CNSComDlg>,
	public IOleInPlaceObjectWindowlessImpl<CNSComDlg>,
	public ISupportErrorInfo,
	public IPersistStorageImpl<CNSComDlg>,
	public ISpecifyPropertyPagesImpl<CNSComDlg>,
	public IQuickActivateImpl<CNSComDlg>,
	public IDataObjectImpl<CNSComDlg>,
	public IProvideClassInfo2Impl<&CLSID_NSComDlg, NULL, &LIBID_DESKLib>,
	public CComCoClass<CNSComDlg, &CLSID_NSComDlg>,
    public IPersistPropertyBagImpl<CNSComDlg>,
    public IPerPropertyBrowsingImpl<CNSComDlg>
{
public:
	CNSComDlg()	{
        m_bstrFileName = TEXT("");
        m_bstrDialogTitle = TEXT("");
        m_bstrDefaultExt = TEXT("");
        m_bstrInitDir = TEXT("");
        m_bstrFilter = TEXT("All files|*.*");
        m_bstrFontName = TEXT("");
        m_lMin = 8;
        m_lMax = 72;
        m_bFontBold = VARIANT_FALSE;
        m_bFontItalic = VARIANT_FALSE;
        m_bFontStrikeThru = VARIANT_FALSE;
        m_bFontUnderLine = VARIANT_FALSE;
        m_bCancelError = VARIANT_FALSE;
        m_oclrColor = 0;
        m_lFilterIndex = 0;
        m_dblFontSize = 8.0;
        m_bstrFileTitle = TEXT("");
        m_dwFlags_File = 0;
        m_dwFlags_Font = 0;
        m_dwFlags_Color = 0;
        m_lCharset = DEFAULT_CHARSET;
        m_lAction = 0;
        m_hIcon = NULL;
        int i;
        for (i =0; i < 16;i++) {
            m_clrColors[i] = RGB(255,255,255);
        }
        m_lHelpCommand = 0x1;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSCOMDLG)

DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct();
void    FinalRelease();

BEGIN_COM_MAP(CNSComDlg)
	COM_INTERFACE_ENTRY(INSComDlg)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
    COM_INTERFACE_ENTRY(IPersistPropertyBag)
END_COM_MAP()

BEGIN_PROP_MAP(CNSComDlg)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
    PROP_ENTRY("CancelError", 15, CLSID_NULL)
    PROP_ENTRY("FileName", 1, CLSID_NULL)
    PROP_ENTRY("DialogTitle", 2, CLSID_NULL)
    PROP_ENTRY("Filter", 3, CLSID_NULL)
    PROP_ENTRY("DefaultExt", 4, CLSID_NULL)
    PROP_ENTRY("InitDir", 5, CLSID_NULL)
    PROP_ENTRY("Color", 6, CLSID_NULL)
    PROP_ENTRY("FontName", 8, CLSID_NULL)
    PROP_ENTRY("FontBold", 9, CLSID_NULL)
    PROP_ENTRY("FontItalic", 10, CLSID_NULL)
    PROP_ENTRY("FontStrikeThru", 11, CLSID_NULL)
    PROP_ENTRY("FontUnderLine", 12, CLSID_NULL)
    PROP_ENTRY("Min", 13, CLSID_NULL)
    PROP_ENTRY("Max", 14, CLSID_NULL)
    PROP_ENTRY("FilterIndex", 16, CLSID_NULL)
    PROP_ENTRY("FontSize", 17, CLSID_NULL)
    PROP_ENTRY("FileTitle", 18, CLSID_NULL)
    PROP_ENTRY("Charset", 23, CLSID_NULL)
    PROP_ENTRY("Action", 24, CLSID_NULL)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CNSComDlg)
	// CHAIN_MSG_MAP(CComControl<CNSComDlg>)
    CHAIN_MSG_MAP(CHiddenCtl)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// DATA VARIABLES
ccBSTR          m_bstrFileName;
ccBSTR          m_bstrDialogTitle;
ccBSTR          m_bstrDefaultExt;
ccBSTR          m_bstrInitDir;
ccBSTR          m_bstrFilter;
ccBSTR          m_bstrFontName;
LONG            m_lMin;
LONG            m_lMax;
VARIANT_BOOL    m_bFontBold;
VARIANT_BOOL    m_bFontItalic;
VARIANT_BOOL    m_bFontStrikeThru;
VARIANT_BOOL    m_bFontUnderLine;
VARIANT_BOOL    m_bCancelError;
OLE_COLOR       m_oclrColor;
LONG            m_lFilterIndex;
double          m_dblFontSize;
ccBSTR          m_bstrFileTitle;
DWORD           m_dwFlags_File;
DWORD           m_dwFlags_Font;
DWORD           m_dwFlags_Color;
LONG            m_lCharset;
LONG            m_lAction;
HICON           m_hIcon;
COLORREF        m_clrColors[16];

ccBSTR          m_bstrHelpFile;
ccVariant       m_vHelpContext;
long            m_lHelpCommand;
ccBSTR          m_bstrHelpKey;


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_INSComDlg,
		};
		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
    DECLARE_VIEW_STATUS(VIEWSTATUS_DVASPECTTRANSPARENT)

// INSComDlg
public:
	STDMETHOD(ShowHelp)();
	STDMETHOD(get_HelpKey)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_HelpKey)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_HelpContext)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_HelpContext)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_HelpCommand)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_HelpCommand)(/*[in]*/ long newVal);
	STDMETHOD(get_HelpFile)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_HelpFile)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_IsPocketPC)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_CustomColors)(/*[in]*/ long index, /*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_CustomColors)(/*[in]*/ long index, /*[in]*/ OLE_COLOR newVal);
	STDMETHOD(Reset)(/*[in,optional]*/ VARIANT vAction);
	STDMETHOD(get_FileNames)(/*[out, retval]*/ IComDlgMiniEnum **pVal);
	STDMETHOD(get_Action)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Action)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_Charset)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Charset)(/*[in]*/ long newVal);
	STDMETHOD(ShowFont)(/*[out,retval]*/ VARIANT_BOOL* pbResult);
	STDMETHOD(ShowColor)(/*[out,retval]*/ VARIANT_BOOL* pbResult);
	STDMETHOD(ShowSave)(/*[out,retval]*/ VARIANT_BOOL* pbResult);
	STDMETHOD(ShowOpen)(/*[out,retval]*/ VARIANT_BOOL* pbResult);
	STDMETHOD(get_FileTitle)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FileTitle)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_FontSize)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_FontSize)(/*[in]*/ double newVal);
	STDMETHOD(get_FilterIndex)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FilterIndex)(/*[in]*/ long newVal);
	STDMETHOD(get_CancelError)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CancelError)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Max)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Max)(/*[in]*/ long newVal);
	STDMETHOD(get_Min)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Min)(/*[in]*/ long newVal);
	STDMETHOD(get_FontUnderLine)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontUnderLine)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontStrikeThru)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontStrikeThru)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontItalic)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontItalic)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontBold)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontBold)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FontName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Flags)(/*[out, retval]*/ INSComDlgFlags **pVal);
	STDMETHOD(get_Color)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_Color)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_InitDir)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_InitDir)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_DefaultExt)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_DefaultExt)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Filter)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Filter)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_DialogTitle)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_DialogTitle)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_FileName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FileName)(/*[in]*/ BSTR newVal);

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;

        //if (di.dwDrawAspect & (DVASPECT_ICON | DVASPECT_THUMBNAIL) || TRUE) {
            if (!m_bUIActive) ::DrawIcon(di.hdcDraw,rc.left, rc.top,m_hIcon);
            /*
		    Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

		    SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		    LPCTSTR pszText = _T("ATL 3.0 : NSComDlg");
		    TextOut(di.hdcDraw, 
			    (rc.left + rc.right) / 2, 
			    (rc.top + rc.bottom) / 2, 
			    pszText, 
			    lstrlen(pszText));
            */
        // }

		return S_OK;
	}
};

#endif //__NSCOMDLG_H_
