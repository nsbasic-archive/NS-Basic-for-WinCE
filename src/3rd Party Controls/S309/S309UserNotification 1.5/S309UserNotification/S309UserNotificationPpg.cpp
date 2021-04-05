// S309UserNotificationPpg.cpp : Implementation of the CS309UserNotificationPropPage property page class.

#include "stdafx.h"
#include "S309UserNotification.h"
#include "S309UserNotificationPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309UserNotificationPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309UserNotificationPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CS309UserNotificationPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309UserNotificationPropPage, "S309.UserNotificationPropPage.1",
	0xe4a5759a, 0xbd6f, 0x11d2, 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67)


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationPropPage::CS309UserNotificationPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309UserNotificationPropPage

BOOL CS309UserNotificationPropPage::CS309UserNotificationPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_S309USERNOTIFICATION_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationPropPage::CS309UserNotificationPropPage - Constructor

CS309UserNotificationPropPage::CS309UserNotificationPropPage() :
	COlePropertyPage(IDD, IDS_S309USERNOTIFICATION_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CS309UserNotificationPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationPropPage::DoDataExchange - Moves data between page and properties

void CS309UserNotificationPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CS309UserNotificationPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationPropPage message handlers
