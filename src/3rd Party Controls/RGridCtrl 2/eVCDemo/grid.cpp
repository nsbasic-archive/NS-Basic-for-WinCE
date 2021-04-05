// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "grid.h"

/////////////////////////////////////////////////////////////////////////////
// CGrid

IMPLEMENT_DYNCREATE(CGrid, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CGrid operations

long CGrid::GetRows()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetRows(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetFixedRows()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedRows(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetCols()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCols(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetFixedCols()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedCols(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

unsigned long CGrid::GetBackColor()
{
	unsigned long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetBackColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetBackColorBkg()
{
	unsigned long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetBackColorBkg(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetBackColorFixed()
{
	unsigned long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetBackColorFixed(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CGrid::GetGridLines()
{
	long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetGridLines(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetGridLinesFixed()
{
	long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetGridLinesFixed(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

unsigned long CGrid::GetGridColor()
{
	unsigned long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetGridColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetGridColorFixed()
{
	unsigned long result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetGridColorFixed(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CGrid::GetAllowUserResizing()
{
	long result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetAllowUserResizing(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetScrollBars()
{
	long result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetScrollBars(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetBorderStyle()
{
	long result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetBorderStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetScrollTrack()
{
	BOOL result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetScrollTrack(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

unsigned long CGrid::GetForeColor()
{
	unsigned long result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetForeColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetForeColorFixed()
{
	unsigned long result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetForeColorFixed(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetForeColorSel()
{
	unsigned long result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetForeColorSel(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetBackColorSel()
{
	unsigned long result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetBackColorSel(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CGrid::GetRowHeightMin()
{
	long result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetRowHeightMin(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CGrid::GetTextMatrix(long Row, long Col)
{
	CString result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
		Row, Col);
	return result;
}

void CGrid::SetTextMatrix(long Row, long Col, LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_BSTR;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 Row, Col, lpszNewValue);
}

CString CGrid::GetTextArray(long index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
		index);
	return result;
}

void CGrid::SetTextArray(long index, LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 index, lpszNewValue);
}

long CGrid::GetRow()
{
	long result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetRow(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetCol()
{
	long result;
	InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCol(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

unsigned long CGrid::GetCellBackColor()
{
	unsigned long result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellBackColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CGrid::GetCellForeColor()
{
	unsigned long result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellForeColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CGrid::GetCellAlignment()
{
	long result;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetCellLeft()
{
	long result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CGrid::GetCellTop()
{
	long result;
	InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CGrid::GetCellWidth()
{
	long result;
	InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CGrid::GetCellHeight()
{
	long result;
	InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetColAlignment(long index, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 index, nNewValue);
}

CString CGrid::GetText()
{
	CString result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CGrid::SetText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CGrid::GetColWidth(long index)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		index);
	return result;
}

void CGrid::SetColWidth(long index, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 index, nNewValue);
}

BOOL CGrid::GetColIsVisible(long index)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		index);
	return result;
}

long CGrid::GetColPos(long index)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		index);
	return result;
}

long CGrid::GetRowHeight(long index)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x26, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		index);
	return result;
}

void CGrid::SetRowHeight(long index, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x26, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 index, nNewValue);
}

BOOL CGrid::GetRowIsVisible(long index)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		index);
	return result;
}

long CGrid::GetRowPos(long index)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		index);
	return result;
}

long CGrid::GetColSel()
{
	long result;
	InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetColSel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetRowSel()
{
	long result;
	InvokeHelper(0x2a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetRowSel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetAllowBigSelection()
{
	BOOL result;
	InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetAllowBigSelection(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CGrid::GetSelectionMode()
{
	long result;
	InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetSelectionMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short CGrid::GetGridLineWidth()
{
	short result;
	InvokeHelper(0x2d, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void CGrid::SetGridLineWidth(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x2d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetLeftCol()
{
	long result;
	InvokeHelper(0x2e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetLeftCol(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetTopRow()
{
	long result;
	InvokeHelper(0x2f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetTopRow(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetFixedAlignment()
{
	long result;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CGrid::GetCellFontName()
{
	CString result;
	InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x31, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CGrid::GetCellFontSize()
{
	long result;
	InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontSize(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x32, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetCellFontBold()
{
	BOOL result;
	InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontBold(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x33, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetCellFontItalic()
{
	BOOL result;
	InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontItalic(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x34, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetCellFontUnderline()
{
	BOOL result;
	InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontUnderline(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x35, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CGrid::GetCellFontWidth()
{
	long result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetCellFontStrikeThrough()
{
	BOOL result;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellFontStrikeThrough(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CGrid::GetFontName()
{
	CString result;
	InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x38, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CGrid::GetFontSize()
{
	long result;
	InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontSize(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x39, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetFontBold()
{
	BOOL result;
	InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontBold(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetFontItalic()
{
	BOOL result;
	InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontItalic(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetFontUnderline()
{
	BOOL result;
	InvokeHelper(0x3c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontUnderline(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CGrid::GetFontWidth()
{
	long result;
	InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetFontStrikeThrough()
{
	BOOL result;
	InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFontStrikeThrough(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetFixedFontBold()
{
	BOOL result;
	InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontBold(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetFixedFontItalic()
{
	BOOL result;
	InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontItalic(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x40, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CGrid::GetFixedFontName()
{
	CString result;
	InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x41, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CGrid::GetFixedFontSize()
{
	long result;
	InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontSize(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetFixedFontStrikeThrough()
{
	BOOL result;
	InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontStrikeThrough(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x43, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetFixedFontUnderline()
{
	BOOL result;
	InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontUnderline(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CGrid::GetFixedFontWidth()
{
	long result;
	InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetFixedFontWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x45, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CGrid::GetCellPictureAlignment()
{
	long result;
	InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetCellPictureAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetWordWrap()
{
	BOOL result;
	InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetWordWrap(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x47, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CGrid::GetHighLight()
{
	long result;
	InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CGrid::SetHighLight(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x48, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CGrid::GetRedraw()
{
	BOOL result;
	InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::SetRedraw(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void CGrid::Clear()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CGrid::AddItem(LPCTSTR Item, VARIANT* index)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Item, index);
}

void CGrid::RemoveItem(long index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index);
}

void CGrid::SetEnabled(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CGrid::GetEnabled()
{
	BOOL result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CGrid::CellLoadPicture(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3e9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

CString CGrid::GetRegistrationCode()
{
	CString result;
	InvokeHelper(0x2710, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CGrid::SetRegistrationCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2710, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CGrid::GetHWnd()
{
	long result;
	InvokeHelper(0x2711, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}
