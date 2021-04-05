#if !defined(AFX_S309PICTUREBOXCTL_H__D4D7C4C6_2CC5_11D3_AE29_00608CC1DD62__INCLUDED_)
#define AFX_S309PICTUREBOXCTL_H__D4D7C4C6_2CC5_11D3_AE29_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define MOUSEMOVEPOINTSCOUNTMAX 200

// S309PictureBoxCtl.h : Declaration of the CS309PictureBox ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CS309PictureBox : See S309PictureBoxCtl.cpp for implementation.

class CS309PictureBox : public COleControl
{
	DECLARE_DYNCREATE(CS309PictureBox)

// Constructor
public:
	CS309PictureBox();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309PictureBox)
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
	~CS309PictureBox();

	DECLARE_OLECREATE_EX(CS309PictureBox)    // Class factory and guid
	DECLARE_OLETYPELIB(CS309PictureBox)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CS309PictureBox)     // Property page IDs
	DECLARE_OLECTLTYPE(CS309PictureBox)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CS309PictureBox)
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
	//{{AFX_DISPATCH(CS309PictureBox)
	afx_msg BOOL GetAnimationAvailable();
	afx_msg long GetAnimationInterval();
	afx_msg void SetAnimationInterval(long nNewValue);
	afx_msg short GetAppearance();
	afx_msg void SetAppearance(short nNewValue);
	afx_msg BOOL GetAutoRefresh();
	afx_msg void SetAutoRefresh(BOOL bNewValue);
	afx_msg BOOL GetAutoSize();
	afx_msg void SetAutoSize(BOOL bNewValue);
	afx_msg BOOL GetBitmapOnClipboard();
	afx_msg short GetBorderStyle();
	afx_msg void SetBorderStyle(short nNewValue);
	afx_msg short GetCenter();
	afx_msg void SetCenter(short nNewValue);
	afx_msg BOOL GetClip();
	afx_msg void SetClip(BOOL bNewValue);
	afx_msg long GetClipHeight();
	afx_msg void SetClipHeight(long nNewValue);
	afx_msg long GetClipLeft();
	afx_msg void SetClipLeft(long nNewValue);
	afx_msg long GetClipTop();
	afx_msg void SetClipTop(long nNewValue);
	afx_msg long GetClipWidth();
	afx_msg void SetClipWidth(long nNewValue);
	afx_msg short GetCommonBitmapID();
	afx_msg void SetCommonBitmapID(short nNewValue);
	afx_msg short GetCommonBitmapType();
	afx_msg void SetCommonBitmapType(short nNewValue);
	afx_msg long GetDrawWidth();
	afx_msg void SetDrawWidth(long nNewValue);
	afx_msg OLE_COLOR GetFillColor();
	afx_msg void SetFillColor(OLE_COLOR nNewValue);
	afx_msg short GetFillStyle();
	afx_msg void SetFillStyle(short nNewValue);
	afx_msg long GetHeight();
	afx_msg void SetHeight(long nNewValue);
	afx_msg long GetImageHeight();
	afx_msg long GetImageLoadBufferSize();
	afx_msg void SetImageLoadBufferSize(long nNewValue);
	afx_msg long GetImageLoadMaxHeight();
	afx_msg void SetImageLoadMaxHeight(long nNewValue);
	afx_msg long GetImageLoadMaxWidth();
	afx_msg void SetImageLoadMaxWidth(long nNewValue);
	afx_msg BOOL GetImageLoaded();
	afx_msg long GetImageWidth();
	afx_msg BOOL GetInvert();
	afx_msg void SetInvert(BOOL bNewValue);
	afx_msg long GetLeft();
	afx_msg void SetLeft(long nNewValue);
	afx_msg short GetMirror();
	afx_msg void SetMirror(short nNewValue);
	afx_msg BSTR GetName();
	afx_msg BOOL GetOverlay();
	afx_msg void SetOverlay(BOOL bNewValue);
	afx_msg long GetOverlayLeft();
	afx_msg void SetOverlayLeft(long nNewValue);
	afx_msg long GetOverlayTop();
	afx_msg void SetOverlayTop(long nNewValue);
	afx_msg OLE_COLOR GetOverlayTransparentColor();
	afx_msg void SetOverlayTransparentColor(OLE_COLOR nNewValue);
	afx_msg short GetPenFillStyle();
	afx_msg void SetPenFillStyle(short nNewValue);
	afx_msg short GetPenStyle();
	afx_msg void SetPenStyle(short nNewValue);
	afx_msg BSTR GetPicture();
	afx_msg void SetPicture(LPCTSTR lpszNewValue);
	afx_msg short GetPlayingCard();
	afx_msg void SetPlayingCard(short nNewValue);
	afx_msg BOOL GetResize();
	afx_msg void SetResize(BOOL bNewValue);
	afx_msg long GetResizeHeight();
	afx_msg void SetResizeHeight(long nNewValue);
	afx_msg long GetResizeWidth();
	afx_msg void SetResizeWidth(long nNewValue);
	afx_msg long GetResourceBitmapID();
	afx_msg void SetResourceBitmapID(long nNewValue);
	afx_msg BSTR GetResourceFile();
	afx_msg void SetResourceFile(LPCTSTR lpszNewValue);
	afx_msg short GetRotate();
	afx_msg void SetRotate(short nNewValue);
	afx_msg short GetScaleMode();
	afx_msg void SetScaleMode(short nNewValue);
	afx_msg short GetScreenBitsPerPixel();
	afx_msg long GetScreenHeight();
	afx_msg long GetScreenLeft();
	afx_msg long GetScreenWidth();
	afx_msg long GetScreenTop();
	afx_msg BOOL GetStretch();
	afx_msg void SetStretch(BOOL bNewValue);
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg long GetTop();
	afx_msg void SetTop(long nNewValue);
	afx_msg OLE_COLOR GetTransparentColor();
	afx_msg void SetTransparentColor(OLE_COLOR nNewValue);
	afx_msg BOOL GetVisible();
	afx_msg void SetVisible(BOOL bNewValue);
	afx_msg BOOL GetWaitCursor();
	afx_msg void SetWaitCursor(BOOL bNewValue);
	afx_msg long GetWidth();
	afx_msg void SetWidth(long nNewValue);
	afx_msg short GetWildCard();
	afx_msg void SetWildCard(short nNewValue);
	afx_msg long GethBitmap();
	afx_msg void SethBitmap(long nNewValue);
	afx_msg BOOL GetResourceFileLoaded();
	afx_msg short GetImageBitsPerPixel();
	afx_msg void SetImageBitsPerPixel(short nNewValue);
	afx_msg short GetImageLoadBitsPerPixel();
	afx_msg void SetImageLoadBitsPerPixel(short nNewValue);
	afx_msg BOOL GetScroll();
	afx_msg void SetScroll(BOOL bNewValue);
	afx_msg long GetScrollX();
	afx_msg void SetScrollX(long nNewValue);
	afx_msg long GetScrollY();
	afx_msg void SetScrollY(long nNewValue);
	afx_msg long GetMouseMovePointsCount();
	afx_msg short GetMouseMovePoints();
	afx_msg void SetMouseMovePoints(short nNewValue);
	afx_msg float GetVersion();
	afx_msg BOOL GetFontBold();
	afx_msg void SetFontBold(BOOL bNewValue);
	afx_msg BOOL GetFontItalic();
	afx_msg void SetFontItalic(BOOL bNewValue);
	afx_msg BSTR GetFontName();
	afx_msg void SetFontName(LPCTSTR lpszNewValue);
	afx_msg BOOL GetFontStrikethru();
	afx_msg void SetFontStrikethru(BOOL bNewValue);
	afx_msg BOOL GetFontUnderline();
	afx_msg void SetFontUnderline(BOOL bNewValue);
	afx_msg BOOL GetFontTransparent();
	afx_msg void SetFontTransparent(BOOL bNewValue);
	afx_msg long GetFontWeight();
	afx_msg void SetFontWeight(long nNewValue);
	afx_msg long GetFontSize();
	afx_msg void SetFontSize(long nNewValue);
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
	afx_msg BOOL GetCommandButton();
	afx_msg void SetCommandButton(BOOL bNewValue);
	afx_msg long GethFont();
	afx_msg void SethFont(long nNewValue);
	afx_msg short GetScrollBars();
	afx_msg void SetScrollBars(short nNewValue);
	afx_msg long GetHScrollPosition();
	afx_msg void SetHScrollPosition(long nNewValue);
	afx_msg long GetVScrollPosition();
	afx_msg void SetVScrollPosition(long nNewValue);
	afx_msg BOOL GetOnToolbar();
	afx_msg void SetOnToolbar(BOOL bNewValue);
	afx_msg long GetResourceIconID();
	afx_msg void SetResourceIconID(long nNewValue);
	afx_msg BOOL GetUseJPEGBitsPerPixel();
	afx_msg void SetUseJPEGBitsPerPixel(BOOL bNewValue);
	afx_msg VARIANT GetByteArray();
	afx_msg void SetByteArray(const VARIANT FAR& newValue);
	afx_msg BOOL GetTapAndHoldEventEnabled();
	afx_msg void SetTapAndHoldEventEnabled(BOOL bNewValue);
	afx_msg BSTR GetPlayingCardsDll();
	afx_msg void SetPlayingCardsDll(LPCTSTR lpszNewValue);
	afx_msg BSTR GetVersionString();
	afx_msg BSTR GetHeaders();
	afx_msg long GetURLFlags();
	afx_msg void SetURLFlags(long nNewValue);
	afx_msg BOOL GetURLFlagPassive();
	afx_msg void SetURLFlagPassive(BOOL bNewValue);
	afx_msg BOOL GetURLFlagCache();
	afx_msg void SetURLFlagCache(BOOL bNewValue);
	afx_msg BOOL GetURLFlagReload();
	afx_msg void SetURLFlagReload(BOOL bNewValue);
	afx_msg BSTR GetURLAgent();
	afx_msg void SetURLAgent(LPCTSTR lpszNewValue);
	afx_msg long GetImageLoadScalePercent();
	afx_msg void SetImageLoadScalePercent(long nNewValue);
	afx_msg long GetFontEscapement();
	afx_msg void SetFontEscapement(long nNewValue);
	afx_msg long GetFontOrientation();
	afx_msg void SetFontOrientation(long nNewValue);
	afx_msg long GetHIcon();
	afx_msg void SetHIcon(long nNewValue);
	afx_msg BOOL GetAutoDetectTransparency();
	afx_msg void SetAutoDetectTransparency(BOOL bNewValue);
	afx_msg long GetResourceIconHeight();
	afx_msg void SetResourceIconHeight(long nNewValue);
	afx_msg long GetResourceIconWidth();
	afx_msg void SetResourceIconWidth(long nNewValue);
	afx_msg void MethodAnimate();
	afx_msg void MethodCaptureScreen();
	afx_msg void MethodClipImage();
	afx_msg void MethodCls();
	afx_msg BOOL MethodCopy();
	afx_msg void MethodCreateImage(long nX, long nY);
	afx_msg void MethodHide();
	afx_msg void MethodInvertImage();
	afx_msg void MethodMirrorImage();
	afx_msg void MethodMove(long nX, long nY, long nW, long nH);
	afx_msg BOOL MethodPaste();
	afx_msg OLE_COLOR MethodQBColor(short nColorCode);
	afx_msg void MethodResizeImage();
	afx_msg void MethodRotateImage();
	afx_msg void MethodSetFocus();
	afx_msg void MethodSetPointArray(long nIndex, long nX, long nY);
	afx_msg void MethodShow();
	afx_msg void MethodZOrder(short nPosition);
	afx_msg BOOL MethodSaveImageToFile(LPCTSTR szFileName, short nFileType);
	afx_msg OLE_COLOR MethodRGB(short nRed, short nGreen, short nBlue);
	afx_msg short MethodIntensityRed(OLE_COLOR ocColor);
	afx_msg short MethodIntensityGreen(OLE_COLOR ocColor);
	afx_msg short MethodIntensityBlue(OLE_COLOR ocColor);
	afx_msg void MethodScrollImage();
	afx_msg void MethodRefreshDesktopWallpaper();
	afx_msg void MethodSetCapture();
	afx_msg void MethodReleaseCapture();
	afx_msg void MethodDrawMouseMoveLinesEx(long nStartX, long nStartY, long nEndX, long nEndY, OLE_COLOR ocColor);
	afx_msg void MethodDrawMouseMoveLines(OLE_COLOR ocColor);
	afx_msg BOOL MethodGetMouseMovePoint(short nPoint, long FAR* nX, long FAR* nY);
	afx_msg void MethodRefreshX();
	afx_msg long MethodTextWidth(LPCTSTR szText);
	afx_msg long MethodTextHeight(LPCTSTR szText);
	afx_msg void MethodDrawCircle(long nX, long nY, float flRadius, const VARIANT FAR& vocColor, const VARIANT FAR& vflAspect);
	afx_msg void MethodDrawLine(long nFromX, long nFromY, long nToX, long nToY, const VARIANT FAR& vocColor, const VARIANT FAR& vBox, const VARIANT FAR& vFill);
	afx_msg void MethodDrawPoint(long nX, long nY, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawPolygon(short nPoints, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawRoundRect(long nLeft, long nTop, long nRight, long nBottom, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawPolyLines(short nPoints, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawText(LPCTSTR szText, const VARIANT FAR& vnX, const VARIANT FAR& vnY, const VARIANT FAR& vocColor);
	afx_msg void MethodDrawPicture(LPCTSTR szName, long nX, long nY, const VARIANT FAR& vnWidth, const VARIANT FAR& vnHeight, const VARIANT FAR& vnX2, const VARIANT FAR& vnY2, const VARIANT FAR& vnWidth2, const VARIANT FAR& vnHeight2, const VARIANT FAR& vnRasterOp);
	afx_msg BOOL MethodDrawIcon(LPCTSTR szFile, const VARIANT FAR& vIconID, const VARIANT FAR& vLarge, const VARIANT FAR& vocColor, const VARIANT FAR& vDrawType);
	afx_msg void MethodStopUrlStream();
	afx_msg void MethodData(const VARIANT FAR& varData, const VARIANT FAR& varDataLength);
	afx_msg long MethodURL(LPCTSTR lpszURL, const VARIANT FAR& vUser, const VARIANT FAR& vPassword);
	afx_msg void MethodDrawTextInRect(LPCTSTR Text, const VARIANT FAR& Left, const VARIANT FAR& Top, const VARIANT FAR& Width, const VARIANT FAR& Height, const VARIANT FAR& Color);
	afx_msg OLE_COLOR GetPixel(long nX, long nY);
	afx_msg void SetPixel(long nX, long nY, OLE_COLOR nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void MethodAboutBox();

// Event maps
	//{{AFX_EVENT(CS309PictureBox)
	void FireLostFocus()
		{FireEvent(eventidLostFocusX,EVENT_PARAM(VTS_NONE));}
	void FireGotFocus()
		{FireEvent(eventidGotFocusX,EVENT_PARAM(VTS_NONE));}
	void FireHScroll(long nSBCode, BOOL FAR* bRefresh, long FAR* nPos, long FAR* nMove, long nMin, long nMax, long nPage, long nCX, long nCY)
		{FireEvent(eventidHScroll,EVENT_PARAM(VTS_I4  VTS_PBOOL  VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4), nSBCode, bRefresh, nPos, nMove, nMin, nMax, nPage, nCX, nCY);}
	void FireVScroll(long nSBCode, BOOL FAR* bRefresh, long FAR* nPos, long FAR* nMove, long nMin, long nMax, long nPage, long nCX, long nCY)
		{FireEvent(eventidVScroll,EVENT_PARAM(VTS_I4  VTS_PBOOL  VTS_PI4  VTS_PI4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4), nSBCode, bRefresh, nPos, nMove, nMin, nMax, nPage, nCX, nCY);}
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
	//{{AFX_DISP_ID(CS309PictureBox)
	dispidAnimationAvailable = 1L,
	dispidAnimationInterval = 2L,
	dispidAppearance = 3L,
	dispidAutoRefresh = 4L,
	dispidAutoSize = 5L,
	dispidBitmapOnClipboard = 6L,
	dispidBorderStyle = 7L,
	dispidCenter = 8L,
	dispidClip = 9L,
	dispidClipHeight = 10L,
	dispidClipLeft = 11L,
	dispidClipTop = 12L,
	dispidClipWidth = 13L,
	dispidCommonBitmapID = 14L,
	dispidCommonBitmapType = 15L,
	dispidDrawWidth = 16L,
	dispidFillColor = 17L,
	dispidFillStyle = 18L,
	dispidHeight = 19L,
	dispidImageHeight = 20L,
	dispidImageLoadBufferSize = 21L,
	dispidImageLoadMaxHeight = 22L,
	dispidImageLoadMaxWidth = 23L,
	dispidImageLoaded = 24L,
	dispidImageWidth = 25L,
	dispidInvert = 26L,
	dispidLeft = 27L,
	dispidMirror = 28L,
	dispidName = 29L,
	dispidOverlay = 30L,
	dispidOverlayLeft = 31L,
	dispidOverlayTop = 32L,
	dispidOverlayTransparentColor = 33L,
	dispidPenFillStyle = 34L,
	dispidPenStyle = 35L,
	dispidPicture = 36L,
	dispidPlayingCard = 37L,
	dispidResize = 38L,
	dispidResizeHeight = 39L,
	dispidResizeWidth = 40L,
	dispidResourceBitmapID = 41L,
	dispidResourceFile = 42L,
	dispidRotate = 43L,
	dispidScaleMode = 44L,
	dispidScreenBitsPerPixel = 45L,
	dispidScreenHeight = 46L,
	dispidScreenLeft = 47L,
	dispidScreenWidth = 48L,
	dispidScreenTop = 49L,
	dispidStretch = 50L,
	dispidTag = 51L,
	dispidTop = 52L,
	dispidTransparentColor = 53L,
	dispidVisible = 54L,
	dispidWaitCursor = 55L,
	dispidWidth = 56L,
	dispidWildCard = 57L,
	dispidHBitmap = 58L,
	dispidResourceFileLoaded = 59L,
	dispidImageBitsPerPixel = 60L,
	dispidImageLoadBitsPerPixel = 61L,
	dispidScroll = 62L,
	dispidScrollX = 63L,
	dispidScrollY = 64L,
	dispidMouseMovePointsCount = 65L,
	dispidMouseMovePoints = 66L,
	dispidVersion = 67L,
	dispidFontBold = 68L,
	dispidFontItalic = 69L,
	dispidFontName = 70L,
	dispidFontStrikethru = 71L,
	dispidFontUnderline = 72L,
	dispidFontTransparent = 73L,
	dispidFontWeight = 74L,
	dispidFontSize = 75L,
	dispidFocusRect = 76L,
	dispidFocusRectIndentLeft = 77L,
	dispidFocusRectIndentRight = 78L,
	dispidFocusRectIndentTop = 79L,
	dispidFocusRectIndentBottom = 80L,
	dispidCommandButton = 81L,
	dispidHFont = 82L,
	dispidScrollBars = 83L,
	dispidHScrollPosition = 84L,
	dispidVScrollPosition = 85L,
	dispidOnToolbar = 86L,
	dispidResourceIconID = 87L,
	dispidUseJPEGBitsPerPixel = 88L,
	dispidByteArray = 89L,
	dispidTapAndHoldEventEnabled = 90L,
	dispidPlayingCardsDll = 91L,
	dispidVersionString = 92L,
	dispidHeaders = 93L,
	dispidURLFlags = 94L,
	dispidURLFlagPassive = 95L,
	dispidURLFlagCache = 96L,
	dispidURLFlagReload = 97L,
	dispidURLAgent = 98L,
	dispidImageLoadScalePercent = 99L,
	dispidFontEscapement = 100L,
	dispidFontOrientation = 101L,
	dispidHIcon = 102L,
	dispidAutoDetectTransparency = 103L,
	dispidResourceIconHeight = 104L,
	dispidResourceIconWidth = 105L,
	dispidAnimate = 106L,
	dispidCaptureScreen = 107L,
	dispidClipImage = 108L,
	dispidCls = 109L,
	dispidCopy = 110L,
	dispidCreateImage = 111L,
	dispidHide = 112L,
	dispidInvertImage = 113L,
	dispidMirrorImage = 114L,
	dispidMove = 115L,
	dispidPaste = 116L,
	dispidPixel = 152L,
	dispidQBColor = 117L,
	dispidResizeImage = 118L,
	dispidRotateImage = 119L,
	dispidSetFocus = 120L,
	dispidSetPointArray = 121L,
	dispidShow = 122L,
	dispidZOrder = 123L,
	dispidSaveImageToFile = 124L,
	dispidRGB = 125L,
	dispidIntensityRed = 126L,
	dispidIntensityGreen = 127L,
	dispidIntensityBlue = 128L,
	dispidScrollImage = 129L,
	dispidRefreshDesktopWallpaper = 130L,
	dispidSetCapture = 131L,
	dispidReleaseCapture = 132L,
	dispidDrawMouseMoveLinesEx = 133L,
	dispidDrawMouseMoveLines = 134L,
	dispidGetMouseMovePoint = 135L,
	dispidRefreshX = 136L,
	dispidTextWidth = 137L,
	dispidTextHeight = 138L,
	dispidDrawCircle = 139L,
	dispidDrawLine = 140L,
	dispidDrawPoint = 141L,
	dispidDrawPolygon = 142L,
	dispidDrawRoundRect = 143L,
	dispidDrawPolyLines = 144L,
	dispidDrawText = 145L,
	dispidDrawPicture = 146L,
	dispidDrawIcon = 147L,
	dispidStopUrlStream = 148L,
	dispidData = 149L,
	dispidURL = 150L,
	dispidDrawTextInRect = 151L,
	eventidLostFocusX = 1L,
	eventidGotFocusX = 2L,
	eventidHScroll = 3L,
	eventidVScroll = 4L,
	eventidTapAndHold = 5L,
	//}}AFX_DISP_ID
	};
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
	HWND m_hParentWindow;
	HINSTANCE m_hInstMe;
	HINSTANCE m_hResourceFile;
	HINSTANCE m_hPlayingCardsDll;
	HINSTANCE m_hCommCtrl;
	HINSTANCE m_hInstance;
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
	CString m_strName;
	CString m_strPicture;
	CString m_strFontResult;
	CString m_strPlayingCardsDll;
	CString m_strVersionString;
	CString m_strHeaders;
	CString m_strURLAgent;
	COleDateTime m_dteDate;
	COleDateTime m_dteExpire;
	POINT *m_ptPointArray;
	POINT m_ptsMouseMove[MOUSEMOVEPOINTSCOUNTMAX];
	LOGFONT m_LogFont;
	BYTE *m_ByteArray;
	long m_nByteArray;
	CUrlImage *m_pUrlImage;
	CCriticalSection m_cs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309PICTUREBOXCTL_H__D4D7C4C6_2CC5_11D3_AE29_00608CC1DD62__INCLUDED)
