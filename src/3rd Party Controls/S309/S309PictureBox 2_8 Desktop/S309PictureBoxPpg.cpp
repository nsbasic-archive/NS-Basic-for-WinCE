// S309PictureBoxPpg.cpp : Implementation of the CS309PictureBoxPropPage property page class.

#include "stdafx.h"
#include "S309PictureBox.h"
#include "S309PictureBoxPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309PictureBoxPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309PictureBoxPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CS309PictureBoxPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309PictureBoxPropPage, "S309.PictureBoxPropPage.1",
	0xd4d7c4b9, 0x2cc5, 0x11d3, 0xae, 0x29, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62)


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxPropPage::CS309PictureBoxPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309PictureBoxPropPage

BOOL CS309PictureBoxPropPage::CS309PictureBoxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_S309PICTUREBOX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxPropPage::CS309PictureBoxPropPage - Constructor

CS309PictureBoxPropPage::CS309PictureBoxPropPage() :
	COlePropertyPage(IDD, IDS_S309PICTUREBOX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CS309PictureBoxPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxPropPage::DoDataExchange - Moves data between page and properties

void CS309PictureBoxPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CS309PictureBoxPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CS309PictureBoxPropPage message handlers
