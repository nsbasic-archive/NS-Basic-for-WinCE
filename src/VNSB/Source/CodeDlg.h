#if !defined(AFX_CODEDLG_H__BBA44492_0E43_11D3_BD7F_00A0C9962E16__INCLUDED_)
#define AFX_CODEDLG_H__BBA44492_0E43_11D3_BD7F_00A0C9962E16__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CodeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCodeDlg dialog

class CCodeDlg : public CDialog
{
// Construction
public:
	CCodeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCodeDlg)
	enum { IDD = IDD_SHOW_CODE };
	CString	m_strCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCodeDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CPrefsDlg dialog

class CPrefsDlg : public CDialog
{
// Construction
public:
	CPrefsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrefsDlg)
	enum { IDD = IDD_PREFS };
	int		m_nGrid;
	BOOL	m_bGridSnap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrefsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrefsDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CODEDLG_H__BBA44492_0E43_11D3_BD7F_00A0C9962E16__INCLUDED_)
