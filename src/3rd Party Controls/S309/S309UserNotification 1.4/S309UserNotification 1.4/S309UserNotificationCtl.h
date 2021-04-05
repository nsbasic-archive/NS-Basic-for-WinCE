#if !defined(AFX_S309USERNOTIFICATIONCTL_H__E4A575A7_BD6F_11D2_AE1A_00608CC01367__INCLUDED_)
#define AFX_S309USERNOTIFICATIONCTL_H__E4A575A7_BD6F_11D2_AE1A_00608CC01367__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309UserNotificationCtl.h : Declaration of the CS309UserNotificationCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl : See S309UserNotificationCtl.cpp for implementation.

class CS309UserNotificationCtrl : public COleControl
{
	DECLARE_DYNCREATE(CS309UserNotificationCtrl)

// Constructor
public:
	CS309UserNotificationCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309UserNotificationCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CS309UserNotificationCtrl();

	DECLARE_OLECREATE_EX(CS309UserNotificationCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CS309UserNotificationCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CS309UserNotificationCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CS309UserNotificationCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CS309UserNotificationCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CS309UserNotificationCtrl)
	afx_msg BOOL GetLED();
	afx_msg void SetLED(BOOL bNewValue);
	afx_msg BOOL GetVibrate();
	afx_msg void SetVibrate(BOOL bNewValue);
	afx_msg BOOL GetDialog();
	afx_msg void SetDialog(BOOL bNewValue);
	afx_msg BOOL GetSound();
	afx_msg void SetSound(BOOL bNewValue);
	afx_msg BOOL GetRepeat();
	afx_msg void SetRepeat(BOOL bNewValue);
	afx_msg BSTR GetDialogTitle();
	afx_msg void SetDialogTitle(LPCTSTR lpszNewValue);
	afx_msg BSTR GetDialogText();
	afx_msg void SetDialogText(LPCTSTR lpszNewValue);
	afx_msg BSTR GetSoundFile();
	afx_msg void SetSoundFile(LPCTSTR lpszNewValue);
	afx_msg VARIANT GetDateTime();
	afx_msg void SetDateTime(const VARIANT FAR& newValue);
	afx_msg BSTR GetAppName();
	afx_msg void SetAppName(LPCTSTR lpszNewValue);
	afx_msg long GetLeft();
	afx_msg void SetLeft(long nNewValue);
	afx_msg long GetTop();
	afx_msg void SetTop(long nNewValue);
	afx_msg short GetVersionMajor();
	afx_msg short GetVersionMinor();
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg long GetVersion();
	afx_msg long Set(long hID);
	afx_msg BOOL Clear(long hID);
	afx_msg BOOL GetUserPreferences();
	afx_msg BOOL Handle(LPCTSTR AppName);
	afx_msg BOOL RunAppAtTime();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CS309UserNotificationCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CS309UserNotificationCtrl)
	dispidLED = 1L,
	dispidVibrate = 2L,
	dispidDialog = 3L,
	dispidSound = 4L,
	dispidRepeat = 5L,
	dispidDialogTitle = 6L,
	dispidDialogText = 7L,
	dispidSoundFile = 8L,
	dispidDateTime = 9L,
	dispidAppName = 10L,
	dispidLeft = 11L,
	dispidTop = 12L,
	dispidVersionMajor = 13L,
	dispidVersionMinor = 14L,
	dispidTag = 15L,
	dispidVersion = 16L,
	dispidSet = 17L,
	dispidClear = 18L,
	dispidGetUserPreferences = 19L,
	dispidHandle = 20L,
	dispidRunAppAtTime = 21L,
	//}}AFX_DISP_ID
	};
private:
	COleVariant m_vTag;
//	BOOL m_bUserMode;
//	BOOL m_bDesignMode;
	BOOL m_bVibrate;
	CString m_sSoundFile;
	BOOL m_bSound;
	BOOL m_bRepeat;
	BOOL m_bLED;
	CString m_sDialogTitle;
	CString m_sDialogText;
	BOOL m_bDialog;
	COleVariant m_vDateTime;
	CString m_sAppName;
	HBITMAP m_hBitmap;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309USERNOTIFICATIONCTL_H__E4A575A7_BD6F_11D2_AE1A_00608CC01367__INCLUDED)
