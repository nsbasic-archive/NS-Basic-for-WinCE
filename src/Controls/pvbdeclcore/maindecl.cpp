////////////////////////////////////////////////////////////////////////////////////////////
// MainDecl.cpp
////////////////////////////////////////////////////////////////////////////////////////////
//
// Purpose:  Declare Forms extension
//
// Copyright (c)  Microsoft Corporation 1998
//
////////////////////////////////////////////////////////////////////////////////////////////

#include "maindecl.h"
#include "resdecl.h"
#include "vberror.h"

//*****************************************************************
// Note: InvokeFunc and all descendents must be thread-safe.
//*****************************************************************

//*****************************************************************
// Globals/Macros
//*****************************************************************

// Convert offset to Declare chunk to actual pointer
VOID*	g_pChunkBase = NULL;
#define CONVERT_OFFSET(offset, type)	(type)(offset + (DWORD)g_pChunkBase)

HINSTANCE*	g_pHandleTable = NULL;
UINT		g_wHandles = 0;

//*****************************************************************
// CDeclPackage implementation
//*****************************************************************

STDMETHODIMP CDeclPackage::InitData(BYTE *pFormChunk)
{
	HRESULT hr;

	g_pChunkBase = (VOID*) pFormChunk;
	m_piDeclDispatch = new CDeclDispatch();
	
	hr = m_piDeclDispatch->InitData(pFormChunk);
	if (!SUCCEEDED(hr)) {
		m_piDeclDispatch->Release();
		m_piDeclDispatch = NULL;
	}
		
	return hr;
}

STDMETHODIMP CDeclPackage::Init(IPVBFormsPackageSite *piFormSite, long pFunc)
{
	HRESULT hr;
	
	m_piFormSite = piFormSite;
	m_piFormSite->AddRef();
	hr = m_piDeclDispatch->Init(piFormSite);

	if (SUCCEEDED(hr)) {
		// Add script constants needed for declare statement
		WCHAR pszScriptConst[1024];
		EXCEPINFO	ei;

		if (LoadString(_Module.GetModuleInstance(), IDS_Constants, pszScriptConst, sizeof(pszScriptConst) / sizeof(WCHAR)) > 0)
			hr = m_piFormSite->AddScriptText(pszScriptConst, NULL, FALSE, &ei);
	}

	return hr;
}

STDMETHODIMP CDeclPackage::Startup(BSTR StartFormName, BOOL *fMsgTrans)
{
	*fMsgTrans = FALSE;
	return S_FALSE;
}

STDMETHODIMP CDeclPackage::FormTransAccel(MSG *msg)
{
	// This should never be called
	return E_NOTIMPL;
}


STDMETHODIMP CDeclPackage::GetFormInfo( BSTR bstrName, unsigned long dwReturnMask, IUnknown **ppunkItem ,ITypeInfo **pptiItem)
{
	return TYPE_E_ELEMENTNOTFOUND;
}

STDMETHODIMP CDeclPackage::ShowScriptError( EXCEPINFO *excep )
{
	return E_NOTIMPL;
}

STDMETHODIMP CDeclPackage::Exit()
{
	return S_OK;
}

STDMETHODIMP CDeclPackage::ActivateStartupForm(BSTR formName)
{
	return E_NOTIMPL;
}

STDMETHODIMP CDeclPackage::GetActiveWindow(HWND *pActiveWnd)
{
	// Always return NULL - let other package handle this
	*pActiveWnd = NULL;
	return S_OK;
}


//*****************************************************************
// CDeclDispatch implementation
//*****************************************************************

HRESULT	CDeclDispatch::InitData(BYTE *pChunkData)
{
	PVB_DECLARE_CHUNK*	pFormChunk = (PVB_DECLARE_CHUNK*) pChunkData;
	HRESULT hr = S_OK;
	
	// Validate form chunk
	if (pFormChunk->ulMagic != IMAGE_CEVB_MAGIC) {
		ShowResMsg(IDS_Err_InvalidFile, NULL, MB_OK);
		return DISP_E_EXCEPTION;
	}

	// Loop through modules, create entries
	DECL_MOD_LIST*	pModList = CONVERT_OFFSET(pFormChunk->odmlMods, DECL_MOD_LIST*);
	g_wHandles = pModList->cMods;
	g_pHandleTable = new HINSTANCE[g_wHandles];
	memset(g_pHandleTable, 0, g_wHandles * sizeof(HINSTANCE));
	
	for (UINT wModIndex = 0; wModIndex < g_wHandles; wModIndex++) {
		DECL_FUNC_LIST*	pFuncList = CONVERT_OFFSET(pModList->decl_mods[wModIndex].odflFuncs, DECL_FUNC_LIST*);
		
		// Create dispatch entry for each function
		for (UINT wFuncIndex = 0; wFuncIndex < pFuncList->cFuncs; wFuncIndex++) {
			CDeclDispatchEntry* pDispEntry = new CDeclDispatchEntry();
			DECL_FUNC*	pFunc = &(pFuncList->decl_funcs[wFuncIndex]);

			hr = pDispEntry->Init(wModIndex, pFunc);
			if (!SUCCEEDED(hr)) {
				delete pDispEntry;
				return hr;
			}
			
			// Add dispatch entry to list
			m_declList.AddElement(pDispEntry);
		}
	}

	return hr;
}

HRESULT CDeclDispatch::Init(IPVBFormsPackageSite* piFormSite)
{
	HRESULT	hr;
	
	hr = piFormSite->AddGlobalFunctions((IDispatch*) this);
	return hr;
}

//*****************************************************************
// CDeclDispatchEntry implementation
//*****************************************************************

HRESULT	CDeclDispatchEntry::Init(int wLib, DECL_FUNC* pFunc)
{
	m_szName = CONVERT_OFFSET(pFunc->oszName, WCHAR*);
	m_wLib = wLib;
	m_pFunc = pFunc;
	return S_OK;
}

HRESULT	CDeclDispatchEntry::InvokeFunc(DISPPARAMS *pDispParams, VARIANT *pVarResult, 
									   EXCEPINFO *pExcepInfo)
{
	HRESULT 	hr;
	HINSTANCE	hLib;
	DWORD		retVal;
	
	// Get library handle - if not loaded, attempt to load
	if ((UINT) m_wLib >= g_wHandles) {
		ShowResMsg(IDS_Err_General, pExcepInfo, MB_OK);
		return DISP_E_EXCEPTION;
	}

	if ((hLib = g_pHandleTable[m_wLib]) == NULL) {
		PVB_DECLARE_CHUNK*	pDeclare = (PVB_DECLARE_CHUNK*) g_pChunkBase;
		DECL_MOD_LIST* 	pModList  = CONVERT_OFFSET(pDeclare->odmlMods, DECL_MOD_LIST*);
		WCHAR*	szLibName = CONVERT_OFFSET(pModList->decl_mods[m_wLib].oszLibName, WCHAR*); 
		
		// Attempt to load library
		hLib = LoadLibrary(szLibName);
		if (hLib == NULL) {
			// Unable to load library - no need to try again this session
			ShowResMsg(IDS_Err_LoadLibrary, pExcepInfo, MB_OK, szLibName, m_szName);
			g_pHandleTable[m_wLib] = (HINSTANCE) INVALID_HANDLE;
			return DISP_E_EXCEPTION;
		}
		else
			g_pHandleTable[m_wLib] = hLib;
	}
	if (hLib == (HINSTANCE) INVALID_HANDLE)
		return E_INVALID_PROCEDURE_CALL;

	// Load entry point from library
	if (m_pFuncAddress == NULL) {
		WCHAR*	szFuncName;
		DWORD	dwOrdinal;
		BOOL	fOrdinal = FALSE;
	
		// Attempt to load from alias first
		if (m_pFunc->oszAlias != NULL_OFFSET) {
			szFuncName = CONVERT_OFFSET(m_pFunc->oszAlias, WCHAR*);

			if (szFuncName[0] == '#') {
				// Must do copy mem - not sure that alignment is on DWORD boundary
				memcpy(&dwOrdinal, szFuncName + 1, sizeof(DWORD));
				fOrdinal = TRUE;
			}
		}
		else
			szFuncName = CONVERT_OFFSET(m_pFunc->oszName, WCHAR*);

		if (!fOrdinal)
			m_pFuncAddress = GetProcAddress(hLib, szFuncName);
		else
			m_pFuncAddress = GetProcAddress(hLib, (WCHAR*)dwOrdinal);

		if (m_pFuncAddress == NULL) {
			ShowResMsg(IDS_Err_LoadFunction, pExcepInfo, MB_OK, m_szName);
			m_pFuncAddress = (VOID*) INVALID_ADDRESS;
			return DISP_E_EXCEPTION;
		}
	}

	// Exit without raising script error if function invalid
	if (m_pFuncAddress == (void*) INVALID_ADDRESS)
		return E_INVALID_PROCEDURE_CALL;

	// Validate number of args
	DECL_LIST	nullDeclList;
	DECL_LIST*	pDeclList = CONVERT_OFFSET(m_pFunc->odtlParams, DECL_LIST*);

	// If no decl list, point to 0 length list
	if (m_pFunc->odtlParams == NULL_OFFSET) {
		pDeclList = &nullDeclList;
		pDeclList->cDecl = 0;
	}

	// Verify # args correct
	if (pDispParams->cArgs != pDeclList->cDecl) {
		ShowResMsg(IDS_Err_WrongNumberArgs, pExcepInfo, MB_OK, m_szName, pDeclList->cDecl, pDispParams->cArgs);
		return DISP_E_EXCEPTION;
	}

	// Convert args into pResults table
	CFuncParm	pResults[MAX_ARGS];

	if (pDispParams->cArgs > MAX_ARGS) {
		ShowResMsg(IDS_Err_TooManyArgs, pExcepInfo, MB_OK, m_szName);
		return DISP_E_EXCEPTION;
	}
	

	hr = ConvertArgs(&(pDeclList->decl_types[0]), pDispParams->rgvarg, pDispParams->cArgs, pResults, pExcepInfo);

// There are a bunch of macros not included here to deal the different number of arguments that functions can have
	if (SUCCEEDED(hr)) {
		switch (pDispParams->cArgs) {

			case x :	\
				retVal = ((FUNC_ARG##x*) m_pFuncAddress)(ARGLIST_##x);	\
				break;	\
// End of calling the function
			default:
				// Too many arguments
				ShowResMsg(IDS_Err_TooManyArgs, pExcepInfo, MB_OK, m_szName);
				return DISP_E_EXCEPTION;
		}

		// Map return value
		hr = StoreReturnValue(retVal, pVarResult, m_pFunc->dtReturnType);
	}

	return hr;
}

HRESULT	CDeclDispatchEntry::ConvertArgs(DECL_TYPE* pDeclTypes, VARIANT* pVars, 
										UINT wCount, CFuncParm* pResults, EXCEPINFO *pExcepInfo)
{
	UINT	j;
	HRESULT hr = S_OK;

	for (j = 0; j < wCount; j++) {
		DECL_TYPE	dType = pDeclTypes[j];
		VARIANT*	vtSrc = &(pVars[wCount - j - 1]);
		VARTYPE	vtDest;

		// If variant is BYREF to a variant, unfold and get inner variant
		if (V_VT(vtSrc) == (VT_BYREF | VT_VARIANT))
			vtSrc = V_VARIANTREF(vtSrc);

		// Perform special case check for NULL pointer.
		if ((V_VT(vtSrc) == VT_I4) && (dType & DECL_BYREF) && 
			(V_I4(vtSrc) == NULL_STRING_VAL)) {
			// Pass 0 and continue.  Nothing to clean up yet.
			pResults[j].SetValue(0);
			continue;
		}
		
		// We have two cases - if passing to DLL function byref, we
		//  want to change the source variant in place and then call
		//	the function with the proper value
		//
		// If this is not byref, we can just convert into a temporary 
		//  variant and pass on
		switch (dType & ~DECL_BYREF) {
			case DECL_INTEGER :
				vtDest = VT_I2;
				break;
			case DECL_LONG :
				vtDest = VT_I4;
				break;
			case DECL_BYTE :
				vtDest = VT_UI1;
				break;
			case DECL_BOOLEAN :
				vtDest = VT_BOOL;
				break;
			case DECL_STRING :
				vtDest = VT_BSTR;
				break;
			case DECL_VARIANT :
				vtDest = VT_VARIANT;
				break;

			// These types are unsupported
			case DECL_SINGLE :
			case DECL_DOUBLE :
			case DECL_OBJECT :
			case DECL_CURRENCY :
			case DECL_DATE :
				ShowResMsg(IDS_Err_UnsupportedTypes, pExcepInfo, MB_OK, m_szName);
				return DISP_E_EXCEPTION;
				
		 	default :
				// Check if DECL_TYPE is user defined type and ByRef
				if ((dType & DECL_BYREF) && (dType & ~DECL_BYREF) >= DECL_MINTYPE) {
					dType &= ~DECL_BYREF;
					vtDest = VT_DISPATCH;
					break;
				}
		 		ShowResMsg(IDS_Err_InvalidFile, pExcepInfo, MB_OK);
			 	return DISP_E_EXCEPTION;
		}
		if ((dType & ~DECL_BYREF) >= DECL_MINTYPE) {
			if (vtDest != V_VT(vtSrc)) {
				hr = VariantChangeType(vtSrc, vtSrc, 0, vtDest);
				if (FAILED(hr)) {
					ShowResMsg(IDS_Err_NotTypeVariable, pExcepInfo, MB_OK, j + 1);
					return DISP_E_EXCEPTION;
				}
			}
			ASSERT(V_VT(vtSrc) == VT_DISPATCH);
			// Get Type interface
			CComPtr<IPVBType> piPVBType;
			hr = vtSrc->pdispVal->QueryInterface(IID_IPVBType, (void **)&piPVBType);
			if (FAILED(hr)) {
				ShowResMsg(IDS_Err_NotTypeVariable, pExcepInfo, MB_OK, j + 1);
				return DISP_E_EXCEPTION;
			}
			// ensure that this object is the correct type
			if (dType != piPVBType->GetTypeIndex()+DECL_MINTYPE) {
				ShowResMsg(IDS_Err_NotTypeVariable, pExcepInfo, MB_OK, j + 1);
				return DISP_E_EXCEPTION;
			}

			// Get pointer to structure
			pResults[j].SetValue((DWORD) piPVBType->GetStructPointer());
			piPVBType.Release();
		} else if ((dType & DECL_BYREF) || (vtDest == VT_BSTR)) {
			// Special handling for variants
			if (vtDest == VT_VARIANT) {
				pResults[j].SetValue((DWORD) vtSrc);
			}
			else {
				// Change type of source variable, store pointer to address of value
				// If type is same, don't perform conversion
				if (vtDest != V_VT(vtSrc)) {
					hr = VariantChangeType(vtSrc, vtSrc, 0, vtDest);
					if (FAILED(hr)) {
						ShowResMsg(IDS_Err_ParamConversion, pExcepInfo, MB_OK, j + 1, m_szName);
						return DISP_E_EXCEPTION;
					}
				}

				// Utilize known fact that variant is stored in union and offset of 
				//	data is the same regardless of the type
				if (dType & DECL_BYREF)
					pResults[j].SetValue((DWORD) &(V_UI4(vtSrc)));
				else
					pResults[j].SetValue(V_UI4(vtSrc));
			}
		}
		else {
			VARIANT	vrDest;
			V_VT(&vrDest) = VT_EMPTY;

			hr = VariantChangeType(&vrDest, vtSrc, 0, vtDest);
			if (FAILED(hr)) {
				ShowResMsg(IDS_Err_ParamConversion, pExcepInfo, MB_OK, j + 1, m_szName);
				return DISP_E_EXCEPTION;
			}
			
			pResults[j].SetValue(V_UI4(&vrDest));
			// If we copied a BSTR variant, mark for deletion
			if (vtDest == VT_BSTR)
				pResults[j].SetFBStr(TRUE);
		}
	}
	
	return hr;
}

HRESULT CDeclDispatchEntry::StoreReturnValue(DWORD dwResult, VARIANT* pVarResult, DECL_TYPE dtReturn)
{ 
	// Create a return variant, let OleAut map variant into proper type
	VARIANT	vrDest;
	HRESULT hr = S_OK;

	// If caller doesn't want return value, just exit
	if (pVarResult == NULL)
		return S_OK;
		
	// The desktop should disallow this
	ASSERT(dtReturn & ~DECL_BYREF);

	// Copy return value into temporary variant
	switch (dtReturn) {
		case DECL_INTEGER :
			V_VT(&vrDest) = VT_I2;
			V_I2(&vrDest) = (short) dwResult;
			break;
			
		case DECL_BOOLEAN :
			V_VT(&vrDest) = VT_BOOL;
			V_I2(&vrDest) = dwResult ? VARIANT_TRUE : VARIANT_FALSE;
			break;
			
		case DECL_LONG :
			V_VT(&vrDest) = VT_I4;
			V_I4(&vrDest) = (long) dwResult;
			break;
		
		case DECL_BYTE :
			V_VT(&vrDest) = VT_UI1;
			V_UI1(&vrDest) = (unsigned char) dwResult;
			break;
			
		case DECL_STRING :
			V_VT(&vrDest) = VT_BSTR;
			V_BSTR(&vrDest) = SysAllocString((BSTR) dwResult);
			break;
			
		case DECL_VARIANT :
			V_VT(&vrDest) = VT_VARIANT | VT_BYREF;
			V_I2(&vrDest) = (short) dwResult;
			break;
			
		case DECL_CURRENCY :
		case DECL_SINGLE :
		case DECL_DOUBLE :
		case DECL_DATE :
		case DECL_OBJECT :
		default :
			// Error - these types are not supported
			ASSERT(1);
			V_VT(&vrDest) = VT_EMPTY;
			goto ReturnDone;
	}

	// Store variant in result
	hr = VariantCopy(pVarResult, &vrDest);

ReturnDone:
	VariantClear(&vrDest);
	return hr; 
}


//*****************************************************************
// COM interface implementations
//*****************************************************************

// IUnknown
DWORD	CDeclDispatch::AddRef(void)
{
	return ++m_cRef;
}

DWORD	CDeclDispatch::Release(void)
{
	if (--m_cRef == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

HRESULT CDeclDispatch::QueryInterface(REFIID riid, PVOID *ppv)
{
	if ((riid == IID_IDispatch) || (riid == IID_IUnknown)) {
		*ppv = this;
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

// IDispatch interface
HRESULT CDeclDispatch::GetTypeInfoCount(UINT *pctinfo)
{
	*pctinfo = 0;
	return S_OK;
}

HRESULT CDeclDispatch::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo ** ppTInfo)
{
	if (ppTInfo == NULL)
		return E_INVALIDARG;

	*ppTInfo = NULL;
	return E_NOTIMPL;
}

HRESULT CDeclDispatch::GetIDsOfNames(REFIID riid, OLECHAR ** rgszNames, UINT cNames, 
						 LCID lcid, DISPID FAR* rgDispId)
{
	UINT		j;
	HRESULT	hr = S_OK;

	for (j = 0; j < cNames; j++) {
		long id = FindName(rgszNames[j]);

		rgDispId[j] = (DISPID) id;
		if (id < 0)
			hr = DISP_E_UNKNOWNNAME;
	}

	return hr;
}

HRESULT CDeclDispatch::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
				  DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo,
				  unsigned int * puArgErr)
{
	CDeclDispatchEntry	*pEntry;

	if ((dispIdMember < 0) || (dispIdMember > m_declList.GetSize()))
		return E_INVALID_PROCEDURE_CALL;

	pEntry = m_declList.ElementAt(dispIdMember);
	return pEntry->InvokeFunc(pDispParams, pVarResult, pExcepInfo);
}

long	CDeclDispatch::FindName(WCHAR* name)
{
	int j;

	for (j = 0; j < m_declList.GetSize(); j++)
		if (_tcsicmp(name, m_declList.ElementAt(j)->GetName()) == 0)
			return j;

	return DISPID_UNKNOWN;
}


