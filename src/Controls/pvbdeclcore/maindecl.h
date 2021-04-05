#pragma once

////////////////////////////////////////////////////////////////////////////////////////////
// MainDecl.h
////////////////////////////////////////////////////////////////////////////////////////////
//
// Purpose:  Declare Forms extension
//
// Copyright (c)  Microsoft Corporation 1998
//
////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include <windows.h>
#include "project.h"
#include "utility.h"
#include "idldecl.h"
#include "pvbdecl.h"

extern VOID* g_pChunkBase;
extern HINSTANCE*	g_pHandleTable;
extern UINT		g_wHandles;

#include "arglist.h"

// CFuncParm:
// Wrapper class to store parameters converted for the string.  Tracks
//	allocated BSTRs and destroys on exit
class CFuncParm
{
public:
	CFuncParm() 	{ m_fBStr = FALSE; }
	~CFuncParm()	{ if (m_fBStr) SysFreeString((BSTR) m_dwValue); }

public:
	// Accessors
	void	SetValue(DWORD val)		{ m_dwValue = val; }
	DWORD	GetValue()				{ return m_dwValue; }
	void	SetFBStr(BOOL val)		{ m_fBStr = val; }
	BOOL	GetFBStr()				{ return m_fBStr; }

private:
	BOOL	m_fBStr;
	DWORD	m_dwValue;
};

// CDeclDispatchEntry:
//	Maps single Declare function instance.  Contains enough info
//	to handle Invoke from script
class CDeclDispatchEntry
{
public:
	CDeclDispatchEntry()	
		{
			m_szName = NULL;
			m_tableEntry = NULL;
			m_wLib = -1;
			m_pFunc = NULL;
			m_pFuncAddress = NULL;
		}
	~CDeclDispatchEntry()	
		{
		}

	// Accessors
	WCHAR*	GetName()		{ return m_szName; }

	// Implementation
	HRESULT	InvokeFunc(DISPPARAMS *pDispParams, VARIANT *pVarResult,
					   EXCEPINFO *pExcepInfo);
	HRESULT	Init(int wLib, DECL_FUNC* pFunc);
	HRESULT	ConvertArgs(DECL_TYPE* pDeclTypes, VARIANT* pVars, 
						UINT wCount, CFuncParm* pResults, EXCEPINFO *pExcepInfo);
	HRESULT StoreReturnValue(DWORD dwResult, VARIANT* pVarResult, 
							 DECL_TYPE dtReturn);

private:
	enum { INVALID_ADDRESS = 0xffffffff };

private:
	WCHAR*	m_szName;
	void*	m_tableEntry;
	int		m_wLib;
	DECL_FUNC*	m_pFunc;
	void*	m_pFuncAddress;
};

// CDeclDispatch
//	Container for CDeclDispatchEntry, implements IDispatch for
//	all declare items
class CDeclDispatch : public IDispatch
{
public:
	CDeclDispatch()
		{
			m_cRef = 1;
		}
	~CDeclDispatch()
		{
			UINT	j;
			
			for (j = 0; j < g_wHandles; j++) {
				// Shouldn't free if handle == INVALID_HANDLE
				if ((g_pHandleTable[j] != NULL) && (g_pHandleTable[j] != (HINSTANCE) INVALID_HANDLE))
					FreeLibrary(g_pHandleTable[j]);
			}
			delete [] g_pHandleTable;
			g_pHandleTable = NULL;
		}

	// Implementation
	HRESULT	InitData(BYTE *pFormChunk);
	HRESULT Init(IPVBFormsPackageSite* piFormSite);

private:

public:
	// COM interfaces
	
	// IUnknown
	STDMETHOD_(DWORD, AddRef)(void);
	STDMETHOD_(DWORD, Release)(void);
	STDMETHOD (QueryInterface)(REFIID riid, PVOID * ppv);

	// IDispatch interface
	STDMETHOD(GetTypeInfoCount)(unsigned int * pctinfo);
	STDMETHOD(GetTypeInfo)(unsigned int iTInfo, LCID lcid, ITypeInfo ** ppTInfo);
	STDMETHOD(GetIDsOfNames)(REFIID riid, OLECHAR ** rgszNames, unsigned int cNames, 
							 LCID lcid, DISPID FAR* rgDispId);
	STDMETHOD(Invoke)(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
					  DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo,
					  unsigned int * puArgErr);

protected:
	// COM Helper function
	long	FindName(WCHAR* name);
	
private:
	GrowablePointerArray<CDeclDispatchEntry>	m_declList;	
	int		m_cRef;
};

// CDeclPackage
//	Implements package interface.  Standard class which delagates most
//	interesting work to CDeclDispatch
class CDeclPackage : public IPVBFormsPackage, 
					 public CComObjectRoot,
					 public CComCoClass<CDeclPackage, &CLSID_PVBDeclarePackage>
{
public:
	CDeclPackage()
		{
			m_piFormSite = NULL;
			m_piDeclDispatch = NULL;
			m_cRef = 1;
		}
	~CDeclPackage()
		{
			if (m_piFormSite != NULL)
				m_piFormSite->Release();
			if (m_piDeclDispatch != NULL)
				m_piDeclDispatch->Release();
			delete [] g_pHandleTable;
		}
		
public:
	DECLARE_NO_REGISTRY()
	DECLARE_NOT_AGGREGATABLE(CDeclPackage)
	
	BEGIN_COM_MAP(CDeclPackage)
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
	CDeclDispatch*			m_piDeclDispatch;
	int		m_cRef;
};

