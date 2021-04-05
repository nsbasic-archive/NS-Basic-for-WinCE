// Grid.h : Declaration of the CGrid

#ifndef __GRID_H_
#define __GRID_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "Cell.h"
#include "RGridCtrlCP.h"
#include "CStockPropImpl2.h"


/////////////////////////////////////////////////////////////////////////////
// CGrid
class ATL_NO_VTABLE CGrid : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl2<CGrid, IGrid, &IID_IGrid, &LIBID_RGRIDCTRLLib, 1, 2>,
	public CComControl<CGrid>,
	public IPersistStreamInitImpl<CGrid>,
	public IOleControlImpl<CGrid>,
	public IOleObjectImpl<CGrid>,
	public IOleInPlaceActiveObjectImpl<CGrid>,
	public IPersistPropertyBagImpl<CGrid>,
	public IViewObjectExImpl<CGrid>,
	public ISupportErrorInfo,
	public IOleInPlaceObjectWindowlessImpl<CGrid>,
	public IConnectionPointContainerImpl<CGrid>,
	public IPersistStorageImpl<CGrid>,
	public ISpecifyPropertyPagesImpl<CGrid>,
	public IQuickActivateImpl<CGrid>,
	public IDataObjectImpl<CGrid>,
	public IProvideClassInfo2Impl<&CLSID_Grid, &DIID__IGridEvents, &LIBID_RGRIDCTRLLib,1, 2>,
	public IPropertyNotifySinkCP<CGrid>,
	public CComCoClass<CGrid, &CLSID_Grid>,
	public CProxy_IGridEvents< CGrid >
{
public:
	CGrid();
	~CGrid();
	
DECLARE_REGISTRY_RESOURCEID(IDR_GRID)
DECLARE_NOT_AGGREGATABLE(CGrid)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CGrid)
	COM_INTERFACE_ENTRY(IGrid)
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
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CGrid)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("Enabled", 1000, CLSID_NULL)
	PROP_ENTRY("Rows", 1, CLSID_NULL)
	PROP_ENTRY("FixedRows", 2, CLSID_NULL)
	PROP_ENTRY("Cols", 3, CLSID_NULL)
	PROP_ENTRY("FixedCols", 4, CLSID_NULL)
	PROP_ENTRY("BackColor", 5, CLSID_NULL)
	PROP_ENTRY("BackColorBkg", 6, CLSID_NULL)
	PROP_ENTRY("BackColorFixed", 7, CLSID_NULL)
	PROP_ENTRY("GridLines", 8, CLSID_NULL)
	PROP_ENTRY("GridLinesFixed", 9, CLSID_NULL)
	PROP_ENTRY("GridColor", 10, CLSID_NULL)
	PROP_ENTRY("GridColorFixed", 11, CLSID_NULL)
	PROP_ENTRY("AllowUserResizing", 12, CLSID_NULL)
	PROP_ENTRY("ScrollBars", 13, CLSID_NULL)
	PROP_ENTRY("BorderStyle", 15, CLSID_NULL)
	PROP_ENTRY("ScrollTrack", 16, CLSID_NULL)
	PROP_ENTRY("ForeColor", 17, CLSID_NULL)
	PROP_ENTRY("ForeColorFixed", 18, CLSID_NULL)
	PROP_ENTRY("ForeColorSel", 19, CLSID_NULL)
	PROP_ENTRY("BackColorSel", 20, CLSID_NULL)
	PROP_ENTRY("RowHeightMin", 21, CLSID_NULL)
	PROP_ENTRY("AllowBigSelection", 43, CLSID_NULL)
	PROP_ENTRY("SelectionMode", 44, CLSID_NULL)
	PROP_ENTRY("GridLineWidth", 45, CLSID_NULL)
	PROP_ENTRY("FontBold", 58, CLSID_NULL)
	PROP_ENTRY("FontItalic", 59, CLSID_NULL)
	PROP_ENTRY("FontName", 56, CLSID_NULL)
	PROP_ENTRY("FontSize", 57, CLSID_NULL)
	PROP_ENTRY("FontStrikeThrough", 62, CLSID_NULL)
	PROP_ENTRY("FontUnderline", 60, CLSID_NULL)
	PROP_ENTRY("FontWidth", 61, CLSID_NULL)
	PROP_ENTRY("FixedFontBold", 63, CLSID_NULL)
	PROP_ENTRY("FixedFontItalic", 64, CLSID_NULL)
	PROP_ENTRY("FixedFontName", 65, CLSID_NULL)
	PROP_ENTRY("FixedFontSize", 66, CLSID_NULL)
	PROP_ENTRY("FixedFontStrikeThrough", 67, CLSID_NULL)
	PROP_ENTRY("FixedFontUnderline", 68, CLSID_NULL)
	PROP_ENTRY("FixedFontWidth", 69, CLSID_NULL)
	PROP_ENTRY("FixedAlignment", 48, CLSID_NULL)
	PROP_ENTRY("WordWrap", 71, CLSID_NULL)
	PROP_ENTRY("HighLight", 72, CLSID_NULL)
	PROP_ENTRY("RegistrationCode", 10000, CLSID_NULL)
	
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CGrid)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__IGridEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CGrid)
	CHAIN_MSG_MAP(CComControl<CGrid>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUP)
	MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
	MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
	MESSAGE_HANDLER(WM_VSCROLL, OnVScroll)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
	MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown)
	MESSAGE_HANDLER(WM_KEYUP, OnKeyUp)
	MESSAGE_HANDLER(WM_SIZE, OnSize)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_IGrid,
		};
		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}


// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IGrid
public:
	STDMETHOD(get_Redraw)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Redraw)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_hWnd)(/*[out, retval]*/ OLE_HANDLE *pVal);
	STDMETHOD(get_HighLight)(/*[out, retval]*/ RHighlightConstants *pVal);
	STDMETHOD(put_HighLight)(/*[in]*/ RHighlightConstants newVal);
	STDMETHOD(get_WordWrap)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_WordWrap)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_RegistrationCode)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_RegistrationCode)(/*[in]*/ BSTR newVal);
	STDMETHOD(CellLoadPicture)(/*[in]*/ BSTR FileName);
	STDMETHOD(get_CellPictureAlignment)(/*[out, retval]*/ AlignmentSettings *pVal);
	STDMETHOD(put_CellPictureAlignment)(/*[in]*/ AlignmentSettings newVal);
	STDMETHOD(get_FixedFontWidth)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FixedFontWidth)(/*[in]*/ long newVal);
	STDMETHOD(get_FixedFontUnderline)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FixedFontUnderline)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FixedFontStrikeThrough)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FixedFontStrikeThrough)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FixedFontSize)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FixedFontSize)(/*[in]*/ long newVal);
	STDMETHOD(get_FixedFontName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FixedFontName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_FixedFontItalic)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FixedFontItalic)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FixedFontBold)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FixedFontBold)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontStrikeThrough)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontStrikeThrough)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontWidth)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FontWidth)(/*[in]*/ long newVal);
	STDMETHOD(get_FontUnderline)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontUnderline)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontItalic)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontItalic)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontBold)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FontBold)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FontSize)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FontSize)(/*[in]*/ long newVal);
	STDMETHOD(get_FontName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FontName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_CellFontStrikeThrough)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CellFontStrikeThrough)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_CellFontWidth)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_CellFontWidth)(/*[in]*/ long newVal);
	STDMETHOD(get_CellFontUnderline)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CellFontUnderline)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_CellFontItalic)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CellFontItalic)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_CellFontBold)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CellFontBold)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_CellFontSize)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_CellFontSize)(/*[in]*/ long newVal);
	STDMETHOD(get_CellFontName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_CellFontName)(/*[in]*/ BSTR newVal);
	STDMETHOD(RemoveItem)(/*[in]*/ long index);
	STDMETHOD(AddItem)(/*[in]*/ BSTR Item, /*[in, optional]*/ VARIANT* index);
//	STDMETHOD(Move)(long Left, long Top, long Width, long Height);
//	STDMETHOD(Refresh)();
//	STDMETHOD(SetFocus)();
//	STDMETHOD(ZOrder)(RZOrderConstants Position);
	STDMETHOD(Clear)();
	STDMETHOD(get_FixedAlignment)(/*[out, retval]*/ AlignmentSettings *pVal);
	STDMETHOD(put_FixedAlignment)(/*[in]*/ AlignmentSettings newVal);
	STDMETHOD(get_TopRow)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_TopRow)(/*[in]*/ long newVal);
	STDMETHOD(get_LeftCol)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_LeftCol)(/*[in]*/ long newVal);
	STDMETHOD(get_GridLineWidth)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_GridLineWidth)(/*[in]*/ short newVal);
	STDMETHOD(get_SelectionMode)(/*[out, retval]*/ SelectionModeSettings *pVal);
	STDMETHOD(put_SelectionMode)(/*[in]*/ SelectionModeSettings newVal);
	STDMETHOD(get_AllowBigSelection)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_AllowBigSelection)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_RowSel)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_RowSel)(/*[in]*/ long newVal);
	STDMETHOD(get_ColSel)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ColSel)(/*[in]*/ long newVal);
	STDMETHOD(get_RowPos)(/*[in]*/ long index, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_RowIsVisible)(/*[in]*/ long index, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_RowHeight)(/*[in]*/ long index, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_RowHeight)(/*[in]*/ long index, /*[in]*/ long newVal);
	STDMETHOD(get_ColPos)(/*[in]*/ long index, /*[out, retval]*/ long *pVal);
	STDMETHOD(get_ColIsVisible)(/*[in]*/ long index, /*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_ColWidth)(/*[in]*/ long index, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_ColWidth)(/*[in]*/ long index, /*[in]*/ long newVal);
	STDMETHOD(get_Text)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Text)(/*[in]*/ BSTR newVal);
	STDMETHOD(put_ColAlignment)(/*[in]*/ long index, /*[in]*/ AlignmentSettings newVal);
	STDMETHOD(get_CellHeight)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_CellWidth)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_CellTop)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_CellLeft)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_CellAlignment)(/*[out, retval]*/ AlignmentSettings *pVal);
	STDMETHOD(put_CellAlignment)(/*[in]*/ AlignmentSettings newVal);
	STDMETHOD(get_CellForeColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_CellForeColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_CellBackColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_CellBackColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_Col)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Col)(/*[in]*/ long newVal);
	STDMETHOD(get_Row)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Row)(/*[in]*/ long newVal);
	STDMETHOD(get_TextArray)(/*[in]*/ long index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_TextArray)(/*[in]*/ long index, /*[in]*/ BSTR newVal);
	STDMETHOD(get_TextMatrix)(/*[in]*/ long Row, /*[in]*/ long Col,/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_TextMatrix)(/*[in]*/ long Row, /*[in]*/ long Col,/*[in]*/ BSTR newVal);
	STDMETHOD(get_RowHeightMin)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_RowHeightMin)(/*[in]*/ long newVal);
	STDMETHOD(get_BackColorSel)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_BackColorSel)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_ForeColorSel)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_ForeColorSel)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_ForeColorFixed)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_ForeColorFixed)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_ForeColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_ForeColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_ScrollTrack)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ScrollTrack)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_BorderStyle)(/*[out, retval]*/ BorderStyleSettings *pVal);
	STDMETHOD(put_BorderStyle)(/*[in]*/ BorderStyleSettings newVal);
	STDMETHOD(get_ScrollBars)(/*[out, retval]*/ ScrollBarsSettings *pVal);
	STDMETHOD(put_ScrollBars)(/*[in]*/ ScrollBarsSettings newVal);
	STDMETHOD(get_AllowUserResizing)(/*[out, retval]*/ AllowUserResizeSettings *pVal);
	STDMETHOD(put_AllowUserResizing)(/*[in]*/ AllowUserResizeSettings newVal);
	STDMETHOD(get_GridColorFixed)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_GridColorFixed)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_GridColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_GridColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_GridLinesFixed)(/*[out, retval]*/ GridLineSettings *pVal);
	STDMETHOD(put_GridLinesFixed)(/*[in]*/ GridLineSettings newVal);
	STDMETHOD(get_GridLines)(/*[out, retval]*/ GridLineSettings *pVal);
	STDMETHOD(put_GridLines)(/*[in]*/ GridLineSettings newVal);
	STDMETHOD(get_BackColorFixed)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_BackColorFixed)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_BackColorBkg)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_BackColorBkg)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_BackColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_BackColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_FixedCols)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FixedCols)(/*[in]*/ long newVal);
	STDMETHOD(get_Cols)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Cols)(/*[in]*/ long newVal);
	STDMETHOD(get_FixedRows)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_FixedRows)(/*[in]*/ long newVal);
	STDMETHOD(get_Rows)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Rows)(/*[in]*/ long newVal);
	STDMETHOD(get_Enabled)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Enabled)(/*[in]*/ VARIANT_BOOL newVal);

	HRESULT OnDraw(ATL_DRAWINFO& di);
	
	BOOL m_bEnabled;

private:
	HWND						m_VScrollBar;
	HWND						m_HScrollBar;

	BOOL						m__bEnabled;

	long						m_nRows;
	long						m_nFixedRows;
	long						m_nCols;
	long						m_nFixedCols;
	long						m_nRowHeightMin;
	long						m_nRow;
	long						m_nCol;

	OLE_COLOR					m__clrBackColor;
	OLE_COLOR					m_clrBackColorBkg;
	OLE_COLOR					m_clrBackColorFixed;
	OLE_COLOR					m_clrGridColor;
	OLE_COLOR					m_clrGridColorFixed;
	OLE_COLOR					m__clrForeColor;
	OLE_COLOR					m_clrForeColorFixed;
	OLE_COLOR					m_clrForeColorSel;
	OLE_COLOR					m_clrBackColorSel;
	short						m_nGridLineWidth;

	GridLineSettings			m_eGridLines;
	GridLineSettings			m_eGridLinesFixed;

	AllowUserResizeSettings		m_eAllowUserResizing;

	ScrollBarsSettings			m_eScrollBars;
	long						m_nHScrollPos;
	long						m_nVScrollPos;
	BOOL						m_bScrollTrack;
	
	BorderStyleSettings			m_eBorderStyle;
	
	POINT						m_BitmapSize;

	long						*m_pColWidths;
	long						*m_pRowHeights;
	long						m_nTotalWidth;
	long						m_nTotalHeight;
	long						m_nTotalFixedWidth;
	long						m_nTotalFixedHeight;
	long						m_nMaxWidth;
	long						m_nMaxHeight;
	long						m_nXPage;
	long						m_nYPage;

	BOOL						m_bColResize;
	BOOL						m_bRowResize;
	long						m_nResizedCell;
	long						m_nOldPos;

	long						m_nColSel;
	long						m_nRowSel;

	VARIANT_BOOL				m_bAllowBigSelection;
	BOOL						m_bSelection;
	BOOL						m_bBigSelectionX;
	BOOL						m_bBigSelectionY;
	POINT						m_nOldCell;
	POINT		 				m_nMousePos;
	SelectionModeSettings		m_eSelectionMode;
	BOOL						m_bMouseDown;

	int							m_nClicks;

	BOOL						m_bKeyUp;
	BOOL						m_bDoKeyPress;

	AlignmentSettings			m_eFixedAlignment;

	BOOL						m_bNoFire;

	BSTR				m_FontName;
	VARIANT_BOOL		m_bFontBold;
	VARIANT_BOOL		m_bFontItalic;
	VARIANT_BOOL		m_bFontUnderline;
	VARIANT_BOOL		m_bFontStrikeThrough;
	long				m_nFontSize;
	long				m_nFontWidth;
	HFONT				m_hFont;
	LOGFONT				m_LogFont;
	
	BSTR				m_FixedFontName;
	VARIANT_BOOL		m_bFixedFontBold;
	VARIANT_BOOL		m_bFixedFontItalic;
	VARIANT_BOOL		m_bFixedFontUnderline;
	VARIANT_BOOL		m_bFixedFontStrikeThrough;
	long				m_nFixedFontSize;
	long				m_nFixedFontWidth;
	HFONT				m_hFixedFont;
	LOGFONT				m_FixedLogFont;
		
	CFontTable			*m_pFontTable;

	VARIANT_BOOL		m_bWordWrap;
	VARIANT_BOOL		m_bRedraw;

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonUP(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnHScroll(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnVScroll(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	DWORD TranslateColor(DWORD col);
	HWND CreateScrollBar(DWORD style, LPRECT pos);
	void SetScrollbarInfo(HWND hWnd, DWORD style);
	void DestroyScrollBar(HWND *hWnd, DWORD style, BOOL erase);
	void DrawCell(RECT *r, long x, long y, COLORREF hBackColor, COLORREF hForeColor, HPEN hGridColor, BOOL Fixed);
	LPCTSTR MakeShortString(RECT &r, LPCTSTR lpszLong );
	void DrawText(RECT &r, LPTSTR str, AlignmentSettings Alignment, COLORREF hBackColor, COLORREF hForeColor);

	void CalculateWidth(long n);
	void CalculateHeight(long n);
	void CalculateXPage(long n);
	void CalculateYPage(long n);
	void CalculateXMax(long n);
	void CalculateYMax(long n);
	void CalculateFixedWidth(long n);
	void CalculateFixedHeight(long n);

	long ColResizeTest(long xpos, long ypos);
	long RowResizeTest(long xpos, long ypos);
	void GetCellNumber(long *x, long *y);

	void DebugPrint(long n, long y, BOOL hex);
	void DeleteFonts();

	long FontSize(long size);

	CMatrix		*m_pMatrix;

	BSTR		m_RegistrationCode;

	HBITMAP		hBitmap;
	HBITMAP		hBitmapOld;
	HDC			hDC;

	HBRUSH hScrollBars;
	HBRUSH hBackColorBkg;
	HBRUSH hBackColorFixed;
	HPEN hGridColor;
	HPEN hGridColorFixed;
	HBRUSH m_hBackColor;
	HBRUSH m_hBackColorSel;
	HBRUSH m_hBackColorFixed;
	
	RHighlightConstants m_eHighlight;

	HWND	focus;


	//void Memory(long p);
};

#endif //__GRID_H_
