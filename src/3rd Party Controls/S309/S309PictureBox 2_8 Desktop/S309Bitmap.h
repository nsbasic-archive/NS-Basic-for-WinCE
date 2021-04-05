// S309Bitmap.h: interface for the CS309Bitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_S309BITMAP_H__E490E277_593D_4DF7_9742_CDA14DA3D47F__INCLUDED_)
#define AFX_S309BITMAP_H__E490E277_593D_4DF7_9742_CDA14DA3D47F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CS309Bitmap  
{
public:
	HBITMAP TakeHBITMAP();
	void CreateFromScreen();
	CS309Bitmap *Scroll(long lScrollX, long lScrollY);
	CS309Bitmap *Rotate(long lDegrees);
	CS309Bitmap *Resize(long lWidth, long lHeight);
	CS309Bitmap *Overlay(CS309Bitmap *pS309BitmapOverlay, long lLeft, long lTop, long lWidth, long lHeight, COLORREF crFillColor, BOOL bTransparent, COLORREF crTransparentColor);
	CS309Bitmap *Mirror(long lMirror);
	CS309Bitmap *Invert();
	CS309Bitmap *CopyToNewBitsPerPixel(long lBitsPerPixel);
	CS309Bitmap *Clip(long lLeft, long lTop, long lWidth, long lHeight, COLORREF crFillColor);
	CS309Bitmap *Copy();
	void SetHBITMAP(HBITMAP hBitmap);
	HBITMAP GetHBITMAP();
	BOOL Create(long lWidth, long lHeight, long lBitsPerPixel, COLORREF crFillColor);
	CS309Bitmap();
	virtual ~CS309Bitmap();

private:
	long IsDIBSectionForRotate(DIBSECTION *ds);
	void CopyRotatedBits(HBITMAP hBitmapSource, HBITMAP hBitmapDest, long lDegrees);
	void CopyScrolledBits(HBITMAP hBitmapSource, HBITMAP hBitmapDest, long lX, long lY);
	HBITMAP CreateDIBSection(long lWidth, long lHeight, long lBitsPerPixel, LPVOID pBits, RGBQUAD *pRGBQuad);
	void DeleteHBITMAP();
	HBITMAP m_hBitmap;
};

#endif // !defined(AFX_S309BITMAP_H__E490E277_593D_4DF7_9742_CDA14DA3D47F__INCLUDED_)
