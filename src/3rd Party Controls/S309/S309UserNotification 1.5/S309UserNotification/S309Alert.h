#if !defined(AFX_S309ALERT_H__C1437CB3_02F8_40BE_AD6C_CA503177A089__INCLUDED_)
#define AFX_S309ALERT_H__C1437CB3_02F8_40BE_AD6C_CA503177A089__INCLUDED_

#include "S309Icon.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// S309Alert.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CS309Alert window

class CS309Alert : public CWnd
{
// Construction
public:
	CS309Alert();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309Alert)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bShow;
	CWnd *m_pTopParent;
	HICON m_hTopParentIcon;
	CString m_strName;
	CString m_strLink;
	BOOL m_bTimeout;
	long m_lCommand;
	virtual ~CS309Alert();

	// Generated message map functions
protected:
	//{{AFX_MSG(CS309Alert)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CS309Alert)
	afx_msg BSTR GetName();
	afx_msg void SetName(LPCTSTR lpszNewValue);
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg BSTR GetHTML();
	afx_msg void SetHTML(LPCTSTR lpszNewValue);
	afx_msg long GetDuration();
	afx_msg void SetDuration(long nNewValue);
	afx_msg BSTR GetTitle();
	afx_msg void SetTitle(LPCTSTR lpszNewValue);
	afx_msg BOOL GetStraightToTray();
	afx_msg void SetStraightToTray(BOOL bNewValue);
	afx_msg BOOL GetCritical();
	afx_msg void SetCritical(BOOL bNewValue);
	afx_msg BOOL GetForceMessage();
	afx_msg void SetForceMessage(BOOL bNewValue);
	afx_msg BOOL GetShow();
	afx_msg void SetShow(BOOL bNewValue);
	afx_msg LPDISPATCH GetIcon();
	afx_msg void SetIcon(LPDISPATCH newValue);
	afx_msg BOOL MethodAdd();
	afx_msg BOOL MethodRemove();
	afx_msg BOOL MethodUpdate();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	DWORD m_dwUpdateMask;
	BOOL m_bValid;
	CS309Icon *m_pIcon;
	COleVariant m_vTag;
	CString m_strTitle;
	CString m_strHTML;
	CLSID m_clsid;
#ifdef S309_HAVE_ALERTS
	SHNOTIFICATIONDATA m_NotificationData;
#endif // S309_HAVE_ALERTS
};

typedef CTypedPtrArray< CObArray, CS309Alert* > CS309AlertArray;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309ALERT_H__C1437CB3_02F8_40BE_AD6C_CA503177A089__INCLUDED_)
