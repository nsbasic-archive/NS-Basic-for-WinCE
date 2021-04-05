#if !defined(AFX_SELECTOBJECTDLG_H__1EC11595_DB55_11D2_BD72_00A0C9962E16__INCLUDED_)
#define AFX_SELECTOBJECTDLG_H__1EC11595_DB55_11D2_BD72_00A0C9962E16__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SelectObjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectObjectDlg dialog

class CSelectObjectDlg : public CDialog
{
// Construction
public:
	CStringArray m_aObjectNames;
	CSelectObjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectObjectDlg)
	enum { IDD = IDD_SELECT_OBJECT };
	CListBox	m_cObjectList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectObjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectObjectDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDblClkObjectList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTOBJECTDLG_H__1EC11595_DB55_11D2_BD72_00A0C9962E16__INCLUDED_)
