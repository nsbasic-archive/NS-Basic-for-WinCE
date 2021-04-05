#if !defined(AFX_NSCEPICTUREBOXCTL_H__98B3D255_AA73_4EDF_814E_77D1BFC40473__INCLUDED_)
#define AFX_NSCEPICTUREBOXCTL_H__98B3D255_AA73_4EDF_814E_77D1BFC40473__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#define MOUSEMOVEPOINTSCOUNTMAX 200

// NSCEPictureBoxCtl.h : Declaration of the CNSCEPictureBoxCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxCtrl : See NSCEPictureBoxCtl.cpp for implementation.

class CNSCEPictureBoxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CNSCEPictureBoxCtrl)

// Constructor
public:
	CNSCEPictureBoxCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNSCEPictureBoxCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcSubmittedBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual void OnEnabledChanged();
	virtual DWORD GetControlFlags();
	virtual BOOL OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray);
	virtual BOOL OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut);
	virtual BOOL OnGetDisplayString(DISPID dispid, CString& strValue);
	virtual void OnTextChanged();
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL


// Implementation
protected:

	~CNSCEPictureBoxCtrl();

	DECLARE_OLECREATE_EX(CNSCEPictureBoxCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CNSCEPictureBoxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CNSCEPictureBoxCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CNSCEPictureBoxCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CNSCEPictureBoxCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CNSCEPictureBoxCtrl)
	BOOL m_showCaption;
	afx_msg void OnShowCaptionChanged();
	float m_scaleWidth;
	afx_msg void OnScaleWidthChanged();
	float m_scaleHeight;
	afx_msg void OnScaleHeightChanged();
	float m_scaleLeft;
	afx_msg void OnScaleLeftChanged();
	float m_scaleTop;
	afx_msg void OnScaleTopChanged();
	afx_msg long GetWidth();
	afx_msg void SetWidth(long nNewValue);
	afx_msg long GetHeight();
	afx_msg void SetHeight(long nNewValue);
	afx_msg BSTR GetFontName();
	afx_msg void SetFontName(LPCTSTR lpszNewValue);
	afx_msg long GetFontSize();
	afx_msg void SetFontSize(long nNewValue);
	afx_msg long GetImageWidth();
	afx_msg long GetImageHeight();
	afx_msg BOOL GetAnimationAvailable();
	afx_msg long GetAnimationInterval();
	afx_msg void SetAnimationInterval(long nNewValue);
	afx_msg short GetAppearance();
	afx_msg void SetAppearance(short nNewValue);
	afx_msg BOOL GetAutoDetectTransparency();
	afx_msg void SetAutoDetectTransparency(BOOL bNewValue);
	afx_msg BOOL GetAutoRefresh();
	afx_msg void SetAutoRefresh(BOOL bNewValue);
	afx_msg BOOL GetAutoSize();
	afx_msg void SetAutoSize(BOOL bNewValue);
	afx_msg BOOL GetBitmapOnClipboard();
	afx_msg short GetBorderStyle();
	afx_msg void SetBorderStyle(short nNewValue);
	afx_msg VARIANT GetByteArray();
	afx_msg void SetByteArray(const VARIANT FAR& newValue);
	afx_msg short GetCenter();
	afx_msg void SetCenter(short nNewValue);
	afx_msg BOOL GetClip();
	afx_msg void SetClip(BOOL bNewValue);
	afx_msg long GetClipHeight();
	afx_msg void SetClipHeight(long nNewValue);
	afx_msg long GetClipWidth();
	afx_msg void SetClipWidth(long nNewValue);
	afx_msg long GetClipTop();
	afx_msg void SetClipTop(long nNewValue);
	afx_msg long GetClipLeft();
	afx_msg void SetClipLeft(long nNewValue);
	afx_msg BOOL GetCommandButton();
	afx_msg void SetCommandButton(BOOL bNewValue);
	afx_msg short GetCommonBitmapID();
	afx_msg void SetCommonBitmapID(short nNewValue);
	afx_msg short GetCommonBitmapType();
	afx_msg void SetCommonBitmapType(short nNewValue);
	afx_msg long GetScreenLeft();
	afx_msg long GetScreenTop();
	afx_msg long GetScreenHeight();
	afx_msg long GetScreenWidth();
	afx_msg long GetDrawWidth();
	afx_msg void SetDrawWidth(long nNewValue);
	afx_msg short GetFillStyle();
	afx_msg void SetFillStyle(short nNewValue);
	afx_msg OLE_COLOR GetFillColor();
	afx_msg void SetFillColor(OLE_COLOR nNewValue);
	afx_msg BOOL GetFocusRect();
	afx_msg void SetFocusRect(BOOL bNewValue);
	afx_msg long GetFocusRectIndentLeft();
	afx_msg void SetFocusRectIndentLeft(long nNewValue);
	afx_msg long GetFocusRectIndentRight();
	afx_msg void SetFocusRectIndentRight(long nNewValue);
	afx_msg long GetFocusRectIndentTop();
	afx_msg void SetFocusRectIndentTop(long nNewValue);
	afx_msg long GetFocusRectIndentBottom();
	afx_msg void SetFocusRectIndentBottom(long nNewValue);
	afx_msg BOOL GetFontBold();
	afx_msg void SetFontBold(BOOL bNewValue);
	afx_msg BOOL GetFontItalic();
	afx_msg void SetFontItalic(BOOL bNewValue);
	afx_msg BOOL GetFontStrikethru();
	afx_msg void SetFontStrikethru(BOOL bNewValue);
	afx_msg BOOL GetFontTransparent();
	afx_msg void SetFontTransparent(BOOL bNewValue);
	afx_msg BOOL GetFontUnderline();
	afx_msg void SetFontUnderline(BOOL bNewValue);
	afx_msg long GetFontEscapement();
	afx_msg void SetFontEscapement(long nNewValue);
	afx_msg long GetFontOrientation();
	afx_msg void SetFontOrientation(long nNewValue);
	afx_msg long GetFontWeight();
	afx_msg void SetFontWeight(long nNewValue);
	afx_msg long GetHScrollPosition();
	afx_msg void SetHScrollPosition(long nNewValue);
	afx_msg long GetVScrollPosition();
	afx_msg void SetVScrollPosition(long nNewValue);
	afx_msg BSTR GetHeaders();
	afx_msg BOOL GetVisible();
	afx_msg void SetVisible(BOOL bNewValue);
	afx_msg short GetImageBitsPerPixel();
	afx_msg void SetImageBitsPerPixel(short nNewValue);
	afx_msg short GetImageLoadBitsPerPixel();
	afx_msg void SetImageLoadBitsPerPixel(short nNewValue);
	afx_msg long GetImageLoadBufferSize();
	afx_msg void SetImageLoadBufferSize(long nNewValue);
	afx_msg long GetImageLoadMaxHeight();
	afx_msg void SetImageLoadMaxHeight(long nNewValue);
	afx_msg long GetImageLoadMaxWidth();
	afx_msg void SetImageLoadMaxWidth(long nNewValue);
	afx_msg long GetImageLoadScalePercent();
	afx_msg void SetImageLoadScalePercent(long nNewValue);
	afx_msg BOOL GetImageLoaded();
	afx_msg BOOL GetInvert();
	afx_msg void SetInvert(BOOL bNewValue);
	afx_msg long GetTop();
	afx_msg void SetTop(long nNewValue);
	afx_msg long GetLeft();
	afx_msg void SetLeft(long nNewValue);
	afx_msg short GetMirror();
	afx_msg void SetMirror(short nNewValue);
	afx_msg short GetMouseMovePoints();
	afx_msg void SetMouseMovePoints(short nNewValue);
	afx_msg long GetMouseMovePointsCount();
	afx_msg BSTR GetName();
	afx_msg BOOL GetOnToolbar();
	afx_msg void SetOnToolbar(BOOL bNewValue);
	afx_msg BOOL GetOverlay();
	afx_msg void SetOverlay(BOOL bNewValue);
	afx_msg long GetOverlayTop();
	afx_msg void SetOverlayTop(long nNewValue);
	afx_msg long GetOverlayLeft();
	afx_msg void SetOverlayLeft(long nNewValue);
	afx_msg OLE_COLOR GetOverlayTransparentColor();
	afx_msg void SetOverlayTransparentColor(OLE_COLOR nNewValue);
	afx_msg short GetPenStyle();
	afx_msg void SetPenStyle(short nNewValue);
	afx_msg short GetPenFillStyle();
	afx_msg void SetPenFillStyle(short nNewValue);
	afx_msg BSTR GetPicture();
	afx_msg void SetPicture(LPCTSTR lpszNewValue);
	afx_msg BSTR GetPlayingCardsDll();
	afx_msg void SetPlayingCardsDll(LPCTSTR lpszNewValue);
	afx_msg short GetPlayingCard();
	afx_msg void SetPlayingCard(short nNewValue);
	afx_msg BOOL GetResize();
	afx_msg void SetResize(BOOL bNewValue);
	afx_msg long GetResizeWidth();
	afx_msg void SetResizeWidth(long nNewValue);
	afx_msg long GetResizeHeight();
	afx_msg void SetResizeHeight(long nNewValue);
	afx_msg long GetResourceBitmapID();
	afx_msg void SetResourceBitmapID(long nNewValue);
	afx_msg BSTR GetResourceFile();
	afx_msg void SetResourceFile(LPCTSTR lpszNewValue);
	afx_msg BOOL GetResourceFileLoaded();
	afx_msg long GetResourceIconWidth();
	afx_msg void SetResourceIconWidth(long nNewValue);
	afx_msg long GetResourceIconHeight();
	afx_msg void SetResourceIconHeight(long nNewValue);
	afx_msg long GetResourceIconID();
	afx_msg void SetResourceIconID(long nNewValue);
	afx_msg short GetRotate();
	afx_msg void SetRotate(short nNewValue);
	afx_msg short GetScaleMode();
	afx_msg void SetScaleMode(short nNewValue);
	afx_msg short GetScreenBitsPerPixel();
	afx_msg BOOL GetScroll();
	afx_msg void SetScroll(BOOL bNewValue);
	afx_msg long GetScrollX();
	afx_msg void SetScrollX(long nNewValue);
	afx_msg long GetScrollY();
	afx_msg void SetScrollY(long nNewValue);
	afx_msg short GetScrollBars();
	afx_msg void SetScrollBars(short nNewValue);
	afx_msg BOOL GetStretch();
	afx_msg void SetStretch(BOOL bNewValue);
	afx_msg BOOL GetWaitCursor();
	afx_msg void SetWaitCursor(BOOL bNewValue);
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg BOOL GetTapAndHoldEventEnabled();
	afx_msg void SetTapAndHoldEventEnabled(BOOL bNewValue);
	afx_msg OLE_COLOR GetTransparentColor();
	afx_msg void SetTransparentColor(OLE_COLOR nNewValue);
	afx_msg BSTR GetURLAgent();
	afx_msg void SetURLAgent(LPCTSTR lpszNewValue);
	afx_msg BOOL GetURLFlagCache();
	afx_msg void SetURLFlagCache(BOOL bNewValue);
	afx_msg BOOL GetURLFlagPassive();
	afx_msg void SetURLFlagPassive(BOOL bNewValue);
	afx_msg BOOL GetURLFlagReload();
	afx_msg void SetURLFlagReload(BOOL bNewValue);
	afx_msg long GetURLFlags();
	afx_msg void SetURLFlags(long nNewValue);
	afx_msg BOOL GetUseJPEGBitsPerPixel();
	afx_msg void SetUseJPEGBitsPerPixel(BOOL bNewValue);
	afx_msg float GetVersion();
	afx_msg BSTR GetVersionString();
	afx_msg short GetWildCard();
	afx_msg void SetWildCard(short nNewValue);
	afx_msg long GetHBitmap();
	afx_msg void SetHBitmap(long nNewValue);
	afx_msg long GetHIcon();
	afx_msg void SetHIcon(long nNewValue);
	afx_msg long GetHFont();
	afx_msg void SetHFont(long nNewValue);
	afx_msg long GetVersionMajor();
	afx_msg long GetVersionMinor();
	afx_msg BSTR GetResourceBitmapIDstr();
	afx_msg void SetResourceBitmapIDstr(LPCTSTR lpszNewValue);
	afx_msg void MethodStopUrlStream();
	afx_msg void Animate();
	afx_msg void MethodCaptureScreen();
	afx_msg void MethodClipImage();
	afx_msg void MethodCls();
	afx_msg BOOL MethodCopy();
	afx_msg BOOL MethodPaste();
	afx_msg void MethodCreateImage(long x, long y);
	afx_msg void MethodData(const VARIANT FAR& x, const VARIANT FAR& y);
	afx_msg void MethodDrawCircle(float a, float b, float c, const VARIANT FAR& d, const VARIANT FAR& e);
	afx_msg BOOL MethodDrawIcon(LPCTSTR szName, const VARIANT FAR& vIconID, const VARIANT FAR& vLarge, const VARIANT FAR& vocColor, const VARIANT FAR& vDrawType);
	afx_msg void MethodDrawLine(float nFromX, float nFromY, float nToX, float nToY, const VARIANT FAR& vocColor, const VARIANT FAR& vBox, const VARIANT FAR& vFill);
	afx_msg void MethodDrawMouseMoveLines(OLE_COLOR ooColor);
	afx_msg void MethodDrawMouseMoveLinesEx(long nStartX, long nStartY, long nEndX, long nEndY, OLE_COLOR ocColor);
	afx_msg void MethodDrawPicture(LPCTSTR szName, float nX, float nY, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, const VARIANT FAR& vnX2, const VARIANT FAR& vnY2, const VARIANT FAR& vnWidth2, const VARIANT FAR& vnHeight2, const VARIANT FAR& vnRasterOp);
	afx_msg void MethodDrawPoint(float x, float y, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawPolygon(short nPoints, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawRoundRect(float nLeft, float nTop, float nRight, float nBottom, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawPolyLines(short nPoints, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawText(LPCTSTR szText, const VARIANT FAR& vnX, const VARIANT FAR& vnY, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawTextInRect(LPCTSTR text, const VARIANT FAR& left, const VARIANT FAR& top, const VARIANT FAR& width, const VARIANT FAR& height, const VARIANT FAR& color);
	afx_msg BOOL MethodGetMouseMovePoint(short nPoint, long FAR* nX, long FAR* nY);
	afx_msg void MethodShow();
	afx_msg void MethodHide();
	afx_msg short MethodIntensityBlue(OLE_COLOR c);
	afx_msg short MethodIntensityRed(OLE_COLOR c);
	afx_msg short MethodIntensityGreen(OLE_COLOR c);
	afx_msg void MethodInvertImage();
	afx_msg void MethodMirrorImage();
	afx_msg void MethodMove(long nX, long nY, long nW, long nH);
	afx_msg OLE_COLOR MethodRGB(short nRed, short nGreen, short nBlue);
	afx_msg OLE_COLOR MethodQBColor(short nColorCode);
	afx_msg void MethodRefreshDesktopWallpaper();
	afx_msg void MethodSetCapture();
	afx_msg void MethodResizeImage();
	afx_msg void MethodRotateImage();
	afx_msg BOOL MethodSaveImageToFile(LPCTSTR szFileName, short nFileType);
	afx_msg void MethodScrollImage();
	afx_msg void MethodSetFocus();
	afx_msg void MethodSetPointArray(long nIndex, float nX, float nY);
	afx_msg long MethodTextWidth(LPCTSTR s);
	afx_msg long MethodTextHeight(LPCTSTR s);
	afx_msg long MethodURL(LPCTSTR lpszURL, const VARIANT FAR& vUser, const VARIANT FAR& vPassword);
	afx_msg void MethodZOrder(short pos);
	afx_msg void Refresh();
	afx_msg void MethodReleaseCapture();
	afx_msg OLE_COLOR GetPixel(long x, long y);
	afx_msg void SetPixel(long x, long y, OLE_COLOR nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CNSCEPictureBoxCtrl)
	void FireGotFocus()
		{FireEvent(eventidGotFocus,EVENT_PARAM(VTS_NONE));}
	void FireHScroll(long nSBCode, BOOL FAR* bRefresh, long FAR* nPos, long FAR* nMove, long nMin, long nMax, long nPage, long nCX, long nCY)
		{FireEvent(eventidHScroll,EVENT_PARAM(VTS_I4  VTS_PBOOL  VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4), nSBCode, bRefresh, nPos, nMove, nMin, nMax, nPage, nCX, nCY);}
	void FireVScroll(long nSBCode, BOOL FAR* bRefresh, long FAR* nPos, long FAR* nMove, long nMin, long nMax, long nPage, long nCX, long nCY)
		{FireEvent(eventidVScroll,EVENT_PARAM(VTS_I4  VTS_PBOOL  VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4), nSBCode, bRefresh, nPos, nMove, nMin, nMax, nPage, nCX, nCY);}
	void FireLostFocus()
		{FireEvent(eventidLostFocus,EVENT_PARAM(VTS_NONE));}
	void FireTapAndHold(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y)
		{FireEvent(eventidTapAndHold,EVENT_PARAM(VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS), Button, Shift, x, y);}
	void FireMouseDown(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y)
		{FireEvent(DISPID_MOUSEDOWN,EVENT_PARAM(VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS), Button, Shift, x, y);}
	void FireMouseMove(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y)
		{FireEvent(DISPID_MOUSEMOVE,EVENT_PARAM(VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS), Button, Shift, x, y);}
	void FireMouseUp(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y)
		{FireEvent(DISPID_MOUSEUP,EVENT_PARAM(VTS_I2  VTS_I2  VTS_XPOS_PIXELS  VTS_YPOS_PIXELS), Button, Shift, x, y);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CNSCEPictureBoxCtrl)
	dispidShowCaption = 1L,
	dispidWidth = 6L,
	dispidHeight = 7L,
	dispidFontName = 8L,
	dispidFontSize = 9L,
	dispidImageWidth = 10L,
	dispidImageHeight = 11L,
	dispidAnimationAvailable = 12L,
	dispidAnimationInterval = 13L,
	dispidAppearance = 14L,
	dispidAutoDetectTransparency = 15L,
	dispidAutoRefresh = 16L,
	dispidAutoSize = 17L,
	dispidBitmapOnClipboard = 18L,
	dispidBorderStyle = 19L,
	dispidByteArray = 20L,
	dispidCenter = 21L,
	dispidClip = 22L,
	dispidClipHeight = 23L,
	dispidClipWidth = 24L,
	dispidClipTop = 25L,
	dispidClipLeft = 26L,
	dispidCommandButton = 27L,
	dispidCommonBitmapID = 28L,
	dispidCommonBitmapType = 29L,
	dispidScreenLeft = 30L,
	dispidScreenTop = 31L,
	dispidScreenHeight = 32L,
	dispidScreenWidth = 33L,
	dispidDrawWidth = 34L,
	dispidFillStyle = 35L,
	dispidFillColor = 36L,
	dispidFocusRect = 37L,
	dispidFocusRectIndentLeft = 38L,
	dispidFocusRectIndentRight = 39L,
	dispidFocusRectIndentTop = 40L,
	dispidFocusRectIndentBottom = 41L,
	dispidFontBold = 42L,
	dispidFontItalic = 43L,
	dispidFontStrikethru = 44L,
	dispidFontTransparent = 45L,
	dispidFontUnderline = 46L,
	dispidFontEscapement = 47L,
	dispidFontOrientation = 48L,
	dispidFontWeight = 49L,
	dispidHScrollPosition = 50L,
	dispidVScrollPosition = 51L,
	dispidVisible = 53L,
	dispidImageBitsPerPixel = 54L,
	dispidImageLoadBitsPerPixel = 55L,
	dispidImageLoadBufferSize = 56L,
	dispidImageLoadMaxHeight = 57L,
	dispidImageLoadMaxWidth = 58L,
	dispidImageLoadScalePercent = 59L,
	dispidImageLoaded = 60L,
	dispidInvert = 61L,
	dispidTop = 62L,
	dispidLeft = 63L,
	dispidMirror = 64L,
	dispidMouseMovePoints = 65L,
	dispidMouseMovePointsCount = 66L,
	dispidOnToolbar = 68L,
	dispidOverlay = 69L,
	dispidOverlayTop = 70L,
	dispidOverlayLeft = 71L,
	dispidOverlayTransparentColor = 72L,
	dispidPenStyle = 73L,
	dispidPenFillStyle = 74L,
	dispidName = 67L,
	dispidPicture = 75L,
	dispidPlayingCardsDll = 76L,
	dispidPlayingCard = 77L,
	dispidResize = 78L,
	dispidResizeWidth = 79L,
	dispidResizeHeight = 80L,
	dispidResourceBitmapID = 81L,
	dispidResourceFile = 82L,
	dispidResourceFileLoaded = 83L,
	dispidResourceIconWidth = 84L,
	dispidResourceIconHeight = 85L,
	dispidResourceIconID = 86L,
	dispidRotate = 87L,
	dispidScaleMode = 88L,
	dispidScreenBitsPerPixel = 89L,
	dispidScroll = 90L,
	dispidScrollX = 91L,
	dispidScrollY = 92L,
	dispidScrollBars = 93L,
	dispidStretch = 94L,
	dispidWaitCursor = 95L,
	dispidTag = 96L,
	dispidTapAndHoldEventEnabled = 97L,
	dispidTransparentColor = 98L,
	dispidURLAgent = 99L,
	dispidURLFlagCache = 100L,
	dispidURLFlagPassive = 101L,
	dispidURLFlagReload = 102L,
	dispidURLFlags = 103L,
	dispidUseJPEGBitsPerPixel = 104L,
	dispidVersion = 105L,
	dispidVersionString = 106L,
	dispidWildCard = 107L,
	dispidHBitmap = 108L,
	dispidHIcon = 109L,
	dispidHFont = 110L,
	dispidScaleWidth = 2L,
	dispidScaleHeight = 3L,
	dispidScaleLeft = 4L,
	dispidScaleTop = 5L,
	dispidVersionMajor = 111L,
	dispidVersionMinor = 112L,
	dispidResourceBitmapIDstr = 113L,
	dispidCaptureScreen = 116L,
	dispidClipImage = 117L,
	dispidCls = 118L,
	dispidCopy = 119L,
	dispidPaste = 120L,
	dispidCreateImage = 121L,
	dispidData = 122L,
	dispidDrawCircle = 123L,
	dispidDrawIcon = 124L,
	dispidDrawLine = 125L,
	dispidDrawMouseMoveLines = 126L,
	dispidDrawMouseMoveLinesEx = 127L,
	dispidDrawPicture = 128L,
	dispidDrawPoint = 129L,
	dispidDrawPolygon = 130L,
	dispidDrawRoundRect = 131L,
	dispidDrawPolyLines = 132L,
	dispidDrawText = 133L,
	dispidDrawTextInRect = 134L,
	dispidGetMouseMovePoint = 135L,
	dispidShow = 136L,
	dispidHide = 137L,
	dispidIntensityBlue = 138L,
	dispidIntensityRed = 139L,
	dispidIntensityGreen = 140L,
	dispidInvertImage = 141L,
	dispidMirrorImage = 142L,
	dispidMove = 143L,
	dispidStopUrlStream = 114L,
	dispidAnimate = 115L,
	dispidPixel = 160L,
	dispidRGB = 144L,
	dispidQBColor = 145L,
	dispidRefreshDesktopWallpaper = 146L,
	dispidSetCapture = 147L,
	dispidResizeImage = 148L,
	dispidRotateImage = 149L,
	dispidSaveImageToFile = 150L,
	dispidScrollImage = 151L,
	dispidSetFocus = 152L,
	dispidSetPointArray = 153L,
	dispidTextWidth = 154L,
	dispidTextHeight = 155L,
	dispidURL = 156L,
	dispidZOrder = 157L,
	dispidReleaseCapture = 159L,
	eventidGotFocus = 1L,
	eventidHScroll = 2L,
	eventidVScroll = 3L,
	eventidLostFocus = 4L,
	eventidTapAndHold = 5L,
	//}}AFX_DISP_ID
	};

private:	
	BOOL m_bAutoDetectTransparency;
	BOOL m_bWinNT;
	BOOL m_bFocusRect;
	BOOL m_bHaveFocus;
	BOOL m_bVBCE;
	BOOL m_bVBCEAutoSize;
	BOOL m_bScroll;
	BOOL m_bFirstTimeAutoSize;
	BOOL m_bWaitingForResize;
	BOOL m_bAutoRefresh;
	BOOL m_bWorkingCaptureScreen;
	BOOL m_bWorkingClip;
	BOOL m_bClip;
	BOOL m_bWorkingAnimationInvert;
	BOOL m_bWorkingInvert;
	BOOL m_bInvert;
	BOOL m_bResize;
	BOOL m_bWorkingAnimationInitialized;
	BOOL m_bWorkingAnimationAvailable;
	BOOL m_bAnimationAvailable;
	BOOL m_bPlayingCardsDllAnimationAvailable;
	BOOL m_bVisible;
	BOOL m_bWaitCursor;
	BOOL m_bDisplayExpired;
	BOOL m_bIsStretched;
	BOOL m_bStretch;
	BOOL m_bOverlay;
	BOOL m_bAutoSize;
	BOOL m_bFontTransparent;
	BOOL m_bCommandButton;
	BOOL m_bWorkingPropExchange;
	BOOL m_bOnToolbar;
	BOOL m_bHaveName;
	BOOL m_bHasMousePointer;
	BOOL m_bUseJPEGBitsPerPixel;
	BOOL m_bTapAndHoldEventEnabled;
	BOOL m_bUrlHttp;
	BOOL m_bAlreadyLoaded;
	short m_nCount;
	short m_nCenter;
	short m_nAppearance;
	short m_nCommonBitmapID;
	short m_nCommonBitmapType;
	short m_nBorderStyle;
	short m_nWorkingAnimationMirror;
	short m_nWorkingAnimationRotate;
	short m_nWorkingAnimationWidth[2];
	short m_nWorkingAnimationHeight[2];
	short m_nWorkingAnimationLeft[2];
	short m_nWorkingAnimationTop[2];
	short m_nWildCard;
	short m_nWorkingWildCard;
	short m_nWorkingAnimationCount;
	short m_nRotate;
	short m_nMirror;
	short m_nWorkingMirror;
	short m_nWorkingRotate;
	short m_nPlayingCard;
	short m_nMouseMovePoints;
	short m_nImageLoadBitsPerPixel;
	short m_nWorkingAnimationPlatform;
	short m_nPenFillStyle;
	short m_nPenStyle;
	short m_nFillStyle;
	short m_nFontNamesCount;
	short m_nScrollBars;
	UINT m_nMouseMovePointsCount;
	UINT m_nTimer;
	long m_nAutoSizeWidth;
	long m_nAutoSizeHeight;
	long m_nHideWidth;
	long m_nHideHeight;
	long m_nScrollY;
	long m_nScrollX;
	long m_nDrawWidth;
	long m_nImageLoadBufferSize;
	long m_nOverlayLeft;
	long m_nOverlayTop;
	long m_nImageLoadMaxWidth;
	long m_nImageLoadMaxHeight;
	long m_nImageLoadScalePercent;
	long m_nWorkingClipWidth;
	long m_nWorkingClipTop;
	long m_nWorkingClipLeft;
	long m_nWorkingClipHeight;
	long m_nResizeWidth;
	long m_nResizeHeight;
	long m_nClipWidth;
	long m_nClipTop;
	long m_nClipLeft;
	long m_nClipHeight;
	long m_nWorkingAnimationInterval;
	long m_nAnimationInterval;
	long m_nResourceID;
	long m_nResourceBitmapID;
	long m_nResourceIconID;
	long m_nDrawTextCurrentY;
	long m_nLogPixelsX;
	long m_nLogPixelsY;
	long m_nFocusRectIndentBottom;
	long m_nFocusRectIndentLeft;
	long m_nFocusRectIndentRight;
	long m_nFocusRectIndentTop;
	long m_nHScrollPosition;
	long m_nVScrollPosition;
	long m_nWorkingHPage;
	long m_nWorkingVPage;
	long m_nWorkingHCX;
	long m_nWorkingHCY;
	long m_nWorkingVCX;
	long m_nWorkingVCY;
	long m_nWorkingHMin;
	long m_nWorkingHMax;
	long m_nWorkingVMin;
	long m_nWorkingVMax;
	long m_nPointArraySize;
	long m_nURLFlags;
	long m_nResourceIconHeight;
	long m_nResourceIconWidth;
	int m_scaleMode;
	HWND m_hParentWindow;
	HINSTANCE m_hInstMe;
	HINSTANCE m_hResourceFile;
	HINSTANCE m_hPlayingCardsDll;
	HINSTANCE m_hCommCtrl;
	HINSTANCE m_hInstance;
	OSVERSIONINFO m_versionInfo;
#ifdef UNDER_CE
	HINSTANCE m_himgdecmpDll;
	DecompressImageIndirectProc m_procDecompressImageIndirect;
#endif // UNDER_CE
	HBITMAP m_hBitmap;
	HBITMAP m_hWorkingBitmap;
	HBITMAP m_hWorkingIconBitmap;
	HBITMAP m_hWorkingAnimationBitmap[2];
	HFONT m_hFont;
	OLE_COLOR m_ocFillColor;
	OLE_COLOR m_ocOverlayTransparentColor;
	OLE_COLOR m_ocTransparentColor;
	COleVariant m_vTag;
	CString m_strResourceFile;
	CString m_strResourceID;
	CString m_strResourceBitmapID;
	CString m_strName;
	CString m_strPicture;
	CString m_strFontResult;
	CString m_strPlayingCardsDll;
	CString m_strVersionString;
	CString m_strHeaders;
	CString m_strURLAgent;
	COleDateTime m_dteDate;
	//COleDateTime m_dteExpire;
	POINT *m_ptPointArray;
	POINT m_ptsMouseMove[MOUSEMOVEPOINTSCOUNTMAX];
	LOGFONT m_LogFont;
	BYTE *m_ByteArray;
	long m_nByteArray;
	CUrlImage *m_pUrlImage;
	CCriticalSection m_cs;

private:
	BOOL CommonGetIconSize(HICON hIcon, long *lWidth, long *lHeight);
	HBITMAP CommonGetBitmapFromIcon(HICON hIcon, long xPassed, long yPassed, OLE_COLOR ocColorPassed, long nDrawType);
	long StartURL(LPCTSTR lpszURL, LPCTSTR lpszUser,LPCTSTR lpszPassword); 
	bool CommonSaveImageToByteArray();
	bool IsMissing(const VARIANT *var);
	void CommonDesignRefresh();
	BOOL CommonGetDisplayString(DISPID dispid, CString& strValue, DWORD dwCookie);
	void CommonScrollBars();
	void CommonLoadImage(HBITMAP* hBitmap, bool* bCopied);
	void CommonDrawPoint(long nX, long nY, OLE_COLOR ocColor);
	void CommonDrawRoundRect(long nLeft, long nTop, long nRight, long nBottom, long nWidth, long nHeight, OLE_COLOR ocColor, short nFillStyle);
	bool CommonOptionalBool(const VARIANT *vBool, bool bInit);
	long CommonOptionalLong(const VARIANT *vLong, long nInit);
	float CommonOptionalFloat(const VARIANT *vFloat, float flInit);
	CString CommonOptionalString(const VARIANT *vString, LPCTSTR lpszInit);
	void CommonDestroyFont();
	void CommonCreateFont();
	long CommonDrawText(int nType, long nX, long nY, LPCTSTR szText, OLE_COLOR ocColor);
	void CommonDrawTextInRect(int nType, RECT *rect, LPCTSTR szText, OLE_COLOR ocColor);
	static int CALLBACK CallbackEnumFontFamilyCallback1(ENUMLOGFONT FAR *lpelf, NEWTEXTMETRIC FAR *lpntm, int FontType, LPARAM lParam);
	static int CALLBACK CallbackEnumFontFamilyCallback2(ENUMLOGFONT FAR *lpelf, NEWTEXTMETRIC FAR *lpntm, int FontType, LPARAM lParam);
	static DWORD CALLBACK CallbackGetImageData(LPSTR szBuffer, DWORD dwBufferMax, LPARAM lParam);
	void CommonFireMousePoints( short nButtons, short nKeys);
	void CommonFireMouse(short nType, short nButtons, short nKeys, long x, long y);
	void CommonDrawPolyLines(POINT* pts, short nPoints, OLE_COLOR ocColor);
	bool IsDIBSection(HBITMAP hBitmap);
	short CommonFireMouseKeys(UINT nFlags);
	short CommonFireMouseButtons(UINT nFlags);
	DWORD SwapEndian(DWORD nOld);
	UINT CEGetDIBColorTable(HBITMAP hDIBSection, UINT uStartIndex, UINT cEntries, RGBQUAD *pColors);
	HBITMAP CommonScroll(HBITMAP hBitmap);
	HBITMAP CommonGetBitmapScroll(HBITMAP hBitmap, long nScrollX, long nScrollY);
	HBITMAP CommonGetBitmapControlSize();
	HBITMAP CommonGetBitmapResource(int nResource);
	HBITMAP CommonGetBitmapResize(HBITMAP hBitmap, int nWidth, int nHeight);
	HBITMAP CommonGetBitmapClip(HBITMAP hBitmap, int nLeft, int nTop, int nWidth, int nHeight);
	HBITMAP CommonGetBitmapOverlay(HBITMAP hDestBitmap, HBITMAP hSourceBitmap, int nLeft, int nTop, int nWidth, int nHeight, OLE_COLOR oc_Transparent);
	HBITMAP CommonGetBitmapCopy(HBITMAP hBitmap);
	HBITMAP CommonGetBitmapCopyToNewBPP(HBITMAP hBitmap, short nBPP);
	HBITMAP CommonGetBitmapInverted(HBITMAP hBitmap);
	HBITMAP CommonGetBitmapRotated(HBITMAP hBitmap, int degrees);
	HBITMAP CommonGetBitmapMirrored(HBITMAP hBitmap, short nMirror);
	HBITMAP CommonGetBitmapScreen();
	HBITMAP CommonResize(HBITMAP hBitmap);
	HBITMAP CommonClip(HBITMAP hBitmap);
	HBITMAP CommonInvert(HBITMAP hBitmap);
	HBITMAP CommonMirror(HBITMAP hBitmap);
	HBITMAP CommonRotate(HBITMAP hBitmap);
	BOOL CommonCheckAutoSize(BOOL bForce);
	BOOL CommonLoadImageIntoBitmap();
	void CommonClearForLoad();
	void CommonGetCommCtrlInstance();
	void CommonGetCardsInstance();
	void AnimateCheckMirror();
	void AnimateCheckRotate();
	void AnimateCheckInvert();
	void AnimatePlayingCard(BOOL bInvalidateControl, HBITMAP hBitmap);
	void CommonSetNewTimer();
	long TransformPassedX(float);
	long TransformPassedY(float);
	long TransformPassedWidth(float);
	long TransformPassedHeight(float);
	float UnTransformPassedX(long);
	float UnTransformPassedY(long);
	float UnTransformPassedWidth(long);
	float UnTransformPassedHeight(long);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NSCEPICTUREBOXCTL_H__98B3D255_AA73_4EDF_814E_77D1BFC40473__INCLUDED)
