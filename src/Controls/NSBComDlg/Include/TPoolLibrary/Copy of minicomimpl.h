#ifndef _MINICOMIMPL_H_
#define _MINICOMIMPL_H_

// Utils

inline BOOL gfInlineIsEqualGUID(REFGUID rguid1, REFGUID rguid2)
{
   return (
	  ((PLONG) &rguid1)[0] == ((PLONG) &rguid2)[0] &&
	  ((PLONG) &rguid1)[1] == ((PLONG) &rguid2)[1] &&
	  ((PLONG) &rguid1)[2] == ((PLONG) &rguid2)[2] &&
	  ((PLONG) &rguid1)[3] == ((PLONG) &rguid2)[3]);
}

HRESULT _STRToBSTR(BSTR* p, LPCTSTR sz, UINT uCP = CP_ACP) {
    int l = (!sz)?0:strlen(sz);
    WCHAR*  wsz = new WCHAR[l + 1];
    wsz[0] = L'\0';
    if (sz) {
        ::MultiByteToWideChar(uCP,0,sz,l,wsz,l+1);
    }
    *p = ::SysAllocString(wsz);
    delete [] wsz;
    if (!(*p)) return E_OUTOFMEMORY;
    return S_OK;
}
HRESULT _OLEToANSIStr(LPSTR* ppsz,LPCWSTR wsz, UINT uCP = CP_ACP) {
    int wl; // = wcslen(wsz);
    *ppsz = NULL;
	wl = ::WideCharToMultiByte(uCP, 0, wsz, wl, NULL, 0,NULL,NULL);
    *ppsz = new CHAR[(wl+1)]; // in case of multibyte
    if (!(*ppsz)) return E_OUTOFMEMORY;
    ::WideCharToMultiByte(uCP, 0, wsz, wl, *ppsz, wl+1,NULL,NULL);
    return S_OK;
}
HRESULT _OLEToTCHAR(LPTSTR* ppsz,LPCWSTR wsz, UINT uCP = CP_ACP) {
    #ifdef UNICODE
        int l = wcslen(wsz);
        *ppsz = new WCHAR[l + 1];
        if (!(*ppsz)) return E_OUTOFMEMORY;
        memcpy(*ppsz,wsz,l);
        (*ppsz)[l] = L'\0';
        return S_OK;
    #else
        int l; // = wcslen(wsz);
		l = ::WideCharToMultiByte(uCP, 0, wsz, l, NULL, 0,NULL,NULL);
        *ppsz = new TCHAR[l + 1];
        if (!(*ppsz)) return E_OUTOFMEMORY;
        ::WideCharToMultiByte(uCP, 0, wsz, l, *ppsz, l+1,NULL,NULL);
        return S_OK;
    #endif // UNICODE
}
HRESULT _WCompareStr(LPCWSTR wsz1,LPCWSTR wsz2,BOOL bCase = FALSE,LCID lcid = LOCALE_USER_DEFAULT) {
    #ifdef UNICODE
        if (CompareString(lcid,((bCase)?0:NORM_IGNORECASE),wsz1,-1,wsz2,-1) == CSTR_EQUAL) return S_OK;
        return S_FALSE;
    #else
        // To avoid problems on some systems we must convert to ANSI
        LPTSTR  sz1 = NULL;
        LPTSTR  sz2 = NULL;
        HRESULT hr;
        hr = _OLEToTCHAR(&sz1,wsz1);
        if (FAILED(hr)) return hr;
        hr = _OLEToTCHAR(&sz2,wsz2);
        if (FAILED(hr)) {
            delete [] sz1;
            return hr;
        }
        int r = CompareString(lcid,((bCase)?0:NORM_IGNORECASE),sz1,-1,sz2,-1);
        delete [] sz1;
        delete [] sz2;
        if (r == CSTR_EQUAL) return S_OK;
        else return S_FALSE;
    #endif
}


template <class T, const IID* piid>
class ccComPtr {
    public:
    T*  p;
	    
	ccComPtr() {	p=NULL;	}
	ccComPtr(T* lp) {
        if ((p = lp) != NULL) p->AddRef();
	}
	ccComPtr(const ccComPtr<T,piid>& lp) {
		if ((p = lp.p) != NULL) p->AddRef();
	}
	~ccComPtr() {
		if (p) p->Release();
	}
	void Release() {
		IUnknown* pTemp = p;
		if (pTemp) {
			p = NULL;
			pTemp->Release();
		}
	}
	operator T*() const	{
		return (T*)p;
	}
	T& operator*() const {
		return *p;
	}
	T** operator&()	{
		return &p;
	}
	T* operator->() const {
		return (T*)p;
	}
	T* operator=(T* lp)	{
        Release();
        p = lp;
        if (p) p->AddRef();
        return p;
	}
	T* operator=(const ccComPtr<T,piid>& lp)	{
        Release();
        p = lp.p;
		if (p) p->AddRef();
        return p;
	}
	bool operator!() const {
		return (p == NULL);
	}
	bool operator<(T* pT) const	{
		return p < pT;
	}
	bool operator==(T* pT) const {
		return p == pT;
	}
	bool IsEqualObject(IUnknown* pOther) {
		if (p == NULL && pOther == NULL)
			return true;
		if (p == NULL || pOther == NULL)
			return false;
    	ccComPtr<IUnknown> punk1;
		ccComPtr<IUnknown> punk2;
		p->QueryInterface(IID_IUnknown, (void**)&punk1);
		pOther->QueryInterface(IID_IUnknown, (void**)&punk2);
		return punk1 == punk2;
	}
	void Attach(T* p2) {
		if (p) p->Release();
		p = p2;
	}
	T* Detach()	{
		T* pt = p;
		p = NULL;
		return pt;
	}
	HRESULT CopyTo(T** ppT)	{
		if (ppT == NULL) return E_POINTER;
		*ppT = p;
		if (p) p->AddRef();
		return S_OK;
	}
	HRESULT CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) {
		return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, *_iid, (void**)&p);
	}
	HRESULT CoCreateInstance(LPCOLESTR szProgID, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) {
		CLSID clsid;
		HRESULT hr = CLSIDFromProgID(szProgID, &clsid);
		if (SUCCEEDED(hr))
			hr = ::CoCreateInstance(clsid, pUnkOuter, dwClsContext, &_iid, (void**)&p);
		return hr;
	}
	template <class Q>
	HRESULT QueryInterface(Q** pp) const {
		return p->QueryInterface(__uuidof(Q), (void**)pp);
	}
};


class ccComVariant: 
    public tagVARIANT 
{
    public:
	    ccComVariant() {	vt = VT_EMPTY; }
        ~ccComVariant() { Clear(); }
    	ccComVariant(const VARIANT& varSrc) {
		    vt = VT_EMPTY;
		    InternalCopy(&varSrc);
    	}
	    ccComVariant(const ccComVariant& varSrc) {
		    vt = VT_EMPTY;
		    InternalCopy(&varSrc);
	    }
	    ccComVariant(BSTR bstrSrc) {
		    vt = VT_EMPTY;
		    *this = bstrSrc;
	    }
	    ccComVariant(LPCOLESTR lpszSrc) {
		    vt = VT_EMPTY;
		    *this = lpszSrc;
	    }
	    ccComVariant(LPCSTR lpszSrc) {
		    vt = VT_EMPTY;
		    *this = lpszSrc;
	    }
        ccComVariant(bool bSrc) {
	        vt = VT_BOOL;
	        boolVal = bSrc ? VARIANT_TRUE : VARIANT_FALSE;
        }
	    ccComVariant(int nSrc) {
		    vt = VT_I4;
		    lVal = nSrc;
	    }
	    ccComVariant(BYTE nSrc) {
		    vt = VT_UI1;
		    bVal = nSrc;
	    }
	    ccComVariant(short nSrc) {
		    vt = VT_I2;
		    iVal = nSrc;
	    }
	    ccComVariant(long nSrc, VARTYPE vtSrc = VT_I4) {
		    vt = vtSrc;
		    lVal = nSrc;
	    }
	    ccComVariant(float fltSrc) {
		    vt = VT_R4;
		    fltVal = fltSrc;
	    }
	    ccComVariant(double dblSrc) {
		    vt = VT_R8;
		    dblVal = dblSrc;
	    }
	    ccComVariant(CY cySrc) {
		    vt = VT_CY;
		    cyVal.Hi = cySrc.Hi;
		    cyVal.Lo = cySrc.Lo;
	    }
	    ccComVariant(IDispatch* pSrc) {
		    vt = VT_DISPATCH;
		    pdispVal = pSrc;
		    if (pdispVal != NULL) pdispVal->AddRef();
	    }
	    ccComVariant(IUnknown* pSrc) {
		    vt = VT_UNKNOWN;
		    punkVal = pSrc;
		    if (punkVal != NULL) punkVal->AddRef();
	    }

	    ccComVariant& operator=(const ccComVariant& varSrc) {
		    InternalCopy(&varSrc);
		    return *this;
	    }
	    ccComVariant& operator=(const VARIANT& varSrc) {
		    InternalCopy(&varSrc);
		    return *this;
	    }
	    ccComVariant& operator=(BSTR bstrSrc) {
		    InternalClear();
		    vt = VT_BSTR;
		    bstrVal = ::SysAllocString(bstrSrc);
		    if (bstrVal == NULL && bstrSrc != NULL) {
			    vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
		    }
		    return *this;
	    }
	    ccComVariant& operator=(LPCOLESTR lpszSrc) {
		    InternalClear();
		    vt = VT_BSTR;
		    bstrVal = ::SysAllocString(lpszSrc);
		    if (bstrVal == NULL && lpszSrc != NULL) {
			    vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
		    }
		    return *this;
	    }
	    ccComVariant& operator=(LPCSTR lpszSrc) {
		    InternalClear();
		    vt = VT_BSTR;
            int     l = strlen(lpszSrc);
            LPOLESTR    wsz = new WCHAR[l + 1];
            if (!wsz) {
                vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
                return *this;
            }
            wsz[0] = L'\0';
            ::MultiByteToWideChar(CP_ACP,0,lpszSrc,l,wsz,l+1);
		    bstrVal = ::SysAllocString(wsz);
            delete [] wsz;
		    if (bstrVal == NULL && lpszSrc != NULL) {
			    vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
		    }
		    return *this;
	    }
	    ccComVariant& operator=(bool bSrc) {
		    if (vt != VT_BOOL) {
			    InternalClear();
			    vt = VT_BOOL;
		    }
		    boolVal = bSrc ? VARIANT_TRUE : VARIANT_FALSE;
		    return *this;
	    }
	    ccComVariant& operator=(int nSrc) {
		    if (vt != VT_I4) {
			    InternalClear();
			    vt = VT_I4;
		    }
		    lVal = nSrc;
		    return *this;
	    }
	    ccComVariant& operator=(BYTE nSrc) {
		    if (vt != VT_UI1) {
			    InternalClear();
			    vt = VT_UI1;
		    }
		    bVal = nSrc;
		    return *this;
	    }
	    ccComVariant& operator=(short nSrc) {
		    if (vt != VT_I2) {
			    InternalClear();
			    vt = VT_I2;
		    }
		    iVal = nSrc;
		    return *this;
	    }
	    ccComVariant& operator=(long nSrc) {
		    if (vt != VT_I4) {
			    InternalClear();
			    vt = VT_I4;
		    }
		    lVal = nSrc;
		    return *this;
	    }
	    ccComVariant& operator=(float fltSrc) {
		    if (vt != VT_R4) {
			    InternalClear();
			    vt = VT_R4;
		    }
		    fltVal = fltSrc;
		    return *this;
	    }
	    ccComVariant& operator=(double dblSrc) {
		    if (vt != VT_R8) {
			    InternalClear();
			    vt = VT_R8;
		    }
		    dblVal = dblSrc;
		    return *this;
	    }
	    ccComVariant& operator=(CY cySrc) {
		    if (vt != VT_CY) {
			    InternalClear();
			    vt = VT_CY;
		    }
		    cyVal.Hi = cySrc.Hi;
		    cyVal.Lo = cySrc.Lo;
		    return *this;
	    }
	    ccComVariant& operator=(IDispatch* pSrc) {
		    InternalClear();
		    vt = VT_DISPATCH;
		    pdispVal = pSrc;
		    if (pdispVal != NULL) pdispVal->AddRef();
		    return *this;
	    }
	    ccComVariant& operator=(IUnknown* pSrc) {
		    InternalClear();
		    vt = VT_UNKNOWN;
		    punkVal = pSrc;
		    if (punkVal != NULL) punkVal->AddRef();
		    return *this;
	    }

	    bool operator==(const VARIANT& varSrc) const {
		    if (this == &varSrc) return true;
		    if (vt != varSrc.vt) return false;
		    switch (vt) {
			    case VT_EMPTY:
			    case VT_NULL:
				    return true;
			    case VT_BOOL:
				    return boolVal == varSrc.boolVal;
			    case VT_UI1:
				    return bVal == varSrc.bVal;
			    case VT_I2:
				    return iVal == varSrc.iVal;
			    case VT_I4:
				    return lVal == varSrc.lVal;
			    case VT_R4:
				    return fltVal == varSrc.fltVal;
			    case VT_R8:
				    return dblVal == varSrc.dblVal;
			    case VT_BSTR:
				    return (::SysStringByteLen(bstrVal) == ::SysStringByteLen(varSrc.bstrVal)) &&
						    (::memcmp(bstrVal, varSrc.bstrVal, ::SysStringByteLen(bstrVal)) == 0);
			    case VT_ERROR:
				    return scode == varSrc.scode;
			    case VT_DISPATCH:
				    return pdispVal == varSrc.pdispVal;
			    case VT_UNKNOWN:
				    return punkVal == varSrc.punkVal;
		    }

		    return false;
	    }
	    bool operator!=(const VARIANT& varSrc) const {return !operator==(varSrc);}

	    HRESULT Clear() { return ::VariantClear(this); }
	    HRESULT Copy(const VARIANT* pSrc) { return ::VariantCopy(this, const_cast<VARIANT*>(pSrc)); }
	    HRESULT Attach(VARIANT* pSrc) {
		    HRESULT hr = Clear();
		    if (!FAILED(hr)) {
			    memcpy(this, pSrc, sizeof(VARIANT));
			    pSrc->vt = VT_EMPTY;
			    hr = S_OK;
		    }
		    return hr;
	    }
	    HRESULT Detach(VARIANT* pDest) {
		    HRESULT hr = ::VariantClear(pDest);
		    if (!FAILED(hr)) {
			    memcpy(pDest, this, sizeof(VARIANT));
			    vt = VT_EMPTY;
			    hr = S_OK;
		    }
		    return hr;
	    }
	    HRESULT ChangeType(VARTYPE vtNew, const VARIANT* pSrc = NULL) {
		    VARIANT* pVar = const_cast<VARIANT*>(pSrc);
		    if (pVar == NULL) pVar = this;
		    return ::VariantChangeType(this, pVar, 0, vtNew);
	    }

        HRESULT InternalClear()	{
		    HRESULT hr = Clear();
		    if (FAILED(hr)) {
			    vt = VT_ERROR;
			    scode = hr;
		    }
		    return hr;
	    }
	    void InternalCopy(const VARIANT* pSrc) {
		    HRESULT hr = Copy(pSrc);
		    if (FAILED(hr)) {
			    vt = VT_ERROR;
			    scode = hr;
		    }
	    }
};

class ccComBSTR {
    public:
	    BSTR m_str;
        ccComBSTR() { m_str = NULL; }
        ccComBSTR(int nSize) { m_str = ::SysAllocStringLen(NULL, nSize); }
        ccComBSTR(int nSize, LPCOLESTR sz) { m_str = ::SysAllocStringLen(sz, nSize); }
        ccComBSTR(LPCOLESTR pSrc) { m_str = ::SysAllocString(pSrc); }
        ccComBSTR(const ccComBSTR& src) { m_str = src.Copy(); }
	    ccComBSTR(REFGUID src) {
		    LPOLESTR szGuid;
		    StringFromCLSID(src, &szGuid);
		    m_str = ::SysAllocString(szGuid);
		    CoTaskMemFree(szGuid);
	    }

	    ccComBSTR& operator=(const ccComBSTR& src) {
		    if (m_str != src.m_str) {
			    if (m_str) ::SysFreeString(m_str);
			    m_str = src.Copy();
		    }
		    return *this;
	    }
	    ccComBSTR& operator=(LPCOLESTR pSrc) {
		    if (m_str) ::SysFreeString(m_str);
		    m_str = ::SysAllocString(pSrc);
		    return *this;
	    }
	    ~ccComBSTR() {
		    if (m_str) ::SysFreeString(m_str);
	    }
	    unsigned int Length() const {
            return (m_str == NULL)? 0 : ::SysStringLen(m_str);
	    }
	    operator BSTR() const {
		    return m_str;
	    }
	    BSTR* operator&() {
		    return &m_str;
	    }
	    BSTR Copy() const {
		    return ::SysAllocStringLen(m_str, ::SysStringLen(m_str));
	    }
	    HRESULT CopyTo(BSTR* pbstr) {
		    if (pbstr == NULL) return E_POINTER;
		    *pbstr = ::SysAllocStringLen(m_str, ::SysStringLen(m_str));
		    if (*pbstr == NULL) return E_OUTOFMEMORY;
		    return S_OK;
	    }
	    void Attach(BSTR src) {
		    m_str = src;
	    }
	    BSTR Detach() {
		    BSTR s = m_str;
		    m_str = NULL;
		    return s;
	    }
	    void Empty() {
		    ::SysFreeString(m_str);
		    m_str = NULL;
	    }
	    bool operator!() const {
		    return (m_str == NULL);
	    }
	    HRESULT Append(const ccComBSTR& bstrSrc) {
		    return Append(bstrSrc.m_str, SysStringLen(bstrSrc.m_str));
	    }
	    HRESULT Append(LPCOLESTR lpsz) {
		    return Append(lpsz, wcslen(lpsz));
	    }
	    HRESULT AppendBSTR(BSTR p) {
		    return Append(p, SysStringLen(p));
	    }
	    HRESULT Append(LPCOLESTR lpsz, int nLen) {
		    int n = Length();
		    BSTR b;
		    b = ::SysAllocStringLen(NULL, n+nLen);
		    if (b == NULL) return E_OUTOFMEMORY;
		    memcpy(b, m_str, n*sizeof(OLECHAR));
		    memcpy(b+n, lpsz, nLen*sizeof(OLECHAR));
		    b[n+nLen] = NULL;
		    SysFreeString(m_str);
		    m_str = b;
		    return S_OK;
	    }
	    bool LoadString(HINSTANCE hInst, UINT nID) {
		    TCHAR sz[512];
		    UINT nLen = ::LoadString(hInst, nID, sz, 512);
		    SysFreeString(m_str);
            if (nLen) _STRToBSTR(&m_str,sz);
            else m_str = NULL;
		    return (nLen != 0);
	    }
        ccComBSTR& operator+=(const ccComBSTR& bstrSrc) {
		    AppendBSTR(bstrSrc.m_str);
		    return *this;
	    }
	    bool operator<(BSTR bstrSrc) const {
		    if (bstrSrc == NULL && m_str == NULL) return false;
		    if (bstrSrc != NULL && m_str != NULL) return wcscmp(m_str, bstrSrc) < 0;
		    return m_str == NULL;
	    }
	    bool operator==(BSTR bstrSrc) const {
		    if (bstrSrc == NULL && m_str == NULL) return true;
		    if (bstrSrc != NULL && m_str != NULL) return wcscmp(m_str, bstrSrc) == 0;
		    return false;
	    }
	    ccComBSTR(LPCSTR pSrc) {
            _STRToBSTR(&m_str,pSrc);
	    }
	    void Append(LPCSTR lpsz) {
            ccComBSTR b;
            b = lpsz;
            Append(b);
	    }
	    ccComBSTR& operator=(LPCSTR pSrc){
		    ::SysFreeString(m_str);
		    _STRToBSTR(&m_str,pSrc);
		    return *this;
	    }
};


// Nonagregatable
template <class T>
class ccComObject:
    public T
{
    private:
        ULONG       m_refCount;
    public:
        ccComObject() {}

        // IUnknown implementation
        virtual ULONG STDMETHODCALLTYPE AddRef() { 
            return (ULONG)::InterlockedIncrement((LONG*)&m_refCount);
        }
        virtual ULONG STDMETHODCALLTYPE Release() { 
            ULONG u = (ULONG)::InterlockedDecrement((LONG*)&m_refCount);
            if (u == 0) {
                m_refCount = 1;
                delete this;
                return 0;
            }
            return u;
        }
        virtual ULONG STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID* ppvObj) {
            if (gfInlineIsEqualGUID(riid,IID_IUnknown)) {
                *ppvObj = (IUnknown*)this;
                AddRef();
            } else {
                HRESULT hr = _InternalQueryInterface(riid,ppvObj);
                if (FAILED(hr)) return hr;
                AddRef();
                return hr;
            }
        }
        static HRESULT CreateInstance(ccComObject<T>** ppObj) {
            *ppObj = NULL;
            *ppObj = new ccComObject<T>();
            if (!(*ppObj)) return E_OUTOFMEMORY;
            return S_OK;
        }
        static HRESULT CreateInstance(REFIID riid,LPVOID* ppvInterface) {
            ccComObject<T>* pObj = NULL;
            *ppvInterface = NULL;
            HRESULT hr = CreateInstance(&pObj);
            if (FAILED(hr)) return hr;
            hr = QueryInterface(riid,ppvInterface);
            if (FAILED(hr)) {
                delete (pObj);
            }
            return hr;
        }
        static HRESULT CreateInstance(REFIID riid,LPVOID* ppvInterface,ccComObject<T>** ppObj) {
            *ppvInterface = NULL;
            HRESULT hr = CreateInstance(ppObj);
            if (FAILED(hr)) return hr;
            hr = QueryInterface(riid,ppvInterface);
            if (FAILED(hr)) {
                delete (*ppObj);
                *ppObj = NULL;
            }
            return hr;
        }
};

// Interface map
#define CC_COM_INTERFACEMAP_BEGIN HRESULT _InternalInterfaceMap(REFIID riid, LPVOID* ppvObj) {\
    *ppvObj = NULL;\
    if (gfInlineIsEqualGUID(riid,IID_NULL)) { return E_NOINTERFACE; }

#define CC_COM_INTERFACE_INTERFACE(_iid,_iface) else if (gfInlineIsEqualGUID(riid,_iid)) {\
    *ppvObj = (_iface*)this; return S_OK; }
#define CC_COM_INTERFACE_INTERFACE_CAST(_iid,_iface, iface2) else if (gfInlineIsEqualGUID(riid,_iid)) {\
    *ppvObj = (_iface*)(iface2*)this; return S_OK; }

#define CC_COM_INTERFACEMAP_END else { return E_NOINTERFACE; } }



template <class T>
class ccComClassBase
{
    public:
        ccComClassBase() { }
    public:
        HRESULT _InternalQueryInterface(REFIID riid, LPVOID* ppvObj) {
            T* pThis = (T*)this;
            return pThis->_InternalInterfaceMap(riid,ppvObj);
        }
    
};

template <class T>
struct _DISPMEMBER_MAP {
        int         nMap;
        HRESULT (T::*pfn)(WORD wFlags,unsigned int nArgs, VARIANTARG* pvarArgs,VARIANT* pVarResult);
        DISPID      dispid;
        LPOLESTR    wszName;
        int         nReqArg;
        int         nOptArg;
};

#define CC_COM_DISPMAP_BEGIN(T) public:\
    typedef HRESULT (T::*_DISPMEMBER)(WORD wFlags,unsigned int nArgs, VARIANTARG* pvarArgs,VARIANT* pVarResult);\
    struct _DISPMEMBER_MAP {\
        int         nMap;\
        _DISPMEMBER pfn;\
        DISPID      dispid;\
        LPOLESTR    wszName;\
        int         nReqArg;\
        int         nOptArg;\
    };\
    static _DISPMEMBER _GetDispMap() {\
        static _DISPMEMBER_MAP _map[] = {

#define CC_COM_DISPMAP_END() {0, NULL, 0, NULL, 0, 0} }; return _map; }

#define CC_COM_DISPMAP_ENTRY(_mapID,f, _dID, _name, _rarg, _oarg) {_mapID, f, _dID, L##name, _rarg, _oarg },


template <class T,class _DispInterface = IDispatch,int _nDispMap = 0>
class ccComDispatchBasicImpl: public _DispInterface
{
    typedef T _DispImplementorClass;

    _DispImplementorClass::_DISPMEMBER_MAP*     _FindDispMemberByID(DISPID _dispid) {
        T::_DISPMEMBER_MAP* pdmap = _DispImplementorClass::_GetDispMap();
        int i;
        for (i = 0; pdmap[i].wszName != NULL; i++) {
            if (_nDispMap == pdmap[i].nMap && _dispid == pdmap[i].dispid) return &pdmap[i];
        }
        return NULL;
    }
    _DispImplementorClass::_DISPMEMBER_MAP*     _FindDispMemberByName(LPCWSTR wszName, LCID lcid) {
        T::_DISPMEMBER_MAP* pdmap = _DispImplementorClass::_GetDispMap();
        int i;
        for (i = 0; pdmap[i].wszName != NULL; i++) {
            if (_nDispMap == pdmap[i].nMap && (_WCompareStr(wszName,pdmap[i].wszName) == S_OK)) return &pdmap[i];
        }
        return NULL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(    REFIID          riid,
                                                        OLECHAR**        rgszNames, 
                                                        unsigned int    cNames,          
                                                        LCID            lcid,                   
                                                        DISPID*         rgDispId) {
        if (!cNames) return S_OK;
        if (!rgDispId || !rgszNames) return E_POINTER;
        unsigned int i;
        HRESULT  hr = S_OK;
        _DispImplementorClass::_DISPMEMBER_MAP*     pMapEntry = NULL;
        for (i = 0; i < cNames; i++) {
            pMapEntry = _FindDispMemberByName(rgszNames[i],lcid);
            if (pMapEntry) {
                rgDispId[i] = pMapEntry->dispid;
            } else {
                rgDispId[i] = DISPID_UNKNOWN;
                hr = DISP_E_UNKNOWNNAME;
            }
        }
        return hr;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(   DISPID  dispIdMember,      
                                                REFIID  riid,              
                                                LCID  lcid,                
                                                WORD  wFlags,              
                                                DISPPARAMS*  pDispParams,  
                                                VARIANT*  pVarResult,  
                                                EXCEPINFO*  pExcepInfo,  
                                                unsigned int*  puArgErr) {
        _DispImplementorClass::_DISPMEMBER_MAP*     pMapEntry = NULL;
        pMapEntry = _FindDispMemberByID(dispIdMember);
        if (!pMapEntry) return DISP_E_MEMBERNOTFOUND;
        
        // pDispParams->cArgs - actual arguments
        if (pDispParams->cArgs < pMapEntry->nReqArg) return DISP_E_BADPARAMCOUNT;
        if (pDispParams->cNamedArgs > 0) return DISP_E_NONAMEDARGS;
        HRESULT hr = (_DispImplementorClass.*pMapEntry->pfn)(wFlags,pDispParams->cArgs,pDispParams->rgvararg,pVarResult);
        return hr;
    }
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount( unsigned int*  pctinfo) {
        if (pctinfo) *pctinfo = 0;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(  unsigned int  iTInfo,
                                                    LCID  lcid,                   
                                                    ITypeInfo**  ppTInfo) {
        return DISP_E_BADINDEX;
    }
   
};

#endif // _MINICOMIMPL_H_
