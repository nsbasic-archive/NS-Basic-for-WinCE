#if !defined(AFX_COMOBJECTDLG_H__8B5CDF74_66DE_11D3_8ABB_00A0C9962E16__INCLUDED_)
#define AFX_COMOBJECTDLG_H__8B5CDF74_66DE_11D3_8ABB_00A0C9962E16__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ComObjectDlg.h : header file
//

class CComObDesc : public CObject  
{
public:
	WORD GetTypeDesc( TYPEDESC *pTypeDesc, int nIndirection = 0 );
	void GetProperties();
   CMap<CString, LPCTSTR, WORD, WORD> m_mapProperties;
	CString m_strName;
	CComObDesc( LPCTSTR strCLSID, LPCTSTR strProgID = NULL );
	CString m_strProgID;
	CString m_strCLSID;
	CComObDesc();
	virtual ~CComObDesc();
};

/////////////////////////////////////////////////////////////////////////////
// CComObjectDlg dialog

class CComObjectDlg : public CDialog
{
// Construction
public:
	CComObDesc *m_pComObDesc;
	void OnOK();
   CTypedPtrMap<CMapStringToOb, CString, CComObDesc*> *m_pMapComObDescs;
	CComObjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CComObjectDlg)
	enum { IDD = IDD_COMOBJECTS };
	CListBox	m_cObList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComObjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComObjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblClkObjects();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMOBJECTDLG_H__8B5CDF74_66DE_11D3_8ABB_00A0C9962E16__INCLUDED_)
