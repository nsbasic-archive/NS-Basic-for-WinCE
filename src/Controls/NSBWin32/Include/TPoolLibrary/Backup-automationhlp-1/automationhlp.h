#ifndef _AUTOMATIONHLP_H_
#define _AUTOMATIONHLP_H_


BSTR    _PackInBSTR(LPCTSTR sz,UINT uCP = CP_ACP);
BSTR    _PackInBSTRA(LPCSTR sz,UINT uCP = CP_ACP);

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
    
    
    // Assignment
    DISPCALLER& operator = (IDispatch* pDisp);  // Makes AddRef
    DISPCALLER& operator <= (IDispatch* pDisp); // Doesn't make AddRef
    DISPCALLER& operator = (IUnknown* pUnk);
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
    
    private:
    bool	CreateArray();
	bool	DestroyArray();
	bool	AddToArray(VARIANT* v);
	public:
    int     GetParamCount();

    // Parameter operators

    DISPCALLER& operator << (VARIANT_BOOL v);
    DISPCALLER& operator << (int v);
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

    // Simplified helpers (limited to non-indexed properties)
    HRESULT     PutProperty(LPCTSTR szMethod,VARIANT v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,long v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,short v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,float v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,double v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,BSTR v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,IUnknown* v,EXCEPINFO pExcep = NULL);
    HRESULT     PutProperty(LPCTSTR szMethod,IDispatch* v,EXCEPINFO pExcep = NULL);

    VARIANT     GetVarProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    long        GetLongProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    short       GetShortProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    float       GetFloatProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    double      GetDoubleProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    BSTR        GetBSTRProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    IUnknown*   GetUnkProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);
    IDispatch*  GetDispProperty(LPCTSTR szMethod,HRESULT* phr,EXCEPINFO pExcep = NULL);



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

// Tries to extract the a value from the variant passing through the chain
// og objects and default values
HRESULT VariantResolveToValue(VARIANT* pvarDest,VARIANT* pvarSrc);

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