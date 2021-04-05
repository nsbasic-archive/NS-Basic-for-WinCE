#if !defined(AFX_S309USERNOTIFICATIONPPG_H__E4A575A9_BD6F_11D2_AE1A_00608CC01367__INCLUDED_)
#define AFX_S309USERNOTIFICATIONPPG_H__E4A575A9_BD6F_11D2_AE1A_00608CC01367__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309UserNotificationPpg.h : Declaration of the CS309UserNotificationPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationPropPage : See S309UserNotificationPpg.cpp.cpp for implementation.

class CS309UserNotificationPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CS309UserNotificationPropPage)
	DECLARE_OLECREATE_EX(CS309UserNotificationPropPage)

// Constructor
public:
	CS309UserNotificationPropPage();

// Dialog Data
	//{{AFX_DATA(CS309UserNotificationPropPage)
	enum { IDD = IDD_PROPPAGE_S309USERNOTIFICATION };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CS309UserNotificationPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309USERNOTIFICATIONPPG_H__E4A575A9_BD6F_11D2_AE1A_00608CC01367__INCLUDED)
