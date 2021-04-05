#if !defined(AFX_MENUEDITORDLG_H__1D59DF44_E598_11D2_BD76_00A0C9962E16__INCLUDED_)
#define AFX_MENUEDITORDLG_H__1D59DF44_E598_11D2_BD76_00A0C9962E16__INCLUDED_

#include "NSBForm.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MenuEditorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMenuEditorDlg dialog

class CMenuEditorDlg : public CDialog
{
// Construction
public:
   void GetMenu( NSBFormMenu *pMenu, HTREEITEM htItem );
	CNSBForm *m_pForm;
   void SetMenu( NSBFormMenu *pFormMenu, HTREEITEM htParent = NULL );
   CTypedPtrArray<CObArray,CNSBFormSubMenu*> m_aMenu;
	CMenuEditorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMenuEditorDlg)
	enum { IDD = IDD_MENU_EDITOR };
	CTreeCtrl	m_cMenuTree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMenuEditorDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnAddMenuItem();
	afx_msg void OnDeleteMenuItem();
	afx_msg void OnAddSubmenuItem();
	afx_msg void OnEndLabelEditMenuTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBeginLabelEditMenuTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelChangedMenuTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CMenuItemEditorDlg dialog

class CMenuItemEditorDlg : public CDialog
{
// Construction
public:
	void GetItem( CString &strItem );
	void SetItem( CString strItem );
	CMenuItemEditorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMenuItemEditorDlg)
	enum { IDD = IDD_MENU_ITEM_EDITOR };
	CString	m_strAccelerator;
	CString	m_strCaption;
	CString	m_strMenuKey;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuItemEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMenuItemEditorDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUEDITORDLG_H__1D59DF44_E598_11D2_BD76_00A0C9962E16__INCLUDED_)
