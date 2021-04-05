/*************************************************************************
 *
 * MainType.h
 *
 * Copyright (C) Microsoft Corporation 1997-1999
 * All rights reserved.
 *
 *************************************************************************
 *
 * Description: Type statement extension
 *
 *************************************************************************/

#pragma once

#include "stdafx.h"
#include "project.h"
#include "pvbtype.h"
#include "typeinfo.h"
#include "typevar.h"
#include "idldecl.h"

// CTypeDispatch
// 	 Contains all type info, implements chunk initialization functions,
//	 and implements CEStruct
class CTypeDispatch : public IDispatch
{
public:
	CTypeDispatch();
	~CTypeDispatch();

	// Implementation
	HRESULT	InitData(BYTE *pFormChunk);
	HRESULT Init(IPVBFormsPackageSite* piFormSite);
	CTypeInfo* GetTypeInfo(DECL_TYPE dtType);
	
	// COM interfaces
	// IUnknown
	STDMETHOD_(DWORD, AddRef)(void);
	STDMETHOD_(DWORD, Release)(void);
	STDMETHOD (QueryInterface)(REFIID riid, PVOID * ppv);

	// IDispatch
	STDMETHOD(GetTypeInfoCount)(unsigned int * pctinfo);
	STDMETHOD(GetTypeInfo)(unsigned int iTInfo, LCID lcid, ITypeInfo ** ppTInfo);
	STDMETHOD(GetIDsOfNames)(REFIID riid, OLECHAR ** rgszNames, unsigned int cNames, 
							 LCID lcid, DISPID FAR* rgDispId);
	STDMETHOD(Invoke)(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
					  DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo,
					  unsigned int * puArgErr);

private:
	IPVBFormsPackageSite* m_piFormSite;
	int m_cRef;
	unsigned int m_cTypes;
	CTypeInfo* m_pTypeInfo;
};

// CTypePackage
//	Implements package interface.  Standard class which delagates most
//	interesting work to CTypeDispatch
class CTypePackage : public IPVBFormsPackage, 
					 public CComObjectRoot,
					 public CComCoClass<CTypePackage, &CLSID_PVBTypePackage>
{
public:
	CTypePackage()
		{
			m_piFormSite = NULL;
			m_piTypeDispatch = NULL;
			m_cRef = 1;
		}
	~CTypePackage()
		{
			if (m_piFormSite != NULL)
				m_piFormSite->Release();
			if (m_piTypeDispatch != NULL)
				m_piTypeDispatch->Release();
		}
		
public:
	DECLARE_NO_REGISTRY()
	DECLARE_NOT_AGGREGATABLE(CTypePackage)
	
	BEGIN_COM_MAP(CTypePackage)
		COM_INTERFACE_ENTRY(IPVBFormsPackage)
	END_COM_MAP()

public:
	// COM interfaces
	
	// IPVBFormsPackage
	STDMETHOD(InitData)(BYTE *pFormChunk);
	STDMETHOD(Init)(IPVBFormsPackageSite *piFormSite, long pFunc);
	STDMETHOD(Startup)(BSTR StartFormName, BOOL *pfMsgTrans);
	STDMETHOD(FormTransAccel)(MSG *msg);
	STDMETHOD(GetFormInfo)(BSTR bstrName,unsigned long,struct IUnknown ** ,struct ITypeInfo **);
	STDMETHOD(ShowScriptError)(EXCEPINFO *excep);
	STDMETHOD(Exit)();
	STDMETHOD(ActivateStartupForm)(BSTR formName);
	STDMETHOD(GetActiveWindow)(HWND *pActiveWnd);
	
private:
	IPVBFormsPackageSite*	m_piFormSite;
	CTypeDispatch*			m_piTypeDispatch;
	int		m_cRef;
};
