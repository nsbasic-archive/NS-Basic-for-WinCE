// S309UserNotificationCtl.cpp : Implementation of the CS309UserNotificationCtrl ActiveX Control class.

#include "stdafx.h"
#include "S309UserNotification.h"
#include "S309UserNotificationCtl.h"
#include "S309UserNotificationPpg.h"
#ifdef UNDER_CE
#include <notify.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309UserNotificationCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309UserNotificationCtrl, COleControl)
	//{{AFX_MSG_MAP(CS309UserNotificationCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CS309UserNotificationCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CS309UserNotificationCtrl)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "LED", GetLED, SetLED, VT_BOOL)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Vibrate", GetVibrate, SetVibrate, VT_BOOL)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Dialog", GetDialog, SetDialog, VT_BOOL)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Sound", GetSound, SetSound, VT_BOOL)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Repeat", GetRepeat, SetRepeat, VT_BOOL)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "DialogTitle", GetDialogTitle, SetDialogTitle, VT_BSTR)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "DialogText", GetDialogText, SetDialogText, VT_BSTR)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "SoundFile", GetSoundFile, SetSoundFile, VT_BSTR)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "DateTime", GetDateTime, SetDateTime, VT_VARIANT)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "AppName", GetAppName, SetAppName, VT_BSTR)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Left", GetLeft, SetLeft, VT_I4)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Top", GetTop, SetTop, VT_I4)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "VersionMajor", GetVersionMajor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "VersionMinor", GetVersionMinor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Version", GetVersion, SetNotSupported, VT_I4)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Set", Set, VT_I4, VTS_I4)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Clear", Clear, VT_BOOL, VTS_I4)
	DISP_FUNCTION(CS309UserNotificationCtrl, "GetUserPreferences", GetUserPreferences, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Handle", Handle, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CS309UserNotificationCtrl, "RunAppAtTime", RunAppAtTime, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CS309UserNotificationCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CS309UserNotificationCtrl, COleControl)
	//{{AFX_EVENT_MAP(CS309UserNotificationCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CS309UserNotificationCtrl, 1)
	PROPPAGEID(CS309UserNotificationPropPage::guid)
END_PROPPAGEIDS(CS309UserNotificationCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309UserNotificationCtrl, "S309.UserNotification.1",
	0xe4a57599, 0xbd6f, 0x11d2, 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CS309UserNotificationCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DS309UserNotification =
		{ 0xe4a57597, 0xbd6f, 0x11d2, { 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67 } };
const IID BASED_CODE IID_DS309UserNotificationEvents =
		{ 0xe4a57598, 0xbd6f, 0x11d2, { 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwS309UserNotificationOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CS309UserNotificationCtrl, IDS_S309USERNOTIFICATION, _dwS309UserNotificationOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::CS309UserNotificationCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309UserNotificationCtrl

BOOL CS309UserNotificationCtrl::CS309UserNotificationCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegInsertable | afxRegApartmentThreading to afxRegInsertable.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_S309USERNOTIFICATION,
			IDB_S309USERNOTIFICATION,
			afxRegInsertable | afxRegApartmentThreading,
			_dwS309UserNotificationOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::CS309UserNotificationCtrl - Constructor

CS309UserNotificationCtrl::CS309UserNotificationCtrl()
{
	InitializeIIDs(&IID_DS309UserNotification, &IID_DS309UserNotificationEvents);

	// TODO: Initialize your control's instance data here.
	m_vDateTime = COleVariant();
//	m_bUserMode = AmbientUserMode();
//	m_bDesignMode = false;
#ifndef UNDER_CE
//	m_bUserMode = !m_bUserMode;
	m_hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(1), IMAGE_BITMAP, 0, 0, 0);
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::~CS309UserNotificationCtrl - Destructor

CS309UserNotificationCtrl::~CS309UserNotificationCtrl()
{
#ifndef UNDER_CE
	::DeleteObject(m_hBitmap);
#endif
}

/*
/////////////////////////////////////////////////////////////////////////////
// NOTE: For WinCE, use AdjustCtlBounds() to adjust the size of the 
//            'CRect& rcBounds' parameter that is passed into the control's 
//            OnDraw() handler.  This adjustment is required for some versions 
//            of Pocket Visual Basic.
static CRect AdjustCtlBounds(const COleControl* pCtl, const CRect &rcBounds)
{
	if((!::IsWindow(pCtl->m_hWnd)) || (pCtl->GetParent() == NULL))
		return rcBounds;

	CRect rcAdjBounds;
	pCtl->GetParent()->GetClientRect(&rcAdjBounds);

	if( (rcAdjBounds.Width() < rcBounds.Width()) && 
		(rcAdjBounds.Height() < rcBounds.Height()) )
		return rcAdjBounds;
	else
		return rcBounds;
}
*/

/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::OnDraw - Drawing function

void CS309UserNotificationCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// Adjust the bounding rectangle
	CRect cRect;
//	CRect rcBounds = AdjustCtlBounds(this,rcSubmittedBounds);

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
// CS309UserNotificationCtrl::DoPropExchange - Persistence support

void CS309UserNotificationCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
	PX_String( pPX, _T("AppName"), m_sAppName, _T("") );
	PX_String( pPX, _T("DialogText"), m_sDialogText, _T("") );
	PX_String( pPX, _T("DialogTitle"), m_sDialogTitle, _T("") );
	PX_String( pPX, _T("SoundFile"), m_sSoundFile, _T("") );
	PX_Bool( pPX, _T("Dialog"), m_bDialog, false );
	PX_Bool( pPX, _T("LED"), m_bLED, false );
	PX_Bool( pPX, _T("Repeat"), m_bRepeat, false );
	PX_Bool( pPX, _T("Sound"), m_bSound, false );
	PX_Bool( pPX, _T("Vibrate"), m_bVibrate, false );
}

/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
// For information on using these flags, please see MFC technical note
// #nnn, "Optimizing an ActiveX Control".
DWORD CS309UserNotificationCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// The control can activate without creating a window.
	// TODO: when writing the control's message handlers, avoid using
	//		the m_hWnd member variable without first checking that its
	//		value is non-NULL.
//	dwFlags |= windowlessActivate;
	return dwFlags;
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::OnResetState - Reset control to default state

void CS309UserNotificationCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::AboutBox - Display an "About" box to the user

void CS309UserNotificationCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_S309USERNOTIFICATION);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl message handlers


BOOL CS309UserNotificationCtrl::GetLED() 
{
	return m_bLED;
}

void CS309UserNotificationCtrl::SetLED(BOOL bNewValue) 
{
	m_bLED = bNewValue;
	SetModifiedFlag();
}

BOOL CS309UserNotificationCtrl::GetVibrate() 
{
	return m_bVibrate;
}

void CS309UserNotificationCtrl::SetVibrate(BOOL bNewValue) 
{
	m_bVibrate = bNewValue;
	SetModifiedFlag();
}

BOOL CS309UserNotificationCtrl::GetDialog() 
{
	return m_bDialog;
}

void CS309UserNotificationCtrl::SetDialog(BOOL bNewValue) 
{
	m_bDialog = bNewValue;
	SetModifiedFlag();
}

BOOL CS309UserNotificationCtrl::GetSound() 
{
	return m_bSound;
}

void CS309UserNotificationCtrl::SetSound(BOOL bNewValue) 
{
	m_bSound = bNewValue;
	SetModifiedFlag();
}

BOOL CS309UserNotificationCtrl::GetRepeat() 
{
	return m_bRepeat;
}

void CS309UserNotificationCtrl::SetRepeat(BOOL bNewValue) 
{
	m_bRepeat = bNewValue;
	SetModifiedFlag();
}

BSTR CS309UserNotificationCtrl::GetDialogTitle() 
{
	CString strResult;
	strResult = m_sDialogTitle;
	return strResult.AllocSysString();
}

void CS309UserNotificationCtrl::SetDialogTitle(LPCTSTR lpszNewValue) 
{
	m_sDialogTitle = lpszNewValue;
	SetModifiedFlag();
}

BSTR CS309UserNotificationCtrl::GetDialogText() 
{
	CString strResult;
	strResult = m_sDialogText;
	return strResult.AllocSysString();
}

void CS309UserNotificationCtrl::SetDialogText(LPCTSTR lpszNewValue) 
{
	m_sDialogText = lpszNewValue;
	SetModifiedFlag();
}

BSTR CS309UserNotificationCtrl::GetSoundFile() 
{
	CString strResult;
	strResult = m_sSoundFile;
	return strResult.AllocSysString();
}

void CS309UserNotificationCtrl::SetSoundFile(LPCTSTR lpszNewValue) 
{
	m_sSoundFile = lpszNewValue;
	SetModifiedFlag();
}


VARIANT CS309UserNotificationCtrl::GetDateTime() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);
	VariantCopyInd( &vaResult, (LPVARIANT)m_vDateTime); 
	return vaResult;
}

void CS309UserNotificationCtrl::SetDateTime(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);

	COleDateTime Date = COleDateTime(Var);

	if (Date.GetStatus() == COleDateTime::valid)
	{
		m_vDateTime.Clear();
		m_vDateTime.Attach(Var);
		SetModifiedFlag();
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("Value out of range."), 0);
	}
}

BSTR CS309UserNotificationCtrl::GetAppName() 
{
	CString strResult;
	strResult = m_sAppName;
	return strResult.AllocSysString();
}

void CS309UserNotificationCtrl::SetAppName(LPCTSTR lpszNewValue) 
{
	m_sAppName = lpszNewValue;
	SetModifiedFlag();
}


long CS309UserNotificationCtrl::Set(long hID) 
{
	HANDLE hUserNotify = 0;
#ifdef UNDER_CE
	SYSTEMTIME Time;
	CE_USER_NOTIFICATION CUN;
	COleDateTime Date = COleDateTime(m_vDateTime);

	if (Date.GetStatus() == COleDateTime::valid)
	{
		Time.wYear = Date.GetYear();
		Time.wMonth = Date.GetMonth();
		Time.wDay = Date.GetDay();
		Time.wHour = Date.GetHour();
		Time.wMinute = Date.GetMinute();
		Time.wSecond = Date.GetSecond();

		CUN.ActionFlags = 0;
		CUN.nMaxSound = 0;
		CUN.dwReserved = 0;
		CUN.pwszDialogTitle = NULL;
		CUN.pwszDialogText = NULL;
		CUN.pwszSound = NULL;
		if (m_bLED)
		{
			CUN.ActionFlags = CUN.ActionFlags + PUN_LED;
		}
		if (m_bVibrate)
		{
			CUN.ActionFlags = CUN.ActionFlags + PUN_VIBRATE;
		}
		if (m_bDialog)
		{
			CUN.ActionFlags = CUN.ActionFlags + PUN_DIALOG;
			CUN.pwszDialogTitle = const_cast <unsigned short *>((LPCTSTR)m_sDialogTitle);
			CUN.pwszDialogText = const_cast <unsigned short *>((LPCTSTR)m_sDialogText);
		}
		if (m_bSound)
		{
			CUN.ActionFlags = CUN.ActionFlags + PUN_SOUND;
			CUN.pwszSound = const_cast <unsigned short *>((LPCTSTR)m_sSoundFile);
			if (m_bRepeat)
			{
				CUN.ActionFlags = CUN.ActionFlags + PUN_REPEAT;
			}
		}
		hUserNotify = CeSetUserNotification((HANDLE)hID, const_cast <unsigned short *>((LPCTSTR)m_sAppName), &Time, &CUN); 
	}
#endif
	return (long)hUserNotify;
}

BOOL CS309UserNotificationCtrl::Clear(long hID) 
{
	BOOL bReturn = false;
#ifdef UNDER_CE
	bReturn = CeClearUserNotification((HANDLE)hID); 
#endif
	return bReturn;
}

BOOL CS309UserNotificationCtrl::GetUserPreferences() 
{
	BOOL bReturn = false;
#ifdef UNDER_CE
	HWND hWND;
	TCHAR szSoundFile[MAX_PATH];
	CE_USER_NOTIFICATION CUN;

	CUN.ActionFlags = 0;
	CUN.nMaxSound = MAX_PATH * sizeof(TCHAR);
	CUN.dwReserved = 0;
	CUN.pwszDialogTitle = NULL;
	CUN.pwszDialogText = NULL;
	if (m_bLED)
	{
		CUN.ActionFlags = CUN.ActionFlags + PUN_LED;
	}
	if (m_bVibrate)
	{
		CUN.ActionFlags = CUN.ActionFlags + PUN_VIBRATE;
	}
	if (m_bDialog)
	{
		CUN.ActionFlags = CUN.ActionFlags + PUN_DIALOG;
	}
	if (m_bSound)
	{
		CUN.ActionFlags = CUN.ActionFlags + PUN_SOUND;
	}
	wcscpy(szSoundFile,(LPCTSTR)m_sSoundFile);
	CUN.pwszSound = szSoundFile;
	if (m_bRepeat)
	{
		CUN.ActionFlags = CUN.ActionFlags + PUN_REPEAT;
	}
	hWND = (HWND)GetHwnd();
	if (hWND != NULL)
		bReturn = CeGetUserNotificationPreferences(hWND, &CUN); 
	else
		bReturn = false;
	if (bReturn)
	{
		if ((CUN.ActionFlags & PUN_LED) == PUN_LED)
			m_bLED = true;
		else
			m_bLED = false;
		if ((CUN.ActionFlags & PUN_VIBRATE) == PUN_VIBRATE)
			m_bVibrate = true;
		else
			m_bVibrate = false;
		if ((CUN.ActionFlags & PUN_DIALOG) == PUN_DIALOG)
			m_bDialog = true;
		else
			m_bDialog = false;
		if ((CUN.ActionFlags & PUN_SOUND) == PUN_SOUND)
			m_bSound = true;
		else
			m_bSound = false;
		m_sSoundFile = CUN.pwszSound;
		if ((CUN.ActionFlags & PUN_REPEAT) == PUN_REPEAT)
			m_bRepeat = true;
		else
			m_bRepeat = false;
	}
#endif
	return bReturn;
}

BOOL CS309UserNotificationCtrl::Handle(LPCTSTR AppName) 
{
	BOOL bReturn = false;
#ifdef UNDER_CE
	bReturn = CeHandleAppNotifications(const_cast <unsigned short *>(AppName));
#endif
	return bReturn;
}

long CS309UserNotificationCtrl::GetLeft() 
{
	long lReturn;
	CRect cRect;
    if (GetRectInContainer(cRect) != 0) 
	{
		lReturn = cRect.left;
	}
	return lReturn;
}

void CS309UserNotificationCtrl::SetLeft(long nNewValue) 
{
	CRect cRect;
    if (GetRectInContainer(cRect) != 0) 
	{
		cRect.left = nNewValue;
		cRect.right = cRect.left;
		SetRectInContainer(cRect);
	}
	SetModifiedFlag();
}

long CS309UserNotificationCtrl::GetTop() 
{
	long lReturn;
	CRect cRect;
    if (GetRectInContainer(cRect) != 0) 
	{
		lReturn = cRect.top;
	}
	return lReturn;
}

void CS309UserNotificationCtrl::SetTop(long nNewValue) 
{
	CRect cRect;
    if (GetRectInContainer(cRect) != 0) 
	{
		cRect.top = nNewValue;
		cRect.bottom = cRect.top;
		SetRectInContainer(cRect);
	}

	SetModifiedFlag();
}

BOOL CS309UserNotificationCtrl::RunAppAtTime() 
{
	BOOL bReturn = false;
#ifdef UNDER_CE
	SYSTEMTIME Time;
	COleDateTime Date = COleDateTime(m_vDateTime);

	if (Date.GetStatus() == COleDateTime::valid)
	{
		Time.wYear = Date.GetYear();
		Time.wMonth = Date.GetMonth();
		Time.wDay = Date.GetDay();
		Time.wHour = Date.GetHour();
		Time.wMinute = Date.GetMinute();
		Time.wSecond = Date.GetSecond();

		bReturn = CeRunAppAtTime(const_cast <unsigned short *>((LPCTSTR)m_sAppName), &Time); 
	}
#endif
	return bReturn;
}

short CS309UserNotificationCtrl::GetVersionMajor() 
{
	// TODO: Add your property handler here

	return _wVerMajor;
}

short CS309UserNotificationCtrl::GetVersionMinor() 
{
	// TODO: Add your property handler here

	return _wVerMinor;
}


VARIANT CS309UserNotificationCtrl::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309UserNotificationCtrl::SetTag(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);
	m_vTag.Clear();
	m_vTag.Attach(Var);

	SetModifiedFlag();
}

long CS309UserNotificationCtrl::GetVersion() 
{
	return (_wVerMajor * 100) + _wVerMinor;
}
