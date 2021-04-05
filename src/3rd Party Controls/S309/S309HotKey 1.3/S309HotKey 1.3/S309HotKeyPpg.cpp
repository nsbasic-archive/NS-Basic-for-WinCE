// S309HotKeyPpg.cpp : Implementation of the CS309HotKeyPropPage property page class.

#include "stdafx.h"
#include "S309HotKey.h"
#include "S309HotKeyPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309HotKeyPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309HotKeyPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CS309HotKeyPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309HotKeyPropPage, "S309.HotKeyPropPage.1",
	0x95299e1c, 0x49ef, 0x11d3, 0xae, 0x2e, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62)


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyPropPage::CS309HotKeyPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309HotKeyPropPage

BOOL CS309HotKeyPropPage::CS309HotKeyPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_S309HOTKEY_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyPropPage::CS309HotKeyPropPage - Constructor

CS309HotKeyPropPage::CS309HotKeyPropPage() :
	COlePropertyPage(IDD, IDS_S309HOTKEY_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CS309HotKeyPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyPropPage::DoDataExchange - Moves data between page and properties

void CS309HotKeyPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CS309HotKeyPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyPropPage message handlers
