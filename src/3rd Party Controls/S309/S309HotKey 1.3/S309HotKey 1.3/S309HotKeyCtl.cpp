// S309HotKeyCtl.cpp : Implementation of the CS309HotKeyCtrl ActiveX Control class.

#include "stdafx.h"
#include "S309HotKey.h"
#include "S309HotKeyCtl.h"
#include "S309HotKeyPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CS309HotKeyCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CS309HotKeyCtrl, COleControl)
	//{{AFX_MSG_MAP(CS309HotKeyCtrl)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CS309HotKeyCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CS309HotKeyCtrl)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "EnumKey", GetEnumKey, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "EnumAlt", GetEnumAlt, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "EnumWindows", GetEnumWindows, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "EnumShift", GetEnumShift, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "EnumControl", GetEnumControl, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "VersionMajor", GetVersionMajor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "VersionMinor", GetVersionMinor, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CS309HotKeyCtrl, "Version", GetVersion, SetNotSupported, VT_I2)
	DISP_FUNCTION(CS309HotKeyCtrl, "Register", Register, VT_BOOL, VTS_I2 VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL)
	DISP_FUNCTION(CS309HotKeyCtrl, "Unregister", Unregister, VT_BOOL, VTS_I2 VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL)
	DISP_FUNCTION(CS309HotKeyCtrl, "UnregisterAll", UnregisterAll, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309HotKeyCtrl, "EnumFirst", EnumFirst, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309HotKeyCtrl, "EnumNext", EnumNext, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309HotKeyCtrl, "KeyboardEvent", KeyboardEvent, VT_EMPTY, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	DISP_FUNCTION(CS309HotKeyCtrl, "MouseEvent", MouseEvent, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION(CS309HotKeyCtrl, "GetAsyncKeyState", GetAsyncKeyState, VT_I2, VTS_I2)
	DISP_FUNCTION(CS309HotKeyCtrl, "GetKeyState", GetKeyState, VT_I2, VTS_I2)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CS309HotKeyCtrl, COleControl)
	//{{AFX_EVENT_MAP(CS309HotKeyCtrl)
	EVENT_CUSTOM("HotKeyDown", FireHotKeyDown, VTS_I2  VTS_BOOL  VTS_BOOL  VTS_BOOL  VTS_BOOL)
	EVENT_CUSTOM("HotKeyUp", FireHotKeyUp, VTS_I2  VTS_BOOL  VTS_BOOL  VTS_BOOL  VTS_BOOL)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CS309HotKeyCtrl, 1)
	PROPPAGEID(CS309HotKeyPropPage::guid)
END_PROPPAGEIDS(CS309HotKeyCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CS309HotKeyCtrl, "S309.HotKey.1",
	0x95299e1b, 0x49ef, 0x11d3, 0xae, 0x2e, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CS309HotKeyCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DS309HotKey =
		{ 0x95299e19, 0x49ef, 0x11d3, { 0xae, 0x2e, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };
const IID BASED_CODE IID_DS309HotKeyEvents =
		{ 0x95299e1a, 0x49ef, 0x11d3, { 0xae, 0x2e, 0, 0x60, 0x8c, 0xc1, 0xdd, 0x62 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwS309HotKeyOleMisc =
#ifdef UNDER_CE
	OLEMISC_INVISIBLEATRUNTIME |
#endif // UNDER_CE
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CS309HotKeyCtrl, IDS_S309HOTKEY, _dwS309HotKeyOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl::CS309HotKeyCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CS309HotKeyCtrl

BOOL CS309HotKeyCtrl::CS309HotKeyCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_S309HOTKEY,
			IDB_S309HOTKEY,
			afxRegApartmentThreading,
			_dwS309HotKeyOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl::CS309HotKeyCtrl - Constructor

CS309HotKeyCtrl::CS309HotKeyCtrl()
{
	InitializeIIDs(&IID_DS309HotKey, &IID_DS309HotKeyEvents);

	m_nIDStart = 0xE000;
	for (long nIndex = 0; nIndex < 4096; nIndex++)
	{
		m_cID[nIndex] = '0';
	}
	m_bEnum = false;

	m_bUserMode = AmbientUserMode();

#ifndef UNDER_CE
	m_bUserMode = !m_bUserMode;
	m_hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(1), IMAGE_BITMAP, 0, 0, 0);
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl::~CS309HotKeyCtrl - Destructor

CS309HotKeyCtrl::~CS309HotKeyCtrl()
{
	BOOL bCleanup = UnregisterAll();
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl::OnDraw - Drawing function

void CS309HotKeyCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	CRect cRect;
	if (m_bUserMode)
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
		if (m_hBitmap != NULL)
		{
			HDC dcNew;
			HBITMAP hBitmap;
			BITMAP Bitmap;

			::GetObject(m_hBitmap, sizeof(Bitmap), &Bitmap);

			dcNew = ::CreateCompatibleDC(pdc->GetSafeHdc());
			hBitmap = (HBITMAP)::SelectObject(dcNew, m_hBitmap);

			::StretchBlt(pdc->GetSafeHdc(), rcBounds.left, rcBounds.top, rcBounds.Width(), rcBounds.Height(), dcNew, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

			::SelectObject(dcNew, hBitmap);
			::DeleteDC(dcNew);
		}
		else
		{
			pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
			pdc->Ellipse(rcBounds);
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl::DoPropExchange - Persistence support

void CS309HotKeyCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl::OnResetState - Reset control to default state

void CS309HotKeyCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CS309HotKeyCtrl message handlers

LRESULT CS309HotKeyCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == WM_HOTKEY) 
	{
		BOOL bAlt = false;
		BOOL bControl = false;
		BOOL bShift = false;
		BOOL bWindows = false;
		short nModifiers = (short)LOWORD(lParam);
		if ((nModifiers & MOD_ALT) == MOD_ALT)
			bAlt = true;
		if ((nModifiers & MOD_CONTROL) == MOD_CONTROL)
			bControl = true;
		if ((nModifiers & MOD_SHIFT) == MOD_SHIFT)
			bShift = true;
		if ((nModifiers & MOD_WIN) == MOD_WIN)
			bWindows = true;
#ifdef UNDER_CE
		if ((nModifiers & MOD_KEYUP) == MOD_KEYUP)
		{
			FireHotKeyUp((UINT)HIWORD(lParam), bAlt, bControl, bShift, bWindows); 
		}
		else
		{
#endif
			if (AmbientUserMode())
			{
				FireHotKeyDown((UINT)HIWORD(lParam), bAlt, bControl, bShift, bWindows); 
			}
#ifdef UNDER_CE
		}
#endif
	}
	return COleControl::WindowProc(message, wParam, lParam);
}

BOOL CS309HotKeyCtrl::Register(short nKey, BOOL bAlt, BOOL bControl, BOOL bShift, BOOL bWindows) 
{
	BOOL bReturn = false;
	short nFlags = 0;
	if (nKey > 255)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("Key out of range."), 0);
		return false;
	}

	if (bAlt)
		nFlags |= MOD_ALT;
	if (bControl)
		nFlags |= MOD_CONTROL;
	if (bShift)
		nFlags |= MOD_SHIFT;
	if (bWindows)
		nFlags |= MOD_WIN;

	short ncID = (nKey << 4) + nFlags;
	long nID = m_nIDStart + ncID;
#ifdef UNDER_CE
	bReturn = ::RegisterHotKey((HWND)GetHwnd(), (UINT)nID, (UINT)(nFlags + MOD_KEYUP), (UINT)nKey);
#else
	bReturn = ::RegisterHotKey((HWND)GetHwnd(), (UINT)nID, (UINT)(nFlags), (UINT)nKey);
#endif
	if (bReturn)
	{
		m_cID[ncID] = '1';
	}
	return bReturn;
}

BOOL CS309HotKeyCtrl::Unregister(short nKey, BOOL bAlt, BOOL bControl, BOOL bShift, BOOL bWindows) 
{
	BOOL bReturn = false;
	short nFlags = 0;
	if (nKey > 255)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("Key out of range."), 0);
		return false;
	}

	if (bAlt)
		nFlags |= MOD_ALT;
	if (bControl)
		nFlags |= MOD_CONTROL;
	if (bShift)
		nFlags |= MOD_SHIFT;
	if (bWindows)
		nFlags |= MOD_WIN;

	short ncID = (nKey << 4) + nFlags;
	long nID = m_nIDStart + ncID;
	bReturn = ::UnregisterHotKey((HWND)GetHwnd(), (UINT)nID);
	if (bReturn)
	{
		m_cID[ncID] = '0';
	}
	return bReturn;
}

BOOL CS309HotKeyCtrl::UnregisterAll() 
{
	BOOL bReturn = true;
	for (long nIndex = 0; nIndex < 4096; nIndex++)
	{
		if (m_cID[nIndex] == '1')
		{
			long nID = m_nIDStart + nIndex;
			if (::UnregisterHotKey((HWND)GetHwnd(), (UINT)nID))
			{
				m_cID[nIndex] = '0';
			}
			else
			{
				bReturn = false;
			}
		}
	}
	return bReturn;
}

short CS309HotKeyCtrl::GetEnumKey() 
{
	short nReturn = 0;
	if (m_bEnum)
	{
		nReturn = (m_nEnum & 0xFF0) >> 4;
	}
	return nReturn;
}

BOOL CS309HotKeyCtrl::EnumFirst() 
{
	BOOL bReturn = false;
	for (m_nEnum = 0; m_nEnum < 4096; m_nEnum++)
	{
		if (m_cID[m_nEnum] == '1')
		{
			bReturn = true;
			break;
		}
	}
	m_bEnum = bReturn;
	return bReturn;
}

BOOL CS309HotKeyCtrl::EnumNext() 
{
	BOOL bReturn = false;
	if (m_bEnum)
	{
		for (; m_nEnum < 4096; m_nEnum++)
		{
			if (m_cID[m_nEnum] == '1')
			{
				bReturn = true;
				break;
			}
		}
		m_bEnum = bReturn;
	}
	return bReturn;
}

BOOL CS309HotKeyCtrl::GetEnumAlt() 
{
	BOOL bReturn = false;
	if (m_bEnum)
	{
		if ((m_nEnum & MOD_ALT) == MOD_ALT)
		{
			bReturn = true;
		}
	}
	return bReturn;
}

BOOL CS309HotKeyCtrl::GetEnumWindows() 
{
	BOOL bReturn = false;
	if (m_bEnum)
	{
		if ((m_nEnum & MOD_WIN) == MOD_WIN)
		{
			bReturn = true;
		}
	}
	return bReturn;
}

BOOL CS309HotKeyCtrl::GetEnumShift() 
{
	BOOL bReturn = false;
	if (m_bEnum)
	{
		if ((m_nEnum & MOD_SHIFT) == MOD_SHIFT)
		{
			bReturn = true;
		}
	}
	return bReturn;
}

BOOL CS309HotKeyCtrl::GetEnumControl() 
{
	BOOL bReturn = false;
	if (m_bEnum)
	{
		if ((m_nEnum & MOD_CONTROL) == MOD_CONTROL)
		{
			bReturn = true;
		}
	}
	return bReturn;
}

VARIANT CS309HotKeyCtrl::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309HotKeyCtrl::SetTag(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);
	m_vTag.Clear();
	m_vTag.Attach(Var);
	SetModifiedFlag();
}

short CS309HotKeyCtrl::GetVersionMajor() 
{
	return _wVerMajor;
}

short CS309HotKeyCtrl::GetVersionMinor() 
{
	return _wVerMinor;
}

void CS309HotKeyCtrl::KeyboardEvent(short VirtualKey, short ScanCode, long dwFlags, long dwExtraInfo) 
{
	if ((VirtualKey > 255) || (VirtualKey < 0))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("VirtualKey out of range."), 0);
		return;
	}
	if ((ScanCode > 255) || (ScanCode < 0))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("ScanCode out of range."), 0);
		return;
	}
	
	keybd_event((BYTE)VirtualKey, (BYTE)ScanCode, dwFlags, dwExtraInfo);

}

void CS309HotKeyCtrl::MouseEvent(long dwFlags, long dwX, long dwY, long dwData, long dwExtraInfo) 
{
	mouse_event(dwFlags, dwX, dwY, dwData, dwExtraInfo);
}

short CS309HotKeyCtrl::GetAsyncKeyState(short VirtualKey) 
{
	short bReturn = 0;
	if ((VirtualKey > 255) || (VirtualKey < 0))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("VirtualKey out of range."), 0);
	}
	else
	{
		bReturn = GetAsyncKeyState(VirtualKey);
	}
	return bReturn;
}

short CS309HotKeyCtrl::GetKeyState(short VirtualKey) 
{
	short bReturn = 0;
	if ((VirtualKey > 255) || (VirtualKey < 0))
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, _T("VirtualKey out of range."), 0);
	}
	else
	{
		bReturn = GetKeyState(VirtualKey);
	}
	return bReturn;
}

short CS309HotKeyCtrl::GetVersion() 
{
	// TODO: Add your property handler here

	return (_wVerMajor * 100) + _wVerMinor;
}
