// VNSBDoc.h : interface of the CVNSBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VNSBDOC_H__33B0A29C_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_VNSBDOC_H__33B0A29C_C462_11D2_BD63_00A0C9962E16__INCLUDED_

#include "NSBForm.h"	// Added by ClassView
#include "NSBFormObjectView.h"
#include "ComObjectDlg.h"
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define ID_FIRST_FORM 440

#define HINT_OBJECT_DEL    0
#define HINT_OBJECT_ADD    1
#define HINT_OBJECT_PASTE  2
#define HINT_SWITCH_FORM   3

typedef CTypedPtrMap<CMapStringToOb,CString,CNSBForm*> CNSBFormMap;

class CVNSBDoc : public CDocument
{
protected: // create from serialization only
	CVNSBDoc();
	DECLARE_DYNCREATE(CVNSBDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVNSBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	INT m_nGrid;
	CComObDesc *GetComObDesc( LPCTSTR lpszProgID );
	CMapStringToString m_mapComObNames;
	void GetComServers();
   CTypedPtrMap<CMapStringToOb, CString, CComObDesc*> m_mapComObDescs;
	BOOL UniqueObjectName( CString &strObjectName );
	void DoFormExit();
	void AddForm( CString strName );
	CString m_strDefaultForm;
	CString m_strCode;
	void doWriteEncryptedBytesV2( CArchive &ar, const TCHAR *szBuf, UINT nLen, DWORD dwFileFlag );
	void doDecryptV2( TCHAR *szBuf, UINT nLen, DWORD dwFileFlag );
	BOOL ParseCode( LPCTSTR lpszText );
	DWORD doCalculateChecksum( TCHAR *szBuf, DWORD dwSeed );
	void WriteToArchive( CArchive &ar );
	void ReadFromArchive( CArchive &ar, UINT nLen );
	CStringArray m_aForms;
	void DoUpdateFormSwitch( int nIndex, CCmdUI *pCmdUI );
	void DoFormSwitch( int nIndex, UINT nID );
	void SetFormMenu();
	CNSBForm *m_pForm;
	CNSBFormMap m_mapForms;
	void DoUpdateToolsAddObject( CCmdUI *pCmdUI );
	void DoToolsAddObject( int nIndex, UINT nID );
	static NSBObject AddObjectList[NUM_NSBOBJECTS];
	virtual ~CVNSBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	BOOL GenerateCode( CString &strCode );
	//{{AFX_MSG(CVNSBDoc)
	afx_msg void OnFormMenu();
	afx_msg void OnUpdateFormMenu(CCmdUI* pCmdUI);
	afx_msg void OnFormAdd();
	afx_msg void OnUpdateFormAdd(CCmdUI* pCmdUI);
	afx_msg void OnFormDelete();
	afx_msg void OnUpdateFormDelete(CCmdUI* pCmdUI);
	afx_msg void OnFormSetdefault();
	afx_msg void OnUpdateFormSetdefault(CCmdUI* pCmdUI);
	afx_msg void OnFormExit();
	afx_msg void OnUpdateFormExit(CCmdUI* pCmdUI);
	afx_msg void OnUpdateObjectsShowCode(CCmdUI* pCmdUI);
	afx_msg void OnObjectsShowCode();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VNSBDOC_H__33B0A29C_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
