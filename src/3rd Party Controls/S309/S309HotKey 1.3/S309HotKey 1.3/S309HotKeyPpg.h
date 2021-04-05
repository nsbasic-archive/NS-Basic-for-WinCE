#if !defined(AFX_S309HOTKEYPPG_H__95299E2A_49EF_11D3_AE2E_00608CC1DD62__INCLUDED_)
#define AFX_S309HOTKEYPPG_H__95299E2A_49EF_11D3_AE2E_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309HotKeyPpg.h : Declaration of the CS309HotKeyPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CS309HotKeyPropPage : See S309HotKeyPpg.cpp.cpp for implementation.

class CS309HotKeyPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CS309HotKeyPropPage)
	DECLARE_OLECREATE_EX(CS309HotKeyPropPage)

// Constructor
public:
	CS309HotKeyPropPage();

// Dialog Data
	//{{AFX_DATA(CS309HotKeyPropPage)
	enum { IDD = IDD_PROPPAGE_S309HOTKEY };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CS309HotKeyPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309HOTKEYPPG_H__95299E2A_49EF_11D3_AE2E_00608CC1DD62__INCLUDED)
