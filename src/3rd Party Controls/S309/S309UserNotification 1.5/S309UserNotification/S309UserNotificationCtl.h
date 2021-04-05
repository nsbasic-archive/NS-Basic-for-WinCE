#if !defined(AFX_S309USERNOTIFICATIONCTL_H__E4A575A7_BD6F_11D2_AE1A_00608CC01367__INCLUDED_)
#define AFX_S309USERNOTIFICATIONCTL_H__E4A575A7_BD6F_11D2_AE1A_00608CC01367__INCLUDED_

#include "S309Alerts.h"	// Added by ClassView
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
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
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
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg float GetVersion();
	afx_msg BSTR GetVersionString();
	afx_msg long MethodSet(long hID);
	afx_msg BOOL MethodClear(long hID);
	afx_msg BOOL MethodGetUserPreferences();
	afx_msg BOOL MethodHandle(LPCTSTR AppName);
	afx_msg BOOL MethodRunAppAtTime();
	afx_msg LPDISPATCH MethodAlerts();
	afx_msg BOOL MethodCancelRunAppAtTime();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CS309UserNotificationCtrl)
	void FireAlertCommand(LPDISPATCH Alert, long Command)
		{FireEvent(eventidAlertCommand,EVENT_PARAM(VTS_DISPATCH  VTS_I4), Alert, Command);}
	void FireAlertDismiss(LPDISPATCH Alert, BOOL Timeout)
		{FireEvent(eventidAlertDismiss,EVENT_PARAM(VTS_DISPATCH  VTS_BOOL), Alert, Timeout);}
	void FireAlertLink(LPDISPATCH Alert, LPCTSTR Link)
		{FireEvent(eventidAlertLink,EVENT_PARAM(VTS_DISPATCH  VTS_BSTR), Alert, Link);}
	void FireAlertShow(LPDISPATCH Alert)
		{FireEvent(eventidAlertShow,EVENT_PARAM(VTS_DISPATCH), Alert);}
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
	dispidTag = 13L,
	dispidVersion = 14L,
	dispidVersionString = 15L,
	dispidSet = 16L,
	dispidClear = 17L,
	dispidGetUserPreferences = 18L,
	dispidHandle = 19L,
	dispidRunAppAtTime = 20L,
	dispidAlerts = 21L,
	dispidCancelRunAppAtTime = 22L,
	eventidAlertCommand = 1L,
	eventidAlertDismiss = 2L,
	eventidAlertLink = 3L,
	eventidAlertShow = 4L,
	//}}AFX_DISP_ID
	};
private:
	HICON m_hIcon;
	CS309Alerts m_Alerts;
	CString m_strVersionString;
	COleVariant m_vTag;
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
