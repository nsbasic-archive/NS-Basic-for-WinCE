#include <TPoolLibrary/automationhlp.h>

// <winerror.h>
// DISPCALLER

HRESULT DISPCALLER::CoCreateInstance(LPTSTR szID,DWORD dwContext) {
    BSTR bstrID = _PackInBSTR(szID);
    if (!bstrID) return E_INVALIDARG;
    
    CLSID	clsid;
    HRESULT hr;
    hr = CLSIDFromString(bstrID,&clsid);
    if (FAILED(hr)) { // Try as progID
        hr = CLSIDFromProgID(bstrID,&clsid);
        if (FAILED(hr)) {
            ::SysFreeString(bstrID);
            return hr;
        }
    }
    // If we are here we have the CLSID
    ::SysFreeString(bstrID);
    return CoCreateInstance(clsid,dwContext);
}
HRESULT DISPCALLER::CoCreateInstance(CLSID& clsid,DWORD dwContext) {
    Release();
    return ::CoCreateInstance(clsid,NULL,dwContext,IID_IDispatch,(void**)&m_pDisp);
}
DISPCALLER& DISPCALLER::operator = (IDispatch* pDisp) {
    if (m_pDisp) m_pDisp->Release();
    DestroyArray();
    m_pDisp = pDisp;
    if (m_pDisp) m_pDisp->AddRef();
    return (*this);
}
DISPCALLER& DISPCALLER::operator <= (IDispatch* pDisp) {
    if (m_pDisp) m_pDisp->Release();
    DestroyArray();
    m_pDisp = pDisp;
    return (*this);
}
DISPCALLER& DISPCALLER::operator = (IUnknown* pUnk) {
    if (m_pDisp) m_pDisp->Release();
    DestroyArray();
    if (pUnk) {
        HRESULT hr = pUnk->QueryInterface(IID_IDispatch,(void**)&m_pDisp);
        if (FAILED(hr)) m_pDisp = NULL;
    } else {
        m_pDisp = NULL;
    }
    return (*this);
}
int     DISPCALLER::GetParamCount() {
    long    lBound;
    HRESULT hr;

    if (m_psaParameters) {
        hr = SafeArrayGetUBound(m_psaParameters,1, &lBound);
        if (FAILED(hr)) return 0;
        return lBound + 1;
    } else return 0;
}
bool	DISPCALLER::CreateArray() {
	if (m_psaParameters) return TRUE;

	SAFEARRAYBOUND	rgsabound[1];
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = 0;

	m_psaParameters = SafeArrayCreate(VT_VARIANT,1,rgsabound);

    if (m_psaParameters) return true;
	return false;
}
bool	DISPCALLER::DestroyArray() {
    if (m_psaParameters) {
        SafeArrayDestroy(m_psaParameters);
        m_psaParameters = NULL;
    }
	return true;
}
bool	DISPCALLER::AddToArray(VARIANT* v) {
	SAFEARRAYBOUND	rgsabound[1];
	HRESULT			hr;
	long			lIndex;

    if (!m_psaParameters) {
        if (!CreateArray()) return false;
    }
	rgsabound[0].lLbound = 0;
	SafeArrayGetUBound(m_psaParameters,1, (long*)&(rgsabound[0].cElements) );
    
    if ((int)rgsabound[0].cElements < 0) rgsabound[0].cElements = 1;
	else rgsabound[0].cElements += 2;
	hr = SafeArrayRedim(m_psaParameters,rgsabound);
    
	if (FAILED(hr)) return false;

	lIndex = rgsabound[0].cElements - 1;
	hr = SafeArrayPutElement(m_psaParameters,&lIndex,v);
	if (FAILED(hr)) return false;
	return true;
}

// Operators
DISPCALLER& DISPCALLER::operator << (VARIANT_BOOL v) {
    VARIANT     var;

    VariantInit(&var);
    var.vt      = VT_BOOL;
    var.boolVal    = v;

    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var); // realy not needed here ;))
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (int v) {
    VARIANT     var;

    VariantInit(&var);
    var.vt      = VT_I4;
    var.lVal    = (long)v;

    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var); // realy not needed here ;))
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (long v) {
    VARIANT     var;

    VariantInit(&var);
    var.vt      = VT_I4;
    var.lVal    = v;

    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var); // realy not needed here ;))
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (BYTE v) {
    VARIANT     var;

    VariantInit(&var);
    var.vt      = VT_UI1;
    var.bVal    = v;

    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var); // realy not needed here ;))
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (float v) {
    VARIANT     var;

    VariantInit(&var);
    var.vt      = VT_R4;
    var.fltVal  = v;

    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var);
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (double v) {
    VARIANT     var;

    VariantInit(&var);
    var.vt      = VT_R8;
    var.dblVal  = v;

    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var);
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (LPCTSTR v) {
    VARIANT     var;
    BSTR        bstrValue;

    VariantInit(&var);
    if (v) {
        #ifdef UNICODE
            // no conversion
            bstrValue = SysAllocString(v);
        #else  // NO UNICODE
            // Conversion
            OLECHAR*    pwszValue;
            pwszValue = new OLECHAR[lstrlen(v) +1];
            // 
            if (MultiByteToWideChar(CP_ACP,0,v,-1,pwszValue,(lstrlen(v) +1))) {
                // conversion successful
                bstrValue = SysAllocString(pwszValue);
            } else {
                // Error
            }
            delete [] pwszValue;
        #endif // UNICODE 
        var.vt      = VT_BSTR;
        var.bstrVal = bstrValue;
    }
    if (!AddToArray(&var)) {
        // Error code
    }
    
    VariantClear(&var); // Release this string
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (BSTR v) {
    VARIANT var;
    VariantInit(&var);
    if (v) {
        var.vt = VT_BSTR;
        var.bstrVal = v;
    }
    if (!AddToArray(&var)) {
        // Error code
    }
    // Don't clear the variant !!! BSTR is not copied.
    // Missing VariantClear is not an error.
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (IUnknown* v) {
    
    VARIANT     var;
    VariantInit(&var);
    if (v) {
        var.vt = VT_UNKNOWN;
        var.punkVal = v;
        v->AddRef();
    }
     
    if (!AddToArray(&var)) {
        // Error code
    }
    VariantClear(&var); // Releases IUnknow
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (IDispatch* v) {
    VARIANT     var;

    VariantInit(&var);
    if (v) {
        var.vt      = VT_DISPATCH;
        var.punkVal = v;
        v->AddRef();
    }
    
    if (!AddToArray(&var)) {
        // Error code
    }

    VariantClear(&var); // Releases IDispatch
    return (*this);
}
DISPCALLER& DISPCALLER::operator << (VARIANT v) {
    if (!AddToArray(&v)) {
        // Error code
    }
    return (*this);
}

// Helpers
VARIANT  DISPCALLER::VariantBool(bool b) {
    VARIANT     v;

    VariantInit(&v);
    v.vt        = VT_BOOL;
    v.boolVal   = (b)?TRUE:FALSE;
    return v;
}
VARIANT     DISPCALLER::VariantError(HRESULT hr) {
    VARIANT     v;

    VariantInit(&v);
    v.vt        = VT_ERROR;
    v.scode    = hr;
    return v;
}

// Callers

VARIANT     DISPCALLER::VariantCall(LPCTSTR szMethod,EXCEPINFO* pExcep,WORD wContext) {
    HRESULT             hr;
    VARIANT             varResult;
    ::VariantInit(&varResult);
    
    hr = Call(szMethod,&varResult,pExcep,wContext);

    return varResult;
}
// By ID
VARIANT     DISPCALLER::VariantCall(DISPID dispid,EXCEPINFO* pExcep,WORD wContext) {

    HRESULT             hr;
    VARIANT             varResult;

    ::VariantInit(&varResult);
    
    hr = Call(dispid,&varResult,pExcep,wContext);

    return varResult;
}

HRESULT     DISPCALLER::Call(LPCTSTR szMethod,VARIANT* pvResult,EXCEPINFO* pExcep,WORD wContext) {
    HRESULT             hr;
    BSTR                bstrMethod;

    // Parameters are packed in the variant - this is not required 
    // but we have other plans

    if (!m_pDisp) {
        DestroyArray();
        return E_NOINTERFACE;
    }
    
    DISPID		dispid;

    bstrMethod = _PackInBSTR(szMethod);

    hr = m_pDisp->GetIDsOfNames(IID_NULL,&bstrMethod,1,LOCALE_SYSTEM_DEFAULT,&dispid);
    SysFreeString(bstrMethod);
    if (FAILED(hr)) {         // <winerror.h>
        DestroyArray();
        return hr;
    }

    return Call(dispid,pvResult,pExcep,wContext);
}
HRESULT     DISPCALLER::Call(DISPID dispid,VARIANT* pvResult,EXCEPINFO* pExcep,WORD wContext) {
    HRESULT             hr;
    VARIANT             varResult;

    // Parameters are packed in the variant - this is not required 
    // but we have other plans

    if (!m_pDisp) {
        DestroyArray();
        if (pvResult) (*pvResult) = VariantError(E_NOINTERFACE);
        return E_NOINTERFACE;
    }
    
    VariantInit(&varResult);
    

    long		lLBound,lUBound;
	long		lElements;
    DISPPARAMS	dispparams;
    DISPID      didPutProp = DISPID_PROPERTYPUT;

    if (m_psaParameters) {
		// In the parameters are more than 0 - they are packed in the array

		SafeArrayGetLBound(m_psaParameters,1,&lLBound);
		SafeArrayGetUBound(m_psaParameters,1,&lUBound);
		lElements = lUBound - lLBound + 1;
		if (lElements > 0) {
			// more than 0
            hr = SafeArrayAccessData(m_psaParameters,(void**)&dispparams.rgvarg);
            if (FAILED(hr)) {
                DestroyArray();
                if (pvResult) (*pvResult) = VariantError(hr);
                return hr;
            }
			
			dispparams.cArgs = lElements;
            if (wContext == DISPATCH_PROPERTYPUT || wContext == DISPATCH_PROPERTYPUTREF) {
                dispparams.rgdispidNamedArgs = &didPutProp;
                dispparams.cNamedArgs = 1;
            } else {
                dispparams.cNamedArgs = 0;
			    dispparams.rgdispidNamedArgs = NULL;
            }
            
			hr = m_pDisp->Invoke(dispid,IID_NULL,LOCALE_SYSTEM_DEFAULT,wContext,&dispparams,&varResult,pExcep,NULL);
			// Clear variants
            SafeArrayUnaccessData(m_psaParameters);
            DestroyArray();
            if (!FAILED(hr)) {
                if (pvResult) {
                    hr = ::VariantCopyInd(pvResult,&varResult);
                }
                ::VariantClear(&varResult);
                return S_OK;
            } else {
                // There is no need to call VariantClear on that variant
                // because it does not contain any data that needs freing memory
                if (pvResult) (*pvResult) = VariantError(hr);
                return hr;
            }

		} else {
			// incorrect
            DestroyArray();
            if (pvResult) (*pvResult) = VariantError();
            return E_FAIL;
		}	
	} 
    // Without parameters
    DestroyArray();

	dispparams.rgvarg = NULL;
	dispparams.cArgs = 0;
	dispparams.cNamedArgs = 0;
	dispparams.rgdispidNamedArgs = NULL;
	hr = m_pDisp->Invoke(dispid,IID_NULL,LOCALE_SYSTEM_DEFAULT,wContext,&dispparams,&varResult,pExcep,NULL);

    if (!FAILED(hr)) {
        if (pvResult) {
            hr = ::VariantCopyInd(pvResult,&varResult);
        }
        ::VariantClear(&varResult);
        return hr;
    } else {
        // There is no need to call VariantClear on that variant
        // because it does not contain any data that needs freing memory
        if (pvResult) (*pvResult) = VariantError(hr);
        return hr;
    }
}

VARIANT     DISPCALLER::GetProperty(LPCTSTR szMethod,EXCEPINFO* pExcep) {
    return VariantCall(szMethod,pExcep,DISPATCH_PROPERTYGET);
}
VARIANT     DISPCALLER::PutProperty(LPCTSTR szMethod,EXCEPINFO* pExcep) {
    return VariantCall(szMethod,pExcep,DISPATCH_PROPERTYPUT);
}
VARIANT     DISPCALLER::PutPropertyRef(LPCTSTR szMethod,EXCEPINFO* pExcep) {
    return VariantCall(szMethod,pExcep,DISPATCH_PROPERTYPUTREF);
}
VARIANT     DISPCALLER::GetProperty(DISPID dispid,EXCEPINFO* pExcep) {
    return VariantCall(dispid,pExcep,DISPATCH_PROPERTYGET);
}
VARIANT     DISPCALLER::PutProperty(DISPID dispid,EXCEPINFO* pExcep) {
    return VariantCall(dispid,pExcep,DISPATCH_PROPERTYPUT);
}
VARIANT     DISPCALLER::PutPropertyRef(DISPID dispid,EXCEPINFO* pExcep) {
    return VariantCall(dispid,pExcep,DISPATCH_PROPERTYPUTREF);
}





// VARIANTENUM

VARIANTENUM::VARIANTENUM() {
    ::VariantInit(this);
    m_pEnum = NULL;
    m_bAtEnd = false;
}
VARIANTENUM::VARIANTENUM(IUnknown* pUnk) {
    ::VariantInit(this);
    m_bAtEnd = false;
    DISPCALLER dc(pUnk);
    HRESULT hr;
    IUnknown* pUnkEnum = NULL;
    if (dc.IsValid()) {
        // Obtain enum
        VARIANT var;
        ::VariantInit(&var);
        var = dc.GetProperty(DISPID_NEWENUM);
        if (var.vt == VT_UNKNOWN) {
            pUnkEnum = var.punkVal;
            pUnkEnum->AddRef();
        }
        ::VariantClear(&var);
        dc.Release();
    } else {
        pUnkEnum = pUnk;
        if (pUnkEnum) pUnkEnum->AddRef();
    }
    if (pUnkEnum) {
        hr = pUnkEnum->QueryInterface(IID_IEnumVARIANT,(void**)&m_pEnum);
        if (FAILED(hr)) {
            m_pEnum = NULL;
        } else {
            // Move to the first
            Next();
        }
    }
}
VARIANTENUM::VARIANTENUM(IEnumVARIANT* pEnm) {
    ::VariantInit(this);
    m_pEnum = pEnm;
    if (m_pEnum) m_pEnum->AddRef();
    m_bAtEnd = false;
    Next();
}
VARIANTENUM::~VARIANTENUM() {
    if (m_pEnum) m_pEnum->Release();
}

bool            VARIANTENUM::Next() {
    HRESULT hr;
    ::VariantClear((VARIANT*)this);
    if (m_pEnum) {
        ULONG   uFetched;
        hr = m_pEnum->Next(1,(VARIANT*)this,&uFetched);
        if (hr == S_OK) return true;
        else {
            m_bAtEnd = true;
        }
    }
    return false;
}
bool            VARIANTENUM::Reset() {
    HRESULT hr;
    ::VariantClear((VARIANT*)this);
    if (m_pEnum) {
        hr = m_pEnum->Reset();
        if (hr == S_OK) {
            return Next();
        }
    }
    return false;
}
bool            VARIANTENUM::Skip(int n) {
    HRESULT hr;
    ::VariantClear((VARIANT*)this);
    if (m_pEnum) {
        hr = m_pEnum->Skip((ULONG)n);
        if (hr == S_OK) {
            return Next();
        }
    }
    return false;
}
VARIANTENUM&    VARIANTENUM::operator = (VARIANTENUM& ve) {
    Clear();
    HRESULT hr;
    if (ve.IsValid()) {
        hr = ve.m_pEnum->Clone(&m_pEnum);
        if (!FAILED(hr)) {
            Reset();
        }
    }
    return (*this);
}
VARIANTENUM&    VARIANTENUM::operator = (IUnknown* pUnk) {
    Clear();
    m_bAtEnd = false;
    DISPCALLER dc(pUnk);
    HRESULT hr;
    IUnknown* pUnkEnum = NULL;
    if (dc.IsValid()) {
        // Obtain enum
        VARIANT var;
        ::VariantInit(&var);
        var = dc.GetProperty(DISPID_NEWENUM);
        if (var.vt == VT_UNKNOWN) {
            pUnkEnum = var.punkVal;
            pUnkEnum->AddRef();
        }
        ::VariantClear(&var);
        dc.Release();
    } else {
        pUnkEnum = pUnk;
        if (pUnkEnum) pUnkEnum->AddRef();
    }
    if (pUnkEnum) {
        hr = pUnkEnum->QueryInterface(IID_IEnumVARIANT,(void**)&m_pEnum);
        if (FAILED(hr)) {
            m_pEnum = NULL;
        } else {
            // Move to the first
            Next();
        }
    }
    return (*this);
}
VARIANTENUM&    VARIANTENUM::operator = (IEnumVARIANT* pEnm) {
    Clear();
    m_pEnum = pEnm;
    if (m_pEnum) m_pEnum->AddRef();
    m_bAtEnd = false;
    return (*this);
}


HRESULT VariantResolveToValue(VARIANT* pvarDest,VARIANT* pvarSrc) {
	if (!pvarDest || !pvarSrc) return E_POINTER;
	VARIANT v;
	::VariantInit(&v);
	
	HRESULT hr;
	hr = ::VariantCopyInd(&v,pvarSrc);
    if (FAILED(hr)) {
        ::VariantClear(&v);
        return hr;
    }
	if (v.vt == VT_UNKNOWN || v.vt == VT_DISPATCH) {
		// Extract value
        VARIANT v1;
		::VariantInit(&v1);
		DISPCALLER dc((IUnknown*)v.punkVal);
		if (!dc.IsValid()) {
			::VariantClear(&v);
            ::VariantClear(&v1);
			return E_FAIL;
		}
		::VariantClear(&v);
		v1 = dc.GetProperty((DISPID)DISPID_VALUE);
		hr = VariantResolveToValue(pvarDest,&v1);
		::VariantClear(&v1);
		return hr;
	}
	hr = ::VariantCopy(pvarDest,&v);
    ::VariantClear(&v);
    return hr;
}

void ClearExcepInfo(EXCEPINFO* pe) {
	// Free the EXCEPINFO
	if (pe->bstrSource) SysFreeString(pe->bstrSource);
	if (pe->bstrDescription) SysFreeString(pe->bstrDescription);
	if (pe->bstrHelpFile) SysFreeString(pe->bstrHelpFile);
	ZeroMemory(pe,sizeof(EXCEPINFO));
}
HRESULT	ConsumeExcepInfo(EXCEPINFO* pe,LPTSTR sz,int nSize,UINT uCP) {
	if (!pe) {
		if (sz && nSize > 0) {
			sz[0] = TEXT('\0');
		}
		return S_FALSE;
	} else {
		// Fill deferred information if needed
		if (pe->pfnDeferredFillIn) {
             (*(pe->pfnDeferredFillIn))(pe);
        }

		#ifdef UNICODE
			int j,i = 0;
			if (pe->bstrSource) {
				for (j = 0;i < (nSize - 2) && pe->bstrSource[j]; i++) {
					sz[i] = pe->bstrSource[j];
				}
				sz[i++] = L':';
			}
			if (pe->bstrDescription) {
				for (j = 0;i < (nSize - 1) && pe->bstrDescription[j]; i++) {
					sz[i] = pe->bstrDescription[j];
				}
			}
			sz[i] = L'\0';
		#else
			int i = 0;
			if (pe->bstrSource) {
				i += ::WideCharToMultiByte(uCP,0,pe->bstrSource,-1,&sz[i],nSize - i - 1,NULL,NULL);
				if (i > 0) sz[i-1] = ' ';
			}
			if (pe->bstrDescription) {
				i += ::WideCharToMultiByte(uCP,0,pe->bstrDescription,-1,&sz[i],nSize - i - 1,NULL,NULL);
			}
			sz[i] = '\0';
		#endif

		// Free the EXCEPINFO
		ClearExcepInfo(pe);
		return S_OK;
	}
}
HRESULT	ConsumeExcepInfoToErrorInfo(EXCEPINFO* pe,REFGUID riid) {
	if (!pe) {
		return S_FALSE;
	} else {
		if (pe->pfnDeferredFillIn) {
             (*(pe->pfnDeferredFillIn))(pe);
        }
		HRESULT				hr;
		ICreateErrorInfo*	pcei = NULL;
		IErrorInfo*			pei = NULL;
		hr = ::CreateErrorInfo(&pcei);
		if (FAILED(hr)) return hr;
		// Transfer the information
		hr = pcei->SetGUID(riid);
		if (FAILED(hr)) goto _CEI_Err_Exit0;
		if (pe->bstrDescription) hr = pcei->SetDescription(pe->bstrDescription);
		if (FAILED(hr)) goto _CEI_Err_Exit0;
		if (pe->bstrSource) hr = pcei->SetSource(pe->bstrSource);
		if (FAILED(hr)) goto _CEI_Err_Exit0;
	
		hr = pcei->QueryInterface(IID_IErrorInfo,(void**)&pei);
		if (FAILED(hr)) goto _CEI_Err_Exit0;
		hr = ::SetErrorInfo(0,pei);
		pei->Release();

	  _CEI_Err_Exit0:
		pcei->Release();
		ClearExcepInfo(pe);
		return hr;
	}
}

HRESULT PackDataInSafeArray(LPBYTE pb,ULONG ulSize,SAFEARRAY** ppArray) {
    if (!pb || !ppArray) return E_POINTER;
    if (ulSize < 0) return E_INVALIDARG;
    
    // Prepare empty Array VT_UI1
    SAFEARRAY*      psa;
    SAFEARRAYBOUND  sab;
    sab.lLbound = 0;
    sab.cElements = (ULONG)ulSize;

    psa = SafeArrayCreate(VT_UI1,1,&sab);

    if (!psa) return E_OUTOFMEMORY;

    // Array is ready
    // Access data
    HRESULT hr;
    LPVOID  pData;

    hr = SafeArrayAccessData(psa,&pData);
    if (FAILED(hr)) {
        SafeArrayDestroy(psa);
        return hr;
    }
    // Fill data
    CopyMemory(pData,pb,ulSize);
    
    hr = SafeArrayUnaccessData(psa);
    if (FAILED(hr)) {
        SafeArrayDestroy(psa);
        return hr;
    }
    *ppArray = psa;
	return S_OK;
}
HRESULT UnPackDataFromSafeArray(SAFEARRAY* psa,LPBYTE* ppBuff,ULONG* pulSize) {
    if (!ppBuff || !pulSize || !psa) return E_POINTER;

    HRESULT     hr;
    
    // Unpack array data
    long  lLBound,lUBound;
    LPVOID  pData;

    hr = SafeArrayGetLBound(psa,1,&lLBound);
    if (FAILED(hr)) return hr;
    hr = SafeArrayGetUBound(psa,1,&lUBound);
    if (FAILED(hr)) return hr;

    if (lUBound < lLBound) {
        *ppBuff = NULL;
        pulSize = 0;
        return S_OK; // Empty array
    }

    hr = SafeArrayAccessData(psa,&pData);
    if (FAILED(hr)) return hr;

    long cb = lUBound - lLBound + 1;
    *ppBuff = new BYTE[cb];
    CopyMemory(*ppBuff,pData,cb);
    SafeArrayUnaccessData(psa);

    *pulSize = (ULONG)cb;
	return S_OK;
}

HRESULT PackDataInVariant(LPBYTE pb,ULONG ulSize,VARIANT* pVar) {
    SAFEARRAY* psa = NULL;
    HRESULT hr = PackDataInSafeArray(pb,ulSize,&psa);
    if (FAILED(hr)) return hr;
    ::VariantInit(pVar);
    pVar->vt = VT_UI1 | VT_ARRAY;
    pVar->parray = psa;
    return S_OK;
}
HRESULT UnPackDataFromVariant(VARIANT v,LPBYTE* ppBuff,ULONG* pulSize) {
    VARIANT vTemp;
    ::VariantInit(&vTemp);
    HRESULT hr = ::VariantCopyInd(&vTemp,&v);
    if (FAILED(hr)) return hr;
    if ( (vTemp.vt & (VT_ARRAY | VT_UI1)) != (VT_ARRAY | VT_UI1)) {
        ::VariantClear(&vTemp);
        return DISP_E_TYPEMISMATCH;
    }
    SAFEARRAY* psa;
    psa = vTemp.parray;
    if (!psa) return DISP_E_TYPEMISMATCH;
	
    
    hr = UnPackDataFromSafeArray(psa,ppBuff,pulSize);
	::VariantClear(&vTemp);
	return hr;
}


// Functions
BSTR    _PackInBSTRA(LPCSTR sz,UINT uCP) {
    register int i;
    i = ::MultiByteToWideChar(uCP,0,sz,-1,NULL,0);
    if (!i) return NULL;
    LPWSTR   _pwsz = new WCHAR[i];
    if (!_pwsz) return NULL;
    BSTR     bstr = NULL;
    if (MultiByteToWideChar(uCP,0,sz,-1,_pwsz,i)) {
        bstr = SysAllocString((LPCOLESTR)_pwsz);
        delete [] _pwsz;
    }
    return bstr;
}
BSTR    _PackInBSTR(LPCTSTR sz,UINT uCP) {
    if (!sz) return NULL;
    #ifdef UNICODE
        return SysAllocString(sz);
    #else
        return _PackInBSTRA(sz,uCP);
    #endif
}
LPSTR   _UnPackBSTRA(BSTR bstr,UINT uCP) {
    if (!bstr) return NULL;
    register int i;
    i = ::WideCharToMultiByte(uCP,0,bstr,-1,NULL,0,NULL,NULL);
    if (!i) return NULL;
    LPSTR   _psz = new CHAR[i];
    if (!_psz) return NULL;
    if (WideCharToMultiByte(uCP,0,bstr,-1,_psz,i,NULL,NULL)) {
        return _psz;
    } else {
        delete [] _psz;
        return NULL;
    }
}
LPTSTR   _UnPackBSTR(BSTR bstr,UINT uCP) {
    if (!bstr) return NULL;
    #ifdef UNICODE
        return bstr;
    #else
        return _UnPackBSTRA(bstr,uCP);
    #endif
}
