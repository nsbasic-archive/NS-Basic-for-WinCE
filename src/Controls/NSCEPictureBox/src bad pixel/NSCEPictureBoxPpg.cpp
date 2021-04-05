// NSCEPictureBoxPpg.cpp : Implementation of the CNSCEPictureBoxPropPage property page class.

#include "stdafx.h"
#include "NSCEPictureBox.h"
#include "NSCEPictureBoxPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CNSCEPictureBoxPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CNSCEPictureBoxPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CNSCEPictureBoxPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CNSCEPictureBoxPropPage, "NSCEPICTUREBOX.NSCEPictureBoxPropPage.1",
	0x29c8619c, 0xa974, 0x4caa, 0x9a, 0x11, 0xef, 0xff, 0x69, 0x5e, 0x15, 0x86)


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxPropPage::CNSCEPictureBoxPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CNSCEPictureBoxPropPage

BOOL CNSCEPictureBoxPropPage::CNSCEPictureBoxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_NSCEPICTUREBOX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxPropPage::CNSCEPictureBoxPropPage - Constructor

CNSCEPictureBoxPropPage::CNSCEPictureBoxPropPage() :
	COlePropertyPage(IDD, IDS_NSCEPICTUREBOX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CNSCEPictureBoxPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxPropPage::DoDataExchange - Moves data between page and properties

void CNSCEPictureBoxPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CNSCEPictureBoxPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxPropPage message handlers
