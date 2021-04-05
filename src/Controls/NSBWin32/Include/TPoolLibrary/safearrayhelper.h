#ifndef _TPOOLLIBRARY_SAFEARRAYHELPER_H_
#define _TPOOLLIBRARY_SAFEARRAYHELPER_H_

#pragma message("Including ccSafeArray (safearrayhelper.h)")

template <class T,VARTYPE VT = VT_VARIANT>
class ccSafeArray;

/* not used yet
template <class T,VARTYPE VT = VT_VARIANT>
class ccSafeArrayIndexer {
public:
    long    m_cIndices;
    long*   m_plIndices;

    ccSafeArrayIndexer(long nIndices) {
        m_cIndices = nIndices;
        m_pIndices = new long[nIndices];
        if (m_pIndices) {
            ZeroMemory(m_pIndices,sizeof(long) * nIndices);
        }
    }
    ccSafeArrayIndexer(ccSafeArrayIndexer& sai) {
        m_cIndices = sai.m_cIndices;
        m_pIndices = new long[sai.m_cIndices];
        if (m_pIndices) {
            CopyMemory(m_pIndices,sai.m_pIndices,sizeof(long) * sai.m_cIndices);
        }
    }
    ~ccSafeArrayIndexer() {
        if (m_pIndices) delete [] m_pIndices;
    }

    ccSafeArrayIndexer  operator [] (long l) {
    }

};
*/ 


// Type of the array alements
template <class T,VARTYPE VT = VT_VARIANT>
class ccSafeArray {
public:
    SAFEARRAY*  psa;
    LPVOID      pv; // Pointer for directly accessed array - if not null. Automatically unaccessed by the operations that need this

    ccSafeArray() {
        psa = NULL;
        pv = NULL;
    }
    ccSafeArray(SAFEARRAY* psaInit) {
        psa = psaInit;
        pv = NULL;
    }
    ccSafeArray(ccSafeArray& sa) {
        if (FAILED(::SafeArrayCopy(sa.psa,&psa))) {
            psa = NULL;
        }
        pv = NULL;
    }
    ~ccSafeArray() {
        if (pv) ::SafeArrayUnaccessData(psa);
        if (psa) ::SafeArrayDestroy(psa);
    }
    BOOL    IsValid() {
        return (psa)?TRUE:FALSE;
    }

    HRESULT CopyFrom(SAFEARRAY* psaIn) {
        if (psa) return E_UNEXPECTED;
        pv = NULL;
        if (FAILED(::SafeArrayCopy(sa.psa,&psa))) {
            psa = NULL;
        }
        return (psa)?S_OK:E_OUTOFMEMORY;
    }
    SAFEARRAY*  Copy() {
        if (!psa) return NULL;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        SAFEARRAY* psaOut = NULL;
        if (FAILED(::SafeArrayCopy(psa,&psaOut))) return NULL;
        return psaOut;
    }
    HRESULT  CopyTo(SAFEARRAY** psaOut) {
        if (!psaOut) return E_POINTER;
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        *psaOut = NULL;
        HRESULT hr = ::SafeArrayCopy(psa,psaOut);
        return hr;
    }
    HRESULT  CopyTo(VARIANT* pvOut) {
        if (!pvOut) return E_POINTER;
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        HRESULT hr = ::SafeArrayCopy(psa,&pvOut->parray);
        if (FAILED(hr)) {
            pvOut->vt = VT_EMPTY;
        } else {
            pvOut->vt = VT_ARRAY | VT;
        }
        return hr;
    }


    HRESULT Destroy() {
        if (psa) {
            if (pv) ::SafeArrayUnaccessData(psa);
            pv = NULL;
            ::SafeArrayDestroy(psa);
        }
        psa = NULL;
        return S_OK;
    }
    SAFEARRAY*  Detach() {
        if (psa && pv) ::SafeArrayUnaccessData(psa);
        SAFEARRAY*  psaOut = psa;
        psa = NULL;
        pv = NULL;
        return psaOut;
    }
    void        Attach(SAFEARRAY* psaIn) {
        Destroy();
        psa = In;
    }
    BOOL        Valid() {
        return (psa)?TRUE:FALSE;
    }
    ccSafeArray&    operator = (ccSafeArray& sa) {
        Destroy();
        if (FAILED(::SafeArrayCopy(sa.psa,&psa))) {
            psa = NULL;
        }
        return (*this);
    }
    ccSafeArray&    operator = (SAFEARRAY* psaIn) {
        Destroy();
        psa = psaIn;
        return (*this);
    }
    ccSafeArray&    operator <= (SAFEARRAY* psaIn) {
        Destroy();
        if (FAILED(::SafeArrayCopy(psaIn,&psa))) {
            psa = NULL;
        }
        return (*this);
    }
    operator SAFEARRAY* () {
        if (pv) return NULL; // Not permitted when locked
        return psa;
    }
    // Note this one must be used with CARE!!!
    SAFEARRAY**     operator & () {
        return &psa;
    }
    HRESULT __cdecl Create(unsigned int cDims,...) {     // Dimensions and UINT cElements for each dimension
        if (psa) return E_UNEXPECTED;
        ULONG i;
        SAFEARRAYBOUND* psab;
        psab = new SAFEARRAYBOUND[cDims];
        if (!psab) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,cDims);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                psab[i].lLbound = 0;
                psab[i].cElements = va_arg(marker,unsigned int);
            }
        va_end(marker);                     // Reset variable arguments
        psa = ::SafeArrayCreate(VT,cDims,psab);
        delete [] psab;
        if (!psa) return E_OUTOFMEMORY;       
        return S_OK;
    }
    HRESULT __cdecl Create2(unsigned int cDims,...) {    // Dimensions and LONG LBound, LONG UBound pairs
        if (psa) return E_UNEXPECTED;
        long i;
        SAFEARRAYBOUND* psab;
        psab = new SAFEARRAYBOUND[cDims];
        if (!psab) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,cDims);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                psab[i].lLbound = va_arg(marker,long);
                psab[i].cElements = va_arg(marker,long) - psab[i].lLbound + 1;
            }
        va_end(marker);                     // Reset variable arguments
        psa = ::SafeArrayCreate(VT,cDims,psab);
        delete [] psab;
        if (!psa) return E_OUTOFMEMORY;
        return S_OK;
    }
    UINT    Dims() {
        if (!psa) return 0;
        return ::SafeArrayGetDim(psa);
    }
    UINT    Elements(unsigned int uDim = 1) {
        if (!psa) return 0;
        LONG    lLBound,lUBound;
        HRESULT hr;
        hr = ::SafeArrayGetLBound(psa,uDim,&lLBound);
        if (FAILED(hr)) return 0;
        hr = ::SafeArrayGetUBound(psa,uDim,&lUBound);
        if (FAILED(hr)) return 0;

        return (lUBound >= lLBound)?(lUBound - lLBound + 1):0;
    }
    long    LBound(unsigned int uDim = 1) {
        if (!psa) return 0;
        long    l = 0;
        ::SafeArrayGetLBound(psa,uDim,&l);
        return l;
    }
    long    UBound(unsigned int uDim = 1) {
        if (!psa) return 0;
        long    l = 0;
        ::SafeArrayGetUBound(psa,uDim,&l);
        return l;
    }
    UINT    ElementSize() {
        if (!psa) return 0;
        return ::SafeArrayGetElemsize(psa);
    }
    HRESULT Redim(unsigned int cElements) {   // only the cElements of the last dimension can be changed
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        UINT    i;
        UINT    uDims = Dims();
        if (uDims < 1) return E_UNEXPECTED;

        SAFEARRAYBOUND* psab;

        psab = new SAFEARRAYBOUND[uDims];
        if (!psab) return E_OUTOFMEMORY;

        for (i = 0;i < uDims; i++) {
            psab[i].lLBound = LBound(uDims - i);
            psab[i].cElements = Elements(uDims - i);
        }
        psab[0].cElements = cElements;
        HRESULT hr = ::SafeArrayRedim(psa,psab);
        delete [] psab;
        return hr;
    }
    HRESULT RedimBound(long lUBound) {   // only the cElements of the last dimension can be changed
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        UINT    i;
        UINT    uDims = Dims();
        if (uDims < 1) return E_UNEXPECTED;

        SAFEARRAYBOUND* psab;

        psab = new SAFEARRAYBOUND[uDims];
        if (!psab) return E_OUTOFMEMORY;

        for (i = 0;i < uDims; i++) {
            psab[i].lLbound = LBound(uDims - i);
            psab[i].cElements = Elements(uDims - i);
        }
        psab[0].cElements = lUBound - psab[0].lLbound + 1;
        HRESULT hr = ::SafeArrayRedim(psa,psab);
        delete [] psab;
        return hr;
    }
    T   operator [] (long lIndex1) { // Works only with 1-dimension arrays
        T   t;
        if (!psa) return t;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        if (Dims() != 1) return t;
        ::SafeArrayGetElement(psa,&lIndex1,&t);
        return t;
    }
    HRESULT  GetElement(T* pt,...) { // The indices must be match the dims!!!! otherwise puff!
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        long    i;
        UINT    cDims = Dims();
        long*   pindices;
        pindices = new long[cDims];
        if (!pindices) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,pt);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                pindices[i] = va_arg(marker,long);
            }
        va_end(marker);                     // Reset variable arguments
        HRESULT hr;
        
        hr = ::SafeArrayGetElement(psa,pindices,(void*)pt);
        
        delete [] pindices;
        return hr;
    }
    HRESULT  PutElement(T pt,...) {
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        ULONG   i;
        UINT    cDims = Dims();
        long*   pindices;
        pindices = new long[cDims];
        if (!pindices) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,pt);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                pindices[i] = va_arg(marker,long);
            }
        va_end(marker);                     // Reset variable arguments
        HRESULT hr;
        /*
            This is implemented as specialized functions below
            if (VT == VT_BSTR || VT == VT_DISPATCH || VT == VT_UNKNOWN) {
                hr = ::SafeArrayPutElement(psa,pindices,(void*)pt);
            } 
        */
        hr = ::SafeArrayPutElement(psa,pindices,(void*)&pt);
        
        delete [] pindices;
        return hr;
    }
    HRESULT Inflate(long l = 1) { // Redims the array inflating it with the specified ammount of data
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        UINT    cDims = Dims();
        long    lUBound = UBound(cDims);
        return RedimBound(lUBound + l);
    }
    HRESULT AddElement(T pt) {
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        UINT    cDims = Dims();
        if (cDims != 1) return E_UNEXPECTED;
        HRESULT hr = Inflate(1);
        if (FAILED(hr)) return hr;
        long    lUBound = UBound();
        return PutElement(pt,lUBound);
    }
    LPVOID  AccessData() {
        if (!psa) return NULL;
        if (pv) return pv;
        HRESULT hr = ::SafeArrayAccessData(psa,&pv);
        if (FAILED(hr)) return NULL;
        return pv;
    }
    HRESULT UnaccessData() {
        if (!psa) return E_UNEXPECTED;
        if (!pv) return S_OK;
        HRESULT hr = ::SafeArrayUnaccessData(psa);
        pv = NULL;
        return hr;
    }

};

// These require <= operators
// for example ccVariant var; var <= array[x];

template<>
VARIANT ccSafeArray<VARIANT,VT_VARIANT>::operator [] (long lIndex1) {
    VARIANT v;
    ::VariantInit(&v);
    if (!psa) return v;
    if (pv) {
        ::SafeArrayUnaccessData(psa);
        pv = NULL;
    }
    if (Dims() > 1) return v;
    ::SafeArrayGetElement(psa,&lIndex1,&v);
    return v;
}
template<>
BSTR ccSafeArray<BSTR,VT_BSTR>::operator [] (long lIndex1) {
    BSTR bstr = NULL;
    if (!psa) return bstr;
    if (pv) {
        ::SafeArrayUnaccessData(psa);
        pv = NULL;
    }
    if (Dims() > 1) return bstr;
    ::SafeArrayGetElement(psa,&lIndex1,&bstr);
    return bstr;
}

template<>
HRESULT  ccSafeArray<BSTR,VT_BSTR>::PutElement(BSTR pt,...) {
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        ULONG   i;
        UINT    cDims = Dims();
        long*   pindices;
        pindices = new long[cDims];
        if (!pindices) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,pt);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                pindices[i] = va_arg(marker,long);
            }
        va_end(marker);                     // Reset variable arguments
        HRESULT hr;
        
        hr = ::SafeArrayPutElement(psa,pindices,(void*)pt);

        delete [] pindices;
        return hr;
}
template<>
HRESULT  ccSafeArray<IDispatch*,VT_DISPATCH>::PutElement(IDispatch* pt,...) {
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        ULONG   i;
        UINT    cDims = Dims();
        long*   pindices;
        pindices = new long[cDims];
        if (!pindices) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,pt);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                pindices[i] = va_arg(marker,long);
            }
        va_end(marker);                     // Reset variable arguments
        HRESULT hr;
        
        hr = ::SafeArrayPutElement(psa,pindices,(void*)pt);

        delete [] pindices;
        return hr;
}
template<>
HRESULT  ccSafeArray<IUnknown*,VT_UNKNOWN>::PutElement(IUnknown* pt,...) {
        if (!psa) return E_UNEXPECTED;
        if (pv) {
            ::SafeArrayUnaccessData(psa);
            pv = NULL;
        }
        ULONG   i;
        UINT    cDims = Dims();
        long*   pindices;
        pindices = new long[cDims];
        if (!pindices) return E_OUTOFMEMORY;

        va_list marker;
        va_start( marker,pt);            // Initialize variable arguments
            for (i = 0;i < cDims; i++) {
                pindices[i] = va_arg(marker,long);
            }
        va_end(marker);                     // Reset variable arguments
        HRESULT hr;
        
        hr = ::SafeArrayPutElement(psa,pindices,(void*)pt);

        delete [] pindices;
        return hr;
}

#endif // _TPOOLLIBRARY_SAFEARRAYHELPER_H_