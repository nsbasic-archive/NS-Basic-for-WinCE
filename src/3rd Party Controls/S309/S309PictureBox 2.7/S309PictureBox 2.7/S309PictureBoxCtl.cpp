// S309PictureBoxCtl.cpp : Implementation of the CS309PictureBox ActiveX Control class.

#include "stdafx.h"
#include "winuser.h"
#include "math.h"
#ifndef UNDER_CE
#include <comdef.h>
#endif
#include "imgdecmp.h"
#include "pegcards.h"
#include "S309PictureBox.h"
#include "S309PictureBoxCtl.h"
#include "S309PictureBoxPpg.h"

#ifdef UNDER_CE
#ifdef WIN32_PLATFORM_HPCPRO
#define S309_MR_MOUSE
#endif // WIN32_PLATFORM_HPCPRO
#else // UNDER_CE
#define S309_MR_MOUSE
#endif // UNDER_CE

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef UNDER_CE
#ifdef WIN32_PLATFORM_PSPC
	#define IDB_CARD_HEIGHT                 41
	#define IDB_CARD_WIDTH					29     
	#define IDB_WILD2_X                     3
	#define IDB_WILD2_Y                     15
	#define IDB_WILD2_H                     11
	#define IDB_WILD2_W                     23
#else
	#define IDB_CARD_HEIGHT                 70
	#define IDB_CARD_WIDTH					52     
	#define IDB_WILD0_X                     43
	#define IDB_WILD0_Y                     2
	#define IDB_WILD0_H                     29
	#define IDB_WILD0_W                     8
	#define IDB_WILD0I_X                    9
	#define IDB_WILD0I_Y                    68
	#define IDB_WILD1_X                     11
	#define IDB_WILD1_Y                     1
	#define IDB_WILD1_H                     7
	#define IDB_WILD1_W                     30
	#define IDB_WILD1I_X                    41
	#define IDB_WILD1I_Y                    69
	#define IDB_WILD2_X                     11
	#define IDB_WILD2_Y                     29
	#define IDB_WILD2_H                     12
	#define IDB_WILD2_W                     30
#endif
#else
	#define IDB_CARD_HEIGHT                 96
	#define IDB_CARD_WIDTH					71     
	#define IDB_WILD0_X                     60
	#define IDB_WILD0_Y                     3
	#define IDB_WILD0_H                     29
	#define IDB_WILD0_W                     8
	#define IDB_WILD0I_X                    2
	#define IDB_WILD0I_Y                    64
	#define IDB_WILD1_X                     20
	#define IDB_WILD1_Y                     3
	#define IDB_WILD1_H                     7
	#define IDB_WILD1_W                     30
	#define IDB_WILD1I_X                    20
	#define IDB_WILD1I_Y                    87
	#define IDB_WILD2_X                     20
	#define IDB_WILD2_Y                     42
	#define IDB_WILD2_H                     12
	#define IDB_WILD2_W                     31
#endif

// --- In  : nBitsPerPixel - bits per pixel
// --- Out : 
// --- Returns :The number of colours for this colour depth
// --- Effect : Returns the number of color table entries given the number
//              of bits per pixel of a bitmap
static int NumColorEntries(int nBitsPerPixel) 
{
    int nColors = 0;

    switch (nBitsPerPixel) 
    {
	    case 1:  nColors = 2;   break;
#ifdef UNDER_CE
        case 2:  nColors = 4;   break;   // winCE only       
#endif
        case 4:  nColors = 16;  break;
        case 8:  nColors = 256; break;
        case 16:
        case 24:
        case 32: nColors = 0;   break;   // 16,24 or 32 bpp have no color table

        default:
           ASSERT(FALSE);
    }

    return nColors;
}


IMPLEMENT_DYNCREATE(CS309PictureBox, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309PictureBox, COleControl)
	//{{AFX_MSG_MAP(CS309PictureBox)
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
#ifdef S309_MR_MOUSE // Comment out this ifdef and the endif to use the classwizard.
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
#endif               // Comment out this endif and the ifdef to use the classwizard. 
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CS309PictureBox, COleControl)
	//{{AFX_DISPATCH_MAP(CS309PictureBox)
	DISP_PROPERTY_EX(CS309PictureBox, "AnimationAvailable", GetAnimationAvailable, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "AnimationInterval", GetAnimationInterval, SetAnimationInterval, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "Appearance", GetAppearance, SetAppearance, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "AutoRefresh", GetAutoRefresh, SetAutoRefresh, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "AutoSize", GetAutoSize, SetAutoSize, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "BitmapOnClipboard", GetBitmapOnClipboard, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "BorderStyle", GetBorderStyle, SetBorderStyle, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Center", GetCenter, SetCenter, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Clip", GetClip, SetClip, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "ClipHeight", GetClipHeight, SetClipHeight, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ClipLeft", GetClipLeft, SetClipLeft, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ClipTop", GetClipTop, SetClipTop, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ClipWidth", GetClipWidth, SetClipWidth, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "CommonBitmapID", GetCommonBitmapID, SetCommonBitmapID, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "CommonBitmapType", GetCommonBitmapType, SetCommonBitmapType, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "DrawWidth", GetDrawWidth, SetDrawWidth, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "FillColor", GetFillColor, SetFillColor, VT_COLOR)
	DISP_PROPERTY_EX(CS309PictureBox, "FillStyle", GetFillStyle, SetFillStyle, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Height", GetHeight, SetHeight, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageHeight", GetImageHeight, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageLoadBufferSize", GetImageLoadBufferSize, SetImageLoadBufferSize, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageLoadMaxHeight", GetImageLoadMaxHeight, SetImageLoadMaxHeight, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageLoadMaxWidth", GetImageLoadMaxWidth, SetImageLoadMaxWidth, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageLoaded", GetImageLoaded, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageWidth", GetImageWidth, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "Invert", GetInvert, SetInvert, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "Left", GetLeft, SetLeft, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "Mirror", GetMirror, SetMirror, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Name", GetName, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX(CS309PictureBox, "Overlay", GetOverlay, SetOverlay, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "OverlayLeft", GetOverlayLeft, SetOverlayLeft, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "OverlayTop", GetOverlayTop, SetOverlayTop, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "OverlayTransparentColor", GetOverlayTransparentColor, SetOverlayTransparentColor, VT_COLOR)
	DISP_PROPERTY_EX(CS309PictureBox, "PenFillStyle", GetPenFillStyle, SetPenFillStyle, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "PenStyle", GetPenStyle, SetPenStyle, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Picture", GetPicture, SetPicture, VT_BSTR)
	DISP_PROPERTY_EX(CS309PictureBox, "PlayingCard", GetPlayingCard, SetPlayingCard, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Resize", GetResize, SetResize, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "ResizeHeight", GetResizeHeight, SetResizeHeight, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ResizeWidth", GetResizeWidth, SetResizeWidth, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ResourceBitmapID", GetResourceBitmapID, SetResourceBitmapID, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ResourceFile", GetResourceFile, SetResourceFile, VT_BSTR)
	DISP_PROPERTY_EX(CS309PictureBox, "Rotate", GetRotate, SetRotate, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "ScaleMode", GetScaleMode, SetScaleMode, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "ScreenBitsPerPixel", GetScreenBitsPerPixel, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "ScreenHeight", GetScreenHeight, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ScreenLeft", GetScreenLeft, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ScreenWidth", GetScreenWidth, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ScreenTop", GetScreenTop, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "Stretch", GetStretch, SetStretch, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CS309PictureBox, "Top", GetTop, SetTop, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "TransparentColor", GetTransparentColor, SetTransparentColor, VT_COLOR)
	DISP_PROPERTY_EX(CS309PictureBox, "Visible", GetVisible, SetVisible, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "WaitCursor", GetWaitCursor, SetWaitCursor, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "Width", GetWidth, SetWidth, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "WildCard", GetWildCard, SetWildCard, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "hBitmap", GethBitmap, SethBitmap, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "VersionMajor", GetVersionMajor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "VersionMinor", GetVersionMinor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "ResourceFileLoaded", GetResourceFileLoaded, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageBitsPerPixel", GetImageBitsPerPixel, SetImageBitsPerPixel, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "ImageLoadBitsPerPixel", GetImageLoadBitsPerPixel, SetImageLoadBitsPerPixel, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Scroll", GetScroll, SetScroll, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "ScrollX", GetScrollX, SetScrollX, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ScrollY", GetScrollY, SetScrollY, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "MouseMovePointsCount", GetMouseMovePointsCount, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "MouseMovePoints", GetMouseMovePoints, SetMouseMovePoints, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "Version", GetVersion, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "FontBold", GetFontBold, SetFontBold, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "FontItalic", GetFontItalic, SetFontItalic, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "FontName", GetFontName, SetFontName, VT_BSTR)
	DISP_PROPERTY_EX(CS309PictureBox, "FontStrikethru", GetFontStrikethru, SetFontStrikethru, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "FontUnderline", GetFontUnderline, SetFontUnderline, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "FontTransparent", GetFontTransparent, SetFontTransparent, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "FontWeight", GetFontWeight, SetFontWeight, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "FontSize", GetFontSize, SetFontSize, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "FocusRect", GetFocusRect, SetFocusRect, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "FocusRectIndentLeft", GetFocusRectIndentLeft, SetFocusRectIndentLeft, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "FocusRectIndentRight", GetFocusRectIndentRight, SetFocusRectIndentRight, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "FocusRectIndentTop", GetFocusRectIndentTop, SetFocusRectIndentTop, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "FocusRectIndentBottom", GetFocusRectIndentBottom, SetFocusRectIndentBottom, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "CommandButton", GetCommandButton, SetCommandButton, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "hFont", GethFont, SethFont, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "ScrollBars", GetScrollBars, SetScrollBars, VT_I2)
	DISP_PROPERTY_EX(CS309PictureBox, "HScrollPosition", GetHScrollPosition, SetHScrollPosition, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "VScrollPosition", GetVScrollPosition, SetVScrollPosition, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "OnToolbar", GetOnToolbar, SetOnToolbar, VT_BOOL)
	DISP_PROPERTY_EX(CS309PictureBox, "ResourceIconID", GetResourceIconID, SetResourceIconID, VT_I4)
	DISP_PROPERTY_EX(CS309PictureBox, "UseJPEGBitsPerPixel", GetUseJPEGBitsPerPixel, SetUseJPEGBitsPerPixel, VT_BOOL)
	DISP_FUNCTION(CS309PictureBox, "Animate", MethodAnimate, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "CaptureScreen", MethodCaptureScreen, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "ClipImage", MethodClipImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "Cls", MethodCls, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "Copy", MethodCopy, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "CreateImage", MethodCreateImage, VT_EMPTY, VTS_I4 VTS_I4)
	DISP_FUNCTION(CS309PictureBox, "Hide", MethodHide, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "InvertImage", MethodInvertImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "MirrorImage", MethodMirrorImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "Move", MethodMove, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION(CS309PictureBox, "Paste", MethodPaste, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "QBColor", MethodQBColor, VT_COLOR, VTS_I2)
	DISP_FUNCTION(CS309PictureBox, "ResizeImage", MethodResizeImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "RotateImage", MethodRotateImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "SetFocus", MethodSetFocus, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "SetPointArray", MethodSetPointArray, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION(CS309PictureBox, "Show", MethodShow, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "ZOrder", MethodZOrder, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CS309PictureBox, "SaveImageToFile", MethodSaveImageToFile, VT_BOOL, VTS_BSTR VTS_I2)
	DISP_FUNCTION(CS309PictureBox, "RGB", MethodRGB, VT_COLOR, VTS_I2 VTS_I2 VTS_I2)
	DISP_FUNCTION(CS309PictureBox, "IntensityRed", MethodIntensityRed, VT_I2, VTS_COLOR)
	DISP_FUNCTION(CS309PictureBox, "IntensityGreen", MethodIntensityGreen, VT_I2, VTS_COLOR)
	DISP_FUNCTION(CS309PictureBox, "IntensityBlue", MethodIntensityBlue, VT_I2, VTS_COLOR)
	DISP_FUNCTION(CS309PictureBox, "ScrollImage", MethodScrollImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "RefreshDesktopWallpaper", MethodRefreshDesktopWallpaper, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "SetCapture", MethodSetCapture, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "ReleaseCapture", MethodReleaseCapture, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "DrawMouseMoveLinesEx", MethodDrawMouseMoveLinesEx, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_COLOR)
	DISP_FUNCTION(CS309PictureBox, "DrawMouseMoveLines", MethodDrawMouseMoveLines, VT_EMPTY, VTS_COLOR)
	DISP_FUNCTION(CS309PictureBox, "GetMouseMovePoint", MethodGetMouseMovePoint, VT_BOOL, VTS_I2 VTS_PI4 VTS_PI4)
	DISP_FUNCTION(CS309PictureBox, "RefreshX", MethodRefreshX, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CS309PictureBox, "TextWidth", MethodTextWidth, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CS309PictureBox, "TextHeight", MethodTextHeight, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CS309PictureBox, "DrawCircle", MethodDrawCircle, VT_EMPTY, VTS_I4 VTS_I4 VTS_R4 VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawLine", MethodDrawLine, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawPoint", MethodDrawPoint, VT_EMPTY, VTS_I4 VTS_I4 VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawPolygon", MethodDrawPolygon, VT_EMPTY, VTS_I2 VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawRoundRect", MethodDrawRoundRect, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawPolyLines", MethodDrawPolyLines, VT_EMPTY, VTS_I2 VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawText", MethodDrawText, VT_EMPTY, VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawPicture", MethodDrawPicture, VT_EMPTY, VTS_BSTR VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CS309PictureBox, "DrawIcon", MethodDrawIcon, VT_BOOL, VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_PROPERTY_PARAM(CS309PictureBox, "Pixel", GetPixel, SetPixel, VT_COLOR, VTS_I4 VTS_I4)
	DISP_STOCKFUNC_REFRESH()
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	DISP_STOCKPROP_HWND()
	DISP_STOCKPROP_CAPTION()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CS309PictureBox, "AboutBox", DISPID_ABOUTBOX, MethodAboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CS309PictureBox, COleControl)
	//{{AFX_EVENT_MAP(CS309PictureBox)
	EVENT_CUSTOM("LostFocusX", FireLostFocus, VTS_NONE)
	EVENT_CUSTOM("GotFocusX", FireGotFocus, VTS_NONE)
	EVENT_CUSTOM("VBCEAutoSize", FireVBCEAutoSize, VTS_I4  VTS_I4)
	EVENT_CUSTOM("HScroll", FireHScroll, VTS_I4  VTS_PBOOL VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	EVENT_CUSTOM("VScroll", FireVScroll, VTS_I4  VTS_PBOOL VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	EVENT_CUSTOM("TapAndHold", FireTapAndHold, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	EVENT_STOCK_CLICK()
	EVENT_STOCK_DBLCLICK()
	EVENT_STOCK_KEYDOWN()
	EVENT_STOCK_KEYPRESS()
	EVENT_STOCK_KEYUP()
	EVENT_CUSTOM_ID("MouseDown", DISPID_MOUSEDOWN, FireMouseDown, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	EVENT_CUSTOM_ID("MouseMove", DISPID_MOUSEMOVE, FireMouseMove, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	EVENT_CUSTOM_ID("MouseUp", DISPID_MOUSEUP, FireMouseUp, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CS309PictureBox, 1)
	PROPPAGEID(CS309PictureBoxPropPage::guid)
END_PROPPAGEIDS(CS309PictureBox)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309PictureBox, "S309.PictureBox.1",
	0x5d28fd29, 0xc320, 0x11d2, 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CS309PictureBox, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DS309PictureBox =
		{ 0xd4d7c4b7, 0x2cc5, 0x11d3, { 0xae, 0x29, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };
const IID BASED_CODE IID_DS309PictureBoxEvents =
		{ 0xd4d7c4b8, 0x2cc5, 0x11d3, { 0xae, 0x29, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information prtdlg

static const DWORD BASED_CODE _dwS309PictureBoxOleMisc =
//	OLEMISC_SIMPLEFRAME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_ALWAYSRUN |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CS309PictureBox, IDS_S309PICTUREBOX, _dwS309PictureBoxOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox::CS309PictureBoxFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309PictureBox

BOOL CS309PictureBox::CS309PictureBoxFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_S309PICTUREBOX,
			IDB_S309PICTUREBOX,
//			afxRegApartmentThreading,
			0,
			_dwS309PictureBoxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox::CS309PictureBox - Constructor

CS309PictureBox::CS309PictureBox()
{
	InitializeIIDs(&IID_DS309PictureBox, &IID_DS309PictureBoxEvents);

	OLE_COLOR backcolor;

//	if (!IsAmbientDisplayNameImplemented(&m_strName,false))
//	{
//		AfxMessageBox(_T("AmbientDisplayName not Implemented"), MB_ICONERROR + MB_OK, 0);
//	}
	m_strName = AmbientDisplayName();
	if (m_strName.GetLength() == 0)
	{
		m_strName = AfxGetAppName();
	}

	m_bAnimationAvailable = false;
	m_bAutoRefresh = true;
	m_bAutoSize = false;
	m_bClip = false;
	m_bCommandButton = false;
//	m_bDesignMode = false;
	m_bDisplayExpired = true;
	m_bFirstTimeAutoSize = false;
	m_bFocusRect = false;
	m_bFontTransparent = true;
#ifdef UNDER_CE
#ifdef S309_MR_MOUSE
	if ((GetSystemMetrics(SM_CXCURSOR) != 0) || (GetSystemMetrics(SM_CYCURSOR) != 0))
	{
		m_bHasMousePointer = true;
	}
	else
	{
		m_bHasMousePointer = false;
	}
#else // S309_MR_MOUSE
	m_bHasMousePointer = false;
#endif // S309_MR_MOUSE
#else // UNDER_CE
	m_bHasMousePointer = false;
#endif // UNDER_CE
	m_bHaveFocus = false;
	m_bHaveName = false;
	m_bInvert = false;
	m_bIsStretched = false;
	m_bOnToolbar = false;
	m_bOverlay = false;
	m_bResize = false;
	m_bScroll = false;
	m_bStretch = false;
	m_bVBCE = false;
	m_bVBCEAutoSize = false;
	m_bVisible= true;
	m_bWaitCursor = false;
	m_bWaitingForResize = false;
	m_bWorkingAnimationAvailable = false;
	m_bWorkingAnimationInitialized = false;
	m_bWorkingAnimationInvert = false;
	m_bWorkingCaptureScreen = false;
	m_bWorkingClip = false;
	m_bWorkingInvert = false;
	m_bWorkingPropExchange = false;
	m_bOnToolbar = false;
	m_bUseJPEGBitsPerPixel = true;

	m_dteExpire.SetDateTime(2000, 7, 31, 23, 59, 59);

	m_hBitmap = NULL;
	m_hWorkingBitmap = NULL;
	m_hWorkingIconBitmap = NULL;
	m_hCommCtrl = NULL;
	m_hFont = NULL;
	m_hInstance = NULL;
	m_hInstMe = AfxGetInstanceHandle();
	m_hParentWindow = NULL;
	m_hPegCards = NULL;
	m_hResourceFile = NULL;
	m_hWorkingAnimationBitmap[0] = NULL;
	m_hWorkingAnimationBitmap[1] = NULL;

	m_nAnimationInterval = 0;
	m_nAppearance = 0; //drawfocus
	m_nBorderStyle = 0;
	m_nCenter = 0;
	m_nClipHeight = 0;
	m_nClipLeft = 0;
	m_nClipTop = 0;
	m_nClipWidth = 0;
	m_nCommonBitmapType = 0;
	m_nCommonBitmapID = -1;
	m_nDrawTextCurrentY = 0;
	m_nPenStyle = 0;
	m_nDrawWidth = 1;
	m_nFillStyle = 0;
	m_nFocusRectIndentBottom = 2;
	m_nFocusRectIndentLeft = 2;
	m_nFocusRectIndentRight = 2;
	m_nFocusRectIndentTop = 2;
	m_nFontNamesCount = 0;
	m_nHideHeight = GetWidth();
	m_nHideWidth = GetHeight();
	m_nImageLoadBufferSize = 0;
	m_nImageLoadMaxHeight = 1000;
	m_nImageLoadMaxWidth = 1000;
	m_nImageLoadScalePercent =100;
	m_nMirror = 0;
	m_nMouseMovePoints = 2;
	m_nMouseMovePointsCount = 0;
	m_nOverlayLeft = 0;
	m_nOverlayTop = 0;
	m_nPenFillStyle = 1;
	m_nPenStyle = 1;
	m_nPlayingCard = 0;
	m_nResizeHeight = 0;
	m_nResizeWidth = 0;
	m_nResourceBitmapID = -1;
	m_nResourceIconID = -1;
	m_nResourceID = -1;
	m_nRotate = 0;
	m_nScrollBars = 0;
//	m_nWorkingScrollBars = -1;
	m_nScrollX = 0;
	m_nScrollY = 0;
	m_nTimer = 0;
	m_nWildCard = 0;
	m_nWorkingAnimationCount = 0;
	m_nWorkingAnimationHeight[0] = 0;
	m_nWorkingAnimationHeight[1] = 0;
	m_nWorkingAnimationInterval = 0;
	m_nWorkingAnimationLeft[0] = 0;
	m_nWorkingAnimationLeft[1] = 0;
	m_nWorkingAnimationMirror = 0;
	m_nWorkingAnimationRotate = 0;
	m_nWorkingAnimationTop[0] = 0;
	m_nWorkingAnimationTop[1] = 0;
	m_nWorkingAnimationWidth[0] = 0;
	m_nWorkingAnimationWidth[1] = 0;
	m_nWorkingClipHeight = 0;
	m_nWorkingClipLeft = 0;
	m_nWorkingClipTop = 0;
	m_nWorkingClipWidth = 0;
	m_nWorkingMirror = 0;
	m_nWorkingRotate = 0;
	m_nWorkingWildCard = 0;
	m_nHScrollPosition = 0;
	m_nVScrollPosition = 0;

	m_nWorkingHCX = ::GetSystemMetrics(SM_CXHSCROLL);
	m_nWorkingHCY = ::GetSystemMetrics(SM_CYHSCROLL);
	m_nWorkingVCX = ::GetSystemMetrics(SM_CXVSCROLL);
	m_nWorkingVCY = ::GetSystemMetrics(SM_CYVSCROLL);
	
	m_strPicture.Empty();
	m_strResourceFile.Empty();

	m_vTag = COleVariant();
	backcolor = AmbientBackColor();
	SetBackColor(backcolor);
//	m_crBackColor = TranslateColor(backcolor, NULL);
	m_ocFillColor = RGB(0,0,0);
	m_ocTransparentColor = (unsigned long)-1;
	m_ocOverlayTransparentColor = (unsigned long)-1;
	m_nBorderStyle = 0; // GetBorderStyle();

//	SetBorderStyle(0);
//	SetAppearance(0);
//	SetText(TEXT(""));

	HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);
	m_nImageLoadBitsPerPixel = GetDeviceCaps(sourceDC, BITSPIXEL);
	::DeleteDC(sourceDC);
	if (m_nImageLoadBitsPerPixel == 16)
	{
		m_nImageLoadBitsPerPixel = 24;
	}

//	if (!IsAmbientUserModeImplemented(&m_bUserMode, true))
//	{
//		AfxMessageBox(_T("AmbientUserMode not Implemented"), MB_ICONERROR + MB_OK, 0);
//	}

	SetFontName(TEXT("Tahoma"));
	HDC dcNew = ::CreateCompatibleDC(NULL);

 	m_nLogPixelsY = ::GetDeviceCaps(dcNew,LOGPIXELSY);
	
//	int rc = EnumFontFamilies((HDC)dcNew, (LPTSTR)NULL, (FONTENUMPROC)CallbackEnumFontFamilyCallback2, (LPARAM)this);

	::DeleteDC(dcNew);

#ifndef UNDER_CE
	m_LogFont.lfHeight = -MulDiv(9, m_nLogPixelsY, 72);
#else // UNDER_CE
	m_LogFont.lfHeight = -1 * (long)(((double)(9 * m_nLogPixelsY) / 72.0) + 0.5);
#endif // UNDER_CE
//	m_LogFont.lfHeight = -1 * (9 * m_nLogPixelsY / 72);
	m_LogFont.lfWidth = 0;
	m_LogFont.lfEscapement = 0; 
	m_LogFont.lfOrientation = 0; 
	m_LogFont.lfWeight = 400; 
	m_LogFont.lfItalic = false; 
	m_LogFont.lfUnderline = false; 
	m_LogFont.lfStrikeOut = false; 
	m_LogFont.lfOutPrecision = OUT_DEFAULT_PRECIS; 
	m_LogFont.lfClipPrecision = CLIP_DEFAULT_PRECIS; 
	m_LogFont.lfQuality = DEFAULT_QUALITY; 
}

int CS309PictureBox::CallbackEnumFontFamilyCallback2(ENUMLOGFONT *lpelf, NEWTEXTMETRIC *lpntm, int FontType,  LPARAM lParam)
{
	int nReturn = 1;

	if (FontType == TRUETYPE_FONTTYPE)
	{
		CS309PictureBox* lpS309PictureBox = (CS309PictureBox*)lParam;

		lpS309PictureBox->m_LogFont.lfCharSet = lpntm->tmCharSet;
		lpS309PictureBox->m_LogFont.lfPitchAndFamily = lpntm->tmPitchAndFamily;
		_tcscpy(lpS309PictureBox->m_LogFont.lfFaceName, lpelf->elfLogFont.lfFaceName);
		
		nReturn = 0;
	}

	return nReturn;
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox::~CS309PictureBox - Destructor

CS309PictureBox::~CS309PictureBox()
{
	m_nWorkingAnimationInterval = 0;
	CommonSetNewTimer();

	for (int i = 0; i < 2; i++)
	{
		if (m_hWorkingAnimationBitmap[i] != NULL)
		{
			::DeleteObject(m_hWorkingAnimationBitmap[i]);
			m_hWorkingAnimationBitmap[i] = NULL;
		}
	}

	if (m_hFont != NULL)
	{
		::DeleteObject(m_hFont);
		m_hFont = NULL;
	}

	if (m_hBitmap != NULL)
	{
		::DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}
	if (m_hResourceFile != NULL)
	{
		FreeLibrary(m_hResourceFile);
		m_hResourceFile = NULL;
	}
	if (m_hPegCards != NULL)
	{
		FreeLibrary(m_hPegCards);
		m_hPegCards = NULL;
	}
	if (m_hCommCtrl != NULL)
	{
		FreeLibrary(m_hCommCtrl);
		m_hCommCtrl = NULL;
	}
}


/////////////////////////////////////////////////////////////////////////////
// NOTE: For WinCE, use AdjustCtlBounds() to adjust the size of the 
//            'CRect& rcBounds' parameter that is passed into the control's 
//            OnDraw() handler.  This adjustment is required for some versions 
//            of Pocket Visual Basic.
static CRect AdjustCtlBounds(const COleControl* pCtl, const CRect &rcBounds)
{
//	if((!::IsWindow(pCtl->m_hWnd)) || (pCtl->GetParent() == NULL))
		return rcBounds;

/*	CRect rcAdjBounds;
	pCtl->GetParent()->GetClientRect(&rcAdjBounds);

	if( (rcAdjBounds.Width() < rcBounds.Width()) && 
		(rcAdjBounds.Height() < rcBounds.Height()) )
		return rcAdjBounds;
	else
		return rcBounds; */
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxCtrl::OnDraw - Drawing function

void CS309PictureBox::OnDraw(CDC* pdc, const CRect& rcSubmittedBounds, const CRect& rcInvalid)
{

	// Adjust the bounding rectangle
	CRect rcBounds = AdjustCtlBounds(this,rcSubmittedBounds);
	BITMAP Bitmap;
	CRect cRect;
	BOOL bResized = false;
	BOOL b16bpp = false;
	bool bFill = true;
	int nBorderOffsetTop = 0;
	int nBorderOffsetLeft = 0;

#ifndef UNDER_CE
	if (AmbientUserMode())
	{
		AfxMessageBox(_T("This version S309 PictureBox Control is not allowed to be used as a run time control on the desktop."), MB_ICONERROR + MB_OK, 0);
		return;
	}
#endif

	if (m_hBitmap == NULL)
	{
		bResized = CommonLoadImageIntoBitmap();
	}

	if (!bResized) 
	{
		bResized = CommonCheckAutoSize(true);
	}

	if (bResized)
	{
		if (m_bWaitingForResize)
		{
			m_bVBCEAutoSize = true;
			m_bAutoSize = false;
#ifdef UNDER_CE
			FireVBCEAutoSize(m_nAutoSizeWidth - 6, m_nAutoSizeHeight - 6);
#endif
			InvalidateControl(NULL);
		}
		else
		{
			m_bWaitingForResize = true;
		}
	}

	if (!bResized)
	{
		CommonScrollBars();

		if (m_bVBCEAutoSize)
		{
			m_bVBCEAutoSize = false;
			m_bAutoSize = true;
		}

		long nStyle = ::GetWindowLong((HWND)GetHwnd(), GWL_STYLE);
		long nOldStyle = nStyle;
		long nExStyle = ::GetWindowLong((HWND)GetHwnd(), GWL_EXSTYLE);
		long nOldExStyle = nExStyle;
		nExStyle &= (0xffffffff ^ (WS_EX_CLIENTEDGE | WS_EX_WINDOWEDGE | WS_EX_DLGMODALFRAME | WS_EX_STATICEDGE));
		nStyle &= (0xffffffff ^ WS_BORDER);
		
		if (m_nBorderStyle != 0)
		{
			nBorderOffsetTop = rcBounds.top;
			nBorderOffsetLeft = rcBounds.left;
			switch (m_nAppearance)
			{
				case -4:
					nExStyle |= (WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME);
//					rcBounds.DeflateRect(3, 3);
					break;
				case -3:
					nExStyle |= WS_EX_CLIENTEDGE;
//					rcBounds.DeflateRect(2, 2);
					break;
				case -2:
					pdc->DrawEdge(rcBounds, EDGE_SUNKEN, BF_RECT | BF_ADJUST);
					break;
				case -1:
					pdc->DrawEdge(rcBounds, EDGE_SUNKEN, BF_RECT | BF_ADJUST | BF_SOFT);
					break;
				case 0:
					pdc->Draw3dRect(rcBounds, RGB(0,0,0), RGB(0,0,0)); 
					rcBounds.DeflateRect(1, 1);
					break;
				case 1:
					pdc->DrawEdge(rcBounds, EDGE_RAISED, BF_RECT | BF_ADJUST | BF_SOFT);
					break;
				case 2:
					pdc->DrawEdge(rcBounds, EDGE_RAISED, BF_RECT | BF_ADJUST);
					break;
				case 3:
					nExStyle |= WS_EX_DLGMODALFRAME;
//					rcBounds.DeflateRect(2, 2);
					break;
				case 4:
					nStyle |= WS_BORDER; 
//					rcBounds.DeflateRect(1, 1);
					break;
				default:
					break;
			}
			nBorderOffsetTop = rcBounds.top - nBorderOffsetTop;
			nBorderOffsetLeft = rcBounds.left - nBorderOffsetLeft;
		}

		if (nStyle != nOldStyle)
		{
			::SetWindowLong((HWND)GetHwnd(),GWL_STYLE,nStyle);
		}
		if (nExStyle != nOldExStyle)
		{
			::SetWindowLong((HWND)GetHwnd(),GWL_EXSTYLE,nExStyle);
		}
		if ((nStyle != nOldStyle) || (nExStyle != nOldExStyle))
		{
			::SetWindowPos((HWND)GetHwnd(), NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
		}

		if (m_hBitmap == NULL)
		{
			m_nWorkingAnimationInterval = 0;
			CommonSetNewTimer();

			if (m_ocTransparentColor < 16777216)
			{
				if (m_ocTransparentColor == GetBackColor())
				{
					bFill = false;
				}
			}
					
			if (bFill)
			{
				pdc->FillSolidRect(rcBounds, TranslateColor(GetBackColor(),NULL));
			}

			m_bAnimationAvailable = false;
		}		
		else
		{ 
			m_bIsStretched = false;
			if (!::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap))
			{
				InvalidateControl(NULL);
			}
			else
			{
				if (Bitmap.bmBitsPixel == 16)
				{
					b16bpp = true;
				}

				GetRectInContainer(cRect);

				int nDestTop = nBorderOffsetTop;
				int nDestLeft = nBorderOffsetLeft;
				int nDestWidth = rcBounds.Width();
				int nDestHeight = rcBounds.Height();

				int nSourceTop = 0;
				int nSourceLeft = 0;
				int nSourceWidth = Bitmap.bmWidth;
				int nSourceHeight = Bitmap.bmHeight;

				if (m_nCenter != 0)
				{
					int nDiffWidth = rcBounds.Width() - Bitmap.bmWidth;
					int nDiffHeight = rcBounds.Height() - Bitmap.bmHeight;
					if ((nDiffWidth != 0) && ((m_nCenter == 1) || (m_nCenter == 3)))
					{
						if (nDiffWidth < 0)
						{
							nSourceLeft = nSourceLeft - (nDiffWidth / 2);
							nSourceWidth = rcBounds.Width();
						}
						if (nDiffWidth > 0)
						{
							nDestLeft = nDestLeft + (nDiffWidth / 2);
						}
					}
					if ((nDiffHeight != 0) && ((m_nCenter == 2) || (m_nCenter == 3)))
					{
						if (nDiffHeight < 0)
						{
							nSourceTop = nSourceTop - (nDiffHeight / 2);
							nSourceHeight = rcBounds.Height();
						}
						if (nDiffHeight > 0)
						{
							nDestTop = nDestTop + (nDiffHeight / 2);
						}
					}
				}
				else
				{
					if (m_bStretch)
					{
						if (rcBounds.Width() != nSourceWidth)
						{
							m_bIsStretched = true;
						}
						if (rcBounds.Height() != nSourceHeight)
						{
							m_bIsStretched = true;
						}
					}
					else
					{
						long nStyle = ::GetWindowLong((HWND)GetHwnd(), GWL_STYLE);

						if ((nStyle & WS_HSCROLL) == WS_HSCROLL)
						{
							nSourceLeft = m_nHScrollPosition;
							nSourceWidth = m_nWorkingHPage;
						}

						if ((nStyle & WS_VSCROLL) == WS_VSCROLL)
						{
							nSourceTop = m_nVScrollPosition;
							nSourceHeight = m_nWorkingVPage;
						}
					}
				}

#ifdef UNDER_CE
				bool bTransparent = false;
				COLORREF crTransparentColor;
				if (m_ocTransparentColor < 16777216)
				{
					crTransparentColor = TranslateColor(m_ocTransparentColor, NULL);
					bTransparent = true;
				}
#endif

				if ((!m_bIsStretched) && ((rcBounds.Width() > nSourceWidth) || (rcBounds.Height() > nSourceHeight)))
				{
#ifdef UNDER_CE
					if (bTransparent)
					{
						if (crTransparentColor == TranslateColor(GetBackColor(),NULL))
						{
							bFill = false;
						}
					}
#endif					
					if (bFill)
					{
						pdc->FillSolidRect(rcBounds, TranslateColor(GetBackColor(),NULL));
#ifndef UNDER_CE
						::GdiFlush();
#endif
					}
				}

				HDC dcNew;
				HBITMAP hBitmap;
				
				if ((m_bIsStretched) && (m_bStretch))
				{
#ifdef UNDER_CE
					if (!bTransparent)
					{
#endif
						dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
						hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

						::StretchBlt(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, dcNew, nSourceLeft, nSourceTop, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

						::SelectObject(dcNew, hBitmap);
						::DeleteDC(dcNew);
#ifdef UNDER_CE
					}
					else
					{
						if (b16bpp)
						{
							hBitmap = CommonGetBitmapCopyToNewBPP(m_hBitmap, 24);
						}
						else
						{
							hBitmap = m_hBitmap;
						}
						::TransparentImage(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, hBitmap, nSourceLeft, nSourceTop, Bitmap.bmWidth, Bitmap.bmHeight, crTransparentColor);
						if (b16bpp)
						{
							::DeleteObject(hBitmap);
						}
					}					
#endif
				}
				else
				{  
#ifdef UNDER_CE
					if (!bTransparent)
					{
#endif
						dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
						hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

						::BitBlt(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, dcNew, nSourceLeft, nSourceTop, SRCCOPY);

						::SelectObject(dcNew, hBitmap);
						::DeleteDC(dcNew);
#ifdef UNDER_CE
					}
					else
					{
						if (nDestWidth > nSourceWidth)
							nDestWidth = nSourceWidth;
						if (nDestHeight > nSourceHeight)
							nDestHeight = nSourceHeight;

						if (b16bpp)
						{
							hBitmap = CommonGetBitmapCopyToNewBPP(m_hBitmap, 24);
						}
						else
						{
							hBitmap = m_hBitmap;
						}
						::TransparentImage(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, hBitmap, nSourceLeft, nSourceTop, nDestWidth, nDestHeight, crTransparentColor);
						if (b16bpp)
						{
							::DeleteObject(hBitmap);
						}
					}					
#endif
				}
				
				CommonSetNewTimer();
			}
		}

		if ((m_bFocusRect) && (m_bHaveFocus))
		{
			rcBounds.DeflateRect(m_nFocusRectIndentLeft, m_nFocusRectIndentTop, m_nFocusRectIndentRight,m_nFocusRectIndentBottom);

			pdc->DrawFocusRect(rcBounds);
		}

		if (m_bCommandButton)
		{
			HFONT hOldFont = NULL;

			CommonCreateFont();
			
			if (m_hFont != NULL)
			{
				hOldFont = (HFONT)::SelectObject(pdc->GetSafeHdc(), m_hFont);
			}

			rcBounds.DeflateRect(2,2);

			pdc->SetTextColor(TranslateColor(GetForeColor(),NULL));

#ifdef UNDER_CE
			pdc->DrawText(GetText(), -1, rcBounds, DT_CENTER | DT_VCENTER);
#else
			_bstr_t bstrText = GetText();
			pdc->DrawText(bstrText, -1, rcBounds, DT_CENTER | DT_VCENTER);
#endif

			if (hOldFont != NULL)
			{
				::SelectObject(pdc->GetSafeHdc(), hOldFont);
			}
		}
	}
} 

/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox::DoPropExchange - Persistence support

void CS309PictureBox::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	BOOL bFontBold = GetFontBold();
	BOOL bFontItalic = GetFontItalic();
	BOOL bFontStrikethru = GetFontStrikethru();
	BOOL bFontUnderline = GetFontUnderline();
	long nFontSize = GetFontSize();
	long nFontWeight = GetFontWeight();
	CString strFontName = m_LogFont.lfFaceName;
	
	PX_Bool( pPX, _T("AutoRefresh"), m_bAutoRefresh, true);
	PX_Bool( pPX, _T("AutoSize"), m_bAutoSize, false);
	PX_Bool( pPX, _T("Clip"), m_bClip, false);
	PX_Bool( pPX, _T("CommandButton"), m_bCommandButton, false);
	PX_Bool( pPX, _T("FocusRect"), m_bFocusRect, false);
	PX_Bool( pPX, _T("FontBold"), bFontBold, false);
	PX_Bool( pPX, _T("FontItalic"), bFontItalic, false);
	PX_Bool( pPX, _T("FontStrikethru"), bFontStrikethru, false);
	PX_Bool( pPX, _T("FontTransparent"), m_bFontTransparent, false);
	PX_Bool( pPX, _T("FontUnderline"), bFontUnderline, false);
	PX_Bool( pPX, _T("Invert"), m_bInvert, false);
	PX_Bool( pPX, _T("Overlay"), m_bOverlay, false);
	PX_Bool( pPX, _T("Resize"), m_bResize, false);
	PX_Bool( pPX, _T("Scroll"), m_bScroll, false);
	PX_Bool( pPX, _T("Stretch"), m_bStretch, false);
	PX_Bool( pPX, _T("Visible"), m_bVisible, true);
	PX_Bool( pPX, _T("WaitCursor"), m_bWaitCursor, false);
	PX_Bool( pPX, _T("UseJPEGBitsPerPixel"), m_bUseJPEGBitsPerPixel, false);

	PX_Short( pPX, _T("Appearance"), m_nAppearance, 0);
	PX_Short( pPX, _T("BorderStyle"), m_nBorderStyle, 0);
	PX_Short( pPX, _T("Center"), m_nCenter, 0);
	PX_Short( pPX, _T("CommonBitmapID"), m_nCommonBitmapID, -1);
	PX_Short( pPX, _T("CommonBitmapType"), m_nCommonBitmapType, 0);
	PX_Short( pPX, _T("FillStyle"), m_nFillStyle, 0);
	PX_Short( pPX, _T("Mirror"), m_nMirror, 0);
	PX_Short( pPX, _T("MouseMovePoints"), m_nMouseMovePoints, 2);
	PX_Short( pPX, _T("PenFillStyle"), m_nPenFillStyle, 1);
	PX_Short( pPX, _T("PenStyle"), m_nPenStyle, 1);
	PX_Short( pPX, _T("PlayingCard"), m_nPlayingCard, 0);
	PX_Short( pPX, _T("Rotate"), m_nRotate, 0);
	PX_Short( pPX, _T("ScrollBars"), m_nScrollBars, 0);
	PX_Short( pPX, _T("Wildcard"), m_nWildCard, 0);

	PX_Long( pPX, _T("AnimationInterval"), m_nAnimationInterval, 0);
	PX_Long( pPX, _T("ClipHeight"), m_nClipHeight, 0);
	PX_Long( pPX, _T("ClipLeft"), m_nClipLeft, 0);
	PX_Long( pPX, _T("ClipTop"), m_nClipTop, 0);
	PX_Long( pPX, _T("ClipWidth"), m_nClipWidth, 0);
	PX_Long( pPX, _T("FocusRectIndentBottom"), m_nFocusRectIndentBottom, 2);
	PX_Long( pPX, _T("FocusRectIndentLeft"), m_nFocusRectIndentLeft, 2);
	PX_Long( pPX, _T("FocusRectIndentRight"), m_nFocusRectIndentRight, 2);
	PX_Long( pPX, _T("FontSize"), nFontSize, 8);
	PX_Long( pPX, _T("FontWeight"), nFontWeight, 400);
	PX_Long( pPX, _T("OverlayLeft"), m_nOverlayLeft, 0);
	PX_Long( pPX, _T("OverlayTop"), m_nOverlayTop, 0);
	PX_Long( pPX, _T("ResizeHeight"), m_nResizeHeight, 0);
	PX_Long( pPX, _T("ResizeWidth"), m_nResizeWidth, 0);
	PX_Long( pPX, _T("ResourceBitmapID"), m_nResourceBitmapID, -1);
	PX_Long( pPX, _T("ResourceIconID"), m_nResourceIconID, -1);
	PX_Long( pPX, _T("ScrollX"), m_nScrollX, 0);
	PX_Long( pPX, _T("ScrollY"), m_nScrollY, 0);

	PX_String(pPX, _T("Picture"), m_strPicture, _T("") );
	PX_String(pPX, _T("ResourceFile"), m_strResourceFile, _T("") );
	PX_String(pPX, _T("FontName"), strFontName, m_LogFont.lfFaceName);

	PX_Color( pPX, _T("FillColor"), m_ocFillColor, RGB(0,0,0));
	PX_Color( pPX, _T("OverlayTransparentColor"), m_ocOverlayTransparentColor, -1);
	PX_Color( pPX, _T("TransparentColor"), m_ocTransparentColor, -1);

	m_bWorkingPropExchange = true;
	SetFontBold(bFontBold);
	SetFontItalic(bFontItalic);
	SetFontStrikethru(bFontStrikethru);
	SetFontUnderline(bFontUnderline);
	SetFontSize(nFontSize);
	SetFontWeight(nFontWeight);
	SetFontName((LPCTSTR)strFontName);
	m_bWorkingPropExchange = false;

#ifdef UNDER_CE
	PX_Bool( pPX, _T("VBCE"), m_bVBCE, false);
#else
	PX_Bool( pPX, _T("VBCE"), m_bVBCE, true);
#endif

	if (m_nPlayingCard > 0)
	{
		SetPlayingCard(m_nPlayingCard);
	}

	if (m_nResourceBitmapID > -1)
	{
		SetResourceBitmapID(m_nResourceBitmapID);
	}

	if (m_nResourceIconID > -1)
	{
		SetResourceIconID(m_nResourceIconID);
	}

	if (m_nCommonBitmapID > -1)
	{
		SetCommonBitmapID(m_nCommonBitmapID);
	}
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox::OnResetState - Reset control to default state

void CS309PictureBox::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox::AboutBox - Display an "About" box to the user

void CS309PictureBox::MethodAboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_S309PICTUREBOX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox message handlers

BSTR CS309PictureBox::GetPicture() 
{
	CString strResult;
	strResult = m_strPicture;
	return strResult.AllocSysString();
}

void CS309PictureBox::SetPicture(LPCTSTR lpszNewValue) 
{
	CommonClearForLoad();

	m_strPicture = lpszNewValue;

	SetModifiedFlag();
	m_bDisplayExpired = true;

	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

BOOL CS309PictureBox::GetAutoSize() 
{
	return ((m_bAutoSize) || (m_bVBCEAutoSize));
}

void CS309PictureBox::SetAutoSize(BOOL bNewValue) 
{
	m_bAutoSize = bNewValue;
	m_bVBCEAutoSize = false;
//	m_nWorkingScrollBars = -1;
	SetModifiedFlag();

	CommonDesignRefresh();
}

BOOL CS309PictureBox::GetStretch() 
{
	return m_bStretch;
}

void CS309PictureBox::SetStretch(BOOL bNewValue) 
{
	m_bStretch = bNewValue;
//	m_nWorkingScrollBars = -1;
	SetModifiedFlag();
	CommonDesignRefresh();
}

long CS309PictureBox::GetTop() 
{
	CRect cRect;
	long lTop;
	lTop = 0;
    if (GetRectInContainer(cRect) != 0) 
	{
		lTop = cRect.top;
	}

	return lTop;
}

void CS309PictureBox::SetTop(long nNewValue) 
{
	CRect cRect;
	long lDiff;
    if (GetRectInContainer(cRect) != 0) 
	{
		lDiff = cRect.bottom - cRect.top;
		cRect.top = nNewValue;
		cRect.bottom = nNewValue + lDiff;
		SetRectInContainer(cRect);
	}
	SetModifiedFlag();
}

long CS309PictureBox::GetLeft() 
{
	CRect cRect;
	long lLeft;
	lLeft = 0;
    if (GetRectInContainer(cRect) != 0) 
	{
		lLeft = cRect.left;
	}

	return lLeft;
}

void CS309PictureBox::SetLeft(long nNewValue) 
{
	CRect cRect;
	long lDiff;
    if (GetRectInContainer(cRect) != 0) 
	{
		lDiff = cRect.right - cRect.left;
		cRect.left = nNewValue;
		cRect.right = nNewValue + lDiff;
		SetRectInContainer(cRect);
	}
	SetModifiedFlag();
}

long CS309PictureBox::GetHeight() 
{
	long lHeight;
	if (m_bVisible)
	{
		CRect cRect;
		lHeight = 0;
		if (GetRectInContainer(cRect) != 0) 
		{
			lHeight = (long)cRect.Height();
		}
	}
	else
	{
		lHeight = m_nHideHeight;
	}

	return lHeight;
}

void CS309PictureBox::SetHeight(long nNewValue) 
{
	if (m_bVisible)
	{
		CRect cRect;
		if (GetRectInContainer(cRect) != 0) 
		{
			cRect.bottom = cRect.top + nNewValue;
			SetRectInContainer(cRect);
		}
	}
	else
	{
		m_nHideHeight = nNewValue;
	}
//	int nH, nW;
//	GetControlSize(&nW, &nH);
//	SetControlSize(nW, nNewValue);
//	SetModifiedFlag();
}

long CS309PictureBox::GetWidth() 
{
	long lWidth;
	if (m_bVisible)
	{
		CRect cRect;
		lWidth = 0;
		if (GetRectInContainer(cRect) != 0) 
		{
			lWidth = (long)cRect.Width();
		}
	}
	else
	{
		lWidth = m_nHideWidth; 
	}

	return lWidth;
}

void CS309PictureBox::SetWidth(long nNewValue) 
{
	if (m_bVisible)
	{
		CRect cRect;
		if (GetRectInContainer(cRect) != 0) 
		{
			cRect.right = cRect.left + nNewValue;
			SetRectInContainer(cRect);
		}
	}
	else
	{
		m_nHideWidth = nNewValue;
	}
//	int nH, nW;
//	GetControlSize(&nW, &nH);
//	SetControlSize(nNewValue, nH);
//	SetModifiedFlag();
}

void CS309PictureBox::MethodCls() 
{
	CommonClearForLoad();
	
	if (m_hBitmap != NULL)
	{
		::DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}

	m_nDrawTextCurrentY = 0;

//	m_nWorkingScrollBars = -1;
//	CommonSetWindowLong();

	InvalidateControl(NULL);
}

long CS309PictureBox::GetImageHeight() 
{
	BITMAP Bitmap;
	long nRet = 0;

	if (m_hBitmap != NULL)
	{
		::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);
		nRet = Bitmap.bmHeight;
	}

	return nRet;
}

long CS309PictureBox::GetImageWidth() 
{
	BITMAP Bitmap;
	long nRet = 0;

	if (m_hBitmap != NULL)
	{
		::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);
		nRet = Bitmap.bmWidth;
	}

	return nRet;
}

BOOL CS309PictureBox::GetWaitCursor() 
{
	return m_bWaitCursor;
}

void CS309PictureBox::SetWaitCursor(BOOL bNewValue) 
{
	m_bWaitCursor = bNewValue;
	SetModifiedFlag();
}

short CS309PictureBox::GetRotate() 
{
	return m_nRotate;
}

void CS309PictureBox::SetRotate(short nNewValue) 
{
	if ((nNewValue == 0) || (nNewValue == 90) || (nNewValue == 180) || (nNewValue == 270))
	{
		m_nRotate = nNewValue;
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	SetModifiedFlag();
}

void CS309PictureBox::MethodRotateImage() 
{
	m_hBitmap = CommonRotate(m_hBitmap);
	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

short CS309PictureBox::GetMirror() 
{
	return m_nMirror;
}

void CS309PictureBox::SetMirror(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 3))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nMirror = nNewValue;
	}
	SetModifiedFlag();
}

void CS309PictureBox::MethodMirrorImage() 
{
	m_hBitmap = CommonMirror(m_hBitmap);
	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

void CS309PictureBox::MethodZOrder(short nPosition) 
{
	if (nPosition == 1)
	{
		SetWindowPos( &wndBottom, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE );
	}
	if (nPosition == 0)
	{
		SetWindowPos( &wndTop, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE );
	}
}

BOOL CS309PictureBox::GetVisible() 
{
	return m_bVisible;
}

void CS309PictureBox::SetVisible(BOOL bNewValue) 
{
	if (m_bVisible != bNewValue)
	{
		m_bVisible = bNewValue;
		CRect cRect;
		if (GetRectInContainer(cRect) != 0) 
		{
			if (m_bVisible)
			{
				cRect.right = cRect.left + m_nHideWidth;
				cRect.bottom = cRect.top + m_nHideHeight;
			}
			else
			{
				m_nHideWidth = cRect.right - cRect.left;
				m_nHideHeight = cRect.bottom - cRect.top;
				cRect.right = cRect.left;
				cRect.bottom = cRect.top;
			}
			SetRectInContainer(cRect);
		}
//		if (m_bVisible)
//		{
//			SetWindowPos( 0, 0, 0, m_nHideWidth, m_nHideHeight, SWP_NOMOVE + SWP_NOZORDER + SWP_SHOWWINDOW);
//		}
//		else
//		{

//			SetWindowPos( 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOZORDER + SWP_HIDEWINDOW);
	//		::SetWindowPos((HWND)GetHwnd(), 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_HIDEWINDOW);
//		}
		CommonSetNewTimer();
		SetModifiedFlag();
	}
}

void CS309PictureBox::MethodShow() 
{
	SetVisible(true);
//	SetWindowPos( 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_SHOWWINDOW);
//	m_bVisible = true;
//	CommonSetNewTimer();
//	SetModifiedFlag();
}

void CS309PictureBox::MethodHide() 
{
	SetVisible(false);
//	SetWindowPos( 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_HIDEWINDOW);
//	::SetWindowPos((HWND)GetHwnd(), 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_HIDEWINDOW);
//    m_bVisible = false;
//	CommonSetNewTimer();
//	SetModifiedFlag();
}

void CS309PictureBox::MethodMove(long nX, long nY, long nW, long nH) 
{
	CRect cRect;
    if (GetRectInContainer(cRect) != 0) 
	{
		cRect.left = nX;
		cRect.top = nY;
		if (m_bVisible)
		{
			cRect.right = nX + nW;
			cRect.bottom = nY + nH;
		}
		else
		{
			cRect.right = nX;
			cRect.bottom = nY;
			m_nHideWidth = nW;
			m_nHideHeight = nH;
		}
		SetRectInContainer(cRect);
	}
}

BSTR CS309PictureBox::GetResourceFile() 
{
	CString strResult;
	strResult = m_strResourceFile;
	return strResult.AllocSysString();
}

void CS309PictureBox::SetResourceFile(LPCTSTR lpszNewValue) 
{

	CommonClearForLoad();

	m_strResourceFile = lpszNewValue;

	SetModifiedFlag();
}

long CS309PictureBox::GetResourceBitmapID() 
{
	return m_nResourceBitmapID;
}

void CS309PictureBox::SetResourceBitmapID(long nNewValue) 
{
	CString strResourceFile;

	strResourceFile = m_strResourceFile;
	CommonClearForLoad();
	m_strResourceFile = strResourceFile;

	m_nResourceBitmapID = nNewValue;
	m_nResourceID = m_nResourceBitmapID;
	SetModifiedFlag();

	m_bDisplayExpired = true;
	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

short CS309PictureBox::GetPlayingCard() 
{
	return m_nPlayingCard;
}

void CS309PictureBox::SetPlayingCard(short nNewValue) 
{
	if (m_hPegCards == NULL)
	{
		CommonGetCardsInstance();
	}

	CommonClearForLoad();

	m_nPlayingCard = nNewValue;
	m_nResourceID = m_nPlayingCard;

#ifndef UNDER_CE
	if ((m_nResourceID >= 1) && (m_nResourceID <= 65))
	{
		m_hInstance = m_hPegCards;
	}
	if ((m_nResourceID >= 67) && (m_nResourceID <= 68))
	{
		m_hInstance = m_hPegCards;
	}
	if ((m_nResourceID >= IDB_JOKER) && (m_nResourceID <= IDB_SUIT4))
	{
		m_hInstance = m_hInstMe;
	}
#else
	if ((m_nResourceID >= IDACLUBS) && (m_nResourceID <= IDKSPADES))
	{
		m_hInstance = m_hPegCards;
	}
	if ((m_nResourceID >= IDFACEDOWNFIRST) && (m_nResourceID <= IDFACEDOWNLAST))
	{
		m_hInstance = m_hPegCards;
	}
	if ((m_nResourceID >= IDCARDO) && (m_nResourceID <= IDCARDGHOST))
	{
		m_hInstance = m_hPegCards;
	}
	if ((m_nResourceID >= IDB_JOKER) && (m_nResourceID <= IDB_SUIT4))
	{
		m_hInstance = m_hInstMe;
	}
	if ((m_nResourceID >= (IDB_JOKER - 100)) && (m_nResourceID <= (IDB_SUIT4 - 100)))
	{
		m_nResourceID += 100;
		m_hInstance = m_hInstMe;
	}
#endif
	if (m_hInstance == NULL)
	{
		if (!AmbientUserMode())
		{
			InvalidateControl(NULL);
			SetModifiedFlag();
		}
		else
		{
			m_nResourceID = -1;
			ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		}
	}
	else
	{
		SetModifiedFlag();
		m_bDisplayExpired = true;
		if (!CommonLoadImageIntoBitmap())
		{
			InvalidateControl(NULL);
		}
	}
}

long CS309PictureBox::GetAnimationInterval() 
{
	return m_nAnimationInterval;
}

void CS309PictureBox::SetAnimationInterval(long nNewValue) 
{
	if ((nNewValue < 0) && (nNewValue > 65535))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nAnimationInterval = nNewValue;
	}
	SetModifiedFlag();
}

BOOL CS309PictureBox::GetAnimationAvailable() 
{
	return m_bAnimationAvailable;
}

void CS309PictureBox::MethodAnimate() 
{
	if ((m_bVisible) && (m_bWorkingAnimationAvailable))
	{
		AnimatePlayingCard(true, m_hBitmap);
	}
}

void CS309PictureBox::OnEnabledChanged() 
{
	COleControl::OnEnabledChanged();
}


void CS309PictureBox::OnTimer(UINT nIDEvent) 
{
	COleControl::OnTimer(nIDEvent);
	CommonSetNewTimer();
	if ((m_bVisible) && (m_bWorkingAnimationAvailable))
	{
		AnimatePlayingCard(true, m_hBitmap);
	}
}

void CS309PictureBox::CommonSetNewTimer()
{
	bool bKillTimer = true;

    if ((m_nWorkingAnimationInterval != m_nAnimationInterval) || (!m_bVisible))
	{
		if (m_nTimer != 0)
		{
			KillTimer(m_nTimer);
			m_nTimer = 0;
		}
		m_nWorkingAnimationInterval = m_nAnimationInterval;

		if (m_bWorkingAnimationAvailable)
		{
			while (m_nWorkingAnimationCount != 0)
			{
				AnimatePlayingCard(false, m_hBitmap);
			}
		}
	}

	if ((m_nWorkingAnimationInterval > 0) && (m_bAnimationAvailable) && (m_bVisible))
	{
		if (m_nTimer == 0)
		{
			m_nTimer = SetTimer(2, m_nWorkingAnimationInterval, NULL);
		}
		bKillTimer = false;
	}

	if (bKillTimer)
	{
		if (m_nTimer != 0)
		{
			KillTimer(m_nTimer);
			m_nTimer = 0;
		}
	}
}

void CS309PictureBox::AnimatePlayingCard(BOOL bInvalidateControl, HBITMAP hBitmap)
{
	int		nResource = 0;
	int		nLeft = 0;
	int		nTop = 0;
	int		nWidth = 0;
	int		nHeight = 0;
	int		nTopOffset = 0;
	int		nLeftOffset = 0;
	int		nInvertLeft = 0;
	int		nInvertTop = 0;
	bool	bInvert = false;
	bool	bOriginal = false;
	bool	bSwapBitmap[2];

#ifndef WIN32_PLATFORM_PSPC
	HBITMAP hBitmap1, hBitmap2;
#endif

	if ((m_hPegCards != NULL) && (m_bWorkingAnimationAvailable))
	{  
		if (!m_bWorkingAnimationInitialized)
		{
			for (int i = 0; i < 2; i++)
			{
				if (m_hWorkingAnimationBitmap[i] != NULL)
				{
					::DeleteObject(m_hWorkingAnimationBitmap[i]);
					m_hWorkingAnimationBitmap[i] = NULL;
				}
			}
		}

		m_nWorkingAnimationCount++;

		switch (m_nPlayingCard)
		{
#ifdef UNDER_CE
#ifndef WIN32_PLATFORM_PSPC
#if WIN32_PLATFORM_HPCPRO
			case IDFACEDOWN1:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 0;
					m_nWorkingAnimationTop[0] = 0;
					m_nWorkingAnimationWidth[0] = IDB_CARD_WIDTH;
					m_nWorkingAnimationHeight[0] = IDB_CARD_HEIGHT;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_ROCKET);
					m_hWorkingAnimationBitmap[1] = NULL;

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = true;
				bSwapBitmap[1] = false;
				break;
			}
#endif WIN32_PLATFORM_HPCPRO
			case IDFACEDOWN2:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = IDANNFACE2_1X;
					m_nWorkingAnimationTop[0] = IDANNFACE2_1Y;
					m_nWorkingAnimationWidth[0] = IDANNFACE2_1W;
					m_nWorkingAnimationHeight[0] = IDANNFACE2_1H;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDANNFACE2_1);
					m_hWorkingAnimationBitmap[1] = NULL;

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = true;
				bSwapBitmap[1] = false;
				break;
			}
			case IDFACEDOWN3:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = IDANNFACE3_1X;
					m_nWorkingAnimationTop[0] = IDANNFACE3_1Y;
					m_nWorkingAnimationWidth[0] = IDANNFACE3_1W;
					m_nWorkingAnimationHeight[0] = IDANNFACE3_1H;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDANNFACE3_1);

					m_nWorkingAnimationLeft[1] = IDANNFACE3_1X;
					m_nWorkingAnimationTop[1] = IDANNFACE3_1Y;
					m_nWorkingAnimationWidth[1] = IDANNFACE3_1W;
					m_nWorkingAnimationHeight[1] = IDANNFACE3_1H;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(IDANNFACE3_2);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case IDFACEDOWN4:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = IDANNFACE4_1X;
					m_nWorkingAnimationTop[0] = IDANNFACE4_1Y;
					m_nWorkingAnimationWidth[0] = IDANNFACE4_1W;
					m_nWorkingAnimationHeight[0] = IDANNFACE4_1H;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDANNFACE4_1);

					m_nWorkingAnimationLeft[1] = IDANNFACE4_1X;
					m_nWorkingAnimationTop[1] = IDANNFACE4_1Y;
					m_nWorkingAnimationWidth[1] = IDANNFACE4_1W;
					m_nWorkingAnimationHeight[1] = IDANNFACE4_1H;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(IDANNFACE4_2);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case IDFACEDOWN5:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = IDANNFACE5_1X;
					m_nWorkingAnimationTop[0] = IDANNFACE5_1Y;
					m_nWorkingAnimationWidth[0] = IDANNFACE5_1W;
					m_nWorkingAnimationHeight[0] = IDANNFACE5_1H;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDANNFACE5_1);

					m_nWorkingAnimationLeft[1] = IDANNFACE5_1X;
					m_nWorkingAnimationTop[1] = IDANNFACE5_1Y;
					m_nWorkingAnimationWidth[1] = IDANNFACE5_1W;
					m_nWorkingAnimationHeight[1] = IDANNFACE5_1H;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(IDANNFACE5_2);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			default:
			{
				if (m_nWorkingWildCard > 0)
				{
					switch (m_nWorkingWildCard)
					{
						case 2:
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = IDB_WILD0_X;
								m_nWorkingAnimationTop[0] = IDB_WILD0_Y;
								m_nWorkingAnimationWidth[0] = IDB_WILD0_W;
								m_nWorkingAnimationHeight[0] = IDB_WILD0_H;
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD0);

								m_nWorkingAnimationLeft[1] = IDB_WILD0I_X - IDB_WILD0_W;
								m_nWorkingAnimationTop[1] = IDB_WILD0I_Y - IDB_WILD0_H;
								m_nWorkingAnimationWidth[1] = IDB_WILD0_W;
								m_nWorkingAnimationHeight[1] = IDB_WILD0_H;
								m_hWorkingAnimationBitmap[1] = CommonGetBitmapMirrored(m_hWorkingAnimationBitmap[0], 3);

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									break;
								case 2:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									m_nWorkingAnimationCount = 0;
									break;
							}
							break;
						case 1:
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = IDB_WILD1_X;
								m_nWorkingAnimationTop[0] = IDB_WILD1_Y;
								m_nWorkingAnimationWidth[0] = IDB_WILD1_W;
								m_nWorkingAnimationHeight[0] = IDB_WILD1_H;
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD1);

								m_nWorkingAnimationLeft[1] = IDB_WILD1I_X - IDB_WILD1_W;
								m_nWorkingAnimationTop[1] = IDB_WILD1I_Y - IDB_WILD1_H;
								m_nWorkingAnimationWidth[1] = IDB_WILD1_W;
								m_nWorkingAnimationHeight[1] = IDB_WILD1_H;
								m_hWorkingAnimationBitmap[1] = CommonGetBitmapMirrored(m_hWorkingAnimationBitmap[0], 3);

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									break;
								case 2:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									m_nWorkingAnimationCount = 0;
									break;
							}
							break;
						case 3:
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = IDB_WILD2_X;
								m_nWorkingAnimationTop[0] = IDB_WILD2_Y;
								m_nWorkingAnimationWidth[0] = IDB_WILD2_W;
								m_nWorkingAnimationHeight[0] = IDB_WILD2_H;
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD2);
								m_hWorkingAnimationBitmap[1] = NULL;

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = false;
									break;
								case 2:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = false;
									m_nWorkingAnimationCount = 0;
									break;
							}
							break;
						default:
							break;
					}
					if (m_nWorkingAnimationCount == 0)
					{
						if (m_nWorkingWildCard != m_nWildCard)
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationInitialized = false;
						}
					}
				}
				else
				{
					switch (m_nPlayingCard)
					{
						case IDJCLUBS:
						case IDQCLUBS:
						case IDKCLUBS:
						case IDJDIAMONDS:
						case IDQDIAMONDS:
						case IDKDIAMONDS:
						case IDJHEARTS:
						case IDQHEARTS:
						case IDKHEARTS:
						case IDJSPADES:
						case IDQSPADES:
						case IDKSPADES:
						case IDB_JOKER:
						case 53:
						{
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = 10;
								m_nWorkingAnimationTop[0] = 9;
								m_nWorkingAnimationWidth[0] = 32;
								m_nWorkingAnimationHeight[0] = 52;
								hBitmap1 = CommonGetBitmapResource(m_nPlayingCard);
								hBitmap2 = CommonGetBitmapClip(hBitmap1, 10, 9, 32, 52);
								::DeleteObject(hBitmap1);
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapMirrored(hBitmap2, 1);
								::DeleteObject(hBitmap2);
								m_hWorkingAnimationBitmap[1] = NULL;

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							if (m_nWorkingAnimationCount > 1)
							{
								m_nWorkingAnimationCount = 0;
							}
							bSwapBitmap[0] = true;
							bSwapBitmap[1] = false;
							break;
						}
						default:
							break;
					}
				}

				break;
			}
#else // WIN32_PLATFORM_PSPC
#if _WIN32_WCE > 211
			case IDFACEDOWN1:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 14;
					m_nWorkingAnimationTop[0] = 7;
					m_nWorkingAnimationWidth[0] = 10;
					m_nWorkingAnimationHeight[0] = 10;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(70);

					m_nWorkingAnimationLeft[1] = 14;
					m_nWorkingAnimationTop[1] = 7;
					m_nWorkingAnimationWidth[1] = 10;
					m_nWorkingAnimationHeight[1] = 10;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(69);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
#endif // _WIN32_WCE > 211
			case IDFACEDOWN2:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 9;
					m_nWorkingAnimationTop[0] = 1;
					m_nWorkingAnimationWidth[0] = 19;
					m_nWorkingAnimationHeight[0] = 17;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(71);

					m_nWorkingAnimationLeft[1] = 9;
					m_nWorkingAnimationTop[1] = 1;
					m_nWorkingAnimationWidth[1] = 19;
					m_nWorkingAnimationHeight[1] = 17;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(72);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case IDFACEDOWN3:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 1;
					m_nWorkingAnimationTop[0] = 17;
					m_nWorkingAnimationWidth[0] = 27;
					m_nWorkingAnimationHeight[0] = 7;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(73);

					m_nWorkingAnimationLeft[1] = 1;
					m_nWorkingAnimationTop[1] = 17;
					m_nWorkingAnimationWidth[1] = 27;
					m_nWorkingAnimationHeight[1] = 7;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(74);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case IDFACEDOWN4:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 14;
					m_nWorkingAnimationTop[0] = 16;
					m_nWorkingAnimationWidth[0] = 12;
					m_nWorkingAnimationHeight[0] = 10;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(75);

					m_nWorkingAnimationLeft[1] = 14;
					m_nWorkingAnimationTop[1] = 16;
					m_nWorkingAnimationWidth[1] = 12;
					m_nWorkingAnimationHeight[1] = 10;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(76);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case IDFACEDOWN6:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 2;
					m_nWorkingAnimationTop[0] = 2;
					m_nWorkingAnimationWidth[0] = 9;
					m_nWorkingAnimationHeight[0] = 5;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(77);
					m_hWorkingAnimationBitmap[1] = NULL;

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = true;
				bSwapBitmap[1] = false;
				break;
			}
			default:
			{
				if (m_nWorkingWildCard > 0)
				{
					if (!m_bWorkingAnimationInitialized)
					{
						m_nWorkingAnimationLeft[0] = IDB_WILD2_X;
						m_nWorkingAnimationTop[0] = IDB_WILD2_Y;
						m_nWorkingAnimationWidth[0] = IDB_WILD2_W;
						m_nWorkingAnimationHeight[0] = IDB_WILD2_H;
						m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD2);
						m_hWorkingAnimationBitmap[1] = NULL;

						m_bWorkingAnimationInvert = false;
						m_nWorkingAnimationRotate = 0;
						m_nWorkingAnimationMirror = 0;
						m_bWorkingAnimationInitialized = true;
					}
					switch (m_nWorkingAnimationCount)
					{
						case 1:
							bSwapBitmap[0] = true;
							bSwapBitmap[1] = false;
							break;
						case 2:
							bSwapBitmap[0] = true;
							bSwapBitmap[1] = false;
							m_nWorkingAnimationCount = 0;
							break;
					}
					if (m_nWorkingAnimationCount == 0)
					{
						if (m_nWorkingWildCard != m_nWildCard)
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationInitialized = false;
						}
					}
				}
				break;
			}
#endif
#else
			case 56:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 24;
					m_nWorkingAnimationTop[0] = 40;
					m_nWorkingAnimationWidth[0] = 24;
					m_nWorkingAnimationHeight[0] = 7;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(683);

					m_nWorkingAnimationLeft[1] = 24;
					m_nWorkingAnimationTop[1] = 40;
					m_nWorkingAnimationWidth[1] = 24;
					m_nWorkingAnimationHeight[1] = 7;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(684);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case 63:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 42;
					m_nWorkingAnimationTop[0] = 12;
					m_nWorkingAnimationWidth[0] = 26;
					m_nWorkingAnimationHeight[0] = 12;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(680);
					m_hWorkingAnimationBitmap[1] = NULL;

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = true;
				bSwapBitmap[1] = false;
				break;
			}
			case 64:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 47;
					m_nWorkingAnimationTop[0] = 1;
					m_nWorkingAnimationWidth[0] = 14;
					m_nWorkingAnimationHeight[0] = 12;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(681);

					m_nWorkingAnimationLeft[1] = 47;
					m_nWorkingAnimationTop[1] = 1;
					m_nWorkingAnimationWidth[1] = 14;
					m_nWorkingAnimationHeight[1] = 12;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(682);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			case 65:
			{
				if (!m_bWorkingAnimationInitialized)
				{
					m_nWorkingAnimationLeft[0] = 32;
					m_nWorkingAnimationTop[0] = 32;
					m_nWorkingAnimationWidth[0] = 32;
					m_nWorkingAnimationHeight[0] = 22;
					m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(678);

					m_nWorkingAnimationLeft[1] = 32;
					m_nWorkingAnimationTop[1] = 32;
					m_nWorkingAnimationWidth[1] = 32;
					m_nWorkingAnimationHeight[1] = 22;
					m_hWorkingAnimationBitmap[1] = CommonGetBitmapResource(679);

					m_bWorkingAnimationInvert = false;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = true;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = false;
						bSwapBitmap[1] = true;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = true;
						bSwapBitmap[1] = false;
						m_nWorkingAnimationCount = 0;
						break;
				}  
				break;
			}
			default:
			{
				if (m_nWorkingWildCard > 0)
				{
					switch (m_nWorkingWildCard)
					{
						case 2:
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = IDB_WILD0_X;
								m_nWorkingAnimationTop[0] = IDB_WILD0_Y;
								m_nWorkingAnimationWidth[0] = IDB_WILD0_W;
								m_nWorkingAnimationHeight[0] = IDB_WILD0_H;
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD0);

								m_nWorkingAnimationLeft[1] = IDB_WILD0I_X; // - IDB_WILD0_W;
								m_nWorkingAnimationTop[1] = IDB_WILD0I_Y; // - IDB_WILD0_H;
								m_nWorkingAnimationWidth[1] = IDB_WILD0_W;
								m_nWorkingAnimationHeight[1] = IDB_WILD0_H;
								m_hWorkingAnimationBitmap[1] = CommonGetBitmapMirrored(m_hWorkingAnimationBitmap[0], 3);

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									break;
								case 2:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									m_nWorkingAnimationCount = 0;
									break;
							}
							break;
						case 1:
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = IDB_WILD1_X;
								m_nWorkingAnimationTop[0] = IDB_WILD1_Y;
								m_nWorkingAnimationWidth[0] = IDB_WILD1_W;
								m_nWorkingAnimationHeight[0] = IDB_WILD1_H;
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD1);

								m_nWorkingAnimationLeft[1] = IDB_WILD1I_X; // - IDB_WILD1_W;
								m_nWorkingAnimationTop[1] = IDB_WILD1I_Y; // - IDB_WILD1_H;
								m_nWorkingAnimationWidth[1] = IDB_WILD1_W;
								m_nWorkingAnimationHeight[1] = IDB_WILD1_H;
								m_hWorkingAnimationBitmap[1] = CommonGetBitmapMirrored(m_hWorkingAnimationBitmap[0], 3);

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									break;
								case 2:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = true;
									m_nWorkingAnimationCount = 0;
									break;
							}
							break;
						case 3:
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = IDB_WILD2_X;
								m_nWorkingAnimationTop[0] = IDB_WILD2_Y;
								m_nWorkingAnimationWidth[0] = IDB_WILD2_W;
								m_nWorkingAnimationHeight[0] = IDB_WILD2_H;
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapResource(IDB_WILD2);
								m_hWorkingAnimationBitmap[1] = NULL;

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = false;
									break;
								case 2:
									bSwapBitmap[0] = true;
									bSwapBitmap[1] = false;
									m_nWorkingAnimationCount = 0;
									break;
							}
							break;
						default:
							break;
					}
					if (m_nWorkingAnimationCount == 0)
					{
						if (m_nWorkingWildCard != m_nWildCard)
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationInitialized = false;
						}
					}
				}
				else
				{
					switch (m_nPlayingCard)
					{
						case IDJCLUBS:
						case IDQCLUBS:
						case IDKCLUBS:
						case IDJDIAMONDS:
						case IDQDIAMONDS:
						case IDKDIAMONDS:
						case IDJHEARTS:
						case IDQHEARTS:
						case IDKHEARTS:
						case IDJSPADES:
						case IDQSPADES:
						case IDKSPADES:
						case IDB_JOKER:
						{
							if (!m_bWorkingAnimationInitialized)
							{
								m_nWorkingAnimationLeft[0] = 13;
								m_nWorkingAnimationTop[0] = 12;
								m_nWorkingAnimationWidth[0] = 45;
								m_nWorkingAnimationHeight[0] = 72;
								hBitmap1 = CommonGetBitmapResource(m_nPlayingCard);
								hBitmap2 = CommonGetBitmapClip(hBitmap1, 13, 12, 45, 72);
								::DeleteObject(hBitmap1);
								m_hWorkingAnimationBitmap[0] = CommonGetBitmapMirrored(hBitmap2, 1);
								::DeleteObject(hBitmap2);
								m_hWorkingAnimationBitmap[1] = NULL;

								m_bWorkingAnimationInvert = false;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = true;
							}
							if (m_nWorkingAnimationCount > 1)
							{
								m_nWorkingAnimationCount = 0;
							}
							bSwapBitmap[0] = true;
							bSwapBitmap[1] = false;
							break;
						}
						default:
							break;
					}
				}
				break;
			}
#endif
		}

		AnimateCheckRotate();
		AnimateCheckMirror();
		AnimateCheckInvert();

		if (bSwapBitmap[0] || bSwapBitmap[1])
		{
			HDC dcDest = ::CreateCompatibleDC(NULL);
			HBITMAP cOldDestBitmap = (HBITMAP)::SelectObject(dcDest, hBitmap);

			HDC dcSource = ::CreateCompatibleDC(NULL);

			for (int i = 0; i < 2; i++)
			{
				if (bSwapBitmap[i])
				{
					
					HBITMAP cOldSourceBitmap = (HBITMAP)::SelectObject(dcSource, m_hWorkingAnimationBitmap[i]);
				
					nLeft = m_nWorkingAnimationLeft[i];
					nTop = m_nWorkingAnimationTop[i];
					nWidth = m_nWorkingAnimationWidth[i];
					nHeight = m_nWorkingAnimationHeight[i];

					::BitBlt(dcDest, nLeft, nTop, nWidth, nHeight, dcSource, 0, 0, SRCINVERT);
					::BitBlt(dcSource, 0,0, nWidth, nHeight, dcDest, nLeft, nTop, SRCINVERT);
					::BitBlt(dcDest, nLeft, nTop, nWidth, nHeight, dcSource, 0, 0, SRCINVERT);

					::SelectObject(dcSource, cOldSourceBitmap);
				}
			}

			::DeleteDC(dcSource);

			::SelectObject(dcDest, cOldDestBitmap);				
			::DeleteDC(dcDest);
			
			if (bInvalidateControl)
			{
				InvalidateControl(NULL);
			}
		}
	}
}

HBITMAP CS309PictureBox::CommonGetBitmapResource(int nResource)
{
	HBITMAP hBitmap = NULL;
	HBITMAP hLoadedBitmap = NULL;
	HINSTANCE hInst = NULL;


	if ((nResource >= IDACLUBS) && (nResource <= IDKSPADES))
	{
		hInst = m_hPegCards;
	}
#ifdef UNDER_CE 
	if ((nResource >= IDFACEDOWNFIRST) && (nResource <= IDFACEDOWNLAST))
	{
		hInst = m_hPegCards;
	}
	if ((nResource >= 69) && (nResource <= 70))
	{
		hInst = m_hPegCards;
	}
	if ((nResource >= IDANNFACE2_1) && (nResource <= IDANNFACE5_2))
	{
		hInst = m_hPegCards;
	}
	if ((nResource >= IDCARDO) && (nResource <= IDCARDGHOST))
	{
		hInst = m_hPegCards;
	}
	if ((nResource >= IDB_JOKER) && (nResource <= IDB_SUIT4))
	{
		hInst = m_hInstMe;
	}
	if ((nResource >= (IDB_JOKER - 100)) && (nResource <= (IDB_SUIT4 - 100)))
	{
		nResource += 100;
		hInst = m_hInstMe;
	}
	if ((nResource >= IDB_WILD0) && (nResource <= IDB_WILD2))
	{
		hInst = m_hInstMe;
	}
	if (nResource >= IDB_ROCKET) 
	{
		hInst = m_hInstMe;
	}
#else
	if ((nResource >= 53) && (nResource <= 65))
	{
		hInst = m_hPegCards;
	}
	if ((nResource >= 67) && (nResource <= 68))
	{
		hInst = m_hPegCards;
	}
	if ((nResource >= IDB_WILD0) && (nResource <= IDB_WILD2))
	{
		hInst = m_hInstMe;
	}
	if ((nResource >= IDB_JOKER) && (nResource <= IDB_SUIT4))
	{
		hInst = m_hInstMe;
	}
	if ((nResource >= 678) && (nResource <= 684))
	{
		hInst = m_hPegCards;
	}
#endif

	if (hInst != NULL)
	{
		hLoadedBitmap = (HBITMAP)LoadImage(hInst,MAKEINTRESOURCE(nResource), IMAGE_BITMAP, 0, 0, 0);
	}

	hBitmap = CommonGetBitmapCopy(hLoadedBitmap);
	::DeleteObject(hLoadedBitmap);

	return hBitmap;

}
void CS309PictureBox::CommonGetCardsInstance()
{
#ifdef UNDER_CE
	m_hPegCards = LoadLibrary(_T("pegcards.dll"));
	if (m_hPegCards == NULL)
	{
		m_hPegCards = LoadLibrary(_T("\\windows\\pegcards.dll"));
	} 
#else
	m_hPegCards = LoadLibrary(TEXT("Cards.dll"));
	if (m_hPegCards == NULL)
	{
		m_hPegCards = LoadLibrary(_T("Cards32.dll"));
	} 
	if (m_hPegCards == NULL)
	{
		AfxMessageBox(_T("m_hPegCards is NULL"), MB_ICONERROR + MB_OK, 0);
	}
#endif
}

short CS309PictureBox::GetWildCard() 
{
	return m_nWildCard;
}

void CS309PictureBox::SetWildCard(short nNewValue) 
{
	if ((nNewValue < 0) && (nNewValue > 3))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nWildCard = nNewValue;
		CommonGetCardsInstance();
	}
	SetModifiedFlag();
}

void CS309PictureBox::OnKillFocus(CWnd* pNewWnd) 
{
	COleControl::OnKillFocus(pNewWnd);
	m_bHaveFocus = false;
	if (m_bFocusRect)
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
		
	FireLostFocus();
}

void CS309PictureBox::OnSetFocus(CWnd* pOldWnd) 
{
	COleControl::OnSetFocus(pOldWnd);
	m_bHaveFocus = true;
	if (m_bFocusRect)
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
	FireGotFocus();
}

void CS309PictureBox::AnimateCheckRotate()
{
	HBITMAP hBitmap;
	int nOffset = 0;
	int nTop, nLeft, nWidth, nHeight;
	
	for (int i = 0; i< 2; i++)
	{
		if (m_nWorkingAnimationRotate != m_nWorkingRotate)
		{
			nOffset = m_nWorkingRotate - m_nWorkingAnimationRotate;
			if (nOffset < 0)
				nOffset = nOffset + 360;
			if (nOffset > 359)
				nOffset = nOffset - 360;
			if (m_hWorkingAnimationBitmap[i] != NULL)
			{
				hBitmap = CommonGetBitmapRotated(m_hWorkingAnimationBitmap[i], nOffset);
				::DeleteObject(m_hWorkingAnimationBitmap[i]);
				m_hWorkingAnimationBitmap[i] = hBitmap;

				nTop = m_nWorkingAnimationTop[i];
				nLeft = m_nWorkingAnimationLeft[i];
				nWidth = m_nWorkingAnimationWidth[i];
				nHeight = m_nWorkingAnimationHeight[i];
				switch (nOffset)
				{
					case 90:
						m_nWorkingAnimationTop[i] = nLeft;
						m_nWorkingAnimationLeft[i] = IDB_CARD_HEIGHT - (nTop + nHeight);
						m_nWorkingAnimationWidth[i] = nHeight;
						m_nWorkingAnimationHeight[i] = nWidth;
						break;
					case 180:
						m_nWorkingAnimationTop[i] = IDB_CARD_HEIGHT - (nTop + nHeight);
						m_nWorkingAnimationLeft[i] = IDB_CARD_WIDTH - (nLeft + nWidth);
						m_nWorkingAnimationWidth[i] = nWidth;
						m_nWorkingAnimationHeight[i] = nHeight;
						break;
					case 270:
						m_nWorkingAnimationTop[i] = IDB_CARD_WIDTH - (nLeft + nWidth);
						m_nWorkingAnimationLeft[i] = nTop;
						m_nWorkingAnimationWidth[i] = nHeight;
						m_nWorkingAnimationHeight[i] = nWidth;
						break;
					default:
						break;
				}
			}
		}
	}
	m_nWorkingAnimationRotate = m_nWorkingAnimationRotate + nOffset;
}


void CS309PictureBox::MethodSetFocus() 
{
	SetFocus();
}

void CS309PictureBox::AnimateCheckMirror()
{
	HBITMAP hBitmap;
	int nOffset = 0;
	int nTop, nLeft, nWidth, nHeight;

	if (m_nWorkingAnimationMirror != m_nWorkingMirror)
	{
		nOffset = (m_nWorkingMirror ^ m_nWorkingAnimationMirror);
//	TCHAR msg[100];
//		swprintf(msg, _T("%d %d %d\0"),nOffset,m_nWorkingMirror,m_nWorkingAnimationMirror);
//		MessageBox(msg,m_strName,MB_OK);
		for (int i = 0; i< 2; i++)
		{
			if (m_hWorkingAnimationBitmap[i] != NULL)
			{
				hBitmap = CommonGetBitmapMirrored(m_hWorkingAnimationBitmap[i], nOffset);
				::DeleteObject(m_hWorkingAnimationBitmap[i]);
				m_hWorkingAnimationBitmap[i] = hBitmap;

				nTop = m_nWorkingAnimationTop[i];
				nLeft = m_nWorkingAnimationLeft[i];
				nWidth = m_nWorkingAnimationWidth[i];
				nHeight = m_nWorkingAnimationHeight[i];
				switch (nOffset)
				{
					case 1:
						m_nWorkingAnimationTop[i] = nTop;
						m_nWorkingAnimationLeft[i] = IDB_CARD_WIDTH - (nLeft + nWidth);
						m_nWorkingAnimationWidth[i] = nWidth;
						m_nWorkingAnimationHeight[i] = nHeight;
						break;
					case 2:
						m_nWorkingAnimationTop[i] = IDB_CARD_HEIGHT - (nTop + nHeight);
						m_nWorkingAnimationLeft[i] = nLeft;
						m_nWorkingAnimationWidth[i] = nWidth;
						m_nWorkingAnimationHeight[i] = nHeight;
						break;
					case 3:
						m_nWorkingAnimationTop[i] = IDB_CARD_HEIGHT - (nTop + nHeight);
						m_nWorkingAnimationLeft[i] = IDB_CARD_WIDTH - (nLeft + nWidth);
						m_nWorkingAnimationWidth[i] = nWidth;
						m_nWorkingAnimationHeight[i] = nHeight;
						break;
					default:
						break;
				}
			}
		}
	}
	m_nWorkingAnimationMirror = m_nWorkingMirror;
}


BOOL CS309PictureBox::GetImageLoaded() 
{
	return (m_hBitmap != NULL);
}

BSTR CS309PictureBox::GetName() 
{
//	CString strResult;

//	strResult = m_strName;

	return m_strName.AllocSysString();
}

VARIANT CS309PictureBox::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309PictureBox::SetTag(const VARIANT FAR& newValue) 
{
	if (!AmbientUserMode())
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGSETNOTVALID, 0);
	}
	else
	{
		COleVariant Var = COleVariant(newValue);
		m_vTag.Clear();
		m_vTag.Attach(Var);

		SetModifiedFlag();
	}
}

BOOL CS309PictureBox::GetInvert() 
{
	return m_bInvert;
}

void CS309PictureBox::SetInvert(BOOL bNewValue) 
{
	m_bInvert = bNewValue;
	SetModifiedFlag();
}

void CS309PictureBox::MethodInvertImage() 
{
	m_hBitmap = CommonInvert(m_hBitmap);
	InvalidateControl(NULL);
}

void CS309PictureBox::AnimateCheckInvert()
{
	HBITMAP hNewBitmap;
	if (m_bWorkingAnimationInvert != m_bWorkingInvert)
	{
		for (int i = 0; i< 2; i++)
		{
			if (m_hWorkingAnimationBitmap[i] != NULL)
			{
				hNewBitmap = CommonGetBitmapInverted(m_hWorkingAnimationBitmap[i]);
				::DeleteObject(m_hWorkingAnimationBitmap[i]);
				m_hWorkingAnimationBitmap[i] = hNewBitmap;
			}
		}
	}
	m_bWorkingAnimationInvert = m_bWorkingInvert;
}

BOOL CS309PictureBox::CommonLoadImageIntoBitmap()
{
	BOOL bAutoSize = false;
	HBITMAP hLoadBitmap = NULL;
	HBITMAP hNewBitmap = NULL;
	BITMAP Bitmap;

	if ((m_strPicture.GetLength() > 0) || (m_nResourceID >= 0) || (m_hWorkingIconBitmap != NULL) || (m_hWorkingBitmap != NULL) || (m_bWorkingCaptureScreen)) 
	{
		m_bAnimationAvailable = false;

		m_nWorkingAnimationInterval = 0;
		CommonSetNewTimer();

		m_bWorkingAnimationAvailable = false;
		m_bWorkingAnimationInitialized = false;
		m_bWorkingAnimationInvert = false;
		m_nWorkingAnimationMirror = 0;
		m_nWorkingAnimationRotate = 0;
		m_nWorkingWildCard = 0;

/*		m_dteDate = m_dteDate.GetCurrentTime();

		if (m_dteDate > m_dteExpire)
		{
			if (m_bDisplayExpired)
			{
				AfxMessageBox(_T("The S309.PictureBox Control has expired.\nGoto http://members.xoom.com/S309"), MB_ICONERROR + MB_OK, 0);
				m_bDisplayExpired = false;
			}
		}
		else
*/		{
			bool bCopied = false;

			CommonLoadImage(&hLoadBitmap, &bCopied);

			if (hLoadBitmap == NULL)
			{
				if (!m_bOverlay)
				{
					if (m_hBitmap != NULL)
					{
						::DeleteObject(m_hBitmap);
						m_hBitmap = NULL;
					}
				}
			}
			else
			{
				if (m_bWorkingClip)
				{
					hNewBitmap = CommonGetBitmapClip(hLoadBitmap, m_nWorkingClipLeft, m_nWorkingClipTop, m_nWorkingClipWidth, m_nWorkingClipHeight);
					::DeleteObject(hLoadBitmap);
					hLoadBitmap = hNewBitmap;
					
					m_bWorkingClip = false;
					m_nWorkingClipHeight = 0;
					m_nWorkingClipLeft = 0;
					m_nWorkingClipTop = 0;
					m_nWorkingClipWidth = 0;

					bCopied = true;
				}
				if (m_bClip)
				{
					hLoadBitmap = CommonClip(hLoadBitmap);
					bCopied = true;
				}

				if (m_bScroll)
				{
					hLoadBitmap = CommonScroll(hLoadBitmap);
					bCopied = true;
				}

				if (m_bResize)
				{
					hLoadBitmap = CommonResize(hLoadBitmap);
					bCopied = true;
				}

				if (!bCopied)
				{
					hNewBitmap = CommonGetBitmapCopy(hLoadBitmap);
					::DeleteObject(hLoadBitmap);
					hLoadBitmap = hNewBitmap;
				}

				m_bWorkingInvert = false;
				m_nWorkingRotate = 0;
				m_nWorkingMirror = 0;

				hLoadBitmap = CommonRotate(hLoadBitmap);

				hLoadBitmap = CommonMirror(hLoadBitmap);

				if (m_bInvert)
				{
					hLoadBitmap = CommonInvert(hLoadBitmap);
				}

				if (m_bOverlay)
				{

					if (m_hBitmap == NULL)
					{
						m_hBitmap = CommonGetBitmapControlSize();
					}

					Bitmap.bmWidth = 0;
					Bitmap.bmHeight = 0;
					::GetObject(hLoadBitmap, sizeof(Bitmap), &Bitmap);

					hNewBitmap = CommonGetBitmapOverlay(m_hBitmap, hLoadBitmap, m_nOverlayLeft, m_nOverlayTop, Bitmap.bmWidth, Bitmap.bmHeight, m_ocOverlayTransparentColor);

					if (m_hBitmap != NULL)
					{
						::DeleteObject(m_hBitmap);
						m_hBitmap = NULL;
					}

					if (hLoadBitmap != NULL)
					{
						::DeleteObject(hLoadBitmap);
						hLoadBitmap = NULL;
					}

					m_hBitmap = hNewBitmap;
//					m_nWorkingScrollBars = -1;
				}
				else
				{
					if (m_hBitmap != NULL)
					{
						::DeleteObject(m_hBitmap);
						m_hBitmap = NULL;
					}

					m_hBitmap = hLoadBitmap;
					m_nDrawTextCurrentY = 0;
//					m_nWorkingScrollBars = -1;
					m_nVScrollPosition = 0;
					m_nHScrollPosition = 0;
				}

				m_nWorkingAnimationCount = 0;

#ifndef UNDER_CE
						if (((m_nPlayingCard > 62) && (m_nPlayingCard < 66)) || (m_nPlayingCard == 56))
						{
							m_bWorkingAnimationAvailable = true;
						}

						if ((m_nWildCard > 0) && (!m_bWorkingAnimationAvailable))
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationAvailable = true;
							AnimatePlayingCard(false, m_hBitmap);
						}

						if (!m_bWorkingAnimationAvailable)
						{
							switch (m_nPlayingCard)
							{
								case IDJCLUBS:
								case IDQCLUBS:
								case IDKCLUBS:
								case IDJDIAMONDS:
								case IDQDIAMONDS:
								case IDKDIAMONDS:
								case IDJHEARTS:
								case IDQHEARTS:
								case IDKHEARTS:
								case IDJSPADES:
								case IDQSPADES:
								case IDKSPADES:
								case IDB_JOKER:
									m_bWorkingAnimationAvailable = true;
									break;
								default:
									break;
							}
						}
						if (m_bWorkingAnimationAvailable)
						{
							m_nWorkingAnimationPlatform = 3;
						}
#else // UNDER_CE
#ifndef WIN32_PLATFORM_PSPC
#if WIN32_PLATFORM_HPCPRO
						if ((m_nPlayingCard >= IDFACEDOWNFIRST) && (m_nPlayingCard < IDFACEDOWNLAST))
#else // WIN32_PLATFORM_HPCPRO
						if ((m_nPlayingCard > IDFACEDOWNFIRST) && (m_nPlayingCard < IDFACEDOWNLAST))
#endif // WIN32_PLATFORM_HPCPRO
						{
							m_bWorkingAnimationAvailable = true;
						}

						if ((m_nWildCard > 0) && (!m_bWorkingAnimationAvailable))
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationAvailable = true;
							AnimatePlayingCard(false, m_hBitmap);
						}

						if (!m_bWorkingAnimationAvailable)
						{
							switch (m_nPlayingCard)
							{
								case IDJCLUBS:
								case IDQCLUBS:
								case IDKCLUBS:
								case IDJDIAMONDS:
								case IDQDIAMONDS:
								case IDKDIAMONDS:
								case IDJHEARTS:
								case IDQHEARTS:
								case IDKHEARTS:
								case IDJSPADES:
								case IDQSPADES:
								case IDKSPADES:
								case IDB_JOKER:
									m_bWorkingAnimationAvailable = true;
									break;
								default:
									break;
							}
						}
						if (m_bWorkingAnimationAvailable)
						{
							m_nWorkingAnimationPlatform = 1;
						}
#else //  WIN32_PLATFORM_PSPC
#if _WIN32_WCE > 211
						if (((m_nPlayingCard >= 61) && (m_nPlayingCard < 65)) || (m_nPlayingCard == 66))
#else // _WIN32_WCE > 211
						if (((m_nPlayingCard > 61) && (m_nPlayingCard < 65)) || (m_nPlayingCard == 66))
#endif // _WIN32_WCE > 211
						{
							m_bWorkingAnimationAvailable = true;
							m_nWorkingAnimationPlatform = 2;
						}

						if ((m_nWildCard > 0) && (!m_bWorkingAnimationAvailable))
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationAvailable = true;
							AnimatePlayingCard(false, m_hBitmap);
						}
#endif //  WIN32_PLATFORM_PSPC
#endif // UNDER_CE

				m_bAnimationAvailable = m_bWorkingAnimationAvailable;
				m_nWorkingAnimationInterval = m_nAnimationInterval;

				bAutoSize = CommonCheckAutoSize(false);
			}
		}
	}
	return bAutoSize;
}

BOOL CS309PictureBox::CommonCheckAutoSize(BOOL bForce)
{
	CRect cRect;
	BITMAP Bitmap;
	BOOL bChangedSize = false;
	int nBorder = 0;
	int nVBCE = 0;
//	int nWidth, nHeight;

	if ((!m_bAutoRefresh) && (!bForce))
	{
		return true;
	}

	if ((m_bAutoSize) && (m_hBitmap != NULL))
	{

		if (::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap))
		{
//			GetControlSize(&nWidth, &nHeight);
			if (GetRectInContainer(cRect))
			{		
				if (m_nBorderStyle != 0)
				{
					switch (m_nAppearance)
					{
						case -4:
							nBorder = 10;
							break;
						case 3:
							nBorder = 6;
							break;
						case 0:
						case 4:
							nBorder = 2;
							break;
						default:
							nBorder = 4;
							break;
					}
//					nBorder = 2;
//					if (m_nAppearance != 0)
//					{
//						nBorder = nBorder + 2;
//					}
				}

#ifdef UNDER_CE
				if (m_bVBCE)
				{
					nVBCE = 6;
				}
#endif
				
				m_nAutoSizeWidth = Bitmap.bmWidth  + nBorder;
				m_nAutoSizeHeight = Bitmap.bmHeight + nBorder;
				if (cRect.Width() != ((Bitmap.bmWidth  + nBorder) - nVBCE))
//				if (nWidth != (Bitmap.bmWidth  + nBorder))
				{
	 				cRect.right = (cRect.left + Bitmap.bmWidth + nBorder) - nVBCE;
//	 				nWidth = Bitmap.bmWidth + nBorder;
					bChangedSize = true;
				}
				if (cRect.Height() != ((Bitmap.bmHeight + nBorder) - nVBCE))
//				if (nHeight != (Bitmap.bmHeight + nBorder))
				{
					cRect.bottom = (cRect.top + Bitmap.bmHeight + nBorder) - nVBCE;
//					nHeight = Bitmap.bmHeight + nBorder;
					bChangedSize = true;
				}
				if (bChangedSize) 
				{
					SetRectInContainer(cRect);
//						MessageBox(_T("SetRectInContainer"),_T(""),0);
//					if (!SetRectInContainer(cRect))
//					if (!SetControlSize(nWidth, nHeight))
						InvalidateControl(NULL);
//					else
//						MessageBox(_T("SetRectInContainer Error"),_T(""),0);
//					m_bFirstTimeAutoSize = true;
					if (m_bVBCE)
					{
//						SetWindowPos( 0, 0, 0, cRect.Width(), cRect.Height(), SWP_NOMOVE  + SWP_NOZORDER);
//						SetControlSize(cRect.Width(), cRect.Height());
//						AdjustWindowRectEx(cRect,0,false,0);
					}
				}
			}
		}

	}
//	else
//	{
//		if (!m_bFirstTimeAutoSize)
//		{
//			MessageBox(_T("FTAS"),_T(""),0);
//			if (GetRectInContainer(cRect))
//			{			
//				SetRectInContainer(cRect);
//			}
//			m_bFirstTimeAutoSize = true;
//		}
//	}
// SystemParametersInfo
	return bChangedSize;
}

long CS309PictureBox::GetClipTop() 
{
	return m_nClipTop;
}

void CS309PictureBox::SetClipTop(long nNewValue) 
{
	m_nClipTop = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetClipLeft() 
{
	return m_nClipLeft;
}

void CS309PictureBox::SetClipLeft(long nNewValue) 
{
	m_nClipLeft = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetClipHeight() 
{
	return m_nClipHeight;
}

void CS309PictureBox::SetClipHeight(long nNewValue) 
{
	m_nClipHeight = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetClipWidth() 
{
	return m_nClipWidth;
}

void CS309PictureBox::SetClipWidth(long nNewValue) 
{
	m_nClipWidth = nNewValue;
	SetModifiedFlag();
}

void CS309PictureBox::MethodClipImage() 
{
	m_hBitmap = CommonClip(m_hBitmap);
	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

BOOL CS309PictureBox::GetClip() 
{
	return m_bClip;
}

void CS309PictureBox::SetClip(BOOL bNewValue) 
{
	m_bClip = bNewValue;
	SetModifiedFlag();
}

short CS309PictureBox::GetBorderStyle() 
{
	return m_nBorderStyle;
}

void CS309PictureBox::SetBorderStyle(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 1))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nBorderStyle = nNewValue;
		SetModifiedFlag();
		CommonDesignRefresh();
	}
}

BOOL CS309PictureBox::GetResize() 
{
	return m_bResize;
}

void CS309PictureBox::SetResize(BOOL bNewValue) 
{
	m_bResize = bNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetResizeHeight() 
{
	return m_nResizeHeight;
}

void CS309PictureBox::SetResizeHeight(long nNewValue) 
{
	if (nNewValue < 0)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nResizeHeight = nNewValue;
	}
	SetModifiedFlag();
}

long CS309PictureBox::GetResizeWidth() 
{
	return m_nResizeWidth;
}

void CS309PictureBox::SetResizeWidth(long nNewValue) 
{
	if (nNewValue < 0)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nResizeWidth = nNewValue;
	}
	SetModifiedFlag();
}

void CS309PictureBox::MethodResizeImage() 
{
	m_hBitmap = CommonResize(m_hBitmap);
	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

HBITMAP CS309PictureBox::CommonRotate(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = hBitmap;
	if ((m_nRotate > 0) && (hBitmap != NULL))
	{
		hReturnBitmap = CommonGetBitmapRotated(hBitmap, m_nRotate);
		if (hReturnBitmap == NULL)
		{
			hReturnBitmap = hBitmap;
		}
		else
		{
			::DeleteObject(hBitmap);
			m_nWorkingRotate = m_nWorkingRotate + m_nRotate;
			if (m_nWorkingRotate > 359)
			{
				m_nWorkingRotate = m_nWorkingRotate - 360;
			}
		}
	}
	return hReturnBitmap;
}

HBITMAP CS309PictureBox::CommonMirror(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = hBitmap;
	if ((m_nMirror > 0) && (hBitmap != NULL))
	{
		hReturnBitmap = CommonGetBitmapMirrored(hBitmap, m_nMirror);
		::DeleteObject(hBitmap);
		m_nWorkingMirror = m_nWorkingMirror ^ m_nMirror;
	}
	return hReturnBitmap;
}

HBITMAP CS309PictureBox::CommonInvert(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = NULL;
	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapInverted(hBitmap);
		::DeleteObject(hBitmap);
		m_bWorkingInvert = !m_bWorkingInvert;
	}
	return hReturnBitmap;
}

HBITMAP CS309PictureBox::CommonClip(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = NULL;

	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapClip(hBitmap, m_nClipLeft, m_nClipTop, m_nClipWidth, m_nClipHeight);
		::DeleteObject(hBitmap);
	}
	return hReturnBitmap;
}

HBITMAP CS309PictureBox::CommonResize(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = NULL;

	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapResize(hBitmap, m_nResizeWidth, m_nResizeHeight);
		::DeleteObject(hBitmap);
	}
	return hReturnBitmap;
}

BOOL CS309PictureBox::GetResourceFileLoaded() 
{
	return (m_hResourceFile != NULL);
}

HBITMAP CS309PictureBox::CommonGetBitmapMirrored(HBITMAP hBitmap, short nMirror)
{
	BITMAP bm;
	if (m_bWaitCursor)
	{
		BeginWaitCursor();
	}

	HDC sourceDC = ::CreateCompatibleDC(NULL);
	HDC destDC = ::CreateCompatibleDC(NULL);

	::GetObject( hBitmap, sizeof( bm ), &bm );

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC, bm.bmWidth, bm.bmHeight);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);	

	switch (nMirror)
	{
		case 1:
#ifdef UNDER_CE
			::StretchBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, bm.bmWidth, 0, -bm.bmWidth, bm.bmHeight, SRCCOPY );
#else
			::StretchBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, bm.bmWidth-1, 0, -bm.bmWidth, bm.bmHeight, SRCCOPY );
#endif
			break;
		case 2:
#ifdef UNDER_CE
			::StretchBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, bm.bmHeight, bm.bmWidth, -bm.bmHeight, SRCCOPY);
#else
			::StretchBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, bm.bmHeight-1, bm.bmWidth, -bm.bmHeight, SRCCOPY);
#endif
			break;
		case 3:
#ifdef UNDER_CE
			::StretchBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, bm.bmWidth, bm.bmHeight, -bm.bmWidth, -bm.bmHeight, SRCCOPY);
#else
			::StretchBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, bm.bmWidth-1, bm.bmHeight-1, -bm.bmWidth, -bm.bmHeight, SRCCOPY);
#endif
			break;
		default:
			break;
	}
//
	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

//#if _WIN32_WCE == 200
	if (m_bWaitCursor)
	{
		EndWaitCursor();
//		SetCursor(hCursor);
	}
//#endif

	return hbmResult;
}

HBITMAP CS309PictureBox::CommonGetBitmapRotated(HBITMAP hBitmap, int degrees)
{
	CDC *sourceDC, *destDC;
	BITMAP bm;
	BITMAPINFOHEADER bmih1, bmih2;
	LPVOID pBits1, pBits2;
	HBITMAP dsBitmap1, dsBitmap2;
	HBITMAP hbmOldSource, hbmOldDest;
	int destx, desty, sourcex, sourcey;

	if (degrees == 180)
	{
		HBITMAP hRetBitmap;
		hRetBitmap = CommonGetBitmapMirrored(hBitmap, 3);
		return hRetBitmap;
	}

	if (m_bWaitCursor)
	{
		BeginWaitCursor();
	}

	sourceDC = new CDC;
	sourceDC->CreateCompatibleDC( NULL );
	destDC = new CDC;
	destDC->CreateCompatibleDC( NULL );
	::GetObject( hBitmap, sizeof( bm ), &bm );

	bmih1.biSize = sizeof(BITMAPINFOHEADER);
	bmih1.biWidth = bm.bmWidth;
	bmih1.biHeight = bm.bmHeight;
	bmih1.biPlanes = 1;
	bmih1.biBitCount = 24;
	bmih1.biCompression = BI_RGB;
	bmih1.biSizeImage = 0;
	bmih1.biXPelsPerMeter = 0;
	bmih1.biYPelsPerMeter = 0;
	bmih1.biClrUsed = 0;
	bmih1.biClrImportant = 0;

	dsBitmap1 = CreateDIBSection(NULL, (BITMAPINFO *) &bmih1, 0, &pBits1, NULL, 0);
	if (dsBitmap1 == NULL)
	{
		TCHAR szMessage[MAX_PATH] = TEXT("Error on rotate (1): Out Of Memory");
		long nLastError = ::GetLastError();
		if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
		{
			wsprintf(szMessage, TEXT("Error on rotate (1): GetLastError() = %d"), nLastError);
		}
		AfxMessageBox(szMessage, MB_ICONWARNING, 0);
		delete sourceDC;
		delete destDC;
		
		if (m_bWaitCursor)
		{
			EndWaitCursor();
		}

		return NULL;
	}

	hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), hBitmap );
	hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), dsBitmap1 );

	destDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource );
	delete sourceDC;
	::SelectObject(destDC->GetSafeHdc(), hbmOldDest);
	delete destDC;

	bmih2.biSize = sizeof(BITMAPINFOHEADER);
	bmih2.biWidth = bm.bmHeight;
	bmih2.biHeight = bm.bmWidth;
	bmih2.biPlanes = 1;
	bmih2.biBitCount = 24;
	bmih2.biCompression = BI_RGB;
	bmih2.biSizeImage = 0;
	bmih2.biXPelsPerMeter = 0;
	bmih2.biYPelsPerMeter = 0;
	bmih2.biClrUsed = 0;
	bmih2.biClrImportant = 0;

	dsBitmap2 = CreateDIBSection(NULL, (BITMAPINFO *) &bmih2, 0, &pBits2, NULL, 0);
	if (dsBitmap2 == NULL)
	{
		TCHAR szMessage[MAX_PATH] = TEXT("Error on rotate (2): Out Of Memory");
		long nLastError = ::GetLastError();
		if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
		{
			wsprintf(szMessage, TEXT("Error on rotate (2): GetLastError() = %d"), nLastError);
		}
		AfxMessageBox(szMessage, MB_ICONWARNING, 0);
		::DeleteObject(dsBitmap1);
		
		if (m_bWaitCursor)
		{
			EndWaitCursor();
		}

		return NULL;
	}

	int nSourceRowBytes = (((bmih1.biWidth * 3) + 3) / 4) * 4;
	int nDestRowBytes = (((bmih2.biWidth * 3) + 3) / 4) * 4;

	unsigned char *source;
	unsigned char *dest;

	switch (degrees)
	{
		case 90:
			destx = -1;
			for( sourcey = bm.bmHeight - 1; sourcey >= 0; sourcey-- )
			{
				destx++;
				desty = -1;
				for( sourcex = 0; sourcex < bm.bmWidth; sourcex++)
				{
					desty++;
					source = (unsigned char *)pBits1 + (nSourceRowBytes * ((bmih1.biHeight - 1) - sourcey)) + (sourcex * 3);
					dest = (unsigned char *)pBits2 + (nDestRowBytes * ((bmih2.biHeight - 1) - desty)) + (destx * 3);
					dest[0] = source[0];
					dest[1] = source[1];
					dest[2] = source[2];
				}
			}
			break;
		case 270:
			destx = -1;
			for( sourcey = 0; sourcey < bm.bmHeight; sourcey++ )
			{
				destx++;
				desty = -1;
				for( sourcex = bm.bmWidth - 1; sourcex >= 0; sourcex-- )
				{
					desty++;
					source = (unsigned char *)pBits1 + (nSourceRowBytes * ((bmih1.biHeight - 1) - sourcey)) + (sourcex * 3);
					dest = (unsigned char *)pBits2 + (nDestRowBytes * ((bmih2.biHeight - 1) - desty)) + (destx * 3);
					dest[0] = source[0];
					dest[1] = source[1];
					dest[2] = source[2];
				}
			}
			break;
	}

	::DeleteObject(dsBitmap1);

	sourceDC = new CDC;
	sourceDC->CreateCompatibleDC(NULL);
	destDC = new CDC;
	destDC->CreateCompatibleDC(NULL);

	hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), hBitmap );
	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC->GetSafeHdc(), bm.bmHeight, bm.bmWidth);
	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource);
	if (hbmResult == NULL)
	{
		TCHAR szMessage[MAX_PATH] = TEXT("Error on rotate (3): Out Of Memory");
		long nLastError = ::GetLastError();
		if (nLastError != ERROR_NOT_ENOUGH_MEMORY)
		{
			wsprintf(szMessage, TEXT("Error on rotate (3): GetLastError() = %d"), nLastError);
		}
		AfxMessageBox(szMessage, MB_ICONWARNING, 0);

		::DeleteObject(dsBitmap2);
		delete sourceDC;
		delete destDC;
		
		if (m_bWaitCursor)
		{
			EndWaitCursor();
		}

		return NULL;
	}


//	BITMAP hbmResult = ::CreateCompatibleBitmap(CClientDC(NULL), bm.bmHeight, bm.bmWidth);
//	HBITMAP	hbmResult = ::CreateBitmap(bm.bmHeight, bm.bmWidth, 1, 24, NULL);

	hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), dsBitmap2);
	hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), hbmResult);

	destDC->BitBlt(0, 0, bm.bmHeight, bm.bmWidth, sourceDC, 0, 0, SRCCOPY);

	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource);
	delete sourceDC;
	::SelectObject(destDC->GetSafeHdc(), hbmOldDest);
	delete destDC;

	::DeleteObject(dsBitmap2);

	if (m_bWaitCursor)
	{
		EndWaitCursor();
	}

	return hbmResult;
}

HBITMAP CS309PictureBox::CommonGetBitmapInverted(HBITMAP hBitmap)
{
	BITMAP bm;

	HDC sourceDC = ::CreateCompatibleDC(NULL);
	HDC destDC = ::CreateCompatibleDC(NULL);

	::GetObject(hBitmap, sizeof(bm), &bm );

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC, bm.bmWidth, bm.bmHeight);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);

	::BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, NOTSRCCOPY);

	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hbmResult;
}

HBITMAP CS309PictureBox::CommonGetBitmapCopy(HBITMAP hBitmap)
{
	BITMAP bm;

	HDC sourceDC = ::CreateCompatibleDC(NULL);
	HDC destDC = ::CreateCompatibleDC(NULL);
	::GetObject(hBitmap, sizeof(bm), &bm);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC, bm.bmWidth, bm.bmHeight);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);

	::BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hbmResult;
}

HBITMAP CS309PictureBox::CommonGetBitmapCopyToNewBPP(HBITMAP hBitmap, short nBPP)
{
	BITMAP bm;

	HDC sourceDC = ::CreateCompatibleDC(NULL);
	HDC destDC = ::CreateCompatibleDC(NULL);
	::GetObject(hBitmap, sizeof(bm), &bm);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

//	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC, bm.bmWidth, bm.bmHeight);
	HBITMAP	hbmResult = ::CreateBitmap(bm.bmWidth, bm.bmHeight, 1, nBPP, NULL);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);

	::BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hbmResult;
}


HBITMAP CS309PictureBox::CommonGetBitmapClip(HBITMAP hBitmap, int nLeft, int nTop, int nWidth, int nHeight)
{
	CDC *sourceDC, *destDC;
	CRect *cRect;
	BITMAP Bitmap;
	
	HBITMAP hbmResult;
	HBITMAP hbmOldDest;

	sourceDC = new CDC;
	destDC = new CDC;
	sourceDC->CreateCompatibleDC(NULL);
	destDC->CreateCompatibleDC(NULL);

	if (hBitmap == NULL)
	{
		if ((!m_bOverlay && (m_ocTransparentColor < 16777216)) || (m_bOverlay && (m_ocOverlayTransparentColor < 16777216)))
		{
			hbmResult = ::CreateBitmap(nWidth + nLeft, nHeight + nTop, 1, 24, NULL);
		}
		else
		{
//		HBITMAP hbmNew = ::CreateBitmap(nWidth + nLeft, nHeight + nTop, 1, 8, NULL);
//			hbmResult = ::CreateCompatibleBitmap(CClientDC(NULL), nWidth + nLeft, nHeight + nTop);
			hbmResult = ::CreateBitmap(nWidth + nLeft, nHeight + nTop, 1, m_nImageLoadBitsPerPixel, NULL);
		}
		hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), hbmResult);

		cRect = new CRect( nLeft, nTop, nLeft + nWidth, nTop + nHeight );
		destDC->FillSolidRect(cRect, TranslateColor(m_ocFillColor, NULL));
		delete cRect;

		::SelectObject(destDC->GetSafeHdc(), hbmOldDest);

//		hbmResult = CommonGetBitmapCopy(hbmNew);
//		::DeleteObject(hbmNew);
	}
	else
	{
		::GetObject(hBitmap, sizeof(Bitmap), &Bitmap);

		HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), hBitmap);

		hbmResult = ::CreateCompatibleBitmap(sourceDC->GetSafeHdc(), nWidth, nHeight);
		hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), hbmResult);
		
		int nCopyWidth = nWidth;
		int nCopyHeight = nHeight;

		if (nWidth > (Bitmap.bmWidth - nLeft))
		{
			nCopyWidth = Bitmap.bmWidth - nLeft;
		}
		if (nHeight > (Bitmap.bmHeight - nTop))
		{
			nCopyHeight = Bitmap.bmHeight - nTop;
		}
		if ((nWidth > nCopyWidth) || (nHeight > nCopyHeight))
		{

			cRect = new CRect( nLeft, nTop, nLeft + nWidth, nTop + nHeight );
			destDC->FillSolidRect(cRect, TranslateColor(m_ocFillColor, NULL));
			delete cRect;
		}

		destDC->BitBlt(0, 0, nCopyWidth, nCopyHeight, sourceDC, nLeft, nTop, SRCCOPY);

		::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource);
		::SelectObject(destDC->GetSafeHdc(), hbmOldDest);
	}

	delete sourceDC;
	delete destDC;

	return hbmResult;
}

HBITMAP CS309PictureBox::CommonGetBitmapOverlay(HBITMAP hDestBitmap, HBITMAP hSourceBitmap, int nLeft, int nTop, int nWidth, int nHeight, OLE_COLOR ocTransparent)
{
	CDC *sourceDC, *destDC;
	CRect *cRect;
	BITMAP Bitmap;
	
	HBITMAP hbmResult;
	HBITMAP hbmOldDest;
	HBITMAP hbmOldSource;

	long nNewWidth;
	long nNewHeight;

	sourceDC = new CDC;
	destDC = new CDC;
	sourceDC->CreateCompatibleDC(NULL);
	destDC->CreateCompatibleDC(NULL);

	Bitmap.bmWidth = 0;
	Bitmap.bmHeight = 0;
	if (hDestBitmap != NULL)
	{
		::GetObject(hDestBitmap, sizeof(Bitmap), &Bitmap);
	}

	if (Bitmap.bmWidth < (nLeft + nWidth))
	{
		nNewWidth = nLeft + nWidth;
	}
	else
	{
		nNewWidth = Bitmap.bmWidth;
	}

	if (Bitmap.bmHeight < (nTop + nHeight))
	{
		nNewHeight = nTop + nHeight;
	}
	else
	{
		nNewHeight = Bitmap.bmHeight;
	}

	if (hDestBitmap != NULL)
	{
		hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), hDestBitmap);
	}

	hbmResult = ::CreateCompatibleBitmap(sourceDC->GetSafeHdc(), nNewWidth, nNewHeight);
//	hbmResult = ::CreateBitmap(nNewWidth, nNewHeight, 1, 8, NULL);
//	hbmResult = ::CreateCompatibleBitmap(CClientDC(NULL), nNewWidth, nNewHeight);
	hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), hbmResult);
		
	cRect = new CRect(0, 0, nNewWidth, nNewHeight);
	destDC->FillSolidRect(cRect, TranslateColor(m_ocFillColor, NULL));
	delete cRect;

	if (hDestBitmap != NULL)
	{
		destDC->BitBlt(0, 0, Bitmap.bmWidth, Bitmap.bmHeight, sourceDC, 0, 0, SRCCOPY);
		::SelectObject(sourceDC->GetSafeHdc(), hSourceBitmap);
	}
	else
	{
		hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), hSourceBitmap);
	}
	
	if (ocTransparent > 16777215)
	{
		destDC->BitBlt(nLeft, nTop, nWidth, nHeight, sourceDC, 0, 0, SRCCOPY);
	}
	else
	{
#ifdef UNDER_CE
		::TransparentImage(destDC->GetSafeHdc(), nLeft, nTop, nWidth, nHeight, sourceDC->GetSafeHdc(), 0, 0, nWidth, nHeight, TranslateColor(ocTransparent, NULL));
#endif
	}

	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource);
	::SelectObject(destDC->GetSafeHdc(), hbmOldDest);

	delete sourceDC;
	delete destDC;

	return hbmResult;
}

HBITMAP CS309PictureBox::CommonGetBitmapResize(HBITMAP hBitmap, int nWidth, int nHeight)
{
	BITMAP Bitmap;

	HDC sourceDC = ::CreateCompatibleDC(NULL);
	HDC destDC = ::CreateCompatibleDC(NULL);

	::GetObject(hBitmap, sizeof(Bitmap), &Bitmap);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC, nWidth, nHeight);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);

	::StretchBlt(destDC, 0, 0, nWidth, nHeight, sourceDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hbmResult;
}

OLE_COLOR CS309PictureBox::GetFillColor() 
{
	return m_ocFillColor;
}

void CS309PictureBox::SetFillColor(OLE_COLOR nNewValue) 
{
	m_ocFillColor = nNewValue;
	SetModifiedFlag();
}

short CS309PictureBox::GetCommonBitmapID() 
{
	return m_nCommonBitmapID;
}

void CS309PictureBox::SetCommonBitmapID(short nNewValue) 
{
	int nhigh = -1;
	short nBitmapType;

	switch (m_nCommonBitmapType)
	{
		case -1:
		case 1:
			nhigh = 14;
			break;
		case -2:
		case 2:
			nhigh = 11;
			break;
		case 0:
		default:
			break;
	}
	
	if (((nNewValue < 0) || (nNewValue > nhigh)) || (nhigh == -1))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		return;
	}

	nBitmapType = m_nCommonBitmapType;
	CommonClearForLoad();
	m_nCommonBitmapType = nBitmapType;

	m_nCommonBitmapID = nNewValue;

	SetModifiedFlag();

#ifdef UNDER_CE
	if (m_hCommCtrl == NULL)
	{
		CommonGetCommCtrlInstance();
	}

	switch (m_nCommonBitmapType)
	{
		case 1:
			m_nResourceID = 120;
			break;
		case -1:
			m_nResourceID = 122;
			break;
		case 2:
			m_nResourceID = 124;
			break;
		case -2:
			m_nResourceID = 126;
			break;
		default:
			break;
	}

	m_hInstance = m_hCommCtrl;
	m_bDisplayExpired = true;
	m_bWorkingClip = true;
	m_nWorkingClipTop = 0;
	m_nWorkingClipWidth = 16;
	m_nWorkingClipHeight = 16;
	m_nWorkingClipLeft = (m_nCommonBitmapID * 16);

	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
#endif
}

short CS309PictureBox::GetCommonBitmapType() 
{
	return m_nCommonBitmapType;
}

void CS309PictureBox::SetCommonBitmapType(short nNewValue) 
{
	if ((nNewValue < -2) && (nNewValue > 2))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		CommonClearForLoad();
		m_nCommonBitmapType = nNewValue;
	}
	SetModifiedFlag();
}

void CS309PictureBox::CommonGetCommCtrlInstance()
{
#ifdef UNDER_CE
	m_hCommCtrl = LoadLibrary(_T("commctrl.dll"));
	if (m_hCommCtrl == NULL)
	{
		m_hCommCtrl = LoadLibrary(_T("\\windows\\commctrl.dll"));
	} 
#endif
}

short CS309PictureBox::GetAppearance() 
{
	return m_nAppearance;
}

void CS309PictureBox::SetAppearance(short nNewValue) 
{
	if ((nNewValue < -4) || (nNewValue > 4))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nAppearance = nNewValue;
		SetModifiedFlag();
		
		CommonDesignRefresh();
	}
}


void CS309PictureBox::MethodCaptureScreen() 
{
	CommonClearForLoad();

	m_bWorkingCaptureScreen = true;

	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

HBITMAP CS309PictureBox::CommonGetBitmapScreen()
{
	HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);
	HDC	destDC = ::CreateCompatibleDC(NULL);

	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN); 
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN); 
 
//	HBITMAP	hbmResult = ::CreateBitmap(nScreenWidth, nScreenHeight, 1, 24, NULL);
	HBITMAP hbmResult = ::CreateCompatibleBitmap(CClientDC(NULL), nScreenWidth, nScreenHeight);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);
	
	::BitBlt(destDC, 0, 0, nScreenWidth, nScreenHeight, sourceDC, 0, 0, SRCCOPY);

	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hbmResult;
}


long CS309PictureBox::GetScreenHeight() 
{
	return GetSystemMetrics(SM_CYSCREEN);
}

long CS309PictureBox::GetScreenWidth() 
{
	return GetSystemMetrics(SM_CXSCREEN); 
}

long CS309PictureBox::GetScreenLeft() 
{
	long x;
	CPoint *cPoint;
	cPoint =  new CPoint(0,0);
	ClientToScreen(cPoint);
	x = cPoint->x;
	delete cPoint;
	return x;
}

long CS309PictureBox::GetScreenTop() 
{
	long y;
	CPoint *cPoint;
	cPoint =  new CPoint(0,0);
	ClientToScreen(cPoint);
	y = cPoint->y;
	delete cPoint;
	return y;
}


short CS309PictureBox::GetScreenBitsPerPixel() 
{
	HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);

	int nBitsPerPixel = GetDeviceCaps(sourceDC, BITSPIXEL);

	::DeleteDC(sourceDC);
	
	return nBitsPerPixel;
}

BOOL CS309PictureBox::MethodSaveImageToFile(LPCTSTR szFileName, short nFileType) 
{
	BOOL bReturn = false;

	if ((nFileType == 0) && (m_hBitmap != NULL))
	{
		CFile file;
		if(file.Open(szFileName, CFile::modeWrite|CFile::modeCreate))
		{
			if (m_bWaitCursor)
			{
				BeginWaitCursor();
			}

			BITMAPFILEHEADER hdr;
			LPBITMAPINFO lpbi;
			LPVOID pBits;
			BITMAP bm;
			DIBSECTION ds;

			bool bIsDib, bDefault1632;

			bIsDib = IsDIBSection(m_hBitmap);

			::GetObject(m_hBitmap, sizeof(BITMAP), &bm);

//			if (ds.dsBmih.biClrUsed)
//			{
//				TCHAR msg[100];
//				swprintf(msg, _T("ClrUsed %d\0"),ds.dsBmih.biClrUsed);
//				MessageBox(msg,_T(""),MB_OK);
//			}
			int bits = bm.bmBitsPixel;
			int mult = NumColorEntries(bits);

			if (mult == 0)
			{
				if ((bits == 16) || (bits == 32)) 
				{
					bDefault1632 = true;
					mult = -3;
					if (bIsDib)
					{
						int nDIBSize = ::GetObject(m_hBitmap, sizeof(DIBSECTION), &ds);
						if (ds.dsBmih.biCompression == BI_BITFIELDS)
						{
							bDefault1632 = false;
						}
					}
				}
				else
				{
					bits = 24;
				}
			}

			lpbi = (LPBITMAPINFO) new BYTE[sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult))];
		
			HDC	sourceDC = ::CreateCompatibleDC(NULL);
			HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, m_hBitmap);
			HDC destDC = ::CreateCompatibleDC(NULL);

			if (mult > 0)
			{	
				if (2 == mult)
				{
					lpbi->bmiColors[1].rgbRed = 255;
					lpbi->bmiColors[1].rgbGreen = 255;
					lpbi->bmiColors[1].rgbBlue = 255;
					lpbi->bmiColors[1].rgbReserved = 0;
					lpbi->bmiColors[0].rgbRed = 0;
					lpbi->bmiColors[0].rgbGreen = 0;
					lpbi->bmiColors[0].rgbBlue = 0;
					lpbi->bmiColors[0].rgbReserved = 0;
				}
				else
				{
					long x,y,i,j;
					bool bFound;

					i = 0;
					for (x=0; ((x < bm.bmWidth) && (i < mult)); x++)
					{
						for (y=0; ((y < bm.bmHeight) && (i < mult)); y++)
						{
							COLORREF    rgbColor;
							RGBQUAD		rgbQuad;
                
							rgbColor = ::GetPixel(sourceDC, x, y);
        
							rgbQuad.rgbReserved = 0;
							rgbQuad.rgbBlue = GetBValue(rgbColor);
							rgbQuad.rgbRed = GetRValue(rgbColor);
							rgbQuad.rgbGreen = GetGValue(rgbColor);
							
							bFound = false;
							for (j=0; j<i;j++) // was for (j=0; j<(i-1);j++)
							{
								if (memcmp(&rgbQuad, &lpbi->bmiColors[j],sizeof(RGBQUAD)) == 0)
								{
									bFound = true;
									break;
								}
							}

							if (!bFound)
							{
								lpbi->bmiColors[i] = rgbQuad;
								i++;
							}						
						}
					}

					if ((i < 17) && (mult > 16))
					{
						mult = 16;
						bits = 4;
					}

					for (; i<mult; i++)
					{
						lpbi->bmiColors[i].rgbRed = 0;
						lpbi->bmiColors[i].rgbGreen = 0;
						lpbi->bmiColors[i].rgbBlue = 0;
						lpbi->bmiColors[i].rgbReserved = 0;
					}
				}
			}
			else
			{
				if (mult != 0)
				{
					if (bDefault1632)
					{
						DWORD dwMask;
						if (bits == 16)
						{
							dwMask = 0x7c00;
							memcpy(&lpbi->bmiColors[0],&dwMask,4);
							dwMask = 0x03E0;
							memcpy(&lpbi->bmiColors[1],&dwMask,4);
							dwMask = 0x001F;
							memcpy(&lpbi->bmiColors[2],&dwMask,4);
						}
						else
						{
							dwMask = 0x00FF0000;
							memcpy(&lpbi->bmiColors[0],&dwMask,4);
							dwMask = 0x0000FF00;
							memcpy(&lpbi->bmiColors[1],&dwMask,4);
							dwMask = 0x000000FF;
							memcpy(&lpbi->bmiColors[2],&dwMask,4);
						}
					}
					else
					{
						memcpy(lpbi->bmiColors, &ds.dsBitfields, sizeof(RGBQUAD) * abs(mult));
					}
				}
			}

			lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			lpbi->bmiHeader.biWidth = bm.bmWidth;
			lpbi->bmiHeader.biHeight = bm.bmHeight;
			lpbi->bmiHeader.biPlanes = 1;
			lpbi->bmiHeader.biBitCount = bits;
			if (mult == -3)
			{
				lpbi->bmiHeader.biCompression = BI_BITFIELDS;
			}
			else
			{
				lpbi->bmiHeader.biCompression = BI_RGB;
			}
			lpbi->bmiHeader.biSizeImage = 0;
			lpbi->bmiHeader.biXPelsPerMeter = 0;
			lpbi->bmiHeader.biYPelsPerMeter = 0;
			lpbi->bmiHeader.biClrUsed = 0;
			lpbi->bmiHeader.biClrImportant = 0;

			HBITMAP dsBitmap = ::CreateDIBSection(NULL, (BITMAPINFO *)lpbi, DIB_RGB_COLORS, &pBits, NULL, 0);
			HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, dsBitmap);

			::BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

			::SelectObject(sourceDC, hbmOldSource);
			::DeleteDC(sourceDC);

			::SelectObject(destDC, hbmOldDest);
			::DeleteDC(destDC);

			DWORD nBitsSize = ((((bm.bmWidth * bits) + 31) & (~31) ) / 8) * bm.bmHeight;

			hdr.bfType		= ((WORD) ('M' << 8) | 'B');	// is always "BM"
			hdr.bfSize		=  sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult)) + nBitsSize;
			hdr.bfReserved1 	= 0;
			hdr.bfReserved2 	= 0;
			hdr.bfOffBits		= (DWORD) sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult));	

			file.Write(&hdr, sizeof(BITMAPFILEHEADER));
			file.Write(lpbi, sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult)));

			unsigned char *source;
			source = (unsigned char *)pBits;

			if (nBitsSize < 65535)
			{
				file.Write(source, nBitsSize);
			}
			else
			{
				file.WriteHuge(source, nBitsSize);
			}

			file.Close();

			::DeleteObject(dsBitmap);

			delete [] lpbi;
			
			if (m_bWaitCursor)
			{
				EndWaitCursor();
			}
			
			bReturn = true;
		}

	}
	return bReturn;
}

short CS309PictureBox::GetCenter() 
{
	return m_nCenter;
}

void CS309PictureBox::SetCenter(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 3))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nCenter = nNewValue;
//		m_nWorkingScrollBars = -1;
		SetModifiedFlag();
		CommonDesignRefresh();
	}
}

void CS309PictureBox::CommonClearForLoad()
{
	if (m_hResourceFile != NULL)
	{
		FreeLibrary(m_hResourceFile);
		m_hResourceFile = NULL;
	}

	m_hWorkingBitmap = NULL;
	m_hWorkingIconBitmap = NULL;
	m_hInstance = NULL;
	m_strResourceFile.Empty();
	m_strPicture.Empty();
	m_nResourceBitmapID = -1;
	m_nResourceIconID = -1;
	m_nResourceID = -1;
	m_nPlayingCard = 0;
	m_nCommonBitmapType = 0;
	m_nCommonBitmapID = -1;
	m_bWorkingCaptureScreen = false;

	m_nDrawTextCurrentY = 0;
//	m_nWorkingScrollBars = -1;
	m_nHScrollPosition = 0;
	m_nVScrollPosition = 0;

	m_bWorkingAnimationAvailable = false;
}

short CS309PictureBox::GetVersionMajor() 
{
	return _wVerMajor;
}

short CS309PictureBox::GetVersionMinor() 
{
	return _wVerMinor;
}

long CS309PictureBox::GethBitmap() 
{
	return (long)m_hBitmap;
}

void CS309PictureBox::SethBitmap(long nNewValue) 
{
	BITMAP Bitmap;

	if (::GetObject((HBITMAP)nNewValue, sizeof(Bitmap), &Bitmap))
	{
		CommonClearForLoad();
		m_hWorkingBitmap = (HBITMAP)nNewValue;
		if (!CommonLoadImageIntoBitmap())
		{
			InvalidateControl(NULL);
		}
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}

	SetModifiedFlag();
}

long CS309PictureBox::GetImageLoadMaxHeight() 
{
	return m_nImageLoadMaxHeight;
}

void CS309PictureBox::SetImageLoadMaxHeight(long nNewValue) 
{
	if (nNewValue < 1)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nImageLoadMaxHeight = nNewValue;
		SetModifiedFlag();
	}
}

long CS309PictureBox::GetImageLoadMaxWidth() 
{
	return m_nImageLoadMaxWidth;
}

void CS309PictureBox::SetImageLoadMaxWidth(long nNewValue) 
{
	if (nNewValue < 1)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nImageLoadMaxWidth = nNewValue;
		SetModifiedFlag();
	}
}

BOOL CS309PictureBox::GetOverlay() 
{
	return m_bOverlay;
}

void CS309PictureBox::SetOverlay(BOOL bNewValue) 
{
	m_bOverlay = bNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetOverlayTop() 
{
	return m_nOverlayTop;
}

void CS309PictureBox::SetOverlayTop(long nNewValue) 
{
	if (nNewValue < 0)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nOverlayTop = nNewValue;
		SetModifiedFlag();
	}
}

long CS309PictureBox::GetOverlayLeft() 
{
	return m_nOverlayLeft;
}

void CS309PictureBox::SetOverlayLeft(long nNewValue) 
{
	if (nNewValue < 0)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nOverlayLeft = nNewValue;
		SetModifiedFlag();
	}
}


OLE_COLOR CS309PictureBox::GetTransparentColor() 
{
	return m_ocTransparentColor;
}

void CS309PictureBox::SetTransparentColor(OLE_COLOR nNewValue) 
{
	m_ocTransparentColor = nNewValue;
	SetModifiedFlag();
}

OLE_COLOR CS309PictureBox::GetOverlayTransparentColor() 
{
	return m_ocOverlayTransparentColor;
}

void CS309PictureBox::SetOverlayTransparentColor(OLE_COLOR nNewValue) 
{
	m_ocOverlayTransparentColor = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetImageLoadBufferSize() 
{
	return m_nImageLoadBufferSize;
}

void CS309PictureBox::SetImageLoadBufferSize(long nNewValue) 
{
	if (nNewValue < -1)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nImageLoadBufferSize = nNewValue;
	}
}

OLE_COLOR CS309PictureBox::MethodRGB(short nRed, short nGreen, short nBlue) 
{
	if ((nRed < 0) || (nRed > 255) || (nGreen < 0) || (nGreen > 255) || (nBlue < 0) || (nBlue > 255))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		return RGB(0, 0, 0);
	}
	else
	{
		return RGB(nRed, nGreen, nBlue);
	}
}

OLE_COLOR CS309PictureBox::MethodQBColor(short nColorCode) 
{
	long nQBColors[16] = {0,8388608,32768,8421376,128,8388736,32896,12632256,8421504,16711680,65280,16776960,255,16711935,65535,16777215};

	if ((nColorCode < 0) || (nColorCode > 15))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		return RGB(0, 0, 0);
	}
	else
	{
		return nQBColors[nColorCode];
	}
}

long CS309PictureBox::GetDrawWidth() 
{
	return m_nDrawWidth;
}

void CS309PictureBox::SetDrawWidth(long nNewValue) 
{
	if (nNewValue < 1)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nDrawWidth = nNewValue;
	}
	SetModifiedFlag();
}

BOOL CS309PictureBox::GetAutoRefresh() 
{
	return m_bAutoRefresh;
}

void CS309PictureBox::SetAutoRefresh(BOOL bNewValue) 
{
	m_bAutoRefresh = bNewValue;
	if (m_bAutoRefresh)
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
	SetModifiedFlag();
}

short CS309PictureBox::GetFillStyle() 
{
	return m_nFillStyle;
}

void CS309PictureBox::SetFillStyle(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 1))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nFillStyle = nNewValue;
		SetModifiedFlag();
	}	
}

void CS309PictureBox::MethodSetPointArray(long nIndex, long nX, long nY) 
{
	if ((nIndex < 1) || (nIndex > 20))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_ptPoint[nIndex - 1].x = nX;
		m_ptPoint[nIndex - 1].y = nY;
		SetModifiedFlag();
	}
}

OLE_COLOR CS309PictureBox::GetPixel(long nX, long nY) 
{
	OLE_COLOR cl = RGB(0, 0, 0);
	BITMAP Bitmap;
	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);

	if ((Bitmap.bmHeight < nY) || (Bitmap.bmWidth < nX))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		HDC dcNew = ::CreateCompatibleDC(NULL);
		HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);
		cl = ::GetPixel(dcNew, nX, nY);
		::SelectObject(dcNew, cOldBitmap);
		::DeleteDC(dcNew);
	}
	return cl;
}

void CS309PictureBox::SetPixel(long nX, long nY, OLE_COLOR nNewValue) 
{
	BITMAP Bitmap;

	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);

	if ((Bitmap.bmHeight < nY) || (Bitmap.bmWidth < nX))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		HDC dcNew = ::CreateCompatibleDC(NULL);
		HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);
		::SetPixel(dcNew, nX, nY, TranslateColor(nNewValue, NULL));
		::SelectObject(dcNew, cOldBitmap);
		::DeleteDC(dcNew);
	}

	SetModifiedFlag();
}

void CS309PictureBox::MethodCreateImage(long nX, long nY) 
{
	long nWidth = 0;
	long nHeight = 0;

	CommonClearForLoad();

	if (m_hBitmap != NULL)
	{
		::DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}

	nWidth = nX;
	nHeight = nY;

	if (nWidth < 1)
	{
		if (abs(nWidth) < GetSystemMetrics(SM_CXSCREEN))
		{
			nWidth = GetSystemMetrics(SM_CXSCREEN) + nWidth;
		}
		else
		{
			nWidth = GetSystemMetrics(SM_CXSCREEN);
		}
	}

	if (nHeight < 1)
	{
		if (abs(nHeight) < GetSystemMetrics(SM_CYSCREEN))
		{
			nHeight = GetSystemMetrics(SM_CYSCREEN) + nHeight;
		}
		else
		{
			nHeight = GetSystemMetrics(SM_CYSCREEN);
		}
	}

	m_hBitmap = CommonGetBitmapClip(NULL, 0, 0, nWidth, nHeight);

	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

HBITMAP CS309PictureBox::CommonGetBitmapControlSize()
{
	CRect cRect;
	HBITMAP hBitmap = NULL;
	OLE_COLOR oc;
	int nBorder = 0;

	CommonClearForLoad();

	oc = m_ocFillColor;
	m_ocFillColor = GetBackColor();

	if (GetRectInContainer(cRect))
	{			
		if (m_nBorderStyle != 0)
		{
			switch (m_nAppearance)
			{
				case -4:
					nBorder = 10;
					break;
				case 3:
					nBorder = 6;
					break;
				case 0:
				case 4:
					nBorder = 2;
					break;
				default:
					nBorder = 4;
					break;
			}
		}

		if ((cRect.Width() > nBorder) && (cRect.Height() > nBorder))
		{
			hBitmap = CommonGetBitmapClip(NULL, 0, 0, cRect.Width() - nBorder, cRect.Height() - nBorder);
		}
	}
		
	if (hBitmap == NULL)
	{
		hBitmap = CommonGetBitmapClip(NULL, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	}

	m_ocFillColor = oc;

	return hBitmap;
}

short CS309PictureBox::GetPenStyle() 
{
	return m_nPenStyle;
}

void CS309PictureBox::SetPenStyle(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 2))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nPenStyle = nNewValue;
		SetModifiedFlag();
	}
}

short CS309PictureBox::GetScaleMode() 
{
	return 3;
}

void CS309PictureBox::SetScaleMode(short nNewValue) 
{
	if (nNewValue != 3)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
}

short CS309PictureBox::GetPenFillStyle() 
{
	return m_nPenFillStyle;
}

void CS309PictureBox::SetPenFillStyle(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 1))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nPenFillStyle = nNewValue;
		SetModifiedFlag();
	}	
}

BOOL CS309PictureBox::MethodCopy() 
{
	BOOL bReturn = false;
	if ((::OpenClipboard(NULL)) && (m_hBitmap != NULL))
	{
		::EmptyClipboard();

		HBITMAP hBitmap = CommonGetBitmapCopy(m_hBitmap);
		bReturn = true;
		if (::SetClipboardData(CF_BITMAP, hBitmap) == NULL)
		{
			::DeleteObject(hBitmap);
			bReturn = false;
		}
		::CloseClipboard();
	}
	return bReturn;
}

BOOL CS309PictureBox::MethodPaste() 
{
	BOOL bReturn = false;
	if (::OpenClipboard(NULL))
	{
		HBITMAP hClipboardBitmap = (HBITMAP)::GetClipboardData(CF_BITMAP);

		if (hClipboardBitmap != NULL)
		{
			CommonClearForLoad();

			m_hWorkingBitmap = hClipboardBitmap;
		
			bReturn = true;

			if (!CommonLoadImageIntoBitmap())
			{
				InvalidateControl(NULL);
			}
		}
		::CloseClipboard();
	}
	return bReturn;
}

BOOL CS309PictureBox::GetBitmapOnClipboard() 
{
	return IsClipboardFormatAvailable(CF_BITMAP);
}

short CS309PictureBox::GetImageBitsPerPixel() 
{
	BITMAP bm;
	short nBpp = 0;
	if (m_hBitmap != NULL)
	{
		if (::GetObject(m_hBitmap, sizeof(bm), &bm))
		{
			nBpp = bm.bmBitsPixel;
		}
	}
	return nBpp;
}

void CS309PictureBox::SetImageBitsPerPixel(short nNewValue) 
{
	if (m_hBitmap != NULL)
	{
		switch (nNewValue)
		{
			case 1:
			case 2:
			case 4:
			case 8:
			case 16:
			case 24:
			case 32:
			{
				HBITMAP hBitmap = CommonGetBitmapCopyToNewBPP(m_hBitmap, nNewValue);
				::DeleteObject(m_hBitmap);
				m_hBitmap = hBitmap;
				if (!CommonCheckAutoSize(false))
				{
					InvalidateControl(NULL);
				}
				break;
			}
			default:
			{
				ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
				break;
			}
		}
	}
}


DWORD CS309PictureBox::GetControlFlags() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return COleControl::GetControlFlags() | pointerInactive;
}
// CWnd

UINT CS309PictureBox::CEGetDIBColorTable(HBITMAP hDIBSection, UINT uStartIndex, UINT cEntries, RGBQUAD *pColors)
{
/**********************************************************************
This function is from the MS KB article "HOWTO: Get the Color Table of 
a DIBSection in Windows CE".

PARAMETERS:
HDC - the Device Context in which the DIBSection is selected
UINT - the index of the first color table entry to retrieve
UINT - the number of color table entries to retrieve
RGBQUAD - a buffer large enough to hold the number of RGBQUAD
entries requested

RETURNS:
UINT - the number of colors placed in the buffer

***********************************************************************/
//UINT CEGetDIBColorTable(HDC hdc, UINT uStartIndex, UINT cEntries,
//                        RGBQUAD *pColors)
//{   
    if (pColors == NULL)
        return 0;                       // No place to put them, fail
    
    // Get a description of the DIB Section
    DIBSECTION ds;
    DWORD dwSize = GetObject( hDIBSection, sizeof(DIBSECTION), &ds );
    
    if (dwSize != sizeof(DIBSECTION))
        return 0;                      // Must not be a DIBSection, fail
    
    if (ds.dsBmih.biBitCount > 8)
        return 0;                      // Not Palettized, fail
    
	if (ds.dsBm.bmBits == NULL)
        return 0;                      // Not Palettized, fail
    // get the number of colors to return per BITMAPINFOHEADER docs
    UINT cColors;
    if (ds.dsBmih.biClrUsed)
        cColors = ds.dsBmih.biClrUsed;
    else
        cColors = 1 << (ds.dsBmih.biBitCount*ds.dsBmih.biPlanes);
    
    // Create a mask for the palette index bits for 1, 2, 4, and 8 bpp
    WORD wIndexMask = (0xFF << (8 - ds.dsBmih.biBitCount)) & 0x00FF;
    
    LPBYTE pBits = (LPBYTE) ds.dsBm.bmBits;
    
    // Initialize the loop variables
    cColors = min( cColors, cEntries );
    BYTE OldPalIndex = *pBits;
 
    UINT TestPixelY;
    if (ds.dsBmih.biHeight > 0 )
        // If button up DIB, pBits points to last row
        TestPixelY = ds.dsBm.bmHeight-1;
    else
        // If top down DIB, pBits points to first row
        TestPixelY = 0;
    
	HDC hdc = ::CreateCompatibleDC(NULL);
	HBITMAP hOldBitmap = (HBITMAP)::SelectObject(hdc, hDIBSection);

    for (UINT iColor = uStartIndex; iColor < cColors; iColor++)
    {
        COLORREF    rgbColor;
        
        // Set the palette index for the test pixel,
        // modifying only the bits for one pixel
        *pBits = (iColor << (8 - ds.dsBmih.biBitCount)) |
            (*pBits & ~wIndexMask);
        
        // now get the resulting color
        rgbColor = ::GetPixel( hdc, 0, TestPixelY );
        
        pColors[iColor - uStartIndex].rgbReserved = 0;
        pColors[iColor - uStartIndex].rgbBlue = GetBValue(rgbColor);
        pColors[iColor - uStartIndex].rgbRed = GetRValue(rgbColor);
        pColors[iColor - uStartIndex].rgbGreen = GetGValue(rgbColor);
    }
    
	::SelectObject(hdc, hOldBitmap);
	::DeleteDC(hdc);

    // Restore the test pixel
    *pBits = OldPalIndex;
    
    return cColors;
}

short CS309PictureBox::MethodIntensityRed(OLE_COLOR ocColor) 
{
	return GetRValue(ocColor);
}

short CS309PictureBox::MethodIntensityGreen(OLE_COLOR ocColor) 
{
	return GetGValue(ocColor);
}

short CS309PictureBox::MethodIntensityBlue(OLE_COLOR ocColor) 
{
	return GetBValue(ocColor);
}

bool CS309PictureBox::IsDIBSection(HBITMAP hBitmap)
{
	bool bReturn = false;
	if (hBitmap != NULL)
	{
		DIBSECTION ds;
		DWORD dwSize = GetObject(hBitmap, sizeof(DIBSECTION), &ds );
   
		if (dwSize == sizeof(DIBSECTION))
		{
			if (ds.dsBm.bmBits != NULL)
			{
				bReturn = true;
			}
		}
	}
	return bReturn;

}

short CS309PictureBox::GetImageLoadBitsPerPixel() 
{
	return m_nImageLoadBitsPerPixel;
}

void CS309PictureBox::SetImageLoadBitsPerPixel(short nNewValue) 
{
	if (0 > nNewValue)
	{
		short nScale = -1 * nNewValue;

		if (nScale > 100)
		{
			ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		}
		else
		{
			m_nImageLoadScalePercent = nScale;
		}
	}
	else
	{
		switch (nNewValue)
		{
			case 1:
			case 2:
			case 4:
			case 8:
			case 16:
			case 24:
			case 32:
			{
				m_nImageLoadBitsPerPixel = nNewValue;
				break;
			}
			default:
			{
				ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
				break;
			}
		}
	}
}

DWORD CS309PictureBox::SwapEndian(DWORD nOld)
{
	DWORD nNew = 0;
	while (nOld > 0)
	{
		nNew = (nNew << 8) + (nOld % 256);
		nOld = nOld >> 8;
	}
	return nNew;
}

HBITMAP CS309PictureBox::CommonGetBitmapScroll(HBITMAP hBitmap, long nScrollX, long nScrollY)
{
	CDC *sourceDC, *destDC;
	BITMAP bm;
	BITMAPINFOHEADER bmih1, bmih2;
	LPVOID pBits1, pBits2;
	HBITMAP dsBitmap1, dsBitmap2;
	HBITMAP hbmOldSource, hbmOldDest;
	int destx, desty, sourcex, sourcey;

	if (m_bWaitCursor)
	{
		BeginWaitCursor();
	}

	sourceDC = new CDC;
	sourceDC->CreateCompatibleDC( NULL );
	destDC = new CDC;
	destDC->CreateCompatibleDC( NULL );
	::GetObject( hBitmap, sizeof( bm ), &bm );

	bmih1.biSize = sizeof(BITMAPINFOHEADER);
	bmih1.biWidth = bm.bmWidth;
	bmih1.biHeight = bm.bmHeight;
	bmih1.biPlanes = 1;
	bmih1.biBitCount = 24;
	bmih1.biCompression = BI_RGB;
	bmih1.biSizeImage = 0;
	bmih1.biXPelsPerMeter = 0;
	bmih1.biYPelsPerMeter = 0;
	bmih1.biClrUsed = 0;
	bmih1.biClrImportant = 0;

	dsBitmap1 = CreateDIBSection(NULL, (BITMAPINFO *) &bmih1, 0, &pBits1, NULL, 0);
	hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), hBitmap );
	hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), dsBitmap1 );

	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC->GetSafeHdc(), bm.bmWidth, bm.bmHeight);

	destDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource );
	delete sourceDC;
	::SelectObject(destDC->GetSafeHdc(), hbmOldDest);
	delete destDC;

	bmih2.biSize = sizeof(BITMAPINFOHEADER);
	bmih2.biWidth = bm.bmWidth;
	bmih2.biHeight = bm.bmHeight;
	bmih2.biPlanes = 1;
	bmih2.biBitCount = 24;
	bmih2.biCompression = BI_RGB;
	bmih2.biSizeImage = 0;
	bmih2.biXPelsPerMeter = 0;
	bmih2.biYPelsPerMeter = 0;
	bmih2.biClrUsed = 0;
	bmih2.biClrImportant = 0;

	dsBitmap2 = CreateDIBSection(NULL, (BITMAPINFO *) &bmih2, 0, &pBits2, NULL, 0);
	
	int nSourceRowBytes = (((bmih1.biWidth * 3) + 3) / 4) * 4;
	int nDestRowBytes = (((bmih2.biWidth * 3) + 3) / 4) * 4;

	unsigned char *source;
	unsigned char *dest;

	while (nScrollX < 0)
	{
		nScrollX += bm.bmWidth;
	}

	while (nScrollX >= bm.bmWidth)
	{
		nScrollX -= bm.bmWidth;
	}

	while (nScrollY < 0)
	{
		nScrollY += bm.bmHeight;
	}

	while (nScrollY >= bm.bmHeight)
	{
		nScrollY -= bm.bmHeight;
	}

	for (sourcex = 0; sourcex < bm.bmWidth; sourcex++)
	{
		destx = sourcex + nScrollX;
		if (destx >= bm.bmWidth) 
		{
			destx -= bm.bmWidth;
		}

		for (sourcey = 0; sourcey < bm.bmHeight; sourcey++)
		{
			desty = sourcey + nScrollY;
			if (desty >= bm.bmHeight) 
			{
				desty -= bm.bmHeight;
			}

			source = (unsigned char *)pBits1 + (nSourceRowBytes * ((bmih1.biHeight - 1) - sourcey)) + (sourcex * 3);
			dest = (unsigned char *)pBits2 + (nDestRowBytes * ((bmih2.biHeight - 1) - desty)) + (destx * 3);
			dest[0] = source[0];
			dest[1] = source[1];
			dest[2] = source[2];

		}
	}
	::DeleteObject(dsBitmap1);

	sourceDC = new CDC;
	sourceDC->CreateCompatibleDC(NULL);
	destDC = new CDC;
	destDC->CreateCompatibleDC(NULL);

//	BITMAP hbmResult = ::CreateCompatibleBitmap(CClientDC(NULL), bm.bmHeight, bm.bmWidth);
//	HBITMAP	hbmResult = ::CreateBitmap(bm.bmHeight, bm.bmWidth, 1, 24, NULL);

	hbmOldSource = (HBITMAP)::SelectObject(sourceDC->GetSafeHdc(), dsBitmap2);
	hbmOldDest = (HBITMAP)::SelectObject(destDC->GetSafeHdc(), hbmResult);

	destDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource);
	delete sourceDC;
	::SelectObject(destDC->GetSafeHdc(), hbmOldDest);
	delete destDC;

	::DeleteObject(dsBitmap2);

	if (m_bWaitCursor)
	{
		EndWaitCursor();
	}

	return hbmResult;
}

BOOL CS309PictureBox::GetScroll() 
{
	return m_bScroll;
}

void CS309PictureBox::SetScroll(BOOL bNewValue) 
{
	m_bScroll = bNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetScrollX() 
{
	return m_nScrollX;
}

void CS309PictureBox::SetScrollX(long nNewValue) 
{
	m_nScrollX = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetScrollY() 
{
	return m_nScrollY;
}

void CS309PictureBox::SetScrollY(long nNewValue) 
{
	m_nScrollY = nNewValue;
	SetModifiedFlag();
}

void CS309PictureBox::MethodScrollImage() 
{
	m_hBitmap = CommonScroll(m_hBitmap);
	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

HBITMAP CS309PictureBox::CommonScroll(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = NULL;

	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapScroll(hBitmap, m_nScrollX, m_nScrollY);
		::DeleteObject(hBitmap);
	}
	return hReturnBitmap;
}

void CS309PictureBox::MethodRefreshDesktopWallpaper() 
{
#ifdef UNDER_CE
	HWND hWnd = ::FindWindow(_T("DesktopExplorerWindow"),NULL);
	if (hWnd != NULL)
	{
		::SendMessage(hWnd, WM_COMMAND, 0x451, 0);
		HDC hDC = ::GetDC(hWnd);
		::SendMessage(hWnd, WM_ERASEBKGND, (WPARAM)hDC, 0);
		::ReleaseDC(hWnd, hDC);
	}
#endif
}

void CS309PictureBox::MethodSetCapture() 
{
	SetCapture();
}

void CS309PictureBox::MethodReleaseCapture() 
{
	ReleaseCapture();
}

void CS309PictureBox::MethodDrawMouseMoveLinesEx(long nStartX, long nStartY, long nEndX, long nEndY, OLE_COLOR ocColor) 
{
	POINT ptsMouseMove[MOUSEMOVEPOINTSCOUNTMAX + 2];

	if (m_nMouseMovePointsCount > 0)
	{
		long screenx = GetScreenLeft();
		long screeny = GetScreenTop();
		for (short nIndex = m_nMouseMovePointsCount; nIndex > 0; nIndex--)
		{
			ptsMouseMove[nIndex].x = (m_ptsMouseMove[nIndex - 1].x / 4) - screenx;
			ptsMouseMove[nIndex].y = (m_ptsMouseMove[nIndex - 1].y / 4) - screeny;
		}
	}
	ptsMouseMove[0].x = nStartX;
	ptsMouseMove[0].y = nStartY;
	ptsMouseMove[m_nMouseMovePointsCount + 1].x = nEndX;
	ptsMouseMove[m_nMouseMovePointsCount + 1].y = nEndY;

	CommonDrawPolyLines(ptsMouseMove, m_nMouseMovePointsCount + 2, ocColor);
}

void CS309PictureBox::MethodDrawMouseMoveLines(OLE_COLOR ocColor) 
{
	switch (m_nMouseMovePointsCount)
	{
		case 0:
			break;
		case 1:
			CommonDrawPoint((m_ptsMouseMove[0].x / 4) - GetScreenLeft(), (m_ptsMouseMove[0].y / 4) - GetScreenTop(), ocColor);
			break;
		default:
			POINT ptsMouseMove[MOUSEMOVEPOINTSCOUNTMAX];
			if (m_hBitmap == NULL)
			{
				m_hBitmap = CommonGetBitmapControlSize();
			}

			long screenx = GetScreenLeft();
			long screeny = GetScreenTop();
			for (short nIndex = m_nMouseMovePointsCount - 1; nIndex > -1; nIndex--)
			{
				ptsMouseMove[nIndex].x = (m_ptsMouseMove[nIndex].x / 4) - screenx;
				ptsMouseMove[nIndex].y = (m_ptsMouseMove[nIndex].y / 4) - screeny;
			}
			
			CommonDrawPolyLines(ptsMouseMove, m_nMouseMovePointsCount, ocColor);
			break;
	}
}

void CS309PictureBox::CommonDrawPolyLines(POINT *pts, short nPoints, OLE_COLOR ocColor)
{
	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	HDC dcNew = ::CreateCompatibleDC(NULL);
	HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

	HPEN hPen;
	if (m_nDrawWidth < 2)
	{
		switch (m_nPenStyle)
		{
			case 0:
				hPen = (HPEN)::CreatePen(PS_NULL, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
			case 2:
				hPen = (HPEN)::CreatePen(PS_DASH, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
			default:
			case 1:
				hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
		}
	}
	else
	{
		hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
	}
	HPEN hOldPen = (HPEN)::SelectObject(dcNew, hPen);
	if (m_nPenFillStyle == 0)
	{
		SetBkMode(dcNew, OPAQUE);
		SetBkColor(dcNew, TranslateColor(GetBackColor(),NULL));
	}
	else
	{
		SetBkMode(dcNew, TRANSPARENT);
	}

	::Polyline(dcNew, pts, nPoints);

	::SelectObject(dcNew, hOldPen);
	::DeleteObject(hPen);

	::SelectObject(dcNew, cOldBitmap);
	::DeleteDC(dcNew);

	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

BOOL CS309PictureBox::MethodGetMouseMovePoint(short nPoint, long FAR* nX, long FAR* nY) 
{
	BOOL bReturn = false;
	if ((nPoint > -1) && ((UINT)nPoint < m_nMouseMovePointsCount))
	{
		*nX = (m_ptsMouseMove[nPoint].x / 4) - GetScreenLeft();
		*nY = (m_ptsMouseMove[nPoint].y / 4) - GetScreenTop();
		bReturn = true;
	}
	return bReturn;
}

void CS309PictureBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
#ifdef UNDER_CE
#ifdef WIN32_PLATFORM_PSPC
#if _WIN32_WCE > 299
	bool bTapAndHold = false;
	if (SHRecognizeGesture(point, false))
	{
		FireTapAndHold(nButtons, nKeys, point.x, point.y);
		bTapAndHold = true;
	}
	if (!bTapAndHold)
#endif // _WIN32_WCE > 299 
#endif // WIN32_PLATFORM_PSPC
#endif // UNDER_CE
	{
		CommonFireMouse(0, nButtons, nKeys, point.x, point.y);
		CommonFireMousePoints(nButtons, nKeys);
	}
	COleControl::OnLButtonDown(nFlags, point);
}

void CS309PictureBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
	CommonFireMousePoints(nButtons, nKeys);
	CommonFireMouse(1, nButtons, nKeys, point.x, point.y);
	COleControl::OnMouseMove(nFlags, point);
}

void CS309PictureBox::OnLButtonUp(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
	CommonFireMousePoints(nButtons, nKeys);
	CommonFireMouse(2, nButtons, nKeys, point.x, point.y);
	COleControl::OnLButtonUp(nFlags, point);
}

void CS309PictureBox::CommonFireMouse(short nType, short nButtons, short nKeys, long x, long y)
{
	switch (nType)
	{
		case 0:
			FireMouseDown(nButtons, nKeys, x, y);
			break;
		case 1:
			FireMouseMove(nButtons, nKeys, x, y);
			break;
		case 2:
			FireMouseUp(nButtons, nKeys, x, y);
			break;
	}
}

void CS309PictureBox::CommonFireMousePoints( short nButtons, short nKeys)
{
	m_nMouseMovePointsCount = 0;
#ifdef UNDER_CE
	if (m_nMouseMovePoints > 0)
	{
		::GetMouseMovePoints(m_ptsMouseMove, MOUSEMOVEPOINTSCOUNTMAX, &m_nMouseMovePointsCount);
		if ((m_nMouseMovePointsCount > 0) && (m_nMouseMovePoints == 1))
		{
			long x;
			long y;
			long px = -1;
			long py = -1;
			long screenx = GetScreenLeft();
			long screeny = GetScreenTop();
			for (UINT nIndex = 0; nIndex < m_nMouseMovePointsCount; nIndex++)
			{
				x = (m_ptsMouseMove[nIndex].x / 4) - screenx;
				y = (m_ptsMouseMove[nIndex].y / 4) - screeny;
				if ((px != x) || (py != y))
				{
					CommonFireMouse(1, nButtons, nKeys, x, y);
					px = x;
					py = y;
				}
			}
		}
	}
#endif
}

long CS309PictureBox::GetMouseMovePointsCount() 
{
	return m_nMouseMovePointsCount;
}

short CS309PictureBox::GetMouseMovePoints() 
{
	return m_nMouseMovePoints;
}

void CS309PictureBox::SetMouseMovePoints(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 2))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nMouseMovePoints = nNewValue;
	}
	SetModifiedFlag();
}

short CS309PictureBox::CommonFireMouseButtons(UINT nFlags)
{
	short nButtons;
	nButtons = (nFlags & (MK_LBUTTON | MK_RBUTTON));
	if ((nFlags & MK_MBUTTON) == MK_MBUTTON)
	{
		nButtons |= 0x04;
	}
	return nButtons;
}

short CS309PictureBox::CommonFireMouseKeys(UINT nFlags)
{
	short nKeys;
	nKeys = ((nFlags & (MK_SHIFT | MK_CONTROL)) >> 2);

	if (GetAsyncKeyState(VK_MENU) != 0)
	{
		nKeys |= 0x04;
	}
	return nKeys;
}

short CS309PictureBox::GetVersion() 
{
	return (_wVerMajor * 100) + _wVerMinor;
}

void CS309PictureBox::MethodRefreshX() 
{
	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

BOOL CS309PictureBox::GetFontBold() 
{
	BOOL bReturn;

	if (m_LogFont.lfWeight <= 550)
		bReturn = false;
	else
		bReturn = true;

	return bReturn;
}

void CS309PictureBox::SetFontBold(BOOL bNewValue) 
{
	CommonDestroyFont();

	if (bNewValue)
		m_LogFont.lfWeight = 700;
	else
		m_LogFont.lfWeight = 400;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BOOL CS309PictureBox::GetFontItalic() 
{
	return m_LogFont.lfItalic;
}

void CS309PictureBox::SetFontItalic(BOOL bNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfItalic = bNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BSTR CS309PictureBox::GetFontName() 
{
	CString strResult;

	strResult = m_LogFont.lfFaceName;

	return strResult.AllocSysString();
}

void CS309PictureBox::SetFontName(LPCTSTR lpszNewValue) 
{
	m_strFontResult = lpszNewValue;

	HDC dcNew = ::CreateCompatibleDC(NULL);

	int rc = EnumFontFamilies((HDC)dcNew, (LPTSTR)NULL, (FONTENUMPROC)CallbackEnumFontFamilyCallback1, (LPARAM)this);

	::DeleteDC(dcNew);

	if (rc == 0)
	{
		CommonDestroyFont();

		if (!m_bWorkingPropExchange)
		{
			SetModifiedFlag();
		}
	}
}

int CS309PictureBox::CallbackEnumFontFamilyCallback1(ENUMLOGFONT *lpelf, NEWTEXTMETRIC *lpntm, int FontType,  LPARAM lParam)
{
	int nReturn = 1;

	if (FontType == TRUETYPE_FONTTYPE)
	{
		CS309PictureBox* lpS309PictureBox = (CS309PictureBox*)lParam;

		nReturn = lpS309PictureBox->m_strFontResult.CompareNoCase(lpelf->elfLogFont.lfFaceName);

		if (nReturn == 0)
		{
			lpS309PictureBox->m_LogFont.lfCharSet = lpntm->tmCharSet;
			lpS309PictureBox->m_LogFont.lfPitchAndFamily = lpntm->tmPitchAndFamily;
			_tcscpy(lpS309PictureBox->m_LogFont.lfFaceName, lpelf->elfLogFont.lfFaceName);	
		}
	}

	return nReturn;
}

BOOL CS309PictureBox::GetFontStrikethru() 
{

	return m_LogFont.lfStrikeOut;
}

void CS309PictureBox::SetFontStrikethru(BOOL bNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfStrikeOut = bNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BOOL CS309PictureBox::GetFontUnderline() 
{

	return m_LogFont.lfUnderline;
}

void CS309PictureBox::SetFontUnderline(BOOL bNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfUnderline = bNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BOOL CS309PictureBox::GetFontTransparent() 
{

	return m_bFontTransparent;
}

void CS309PictureBox::SetFontTransparent(BOOL bNewValue) 
{
	m_bFontTransparent = bNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetFontWeight() 
{
	return m_LogFont.lfWeight;
}

void CS309PictureBox::SetFontWeight(long nNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfWeight = nNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}


long CS309PictureBox::GetFontSize() 
{
	long nReturn = (long)((-1.0 * ((double)(m_LogFont.lfHeight * 72) / (double)(m_nLogPixelsY))) + 0.5);
//	long nReturn = -1 * (m_LogFont.lfHeight * 72 / m_nLogPixelsY); 
//	long nTemp = -1 * (nReturn * m_nLogPixelsY / 72);
//	if (nTemp != m_LogFont.lfHeight)
//		nReturn++;
	return nReturn;
}

void CS309PictureBox::SetFontSize(long nNewValue) 
{
	CommonDestroyFont();

#ifndef UNDER_CE
	m_LogFont.lfHeight = -MulDiv(nNewValue, m_nLogPixelsY, 72);
#else // UNDER_CE
	m_LogFont.lfHeight = -1 * (long)(((double)(nNewValue * m_nLogPixelsY) / 72.0) + 0.5);
#endif // UNDER_CE

//	m_LogFont.lfHeight = -1 * (nNewValue * m_nLogPixelsY / 72);

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}


DWORD CS309PictureBox::CallbackGetImageData(LPSTR szBuffer, DWORD dwBufferMax, LPARAM lParam)
{
	DWORD dwNumberOfBytesRead;

	if ((HANDLE)lParam != INVALID_HANDLE_VALUE)
	{
		ReadFile((HANDLE)lParam, szBuffer, dwBufferMax, &dwNumberOfBytesRead, NULL);
	}
	else
	{
		dwNumberOfBytesRead = 0;
	}

	return dwNumberOfBytesRead;
}

BOOL CS309PictureBox::GetFocusRect() 
{
	return m_bFocusRect;
}

void CS309PictureBox::SetFocusRect(BOOL bNewValue) 
{
	m_bFocusRect = bNewValue;
	SetModifiedFlag();
}


long CS309PictureBox::GetFocusRectIndentLeft() 
{
	return m_nFocusRectIndentLeft;
}

void CS309PictureBox::SetFocusRectIndentLeft(long nNewValue) 
{
	m_nFocusRectIndentLeft = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetFocusRectIndentRight() 
{
	return m_nFocusRectIndentRight;
}

void CS309PictureBox::SetFocusRectIndentRight(long nNewValue) 
{
	m_nFocusRectIndentRight = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetFocusRectIndentTop() 
{
	return m_nFocusRectIndentTop;
}

void CS309PictureBox::SetFocusRectIndentTop(long nNewValue) 
{
	m_nFocusRectIndentTop = nNewValue;
	SetModifiedFlag();
}

long CS309PictureBox::GetFocusRectIndentBottom() 
{
	return m_nFocusRectIndentBottom;
}

void CS309PictureBox::SetFocusRectIndentBottom(long nNewValue) 
{
	m_nFocusRectIndentBottom = nNewValue;
	SetModifiedFlag();
}

BOOL CS309PictureBox::GetCommandButton() 
{
	return m_bCommandButton;
}

void CS309PictureBox::SetCommandButton(BOOL bNewValue) 
{
	m_bCommandButton = bNewValue;
	if (m_bCommandButton)
		m_bFocusRect = true;	
	SetModifiedFlag();

	CommonDesignRefresh();
}

long CS309PictureBox::GethFont() 
{
	if (AmbientUserMode())
	{
		CommonCreateFont();
	}
	
	return (long)m_hFont;
}

void CS309PictureBox::SethFont(long nNewValue) 
{
	if (::GetObject((HFONT)nNewValue, sizeof(m_LogFont), &m_LogFont))
	{
		CommonDestroyFont();
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
}

void CS309PictureBox::CommonCreateFont()
{
	if (m_hFont == NULL)
	{
		m_hFont = ::CreateFontIndirect(&m_LogFont);

		if (m_hFont != NULL)
		{
			::GetObject(m_hFont, sizeof(m_LogFont), &m_LogFont);
		}
	}
}

void CS309PictureBox::CommonDestroyFont()
{
	if (m_hFont != NULL)
	{
		::DeleteObject(m_hFont);
		m_hFont = NULL;
	}
}

void CS309PictureBox::MethodDrawCircle(long nX, long nY, float flRadius, const VARIANT FAR& vocColor, const VARIANT FAR& vflAspect) 
{
	float flAspectRatio = CommonOptionalFloat(&vflAspect,1.0);
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor,(long)GetForeColor());

	int nLeft, nTop, nRight, nBottom;

	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	if (flAspectRatio < 1.0)
	{
		int nRadius = (int)(flRadius * flAspectRatio);
		nTop = nY - nRadius;
		nBottom = nY + nRadius;
		nLeft = nX - (int)flRadius;
		nRight = nX + (int)flRadius;
	}
	else
	{
		int nRadius = (int)(flRadius / flAspectRatio);
		nTop = nY - (int)flRadius;
		nBottom = nY + (int)flRadius;
		nLeft = nX - nRadius;
		nRight = nX + nRadius;
	}

	HDC dcNew = ::CreateCompatibleDC(NULL);
	HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

	HPEN hPen;
	if (m_nDrawWidth < 2)
	{
		switch (m_nPenStyle)
		{
			case 0:
				hPen = (HPEN)::CreatePen(PS_NULL, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
			case 2:
				hPen = (HPEN)::CreatePen(PS_DASH, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
			default:
			case 1:
				hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
		}
	}
	else
	{
		hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
	}
	HPEN hOldPen = (HPEN)::SelectObject(dcNew, hPen);
	if (m_nPenFillStyle == 0)
	{
		SetBkMode(dcNew, OPAQUE);
		SetBkColor(dcNew, TranslateColor(GetBackColor(),NULL));
	}
	else
	{
		SetBkMode(dcNew, TRANSPARENT);
	}

	HBRUSH hBrush;
	if (m_nFillStyle == 0)
	{
		hBrush = (HBRUSH)::CreateSolidBrush(TranslateColor(m_ocFillColor, NULL));
	}
	else
	{
		hBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(dcNew, hBrush);

	::Ellipse(dcNew, nLeft, nTop, nRight, nBottom);

	::SelectObject(dcNew, hOldBrush);
	if (m_nFillStyle == 0)
	{
		::DeleteObject(hBrush);
	}

	::SelectObject(dcNew, hOldPen);
	::DeleteObject(hPen);

	::SelectObject(dcNew, cOldBitmap);
	::DeleteDC(dcNew);

	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

float CS309PictureBox::CommonOptionalFloat(const VARIANT *vFloat, float flInit)
{
	float flReturn = flInit;

	if (V_VT(vFloat) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vFloat), 0, VT_R4) == S_OK)
		{
			flReturn = varTemp.fltVal;
		}
		::VariantClear(&varTemp);
	}
	return flReturn;
} 

long CS309PictureBox::CommonOptionalLong(const VARIANT *vLong, long nInit)
{
	long nReturn = nInit;

	if (V_VT(vLong) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vLong), 0, VT_I4) == S_OK)
		{
			nReturn = varTemp.lVal;
		}
		::VariantClear(&varTemp);
	}
	return nReturn;
} 

bool CS309PictureBox::CommonOptionalBool(const VARIANT *vBool, bool bInit)
{
	bool bReturn = bInit;

	if (V_VT(vBool) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vBool), 0, VT_BOOL) == S_OK)
		{
			if (varTemp.boolVal == VARIANT_TRUE)
			{
				bReturn = true;
			}
			else
			{
				bReturn = false;
			}
		}
		::VariantClear(&varTemp);
	}
	return bReturn;
} 

void CS309PictureBox::MethodDrawLine(long nFromX, long nFromY, long nToX, long nToY, const VARIANT FAR& vocColor, const VARIANT FAR& vBox, const VARIANT FAR& vFill) 
{
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	bool bBox = CommonOptionalBool(&vBox, false);
	bool bFill = CommonOptionalBool(&vFill, false);

	if (bBox)
	{
		short nFillStyle = m_nFillStyle;
		if (bFill)
		{
			nFillStyle = 0;
		}
		CommonDrawRoundRect(nFromX, nFromY, nToX, nToY, 0, 0, ocColor, nFillStyle);
	}
	else
	{
		POINT pPoint[5];
		int nPoints;
		BOOL bBox = false;
		BOOL bFill = false;

		if (m_hBitmap == NULL)
		{
			m_hBitmap = CommonGetBitmapControlSize();
		}

		HDC dcNew = ::CreateCompatibleDC(NULL);
		HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

		HPEN hPen;
		if (m_nDrawWidth < 2)
		{
			switch (m_nPenStyle)
			{
				case 0:
					hPen = (HPEN)::CreatePen(PS_NULL, m_nDrawWidth, TranslateColor(ocColor, NULL));
					break;
				case 2:
					hPen = (HPEN)::CreatePen(PS_DASH, m_nDrawWidth, TranslateColor(ocColor, NULL));
					break;
				default:
				case 1:
					hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
					break;
			}
		}
		else
		{
			hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
		}
		HPEN hOldPen = (HPEN)::SelectObject(dcNew, hPen);
		if (m_nPenFillStyle == 0)
		{
			SetBkMode(dcNew, OPAQUE);
			SetBkColor(dcNew, TranslateColor(GetBackColor(),NULL));
		}
		else
		{
			SetBkMode(dcNew, TRANSPARENT);
		}

		if (bBox)
		{
			HBRUSH hBrush;
			if (bFill)
			{
				hBrush = (HBRUSH)::CreateSolidBrush(TranslateColor(m_ocFillColor, NULL));
			}
			else
			{
				hBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
			}
			HBRUSH hOldBrush = (HBRUSH)::SelectObject(dcNew, hBrush);

			::Rectangle(dcNew, nFromX, nFromY, nToX, nToY);

			::SelectObject(dcNew, hOldBrush);
			if (bFill)
			{
				::DeleteObject(hBrush);
			}
		}
		else
		{
			pPoint[0].x = nFromX;
			pPoint[0].y = nFromY;
			pPoint[1].x = nToX;
			pPoint[1].y = nToY;
			nPoints = 2;

			::Polyline(dcNew, pPoint, nPoints);
		}

		::SelectObject(dcNew, hOldPen);
		::DeleteObject(hPen);

		::SelectObject(dcNew, cOldBitmap);
		::DeleteDC(dcNew);

		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
}

void CS309PictureBox::CommonDrawRoundRect(long nLeft, long nTop, long nRight, long nBottom, long nWidth, long nHeight, OLE_COLOR ocColor, short nFillStyle)
{
	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	HDC dcNew = ::CreateCompatibleDC(NULL);
	HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

	HPEN hPen;
	if (m_nDrawWidth < 2)
	{
		switch (m_nPenStyle)
		{
			case 0:
				hPen = (HPEN)::CreatePen(PS_NULL, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
			case 2:
				hPen = (HPEN)::CreatePen(PS_DASH, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
			default:
			case 1:
				hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
				break;
		}
	}
	else
	{
		hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
	}
	HPEN hOldPen = (HPEN)::SelectObject(dcNew, hPen);
	if (m_nPenFillStyle == 0)
	{
		SetBkMode(dcNew, OPAQUE);
		SetBkColor(dcNew, TranslateColor(GetBackColor(),NULL));
	}
	else
	{
		SetBkMode(dcNew, TRANSPARENT);
	}

	HBRUSH hBrush;
	if (nFillStyle == 0)
	{
		hBrush = (HBRUSH)::CreateSolidBrush(TranslateColor(m_ocFillColor, NULL));
	}
	else
	{
		hBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(dcNew, hBrush);

	::RoundRect(dcNew, nLeft, nTop, nRight, nBottom, nWidth, nHeight);

	::SelectObject(dcNew, hOldBrush);
	if (m_nFillStyle == 0)
	{
		::DeleteObject(hBrush);
	}

	::SelectObject(dcNew, hOldPen);
	::DeleteObject(hPen);

	::SelectObject(dcNew, cOldBitmap);
	::DeleteDC(dcNew);

	if (!CommonCheckAutoSize(false))
	{
		InvalidateControl(NULL);
	}
}

void CS309PictureBox::MethodDrawPoint(long nX, long nY, const VARIANT FAR& vocColor) 
{
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	CommonDrawPoint(nX, nY, ocColor);
}

void CS309PictureBox::MethodDrawPolygon(short nPoints, const VARIANT FAR& vocColor) 
{
	if ((nPoints < 2) || (nPoints > 20))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

		if (m_hBitmap == NULL)
		{
			m_hBitmap = CommonGetBitmapControlSize();
		}

		HDC dcNew = ::CreateCompatibleDC(NULL);
		HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

		HPEN hPen;
		if (m_nDrawWidth < 2)
		{
			switch (m_nPenStyle)
			{
				case 0:
					hPen = (HPEN)::CreatePen(PS_NULL, m_nDrawWidth, TranslateColor(ocColor, NULL));
					break;
				case 2:
					hPen = (HPEN)::CreatePen(PS_DASH, m_nDrawWidth, TranslateColor(ocColor, NULL));
					break;
				default:
				case 1:
					hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
					break;
			}
		}
		else
		{
			hPen = (HPEN)::CreatePen(PS_SOLID, m_nDrawWidth, TranslateColor(ocColor, NULL));
		}
		HPEN hOldPen = (HPEN)::SelectObject(dcNew, hPen);
		if (m_nPenFillStyle == 0)
		{
			SetBkMode(dcNew, OPAQUE);
			SetBkColor(dcNew, TranslateColor(GetBackColor(),NULL));
		}
		else
		{
			SetBkMode(dcNew, TRANSPARENT);
		}

		HBRUSH hBrush;
		if (m_nFillStyle == 0)
		{
			hBrush = (HBRUSH)::CreateSolidBrush(TranslateColor(m_ocFillColor, NULL));
		}
		else
		{
			hBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
		}
		HBRUSH hOldBrush = (HBRUSH)::SelectObject(dcNew, hBrush);

		::Polygon(dcNew, m_ptPoint, nPoints);

		::SelectObject(dcNew, hOldBrush);
		if (m_nFillStyle == 0)
		{
			::DeleteObject(hBrush);
		}

		::SelectObject(dcNew, hOldPen);
		::DeleteObject(hPen);

		::SelectObject(dcNew, cOldBitmap);
		::DeleteDC(dcNew);

		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
}

void CS309PictureBox::CommonDrawPoint(long nX, long nY, OLE_COLOR ocColor)
{
	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	HDC dcNew = ::CreateCompatibleDC(NULL);
	HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);
	::SetPixel(dcNew, nX, nY, TranslateColor(ocColor, NULL));
	::SelectObject(dcNew, cOldBitmap);
	::DeleteDC(dcNew);
}

void CS309PictureBox::MethodDrawRoundRect(long nLeft, long nTop, long nRight, long nBottom, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, const VARIANT FAR& vocColor) 
{
	long nWidth = CommonOptionalLong(&vnWidth, 0);
	long nHeight = CommonOptionalLong(&vnHeight, 0);
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	CommonDrawRoundRect(nLeft, nTop, nRight, nBottom, nWidth, nHeight, ocColor, m_nFillStyle);
}

void CS309PictureBox::MethodDrawPolyLines(short nPoints, const VARIANT FAR& vocColor) 
{
	if ((nPoints < 2) || (nPoints > 20))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());
	
		CommonDrawPolyLines(m_ptPoint, nPoints, ocColor);
	}
}

long CS309PictureBox::MethodTextWidth(LPCTSTR szText) 
{
	return CommonDrawText(1, 0, 0, szText, GetForeColor());
}

long CS309PictureBox::MethodTextHeight(LPCTSTR szText) 
{
	return CommonDrawText(2, 0, 0, szText, GetForeColor());
}

void CS309PictureBox::MethodDrawText(LPCTSTR szText, const VARIANT FAR& vnX, const VARIANT FAR& vnY, const VARIANT FAR& vocColor) 
{
	long nX = CommonOptionalLong(&vnX, 0);
	long nY = CommonOptionalLong(&vnY, m_nDrawTextCurrentY);
	long nCurrentY;
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	nCurrentY = CommonDrawText(3, nX, nY, szText, ocColor);

	if (IsMissing(&vnX) && IsMissing(&vnY))
	{
		m_nDrawTextCurrentY = nCurrentY;
	}
}

long CS309PictureBox::CommonDrawText(int nType, long nX, long nY, LPCTSTR szText, OLE_COLOR ocColor)
{
	long nReturn = 0;
//#if UNDER_CE
	if (m_hBitmap == NULL)
	{
		m_hBitmap = CommonGetBitmapControlSize();
	}

	HDC dcNew = ::CreateCompatibleDC(NULL);
	HBITMAP cOldBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);
	HFONT hOldFont = NULL;

	CommonCreateFont();

	if (m_hFont != NULL)
	{
		hOldFont = (HFONT)::SelectObject(dcNew, m_hFont);
	}

	RECT Rect;
	BITMAP Bitmap;

	::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);

	switch (nType)
	{
		case 1:
		case 2:
			Rect.top = 0;
			Rect.left = 0;
			Rect.bottom = Bitmap.bmHeight;
			Rect.right = Bitmap.bmWidth;
			break;

		case 3:
			Rect.top = nY;
			Rect.left = nX;
			Rect.bottom = Bitmap.bmHeight - Rect.top;
			Rect.right = Bitmap.bmWidth - Rect.left;

			if (m_bFontTransparent)
				::SetBkMode(dcNew, TRANSPARENT);
			else
				::SetBkMode(dcNew, OPAQUE);

			::SetBkColor(dcNew, TranslateColor(GetBackColor(),NULL));
			::SetTextColor(dcNew, TranslateColor(ocColor,NULL));
			break;

		default:
			break;
	}

	::DrawText(dcNew,szText, -1, &Rect, DT_CALCRECT);

	switch (nType)
	{
		case 1:
			nReturn = Rect.right - Rect.left;
			break;

		case 2:
			nReturn = Rect.bottom - Rect.top;
			break;

		case 3:
			nReturn = Rect.bottom;

			::DrawText(dcNew,szText, -1, &Rect, 0);
			
			if (!CommonCheckAutoSize(false))
			{
				InvalidateControl(NULL);
			}

		default:
			break;
	}

	::SelectObject(dcNew, cOldBitmap);

	if (hOldFont != NULL)
	{
		::SelectObject(dcNew, hOldFont);
		hOldFont = NULL;
	}

	::DeleteDC(dcNew);

//#endif
	return nReturn;
}

void CS309PictureBox::CommonLoadImage(HBITMAP *hBitmap, bool *bCopiedPassed)
{
	HBITMAP hLoadBitmap = *hBitmap;
	bool bCopied = *bCopiedPassed;

	if (m_strPicture.GetLength() > 0)
	{
#ifndef UNDER_CE
		hLoadBitmap = (HBITMAP)::LoadImage(NULL, m_strPicture, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
#else
		DecompressImageInfo dii;
		HRESULT hr;
		HANDLE hFile = INVALID_HANDLE_VALUE;

		hFile = CreateFile(m_strPicture,GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		
		if (hFile != INVALID_HANDLE_VALUE)
		{
			DWORD dwFileLen = GetFileSize(hFile, NULL);
			DWORD dwBufferSize;
			DWORD dwCurrentBuffer = 0;
			WORD nBitDepth;
			long nMaxWidth;
			long nMaxHeight;
			bool bGif = false;
			bool bBitmap = false;
			bool bJpeg = false;

			nMaxWidth = m_nImageLoadMaxWidth;
			nMaxHeight = m_nImageLoadMaxHeight;
			nBitDepth = m_nImageLoadBitsPerPixel;

			if (m_nImageLoadBufferSize < 1)
			{
				dwBufferSize = dwFileLen;
			}
			else
			{
				dwBufferSize = m_nImageLoadBufferSize;
			}

			LPBYTE szBuffer = new BYTE[dwBufferSize];
			
			if (NULL == szBuffer)
			{
				CloseHandle(hFile);
				return;
			}
			
			ReadFile(hFile, szBuffer, dwBufferSize, &dwCurrentBuffer, NULL);

			if (dwBufferSize >= dwFileLen)
			{
				if ((szBuffer[0] == 'B') && (szBuffer[1] == 'M'))
				{
					bBitmap = true;
					if (m_nImageLoadBufferSize > -1)
					{
//							TCHAR msg[100];
						LPBITMAPFILEHEADER hdr;
						BITMAPINFOHEADER bi;
						hdr = (LPBITMAPFILEHEADER)&szBuffer[0];
						memcpy(&bi,&szBuffer[sizeof(BITMAPFILEHEADER)],sizeof(BITMAPINFOHEADER));
						if (hdr->bfSize == dwFileLen)
						{
							nMaxHeight = bi.biHeight;
							nMaxWidth = bi.biWidth;
							nBitDepth = bi.biBitCount;
						}
						else
						{
							nMaxHeight = SwapEndian(bi.biHeight);
							nMaxWidth = SwapEndian(bi.biWidth);
							nBitDepth = (WORD)SwapEndian(bi.biBitCount);
						}
//							swprintf(msg, _T("height %d width %d bpp %d\0"),nMaxHeight, nMaxWidth, nBitDepth);
//							MessageBox(msg,_T(""),MB_OK);
					}
				}

				if ((szBuffer[0] == 'G') && (szBuffer[1] == 'I') && (szBuffer[2] == 'F'))
				{
					bGif = true;
					if (m_nImageLoadBufferSize > -1)
					{
						DWORD ptr = 6;
						nMaxWidth = (WORD)szBuffer[ptr] + ((WORD)szBuffer[ptr + 1] * 256);
						nMaxHeight = (WORD)szBuffer[ptr + 2]  + ((WORD)szBuffer[ptr + 3] * 256);
						nBitDepth = abs((((char)(szBuffer[ptr + 4]) & 0x70) >> 4)) + 1;
//						nBitDepth = 24;
					}
				}

				if ((szBuffer[0] == 0xff) && (szBuffer[1] == 0xd8) && (szBuffer[2] == 0xff) && (szBuffer[3] == 0xe0))
				{
					bJpeg = true;
					if (m_nImageLoadBufferSize > -1)
					{
						DWORD nSegment = 2;
						DWORD nLength;
						
						nLength = (szBuffer[nSegment + 2] * 256) + szBuffer[nSegment + 3];
						if (memcmp(&szBuffer[nSegment + 4],"JFIF\0",5) == 0)
						{
							nSegment += nLength + 2;
							while (nSegment < dwBufferSize)
							{
								if ((szBuffer[nSegment] == 0xff) && (szBuffer[nSegment + 1] == 0xc0))
								{
									if (m_bUseJPEGBitsPerPixel)
									{
										nBitDepth = szBuffer[nSegment + 4];
									}
									nMaxHeight = (szBuffer[nSegment + 5] * 256) + szBuffer[nSegment + 6];
									nMaxWidth = (szBuffer[nSegment + 7] * 256) + szBuffer[nSegment + 8];
									break;
								}
								if ((szBuffer[nSegment] == 0xff) && (szBuffer[nSegment + 1] == 0xd9))
								{
									break;
								}
								else
								{
									nLength = (szBuffer[nSegment + 2] * 256) + szBuffer[nSegment + 3];
									nSegment += nLength + 2;
								}
							}
						}
					}
				}
			}

//					OLE_COLOR oc;
//					if (m_bOverlay)
//					{
//						oc = m_ocOverlayTransparentColor;
//					}
//					else
//					{
//						oc = m_ocTransparentColor;
//					}

//					pdc = GetDC(NULL, OLEDC_NODRAW);
			HDC pdc = ::CreateCompatibleDC(NULL);
//			HDC pdc = ::CreateDC(NULL, NULL, NULL, NULL);
//			HBITMAP hTemp1 = CommonGetBitmapClip(NULL,0,0,1,1);
//			HBITMAP hTemp2 = CommonGetBitmapCopyToNewBPP(hTemp1,24);
//			::DeleteObject(hTemp1);
//			HBITMAP hOldBitmap = (HBITMAP)SelectObject(pdc, hTemp2);


			dii.dwSize =  sizeof(DecompressImageInfo);
			dii.pbBuffer = szBuffer;
			dii.dwBufferMax = dwBufferSize;
			dii.dwBufferCurrent = dwCurrentBuffer;
			dii.phBM = &hLoadBitmap;
			dii.ppImageRender = NULL;
//					dii.iBitDepth = pdc->GetDeviceCaps(BITSPIXEL);
			dii.iBitDepth = nBitDepth;
			dii.lParam = (LPARAM) hFile;
//					dii.hdc = pdc->GetSafeHdc();
			dii.hdc = pdc;
			dii.iScale = m_nImageLoadScalePercent;
			dii.iMaxWidth = nMaxWidth;
			dii.iMaxHeight = nMaxHeight;
			dii.pfnGetData = CallbackGetImageData;
			dii.pfnImageProgress = NULL;
//					if ((m_ocTransparentColor < 16777216) && (bGif))
//					{
//						dii.crTransparentOverride = TranslateColor(m_ocTransparentColor,NULL);
//						if (dii.iBitDepth < 24)
//						{
//							dii.iBitDepth = 24;
//						}
//					}
//					else
//					{
//				dii.crTransparentOverride = m_ocTransparentColor;
				dii.crTransparentOverride = -1;
//					}

			if (m_bWaitCursor)
			{
				BeginWaitCursor();
			}

			hr = DecompressImageIndirect(&dii);

			if (m_bWaitCursor)
			{
				EndWaitCursor();
			}

			CloseHandle(hFile);
			
//					ReleaseDC(pdc);
//			::SelectObject(pdc, hOldBitmap);
//			::DeleteObject(hTemp2);
			::DeleteDC(pdc);

//					if ((hLoadBitmap == NULL) && (bBitmap) && (nBitDepth > 8))
			if ((hLoadBitmap == NULL) && (bBitmap))
			{
				LPBITMAPFILEHEADER hdr;
				LPBITMAPINFO lpbi;
				LPVOID pBits;

				hdr = (LPBITMAPFILEHEADER)&szBuffer[0];
				int lpbiSize = sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * 3);
				lpbi = (LPBITMAPINFO) new BYTE[lpbiSize];
				memcpy(lpbi,&szBuffer[sizeof(BITMAPFILEHEADER)], lpbiSize);
				
				DWORD nOffBits = hdr->bfOffBits;
				DWORD nSize = hdr->bfSize;
				if (nSize != dwFileLen)
				{
					nOffBits = SwapEndian(nOffBits);
					nSize = SwapEndian(nSize);
					lpbi->bmiHeader.biSize = SwapEndian(lpbi->bmiHeader.biSize);
					lpbi->bmiHeader.biWidth = SwapEndian(lpbi->bmiHeader.biWidth);
					lpbi->bmiHeader.biHeight = SwapEndian(lpbi->bmiHeader.biHeight);
					lpbi->bmiHeader.biPlanes = (unsigned short)SwapEndian(lpbi->bmiHeader.biPlanes);
					lpbi->bmiHeader.biBitCount = (unsigned short)SwapEndian(lpbi->bmiHeader.biBitCount);
					lpbi->bmiHeader.biCompression = SwapEndian(lpbi->bmiHeader.biCompression);
					lpbi->bmiHeader.biSizeImage = SwapEndian(lpbi->bmiHeader.biSizeImage);
				}

				if (nSize == 0)
				{
					nSize = dwFileLen;
				}

				if ((lpbi->bmiHeader.biCompression == BI_BITFIELDS) || (lpbi->bmiHeader.biCompression == BI_RGB))
				{
					hLoadBitmap = ::CreateDIBSection(NULL, (BITMAPINFO *)lpbi, DIB_RGB_COLORS, &pBits, NULL, 0);
					if (hLoadBitmap != NULL)
					{
						unsigned char *source;
						source = (unsigned char *)pBits;
						memcpy(source, &szBuffer[hdr->bfOffBits], nSize - nOffBits);
					}
				}
				delete [] lpbi;
			}

			delete [] szBuffer;

//					if ((m_ocTransparentColor == 4294967294) && (bGif))
//					{
//						RGBQUAD rgbQuad;
//						if (CEGetDIBColorTable(hLoadBitmap, nGiftcindex -1, 1, &rgbQuad) != 0)
//						{
//							m_ocTransparentColor = RGB(rgbQuad.rgbRed, rgbQuad.rgbGreen, rgbQuad.rgbBlue);
//						}
//						else
//						{
//							MessageBox(_T("not a dib"),_T(""),0);
//						}
//					}
		}
#endif
	}

	if (m_nResourceID >= 0)
	{
		if (m_hInstance == NULL)
		{
			m_hResourceFile = LoadLibrary(m_strResourceFile);
			m_hInstance = m_hResourceFile;
		}

		if (m_nResourceIconID >= 0)
		{
			HICON hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(m_nResourceID));
			hLoadBitmap = CommonGetBitmapClip(NULL, 0, 0, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON));
			
			HDC destDC = ::CreateCompatibleDC(NULL);

			HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hLoadBitmap);

			::DrawIconEx(destDC, 0, 0, hIcon, 0, 0, 0, NULL, DI_NORMAL);

			::SelectObject(destDC, hbmOldDest);
			::DeleteDC(destDC);
			bCopied = true;
		}
		else
		{
			if (m_hInstance != NULL)
			{
				hLoadBitmap = (HBITMAP)::LoadImage(m_hInstance,MAKEINTRESOURCE(m_nResourceID), IMAGE_BITMAP, 0, 0, 0);
			}
#ifndef UNDER_CE
			BITMAP Bitmap;
			::GetObject(hLoadBitmap, sizeof(Bitmap), &Bitmap);

			if ((m_nPlayingCard > 0) && (Bitmap.bmBitsPixel == 1))
			{
				HBITMAP hNewBitmap = CommonGetBitmapCopyToNewBPP(hLoadBitmap, 24);
				::DeleteObject(hLoadBitmap);
				hLoadBitmap = hNewBitmap;
				bCopied = true;
			}
#endif
		}

	}

	if (m_bWorkingCaptureScreen)
	{
		hLoadBitmap = CommonGetBitmapScreen();
		m_bWorkingCaptureScreen = false;
		bCopied = true;
	}

	if (m_hWorkingBitmap != NULL)
	{
		hLoadBitmap = CommonGetBitmapCopy(m_hWorkingBitmap);
		m_hWorkingBitmap = NULL;
		bCopied = true;
	}

	if (m_hWorkingIconBitmap != NULL)
	{
		hLoadBitmap = CommonGetBitmapCopy(m_hWorkingIconBitmap);
		bCopied = true;
	}
	*hBitmap = hLoadBitmap;
	*bCopiedPassed = bCopied;
}

void CS309PictureBox::MethodDrawPicture(LPCTSTR szName, long nX, long nY, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, const VARIANT FAR& vnX2, const VARIANT FAR& vnY2, const VARIANT FAR& vnWidth2, const VARIANT FAR& vnHeight2, const VARIANT FAR& vnRasterOp) 
{
	HBITMAP hBitmap = NULL;
	BITMAP Bitmap;
	bool bCopied = false;

	CommonClearForLoad();
	m_strPicture = szName;

	CommonLoadImage(&hBitmap, &bCopied);

	if (hBitmap != NULL)
	{
		::GetObject(hBitmap, sizeof(Bitmap), &Bitmap);

		long nWidth = CommonOptionalLong(&vnWidth, Bitmap.bmWidth);
		long nHeight = CommonOptionalLong(&vnHeight, Bitmap.bmHeight);
		long nX2 = CommonOptionalLong(&vnX2, 0);
		long nY2 = CommonOptionalLong(&vnY2, 0);
		long nWidth2 = CommonOptionalLong(&vnWidth2, Bitmap.bmWidth);
		long nHeight2 = CommonOptionalLong(&vnHeight2, Bitmap.bmHeight);
		long nRasterOp = CommonOptionalLong(&vnRasterOp, SRCCOPY);

		if (m_hBitmap == NULL)
		{
			m_hBitmap = CommonGetBitmapControlSize();
		}

		if (((nX + nWidth) > GetImageWidth()) || ((nY + nHeight) > GetImageHeight()))
		{
			HBITMAP hReturnBitmap = CommonGetBitmapClip(m_hBitmap, 0, 0, (nX + nWidth), (nY + nHeight));
			::DeleteObject(m_hBitmap);
			m_hBitmap = hReturnBitmap;
		}

		HDC sourceDC = ::CreateCompatibleDC(NULL);
		HDC destDC = ::CreateCompatibleDC(NULL);

		HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

		HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, m_hBitmap);

		::StretchBlt(destDC, nX, nY, nWidth, nHeight, sourceDC, nX2, nY2, nWidth2, nHeight2, nRasterOp);

		::SelectObject(sourceDC, hbmOldSource);
		::DeleteDC(sourceDC);

		::SelectObject(destDC, hbmOldDest);
		::DeleteDC(destDC);

		::DeleteObject(hBitmap);

		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
}

short CS309PictureBox::GetScrollBars() 
{
	return m_nScrollBars;
}

void CS309PictureBox::SetScrollBars(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 3))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nScrollBars = nNewValue;
		SetModifiedFlag();
		CommonDesignRefresh();
	}
}

void CS309PictureBox::CommonScrollBars()
{
	long nStyle = ::GetWindowLong((HWND)GetHwnd(), GWL_STYLE);
	long nOldStyle = nStyle;

	nStyle &= (0xffffffff ^ (WS_HSCROLL | WS_VSCROLL));

	if ((!m_bAutoSize) && (!m_bStretch) && (m_nCenter == 0) && (m_hBitmap != NULL) && (m_nScrollBars != 0))
	{
		long nBorder = 0;

		if (m_nBorderStyle != 0)
		{
			switch (m_nAppearance)
			{
				case -4:
					nBorder = 10;
					break;
				case 3:
					nBorder = 6;
					break;
				case 0:
				case 4:
					nBorder = 2;
					break;
				default:
					nBorder = 4;
					break;
			}
		}
		
		long nVWidth = 0;
		long nHHeight = 0;
		long nImageWidth = GetImageWidth();
		long nImageHeight = GetImageHeight();
		long nControlWidth = GetWidth() - nBorder;
		long nControlHeight = GetHeight() - nBorder;

		if ((m_nScrollBars == 1) || (m_nScrollBars == 3))
		{
			if (nControlWidth < nImageWidth)
			{
				nHHeight = m_nWorkingHCY;
				nStyle |= WS_HSCROLL;
			}
		}

		if ((m_nScrollBars == 2) || (m_nScrollBars == 3))
		{
			if (nControlHeight < nImageHeight)
			{
				nVWidth = m_nWorkingVCX;
				nStyle |= WS_VSCROLL;
			}
		}

		if (!((((nVWidth == 0) && (nHHeight == 0)) || ((nVWidth != 0) && (nHHeight != 0))) && (m_nScrollBars == 3)))
		{
			if (nHHeight == 0)
			{
				if ((nControlWidth - nVWidth) < nImageWidth)
				{
					nHHeight = m_nWorkingHCY;
					nStyle |= WS_HSCROLL;
				}
			}

			if (nVWidth == 0)
			{
				if ((nControlHeight - nHHeight) < nImageHeight)
				{
					nVWidth = m_nWorkingVCX;
					nStyle |= WS_VSCROLL;
				}
			}
		}

		if (nStyle != nOldStyle)
		{
			::SetWindowLong((HWND)GetHwnd(), GWL_STYLE, nStyle);
			::SetWindowPos((HWND)GetHwnd(), NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
		}

		if ((nStyle & (WS_HSCROLL | WS_VSCROLL)) != 0)
		{
			SCROLLINFO si;

			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
			si.nMin = 0;

			if ((nStyle & WS_HSCROLL) == WS_HSCROLL)
			{
				m_nWorkingHPage = nControlWidth - nVWidth;
				m_nWorkingHMax = nImageWidth;
				m_nWorkingHMin = 0;
				si.nMax = m_nWorkingHMax;
				si.nMin = m_nWorkingHMin;
				si.nPage = m_nWorkingHPage;
				si.nPos = m_nHScrollPosition;
				::SetScrollInfo((HWND)GetHwnd(), SB_HORZ, &si, m_bAutoRefresh);
			}

			if ((nStyle & WS_VSCROLL) == WS_VSCROLL)
			{
				m_nWorkingVPage = nControlHeight - nHHeight;
				m_nWorkingVMax = nImageHeight;
				m_nWorkingVMin = 0;
				si.nMax = m_nWorkingVMax;
				si.nMin = m_nWorkingVMin;
				si.nPage = m_nWorkingVPage;
				si.nPos = m_nVScrollPosition;
				::SetScrollInfo((HWND)GetHwnd(), SB_VERT, &si, m_bAutoRefresh);
			}
		}
	}
	else
	{
		if (nStyle != nOldStyle)
		{
			::SetWindowLong((HWND)GetHwnd(), GWL_STYLE, nStyle);
			::SetWindowPos((HWND)GetHwnd(), NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
		}
	}
}

void CS309PictureBox::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	long nPosition = m_nHScrollPosition;
	long nMove = 0;
	BOOL bRefresh = false;

	switch (nSBCode)
	{
		case SB_LINELEFT:
			nMove = -1;
			break;
		case SB_LINERIGHT:
			nMove = 1;
			break;
		case SB_PAGELEFT:
			nMove = -1 * m_nWorkingHPage;
			break;
		case SB_PAGERIGHT:
			nMove = m_nWorkingHPage;
			break;
		case SB_THUMBPOSITION:
			nPosition = nPos;
			break;
		case SB_THUMBTRACK:
			bRefresh = true;
			nPosition = nPos;
			break;
		case SB_TOP:
			nPosition = m_nWorkingHMin;
			break;
		case SB_BOTTOM:
			nPosition = m_nWorkingHMax;
			break;
		case SB_ENDSCROLL:
			bRefresh = true;
			break;
	}

	FireHScroll(nSBCode, &bRefresh, &nPosition, &nMove, m_nWorkingHMin, m_nWorkingHMax, m_nWorkingHPage, m_nWorkingHCX, m_nWorkingHCY);

	SCROLLINFO si;

	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_POS;
	m_nHScrollPosition = nPosition + nMove;
	if ((m_nHScrollPosition + m_nWorkingHPage) > m_nWorkingHMax)
	{
		m_nHScrollPosition = m_nWorkingHMax - m_nWorkingHPage;
	}

	if (m_nHScrollPosition < 0)
	{
		m_nHScrollPosition = 0;
	}

	si.nPos = m_nHScrollPosition;

	::SetScrollInfo((HWND)GetHwnd(), SB_HORZ, &si, m_bAutoRefresh);

//	COleControl::OnHScroll(nSBCode, nPos, pScrollBar);

	if (bRefresh)
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
}

void CS309PictureBox::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	long nPosition = m_nVScrollPosition;
	long nMove = 0;
	BOOL bRefresh = false;

	switch (nSBCode)
	{
		case SB_LINEUP:
			nMove = -1;
			break;
		case SB_LINEDOWN:
			nMove = 1;
			break;
		case SB_PAGEUP:
			nMove = -1 * m_nWorkingVPage;
			break;
		case SB_PAGEDOWN:
			nMove = m_nWorkingVPage;
			break;
		case SB_THUMBPOSITION:
			nPosition = nPos;
			break;
		case SB_THUMBTRACK:
			nPosition = nPos;
			bRefresh = true;
			break;
		case SB_TOP:
			nPosition = m_nWorkingVMin;
			break;
		case SB_BOTTOM:
			nPosition = m_nWorkingVMax;
			break;
		case SB_ENDSCROLL:
			bRefresh = true;
			break;
	}

	FireVScroll(nSBCode, &bRefresh, &nPosition, &nMove, m_nWorkingVMin, m_nWorkingVMax, m_nWorkingVPage, m_nWorkingVCX, m_nWorkingVCY);

	SCROLLINFO si;

	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_POS;
	m_nVScrollPosition = nPosition + nMove;
	if ((m_nVScrollPosition + m_nWorkingVPage) > m_nWorkingVMax)
	{
		m_nVScrollPosition = m_nWorkingVMax - m_nWorkingVPage;
	}

	if (m_nVScrollPosition < 0)
	{
		m_nVScrollPosition = 0;
	}

	si.nPos = m_nVScrollPosition;

	::SetScrollInfo((HWND)GetHwnd(), SB_VERT, &si, m_bAutoRefresh);

//	COleControl::OnVScroll(nSBCode, nPos, pScrollBar);

	if (bRefresh)
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
}


BOOL CS309PictureBox::OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray) 
{
	BOOL bReturn = false;
#ifndef UNDER_CE
	CString strValue;
	DWORD dwCookie;
	switch (dispid)
	{
		case dispidAppearance:
			for (dwCookie = 0; dwCookie < 9; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidBorderStyle:
			for (dwCookie = 0; dwCookie < 2; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidCenter:
			for (dwCookie = 0; dwCookie < 4; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidCommonBitmapID:
//			bReturn = true;
			break;
		case dispidCommonBitmapType:
			for (dwCookie = 0; dwCookie < 5; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidFillStyle:
			for (dwCookie = 0; dwCookie < 2; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidMirror:
			for (dwCookie = 0; dwCookie < 4; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidMouseMovePoints:
			for (dwCookie = 0; dwCookie < 3; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidPenFillStyle:
			for (dwCookie = 0; dwCookie < 2; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidPenStyle:
			for (dwCookie = 0; dwCookie < 3; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidPlayingCard:
			break;
		case dispidRotate:
			for (dwCookie = 0; dwCookie < 360; dwCookie += 90)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidWildCard:
			for (dwCookie = 0; dwCookie < 4; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
		case dispidScrollBars:
			for (dwCookie = 0; dwCookie < 4; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = true;
				}
			}
			break;
	}
#endif

	if (!bReturn)
	{
		bReturn = COleControl::OnGetPredefinedStrings(dispid, pStringArray, pCookieArray);
	}

	return bReturn;
}

BOOL CS309PictureBox::OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut) 
{
	BOOL bReturn = false;
#ifndef UNDER_CE
	long nVal = dwCookie;
	switch (dispid)
	{
		case dispidBorderStyle:
		case dispidCenter:
//		case dispidCommonBitmapID:
		case dispidFillStyle:
		case dispidMirror:
		case dispidMouseMovePoints:
		case dispidPenFillStyle:
		case dispidPenStyle:
		case dispidPlayingCard:
		case dispidRotate:
		case dispidScrollBars:
		case dispidWildCard:
			lpvarOut->vt = VT_I4;
			lpvarOut->lVal = dwCookie;
			bReturn = true;
			break;
		case dispidAppearance:
			nVal -= 4;
			lpvarOut->vt = VT_I4;
			lpvarOut->lVal = nVal;
			bReturn = true;
			break;
		case dispidCommonBitmapType:
			nVal -= 2;
			lpvarOut->vt = VT_I4;
			lpvarOut->lVal = nVal;
			bReturn = true;
			break;
	}
#endif
	if (!bReturn)
	{
		bReturn = COleControl::OnGetPredefinedValue(dispid, dwCookie, lpvarOut);
	}

	return bReturn;
}

BOOL CS309PictureBox::OnGetDisplayString(DISPID dispid, CString& strValue) 
{
	BOOL bReturn = false;
#ifndef UNDER_CE
	switch (dispid)
	{
		case dispidAppearance:
			if (CommonGetDisplayString(dispid, strValue, m_nAppearance + 4))
			{
				bReturn = true;
			}
			break;
		case dispidBorderStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nBorderStyle))
			{
				bReturn = true;
			}
			break;
		case dispidCenter:
			if (CommonGetDisplayString(dispid, strValue, m_nCenter))
			{
				bReturn = true;
			}
			break;
		case dispidCommonBitmapID:
//			bReturn = true;
			break;
		case dispidCommonBitmapType:
			if (CommonGetDisplayString(dispid, strValue, m_nCommonBitmapType + 2))
			{
				bReturn = true;
			}
			break;
		case dispidFillStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nFillStyle))
			{
				bReturn = true;
			}
			break;
		case dispidMirror:
			if (CommonGetDisplayString(dispid, strValue, m_nMirror))
			{
				bReturn = true;
			}
			break;
		case dispidMouseMovePoints:
			if (CommonGetDisplayString(dispid, strValue, m_nMouseMovePoints))
			{
				bReturn = true;
			}
			break;
		case dispidPenFillStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nPenFillStyle))
			{
				bReturn = true;
			}
			break;
		case dispidPenStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nPenStyle))
			{
				bReturn = true;
			}
			break;
		case dispidPlayingCard:
			break;
		case dispidRotate:
			if (CommonGetDisplayString(dispid, strValue, m_nRotate))
			{
				bReturn = true;
			}
			break;
		case dispidWildCard:
			if (CommonGetDisplayString(dispid, strValue, m_nWildCard))
			{
				bReturn = true;
			}
			break;
		case dispidScrollBars:
			if (CommonGetDisplayString(dispid, strValue, m_nScrollBars))
			{
				bReturn = true;
			}
			break;
	}
#endif

	if (!bReturn)
	{
		bReturn = COleControl::OnGetDisplayString(dispid, strValue);
	}

	return bReturn;
}

BOOL CS309PictureBox::CommonGetDisplayString(DISPID dispid, CString &strValue, DWORD dwCookie)
{
	BOOL bReturn = false;
	strValue.Empty();
#ifndef UNDER_CE
	switch (dispid)
	{
		case dispidAppearance:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("-4 - 3D Sunken Border Frame (ScrollBars)");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("-3 - 3D Sunken Border (ScrollBars)");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("-2 - 3D Sunken Border (Tiles)");
					bReturn = true;
					break;
				case 3:
					strValue = TEXT("-1 - 3D Sunken Border (Soft)");
					bReturn = true;
					break;
				case 4:
					strValue = TEXT("0 - Single Line Border");
					bReturn = true;
					break;
				case 5:
					strValue = TEXT("1 - 3D Raised Border (Soft)");
					bReturn = true;
					break;
				case 6:
					strValue = TEXT("2 - 3D Raised Border (Tiles)");
					bReturn = true;
					break;
				case 7:
					strValue = TEXT("3 - 3D Raised Border (ScrollBars)");
					bReturn = true;
					break;
				case 8:
					strValue = TEXT("4 - Single Line Border (ScrollBars)");
					bReturn = true;
					break;
			}
			break;
		case dispidBorderStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Border");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Has Border");
					bReturn = true;
					break;
			}
			break;
		case dispidCenter:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Do Not Center");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Center Horizontally");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("2 - Center Vertically");
					bReturn = true;
					break;
				case 3:
					strValue = TEXT("3 - Center Both");
					bReturn = true;
					break;
			}
			break;
		case dispidCommonBitmapID:
//			bReturn = true;
			break;
		case dispidCommonBitmapType:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("-2 - Disabled View Bitmaps");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("-1 - Disabled Standard Bitmaps");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("0 - No Bitmap");
					bReturn = true;
					break;
				case 3:
					strValue = TEXT("1 - Enabled Standard Bitmaps");
					bReturn = true;
					break;
				case 4:
					strValue = TEXT("2 - Enabled View Bitmaps");
					bReturn = true;
					break;
			}
			break;
		case dispidFillStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Solid");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Transparent");
					bReturn = true;
					break;
			}
			break;
		case dispidMirror:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Do Not Mirror");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Mirror Horizontally");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("2 - Mirror Vertically");
					bReturn = true;
					break;
				case 3:
					strValue = TEXT("3 - Mirror Both");
					bReturn = true;
					break;
			}
			break;
		case dispidMouseMovePoints:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Mouse Move Points");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Send Through MouseDown");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("2 - Make Available");
					bReturn = true;
					break;
			}
			break;
		case dispidPenFillStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Solid");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Transparent");
					bReturn = true;
					break;
			}
			break;
		case dispidPenStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Line");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Solid Line");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("2 - Dashed Line");
					bReturn = true;
					break;
			}
			break;
		case dispidPlayingCard:
			break;
		case dispidRotate:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Rotation");
					bReturn = true;
					break;
				case 90:
					strValue = TEXT("90 - Rotate 90 Degrees");
					bReturn = true;
					break;
				case 180:
					strValue = TEXT("180 - Rotate 180 Degrees");
					bReturn = true;
					break;
				case 270:
					strValue = TEXT("270 - Rotate 270 Degrees");
					bReturn = true;
					break;
			}
			break;
		case dispidWildCard:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Indicator");
					bReturn = true;
					break;
				case 1:
					strValue = TEXT("1 - Horizontal Indicators");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("2 - Vertical Indicators");
					bReturn = true;
					break;
				case 3:
					strValue = TEXT("3 - Center Indicator");
					bReturn = true;
					break;
			}
			break;
		case dispidScrollBars:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Scroll Bars");
					bReturn = true;
					break;
				case 1: 
					strValue = TEXT("1 - Horizontal Scroll Bar");
					bReturn = true;
					break;
				case 2:
					strValue = TEXT("2 - Vertical Scroll Bar");
					bReturn = true;
					break;
				case 3:
					strValue = TEXT("3 - Both Scroll Bars");
					bReturn = true;

					break;
			}
			break;
	}
#endif

	return bReturn;
}


bool CS309PictureBox::IsAmbientUserModeImplemented(BOOL *pbUserMode, bool bInit)
{
	if (!GetAmbientProperty(DISPID_AMBIENT_USERMODE, VT_BOOL, pbUserMode))
	{
		if (bInit)
		{
			*pbUserMode = true;
		}
		return false;
	}
	else
		return true;
}
BOOL CS309PictureBox::IsAmbientDisplayNameImplemented(CString *pDisplayName, bool bInit)
{
	return GetAmbientProperty(DISPID_AMBIENT_DISPLAYNAME, VT_BSTR, pDisplayName);
}

void CS309PictureBox::CommonDesignRefresh()
{
	if (!AmbientUserMode())
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
}

long CS309PictureBox::GetHScrollPosition() 
{
	return m_nHScrollPosition;
}

void CS309PictureBox::SetHScrollPosition(long nNewValue) 
{
	SCROLLINFO si;

	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_POS;

	m_nHScrollPosition = nNewValue;

	if ((m_nHScrollPosition + m_nWorkingHPage) > m_nWorkingHMax)
	{
		m_nHScrollPosition = m_nWorkingHMax - m_nWorkingHPage;
	}

	if (m_nHScrollPosition < 0)
	{
		m_nHScrollPosition = 0;
	}

	si.nPos = m_nHScrollPosition;

	::SetScrollInfo((HWND)GetHwnd(), SB_HORZ, &si, m_bAutoRefresh);
}

long CS309PictureBox::GetVScrollPosition() 
{
	return m_nVScrollPosition;
}

void CS309PictureBox::SetVScrollPosition(long nNewValue) 
{
	SCROLLINFO si;

	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_POS;
	m_nVScrollPosition = nNewValue;

	if ((m_nVScrollPosition + m_nWorkingVPage) > m_nWorkingVMax)
	{
		m_nVScrollPosition = m_nWorkingVMax - m_nWorkingVPage;
	}

	if (m_nVScrollPosition < 0)
	{
		m_nVScrollPosition = 0;
	}

	si.nPos = m_nVScrollPosition;

	::SetScrollInfo((HWND)GetHwnd(), SB_VERT, &si, m_bAutoRefresh);
}

bool CS309PictureBox::IsMissing(const VARIANT *var)
{
	bool bReturn = false;
	if (V_VT(var) == VT_ERROR)
	{
		bReturn = true;
	}
	return bReturn;
}


#ifdef S309_MR_MOUSE
void CS309PictureBox::OnMButtonDown(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
	CommonFireMouse(0, nButtons, nKeys, point.x, point.y);
	CommonFireMousePoints(nButtons, nKeys);
	COleControl::OnMButtonDown(nFlags, point);
}

void CS309PictureBox::OnMButtonUp(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
	CommonFireMousePoints(nButtons, nKeys);
	CommonFireMouse(2, nButtons, nKeys, point.x, point.y);
	COleControl::OnMButtonUp(nFlags, point);
}

void CS309PictureBox::OnRButtonDown(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
	CommonFireMouse(0, nButtons, nKeys, point.x, point.y);
	CommonFireMousePoints(nButtons, nKeys);
	COleControl::OnRButtonDown(nFlags, point);
}

void CS309PictureBox::OnRButtonUp(UINT nFlags, CPoint point) 
{
	short nButtons = CommonFireMouseButtons(nFlags);
	short nKeys = CommonFireMouseKeys(nFlags);
	CommonFireMousePoints(nButtons, nKeys);
	CommonFireMouse(2, nButtons, nKeys, point.x, point.y);
	COleControl::OnRButtonUp(nFlags, point);
}
#endif

BOOL CS309PictureBox::GetOnToolbar() 
{
	return m_bOnToolbar;
}

void CS309PictureBox::SetOnToolbar(BOOL bNewValue) 
{
	if (!m_bVBCE)
	{
		if (bNewValue)
		{
			if (!m_bOnToolbar)
			{
				HWND hWnd = (HWND)GetHwnd();
				HWND hWndParent = ::GetParent(hWnd);
				HWND hWndGrand = ::GetParent(hWndParent);
				POINT ptPoint;
#if _WIN32_WCE < 300
				ptPoint.x = 0;
				ptPoint.y = 0;
				HWND hWndToolbar = ::ChildWindowFromPoint(hWndGrand, ptPoint);
#else // _WIN32_WCE < 300
				ptPoint.x = 0;
				ptPoint.y = GetScreenHeight() - 1;
				HWND hWndToolbar = ::WindowFromPoint(ptPoint);
#endif // _WIN32_WCE < 300
				if (hWndToolbar != NULL)
				{
					m_hParentWindow = ::SetParent(hWnd, hWndToolbar);
					if (m_hParentWindow != NULL)
					{
						if (m_hParentWindow != hWndParent)
						{
//							AfxMessageBox(TEXT("Not Equal"),0,0);
						}
						m_bOnToolbar = true;
					}
					else
					{
//						AfxMessageBox(TEXT("parent null"),0,0);
					}
				}
				else
				{
//					AfxMessageBox(TEXT("toolbar null"),0,0);
				}
			}
		}
		else
		{
			if (m_bOnToolbar)
			{
				if (m_hParentWindow != NULL)
				{
					HWND hWnd = (HWND)GetHwnd();
					::SetParent(hWnd, m_hParentWindow);
					m_hParentWindow = NULL;
					m_bOnToolbar = false;
					SetWindowPos( &wndTop, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE );
				}
			}
		}
	}
}

void CS309PictureBox::OnTextChanged() 
{
	COleControl::OnTextChanged();
	if ((!m_bVBCE) && (!m_bHaveName))
	{
		m_bHaveName = true;
		if (m_strName.CompareNoCase(TEXT("S309PictureBox")) == 0)
		{
			m_strName = GetText();
			SetText(TEXT(""));
		}
	}
}

#ifdef S309_MR_MOUSE
BOOL CS309PictureBox::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
#ifdef UNDER_CE
	if (m_bHasMousePointer)
	{
		BeginWaitCursor();
		EndWaitCursor();
		m_bHasMousePointer = false;
	}
#endif
	return COleControl::OnSetCursor(pWnd, nHitTest, message);
}
#endif

long CS309PictureBox::GetResourceIconID() 
{
	return m_nResourceIconID;
}

void CS309PictureBox::SetResourceIconID(long nNewValue) 
{
	CString strResourceFile;

	strResourceFile = m_strResourceFile;
	CommonClearForLoad();
	m_strResourceFile = strResourceFile;

	m_nResourceIconID = nNewValue;
	m_nResourceID = m_nResourceIconID;
	SetModifiedFlag();

	m_bDisplayExpired = true;
	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

BOOL CS309PictureBox::GetUseJPEGBitsPerPixel() 
{
	return m_bUseJPEGBitsPerPixel;
}

void CS309PictureBox::SetUseJPEGBitsPerPixel(BOOL bNewValue) 
{
	m_bUseJPEGBitsPerPixel = bNewValue;
	SetModifiedFlag();
}

BOOL CS309PictureBox::MethodDrawIcon(LPCTSTR szFile, const VARIANT FAR& vIconID, const VARIANT FAR& vLarge, const VARIANT FAR& vocColor, const VARIANT FAR& vDrawType) 
{
	BOOL bReturn = false;

	OLE_COLOR ocColor = GetBackColor();
	if (m_bOverlay)
	{
		if (m_ocOverlayTransparentColor < 16777216)
		{
			ocColor = m_ocOverlayTransparentColor;
		}
	}
	else
	{
		if (m_ocTransparentColor < 16777216)
		{
			ocColor = m_ocTransparentColor;
		}
	}

	ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor,(long)ocColor);

	bool bLarge = CommonOptionalBool(&vLarge, false);
	long nIconID = CommonOptionalLong(&vIconID, 0);
	long nDrawType = CommonOptionalLong(&vDrawType, DI_NORMAL);
	short x = 0;
	short y = 0;

	HICON hLarge = NULL;
	HICON hSmall = NULL;
	HICON hIcon = NULL;

#ifdef UNDER_CE
#if _WIN32_WCE > 210 
	if (nIconID > 0)
	{
		nIconID = nIconID * -1;
	}
#ifdef WIN32_PLATFORM_PSPC
	HICON hxIcon = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
#else // WIN32_PLATFORM_PSPC
#if _WIN32_WCE < 212
	UINT nIcons = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
#else // _WIN32_WCE < 212
	HICON hxIcon = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
#endif // _WIN32_WCE < 212
#endif // WIN32_PLATFORM_PSPC
#else // _WIN32_WCE > 210
	UINT nIcons = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
#endif //  _WIN32_WCE > 210
#else // UNDER_CE
	UINT nIcons = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
#endif // UNDER_CE

	if (bLarge)
	{
		hIcon = hLarge;
		x = GetSystemMetrics(SM_CXICON);
		y = GetSystemMetrics(SM_CYICON);
		if (hSmall != NULL)
		{
			::DestroyIcon(hSmall);
		}
	}
	else
	{
		hIcon = hSmall;
		x = GetSystemMetrics(SM_CXSMICON);
		y = GetSystemMetrics(SM_CYSMICON);
		if (hLarge != NULL)
		{
			::DestroyIcon(hLarge);
		}
	}

	if (hIcon != NULL)
	{
		CommonClearForLoad();

		OLE_COLOR oc;
		oc = m_ocFillColor;

		m_ocFillColor = ocColor;

		m_hWorkingIconBitmap = CommonGetBitmapClip(NULL, 0, 0, x, y);

		m_ocFillColor = oc;
			
		HDC destDC = ::CreateCompatibleDC(NULL);

		HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, m_hWorkingIconBitmap);

		::DrawIconEx(destDC, 0, 0, hIcon, x, y, 0, NULL, nDrawType);

		::SelectObject(destDC, hbmOldDest);
		::DeleteDC(destDC);

		::DestroyIcon(hIcon);

		m_bDisplayExpired = true;
		if (!CommonLoadImageIntoBitmap())
		{
			InvalidateControl(NULL);
		}

		::DeleteObject(m_hWorkingIconBitmap);
		m_hWorkingIconBitmap = NULL;

		bReturn = true;
	}

	return bReturn;
}
