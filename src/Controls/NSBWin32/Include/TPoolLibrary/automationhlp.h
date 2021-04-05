#ifndef _AUTOMATIONHLP_H_
#define _AUTOMATIONHLP_H_

#pragma message("Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp")

BSTR    _PackInBSTR(LPCTSTR sz,UINT uCP = CP_ACP);
BSTR    _PackInBSTRA(LPCSTR sz,UINT uCP = CP_ACP);
// The bstr is not freed by the routines below
// The returned result must be freed using delete []
LPSTR   _UnPackBSTRA(BSTR bstr,UINT uCP = CP_ACP);
LPTSTR   _UnPackBSTR(BSTR bstr,UINT uCP = CP_ACP);

// Tries to extract the a value from the variant passing through the chain
// og objects and default values
HRESULT VariantResolveToValue(VARIANT* pvarDest,VARIANT* pvarSrc);

#ifdef  TPOOLLIBRARY_PACKEDCOMTYPES
    #include "automationhlp-typepackers.h"
#endif  // TPOOLLIBRARY_PACKEDCOMTYPES


// Note about the parameters of the constructor
// if bAddReff is FALSE - no AddRef will be called
// on the IDispatch packed here. It is useful if the
// object was initialized from the IDispatch pointer
// returned from another function
class DISPCALLER {
    LPDISPATCH          m_pDisp;
    SAFEARRAY*			m_psaParameters;
public:
    DISPCALLER(DISPCALLER& dc) {
        m_psaParameters = NULL;
        m_pDisp = dc.m_pDisp;
        if (m_pDisp) m_pDisp->AddRef();
    }
    DISPCALLER(LPDISPATCH pDisp,BOOL bAddRef = FALSE) {
        m_pDisp = pDisp;
        m_psaParameters = NULL;
        if (bAddRef && m_pDisp) m_pDisp->AddRef();
    }
    DISPCALLER(IUnknown* pUnk) {
        m_psaParameters = NULL;
        if (pUnk) {
            pUnk->QueryInterface(IID_IDispatch,(void**)&m_pDisp);
        }
    }
    DISPCALLER() {
        m_pDisp = NULL;
        m_psaParameters = NULL;
    }
    ~DISPCALLER() {
        if (m_pDisp) m_pDisp->Release();
        DestroyArray();
    }

    BOOL    IsValid() { return (m_pDisp)?TRUE:FALSE; }
    
    // Object creation
    HRESULT CoCreateInstance(LPTSTR szID,DWORD dwContext = CLSCTX_SERVER);
    HRESULT CoCreateInstance(CLSID& clsid,DWORD dwContext = CLSCTX_SERVER);
    
    // Assignment
    DISPCALLER& operator = (IDispatch* pDisp);  // Makes AddRef
    DISPCALLER& operator <= (IDispatch* pDisp); // Doesn't make AddRef
    DISPCALLER& operator = (IUnknown* pUnk);
    DISPCALLER& operator = (DISPCALLER& dc) {
        Release();
        m_pDisp = dc.m_pDisp;
        if (m_pDisp) m_pDisp->AddRef();
        return (*this);
    }
    LPDISPATCH* GetPtrPtr() {
        if (m_pDisp) m_pDisp->Release();
        m_pDisp = NULL;
        return &m_pDisp;
    }
    HRESULT     CopyDisp(IDispatch** pdisp) {
        if (!pdisp) return E_POINTER;
        *pdisp = m_pDisp;
        if (m_pDisp) m_pDisp->AddRef();
        return S_OK;
    }
    void        Release() {
        if (m_pDisp) m_pDisp->Release();
        m_pDisp = NULL;
    }
    HRESULT     QueryInterface(REFIID riid,LPVOID* ppvobj) {
        if (!m_pDisp) return E_POINTER;
        return m_pDisp->QueryInterface(riid,ppvobj);
    }
    
    private:
    bool	CreateArray();
	bool	DestroyArray();
	bool	AddToArray(VARIANT* v);
	public:
    int     GetParamCount();
    void    ClearArgs() {
        DestroyArray();
    }

    // Parameter operators

    DISPCALLER& operator << (VARIANT_BOOL v);
    DISPCALLER& operator << (BYTE v);
    DISPCALLER& operator << (int v);
    DISPCALLER& operator << (long v);
	DISPCALLER& operator << (LPCTSTR v);
    DISPCALLER& operator << (BSTR v);
    DISPCALLER& operator << (float v);
    DISPCALLER& operator << (double v);
	DISPCALLER& operator << (IUnknown* v); 
    DISPCALLER& operator << (IDispatch* v);
    DISPCALLER& operator << (VARIANT v);   // does not clear passed variant !!!

    VARIANT  VariantBool(bool b);
    VARIANT  VariantError(HRESULT hr = E_FAIL);

    VARIANT     VariantCall(LPCTSTR szMethod,EXCEPINFO* pExcep = NULL,WORD wContext = DISPATCH_METHOD);
    VARIANT     GetProperty(LPCTSTR szMethod,EXCEPINFO* pExcep = NULL);
    VARIANT     PutProperty(LPCTSTR szMethod,EXCEPINFO* pExcep = NULL);
	VARIANT     PutPropertyRef(LPCTSTR szMethod,EXCEPINFO* pExcep = NULL);
    VARIANT     VariantCall(DISPID dispid,EXCEPINFO* pExcep = NULL,WORD wContext = DISPATCH_METHOD);
    VARIANT     GetProperty(DISPID dispid,EXCEPINFO* pExcep = NULL);
    VARIANT     PutProperty(DISPID dispid,EXCEPINFO* pExcep = NULL);
	VARIANT     PutPropertyRef(DISPID dispid,EXCEPINFO* pExcep = NULL);

    HRESULT     Call(LPCTSTR szMethod,VARIANT* pvResult = NULL,EXCEPINFO* pExcep = NULL,WORD wContext = DISPATCH_METHOD);
    HRESULT     Call(DISPID dispid,VARIANT* pvResult = NULL,EXCEPINFO* pExcep = NULL,WORD wContext = DISPATCH_METHOD);

    // Macros are used below because some versions of Visual C have problems with some of the template
    // techniques required

    // Simplified helpers (limited to non-indexed properties)
    #define PUTPROPERTYHLP(type) \
    HRESULT PutProperty(LPCTSTR szMethod,type v,EXCEPINFO* pExcep = NULL) { \
        DestroyArray(); \
        (*this) << v; \
        return Call(szMethod,NULL,pExcep,DISPATCH_PROPERTYPUT); \
    } \
    HRESULT PutProperty(DISPID dispid,type v,EXCEPINFO* pExcep = NULL) { \
        DestroyArray(); \
        (*this) << v; \
        return Call(dispid,NULL,pExcep,DISPATCH_PROPERTYPUT); \
    }

    PUTPROPERTYHLP(VARIANT)
    PUTPROPERTYHLP(VARIANT_BOOL)
    PUTPROPERTYHLP(long)
    PUTPROPERTYHLP(BYTE)
    PUTPROPERTYHLP(float)
    PUTPROPERTYHLP(double)
    PUTPROPERTYHLP(BSTR)
    PUTPROPERTYHLP(IUnknown*)
    PUTPROPERTYHLP(IDispatch*)
    // These are created using the above macro
    //HRESULT     PutProperty(LPCTSTR szMethod,<type> v,EXCEPINFO pExcep = NULL);
    //HRESULT     PutProperty(DISPID dispid,<type> v,EXCEPINFO pExcep = NULL);
    #undef PUTPROPERTYHLP

    HRESULT PutProperty(LPCTSTR szMethod,LPCTSTR v,UINT uCP = CP_ACP,EXCEPINFO* pExcep = NULL) {
        DestroyArray();
        BSTR    bstr = _PackInBSTR(v,uCP);
        (*this) << bstr;
        ::SysFreeString(bstr);
        return Call(szMethod,NULL,pExcep,DISPATCH_PROPERTYPUT);
    }
    HRESULT PutProperty(DISPID dispid,LPCTSTR v,UINT uCP = CP_ACP,EXCEPINFO* pExcep = NULL) {
        DestroyArray();
        BSTR    bstr = _PackInBSTR(v,uCP);
        (*this) << bstr;
        ::SysFreeString(bstr);
        return Call(dispid,NULL,pExcep,DISPATCH_PROPERTYPUT);
    }

    #define PUTPROPERTYHLP(MethodName,type,vartype,varmember) \
    type    MethodName(LPCTSTR szMethod,HRESULT* phr = NULL,EXCEPINFO* pExcep = NULL) { \
        VARIANT vResult; \
        ::VariantInit(&vResult); \
        HRESULT hr = Call(szMethod,&vResult,pExcep,DISPATCH_PROPERTYGET); \
        if (phr) *phr = hr; \
        if (FAILED(hr)) return NULL; \
        hr = ::VariantChangeType(&vResult,&vResult,0,vartype); \
        if (phr) *phr = hr; \
        type t = vResult.varmember; \
        if (FAILED(hr)) { \
            ::VariantClear(&vResult); \
            return NULL; \
        } \
        return t; \
    } \
    type    MethodName(DISPID dispid,HRESULT* phr = NULL,EXCEPINFO* pExcep = NULL) { \
        VARIANT vResult; \
        ::VariantInit(&vResult); \
        HRESULT hr = Call(dispid,&vResult,pExcep,DISPATCH_PROPERTYGET); \
        if (phr) *phr = hr; \
        if (FAILED(hr)) return NULL; \
        hr = ::VariantChangeType(&vResult,&vResult,0,vartype); \
        if (phr) *phr = hr; \
        type t = vResult.varmember; \
        if (FAILED(hr)) { \
            ::VariantClear(&vResult); \
            return NULL; \
        } \
        return t; \
    }

    PUTPROPERTYHLP(GetByteProperty,BYTE,VT_UI1,bVal)
    PUTPROPERTYHLP(GetShortProperty,short,VT_I2,iVal)
    PUTPROPERTYHLP(GetLongProperty,long,VT_I4,lVal)
    PUTPROPERTYHLP(GetBoolProperty,VARIANT_BOOL,VT_BOOL,boolVal)
    PUTPROPERTYHLP(GetFloatProperty,float,VT_R4,fltVal)
    PUTPROPERTYHLP(GetDoubleProperty,double,VT_R8,dblVal)
    PUTPROPERTYHLP(GetBSTRProperty,BSTR,VT_BSTR,bstrVal)
    PUTPROPERTYHLP(GetUnkProperty,IUnknown*,VT_UNKNOWN,punkVal)
    PUTPROPERTYHLP(GetDispProperty,IDispatch*,VT_DISPATCH,pdispVal)

    // These are created using the above macro
    //<type>     MethodName(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    //<type>     MethodName(DISPID dispid,HRESULT* phr,EXCEPINFO pExcep = NULL);
    // WARNING! the retunred BSTR, IDispatch/IUnknown must be freed/released if they are not NULL!
    #undef PUTPROPERTYHLP

    // The returned string must be freed using delete []
    LPTSTR  GetStringProperty(LPCTSTR szMethod,UINT uCP = CP_ACP,HRESULT* phr = NULL,EXCEPINFO* pExcep = NULL) {
        BSTR    bstr;
        bstr = GetBSTRProperty(szMethod,phr,pExcep);
        LPTSTR  sz = _UnPackBSTR(bstr,uCP);
        ::SysFreeString(bstr);
        return sz;
    }
    LPTSTR  GetStringProperty(DISPID dispid,UINT uCP = CP_ACP,HRESULT* phr = NULL,EXCEPINFO* pExcep = NULL) {
        BSTR    bstr;
        bstr = GetBSTRProperty(dispid,phr,pExcep);
        LPTSTR  sz = _UnPackBSTR(bstr,uCP);
        ::SysFreeString(bstr);
        return sz;
    }
    LPTSTR  GetStringProperty(LPCTSTR szMethod,LPTSTR szResult,UINT uBufLen,UINT uCP = CP_ACP,HRESULT* phr = NULL,EXCEPINFO* pExcep = NULL) {
        BSTR    bstr;
        bstr = GetBSTRProperty(szMethod,phr,pExcep);
        LPTSTR  sz = _UnPackBSTR(bstr,uCP);
        ::SysFreeString(bstr);
        if (sz) {
            long lLen = min(_tcslen(sz),uBufLen - 1);
            memcpy(szResult,sz,lLen * sizeof(TCHAR));
            szResult[lLen] = TEXT('\0');
            delete [] sz;
            return szResult;
        } else {
            if (szResult) szResult[0] = TEXT('\0');
            return NULL;
        }
        return sz;
    }
    LPTSTR  GetStringProperty(DISPID dispid,LPTSTR szResult,UINT uBufLen,UINT uCP = CP_ACP,HRESULT* phr = NULL,EXCEPINFO* pExcep = NULL) {
        BSTR    bstr;
        bstr = GetBSTRProperty(dispid,phr,pExcep);
        LPTSTR  sz = _UnPackBSTR(bstr,uCP);
        ::SysFreeString(bstr);
        if (sz) {
            long lLen = min(_tcslen(sz),uBufLen - 1);
            memcpy(szResult,sz,lLen * sizeof(TCHAR));
            szResult[lLen] = TEXT('\0');
            delete [] sz;
            return szResult;
        } else {
            if (szResult) szResult[0] = TEXT('\0');
            return NULL;
        }
    }

};

class VARIANTENUM: public VARIANT {
    IEnumVARIANT*   m_pEnum;
    bool            m_bAtEnd;
public:
    VARIANTENUM();
    VARIANTENUM(IUnknown* pUnk);
    VARIANTENUM(IEnumVARIANT* pEnm);
    ~VARIANTENUM();

    BOOL            IsValid() { return (m_pEnum)?TRUE:FALSE; }
    HRESULT         Clear() { 
        if (m_pEnum) {
            m_pEnum->Release();
            m_pEnum = NULL;
        }
        m_bAtEnd = false;
        return ::VariantClear(this); 
    }

    VARIANTENUM&    operator = (VARIANTENUM& ve);
    VARIANTENUM&    operator = (IUnknown* pUnk);
    VARIANTENUM&    operator = (IEnumVARIANT* pEnm);

    bool            Next();
    bool            Reset();
    bool            Skip(int n);
    bool            atEnd() {return (!m_pEnum || m_bAtEnd); }

};

void ClearExcepInfo(EXCEPINFO* pe);
// Consumes the exception information into the string buffer passed
// Clears the EXCEPINFO structure passed
HRESULT	ConsumeExcepInfo(EXCEPINFO* pe,LPTSTR sz,int nSize,UINT uCP);
HRESULT	ConsumeExcepInfoToErrorInfo(EXCEPINFO* pe,REFGUID riid = IID_IDispatch);

// PackDataInSafeArray

HRESULT PackDataInSafeArray(LPBYTE pb,ULONG ulSize,SAFEARRAY** ppArray);
HRESULT UnPackDataFromSafeArray(SAFEARRAY* psa,LPBYTE* ppBuff,ULONG* pulSize);

HRESULT PackDataInVariant(LPBYTE pb,ULONG ulSize,VARIANT* pVar);
HRESULT UnPackDataFromVariant(VARIANT v,LPBYTE* ppBuff,ULONG* pulSize);

#endif // _AUTOMATIONHLP_H_