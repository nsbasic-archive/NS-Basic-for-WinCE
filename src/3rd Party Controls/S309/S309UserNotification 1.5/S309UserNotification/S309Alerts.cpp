// S309Alerts.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "S309Alerts.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS309Alerts

CS309Alerts::CS309Alerts()
{
	EnableAutomation();
	m_pTopParent = NULL;
	m_vTag.Clear();
}

CS309Alerts::~CS309Alerts()
{
	CS309Alert *pItem;
	while (m_AlertArray.GetSize() > 0)
	{
		pItem = m_AlertArray.GetAt(0);
		m_AlertArray.RemoveAt(0);
		LPDISPATCH lpDx = pItem->GetIDispatch(FALSE);
		if (0 != lpDx->Release())
		{
			pItem->m_pTopParent = NULL;
		}
	}
}

void CS309Alerts::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CS309Alerts, CWnd)
	//{{AFX_MSG_MAP(CS309Alerts)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CS309Alerts, CWnd)
	//{{AFX_DISPATCH_MAP(CS309Alerts)
	DISP_PROPERTY_EX(CS309Alerts, "Count", GetCount, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CS309Alerts, "Tag", GetTag, SetTag, VT_VARIANT)
	DISP_FUNCTION(CS309Alerts, "Remove", MethodRemove, VT_BOOL, VTS_VARIANT)
	DISP_FUNCTION(CS309Alerts, "Add", MethodAdd, VT_DISPATCH, VTS_BSTR)
	DISP_PROPERTY_PARAM(CS309Alerts, "Item", GetItem, SetNotSupported, VT_DISPATCH, VTS_VARIANT)
	DISP_DEFVALUE(CS309Alerts, "Item")
	//}}AFX_DISPATCH_MAP
	DISP_PROPERTY_EX_ID(CS309Alerts, "_NewEnum", DISPID_NEWENUM, _NewEnum, SetNotSupported, VT_UNKNOWN)
END_DISPATCH_MAP()

// Note: we add support for IID_IS309Alerts to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {64172A96-14B7-4A3F-9668-E016A9F8CBF2}
static const IID IID_IS309Alerts =
{ 0x64172a96, 0x14b7, 0x4a3f, { 0x96, 0x68, 0xe0, 0x16, 0xa9, 0xf8, 0xcb, 0xf2 } };

BEGIN_INTERFACE_MAP(CS309Alerts, CWnd)
	INTERFACE_PART(CS309Alerts, IID_IS309Alerts, Dispatch)
    INTERFACE_PART(CS309Alerts, IID_IEnumVARIANT, EnumVARIANT)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS309Alerts message handlers

CS309Alerts::XEnumVARIANT::XEnumVARIANT()
{    
	m_lCurrentPosition = -1;  
}

CS309Alerts::XEnumVARIANT::~XEnumVARIANT()
{    
}

STDMETHODIMP_(ULONG) CS309Alerts::XEnumVARIANT::AddRef()
{   
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)
    return pThis->ExternalAddRef() ;
}   

STDMETHODIMP_(ULONG) CS309Alerts::XEnumVARIANT::Release()
{   
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)
    return pThis->ExternalRelease() ;
}   

STDMETHODIMP CS309Alerts::XEnumVARIANT::QueryInterface( REFIID iid, void FAR* FAR* ppvObj )
{   
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)
    return (HRESULT)pThis->ExternalQueryInterface( (void FAR*)&iid, ppvObj) ;
}   

// IEnumVARIANT::Next
// 
STDMETHODIMP CS309Alerts::XEnumVARIANT::Next( ULONG celt, VARIANT FAR* rgvar, ULONG FAR* pceltFetched)
{
    // This sets up the "pThis" pointer so that it points to our
    // containing CS309Alerts instance
    //
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)

    HRESULT hr;
    ULONG   l ;
    CS309Alert *pItem = NULL ;

    // pceltFetched can legally == 0
    //                                           
    if (pceltFetched != NULL)
        *pceltFetched = 0;
    else if (celt > 1)
    {   
        return ResultFromScode( E_INVALIDARG ) ;   
    }

    for (l=0; l < celt; l++)
        VariantInit( &rgvar[l] ) ;

    // Retrieve the next celt elements.
    hr = NOERROR;

	if (-1 < m_lCurrentPosition)
	{
		for (l = 0; 0 < celt; l++)
		{   
			if (m_lCurrentPosition >= pThis->m_AlertArray.GetSize())
			{
				break;
			}
			pItem = pThis->m_AlertArray.GetAt(m_lCurrentPosition++);
			celt--;
			if (pItem)
			{
				rgvar[l].vt = VT_DISPATCH;
				rgvar[l].pdispVal = pItem->GetIDispatch(TRUE);
				if (pceltFetched != NULL)
					(*pceltFetched)++ ;
			}
			else 
				return ResultFromScode(E_UNEXPECTED);

		}
    }

    if (celt != 0)
       hr = ResultFromScode( S_FALSE ) ;

    return hr ;
}

STDMETHODIMP CS309Alerts::XEnumVARIANT::Skip(ULONG celt) 
{
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)

	m_lCurrentPosition += celt;

    return (m_lCurrentPosition < pThis->m_AlertArray.GetSize() ? NOERROR : ResultFromScode( S_FALSE )) ;
}

STDMETHODIMP CS309Alerts::XEnumVARIANT::Reset()
{
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)

	m_lCurrentPosition = 0;

    return NOERROR ;
}

STDMETHODIMP CS309Alerts::XEnumVARIANT::Clone(IEnumVARIANT FAR* FAR* ppenum) 
{
    METHOD_PROLOGUE(CS309Alerts, EnumVARIANT)   
    CS309Alerts *p = new CS309Alerts ;
    if (p)
    {
        p->m_xEnumVARIANT.m_lCurrentPosition = m_lCurrentPosition;
        return NOERROR ;    
    }
    else
        return ResultFromScode( E_OUTOFMEMORY ) ;
}

long CS309Alerts::GetCount() 
{
	return m_AlertArray.GetSize();
}

LPUNKNOWN CS309Alerts::_NewEnum() 
{
	m_xEnumVARIANT.Reset();
	return &m_xEnumVARIANT;
}

LPDISPATCH CS309Alerts::GetItem(const VARIANT FAR& ID) 
{
	LPDISPATCH lpDx = NULL;
	VARIANT vaResult;
	VariantInit(&vaResult);
	V_VT(&vaResult) = VT_DISPATCH;
	V_DISPATCH(&vaResult) = NULL;

	if (V_VT(&ID) != VT_ERROR)
	{
	    CS309Alert *pItem = NULL;

/*		if (VT_DISPATCH == (V_VT(&ID) & VT_DISPATCH))
		{
			LPDISPATCH lpDx = NULL;

			VARIANT varTemp;
			::VariantInit(&varTemp);
			if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(&ID), 0, VT_DISPATCH) == S_OK)
			{
				lpDx = V_DISPATCH(&varTemp);
			}
			::VariantClear(&varTemp);

			long lItem = FindDispatch(lpDx);

			if (-1 != lItem)
			{
				pItem = m_AlertArray.GetAt(lItem);
			}
		} */
		if (VT_BSTR == (V_VT(&ID) & VT_BSTR))
		{
			CString strID = TEXT("");

			VARIANT varTemp;
			::VariantInit(&varTemp);
			if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(&ID), 0, VT_BSTR) == S_OK)
			{
				strID = V_BSTR(&varTemp);
			}
			::VariantClear(&varTemp);

			CS309Alert *pItemSearch;

			if (!strID.IsEmpty())
			{
				for (long lIndex = 0; lIndex < m_AlertArray.GetSize(); lIndex++)
				{
					pItemSearch = m_AlertArray.GetAt(lIndex);
					if(0 == strID.CompareNoCase(pItemSearch->m_strName))
					{
						pItem = pItemSearch;
						break;
					}
				}
			}
		}
		else if (0 != (V_VT(&ID) & (VT_I1 | VT_I2 | VT_I4 | VT_R4 | VT_R8)))
		{
			long lID = 0;

			VARIANT varTemp;
			::VariantInit(&varTemp);
			if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(&ID), 0, VT_I4) == S_OK)
			{
				lID = V_I4(&varTemp);
			}
			::VariantClear(&varTemp);

			if ((lID > 0) && (lID <= m_AlertArray.GetSize()))
			{
				pItem = m_AlertArray.GetAt(lID - 1);
			}
		}

		if (pItem)
		{
			V_VT(&vaResult) = VT_DISPATCH;
			V_DISPATCH(&vaResult) = pItem->GetIDispatch(TRUE);

			lpDx = V_DISPATCH(&vaResult);
		}
	}

	return lpDx;
}
/*
long CS309Alerts::FindDispatch(LPDISPATCH pObject)
{
	CS309Alert *pItemSearch;

	if (NULL != pObject)
	{
		for (long lIndex = 0; lIndex < m_AlertArray.GetSize(); lIndex++)
		{
			pItemSearch = m_AlertArray.GetAt(lIndex);
			if (pObject == pItemSearch->GetIDispatch(FALSE))
			{
				return lIndex;
			}
		}
	} 

	return -1;
} */

BOOL CS309Alerts::MethodRemove(const VARIANT FAR& ID) 
{
	VARIANT vaResult;
	VariantInit(&vaResult);
	V_VT(&vaResult) = VT_DISPATCH;
	V_DISPATCH(&vaResult) = NULL;

	if (V_VT(&ID) != VT_ERROR)
	{
	    CS309Alert *pItem = NULL;

		if (VT_BSTR == (V_VT(&ID) & VT_BSTR))
		{
			CString strID = TEXT("");

			VARIANT varTemp;
			::VariantInit(&varTemp);
			if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(&ID), 0, VT_BSTR) == S_OK)
			{
				strID = V_BSTR(&varTemp);
			}
			::VariantClear(&varTemp);

			CS309Alert *pItemSearch;

			if (!strID.IsEmpty())
			{
				for (long lIndex = 0; lIndex < m_AlertArray.GetSize(); lIndex++)
				{
					pItemSearch = m_AlertArray.GetAt(lIndex);
					if(0 == strID.CompareNoCase(pItemSearch->m_strName))
					{
						m_AlertArray.RemoveAt(lIndex);
						LPDISPATCH lpDx = pItemSearch->GetIDispatch(FALSE);
						if (0 != lpDx->Release())
						{
							pItemSearch->m_pTopParent = NULL;
						}

						return TRUE;
					}
				}
			}
		}
		else if (0 != (V_VT(&ID) & (VT_I1 | VT_I2 | VT_I4 | VT_R4 | VT_R8)))
		{
			long lID = 0;

			VARIANT varTemp;
			::VariantInit(&varTemp);
			if (::VariantChangeType(&varTemp, const_cast <struct tagVARIANT *>(&ID), 0, VT_I4) == S_OK)
			{
				lID = V_I4(&varTemp);
			}
			::VariantClear(&varTemp);

			if ((lID > 0) && (lID <= m_AlertArray.GetSize()))
			{
				pItem = m_AlertArray.GetAt(lID - 1);
				m_AlertArray.RemoveAt(lID - 1);
				LPDISPATCH lpDx = pItem->GetIDispatch(FALSE);
				if (0 != lpDx->Release())
				{
					pItem->m_pTopParent= NULL;
				}

				return TRUE;
			}
		}
	}

	return FALSE;
}

LPDISPATCH CS309Alerts::MethodAdd(LPCTSTR Name) 
{
	CS309Alert *pItemSearch;
	CString strID = Name;
	if (strID.IsEmpty())
	{
		return NULL;
	}
	else
	{
		for (long lIndex = 0; lIndex < m_AlertArray.GetSize(); lIndex++)
		{
			pItemSearch = m_AlertArray.GetAt(lIndex);
			if(0 == strID.CompareNoCase(pItemSearch->m_strName))
			{
				return NULL;
			}
		}
	}

	pItemSearch = new CS309Alert;
	if (NULL != pItemSearch)
	{
		pItemSearch->m_strName = strID;
		pItemSearch->m_pTopParent = m_pTopParent;
		pItemSearch->m_hTopParentIcon = m_hTopParentIcon;
		m_AlertArray.Add(pItemSearch);

		return pItemSearch->GetIDispatch(TRUE);
	}

	return NULL;
}

VARIANT CS309Alerts::GetTag() 
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	VariantCopyInd( &vaResult, (LPVARIANT)m_vTag); 
	return vaResult;
}

void CS309Alerts::SetTag(const VARIANT FAR& newValue) 
{
	COleVariant Var = COleVariant(newValue);
	m_vTag.Clear();
	m_vTag.Attach(Var);
}
