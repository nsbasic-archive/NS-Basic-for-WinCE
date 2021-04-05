#if !defined(AFX_NSBFORMOBJECTVIEW_H__BE6760B8_C46C_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_NSBFORMOBJECTVIEW_H__BE6760B8_C46C_11D2_BD63_00A0C9962E16__INCLUDED_

#include "NSBForm.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NSBFormObjectView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNSBFormObjectView window

#define SELECT_INDENT  2
#define SELECT_HANDLE  4

class CNSBFormObjectView : public CWnd
{
   DECLARE_DYNAMIC( CNSBFormObjectView )
// Construction
public:
	CNSBFormObjectView();
	CNSBFormObjectView( CNSBFormObject *pFormOb, CWnd *pParent );

// Attributes
public:

// Operations
public:
   BOOL Create( LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNSBFormObjectView)
	//}}AFX_VIRTUAL

// Implementation
public:
	void ChangeProperty( CString &strKey, CString strVal );
	CNSBFormObject* GetFormObject();
	void DoResize( int cx, int cy, int nDragHandle, int nGrid );
	void DoMove( int cx, int cy, int nGrid );
	void DoDrag( CPoint ptDelta, int nGrid, int nDragHandle = 0 );
	CNSBFormObject *m_pFormOb;
	void AdjustClickPoint( int nDragHandle, CRect &newBounds );
	void SetDragHandle();
	INT m_nDragHandle;
	static LPCTSTR m_lpszClassName;
	BOOL m_bRectChanged;
	void Select( BOOL bSelect );
	CPoint m_ptClick;
	BOOL m_bSelected;
	virtual ~CNSBFormObjectView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNSBFormObjectView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

typedef CTypedPtrArray<CObArray,CNSBFormObjectView*> CNSBFormObViewArray;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NSBFORMOBJECTVIEW_H__BE6760B8_C46C_11D2_BD63_00A0C9962E16__INCLUDED_)
