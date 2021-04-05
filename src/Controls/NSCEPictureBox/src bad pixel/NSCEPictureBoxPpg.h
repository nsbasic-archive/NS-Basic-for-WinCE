#if !defined(AFX_NSCEPICTUREBOXPPG_H__C3E832F2_9659_49C9_A4A9_687BC23F9ACB__INCLUDED_)
#define AFX_NSCEPICTUREBOXPPG_H__C3E832F2_9659_49C9_A4A9_687BC23F9ACB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// NSCEPictureBoxPpg.h : Declaration of the CNSCEPictureBoxPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxPropPage : See NSCEPictureBoxPpg.cpp.cpp for implementation.

class CNSCEPictureBoxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CNSCEPictureBoxPropPage)
	DECLARE_OLECREATE_EX(CNSCEPictureBoxPropPage)

// Constructor
public:
	CNSCEPictureBoxPropPage();

// Dialog Data
	//{{AFX_DATA(CNSCEPictureBoxPropPage)
	enum { IDD = IDD_PROPPAGE_NSCEPICTUREBOX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CNSCEPictureBoxPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NSCEPICTUREBOXPPG_H__C3E832F2_9659_49C9_A4A9_687BC23F9ACB__INCLUDED)
