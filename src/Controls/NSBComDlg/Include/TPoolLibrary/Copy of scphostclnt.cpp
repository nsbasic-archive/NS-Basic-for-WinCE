// HEADER FILES INCLUDED
// These includes are given here only as an example
// Before compiling your project please review them and include here
// only the required ones.
// Different libraries (like MFC or Jaked-Objects) may have common
// project include file - it is a good idea to replace these headers with it.
//#include <stdafx.h>
// END OF HEADER FILES

#include "scphostclnt.h"


SCPHOSTCLNT::SCPHOSTCLNT() {
    m_pScpMan = NULL;
    HRESULT hr;
    hr = CoCreateInstance(CLSID_ScpMan,NULL,CLSCTX_INPROC_SERVER,IID_IScpMan,(void**)&m_pScpMan);
    if (FAILED(hr)) {
        m_pScpMan = NULL;
    }
}
SCPHOSTCLNT::SCPHOSTCLNT(IScpMan* pScpHost) {
    m_pScpMan = pScpHost;
    if (m_pScpMan) m_pScpMan->AddRef();
}
SCPHOSTCLNT::~SCPHOSTCLNT() {
    Close();
    if (m_pScpMan) m_pScpMan->Release();
}
BOOL SCPHOSTCLNT::CreateInstance() {
    if (m_pScpMan) return FALSE;
    HRESULT hr;
    hr = CoCreateInstance(CLSID_ScpMan,NULL,CLSCTX_INPROC_SERVER,IID_IScpMan,(void**)&m_pScpMan);
    if (FAILED(hr)) {
        m_pScpMan = NULL;
    }
    return (SUCCEEDED(hr));
}

BOOL            SCPHOSTCLNT::Success() {
    return (m_pScpMan)?TRUE:FALSE;
}
int             SCPHOSTCLNT::Add(LPCTSTR szName,IDispatch* pDisp) {
        if (!szName || !pDisp) return 0;
        BSTR    bstrName = _PackInBSTR(szName);
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

        hr = m_pScpMan->Add(varKey,varItem,&varPlace);

        VariantClear(&varKey);
        VariantClear(&varItem);
        int nPlace = (int)varPlace.lVal;
        VariantClear(&varPlace);

        if (hr != S_OK) return 0;
        return nPlace;
}
int             SCPHOSTCLNT::Count() {
    long    l;
    HRESULT hr = m_pScpMan->get_Count(&l);
    if (!FAILED(hr)) return l;
    return -1;
}
IDispatch*      SCPHOSTCLNT::Item(LPCTSTR szName) {
    VARIANT     varIndex,varItem;

    if (!szName) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varItem);

    varIndex.vt = VT_BSTR;
    varIndex.bstrVal = _PackInBSTR(szName);

    if (!varIndex.bstrVal) return NULL;
    HRESULT hr = m_pScpMan->get_Item(varIndex,&varItem);
    VariantClear(&varIndex);
    if (FAILED(hr)) {
        return NULL;
    } else {
        return varItem.pdispVal; // must be released
    }
}
IDispatch*      SCPHOSTCLNT::Item(int nIndex) {
    VARIANT     varIndex,varItem;

    if (nIndex < 1) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varItem);

    varIndex.vt = VT_I4;
    varIndex.lVal = (long)nIndex;

    HRESULT hr = m_pScpMan->get_Item(varIndex,&varItem);
    VariantClear(&varIndex);
    if (FAILED(hr)) {
        return NULL;
    } else {
        return varItem.pdispVal; // must be released
    }
}
BOOL            SCPHOSTCLNT::Clear() {
    return (!FAILED(m_pScpMan->Clear()));
}
BOOL            SCPHOSTCLNT::Remove(LPCTSTR szName) {
    VARIANT     varIndex,varResult;
    if (!szName) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varResult);

    varIndex.vt = VT_BSTR;
    varIndex.bstrVal = _PackInBSTR(szName);

    if (!varIndex.bstrVal) return NULL;
    HRESULT hr = m_pScpMan->Remove(varIndex,&varResult);
    VariantClear(&varIndex);
    VariantClear(&varResult);
    if (hr == S_OK) return TRUE;
    return FALSE;
}
BOOL            SCPHOSTCLNT::Remove(int nIndex) {
    VARIANT     varIndex,varResult;
    if (nIndex < 1) return NULL;
    VariantInit(&varIndex); 
    VariantInit(&varResult);

    varIndex.vt = VT_I4;
    varIndex.lVal = (long)nIndex;

    HRESULT hr = m_pScpMan->Remove(varIndex,&varResult);
    VariantClear(&varIndex);
    VariantClear(&varResult);
    if (hr == S_OK) return TRUE;
    return FALSE;
}
BOOL            SCPHOSTCLNT::IsLocked() {
    BOOL    b;
    m_pScpMan->get_locked(&b);
    return b;
}
BOOL            SCPHOSTCLNT::LoadEngine(LPCTSTR szName) {
    BSTR    bstrName;
    if (!szName) return FALSE;
    bstrName = _PackInBSTR(szName);
    if (!bstrName) return FALSE;
    VARIANT varResult;
    VariantInit(&varResult);

    HRESULT hr = m_pScpMan->LoadEngine(bstrName,&varResult);
    VariantClear(&varResult);
    SysFreeString(bstrName);
    return (hr == S_OK);
}
BOOL            SCPHOSTCLNT::AddCode(LPCTSTR szCode) {
    BSTR    bstrCode;
    if (!szCode) return FALSE;
    bstrCode = _PackInBSTR(szCode);
    if (!bstrCode) return FALSE;
    VARIANT varResult;
    VariantInit(&varResult);

    HRESULT hr = m_pScpMan->AddText(bstrCode,&varResult);
    VariantClear(&varResult);
    SysFreeString(bstrCode);
    return (hr == S_OK);    
}
BOOL            SCPHOSTCLNT::Run() {
    VARIANT varResult;
    VariantInit(&varResult);
    HRESULT hr = m_pScpMan->Run(&varResult);
    VariantClear(&varResult);
    return (hr == S_OK);
}
BOOL            SCPHOSTCLNT::AddEventHandler(LPCTSTR szItem,LPCTSTR szSubItem,LPCTSTR szEvent,LPCTSTR szCode) {
    BSTR    bstrCode;
    BSTR    bstrItem;
    BSTR    bstrEvent;
    BSTR    bstrSubItem;
    if (!szCode || ! szItem || !szEvent) return FALSE;
    bstrCode = _PackInBSTR(szCode);
    bstrItem = _PackInBSTR(szItem);
    bstrEvent = _PackInBSTR(szEvent);
    bstrSubItem = _PackInBSTR(szSubItem);
    
    VARIANT varResult;
    VariantInit(&varResult);

    HRESULT hr = m_pScpMan->AddEventHandler(bstrItem,bstrSubItem,bstrEvent,bstrCode,&varResult);
    VariantClear(&varResult);
    SysFreeString(bstrCode);
    SysFreeString(bstrItem);
    SysFreeString(bstrEvent);
    SysFreeString(bstrSubItem);
    return (hr == S_OK);    
}
BOOL            SCPHOSTCLNT::Connect() {
    VARIANT varResult;
    VariantInit(&varResult);
    HRESULT hr = m_pScpMan->Connect(&varResult);
    VariantClear(&varResult);
    return (hr == S_OK);
}
BOOL            SCPHOSTCLNT::Stop() {
    HRESULT hr = m_pScpMan->Stop(); 
    return (hr == S_OK);
}
BOOL            SCPHOSTCLNT::Close() {
    return (!FAILED(m_pScpMan->Close()));
}
IDispatch*      SCPHOSTCLNT::GetScriptDispatch() {
    LPDISPATCH  pDisp;
    HRESULT hr = m_pScpMan->get_script(&pDisp);
    if (!FAILED(hr)) return pDisp; // must be released
    return NULL;
}
int             SCPHOSTCLNT::GetLastError(LPTSTR szBuff,int cChars) {
    BSTR    bstrError;
    HRESULT hr = m_pScpMan->get_lastError(&bstrError);
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
            WideCharToMultiByte(CP_ACP,0,bstrError,-1,szBuff,cChars,NULL,NULL);
            SysFreeString(bstrError);
            return n + 1;
        #endif
    }
}
IDispatch*      SCPHOSTCLNT::GetSelfDispatch() {
    LPDISPATCH  pDisp = NULL;
    m_pScpMan->QueryInterface(IID_IDispatch,(void**)&pDisp);
    return pDisp;
}

// Functions
BSTR    _PackInBSTR(LPCTSTR sz) {
    if (!sz) return NULL;
    #ifdef UNICODE
        return SysAllocString(sz);
    #else
        register i = lstrlen(sz) + 1;
        LPWSTR   _pwsz = new WCHAR[i];
        BSTR     bstr;
        if (!_pwsz) return NULL;
        if (MultiByteToWideChar(CP_ACP,0,sz,-1,_pwsz,i)) {
            bstr = SysAllocString((LPCOLESTR)_pwsz);
            delete [] _pwsz;
            return bstr;
        }
        return NULL;
    #endif
}

#include <automationhlp.cpp>