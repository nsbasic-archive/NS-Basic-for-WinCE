// HEADER FILES INCLUDED
// These includes are given here only as an example
// Before compiling your project please review them and include here
// only the required ones.
// Different libraries (like MFC or Jaked-Objects) may have common
// project include file - it is a good idea to replace these headers with it.
//#include <stdafx.h>
// END OF HEADER FILES

#include "scpaggregateclnt.h"


SCPAGGREGATECLNT::SCPAGGREGATECLNT() {
    m_pScpAgg = NULL;
    HRESULT hr;
    hr = CoCreateInstance(CLSID_ScpAggregate,NULL,CLSCTX_INPROC_SERVER,IID_IScpAggregate,(void**)&m_pScpAgg);
    if (FAILED(hr)) {
        m_pScpAgg = NULL;
    }
    m_uCP = CP_ACP;
}
SCPAGGREGATECLNT::SCPAGGREGATECLNT(IScpAggregate* pScpHost) {
    m_pScpAgg = pScpHost;
    if (m_pScpAgg) m_pScpAgg->AddRef();
    m_uCP = CP_ACP;
}
SCPAGGREGATECLNT::~SCPAGGREGATECLNT() {
    if (m_pScpAgg) {
		Close();
		m_pScpAgg->Release();
	}
}
HRESULT			SCPAGGREGATECLNT::Detach(IScpAggregate** ppObj) {
	if (ppObj) {
		*ppObj = m_pScpAgg;
		if (*ppObj) (*ppObj)->AddRef();
	}
	if (m_pScpAgg) {
		m_pScpAgg->Release();
		m_pScpAgg = NULL;
	}
    return S_OK;
}

BOOL SCPAGGREGATECLNT::CreateInstance() {
    if (m_pScpAgg) return FALSE;
    HRESULT hr;
    hr = CoCreateInstance(CLSID_ScpAggregate,NULL,CLSCTX_INPROC_SERVER,IID_IScpAggregate,(void**)&m_pScpAgg);
    if (FAILED(hr)) {
        m_pScpAgg= NULL;
    }
    return (SUCCEEDED(hr));
}

BOOL            SCPAGGREGATECLNT::Success() {
    return (m_pScpAgg)?TRUE:FALSE;
}

int             SCPAGGREGATECLNT::Add(LPCTSTR szName,IDispatch* pDisp) {
        if (!szName || !pDisp) return 0;
        BSTR    bstrName = _PackInBSTR(szName,m_uCP);
        if (!bstrName) return 0;

        HRESULT hr;
        VARIANT varKey,varItem,varPlace;

        VariantInit(&varKey);
        VariantInit(&varItem);
        VariantInit(&varPlace);
        varKey.vt = VT_BSTR;
        varKey.bstrVal = bstrName;
        varItem.vt = VT_DISPATCH;
        varItem.pdispVal = pDisp;
        pDisp->AddRef();

        hr = m_pScpAgg->Add(varKey,varItem,&varPlace);

        VariantClear(&varKey);
        VariantClear(&varItem);
        int nPlace = (int)varPlace.lVal;
        VariantClear(&varPlace);

        if (hr != S_OK) return 0;
        return nPlace;
}
int             SCPAGGREGATECLNT::AddEx(LPCTSTR szName,IDispatch* pDisp, long lOptions) {
        if (!szName || !pDisp) return 0;
        BSTR    bstrName = _PackInBSTR(szName,m_uCP);
        if (!bstrName) return 0;

        HRESULT hr;
        VARIANT varKey,varItem,varPlace;

        VariantInit(&varKey);
        VariantInit(&varItem);
        VariantInit(&varPlace);
        varKey.vt = VT_BSTR;
        varKey.bstrVal = bstrName;
        varItem.vt = VT_DISPATCH;
        varItem.pdispVal = pDisp;
        pDisp->AddRef();

        hr = m_pScpAgg->AddEx(varKey,varItem,lOptions,&varPlace);
        
        VariantClear(&varKey);
        VariantClear(&varItem);
        int nPlace = (int)varPlace.lVal;
        VariantClear(&varPlace);

        if (hr != S_OK) return 0;
        return nPlace;
}
int             SCPAGGREGATECLNT::Count() {
    long    l;
    HRESULT hr = m_pScpAgg->get_Count(&l);
    if (!FAILED(hr)) return l;
    return -1;
}
IDispatch*      SCPAGGREGATECLNT::Item(LPCTSTR szName) {
    VARIANT     varIndex,varItem;

    if (!szName) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varItem);

    varIndex.vt = VT_BSTR;
    varIndex.bstrVal = _PackInBSTR(szName,m_uCP);

    if (!varIndex.bstrVal) return NULL;
    HRESULT hr = m_pScpAgg->get_Item(varIndex,&varItem);
    VariantClear(&varIndex);
    if (FAILED(hr)) {
        return NULL;
    } else {
        return varItem.pdispVal; // must be released
    }
}
IDispatch*      SCPAGGREGATECLNT::Item(int nIndex) {
    VARIANT     varIndex,varItem;

    if (nIndex < 1) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varItem);

    varIndex.vt = VT_I4;
    varIndex.lVal = (long)nIndex;

    HRESULT hr = m_pScpAgg->get_Item(varIndex,&varItem);
    VariantClear(&varIndex);
    if (FAILED(hr)) {
        return NULL;
    } else {
        return varItem.pdispVal; // must be released
    }
}
BOOL            SCPAGGREGATECLNT::Clear() {
    return (!FAILED(m_pScpAgg->Clear()));
}
BOOL            SCPAGGREGATECLNT::Remove(LPCTSTR szName) {
    VARIANT     varIndex,varResult;
    if (!szName) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varResult);

    varIndex.vt = VT_BSTR;
    varIndex.bstrVal = _PackInBSTR(szName,m_uCP);

    if (!varIndex.bstrVal) return NULL;
    HRESULT hr = m_pScpAgg->Remove(varIndex,&varResult);
    VariantClear(&varIndex);
    VariantClear(&varResult);
    if (hr == S_OK) return TRUE;
    return FALSE;
}
BOOL            SCPAGGREGATECLNT::Remove(int nIndex) {
    VARIANT     varIndex,varResult;
    if (nIndex < 1) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varResult);

    varIndex.vt = VT_I4;
    varIndex.lVal = (long)nIndex;

    HRESULT hr = m_pScpAgg->Remove(varIndex,&varResult);
    VariantClear(&varIndex);
    VariantClear(&varResult);
    if (hr == S_OK) return TRUE;
    return FALSE;
}

BOOL            SCPAGGREGATECLNT::AddEngine(LPCTSTR szName) {
    BSTR    bstrName;
    if (!szName) return FALSE;
    bstrName = _PackInBSTR(szName,m_uCP);
    if (!bstrName) return FALSE;
    VARIANT varResult;
    VariantInit(&varResult);

    HRESULT hr = m_pScpAgg->AddEngine(bstrName,&varResult);
    VariantClear(&varResult);
    SysFreeString(bstrName);
    return (hr == S_OK);
}

BOOL            SCPAGGREGATECLNT::AddCode(LPCTSTR szLanguage,LPCTSTR szCode) {
    BSTR    bstrCode;
    BSTR    bstrLang;
    if (!szCode || !szLanguage) return FALSE;
    bstrCode = _PackInBSTR(szCode,m_uCP);
    bstrLang = _PackInBSTR(szLanguage,m_uCP);
    if (!bstrCode) return FALSE;
    VARIANT varResult;
    VariantInit(&varResult);

    HRESULT hr = m_pScpAgg->AddText(bstrLang,bstrCode,&varResult);
    VariantClear(&varResult);
    SysFreeString(bstrCode);
    SysFreeString(bstrLang);
    return (hr == S_OK);    
}
BOOL            SCPAGGREGATECLNT::AddCodeEx(LPCTSTR szLanguage,LPCTSTR szCode,long lLine,long lContext) {
    BSTR    bstrCode;
    BSTR    bstrLang;
    if (!szCode || !szLanguage) return FALSE;
    bstrCode = _PackInBSTR(szCode,m_uCP);
    bstrLang = _PackInBSTR(szLanguage,m_uCP);
    if (!bstrCode) return FALSE;
    VARIANT_BOOL bResult;
    VARIANT vNothing;
    ::VariantInit(&vNothing);
    vNothing.vt = VT_ERROR;
    vNothing.scode = DISP_E_PARAMNOTFOUND;

    HRESULT hr = m_pScpAgg->AddTextEx(bstrLang,bstrCode,lLine,lContext,vNothing,&bResult);
    
    SysFreeString(bstrCode);
    SysFreeString(bstrLang);
    return (hr == S_OK);    
}
BOOL            SCPAGGREGATECLNT::Run(long lOrder) {
    VARIANT varResult;
    VariantInit(&varResult);
    HRESULT hr = m_pScpAgg->Run(lOrder,&varResult);
    VariantClear(&varResult);
    return (hr == S_OK);
}
BOOL            SCPAGGREGATECLNT::AddEventHandler(LPCTSTR szLanguage, LPCTSTR szItem,LPCTSTR szSubItem,LPCTSTR szEvent,LPCTSTR szCode) {
    BSTR    bstrCode;
    BSTR    bstrItem;
    BSTR    bstrEvent;
    BSTR    bstrSubItem;
    BSTR    bstrLang;
    if (!szCode || ! szItem || !szEvent || !szLanguage) return FALSE;
    bstrCode = _PackInBSTR(szCode,m_uCP);
    bstrItem = _PackInBSTR(szItem,m_uCP);
    bstrEvent = _PackInBSTR(szEvent,m_uCP);
    bstrSubItem = _PackInBSTR(szSubItem,m_uCP);
    bstrLang = _PackInBSTR(szLanguage,m_uCP);
    
    VARIANT varResult;
    VariantInit(&varResult);

    HRESULT hr = m_pScpAgg->AddEventHandler(bstrItem,bstrSubItem,bstrEvent,bstrCode,bstrLang,&varResult);
    VariantClear(&varResult);
    SysFreeString(bstrCode);
    SysFreeString(bstrItem);
    SysFreeString(bstrEvent);
    SysFreeString(bstrSubItem);
    SysFreeString(bstrLang);
    return (hr == S_OK);    
}
BOOL            SCPAGGREGATECLNT::Connect() {
    VARIANT varResult;
    VariantInit(&varResult);
    HRESULT hr = m_pScpAgg->Connect(&varResult);
    VariantClear(&varResult);
    return (hr == S_OK);
}
BOOL            SCPAGGREGATECLNT::Stop() {
    HRESULT hr = m_pScpAgg->Stop(); 
    return (hr == S_OK);
}
BOOL            SCPAGGREGATECLNT::Close() {
    return (!FAILED(m_pScpAgg->Close()));
}
IDispatch*      SCPAGGREGATECLNT::GetScriptDispatch(LPCTSTR szLanguage) {
    if (szLanguage) return NULL;
    VARIANT     vLang;
    ::VariantInit(&vLang);
    vLang.bstrVal = _PackInBSTR(szLanguage,m_uCP);
    vLang.vt = VT_BSTR;
    LPDISPATCH  pDisp;
    HRESULT hr = m_pScpAgg->get_script(vLang,&pDisp);
    ::VariantClear(&vLang);
    if (!FAILED(hr)) return pDisp; // must be released
    return NULL;
}
IDispatch*      SCPAGGREGATECLNT::GetScriptDispatch(int nEngine) {
    VARIANT     vLang;
    ::VariantInit(&vLang);
    vLang.lVal = (long)nEngine;
    vLang.vt = VT_I4;
    LPDISPATCH  pDisp;
    HRESULT hr = m_pScpAgg->get_script(vLang,&pDisp);
    ::VariantClear(&vLang);
    if (!FAILED(hr)) return pDisp; // must be released
    return NULL;
}

int             SCPAGGREGATECLNT::GetLastError(LPTSTR szBuff,int cChars) {
    BSTR    bstrError;
    HRESULT hr = m_pScpAgg->get_lastError(&bstrError);
    int     n;
    if (!szBuff) {
        if (FAILED(hr)) return 0;
        n = lstrlenW(bstrError);
        SysFreeString(bstrError);
        return n;
    } else {
        if (FAILED(hr)) {
            szBuff[0] = '\0';
            return 0;        
        }
        n = lstrlenW(bstrError);
        if (cChars <= n) {
            SysFreeString(bstrError);            
            szBuff[0] = '\0';
            return 0;
        }
        #ifdef UNICODE
            lstrcpy(szBuff,bstrError);
            SysFreeString(bstrError);
            return n + 1;
        #else
            ::WideCharToMultiByte(m_uCP,0,bstrError,-1,szBuff,cChars,NULL,NULL);
            SysFreeString(bstrError);
            return n + 1;
        #endif
    }
}
IDispatch*      SCPAGGREGATECLNT::GetSelfDispatch() {
    LPDISPATCH  pDisp = NULL;
    m_pScpAgg->QueryInterface(IID_IDispatch,(void**)&pDisp);
    return pDisp;
}
int             SCPAGGREGATECLNT::WhereIsDefined(LPCTSTR szName) {
    int n;
    HRESULT hr;
    VARIANT v,vResult;
    ::VariantInit(&v);
    ::VariantInit(&vResult);
    v.vt = VT_BSTR;
    v.bstrVal = _PackInBSTR(szName,m_uCP);
    hr = m_pScpAgg->WhereIsDefined(v,0,&vResult);
    ::VariantClear(&v);
    if (FAILED(hr)) {
        ::VariantClear(&vResult);
        SetErrorHost(-1);
        return -1;
    }
    hr = ::VariantChangeType(&v,&vResult,0,VT_I4);
    if (FAILED(hr)) {
        ::VariantClear(&vResult);
        SetErrorHost(-1);
        return -1;
    }
    n = vResult.lVal;
    ::VariantClear(&vResult);
    SetErrorHost(n);
    return n;
}
int             SCPAGGREGATECLNT::GetErrorHost() {
    long n;
    HRESULT hr = m_pScpAgg->get_errorHost(&n); 
    if (FAILED(hr)) return -1;
    return n;
}
void            SCPAGGREGATECLNT::SetErrorHost(int n) {
    m_pScpAgg->put_errorHost((long)n); 
}

#include <scphostclnt.cpp>
