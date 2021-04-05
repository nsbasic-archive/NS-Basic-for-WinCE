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

#ifndef UNDER_CE
	#include "file_ver.h"	// CFileVersionInfo
#else // UNDER_CE
 #ifndef WCE_PLATFORM_STANDARDSDK
	#define VS_VERSION_INFO         1
 #endif // WCE_PLATFORM_STANDARDSDK
	#include "res.h"        // Ce....
#endif // UNDER_CE


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
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "Version", GetVersion, SetNotSupported, VT_R4)
	DISP_PROPERTY_EX(CS309UserNotificationCtrl, "VersionString", GetVersionString, SetNotSupported, VT_BSTR)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Set", MethodSet, VT_I4, VTS_I4)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Clear", MethodClear, VT_BOOL, VTS_I4)
	DISP_FUNCTION(CS309UserNotificationCtrl, "GetUserPreferences", MethodGetUserPreferences, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Handle", MethodHandle, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CS309UserNotificationCtrl, "RunAppAtTime", MethodRunAppAtTime, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309UserNotificationCtrl, "Alerts", MethodAlerts, VT_DISPATCH, VTS_NONE)
	DISP_FUNCTION(CS309UserNotificationCtrl, "CancelRunAppAtTime", MethodCancelRunAppAtTime, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CS309UserNotificationCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CS309UserNotificationCtrl, COleControl)
	//{{AFX_EVENT_MAP(CS309UserNotificationCtrl)
	EVENT_CUSTOM("AlertCommand", FireAlertCommand, VTS_DISPATCH  VTS_I4)
	EVENT_CUSTOM("AlertDismiss", FireAlertDismiss, VTS_DISPATCH  VTS_BOOL)
	EVENT_CUSTOM("AlertLink", FireAlertLink, VTS_DISPATCH  VTS_BSTR)
	EVENT_CUSTOM("AlertShow", FireAlertShow, VTS_DISPATCH)
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

// {A6436888-F49A-4bd2-B1D5-48C7D2B21C51}
IMPLEMENT_OLECREATE_EX(CS309UserNotificationCtrl, "S309.UserNotification.1.5",
	0xa6436888, 0xf49a, 0x4bd2, 0xb1, 0xd5, 0x48, 0xc7, 0xd2, 0xb2, 0x1c, 0x51)
//	0xe4a57599, 0xbd6f, 0x11d2, 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CS309UserNotificationCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs
// {09CF196B-CC6E-4b1a-8B87-45CECBCD28AD}
const IID BASED_CODE IID_DS309UserNotification =
		{ 0x9cf196b, 0xcc6e, 0x4b1a, { 0x8b, 0x87, 0x45, 0xce, 0xcb, 0xcd, 0x28, 0xad } };
//		{ 0xe4a57597, 0xbd6f, 0x11d2, { 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67 } };

// {443FCCAC-E1B3-4c6d-9457-7051DFAF27A4}
const IID BASED_CODE IID_DS309UserNotificationEvents =
		{ 0x443fccac, 0xe1b3, 0x4c6d, { 0x94, 0x57, 0x70, 0x51, 0xdf, 0xaf, 0x27, 0xa4 } };
//		{ 0xe4a57598, 0xbd6f, 0x11d2, { 0xae, 0x1a, 0, 0x60, 0x8c, 0xc0, 0x13, 0x67 } };


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
//			afxRegInsertable | afxRegApartmentThreading,
			0,
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

#ifdef S309_HAVE_ALERTS
	m_hIcon = (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(0), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR); 
#else // S309_HAVE_ALERTS
	m_hIcon = NULL;
#endif // S309_HAVE_ALERTS
	m_Alerts.GetIDispatch(TRUE);
	m_Alerts.m_pTopParent = this;
	m_Alerts.m_hTopParentIcon = m_hIcon;

	m_strVersionString.Empty();
	m_vTag.Clear();
	m_vDateTime = COleVariant();

#ifndef UNDER_CE
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

	if (NULL != m_hIcon)
	{
		DestroyIcon(m_hIcon);
		m_hIcon = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CS309UserNotificationCtrl::OnDraw - Drawing function

void CS309UserNotificationCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
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
// CS309UserNotificationCtrl::DoPropExchange - Persistence support

void CS309UserNotificationCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
	PX_String( pPX, TEXT("AppName"), m_sAppName, TEXT("") );
	PX_String( pPX, TEXT("DialogText"), m_sDialogText, TEXT("") );
	PX_String( pPX, TEXT("DialogTitle"), m_sDialogTitle, TEXT("") );
	PX_String( pPX, TEXT("SoundFile"), m_sSoundFile, TEXT("") );
	PX_Bool( pPX, TEXT("Dialog"), m_bDialog, FALSE);
	PX_Bool( pPX, TEXT("LED"), m_bLED, FALSE);
	PX_Bool( pPX, TEXT("Sound"), m_bSound, FALSE);
	PX_Bool( pPX, TEXT("Vibrate"), m_bVibrate, FALSE);
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

	if (COleDateTime::valid == Date.GetStatus())
	{
		m_vDateTime.Clear();
		m_vDateTime.Attach(Var);
		SetModifiedFlag();
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, TEXT("Value out of range."), 0);
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

long CS309UserNotificationCtrl::MethodSet(long hID) 
{
	HANDLE hUserNotify = 0;
#ifdef UNDER_CE
	TCHAR szAppName[MAX_PATH];
	TCHAR szDialogTitle[MAX_PATH];
	TCHAR szDialogText[MAX_PATH];
	TCHAR szSound[MAX_PATH];
	SYSTEMTIME Time;
	CE_USER_NOTIFICATION CUN;
	COleDateTime Date = COleDateTime(m_vDateTime);

	if (Date.GetStatus() == COleDateTime::valid)
	{
		VariantTimeToSystemTime(Date.m_dt, &Time);

		memset(&CUN, 0, sizeof(CE_USER_NOTIFICATION));
		CUN.ActionFlags = 0;
		CUN.nMaxSound = 0;
		CUN.dwReserved = 0;
		CUN.pwszDialogTitle = NULL;
		CUN.pwszDialogText = NULL;
		CUN.pwszSound = NULL;
		if (m_bLED)
		{
			CUN.ActionFlags |= PUN_LED;
		}
		if (m_bVibrate)
		{
			CUN.ActionFlags |= PUN_VIBRATE;
		}
		if (m_bDialog)
		{
			CUN.ActionFlags |= PUN_DIALOG;
			_tcscpy(szDialogTitle, m_sDialogTitle);
			_tcscpy(szDialogText, m_sDialogText);
			CUN.pwszDialogTitle = szDialogTitle;
			CUN.pwszDialogText = szDialogText;
		}
		if (m_bSound)
		{
			CUN.ActionFlags |= PUN_SOUND;
			_tcscpy(szSound, m_sSoundFile);
			CUN.pwszSound = szSound;
			if (m_bRepeat)
			{
				CUN.ActionFlags |= PUN_REPEAT;
			}
		}
		_tcscpy(szAppName, m_sAppName);
		hUserNotify = CeSetUserNotification((HANDLE)hID, szAppName, &Time, &CUN); 
		if (hUserNotify == 0)
		{
			CString strMessage;
			strMessage.Format(TEXT("Set failed, GetLastError() = %d"), GetLastError());
			AfxMessageBox(strMessage);
		}
	}
#endif
	return (long)hUserNotify;
}

BOOL CS309UserNotificationCtrl::MethodClear(long hID) 
{
	BOOL bReturn = false;
#ifdef UNDER_CE
	bReturn = CeClearUserNotification((HANDLE)hID); 
#endif
	return bReturn;
}

BOOL CS309UserNotificationCtrl::MethodGetUserPreferences() 
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

BOOL CS309UserNotificationCtrl::MethodHandle(LPCTSTR AppName) 
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

BOOL CS309UserNotificationCtrl::MethodRunAppAtTime() 
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

//		bReturn = CeRunAppAtTime(const_cast <unsigned short *>((LPCTSTR)m_sAppName), &Time); 
		bReturn = CeRunAppAtTime((LPTSTR)(LPCTSTR)m_sAppName, &Time); 
	}
#endif
	return bReturn;
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

float CS309UserNotificationCtrl::GetVersion() 
{
	return (float)(_wVerMajor + ((float)_wVerMinor / 100.0));
}

LPDISPATCH CS309UserNotificationCtrl::MethodAlerts() 
{
	// TODO: Add your dispatch handler code here

	return m_Alerts.GetIDispatch(TRUE);
}

BSTR CS309UserNotificationCtrl::GetVersionString() 
{
	CString strResult;

	if (m_strVersionString.IsEmpty())
	{
		TCHAR szFile[4095];

		if (GetModuleFileName(AfxGetInstanceHandle(), szFile, 4095))
		{
#ifdef UNDER_CE
			CeResource cer;
			CeVersionInfo *cevi;
			cevi = new CeVersionInfo;
			cer.Load(szFile);
			HRSRC hRsrc = cer.FindResource(VS_VERSION_INFO, RT_VERSION);
			DWORD dwSize;
			LPVOID lpByte = cer.LoadResource(hRsrc, dwSize);

			cevi->Load((LPBYTE)lpByte);
			
			m_strVersionString = cevi->m_wszFileVersion;

			delete cevi;
#else //UNDER_CE
			CFileVersionInfo m_info;

			m_info.ReadVersionInfo(szFile);

			if (m_info.IsValid())
			{
				m_strVersionString = m_info.GetFileVersionString();
			} 
#endif // UNDER_CE
		}
	}

	strResult = m_strVersionString;
	return strResult.AllocSysString();
}

LRESULT CS309UserNotificationCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	LPDISPATCH lpDx = NULL;
	CS309Alert *alert;
	CString strMessage;
	switch (message)
	{
		case WM_USER:
			alert = (CS309Alert *)lParam;
			lpDx = alert->GetIDispatch(TRUE);
			switch (wParam)
			{
				case 1:
					FireAlertCommand(lpDx, alert->m_lCommand);
					return TRUE;
					break;
				case 2:
					FireAlertLink(lpDx, (LPCTSTR)alert->m_strLink);
					return TRUE;
					break;
				case 3:
					FireAlertDismiss(lpDx, alert->m_bTimeout);
					return TRUE;
					break;
				case 4:
					FireAlertShow(lpDx);
					return (!alert->m_bShow);
					break;
			}
			break;
		default:
			break;
	}
	return COleControl::WindowProc(message, wParam, lParam);
}

BOOL CS309UserNotificationCtrl::MethodCancelRunAppAtTime() 
{
	BOOL bReturn = false;
#ifdef UNDER_CE
	bReturn = CeRunAppAtTime((LPTSTR)(LPCTSTR)m_sAppName, NULL); 
#endif
	return bReturn;
}
