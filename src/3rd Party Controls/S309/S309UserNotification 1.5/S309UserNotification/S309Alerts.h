#if !defined(AFX_S309ALERTS_H__F5E4F517_5B04_4DDE_8288_956C99B7DC73__INCLUDED_)
#define AFX_S309ALERTS_H__F5E4F517_5B04_4DDE_8288_956C99B7DC73__INCLUDED_

#include "S309Alert.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// S309Alerts.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CS309Alerts window

class CS309Alerts : public CWnd
{
// Construction
public:
	CS309Alerts();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CS309Alerts)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	CWnd *m_pTopParent;
	HICON m_hTopParentIcon;
	CS309AlertArray m_AlertArray;
	virtual ~CS309Alerts();

	// Generated message map functions
protected:
	//{{AFX_MSG(CS309Alerts)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CS309Alerts)
	afx_msg long GetCount();
	afx_msg VARIANT GetTag();
	afx_msg void SetTag(const VARIANT FAR& newValue);
	afx_msg BOOL MethodRemove(const VARIANT FAR& ID);
	afx_msg LPDISPATCH MethodAdd(LPCTSTR Name);
	afx_msg LPDISPATCH GetItem(const VARIANT FAR& ID);
	//}}AFX_DISPATCH
	afx_msg LPUNKNOWN _NewEnum();
	DECLARE_DISPATCH_MAP()

	BEGIN_INTERFACE_PART(EnumVARIANT, IEnumVARIANT)
		STDMETHOD(Next)(THIS_ ULONG celt, VARIANT FAR* rgvar, ULONG FAR* pceltFetched);
		STDMETHOD(Skip)(THIS_ ULONG celt) ;
		STDMETHOD(Reset)(THIS) ;
		STDMETHOD(Clone)(THIS_ IEnumVARIANT FAR* FAR* ppenum) ;
		XEnumVARIANT() ;        // constructor to set m_posCurrent
		~XEnumVARIANT() ;       
		long m_lCurrentPosition; // Next() requires we keep track of our current item
	END_INTERFACE_PART(EnumVARIANT)    
  
	DECLARE_INTERFACE_MAP()
private:
//	long FindDispatch(LPDISPATCH pObject);
	COleVariant m_vTag;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309ALERTS_H__F5E4F517_5B04_4DDE_8288_956C99B7DC73__INCLUDED_)
