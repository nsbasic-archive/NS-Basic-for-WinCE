// S309Bitmap.cpp: implementation of the CS309Bitmap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "s309picturebox.h"
#include "S309Bitmap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CS309Bitmap::CS309Bitmap()
{
	m_hBitmap = NULL;
}

CS309Bitmap::~CS309Bitmap()
{
	DeleteHBITMAP();
}

HBITMAP CS309Bitmap::GetHBITMAP()
{
	return m_hBitmap;
}

void CS309Bitmap::SetHBITMAP(HBITMAP hBitmap)
{
	if (NULL != hBitmap)
	{
		DeleteHBITMAP();

		m_hBitmap = hBitmap;
	}
}

void CS309Bitmap::DeleteHBITMAP()
{
	if (NULL != m_hBitmap)
	{
		DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}
}

BOOL CS309Bitmap::Create(long lWidth, long lHeight, long lBitsPerPixel, COLORREF crFillColor)
{

/*	if ((!m_bOverlay && (m_ocTransparentColor < 16777216)) || (m_bOverlay && (m_ocOverlayTransparentColor < 16777216)))
	{
		hbmResult = ::CreateBitmap(nWidth + nLeft, nHeight + nTop, 1, 24, NULL);
	}
	else
	{
		m_hBitmap = ::CreateBitmap(nWidth + nLeft, nHeight + nTop, 1, lBitsPerPixel, NULL);
	} */
	
	m_hBitmap = ::CreateBitmap(lWidth, lHeight, 1, lBitsPerPixel, NULL);

	if (NULL != m_hBitmap)
	{
		CRect cRect;
		cRect.SetRect(0, 0, lWidth, lHeight);

		CDC cDC;
		cDC.CreateCompatibleDC(NULL);

		HBITMAP hOldBitmap = (HBITMAP)cDC.SelectObject(m_hBitmap);
		cDC.FillSolidRect(cRect, crFillColor);
		cDC.SelectObject(hOldBitmap);

		return TRUE;
	}

	return FALSE;
}

CS309Bitmap *CS309Bitmap::Copy()
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	CDC cDCSource, cDCDest;

	HBITMAP hBitmapNew = NULL;
	HBITMAP hBitmapOldDest = NULL;
	HBITMAP hBitmapOldSource = NULL;
	cDCSource.CreateCompatibleDC(NULL);
	cDCDest.CreateCompatibleDC(NULL);

	BITMAP bm;
	::GetObject(m_hBitmap, sizeof(bm), &bm);

	hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);

	hBitmapNew = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), bm.bmWidth, bm.bmHeight);

	if (NULL != hBitmapNew)
	{
		hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmapNew);

		cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, SRCCOPY);

		cDCSource.SelectObject(hBitmapOldSource);

		cDCDest.SelectObject(hBitmapOldDest);

		CS309Bitmap *pS309Bitmap = new CS309Bitmap;
		if (NULL == pS309Bitmap)
		{
			DeleteObject(hBitmapNew);
		}
		else
		{
			pS309Bitmap->m_hBitmap = hBitmapNew;
		}

		return pS309Bitmap;
	}

	return NULL;
}

CS309Bitmap *CS309Bitmap::Clip(long lLeft, long lTop, long lWidth, long lHeight, COLORREF crFillColor)
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	CS309Bitmap *pS309Bitmap = new CS309Bitmap;

	if (NULL != pS309Bitmap)
	{
		CDC cDCSource, cDCDest;

		HBITMAP hNewBitmap = NULL;
		HBITMAP hOldBitmapDest = NULL;
		HBITMAP hOldBitmapSource = NULL;
		cDCSource.CreateCompatibleDC(NULL);
		cDCDest.CreateCompatibleDC(NULL);

		BITMAP bm;
		::GetObject(m_hBitmap, sizeof(BITMAP), &bm);

		hOldBitmapSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);

		hNewBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), lWidth, lHeight);

		if (NULL == hNewBitmap)
		{
			delete pS309Bitmap;
			pS309Bitmap = NULL;
		}
		else
		{
			pS309Bitmap->m_hBitmap = hNewBitmap;

			hOldBitmapDest = (HBITMAP)cDCDest.SelectObject(hNewBitmap);
				
			long lCopyWidth = lWidth;
			long lCopyHeight = lHeight;

			if (lWidth > (bm.bmWidth - lLeft))
			{
				lCopyWidth = bm.bmWidth - lLeft;
			}
			if (lHeight > (bm.bmHeight - lTop))
			{
				lCopyHeight = bm.bmHeight - lTop;
			}

			if ((lWidth > lCopyWidth) || (lHeight > lCopyHeight))
			{

				CRect cRect;
				cRect.SetRect(0, 0, lWidth, lHeight);
				cDCDest.FillSolidRect(cRect, crFillColor);
			}

			cDCDest.BitBlt(0, 0, lCopyWidth, lCopyHeight, &cDCSource, lLeft, lTop, SRCCOPY);

			cDCDest.SelectObject(hOldBitmapDest);
		}

		cDCSource.SelectObject(hOldBitmapSource);
	}

	return pS309Bitmap;
}

CS309Bitmap *CS309Bitmap::CopyToNewBitsPerPixel(long lBitsPerPixel)
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	CS309Bitmap *pS309Bitmap = new CS309Bitmap;

	if (NULL != pS309Bitmap)
	{
		BITMAP bm;
		HBITMAP hBitmapOldSource, hBitmapOldDest;
		CDC cDCSource, cDCDest;
		cDCSource.CreateCompatibleDC(NULL);
		cDCDest.CreateCompatibleDC(NULL);

		::GetObject(m_hBitmap, sizeof(bm), &bm);

		hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
		HBITMAP	hBitmap = ::CreateBitmap(bm.bmWidth, bm.bmHeight, 1, lBitsPerPixel, NULL);

		if (NULL == hBitmap)
		{
			delete pS309Bitmap;
			pS309Bitmap = NULL;
		}
		else
		{
			pS309Bitmap->m_hBitmap = hBitmap;

			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmap);

			BOOL bReturn = cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, SRCCOPY);

			cDCDest.SelectObject(hBitmapOldDest);
		}

		cDCSource.SelectObject(hBitmapOldSource);
	}

	return pS309Bitmap;
}

CS309Bitmap *CS309Bitmap::Invert()
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	CS309Bitmap *pS309Bitmap = new CS309Bitmap;

	if (NULL != pS309Bitmap)
	{
		BITMAP bm;
		HBITMAP hBitmapOldSource, hBitmapOldDest;
		CDC cDCSource, cDCDest;
		cDCSource.CreateCompatibleDC(NULL);
		cDCDest.CreateCompatibleDC(NULL);

		::GetObject(m_hBitmap, sizeof(bm), &bm);

		hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
		HBITMAP	hBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), bm.bmWidth, bm.bmHeight);

		if (NULL == hBitmap)
		{
			delete pS309Bitmap;
			pS309Bitmap = NULL;
		}
		else
		{
			pS309Bitmap->m_hBitmap = hBitmap;

			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmap);

			cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, NOTSRCCOPY);

			cDCDest.SelectObject(hBitmapOldDest);
		}
		
		cDCSource.SelectObject(hBitmapOldSource);
	}
	
	return pS309Bitmap;
}

CS309Bitmap *CS309Bitmap::Mirror(long lMirror)
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	if (0 == lMirror)
	{
		return Copy();
	}

	CS309Bitmap *pS309Bitmap = new CS309Bitmap;

	if (NULL != pS309Bitmap)
	{
		BITMAP bm;
		HBITMAP hBitmapOldSource, hBitmapOldDest;
		CDC cDCSource, cDCDest;
		cDCSource.CreateCompatibleDC(NULL);
		cDCDest.CreateCompatibleDC(NULL);

		::GetObject(m_hBitmap, sizeof(bm), &bm);

		hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
		HBITMAP	hBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), bm.bmWidth, bm.bmHeight);

		if (NULL == hBitmap)
		{
			delete pS309Bitmap;
			pS309Bitmap = NULL;
		}
		else
		{
			pS309Bitmap->m_hBitmap = hBitmap;

			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmap);	

			switch (lMirror)
			{
				case 1:
#ifdef UNDER_CE
					cDCDest.StretchBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, bm.bmWidth, 0, -bm.bmWidth, bm.bmHeight, SRCCOPY );
#else
					cDCDest.StretchBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, bm.bmWidth-1, 0, -bm.bmWidth, bm.bmHeight, SRCCOPY );
#endif
					break;
				case 2:
#ifdef UNDER_CE
					cDCDest.StretchBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, bm.bmHeight, bm.bmWidth, -bm.bmHeight, SRCCOPY);
#else
					cDCDest.StretchBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, bm.bmHeight-1, bm.bmWidth, -bm.bmHeight, SRCCOPY);
#endif
					break;
				case 3:
#ifdef UNDER_CE
					cDCDest.StretchBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, bm.bmWidth, bm.bmHeight, -bm.bmWidth, -bm.bmHeight, SRCCOPY);
#else
					cDCDest.StretchBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, bm.bmWidth-1, bm.bmHeight-1, -bm.bmWidth, -bm.bmHeight, SRCCOPY);
#endif
					break;
				default:
					break;
			}

			cDCDest.SelectObject(hBitmapOldDest);
		}
		
		cDCSource.SelectObject(hBitmapOldSource);
	}
	
	return pS309Bitmap;
}

CS309Bitmap *CS309Bitmap::Overlay(CS309Bitmap *pS309BitmapOverlay, long lLeft, long lTop, long lWidth, long lHeight, COLORREF crFillColor, BOOL bTransparent, COLORREF crTransparentColor)
{
	if ((NULL == m_hBitmap) || (NULL == pS309BitmapOverlay) || (NULL == pS309BitmapOverlay->m_hBitmap))
	{
		return NULL;
	}

	CS309Bitmap *pS309Bitmap = new CS309Bitmap;

	if (NULL != pS309Bitmap)
	{
		long lNewWidth, lNewHeight;
		BITMAP bm;
		HBITMAP hBitmapOldSource, hBitmapOldDest;
		CDC cDCSource, cDCDest;
		cDCSource.CreateCompatibleDC(NULL);
		cDCDest.CreateCompatibleDC(NULL);

		::GetObject(m_hBitmap, sizeof(bm), &bm);

		if (bm.bmWidth < (lLeft + lWidth))
		{
			lNewWidth = lLeft + lWidth;
		}
		else
		{
			lNewWidth = bm.bmWidth;
		}

		if (bm.bmHeight < (lTop + lHeight))
		{
			lNewHeight = lTop + lHeight;
		}
		else
		{
			lNewHeight = bm.bmHeight;
		}

		hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
		HBITMAP	hBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), lNewWidth, lNewHeight);

		if (NULL == hBitmap)
		{
			delete pS309Bitmap;
			pS309Bitmap = NULL;
		}
		else
		{
			pS309Bitmap->m_hBitmap = hBitmap;

			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmap);	

			if ((lNewHeight > bm.bmHeight) || (lNewWidth > bm.bmWidth))
			{
				CRect cRect;
				cRect.SetRect(0, 0, lNewWidth, lNewHeight);
				cDCDest.FillSolidRect(cRect, crFillColor);
			}

			cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, SRCCOPY);

			cDCSource.SelectObject(pS309BitmapOverlay->m_hBitmap);
			
			if (!bTransparent)
			{
				cDCDest.BitBlt(lLeft, lTop, lWidth, lHeight, &cDCSource, 0, 0, SRCCOPY);
			}
			else
			{
#ifdef UNDER_CE
				::TransparentImage(cDCDest.GetSafeHdc(), lLeft, lTop, lWidth, lHeight, cDCSource.GetSafeHdc(), 0, 0, lWidth, lHeight, crTransparentColor);
#else // UNDER_CE
				::TransparentBlt(cDCDest.GetSafeHdc(), lLeft, lTop, lWidth, lHeight, cDCSource.GetSafeHdc(), 0, 0, lWidth, lHeight, crTransparentColor);
#endif // UNDER_CE
			}

			cDCDest.SelectObject(hBitmapOldDest);
		}
		
		cDCSource.SelectObject(hBitmapOldSource);
	}
	
	return pS309Bitmap;
}

CS309Bitmap *CS309Bitmap::Resize(long lWidth, long lHeight)
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	BITMAP bm;
	::GetObject(m_hBitmap, sizeof(bm), &bm);

	if ((lWidth == bm.bmWidth) && (lHeight == bm.bmHeight))
	{
		return Copy();
	}

	CS309Bitmap *pS309Bitmap = new CS309Bitmap;

	if (NULL != pS309Bitmap)
	{
		HBITMAP hBitmapOldSource, hBitmapOldDest;
		CDC cDCSource, cDCDest;
		cDCSource.CreateCompatibleDC(NULL);
		cDCDest.CreateCompatibleDC(NULL);


		hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
		HBITMAP	hBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), lWidth, lHeight);

		if (NULL == hBitmap)
		{
			delete pS309Bitmap;
			pS309Bitmap = NULL;
		}
		else
		{
			pS309Bitmap->m_hBitmap = hBitmap;

			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmap);	

			cDCDest.StretchBlt(0, 0, lWidth, lHeight, &cDCSource, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

			cDCDest.SelectObject(hBitmapOldDest);
		}
		
		cDCSource.SelectObject(hBitmapOldSource);
	}
	
	return pS309Bitmap;
}

CS309Bitmap *CS309Bitmap::Rotate(long lDegrees)
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	if (0 == lDegrees)
	{
		return Copy();
	}

	if (180 == lDegrees)
	{
		return Mirror(3);
	}

	CS309Bitmap *pS309Bitmap = NULL;

	LPVOID pBits1;
	DIBSECTION ds;
	long dsBitsPerPixel;
	HBITMAP hBitmapOldSource, hBitmapOldDest;
	CDC cDCSource, cDCDest;
	cDCSource.CreateCompatibleDC(NULL);
	cDCDest.CreateCompatibleDC(NULL);

	hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
//	COLORREF crColor = cDCSource.GetPixel(0, 0);
	dsBitsPerPixel = IsDIBSectionForRotate(&ds);
	if (16 <= dsBitsPerPixel)
	{
//		HBITMAP	hBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), ds.dsBm.bmHeight, ds.dsBm.bmWidth);
		HBITMAP	hBitmap = CreateDIBSection(ds.dsBm.bmHeight, ds.dsBm.bmWidth, dsBitsPerPixel, &pBits1, NULL);
		cDCSource.SelectObject(hBitmapOldSource);
		if (NULL == hBitmap)
		{
			long nLastError = ::GetLastError();
			CString strMessage = TEXT("Error on rotate (1): Out Of Memory");
			if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
			{
				strMessage.Format(TEXT("Error on rotate (1): GetLastError() = %d"), nLastError);
			}
			AfxMessageBox(strMessage, MB_ICONWARNING, 0);

		}
		else
		{
//			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(hBitmap);
//			cDCDest.SetPixel(0, 0, crColor);
//			cDCDest.SelectObject(hBitmapOldDest);
			AfxMessageBox(TEXT("Fast path"));
			CopyRotatedBits(m_hBitmap, hBitmap, lDegrees);
			pS309Bitmap = new CS309Bitmap;
			pS309Bitmap->m_hBitmap = hBitmap;
		}
	}
	else
	{
		HBITMAP dsBitmap1, dsBitmap2;
		BITMAP bm;
		GetObject(m_hBitmap, sizeof(BITMAP), &bm);
		long lBitsPerPixel = bm.bmBitsPixel;

//		if (0 == dsBitsPerPixel)
		if (true)
		{
//			if (lBitsPerPixel < 24)
//			{
				lBitsPerPixel = 24;
//			}

			dsBitmap1 = CreateDIBSection(bm.bmWidth, bm.bmHeight, lBitsPerPixel, &pBits1, NULL);
			if (NULL != dsBitmap1)
			{
				hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(dsBitmap1);
				cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, SRCCOPY);
				cDCSource.SelectObject(hBitmapOldSource);
				cDCDest.SelectObject(hBitmapOldDest);
				AfxMessageBox(TEXT("Slow path 1"));
			}
		}
		else
		{
			AfxMessageBox(TEXT("Slow path 2"));
			CS309Bitmap *pBitmap = CopyToNewBitsPerPixel(8);
			if (NULL == pBitmap)
			{
				dsBitmap1 = NULL;
			}
			else
			{
				dsBitmap1 = pBitmap->m_hBitmap;
				pBitmap->m_hBitmap = NULL;
				delete pBitmap;
			}
		}

		if (NULL == dsBitmap1)
		{
			long nLastError = ::GetLastError();
			CString strMessage = TEXT("Error on rotate (2): Out Of Memory");
			if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
			{
				strMessage.Format(TEXT("Error on rotate (2): GetLastError() = %d"), nLastError);
			}
			AfxMessageBox(strMessage, MB_ICONWARNING, 0);
		}
		else
		{
			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(dsBitmap1);
			cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, SRCCOPY);

//			dsBitmap2 = CreateCompatibleBitmap(cDCDest.GetSafeHdc(), bm.bmHeight, bm.bmWidth);
			dsBitmap2 = CreateDIBSection(bm.bmHeight, bm.bmWidth, lBitsPerPixel, &pBits1, NULL);
			cDCDest.SelectObject(hBitmapOldDest);
			if (NULL == dsBitmap2)
			{
				long nLastError = ::GetLastError();
				CString strMessage = TEXT("Error on rotate (3): Out Of Memory");
				if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
				{
					strMessage.Format(TEXT("Error on rotate (3): GetLastError() = %d"), nLastError);
				}
				AfxMessageBox(strMessage, MB_ICONWARNING, 0);

				cDCDest.SelectObject(hBitmapOldDest);
			
				DeleteObject(dsBitmap1);
				dsBitmap1 = NULL;
			}
			else
			{
//				hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(dsBitmap2);
//				cDCDest.SetPixel(0, 0, crColor);
//				cDCDest.SelectObject(hBitmapOldDest);
				CopyRotatedBits(dsBitmap1, dsBitmap2, lDegrees);

				DeleteObject(dsBitmap1);
				dsBitmap1 = NULL;

				BITMAP bm2;
				GetObject(dsBitmap2, sizeof(BITMAP), &bm2);

				if (bm.bmBitsPixel == bm2.bmBitsPixel)
				{
					pS309Bitmap = new CS309Bitmap;
					if (NULL == pS309Bitmap)
					{
						long nLastError = ::GetLastError();
						CString strMessage = TEXT("Error on rotate (4): Out Of Memory");
						if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
						{
							strMessage.Format(TEXT("Error on rotate (4): GetLastError() = %d"), nLastError);
						}
						AfxMessageBox(strMessage, MB_ICONWARNING, 0);

						DeleteObject(dsBitmap2);
						dsBitmap2 = NULL;
					}
					else
					{
						pS309Bitmap->m_hBitmap = dsBitmap2;
						dsBitmap2 = NULL;
					}
				}
				else
				{
					CS309Bitmap *pBitmap = new CS309Bitmap;
					if (NULL == pBitmap)
					{
						long nLastError = ::GetLastError();
						CString strMessage = TEXT("Error on rotate (5): Out Of Memory");
						if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
						{
							strMessage.Format(TEXT("Error on rotate (5): GetLastError() = %d"), nLastError);
						}
						AfxMessageBox(strMessage, MB_ICONWARNING, 0);

						cDCDest.SelectObject(hBitmapOldDest);
					
						DeleteObject(dsBitmap2);
						dsBitmap2 = NULL;
					}
					else
					{
						pBitmap->m_hBitmap = dsBitmap2;
						dsBitmap2 = NULL;
						pS309Bitmap = pBitmap->CopyToNewBitsPerPixel(bm.bmBitsPixel);
						delete pBitmap;
					}
				}
			}
		}
	}

	return pS309Bitmap;
}

HBITMAP CS309Bitmap::CreateDIBSection(long lWidth, long lHeight, long lBitsPerPixel, LPVOID pBits, RGBQUAD *pRGBQuad)
{
	HBITMAP hBitmap = NULL;
	BITMAPINFOHEADER *bmih = (BITMAPINFOHEADER *)new BYTE[sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * 256)];
	if (NULL != bmih)
	{
		RGBQUAD *bmiColors = (RGBQUAD *)bmih + sizeof(BITMAPINFOHEADER);

		bmih->biSize = sizeof(BITMAPINFOHEADER);
		bmih->biWidth = lWidth;
		bmih->biHeight = lHeight;
		bmih->biPlanes = 1;
		bmih->biBitCount = (USHORT)lBitsPerPixel;
		bmih->biCompression = BI_RGB;
		bmih->biSizeImage = 0;
		bmih->biXPelsPerMeter = 0;
		bmih->biYPelsPerMeter = 0;
		bmih->biClrUsed = 0;
		bmih->biClrImportant = 0;

		DWORD dwMask;
		switch (lBitsPerPixel)
		{
			case 16:
				bmih->biCompression = BI_BITFIELDS;
				dwMask = 0x7c00;
				memcpy(&bmiColors[0],&dwMask,4);
				dwMask = 0x03E0;
				memcpy(&bmiColors[1],&dwMask,4);
				dwMask = 0x001F;
				memcpy(&bmiColors[2],&dwMask,4);
				break;
			case 32:
				bmih->biCompression = BI_BITFIELDS;
				dwMask = 0x00FF0000;
				memcpy(&bmiColors[0],&dwMask,4);
				dwMask = 0x0000FF00;
				memcpy(&bmiColors[1],&dwMask,4);
				dwMask = 0x000000FF;
				memcpy(&bmiColors[2],&dwMask,4);
				break;
			default:
				break;
		}

		hBitmap = ::CreateDIBSection(NULL, (BITMAPINFO *) bmih, 0, &pBits, NULL, 0);

		delete [] bmih;
	}
	return hBitmap;
}

long CS309Bitmap::IsDIBSectionForRotate(DIBSECTION *ds)
{
	if (m_hBitmap != NULL)
	{
		if (sizeof(DIBSECTION) == GetObject(m_hBitmap, sizeof(DIBSECTION), ds))
		{
			if (ds->dsBm.bmBits != NULL)
			{
				return ds->dsBm.bmBitsPixel;
			}
		}
	}

	return 0;
}

void CS309Bitmap::CopyRotatedBits(HBITMAP hBitmapSource, HBITMAP hBitmapDest, long lDegrees)
{
	DIBSECTION ds1, ds2;
	GetObject(hBitmapSource, sizeof(DIBSECTION), &ds1);
	GetObject(hBitmapDest, sizeof(DIBSECTION), &ds2);

	long lBytes = 0;
	switch (ds1.dsBm.bmBitsPixel)
	{
		default:
			break;
		case 32:
			lBytes++;
		case 24:
			lBytes++;
		case 16:
			lBytes++;
		case 8:
			lBytes++;
	}

	long lSourceRowBytes = (((ds1.dsBm.bmWidth * lBytes) + 3) / 4) * 4;
	long lDestRowBytes = (((ds2.dsBm.bmWidth * lBytes) + 3) / 4) * 4;

	unsigned char *source;
	unsigned char *dest;
	long ldestx, ldesty, lsourcex, lsourcey;

	if (ds1.dsBm.bmBits == NULL)
	{
		AfxMessageBox(TEXT("bits 1 null"));
	}
	if (ds2.dsBm.bmBits == NULL)
	{
		AfxMessageBox(TEXT("bits 2 null"));
	}
	switch (lDegrees)
	{
		case 90:
			ldestx = -1;
			for(lsourcey = ds1.dsBm.bmHeight - 1; lsourcey >= 0; lsourcey--)
			{
				ldestx++;
				ldesty = -1;
				for(lsourcex = 0; lsourcex < ds1.dsBm.bmWidth; lsourcex++)
				{
					ldesty++;
					source = (unsigned char *)ds1.dsBm.bmBits + (lSourceRowBytes * ((ds1.dsBm.bmHeight - 1) - lsourcey)) + (lsourcex * lBytes);
					dest = (unsigned char *)ds2.dsBm.bmBits + (lDestRowBytes * ((ds2.dsBm.bmHeight - 1) - ldesty)) + (ldestx * lBytes);
					memcpy(dest, source, lBytes);
				}
			}
			break;
		case 270:
			ldestx = -1;
			for(lsourcey = 0; lsourcey < ds1.dsBm.bmHeight; lsourcey++)
			{
				ldestx++;
				ldesty = -1;
				for(lsourcex = ds1.dsBm.bmWidth - 1; lsourcex >= 0; lsourcex-- )
				{
					ldesty++;
					source = (unsigned char *)ds1.dsBm.bmBits + (lSourceRowBytes * ((ds1.dsBm.bmHeight - 1) - lsourcey)) + (lsourcex * lBytes);
					dest = (unsigned char *)ds2.dsBm.bmBits + (lDestRowBytes * ((ds2.dsBm.bmHeight - 1) - ldesty)) + (ldestx * lBytes);
					memcpy(dest, source, lBytes);
				}
			}
			break;
	}
}

CS309Bitmap *CS309Bitmap::Scroll(long lScrollX, long lScrollY)
{
	if (NULL == m_hBitmap)
	{
		return NULL;
	}

	if ((0 == lScrollX) && (0 == lScrollY))
	{
		return Copy();
	}

	CS309Bitmap *pS309Bitmap = NULL;

	DIBSECTION ds;
	long dsBitsPerPixel;
	HBITMAP hBitmapOldSource, hBitmapOldDest;
	CDC cDCSource, cDCDest;
	cDCSource.CreateCompatibleDC(NULL);
	cDCDest.CreateCompatibleDC(NULL);

	hBitmapOldSource = (HBITMAP)cDCSource.SelectObject(m_hBitmap);
	dsBitsPerPixel = IsDIBSectionForRotate(&ds);
	if (8 <= dsBitsPerPixel)
	{
		HBITMAP	hBitmap = ::CreateCompatibleBitmap(cDCSource.GetSafeHdc(), ds.dsBm.bmHeight, ds.dsBm.bmWidth);
		if (NULL == hBitmap)
		{
			long nLastError = ::GetLastError();
			CString strMessage = TEXT("Error on scroll (1): Out Of Memory");
			if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
			{
				strMessage.Format(TEXT("Error on scroll (1): GetLastError() = %d"), nLastError);
			}
			AfxMessageBox(strMessage, MB_ICONWARNING, 0);

			cDCSource.SelectObject(hBitmapOldSource);
		}
		else
		{
			CopyScrolledBits(m_hBitmap, hBitmap, lScrollX, lScrollY);
			pS309Bitmap = new CS309Bitmap;
			pS309Bitmap->m_hBitmap = hBitmap;
		}
	}
	else
	{
		LPVOID pBits1;
		HBITMAP dsBitmap1, dsBitmap2;
		BITMAP bm;
		GetObject(m_hBitmap, sizeof(BITMAP), &bm);
		long lBitsPerPixel = bm.bmBitsPixel;

		if (0 == dsBitsPerPixel)
		{
			if (lBitsPerPixel < 24)
			{
				lBitsPerPixel = 24;
			}

			dsBitmap1 = CreateDIBSection(bm.bmWidth, bm.bmHeight, lBitsPerPixel, &pBits1, NULL);
		}
		else
		{
			CS309Bitmap *pBitmap = CopyToNewBitsPerPixel(8);
			if (NULL == pBitmap)
			{
				dsBitmap1 = NULL;
			}
			else
			{
				dsBitmap1 = pBitmap->m_hBitmap;
				pBitmap->m_hBitmap = NULL;
				delete pBitmap;
			}
		}

		if (NULL == dsBitmap1)
		{
			long nLastError = ::GetLastError();
			CString strMessage = TEXT("Error on scroll (2): Out Of Memory");
			if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
			{
				strMessage.Format(TEXT("Error on scroll (2): GetLastError() = %d"), nLastError);
			}
			AfxMessageBox(strMessage, MB_ICONWARNING, 0);
		}
		else
		{
			hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(dsBitmap1);
			cDCDest.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &cDCSource, 0, 0, SRCCOPY);

			dsBitmap2 = CreateCompatibleBitmap(cDCDest.GetSafeHdc(), bm.bmHeight, bm.bmWidth);
			cDCDest.SelectObject(hBitmapOldDest);
			if (NULL == dsBitmap2)
			{
				long nLastError = ::GetLastError();
				CString strMessage = TEXT("Error on scroll (3): Out Of Memory");
				if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
				{
					strMessage.Format(TEXT("Error on scroll (3): GetLastError() = %d"), nLastError);
				}
				AfxMessageBox(strMessage, MB_ICONWARNING, 0);

				cDCDest.SelectObject(hBitmapOldDest);
			
				DeleteObject(dsBitmap1);
				dsBitmap1 = NULL;
			}
			else
			{
				CopyScrolledBits(dsBitmap1, dsBitmap2, lScrollX, lScrollY);

				DeleteObject(dsBitmap1);
				dsBitmap1 = NULL;

				BITMAP bm2;
				GetObject(dsBitmap2, sizeof(BITMAP), &bm2);

				if (bm.bmBitsPixel == bm2.bmBitsPixel)
				{
					pS309Bitmap = new CS309Bitmap;
					if (NULL == pS309Bitmap)
					{
						long nLastError = ::GetLastError();
						CString strMessage = TEXT("Error on scroll (4): Out Of Memory");
						if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
						{
							strMessage.Format(TEXT("Error on scroll (4): GetLastError() = %d"), nLastError);
						}
						AfxMessageBox(strMessage, MB_ICONWARNING, 0);

						DeleteObject(dsBitmap2);
						dsBitmap2 = NULL;
					}
					else
					{
						pS309Bitmap->m_hBitmap = dsBitmap2;
						dsBitmap2 = NULL;
					}
				}
				else
				{
					CS309Bitmap *pBitmap = new CS309Bitmap;
					if (NULL == pBitmap)
					{
						long nLastError = ::GetLastError();
						CString strMessage = TEXT("Error on scroll (5): Out Of Memory");
						if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
						{
							strMessage.Format(TEXT("Error on scroll (5): GetLastError() = %d"), nLastError);
						}
						AfxMessageBox(strMessage, MB_ICONWARNING, 0);

						cDCDest.SelectObject(hBitmapOldDest);
					
						DeleteObject(dsBitmap2);
						dsBitmap2 = NULL;
					}
					else
					{
						pBitmap->m_hBitmap = dsBitmap2;
						dsBitmap2 = NULL;
						pS309Bitmap = pBitmap->CopyToNewBitsPerPixel(bm.bmBitsPixel);
						delete pBitmap;
					}
				}
			}
		}
	}

	return pS309Bitmap;
}

void CS309Bitmap::CopyScrolledBits(HBITMAP hBitmapSource, HBITMAP hBitmapDest, long lX, long lY)
{
	DIBSECTION ds1, ds2;
	GetObject(hBitmapSource, sizeof(DIBSECTION), &ds1);
	GetObject(hBitmapDest, sizeof(DIBSECTION), &ds2);

	long lBytes = 0;
	switch (ds1.dsBm.bmBitsPixel)
	{
		default:
			break;
		case 32:
			lBytes++;
		case 24:
			lBytes++;
		case 16:
			lBytes++;
		case 8:
			lBytes++;
	}

	long lSourceRowBytes = (((ds1.dsBm.bmWidth * lBytes) + 3) / 4) * 4;
	long lDestRowBytes = (((ds2.dsBm.bmWidth * lBytes) + 3) / 4) * 4;

	unsigned char *source;
	unsigned char *dest;
	long ldestx, ldesty, lsourcex, lsourcey;
	long lScrollX = lX;
	long lScrollY = lY;

	while (lScrollX < 0)
	{
		lScrollX += ds1.dsBm.bmWidth;
	}

	while (lScrollX >= ds1.dsBm.bmWidth)
	{
		lScrollX -= ds1.dsBm.bmWidth;
	}

	while (lScrollY < 0)
	{
		lScrollY += ds1.dsBm.bmHeight;
	}

	while (lScrollY >= ds1.dsBm.bmHeight)
	{
		lScrollY -= ds1.dsBm.bmHeight;
	}

	for (lsourcex = 0; lsourcex < ds1.dsBm.bmWidth; lsourcex++)
	{
		ldestx = lsourcex + lScrollX;
		if (ldestx >= ds1.dsBm.bmWidth) 
		{
			ldestx -= ds1.dsBm.bmWidth;
		}

		for (lsourcey = 0; lsourcey < ds1.dsBm.bmHeight; lsourcey++)
		{
			ldesty = lsourcey + lScrollY;
			if (ldesty >= ds1.dsBm.bmHeight) 
			{
				ldesty -= ds1.dsBm.bmHeight;
			}

			source = (unsigned char *)ds1.dsBm.bmBits + (lSourceRowBytes * ((ds1.dsBm.bmHeight - 1) - lsourcey)) + (lsourcex * lBytes);
			dest = (unsigned char *)ds2.dsBm.bmBits + (lDestRowBytes * ((ds2.dsBm.bmHeight - 1) - ldesty)) + (ldestx * lBytes);
			memcpy(dest, source, lBytes);
		}
	}
}

void CS309Bitmap::CreateFromScreen()
{
	DeleteHBITMAP();

	CDC cDCSource, cDCDest;

#ifdef UNDER_CE
	cDCSource.CreateDC(NULL, NULL, NULL, NULL);
#else
	cDCSource.CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
#endif
	cDCDest.CreateCompatibleDC(NULL);

	long lScreenWidth = GetSystemMetrics(SM_CXSCREEN); 
	long lScreenHeight = GetSystemMetrics(SM_CYSCREEN); 
 
	HBITMAP m_hBitmap = ::CreateCompatibleBitmap(cDCSource, lScreenWidth, lScreenHeight);
	HBITMAP hBitmapOldDest = (HBITMAP)cDCDest.SelectObject(m_hBitmap);
	cDCDest.BitBlt(0, 0, lScreenWidth, lScreenHeight, &cDCSource, 0, 0, SRCCOPY);
	cDCDest.SelectObject(hBitmapOldDest);
}

HBITMAP CS309Bitmap::TakeHBITMAP()
{
	HBITMAP hBitmap = m_hBitmap;
	m_hBitmap = NULL;
	return hBitmap;
}
