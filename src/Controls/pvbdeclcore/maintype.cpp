/*************************************************************************
 *
 * MainType.cpp
 *
 * Copyright (C) Microsoft Corporation 1997-1999
 * All rights reserved.
 *
 *************************************************************************
 *
 * Description: Type statement extension
 *
 *************************************************************************/

#include "maintype.h"
#include "resdecl.h"

static const LPCWSTR g_wszStructFunc = L"CESTRUCT";
static const DISPID g_dispidStructFunc = 1;

// CTypeDispatch implementation
CTypeDispatch::CTypeDispatch()
{
	m_cRef = 1;
	m_pTypeInfo = NULL;
	m_piFormSite = NULL;
}

CTypeDispatch::~CTypeDispatch()
{
	if (NULL != m_piFormSite)
		m_piFormSite->Release();
	if (NULL != m_pTypeInfo)
		delete[] m_pTypeInfo;
}

HRESULT CTypeDispatch::InitData(BYTE *pChunkData)
{
	PVB_TYPE_CHUNK* pTypeChunk = (PVB_TYPE_CHUNK*) pChunkData;
	HRESULT hr = S_OK;
	TYPE_INFO *pti;
	unsigned int i;

	// Validate form chunk
	if (pTypeChunk->ulMagic != IMAGE_CEVB_MAGIC) {
		ShowResMsg(IDS_Err_InvalidTypeChunk, NULL, MB_OK);
		return DISP_E_EXCEPTION;
	}
	
	m_cTypes = pTypeChunk->cTypes;

	if (0 == m_cTypes) {
		ShowResMsg(IDS_Err_InvalidTypeChunk, NULL, MB_OK);
		return DISP_E_EXCEPTION;
	}
	m_pTypeInfo = new CTypeInfo[m_cTypes];
	pti = (TYPE_INFO *)(((BYTE *)pTypeChunk) + pTypeChunk->otlTypes);
	DEBUGMSG(1, (L"Number of user defined types: %d\n", m_cTypes));
	for (i=0; i<m_cTypes; i++) {
		DEBUGMSG(1, (L"Initializing type %d\n", i));
		hr = m_pTypeInfo[i].Init(pti, (BYTE *)pTypeChunk, (DWORD) i);
		if FAILED(hr) {
			ShowResMsg(IDS_Err_InvalidTypeChunk, NULL, MB_OK);
			return DISP_E_EXCEPTION;
		}
		pti = (TYPE_INFO*) (((BYTE*)pti) + sizeof(TYPE_INFO) + (pti->cElements-1)*sizeof(TYPE_ELEMENT));
	}
	return hr;
}

HRESULT CTypeDispatch::Init(IPVBFormsPackageSite* piFormSite)
{
	HRESULT hr;

	m_piFormSite = piFormSite;
	m_piFormSite->AddRef();
	hr = m_piFormSite->AddGlobalFunctions((IDispatch*) this);
	return hr;
}

CTypeInfo* CTypeDispatch::GetTypeInfo(DECL_TYPE dtType)
{
	ASSERT(dtType >= DECL_MINTYPE && dtType - DECL_MINTYPE < m_cTypes);
	return &(m_pTypeInfo[dtType - DECL_MINTYPE]);
}

// IUnknown implementation
DWORD CTypeDispatch::AddRef(void)
{
	return ++m_cRef;
}

DWORD CTypeDispatch::Release(void)
{
	if (0 == --m_cRef) {
		delete this;
		return 0;
	}
	return m_cRef;
}

HRESULT CTypeDispatch::QueryInterface(REFIID riid, PVOID *ppv)
{
	if ((riid == IID_IDispatch) || (riid == IID_IUnknown)) {
		*ppv = this;
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

// IDispatch implementation
HRESULT CTypeDispatch::GetTypeInfoCount(UINT *pctinfo)
{
	*pctinfo = 0;
	return S_OK;
}

HRESULT CTypeDispatch::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo ** ppTInfo)
{
	if (ppTInfo == NULL)
		return E_INVALIDARG;

	*ppTInfo = NULL;
	return E_NOTIMPL;
}

HRESULT CTypeDispatch::GetIDsOfNames(REFIID riid, OLECHAR ** rgszNames, UINT cNames, 
					 LCID lcid, DISPID FAR* rgDispId)
{
	HRESULT hr = S_OK;
	UINT i;
	LPWSTR wszName;

	if (IID_NULL != riid)
		return DISP_E_UNKNOWNINTERFACE;

	if (0 == cNames)
		return S_OK;

	wszName = _wcsdup(rgszNames[0]);
	if (NULL == wszName)
		return E_OUTOFMEMORY;
	_wcsupr(wszName);
	if (0 == wcscmp(wszName, g_wszStructFunc))
		rgDispId[0] = g_dispidStructFunc;
	else {
		rgDispId[0] = DISPID_UNKNOWN;
		hr = DISP_E_UNKNOWNNAME;
	}
	free(wszName);				

	if (cNames > 1)	 {	// should only be one
		hr = DISP_E_UNKNOWNNAME;	
		for (i=1; i<cNames; i++)
			rgDispId[1] = DISPID_UNKNOWN;
	}

	return hr;
}

// The only function you can invoke on this object is to create a 
// structure.
HRESULT CTypeDispatch::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
				  DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo,
				  unsigned int * puArgErr)
{
	HRESULT hr = S_OK;
	VARIANT var;
	pExcepInfo = NULL;
	if (IID_NULL != riid)
		return DISP_E_UNKNOWNINTERFACE;

	if (wFlags & DISPATCH_METHOD) {
		if (dispIdMember != g_dispidStructFunc)
			return DISP_E_MEMBERNOTFOUND;
		if (pDispParams->cArgs != 1)
			return DISP_E_BADPARAMCOUNT;
		VariantInit(&var);
		hr = VariantChangeType(&var, pDispParams->rgvarg, 0,
			VT_I4);
		if (FAILED(hr)) {
			ASSERT(E_INVALIDARG != hr && DISP_E_BADVARTYPE != hr);
			if (DISP_E_OVERFLOW == hr)
				hr = DISP_E_TYPEMISMATCH;
		}
		if (var.lVal < 0 || var.lVal >= (int) m_cTypes)
            return E_UNEXPECTED;  // this should never happen unless the
                                  // .vb file is fubar

        VariantInit(pVarResult);
        pVarResult->vt = VT_DISPATCH;
        this->AddRef();
        CTypeVar *ptv = new CTypeVar(this, &(m_pTypeInfo[var.lVal]));
        hr = ptv->Init(NULL);
        if (FAILED(hr)) {
            ptv->Release();
            return hr;
        }
        pVarResult->pdispVal = static_cast<IDispatch*>(ptv);
        return hr;
    }
    return DISP_E_MEMBERNOTFOUND;
}

//*****************************************************************
// CTypePackage implementation
//*****************************************************************

STDMETHODIMP CTypePackage::InitData(BYTE *pFormChunk)
{
	HRESULT hr;

	m_piTypeDispatch = new CTypeDispatch();
	
	hr = m_piTypeDispatch->InitData(pFormChunk);
	if (!SUCCEEDED(hr)) {
		m_piTypeDispatch->Release();
		m_piTypeDispatch = NULL;
	}

	return hr;
}

STDMETHODIMP CTypePackage::Init(IPVBFormsPackageSite *piFormSite, long pFunc)
{
	HRESULT hr;
	
	m_piFormSite = piFormSite;
	m_piFormSite->AddRef();
	hr = m_piTypeDispatch->Init(piFormSite);

	return hr;
}

STDMETHODIMP CTypePackage::Startup(BSTR StartFormName, BOOL *fMsgTrans)
{
	*fMsgTrans = FALSE;
	return S_FALSE;
}

STDMETHODIMP CTypePackage::FormTransAccel(MSG *msg)
{
	// This should never be called
	return E_NOTIMPL;
}


STDMETHODIMP CTypePackage::GetFormInfo( BSTR bstrName, unsigned long dwReturnMask, IUnknown **ppunkItem ,ITypeInfo **pptiItem)
{
	return TYPE_E_ELEMENTNOTFOUND;
}

STDMETHODIMP CTypePackage::ShowScriptError( EXCEPINFO *excep )
{
	return E_NOTIMPL;
}

STDMETHODIMP CTypePackage::Exit()
{
	return S_OK;
}

STDMETHODIMP CTypePackage::ActivateStartupForm(BSTR formName)
{
	return E_NOTIMPL;
}

STDMETHODIMP CTypePackage::GetActiveWindow(HWND *pActiveWnd)
{
	// Always return NULL - let other package handle this
	*pActiveWnd = NULL;
	return S_OK;
}

