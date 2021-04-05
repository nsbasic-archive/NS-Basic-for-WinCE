#if !defined(AFX_S309TIMERPPG_H__0C993DB5_484A_11D3_AE2D_00608CC1DD62__INCLUDED_)
#define AFX_S309TIMERPPG_H__0C993DB5_484A_11D3_AE2D_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309TimerPpg.h : Declaration of the CS309TimerPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CS309TimerPropPage : See S309TimerPpg.cpp.cpp for implementation.

class CS309TimerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CS309TimerPropPage)
	DECLARE_OLECREATE_EX(CS309TimerPropPage)

// Constructor
public:
	CS309TimerPropPage();

// Dialog Data
	//{{AFX_DATA(CS309TimerPropPage)
	enum { IDD = IDD_PROPPAGE_S309TIMER };
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CS309TimerPropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309TIMERPPG_H__0C993DB5_484A_11D3_AE2D_00608CC1DD62__INCLUDED)
