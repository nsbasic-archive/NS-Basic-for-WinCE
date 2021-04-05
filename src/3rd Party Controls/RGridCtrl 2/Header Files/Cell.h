// Cell.h: interface for the CCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CELL_H__FBB44DEF_890E_4316_AAF0_926E97C62F0F__INCLUDED_)
#define AFX_CELL_H__FBB44DEF_890E_4316_AAF0_926E97C62F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct _FontList
{
	HFONT		Font;
	LOGFONT		LogFont;
	long		cells;
	_FontList	*next;

	_FontList()
	{
		next = NULL;
		Font = NULL;
		ZeroMemory(&LogFont, sizeof(LOGFONT));
		cells = 0;
	}

	~_FontList()
	{
		if (next) delete next;
	}

} FontList;

class CFontTable  
{
public:
	CFontTable();
	virtual ~CFontTable();

	long	AddFont(LOGFONT *font);
	long	FindFont(LOGFONT *font);
	long	_DeleteFont(long index);
	HFONT	GetFont(long index);
	void	GetLogFont(long index, LOGFONT *font);

private:
	FontList	*m_pFonts;
	long		m_nFonts;
};

class CCell  
{
public:
	CCell(CFontTable *FontTable);
	virtual ~CCell();

	void	put_Text(BSTR newVal);
	void	get_Text(BSTR *pVal);
	void	put_BackColor(OLE_COLOR newVal);
	void	get_BackColor(OLE_COLOR *pVal, HBRUSH *pBrush);
	void	put_ForeColor(OLE_COLOR newVal);
	void	get_ForeColor(OLE_COLOR *pVal);
	void	put_BackColorSel(OLE_COLOR newVal);
	void	get_BackColorSel(OLE_COLOR *pVal, HBRUSH *pBrush);
	void	put_ForeColorSel(OLE_COLOR newVal);
	void	get_ForeColorSel(OLE_COLOR *pVal);
	void	get_Alignment(AlignmentSettings *pVal);
	void	put_Alignment(AlignmentSettings newVal);
	void	get_Selected(VARIANT_BOOL *pVal);
	void	put_Selected(VARIANT_BOOL newVal);
	void	get_FontIndex(long *pVal);
	void	put_FontIndex(long newVal);
	void    get_PictureAlignment(AlignmentSettings *pVal);
	void	put_PictureAlignment(AlignmentSettings newVal);
	void	get_Picture(HBITMAP *pVal);
	void	put_Picture(HBITMAP newVal);
	void	Reset();
private:
	DWORD TranslateColor(DWORD col);

	BSTR				m_Text;
	OLE_COLOR			m_clrBackColor;
	OLE_COLOR			m_clrForeColor;
	OLE_COLOR			m_clrBackColorSel;
	OLE_COLOR			m_clrForeColorSel;
	AlignmentSettings	m_eAlignment;
	VARIANT_BOOL		m_bSelected;

	CFontTable			*m_pFontTable;
	long				m_nFontIndex;

	AlignmentSettings	m_ePictureAlignment;
	HBITMAP				m_hPicture;
	HBRUSH				m_hBackColor;
	HBRUSH				m_hBackColorSel;

	static BSTR m_szEmptyString;
};


class CMatrix  
{
public:
	CMatrix(long x, long y, CFontTable *FontTable);
	virtual ~CMatrix();

	void ChangeRows(long n);
	void ChangeCols(long n);
	void AddRow(long n, BSTR text);
	void RemoveRow(long n);

	void	get_Text(long x, long y, BSTR *pVal);
	void	put_Text(long x, long y, BSTR newVal);
	void	get_BackColor(long x, long y, OLE_COLOR *pVal, HBRUSH *pBrush);
	void	put_BackColor(long x, long y, OLE_COLOR newVal);
	void	get_ForeColor(long x, long y, OLE_COLOR *pVal);
	void	put_ForeColor(long x, long y, OLE_COLOR newVal);
	void	get_BackColorSel(long x, long y, OLE_COLOR *pVal, HBRUSH *pBrush);
	void	put_BackColorSel(long x, long y, OLE_COLOR newVal);
	void	get_ForeColorSel(long x, long y, OLE_COLOR *pVal);
	void	put_ForeColorSel(long x, long y, OLE_COLOR newVal);
	void	get_Alignment(long x, long y, AlignmentSettings *pVal);
	void	put_Alignment(long x, long y, AlignmentSettings newVal);
	void	get_Selected(long x, long y, VARIANT_BOOL *pVal);
	void	put_Selected(long x, long y, VARIANT_BOOL newVal);
	void	get_FontIndex(long x, long y, long *pVal);
	void	put_FontIndex(long x, long y, long newVal);
	void    get_PictureAlignment(long x, long y, AlignmentSettings *pVal);
	void	put_PictureAlignment(long x, long y, AlignmentSettings newVal);
	void	get_Picture(long x, long y, HBITMAP *pVal);
	void	put_Picture(long x, long y, HBITMAP newVal);
	void Reset();
private:
	CCell		***m_pMatrix;
	POINT		size;
	CFontTable	*m_pFontTable;
};

#endif // !defined(AFX_CELL_H__FBB44DEF_890E_4316_AAF0_926E97C62F0F__INCLUDED_)
