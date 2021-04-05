// NSCEBitmap.h: interface for the CNSCEBitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NSCEBITMAP_H__E490E277_593D_4DF7_9742_CDA14DA3D47F__INCLUDED_)
#define AFX_NSCEBITMAP_H__E490E277_593D_4DF7_9742_CDA14DA3D47F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNSCEBitmap  
{
public:
	HBITMAP TakeHBITMAP();
	void CreateFromScreen();
	CNSCEBitmap *Scroll(long lScrollX, long lScrollY);
	CNSCEBitmap *Rotate(long lDegrees);
	CNSCEBitmap *Resize(long lWidth, long lHeight);
	CNSCEBitmap *Overlay(CNSCEBitmap *pNSCEBitmapOverlay, long lLeft, long lTop, long lWidth, long lHeight, COLORREF crFillColor, BOOL bTransparent, COLORREF crTransparentColor);
	CNSCEBitmap *Mirror(long lMirror);
	CNSCEBitmap *Invert();
	CNSCEBitmap *CopyToNewBitsPerPixel(long lBitsPerPixel);
	CNSCEBitmap *Clip(long lLeft, long lTop, long lWidth, long lHeight, COLORREF crFillColor);
	CNSCEBitmap *Copy();
	void SetHBITMAP(HBITMAP hBitmap);
	HBITMAP GetHBITMAP();
	BOOL Create(long lWidth, long lHeight, long lBitsPerPixel, COLORREF crFillColor);
	CNSCEBitmap();
	virtual ~CNSCEBitmap();

private:
	long IsDIBSectionForRotate(DIBSECTION *ds);
	void CopyRotatedBits(HBITMAP hBitmapSource, HBITMAP hBitmapDest, long lDegrees);
	void CopyScrolledBits(HBITMAP hBitmapSource, HBITMAP hBitmapDest, long lX, long lY);
	HBITMAP CreateDIBSection(long lWidth, long lHeight, long lBitsPerPixel, LPVOID pBits, RGBQUAD *pRGBQuad);
	void DeleteHBITMAP();
	HBITMAP m_hBitmap;
};

#endif // !defined(AFX_NSCEBITMAP_H__E490E277_593D_4DF7_9742_CDA14DA3D47F__INCLUDED_)
