// Grid.cpp : Implementation of CGrid

#include "stdafx.h"
#include "RGridCtrl.h"
#include "Grid.h"
#include "Cell.h"
#include "ocidl.h"	// Added by ClassView

#define		ID_SELECT		1
#define		ID_BIGSELECT	2
#define		ID_CLICKS		3
#define		ID_KEYPRESS		4


/////////////////////////////////////////////////////////////////////////////
// CGrid

CGrid::CGrid()
{
	m__bEnabled = TRUE;

	m_VScrollBar = NULL;
	m_HScrollBar = NULL;

	m_nRows = 2;
	m_nCols = 2;
	m_nFixedRows = 1;
	m_nFixedCols = 1;
	m_nRowHeightMin = 15;
	m_nRow = 0;
	m_nCol = 0;
	
	m__clrBackColor = COLOR_WINDOW | 0x80000000;
	m_clrBackColorBkg = RGB(128, 128, 128);
	m_clrBackColorFixed = COLOR_BTNFACE | 0x80000000;
	m_clrGridColor = RGB(192, 192, 192);
	m_clrGridColorFixed = RGB(0, 0, 0);
	m__clrForeColor = COLOR_WINDOWTEXT | 0x80000000;
	m_clrForeColorFixed = COLOR_BTNTEXT | 0x80000000;
	m_clrForeColorSel = COLOR_HIGHLIGHTTEXT | 0x80000000;
	m_clrBackColorSel = COLOR_HIGHLIGHT | 0x80000000;
	m_nGridLineWidth = 1;

	hScrollBars = CreateSolidBrush(::GetSysColor(COLOR_BTNFACE));
	hBackColorBkg = CreateSolidBrush(TranslateColor(m_clrBackColorBkg));
	hBackColorFixed = CreateSolidBrush(TranslateColor(m_clrBackColorFixed));
	hGridColor = CreatePen(PS_SOLID, 1, TranslateColor(m_clrGridColor));
	hGridColorFixed = CreatePen(PS_SOLID, 1, TranslateColor(m_clrGridColorFixed));
	m_hBackColor = CreateSolidBrush(TranslateColor(m__clrBackColor));
	m_hBackColorSel = CreateSolidBrush(TranslateColor(m_clrBackColorSel));

	m_eGridLines = rgridGridNone;
	m_eGridLinesFixed = rgridGridInset;
	m_eAllowUserResizing = rgridResizeNone;

	m_eScrollBars = rgridScrollBarBoth;
	m_nHScrollPos = 0;
	m_nVScrollPos = 0;
	m_bScrollTrack = FALSE;

	m_eBorderStyle = rgridBorderSingle;

	m_pColWidths = NULL;
	m_pRowHeights = NULL;
	m_nTotalWidth = m_nTotalHeight = 0;
	m_nTotalFixedWidth = m_nTotalFixedHeight = 0;
	m_nXPage = m_nYPage = 0;
	m_nMaxHeight = m_nMaxWidth = 0;

	m_bColResize = FALSE;
	m_bRowResize = FALSE;
	m_nResizedCell = -1;

	m_nColSel = -1;
	m_nRowSel = -1;

	m_bAllowBigSelection = TRUE;
	m_bSelection = FALSE;
	m_bBigSelectionX = FALSE;
	m_bBigSelectionY = FALSE;
	m_eSelectionMode = rgridSelectionFree;
	m_bMouseDown = FALSE;

	m_nClicks = 0;

	m_eFixedAlignment = rgridAlignGeneral;

	m_bKeyUp = TRUE;
	m_bDoKeyPress = FALSE;

	m_bNoFire = FALSE;

	m_FontName = SysAllocString(_T("Arial"));
	m_bFontBold = FALSE;
	m_bFontItalic = FALSE;
	m_bFontUnderline = FALSE;
	m_bFontStrikeThrough = FALSE;
	m_nFontSize = 8;
	m_nFontWidth = 0;

	m_LogFont.lfCharSet = DEFAULT_CHARSET;
	m_LogFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	m_LogFont.lfEscapement = 0;
	_tcscpy(m_LogFont.lfFaceName, m_FontName);
	m_LogFont.lfHeight = m_nFontSize;
	m_LogFont.lfItalic = (BOOL)m_bFontItalic;
	m_LogFont.lfOrientation = 0;
	m_LogFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	m_LogFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE ;
	m_LogFont.lfQuality = DEFAULT_QUALITY;
	m_LogFont.lfStrikeOut = (BOOL)m_bFontStrikeThrough;
	m_LogFont.lfUnderline = (BOOL)m_bFontUnderline;
	m_LogFont.lfWeight = (m_bFontBold) ? FW_BOLD : FW_NORMAL;
	m_LogFont.lfWidth = 0;

	m_hFont = CreateFontIndirect(&m_LogFont);

	m_FixedFontName = SysAllocString(_T("Arial"));
	m_bFixedFontBold = FALSE;
	m_bFixedFontItalic = FALSE;
	m_bFixedFontUnderline = FALSE;
	m_bFixedFontStrikeThrough = FALSE;
	m_nFixedFontSize = 8;
	m_nFixedFontWidth = 0;

	m_FixedLogFont.lfCharSet = DEFAULT_CHARSET;
	m_FixedLogFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	m_FixedLogFont.lfEscapement = 0;
	_tcscpy(m_FixedLogFont.lfFaceName, m_FixedFontName);
	m_FixedLogFont.lfHeight = m_nFixedFontSize;
	m_FixedLogFont.lfItalic = (BOOL)m_bFixedFontItalic;
	m_FixedLogFont.lfOrientation = 0;
	m_FixedLogFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	m_FixedLogFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE ;
	m_FixedLogFont.lfQuality = DEFAULT_QUALITY;
	m_FixedLogFont.lfStrikeOut = (BOOL)m_bFixedFontStrikeThrough;
	m_FixedLogFont.lfUnderline = (BOOL)m_bFixedFontUnderline;
	m_FixedLogFont.lfWeight = (m_bFixedFontBold) ? FW_BOLD : FW_NORMAL;
	m_FixedLogFont.lfWidth = 0;

	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);

	m_pFontTable = new CFontTable;
	m_pMatrix = new CMatrix(m_nCols, m_nRows, m_pFontTable);

	m_RegistrationCode = ::SysAllocString(_T(""));

	m_eHighlight = rgridHighlightAlways;

	m_bWordWrap = FALSE;
	m_bRedraw = VARIANT_TRUE;

#ifdef UNDER_CE
	hDC = NULL;
	hBitmap = NULL;
#endif
}

//----------------------------------------------------------------------------------------------------------

CGrid::~CGrid()
{
	if (m_VScrollBar) ::DestroyWindow(m_VScrollBar);
	if (m_HScrollBar) ::DestroyWindow(m_HScrollBar);
	if (m_pColWidths) LocalFree(m_pColWidths);
	if (m_pRowHeights) LocalFree(m_pRowHeights);
	if (m_pMatrix) delete m_pMatrix;
	if (m_pFontTable) delete m_pFontTable;
	if (m_hFont) DeleteObject(m_hFont);
	if (m_hFixedFont) DeleteObject(m_hFixedFont);
	SysFreeString(m_RegistrationCode);
//	SelectObject(hDC, hBitmapOld);
//	DeleteObject(hBitmap);
//	DeleteDC(hDC);
	DeleteObject(hScrollBars);
	DeleteObject(hBackColorBkg);
	DeleteObject(hBackColorFixed);
	DeleteObject(hGridColor);
	DeleteObject(hGridColorFixed);
	DeleteObject(m_hBackColor);
	DeleteObject(m_hBackColorSel);
}

//---------------------------------------------------------------------------------------------------------

void CGrid::DebugPrint(long n, long y, BOOL hex)
{
	BSTR t;
	TCHAR tt[100];

	if (hex) wsprintf(tt, _T("%x"), n);
	else wsprintf(tt, _T("%d"), n);
	t = SysAllocString(tt);
	m_pMatrix->put_Text(0, y, t);
	SysFreeString(t);
}

//---------------------------------------------------------------------------------------------------------

DWORD CGrid::TranslateColor(DWORD col)
{
	DWORD clr = col;
	DWORD COLOR_CONST;

#ifndef UNDER_CE
	COLOR_CONST = 0x00000000;
#else
#if defined(_X86_)
#if defined(_WIN32_WCE) && (_WIN32_WCE < 400)
#if defined(__WCE2002_VERSION_)
	COLOR_CONST = 0x40000000;
#else
	COLOR_CONST = 0x80000000;
#endif
#else 
	COLOR_CONST = 0x40000000;
#endif
#elif defined(ARM) || defined(SH3) || defined(MIPS)
	COLOR_CONST	= 0x40000000;
#endif
#endif
	
	if (col & 0xff000000)
	{	

		col = (col & 0xffffff) | COLOR_CONST;
		clr = ::GetSysColor(col);
	}
	return clr;
}

void CGrid::SetScrollbarInfo(HWND hWnd, DWORD style)
{
	SCROLLINFO si;
	ZeroMemory(&si, sizeof(SCROLLINFO));
	si.cbSize = sizeof(SCROLLINFO);
	if (m__bEnabled)
	{
		si.fMask = SIF_ALL;
		if (style & SBS_VERT) 
		{
			si.nMax = m_nMaxHeight;
			if (m_nVScrollPos > si.nMax) m_nVScrollPos = si.nMax;
			si.nPos = m_nVScrollPos;
			si.nTrackPos = m_nVScrollPos;
			si.nPage = 1;
		}
		else
		{
			si.nMax = m_nMaxWidth;
			if (m_nHScrollPos > si.nMax) m_nHScrollPos = si.nMax;
			si.nPos = m_nHScrollPos;
			si.nTrackPos = m_nHScrollPos;
			si.nPage = 1;
		}
		si.nMin = 0;
	}
	else si.fMask = SIF_DISABLENOSCROLL;
	
	::SetScrollInfo(hWnd, SB_CTL, &si, TRUE);
}

HWND CGrid::CreateScrollBar(DWORD style, LPRECT pos)
{
/*if (m__bEnabled == FALSE) 
	style |= WS_DISABLED;*/
	
	HWND hWnd;
	
	
	hWnd = CreateWindow(_T("SCROLLBAR"), _T(""), WS_CHILD | style, pos->left, 
		pos->top, pos->right, pos->bottom, m_hWnd, NULL, _Module.m_hInst, NULL);
	if (hWnd)
	{
		::ShowWindow(hWnd, SW_SHOWNORMAL);
		
		SetScrollbarInfo(hWnd, style);
	}
	
	return hWnd;
}

void CGrid::DestroyScrollBar(HWND *hWnd, DWORD style, BOOL erase)
{
	if (*hWnd)
	{
		::DestroyWindow(*hWnd);
		*hWnd = NULL;
		if (erase) 
			if (style == SBS_VERT) 
			{
				m_nVScrollPos = 0;
			}
			else 
			{
				m_nHScrollPos = 0;
			}
	}
}

void CGrid::CalculateHeight(long n)
{
	m_nTotalHeight = 0;
	for (long i = 0; i < n; i++)
		m_nTotalHeight += m_pRowHeights[i];
}

void CGrid::CalculateWidth(long n)
{
	m_nTotalWidth = 0;
	for (long i = 0; i < n; i++)
		m_nTotalWidth += m_pColWidths[i];
}

void CGrid::CalculateXMax(long n)
{
	m_nMaxWidth = 0;
	long x = m_BitmapSize.x - m_nTotalFixedWidth;
	for (long i = n - 1; i >= m_nFixedCols && x > 0; i--)
	{
		x -= m_pColWidths[i];
		m_nMaxWidth++;
	}
	m_nMaxWidth = n - m_nMaxWidth - m_nFixedCols;
	if (x) m_nMaxWidth++;
}

void CGrid::CalculateYMax(long n)
{
	m_nMaxHeight = 0;
	long y = m_BitmapSize.y - m_nTotalFixedHeight;
	for (long i = n - 1; i >= m_nFixedRows && y > 0; i--)
	{
		y -= m_pRowHeights[i];
		m_nMaxHeight++;
	}
	m_nMaxHeight = n - m_nMaxHeight - m_nFixedRows;
	if (y) m_nMaxHeight++;
}

void CGrid::CalculateXPage(long n)
{
	m_nXPage = 0;
	long x = m_BitmapSize.x - m_nTotalFixedWidth;
	for (long i = m_nHScrollPos + m_nFixedCols; i < n && x > 0; i++)
	{
		x -= m_pColWidths[i];
		m_nXPage++;
	}
	if (x < 0) m_nXPage--;
}

void CGrid::CalculateYPage(long n)
{
	m_nYPage = 0;
	long y = m_BitmapSize.y - m_nTotalFixedHeight;
	for (long i = m_nVScrollPos + m_nFixedRows; i < n && y > 0; i++)
	{
		y -= m_pRowHeights[i];
		m_nYPage++;
	}
	if (y < 0) m_nYPage--;
}

void CGrid::CalculateFixedHeight(long n)
{
	m_nTotalFixedHeight = 0;
	for (long j = 0; j < n; j++)
	{
		m_nTotalFixedHeight += m_pRowHeights[j];
	}
}

void CGrid::CalculateFixedWidth(long n)
{
	m_nTotalFixedWidth = 0;
	for (long i = 0; i < n; i++)
	{
		m_nTotalFixedWidth += m_pColWidths[i];
	}
}

void CGrid::DrawCell(RECT *rc, long x, long y, COLORREF clrBackColor, COLORREF clrForeColor, HPEN hGridColor, BOOL Fixed)
{
	POINT pt[5];
	AlignmentSettings Alignment;
	VARIANT_BOOL bSelected;
	RECT r = {rc->left, rc->top, rc->right, rc->bottom};

	COLORREF BackColor = 0;
	COLORREF ForeColor = 0;
	HBRUSH		hBackColor;

	long index;

	m_pMatrix->get_FontIndex(x, y, &index);

	HFONT font = NULL;
#ifdef UNDER_CE
	HFONT oldfont;
#endif

#ifdef UNDER_CE
	if (index != -1) 
	{
		oldfont = (HFONT)SelectObject(hDC, m_pFontTable->GetFont(index));
	}
	else
	{
		if (Fixed)
		{
			oldfont = (HFONT)SelectObject(hDC, m_hFixedFont);
		}
		else
		{
			oldfont = (HFONT)SelectObject(hDC, m_hFont);
		}
	}
#endif

	m_pMatrix->get_Selected(x, y, &bSelected);
		m_pMatrix->get_Alignment(x, y, &Alignment);
	if (!Fixed) 
	{
		if (bSelected && m_eHighlight == rgridHighlightAlways)
		{
			m_pMatrix->get_BackColorSel(x, y, &BackColor, &hBackColor);
			m_pMatrix->get_ForeColorSel(x, y, &ForeColor);
			if (BackColor == 0) 
			{
				BackColor = m_clrBackColorSel;
				hBackColor = m_hBackColorSel;
			}
			if (ForeColor == 0) ForeColor = m_clrForeColorSel;
		}
		else
		{
			m_pMatrix->get_BackColor(x, y, &BackColor, &hBackColor);
			m_pMatrix->get_ForeColor(x, y, &ForeColor);
			if (BackColor == 0) 
			{
				BackColor = clrBackColor;
				hBackColor = m_hBackColor;
			}
			if (ForeColor == 0) ForeColor = clrForeColor;
		}
	} else
	{
		hBackColor = hBackColorFixed;
		BackColor = clrBackColor;
		ForeColor = clrForeColor;
	}
	
	
	switch((Fixed) ? m_eGridLinesFixed : m_eGridLines)
	{
	case rgridGridInset:
	case rgridGridRaised:
		r.left++;
		r.top++;
	case rgridGridFlat:
		r.right--;
		r.bottom--;
	}
	FillRect(hDC, &r, hBackColor);
	
	BSTR text;
	
	m_pMatrix->get_Text(x, y, &text);
	r.bottom--;
	r.left++;
	r.right--;
	r.top++;
	
#ifdef UNDER_CE

	RECT rr;
	rr.left = 0;
	rr.top = 0;
	rr.right = r.right - r.left;
	rr.bottom = r.bottom - r.top;
	
	HBITMAP hPicture, hOldPicture;
	HDC		hCellPicDC;
	m_pMatrix->get_Picture(x, y, &hPicture);
	if (hPicture)
	{
	//	DebugBreak();

		AlignmentSettings PicAlignment;
		m_pMatrix->get_PictureAlignment(x, y, &PicAlignment);
		RECT size;
		hCellPicDC = ::CreateCompatibleDC(hDC);
		hOldPicture = (HBITMAP)SelectObject(hCellPicDC, hPicture);
		GetClipBox(hCellPicDC, &size);
		POINT pos;
		
		switch(PicAlignment)
		{
		case rgridAlignLeftTop:
			pos.x = pos.y = 0;
			break;
		case rgridAlignGeneral:
		case rgridAlignLeftCenter:
			pos.x = 0;
			pos.y = (rr.bottom - size.bottom) / 2;
			break;
		case rgridAlignLeftBottom:
			pos.x = 0;
			pos.y = rr.bottom - size.bottom;
			break;
		case rgridAlignCenterTop:
			pos.x = (rr.right - size.right) / 2;
			pos.y = 0;
			break;
		case rgridAlignCenterCenter:
			pos.x = (rr.right - size.right) / 2;
			pos.y = (rr.bottom - size.bottom) / 2;
			break;
		case rgridAlignCenterBottom:
			pos.x = (rr.right - size.right) / 2;
			pos.y = rr.bottom - size.bottom;
			break;
		case rgridAlignRightTop:
			pos.x = rr.right - size.right;
			pos.y = 0;
			break;
		case rgridAlignRightCenter:
			pos.x = rr.right - size.right;
			pos.y = (rr.bottom - size.bottom) / 2;
			break;
		case rgridAlignRightBottom:
			pos.x = rr.right - size.right;
			pos.y = rr.bottom - size.bottom;
			break;
		}
		
		long xx = 0, yy = 0;
		if (pos.x < 0) 
		{
			size.right += pos.x;
			xx = -1 * pos.x;
			pos.x = 0;
		}
		if (pos.y < 0)
		{
			size.bottom += pos.y;
			yy = -1 * pos.y;
			pos.y = 0;
		}

		if (size.right > rr.right)
		{
			size.right = rr.right;
		}

		if (size.bottom > rr.bottom)
			size.bottom = rr.bottom;
		
		BitBlt(hDC, pos.x + r.left, pos.y + r.top, size.right, size.bottom, hCellPicDC, xx, yy, SRCCOPY);
	}

#endif	

	if (text && _tcslen(text))
	{
		
//#ifdef UNDER_CE

		DrawText(r, text, Alignment, TranslateColor(BackColor), TranslateColor(ForeColor));
		SysFreeString(text);
	}
	
#ifdef UNDER_CE
	if (hPicture) 
	{
		SelectObject(hCellPicDC, hOldPicture);
		DeleteDC(hCellPicDC);
	}
//#else
//		DrawText(r, text, Alignment, TranslateColor(BackColor), TranslateColor(ForeColor));
#endif
		
	r.left = rc->left;
	r.top = rc->top;
	r.bottom = rc->bottom;
	r.right = rc->right;

	switch((Fixed) ? m_eGridLinesFixed : m_eGridLines)
	{
	case rgridGridInset:
	case rgridGridRaised:
		pt[0].x = pt[1].x = r.left;
		pt[2].x = r.right - 1;
		pt[0].y = r.bottom - 1;
		pt[1].y = pt[2].y = r.top;

		SelectObject(hDC, (((Fixed) ? m_eGridLinesFixed : m_eGridLines) == rgridGridInset) ? (HPEN)GetStockObject(WHITE_PEN) : (HPEN)GetStockObject(BLACK_PEN));
		Polyline(hDC, pt, 3);
		pt[0].x = r.left + 1;
		pt[1].x = pt[2].x = r.right - 1;
		pt[0].y = pt[1].y = r.bottom - 1;
		pt[2].y = r.top - 1;

		SelectObject(hDC, (((Fixed) ? m_eGridLinesFixed : m_eGridLines) == rgridGridInset) ? (HPEN)GetStockObject(BLACK_PEN) : (HPEN)GetStockObject(WHITE_PEN));
		Polyline(hDC, pt, 3);
		break;
	case rgridGridFlat:
		SelectObject(hDC, hGridColor);
		for (long q = 0; q < m_nGridLineWidth; q++)
		{
			pt[0].x = r.left;
			pt[1].x = pt[2].x = r.right - 1 - q;
			pt[0].y = pt[1].y = r.bottom - 1 - q;
			pt[2].y = r.top - 1;

			Polyline(hDC, pt, 3);
		}
	}

#ifdef UNDER_CE
	if (font) SelectObject(hDC, oldfont);
#endif

}

long CGrid::ColResizeTest(long xpos, long ypos)
{
	long i;
	long pos;


	if (m_eBorderStyle == rgridBorderSingle) 
	{
		xpos--;
		ypos--;
	}

	if (ypos > m_nTotalFixedHeight) return -1;
	if (xpos <= m_nTotalFixedWidth + 1)
	{
		pos = 0;
		for (i = 0; i < m_nFixedCols; i++)
		{
			pos += m_pColWidths[i];
			if (xpos >= pos - 2 && xpos <= pos + 1) return i;
		}
	}
	pos = m_nTotalFixedWidth;
	for (i = m_nHScrollPos + m_nFixedCols; i < m_nHScrollPos + m_nXPage + m_nFixedCols; i++)
	{
		pos += m_pColWidths[i];
		if (xpos >= pos - 2 && xpos <= pos + 1) return i;
	}

	return -1;
}

long CGrid::RowResizeTest(long xpos, long ypos)
{
	long j;
	long pos;

	if (m_eBorderStyle == rgridBorderSingle) 
	{
		xpos--;
		ypos--;
	}

	if (xpos > m_nTotalFixedWidth) return -1;
	if (ypos <= m_nTotalFixedHeight + 1)
	{
		pos = 0;
		for (j = 0; j < m_nFixedRows; j++)
		{
			pos += m_pRowHeights[j];
			if (ypos >= pos - 2 && ypos <= pos + 1) return j;
		}
	}
	pos = m_nTotalFixedHeight;
	for (j = m_nVScrollPos + m_nFixedRows; j < m_nVScrollPos + m_nYPage + m_nFixedRows; j++)
	{
		pos += m_pRowHeights[j];
		if (ypos >= pos - 2 && ypos <= pos + 1) return j;
	}
	
	return -1;
}

void CGrid::DrawText(RECT &r, LPTSTR str, AlignmentSettings Alignment, COLORREF hBackColor, COLORREF clrForeColor)
{
	LPCTSTR     retStr;
    UINT        nJustify;
	UINT		len     = _tcslen(str);
	double		t;
	TCHAR		tt;
	RECT		rr;
	BOOL		wrap = m_bWordWrap;
		
	//DebugBreak();

	switch(Alignment)
	{
	case rgridAlignLeftTop:
		nJustify = DT_LEFT;
		break;
	case rgridAlignLeftBottom:
		nJustify = DT_LEFT;
		break;
	case rgridAlignCenterTop:
		nJustify = DT_CENTER;
		break;
	case rgridAlignCenterCenter:
		nJustify = DT_CENTER;
		break;
	case rgridAlignCenterBottom:
		nJustify = DT_CENTER;
		break;
	case rgridAlignRightTop:
		nJustify = DT_RIGHT;
		break;
	case rgridAlignRightCenter:
		nJustify = DT_RIGHT;
		break;
	case rgridAlignRightBottom:
		nJustify = DT_RIGHT;
		break;
	case rgridAlignGeneral:
	//	DebugBreak();
		if (_stscanf(str, _T("%lf%c"), &t, &tt) == 1)
		{
			//if (wrap) nJustify = DT_RIGHT;
			/*else*/ nJustify = DT_RIGHT/* | DT_VCENTER*/;
			wrap = FALSE;
		}
		else
		{
			nJustify = DT_LEFT;
		}
		break;
	case rgridAlignLeftCenter:
	default:
		nJustify = DT_LEFT;
		break;
	}

	if (wrap) 
	{
		retStr = str;
		nJustify |= DT_WORDBREAK;
	}
	else 
	{
		if (_tcsstr(str, _T("\r\n")))
			retStr = str;
		else retStr = MakeShortString(r, str);
		nJustify |= DT_SINGLELINE;
	}
	SetBkColor(hDC, TranslateColor(hBackColor));
	SetTextColor(hDC, TranslateColor(clrForeColor));
	SetBkMode(hDC, TRANSPARENT);
	
	memcpy(&rr, &r, sizeof(RECT));
	memcpy(&rr, &r, sizeof(RECT));
	::DrawText(hDC, retStr, _tcslen(retStr), &rr, nJustify | DT_NOPREFIX | DT_CALCRECT);

	if (wrap)
	{
		if (rr.bottom < r.bottom)
		{
			long db = r.bottom - rr.bottom;
			switch(Alignment)
			{
			case rgridAlignLeftBottom:
			case rgridAlignCenterBottom:
			case rgridAlignRightBottom:
				rr.top += db;
				rr.bottom += db;
				break;
			case rgridAlignCenterCenter:
			case rgridAlignRightCenter:
			case rgridAlignGeneral:
			case rgridAlignLeftCenter:
				rr.top += db / 2;
				rr.bottom += db / 2;
				break;
			case rgridAlignLeftTop:
			case rgridAlignCenterTop:
			case rgridAlignRightTop:
			default:
				break;
			}
		}
		else rr.bottom = r.bottom;
		/*if (rr.right > r.right)*/ rr.right = r.right;

		::DrawText(hDC, retStr, _tcslen(retStr), &rr, nJustify | DT_NOPREFIX);
	}
	else
	{
	//	DebugBreak();

		long height = rr.bottom - rr.top;
		long tokens = 0;
		LPTSTR pdest;
		LPCTSTR psrc = retStr;
		
		while(1)
		{
			pdest = _tcsstr(psrc, _T("\r\n"));
			if (pdest == NULL) break;
			psrc = pdest + sizeof(TCHAR);
			tokens++;
		}
					
		long top;

		switch(Alignment)
		{
		case rgridAlignLeftBottom:
		case rgridAlignCenterBottom:
		case rgridAlignRightBottom:
			nJustify |= DT_BOTTOM;
			if (tokens)
			{
				psrc = retStr;
				top = r.bottom - (tokens + 1) * height;
				while(1)
				{
					pdest = _tcsstr(psrc, _T("\r\n"));
					if (pdest) pdest[0] = '\0';
					rr.top = top;
					rr.bottom = top + height;
					rr.right = r.right;
					if (rr.top < r.top) rr.top = r.top;
					if (rr.bottom >= r.top)
						::DrawText(hDC, psrc, _tcslen(psrc), &rr, nJustify | DT_NOPREFIX);
					if (pdest == NULL) break;
					top += height;
					pdest[0] = '\r';
					psrc = pdest + 2;
				}
			}
			else
			{
				::DrawText(hDC, retStr, _tcslen(retStr), &r, nJustify | DT_NOPREFIX);
			}
			break;
		case rgridAlignCenterCenter:
		case rgridAlignRightCenter:
		case rgridAlignGeneral:
		case rgridAlignLeftCenter:
			nJustify |= DT_VCENTER;
			if (tokens)
			{
				psrc = retStr;
				top = r.top + ((r.bottom - r.top) - (tokens + 1) * height) / 2;
				while(1)
				{
					pdest = _tcsstr(psrc, _T("\r\n"));
					if (pdest) pdest[0] = '\0';
					rr.top = top;
					rr.bottom = top + height;
					rr.right = r.right;
					if (rr.top < r.top) rr.top = r.top;
					if (rr.bottom > r.bottom) rr.bottom = r.bottom;
					if (rr.bottom >= r.top && rr.top <= r.bottom)
						::DrawText(hDC, psrc, _tcslen(psrc), &rr, nJustify | DT_NOPREFIX);
					if (pdest == NULL) break;
					top += height;
					pdest[0] = '\r';
					psrc = pdest + 2;
				}
			}
			else
			{
				::DrawText(hDC, retStr, _tcslen(retStr), &r, nJustify | DT_NOPREFIX);
			}
			break;
		case rgridAlignLeftTop:
		case rgridAlignCenterTop:
		case rgridAlignRightTop:
		default:
			nJustify |= DT_TOP;
			if (tokens)
			{
				psrc = retStr;
				top = r.top;
				while(1)
				{
					pdest = _tcsstr(psrc, _T("\r\n"));
					if (pdest) pdest[0] = '\0';
					rr.top = top;
					rr.bottom = r.bottom;
					rr.right = r.right;
					if (rr.top >= rr.bottom) break;
					::DrawText(hDC, psrc, _tcslen(psrc), &rr, nJustify | DT_NOPREFIX);
					if (pdest == NULL) break;
					top += height;
					pdest[0] = '\r';
					psrc = pdest + 2;
				}
			}
			else
			{
				::DrawText(hDC, retStr, _tcslen(retStr), &r, nJustify | DT_NOPREFIX);
			}
			break;
		}
	}
};

LPCTSTR CGrid::MakeShortString(RECT &r, LPCTSTR lpszLong )
{
	static const _TCHAR szThreeDots[]=_T("...");

	int           len = lstrlen(lpszLong);
	SIZE size;
	
	GetTextExtentPoint(hDC, lpszLong, len, &size);

	if( !len || size.cx <= (r.right - r.left))
		return(lpszLong);

	static _TCHAR szShort[MAX_PATH];

	ZeroMemory(szShort, sizeof(_TCHAR) * MAX_PATH);

	lstrcpy(szShort,lpszLong);
	GetTextExtentPoint(hDC, szThreeDots, _tcslen(szThreeDots), &size);
	int nAddLen = size.cx;

	for(int i=len-1; i>0; i--)
	{
		szShort[i] = 0;
		GetTextExtentPoint(hDC, szShort, i, &size);
		if(size.cx + nAddLen <= (r.right - r.left) )
			break;
	}

	lstrcat( szShort, szThreeDots);

	return(szShort);
}

void CGrid::GetCellNumber(long *x, long *y)
{
	long xpos = *x;
	long ypos = *y;

	long i,j;

	CalculateFixedWidth(m_nFixedCols);
	CalculateFixedHeight(m_nFixedRows);
	CalculateXPage(m_nCols);
	CalculateYPage(m_nRows);

	long width = m_pColWidths[0];
	long height = m_pRowHeights[0];
	
	for (j = 0; j < m_nFixedRows; j++)
	{
		for (i = 0; i < m_nFixedCols; i++)
		{
			if (xpos < width && ypos < height)
			{
				*x = i;
				*y = j;
				return;
			}
			width += m_pColWidths[i + 1];
		}
		width = m_pColWidths[0];
		height += m_pRowHeights[j + 1];
	}

	width = m_nTotalFixedWidth;
	height = m_pRowHeights[0];

	for (j = 0; j < m_nFixedRows; j++)
	{
		for (i = m_nHScrollPos + m_nFixedCols; i < m_nHScrollPos + m_nFixedCols +m_nXPage + 1 && i < m_nCols; i++)
		{
			width += m_pColWidths[i];
			if (xpos < width && ypos < height)
			{
				*x = i;
				*y = j;
				return;
			}
		}
		width = m_nTotalFixedWidth;
		height += m_pRowHeights[j + 1];
	}

	width = m_pColWidths[0];
	height = m_nTotalFixedHeight;

	for (j = m_nVScrollPos + m_nFixedRows; j < m_nFixedRows + m_nVScrollPos + m_nYPage + 1 && j < m_nRows; j++)
	{
		height += m_pRowHeights[j];
		for (i = 0; i < m_nFixedCols; i++)
		{
			if (xpos < width && ypos < height)
			{
				*x = i;
				*y = j;
				return;
			}
			width += m_pColWidths[i + 1];
		}
		width = m_pColWidths[0];
	}
		
	width = m_nTotalFixedWidth;
	height = m_nTotalFixedHeight;

	for (j = m_nVScrollPos + m_nFixedRows; j < m_nYPage + m_nVScrollPos + m_nFixedRows + 1 && j < m_nRows; j++)
	{
		height += m_pRowHeights[j];
		for (i = m_nHScrollPos + m_nFixedCols; i < m_nXPage + m_nHScrollPos + m_nFixedCols + 1 && i < m_nCols; i++)
		{
			width += m_pColWidths[i];
			if (xpos < width && ypos < height)
			{
				*x = i;
				*y = j;
				return;
			}
		}
		width = m_nTotalFixedWidth;
	}
	
	*x = -1;
	*y = -1;
}

void CGrid::DeleteFonts()
{
	for (long j = m_nFixedRows; j < m_nRows; j++)
		for (long i = m_nFixedCols; i < m_nCols; i++)
		{
			m_pMatrix->put_FontIndex(i, j, -1);
		}
	if (m_pFontTable) delete m_pFontTable;
	m_pFontTable = new CFontTable;
}

long CGrid::FontSize(long size)
{
	double c = (double)size * (double)GetDeviceCaps(::GetDC(NULL), LOGPIXELSY) / 72.0;

	double d = c - (double)(int)c;

	if (d >= 0.5) 
		c = ceil(c);
	else
		c = floor(c);

	c = -c;

	return (int)c;
}

//----------------------------------------------------------------------------------------------------------

LRESULT CGrid::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	RECT r = {0, 0, 0, 0};
	if (m_hWnd) GetClientRect(&r);
	
	m_BitmapSize.x = r.right - r.left;
	m_BitmapSize.y = r.bottom - r.top;
	if (m_eBorderStyle == rgridBorderSingle)
	{
		m_BitmapSize.x -= 2;
		m_BitmapSize.y -= 2;
	}
	
	put_Rows(m_nRows);
	put_Cols(m_nCols);

#ifdef UNDER_CE
	//make registration number
	DWORD regnum = 0;
	for (long i = 0; i < 8; i++)
	{
		regnum *= 13;
		regnum += (m_RegistrationCode[i] * (1 << (8 - i))) % 10;
	}
	if (regnum != 540620268) MessageBox(_T("Resco Grid Control - Unregistered version.\nGo to www.resco-net.com to purchase the registration code."));
#endif

	return 0;
}

HRESULT CGrid::OnDraw(ATL_DRAWINFO& di)
{
	RECT rc = *(RECT*)di.prcBounds;
	RECT r;
	POINT pt[5];
	long x, y;
	long i, j;

	
//	Memory(0);
	
//	DebugBreak();

#ifdef UNDER_CE
	if (m_hWnd)
		::GetWindowRect(m_hWnd, &r);
	else
		::GetWindowRect(GetDesktopWindow(), &r);
	hBitmap = CreateCompatibleBitmap(di.hdcDraw, r.right - r.left, r.bottom - r.top);	
	hDC = ::CreateCompatibleDC(di.hdcDraw);
	hBitmapOld = (HBITMAP)SelectObject(hDC, hBitmap);

#else
	hDC = di.hdcDraw;

	POINT origin;

	m_BitmapSize.x = rc.right - rc.left;
	m_BitmapSize.y = rc.bottom - rc.top;
	if (m_eBorderStyle == rgridBorderSingle)
	{
		m_BitmapSize.x -= 2;
		m_BitmapSize.y -= 2;
	}
	origin.x = rc.left;
	origin.y = rc.top;
#endif

	HPEN hOldPen = (HPEN)SelectObject(di.hdcDraw, (HPEN)GetStockObject(BLACK_PEN));

	if (m_pRowHeights && m_pColWidths)
	{
		CalculateXPage(m_nCols);
		CalculateYPage(m_nRows);
	} else
	{
		m_nXPage = 5;
		m_nYPage = 20;
	}

#ifdef UNDER_CE
	r.left = r.top = 0;
	r.bottom = m_BitmapSize.y;
	r.right = m_BitmapSize.x;
	//FillRect(hDC, &r, hBackColorBkg);
#else
	r.left = rc.left;
	r.top = rc.top;
	if (m_eBorderStyle == rgridBorderSingle)
	{
		r.left++;
		r.top++;
		origin.x++;
		origin.y++;
	}
	r.right = r.left + m_BitmapSize.x;
	r.bottom = r.top + m_BitmapSize.y;
	//FillRect(di.hdcDraw, &r, hBackColorBkg);
#endif
	FillRect(hDC, &r, hBackColorBkg);

//	Memory(1);

// total fixed

	r.bottom = 0;
	for (j = 0; j < m_nFixedRows; j++)
	{
		r.right = 0;
		r.top = r.bottom;
		r.bottom += (m_pRowHeights) ? m_pRowHeights[j] : m_nRowHeightMin;
		if (r.top != r.bottom)
		{
			for (i = 0; i < m_nFixedCols; i++)
			{	
				r.left = r.right;
				r.right += (m_pColWidths) ? m_pColWidths[i] : 40;
#ifdef UNDER_CE
				DrawCell(&r, i, j, m_clrBackColorFixed, m_clrForeColorFixed, hGridColorFixed, TRUE);
#else
				r.left += origin.x;
				r.right += origin.x;
				r.top += origin.y;
				r.bottom += origin.y;
				DrawCell(&r, i, j, m_clrBackColorFixed, m_clrForeColorFixed, hGridColorFixed, TRUE);
				r.left -= origin.x;
				r.right -= origin.x;
				r.top -= origin.y;
				r.bottom -= origin.y;
#endif
			}
		}
	}

//	Memory(2);

//upper fixed

	r.bottom = 0;
	for (j = 0; j < m_nFixedRows; j++)
	{
		r.right = m_nTotalFixedWidth;
		x = m_BitmapSize.x - m_nTotalFixedWidth;
		i = m_nHScrollPos + m_nFixedCols;
		r.top = r.bottom;
		r.bottom += (m_pRowHeights) ? m_pRowHeights[j] : m_nRowHeightMin;
		if (r.top != r.bottom)
		{
			while (x > 0 && i < m_nCols && i < m_nHScrollPos + m_nFixedCols + m_nXPage + 1)
			{
				r.left = r.right;
				r.right += (m_pColWidths) ? m_pColWidths[i] : 40;
#ifdef UNDER_CE
				DrawCell(&r, i, j, m_clrBackColorFixed, m_clrForeColorFixed, hGridColorFixed, TRUE);
#else
				r.left += origin.x;
				r.right += origin.x;
				r.top += origin.y;
				r.bottom += origin.y;
				DrawCell(&r, i, j, m_clrBackColorFixed, m_clrForeColorFixed, hGridColorFixed, TRUE);
				r.left -= origin.x;
				r.right -= origin.x;
				r.top -= origin.y;
				r.bottom -= origin.y;
#endif
				i++;
			}
		}
	}

//	Memory(3);

//left fixed

	r.right = 0;
	for (i = 0; i < m_nFixedCols; i++)
	{
		r.bottom = m_nTotalFixedHeight;
		y = m_BitmapSize.y - m_nTotalFixedHeight;
		j = m_nVScrollPos + m_nFixedRows;
		r.left = r.right;
		r.right += (m_pColWidths) ? m_pColWidths[i] : 40;
		while (y > 0 && j < m_nRows && j < m_nVScrollPos + m_nFixedRows + m_nYPage + 1)
		{
			r.top = r.bottom;
			r.bottom += (m_pRowHeights) ? m_pRowHeights[j] : m_nRowHeightMin;
			if (r.top != r.bottom)
			{
				
#ifdef UNDER_CE
				DrawCell(&r, i, j, m_clrBackColorFixed, m_clrForeColorFixed, hGridColorFixed, TRUE);
#else
				r.left += origin.x;
				r.right += origin.x;
				r.top += origin.y;
				r.bottom += origin.y;
				DrawCell(&r, i, j, m_clrBackColorFixed, m_clrForeColorFixed, hGridColorFixed, TRUE);
				r.left -= origin.x;
				r.right -= origin.x;
				r.top -= origin.y;
				r.bottom -= origin.y;
#endif
			}
			j++;
		}
	}

//	Memory(4);

//inside grid
	r.bottom = m_nTotalFixedHeight;
	y = m_BitmapSize.y - m_nTotalFixedHeight;
	j = m_nVScrollPos + m_nFixedRows;
	while (y > 0 && j < m_nRows && j < m_nVScrollPos + m_nFixedRows + m_nYPage + 1)
	{
		r.top = r.bottom;
		r.bottom += (m_pRowHeights) ? m_pRowHeights[j] : m_nRowHeightMin;

		r.right = m_nTotalFixedWidth;
		x = m_BitmapSize.x - m_nTotalFixedWidth;
		i = m_nHScrollPos + m_nFixedCols;
		if (r.top != r.bottom)
		{
			while (x > 0 && i < m_nCols && i < m_nHScrollPos + m_nFixedCols + m_nXPage + 1)
			{
				r.left = r.right;
				r.right += (m_pColWidths) ? m_pColWidths[i] : 40;
#ifdef UNDER_CE
				DrawCell(&r, i, j, m__clrBackColor, m__clrForeColor, hGridColor, FALSE);
#else
				r.left += origin.x;
				r.right += origin.x;
				r.top += origin.y;
				r.bottom += origin.y;
				DrawCell(&r, i, j, m__clrBackColor, m__clrForeColor, hGridColor, FALSE);
				r.left -= origin.x;
				r.right -= origin.x;
				r.top -= origin.y;
				r.bottom -= origin.y;
#endif
				i++;
			}
		}
		j++;
	}

//	Memory(5);

	if (m_HScrollBar && m_VScrollBar)
	{
		r.left = rc.right - 16;
		r.top = rc.bottom - 16;
		r.right = rc.right;
		r.bottom = rc.bottom;
		FillRect(di.hdcDraw, &r, hScrollBars);
	}
#ifdef UNDER_CE
	BOOL bRes;

	if (m_eBorderStyle == rgridBorderNone) bRes = BitBlt(di.hdcDraw, 0, 0, m_BitmapSize.x, m_BitmapSize.y, hDC, 0, 0, SRCCOPY);
	else bRes = BitBlt(di.hdcDraw, 1, 1, m_BitmapSize.x - 2, m_BitmapSize.y - 2, hDC, 0, 0, SRCCOPY); 

	if (!bRes)
	{
		LPVOID lpMsgBuf;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, GetLastError(), 0, (LPTSTR) &lpMsgBuf, 0, NULL);
		::MessageBox(NULL, (LPCTSTR)lpMsgBuf, _T("Error"), MB_OK | MB_ICONINFORMATION);
		LocalFree( lpMsgBuf );
	}

#endif
	if (m_eBorderStyle == rgridBorderSingle)
	{
		SelectObject(di.hdcDraw, (HBRUSH)CreateSolidBrush(0));

		pt[4].x = pt[0].x = rc.left;
		pt[4].y = pt[0].y = pt[1].y = rc.top;
		pt[1].x = pt[2].x = rc.right - 1;
		pt[2].y = pt[3].y = rc.bottom - 1;
		pt[3].x = rc.left;
		
		::Polyline(di.hdcDraw, pt, 5);
	}

	SelectObject(di.hdcDraw, hOldPen);

#ifdef UNDER_CE
	SelectObject(hDC, hBitmapOld);
	DeleteObject(hBitmap);
	DeleteDC(hDC);
	hDC = NULL;
#endif

//	Memory(6);

	return S_OK;
}

LRESULT CGrid::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	SetFocus();

	focus = GetFocus();

	//DebugBreak();
	
	if (m_bMouseDown)
	{
		KillTimer(ID_SELECT);
		KillTimer(ID_BIGSELECT);
		KillTimer(ID_CLICKS);
		m_nClicks = 0;
				
		m_bColResize = FALSE;
		m_bRowResize = FALSE;
		m_bSelection = FALSE;
		m_bBigSelectionX = FALSE;
		m_bBigSelectionY = FALSE;
	}

	m_bMouseDown = TRUE;

	if (m_nClicks == 0) ::SetTimer(m_hWnd, ID_CLICKS, 250, NULL);
	
	long xpos = LOWORD(lParam);
	long ypos = HIWORD(lParam);

	m_nMousePos.x = xpos;
	m_nMousePos.y = ypos;

	CalculateFixedHeight(m_nFixedRows);
	CalculateFixedWidth(m_nFixedCols);

	long x, y;
	x = xpos;
	y = ypos;
	
	Fire_MouseDown(wParam, x, y);

	//DebugBreak();

	m_nResizedCell = ColResizeTest(xpos, ypos);
	if (m_nResizedCell >= 0) 
	{
		m_bColResize = TRUE;
		m_nOldPos = xpos;
		Fire_MouseDown(wParam, x, y);
		return 0;
	}
	else
	{
		m_nResizedCell = RowResizeTest(xpos, ypos);
		if (m_nResizedCell >= 0) 
		{
			m_bRowResize = TRUE;
			m_nOldPos = ypos;
			Fire_MouseDown(wParam, x, y);
			return 0;
		}
	}
	
	if (!m_bSelection)
	{
		GetCellNumber(&xpos, &ypos);

		if (xpos < 0 || ypos < 0)
		{
			Fire_MouseDown(wParam, x, y);
			return 0;
		}

		if (xpos < m_nFixedCols && ypos < m_nFixedRows)
		{
			if (m_bAllowBigSelection)
			{
				m_bNoFire = TRUE;
				put_Col(0);
				m_bNoFire = FALSE;
				put_Row(0);
				put_ColSel(m_nCols - m_nFixedCols - 1);
				put_RowSel(m_nRows - m_nFixedRows - 1);

				if (m_VScrollBar)
				{
					SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};	
					::GetScrollInfo (m_VScrollBar, SB_CTL, &si);
					si.nPos = 0;
					si.fMask = SIF_POS;
					m_nVScrollPos = ::SetScrollInfo (m_VScrollBar, SB_CTL, &si, TRUE);
				}
				if (m_HScrollBar)
				{
					SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
					::GetScrollInfo (m_HScrollBar, SB_CTL, &si);
					si.nPos = 0;
					si.fMask = SIF_POS;
					m_nHScrollPos = ::SetScrollInfo (m_HScrollBar, SB_CTL, &si, TRUE);
				}

				Fire_MouseDown(wParam, x, y);
				return 0;
			}
		}
		if (xpos < m_nFixedCols) 
		{
			if (m_bAllowBigSelection)
			{
				m_bBigSelectionY = TRUE;
				m_bNoFire = TRUE;
				put_Col(0);
				m_bNoFire = FALSE;
				put_Row(ypos - m_nFixedRows);
				put_ColSel(m_nCols - m_nFixedCols - 1);
				if (m_bRedraw) InvalidateRect(NULL, FALSE);
				m_nOldCell.y = ypos;
				::SetTimer(m_hWnd, ID_BIGSELECT, 100, NULL);
			}
			else xpos = m_nFixedCols;

			Fire_MouseDown(wParam, x, y);
			return 0;
		}
		if (ypos < m_nFixedRows) 
		{
			if (m_bAllowBigSelection)
			{
				m_bBigSelectionX = TRUE;
				m_bNoFire = TRUE;
				put_Row(0);
				m_bNoFire = FALSE;
				put_Col(xpos - m_nFixedCols);
				put_RowSel(m_nRows - m_nFixedRows - 1);
				if (m_bRedraw) InvalidateRect(NULL, FALSE);
				m_nOldCell.x = xpos;
				::SetTimer(m_hWnd, ID_BIGSELECT, 100, NULL);
			}
			else ypos = m_nFixedRows;
	
			Fire_MouseDown(wParam, x, y);
			return 0;
		}
		if (xpos >= m_nFixedCols && ypos >= m_nFixedRows && xpos < m_nCols && ypos < m_nRows)
		{
			switch(m_eSelectionMode)
			{
			case rgridSelectionFree:
				m_bNoFire = TRUE;
				put_Col(xpos - m_nFixedCols);
				m_bNoFire = FALSE;
				put_Row(ypos - m_nFixedRows);
				m_pMatrix->put_Selected(xpos, ypos, TRUE);
				break;
			case rgridSelectionByRow:
				m_bNoFire = TRUE;
				put_Col(0);
				m_bNoFire = FALSE;
				put_Row(ypos - m_nFixedRows);
				put_ColSel(m_nCols - m_nFixedCols - 1);
				break;
			case rgridSelectionByColumn:
				m_bNoFire = TRUE;
				put_Row(0);
				m_bNoFire = FALSE;
				put_Col(xpos - m_nFixedCols);
				put_RowSel(m_nRows - m_nFixedRows - 1);
				break;
			}
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
			m_bSelection = TRUE;
			m_nOldCell.x = xpos;
			m_nOldCell.y = ypos;
			::SetTimer(m_hWnd, ID_SELECT, 100, NULL);
		}
	}

	Fire_MouseDown(wParam, x, y);
	return 0;
}

LRESULT CGrid::OnLButtonUP(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	m_bMouseDown = FALSE;

	Fire_MouseUp(wParam, LOWORD(lParam), HIWORD(lParam));

	KillTimer(ID_SELECT);
	KillTimer(ID_BIGSELECT);

	m_nClicks++;
	if (m_nClicks == 2)
	{
		KillTimer(ID_CLICKS);
		m_nClicks = 0;
		Fire_DblClick();
	}

	m_bColResize = FALSE;
	m_bRowResize = FALSE;
	m_bSelection = FALSE;
	m_bBigSelectionX = FALSE;
	m_bBigSelectionY = FALSE;
	
	return 0;
}

LRESULT CGrid::OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	long xpos = LOWORD(lParam);
	long ypos = HIWORD(lParam);

	Fire_MouseMove(wParam, xpos, ypos);

	m_nMousePos.x = xpos;
	m_nMousePos.y = ypos;

	if (m_bColResize && (m_eAllowUserResizing == rgridResizeColumns || m_eAllowUserResizing == rgridResizeBoth))
	{
		m_pColWidths[m_nResizedCell] += xpos - m_nOldPos;
		if (m_pColWidths[m_nResizedCell] < 1) m_pColWidths[m_nResizedCell] = 1;
		if (xpos - m_nOldPos) 
		{
			CalculateWidth(m_nCols);
			CalculateFixedWidth(m_nFixedCols);
			CalculateXPage(m_nCols);
			CalculateXMax(m_nCols);
			
			if (m_VScrollBar)
			{
				SCROLLINFO si;
				ZeroMemory(&si, sizeof(SCROLLINFO));
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE;
				si.nMin = 0;
				si.nMax = m_nMaxWidth;
				::SetScrollInfo(m_HScrollBar, SB_CTL, &si, TRUE);
			}
			if (m_HScrollBar && m_BitmapSize.x > m_nTotalWidth)
			{
				DestroyScrollBar(&m_HScrollBar, SBS_HORZ, TRUE);
				m_BitmapSize.y += 15;
				put_Rows(m_nRows);
			}
			if (!m_HScrollBar && m_BitmapSize.x < m_nTotalWidth)
			{
				put_Cols(m_nCols);
			}
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		m_nOldPos = xpos;
		Fire_ColWidthChange(m_nResizedCell);
	}
	if (m_bRowResize && (m_eAllowUserResizing == rgridResizeRows || m_eAllowUserResizing == rgridResizeBoth))
	{
		m_pRowHeights[m_nResizedCell] += ypos - m_nOldPos;
		if (m_pRowHeights[m_nResizedCell] < m_nRowHeightMin) m_pRowHeights[m_nResizedCell] = m_nRowHeightMin;
		if (ypos - m_nOldPos) 
		{
			CalculateHeight(m_nRows);
			CalculateFixedHeight(m_nFixedRows);
			CalculateYPage(m_nRows);
			CalculateYMax(m_nRows);
			if (m_VScrollBar)
			{
				SCROLLINFO si;
				ZeroMemory(&si, sizeof(SCROLLINFO));
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE;
				si.nMin = 0;
				si.nMax = m_nMaxHeight;
				::SetScrollInfo(m_VScrollBar, SB_CTL, &si, TRUE);
			}
			if (m_VScrollBar && m_BitmapSize.y > m_nTotalHeight)
			{
				DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
				m_BitmapSize.x += 15;
			}
			if (!m_VScrollBar && m_BitmapSize.y < m_nTotalHeight)
			{
				put_Rows(m_nRows);
			}
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		m_nOldPos = ypos;
		Fire_RowHeightChange(m_nResizedCell);
	}
	if (m_bSelection)
	{
		GetCellNumber(&xpos, &ypos);

		if (xpos < m_nFixedCols && xpos > -1) xpos = m_nFixedCols;
		if (ypos < m_nFixedRows && ypos > -1) ypos = m_nFixedRows;
		if (xpos >= m_nFixedCols && ypos >= m_nFixedRows && xpos < m_nCols && ypos < m_nRows)
		{
			if (m_nOldCell.x != xpos || m_nOldCell.y != ypos)
			{
				m_nOldCell.x = xpos;
				m_nOldCell.y = ypos;

				switch(m_eSelectionMode)
				{
				case rgridSelectionFree:
					if (xpos != -1) put_ColSel(xpos - m_nFixedCols);
					if (ypos != -1) put_RowSel(ypos - m_nFixedRows);
					break;
				case rgridSelectionByRow:
					if (ypos != -1) put_RowSel(ypos - m_nFixedRows);
					break;
				case rgridSelectionByColumn:
					if (xpos != -1) put_ColSel(xpos - m_nFixedCols);
					break;
				}
			}
		}
	}

	if (m_bBigSelectionX)
	{
		GetCellNumber(&xpos, &ypos);
		if (xpos < m_nFixedCols) xpos = m_nFixedCols;
		if (xpos >= m_nFixedCols && xpos < m_nCols)
		{
			if (m_nOldCell.x != xpos)
			{
				m_nOldCell.x = xpos;
				put_ColSel(xpos - m_nFixedCols);
			}
		}
	}

	if (m_bBigSelectionY)
	{
		GetCellNumber(&xpos, &ypos);
		if (ypos < m_nFixedRows) ypos = m_nFixedRows;
		if (ypos >= m_nFixedRows && ypos < m_nRows)
		{
			if (m_nOldCell.y != ypos)
			{
				m_nOldCell.y = ypos;
				put_RowSel(ypos - m_nFixedRows);
			}
		}
	}

	return 0;
}

LRESULT CGrid::OnHScroll(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	if (m_bMouseDown)
	{
		KillTimer(ID_SELECT);
		KillTimer(ID_BIGSELECT);
		KillTimer(ID_CLICKS);
		m_nClicks = 0;
				
		m_bColResize = FALSE;
		m_bRowResize = FALSE;
		m_bSelection = FALSE;
		m_bBigSelectionX = FALSE;
		m_bBigSelectionY = FALSE;
	}

	Fire_HScroll();

	int nScrollCode = (int)LOWORD(wParam);
	int nPos = (int)HIWORD(wParam);

	SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
    ::GetScrollInfo (m_HScrollBar, SB_CTL, &si);

    switch (nScrollCode)
    {
	case SB_LINERIGHT:
		si.nPos++;
		break;
	case SB_LINELEFT:
		si.nPos--;
		break;
	case SB_PAGERIGHT:
		si.nPos += m_nXPage;
		break;
	case SB_PAGELEFT:
		si.nPos -= m_nXPage;
		break;
	case SB_THUMBTRACK:
    case SB_THUMBPOSITION:
		si.nPos = nPos + si.nMin;
		break;
	}
	
	si.fMask = SIF_POS;
    m_nHScrollPos = ::SetScrollInfo (m_HScrollBar, SB_CTL, &si, TRUE);

	if (!m_bScrollTrack)
	{
		if (nScrollCode != SB_THUMBTRACK) if (m_bRedraw) ::InvalidateRect(m_hWnd, NULL, FALSE);
	}
	else if (m_bRedraw) ::InvalidateRect(m_hWnd, NULL, FALSE);
		
	return 0;
}

LRESULT CGrid::OnVScroll(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	if (m_bMouseDown)
	{
		KillTimer(ID_SELECT);
		KillTimer(ID_BIGSELECT);
		KillTimer(ID_CLICKS);
		m_nClicks = 0;
				
		m_bColResize = FALSE;
		m_bRowResize = FALSE;
		m_bSelection = FALSE;
		m_bBigSelectionX = FALSE;
		m_bBigSelectionY = FALSE;
	}

	Fire_VScroll();

	int nScrollCode = (int)LOWORD(wParam);
	int nPos = (int)HIWORD(wParam);

	SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
    ::GetScrollInfo (m_VScrollBar, SB_CTL, &si);

    switch (nScrollCode)
    {
	case SB_PAGEUP:
		si.nPos -= m_nYPage;
		break;
	case SB_PAGEDOWN:
		si.nPos += m_nYPage;
		break;
	case SB_LINEUP:
		si.nPos--;
		break;
	case SB_LINEDOWN:
		si.nPos++;
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
    	si.nPos = nPos + si.nMin; 
		break;
    }

	si.fMask = SIF_POS;

	m_nVScrollPos = ::SetScrollInfo (m_VScrollBar, SB_CTL, &si, TRUE);

	if (!m_bScrollTrack)
	{
		if (nScrollCode != SB_THUMBTRACK) if (m_bRedraw) ::InvalidateRect(m_hWnd, NULL, FALSE);
	}
	else if (m_bRedraw) ::InvalidateRect(m_hWnd, NULL, FALSE);

	return 0;
}

LRESULT CGrid::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	long x, y;

	x = m_nMousePos.x;
	y = m_nMousePos.y;
	GetCellNumber(&x, &y);

	if (focus != GetFocus())
	{
		KillTimer(ID_SELECT);
		KillTimer(ID_BIGSELECT);
		KillTimer(ID_CLICKS);
		KillTimer(ID_KEYPRESS);
		
		return 0;
	}
	
	if (wParam == ID_SELECT || wParam == ID_BIGSELECT)
	{
		if (x >= m_nHScrollPos + m_nFixedCols + m_nXPage && x < m_nCols)
		{
			
			if (m_HScrollBar) 
			{
				Fire_HScroll();
				
				SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
				::GetScrollInfo (m_HScrollBar, SB_CTL, &si);
				
				si.nPos++;
							
				si.fMask = SIF_POS;
				m_nHScrollPos = ::SetScrollInfo (m_HScrollBar, SB_CTL, &si, TRUE);
			}
		}
		if (x < m_nFixedCols && x > -1)
		{
			if (m_HScrollBar) 
			{
				Fire_HScroll();
				
				SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
				::GetScrollInfo (m_HScrollBar, SB_CTL, &si);
				
				si.nPos--;
							
				si.fMask = SIF_POS;
				m_nHScrollPos = ::SetScrollInfo (m_HScrollBar, SB_CTL, &si, TRUE);
			}
		}

		if (y >= m_nVScrollPos + m_nFixedRows + m_nYPage && y < m_nRows)
		{
			if (m_VScrollBar) 
			{
				Fire_VScroll();
				
				SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
				::GetScrollInfo (m_VScrollBar, SB_CTL, &si);
				
				si.nPos++;
							
				si.fMask = SIF_POS;
				m_nVScrollPos = ::SetScrollInfo (m_VScrollBar, SB_CTL, &si, TRUE);
			}
		}
		if (y < m_nFixedRows && y > -1)
		{
			if (m_VScrollBar) 
			{
				Fire_VScroll();
				
				SCROLLINFO si = {sizeof(SCROLLINFO), SIF_PAGE|SIF_POS|SIF_RANGE|SIF_TRACKPOS, 0, 0, 0, 0, 0};
				::GetScrollInfo (m_VScrollBar, SB_CTL, &si);
				
				si.nPos--;
							
				si.fMask = SIF_POS;
				m_nVScrollPos = ::SetScrollInfo (m_VScrollBar, SB_CTL, &si, TRUE);
			}
		}

		if (x >= m_nFixedCols && y >= m_nFixedRows && x >= 0 && x < m_nCols && y < m_nRows && wParam == ID_SELECT)
		{
			if (m_nOldCell.x != x || m_nOldCell.y != y)
			{
				m_nOldCell.x = x;
				m_nOldCell.y = y;
	
				switch(m_eSelectionMode)
				{
				case rgridSelectionFree:
					put_ColSel(x - m_nFixedCols);
					put_RowSel(y - m_nFixedRows);
					break;
				case rgridSelectionByRow:
					put_RowSel(y - m_nFixedRows);
					break;
				case rgridSelectionByColumn:
					put_ColSel(x - m_nFixedCols);
					break;
				}
			}
		}

		if (wParam == ID_BIGSELECT)
		{
			if (m_bBigSelectionX)
			{
				if (m_nOldCell.x != x)
				{
					m_nOldCell.x = x;
					put_ColSel(x - m_nFixedCols);
				}				
			}
			if (m_bBigSelectionY)
			{
				if (m_nOldCell.y != y)
				{
					m_nOldCell.y = y;
					put_RowSel(y - m_nFixedCols);
				}
			}
		}
	}

	if (wParam == ID_CLICKS)
	{
		KillTimer(ID_CLICKS);
		if (m_nClicks == 1) Fire_Click();
		if (m_nClicks == 2) Fire_DblClick();
		m_nClicks = 0;
	}

	if (wParam == ID_KEYPRESS)
	{
		KillTimer(ID_KEYPRESS);
		m_bDoKeyPress = FALSE;
	}

	return 0;
}

LRESULT CGrid::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	Fire_KeyDown((short)wParam, GetKeyState(VK_SHIFT));
	if (!m_bDoKeyPress && m_bKeyUp) 
	{
		::SetTimer(m_hWnd, ID_KEYPRESS, 100, NULL);
		m_bDoKeyPress = TRUE;
	}
	m_bKeyUp = FALSE;


	return 0;
}
LRESULT CGrid::OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!m__bEnabled) return S_OK;

	Fire_KeyUp((short)wParam, GetKeyState(VK_SHIFT));
		
	if (m_bDoKeyPress) Fire_KeyPress((int)wParam);
	m_bDoKeyPress = FALSE;
	m_bKeyUp = TRUE;

	return 0;
}

LRESULT CGrid::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	m_BitmapSize.x = LOWORD(lParam); 
	m_BitmapSize.y = HIWORD(lParam);

#ifdef UNDER_CE
	if (hDC)
	{
	/*	SelectObject(hDC, hBitmapOld);
		DeleteObject(hBitmap);
		hBitmap = NULL;
		hBitmap = CreateCompatibleBitmap(GetDC(), m_BitmapSize.x, m_BitmapSize.y);
		/*DeleteDC(hDC);
		hDC = NULL;*/
	}

/*	RECT r, pos;
	GetClientRect(&r);
		
	if (m_eBorderStyle == rgridBorderSingle)
	{
		r.left++;
		r.top++;
		r.right--;
		r.bottom--;
	}

	/*if (m_HScrollBar) 
	{
		DestroyScrollBar(&m_HScrollBar, SBS_HORZ, FALSE);
		pos.left = r.left;
		pos.top = r.bottom - 15;
		pos.right = r.right - r.left - ((m_VScrollBar) ? 15 : 0);
		pos.bottom = 15;
		CalculateXMax(m_nCols);
		CalculateXPage(m_nCols);
		m_HScrollBar = CreateScrollBar(SBS_HORZ, &pos);
		m_BitmapSize.y -= 15;
	}
		
	if (m_VScrollBar)
	{
		DestroyScrollBar(&m_VScrollBar, SBS_VERT, FALSE);
		pos.left = r.right;
		pos.top = r.top;
		pos.right = 15;
		pos.bottom = r.bottom - r.top - ((m_HScrollBar) ? 15 : 0);
		CalculateYMax(m_nRows);
		CalculateYPage(m_nRows);
		m_VScrollBar = CreateScrollBar(SBS_VERT, &pos);
		m_BitmapSize.x -= 15;
	}*/
	if (m_HScrollBar) DestroyScrollBar(&m_HScrollBar, SBS_HORZ, FALSE);
	if (m_VScrollBar) DestroyScrollBar(&m_VScrollBar, SBS_VERT, FALSE);
	put_Cols(m_nCols);
	put_Rows(m_nRows);
#endif
	
	return 0;
}

LRESULT CGrid::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// TODO : Add Code for message handler. Call DefWindowProc if necessary.
	return 1;
}

//----------------------------------------------------------------------------------------------------------

STDMETHODIMP CGrid::get_Rows(long *pVal)
{
	*pVal = m_nRows;

	return S_OK;
}

STDMETHODIMP CGrid::put_Rows(long newVal)
{
	if (newVal < 0) return Error(_T("Invalid Row Value"));
	if (newVal < m_nFixedRows) return Error(_T("Rows must be equal or greater than FixedRows value"));

	m_pMatrix->ChangeRows(newVal);

	if (m_nRows != newVal)
	{
		long *tmp = (long*)LocalAlloc(LPTR, newVal * sizeof(long));
		if (m_pRowHeights)
		{
			memcpy(tmp, m_pRowHeights, ((newVal > m_nRows) ? m_nRows : newVal) * sizeof(long));
			if (newVal > m_nRows)
			{
				for (long i = m_nRows; i < newVal; i++)
					tmp[i] = m_nRowHeightMin;
			}
		}
		else
		{
			for (long i = 0; i < newVal; i++)
				tmp[i] = m_nRowHeightMin;
		}
		LocalFree(m_pRowHeights);
		m_pRowHeights = tmp;
	}
	else if (!m_pRowHeights)
	{
		m_pRowHeights = (long*)LocalAlloc(LPTR, newVal);
		for (long i = 0; i < newVal; i++)
			m_pRowHeights[i] = m_nRowHeightMin;
	}

	if (newVal - m_nFixedRows <= m_nRow) m_nRow = 0;

	CalculateHeight(newVal);
	CalculateFixedHeight(m_nFixedRows);
	CalculateYMax(newVal);

	if (m_hWnd && (m_eScrollBars == rgridScrollBarBoth || m_eScrollBars == rgridScrollBarVertical))
	{
		RECT r, pos;

		GetClientRect(&r);

		if (m_eBorderStyle == rgridBorderSingle)
		{
			r.left++;
			r.top++;
			r.right--;
			r.bottom--;
		}
		
		if (m_HScrollBar) 
		{
			r.bottom -= 15;
		}
		
		if ((r.bottom - r.top) < m_nTotalHeight)
		{	
			if (m_VScrollBar) DestroyScrollBar(&m_VScrollBar, SBS_VERT, FALSE);
			else m_BitmapSize.x -= 15;

			if (m_HScrollBar)
			{
				DestroyScrollBar(&m_HScrollBar, SBS_HORZ, FALSE);
				pos.left = r.left;
				pos.top = r.bottom;
				pos.right = r.right - r.left - 15;
				pos.bottom = 15;
				CalculateXMax(m_nCols);
				CalculateXPage(m_nCols);
				m_HScrollBar = CreateScrollBar(SBS_HORZ, &pos);
			}

			pos.left = r.right - 15;
			pos.top = r.top;
			pos.right = 15;
			pos.bottom = r.bottom - r.top;
			CalculateYMax(newVal);
			CalculateYPage(newVal);
			m_VScrollBar = CreateScrollBar(SBS_VERT, &pos);
		}
		else if (m_VScrollBar)
		{
			DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
			m_BitmapSize.x += 15;
			if (m_HScrollBar)
			{
				DestroyScrollBar(&m_HScrollBar, SBS_HORZ, FALSE);

				pos.left = r.left;
				pos.top = r.bottom;
				pos.right = r.right - r.left;
				pos.bottom = 15;
				CalculateXMax(m_nCols);
				CalculateXPage(m_nCols);
				m_HScrollBar = CreateScrollBar(SBS_HORZ, &pos);
			}
		}
	}

	m_nRows = newVal;
	CalculateYPage(newVal);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	


//	SetFocus();

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedRows(long *pVal)
{
	*pVal = m_nFixedRows;

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedRows(long newVal)
{
	if (newVal < 0) return Error(_T("Invalid Row Value"));
	if (newVal > m_nRows) return Error(_T("FixedRows must be equal or less than Rows value"));

	if (m_pRowHeights)CalculateFixedHeight(newVal);

	m_nFixedRows = newVal;

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	
	return S_OK;
}

STDMETHODIMP CGrid::get_Cols(long *pVal)
{
	*pVal = m_nCols;

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::put_Cols(long newVal)
{
	if (newVal < 0) return Error(_T("Invalid Column Value"));
	if (newVal < m_nFixedCols) return Error(_T("Cols must be equal or greater than FixedCols value"));

	m_pMatrix->ChangeCols(newVal);

	if (m_nCols != newVal)
	{
		long *tmp = (long*)LocalAlloc(LPTR, newVal * sizeof(long));
		if (m_pColWidths)
		{
			memcpy(tmp, m_pColWidths, newVal * sizeof(long));
			if (newVal > m_nCols)
			{
				for (long i = m_nCols; i < newVal; i++)
					tmp[i] = 40;
			}
		} else
		{
			for (long i = 0; i < newVal; i++)
				tmp[i] = 40;
		}
		LocalFree(m_pColWidths);
		m_pColWidths = tmp;
	}
	else if (!m_pColWidths)
	{
		m_pColWidths = (long*)LocalAlloc(LPTR, newVal);
		for (long i = 0; i < newVal; i++)
			m_pColWidths[i] = 40;
	}

	if (newVal - m_nFixedCols <= m_nCol) m_nCol = 0;

	CalculateWidth(newVal);
	CalculateFixedWidth(m_nFixedCols);
	CalculateXMax(newVal);

	if (m_hWnd && (m_eScrollBars == rgridScrollBarBoth || m_eScrollBars == rgridScrollBarHorizontal))
	{
		RECT r, pos;
		GetClientRect(&r);
		
		if (m_eBorderStyle == rgridBorderSingle)
		{
			r.left++;
			r.top++;
			r.right--;
			r.bottom--;
		}

		if (m_VScrollBar) 
			r.right -= 15;

		if ((r.right - r.left) < m_nTotalWidth)
		{
			if (m_HScrollBar) DestroyScrollBar(&m_HScrollBar, SBS_HORZ, FALSE);
			else m_BitmapSize.y -= 15;

			if (m_VScrollBar)
			{
				DestroyScrollBar(&m_VScrollBar, SBS_VERT, FALSE);

				pos.left = r.right;
				pos.top = r.top;
				pos.right = 15;
				pos.bottom = r.bottom - r.top - 15;
				CalculateYMax(m_nRows);
				CalculateYPage(m_nRows);
				m_VScrollBar = CreateScrollBar(SBS_VERT, &pos);
			}

			pos.left = r.left;
			pos.top = r.bottom - 15;
			pos.right = r.right - r.left;
			pos.bottom = 15;
			CalculateXMax(newVal);
			CalculateXPage(newVal);
			m_HScrollBar = CreateScrollBar(SBS_HORZ, &pos);
		}
		else if (m_HScrollBar)
		{
			DestroyScrollBar(&m_HScrollBar, SBS_HORZ, TRUE);
			m_BitmapSize.y += 15;
			if (m_VScrollBar)
			{
				DestroyScrollBar(&m_VScrollBar, SBS_VERT, FALSE);

				pos.left = r.right;
				pos.top = r.top;
				pos.right = 15;
				pos.bottom = r.bottom - r.top;
				CalculateYMax(m_nRows);
				CalculateYPage(m_nRows);
				m_VScrollBar = CreateScrollBar(SBS_VERT, &pos);
			}
		}
	}

	m_nCols = newVal;
	CalculateXPage(newVal);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedCols(long *pVal)
{
	*pVal = m_nFixedCols;

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedCols(long newVal)
{
	if (newVal < 0) return Error(_T("Invalid Column Value"));
	if (newVal > m_nCols) return Error(_T("FixedCols must be equal or less than Cols value"));

	if (m_pColWidths) CalculateFixedWidth(newVal);

	m_nFixedCols = newVal;

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_BackColor(OLE_COLOR *pVal)
{
	*pVal = m__clrBackColor;

	return S_OK;
}

STDMETHODIMP CGrid::put_BackColor(OLE_COLOR newVal)
{
	m__clrBackColor = newVal;
	DeleteObject(m_hBackColor);
	m_hBackColor = CreateSolidBrush(TranslateColor(newVal));
	for (long j = m_nFixedRows; j < m_nRows; j++)
		for (long i = m_nFixedCols; i < m_nCols; i++)
		{
			m_pMatrix->put_BackColor(i, j, 0);
		}

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_BackColorBkg(OLE_COLOR *pVal)
{
	*pVal = m_clrBackColorBkg;

	return S_OK;
}

STDMETHODIMP CGrid::put_BackColorBkg(OLE_COLOR newVal)
{
	m_clrBackColorBkg = newVal;
	DeleteObject(hBackColorBkg);
	hBackColorBkg = CreateSolidBrush(TranslateColor(newVal));

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_BackColorFixed(OLE_COLOR *pVal)
{
	*pVal = m_clrBackColorFixed;

	return S_OK;
}

STDMETHODIMP CGrid::put_BackColorFixed(OLE_COLOR newVal)
{
	m_clrBackColorFixed = newVal;
	DeleteObject(hBackColorFixed);
	hBackColorFixed = CreateSolidBrush(TranslateColor(newVal));

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_GridLines(GridLineSettings *pVal)
{
	*pVal = m_eGridLines;

	return S_OK;
}

STDMETHODIMP CGrid::put_GridLines(GridLineSettings newVal)
{
	m_eGridLines = newVal;
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_GridLinesFixed(GridLineSettings *pVal)
{
	*pVal = m_eGridLinesFixed;

	return S_OK;
}

STDMETHODIMP CGrid::put_GridLinesFixed(GridLineSettings newVal)
{
	m_eGridLinesFixed = newVal;
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_GridColor(OLE_COLOR *pVal)
{
	*pVal = m_clrGridColor;

	return S_OK;
}

STDMETHODIMP CGrid::put_GridColor(OLE_COLOR newVal)
{
	m_clrGridColor = newVal;
	DeleteObject(hGridColor);
	hGridColor = CreatePen(PS_SOLID, 1, TranslateColor(newVal));
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_GridColorFixed(OLE_COLOR *pVal)
{
	*pVal = m_clrGridColorFixed;

	return S_OK;
}

STDMETHODIMP CGrid::put_GridColorFixed(OLE_COLOR newVal)
{
	m_clrGridColorFixed = newVal;
	DeleteObject(hGridColorFixed);
	hGridColorFixed = CreatePen(PS_SOLID, 1, TranslateColor(newVal));
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_AllowUserResizing(AllowUserResizeSettings *pVal)
{
	*pVal = m_eAllowUserResizing;

	return S_OK;
}

STDMETHODIMP CGrid::put_AllowUserResizing(AllowUserResizeSettings newVal)
{
	m_eAllowUserResizing = newVal;

	return S_OK;
}

STDMETHODIMP CGrid::get_ScrollBars(ScrollBarsSettings *pVal)
{
	*pVal = m_eScrollBars;

	return S_OK;
}

STDMETHODIMP CGrid::put_ScrollBars(ScrollBarsSettings newVal)
{
	m_eScrollBars = newVal;

	if (m_HScrollBar) 
	{
		DestroyScrollBar(&m_HScrollBar, SBS_HORZ, TRUE);
		m_BitmapSize.y += 15;
	}
	if (m_VScrollBar) 
	{
		DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
		m_BitmapSize.x += 15;
	}

	if (newVal == rgridScrollBarBoth)
	{
		put_Cols(m_nCols);
		put_Rows(m_nRows);
	}
	else if (newVal == rgridScrollBarVertical)
	{
		put_Rows(m_nRows);
	}
	else if (newVal == rgridScrollBarHorizontal)
	{
		put_Cols(m_nCols);
	}
	else
	{
		if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	}

	return S_OK;
}

STDMETHODIMP CGrid::get_BorderStyle(BorderStyleSettings *pVal)
{
	*pVal = m_eBorderStyle;

	return S_OK;
}

STDMETHODIMP CGrid::put_BorderStyle(BorderStyleSettings newVal)
{
	if (m_HScrollBar) 
	{
		DestroyScrollBar(&m_HScrollBar, SBS_HORZ, FALSE);
		m_BitmapSize.y += 15;
	}
	if (m_VScrollBar) 
	{
		DestroyScrollBar(&m_VScrollBar, SBS_VERT, FALSE);
		m_BitmapSize.x += 15;
	}
	if (newVal != m_eBorderStyle)
	{
		if (newVal == rgridBorderNone)
		{
			m_BitmapSize.x += 2;
			m_BitmapSize.y += 2;
		}
		else
		{
			m_BitmapSize.x -= 2;
			m_BitmapSize.y -= 2;
		}
	}
	m_eBorderStyle = newVal;
	put_ScrollBars(m_eScrollBars);
	
	return S_OK;
}

STDMETHODIMP CGrid::get_ScrollTrack(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bScrollTrack ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_ScrollTrack(VARIANT_BOOL newVal)
{
	m_bScrollTrack = newVal;

	return S_OK;
}

STDMETHODIMP CGrid::get_ForeColor(OLE_COLOR *pVal)
{
	*pVal = m__clrForeColor;

	return S_OK;
}

STDMETHODIMP CGrid::put_ForeColor(OLE_COLOR newVal)
{
	m__clrForeColor = newVal;
	for (long j = m_nFixedRows; j < m_nRows; j++)
		for (long i = m_nFixedCols; i < m_nCols; i++)
		{
			m_pMatrix->put_ForeColor(i, j, 0);
		}
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_ForeColorFixed(OLE_COLOR *pVal)
{
	*pVal = m_clrForeColorFixed;

	return S_OK;
}

STDMETHODIMP CGrid::put_ForeColorFixed(OLE_COLOR newVal)
{
	m_clrForeColorFixed = newVal;
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_ForeColorSel(OLE_COLOR *pVal)
{
	*pVal = m_clrForeColorSel;

	return S_OK;
}

STDMETHODIMP CGrid::put_ForeColorSel(OLE_COLOR newVal)
{
	m_clrForeColorSel = newVal;
	for (long j = m_nFixedRows; j < m_nRows; j++)
		for (long i = m_nFixedCols; i < m_nCols; i++)
		{
			m_pMatrix->put_ForeColorSel(i, j, 0);
		}
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_BackColorSel(OLE_COLOR *pVal)
{
	*pVal = m_clrBackColorSel;

	return S_OK;
}

STDMETHODIMP CGrid::put_BackColorSel(OLE_COLOR newVal)
{
	m_clrBackColorSel = newVal;
	DeleteObject(m_hBackColorSel);
	m_hBackColorSel = CreateSolidBrush(TranslateColor(newVal));
	for (long j = m_nFixedRows; j < m_nRows; j++)
		for (long i = m_nFixedCols; i < m_nCols; i++)
		{
			m_pMatrix->put_BackColorSel(i, j, 0);
		}
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_RowHeightMin(long *pVal)
{
	*pVal = m_nRowHeightMin;

	return S_OK;
}

STDMETHODIMP CGrid::put_RowHeightMin(long newVal)
{
	if (newVal < 0) return Error(_T("Invalid RowHeight Value"));

	m_nRowHeightMin = newVal;

	if (m_pRowHeights)
	{
		for (long i = 0; i < m_nRows; i++)
			if (m_pRowHeights[i] < newVal) 
				m_pRowHeights[i] = newVal;
	}
	else
	{
		m_pRowHeights = (long*)LocalAlloc(LPTR, m_nRows);
		for (long i = 0; i < m_nRows; i++)
			m_pRowHeights[i] = m_nRowHeightMin;
	}

	CalculateHeight(m_nRows);
	CalculateFixedHeight(m_nFixedRows);
	CalculateYPage(m_nRows);
	CalculateYMax(m_nRows);
	
	if (m_VScrollBar && m_BitmapSize.y > m_nTotalHeight)
	{
		DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
		m_BitmapSize.x += 15;
	}

	if (m_BitmapSize.y > m_nTotalHeight)
	{
		if (m_VScrollBar)
		{
			DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
			m_BitmapSize.x += 15;
		}	
		put_Rows(m_nRows);
	}
	else
	{
		if (m_VScrollBar)
			SetScrollbarInfo(m_VScrollBar, SBS_VERT);
		else
			put_Rows(m_nRows);
	}

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);	
	}

	return S_OK;
}

STDMETHODIMP CGrid::get_TextMatrix(long Row, long Col, BSTR *pVal)
{
	if (Row >= m_nRows || Col >= m_nCols || Row < 0 || Col < 0) return Error(_T("Subscript out of range."));
	m_pMatrix->get_Text(Col, Row, pVal);

	return S_OK;
}

STDMETHODIMP CGrid::put_TextMatrix(long Row, long Col, BSTR newVal)
{
	if (Row >= m_nRows || Col >= m_nCols || Row < 0 || Col < 0) return Error(_T("Subscript out of range."));
	m_pMatrix->put_Text(Col, Row, newVal);
	
	if (Col < m_nFixedCols && Row < m_nFixedRows) 
		if (m_hWnd)
		{
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		else
			if (m_bRedraw) FireViewChange();	
		CalculateXPage(m_nCols);
		CalculateYPage(m_nRows);
		if (Col < m_nFixedCols && Row >= m_nVScrollPos && Row <= m_nVScrollPos + m_nYPage) 
			if (m_hWnd)
			{
				if (m_bRedraw) InvalidateRect(NULL, FALSE);
			}
			else
				if (m_bRedraw) FireViewChange();	
		if (Row < m_nFixedRows && Col >= m_nHScrollPos && Col <= m_nHScrollPos + m_nXPage) 
					if (m_hWnd)
					{
						if (m_bRedraw) InvalidateRect(NULL, FALSE);
					}
					else
						if (m_bRedraw) FireViewChange();	
		if (Row >= m_nVScrollPos && Row <= m_nVScrollPos + m_nYPage && Col >= m_nHScrollPos && Col <= m_nHScrollPos + m_nXPage) 
			if (m_hWnd)
			{
				if (m_bRedraw) InvalidateRect(NULL, FALSE);
			}
			else
				if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_TextArray(long index, BSTR *pVal)
{
	if (index < 0 || index >= m_nCols * m_nRows) Error(_T("Subscript out of range."));
	long col, row;
	col = index % m_nRows;
	row = index / m_nRows;
	m_pMatrix->get_Text(col, row, pVal);

	return S_OK;
}

STDMETHODIMP CGrid::put_TextArray(long index, BSTR newVal)
{
	if (index < 0 || index >= m_nCols * m_nRows) Error(_T("Subscript out of range."));
	
	long Col = index % m_nRows;
	long Row = index / m_nRows;
	m_pMatrix->put_Text(Col, Row, newVal);

	if (Col < m_nFixedCols && Row < m_nFixedRows) 
		if (m_hWnd)
		{
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		else
			if (m_bRedraw) FireViewChange();	
	CalculateXPage(m_nCols);
	CalculateYPage(m_nRows);
	if (Col < m_nFixedCols && Row >= m_nVScrollPos && Row <= m_nVScrollPos + m_nYPage) 
		if (m_hWnd)
		{
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		else
			if (m_bRedraw) FireViewChange();	
	if (Row < m_nFixedRows && Col >= m_nHScrollPos && Col <= m_nHScrollPos + m_nXPage) 
		if (m_hWnd)
		{
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		else
			if (m_bRedraw) FireViewChange();	
	if (Row >= m_nVScrollPos && Row <= m_nVScrollPos + m_nYPage && Col >= m_nHScrollPos && Col <= m_nHScrollPos + m_nXPage) 
		if (m_hWnd)
		{
			if (m_bRedraw) InvalidateRect(NULL, FALSE);
		}
		else
			if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_Row(long *pVal)
{
	*pVal = m_nRow;

	return S_OK;
}

STDMETHODIMP CGrid::put_Row(long newVal)
{
	//	DebugBreak();
	
	if (newVal < 0 || newVal >= m_nRows - m_nFixedRows) return Error(_T("Invalid Row Value"));
	long startr, endr, startc, endc;
	
	if ((m_nRowSel != -1) && (m_nColSel != -1))
	{
		if (m_nRow < m_nRowSel) 
		{
			startr = m_nRow;
			endr = m_nRowSel;
		} else
		{
			startr = m_nRowSel;
			endr = m_nRow;
		}
		if (m_nCol < m_nColSel)
		{
			startc = m_nCol;
			endc = m_nColSel;
		} else
		{
			startc = m_nColSel;
			endc = m_nCol;
		}
		
		if (startr >= m_nRows - m_nFixedRows) startr = m_nRows - m_nFixedRows - 1;
		if (startr < 0) startr = 0;
		if (endr >= m_nRows - m_nFixedRows) endr = m_nRows - m_nFixedRows - 1;
		if (endr < 0) endr = 0;
		
		for (long j = startr; j <= endr; j++)
			for (long i = startc; i <= endc; i++)
			{
				m_pMatrix->put_Selected(m_nFixedCols + i, m_nFixedRows + j, FALSE);
			}
	}
	
	if (!m_bNoFire) Fire_LeaveCell();

	m_nRow = newVal;
	m_nColSel = m_nCol;
	m_nRowSel = newVal;

	if (m_bRedraw) InvalidateRect(NULL, FALSE);

	if (!m_bNoFire) Fire_EnterCell();
	Fire_RowColChange();

	return S_OK;
}

STDMETHODIMP CGrid::get_Col(long *pVal)
{
	*pVal = m_nCol;

	return S_OK;
}

STDMETHODIMP CGrid::put_Col(long newVal)
{
	if (newVal < 0 || newVal >= m_nCols - m_nFixedCols) return Error(_T("Invalid Col Value"));
	long startr, endr, startc, endc;
	
	if ((m_nRowSel != -1) && (m_nColSel != -1))
	{
		if (m_nRow < m_nRowSel) 
		{
			startr = m_nRow;
			endr = m_nRowSel;
		} else
		{
			startr = m_nRowSel;
			endr = m_nRow;
		}
		if (m_nCol < m_nColSel)
		{
			startc = m_nCol;
			endc = m_nColSel;
		} else
		{
			startc = m_nColSel;
			endc = m_nCol;
		}
		if (startc >= m_nCols - m_nFixedCols) startc = m_nCols - m_nFixedCols - 1;
		if (startc < 0) startc = 0;
		if (endc >= m_nCols - m_nFixedCols) endc = m_nCols - m_nFixedCols - 1;
		if (endc < 0) endc = 0;
		
		if (m_nFixedRows != m_nRows)
		{
			for (long j = startr; j <= endr; j++)
				for (long i = startc; i <= endc; i++)
				{
					m_pMatrix->put_Selected(m_nFixedCols + i, m_nFixedRows + j, FALSE);
				}
		}
	}

	if (!m_bNoFire) Fire_LeaveCell();

	m_nCol = newVal;
	m_nColSel = newVal;
	m_nRowSel = m_nRow;

	if (m_bRedraw) InvalidateRect(NULL, FALSE);

	if (!m_bNoFire) Fire_EnterCell();
	Fire_RowColChange();

	return S_OK;
}

STDMETHODIMP CGrid::get_CellBackColor(OLE_COLOR *pVal)
{
	HBRUSH h;
	m_pMatrix->get_BackColor(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, pVal, &h);

	return S_OK;
}

STDMETHODIMP CGrid::put_CellBackColor(OLE_COLOR newVal)
{
	m_pMatrix->put_BackColor(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, newVal);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_CellForeColor(OLE_COLOR *pVal)
{
	m_pMatrix->get_ForeColor(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, pVal);	

	return S_OK;
}

STDMETHODIMP CGrid::put_CellForeColor(OLE_COLOR newVal)
{
	m_pMatrix->put_ForeColor(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, newVal);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_CellAlignment(AlignmentSettings *pVal)
{
	m_pMatrix->get_Alignment(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, pVal);

	return S_OK;
}

STDMETHODIMP CGrid::put_CellAlignment(AlignmentSettings newVal)
{
	m_pMatrix->put_Alignment(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, newVal);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_CellLeft(long *pVal)
{
	long left = m_rcPos.left + m_nTotalFixedWidth;

	for (long i = m_nHScrollPos; i < m_nCol; i++)
	{
		left += m_pColWidths[i + m_nFixedCols];
	}

	*pVal = left;

	return S_OK;
}

STDMETHODIMP CGrid::get_CellTop(long *pVal)
{
	long top = m_rcPos.top + m_nTotalFixedHeight;

	for (long j = m_nVScrollPos; j < m_nRow; j++)
	{
		top += m_pRowHeights[j + m_nFixedRows];
	}

	*pVal = top;

	return S_OK;
}

STDMETHODIMP CGrid::get_CellWidth(long *pVal)
{
	*pVal = m_pColWidths[m_nCol + m_nFixedCols] + 1;	

	return S_OK;
}

STDMETHODIMP CGrid::get_CellHeight(long *pVal)
{
	*pVal = m_pRowHeights[m_nRow + m_nFixedRows] + 1;

	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontName(BSTR *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		*pVal = SysAllocString(font.lfFaceName);
	}
	else
	{
		*pVal = SysAllocString(m_LogFont.lfFaceName);
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontName(BSTR newVal)
{
	if (_tcslen(newVal) >= 32) return Error(_T("Font name too long."));

	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	_tcscpy(font.lfFaceName, newVal);
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));
	
	if (m_bRedraw) InvalidateRect(NULL, FALSE);

	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontSize(long *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		*pVal = (-72 * font.lfHeight) / GetDeviceCaps(::GetDC(NULL), LOGPIXELSY);
	}
	else
	{
		*pVal = (-72 * m_LogFont.lfHeight) / GetDeviceCaps(::GetDC(NULL), LOGPIXELSY);
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontSize(long newVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	font.lfHeight = FontSize(newVal);
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontBold(VARIANT_BOOL *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
#pragma warning(disable: 4310)
		*pVal = (font.lfWeight == FW_BOLD) ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}
	else
	{
#pragma warning(disable: 4310)
		*pVal = (m_LogFont.lfWeight == FW_BOLD) ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontBold(VARIANT_BOOL newVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	font.lfWeight = (newVal) ? FW_BOLD : FW_NORMAL;
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontItalic(VARIANT_BOOL *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
#pragma warning(disable: 4310)
		*pVal = font.lfItalic ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}
	else
	{
#pragma warning(disable: 4310)
		*pVal = m_LogFont.lfItalic ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontItalic(VARIANT_BOOL newVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	font.lfItalic = (BOOL)newVal;
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontUnderline(VARIANT_BOOL *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
#pragma warning(disable: 4310)
		*pVal = font.lfUnderline ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}
	else
	{
#pragma warning(disable: 4310)
		*pVal = m_LogFont.lfUnderline ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontUnderline(VARIANT_BOOL newVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	font.lfUnderline = (BOOL)newVal;
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontWidth(long *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		*pVal = font.lfWidth;
	}
	else
	{
		*pVal = m_LogFont.lfWidth;
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontWidth(long newVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	font.lfWidth = newVal;
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
	return S_OK;
}

STDMETHODIMP CGrid::get_CellFontStrikeThrough(VARIANT_BOOL *pVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
#pragma warning(disable: 4310)
		*pVal = font.lfStrikeOut ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}
	else
	{
#pragma warning(disable: 4310)
		*pVal = m_LogFont.lfStrikeOut ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	}

	return S_OK;
}

STDMETHODIMP CGrid::put_CellFontStrikeThrough(VARIANT_BOOL newVal)
{
	long index;
	LOGFONT font;

	m_pMatrix->get_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, &index);

	if (index != -1)
	{
		m_pFontTable->GetLogFont(index, &font);
		m_pFontTable->_DeleteFont(index);
	}
	else
	{
		memcpy(&font, &m_LogFont, sizeof(LOGFONT));
	}
	font.lfStrikeOut = (BOOL)newVal;
	m_pMatrix->put_FontIndex(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, m_pFontTable->AddFont(&font));

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
	return S_OK;
}

STDMETHODIMP CGrid::put_ColAlignment(long index, AlignmentSettings newVal)
{
	if (index < 0 || index >= m_nRows) Error(_T("Invalid Index value."));

	for (long j = 0; j < m_nRows; j++)
	{
		m_pMatrix->put_Alignment(index, j, newVal);
	}

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_Text(BSTR *pVal)
{
	m_pMatrix->get_Text(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, pVal);

	return S_OK;
}

STDMETHODIMP CGrid::put_Text(BSTR newVal)
{
	m_pMatrix->put_Text(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, newVal);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_ColWidth(long index, long *pVal)
{
	*pVal = m_pColWidths[index];

	return S_OK;
}

STDMETHODIMP CGrid::put_ColWidth(long index, long newVal)
{
	if (index < -1 || index >= m_nCols) return Error(_T("Invalid Index Value"));
	if (newVal < -1) return Error(_T("Invalid ColWidth Value"));
	if (index == -1)
	{
		for (long i = 0; i < m_nCols; i++)
			if (newVal == -1) 
				m_pColWidths[i] = 40;
			else m_pColWidths[i] = newVal;
	}
	else
	{
		if (newVal > -1) m_pColWidths[index] = newVal;
		if (newVal == -1) m_pColWidths[index] = 40;	
	}
	
	CalculateWidth(m_nCols);
	CalculateFixedWidth(m_nFixedCols);
	CalculateXPage(m_nCols);
	CalculateXMax(m_nCols);
	if (m_HScrollBar && m_BitmapSize.x > m_nTotalWidth)
	{
		DestroyScrollBar(&m_HScrollBar, SBS_HORZ, TRUE);
		m_BitmapSize.y += 15;
	}
	if (m_BitmapSize.x > m_nTotalWidth)
	{
		if (m_HScrollBar)
		{
			DestroyScrollBar(&m_HScrollBar, SBS_HORZ, TRUE);
			m_BitmapSize.y += 15;
		}
		put_Cols(m_nCols);
	}
	else
	{
		if (m_HScrollBar)
			SetScrollbarInfo(m_HScrollBar, SBS_HORZ);
		else
			put_Cols(m_nCols);
	}

	if (m_bRedraw) InvalidateRect(NULL, FALSE);

	Fire_ColWidthChange(index);

	return S_OK;
}

STDMETHODIMP CGrid::get_ColIsVisible(long index, VARIANT_BOOL *pVal)
{
	*pVal = VARIANT_TRUE;
	if (index < m_nHScrollPos) *pVal = VARIANT_FALSE;
	CalculateXPage(m_nCols);
	if (index > m_nXPage + m_nHScrollPos) *pVal = VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGrid::get_ColPos(long index, long *pVal)
{
	long pos = 0;
	if (index < 0 || index >= m_nCols) return Error(_T("Invalid Column Value"));
	if (index < m_nFixedCols)
	{
		for (long i = 0; i < index; i++)
			pos += m_pColWidths[i];
		*pVal = pos;
	}	
	if (index >= m_nFixedCols)
	{
		CalculateFixedWidth(m_nFixedCols);
		if (index - m_nFixedCols < m_nHScrollPos)
		{
			for (long i = m_nHScrollPos; i > (index - m_nFixedCols); i--)
				pos += m_pColWidths[i + m_nFixedCols - 1];
			*pVal = m_nTotalFixedWidth - pos;
		}
		if (index - m_nFixedCols >= m_nHScrollPos)
		{
			for (long i = m_nHScrollPos; i < (index - m_nFixedCols); i++)
				pos += m_pColWidths[i + m_nFixedCols];
			*pVal = m_nTotalFixedWidth + pos;
		}
	}

	return S_OK;
}


STDMETHODIMP CGrid::get_RowHeight(long index, long *pVal)
{
	*pVal = m_pRowHeights[index];

	return S_OK;
}

STDMETHODIMP CGrid::put_RowHeight(long index, long newVal)
{
	if (index < -1 || index >= m_nRows) return Error(_T("Invalid Index Value"));
	if (newVal < -1) return Error(_T("Invalid RowHeight Value"));
	if (index == -1) 
	{
		for (long i = 0; i < m_nRows; i++)
			if (newVal == -1) 
				m_pRowHeights[i] = m_nRowHeightMin;
			else m_pRowHeights[i] = newVal;
	}
	else
	{
		if (newVal > -1) m_pRowHeights[index] = newVal;
		if (newVal == -1) m_pRowHeights[index] = m_nRowHeightMin;	
	}
	
	CalculateHeight(m_nRows);
	CalculateFixedHeight(m_nFixedRows);
	CalculateYPage(m_nRows);
	CalculateYMax(m_nRows);
	
	if (m_VScrollBar && m_BitmapSize.y > m_nTotalHeight)
	{
		DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
		m_BitmapSize.x += 15;
	}

	if (m_BitmapSize.y > m_nTotalHeight)
	{
		if (m_VScrollBar)
		{
			DestroyScrollBar(&m_VScrollBar, SBS_VERT, TRUE);
			m_BitmapSize.x += 15;
		}	
		put_Rows(m_nRows);
	}
	else
	{
		if (m_VScrollBar)
			SetScrollbarInfo(m_VScrollBar, SBS_VERT);
		else
			put_Rows(m_nRows);
	}

	if (m_bRedraw) InvalidateRect(NULL, FALSE);	

	Fire_RowHeightChange(index);

	return S_OK;
}

STDMETHODIMP CGrid::get_RowIsVisible(long index, VARIANT_BOOL *pVal)
{
	*pVal = VARIANT_TRUE;
	if (index < m_nVScrollPos) *pVal = VARIANT_FALSE;
	CalculateYPage(m_nRows);
	if (index > m_nYPage + m_nVScrollPos) *pVal = VARIANT_FALSE;	

	return S_OK;
}

STDMETHODIMP CGrid::get_RowPos(long index, long *pVal)
{
	long pos = 0;
	if (index < 0 || index >= m_nRows) return Error(_T("Invalid Row Value"));
	if (index < m_nFixedRows)
	{
		for (long i = 0; i < index; i++)
			pos += m_pRowHeights[i];
		*pVal = pos;
	}	
	if (index >= m_nFixedRows)
	{
		CalculateFixedHeight(m_nFixedRows);
		if (index - m_nFixedRows < m_nVScrollPos)
		{
			for (long i = m_nVScrollPos; i > (index - m_nFixedRows); i--)
				pos += m_pRowHeights[i + m_nFixedRows - 1];
			*pVal = m_nTotalFixedHeight - pos;
		}
		if (index - m_nFixedRows >= m_nVScrollPos)
		{
			for (long i = m_nVScrollPos; i < (index - m_nFixedRows); i++)
				pos += m_pRowHeights[i + m_nFixedRows];
			*pVal = m_nTotalFixedHeight + pos;
		}
	}	

	return S_OK;
}

STDMETHODIMP CGrid::get_ColSel(long *pVal)
{
	*pVal = m_nColSel;

	return S_OK;
}

STDMETHODIMP CGrid::put_ColSel(long newVal)
{
	if (newVal < -1 || newVal >= m_nCols - m_nFixedCols) return Error(_T("Invalid Col Value"));

	long startr, endr, startc, endc;

	if (m_nRow < m_nRowSel) 
	{
		startr = m_nRow;
		endr = m_nRowSel;
	} else
	{
		startr = m_nRowSel;
		endr = m_nRow;
	}
	if (m_nCol < m_nColSel)
	{
		startc = m_nCol;
		endc = m_nColSel;
	} else
	{
		startc = m_nColSel;
		endc = m_nCol;
	}

	if (m_nColSel != -1 && m_nRowSel != -1)
	{
		for (long j = startr; j <= endr; j++)
			for (long i = startc; i <= endc; i++)
			{
				m_pMatrix->put_Selected(m_nFixedCols + i, m_nFixedRows + j, FALSE);
			}
	}

	m_nColSel = newVal;

	if (newVal == -1)
	{
		m_nRowSel = -1;
	}
	else
	{
		if (m_nRow < m_nRowSel) 
		{
			startr = m_nRow;
			endr = m_nRowSel;
		} else
		{
			startr = m_nRowSel;
			endr = m_nRow;
		}
		if (m_nCol < m_nColSel)
		{
			startc = m_nCol;
			endc = m_nColSel;
		} else
		{
			startc = m_nColSel;
			endc = m_nCol;
		}

		if (m_nRowSel != -1)
		{
			for (long j = startr; j <= endr; j++)
				for (long i = startc; i <= endc; i++)
				{
					m_pMatrix->put_Selected(m_nFixedCols + i, m_nFixedRows + j, TRUE);
				}
		}
	}

	if (m_bRedraw) InvalidateRect(NULL, FALSE);

	Fire_SelChange();

	return S_OK;
}

STDMETHODIMP CGrid::get_RowSel(long *pVal)
{
	*pVal = m_nRowSel;

	return S_OK;
}

STDMETHODIMP CGrid::put_RowSel(long newVal)
{
	if (newVal < -1 || newVal >= m_nRows - m_nFixedRows) return Error(_T("Invalid Row Value"));

	long startr, endr, startc, endc;

	if (m_nRow < m_nRowSel) 
	{
		startr = m_nRow;
		endr = m_nRowSel;
	} else
	{
		startr = m_nRowSel;
		endr = m_nRow;
	}
	if (m_nCol < m_nColSel)
	{
		startc = m_nCol;
		endc = m_nColSel;
	} else
	{
		startc = m_nColSel;
		endc = m_nCol;
	}

	if (m_nColSel != -1 && m_nRowSel != -1)
	{
		for (long j = startr; j <= endr; j++)
			for (long i = startc; i <= endc; i++)
			{
				m_pMatrix->put_Selected(m_nFixedCols + i, m_nFixedRows + j, FALSE);
			}
	}

	if (newVal == -1)
	{
		m_nRowSel = -1;
		m_nColSel = -1;
	}
	else
	{
		m_nRowSel = newVal;
		if (m_nRow < m_nRowSel) 
		{
			startr = m_nRow;
			endr = m_nRowSel;
		} else
		{
			startr = m_nRowSel;
			endr = m_nRow;
		}
		if (m_nCol < m_nColSel)
		{
			startc = m_nCol;
			endc = m_nColSel;
		} else
		{
			startc = m_nColSel;
			endc = m_nCol;
		}

		if (m_nColSel != -1)
		{
			for (long j = startr; j <= endr; j++)
				for (long i = startc; i <= endc; i++)
				{
					m_pMatrix->put_Selected(m_nFixedCols + i, m_nFixedRows + j, TRUE);
				}
		}
	}

	if (m_bRedraw) InvalidateRect(NULL, FALSE);

	Fire_SelChange();

	return S_OK;
}

STDMETHODIMP CGrid::get_AllowBigSelection(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bAllowBigSelection ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_AllowBigSelection(VARIANT_BOOL newVal)
{
	m_bAllowBigSelection = newVal;

	return S_OK;
}

STDMETHODIMP CGrid::get_SelectionMode(SelectionModeSettings *pVal)
{
	*pVal = m_eSelectionMode;

	return S_OK;
}

STDMETHODIMP CGrid::put_SelectionMode(SelectionModeSettings newVal)
{
	m_eSelectionMode = newVal;

	return S_OK;
}

STDMETHODIMP CGrid::get_GridLineWidth(short *pVal)
{
	*pVal = m_nGridLineWidth;

	return S_OK;
}

STDMETHODIMP CGrid::put_GridLineWidth(short newVal)
{
	if (newVal < 1 || newVal > 10) return Error(_T("Invalid property value"));

	m_nGridLineWidth = newVal;

	return S_OK;
}

STDMETHODIMP CGrid::get_LeftCol(long *pVal)
{
	*pVal = m_nHScrollPos;

	return S_OK;
}

STDMETHODIMP CGrid::put_LeftCol(long newVal)
{
	if (newVal < 0 || newVal >= m_nCols) return Error(_T("Invalid Col Value"));
	BOOL a;
	OnHScroll(0, SB_THUMBPOSITION  | (newVal << 16), 0, a);

	return S_OK;
}

STDMETHODIMP CGrid::get_TopRow(long *pVal)
{
	*pVal = m_nVScrollPos;

	return S_OK;
}

STDMETHODIMP CGrid::put_TopRow(long newVal)
{
	if (newVal < 0 || newVal >= m_nRows) return Error(_T("Invalid Row Value"));
	BOOL a;
	OnVScroll(0, SB_THUMBPOSITION  | (newVal << 16), 0, a);

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedAlignment(AlignmentSettings *pVal)
{
	*pVal = m_eFixedAlignment;	

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedAlignment(AlignmentSettings newVal)
{
	m_eFixedAlignment = newVal;

	/*for (long j = 0; j < m_nFixedCols; j++)
		for (long i = 0; i < m_nCols; i++)
			m_pMatrix->put_Alignment(i, j, newVal);
	for (j = m_nFixedCols; j < m_nRows; j++)
		for (long i = 0; i < m_nFixedRows; i++)
			m_pMatrix->put_Alignment(i, j, newVal);*/

	for (long j = 0; j < m_nFixedRows; j++)
		for (long i = 0; i < m_nCols; i++)
			m_pMatrix->put_Alignment(i, j, newVal);
	for (j = m_nFixedRows; j < m_nRows; j++)
		for (long i = 0; i < m_nFixedCols; i++)
			m_pMatrix->put_Alignment(i, j, newVal);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_Enabled(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m__bEnabled ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_Enabled(VARIANT_BOOL newVal)
{
	m__bEnabled = newVal;

//	DWORD dwStyle;

/*	if (m_hWnd) dwStyle = GetWindowLong(GWL_STYLE);

	if (newVal) 
		dwStyle &= ~WS_DISABLED;
	else 
		dwStyle |= WS_DISABLED;
		
	if (m_hWnd) SetWindowLong(GWL_STYLE, dwStyle);*/
	
	if (m_HScrollBar)
	{
		CalculateFixedWidth(m_nFixedCols);
		CalculateWidth(m_nCols);
		CalculateXMax(m_nCols);
		CalculateXPage(m_nCols);

		SCROLLINFO si;
		ZeroMemory(&si, sizeof(SCROLLINFO));
		si.cbSize = sizeof(SCROLLINFO);
		if (m__bEnabled) 
		{
			si.fMask = SIF_ALL;
			si.nMax = m_nMaxWidth;
			if (m_nHScrollPos > si.nMax) m_nHScrollPos = si.nMax;
			si.nPos = m_nHScrollPos;
			si.nTrackPos = m_nHScrollPos;
			si.nPage = 1;
			si.nMin = 0;
		}
		else si.fMask = SIF_DISABLENOSCROLL;
		
		::SetScrollInfo(m_HScrollBar, SB_CTL, &si, TRUE);
	}

	if (m_VScrollBar)
	{
		CalculateFixedHeight(m_nFixedRows);
		CalculateHeight(m_nRows);
		CalculateYMax(m_nRows);
		CalculateYPage(m_nRows);

		SCROLLINFO si;
		ZeroMemory(&si, sizeof(SCROLLINFO));
		si.cbSize = sizeof(SCROLLINFO);
		if (m__bEnabled)
		{
			si.fMask = SIF_ALL;
			si.nMax = m_nMaxHeight;
			if (m_nVScrollPos > si.nMax) m_nVScrollPos = si.nMax;
			si.nPos = m_nVScrollPos;
			si.nTrackPos = m_nVScrollPos;
			si.nPage = 1;
			si.nMin = 0;
		}
		else si.fMask = SIF_DISABLENOSCROLL;

		::SetScrollInfo(m_VScrollBar, SB_CTL, &si, TRUE);
	
	}
	
	return S_OK;
}

STDMETHODIMP CGrid::get_FontStrikeThrough(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFontStrikeThrough ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	return S_OK;
}

STDMETHODIMP CGrid::put_FontStrikeThrough(VARIANT_BOOL newVal)
{
	m_bFontStrikeThrough = newVal;

	m_LogFont.lfStrikeOut = (BOOL)newVal;
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FontWidth(long *pVal)
{
	*pVal = m_nFontWidth;

	return S_OK;
}

STDMETHODIMP CGrid::put_FontWidth(long newVal)
{
	m_nFontWidth = newVal;

	m_LogFont.lfWidth = newVal;
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FontUnderline(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFontUnderline ? VARIANT_TRUE : VARIANT_FALSE;	
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_FontUnderline(VARIANT_BOOL newVal)
{
	m_bFontUnderline = newVal;

	m_LogFont.lfUnderline = (BOOL)newVal;
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FontItalic(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFontItalic ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_FontItalic(VARIANT_BOOL newVal)
{
	m_bFontItalic = newVal;

	m_LogFont.lfItalic = (BOOL)newVal;
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	
	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FontBold(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFontBold ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_FontBold(VARIANT_BOOL newVal)
{
	m_bFontBold = newVal;

	m_LogFont.lfWeight = (newVal) ? FW_BOLD : FW_NORMAL;
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FontSize(long *pVal)
{
	*pVal = m_nFontSize;

	return S_OK;
}

STDMETHODIMP CGrid::put_FontSize(long newVal)
{
	m_nFontSize = newVal;

	m_LogFont.lfHeight = FontSize(newVal);
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FontName(BSTR *pVal)
{
	*pVal = SysAllocString(m_FontName);

	return S_OK;
}

STDMETHODIMP CGrid::put_FontName(BSTR newVal)
{
	SysFreeString(m_FontName);
	m_FontName = SysAllocString(newVal);

	_tcscpy(m_LogFont.lfFaceName, newVal);
	DeleteObject(m_hFont);
	m_hFont = CreateFontIndirect(&m_LogFont);

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	
	DeleteFonts();
	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontBold(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFixedFontBold ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontBold(VARIANT_BOOL newVal)
{
	m_bFixedFontBold = newVal;

	m_FixedLogFont.lfWeight = (newVal) ? FW_BOLD : FW_NORMAL;
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontItalic(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFixedFontItalic ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontItalic(VARIANT_BOOL newVal)
{
	m_bFixedFontItalic = newVal;

	m_FixedLogFont.lfItalic = (BOOL)newVal;
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontName(BSTR *pVal)
{
	*pVal = SysAllocString(m_FixedFontName);

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontName(BSTR newVal)
{
	SysFreeString(m_FixedFontName);
	m_FixedFontName = SysAllocString(newVal);

	_tcscpy(m_FixedLogFont.lfFaceName, newVal);
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontSize(long *pVal)
{
	*pVal = m_nFixedFontSize;
	
	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontSize(long newVal)
{
	m_nFixedFontSize = newVal;

	m_FixedLogFont.lfHeight = FontSize(newVal);
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontStrikeThrough(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFixedFontStrikeThrough ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontStrikeThrough(VARIANT_BOOL newVal)
{
	m_bFixedFontStrikeThrough = newVal;

	m_FixedLogFont.lfStrikeOut = (BOOL)newVal;
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontUnderline(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bFixedFontUnderline ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)
	
	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontUnderline(VARIANT_BOOL newVal)
{
	m_bFixedFontUnderline = newVal;

	m_FixedLogFont.lfUnderline = (BOOL)newVal;
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_FixedFontWidth(long *pVal)
{
	*pVal = m_nFixedFontWidth;
	
	return S_OK;
}

STDMETHODIMP CGrid::put_FixedFontWidth(long newVal)
{
	m_nFixedFontWidth = newVal;

	m_FixedLogFont.lfWidth = newVal;
	DeleteObject(m_hFixedFont);
	m_hFixedFont = CreateFontIndirect(&m_FixedLogFont);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_CellPictureAlignment(AlignmentSettings *pVal)
{
	m_pMatrix->get_PictureAlignment(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, pVal);
	return S_OK;
}

STDMETHODIMP CGrid::put_CellPictureAlignment(AlignmentSettings newVal)
{
	
	m_pMatrix->put_PictureAlignment(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, newVal);
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_WordWrap(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bWordWrap ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_WordWrap(VARIANT_BOOL newVal)
{
	m_bWordWrap = newVal;

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_HighLight(RHighlightConstants *pVal)
{
	*pVal = m_eHighlight;

	return S_OK;
}

STDMETHODIMP CGrid::put_HighLight(RHighlightConstants newVal)
{
	m_eHighlight = newVal;
	
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

STDMETHODIMP CGrid::get_hWnd(OLE_HANDLE *pVal)
{
	// TODO: Add your implementation code here

	*pVal = (OLE_HANDLE)m_hWnd;

	return S_OK;
}

STDMETHODIMP CGrid::get_Redraw(VARIANT_BOOL *pVal)
{
#pragma warning(disable: 4310)
	*pVal = m_bRedraw ? VARIANT_TRUE : VARIANT_FALSE;
#pragma warning(disable: 4310)

	return S_OK;
}

STDMETHODIMP CGrid::put_Redraw(VARIANT_BOOL newVal)
{
	m_bRedraw = newVal;
	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	
	
	return S_OK;
}

//------------------------------------------------------------------------------------------

STDMETHODIMP CGrid::Clear()
{
	m_nRowSel = -1;
	m_nColSel = -1;

	m_nCol = 0;
	m_nRow = 0;


	m_pMatrix->Reset();

	if (m_hWnd)
	{
		if (m_bRedraw) InvalidateRect(NULL, FALSE);
	}
	else
		if (m_bRedraw) FireViewChange();	

	return S_OK;
}

/*STDMETHODIMP CGrid::ZOrder(RZOrderConstants Position)
{
	DebugBreak();

	HWND flag = (Position == rgridSendToBack) ? HWND_BOTTOM : HWND_TOP;
	SetWindowPos(flag, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return S_OK;
}

STDMETHODIMP CGrid::SetFocus()
{
	DebugBreak();

 	::SetFocus(m_hWnd);

	return S_OK;
}

STDMETHODIMP CGrid::Refresh()
{
	DebugBreak();
	
	InvalidateRect(NULL, FALSE);

	return S_OK;
}

STDMETHODIMP CGrid::Move(long Left, long Top, long Width, long Height)
{
	DebugBreak();

	RECT rc;
	GetWindowRect(&rc);
	if (Left < 0) return E_INVALIDARG;
	rc.left = Left;
	if (Top >= 0) rc.top = Top;
	if (Width > 0) rc.right = rc.left + Width;
	if (Height > 0) rc.bottom = rc.top + Height;

	MoveWindow(&rc, TRUE);

	return S_OK;
}*/

STDMETHODIMP CGrid::AddItem(BSTR Item, VARIANT* index)
{
//	DebugBreak();

	if (!(V_VT(index) == VT_I2 || V_VT(index) == VT_I4 || V_VT(index) == VT_ERROR)) 
		return E_INVALIDARG;

	if (V_VT(index) != VT_ERROR)
	{
		if (V_I2(index) < 0 || V_I2(index) > m_nRows) 
			return Error(_T("Grid does not contain that row"));
		if (V_I2(index) < m_nFixedRows)
			return Error(_T("Cannot use AddItem on a fixed row"));
	}
	else
	{
		index->vt = VT_I2;
		index->lVal = m_nRows;
	}

	long c, r, cs, rs;

	c = m_nCol;
	r = m_nRow;
	cs = m_nColSel;
	rs = m_nRowSel;

	put_Col(c);
	put_Row(r);

	m_pMatrix->AddRow(V_I2(index), Item); 

	put_Rows(m_nRows + 1);

	put_Col(c);
	put_Row(r);
	put_ColSel(cs);
	put_RowSel(rs);

	return S_OK;
}

STDMETHODIMP CGrid::RemoveItem(long index)
{
	if (index < 0 || index > m_nRows) return Error(_T("Grid does not contain that row"));
	if (index < m_nFixedRows) return Error(_T("Cannot do a RemoveItem on a fixed row"));
//	if (m_nRows - m_nFixedRows == 1) return Error(_T("Can not remove last non-fixed row"));

	if (index == m_nRows) index--;

	m_pMatrix->RemoveRow(index);

	put_Rows(m_nRows - 1);

	if ((m_nRows - m_nFixedRows) == m_nRowSel)
	{
		if (m_nRow != m_nRowSel)
		{
			m_nRowSel -= 1;	
		} else
		{
			m_nColSel = -1;
			m_nRowSel = -1;
		}
	} 


	return S_OK;
}

STDMETHODIMP CGrid::CellLoadPicture(BSTR FileName)
{	
#ifdef UNDER_CE
	if (_tcslen(FileName) == 0)
	{
		m_pMatrix->put_Picture(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, NULL);	
	}
	else
	{
		HBITMAP Picture = SHLoadDIBitmap(FileName);
	
		if (Picture == NULL) 
		{
			return Error(_T("Cannot load picture"));
		}

		m_pMatrix->put_Picture(m_nCol + m_nFixedCols, m_nRow + m_nFixedRows, Picture);
	}

	if (m_bRedraw) InvalidateRect(NULL, FALSE);
#endif
	
	return S_OK;
}

//----------------------------------------------------------------------------------------------------------------

STDMETHODIMP CGrid::get_RegistrationCode(BSTR *pVal)
{
	*pVal = ::SysAllocString(m_RegistrationCode);

	return S_OK;
}

STDMETHODIMP CGrid::put_RegistrationCode(BSTR newVal)
{
	SysFreeString(m_RegistrationCode);
	m_RegistrationCode = SysAllocString(newVal);

	return S_OK;
}

/*void CGrid::Memory(long p)
{
	MEMORYSTATUS ms;
	ZeroMemory(&ms, sizeof(ms));
	ms.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&ms);

	DebugPrint(ms.dwAvailPhys, p, FALSE);
	/*wsprintf(t, _T("MemoryLoad: %d\nTotalPhys: %d\nAvailPhys: %d\nTotalPageFile: %d\nAvailPageFile: %d\nTotalVirtual: %d\nAvailVirtual: %d"),
		ms.dwMemoryLoad, ms.dwTotalPhys, ms.dwAvailPhys, ms.dwTotalPageFile, ms.dwAvailPageFile, ms.dwTotalVirtual, ms.dwAvailVirtual);
	MessageBox(t);*/

//}

