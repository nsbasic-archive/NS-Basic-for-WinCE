// EVCDemoDlg.h : header file
//
//{{AFX_INCLUDES()
#include "grid.h"
//}}AFX_INCLUDES

#if !defined(AFX_EVCDEMODLG_H__FBECC04F_0DB7_460D_B086_911157BFDF0D__INCLUDED_)
#define AFX_EVCDEMODLG_H__FBECC04F_0DB7_460D_B086_911157BFDF0D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CEVCDemoDlg dialog

class CEVCDemoDlg : public CDialog
{
// Construction
public:
	CEVCDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEVCDemoDlg)
	enum { IDD = IDD_EVCDEMO_DIALOG };
	CEdit	m_ValueEdit;
	CGrid	m_Grid;
	CString	m_Value;
	BOOL	m_WordWrap;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEVCDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEVCDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnWordwrap();
	afx_msg void OnAdd();
	afx_msg void OnRemove();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EVCDEMODLG_H__FBECC04F_0DB7_460D_B086_911157BFDF0D__INCLUDED_)
