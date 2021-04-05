// S309TimerCtl.cpp : Implementation of the CS309TimerCtrl ActiveX Control class.

#include "stdafx.h"
#include "S309Timer.h"
#include "S309TimerCtl.h"
#include "S309TimerPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309TimerCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309TimerCtrl, COleControl)
	//{{AFX_MSG_MAP(CS309TimerCtrl)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CS309TimerCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CS309TimerCtrl)
	DISP_PROPERTY_EX(CS309TimerCtrl, "Enabled", GetEnabled, SetEnabled, VT_BOOL)
	DISP_PROPERTY_EX(CS309TimerCtrl, "Count", GetCount, SetCount, VT_I4)
	DISP_PROPERTY_EX(CS309TimerCtrl, "Interval", GetInterval, SetInterval, VT_I4)
	DISP_PROPERTY_EX(CS309TimerCtrl, "VersionMajor", GetVersionMajor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309TimerCtrl, "VersionMinor", GetVersionMinor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309TimerCtrl, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CS309TimerCtrl, "Version", GetVersion, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309TimerCtrl, "IdleTimeoutBattery", GetIdleTimeoutBattery, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309TimerCtrl, "IdleTimeoutExternal", GetIdleTimeoutExternal, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309TimerCtrl, "IdleTimeoutResetEnabled", GetIdleTimeoutResetEnabled, SetIdleTimeoutResetEnabled, VT_BOOL)
	DISP_PROPERTY_EX(CS309TimerCtrl, "IdleTimeoutInterval", GetIdleTimeoutInterval, SetIdleTimeoutInterval, VT_I4)
	DISP_PROPERTY_EX(CS309TimerCtrl, "OnBatteryPower", GetOnBatteryPower, SetNotSupported, VT_BOOL)
	DISP_DEFVALUE(CS309TimerCtrl, "Interval")
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CS309TimerCtrl, COleControl)
	//{{AFX_EVENT_MAP(CS309TimerCtrl)
	EVENT_CUSTOM("Timer", FireTimer, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

BEGIN_PROPPAGEIDS(CS309TimerCtrl, 1)
	PROPPAGEID(CS309TimerPropPage::guid)
END_PROPPAGEIDS(CS309TimerCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309TimerCtrl, "S309.Timer.1",
	0xc8f5328, 0xbc6a, 0x11d2, 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CS309TimerCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DS309Timer =
		{ 0xc993da6, 0x484a, 0x11d3, { 0xae, 0x2d, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };
const IID BASED_CODE IID_DS309TimerEvents =
		{ 0xc993da7, 0x484a, 0x11d3, { 0xae, 0x2d, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwS309TimerOleMisc =
#ifdef UNDER_CE
	OLEMISC_INVISIBLEATRUNTIME |
#endif // UNDER_CE
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_ALWAYSRUN |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CS309TimerCtrl, IDS_S309TIMER, _dwS309TimerOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl::CS309TimerCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309TimerCtrl

BOOL CS309TimerCtrl::CS309TimerCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_S309TIMER,
			IDB_S309TIMER,
			0, //			afxRegApartmentThreading,
			_dwS309TimerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
	
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl::CS309TimerCtrl - Constructor

CS309TimerCtrl::CS309TimerCtrl()
{
	InitializeIIDs(&IID_DS309Timer, &IID_DS309TimerEvents);

	m_nInterval = 0;
	m_nIdleTimeoutInterval = 0;
	m_nWorkingInterval = 0;
	m_nWorkingIdleTimeoutInterval = 0;
	m_bEnabled = false;
	m_nTimer = 0;
	m_nIdleTimer = 0;
	m_nCount = -1;
    m_bIdleTimeoutResetEnabled = false;

#ifdef UNDER_CE
	DWORD dwBatteryTimeout = 0;
	DWORD dwExternalTimeout = 0;
	SystemParametersInfo(SPI_GETBATTERYIDLETIMEOUT, 0, &dwBatteryTimeout, 0);
	SystemParametersInfo(SPI_GETEXTERNALIDLETIMEOUT, 0, &dwExternalTimeout, 0);

	m_nBatteryTimeout = (long)(dwBatteryTimeout * 1000);
	m_nExternalTimeout = (long)(dwExternalTimeout * 1000);

	if (m_nBatteryTimeout > 0)
	{
		m_nIdleTimeoutInterval = m_nBatteryTimeout;
	}
	if (m_nExternalTimeout > 0)
	{
		if (m_nIdleTimeoutInterval == 0)
		{	
			m_nIdleTimeoutInterval = m_nExternalTimeout;
		}
		else
		{
			if (m_nExternalTimeout < m_nIdleTimeoutInterval)
			{
				m_nIdleTimeoutInterval = m_nExternalTimeout;
			}
		}
	}
	if (m_nIdleTimeoutInterval > 0)
	{
		m_nIdleTimeoutInterval = m_nIdleTimeoutInterval / 2;
		if (m_nIdleTimeoutInterval > 65535)
		{
			m_nIdleTimeoutInterval = 65535;
		}
	}
	m_bOnBatteryPower = true;
#else // UNDER_CE
	m_hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(1), IMAGE_BITMAP, 0, 0, 0);
	m_bOnBatteryPower = false;
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl::~CS309TimerCtrl - Destructor

CS309TimerCtrl::~CS309TimerCtrl()
{
	if (m_nTimer != 0)
	{
		KillTimer(m_nTimer);
	}
	if (m_nIdleTimer != 0)
	{
		KillTimer(m_nIdleTimer);
	}
#ifndef UNDER_CE
	::DeleteObject(m_hBitmap);
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl::OnDraw - Drawing function

void CS309TimerCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	CRect cRect;


	if (AmbientUserMode())
	{
		if (GetRectInContainer(cRect) != 0) 
		{
			if ((cRect.top != cRect.bottom) || (cRect.left != cRect.right))
			{
				cRect.bottom = cRect.top;
				cRect.right = cRect.left;
				SetRectInContainer(cRect);
			}
		}
	}
	else
	{
		cRect.left = rcBounds.left;
		cRect.top = rcBounds.top;
		cRect.right = rcBounds.right;
		cRect.bottom = rcBounds.bottom;
		pdc->DrawEdge(cRect, EDGE_RAISED, BF_RECT | BF_ADJUST | BF_SOFT);

		if (m_hBitmap != NULL)
		{
			HDC dcNew;
			HBITMAP hBitmap;
			BITMAP Bitmap;

			::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);

			dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
			hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

			::StretchBlt(pdc->GetSafeHdc(), cRect.left, cRect.top, cRect.Width(), cRect.Height(), dcNew, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

			::SelectObject(dcNew, hBitmap);
			::DeleteDC(dcNew);
		}
		else
		{
			pdc->FillRect(cRect, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
			pdc->Ellipse(cRect);
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl::DoPropExchange - Persistence support

void CS309TimerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	PX_Long(pPX, _T("Count"), m_nCount, m_nCount);
	PX_Long(pPX, _T("Interval"), m_nInterval, m_nInterval);
	PX_Long(pPX, _T("IdleTimeoutInterval"), m_nIdleTimeoutInterval, m_nIdleTimeoutInterval);
	PX_Bool(pPX, _T("Enabled"), m_bEnabled, m_bEnabled);
	PX_Bool(pPX, _T("IdleTimeoutResetEnabled"), m_bIdleTimeoutResetEnabled, m_bIdleTimeoutResetEnabled);

	if (pPX->IsLoading() & AmbientUserMode())
	{
//		MessageBox(TEXT("is loading"),TEXT(""),0);
		SetTimerFunction();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl::OnResetState - Reset control to default state

void CS309TimerCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CS309TimerCtrl message handlers

void CS309TimerCtrl::OnTimer(UINT nIDEvent) 
{

	COleControl::OnTimer(nIDEvent);

#ifdef UNDER_CE
	if (nIDEvent == m_nIdleTimer)
	{
		::SystemIdleTimerReset();
		SetTimerFunction();
	}
#endif // UNDER_CE

	if (nIDEvent == m_nTimer)
	{
		if (m_nCount > 0)
		{
			m_nCount--;
		}
		
		FireTimer();
		
		SetTimerFunction();
	}
}

BOOL CS309TimerCtrl::GetEnabled() 
{
	return m_bEnabled;
}

void CS309TimerCtrl::SetEnabled(BOOL bNewValue) 
{
	if (m_bEnabled != bNewValue)
	{
		m_bEnabled = bNewValue;
		SetModifiedFlag();
		SetTimerFunction();
	}
}

long CS309TimerCtrl::GetCount() 
{
	return m_nCount;
}

void CS309TimerCtrl::SetCount(long nNewValue) 
{
	if (nNewValue < -1) 
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("Value out of range."), 0);
	}
	else
	{
		if (m_nCount != nNewValue)
		{
			m_nCount = nNewValue;
			SetTimerFunction();
			SetModifiedFlag();
		}
	}
}

long CS309TimerCtrl::GetInterval() 
{
	return m_nInterval;
}

void CS309TimerCtrl::SetInterval(long nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 65535))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("Value out of range."), 0);
	}
	else
	{
		if (m_nInterval != nNewValue)
		{
			m_nInterval = nNewValue;
			SetTimerFunction();
			SetModifiedFlag();
		}
	}
}

short CS309TimerCtrl::GetVersionMajor() 
{
	return _wVerMajor;
}

short CS309TimerCtrl::GetVersionMinor() 
{
	return _wVerMinor;
}

VARIANT CS309TimerCtrl::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309TimerCtrl::SetTag(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);
	m_vTag.Clear();
	m_vTag.Attach(Var);
	SetModifiedFlag();
}

void CS309TimerCtrl::SetTimerFunction()
{
	if (AmbientUserMode())
	{
		if ((m_nInterval != m_nWorkingInterval) || (m_nCount == 0))
		{
			if (m_nTimer != 0)
			{
				KillTimer(m_nTimer);
				m_nTimer = 0;
			}
		}

		if ((m_bEnabled) && (m_nInterval > 0) && (m_nCount != 0))
		{
			if (m_nTimer == 0)
			{
				m_nTimer = SetTimer(2, m_nInterval, NULL);
				if (m_nTimer == 0)
				{
//					MessageBox(_T("SetTimer Error"),_T("TimerCtrl"),MB_OK);
				}
				else
				{
//					MessageBox(_T("SetTimer Okay"),_T("TimerCtrl"),MB_OK);
				}
				m_nWorkingInterval = m_nInterval;
			}
		}
		else
		{
			if (m_nTimer != 0)
			{
				KillTimer(m_nTimer);
				m_nTimer = 0;
			}
		}

#ifdef UNDER_CE
		if ((m_nIdleTimeoutInterval != m_nWorkingIdleTimeoutInterval))
		{
			if (m_nIdleTimer != 0)
			{
				KillTimer(m_nIdleTimer);
				m_nIdleTimer = 0;
			}
		}

		if ((m_bIdleTimeoutResetEnabled) && (m_nIdleTimeoutInterval > 0))
		{
			if (m_nIdleTimer == 0)
			{
				m_nIdleTimer = SetTimer(3, m_nIdleTimeoutInterval, NULL);
				if (m_nIdleTimer == 0)
				{
//					MessageBox(_T("SetTimer Error"),_T("TimerCtrl"),MB_OK);
				}
				else
				{
//					MessageBox(_T("SetTimer Okay"),_T("TimerCtrl"),MB_OK);
				}
				m_nWorkingIdleTimeoutInterval = m_nIdleTimeoutInterval;
			}
		}
		else
		{
			if (m_nIdleTimer != 0)
			{
				KillTimer(m_nIdleTimer);
				m_nIdleTimer = 0;
			}
		}
#endif UNDER_CE
	}
}

long CS309TimerCtrl::GetVersion() 
{
	return (_wVerMajor * 100) + _wVerMinor;
}

long CS309TimerCtrl::GetIdleTimeoutBattery() 
{
	return m_nBatteryTimeout;
}

long CS309TimerCtrl::GetIdleTimeoutExternal() 
{
	return m_nExternalTimeout;
}

BOOL CS309TimerCtrl::GetIdleTimeoutResetEnabled() 
{
	return m_bIdleTimeoutResetEnabled;
}

void CS309TimerCtrl::SetIdleTimeoutResetEnabled(BOOL bNewValue) 
{
	if (m_bIdleTimeoutResetEnabled != bNewValue)
	{
		SetModifiedFlag();
		m_bIdleTimeoutResetEnabled = bNewValue;
	}
}

long CS309TimerCtrl::GetIdleTimeoutInterval() 
{
	return m_nIdleTimeoutInterval;
}

void CS309TimerCtrl::SetIdleTimeoutInterval(long nNewValue) 
{
	if ((nNewValue < 0) || (nNewValue > 65535))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("Value out of range."), 0);
	}
	else
	{
		if (m_nIdleTimeoutInterval != nNewValue)
		{
			m_nIdleTimeoutInterval = nNewValue;
			SetTimerFunction();
			SetModifiedFlag();
		}
	}
}

BOOL CS309TimerCtrl::GetOnBatteryPower() 
{
#ifdef UNDER_CE
	m_bOnBatteryPower = true;
	SYSTEM_POWER_STATUS_EX spse;
	if (GetSystemPowerStatusEx(&spse, true))
	{
		if (spse.ACLineStatus == 1)
		{
			m_bOnBatteryPower = false;
		}
	}
#endif
	return m_bOnBatteryPower;
}

