// S309Icon.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "S309Icon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS309Icon

IMPLEMENT_DYNCREATE(CS309Icon, CCmdTarget)

CS309Icon::CS309Icon()
{
	EnableAutomation();
	m_hIcon = NULL;
	m_lIconID = 0;
	m_strName.Empty();
	m_vTag.Clear();
}

CS309Icon::~CS309Icon()
{
	Destroy();
}

void CS309Icon::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CS309Icon, CCmdTarget)
	//{{AFX_MSG_MAP(CS309Icon)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CS309Icon, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CS309Icon)
	DISP_PROPERTY_EX(CS309Icon, "This", GetThis, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309Icon, "hIcon", GetHIcon, SetHIcon, VT_I4)
	DISP_PROPERTY_EX(CS309Icon, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_FUNCTION(CS309Icon, "Load", MethodLoad, VT_BOOL, VTS_BSTR VTS_VARIANT)
	DISP_FUNCTION(CS309Icon, "Destroy", MethodDestroy, VT_EMPTY, VTS_NONE)
	DISP_DEFVALUE(CS309Icon, "hIcon")
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IS309Icon to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E48A1C23-57FB-4117-A0FF-3E12335ECC28}
static const IID IID_IS309Icon =
{ 0xe48a1c23, 0x57fb, 0x4117, { 0xa0, 0xff, 0x3e, 0x12, 0x33, 0x5e, 0xcc, 0x28 } };

BEGIN_INTERFACE_MAP(CS309Icon, CCmdTarget)
	INTERFACE_PART(CS309Icon, IID_IS309Icon, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS309Icon message handlers

long CS309Icon::GetThis() 
{
	return (long)this;
}

long CS309Icon::CommonOptionalLong(const VARIANT *vLong, long nInit)
{
	long nReturn = nInit;

	if (V_VT(vLong) != VT_ERROR)
	{
		VARIANT varTemp;
		::VariantInit(&varTemp);
		if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(vLong), 0, VT_I4) == S_OK)
		{
			nReturn = V_I4(&varTemp);
		}
		::VariantClear(&varTemp);
	}
	return nReturn;
} 

HICON CS309Icon::hIcon()
{
	return m_hIcon;
}

void CS309Icon::Destroy()
{
	if (NULL != m_hIcon)
	{
		::DestroyIcon(m_hIcon);
		m_hIcon = NULL;
	}
}

BOOL CS309Icon::MethodLoad(LPCTSTR Name, const VARIANT FAR& IconID) 
{
	BOOL bReturn = FALSE;

#ifdef S309_HAVE_ALERTS
	bool bLarge = false;
	int x = 0;
	int y = 0;
	m_lIconID = CommonOptionalLong(&IconID, 0);
	m_strName = Name;

	HICON hLarge = NULL;
	HICON hSmall = NULL;
	HICON hIcon = NULL;

	HICON hxIcon = NULL;
	UINT nIcons = 0;
#ifdef UNDER_CE
 #if _WIN32_WCE > 210 
	if (m_lIconID > 0)
	{
		m_lIconID = m_lIconID * -1;
	}
  #ifdef WIN32_PLATFORM_PSPC
	hxIcon = ::ExtractIconEx(m_strName, m_lIconID, &hLarge, &hSmall, 1);
  #else // WIN32_PLATFORM_PSPC
   #if _WIN32_WCE < 301
	nIcons = ::ExtractIconEx(m_strName, m_lIconID, &hLarge, &hSmall, 1);
   #else // _WIN32_WCE < 301
	hxIcon = ::ExtractIconEx(m_strName, m_lIconID, &hLarge, &hSmall, 1);
   #endif // _WIN32_WCE < 301
  #endif // WIN32_PLATFORM_PSPC
 #else // _WIN32_WCE > 210
	nIcons = ::ExtractIconEx(m_strName, m_lIconID, &hLarge, &hSmall, 1);
 #endif //  _WIN32_WCE > 210
#else // UNDER_CE
	nIcons = ::ExtractIconEx(m_strName, m_lIconID, &hLarge, &hSmall, 1);
#endif // UNDER_CE

	if (bLarge)
	{
		hIcon = hLarge;
		x = GetSystemMetrics(SM_CXICON);
		y = GetSystemMetrics(SM_CYICON);
		if (hSmall != NULL)
		{
			::DestroyIcon(hSmall);
		}
	}
	else
	{
		hIcon = hSmall;
		x = GetSystemMetrics(SM_CXSMICON);
		y = GetSystemMetrics(SM_CYSMICON);
		if (hLarge != NULL)
		{
			::DestroyIcon(hLarge);
		}
	}

	if (hIcon != NULL)
	{
		if (NULL != m_hIcon)
		{
			::DestroyIcon(m_hIcon);
		}
		m_hIcon = hIcon;
		bReturn = TRUE;
	}
#endif // S309_HAVE_ALERTS
	return bReturn;
}

void CS309Icon::MethodDestroy() 
{
	Destroy();
}

long CS309Icon::GetHIcon() 
{
	return 0;
}

void CS309Icon::SetHIcon(long nNewValue) 
{
	if (m_hIcon != (HICON)nNewValue)
	{
		Destroy();
		m_hIcon = (HICON)nNewValue;
	}
}

VARIANT CS309Icon::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);
	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309Icon::SetTag(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);
	m_vTag.Clear();
	m_vTag.Attach(Var);
}
