#ifndef _TPOOLLIBRARY_AUTMATIONHLP_TYPEPACKERS_H_
#define _TPOOLLIBRARY_AUTMATIONHLP_TYPEPACKERS_H_

#pragma message("Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)")

class ccBSTR;
class ccEXCEPINFO;
class ccVariant : public tagVARIANT {
    public:
        ccVariant() { vt = VT_EMPTY; }
        ~ccVariant() { Clear(); }
        ccVariant(const VARIANT& Src) { vt = VT_EMPTY;DoCopy(&Src);}
        ccVariant(const ccVariant& Src) { vt = VT_EMPTY; DoCopy(&Src);}
	    ccVariant(BSTR bstr) {vt = VT_EMPTY;*this = bstr;}
	    ccVariant(LPCOLESTR Src) {vt = VT_EMPTY;*this = Src;}
	    ccVariant(LPCSTR Src) {vt = VT_EMPTY;*this = Src;}
	    ccVariant(bool b) {vt = VT_BOOL; boolVal = b ? VARIANT_TRUE : VARIANT_FALSE;}
	    ccVariant(int n) {vt = VT_I4;lVal = n;}
        ccVariant(BYTE b) { vt = VT_UI1; bVal = b; }
        ccVariant(short h) { vt = VT_I2; iVal = h; }
        ccVariant(long l) { vt = VT_I4; lVal = l; }
	    ccVariant(float flt) {vt = VT_R4; fltVal = flt;	}
        ccVariant(double dbl) { vt = VT_R8; dblVal = dbl; }
        ccVariant(CY cy) { vt = VT_CY; cyVal.Hi = cy.Hi; cyVal.Lo = cy.Lo; }
        ccVariant(IDispatch* p) { 
            vt = VT_DISPATCH; 
            pdispVal = p;
            if (pdispVal != NULL) pdispVal->AddRef();
	    }
	    ccVariant(IUnknown* pSrc) {
		    vt = VT_UNKNOWN;
		    punkVal = pSrc;
		    if (punkVal != NULL) punkVal->AddRef();
	    }

    // Assignments
	    ccVariant& operator = (const ccVariant& Src) {
		    DoCopy(&Src);
		    return *this;
	    }
	    ccVariant& operator = (const VARIANT& Src) {
		    DoCopy(&Src);
		    return *this;
	    }
        // Safe attach
        ccVariant& operator <= (VARIANT& Src) {
		    DoClear();
            CopyMemory(this,&Src,sizeof(VARIANT));
            Src.vt = VT_EMPTY;
		    return *this;
	    }
	    ccVariant& SetOptional() {
	        DoClear();
	        vt = VT_ERROR;
	        scode = DISP_E_PARAMNOTFOUND;
	        return (*this);
	    }
        bool IsOmitted() {
	        if (vt == VT_ERROR && scode == DISP_E_PARAMNOTFOUND) return true;
	        return false;
	    }
        ccVariant& operator <= (const BSTR bstr) {
		    DoClear();
            vt = VT_BSTR;
            bstrVal = bstr;
		    return (*this);
	    }
	    ccVariant& operator = (BSTR bstr) {
		    DoClear();
		    vt = VT_BSTR;
		    bstrVal = ::SysAllocString(bstr);
		    if (bstrVal == NULL && bstr != NULL) {
			    vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
		    }
		    return *this;
	    }
	    ccVariant& operator = (LPCOLESTR lpszSrc)	{
		    DoClear();
		    vt = VT_BSTR;
		    bstrVal = ::SysAllocString(lpszSrc);
		    if (bstrVal == NULL && lpszSrc != NULL)	{
			    vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
		    }
		    return *this;
	    }
	    ccVariant& operator = (LPCSTR lpszSrc) {
		    DoClear();
		    vt = VT_BSTR;
		    bstrVal = _PackInBSTRA(lpszSrc);
		    if (bstrVal == NULL && lpszSrc != NULL) {
			    vt = VT_ERROR;
			    scode = E_OUTOFMEMORY;
		    }
		    return *this;
	    }
	    ccVariant& operator = (bool bSrc) {
		    if (vt != VT_BOOL) {
			    DoClear();
			    vt = VT_BOOL;
		    }
			boolVal = bSrc ? VARIANT_TRUE : VARIANT_FALSE;
			return *this;
	    }
	    ccVariant& operator = (int nSrc) {
		    DoClear();
            vt = VT_I4;
		    lVal = nSrc;
		    return *this;
	    }
	    ccVariant& operator = (BYTE nSrc) {
		    DoClear();
			vt = VT_UI1;
		    bVal = nSrc;
		    return *this;
	    }
	    ccVariant& operator = (short nSrc) {
		    DoClear();
			vt = VT_I2;
		    iVal = nSrc;
		    return *this;
	    }
	    ccVariant& operator = (long nSrc) {
		    DoClear();
			vt = VT_I4;
		    lVal = nSrc;
		    return *this;
	    }
	    ccVariant& operator = (float fltSrc) {
		    DoClear();
			vt = VT_R4;
		    fltVal = fltSrc;
		    return *this;
	    }
	    ccVariant& operator = (double dblSrc) {
		    DoClear();
			vt = VT_R8;
		    dblVal = dblSrc;
		    return *this;
	    }
	    ccVariant& operator = (CY cySrc) {
		    DoClear();
			vt = VT_CY;
		    cyVal.Hi = cySrc.Hi;
		    cyVal.Lo = cySrc.Lo;
		    return *this;
	    }
	    ccVariant& operator = (IDispatch* pSrc)	{
		    DoClear();
		    vt = VT_DISPATCH;
		    pdispVal = pSrc;
		    if (pdispVal != NULL) pdispVal->AddRef();
		    return *this;
	    }
	    ccVariant& operator = (IUnknown* pSrc) {
		    DoClear();
		    vt = VT_UNKNOWN;
		    punkVal = pSrc;
		    if (punkVal != NULL) punkVal->AddRef();
		    return *this;
	    }
    // Conversions
                    operator long () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_I4);
            if (FAILED(hr)) return 0;
            return lVal;
        }
                    operator int () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_I4);
            if (FAILED(hr)) return 0;
            return (int)lVal;
        }
                    operator short () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_I2);
            if (FAILED(hr)) return 0;
            return iVal;
        }
                    operator char () {
            if (IsOmitted()) return '\0';
            HRESULT hr = ChangeType(VT_I1);
            if (FAILED(hr)) return 0;
            return cVal;
        }
                    operator unsigned char () {
            if (IsOmitted()) return '\0';
            HRESULT hr = ChangeType(VT_UI1);
            if (FAILED(hr)) return 0;
            return bVal;
        }
                    operator unsigned short () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_UI2);
            if (FAILED(hr)) return 0;
            return uiVal;
        }
                    operator unsigned long () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_UI4);
            if (FAILED(hr)) return 0;
            return ulVal;
        }
                    operator bool () {
            if (IsOmitted()) return false;
            HRESULT hr = ChangeType(VT_BOOL);
            if (FAILED(hr)) return false;
            return (boolVal?true:false);
        }
                    operator float () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_R4);
            if (FAILED(hr)) return 0;
            return fltVal;
        }
                    operator double () {
            if (IsOmitted()) return 0;
            HRESULT hr = ChangeType(VT_R8);
            if (FAILED(hr)) return 0;
            return dblVal;
        }
        operator ccBSTR ();
        operator BSTR () {
            if (IsOmitted()) return NULL;
            HRESULT hr = ChangeType(VT_BSTR);
            if (FAILED(hr)) return NULL;
            return bstrVal;
        }



    // Action helpers
	    HRESULT Clear() { return ::VariantClear(this); }
	    HRESULT Copy(const VARIANT* pSrc) { return ::VariantCopy(this, const_cast<VARIANT*>(pSrc)); }
        HRESULT CopyTo(VARIANT* pDst)	{
		    if (pDst == NULL) return E_POINTER;
            return ::VariantCopy(pDst,this);
	    }
	    HRESULT Attach(VARIANT* pSrc) {
		    HRESULT hr = Clear();
		    if (!FAILED(hr)) {
			    CopyMemory(this, pSrc, sizeof(VARIANT));
			    pSrc->vt = VT_EMPTY;
			    hr = S_OK;
		    }
		    return hr;
	    }
	    HRESULT Detach(VARIANT* pDest) {
		    HRESULT hr = ::VariantClear(pDest);
		    if (!FAILED(hr)) {
			    CopyMemory(pDest, this, sizeof(VARIANT));
			    vt = VT_EMPTY;
			    hr = S_OK;
		    }
		    return hr;
	    }
        // This routine should be used with care!
        // It means that the ccVariant object will no longer control
        // the data in the variant. Call it only when the control over
        // the data is transferred to another object or is done manually-  BUT BE SURE!!!
        // Example: When SAFEARRAY is set to a ccSafeArray object.
        HRESULT ReleaseControl() {
		    vt = VT_EMPTY;
		    return S_OK;
	    }
	    HRESULT ChangeType(VARTYPE vtNew, const VARIANT* pSrc = NULL) {
		    VARIANT* pVar = const_cast<VARIANT*>(pSrc);
		    if (pVar == NULL) pVar = this;
		    return ::VariantChangeType(this, pVar, 0, vtNew);
	    }
        HRESULT ToValue(VARIANT* pSrc = NULL) {
            VARIANT* pVar = const_cast<VARIANT*>(pSrc);
            if (pVar == NULL) pVar = this;
            VARIANT vTemp;
            ::VariantInit(&vTemp);
            HRESULT hr = ::VariantResolveToValue(&vTemp,pVar);
            if (FAILED(hr)) {
                ::VariantClear(&vTemp);
                return hr;
            }
            DoClear();
            hr = ::VariantCopy(this,&vTemp);
            if (FAILED(hr)) {
                vt = VT_ERROR;
			    scode = hr;
            }
            ::VariantClear(&vTemp);
            return hr;
        }
        bool    IsNumeric() {
            switch (vt) {
                case VT_I1:
                case VT_I2:
                case VT_I4:
                case VT_UI1:
                case VT_UI2:
                case VT_UI4:
                case VT_R4:
                case VT_R8:
                case VT_INT:
                case VT_UINT:
                    return true;
                default:
                    return false;
            }
        }


    // Helpers
	    HRESULT DoClear() {
		    HRESULT hr = Clear();
		    if (FAILED(hr)) {
			    vt = VT_ERROR;
			    scode = hr;
		    }
		    return hr;
	    }
	    void DoCopy(const VARIANT* pSrc) {
		    HRESULT hr = Copy(pSrc);
		    if (FAILED(hr)) {
			    vt = VT_ERROR;
			    scode = hr;
		    }
	    }
};

class ccBSTR {
public:
	BSTR m_str;
    ccBSTR() { m_str = NULL; }
    ccBSTR(int nSize) { m_str = ::SysAllocStringLen(NULL, nSize); }
    ccBSTR(int nSize, LPCOLESTR sz)	{ m_str = ::SysAllocStringLen(sz, nSize); }
    ccBSTR(LPCOLESTR pSrc) { m_str = ::SysAllocString(pSrc); }
    ccBSTR(const ccBSTR& src) { m_str = src.Copy();	}
	ccBSTR(REFGUID src)	{
		LPOLESTR szGuid;
		HRESULT hr = StringFromCLSID(src, &szGuid);
        if (!FAILED(hr)) {
		    m_str = ::SysAllocString(szGuid);
            CoTaskMemFree(szGuid);
        } else {
            m_str = NULL;
        }		
	}
    ccBSTR(LPCSTR pSrc)	{
		m_str = _PackInBSTRA(pSrc);
	}

    // Assignements
    ccBSTR& operator = (LPCSTR pSrc) {
		::SysFreeString(m_str);
		m_str = _PackInBSTRA(pSrc);
		return *this;
	}
	ccBSTR& operator = (const ccBSTR& src) {
		if (m_str != src.m_str) {
			if (m_str) ::SysFreeString(m_str);
			m_str = src.Copy();
		}
		return *this;
	}
	ccBSTR& operator = (LPCOLESTR pSrc)	{
		if (m_str) ::SysFreeString(m_str);
		m_str = ::SysAllocString(pSrc);
		return *this;
	}
    ccBSTR& operator = (VARIANT v)	{
		if (m_str) ::SysFreeString(m_str);
        m_str = NULL;
        ccVariant vs(v);
        if (!FAILED(vs.ChangeType(VT_BSTR))) {
            m_str = ::SysAllocString(vs.bstrVal);
        }
		return *this;
	}

    // Safe Attach
    ccBSTR& operator <= (BSTR pSrc)	{
		if (m_str) ::SysFreeString(m_str);
		m_str = pSrc;
		return *this;
	}

	~ccBSTR()	{
		::SysFreeString(m_str);
	}
	unsigned int Length() const	{
		return (m_str == NULL)? 0 : SysStringLen(m_str);
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
    HRESULT Compact() {
        if (!m_str) return S_OK;
        BSTR bstr = SysAllocString(m_str);
        if (!bstr) return E_OUTOFMEMORY;
        ::SysFreeString(m_str);
        m_str = bstr;
        return S_OK;
    }
	HRESULT CopyTo(BSTR* pbstr)	{
		if (pbstr == NULL) return E_POINTER;
		*pbstr = ::SysAllocStringLen(m_str, ::SysStringLen(m_str));
		if (*pbstr == NULL) return E_OUTOFMEMORY;
		return S_OK;
	}
    HRESULT CopyTo(VARIANT* pVar)	{
		if (pVar == NULL) return E_POINTER;
        if (m_str) {
            pVar->vt = VT_BSTR;
            pVar->bstrVal = ::SysAllocStringLen(m_str, ::SysStringLen(m_str));
            if (!pVar->bstrVal) {
                pVar->vt = VT_EMPTY;
                return E_OUTOFMEMORY;
            }
        } else {
            pVar->vt = VT_EMPTY;
        }
		return S_OK;
	}
    HRESULT CopyToBuff(LPOLESTR wszBuff,LONG lLimit = -1) { // Including the null terminator
        if (!wszBuff) return E_POINTER;
        LONG l;
        if (lLimit == 0) return S_OK;
        if (!m_str) {
            wszBuff[0] = L'\0';
            return S_OK;
        }
        long len = Length();
        for (l = 0; l < lLimit - 1 && l < len; l++) {
            wszBuff[l] = m_str[l];
        }
        wszBuff[l] = L'\0';
        return S_OK;
    }
	HRESULT Attach(BSTR src) {
        if (m_str) return E_POINTER;
		m_str = src;
        return S_OK;
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
	bool operator! () const	{
		return (m_str == NULL);
	}
    BSTR Alloc(UINT uLen = 0,LPCOLESTR wszSrc = NULL) {
        if (m_str) ::SysFreeString(m_str);
        m_str = ::SysAllocStringLen(NULL,uLen); // Allocates + 1 for the null terminator
        if (!m_str) return NULL;
        m_str[0] = L'\0';
        if (wszSrc) {
            ULONG i;
            for (i = 0;wszSrc[i] != L'\0' && i < uLen;i++) {
                m_str[i] = wszSrc[i];
            }
            m_str[i] = L'\0';
        }        
        m_str[uLen] = L'\0';
        return m_str;
    }
    BSTR CompactPtr() {
        if (!m_str) return NULL;
        BSTR bstrNew = ::SysAllocString(m_str);
        if (!bstrNew) return NULL;
        ::SysFreeString(m_str);
        m_str = bstrNew;
        return m_str;
    }
	HRESULT Append(const ccBSTR& bstrSrc)	{
        return Append(bstrSrc.m_str, ::SysStringLen(bstrSrc.m_str));
	}
	HRESULT Append(LPCOLESTR lpsz) {
		return Append(lpsz, ocslen(lpsz));
	}
	HRESULT AppendBSTR(BSTR p) {
		return Append(p, SysStringLen(p));
	}
	HRESULT Append(LPCOLESTR lpsz, int nLen) {
		int n1 = Length();
        if (!n1) Alloc();
		BSTR b;
		b = ::SysAllocStringLen(NULL, n1+nLen);
		if (b == NULL) return E_OUTOFMEMORY;
		memcpy(b, m_str, n1*sizeof(OLECHAR));
		memcpy(b+n1, lpsz, nLen*sizeof(OLECHAR));
		b[n1+nLen] = NULL;
		SysFreeString(m_str);
		m_str = b;
		return S_OK;
	}
    HRESULT Append(LPCSTR lpsz) {
		BSTR bstr = _PackInBSTRA(lpsz);
		HRESULT hr = Append(bstr);
        ::SysFreeString(bstr);
        return hr;
	}
	bool LoadString(HINSTANCE hInst, UINT nID) {
		TCHAR sz[512];
		UINT nLen = ::LoadString(hInst, nID, sz, 512);
		SysFreeString(m_str);
		m_str = (nLen != 0) ? _PackInBSTR(sz) : NULL;
		return (nLen != 0);
	}
};

// Caution the pfnDeferredFillIn must be used carefully
class ccEXCEPINFO: 
    public tagEXCEPINFO {
public:
    ccEXCEPINFO() {
        ZeroMemory(this,sizeof(EXCEPINFO));
    }
    ccEXCEPINFO(EXCEPINFO* pei) {
        Copy(pei);
    }
    ccEXCEPINFO(const EXCEPINFO& ei) {
        Copy(&ei);
    }
    ccEXCEPINFO(const ccEXCEPINFO& ei) {
        Copy(&ei);
    }
    ~ccEXCEPINFO() {
        Clear();
    }
    
    ccEXCEPINFO& operator = (const ccEXCEPINFO& Src) {
		Copy(&Src);
		return *this;
	}
	ccEXCEPINFO& operator = (const EXCEPINFO& Src) {
		Copy(&Src);
		return *this;
	}
    // Safe attach
    ccEXCEPINFO& operator <= (EXCEPINFO& Src) {
		Clear();
        CopyMemory(this,&Src,sizeof(EXCEPINFO));
        ZeroMemory(&Src,sizeof(EXCEPINFO));
		return *this;
	}
    HRESULT Attach(EXCEPINFO* pSrc) {
		CopyMemory(this, pSrc, sizeof(EXCEPINFO));
		ZeroMemory(&pSrc,sizeof(EXCEPINFO));
		return S_OK;
	}
    HRESULT Detach(EXCEPINFO* pDst) {
        if (!pDst) return E_POINTER;
        if (pDst->bstrSource) ::SysFreeString(pDst->bstrSource);
	    if (pDst->bstrDescription) ::SysFreeString(pDst->bstrDescription);
	    if (pDst->bstrHelpFile) ::SysFreeString(pDst->bstrHelpFile);
        CopyMemory(pDst,this, sizeof(EXCEPINFO));
        ZeroMemory(this,sizeof(EXCEPINFO));
        return S_OK;
    }
    HRESULT CopyTo(EXCEPINFO* pDst) {
        if (pDst->bstrSource) ::SysFreeString(pDst->bstrSource);
	    if (pDst->bstrDescription) ::SysFreeString(pDst->bstrDescription);
	    if (pDst->bstrHelpFile) ::SysFreeString(pDst->bstrHelpFile);

        ZeroMemory(pDst,sizeof(EXCEPINFO));

        pDst->wCode = wCode;
        pDst->wReserved = wReserved;
        pDst->dwHelpContext = dwHelpContext;
        pDst->pvReserved = pvReserved;
        pDst->pfnDeferredFillIn = pfnDeferredFillIn;
        pDst->scode = scode;

        if (bstrSource) {
            pDst->bstrSource = ::SysAllocString(bstrSource);
            if (!pDst->bstrSource) return E_OUTOFMEMORY;
        }
        if (bstrDescription) {
            pDst->bstrDescription = ::SysAllocString(bstrDescription);
            if (!pDst->bstrDescription) return E_OUTOFMEMORY;
        }
        if (bstrHelpFile) {
            pDst->bstrHelpFile = ::SysAllocString(bstrHelpFile);
            if (!pDst->bstrHelpFile) return E_OUTOFMEMORY;
        }
        return S_OK;
    }

    HRESULT GetSource(LPTSTR sz,int nSize,UINT uCP = CP_ACP) {
        if (!nSize || !sz) return E_POINTER;
        #ifdef UNICODE
            int i = 0;
            if (bstrSource) {
				for (i = 0;i < (nSize - 2) && bstrSource[i]; i++) {
					sz[i] = bstrSource[i];
				}
				sz[i] = L'\0';
			}
            sz[i] = L'\0';
            return S_OK;
        #else
            int i = 0;
			if (bstrSource) {
				i += ::WideCharToMultiByte(uCP,0,bstrSource,-1,&sz[i],nSize - 1,NULL,NULL);
			}
            sz[i] = '\0';
        #endif
        return S_OK;
    }
    HRESULT GetDescription(LPTSTR sz,int nSize,UINT uCP = CP_ACP) {
        if (!nSize || !sz) return E_POINTER;
        #ifdef UNICODE
            int i = 0;
            if (bstrDescription) {
				for (i = 0;i < (nSize - 2) && bstrDescription[i]; i++) {
					sz[i] = bstrDescription[i];
				}
				sz[i] = L'\0';
			}
            sz[i] = L'\0';
            return S_OK;
        #else
            int i = 0;
			if (bstrDescription) {
				i += ::WideCharToMultiByte(uCP,0,bstrDescription,-1,&sz[i],nSize - 1,NULL,NULL);
			}
            sz[i] = '\0';
        #endif
        return S_OK;
    }
    HRESULT GetHelpFile(LPTSTR sz,int nSize,UINT uCP = CP_ACP) {
        if (!nSize || !sz) return E_POINTER;
        #ifdef UNICODE
            int i = 0;
            if (bstrHelpFile) {
				for (i = 0;i < (nSize - 2) && bstrHelpFile[i]; i++) {
					sz[i] = bstrHelpFile[i];
				}
				sz[i] = L'\0';
			}
            sz[i] = L'\0';
            return S_OK;
        #else
            int i = 0;
			if (bstrHelpFile) {
				i += ::WideCharToMultiByte(uCP,0,bstrHelpFile,-1,&sz[i],nSize - 1,NULL,NULL);
			}
            sz[i] = '\0';
        #endif
        return S_OK;
    }
    HRESULT GetErrText(LPTSTR sz,int nSize,UINT uCP = CP_ACP) {
        if (!nSize || !sz) return E_POINTER;
        
		#ifdef UNICODE
			int j,i = 0;
			if (bstrSource) {
				for (j = 0;i < (nSize - 2) && bstrSource[j]; i++) {
					sz[i] = bstrSource[j];
				}
				sz[i++] = L':';
			}
			if (bstrDescription) {
				for (j = 0;i < (nSize - 1) && bstrDescription[j]; i++) {
					sz[i] = bstrDescription[j];
				}
			}
			sz[i] = L'\0';
		#else
			int i = 0;
			if (bstrSource) {
				i += ::WideCharToMultiByte(uCP,0,bstrSource,-1,&sz[i],nSize - i - 1,NULL,NULL);
				if (i > 0) sz[i-1] = ' ';
			}
			if (bstrDescription) {
				i += ::WideCharToMultiByte(uCP,0,bstrDescription,-1,&sz[i],nSize - i - 1,NULL,NULL);
			}
			sz[i] = '\0';
		#endif

		return S_OK;
    }
    HRESULT FillIn() {
        if (pfnDeferredFillIn) {
             return (*(pfnDeferredFillIn))(this);
        }
        return S_OK;
    }
    HRESULT ToErrorInfo(REFGUID riid = GUID_NULL) {
		HRESULT				hr;
		ICreateErrorInfo*	pcei = NULL;
		IErrorInfo*			pei = NULL;
		hr = ::CreateErrorInfo(&pcei);
		if (FAILED(hr)) return hr;
		// Transfer the information
		hr = pcei->SetGUID(riid);
		if (FAILED(hr)) goto _CCEI_Err_Exit0;
		if (bstrDescription) hr = pcei->SetDescription(bstrDescription);
		if (FAILED(hr)) goto _CCEI_Err_Exit0;
		if (bstrSource) hr = pcei->SetSource(bstrSource);
		if (FAILED(hr)) goto _CCEI_Err_Exit0;
        if (bstrHelpFile) hr = pcei->SetHelpFile(bstrHelpFile);
		if (FAILED(hr)) goto _CCEI_Err_Exit0;
	
		hr = pcei->QueryInterface(IID_IErrorInfo,(void**)&pei);
		if (FAILED(hr)) goto _CCEI_Err_Exit0;
		hr = ::SetErrorInfo(0,pei);
		pei->Release();

	  _CCEI_Err_Exit0:
		pcei->Release();
		return hr;
    }
    HRESULT FromErrorInfo(HRESULT hrRes = DISP_E_EXCEPTION) {
        Clear();
        scode = hrRes;
        wCode = 1;
        IErrorInfo* pei = NULL;
        HRESULT hr = ::GetErrorInfo(0,&pei);
        if (FAILED(hr)) {
            return hr;
        }
        hr = pei->GetDescription(&bstrDescription);
        if (FAILED(hr)) goto _CCFromErrorInfo_0_Exit0;
        hr = pei->GetSource(&bstrSource);
        if (FAILED(hr)) goto _CCFromErrorInfo_0_Exit0;
        hr = pei->GetHelpFile(&bstrHelpFile);
        if (FAILED(hr)) goto _CCFromErrorInfo_0_Exit0;
        hr = pei->GetHelpContext(&dwHelpContext);

      _CCFromErrorInfo_0_Exit0:
        pei->Release();
        return hr;
    };
    HRESULT SetInfo(LPCTSTR szSrc = NULL,LPCTSTR szDesc = NULL,LPCTSTR szHlp = NULL,HRESULT hrRes = DISP_E_EXCEPTION,UINT uCP = CP_ACP) {
        Clear();
        wCode = 1;
        scode = hrRes;
        if (szSrc) {
            bstrSource = _PackInBSTR(szSrc,uCP);
            if (!bstrSource) return E_OUTOFMEMORY;
        }
        if (szDesc) {
            bstrDescription = _PackInBSTR(szDesc,uCP);
            if (!bstrDescription) return E_OUTOFMEMORY;
        }
        if (szHlp) {
            bstrHelpFile = _PackInBSTR(szHlp,uCP);
            if (!bstrHelpFile) return E_OUTOFMEMORY;
        }
        return hrRes;
    }

    
    void    Clear() {
        if (bstrSource) ::SysFreeString(bstrSource);
	    if (bstrDescription) ::SysFreeString(bstrDescription);
	    if (bstrHelpFile) ::SysFreeString(bstrHelpFile);
	    ZeroMemory(this,sizeof(EXCEPINFO));
    }                                              
    HRESULT Copy(const EXCEPINFO* pei) {
        Clear();
        if (pei) {
            wCode = pei->wCode;
            wReserved = pei->wReserved;
            if (pei->bstrSource) {
                bstrSource = ::SysAllocString(pei->bstrSource);
                if (!bstrSource) return E_OUTOFMEMORY;
            }
            if (pei->bstrDescription) {
                bstrDescription = ::SysAllocString(pei->bstrDescription);
                if (!bstrDescription) return E_OUTOFMEMORY;
            }
            if (pei->bstrHelpFile) {
                bstrHelpFile = ::SysAllocString(pei->bstrHelpFile);
                if (!bstrHelpFile) return E_OUTOFMEMORY;
            }
            dwHelpContext = pei->dwHelpContext;
            pvReserved = pei->pvReserved;
            pfnDeferredFillIn = pei->pfnDeferredFillIn;
            scode = pei->scode;
        }
        return S_OK;
    }
};


#endif // _TPOOLLIBRARY_AUTMATIONHLP_TYPEPACKERS_H_