// VNSBView.h : interface of the CVNSBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VNSBVIEW_H__33B0A29E_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_VNSBVIEW_H__33B0A29E_C462_11D2_BD63_00A0C9962E16__INCLUDED_

#include "NSBFormObjectView.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CVNSBView : public CView
{
protected: // create from serialization only
	CVNSBView();
	DECLARE_DYNCREATE(CVNSBView)

// Attributes
public:
	CVNSBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVNSBView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	INT m_nGrid;
	void ChangeProperty( CString &strKey, CString strVal );
	CNSBFormObject* GetFormObject();
	CWnd* GetSelectionView();
	void SelectionMove( int cx, int cy );
	void AddViewObjects( BOOL bDestroy = FALSE );
	void SelectionFormObjects( CNSBFormObjectArray& arrFormObs );
	void SelectionEditProperties();
	void SelectionChangeRect();
	void FormObjectDrag( CPoint ptDelta, int nDragHandle );
	void Select( CString &strObjectName, BOOL bADD = FALSE );
	void Select( CNSBFormObjectView *pViewOb = NULL, BOOL bAdd = FALSE );
	void AddViewObject( CNSBFormObject *pFormOb );
	CNSBFormObViewArray m_aViewObjects;
	CNSBFormObViewArray m_aSelection;
	CNSBFormObjectArray m_aClipboard;
	virtual ~CVNSBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVNSBView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEditProperties();
	afx_msg void OnUpdateEditProperties(CCmdUI* pCmdUI);
	afx_msg void OnEditSelectObject();
	afx_msg void OnUpdateEditSelectObject(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEditPrefs();
	afx_msg void OnUpdateEditPrefs(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VNSBView.cpp
inline CVNSBDoc* CVNSBView::GetDocument()
   { return (CVNSBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VNSBVIEW_H__33B0A29E_C462_11D2_BD63_00A0C9962E16__INCLUDED_)
