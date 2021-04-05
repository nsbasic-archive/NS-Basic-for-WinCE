// Cell.cpp: implementation of the CCell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RGridCtrl.h"
#include "Cell.h"

BSTR CCell::m_szEmptyString = TEXT("");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCell::CCell(CFontTable *FontTable)
{
	//m_Text = SysAllocString(_T(""));
	m_Text = NULL;
	m_clrBackColor = 0;
	m_clrForeColor = 0;
	m_clrBackColorSel = 0;
	m_clrForeColorSel = 0;
	m_eAlignment = rgridAlignGeneral;
	m_bSelected = FALSE;
	m_ePictureAlignment = rgridAlignGeneral;
	m_hPicture = NULL;
	m_hBackColor = NULL;
	m_hBackColorSel = NULL;

	m_nFontIndex = -1;
}

CCell::~CCell()
{
	if (m_Text) SysFreeString(m_Text);
	DeleteObject(m_hPicture);
	DeleteObject(m_hBackColor);
	DeleteObject(m_hBackColorSel);
}

void CCell::Reset()
{
	if (m_Text) SysFreeString(m_Text);
	//m_Text = SysAllocString(_T(""));
	m_Text = NULL;
	m_clrBackColor = 0;
	m_clrForeColor = 0;
	m_clrBackColorSel = 0;
	m_clrForeColorSel = 0;
	m_eAlignment = rgridAlignGeneral;
	m_bSelected = FALSE;
	m_ePictureAlignment = rgridAlignGeneral;
	DeleteObject(m_hPicture);
	DeleteObject(m_hBackColor);
	DeleteObject(m_hBackColorSel);

	m_hPicture = NULL;
	m_hBackColor = NULL;
	m_hBackColorSel = NULL;

	m_nFontIndex = -1;
}

DWORD CCell::TranslateColor(DWORD col)
{
	DWORD clr = col;
	DWORD COLOR_CONST;

#ifndef UNDER_CE
	COLOR_CONST = 0x00000000;
#else
#if defined(_X86_)
	COLOR_CONST = 0x80000000;
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

void CCell::put_Text(BSTR newVal)
{
	if (m_Text) SysFreeString(m_Text);
	if (newVal && _tcslen(newVal))
		m_Text = SysAllocString(newVal);
	else
		m_Text = NULL;
}

void CCell::get_Text(BSTR *pVal)
{
	if (m_Text)
		*pVal = SysAllocString(m_Text);
	else
		*pVal = SysAllocString(m_szEmptyString);
}

void CCell::get_BackColor(OLE_COLOR *pVal, HBRUSH *pBrush)
{
	*pVal = m_clrBackColor;
	*pBrush = m_hBackColor;
}

void CCell::put_BackColor(OLE_COLOR newVal)
{
	m_clrBackColor = newVal;
	DeleteObject(m_hBackColor);
	m_hBackColor = CreateSolidBrush(TranslateColor(newVal));
}

void CCell::get_ForeColor(OLE_COLOR *pVal)
{
	*pVal = m_clrForeColor;
}

void CCell::put_ForeColor(OLE_COLOR newVal)
{
	m_clrForeColor = newVal;
}

void CCell::get_BackColorSel(OLE_COLOR *pVal, HBRUSH *pBrush)
{
	*pVal = m_clrBackColorSel;
	*pBrush = m_hBackColorSel;
}

void CCell::put_BackColorSel(OLE_COLOR newVal)
{
	m_clrBackColorSel = newVal;
	DeleteObject(m_hBackColor);
	m_hBackColor = CreateSolidBrush(TranslateColor(newVal));
}

void CCell::get_ForeColorSel(OLE_COLOR *pVal)
{
	*pVal = m_clrForeColorSel;
}

void CCell::put_ForeColorSel(OLE_COLOR newVal)
{
	m_clrForeColorSel = newVal;
}

void CCell::get_Alignment(AlignmentSettings *pVal)
{
	*pVal = m_eAlignment;
}

void CCell::put_Alignment(AlignmentSettings newVal)
{
	m_eAlignment = newVal;
}

void CCell::get_Selected(VARIANT_BOOL *pVal)
{
	*pVal = m_bSelected;
}

void CCell::put_Selected(VARIANT_BOOL newVal)
{
	m_bSelected = newVal;
}

void CCell::get_FontIndex(long *pVal)
{
	*pVal = m_nFontIndex;
}

void CCell::put_FontIndex(long newVal)
{
	m_nFontIndex = newVal;
}

void CCell::get_PictureAlignment(AlignmentSettings *pVal)
{
	*pVal = m_ePictureAlignment;
}

void CCell::put_PictureAlignment(AlignmentSettings newVal)
{
	m_ePictureAlignment = newVal;
}

void CCell::get_Picture(HBITMAP *pVal)
{
	*pVal = m_hPicture;
}

void CCell::put_Picture(HBITMAP newVal)
{
	DeleteObject(m_hPicture);
	m_hPicture = newVal;
}

//////////////////////////////////////////////////////////////////////
// CMatrix Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMatrix::CMatrix(long x, long y, CFontTable *FontTable)
{
	m_pMatrix = NULL;
	m_pFontTable = new CFontTable;
	size.x = x;
	size.y = y;

	m_pMatrix = (CCell***)LocalAlloc(LPTR, sizeof(CCell**) * y);
	if (m_pMatrix)
	{
		for (long j = 0; j < y; j++)
		{
			m_pMatrix[j] = (CCell**)LocalAlloc(LPTR, sizeof(CCell*) * x);
			for (long i = 0; i < x; i++)
			{
				m_pMatrix[j][i] = new CCell(FontTable);
			}
		}
	}
}

CMatrix::~CMatrix()
{
	if (m_pMatrix)
	{
		for (long j = 0; j < size.y; j++)
		{
			for (long i = 0; i < size.x; i++)
			{
				delete m_pMatrix[j][i];
				m_pMatrix[j][i] = NULL;
			}
			LocalFree(m_pMatrix[j]);
			m_pMatrix[j] = NULL;
		}
	}
	LocalFree(m_pMatrix);
	if (m_pFontTable) delete m_pFontTable;
}

void CMatrix::Reset()
{
	if (m_pMatrix)
	{
		for (long j = 0; j < size.y; j++)
		{
			for (long i = 0; i < size.x; i++)
			{
				m_pMatrix[j][i]->Reset();	
			}
		}
	}
}

void CMatrix::ChangeCols(long n)
{
	if (n == size.x) return;

	for (long j = 0; j < size.y; j++)
	{
		CCell **tmp = (CCell**)LocalAlloc(LPTR, sizeof(CCell*) * n);
		if (tmp)
		{
			memcpy(tmp, m_pMatrix[j], sizeof(CCell*) * ((n < size.x) ? n : size.x));
			if (n > size.x)
			{
				for (long i = size.x; i < n; i++)
				{
					tmp[i] = new CCell(m_pFontTable);
				}
			}
			else if (n < size.x)
			{
				for (long i = n; i < size.x; i++)
				{
					delete m_pMatrix[j][i];
					m_pMatrix[j][i] = NULL;
				}
			}
			LocalFree(m_pMatrix[j]);
			m_pMatrix[j] = tmp;
		}
	}

	size.x = n;
}

void CMatrix::ChangeRows(long n)
{
	if (n == size.y) return;

	CCell ***tmp = (CCell***)LocalAlloc(LPTR, sizeof(CCell**) * n);

	if (tmp)
	{
		memcpy(tmp, m_pMatrix, sizeof(CCell**) * ((n < size.y) ? n : size.y));
		if (n > size.y)
		{
			for (long j = size.y; j < n; j++)
			{
				tmp[j] = (CCell**)LocalAlloc(LPTR, sizeof(CCell*) * size.x);
				//if (!tmp[j]) DebugBreak();
				for (long i = 0; i < size.x; i++)
				{
					tmp[j][i] = new CCell(m_pFontTable);
				}
			}
		}
		else if (n < size.y)
		{
			for (long j = n; j < size.y; j++)
			{
				for (long i = 0; i < size.x; i++)
				{
					delete m_pMatrix[j][i];
					m_pMatrix[j][i] = NULL;
				}
				LocalFree(m_pMatrix[j]);
			}
		}
		LocalFree(m_pMatrix);
		m_pMatrix = tmp;

		size.y = n;
	}
}

void CMatrix::AddRow(long n, BSTR text)
{
	CCell ***tmp = (CCell***)LocalAlloc(LPTR, sizeof(CCell**) * size.y + 1);
	if (tmp)
	{
		memcpy(tmp, m_pMatrix, n * sizeof(CCell**));
		memcpy(&tmp[n + 1], &m_pMatrix[n], sizeof(CCell**) * (size.y - n));
		tmp[n] = (CCell**)LocalAlloc(LPTR, sizeof(CCell*) * size.x);
		for (long i = 0; i < size.x; i++)
		{
			tmp[n][i] = new CCell(m_pFontTable);
		}
	}
	LocalFree(m_pMatrix);
	m_pMatrix = tmp;

	TCHAR textbuf[1024];

	ZeroMemory(textbuf, sizeof(TCHAR) * 1024);
	long i = 0;
	long j = 0;
	long k = 0;

	while(1)
	{
		if (text[i] == 0) 
		{
			if (j < size.x) m_pMatrix[n][j]->put_Text(textbuf);
			break;
		}
		if (text[i] == '\t')
		{
			if (j < size.x) m_pMatrix[n][j]->put_Text(textbuf);
			j++;
			i++;
			k = 0;
			ZeroMemory(textbuf, sizeof(TCHAR) * 1024);
			continue;
		}
		textbuf[k] = text[i];
		k++;
		i++;
	}

	size.y++;
}

void CMatrix::RemoveRow(long n)
{
	CCell ***tmp = (CCell***)LocalAlloc(LPTR, sizeof(CCell**) * size.y - 1);
	if (tmp)
	{
		memcpy(tmp, m_pMatrix, sizeof(CCell**) * n);
		memcpy(&tmp[n], &m_pMatrix[n + 1], sizeof(CCell**) * (size.y - 1 - n));
		for (long i = 0; i < size.x; i++)
		{
			delete m_pMatrix[n][i];
			m_pMatrix[n][i] = NULL;
		}
		LocalFree(m_pMatrix[n]);
	}
	LocalFree(m_pMatrix);
	m_pMatrix = tmp;

	size.y--;
}

void CMatrix::get_Text(long x, long y, BSTR *pVal)
{
	m_pMatrix[y][x]->get_Text(pVal);
}

void CMatrix::put_Text(long x, long y, BSTR newVal)
{
	m_pMatrix[y][x]->put_Text(newVal);
}

void CMatrix::get_BackColor(long x, long y, OLE_COLOR *pVal, HBRUSH *pBrush)
{
	m_pMatrix[y][x]->get_BackColor(pVal, pBrush);
}

void CMatrix::put_BackColor(long x, long y, OLE_COLOR newVal)
{
	m_pMatrix[y][x]->put_BackColor(newVal);
}

void CMatrix::get_ForeColor(long x, long y, OLE_COLOR *pVal)
{
	m_pMatrix[y][x]->get_ForeColor(pVal);
}

void CMatrix::put_ForeColor(long x, long y, OLE_COLOR newVal)
{
	m_pMatrix[y][x]->put_ForeColor(newVal);
}

void CMatrix::get_BackColorSel(long x, long y, OLE_COLOR *pVal, HBRUSH *pBrush)
{
	m_pMatrix[y][x]->get_BackColorSel(pVal, pBrush);
}

void CMatrix::put_BackColorSel(long x, long y, OLE_COLOR newVal)
{
	m_pMatrix[y][x]->put_BackColorSel(newVal);
}

void CMatrix::get_ForeColorSel(long x, long y, OLE_COLOR *pVal)
{
	m_pMatrix[y][x]->get_ForeColorSel(pVal);
}

void CMatrix::put_ForeColorSel(long x, long y, OLE_COLOR newVal)
{
	m_pMatrix[y][x]->put_ForeColorSel(newVal);
}

void CMatrix::get_Alignment(long x, long y, AlignmentSettings *pVal)
{
	m_pMatrix[y][x]->get_Alignment(pVal);
}

void CMatrix::put_Alignment(long x, long y, AlignmentSettings newVal)
{
	m_pMatrix[y][x]->put_Alignment(newVal);
}

void CMatrix::get_Selected(long x, long y, VARIANT_BOOL *pVal)
{
	m_pMatrix[y][x]->get_Selected(pVal);
}

void CMatrix::put_Selected(long x, long y, VARIANT_BOOL newVal)
{
	m_pMatrix[y][x]->put_Selected(newVal);
}

void CMatrix::get_FontIndex(long x, long y, long *pVal)
{
	m_pMatrix[y][x]->get_FontIndex(pVal);
}

void CMatrix::put_FontIndex(long x, long y, long newVal)
{
	m_pMatrix[y][x]->put_FontIndex(newVal);
}

void CMatrix::get_PictureAlignment(long x, long y, AlignmentSettings *pVal)
{
	m_pMatrix[y][x]->get_PictureAlignment(pVal);
}

void CMatrix::put_PictureAlignment(long x, long y, AlignmentSettings newVal)
{
	m_pMatrix[y][x]->put_PictureAlignment(newVal);
}

void CMatrix::get_Picture(long x, long y, HBITMAP *pVal)
{
	m_pMatrix[y][x]->get_Picture(pVal);
}

void CMatrix::put_Picture(long x, long y, HBITMAP newVal)
{
	m_pMatrix[y][x]->put_Picture(newVal);
} 

//////////////////////////////////////////////////////////////////////
// FontTable Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFontTable::CFontTable()
{
	m_pFonts = NULL;
}

CFontTable::~CFontTable()
{
	if (m_pFonts) delete m_pFonts;
}

long CFontTable::AddFont(LOGFONT *font)
{
	long index = FindFont(font);
	FontList *tmp = m_pFonts;

	if (index != -1) 
	{
		long i = index;

		while(i) 
		{
			i--;
			tmp = tmp->next;
		}
		tmp->cells++;
		
		return index;
	}
	
	index = 0;
	
	if (!tmp) 
	{
		tmp = new FontList;
		m_pFonts = tmp;
	}
	else
	{
		while(tmp->next) 
		{
			index++;
			tmp = tmp->next;
		}
		
		tmp->next = new FontList;
		tmp = tmp->next;
		index++;
	}
	memcpy(&tmp->LogFont, font, sizeof(LOGFONT));
	tmp->cells++;
	tmp->Font = CreateFontIndirect(font);

	return index;
}

long CFontTable::FindFont(LOGFONT *font)
{
	long index = 0;

	FontList *tmp = m_pFonts;

	while(tmp)
	{
		if (memcmp(&tmp->LogFont, font, sizeof(LOGFONT)) == 0)
		{
			return index;
		}
		index++;
		tmp = tmp->next;
	}
	return -1;
}

long CFontTable::_DeleteFont(long index)
{
	FontList *tmp = m_pFonts;
	FontList *tmp1;

	if (index == 0)
	{
		tmp->cells--;
		if (tmp->cells == 0)
		{
			m_pFonts = tmp->next;
			tmp->next = NULL;
			delete tmp;
			return 0;
		}
		return tmp->cells;
	}

	while(index)
	{
		index--;
		tmp1 = tmp;
		tmp = tmp->next;
	}

	tmp->cells--;
	if (tmp->cells == 0)
	{
		tmp1->next = tmp->next;
		tmp->next = NULL;
		delete tmp;
		return 0;
	}
	
	return tmp->cells;
}

HFONT CFontTable::GetFont(long index)
{
	FontList *tmp = m_pFonts;

	while(index)
	{
		index--;
		tmp = tmp->next;
	}

	return tmp->Font;
}

void CFontTable::GetLogFont(long index, LOGFONT *font)
{
	FontList *tmp = m_pFonts;

	while(index)
	{
		index--;
		tmp = tmp->next;
	}

	memcpy(font, &tmp->LogFont, sizeof(LOGFONT));

	return;
}

//#include "..\HEADER FILES\"
