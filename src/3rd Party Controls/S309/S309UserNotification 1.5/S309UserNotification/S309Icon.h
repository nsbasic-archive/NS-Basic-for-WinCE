#if !defined(AFX_S309ICON_H__0CD24846_5365_4910_9D4C_440D99D5C4CE__INCLUDED_)
#define AFX_S309ICON_H__0CD24846_5365_4910_9D4C_440D99D5C4CE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// S309Icon.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CS309Icon command target

class CS309Icon : public CCmdTarget
{
	DECLARE_DYNCREATE(CS309Icon)

// Attributes
public:


// Operations
public:
	HICON hIcon();
	CS309Icon();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309Icon)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CS309Icon();

	// Generated message map functions
	//{{AFX_MSG(CS309Icon)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CS309Icon)
	afx_msg long GetThis();
	afx_msg long GetHIcon();
	afx_msg void SetHIcon(long nNewValue);
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg BOOL MethodLoad(LPCTSTR Name, const VARIANT FAR& IconID);
	afx_msg void MethodDestroy();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	void Destroy();
	HICON m_hIcon;
	long m_lIconID;
	long CommonOptionalLong(const VARIANT *vLong, long nInit);
	CString m_strName;
	COleVariant m_vTag;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309ICON_H__0CD24846_5365_4910_9D4C_440D99D5C4CE__INCLUDED_)
