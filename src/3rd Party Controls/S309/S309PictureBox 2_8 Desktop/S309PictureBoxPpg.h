#if !defined(AFX_S309PICTUREBOXPPG_H__D4D7C4C8_2CC5_11D3_AE29_00608CC1DD62__INCLUDED_)
#define AFX_S309PICTUREBOXPPG_H__D4D7C4C8_2CC5_11D3_AE29_00608CC1DD62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// S309PictureBoxPpg.h : Declaration of the CS309PictureBoxPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxPropPage : See S309PictureBoxPpg.cpp.cpp for implementation.

class CS309PictureBoxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CS309PictureBoxPropPage)
	DECLARE_OLECREATE_EX(CS309PictureBoxPropPage)

// Constructor
public:
	CS309PictureBoxPropPage();

// Dialog Data
	//{{AFX_DATA(CS309PictureBoxPropPage)
	enum { IDD = IDD_PROPPAGE_S309PICTUREBOX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CS309PictureBoxPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S309PICTUREBOXPPG_H__D4D7C4C8_2CC5_11D3_AE29_00608CC1DD62__INCLUDED)
