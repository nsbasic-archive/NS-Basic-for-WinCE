#if !defined(AFX_S309TIMERCTL_H__0C993DB3_484A_11D3_AE2D_00608CC1DD62__INCLUDED_)
#define AFX_S309TIMERCTL_H__0C993DB3_484A_11D3_AE2D_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifdef UNDER_CE
#if _WIN32_WCE < 202
extern "C" {
void WINAPI SystemIdleTimerReset(void);
}
#endif // _WIN32_WCE < 202
#endif // UNDER_CE

// S309TimerCtl.h : Declaration of the CS309TimerCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl : See S309TimerCtl.cpp for implementation.

class CS309TimerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CS309TimerCtrl)

// Constructor
public:
	CS309TimerCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309TimerCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CS309TimerCtrl();

	DECLARE_OLECREATE_EX(CS309TimerCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CS309TimerCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CS309TimerCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CS309TimerCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CS309TimerCtrl)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CS309TimerCtrl)
	afx_msg BOOL GetEnabled();
	afx_msg void SetEnabled(BOOL bNewValue);
	afx_msg long GetCount();
	afx_msg void SetCount(long nNewValue);
	afx_msg long GetInterval();
	afx_msg void SetInterval(long nNewValue);
	afx_msg short GetVersionMajor();
	afx_msg short GetVersionMinor();
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg long GetVersion();
	afx_msg long GetIdleTimeoutBattery();
	afx_msg long GetIdleTimeoutExternal();
	afx_msg BOOL GetIdleTimeoutResetEnabled();
	afx_msg void SetIdleTimeoutResetEnabled(BOOL bNewValue);
	afx_msg long GetIdleTimeoutInterval();
	afx_msg void SetIdleTimeoutInterval(long nNewValue);
	afx_msg BOOL GetOnBatteryPower();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CS309TimerCtrl)
	void FireTimer()
		{FireEvent(eventidTimer,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CS309TimerCtrl)
	dispidEnabled = 1L,
	dispidCount = 2L,
	dispidInterval = 3L,
	dispidVersionMajor = 4L,
	dispidVersionMinor = 5L,
	dispidTag = 6L,
	dispidVersion = 7L,
	dispidIdleTimeoutBattery = 8L,
	dispidIdleTimeoutExternal = 9L,
	dispidIdleTimeoutReset = 10L,
	dispidIdleTimeoutInterval = 11L,
	dispidOnBatteryPower = 12L,
	eventidTimer = 1L,
	//}}AFX_DISP_ID
	};
private:
	void SetTimerFunction();
	COleVariant m_vTag;
	long m_nCount;
//	BOOL m_bUserMode;
//	BOOL m_bDesignMode;
	long m_nWorkingInterval;
	long m_nWorkingIdleTimeoutInterval;
	UINT m_nTimer;
	UINT m_nIdleTimer;
	BOOL m_bEnabled;
	BOOL m_bIdleTimeoutResetEnabled;
	BOOL m_bOnBatteryPower;
	long m_nInterval;
	long m_nIdleTimeoutInterval;
	HBITMAP m_hBitmap;
	long m_nBatteryTimeout;
	long m_nExternalTimeout;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309TIMERCTL_H__0C993DB3_484A_11D3_AE2D_00608CC1DD62__INCLUDED)
