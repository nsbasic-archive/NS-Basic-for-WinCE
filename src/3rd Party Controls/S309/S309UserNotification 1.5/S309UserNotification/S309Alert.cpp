// S309Alert.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"

#ifdef S309_HAVE_ALERTS
	#pragma comment(lib, "Aygshell.lib")

//	#include <sipapi.h>
//	#include <shlobj.h>
//	#include <prsht.h>
#endif // S309_HAVE_ALERTS

#include "S309Alert.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// {BD26BAEE-BAC7-489a-A1A4-25CBC10AFE97}
static const GUID guidNotifyApp = 
{ 0xbd26baee, 0xbac7, 0x489a, { 0xa1, 0xa4, 0x25, 0xcb, 0xc1, 0xa, 0xfe, 0x97 } };

/////////////////////////////////////////////////////////////////////////////
// CS309Alert

CS309Alert::CS309Alert()
{
	EnableAutomation();

	m_pTopParent = NULL;
	m_vTag.Clear();
	m_bValid = TRUE;
	m_pIcon = new CS309Icon;
	m_hTopParentIcon = NULL;
	m_strTitle.Empty();
	m_strHTML.Empty();
	m_bShow = TRUE;
	m_clsid = guidNotifyApp;
	m_dwUpdateMask = 0;
#ifdef S309_HAVE_ALERTS
	memset(&m_NotificationData, 0, sizeof(SHNOTIFICATIONDATA));
	m_NotificationData.cbStruct = sizeof(SHNOTIFICATIONDATA);
	m_NotificationData.lParam = (LPARAM)this;
	m_NotificationData.dwID = (DWORD)this;
#endif // S309_HAVE_ALERTS

}

CS309Alert::~CS309Alert()
{
#ifdef S309_HAVE_ALERTS
	SHNotificationRemove(&m_clsid, m_NotificationData.dwID);
#endif // S309_HAVE_ALERTS
	if (NULL != m_pIcon)
	{
		LPDISPATCH lpDx = m_pIcon->GetIDispatch(FALSE);
		m_pIcon = NULL;
		lpDx->Release();
	}
}

void CS309Alert::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CS309Alert, CWnd)
	//{{AFX_MSG_MAP(CS309Alert)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CS309Alert, CWnd)
	//{{AFX_DISPATCH_MAP(CS309Alert)
	DISP_PROPERTY_EX(CS309Alert, "Name", GetName, SetName, VT_BSTR)
	DISP_PROPERTY_EX(CS309Alert, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_PROPERTY_EX(CS309Alert, "HTML", GetHTML, SetHTML, VT_BSTR)
	DISP_PROPERTY_EX(CS309Alert, "Duration", GetDuration, SetDuration, VT_I4)
	DISP_PROPERTY_EX(CS309Alert, "Title", GetTitle, SetTitle, VT_BSTR)
	DISP_PROPERTY_EX(CS309Alert, "StraightToTray", GetStraightToTray, SetStraightToTray, VT_BOOL)
	DISP_PROPERTY_EX(CS309Alert, "Critical", GetCritical, SetCritical, VT_BOOL)
	DISP_PROPERTY_EX(CS309Alert, "ForceMessage", GetForceMessage, SetForceMessage, VT_BOOL)
	DISP_PROPERTY_EX(CS309Alert, "Show", GetShow, SetShow, VT_BOOL)
	DISP_PROPERTY_EX(CS309Alert, "Icon", GetIcon, SetIcon, VT_DISPATCH)
	DISP_FUNCTION(CS309Alert, "Add", MethodAdd, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309Alert, "Remove", MethodRemove, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CS309Alert, "Update", MethodUpdate, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IS309Alert to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {62F5D63B-92A7-4182-81F4-822D702EEFA6}
static const IID IID_IS309Alert =
{ 0x62f5d63b, 0x92a7, 0x4182, { 0x81, 0xf4, 0x82, 0x2d, 0x70, 0x2e, 0xef, 0xa6 } };

BEGIN_INTERFACE_MAP(CS309Alert, CWnd)
	INTERFACE_PART(CS309Alert, IID_IS309Alert, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS309Alert message handlers

BSTR CS309Alert::GetName() 
{
	CString strResult;
	strResult = m_strName;
	return strResult.AllocSysString();
}

void CS309Alert::SetName(LPCTSTR lpszNewValue) 
{
	m_strName = lpszNewValue;
}

VARIANT CS309Alert::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309Alert::SetTag(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);
	m_vTag.Clear();
	m_vTag.Attach(Var);
}

BSTR CS309Alert::GetHTML() 
{
	CString strResult;
	strResult = m_strHTML;
	return strResult.AllocSysString();
}

void CS309Alert::SetHTML(LPCTSTR lpszNewValue) 
{
	if (0 != m_strHTML.Compare(lpszNewValue))
	{
		m_strHTML = lpszNewValue;
#ifdef S309_HAVE_ALERTS
		m_dwUpdateMask |= SHNUM_HTML;
#endif // S309_HAVE_ALERTS
	}
}

long CS309Alert::GetDuration() 
{
#ifdef S309_HAVE_ALERTS
	return m_NotificationData.csDuration;
#else // S309_HAVE_ALERTS
	return 0;
#endif // S309_HAVE_ALERTS
}

void CS309Alert::SetDuration(long nNewValue) 
{
#ifdef S309_HAVE_ALERTS
	if (m_NotificationData.csDuration != (DWORD)nNewValue)
	{
		m_NotificationData.csDuration = nNewValue;
		m_dwUpdateMask |= SHNUM_DURATION;
	}
#endif // S309_HAVE_ALERTS
}

BSTR CS309Alert::GetTitle() 
{
	CString strResult;
	strResult = m_strTitle;
	return strResult.AllocSysString();
}

void CS309Alert::SetTitle(LPCTSTR lpszNewValue) 
{
	if (0 != m_strTitle.Compare(lpszNewValue))
	{
		m_strTitle = lpszNewValue;
#ifdef S309_HAVE_ALERTS
		m_dwUpdateMask |= SHNUM_TITLE;
#endif // S309_HAVE_ALERTS
	}
}

BOOL CS309Alert::GetStraightToTray() 
{
#ifdef S309_HAVE_ALERTS
	return (SHNF_STRAIGHTTOTRAY == (m_NotificationData.grfFlags & SHNF_STRAIGHTTOTRAY));
#else // S309_HAVE_ALERTS
	return FALSE;
#endif // S309_HAVE_ALERTS
}

void CS309Alert::SetStraightToTray(BOOL bNewValue) 
{
#ifdef S309_HAVE_ALERTS
	m_NotificationData.grfFlags &= (0xffffffff ^ SHNF_STRAIGHTTOTRAY);
	if (bNewValue)
	{
		m_NotificationData.grfFlags |= SHNF_STRAIGHTTOTRAY;
	}
#endif // S309_HAVE_ALERTS
}

BOOL CS309Alert::GetCritical() 
{
#ifdef S309_HAVE_ALERTS
	return (SHNF_CRITICAL == (m_NotificationData.grfFlags & SHNF_CRITICAL));
#else // S309_HAVE_ALERTS
	return FALSE;
#endif // S309_HAVE_ALERTS
}

void CS309Alert::SetCritical(BOOL bNewValue) 
{
#ifdef S309_HAVE_ALERTS
	m_NotificationData.grfFlags &= (0xffffffff ^ SHNF_CRITICAL);
	if (bNewValue)
	{
		m_NotificationData.grfFlags |= SHNF_CRITICAL;
	}
#endif // S309_HAVE_ALERTS
}

BOOL CS309Alert::GetForceMessage() 
{
#ifdef S309_HAVE_ALERTS
	return (SHNF_FORCEMESSAGE == (m_NotificationData.grfFlags & SHNF_FORCEMESSAGE));
#else // S309_HAVE_ALERTS
	return FALSE;
#endif // S309_HAVE_ALERTS
}

void CS309Alert::SetForceMessage(BOOL bNewValue) 
{
#ifdef S309_HAVE_ALERTS
	m_NotificationData.grfFlags &= (0xffffffff ^ SHNF_FORCEMESSAGE);
	if (bNewValue)
	{
		m_NotificationData.grfFlags |= SHNF_FORCEMESSAGE;
	}
#endif // S309_HAVE_ALERTS
}

BOOL CS309Alert::MethodAdd() 
{
#ifdef S309_HAVE_ALERTS
	if (NULL == this->GetSafeHwnd())
	{
		RECT rect;
		rect.left = 0;
		rect.top = 0;
		rect.right = 0;
		rect.bottom = 0;
		this->Create(TEXT("STATIC"), TEXT("CS309Alert"), WS_VISIBLE | WS_CHILD, rect, m_pTopParent, -1, NULL);
	}

	LRESULT lResult;

	if (!m_strHTML.IsEmpty())
	{
		m_NotificationData.hwndSink = this->GetSafeHwnd();
		m_NotificationData.pszHTML = m_strHTML;
		if (m_strTitle.IsEmpty())
		{
			m_NotificationData.pszTitle = NULL;
		}
		else
		{
			m_NotificationData.pszTitle = m_strTitle;
		}
		m_NotificationData.clsid = m_clsid;
		m_NotificationData.npPriority = SHNP_INFORM;
	} 
	else
	{
		m_NotificationData.hwndSink = NULL;
		m_NotificationData.pszHTML = NULL;
		m_NotificationData.pszTitle = NULL;
		memset(&m_NotificationData.clsid, 0, sizeof(CLSID));
		m_NotificationData.npPriority = SHNP_ICONIC;
	}

	m_NotificationData.hicon = NULL;
	if (NULL != m_pIcon)
	{
		m_NotificationData.hicon = m_pIcon->hIcon();
	}
	if (NULL == m_NotificationData.hicon) 
	{
		m_NotificationData.hicon = m_hTopParentIcon;
	}

	SHNotificationRemove(&m_clsid, m_NotificationData.dwID);
	lResult = SHNotificationAdd(&m_NotificationData);

	if (ERROR_SUCCESS == lResult)
	{
		m_dwUpdateMask = 0;
	}

	return (ERROR_SUCCESS == lResult);
#else // S309_HAVE_ALERTS
	return FALSE;
#endif // S309_HAVE_ALERTS
}

BOOL CS309Alert::MethodRemove() 
{
#ifdef S309_HAVE_ALERTS
	LRESULT lResult = SHNotificationRemove(&m_clsid, m_NotificationData.dwID);

	if (ERROR_SUCCESS == lResult)
	{
		m_dwUpdateMask = 0;
	}

	return (ERROR_SUCCESS == lResult);
#else // S309_HAVE_ALERTS
	return FALSE;
#endif // S309_HAVE_ALERTS
}

BOOL CS309Alert::OnCommand(WPARAM wParam, LPARAM lParam) 
{
#ifdef S309_HAVE_ALERTS
	if (NULL != m_pTopParent)
	{
		if (lParam == (LPARAM)m_NotificationData.dwID)
		{
			m_lCommand = LOWORD(wParam);
			m_pTopParent->SendMessage(WM_USER, 1, (LPARAM)this);
			return TRUE;
		}
	}
#endif // S309_HAVE_ALERTS
	return CWnd::OnCommand(wParam, lParam);
}

LRESULT CS309Alert::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
#ifdef S309_HAVE_ALERTS
	if (NULL != m_pTopParent)
	{
		NMSHN *nmshn;
		switch (message)
		{
			case WM_NOTIFY:
				nmshn = (NMSHN*)lParam;
				if (((LPARAM)this == nmshn->lParam) && (m_NotificationData.dwID == nmshn->hdr.idFrom))
				{
					CString strMessage;
					switch (nmshn->hdr.code)
					{
						case SHNN_LINKSEL:
							m_strLink = nmshn->pszLink;
							m_pTopParent->PostMessage(WM_USER, 2, (LPARAM)this);
							return TRUE;
							break;
						case SHNN_DISMISS:
							m_bTimeout = nmshn->fTimeout;
							m_pTopParent->PostMessage(WM_USER, 3, (LPARAM)this);
							return TRUE;
							break;
						case SHNN_SHOW:
							return m_pTopParent->SendMessage(WM_USER, 4, (LPARAM)this);
							break;
						default:
							break;
					}
				}
				break;
			default:
				break;
		}
	}
#endif // S309_HAVE_ALERTS
	return CWnd::WindowProc(message, wParam, lParam);
}

BOOL CS309Alert::GetShow() 
{
	return m_bShow;
}

void CS309Alert::SetShow(BOOL bNewValue) 
{
	m_bShow = bNewValue;
}

BOOL CS309Alert::MethodUpdate() 
{
#ifdef S309_HAVE_ALERTS
	if (NULL == this->GetSafeHwnd())
	{
		return FALSE;
	}

	HICON hTemp = NULL;
	m_dwUpdateMask &= (0xffffffff ^ SHNUM_ICON);
	if (NULL != m_pIcon)
	{
		hTemp = m_pIcon->hIcon();
	}
	if (NULL == hTemp) 
	{
		hTemp = m_hTopParentIcon;
	}
	if (m_NotificationData.hicon != hTemp)
	{
		m_dwUpdateMask |= SHNUM_ICON;
	}

	if (0 == m_dwUpdateMask)
	{
		return FALSE;
	}

	LRESULT lResult;

	if (!m_strHTML.IsEmpty())
	{
		m_NotificationData.hwndSink = this->GetSafeHwnd();
		m_NotificationData.pszHTML = m_strHTML;
		if (m_strTitle.IsEmpty())
		{
			m_NotificationData.pszTitle = NULL;
		}
		else
		{
			m_NotificationData.pszTitle = m_strTitle;
		}
		m_NotificationData.clsid = m_clsid;

		if (SHNP_INFORM != m_NotificationData.npPriority)
		{
			m_dwUpdateMask |= SHNUM_PRIORITY;
		}
		m_NotificationData.npPriority = SHNP_INFORM;
	} 
	else
	{
		m_NotificationData.hwndSink = NULL;
		m_NotificationData.pszHTML = NULL;
		m_NotificationData.pszTitle = NULL;
		memset(&m_NotificationData.clsid, 0, sizeof(CLSID));

		if (SHNP_ICONIC != m_NotificationData.npPriority)
		{
			m_dwUpdateMask |= SHNUM_PRIORITY;
		}
		m_NotificationData.npPriority = SHNP_ICONIC;
	}

	m_NotificationData.hicon = hTemp;

	lResult = SHNotificationUpdate(m_dwUpdateMask, &m_NotificationData);

	if (ERROR_SUCCESS == lResult)
	{
		m_dwUpdateMask = 0;
	}
	else
	{
		if (SHNUM_PRIORITY == (m_dwUpdateMask & SHNUM_PRIORITY))
		{
			m_dwUpdateMask &= (0xffffffff ^ SHNUM_PRIORITY);

			if (SHNP_INFORM == m_NotificationData.npPriority)
			{
				m_NotificationData.npPriority = SHNP_ICONIC;
			}
			else
			{
				m_NotificationData.npPriority = SHNP_INFORM;
			}
		}
	}

	return (ERROR_SUCCESS == lResult);
#else // S309_HAVE_ALERTS
	return FALSE;
#endif // S309_HAVE_ALERTS
}

LPDISPATCH CS309Alert::GetIcon() 
{
	if (NULL == m_pIcon)
	{
		return NULL;
	}
	else
	{
		return m_pIcon->GetIDispatch(TRUE);
	}
}

void CS309Alert::SetIcon(LPDISPATCH newValue) 
{
	if (NULL != newValue)
	{
#ifdef S309_HAVE_ALERTS
		LPDISPATCH lpDx = NULL;

		if (NULL != m_pIcon)
		{
			lpDx = m_pIcon->GetIDispatch(FALSE);
		}
		
		if (newValue != lpDx)
		{
			OLECHAR FAR* szMember = TEXT("This");
			DISPID dispid;
			DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};
			if (S_OK == newValue->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &dispid))
			{
				if (NULL != lpDx)
				{
					lpDx->Release();
					m_pIcon = NULL;
				}
				COleDispatchDriver dd;
				dd.AttachDispatch(newValue, FALSE);
				dd.GetProperty(dispid, VT_I4, &m_pIcon);
				dd.ReleaseDispatch();
				m_dwUpdateMask |= SHNUM_ICON;
			}
			else
			{
				newValue->Release();
			}
		}
		else
		{
			newValue->Release();
		}
#else // S309_HAVE_ALERTS
		newValue->Release();
#endif // S309_HAVE_ALERTS
	}
}
