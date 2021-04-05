#if !defined(AFX_S309HOTKEYCTL_H__95299E28_49EF_11D3_AE2E_00608CC1DD62__INCLUDED_)
#define AFX_S309HOTKEYCTL_H__95299E28_49EF_11D3_AE2E_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309HotKeyCtl.h : Declaration of the CS309HotKeyCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl : See S309HotKeyCtl.cpp for implementation.

class CS309HotKeyCtrl : public COleControl
{
	DECLARE_DYNCREATE(CS309HotKeyCtrl)

// Constructor
public:
	CS309HotKeyCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309HotKeyCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CS309HotKeyCtrl();

	DECLARE_OLECREATE_EX(CS309HotKeyCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CS309HotKeyCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CS309HotKeyCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CS309HotKeyCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CS309HotKeyCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CS309HotKeyCtrl)
	afx_msg short GetEnumKey();
	afx_msg BOOL GetEnumAlt();
	afx_msg BOOL GetEnumWindows();
	afx_msg BOOL GetEnumShift();
	afx_msg BOOL GetEnumControl();
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg short GetVersionMajor();
	afx_msg short GetVersionMinor();
	afx_msg short GetVersion();
	afx_msg BOOL Register(short nKey, BOOL bAlt, BOOL bControl, BOOL bShift, BOOL bWindows);
	afx_msg BOOL Unregister(short nKey, BOOL bAlt, BOOL bControl, BOOL bShift, BOOL bWindows);
	afx_msg BOOL UnregisterAll();
	afx_msg BOOL EnumFirst();
	afx_msg BOOL EnumNext();
	afx_msg void KeyboardEvent(short VirtualKey, short ScanCode, long dwFlags, long dwExtraInfo);
	afx_msg void MouseEvent(long dwFlags, long dwX, long dwY, long dwData, long dwExtraInfo);
	afx_msg short GetAsyncKeyState(short VirtualKey);
	afx_msg short GetKeyState(short VirtualKey);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CS309HotKeyCtrl)
	void FireHotKeyDown(short nKey, BOOL bAlt, BOOL bControl, BOOL bShift, BOOL bWindows)
		{FireEvent(eventidHotKeyDown,EVENT_PARAM(VTS_I2  VTS_BOOL  VTS_BOOL  VTS_BOOL  VTS_BOOL), nKey, bAlt, bControl, bShift, bWindows);}
	void FireHotKeyUp(short nKey, BOOL bAlt, BOOL bControl, BOOL bShift, BOOL bWindows)
		{FireEvent(eventidHotKeyUp,EVENT_PARAM(VTS_I2  VTS_BOOL  VTS_BOOL  VTS_BOOL  VTS_BOOL), nKey, bAlt, bControl, bShift, bWindows);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CS309HotKeyCtrl)
	dispidEnumKey = 1L,
	dispidEnumAlt = 2L,
	dispidEnumWindows = 3L,
	dispidEnumShift = 4L,
	dispidEnumControl = 5L,
	dispidTag = 6L,
	dispidVersionMajor = 7L,
	dispidVersionMinor = 8L,
	dispidVersion = 9L,
	dispidRegister = 10L,
	dispidUnregister = 11L,
	dispidUnregisterAll = 12L,
	dispidEnumFirst = 13L,
	dispidEnumNext = 14L,
	dispidKeyboardEvent = 15L,
	dispidMouseEvent = 16L,
	dispidGetAsyncKeyState = 17L,
	dispidGetKeyState = 18L,
	eventidHotKeyDown = 1L,
	eventidHotKeyUp = 2L,
	//}}AFX_DISP_ID
	};
private:
	COleVariant m_vTag;
	BOOL m_bEnum;
	BOOL m_bUserMode;
	long m_nEnum;
	BYTE m_cID[4096];
	long m_nIDStart;
	HBITMAP m_hBitmap;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309HOTKEYCTL_H__95299E28_49EF_11D3_AE2E_00608CC1DD62__INCLUDED)
