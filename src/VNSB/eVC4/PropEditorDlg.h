#if !defined(AFX_PROPEDITORDLG_H__7AB1F594_CEF2_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_PROPEDITORDLG_H__7AB1F594_CEF2_11D2_BD63_00A0C9962E16__INCLUDED_

#include "ComObjectDlg.h"	// Added by ClassView
#include "NSBForm.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropEditorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropEditorDlg dialog

class CPropEditorDlg : public CDialog
{
// Construction
public:
   CComObDesc *m_pComObDesc;
	static int CALLBACK EnumFontFamProc( const LOGFONT *lplf, const TEXTMETRIC *lpntm, unsigned long FontType, LPARAM lParam );
	CString m_strObjectName;
	CString FilterProperty( CString &strProperty );
	CWnd *m_pView;
	BOOL m_bPropertyDirty;
	CString m_strProperty;
	CNSBFormObject *m_pFormOb;
	static NSBProperty NSBPropertyList[NUM_NSBPROPERTIES];
	int m_nVisibleEditor;
	CPropEditorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPropEditorDlg)
	enum { IDD = IDD_PROPERTY_EDITOR };
	CEdit	m_cObjectName;
	CComboBox	m_cEditList;
	CButton	m_cChoose;
	CEdit	m_cEditMulti;
	CEdit	m_cNumber;
	CComboBox	m_cProperties;
	CEdit	m_cEditSingle;
	CComboBox	m_cList;
	//}}AFX_DATA
#if _WIN32_WCE >= 211
   CDateTimeCtrl m_cDate;
	CDateTimeCtrl m_cTime;
#endif

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual void OnOK();
	// Generated message map functions
	//{{AFX_MSG(CPropEditorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeProperties();
	afx_msg void OnChangeProperty();
	afx_msg void OnApply();
	afx_msg void OnClose();
	afx_msg void OnChoose();
	afx_msg void OnChangeObjectName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPEDITORDLG_H__7AB1F594_CEF2_11D2_BD63_00A0C9962E16__INCLUDED_)
