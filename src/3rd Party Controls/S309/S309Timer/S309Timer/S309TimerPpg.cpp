// S309TimerPpg.cpp : Implementation of the CS309TimerPropPage property page class.

#include "stdafx.h"
#include "S309Timer.h"
#include "S309TimerPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309TimerPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309TimerPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CS309TimerPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309TimerPropPage, "S309.TimerPropPage.1",
	0xc993da8, 0x484a, 0x11d3, 0xae, 0x2d, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62)


/////////////////////////////////////////////////////////////////////////////
// CS309TimerPropPage::CS309TimerPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309TimerPropPage

BOOL CS309TimerPropPage::CS309TimerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_S309TIMER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerPropPage::CS309TimerPropPage - Constructor

CS309TimerPropPage::CS309TimerPropPage() :
	COlePropertyPage(IDD, IDS_S309TIMER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CS309TimerPropPage)
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerPropPage::DoDataExchange - Moves data between page and properties

void CS309TimerPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CS309TimerPropPage)
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerPropPage message handlers
