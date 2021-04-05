#if !defined(AFX_VNSBDLG_H__083D5356_C499_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_VNSBDLG_H__083D5356_C499_11D2_BD63_00A0C9962E16__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// VNSBDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNSBFormNameDlg dialog

class CNSBFormNameDlg : public CDialog
{
// Construction
public:
	CNSBFormNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNSBFormNameDlg)
	enum { IDD = IDD_FORMNAME };
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNSBFormNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNSBFormNameDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VNSBDLG_H__083D5356_C499_11D2_BD63_00A0C9962E16__INCLUDED_)
