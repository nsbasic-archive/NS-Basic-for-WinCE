// NSCEPictureBoxCtl.cpp : Implementation of the CNSCEPictureBoxCtrl ActiveX Control class.

#include "stdafx.h"
#include "winuser.h"
#include "math.h"

#ifndef UNDER_CE
	#include <comdef.h>
	#include "file_ver.h"	// CFileVersionInfo
#else // UNDER_CE
#ifndef WCE_PLATFORM_STANDARDSDK
	#define VS_VERSION_INFO         1
//	#undef VER_H
//	#include <winver.h>
#endif // WCE_PLATFORM_STANDARDSDK
	#include "res.h"        // Ce....
	#include "imgdecmp.h"
	typedef HRESULT (__stdcall *DecompressImageIndirectProc)(DecompressImageInfo *);
#endif // UNDER_CE

#include "pegcards.h"
#include "NSCEBitmap.h"
#include "UrlImage.h"
#include "UrlImageData.h"
#include "NSCEPictureBox.h"
#include "NSCEPictureBoxCtl.h"
#include "NSCEPictureBoxPpg.h"

#ifdef UNDER_CE
#ifdef WIN32_PLATFORM_HPCPRO
#define NSCE_MR_MOUSE
#endif // WIN32_PLATFORM_HPCPRO
#else // UNDER_CE
#define NSCE_MR_MOUSE
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


#define afxRegBothThreading 0x0004

IMPLEMENT_DYNCREATE(CNSCEPictureBoxCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CNSCEPictureBoxCtrl, COleControl)
	//{{AFX_MSG_MAP(CNSCEPictureBoxCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
//	ON_WM_ENTERMENULOOP()
//	ON_WM_EXITMENULOOP()
//	ON_WM_MBUTTONDOWN()
//	ON_WM_MBUTTONUP()
//	ON_WM_RBUTTONDOWN()
//	ON_WM_RBUTTONUP()
//	ON_WM_SETCURSOR()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CNSCEPictureBoxCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CNSCEPictureBoxCtrl)
	DISP_PROPERTY_NOTIFY(CNSCEPictureBoxCtrl, "ShowCaption", m_showCaption, OnShowCaptionChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CNSCEPictureBoxCtrl, "ScaleWidth", m_scaleWidth, OnScaleWidthChanged, VT_R4)
	DISP_PROPERTY_NOTIFY(CNSCEPictureBoxCtrl, "ScaleHeight", m_scaleHeight, OnScaleHeightChanged, VT_R4)
	DISP_PROPERTY_NOTIFY(CNSCEPictureBoxCtrl, "ScaleLeft", m_scaleLeft, OnScaleLeftChanged, VT_R4)
	DISP_PROPERTY_NOTIFY(CNSCEPictureBoxCtrl, "ScaleTop", m_scaleTop, OnScaleTopChanged, VT_R4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Width", GetWidth, SetWidth, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Height", GetHeight, SetHeight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontName", GetFontName, SetFontName, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontSize", GetFontSize, SetFontSize, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageWidth", GetImageWidth, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageHeight", GetImageHeight, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "AnimationAvailable", GetAnimationAvailable, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "AnimationInterval", GetAnimationInterval, SetAnimationInterval, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Appearance", GetAppearance, SetAppearance, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "AutoDetectTransparency", GetAutoDetectTransparency, SetAutoDetectTransparency, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "AutoRefresh", GetAutoRefresh, SetAutoRefresh, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "AutoSize", GetAutoSize, SetAutoSize, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "BitmapOnClipboard", GetBitmapOnClipboard, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "BorderStyle", GetBorderStyle, SetBorderStyle, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ByteArray", GetByteArray, SetByteArray, VT_VARIANT)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Center", GetCenter, SetCenter, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Clip", GetClip, SetClip, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ClipHeight", GetClipHeight, SetClipHeight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ClipWidth", GetClipWidth, SetClipWidth, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ClipTop", GetClipTop, SetClipTop, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ClipLeft", GetClipLeft, SetClipLeft, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "CommandButton", GetCommandButton, SetCommandButton, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "CommonBitmapID", GetCommonBitmapID, SetCommonBitmapID, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "CommonBitmapType", GetCommonBitmapType, SetCommonBitmapType, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScreenLeft", GetScreenLeft, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScreenTop", GetScreenTop, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScreenHeight", GetScreenHeight, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScreenWidth", GetScreenWidth, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "DrawWidth", GetDrawWidth, SetDrawWidth, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FillStyle", GetFillStyle, SetFillStyle, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FillColor", GetFillColor, SetFillColor, VT_COLOR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FocusRect", GetFocusRect, SetFocusRect, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FocusRectIndentLeft", GetFocusRectIndentLeft, SetFocusRectIndentLeft, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FocusRectIndentRight", GetFocusRectIndentRight, SetFocusRectIndentRight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FocusRectIndentTop", GetFocusRectIndentTop, SetFocusRectIndentTop, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FocusRectIndentBottom", GetFocusRectIndentBottom, SetFocusRectIndentBottom, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontBold", GetFontBold, SetFontBold, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontItalic", GetFontItalic, SetFontItalic, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontStrikethru", GetFontStrikethru, SetFontStrikethru, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontTransparent", GetFontTransparent, SetFontTransparent, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontUnderline", GetFontUnderline, SetFontUnderline, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontEscapement", GetFontEscapement, SetFontEscapement, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontOrientation", GetFontOrientation, SetFontOrientation, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "FontWeight", GetFontWeight, SetFontWeight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "HScrollPosition", GetHScrollPosition, SetHScrollPosition, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "VScrollPosition", GetVScrollPosition, SetVScrollPosition, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Headers", GetHeaders, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Visible", GetVisible, SetVisible, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageBitsPerPixel", GetImageBitsPerPixel, SetImageBitsPerPixel, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageLoadBitsPerPixel", GetImageLoadBitsPerPixel, SetImageLoadBitsPerPixel, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageLoadBufferSize", GetImageLoadBufferSize, SetImageLoadBufferSize, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageLoadMaxHeight", GetImageLoadMaxHeight, SetImageLoadMaxHeight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageLoadMaxWidth", GetImageLoadMaxWidth, SetImageLoadMaxWidth, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageLoadScalePercent", GetImageLoadScalePercent, SetImageLoadScalePercent, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ImageLoaded", GetImageLoaded, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Invert", GetInvert, SetInvert, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Top", GetTop, SetTop, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Left", GetLeft, SetLeft, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Mirror", GetMirror, SetMirror, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "MouseMovePoints", GetMouseMovePoints, SetMouseMovePoints, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "MouseMovePointsCount", GetMouseMovePointsCount, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Name", GetName, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "OnToolbar", GetOnToolbar, SetOnToolbar, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Overlay", GetOverlay, SetOverlay, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "OverlayTop", GetOverlayTop, SetOverlayTop, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "OverlayLeft", GetOverlayLeft, SetOverlayLeft, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "OverlayTransparentColor", GetOverlayTransparentColor, SetOverlayTransparentColor, VT_COLOR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "PenStyle", GetPenStyle, SetPenStyle, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "PenFillStyle", GetPenFillStyle, SetPenFillStyle, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Picture", GetPicture, SetPicture, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "PlayingCardsDll", GetPlayingCardsDll, SetPlayingCardsDll, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "PlayingCard", GetPlayingCard, SetPlayingCard, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Resize", GetResize, SetResize, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResizeWidth", GetResizeWidth, SetResizeWidth, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResizeHeight", GetResizeHeight, SetResizeHeight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResourceBitmapID", GetResourceBitmapID, SetResourceBitmapID, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResourceFile", GetResourceFile, SetResourceFile, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResourceFileLoaded", GetResourceFileLoaded, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResourceIconWidth", GetResourceIconWidth, SetResourceIconWidth, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResourceIconHeight", GetResourceIconHeight, SetResourceIconHeight, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ResourceIconID", GetResourceIconID, SetResourceIconID, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Rotate", GetRotate, SetRotate, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScaleMode", GetScaleMode, SetScaleMode, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScreenBitsPerPixel", GetScreenBitsPerPixel, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Scroll", GetScroll, SetScroll, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScrollX", GetScrollX, SetScrollX, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScrollY", GetScrollY, SetScrollY, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "ScrollBars", GetScrollBars, SetScrollBars, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Stretch", GetStretch, SetStretch, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "WaitCursor", GetWaitCursor, SetWaitCursor, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "TapAndHoldEventEnabled", GetTapAndHoldEventEnabled, SetTapAndHoldEventEnabled, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "TransparentColor", GetTransparentColor, SetTransparentColor, VT_COLOR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "URLAgent", GetURLAgent, SetURLAgent, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "URLFlagCache", GetURLFlagCache, SetURLFlagCache, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "URLFlagPassive", GetURLFlagPassive, SetURLFlagPassive, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "URLFlagReload", GetURLFlagReload, SetURLFlagReload, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "URLFlags", GetURLFlags, SetURLFlags, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "UseJPEGBitsPerPixel", GetUseJPEGBitsPerPixel, SetUseJPEGBitsPerPixel, VT_BOOL)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "Version", GetVersion, SetNotSupported, VT_R4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "VersionString", GetVersionString, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "WildCard", GetWildCard, SetWildCard, VT_I2)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "hBitmap", GetHBitmap, SetHBitmap, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "hIcon", GetHIcon, SetHIcon, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "hFont", GetHFont, SetHFont, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "VersionMajor", GetVersionMajor, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "VersionMinor", GetVersionMinor, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CNSCEPictureBoxCtrl, "parentHWnd", GetParentHWnd, SetNotSupported, VT_I4)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "StopUrlStream", MethodStopUrlStream, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Animate", Animate, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "CaptureScreen", MethodCaptureScreen, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "ClipImage", MethodClipImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Cls", MethodCls, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Copy", MethodCopy, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Paste", MethodPaste, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "CreateImage", MethodCreateImage, VT_EMPTY, VTS_I4 VTS_I4)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Data", MethodData, VT_EMPTY, VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawCircle", MethodDrawCircle, VT_EMPTY, VTS_R4 VTS_R4 VTS_R4 VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawIcon", MethodDrawIcon, VT_BOOL, VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawLine", MethodDrawLine, VT_EMPTY, VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawMouseMoveLines", MethodDrawMouseMoveLines, VT_EMPTY, VTS_COLOR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawMouseMoveLinesEx", MethodDrawMouseMoveLinesEx, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_COLOR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawPicture", MethodDrawPicture, VT_EMPTY, VTS_BSTR VTS_R4 VTS_R4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawPoint", MethodDrawPoint, VT_EMPTY, VTS_R4 VTS_R4 VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawPolygon", MethodDrawPolygon, VT_EMPTY, VTS_I2 VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawRoundRect", MethodDrawRoundRect, VT_EMPTY, VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawPolyLines", MethodDrawPolyLines, VT_EMPTY, VTS_I2 VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawText", MethodDrawText, VT_EMPTY, VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "DrawTextInRect", MethodDrawTextInRect, VT_EMPTY, VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "GetMouseMovePoint", MethodGetMouseMovePoint, VT_BOOL, VTS_I2 VTS_PI4 VTS_PI4)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Show", MethodShow, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Hide", MethodHide, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "IntensityBlue", MethodIntensityBlue, VT_I2, VTS_COLOR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "IntensityRed", MethodIntensityRed, VT_I2, VTS_COLOR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "IntensityGreen", MethodIntensityGreen, VT_I2, VTS_COLOR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "InvertImage", MethodInvertImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "MirrorImage", MethodMirrorImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "Move", MethodMove, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "RGB", MethodRGB, VT_COLOR, VTS_I2 VTS_I2 VTS_I2)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "QBColor", MethodQBColor, VT_COLOR, VTS_I2)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "RefreshDesktopWallpaper", MethodRefreshDesktopWallpaper, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "SetCapture", MethodSetCapture, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "ReleaseCapture", MethodReleaseCapture, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "RefreshX", MethodRefreshX, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "ResizeImage", MethodResizeImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "RotateImage", MethodRotateImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "SaveImageToFile", MethodSaveImageToFile, VT_BOOL, VTS_BSTR VTS_I2)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "ScrollImage", MethodScrollImage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "SetFocus", MethodSetFocus, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "SetPointArray", MethodSetPointArray, VT_EMPTY, VTS_I4 VTS_R4 VTS_R4)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "TextWidth", MethodTextWidth, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "TextHeight", MethodTextHeight, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "URL", MethodURL, VT_I4, VTS_BSTR VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CNSCEPictureBoxCtrl, "ZOrder", MethodZOrder, VT_EMPTY, VTS_I2)
	DISP_PROPERTY_PARAM(CNSCEPictureBoxCtrl, "Pixel", GetPixel, SetPixel, VT_COLOR, VTS_I4 VTS_I4)
	DISP_STOCKPROP_FORECOLOR()
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_HWND()
	DISP_STOCKPROP_CAPTION()
	DISP_STOCKPROP_ENABLED()
	DISP_FUNCTION_ID(CNSCEPictureBoxCtrl, "Refresh", DISPID_REFRESH, Refresh, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CNSCEPictureBoxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CNSCEPictureBoxCtrl, COleControl)
	//{{AFX_EVENT_MAP(CNSCEPictureBoxCtrl)
	EVENT_CUSTOM("GotFocus", FireGotFocus, VTS_NONE)
	EVENT_CUSTOM("HScroll", FireHScroll, VTS_I4  VTS_PBOOL  VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	EVENT_CUSTOM("VScroll", FireVScroll, VTS_I4  VTS_PBOOL  VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	EVENT_CUSTOM("LostFocus", FireLostFocus, VTS_NONE)
	EVENT_CUSTOM("TapAndHold", FireTapAndHold, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	EVENT_STOCK_CLICK()
	EVENT_STOCK_DBLCLICK()
	EVENT_CUSTOM_ID("MouseDown", DISPID_MOUSEDOWN, FireMouseDown, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	EVENT_CUSTOM_ID("MouseMove", DISPID_MOUSEMOVE, FireMouseMove, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	EVENT_CUSTOM_ID("MouseUp", DISPID_MOUSEUP, FireMouseUp, VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()

/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CNSCEPictureBoxCtrl, 1)
	PROPPAGEID(CNSCEPictureBoxPropPage::guid)
END_PROPPAGEIDS(CNSCEPictureBoxCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CNSCEPictureBoxCtrl, "NSCEPICTUREBOX.NSCEPictureBoxCtrl.1",
	0xa814c71a, 0xa051, 0x4350, 0x88, 0xf, 0xd, 0x76, 0xf7, 0x43, 0xc6, 0x3c)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CNSCEPictureBoxCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DNSCEPictureBox =
		{ 0x72d0af66, 0xce97, 0x45ee, { 0x8c, 0x62, 0xf8, 0x75, 0xf1, 0xb0, 0x2, 0xe3 } };
const IID BASED_CODE IID_DNSCEPictureBoxEvents =
		{ 0xd83df036, 0x29ab, 0x4f46, { 0xb8, 0x4d, 0x17, 0x4a, 0xaf, 0xd5, 0x61, 0xd6 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwNSCEPictureBoxOleMisc =
//	OLEMISC_SIMPLEFRAME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_ALWAYSRUN |
	OLEMISC_RECOMPOSEONRESIZE;


IMPLEMENT_OLECTLTYPE(CNSCEPictureBoxCtrl, IDS_NSCEPICTUREBOX, _dwNSCEPictureBoxOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::CNSCEPictureBoxCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CNSCEPictureBoxCtrl

BOOL CNSCEPictureBoxCtrl::CNSCEPictureBoxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows both-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If the current SDK does not support the both-model yet, then
	// you must manually change the named value "ThreadingModel" with a 
	// value of "Both" in their class ID registry entry under the 
	// class id\InprocServer32 key, using the Remote Registry Editor. 

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_NSCEPICTUREBOX,
			IDB_NSCEPICTUREBOX,
			afxRegBothThreading,
			_dwNSCEPictureBoxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::CNSCEPictureBoxCtrl - Constructor

CNSCEPictureBoxCtrl::CNSCEPictureBoxCtrl()
{
	InitializeIIDs(&IID_DNSCEPictureBox, &IID_DNSCEPictureBoxEvents);

	OLE_COLOR backcolor;

	//m_dteExpire.SetDateTime(2004, 6, 30, 23, 59, 59);
	m_showCaption = false;

	m_versionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (!GetVersionEx(&m_versionInfo))
	{
		m_versionInfo.dwMajorVersion = 2;
	}


#ifdef UNDER_CE
	m_procDecompressImageIndirect = NULL;
	m_himgdecmpDll = LoadLibrary(_T("imgdecmp.dll"));
	if (NULL != m_himgdecmpDll) 
	{
		m_procDecompressImageIndirect = (DecompressImageIndirectProc)GetProcAddress(m_himgdecmpDll, TEXT("DecompressImageIndirect"));
	}
#endif // UNDER_CE

	m_strName = AmbientDisplayName();
	if (m_strName.GetLength() == 0)
	{
		m_strName = AfxGetAppName();
	}

	m_bAutoDetectTransparency = TRUE;
	m_bAlreadyLoaded = FALSE;
	m_bAnimationAvailable = FALSE;
	m_bPlayingCardsDllAnimationAvailable = FALSE;
	m_bAutoRefresh = TRUE;
	m_bAutoSize = FALSE;
	m_bClip = FALSE;
	m_bCommandButton = FALSE;
	m_bDisplayExpired = TRUE;
	m_bFirstTimeAutoSize = FALSE;
	m_bFocusRect = FALSE;
	m_bFontTransparent = TRUE;
	m_scaleMode = 3;

#ifdef UNDER_CE
#ifdef NSCE_MR_MOUSE
	if ((GetSystemMetrics(SM_CXCURSOR) != 0) || (GetSystemMetrics(SM_CYCURSOR) != 0))
	{
		m_bHasMousePointer = TRUE;
	}
	else
	{
		m_bHasMousePointer = FALSE;
	}
#else // NSCE_MR_MOUSE
	m_bHasMousePointer = FALSE;
#endif // NSCE_MR_MOUSE
#else // UNDER_CE
	m_bHasMousePointer = FALSE;
#endif // UNDER_CE
	m_bHaveFocus = FALSE;
	m_bHaveName = FALSE;
	m_bInvert = FALSE;
	m_bIsStretched = FALSE;
	m_bOnToolbar = FALSE;
	m_bOverlay = FALSE;
	m_bResize = FALSE;
	m_bScroll = FALSE;
	m_bStretch = FALSE;
	m_bVBCE = FALSE;
	m_bVBCEAutoSize = FALSE;
	m_bVisible= TRUE;
	m_bWaitCursor = FALSE;
	m_bWaitingForResize = FALSE;
	m_bWorkingAnimationAvailable = FALSE;
	m_bWorkingAnimationInitialized = FALSE;
	m_bWorkingAnimationInvert = FALSE;
	m_bWorkingCaptureScreen = FALSE;
	m_bWorkingClip = FALSE;
	m_bWorkingInvert = FALSE;
	m_bWorkingPropExchange = FALSE;
	m_bOnToolbar = FALSE;
	m_bUseJPEGBitsPerPixel = TRUE;
	m_bUrlHttp = FALSE;
	m_strHeaders.Empty();

	m_hBitmap = NULL;
	m_hWorkingBitmap = NULL;
	m_hWorkingIconBitmap = NULL;
	m_hCommCtrl = NULL;
	m_hFont = NULL;
	m_hInstance = NULL;
	m_hInstMe = AfxGetInstanceHandle();
	m_hParentWindow = NULL;
	m_hPlayingCardsDll = NULL;
	m_hResourceFile = NULL;
	m_hWorkingAnimationBitmap[0] = NULL;
	m_hWorkingAnimationBitmap[1] = NULL;

	m_nResourceIconHeight = 0;
	m_nResourceIconWidth = 0;
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
	m_nScrollX = 0;
	m_nScrollY = 0;
	m_nTimer = 0;
	m_nWildCard = 0;

	m_nURLFlags = INTERNET_FLAG_PASSIVE | INTERNET_FLAG_DONT_CACHE;
	m_strURLAgent = TEXT("NSBasic CE PictureBox");

	m_nPointArraySize = 0;
	m_ptPointArray = NULL;

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

	m_ByteArray = NULL;
	m_nByteArray = 0;

	m_strPicture.Empty();
	m_strResourceFile.Empty();

	m_vTag = COleVariant();
	backcolor = AmbientBackColor();
	SetBackColor(backcolor);
	m_ocFillColor = RGB(0,0,0);
	m_ocTransparentColor = (unsigned long)-1;
	m_ocOverlayTransparentColor = (unsigned long)-1;
	m_nBorderStyle = 0; // GetBorderStyle();

	m_strPlayingCardsDll = TEXT("Default");
#ifdef UNDER_CE
	m_bWinNT = FALSE;
#else
	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (GetVersionEx((OSVERSIONINFO *)&osvi))
	{
		if (VER_PLATFORM_WIN32_NT == osvi.dwPlatformId) 
		{
			m_bWinNT = TRUE;
		}
		else
		{
			m_bWinNT = FALSE;
		}
	}
#endif

#ifdef UNDER_CE
	HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);
#else
	HDC sourceDC = ::CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
#endif
	m_nImageLoadBitsPerPixel = GetDeviceCaps(sourceDC, BITSPIXEL);
	::DeleteDC(sourceDC);
	if (m_nImageLoadBitsPerPixel == 16)
	{
		m_nImageLoadBitsPerPixel = 24;
	}

	SetFontName(TEXT("Tahoma"));
	HDC dcNew = ::CreateCompatibleDC(NULL);

 	m_nLogPixelsX = ::GetDeviceCaps(dcNew,LOGPIXELSX);
 	m_nLogPixelsY = ::GetDeviceCaps(dcNew,LOGPIXELSY);

#ifdef UNDER_CE
	if (m_versionInfo.dwMajorVersion >= 5) {m_nLogPixelsX /= 2; m_nLogPixelsY /= 2;}
#endif
	
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
	m_LogFont.lfItalic = FALSE; 
	m_LogFont.lfUnderline = FALSE; 
	m_LogFont.lfStrikeOut = FALSE; 
	m_LogFont.lfOutPrecision = OUT_DEFAULT_PRECIS; 
	m_LogFont.lfClipPrecision = CLIP_DEFAULT_PRECIS; 
	m_LogFont.lfQuality = DEFAULT_QUALITY;
	
	m_pUrlImage = NULL;

	m_bTapAndHoldEventEnabled = TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::~CNSCEPictureBoxCtrl - Destructor

CNSCEPictureBoxCtrl::~CNSCEPictureBoxCtrl()
{
	if (NULL != m_ptPointArray)
	{
		delete m_ptPointArray;
		m_ptPointArray = NULL;
	}

	if (NULL != m_pUrlImage)
	{
		CUrlImage *pUrlImage = m_pUrlImage;
		m_pUrlImage = NULL;
		pUrlImage->Abort(TRUE);
	}

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
	if (m_hPlayingCardsDll != NULL)
	{
		FreeLibrary(m_hPlayingCardsDll);
		m_hPlayingCardsDll = NULL;
	}
	if (m_hCommCtrl != NULL)
	{
		FreeLibrary(m_hCommCtrl);
		m_hCommCtrl = NULL;
	}

	if (m_ByteArray != NULL)
	{ 
		delete [] m_ByteArray;
		m_ByteArray = NULL;
		m_nByteArray = 0;
	}

#ifdef UNDER_CE
	if (NULL != m_himgdecmpDll)
	{
		FreeLibrary(m_himgdecmpDll);
		m_hCommCtrl = NULL;
		m_procDecompressImageIndirect = NULL;
	}
#endif // UNDER_CE
}

BOOL CNSCEPictureBoxCtrl::PreCreateWindow(CREATESTRUCT& cs) 
{
#ifndef UNDER_CE
//	cs.dwExStyle |= WS_EX_TRANSPARENT;
#endif // UNDER_CE
	return COleControl::PreCreateWindow(cs);
}

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

bool CNSCEPictureBoxCtrl::IsDIBSection(HBITMAP hBitmap)
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

bool CNSCEPictureBoxCtrl::IsMissing(const VARIANT *var)
{
	bool bReturn = false;
	if (V_VT(var) == VT_ERROR)
	{
		bReturn = true;
	}
	return bReturn;
}

BOOL CNSCEPictureBoxCtrl::CommonGetDisplayString(DISPID dispid, CString &strValue, DWORD dwCookie)
{
	BOOL bReturn = FALSE;
	strValue.Empty();
#ifndef UNDER_CE
	switch (dispid)
	{
		case dispidAppearance:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("-4 - 3D Sunken Border Frame (ScrollBars)");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("-3 - 3D Sunken Border (ScrollBars)");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("-2 - 3D Sunken Border (Tiles)");
					bReturn = TRUE;
					break;
				case 3:
					strValue = TEXT("-1 - 3D Sunken Border (Soft)");
					bReturn = TRUE;
					break;
				case 4:
					strValue = TEXT("0 - Single Line Border");
					bReturn = TRUE;
					break;
				case 5:
					strValue = TEXT("1 - 3D Raised Border (Soft)");
					bReturn = TRUE;
					break;
				case 6:
					strValue = TEXT("2 - 3D Raised Border (Tiles)");
					bReturn = TRUE;
					break;
				case 7:
					strValue = TEXT("3 - 3D Raised Border (ScrollBars)");
					bReturn = TRUE;
					break;
				case 8:
					strValue = TEXT("4 - Single Line Border (ScrollBars)");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidBorderStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Border");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Has Border");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidCenter:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Do Not Center");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Center Horizontally");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("2 - Center Vertically");
					bReturn = TRUE;
					break;
				case 3:
					strValue = TEXT("3 - Center Both");
					bReturn = TRUE;
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
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("-1 - Disabled Standard Bitmaps");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("0 - No Bitmap");
					bReturn = TRUE;
					break;
				case 3:
					strValue = TEXT("1 - Enabled Standard Bitmaps");
					bReturn = TRUE;
					break;
				case 4:
					strValue = TEXT("2 - Enabled View Bitmaps");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidFillStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Solid");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Transparent");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidMirror:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Do Not Mirror");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Mirror Horizontally");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("2 - Mirror Vertically");
					bReturn = TRUE;
					break;
				case 3:
					strValue = TEXT("3 - Mirror Both");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidMouseMovePoints:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Mouse Move Points");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Send Through MouseDown");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("2 - Make Available");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidPenFillStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - Solid");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Transparent");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidPenStyle:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Line");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Solid Line");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("2 - Dashed Line");
					bReturn = TRUE;
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
					bReturn = TRUE;
					break;
				case 90:
					strValue = TEXT("90 - Rotate 90 Degrees");
					bReturn = TRUE;
					break;
				case 180:
					strValue = TEXT("180 - Rotate 180 Degrees");
					bReturn = TRUE;
					break;
				case 270:
					strValue = TEXT("270 - Rotate 270 Degrees");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidWildCard:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Indicator");
					bReturn = TRUE;
					break;
				case 1:
					strValue = TEXT("1 - Horizontal Indicators");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("2 - Vertical Indicators");
					bReturn = TRUE;
					break;
				case 3:
					strValue = TEXT("3 - Center Indicator");
					bReturn = TRUE;
					break;
			}
			break;
		case dispidScrollBars:
			switch (dwCookie)
			{
				case 0:
					strValue = TEXT("0 - No Scroll Bars");
					bReturn = TRUE;
					break;
				case 1: 
					strValue = TEXT("1 - Horizontal Scroll Bar");
					bReturn = TRUE;
					break;
				case 2:
					strValue = TEXT("2 - Vertical Scroll Bar");
					bReturn = TRUE;
					break;
				case 3:
					strValue = TEXT("3 - Both Scroll Bars");
					bReturn = TRUE;
					break;
			}
			break;
	}
#endif

	return bReturn;
} 
 
long CNSCEPictureBoxCtrl::TransformPassedX(float inCoord)
{
	if (3 == m_scaleMode) return (long)(inCoord + 0.5);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Width();
	}
	else
	{
		size = 240.0;
	}

	return (long) ((inCoord - m_scaleLeft) / m_scaleWidth * size + 0.5);
}

long CNSCEPictureBoxCtrl::TransformPassedY(float inCoord)
{
	if (3 == m_scaleMode) return (long)(inCoord + 0.5);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Height();
	}
	else
	{
		size = 360.0;
	}

	return (long) ((inCoord - m_scaleTop) / m_scaleHeight * size + 0.5);
}

long CNSCEPictureBoxCtrl::TransformPassedWidth(float inCoord)
{
	if (3 == m_scaleMode) return (long)(inCoord + 0.5);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Width();
	}
	else
	{
		size = 240.0;
	}

	return (long) ((inCoord) / m_scaleWidth * size + 0.5);
}

long CNSCEPictureBoxCtrl::TransformPassedHeight(float inCoord)
{
	if (3 == m_scaleMode) return (long)(inCoord + 0.5);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Height();
	}
	else
	{
		size = 360.0;
	}

	return (long) ((inCoord) / m_scaleHeight * size + 0.5);
}

float CNSCEPictureBoxCtrl::UnTransformPassedX(long inCoord)
{
	if (3 == m_scaleMode) return (float)(inCoord);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Width();
	}
	else
	{
		size = 240.0;
	}

	return (float) (((float) inCoord) * m_scaleWidth / size) + m_scaleLeft;
}

float CNSCEPictureBoxCtrl::UnTransformPassedY(long inCoord)
{
	if (3 == m_scaleMode) return (float)(inCoord);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Height();
	}
	else
	{
		size = 360.0;
	}

	return (float) (((float) inCoord) * m_scaleHeight / size) + m_scaleTop;
}

float CNSCEPictureBoxCtrl::UnTransformPassedWidth(long inCoord)
{
	if (3 == m_scaleMode) return (float)(inCoord);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Width();
	}
	else
	{
		size = 240.0;
	}

	return (float) (((float) inCoord) * m_scaleWidth / size);
}

float CNSCEPictureBoxCtrl::UnTransformPassedHeight(long inCoord)
{
	if (3 == m_scaleMode) return (float)(inCoord);

	CRect cRect;
	float size = 0.0;

	if (GetRectInContainer(cRect) != 0) 
	{
		size = (float)cRect.Height();
	}
	else
	{
		size = 360.0;
	}

	return (float) (((float) inCoord) * m_scaleHeight / size);
}


void CNSCEPictureBoxCtrl::CommonFireMousePoints( short nButtons, short nKeys)
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

short CNSCEPictureBoxCtrl::CommonFireMouseButtons(UINT nFlags)
{
	short nButtons;
	nButtons = (nFlags & (MK_LBUTTON | MK_RBUTTON));
	if ((nFlags & MK_MBUTTON) == MK_MBUTTON)
	{
		nButtons |= 0x04;
	}
	return nButtons;
}

short CNSCEPictureBoxCtrl::CommonFireMouseKeys(UINT nFlags)
{
	short nKeys;
	nKeys = ((nFlags & (MK_SHIFT | MK_CONTROL)) >> 2);

	if (GetAsyncKeyState(VK_MENU) != 0)
	{
		nKeys |= 0x04;
	}
	return nKeys;
}

void CNSCEPictureBoxCtrl::CommonGetCardsInstance() 
{
	CString strPlayingCardsDll;
	strPlayingCardsDll = m_strPlayingCardsDll;
 
	if (0 == strPlayingCardsDll.CompareNoCase(TEXT("Default")))
	{
#ifdef UNDER_CE
		strPlayingCardsDll = TEXT("PegCards.dll");
#else // UNDER_CE
		if (m_bWinNT)
		{
			strPlayingCardsDll = TEXT("Cards.dll");
		}
		else
		{
			strPlayingCardsDll = TEXT("Cards32.dll");
		}
#endif // UNDER_CE
	}

	m_bPlayingCardsDllAnimationAvailable = FALSE;

	m_hPlayingCardsDll = LoadLibrary(strPlayingCardsDll);
		if (m_hPlayingCardsDll == NULL)
	{
		CString strMessage;
		strMessage.Format(TEXT("%s not found."), strPlayingCardsDll);
#ifndef UNDER_CE
		if (!m_bWinNT)
		{
			if (0 == m_strPlayingCardsDll.CompareNoCase(TEXT("Cards32.dll")))
			{
				strMessage += TEXT(" Windows 9x/Me requires a 32 bit dll named cards32.dll in the system32 directory.");
			}
		}
#endif
		AfxMessageBox(strMessage, MB_ICONERROR + MB_OK, 0);
	}
	else
	{
#ifdef UNDER_CE
		m_bPlayingCardsDllAnimationAvailable = TRUE;
#else
		CFileVersionInfo m_info;

		TCHAR szFile[4095];

		if (GetModuleFileName(m_hPlayingCardsDll, szFile, 4095))
		{
			m_info.ReadVersionInfo(szFile);

			if (m_info.IsValid())
			{
				if (0 == m_info.GetVersionInfo(0).CompareNoCase(TEXT("Microsoft Corporation")))
				{
					DWORD dwMajorFileVersion = m_info.GetMajorFileVersion();
					if ((3 == HIWORD(dwMajorFileVersion)) || (4 == HIWORD(dwMajorFileVersion)) ||
						((5 == HIWORD(dwMajorFileVersion)) && (0 == LOWORD(dwMajorFileVersion))))
					{
						m_bPlayingCardsDllAnimationAvailable = TRUE;
					}
				}
			}
		}
		else
		{
			CString strMessage;
			strMessage.Format(TEXT("GetLastError()=%d from GetModuleFileName"), GetLastError());
			AfxMessageBox(strMessage);
		} 
#endif
	}
}

long CNSCEPictureBoxCtrl::CommonDrawText(int nType, long nX, long nY, LPCTSTR szText, OLE_COLOR ocColor)
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
			if ((0 == m_LogFont.lfEscapement) && (0 == m_LogFont.lfOrientation))
			{
				Rect.top = nY;
				Rect.left = nX;
			}
			else
			{
				Rect.top = 0;
				Rect.left = 0;
			}
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

	if ((0 == m_LogFont.lfEscapement) && (0 == m_LogFont.lfOrientation))
	{
		::DrawText(dcNew,szText, -1, &Rect, DT_CALCRECT);
	}

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

			if ((0 == m_LogFont.lfEscapement) && (0 == m_LogFont.lfOrientation))
			{
				::DrawText(dcNew,szText, -1, &Rect, 0);
			}
			else
			{
#ifndef UNDER_CE
				::SetGraphicsMode(dcNew, GM_ADVANCED);
#endif // UNDER_CE
				::DrawText(dcNew,szText, -1, &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			}
			
			if (!CommonCheckAutoSize(FALSE))
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

void CNSCEPictureBoxCtrl::CommonDrawTextInRect(int nType, RECT *rect, LPCTSTR szText, OLE_COLOR ocColor)
{
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

	switch (nType)
	{
		case 3:
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

	switch (nType)
	{
		case 3:
#ifndef UNDER_CE
			::SetGraphicsMode(dcNew, GM_ADVANCED);
#endif // UNDER_CE
			::DrawText(dcNew,szText, -1, rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			
			if (!CommonCheckAutoSize(FALSE))
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

	return;
}

void CNSCEPictureBoxCtrl::CommonDrawPoint(long nX, long nY, OLE_COLOR ocColor)
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

void CNSCEPictureBoxCtrl::CommonDrawPolyLines(POINT *pts, short nPoints, OLE_COLOR ocColor)
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

	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

void CNSCEPictureBoxCtrl::CommonDrawRoundRect(long nLeft, long nTop, long nRight, long nBottom, long nWidth, long nHeight, OLE_COLOR ocColor, short nFillStyle)
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

bool CNSCEPictureBoxCtrl::CommonSaveImageToByteArray()
{
	BITMAPINFO *bih = NULL;
	bih = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO) + (256 * sizeof(RGBQUAD))];

	if (NULL == bih)
	{
		return false;
	}
//	BITMAPINFO bih;
//	RGBQUAD bmiColors[256];
	BITMAP bm;
	DIBSECTION ds;

	bool bReturn = false;

	bool bIsDib, bDefault1632;

	HDC	sourceDC = ::CreateCompatibleDC(NULL);
	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, m_hBitmap);
	HDC destDC = ::CreateCompatibleDC(NULL);

	bIsDib = IsDIBSection(m_hBitmap);

	::GetObject(m_hBitmap, sizeof(BITMAP), &bm);

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

	if (mult > 0)
	{	
		if (2 == mult)
		{
			bih->bmiColors[0].rgbRed = 255;
			bih->bmiColors[0].rgbGreen = 255;
			bih->bmiColors[0].rgbBlue = 255;
			bih->bmiColors[0].rgbReserved = 0;
			bih->bmiColors[1].rgbRed = 0;
			bih->bmiColors[1].rgbGreen = 0;
			bih->bmiColors[1].rgbBlue = 0;
			bih->bmiColors[1].rgbReserved = 0;
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
					for (j=0; j<i;j++)
					{
						if (memcmp(&rgbQuad, &bih->bmiColors[j], sizeof(RGBQUAD)) == 0)
						{
							bFound = true;
							break;
						}
					}

					if (!bFound)
					{
	//					::MessageBox(::GetForegroundWindow(), TEXT("adding rgbquad"), TEXT(""), MB_OK);
						bih->bmiColors[i].rgbRed = rgbQuad.rgbRed;
						bih->bmiColors[i].rgbGreen = rgbQuad.rgbGreen;
						bih->bmiColors[i].rgbBlue = rgbQuad.rgbBlue;
						bih->bmiColors[i].rgbReserved = rgbQuad.rgbReserved;
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
				bih->bmiColors[i].rgbRed = 0;
				bih->bmiColors[i].rgbGreen = 0;
				bih->bmiColors[i].rgbBlue = 0;
				bih->bmiColors[i].rgbReserved = 0;
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
					memcpy(&bih->bmiColors[0],&dwMask,4);
					dwMask = 0x03E0;
					memcpy(&bih->bmiColors[1],&dwMask,4);
					dwMask = 0x001F;
					memcpy(&bih->bmiColors[2],&dwMask,4);
				}
				else
				{
					dwMask = 0x00FF0000;
					memcpy(&bih->bmiColors[0],&dwMask,4);
					dwMask = 0x0000FF00;
					memcpy(&bih->bmiColors[1],&dwMask,4);
					dwMask = 0x000000FF;
					memcpy(&bih->bmiColors[2],&dwMask,4);
				}
			}
			else
			{
				memcpy(&bih->bmiColors[0], &ds.dsBitfields, sizeof(RGBQUAD) * abs(mult));
			}
		}
	}

	LPBITMAPFILEHEADER lphdr;
	LPBITMAPINFO lpbi;
	LPVOID pBits;
	LPBYTE lpBytes; 

	DWORD nBitsSize = ((((bm.bmWidth * bits) + 31) & (~31)) / 8) * bm.bmHeight;
	
	if (m_ByteArray != NULL)
	{ 
		delete [] m_ByteArray;
		m_ByteArray = NULL;
		m_nByteArray = 0;
	}

	m_nByteArray = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult)) + nBitsSize;
	m_ByteArray = new BYTE[m_nByteArray];

	if (m_ByteArray == NULL)
	{
		if (NULL != bih)
		{
			delete bih;
			bih = NULL;
		}
		return false;
	}
	
	lphdr = (LPBITMAPFILEHEADER)m_ByteArray;
	lpbi = (LPBITMAPINFO)(m_ByteArray + sizeof(BITMAPFILEHEADER));
	lpBytes = (LPBYTE)(m_ByteArray + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult)));

	lphdr->bfType		= ((WORD) ('M' << 8) | 'B');	// is always "BM"
	lphdr->bfSize		=  sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult)) + nBitsSize;
	lphdr->bfReserved1 	= 0;
	lphdr->bfReserved2 	= 0;
	lphdr->bfOffBits	= (DWORD) sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult));	

	bih->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bih->bmiHeader.biWidth = bm.bmWidth;
	bih->bmiHeader.biHeight = bm.bmHeight;
	bih->bmiHeader.biPlanes = 1;
	bih->bmiHeader.biBitCount = bits;
	if (mult == -3)
	{
		bih->bmiHeader.biCompression = BI_BITFIELDS;
	}
	else
	{
		bih->bmiHeader.biCompression = BI_RGB;
	}
	bih->bmiHeader.biSizeImage = 0;
	bih->bmiHeader.biXPelsPerMeter = 0;
	bih->bmiHeader.biYPelsPerMeter = 0;
	bih->bmiHeader.biClrUsed = 0;
	bih->bmiHeader.biClrImportant = 0;

	memcpy(lpbi, bih, sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * abs(mult)));
//	if (mult != 0)
//	{
//		memcpy(&lpbi->bmiColors[0], &bmiColors[0], sizeof(RGBQUAD) * abs(mult));
//	}

	HBITMAP dsBitmap = ::CreateDIBSection(NULL, bih, DIB_RGB_COLORS, &pBits, NULL, 0);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, dsBitmap);

	::BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY);

/*	{	
		long x,y,i;
		bool bFound = false;

		i = 0;
		for (x=0; ((x < bm.bmWidth) && (i < mult)); x++)
		{
			for (y=0; ((y < bm.bmHeight) && (i < mult)); y++)
			{
				if (::GetPixel(sourceDC, x, y) != ::GetPixel(destDC, x, y))
				{
					::MessageBox(::GetForegroundWindow(), TEXT("pixel error"), TEXT(""), MB_OK);
					bFound = true;
					break;
				}
			}
			if (bFound)
			{
				break;
			}
		}
	}
*/	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	memcpy(&lpBytes[0], (unsigned char *)pBits, nBitsSize);

	::DeleteObject(dsBitmap);

	bReturn = true;

	if (NULL != bih)
	{
		delete bih;
		bih = NULL;
	}

	return bReturn;
}

void CNSCEPictureBoxCtrl::CommonGetCommCtrlInstance()
{
#ifdef UNDER_CE

	m_hCommCtrl = LoadLibrary(TEXT("commctrl.dll"));
	if (m_hCommCtrl == NULL)
	{
		m_hCommCtrl = LoadLibrary(TEXT("\\windows\\commctrl.dll"));
	}
#endif
}

void CNSCEPictureBoxCtrl::CommonDesignRefresh()
{
	if (!AmbientUserMode())
	{
		if (!CommonCheckAutoSize(false))
		{
			InvalidateControl(NULL);
		}
	}
} 

void CNSCEPictureBoxCtrl::CommonClearForLoad()
{
	if (m_hResourceFile != NULL)
	{
		FreeLibrary(m_hResourceFile);
		m_hResourceFile = NULL;
	}

	m_strHeaders.Empty();
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
	m_bWorkingCaptureScreen = FALSE;

	m_nDrawTextCurrentY = 0;
//	m_nWorkingScrollBars = -1;
	m_nHScrollPosition = 0;
	m_nVScrollPosition = 0;

	m_bWorkingAnimationAvailable = FALSE;

	if (m_ByteArray != NULL)
	{
		delete [] m_ByteArray;
		m_ByteArray = NULL;
		m_nByteArray = 0;
	}
	
	MethodStopUrlStream();
	m_bUrlHttp = FALSE;
}

HBITMAP CNSCEPictureBoxCtrl::CommonRotate(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = hBitmap;
	if ((m_nRotate > 0) && (hBitmap != NULL))
	{
//rotate		hReturnBitmap = CommonGetBitmapRotated(hBitmap, m_nRotate);
		CNSCEBitmap *pOld = new CNSCEBitmap;
		if (NULL != pOld)
		{
			CNSCEBitmap *pNew;
			pOld->SetHBITMAP(hBitmap);
			pNew = pOld->Rotate(m_nRotate);
			if (NULL != pNew)
			{
				hReturnBitmap = pNew->TakeHBITMAP();
				delete pNew;
			}
			pOld->TakeHBITMAP();
			delete pOld;
		}
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

HBITMAP CNSCEPictureBoxCtrl::CommonMirror(HBITMAP hBitmap)
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

HBITMAP CNSCEPictureBoxCtrl::CommonInvert(HBITMAP hBitmap)
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

HBITMAP CNSCEPictureBoxCtrl::CommonClip(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = NULL;

	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapClip(hBitmap, m_nClipLeft, m_nClipTop, m_nClipWidth, m_nClipHeight);
		::DeleteObject(hBitmap);
	}
	return hReturnBitmap;
}

HBITMAP CNSCEPictureBoxCtrl::CommonResize(HBITMAP hBitmap)
{
	SetScaleMode(m_scaleMode);
	HBITMAP hReturnBitmap = NULL;

	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapResize(hBitmap, m_nResizeWidth, m_nResizeHeight);
		::DeleteObject(hBitmap);
	}
	return hReturnBitmap;
}

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapControlSize()
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

CString CNSCEPictureBoxCtrl::CommonOptionalString(const VARIANT *vString, LPCTSTR lpszInit)
{
	CString strReturn = lpszInit;

	if (V_VT(vString) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vString), 0, VT_BSTR) == S_OK)
		{
			strReturn = V_BSTR(&varTemp);
		}
		::VariantClear(&varTemp);
	}
	return strReturn;
} 

float CNSCEPictureBoxCtrl::CommonOptionalFloat(const VARIANT *vFloat, float flInit)
{
	float flReturn = flInit;

	if (V_VT(vFloat) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vFloat), 0, VT_R4) == S_OK)
		{
			flReturn = V_R4(&varTemp);
		}
		::VariantClear(&varTemp);
	}
	return flReturn;
} 

long CNSCEPictureBoxCtrl::CommonOptionalLong(const VARIANT *vLong, long nInit)
{
	long nReturn = nInit;

	if (V_VT(vLong) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vLong), 0, VT_I4) == S_OK)
		{
			nReturn = V_I4(&varTemp);
		}
		::VariantClear(&varTemp);
	}
	return nReturn;
} 

bool CNSCEPictureBoxCtrl::CommonOptionalBool(const VARIANT *vBool, bool bInit)
{
	bool bReturn = bInit;

	if (V_VT(vBool) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vBool), 0, VT_BOOL) == S_OK)
		{
			if (V_BOOL(&varTemp) == VARIANT_TRUE)
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

BOOL CNSCEPictureBoxCtrl::CommonLoadImageIntoBitmap()
{
	BOOL bAutoSize = FALSE;
	HBITMAP hLoadBitmap = NULL;
	HBITMAP hNewBitmap = NULL;
	BITMAP Bitmap;

	if ((m_strPicture.GetLength() > 0) || (m_ByteArray != NULL) || (m_nResourceID >= 0) || (m_hWorkingIconBitmap != NULL) || (m_hWorkingBitmap != NULL) || (m_bWorkingCaptureScreen)) 
	{
		m_bAnimationAvailable = FALSE;

		m_nWorkingAnimationInterval = 0;
		CommonSetNewTimer();

		m_bWorkingAnimationAvailable = FALSE;
		m_bWorkingAnimationInitialized = FALSE;
		m_bWorkingAnimationInvert = FALSE;
		m_nWorkingAnimationMirror = 0;
		m_nWorkingAnimationRotate = 0;
		m_nWorkingWildCard = 0;

		m_dteDate = m_dteDate.GetCurrentTime();

#if 0
		if (m_dteDate > m_dteExpire)
		{
			if (m_bDisplayExpired)
			{
				AfxMessageBox(TEXT("The NSCE.PictureBox Control has expired.\nGoto http://nsbasic.com/NSCE"), MB_ICONERROR + MB_OK, 0);
				m_bDisplayExpired = FALSE;
			}
		}
		else
#endif
		{
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
					
					m_bWorkingClip = FALSE;
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
					if (!IsDIBSection(hLoadBitmap))
					{
						hNewBitmap = CommonGetBitmapCopy(hLoadBitmap);
						if (NULL != hNewBitmap)
						{
							::DeleteObject(hLoadBitmap);
							hLoadBitmap = hNewBitmap;
						}
					}
				}

				m_bWorkingInvert = FALSE;
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
							m_bWorkingAnimationAvailable = m_bPlayingCardsDllAnimationAvailable;
						}

						if ((m_nWildCard > 0) && (!m_bWorkingAnimationAvailable))
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationAvailable = TRUE;
							AnimatePlayingCard(FALSE, m_hBitmap);
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
									m_bWorkingAnimationAvailable = TRUE;
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
							m_bWorkingAnimationAvailable = TRUE;
						}

						if ((m_nWildCard > 0) && (!m_bWorkingAnimationAvailable))
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationAvailable = TRUE;
							AnimatePlayingCard(FALSE, m_hBitmap);
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
									m_bWorkingAnimationAvailable = TRUE;
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
							m_bWorkingAnimationAvailable = TRUE;
							m_nWorkingAnimationPlatform = 2;
						}

						if ((m_nWildCard > 0) && (!m_bWorkingAnimationAvailable))
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationAvailable = TRUE;
							AnimatePlayingCard(FALSE, m_hBitmap);
						}
#endif //  WIN32_PLATFORM_PSPC
#endif // UNDER_CE

				m_bAnimationAvailable = m_bWorkingAnimationAvailable;
				m_nWorkingAnimationInterval = m_nAnimationInterval;

				bAutoSize = CommonCheckAutoSize(FALSE);
			}
		}
	}
	return bAutoSize;
}

BOOL CNSCEPictureBoxCtrl::CommonCheckAutoSize(BOOL bForce)
{
	CRect cRect;
	BITMAP Bitmap;
	BOOL bChangedSize = FALSE;
	int nBorder = 0;
	int nVBCE = 0;

	if ((!m_bAutoRefresh) && (!bForce))
	{
		return TRUE;
	}

	if ((m_bAutoSize) && (m_hBitmap != NULL))
	{

		if (!::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap))
		{
//			AfxMessageBox(TEXT("!GetObject()"));
		}
		else
		{
			if (!GetRectInContainer(cRect))
			{
//				AfxMessageBox(TEXT("!GetRectInContainer()"));
			}
			else
			{		
				if (m_bVBCE)
				{
					CWnd *pWnd = (CWnd *)this->GetParent();
					pWnd->GetWindowRect(cRect);
				}
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

//#ifdef UNDER_CE
//				if (m_bVBCE)
//				{
//					nVBCE = 6;
//				}
//#endif
				
				m_nAutoSizeWidth = Bitmap.bmWidth  + nBorder;
				m_nAutoSizeHeight = Bitmap.bmHeight + nBorder;
				if (cRect.Width() != ((Bitmap.bmWidth  + nBorder) - nVBCE))
				{
	 				cRect.right = (cRect.left + Bitmap.bmWidth + nBorder) - nVBCE;
					bChangedSize = TRUE;
				}
				if (cRect.Height() != ((Bitmap.bmHeight + nBorder) - nVBCE))
				{
					cRect.bottom = (cRect.top + Bitmap.bmHeight + nBorder) - nVBCE;
					bChangedSize = TRUE;
				}
				if (bChangedSize) 
				{
#ifdef UNDER_CE
					if (m_bVBCE)
					{
						SetControlSize(cRect.Width(), cRect.Height());
						(CWnd *)this->GetParent()->SetWindowPos(
							NULL, 0, 0, cRect.Width(), cRect.Height(), 
							SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
					}
#endif //  UNDER_CE
					SetControlSize(cRect.Width(), cRect.Height());
					InvalidateControl(NULL);
				}
			}
		}

	}

	return bChangedSize;
}

DWORD CNSCEPictureBoxCtrl::SwapEndian(DWORD nOld)
{
	DWORD nNew = 0;
	while (nOld > 0)
	{
		nNew = (nNew << 8) + (nOld % 256);
		nOld = nOld >> 8;
	}
	return nNew;
}

long CNSCEPictureBoxCtrl::StartURL(LPCTSTR lpszURL, LPCTSTR lpszUser,LPCTSTR lpszPassword) 
{
	long lReturn = 0;

	CUrlImage *pUrlImage = new CUrlImage;

	MethodStopUrlStream();

	m_cs.Lock();
	m_pUrlImage = pUrlImage;
	lReturn = m_pUrlImage->GetUrl(this, WM_APP, lpszURL, lpszUser, lpszPassword, m_nURLFlags, m_strURLAgent, m_nImageLoadBufferSize);
	m_strHeaders = m_pUrlImage->m_strHeaders;
	m_cs.Unlock();
	
	return lReturn;
}

DWORD CNSCEPictureBoxCtrl::CallbackGetImageData(LPSTR szBuffer, DWORD dwBufferMax, LPARAM lParam)
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

BOOL CNSCEPictureBoxCtrl::CommonGetIconSize(HICON hIcon, long *lWidth, long *lHeight)
{
	long x = 0;
	long y = 0;
#ifdef UNDER_CE
	OLE_COLOR oc = m_ocFillColor;
	short lILBPP = m_nImageLoadBitsPerPixel;

	m_ocFillColor = RGB(128,128,128);
	m_nImageLoadBitsPerPixel = 4;
	HBITMAP hBitmap = CommonGetBitmapClip(NULL, 0, 0, 129, 129);
	m_ocFillColor = oc;
	m_nImageLoadBitsPerPixel = lILBPP;	

	if (NULL != hBitmap)
	{
		HDC destDC = ::CreateCompatibleDC(NULL);

		if (NULL != destDC)
		{
			HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hBitmap);

			if (::DrawIconEx(destDC, 0, 0, hIcon, 0, 0, 0, NULL, DI_MASK))
			{
				long lIndex;
				for (lIndex = 0; lIndex < 129; lIndex++)
				{
					if (RGB(128,128,128) == ::GetPixel(destDC, lIndex, 0))
					{
						y = lIndex;
						break;
					}
				}
				for (lIndex = 0; lIndex < 129; lIndex++)
				{
					if (RGB(128,128,128) == ::GetPixel(destDC, 0, lIndex))
					{
						x = lIndex;
						break;
					}
				}
			}
			::SelectObject(destDC, hbmOldDest);
			::DeleteDC(destDC);
		}
		::DeleteObject(hBitmap);
	}
#else // UNDER_CE
	ICONINFO ii;
	if (GetIconInfo(hIcon, &ii))
	{
		if (ii.fIcon)
		{
			BITMAP bm;
			if (GetObject(ii.hbmColor, sizeof(BITMAP), &bm))
			{
				x = bm.bmWidth;
				y = bm.bmHeight;
			}
		}
	}
#endif // UNDER_CE
	if (!x || !y)
	{
		return FALSE;
	}

	*lWidth = x;
	*lHeight = y;

	return TRUE;
}

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapFromIcon(HICON hIcon, long xPassed, long yPassed, OLE_COLOR ocColorPassed, long nDrawType)
{
	HBITMAP hBitmap = NULL;

	long x = xPassed;
	long y = yPassed;
	if (!x || !y)
	{
		if (!CommonGetIconSize(hIcon, &x, &y))
		{
			return NULL;
		}
	}

	OLE_COLOR ocColor = ocColorPassed;
	if (ocColor > 16777215)
	{
		ocColor = GetBackColor();
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
	}

	CommonClearForLoad();

	OLE_COLOR oc;
	oc = m_ocFillColor;

	m_ocFillColor = ocColor;

	hBitmap = CommonGetBitmapClip(NULL, 0, 0, x, y);

	m_ocFillColor = oc;
		
	HDC destDC = ::CreateCompatibleDC(NULL);

	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hBitmap);

	::DrawIconEx(destDC, 0, 0, hIcon, x, y, 0, NULL, nDrawType);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hBitmap;
}

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapScreen()
{
#ifdef UNDER_CE
	HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);
#else
	HDC sourceDC = ::CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
#endif
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapScroll(HBITMAP hBitmap, long nScrollX, long nScrollY)
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

void CNSCEPictureBoxCtrl::CommonLoadImage(HBITMAP *hBitmap, bool *bCopiedPassed)
{
	HBITMAP hLoadBitmap = *hBitmap;
	bool bCopied = *bCopiedPassed;
	
	if ((m_strPicture.GetLength() > 0) || (m_ByteArray != NULL))
	{
		HRESULT hr;
		HANDLE hFile = INVALID_HANDLE_VALUE;

		if (m_ByteArray == NULL)
		{
			LPTSTR lpszUser = NULL;
			LPTSTR lpszPassword = NULL;
			LPTSTR lpszUrl = NULL;
			DWORD dwUrlLength;
			URL_COMPONENTS uc;
			memset(&uc, 0 , sizeof(URL_COMPONENTS));
			uc.dwStructSize = sizeof(URL_COMPONENTS);
			uc.dwExtraInfoLength = 255;
			uc.dwHostNameLength = 255;
			uc.dwPasswordLength = 255;
			uc.dwSchemeLength = 255;
			uc.dwUrlPathLength = 255;
			uc.dwUserNameLength = 255;

			BOOL bReturn = InternetCrackUrl(m_strPicture, 0, 0, &uc);

			switch (uc.nScheme)
			{
				case INTERNET_SCHEME_FTP:
//				case INTERNET_SCHEME_GOPHER:
				case INTERNET_SCHEME_HTTP:
				case INTERNET_SCHEME_HTTPS:
					lpszUser = new TCHAR[uc.dwUserNameLength + 1];
					memmove(lpszUser, uc.lpszUserName,  sizeof(TCHAR) * uc.dwUserNameLength);
					lpszUser[uc.dwUserNameLength] = TEXT('\0');

					lpszPassword = new TCHAR[uc.dwPasswordLength + 1];
					memmove(lpszPassword, uc.lpszPassword,  sizeof(TCHAR) * uc.dwPasswordLength);
					lpszPassword[uc.dwPasswordLength] = TEXT('\0');

					dwUrlLength = uc.dwExtraInfoLength + uc.dwHostNameLength + uc.dwSchemeLength + uc.dwUrlPathLength + 10;
					lpszUrl = new TCHAR[dwUrlLength];

					uc.dwPasswordLength = 0;
					uc.lpszPassword = NULL;
					uc.dwUserNameLength = 0;
					uc.lpszUserName = NULL;

					bReturn = InternetCreateUrl(&uc, 0, lpszUrl, &dwUrlLength);

					m_bUrlHttp = TRUE;
					StartURL(lpszUrl, lpszUser, lpszPassword);

					delete lpszUrl;
					lpszUrl = NULL;
					delete lpszUser;
					lpszUser = NULL;
					delete lpszPassword;
					lpszPassword = NULL;
					break;
				default:
					hFile = CreateFile(m_strPicture,GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					break;
			}
		}
		
		if ((hFile != INVALID_HANDLE_VALUE) || (m_ByteArray != NULL))
		{
			DWORD dwFileLen;

			if (m_ByteArray == NULL)
			{
				dwFileLen = GetFileSize(hFile, NULL);
			}
			else
			{
				dwFileLen = m_nByteArray;
			}

			DWORD dwBufferSize;
			DWORD dwCurrentBuffer = 0;
			WORD nBitDepth;
			long nMaxWidth;
			long nMaxHeight;
			bool bGif = false;
			bool bBitmap = false;
			bool bJpeg = false;
			bool bPNG = false;
			bool bTransparent = false;
			BYTE byTransparentIndex = 0;

			nMaxWidth = m_nImageLoadMaxWidth;
			nMaxHeight = m_nImageLoadMaxHeight;
			nBitDepth = m_nImageLoadBitsPerPixel;

#ifndef UNDER_CE
			dwBufferSize = dwFileLen;
#else // UNDER_CE
			if ((m_nImageLoadBufferSize < 1) || (m_ByteArray != NULL))
			{
				dwBufferSize = dwFileLen;
			}
			else
			{
				dwBufferSize = m_nImageLoadBufferSize;
			}
#endif // UNDER_CE

			LPBYTE pBuffer;
			if (m_ByteArray != NULL)
			{
				pBuffer = m_ByteArray;
				dwCurrentBuffer = m_nByteArray;
			}
			else
			{
				pBuffer = new BYTE[dwBufferSize];
				if (NULL == pBuffer)
				{
					return;
				}
				ReadFile(hFile, pBuffer, dwBufferSize, &dwCurrentBuffer, NULL);
			}


//			if (dwBufferSize >= dwFileLen)
			if (dwBufferSize > 7)
			{
				if (0 == memcmp(pBuffer, "\211PNG\r\n\032\n", 8))
				{
					bPNG = true;
					if ((m_nImageLoadBufferSize > -1) && (dwBufferSize > 24))
					{
						if (0 == memcmp(pBuffer + 12, "IHDR", 4))
						{
							nMaxWidth = 0;
							for (long lPng = 16; lPng < 20;lPng++)
							{
								nMaxWidth = (nMaxWidth * 256) + pBuffer[lPng];
							}

							nMaxHeight = 0;
							for (lPng = 20; lPng < 24;lPng++)
							{
								nMaxHeight = (nMaxHeight * 256) + pBuffer[lPng];
							}
							nBitDepth = pBuffer[24];
						}
					}
				}

				if (0 == memcmp(pBuffer, "BM", 2))
				{
					bBitmap = true;
					if ((m_nImageLoadBufferSize > -1) && (dwBufferSize >= sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)))
					{
						LPBITMAPFILEHEADER hdr;
						BITMAPINFOHEADER bi;
						hdr = (LPBITMAPFILEHEADER)&pBuffer[0];
						memcpy(&bi,&pBuffer[sizeof(BITMAPFILEHEADER)],sizeof(BITMAPINFOHEADER));
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
					}
				}

				if (0 == memcmp(pBuffer, "GIF", 3))
				{
					bGif = true;
					if ((m_nImageLoadBufferSize > -1) && (dwBufferSize > 10))
					{
						DWORD ptr = 6;
						nMaxWidth = (WORD)pBuffer[ptr] + ((WORD)pBuffer[ptr + 1] * 256);
						nMaxHeight = (WORD)pBuffer[ptr + 2]  + ((WORD)pBuffer[ptr + 3] * 256);
						nBitDepth = abs((((char)(pBuffer[ptr + 4]) & 0x70) >> 4)) + 1;

						if (m_bAutoDetectTransparency) 
						{
							DWORD gct = 0;
							DWORD gctsize = 0;
							DWORD lct = 0;
							DWORD lctsize = 0;
							DWORD len = 0;

							if ((pBuffer[ptr + 4] & 0x80) == 0x80)
							{
								gct = ptr + 7;
								gctsize = (1 << ((pBuffer[ptr + 4] & 0x07) + 1)) * 3;
							}

							ptr += 7 + gctsize;

							while (ptr < dwBufferSize)
							{
								switch (pBuffer[ptr])
								{
									default:
									case 0x3b:
										ptr = dwBufferSize;
										break;
									case 0x2c:
										ptr++;
										if ((ptr + 8) < dwBufferSize)
										{
											lct = 0;
											lctsize = 0;
											if ((pBuffer[ptr + 8] & 0x01) == 0x01)
											{
												lct = ptr + 9;
												lctsize = (1 << (((pBuffer[ptr + 8] & 0xe0) >> 5) + 1)) * 3;
												if (bTransparent)
												{
													ptr = dwBufferSize;
													break;
												}
											}
											ptr += lctsize + 9;
											ptr++;  // lzw_mcs
											if (ptr < dwBufferSize)
											{
												len = pBuffer[ptr];
												while ((len > 0) && (ptr < dwBufferSize))
												{
													ptr += len + 1;
													len = pBuffer[ptr];
												}
												ptr++;
											}
										}
										else
										{
											ptr = dwBufferSize;
										}
										break;
									case 0x21:
										ptr++;
										if (ptr < dwBufferSize)
										{
											switch (pBuffer[ptr])
											{
												default:
												case 0x01:
												case 0xfe:
												case 0xff:
													ptr++;
													if (ptr < dwBufferSize)
													{
														len = pBuffer[ptr];
														while ((len > 0) && (ptr < dwBufferSize))
														{
															ptr += len + 1;
															if (ptr < dwBufferSize)
															{
																len = pBuffer[ptr];
															}
														}
													}
													ptr++;
													break;
												case 0xf9:
													ptr++;
													if ((ptr + 4) < dwBufferSize)
													{
														len = pBuffer[ptr];
														if ((pBuffer[ptr + 1] & 0x01) == 0x01)
														{
															byTransparentIndex = pBuffer[ptr + 4];
															bTransparent = true;
//															if (lct)
															{
																ptr = dwBufferSize;
																break;
															}
														}
														while ((len > 0) && (ptr < dwBufferSize))
														{
															ptr += len + 1;
															if (ptr < dwBufferSize)
															{
																len = pBuffer[ptr];
															}
														}
														ptr++;
													}
													break;
											}
										}
										break;
								}
							}

/*							if (bTransparent)
							{
								if (lct)
								{
									gct = lct;
								}

								gct += (byTransparentIndex - 1) * 3;
								m_ocTransparentColor = RGB(pBuffer[gct+2], pBuffer[gct + 1], pBuffer[gct]);
							} */
						}
					}
				}

				if (0 == memcmp(pBuffer, "\255\216\255\224", 4))
				{
					bJpeg = true;
					if ((m_nImageLoadBufferSize > -1) && (dwBufferSize > 11))
					{
						DWORD nSegment = 2;
						DWORD nLength;
						
						nLength = (pBuffer[nSegment + 2] * 256) + pBuffer[nSegment + 3];
						if (memcmp(&pBuffer[nSegment + 4],"JFIF\0",5) == 0)
						{
							nSegment += nLength + 2;
							while ((nSegment + 3) < dwBufferSize)
							{
								if ((pBuffer[nSegment] == 0xff) && (pBuffer[nSegment + 1] == 0xc0))
								{
									if ((nSegment + 8) < dwBufferSize)
									{
										if (m_bUseJPEGBitsPerPixel)
										{
											nBitDepth = pBuffer[nSegment + 4];
										}
										nMaxHeight = (pBuffer[nSegment + 5] * 256) + pBuffer[nSegment + 6];
										nMaxWidth = (pBuffer[nSegment + 7] * 256) + pBuffer[nSegment + 8];
										break;
									}
								}
								if ((pBuffer[nSegment] == 0xff) && (pBuffer[nSegment + 1] == 0xd9))
								{
									break;
								}
								else
								{
									nLength = (pBuffer[nSegment + 2] * 256) + pBuffer[nSegment + 3];
									nSegment += nLength + 2;
								}
							}
						}
					}
				}
			}

			HDC pdc = ::CreateCompatibleDC(NULL);
#ifndef UNDER_CE
			if (m_bWaitCursor)
			{
				BeginWaitCursor();
			}

			HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwBufferSize);
			IPicture *IPicture = NULL; // Same As LPPICTURE (typedef IPicture __RPC_FAR *LPPICTURE)

			if(hGlobal != NULL)
			{
				void *pData = GlobalLock(hGlobal);
				memcpy(pData, pBuffer, dwBufferSize);
				GlobalUnlock(hGlobal);

				IStream* pStream = NULL;

				if(CreateStreamOnHGlobal(hGlobal, TRUE, &pStream) == S_OK)
				{
					hr = OleLoadPicture(pStream, dwBufferSize, FALSE, IID_IPicture, (LPVOID *)&IPicture);
					pStream->Release();
					pStream = NULL;
				}

				FreeResource(hGlobal); // 16Bit Windows Needs This (32Bit - Automatic Release)

				if(IPicture != NULL) // Do Not Try To Read From Memory That Is Not Exist...
				{ 
					OLE_HANDLE hHandle;
					IPicture->get_Handle(&hHandle);
					hLoadBitmap = CommonGetBitmapCopy((HBITMAP)hHandle);

					IPicture->Release();
					IPicture = NULL;
				}
			}


			if (m_bWaitCursor)
			{
				EndWaitCursor();
			}
#else // UNDER_CE
			if (NULL != m_procDecompressImageIndirect)
			{
				switch (nBitDepth)
				{
					case 3:
						nBitDepth = 4;
						break;
					case 5:
					case 6:
					case 7:
						nBitDepth = 8;
						break;
					default:
						break;
				}

				DecompressImageInfo dii;

				dii.dwSize =  sizeof(DecompressImageInfo);
				dii.pbBuffer = pBuffer;
				dii.dwBufferMax = dwBufferSize;
				dii.dwBufferCurrent = dwCurrentBuffer;
				dii.phBM = &hLoadBitmap;
				dii.ppImageRender = NULL;
				dii.iBitDepth = nBitDepth;
				dii.lParam = (LPARAM) hFile;
				dii.hdc = pdc;
				dii.iScale = m_nImageLoadScalePercent;
				dii.iMaxWidth = nMaxWidth;
				dii.iMaxHeight = nMaxHeight;
				dii.pfnGetData = CallbackGetImageData;
				dii.pfnImageProgress = NULL;
				dii.crTransparentOverride = -1;

				if (m_bWaitCursor)
				{
					BeginWaitCursor();
				}

				hr = m_procDecompressImageIndirect(&dii);

				if (m_bWaitCursor)
				{
					EndWaitCursor();
				}
			}
#endif // UNDER_CE
			CloseHandle(hFile);
			
			if (bTransparent)
			{
				HBITMAP cOldBitmap = (HBITMAP)::SelectObject(pdc, hLoadBitmap);
				m_ocTransparentColor = ::GetPixel(pdc, 0, 0);
				::SelectObject(pdc, cOldBitmap);
/*				DIBSECTION ds;
				if (sizeof(DIBSECTION) ==::GetObject(hLoadBitmap, sizeof(DIBSECTION), &ds))
				{
					if (8 == ds.dsBmih.biBitCount)
					{
						if (0 != ds.dsBm.bmBits)
						{
							LPBYTE ptr = (LPBYTE)ds.dsBm.bmBits;
							BYTE byTest;
							long lRowBytes = ((ds.dsBm.bmWidth + 3) / 4) * 4;
							long lPointer;
							CString strMessage;
//								strMessage.Format(TEXT("%d %d"), lRowBytes, ds.dsBm.bmWidthBytes);
//								AfxMessageBox(strMessage);
							for (long lH = 0; lH < ds.dsBm.bmHeight; lH++)
							{
								for (long lW = 0; lW < ds.dsBm.bmWidth; lW++)
								{
									lPointer = (((ds.dsBm.bmHeight - 1) - lH) * lRowBytes) + lW;
//										strMessage.Format(TEXT("x=%d, y+%d, ptr=%d, mx=%d, my=%d"), 
//											lW, lH, lPointer, ds.dsBm.bmWidth, ds.dsBm.bmHeight);
//										AfxMessageBox(strMessage);
									byTest = ptr[lPointer];
//										strMessage.Format(TEXT("%d %d"), byTransparentIndex, byTest);
//										AfxMessageBox(strMessage);
									if (byTransparentIndex == byTest)
									{
										AfxMessageBox(TEXT("got it"));
										HBITMAP cOldBitmap = (HBITMAP)::SelectObject(pdc, hLoadBitmap);
										m_ocTransparentColor = ::GetPixel(pdc, lW, lH);
										::SelectObject(pdc, cOldBitmap);
										lH = ds.dsBm.bmHeight;
										lW = ds.dsBm.bmWidth;
									}
								}
							}
						}
					}
				} */
			}

			::DeleteDC(pdc);

			if ((hLoadBitmap == NULL) && (bBitmap))
			{
				LPBITMAPFILEHEADER hdr;
				LPBITMAPINFO lpbi;
				LPVOID pBits;

				hdr = (LPBITMAPFILEHEADER)&pBuffer[0];
				int lpbiSize = sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * 3);
				lpbi = (LPBITMAPINFO) new BYTE[lpbiSize];
				memcpy(lpbi,&pBuffer[sizeof(BITMAPFILEHEADER)], lpbiSize);
				
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
						memcpy(source, &pBuffer[hdr->bfOffBits], nSize - nOffBits);
					}
				}
				delete [] lpbi;
			}

			if (m_ByteArray == NULL)
			{
				delete [] pBuffer;
			}

		}
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
#ifdef UNDER_CE
			HICON hIcon = (HICON)LoadImage(m_hInstance, MAKEINTRESOURCE(m_nResourceID), IMAGE_ICON, m_nResourceIconWidth, m_nResourceIconHeight, 0); 
			if (NULL != hIcon)
			{
				hLoadBitmap = CommonGetBitmapFromIcon(hIcon, m_nResourceIconWidth, m_nResourceIconHeight, -1, DI_NORMAL);
			}
#else // UNDER_CE
			HICON hIcon = (HICON)LoadImage(m_hInstance, MAKEINTRESOURCE(m_nResourceID), IMAGE_ICON, m_nResourceIconWidth, m_nResourceIconHeight, LR_DEFAULTCOLOR | LR_DEFAULTSIZE); 
			if (NULL != hIcon)
			{
				hLoadBitmap = CommonGetBitmapFromIcon(hIcon, 0, 0, -1, DI_NORMAL);
			}
#endif / UNDER_CE
//			HICON hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(m_nResourceID));

/*			hLoadBitmap = CommonGetBitmapClip(NULL, 0, 0, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON));
			
			HDC destDC = ::CreateCompatibleDC(NULL);

			HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hLoadBitmap);

			::DrawIconEx(destDC, 0, 0, hIcon, 0, 0, 0, NULL, DI_NORMAL);

			::SelectObject(destDC, hbmOldDest);
			::DeleteDC(destDC); */
			if (NULL != hLoadBitmap)
			{
				bCopied = true;
			}
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
				HBITMAP hNewBitmap = CommonGetBitmapCopyToNewBPP(hLoadBitmap, GetScreenBitsPerPixel());
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
		m_bWorkingCaptureScreen = FALSE;
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

HBITMAP CNSCEPictureBoxCtrl::CommonScroll(HBITMAP hBitmap)
{
	HBITMAP hReturnBitmap = NULL;

	if (hBitmap != NULL)
	{
		hReturnBitmap = CommonGetBitmapScroll(hBitmap, m_nScrollX, m_nScrollY);
		::DeleteObject(hBitmap);
	}
	return hReturnBitmap;
}

void CNSCEPictureBoxCtrl::CommonCreateFont()
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

void CNSCEPictureBoxCtrl::CommonScrollBars()
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

/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::OnDraw - Drawing function

void CNSCEPictureBoxCtrl::OnDraw(CDC* pdc, const CRect& rcSubmittedBounds, const CRect& rcInvalid)
{
	CRect rcBounds = rcSubmittedBounds;
	BITMAP Bitmap;
	CRect cRect;
	BOOL bResized = FALSE;
	BOOL b16bpp = FALSE;
	BOOL bFill = TRUE;
	int nBorderOffsetTop = 0;
	int nBorderOffsetLeft = 0;

	//#ifndef UNDER_CE
//	if (AmbientUserMode())
//	{
//		AfxMessageBox(TEXT("This version NSCE PictureBox Control is not allowed to be used as a run time control on the desktop."), MB_ICONERROR + MB_OK, 0);
//		return;
//	}
//#endif

	if (m_hBitmap == NULL)
	{
		bResized = CommonLoadImageIntoBitmap();
	}

	if (!bResized) 
	{
		bResized = CommonCheckAutoSize(TRUE);
	}

	if (bResized)
	{
		if (m_bWaitingForResize)
		{
			m_bVBCEAutoSize = TRUE;
			m_bAutoSize = FALSE;
#ifdef UNDER_CE
//			FireVBCEAutoSize(m_nAutoSizeWidth - 6, m_nAutoSizeHeight - 6);
#endif
			InvalidateControl(NULL);
		}
		else
		{
			m_bWaitingForResize = TRUE;
		}
	} 

	if (!bResized)
	{
		CommonScrollBars();

//		if (m_bVBCEAutoSize)
//		{
//			m_bVBCEAutoSize = FALSE;
//			m_bAutoSize = TRUE;
//		}

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
					bFill = FALSE;
				}
			}
					
			if (bFill)
			{
				pdc->FillSolidRect(rcBounds, TranslateColor(GetBackColor(),NULL));
			}

			m_bAnimationAvailable = FALSE;
		}		
		else
		{ 
			m_bIsStretched = FALSE;
			if (!::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap))
			{
				InvalidateControl(NULL);
			}
			else
			{
				if (Bitmap.bmBitsPixel == 16)
				{
					b16bpp = TRUE;
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
							m_bIsStretched = TRUE;
						}
						if (rcBounds.Height() != nSourceHeight)
						{
							m_bIsStretched = TRUE;
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

				BOOL bTransparent = FALSE;
				COLORREF crTransparentColor;
				if (m_ocTransparentColor < 16777216)
				{
					crTransparentColor = TranslateColor(m_ocTransparentColor, NULL);
					bTransparent = TRUE;
				}

				if ((!m_bIsStretched) && ((rcBounds.Width() > nSourceWidth) || (rcBounds.Height() > nSourceHeight)))
				{
					if (bTransparent)
					{
						if (crTransparentColor == TranslateColor(GetBackColor(),NULL))
						{
							bFill = FALSE;
						}
					}

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
					if (!bTransparent)
					{
						dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
						hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

						::StretchBlt(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, dcNew, nSourceLeft, nSourceTop, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

						::SelectObject(dcNew, hBitmap);
						::DeleteDC(dcNew);
					}
					else
					{
#ifdef UNDER_CE
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
#else // UNDER_CE
						dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
						hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

						::SelectObject(dcNew, hBitmap);
						::DeleteDC(dcNew);
#endif // UNDER_CE
					}					
				}
				else
				{  
					if (!bTransparent)
					{
						dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
						hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

						::BitBlt(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, dcNew, nSourceLeft, nSourceTop, SRCCOPY);
						
						::SelectObject(dcNew, hBitmap);
						::DeleteDC(dcNew);
					}
					else
					{
						if (nDestWidth > nSourceWidth)
							nDestWidth = nSourceWidth;
						if (nDestHeight > nSourceHeight)
							nDestHeight = nSourceHeight;

#ifdef UNDER_CE
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
#else // UNDER_CE
						dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
						hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

						::TransparentBlt(pdc->GetSafeHdc(), nDestLeft, nDestTop, nDestWidth, nDestHeight, dcNew, nSourceLeft, nSourceTop, nDestWidth, nDestHeight, crTransparentColor);

						::SelectObject(dcNew, hBitmap);
						::DeleteDC(dcNew);
#endif // UNDER_CE
					}					
				}
				
				CommonSetNewTimer();
			}
		}

		if ((m_bFocusRect) && (m_bHaveFocus))
		{
			rcBounds.DeflateRect(m_nFocusRectIndentLeft, m_nFocusRectIndentTop, m_nFocusRectIndentRight,m_nFocusRectIndentBottom);

			pdc->DrawFocusRect(rcBounds);
		}

		HFONT hOldFont = NULL;

		CommonCreateFont();
		
		if (m_hFont != NULL)
		{
			hOldFont = (HFONT)::SelectObject(pdc->GetSafeHdc(), m_hFont);
		}

		pdc->SetTextColor(TranslateColor(GetForeColor(),NULL));

		if (m_bCommandButton)
		{
			rcBounds.DeflateRect(2,2);

#ifdef UNDER_CE
			pdc->DrawText(GetText(), -1, rcBounds, DT_CENTER | DT_VCENTER);
#else
			_bstr_t bstrText = GetText();
			pdc->DrawText(bstrText, -1, rcBounds, DT_CENTER | DT_VCENTER);
#endif
		}
		else if (m_showCaption)
		{
#ifdef UNDER_CE
			pdc->DrawText(GetText(), -1, rcBounds, DT_EXPANDTABS|DT_NOCLIP|DT_WORDBREAK);
#else
			_bstr_t bstrText = GetText();
			pdc->DrawText(bstrText, -1, rcBounds, DT_EXPANDTABS|DT_NOCLIP|DT_WORDBREAK);
#endif
		}

		if (hOldFont != NULL)
		{
			::SelectObject(pdc->GetSafeHdc(), hOldFont);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::DoPropExchange - Persistence support

void CNSCEPictureBoxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	
	CString strDefault;

	BOOL bFontBold = GetFontBold();
	BOOL bFontItalic = GetFontItalic();
	BOOL bFontStrikethru = GetFontStrikethru();
	BOOL bFontUnderline = GetFontUnderline();
	long nFontSize = GetFontSize();
	long nFontWeight = GetFontWeight();
	long nFontEscapement = GetFontEscapement();
	long nFontOrientation = GetFontOrientation();
	CString strFontName = m_LogFont.lfFaceName;
	
	PX_Bool( pPX, TEXT("AutoDetectTransparency"), m_bAutoDetectTransparency, TRUE);
	PX_Bool( pPX, TEXT("AutoRefresh"), m_bAutoRefresh, TRUE);
	PX_Bool( pPX, TEXT("AutoSize"), m_bAutoSize, FALSE);
	PX_Bool( pPX, TEXT("Clip"), m_bClip, FALSE);
	PX_Bool( pPX, TEXT("CommandButton"), m_bCommandButton, FALSE);
	PX_Bool( pPX, TEXT("FocusRect"), m_bFocusRect, FALSE);
	PX_Bool( pPX, TEXT("FontBold"), bFontBold, FALSE);
	PX_Bool( pPX, TEXT("FontItalic"), bFontItalic, FALSE);
	PX_Bool( pPX, TEXT("FontStrikethru"), bFontStrikethru, FALSE);
	PX_Bool( pPX, TEXT("FontTransparent"), m_bFontTransparent, FALSE);
	PX_Bool( pPX, TEXT("FontUnderline"), bFontUnderline, FALSE);
	PX_Bool( pPX, TEXT("Invert"), m_bInvert, FALSE);
	PX_Bool( pPX, TEXT("Overlay"), m_bOverlay, FALSE);
	PX_Bool( pPX, TEXT("Resize"), m_bResize, FALSE);
	PX_Bool( pPX, TEXT("Scroll"), m_bScroll, FALSE);
	PX_Bool( pPX, TEXT("Stretch"), m_bStretch, FALSE);
//	PX_Bool( pPX, TEXT("Visible"), m_bVisible, TRUE);
	PX_Bool( pPX, TEXT("WaitCursor"), m_bWaitCursor, FALSE);
	PX_Bool( pPX, TEXT("UseJPEGBitsPerPixel"), m_bUseJPEGBitsPerPixel, FALSE);
	PX_Bool( pPX, TEXT("TapAndHoldEventEnabled"), m_bTapAndHoldEventEnabled, FALSE);

	PX_Short( pPX, TEXT("Appearance"), m_nAppearance, 0);
	PX_Short( pPX, TEXT("BorderStyle"), m_nBorderStyle, 0);
	PX_Short( pPX, TEXT("Center"), m_nCenter, 0);
	PX_Short( pPX, TEXT("CommonBitmapID"), m_nCommonBitmapID, -1);
	PX_Short( pPX, TEXT("CommonBitmapType"), m_nCommonBitmapType, 0);
	PX_Short( pPX, TEXT("FillStyle"), m_nFillStyle, 0);
	PX_Short( pPX, TEXT("Mirror"), m_nMirror, 0);
	PX_Short( pPX, TEXT("MouseMovePoints"), m_nMouseMovePoints, 2);
	PX_Short( pPX, TEXT("PenFillStyle"), m_nPenFillStyle, 1);
	PX_Short( pPX, TEXT("PenStyle"), m_nPenStyle, 1);
	PX_Short( pPX, TEXT("PlayingCard"), m_nPlayingCard, 0);
	PX_Short( pPX, TEXT("Rotate"), m_nRotate, 0);
	PX_Short( pPX, TEXT("ScrollBars"), m_nScrollBars, 0);
	PX_Short( pPX, TEXT("Wildcard"), m_nWildCard, 0);

	PX_Long( pPX, TEXT("AnimationInterval"), m_nAnimationInterval, 0);
	PX_Long( pPX, TEXT("ClipHeight"), m_nClipHeight, 0);
	PX_Long( pPX, TEXT("ClipLeft"), m_nClipLeft, 0);
	PX_Long( pPX, TEXT("ClipTop"), m_nClipTop, 0);
	PX_Long( pPX, TEXT("ClipWidth"), m_nClipWidth, 0);
	PX_Long( pPX, TEXT("DrawWidth"), m_nDrawWidth, 1);
	PX_Long( pPX, TEXT("FocusRectIndentBottom"), m_nFocusRectIndentBottom, 2);
	PX_Long( pPX, TEXT("FocusRectIndentLeft"), m_nFocusRectIndentLeft, 2);
	PX_Long( pPX, TEXT("FocusRectIndentRight"), m_nFocusRectIndentRight, 2);
	PX_Long( pPX, TEXT("FocusRectIndentTop"), m_nFocusRectIndentTop, 2);
	PX_Long( pPX, TEXT("FontEscapement"), nFontEscapement, 0);
	PX_Long( pPX, TEXT("FontOrientation"), nFontOrientation, 0);
	PX_Long( pPX, TEXT("FontSize"), nFontSize, 8);
	PX_Long( pPX, TEXT("FontWeight"), nFontWeight, 400);
	PX_Long( pPX, TEXT("ImageLoadBufferSize"), m_nImageLoadBufferSize, 0);
	PX_Long( pPX, TEXT("ImageLoadMaxHeight"), m_nImageLoadMaxHeight, 1000);
	PX_Long( pPX, TEXT("ImageLoadMaxWidth"), m_nImageLoadMaxWidth, 1000); 
	PX_Long( pPX, TEXT("ImageLoadScalePercent"), m_nImageLoadScalePercent, 100); 
	PX_Long( pPX, TEXT("OverlayLeft"), m_nOverlayLeft, 0);
	PX_Long( pPX, TEXT("OverlayTop"), m_nOverlayTop, 0);
	PX_Long( pPX, TEXT("ResizeHeight"), m_nResizeHeight, 0);
	PX_Long( pPX, TEXT("ResizeWidth"), m_nResizeWidth, 0);
	PX_Long( pPX, TEXT("ResourceBitmapID"), m_nResourceBitmapID, -1);
	PX_Long( pPX, TEXT("ResourceIconID"), m_nResourceIconID, -1);
	PX_Long( pPX, TEXT("ScrollX"), m_nScrollX, 0);
	PX_Long( pPX, TEXT("ScrollY"), m_nScrollY, 0);
	PX_Long( pPX, TEXT("URLFlags"), m_nURLFlags, INTERNET_FLAG_PASSIVE | INTERNET_FLAG_DONT_CACHE);

	PX_String(pPX, TEXT("Picture"), m_strPicture, TEXT("") );
	PX_String(pPX, TEXT("ResourceFile"), m_strResourceFile, TEXT(""));
	PX_String(pPX, TEXT("FontName"), strFontName, TEXT("Tahoma"));
	PX_String(pPX, TEXT("PlayingCardsDll"), m_strPlayingCardsDll, TEXT("Default"));
	PX_String(pPX, TEXT("URLAgent"), m_strURLAgent, TEXT("NSBasic CE PictureBox"));

	PX_Color( pPX, TEXT("FillColor"), m_ocFillColor, RGB(0,0,0));
	PX_Color( pPX, TEXT("OverlayTransparentColor"), m_ocOverlayTransparentColor, -1);
	PX_Color( pPX, TEXT("TransparentColor"), m_ocTransparentColor, -1);

	m_bWorkingPropExchange = TRUE;
	SetFontBold(bFontBold);
	SetFontItalic(bFontItalic);
	SetFontStrikethru(bFontStrikethru);
	SetFontUnderline(bFontUnderline);
	SetFontSize(nFontSize);
	SetFontWeight(nFontWeight);
	SetFontEscapement(nFontEscapement);
	SetFontOrientation(nFontOrientation);
	SetFontName((LPCTSTR)strFontName);
	m_bWorkingPropExchange = FALSE;

#ifdef UNDER_CE
	m_bVBCE = TRUE;
#endif

	if (!m_strPicture.IsEmpty())
	{
		SetPicture(m_strPicture);
	}

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
/* #ifdef UNDER_CE
	if (m_bVBCE && m_bVisible)
	{
		(CWnd *)this->GetParent()->ShowWindow(SW_SHOWNORMAL);
//		(CWnd *)this->ShowWindow(SW_SHOW);
	}
#endif //  UNDER_CE
*/
}

/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::OnResetState - Reset control to default state

void CNSCEPictureBoxCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl::AboutBox - Display an "About" box to the user

void CNSCEPictureBoxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_NSCEPICTUREBOX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl message handlers

#if 0
void CNSCEPictureBoxCtrl::Decorate() 
{
	// TODO: Add your dispatch handler code here
	CWnd *pCWnd = (CWnd *)new(CWnd);

	pCWnd->CreateEx(0, L"BUTTON", _T("Nose"), WS_VISIBLE|WS_CHILD|BS_GROUPBOX,
		10, 40, 200, 200, m_hWnd, (HMENU)37, 0 );
	pCWnd->BringWindowToTop();

	CWnd *subWind;

	subWind = new CWnd;
	subWind->CreateEx(0, L"BUTTON", _T("Option 1"), WS_VISIBLE|WS_CHILD|WS_TABSTOP|BS_AUTORADIOBUTTON|BS_NOTIFY,
		10, 40, 100, 20, pCWnd -> m_hWnd, (HMENU)38, 0 );
	subWind->BringWindowToTop();

	subWind = new CWnd;
	subWind->CreateEx(0, L"BUTTON", _T("Option 2"), WS_VISIBLE|WS_CHILD|WS_GROUP|WS_TABSTOP|BS_AUTORADIOBUTTON|BS_NOTIFY,
		10, 70, 100, 20, pCWnd -> m_hWnd, (HMENU)39, 0 );
	subWind->BringWindowToTop();


}
#endif

void CNSCEPictureBoxCtrl::OnShowCaptionChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetWidth() 
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

void CNSCEPictureBoxCtrl::SetWidth(long nNewValue) 
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
	SetScaleMode(m_scaleMode);
//	int nH, nW;
//	GetControlSize(&nW, &nH);
//	SetControlSize(nNewValue, nH);
//	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetHeight() 
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

void CNSCEPictureBoxCtrl::SetHeight(long nNewValue) 
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
	SetScaleMode(m_scaleMode);
//	int nH, nW;
//	GetControlSize(&nW, &nH);
//	SetControlSize(nW, nNewValue);
//	SetModifiedFlag();
}

BSTR CNSCEPictureBoxCtrl::GetFontName() 
{
	CString strResult;

	strResult = m_LogFont.lfFaceName;

	return strResult.AllocSysString();
}

void CNSCEPictureBoxCtrl::SetFontName(LPCTSTR lpszNewValue) 
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

void CNSCEPictureBoxCtrl::CommonSetNewTimer()
{
	BOOL bKillTimer = TRUE;

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
				AnimatePlayingCard(FALSE, m_hBitmap);
			}
		}
	}

	if ((m_nWorkingAnimationInterval > 0) && (m_bAnimationAvailable) && (m_bVisible))
	{
		if (m_nTimer == 0)
		{
			m_nTimer = SetTimer(2, m_nWorkingAnimationInterval, NULL);
		}
		bKillTimer = FALSE;
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

void CNSCEPictureBoxCtrl::CommonDestroyFont()
{
	if (m_hFont != NULL)
	{
		::DeleteObject(m_hFont);
		m_hFont = NULL;
	}
}

int CNSCEPictureBoxCtrl::CallbackEnumFontFamilyCallback1(ENUMLOGFONT *lpelf, NEWTEXTMETRIC *lpntm, int FontType,  LPARAM lParam)
{
	int nReturn = 1;

	if (FontType == TRUETYPE_FONTTYPE)
	{
		CNSCEPictureBoxCtrl* lpNSCEPictureBox = (CNSCEPictureBoxCtrl*)lParam;

		nReturn = lpNSCEPictureBox->m_strFontResult.CompareNoCase(lpelf->elfLogFont.lfFaceName);

		if (nReturn == 0)
		{
			lpNSCEPictureBox->m_LogFont.lfCharSet = lpntm->tmCharSet;
			lpNSCEPictureBox->m_LogFont.lfPitchAndFamily = lpntm->tmPitchAndFamily;
			_tcscpy(lpNSCEPictureBox->m_LogFont.lfFaceName, lpelf->elfLogFont.lfFaceName);	
		}
	}

	return nReturn;
}

void CNSCEPictureBoxCtrl::AnimatePlayingCard(BOOL bInvalidateControl, HBITMAP hBitmap)
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
	BOOL	bInvert = FALSE;
	BOOL	bOriginal = FALSE;
	BOOL	bSwapBitmap[2];

#ifndef WIN32_PLATFORM_PSPC
	HBITMAP hBitmap1, hBitmap2;
#endif

	if ((m_hPlayingCardsDll != NULL) && (m_bWorkingAnimationAvailable))
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = TRUE;
				bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = TRUE;
				bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
									break;
								case 2:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
									break;
								case 2:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = FALSE;
								case 2:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = FALSE;
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
							m_bWorkingAnimationInitialized = FALSE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							if (m_nWorkingAnimationCount > 1)
							{
								m_nWorkingAnimationCount = 0;
							}
							bSwapBitmap[0] = TRUE;
							bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = TRUE;
				bSwapBitmap[1] = FALSE;
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

						m_bWorkingAnimationInvert = FALSE;
						m_nWorkingAnimationRotate = 0;
						m_nWorkingAnimationMirror = 0;
						m_bWorkingAnimationInitialized = TRUE;
					}
					switch (m_nWorkingAnimationCount)
					{
						case 1:
							bSwapBitmap[0] = TRUE;
							bSwapBitmap[1] = FALSE;
							break;
						case 2:
							bSwapBitmap[0] = TRUE;
							bSwapBitmap[1] = FALSE;
							m_nWorkingAnimationCount = 0;
							break;
					}
					if (m_nWorkingAnimationCount == 0)
					{
						if (m_nWorkingWildCard != m_nWildCard)
						{
							m_nWorkingWildCard = m_nWildCard;
							m_bWorkingAnimationInitialized = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				if (m_nWorkingAnimationCount > 1)
				{
					m_nWorkingAnimationCount = 0;
				}
				bSwapBitmap[0] = TRUE;
				bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

					m_bWorkingAnimationInvert = FALSE;
					m_nWorkingAnimationRotate = 0;
					m_nWorkingAnimationMirror = 0;
					m_bWorkingAnimationInitialized = TRUE;
				}
				switch (m_nWorkingAnimationCount)
				{
					case 1: // swap orig and bitmap 1
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
						break;
					case 2: // swap bitmap 1 and bitmap 2
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					case 3: // swap bitmap 2 and bitmap 1
						bSwapBitmap[0] = FALSE;
						bSwapBitmap[1] = TRUE;
						break;
					default: // swap bitmap 1 and orig
						bSwapBitmap[0] = TRUE;
						bSwapBitmap[1] = FALSE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
									break;
								case 2:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
									break;
								case 2:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = TRUE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							switch (m_nWorkingAnimationCount)
							{
								case 1:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = FALSE;
									break;
								case 2:
									bSwapBitmap[0] = TRUE;
									bSwapBitmap[1] = FALSE;
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
							m_bWorkingAnimationInitialized = FALSE;
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

								m_bWorkingAnimationInvert = FALSE;
								m_nWorkingAnimationRotate = 0;
								m_nWorkingAnimationMirror = 0;
								m_bWorkingAnimationInitialized = TRUE;
							}
							if (m_nWorkingAnimationCount > 1)
							{
								m_nWorkingAnimationCount = 0;
							}
							bSwapBitmap[0] = TRUE;
							bSwapBitmap[1] = FALSE;
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

void CNSCEPictureBoxCtrl::AnimateCheckInvert()
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

void CNSCEPictureBoxCtrl::AnimateCheckMirror()
{
	HBITMAP hBitmap;
	int nOffset = 0;
	int nTop, nLeft, nWidth, nHeight;

	if (m_nWorkingAnimationMirror != m_nWorkingMirror)
	{
		nOffset = (m_nWorkingMirror ^ m_nWorkingAnimationMirror);
//	TCHAR msg[100];
//		swprintf(msg, TEXT("%d %d %d\0"),nOffset,m_nWorkingMirror,m_nWorkingAnimationMirror);
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapResource(int nResource)
{
	HBITMAP hBitmap = NULL;
	HBITMAP hLoadedBitmap = NULL;
	HINSTANCE hInst = NULL;


	if ((nResource >= IDACLUBS) && (nResource <= IDKSPADES))
	{
		hInst = m_hPlayingCardsDll;
	}
#ifdef UNDER_CE 
	if ((nResource >= IDFACEDOWNFIRST) && (nResource <= IDFACEDOWNLAST))
	{
		hInst = m_hPlayingCardsDll;
	}
	if ((nResource >= 69) && (nResource <= 70))
	{
		hInst = m_hPlayingCardsDll;
	}
	if ((nResource >= IDANNFACE2_1) && (nResource <= IDANNFACE5_2))
	{
		hInst = m_hPlayingCardsDll;
	}
	if ((nResource >= IDCARDO) && (nResource <= IDCARDGHOST))
	{
		hInst = m_hPlayingCardsDll;
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
		hInst = m_hPlayingCardsDll;
	}
	if ((nResource >= 67) && (nResource <= 68))
	{
		hInst = m_hPlayingCardsDll;
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
		hInst = m_hPlayingCardsDll;
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

void CNSCEPictureBoxCtrl::AnimateCheckRotate()
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
//rotate				hBitmap = CommonGetBitmapRotated(m_hWorkingAnimationBitmap[i], nOffset);
				CNSCEBitmap *pOld = new CNSCEBitmap;
				if (NULL != pOld)
				{
					pOld->SetHBITMAP(m_hWorkingAnimationBitmap[i]);
					CNSCEBitmap *pNew = pOld->Rotate(nOffset);
					if (NULL != pNew)
					{
						hBitmap = pNew->TakeHBITMAP();
						delete pNew;
					}
					pOld->TakeHBITMAP();
					delete pOld;
				}

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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapMirrored(HBITMAP hBitmap, short nMirror)
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapRotated(HBITMAP hBitmap, int degrees)
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapInverted(HBITMAP hBitmap)
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapCopy(HBITMAP hBitmap)
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapCopyToNewBPP(HBITMAP hBitmap, short nBPP)
{
	BITMAP bm;

	HDC sourceDC = ::CreateCompatibleDC(NULL);
	HDC destDC = ::CreateCompatibleDC(NULL);
//	HDC sourceDC = ::CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
//	HDC destDC = ::CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
//	if ((sourceDC == NULL) || (destDC == NULL))
//	{
//		AfxMessageBox("dc == NULL");
//	}
	::GetObject(hBitmap, sizeof(bm), &bm);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject(sourceDC, hBitmap);

//	HBITMAP hbmResult = ::CreateCompatibleBitmap(sourceDC, bm.bmWidth, bm.bmHeight);
	HBITMAP	hbmResult = ::CreateBitmap(bm.bmWidth, bm.bmHeight, 1, nBPP, NULL);
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject(destDC, hbmResult);

//	if (hbmResult == NULL)
//	{
//		AfxMessageBox("hbmResult == NULL");
//	}

	if (::BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC, 0, 0, SRCCOPY) == 0)
	{
//		CString str;
//		str.Format(TEXT("GetLastError=%d"), GetLastError());
//		AfxMessageBox(str);
	}

	::SelectObject(sourceDC, hbmOldSource);
	::DeleteDC(sourceDC);

	::SelectObject(destDC, hbmOldDest);
	::DeleteDC(destDC);

	return hbmResult;
}

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapClip(HBITMAP hBitmap, int nLeft, int nTop, int nWidth, int nHeight)
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
#ifdef UNDER_CE
			HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);
#else
			HDC sourceDC = ::CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
#endif
			//hbmResult = ::CreateBitmap(nWidth + nLeft, nHeight + nTop, 1, m_nImageLoadBitsPerPixel /*24*/, NULL);
			hbmResult = ::CreateCompatibleBitmap(sourceDC, nWidth + nLeft, nHeight + nTop);
			::DeleteDC(sourceDC);
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

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapOverlay(HBITMAP hDestBitmap, HBITMAP hSourceBitmap, int nLeft, int nTop, int nWidth, int nHeight, OLE_COLOR ocTransparent)
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
#else // UNDER_CE
		::TransparentBlt(destDC->GetSafeHdc(), nLeft, nTop, nWidth, nHeight, sourceDC->GetSafeHdc(), 0, 0, nWidth, nHeight, TranslateColor(ocTransparent, NULL));
#endif // UNDER_CE
	}

	::SelectObject(sourceDC->GetSafeHdc(), hbmOldSource);
	::SelectObject(destDC->GetSafeHdc(), hbmOldDest);

	delete sourceDC;
	delete destDC;

	return hbmResult;
}

HBITMAP CNSCEPictureBoxCtrl::CommonGetBitmapResize(HBITMAP hBitmap, int nWidth, int nHeight)
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

long CNSCEPictureBoxCtrl::GetFontSize() 
{
	long nReturn = (long)((-1.0 * ((double)(m_LogFont.lfHeight * 72) / (double)(m_nLogPixelsY))) + 0.5);
////	long nReturn = -1 * (m_LogFont.lfHeight * 72 / m_nLogPixelsY); 
//#ifndef UNDER_CE
//	long nTemp = -MulDiv(nReturn, m_nLogPixelsY, 72);
//#else // UNDER_CE
//	long nTemp = -1 * (long)(((double)(nReturn * m_nLogPixelsY) / 72.0) + 0.5);
//	long nTemp = -1 * (nReturn * m_nLogPixelsY / 72);
//#endif // UNDER_CE
//	if (nTemp != m_LogFont.lfHeight)
//		nReturn++;
	return nReturn;
}

void CNSCEPictureBoxCtrl::SetFontSize(long nNewValue) 
{
	CommonDestroyFont();

#ifndef UNDER_CE
	m_LogFont.lfHeight = -MulDiv(nNewValue, m_nLogPixelsY, 72);
#else // UNDER_CE
	m_LogFont.lfHeight = -1 * (long)(((double)(nNewValue * m_nLogPixelsY) / 72.0) + 0.5);
//	m_LogFont.lfHeight = -1 * (nNewValue * m_nLogPixelsY / 72);
#endif // UNDER_CE

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

long CNSCEPictureBoxCtrl::GetImageHeight() 
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

long CNSCEPictureBoxCtrl::GetImageWidth() 
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

void CNSCEPictureBoxCtrl::MethodStopUrlStream() 
{
	CUrlImage *pUrlImage = m_pUrlImage;
	if (NULL != pUrlImage)
	{ 
		m_cs.Lock();
		m_pUrlImage = NULL;
		pUrlImage->Abort(TRUE);
		m_cs.Unlock();
	}
}


void CNSCEPictureBoxCtrl::Animate() 
{
	if ((m_bVisible) && (m_bWorkingAnimationAvailable))
	{
		AnimatePlayingCard(TRUE, m_hBitmap);
	}
}

BOOL CNSCEPictureBoxCtrl::GetAnimationAvailable() 
{
	return m_bAnimationAvailable;
}


long CNSCEPictureBoxCtrl::GetAnimationInterval() 
{
	return m_nAnimationInterval;
}

void CNSCEPictureBoxCtrl::SetAnimationInterval(long nNewValue) 
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

short CNSCEPictureBoxCtrl::GetAppearance() 
{
	return m_nAppearance;
}

void CNSCEPictureBoxCtrl::SetAppearance(short nNewValue) 
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

BOOL CNSCEPictureBoxCtrl::GetAutoDetectTransparency() 
{
	return m_bAutoDetectTransparency;
}

void CNSCEPictureBoxCtrl::SetAutoDetectTransparency(BOOL bNewValue) 
{
	m_bAutoDetectTransparency = bNewValue;
	SetModifiedFlag();
	CommonDesignRefresh();
}

BOOL CNSCEPictureBoxCtrl::GetAutoRefresh() 
{
	return m_bAutoRefresh;
}

void CNSCEPictureBoxCtrl::SetAutoRefresh(BOOL bNewValue) 
{
	m_bAutoRefresh = bNewValue;
	if (m_bAutoRefresh)
	{
		if (!CommonCheckAutoSize(FALSE))
		{
			InvalidateControl(NULL);
		}
	}
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetAutoSize() 
{
	return ((m_bAutoSize) || (m_bVBCEAutoSize));
}

void CNSCEPictureBoxCtrl::SetAutoSize(BOOL bNewValue) 
{
	m_bAutoSize = bNewValue;
	m_bVBCEAutoSize = FALSE;
	SetModifiedFlag();

	CommonDesignRefresh();
}

BOOL CNSCEPictureBoxCtrl::GetBitmapOnClipboard() 
{
	return IsClipboardFormatAvailable(CF_BITMAP);
}

short CNSCEPictureBoxCtrl::GetBorderStyle() 
{
	return m_nBorderStyle;
}

void CNSCEPictureBoxCtrl::SetBorderStyle(short nNewValue) 
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

VARIANT CNSCEPictureBoxCtrl::GetByteArray() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);
	HRESULT bhr = NOERROR;
	LPSAFEARRAY bpsa;
	SAFEARRAYBOUND brgsabound[1];

	if (CommonSaveImageToByteArray())
	{
		brgsabound[0].cElements = m_nByteArray;
		brgsabound[0].lLbound = 0;
		bpsa = ::SafeArrayCreate(VT_VARIANT, 1, brgsabound);
		if (!bpsa)
		{
			if (m_ByteArray != NULL)
			{
				delete [] m_ByteArray;
				m_ByteArray = NULL;
				m_nByteArray = 0;
			}
			return vaResult;
		}
		if (FAILED(bhr = ::SafeArrayLock(bpsa)))
		{
			if (m_ByteArray != NULL)
			{
				delete [] m_ByteArray;
				m_ByteArray = NULL;
				m_nByteArray = 0;
			}
			return vaResult;
		}
		long nbIndex[1];
		LPVARIANT lpbVar;

		for (long j = 0; j < m_nByteArray; j++)
		{
			nbIndex[0] = j;
			::SafeArrayPtrOfIndex(bpsa, nbIndex, (LPVOID*)&lpbVar);	
			V_VT(lpbVar) = VT_UI1;
			V_UI1(lpbVar) = m_ByteArray[j];
		}
		::SafeArrayUnlock(bpsa);
		V_VT(&vaResult) = VT_ARRAY | VT_VARIANT;
		V_ARRAY(&vaResult) = bpsa;
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Out of Memory"), 0);
	}

	if (m_ByteArray != NULL)
	{
		delete [] m_ByteArray;
		m_ByteArray = NULL;
		m_nByteArray = 0;
	}

	return vaResult;
}

void CNSCEPictureBoxCtrl::SetByteArray(const VARIANT FAR& newValue) 
{
	long lBound;
	long uBound;
	long index;
	long byteindex;

	HRESULT bhr = NOERROR;
	SAFEARRAY *bpsa;
	VARIANT *pVariant;
	VARIANT varElement;
	
	if ((V_VT(&newValue) & (VT_ARRAY | VT_VARIANT)) != (VT_ARRAY | VT_VARIANT))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Value passed is not a variant array"), 0);
		return;
	}

	if (V_VT(&newValue) & VT_BYREF)
	{
		bpsa = *(V_ARRAYREF(&newValue));
	}
	else
	{
		bpsa = V_ARRAY(&newValue);
	}

	bhr = SafeArrayAccessData(bpsa, (void HUGEP* FAR*)&pVariant); // access the data and lock the array
	if (FAILED(bhr))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Cannot access SAFEARRAY."), 0);
		return;
	}

	if(SafeArrayGetDim(bpsa) != 1)  // is it a one dimesnsional array?
	{
		SafeArrayUnaccessData(bpsa); // unaccess the data and unlock the array
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Array not one dimensional"), 0);
		return;
	}

    bhr = SafeArrayGetLBound(bpsa, 1, &lBound); // get lower bounds of the array
	if(FAILED(bhr))
	{
		SafeArrayUnaccessData(bpsa); // unaccess the data and unlock the array
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Cannot access Lower Bounds of array"), 0);
		return;
	}

	bhr = SafeArrayGetUBound(bpsa, 1, &uBound); // get upper bounds of the array
	if(FAILED(bhr))
	{
		SafeArrayUnaccessData(bpsa); // unaccess the data and unlock the array
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Cannot access Upper Bounds of array"), 0);
		return;
	}

	if (m_ByteArray != NULL)
	{
		delete [] m_ByteArray;
		m_ByteArray = NULL;
		m_nByteArray = 0;
	}

	CommonClearForLoad();

	m_nByteArray = (uBound - lBound) + 1;
	m_ByteArray = new BYTE[m_nByteArray]; // alloc storage for bytes

	bool bGood = true;
	byteindex = 0;
	for (index = lBound; index <= uBound; index++)
	{
		bhr = SafeArrayGetElement(bpsa, &index, &varElement);  // get the element
		if(FAILED(bhr))
		{
			ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Cannot access an element of array"), 0);
			bGood = false;
			break;
		}
		else
		{
			if (V_VT(&varElement) == VT_UI1) // make sure it is a byte variant
			{
				m_ByteArray[byteindex] = V_UI1(&varElement);
			}
			else
			{
				ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Element not a byte (UI1)"), 0);
				bGood = false;
				break;
			}
		}
		byteindex++;
	}

	SafeArrayUnaccessData(bpsa); // unaccess the data and unlock the array

	if (bGood)
	{
		m_bDisplayExpired = true;

		if (!CommonLoadImageIntoBitmap())
		{
			InvalidateControl(NULL);
		}
	}

	if (m_ByteArray != NULL)
	{
		delete [] m_ByteArray;
		m_ByteArray = NULL;
		m_nByteArray = 0;
	}
}

void CNSCEPictureBoxCtrl::MethodCaptureScreen() 
{
	CommonClearForLoad();

	m_bWorkingCaptureScreen = true;

	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

short CNSCEPictureBoxCtrl::GetCenter() 
{
	return m_nCenter;
}

void CNSCEPictureBoxCtrl::SetCenter(short nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 3))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nCenter = nNewValue;
		SetModifiedFlag();
		CommonDesignRefresh();
	}
}

long CNSCEPictureBoxCtrl::GetClipTop() 
{
	return m_nClipTop;
}

void CNSCEPictureBoxCtrl::SetClipTop(long nNewValue) 
{
	m_nClipTop = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetClipLeft() 
{
	return m_nClipLeft;
}

void CNSCEPictureBoxCtrl::SetClipLeft(long nNewValue) 
{
	m_nClipLeft = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetClipHeight() 
{
	return m_nClipHeight;
}

void CNSCEPictureBoxCtrl::SetClipHeight(long nNewValue) 
{
	m_nClipHeight = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetClipWidth() 
{
	return m_nClipWidth;
}

void CNSCEPictureBoxCtrl::SetClipWidth(long nNewValue) 
{
	m_nClipWidth = nNewValue;
	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::MethodClipImage() 
{
	m_hBitmap = CommonClip(m_hBitmap);
	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

BOOL CNSCEPictureBoxCtrl::GetClip() 
{
	return m_bClip;
}

void CNSCEPictureBoxCtrl::SetClip(BOOL bNewValue) 
{
	m_bClip = bNewValue;
	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::MethodCls() 
{
	CommonClearForLoad();
	
	if (m_hBitmap != NULL)
	{
		::DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}

	m_nDrawTextCurrentY = 0;
	SetText("");
//	m_nWorkingScrollBars = -1;
//	CommonSetWindowLong();

	InvalidateControl(NULL);
}

BOOL CNSCEPictureBoxCtrl::GetCommandButton() 
{
	return m_bCommandButton;
}

void CNSCEPictureBoxCtrl::SetCommandButton(BOOL bNewValue) 
{
	m_bCommandButton = bNewValue;
	if (m_bCommandButton)
		m_bFocusRect = TRUE;	
	SetModifiedFlag();

	CommonDesignRefresh();
}

short CNSCEPictureBoxCtrl::GetCommonBitmapID() 
{
	return m_nCommonBitmapID;
}

void CNSCEPictureBoxCtrl::SetCommonBitmapID(short nNewValue) 
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
	m_bDisplayExpired = TRUE;
	m_bWorkingClip = TRUE;
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

short CNSCEPictureBoxCtrl::GetCommonBitmapType() 
{
	return m_nCommonBitmapType;
}

void CNSCEPictureBoxCtrl::SetCommonBitmapType(short nNewValue) 
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

BOOL CNSCEPictureBoxCtrl::MethodCopy() 
{
	BOOL bReturn = FALSE;
	if ((::OpenClipboard(NULL)) && (m_hBitmap != NULL))
	{
		::EmptyClipboard();

		HBITMAP hBitmap = CommonGetBitmapCopy(m_hBitmap);
		bReturn = TRUE;
		if (::SetClipboardData(CF_BITMAP, hBitmap) == NULL)
		{
			::DeleteObject(hBitmap);
			bReturn = FALSE;
		}
		::CloseClipboard();
	}
	return bReturn;
}

BOOL CNSCEPictureBoxCtrl::MethodPaste() 
{
	BOOL bReturn = FALSE;
	if (::OpenClipboard(NULL))
	{
		HBITMAP hClipboardBitmap = (HBITMAP)::GetClipboardData(CF_BITMAP);

		if (hClipboardBitmap != NULL)
		{
			CommonClearForLoad();

			m_hWorkingBitmap = hClipboardBitmap;
		
			bReturn = TRUE;

			if (!CommonLoadImageIntoBitmap())
			{
				InvalidateControl(NULL);
			}
		}
		::CloseClipboard();
	}
	return bReturn;
}

void CNSCEPictureBoxCtrl::MethodCreateImage(long nX, long nY) 
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

void CNSCEPictureBoxCtrl::MethodData(const VARIANT FAR& varData, const VARIANT FAR& varDataLength) 
{
	if ((V_VT(&varData) & VT_BSTR) == VT_BSTR)
	{
		VARIANT vaTemp;
		::VariantInit(&vaTemp);
		if (::VariantChangeType(&vaTemp, const_cast <struct tagVARIANT *>(&varData), 0, VT_BSTR) == S_OK)
		{
			long lLength = ::SysStringByteLen(V_BSTR(&vaTemp));

			lLength = CommonOptionalLong(&varDataLength, lLength);
			m_bDisplayExpired = TRUE;

			CommonClearForLoad();
			m_nByteArray = lLength;
			m_ByteArray = (BYTE *)V_BSTR(&vaTemp);

			if ((m_ByteArray[1] == 0x00) && 
				(m_ByteArray[3] == 0x00) && 
				(m_ByteArray[5] == 0x00) && 
				(m_ByteArray[7] == 0x00))
			{
				lLength = ::SysStringLen(V_BSTR(&vaTemp));

				m_ByteArray = new BYTE[lLength + 1];
				m_nByteArray = lLength;
				if (m_ByteArray != NULL)
				{	
					for (long lIndex = 0; lIndex < lLength; lIndex++)
					{
#ifdef UNDER_CE
						m_ByteArray[lIndex] = (BYTE)V_BSTR(&vaTemp)[lIndex];
#else // UNDER_CE
						wctomb((char *)(m_ByteArray + lIndex), V_BSTR(&vaTemp)[lIndex]);
#endif // UNDER_CE
					}
					if (!CommonLoadImageIntoBitmap())
					{
						InvalidateControl(NULL);
					}

					delete m_ByteArray;
				}
			}
			else
			{
				if (!CommonLoadImageIntoBitmap())
				{
					InvalidateControl(NULL);
				}
			}
			m_ByteArray = NULL;
			m_nByteArray = 0;
			VariantClear(&vaTemp);
		}
	}
	else
	{
		CString strMessage;
		strMessage.Format(TEXT("Error: V_VT = %d"), V_VT(&varData));
		AfxMessageBox(strMessage);
	}
}

void CNSCEPictureBoxCtrl::MethodDrawCircle(float x, float y, float flRadius, const VARIANT FAR& vocColor, const VARIANT FAR& vflAspect) 
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
		float nRadius = (float)(flRadius * flAspectRatio);
		nTop = TransformPassedY(y - nRadius);
		nBottom = TransformPassedY(y + nRadius);
		nLeft = TransformPassedX(x - flRadius);
		nRight = TransformPassedX(x + flRadius);
	}
	else
	{
		float nRadius = (float)(flRadius / flAspectRatio);
		nTop = TransformPassedY(y - flRadius);
		nBottom = TransformPassedY(y + flRadius);
		nLeft = TransformPassedX(x - nRadius);
		nRight = TransformPassedX(x + nRadius);
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

	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

#if 0
static LPICONRESOURCE ReadIconFromICOFile( LPCTSTR szFileName ) {
     LPICONRESOURCE
    lpIR = NULL, lpNew = NULL;
     HANDLE
            hFile = NULL;
     UINT
                i;
     DWORD
            dwBytesRead;
     LPICONDIRENTRY
    lpIDE = NULL;
       // Open the file
     if( (hFile = CreateFile( szFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL )) == INVALID_HANDLE_VALUE )
     {
         MessageBox( NULL, "Error Opening File for Reading", szFileName, MB_OK );
         return NULL;
     }
     // Allocate memory for the resource structure
     if( (lpIR = malloc( sizeof(ICONRESOURCE) )) == NULL )
     {
         MessageBox( NULL, "Error Allocating Memory", szFileName, MB_OK );
         CloseHandle( hFile );
         return NULL;
     }
     // Read in the header
     if( (lpIR->nNumImages = ReadICOHeader( hFile )) == (UINT)-1 )
     {
         MessageBox( NULL, "Error Reading File Header", szFileName, MB_OK );
         CloseHandle( hFile );
         free( lpIR );
         return NULL;
     }
     // Adjust the size of the struct to account for the images
     if( (lpNew = realloc( lpIR, sizeof(ICONRESOURCE) + ((lpIR->nNumImages-1) * sizeof(ICONIMAGE)) )) == NULL )
     {
         MessageBox( NULL, "Error Allocating Memory", szFileName, MB_OK );
         CloseHandle( hFile );
         free( lpIR );
         return NULL;
     }
     lpIR = lpNew;
     // Store the original name
     lstrcpy( lpIR->szOriginalICOFileName, szFileName );
     lstrcpy( lpIR->szOriginalDLLFileName, "" );
     // Allocate enough memory for the icon directory entries
     if( (lpIDE = malloc( lpIR->nNumImages * sizeof( ICONDIRENTRY ) ) ) == NULL )
     {
         MessageBox( NULL, "Error Allocating Memory", szFileName, MB_OK );
         CloseHandle( hFile );
         free( lpIR );
         return NULL;
     }
     // Read in the icon directory entries
     if( ! ReadFile( hFile, lpIDE, lpIR->nNumImages * sizeof( ICONDIRENTRY ), &dwBytesRead, NULL ) )
     {
         MessageBox( NULL, "Error Reading File", szFileName, MB_OK );
         CloseHandle( hFile );
         free( lpIR );
         return NULL;
     }
     if( dwBytesRead != lpIR->nNumImages * sizeof( ICONDIRENTRY ) )
     {
         MessageBox( NULL, "Error Reading File", szFileName, MB_OK );
         CloseHandle( hFile );
         free( lpIR );
         return NULL;
     }
     // Loop through and read in each image
     for( i = 0; i < lpIR->nNumImages; i++ )
     {
         // Allocate memory for the resource
         if( (lpIR->IconImages[i].lpBits = malloc(lpIDE[i].dwBytesInRes)) == NULL )
         {
             MessageBox( NULL, "Error Allocating Memory", szFileName, MB_OK );
             CloseHandle( hFile );
             free( lpIR );
             free( lpIDE );
             return NULL;
         }
         lpIR->IconImages[i].dwNumBytes = lpIDE[i].dwBytesInRes;
         // Seek to beginning of this image
         if( SetFilePointer( hFile, lpIDE[i].dwImageOffset, NULL, FILE_BEGIN ) == 0xFFFFFFFF )
         {
             MessageBox( NULL, "Error Seeking in File", szFileName, MB_OK );
             CloseHandle( hFile );
             free( lpIR );
             free( lpIDE );
             return NULL;
         }
         // Read it in
         if( ! ReadFile( hFile, lpIR->IconImages[i].lpBits, lpIDE[i].dwBytesInRes, &dwBytesRead, NULL ) )
         {
             MessageBox( NULL, "Error Reading File", szFileName, MB_OK );
             CloseHandle( hFile );
             free( lpIR );
             free( lpIDE );
             return NULL;
         }
         if( dwBytesRead != lpIDE[i].dwBytesInRes )
         {
             MessageBox( NULL, "Error Reading File", szFileName, MB_OK );
             CloseHandle( hFile );
             free( lpIDE );
             free( lpIR );
             return NULL;
         }
         // Set the internal pointers appropriately
         if( ! AdjustIconImagePointers( &(lpIR->IconImages[i]) ) )
         {
             MessageBox( NULL, "Error Converting to Internal Format", szFileName, MB_OK );
             CloseHandle( hFile );
             free( lpIDE );
             free( lpIR );
             return NULL;
         }
     }
     // Clean up
     free( lpIDE );
     CloseHandle( hFile );
     return lpIR;
} /* End ReadIconFromICOFile() **********************************************/  
#endif

BOOL CNSCEPictureBoxCtrl::MethodDrawIcon(LPCTSTR szFile, const VARIANT FAR& vIconID, const VARIANT FAR& vLarge, const VARIANT FAR& vocColor, const VARIANT FAR& vDrawType) 
{
	BOOL bReturn = FALSE;

	bool bLarge = CommonOptionalBool(&vLarge, false);
	long nIconID = CommonOptionalLong(&vIconID, 0);
	short x = 0;
	short y = 0;

	HICON hLarge = NULL;
	HICON hSmall = NULL;
	HICON hIcon = NULL;

	HICON hxIcon = NULL;
	UINT nIcons = 0;
#ifdef UNDER_CE
 #if _WIN32_WCE > 210 
	if (nIconID > 0)
	{
		nIconID = nIconID * -1;
	}
  #ifdef WIN32_PLATFORM_PSPC
	hxIcon = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
  #else // WIN32_PLATFORM_PSPC
   #if _WIN32_WCE < 301
	nIcons = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
   #else // _WIN32_WCE < 301
	hxIcon = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
   #endif // _WIN32_WCE < 301
  #endif // WIN32_PLATFORM_PSPC
 #else // _WIN32_WCE > 210
	nIcons = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
 #endif //  _WIN32_WCE > 210
#else // UNDER_CE
	nIcons = ::ExtractIconEx(szFile, nIconID, &hLarge, &hSmall, 1);
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

	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, -1);
	long nDrawType = CommonOptionalLong(&vDrawType, DI_NORMAL);

	if (NULL != hIcon)
	{
		m_hWorkingIconBitmap = CommonGetBitmapFromIcon(hIcon, x, y, ocColor, nDrawType);

		::DestroyIcon(hIcon);

		if (NULL == m_hWorkingIconBitmap)
		{
			ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		}
		else
		{
			m_bDisplayExpired = TRUE;
			if (!CommonLoadImageIntoBitmap())
			{
				InvalidateControl(NULL);
			}

			::DeleteObject(m_hWorkingIconBitmap);
			m_hWorkingIconBitmap = NULL;

			bReturn = TRUE;
		}
	}

	return bReturn;
}

void CNSCEPictureBoxCtrl::MethodDrawLine(float fromX, float fromY, float toX, float toY, const VARIANT FAR& vocColor, const VARIANT FAR& vBox, const VARIANT FAR& vFill) 
{
	long nFromX = TransformPassedX(fromX);
	long nFromY = TransformPassedY(fromY);
	long nToX = TransformPassedX(toX);
	long nToY = TransformPassedY(toY);
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

		if (!CommonCheckAutoSize(FALSE))
		{
			InvalidateControl(NULL);
		}
	}
}

void CNSCEPictureBoxCtrl::MethodDrawMouseMoveLinesEx(long nStartX, long nStartY, long nEndX, long nEndY, OLE_COLOR ocColor) 
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

void CNSCEPictureBoxCtrl::MethodDrawMouseMoveLines(OLE_COLOR ocColor) 
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

long CNSCEPictureBoxCtrl::GetScreenHeight() 
{
	return GetSystemMetrics(SM_CYSCREEN);
}

long CNSCEPictureBoxCtrl::GetScreenWidth() 
{
	return GetSystemMetrics(SM_CXSCREEN); 
}

long CNSCEPictureBoxCtrl::GetScreenLeft() 
{
	long x;
	CPoint *cPoint;
	cPoint =  new CPoint(0,0);
	ClientToScreen(cPoint);
	x = cPoint->x;
	delete cPoint;
	return x;
}

long CNSCEPictureBoxCtrl::GetScreenTop() 
{
	long y;
	CPoint *cPoint;
	cPoint =  new CPoint(0,0);
	ClientToScreen(cPoint);
	y = cPoint->y;
	delete cPoint;
	return y;
}

void CNSCEPictureBoxCtrl::MethodDrawPicture(LPCTSTR szName, float x, float y, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, 
										const VARIANT FAR& vnX2, const VARIANT FAR& vnY2, const VARIANT FAR& vnWidth2, const VARIANT FAR& vnHeight2, 
										const VARIANT FAR& vnRasterOp) 
{
	HBITMAP hBitmap = NULL;
	BITMAP Bitmap;
	bool bCopied = false;
	long nX = TransformPassedX(x);
	long nY = TransformPassedY(y);

	CommonClearForLoad();
	m_strPicture = szName;

	CommonLoadImage(&hBitmap, &bCopied);

	if (hBitmap != NULL)
	{
		::GetObject(hBitmap, sizeof(Bitmap), &Bitmap);

		long nWidth = TransformPassedWidth(CommonOptionalFloat(&vnWidth, UnTransformPassedWidth(Bitmap.bmWidth)));
		long nHeight = TransformPassedHeight(CommonOptionalFloat(&vnHeight, UnTransformPassedHeight(Bitmap.bmHeight)));
		long nX2 = TransformPassedWidth(CommonOptionalFloat(&vnX2, 0.0));
		long nY2 = TransformPassedHeight(CommonOptionalFloat(&vnY2, 0));
		long nWidth2 = TransformPassedWidth(CommonOptionalFloat(&vnWidth2, UnTransformPassedWidth(Bitmap.bmWidth)));
		long nHeight2 = TransformPassedHeight(CommonOptionalFloat(&vnHeight2, UnTransformPassedHeight(Bitmap.bmHeight)));
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

		HDC sourceDC = ::CreateCompatibleDC(GetDC() -> m_hDC);//::CreateCompatibleDC(NULL);	// EMP fix colors
		HDC destDC = ::CreateCompatibleDC(GetDC() -> m_hDC);//::CreateCompatibleDC(NULL);		// EMP fix colors

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

void CNSCEPictureBoxCtrl::MethodDrawPoint(float x, float y, const VARIANT FAR& vocColor) 
{
	long nX = TransformPassedX(x);
	long nY = TransformPassedY(y);
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	CommonDrawPoint(nX, nY, ocColor);
}

void CNSCEPictureBoxCtrl::MethodDrawPolygon(short nPoints, const VARIANT FAR& vocColor) 
{
	if ((nPoints < 2) || (nPoints > m_nPointArraySize))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		if (NULL != m_ptPointArray)
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

			::Polygon(dcNew, m_ptPointArray, nPoints);

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
}

void CNSCEPictureBoxCtrl::MethodDrawRoundRect(float nLeft, float nTop, float nRight, float nBottom, 
										  const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, 
										  const VARIANT FAR& vocColor) 
{
	float width = CommonOptionalFloat(&vnWidth, 0);
	float height = CommonOptionalFloat(&vnHeight, 0);
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	CommonDrawRoundRect(TransformPassedX(nLeft), TransformPassedY(nTop), 
						TransformPassedX(nRight), TransformPassedY(nBottom), 
						TransformPassedWidth(width), TransformPassedHeight(height), ocColor, m_nFillStyle);
}

void CNSCEPictureBoxCtrl::MethodDrawPolyLines(short nPoints, const VARIANT FAR& vocColor) 
{
	if ((nPoints < 2) || (nPoints > m_nPointArraySize))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		if (NULL != m_ptPointArray)
		{
			OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());
	
			CommonDrawPolyLines(m_ptPointArray, nPoints, ocColor);
		}
	}
}

void CNSCEPictureBoxCtrl::MethodDrawText(LPCTSTR szText, const VARIANT FAR& vnX, const VARIANT FAR& vnY, 
									 const VARIANT FAR& vocColor) 
{
	long nX = TransformPassedX(CommonOptionalFloat(&vnX, 0.0));
	long nY = TransformPassedY(CommonOptionalFloat(&vnY, UnTransformPassedY(m_nDrawTextCurrentY)));
	long nCurrentY;
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&vocColor, (long)GetForeColor());

	nCurrentY = CommonDrawText(3, nX, nY, szText, ocColor);

	if (IsMissing(&vnX) && IsMissing(&vnY))
	{
		m_nDrawTextCurrentY = nCurrentY;
	}
}

void CNSCEPictureBoxCtrl::MethodDrawTextInRect(LPCTSTR Text, const VARIANT FAR& Left, const VARIANT FAR& Top, 
										   const VARIANT FAR& Width, const VARIANT FAR& Height, 
										   const VARIANT FAR& Color) 
{
	RECT rect;
	rect.left = TransformPassedX(CommonOptionalFloat(&Left, 0.0));
	rect.right = rect.left + TransformPassedWidth(CommonOptionalFloat(&Width, UnTransformPassedWidth(GetWidth())));
	rect.top = TransformPassedX(CommonOptionalFloat(&Top, 0.0));
	rect.bottom = rect.top + TransformPassedHeight(CommonOptionalFloat(&Height, UnTransformPassedHeight(GetHeight())));
	OLE_COLOR ocColor = (OLE_COLOR)CommonOptionalLong(&Color, (long)GetForeColor());

	CommonDrawTextInRect(3, &rect, Text, ocColor);
}

long CNSCEPictureBoxCtrl::GetDrawWidth() 
{
	return m_nDrawWidth;
}

void CNSCEPictureBoxCtrl::SetDrawWidth(long nNewValue) 
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

short CNSCEPictureBoxCtrl::GetFillStyle() 
{
	return m_nFillStyle;
}

void CNSCEPictureBoxCtrl::SetFillStyle(short nNewValue) 
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

OLE_COLOR CNSCEPictureBoxCtrl::GetFillColor() 
{
	return m_ocFillColor;
}

void CNSCEPictureBoxCtrl::SetFillColor(OLE_COLOR nNewValue) 
{
	m_ocFillColor = nNewValue;
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetFocusRect() 
{
	return m_bFocusRect;
}

void CNSCEPictureBoxCtrl::SetFocusRect(BOOL bNewValue) 
{
	m_bFocusRect = bNewValue;
	SetModifiedFlag();
}


long CNSCEPictureBoxCtrl::GetFocusRectIndentLeft() 
{
	return m_nFocusRectIndentLeft;
}

void CNSCEPictureBoxCtrl::SetFocusRectIndentLeft(long nNewValue) 
{
	m_nFocusRectIndentLeft = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetFocusRectIndentRight() 
{
	return m_nFocusRectIndentRight;
}

void CNSCEPictureBoxCtrl::SetFocusRectIndentRight(long nNewValue) 
{
	m_nFocusRectIndentRight = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetFocusRectIndentTop() 
{
	return m_nFocusRectIndentTop;
}

void CNSCEPictureBoxCtrl::SetFocusRectIndentTop(long nNewValue) 
{
	m_nFocusRectIndentTop = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetFocusRectIndentBottom() 
{
	return m_nFocusRectIndentBottom;
}

void CNSCEPictureBoxCtrl::SetFocusRectIndentBottom(long nNewValue) 
{
	m_nFocusRectIndentBottom = nNewValue;
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetFontBold() 
{
	BOOL bReturn;

	if (m_LogFont.lfWeight <= 550)
		bReturn = FALSE;
	else
		bReturn = TRUE;

	return bReturn;
}

void CNSCEPictureBoxCtrl::SetFontBold(BOOL bNewValue) 
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

BOOL CNSCEPictureBoxCtrl::GetFontItalic() 
{
	return m_LogFont.lfItalic;
}

void CNSCEPictureBoxCtrl::SetFontItalic(BOOL bNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfItalic = bNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BOOL CNSCEPictureBoxCtrl::GetFontStrikethru() 
{

	return m_LogFont.lfStrikeOut;
}

void CNSCEPictureBoxCtrl::SetFontStrikethru(BOOL bNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfStrikeOut = bNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BOOL CNSCEPictureBoxCtrl::GetFontUnderline() 
{

	return m_LogFont.lfUnderline;
}

void CNSCEPictureBoxCtrl::SetFontUnderline(BOOL bNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfUnderline = bNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

void CNSCEPictureBoxCtrl::SetFontTransparent(BOOL bNewValue) 
{
	m_bFontTransparent = bNewValue;
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetFontTransparent() 
{

	return m_bFontTransparent;
}

long CNSCEPictureBoxCtrl::GetFontEscapement() 
{
	return m_LogFont.lfEscapement;
}

void CNSCEPictureBoxCtrl::SetFontEscapement(long nNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfEscapement = nNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

long CNSCEPictureBoxCtrl::GetFontOrientation() 
{
	return m_LogFont.lfOrientation;
}

void CNSCEPictureBoxCtrl::SetFontOrientation(long nNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfOrientation = nNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

long CNSCEPictureBoxCtrl::GetFontWeight() 
{
	return m_LogFont.lfWeight;
}

void CNSCEPictureBoxCtrl::SetFontWeight(long nNewValue) 
{
	CommonDestroyFont();

	m_LogFont.lfWeight = nNewValue;

	if (!m_bWorkingPropExchange)
	{
		SetModifiedFlag();
	}
}

BOOL CNSCEPictureBoxCtrl::MethodGetMouseMovePoint(short nPoint, long FAR* nX, long FAR* nY) 
{
	BOOL bReturn = FALSE;
	if ((nPoint > -1) && ((UINT)nPoint < m_nMouseMovePointsCount))
	{
		*nX = (m_ptsMouseMove[nPoint].x / 4) - GetScreenLeft();
		*nY = (m_ptsMouseMove[nPoint].y / 4) - GetScreenTop();
		bReturn = TRUE;
	}
	return bReturn;
}

long CNSCEPictureBoxCtrl::GetHScrollPosition() 
{
	return m_nHScrollPosition;
}

void CNSCEPictureBoxCtrl::SetHScrollPosition(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetVScrollPosition() 
{
	return m_nVScrollPosition;
}

void CNSCEPictureBoxCtrl::SetVScrollPosition(long nNewValue) 
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

BSTR CNSCEPictureBoxCtrl::GetHeaders() 
{
	CString strResult;
	strResult = m_strHeaders;
	return strResult.AllocSysString();
}

void CNSCEPictureBoxCtrl::MethodShow() 
{
	SetVisible(TRUE);
//	SetWindowPos( 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_SHOWWINDOW);
//	m_bVisible = true;
//	CommonSetNewTimer();
//	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::MethodHide() 
{
	SetVisible(FALSE);
//	SetWindowPos( 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_HIDEWINDOW);
//	::SetWindowPos((HWND)GetHwnd(), 0, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE + SWP_NOZORDER + SWP_HIDEWINDOW);
//    m_bVisible = false;
//	CommonSetNewTimer();
//	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetVisible() 
{
	return m_bVisible;
}

void CNSCEPictureBoxCtrl::SetVisible(BOOL bNewValue) 
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

short CNSCEPictureBoxCtrl::GetImageBitsPerPixel() 
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

void CNSCEPictureBoxCtrl::SetImageBitsPerPixel(short nNewValue) 
{
	if (m_hBitmap != NULL)
	{
		switch (nNewValue)
		{
			case 1:
#ifdef UNDER_CE
			case 2:
#endif // UNDER_CE
			case 4:
			case 8:
			case 16:
			case 24:
			case 32:
			{
				HBITMAP hBitmap = CommonGetBitmapCopyToNewBPP(m_hBitmap, nNewValue);
/*				HBITMAP hBitmap = NULL;
				CNSCEBitmap *pOld = new CNSCEBitmap;
				if (NULL != pOld)
				{
					CNSCEBitmap *pNew;
					pOld->SetHBITMAP(m_hBitmap);
					pNew = pOld->CopyToNewBitsPerPixel(nNewValue);
					if (NULL != pNew)
					{
						hBitmap = pNew->TakeHBITMAP();
						delete pNew;
					}
					pOld->TakeHBITMAP();
					delete pOld;
				}
*/
				::DeleteObject(m_hBitmap);
				m_hBitmap = hBitmap;
				if (!CommonCheckAutoSize(FALSE))
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

short CNSCEPictureBoxCtrl::GetImageLoadBitsPerPixel() 
{
	return m_nImageLoadBitsPerPixel;
}

void CNSCEPictureBoxCtrl::SetImageLoadBitsPerPixel(short nNewValue) 
{
	switch (nNewValue)
	{
		case 1:
#ifdef UNDER_CE
		case 2:
#endif // UNDER_CE
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

long CNSCEPictureBoxCtrl::GetImageLoadBufferSize() 
{
	return m_nImageLoadBufferSize;
}

void CNSCEPictureBoxCtrl::SetImageLoadBufferSize(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetImageLoadMaxHeight() 
{
	return m_nImageLoadMaxHeight;
}

void CNSCEPictureBoxCtrl::SetImageLoadMaxHeight(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetImageLoadMaxWidth() 
{
	return m_nImageLoadMaxWidth;
}

void CNSCEPictureBoxCtrl::SetImageLoadMaxWidth(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetImageLoadScalePercent() 
{
	return m_nImageLoadScalePercent;
}

void CNSCEPictureBoxCtrl::SetImageLoadScalePercent(long nNewValue) 
{
	if ((nNewValue < 1) || (nNewValue > 100))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nImageLoadScalePercent = nNewValue;
		SetModifiedFlag();
	}
}

BOOL CNSCEPictureBoxCtrl::GetImageLoaded() 
{
	return (m_hBitmap != NULL);
}

short CNSCEPictureBoxCtrl::MethodIntensityRed(OLE_COLOR ocColor) 
{
	return GetRValue(ocColor);
}

short CNSCEPictureBoxCtrl::MethodIntensityGreen(OLE_COLOR ocColor) 
{
	return GetGValue(ocColor);
}

short CNSCEPictureBoxCtrl::MethodIntensityBlue(OLE_COLOR ocColor) 
{
	return GetBValue(ocColor);
}

BOOL CNSCEPictureBoxCtrl::GetInvert() 
{
	return m_bInvert;
}

void CNSCEPictureBoxCtrl::SetInvert(BOOL bNewValue) 
{
	m_bInvert = bNewValue;
	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::MethodInvertImage() 
{
	m_hBitmap = CommonInvert(m_hBitmap);
	InvalidateControl(NULL);
}

long CNSCEPictureBoxCtrl::GetTop() 
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

void CNSCEPictureBoxCtrl::SetTop(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetLeft() 
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

void CNSCEPictureBoxCtrl::SetLeft(long nNewValue) 
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

short CNSCEPictureBoxCtrl::GetMirror() 
{
	return m_nMirror;
}

void CNSCEPictureBoxCtrl::SetMirror(short nNewValue) 
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

void CNSCEPictureBoxCtrl::MethodMirrorImage() 
{
	m_hBitmap = CommonMirror(m_hBitmap);
	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

short CNSCEPictureBoxCtrl::GetMouseMovePoints() 
{
	return m_nMouseMovePoints;
}

void CNSCEPictureBoxCtrl::SetMouseMovePoints(short nNewValue) 
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

long CNSCEPictureBoxCtrl::GetMouseMovePointsCount() 
{
	return m_nMouseMovePointsCount;
}

void CNSCEPictureBoxCtrl::MethodMove(long nX, long nY, long nW, long nH) 
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

BSTR CNSCEPictureBoxCtrl::GetName() 
{
//	CString strResult;

//	strResult = m_strName;

	return m_strName.AllocSysString();
}

BOOL CNSCEPictureBoxCtrl::GetOnToolbar() 
{
	return m_bOnToolbar;
}

void CNSCEPictureBoxCtrl::SetOnToolbar(BOOL bNewValue) 
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
						m_bOnToolbar = TRUE;
					}
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
					m_bOnToolbar = FALSE;
					SetWindowPos( &wndTop, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE );
				}
			}
		}
	}
}

BOOL CNSCEPictureBoxCtrl::GetOverlay() 
{
	return m_bOverlay;
}

void CNSCEPictureBoxCtrl::SetOverlay(BOOL bNewValue) 
{
	m_bOverlay = bNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetOverlayTop() 
{
	return m_nOverlayTop;
}

void CNSCEPictureBoxCtrl::SetOverlayTop(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetOverlayLeft() 
{
	return m_nOverlayLeft;
}

void CNSCEPictureBoxCtrl::SetOverlayLeft(long nNewValue) 
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

OLE_COLOR CNSCEPictureBoxCtrl::GetOverlayTransparentColor() 
{
	return m_ocOverlayTransparentColor;
}

void CNSCEPictureBoxCtrl::SetOverlayTransparentColor(OLE_COLOR nNewValue) 
{
	m_ocOverlayTransparentColor = nNewValue;
	SetModifiedFlag();
}

short CNSCEPictureBoxCtrl::GetPenFillStyle() 
{
	return m_nPenFillStyle;
}

void CNSCEPictureBoxCtrl::SetPenFillStyle(short nNewValue) 
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

short CNSCEPictureBoxCtrl::GetPenStyle() 
{
	return m_nPenStyle;
}

void CNSCEPictureBoxCtrl::SetPenStyle(short nNewValue) 
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

BSTR CNSCEPictureBoxCtrl::GetPicture() 
{
	CString strResult;
	strResult = m_strPicture;
	return strResult.AllocSysString();
}

void CNSCEPictureBoxCtrl::SetPicture(LPCTSTR lpszNewValue) 
{
	CommonClearForLoad();

	m_strPicture = lpszNewValue;

	SetModifiedFlag();
	m_bDisplayExpired = TRUE;

	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

OLE_COLOR CNSCEPictureBoxCtrl::GetPixel(long nX, long nY) 
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

void CNSCEPictureBoxCtrl::SetPixel(long nX, long nY, OLE_COLOR nNewValue) 
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

BSTR CNSCEPictureBoxCtrl::GetPlayingCardsDll() 
{
	CString strResult;
	strResult = m_strPlayingCardsDll;
	return strResult.AllocSysString();
}

void CNSCEPictureBoxCtrl::SetPlayingCardsDll(LPCTSTR lpszNewValue) 
{
	m_strPlayingCardsDll = lpszNewValue;
	if (m_hPlayingCardsDll != NULL)
	{
		FreeLibrary(m_hPlayingCardsDll);
		m_hPlayingCardsDll = NULL;
	}
	SetModifiedFlag();
}

short CNSCEPictureBoxCtrl::GetPlayingCard() 
{
	return m_nPlayingCard;
}

void CNSCEPictureBoxCtrl::SetPlayingCard(short nNewValue) 
{
	if (m_hPlayingCardsDll == NULL)
	{
		CommonGetCardsInstance();
	}

	CommonClearForLoad();

	m_nPlayingCard = nNewValue;
	m_nResourceID = m_nPlayingCard;

#ifndef UNDER_CE
	if ((m_nResourceID >= 1) && (m_nResourceID <= 65))
	{
		m_hInstance = m_hPlayingCardsDll;
	}
	if ((m_nResourceID >= 67) && (m_nResourceID <= 68))
	{
		m_hInstance = m_hPlayingCardsDll;
	}
	if ((m_nResourceID >= IDB_JOKER) && (m_nResourceID <= IDB_SUIT4))
	{
		m_hInstance = m_hInstMe;
	}
#else
	if ((m_nResourceID >= IDACLUBS) && (m_nResourceID <= IDKSPADES))
	{
		m_hInstance = m_hPlayingCardsDll;
	}
	if ((m_nResourceID >= IDFACEDOWNFIRST) && (m_nResourceID <= IDFACEDOWNLAST))
	{
		m_hInstance = m_hPlayingCardsDll;
	}
	if ((m_nResourceID >= IDCARDO) && (m_nResourceID <= IDCARDGHOST))
	{
		m_hInstance = m_hPlayingCardsDll;
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
		m_bDisplayExpired = TRUE;
		if (!CommonLoadImageIntoBitmap())
		{
			InvalidateControl(NULL);
		}
	}
}

OLE_COLOR CNSCEPictureBoxCtrl::MethodRGB(short nRed, short nGreen, short nBlue) 
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

OLE_COLOR CNSCEPictureBoxCtrl::MethodQBColor(short nColorCode) 
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

void CNSCEPictureBoxCtrl::MethodRefreshDesktopWallpaper() 
{
#ifdef UNDER_CE
	HWND hWnd = ::FindWindow(TEXT("DesktopExplorerWindow"),NULL);
	if (hWnd != NULL)
	{
		::SendMessage(hWnd, WM_COMMAND, 0x451, 0);
		HDC hDC = ::GetDC(hWnd);
		::SendMessage(hWnd, WM_ERASEBKGND, (WPARAM)hDC, 0);
		::ReleaseDC(hWnd, hDC);
	}
#endif
}

void CNSCEPictureBoxCtrl::MethodSetCapture() 
{
	SetCapture();
}

void CNSCEPictureBoxCtrl::MethodReleaseCapture() 
{
	ReleaseCapture();
}

void CNSCEPictureBoxCtrl::MethodRefreshX() 
{
	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

BOOL CNSCEPictureBoxCtrl::GetResize() 
{
	return m_bResize;
}

void CNSCEPictureBoxCtrl::SetResize(BOOL bNewValue) 
{
	m_bResize = bNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetResizeHeight() 
{
	return m_nResizeHeight;
}

void CNSCEPictureBoxCtrl::SetResizeHeight(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetResizeWidth() 
{
	return m_nResizeWidth;
}

void CNSCEPictureBoxCtrl::SetResizeWidth(long nNewValue) 
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

void CNSCEPictureBoxCtrl::MethodResizeImage() 
{
	m_hBitmap = CommonResize(m_hBitmap);
	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

long CNSCEPictureBoxCtrl::GetResourceBitmapID() 
{
	return m_nResourceBitmapID;
}

void CNSCEPictureBoxCtrl::SetResourceBitmapID(long nNewValue) 
{
	CString strResourceFile;

	strResourceFile = m_strResourceFile;
	CommonClearForLoad();
	m_strResourceFile = strResourceFile;

	m_nResourceBitmapID = nNewValue;
	m_nResourceID = m_nResourceBitmapID;
	SetModifiedFlag();

	m_bDisplayExpired = TRUE;
	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

BSTR CNSCEPictureBoxCtrl::GetResourceFile() 
{
	CString strResult;
	strResult = m_strResourceFile;
	return strResult.AllocSysString();
}

void CNSCEPictureBoxCtrl::SetResourceFile(LPCTSTR lpszNewValue) 
{

	CommonClearForLoad();

	m_strResourceFile = lpszNewValue;

	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetResourceFileLoaded() 
{
	return (m_hResourceFile != NULL);
}

long CNSCEPictureBoxCtrl::GetResourceIconHeight() 
{
	return m_nResourceIconHeight;
}

void CNSCEPictureBoxCtrl::SetResourceIconHeight(long nNewValue) 
{
	if (0 > nNewValue)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nResourceIconHeight = nNewValue;
		SetModifiedFlag();
	}
}

long CNSCEPictureBoxCtrl::GetResourceIconWidth() 
{
	return m_nResourceIconWidth;
}

void CNSCEPictureBoxCtrl::SetResourceIconWidth(long nNewValue) 
{
	if (0 > nNewValue)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_nResourceIconWidth = nNewValue;
		SetModifiedFlag();
	}
}

long CNSCEPictureBoxCtrl::GetResourceIconID() 
{
	return m_nResourceIconID;
}

void CNSCEPictureBoxCtrl::SetResourceIconID(long nNewValue) 
{
	CString strResourceFile;

	strResourceFile = m_strResourceFile;
	CommonClearForLoad();
	m_strResourceFile = strResourceFile;

	m_nResourceIconID = nNewValue;
	m_nResourceID = m_nResourceIconID;
	SetModifiedFlag();

	m_bDisplayExpired = TRUE;
	if (!CommonLoadImageIntoBitmap())
	{
		InvalidateControl(NULL);
	}
}

short CNSCEPictureBoxCtrl::GetRotate() 
{
	return m_nRotate;
}

void CNSCEPictureBoxCtrl::SetRotate(short nNewValue) 
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

void CNSCEPictureBoxCtrl::MethodRotateImage() 
{
	m_hBitmap = CommonRotate(m_hBitmap);
	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

BOOL CNSCEPictureBoxCtrl::MethodSaveImageToFile(LPCTSTR szFileName, short nFileType) 
{
	BOOL bReturn = FALSE;

	if ((nFileType == 0) && (m_hBitmap != NULL))
	{
		CFile file;
		if(file.Open(szFileName, CFile::modeWrite|CFile::modeCreate))
		{
			if (m_bWaitCursor)
			{
				BeginWaitCursor();
			}

			if (CommonSaveImageToByteArray())
			{
				if (m_nByteArray < 65535)
				{
					file.Write(m_ByteArray, m_nByteArray);
				}
				else
				{
					file.WriteHuge(m_ByteArray, m_nByteArray);
				}

				bReturn = TRUE;
			}

			if (m_ByteArray != NULL)
			{
				delete [] m_ByteArray;
				m_ByteArray = NULL;
				m_nByteArray = 0;
			}

			file.Close();

			if (m_bWaitCursor)
			{
				EndWaitCursor();
			}
		}
	}

	return bReturn;
}

short CNSCEPictureBoxCtrl::GetScaleMode() 
{
	return m_scaleMode;;
}

void CNSCEPictureBoxCtrl::SetScaleMode(short nNewValue) 
{
	m_scaleMode = nNewValue;
	long width = 0, height = 0;
	CRect cRect;

	if (GetRectInContainer(cRect) != 0) 
	{
		width = (long)cRect.Width();
		height = (long)cRect.Height();
	}

	switch (m_scaleMode)
	{
		case 0:		// User-defined
			break;
		case 1:		// Twips
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)(((float)width) * 1440.0 / (float)m_nLogPixelsX);
			m_scaleHeight = (float)(((float)height) * 1440.0 / (float)m_nLogPixelsY);
			break;
		case 2:		// Points
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)(((float)width) * 72.0 / (float)m_nLogPixelsX);
			m_scaleHeight = (float)(((float)height) * 72.0 / (float)m_nLogPixelsY);
			break;
		default:
		case 3:		// Traditional pixels
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)width;
			m_scaleHeight = (float)height;
			break;
		case 4:		// Characters
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)(((float)width) * 12.0 / (float)m_nLogPixelsX);
			m_scaleHeight = (float)(((float)height) * 6.0 / (float)m_nLogPixelsY);
			break;
		case 5:		// Inches
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)(((float)width) / (float)m_nLogPixelsX);
			m_scaleHeight = (float)(((float)height) / (float)m_nLogPixelsY);
			break;
		case 6:		// Millimeters
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)(((float)width) * 25.4 / (float)m_nLogPixelsX);
			m_scaleHeight = (float)(((float)height) * 25.4 / (float)m_nLogPixelsY);
			break;
		case 7:		// Centimeters
			m_scaleLeft = 0.0;
			m_scaleTop = 0.0;
			m_scaleWidth = (float)(((float)width) * 2.54 / (float)m_nLogPixelsX);
			m_scaleHeight = (float)(((float)height) * 2.54 / (float)m_nLogPixelsY);
			break;
	}
}

short CNSCEPictureBoxCtrl::GetScreenBitsPerPixel() 
{
#ifdef UNDER_CE
	HDC sourceDC = ::CreateDC(NULL, NULL, NULL, NULL);
#else
	HDC sourceDC = ::CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
#endif
	int nBitsPerPixel = GetDeviceCaps(sourceDC, BITSPIXEL);

	::DeleteDC(sourceDC);
	
	return nBitsPerPixel;
}

BOOL CNSCEPictureBoxCtrl::GetScroll() 
{
	return m_bScroll;
}

void CNSCEPictureBoxCtrl::SetScroll(BOOL bNewValue) 
{
	m_bScroll = bNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetScrollX() 
{
	return m_nScrollX;
}

void CNSCEPictureBoxCtrl::SetScrollX(long nNewValue) 
{
	m_nScrollX = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetScrollY() 
{
	return m_nScrollY;
}

void CNSCEPictureBoxCtrl::SetScrollY(long nNewValue) 
{
	m_nScrollY = nNewValue;
	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::MethodScrollImage() 
{
	m_hBitmap = CommonScroll(m_hBitmap);
	if (!CommonCheckAutoSize(FALSE))
	{
		InvalidateControl(NULL);
	}
}

short CNSCEPictureBoxCtrl::GetScrollBars() 
{
	return m_nScrollBars;
}

void CNSCEPictureBoxCtrl::SetScrollBars(short nNewValue) 
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

void CNSCEPictureBoxCtrl::MethodSetFocus() 
{
	SetFocus();
}

void CNSCEPictureBoxCtrl::MethodSetPointArray(long nIndex, float x, float y) 
{
	if (nIndex < 1)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		if (m_nPointArraySize < nIndex)
		{
			POINT *ptArray = new POINT[nIndex];

			if (NULL != m_ptPointArray)
			{
				for (long lIndex = 0; lIndex < m_nPointArraySize; lIndex++)
				{
					ptArray[lIndex].x = m_ptPointArray[lIndex].x;
					ptArray[lIndex].y = m_ptPointArray[lIndex].y;
				}

				delete m_ptPointArray;
			}

			m_ptPointArray = ptArray;

			m_nPointArraySize = nIndex;
		}

		m_ptPointArray[nIndex - 1].x = TransformPassedX(x);
		m_ptPointArray[nIndex - 1].y = TransformPassedY(y);
		SetModifiedFlag();
	}
}

BOOL CNSCEPictureBoxCtrl::GetStretch() 
{
	return m_bStretch;
}

void CNSCEPictureBoxCtrl::SetStretch(BOOL bNewValue) 
{
	m_bStretch = bNewValue;
	SetModifiedFlag();
	CommonDesignRefresh();
}

BOOL CNSCEPictureBoxCtrl::GetWaitCursor() 
{
	return m_bWaitCursor;
}

void CNSCEPictureBoxCtrl::SetWaitCursor(BOOL bNewValue) 
{
	m_bWaitCursor = bNewValue;
	SetModifiedFlag();
}

VARIANT CNSCEPictureBoxCtrl::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CNSCEPictureBoxCtrl::SetTag(const VARIANT FAR& newValue) 
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

BOOL CNSCEPictureBoxCtrl::GetTapAndHoldEventEnabled() 
{
	return m_bTapAndHoldEventEnabled;
}

void CNSCEPictureBoxCtrl::SetTapAndHoldEventEnabled(BOOL bNewValue) 
{
	m_bTapAndHoldEventEnabled = bNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::MethodTextWidth(LPCTSTR szText) 
{
	return CommonDrawText(1, 0, 0, szText, GetForeColor());
}

long CNSCEPictureBoxCtrl::MethodTextHeight(LPCTSTR szText) 
{
	return CommonDrawText(2, 0, 0, szText, GetForeColor());
}

OLE_COLOR CNSCEPictureBoxCtrl::GetTransparentColor() 
{
	return m_ocTransparentColor;
}

void CNSCEPictureBoxCtrl::SetTransparentColor(OLE_COLOR nNewValue) 
{
	m_ocTransparentColor = nNewValue;
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::MethodURL(LPCTSTR lpszURL, const VARIANT FAR& vUser, const VARIANT FAR& vPassword) 
{
	long lReturn = -1;

	CString strUser = CommonOptionalString(&vUser, TEXT(""));
	CString strPassword = CommonOptionalString(&vPassword, TEXT(""));
	LPTSTR lpszNewUrl = NULL;
	DWORD dwUrlLength;
	URL_COMPONENTS uc;
	memset(&uc, 0 , sizeof(URL_COMPONENTS));
	uc.dwStructSize = sizeof(URL_COMPONENTS);
	uc.dwExtraInfoLength = 255;
	uc.dwHostNameLength = 255;
	uc.dwPasswordLength = 255;
	uc.dwSchemeLength = 255;
	uc.dwUrlPathLength = 255;
	uc.dwUserNameLength = 255;

	BOOL bReturn = InternetCrackUrl(lpszURL, 0, 0, &uc);

	switch (uc.nScheme)
	{
		case INTERNET_SCHEME_FTP:
		case INTERNET_SCHEME_HTTP:
		case INTERNET_SCHEME_HTTPS:
			if (0 < uc.dwUserNameLength)
			{
				strUser = uc.lpszUserName;
			}

			if (0 < uc.dwPasswordLength)
			{
				strPassword = uc.lpszPassword;
			}

			dwUrlLength = uc.dwExtraInfoLength + uc.dwHostNameLength + uc.dwSchemeLength + uc.dwUrlPathLength + 10;
			lpszNewUrl = new TCHAR[dwUrlLength];

			uc.dwPasswordLength = 0;
			uc.lpszPassword = NULL;
			uc.dwUserNameLength = 0;
			uc.lpszUserName = NULL;

			bReturn = InternetCreateUrl(&uc, 0, lpszNewUrl, &dwUrlLength);
			
			lReturn = StartURL(lpszNewUrl, strUser, strPassword);

			delete lpszNewUrl;
			lpszNewUrl = NULL;
			break;
		default:
			break;
	}

	return lReturn;
}

BSTR CNSCEPictureBoxCtrl::GetURLAgent() 
{
	CString strResult;
	strResult = m_strURLAgent;
	return strResult.AllocSysString();
}

void CNSCEPictureBoxCtrl::SetURLAgent(LPCTSTR lpszNewValue) 
{
	m_strURLAgent = lpszNewValue;
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetURLFlagPassive() 
{
	return (INTERNET_FLAG_PASSIVE == (m_nURLFlags & INTERNET_FLAG_PASSIVE));
}

void CNSCEPictureBoxCtrl::SetURLFlagPassive(BOOL bNewValue) 
{
	m_nURLFlags &= (0xffffffff ^ INTERNET_FLAG_PASSIVE);
	if (bNewValue)
	{
		m_nURLFlags |= INTERNET_FLAG_PASSIVE;
	}
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetURLFlagCache() 
{
	return (INTERNET_FLAG_DONT_CACHE != (m_nURLFlags & INTERNET_FLAG_DONT_CACHE));
}

void CNSCEPictureBoxCtrl::SetURLFlagCache(BOOL bNewValue) 
{
	m_nURLFlags &= (0xffffffff ^ INTERNET_FLAG_DONT_CACHE);
	if (!bNewValue)
	{
		m_nURLFlags |= INTERNET_FLAG_DONT_CACHE;
	}
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetURLFlagReload() 
{
	return (INTERNET_FLAG_RELOAD == (m_nURLFlags & INTERNET_FLAG_RELOAD));
}

void CNSCEPictureBoxCtrl::SetURLFlagReload(BOOL bNewValue) 
{
	m_nURLFlags &= (0xffffffff ^ INTERNET_FLAG_RELOAD);
	if (bNewValue)
	{
		m_nURLFlags |= INTERNET_FLAG_RELOAD;
	}
	SetModifiedFlag();
}

long CNSCEPictureBoxCtrl::GetURLFlags() 
{
	return m_nURLFlags;
}

void CNSCEPictureBoxCtrl::SetURLFlags(long nNewValue) 
{
	m_nURLFlags = nNewValue;
	SetModifiedFlag();
}

BOOL CNSCEPictureBoxCtrl::GetUseJPEGBitsPerPixel() 
{
	return m_bUseJPEGBitsPerPixel;
}

void CNSCEPictureBoxCtrl::SetUseJPEGBitsPerPixel(BOOL bNewValue) 
{
	m_bUseJPEGBitsPerPixel = bNewValue;
	SetModifiedFlag();
}

float CNSCEPictureBoxCtrl::GetVersion() 
{
	return (float)(_wVerMajor * 100.0 + ((float)_wVerMinor/* / 100.0*/));
}

long CNSCEPictureBoxCtrl::GetVersionMajor() 
{
	return _wVerMajor;
}

long CNSCEPictureBoxCtrl::GetVersionMinor() 
{
	return _wVerMinor;
}

#if 0
long CNSCEPictureBoxCtrl::GetParentHWnd() 
{
	return (long) ::GetParent(m_hWnd);
}
#endif

BSTR CNSCEPictureBoxCtrl::GetVersionString() 
{
	CString strResult;

	if (m_strVersionString.IsEmpty())
	{
		TCHAR szFile[4095];

		if (GetModuleFileName(m_hInstMe, szFile, 4095))
		{
#ifdef UNDER_CE
			CeResource cer;
			CeVersionInfo *cevi;
			cevi = new CeVersionInfo;
			cer.Load(szFile);
			HRSRC hRsrc = cer.FindResource(VS_VERSION_INFO, RT_VERSION);
			DWORD dwSize;
			LPVOID lpByte = cer.LoadResource(hRsrc, dwSize);

			cevi->Load((LPBYTE)lpByte);
			
			m_strVersionString = cevi->m_wszFileVersion;

			delete cevi;
#else //UNDER_CE
			CFileVersionInfo m_info;

			m_info.ReadVersionInfo(szFile);

			if (m_info.IsValid())
			{
				m_strVersionString = m_info.GetFileVersionString();
			} 
#endif // UNDER_CE
		}
	}

	strResult = m_strVersionString;
	return strResult.AllocSysString();
}

short CNSCEPictureBoxCtrl::GetWildCard() 
{
	return m_nWildCard;
}

void CNSCEPictureBoxCtrl::SetWildCard(short nNewValue) 
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

void CNSCEPictureBoxCtrl::MethodZOrder(short nPosition) 
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

long CNSCEPictureBoxCtrl::GetHBitmap() 
{
	return (long)m_hBitmap;
}

void CNSCEPictureBoxCtrl::SetHBitmap(long nNewValue) 
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

long CNSCEPictureBoxCtrl::GetHIcon() 
{
	return 0;
}

void CNSCEPictureBoxCtrl::SetHIcon(long nNewValue) 
{

	HICON hIcon = (HICON)nNewValue;

	if (NULL == hIcon)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
		return;
	}

	m_hWorkingIconBitmap = CommonGetBitmapFromIcon(hIcon, 0, 0, -1, DI_NORMAL);

	::DestroyIcon(hIcon);

	if (NULL == m_hWorkingIconBitmap)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, IDS_STRINGVALUEOUTOFRANGE, 0);
	}
	else
	{
		m_bDisplayExpired = TRUE;
		if (!CommonLoadImageIntoBitmap())
		{
			InvalidateControl(NULL);
		}

		::DeleteObject(m_hWorkingIconBitmap);
		m_hWorkingIconBitmap = NULL;
	}
}

long CNSCEPictureBoxCtrl::GetHFont() 
{
	if (AmbientUserMode())
	{
		CommonCreateFont();
	}
	
	return (long)m_hFont;
}

void CNSCEPictureBoxCtrl::SetHFont(long nNewValue) 
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

void CNSCEPictureBoxCtrl::OnScaleWidthChanged() 
{
	m_scaleMode = 0;

	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::OnScaleHeightChanged() 
{
	m_scaleMode = 0;

	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::OnScaleLeftChanged() 
{
	m_scaleMode = 0;

	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::OnScaleTopChanged() 
{
	m_scaleMode = 0;

	SetModifiedFlag();
}

void CNSCEPictureBoxCtrl::OnEnabledChanged() 
{
	COleControl::OnEnabledChanged();
}


void CNSCEPictureBoxCtrl::OnTimer(UINT nIDEvent) 
{
	COleControl::OnTimer(nIDEvent);
	CommonSetNewTimer();
	if ((m_bVisible) && (m_bWorkingAnimationAvailable))
	{
		AnimatePlayingCard(true, m_hBitmap);
	}
}

void CNSCEPictureBoxCtrl::OnKillFocus(CWnd* pNewWnd) 
{
	COleControl::OnKillFocus(pNewWnd);
	m_bHaveFocus = FALSE;
	if (m_bFocusRect)
	{
		if (!CommonCheckAutoSize(FALSE))
		{
			InvalidateControl(NULL);
		}
	}
		
	FireLostFocus();
}

void CNSCEPictureBoxCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	COleControl::OnSetFocus(pOldWnd);
	m_bHaveFocus = TRUE;
	if (m_bFocusRect)
	{
		if (!CommonCheckAutoSize(FALSE))
		{
			InvalidateControl(NULL);
		}
	}
	FireGotFocus(); 
}

DWORD CNSCEPictureBoxCtrl::GetControlFlags() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return COleControl::GetControlFlags() | pointerInactive;
}
// CWnd

void CNSCEPictureBoxCtrl::OnTextChanged() 
{
	COleControl::OnTextChanged();
	if ((!m_bVBCE) && (!m_bHaveName))
	{
		m_bHaveName = TRUE;
		if (m_strName.CompareNoCase(TEXT("NSCEPictureBox")) == 0)
		{
			m_strName = GetText();
			SetText(TEXT(""));
		}
	}
}

BOOL CNSCEPictureBoxCtrl::OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut) 
{
	BOOL bReturn = FALSE;
#ifndef UNDER_CE
	if (AmbientUserMode())
	{
		return FALSE;
	}

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
			bReturn = TRUE;
			break;
		case dispidAppearance:
			nVal -= 4;
			lpvarOut->vt = VT_I4;
			lpvarOut->lVal = nVal;
			bReturn = TRUE;
			break;
		case dispidCommonBitmapType:
			nVal -= 2;
			lpvarOut->vt = VT_I4;
			lpvarOut->lVal = nVal;
			bReturn = TRUE;
			break;
	}
#endif
	if (!bReturn)
	{
		bReturn = COleControl::OnGetPredefinedValue(dispid, dwCookie, lpvarOut);
	}

	return bReturn;
}

BOOL CNSCEPictureBoxCtrl::OnGetDisplayString(DISPID dispid, CString& strValue) 
{
	BOOL bReturn = FALSE;
#ifndef UNDER_CE

	if (AmbientUserMode())
	{
		return FALSE;
	}

	switch (dispid)
	{
		case dispidAppearance:
			if (CommonGetDisplayString(dispid, strValue, m_nAppearance + 4))
			{
				bReturn = TRUE;
			}
			break;
		case dispidBorderStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nBorderStyle))
			{
				bReturn = TRUE;
			}
			break;
		case dispidCenter:
			if (CommonGetDisplayString(dispid, strValue, m_nCenter))
			{
				bReturn = TRUE;
			}
			break;
		case dispidCommonBitmapID:
//			bReturn = true;
			break;
		case dispidCommonBitmapType:
			if (CommonGetDisplayString(dispid, strValue, m_nCommonBitmapType + 2))
			{
				bReturn = TRUE;
			}
			break;
		case dispidFillStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nFillStyle))
			{
				bReturn = TRUE;
			}
			break;
		case dispidMirror:
			if (CommonGetDisplayString(dispid, strValue, m_nMirror))
			{
				bReturn = TRUE;
			}
			break;
		case dispidMouseMovePoints:
			if (CommonGetDisplayString(dispid, strValue, m_nMouseMovePoints))
			{
				bReturn = TRUE;
			}
			break;
		case dispidPenFillStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nPenFillStyle))
			{
				bReturn = TRUE;
			}
			break;
		case dispidPenStyle:
			if (CommonGetDisplayString(dispid, strValue, m_nPenStyle))
			{
				bReturn = TRUE;
			}
			break;
		case dispidPlayingCard:
			break;
		case dispidRotate:
			if (CommonGetDisplayString(dispid, strValue, m_nRotate))
			{
				bReturn = TRUE;
			}
			break;
		case dispidWildCard:
			if (CommonGetDisplayString(dispid, strValue, m_nWildCard))
			{
				bReturn = TRUE;
			}
			break;
		case dispidScrollBars:
			if (CommonGetDisplayString(dispid, strValue, m_nScrollBars))
			{
				bReturn = TRUE;
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

LRESULT CNSCEPictureBoxCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	DWORD dwDataLength;
	CString strText;

	switch (message)
	{
		case WM_APP:
			m_cs.Lock();
			switch (wParam)
			{
				case 1:
					if ((CUrlImage *)lParam == m_pUrlImage)
					{
						m_bUrlHttp = FALSE;
						m_pUrlImage = NULL;
					}
					Sleep(500);
					delete (CUrlImage *)lParam;
					break;
				case 2:
					{
						CUrlImageData *pImageData = (CUrlImageData *)lParam;
						if (pImageData->m_pUrlImage == m_pUrlImage)
						{
							m_bDisplayExpired = TRUE;
							
							CUrlImage *pUrlImage = m_pUrlImage;
							m_pUrlImage = NULL;
							CString strHeaders = m_strHeaders;
							CommonClearForLoad();
							m_strHeaders = strHeaders;
							m_bUrlHttp = FALSE;
							m_pUrlImage = pUrlImage;
							m_nByteArray = pImageData->m_dwByteArrayLength;
							m_ByteArray = pImageData->m_pByteArray;
							if (!CommonLoadImageIntoBitmap())
							{
								InvalidateControl(NULL);
							}
							m_ByteArray = NULL;
							m_nByteArray = 0;
						}
						delete pImageData;
					}
					break;
				case 3:
					dwDataLength = (DWORD)lParam;
					strText.Format(TEXT("%d"), dwDataLength);
					AfxMessageBox(strText);
				default:
					break;
			}
			m_cs.Unlock();
			break;
		default:
			break;
	}

	return COleControl::WindowProc(message, wParam, lParam);
}


int CNSCEPictureBoxCtrl::OnEnterMenuLoop(BOOL track)
{
	return 0;
}

int CNSCEPictureBoxCtrl::OnExitMenuLoop(BOOL track)
{
	return 0;
}

void CNSCEPictureBoxCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
#ifdef UNDER_CE
#ifdef WIN32_PLATFORM_PSPC
#if _WIN32_WCE > 299
		BOOL bTapAndHold = FALSE;
		if (m_bTapAndHoldEventEnabled && SHRecognizeGesture(point, FALSE))
		{
			FireTapAndHold(nButtons, nKeys, point.x, point.y);
			bTapAndHold = TRUE;
		}
		if (!bTapAndHold)
#endif // _WIN32_WCE > 299 
#endif // WIN32_PLATFORM_PSPC
#endif // UNDER_CE
		{
			CommonFireMouse(0, nButtons, nKeys, point.x, point.y);
			CommonFireMousePoints(nButtons, nKeys);
		}
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnLButtonDown(nFlags, point);
}

void CNSCEPictureBoxCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
		CommonFireMousePoints(nButtons, nKeys);
		CommonFireMouse(1, nButtons, nKeys, point.x, point.y);
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnMouseMove(nFlags, point);
}

void CNSCEPictureBoxCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
		CommonFireMousePoints(nButtons, nKeys);
		CommonFireMouse(2, nButtons, nKeys, point.x, point.y);
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnLButtonUp(nFlags, point);
}

void CNSCEPictureBoxCtrl::CommonFireMouse(short nType, short nButtons, short nKeys, long x, long y)
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

void CNSCEPictureBoxCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	long nPosition = m_nHScrollPosition;
	long nMove = 0;
	BOOL bRefresh = FALSE;

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
			bRefresh = TRUE;
			nPosition = nPos;
			break;
		case SB_TOP:
			nPosition = m_nWorkingHMin;
			break;
		case SB_BOTTOM:
			nPosition = m_nWorkingHMax;
			break;
		case SB_ENDSCROLL:
			bRefresh = TRUE;
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
		if (!CommonCheckAutoSize(FALSE))
		{
			InvalidateControl(NULL);
		}
	}
}

void CNSCEPictureBoxCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	long nPosition = m_nVScrollPosition;
	long nMove = 0;
	BOOL bRefresh = FALSE;

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
			bRefresh = TRUE;
			break;
		case SB_TOP:
			nPosition = m_nWorkingVMin;
			break;
		case SB_BOTTOM:
			nPosition = m_nWorkingVMax;
			break;
		case SB_ENDSCROLL:
			bRefresh = TRUE;
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
		if (!CommonCheckAutoSize(FALSE))
		{
			InvalidateControl(NULL);
		}
	}
}

BOOL CNSCEPictureBoxCtrl::OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray) 
{
	BOOL bReturn = FALSE;
#ifndef UNDER_CE
	if (AmbientUserMode())
	{
		return FALSE;
	}

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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
				}
			}
			break;
		case dispidCommonBitmapID:
//			bReturn = TRUE;
			break;
		case dispidCommonBitmapType:
			for (dwCookie = 0; dwCookie < 5; dwCookie++)
			{
				if (CommonGetDisplayString(dispid, strValue, dwCookie))
				{
					pStringArray->Add(strValue);
					pCookieArray->Add(dwCookie);
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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
					bReturn = TRUE;
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

void CNSCEPictureBoxCtrl::OnMButtonDown(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
		CommonFireMouse(0, nButtons, nKeys, point.x, point.y);
		CommonFireMousePoints(nButtons, nKeys);
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnMButtonDown(nFlags, point);
}

void CNSCEPictureBoxCtrl::OnMButtonUp(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
		CommonFireMousePoints(nButtons, nKeys);
		CommonFireMouse(2, nButtons, nKeys, point.x, point.y);
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnMButtonUp(nFlags, point);
}

void CNSCEPictureBoxCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
		CommonFireMouse(0, nButtons, nKeys, point.x, point.y);
		CommonFireMousePoints(nButtons, nKeys);
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnRButtonDown(nFlags, point);
}

void CNSCEPictureBoxCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
#ifndef UNDER_CE 
	if (AmbientUserMode())
	{
#endif // UNDER_CE 
		short nButtons = CommonFireMouseButtons(nFlags);
		short nKeys = CommonFireMouseKeys(nFlags);
		CommonFireMousePoints(nButtons, nKeys);
		CommonFireMouse(2, nButtons, nKeys, point.x, point.y);
#ifndef UNDER_CE 
	}
#endif // UNDER_CE 
	COleControl::OnRButtonUp(nFlags, point);
}

BOOL CNSCEPictureBoxCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
#ifdef UNDER_CE
	if (m_bHasMousePointer)
	{
		BeginWaitCursor();
		EndWaitCursor();
		m_bHasMousePointer = FALSE;
	}
#endif
	return COleControl::OnSetCursor(pWnd, nHitTest, message);
}


void CNSCEPictureBoxCtrl::Refresh() 
{
	// TODO: Add your dispatch handler code here
	MethodRefreshX();
}

long CNSCEPictureBoxCtrl::GetParentHWnd() 
{
	return (long)::GetParent(m_hWnd);
}

void CNSCEPictureBoxCtrl::SetParentHWnd(long nNewValue) 
{
	// TODO: Add your property handler here

	SetModifiedFlag();
}
