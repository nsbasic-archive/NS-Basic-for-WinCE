#ifndef _TPOOLLIB_ASYNCMONHELPER_H_
#define _TPOOLLIB_ASYNCMONHELPER_H_

// ATL only class !!!
// This class is an extended version of the simple CBindStatusCallback
// provided in ATL. While it follows the same implementation pattern in order to give you
// a well-known starting point for comparison it is more advanced
// giving you more control over the download process and ability to not only download
// but also upload data

// The constants here are already defined in urlmon.h of the newest Platform SDK-s
// However if you want to use this class with an older SDK you will find that these are
// missing there

#ifndef BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE
    #define BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE	22
    #define BINDSTATUS_CLASSINSTALLLOCATION	        (BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE + 1)
    #define BINDSTATUS_DECODING	                    (BINDSTATUS_CLASSINSTALLLOCATION + 1)
    #define BINDSTATUS_LOADINGMIMEHANDLER           (BINDSTATUS_DECODING + 1)
    #define BINDSTATUS_CONTENTDISPOSITIONATTACH     (BINDSTATUS_LOADINGMIMEHANDLER + 1)
    #define BINDSTATUS_FILTERREPORTMIMETYPE	        (BINDSTATUS_CONTENTDISPOSITIONATTACH + 1)
    #define BINDSTATUS_CLSIDCANINSTANTIATE	        (BINDSTATUS_FILTERREPORTMIMETYPE + 1)
    #define BINDSTATUS_IUNKNOWNAVAILABLE	        (BINDSTATUS_CLSIDCANINSTANTIATE + 1)
    #define BINDSTATUS_DIRECTBIND	                (BINDSTATUS_IUNKNOWNAVAILABLE + 1)
    #define BINDSTATUS_RAWMIMETYPE	                (BINDSTATUS_DIRECTBIND + 1)
    #define BINDSTATUS_PROXYDETECTING	            (BINDSTATUS_RAWMIMETYPE + 1)
    #define BINDSTATUS_ACCEPTRANGES	                (BINDSTATUS_PROXYDETECTING + 1)
#endif

#define     PERMITBIND_INFO_NONNETWORK          0x0001

template <class T, int nBindFlags = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE>
class ATL_NO_VTABLE ccBindStatusCallback :
	public CComObjectRootEx<typename T::_ThreadModel::ThreadModelNoCS>,
	public IBindStatusCallback
{
    // Callback functions prototypes
    // =============================
    // These functions are implemented by your classes that need the data downloaded or supply the upload data.
    // Only the TPOOLLIB_PDATAAVAILABLE is almost always required


	typedef void (T::*TPOOLLIB_PDATAAVAILABLE)(ccBindStatusCallback<T, nBindFlags>* pbsc, BYTE* pBytes, DWORD dwSize);
    typedef void (T::*TPOOLLIB_PPROGRESS)(ccBindStatusCallback<T, nBindFlags>* pbsc, UINT ulProgrss,UINT ulProgressMax,ULONG ulStatusCode, LPCWSTR wszStatusText);
    typedef BOOL (T::*TPOOLLIB_PBINDPERMIT)(ccBindStatusCallback<T, nBindFlags>* pbsc, LPCWSTR wszURL,DWORD dwInfoFlags,LPCWSTR wszSite);

public:

typedef ccBindStatusCallback<T, nBindFlags> thisClass;

BEGIN_COM_MAP(thisClass)
	COM_INTERFACE_ENTRY(IBindStatusCallback)
END_COM_MAP()

	ccBindStatusCallback() {
		m_pT = NULL;
		m_pFunc = NULL;
        m_pFuncProgress = NULL;
        m_pFuncPermit = NULL;
        m_bDispositionAttachment = FALSE;
        m_bFormPost = FALSE;
        m_uCP = CP_ACP;
        m_bstrVerb = TEXT("GET");
        m_spHold.Release();
        m_dwTransferID = 0;
        m_nBindFlags = nBindFlags;
	}
	~ccBindStatusCallback()	{
		ATLTRACE2(atlTraceControls,2,_T("~ccBindStatusCallback\n"));
	}

	STDMETHOD(OnStartBinding)(DWORD /*dwReserved*/, IBinding *pBinding)	{
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::OnStartBinding\n"));
		m_spBinding = pBinding;
		return S_OK;
	}

	STDMETHOD(GetPriority)(LONG *pnPriority) {
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::GetPriority"));
		HRESULT hr = S_OK;
		if (pnPriority)
			*pnPriority = THREAD_PRIORITY_NORMAL;
		else
			hr = E_INVALIDARG;
		return S_OK;
	}

	STDMETHOD(OnLowResource)(DWORD /*reserved*/) {
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::OnLowResource"));
		return S_OK;
	}

	STDMETHOD(OnProgress)(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText)	{
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::OnProgress"));
        switch (ulStatusCode) {
            case BINDSTATUS_MIMETYPEAVAILABLE:
            case BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE:
                m_bstrMimeType = wszStatusText;
            break;
            case BINDSTATUS_CONTENTDISPOSITIONATTACH:
                m_bDispositionAttachment = TRUE;
            break;
        }
        if (m_pFuncProgress) {
            (m_pT->*m_pFuncProgress)(this,ulProgress,ulProgressMax,ulStatusCode,wszStatusText);
        }
		return S_OK;
	}

	STDMETHOD(OnStopBinding)(HRESULT hresult, LPCWSTR /*szError*/)	{
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::OnStopBinding\n"));
		// Pass NULL as the array of bytes to signify the end.
		// Pass the HRESULT for the dwSize parameter
        if (m_pFunc) (m_pT->*m_pFunc)(this, NULL, hresult);
		m_spBinding.Release();
		m_spBindCtx.Release();
		m_spMoniker.Release();
        m_spHold.Release(); // Release the target object
		return S_OK;
	}

	STDMETHOD(GetBindInfo)(DWORD *pgrfBINDF, BINDINFO *pbindInfo) {
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::GetBindInfo\n"));

		if (pbindInfo==NULL || pbindInfo->cbSize==0 || pgrfBINDF==NULL) return E_INVALIDARG;

        USES_CONVERSION;

        HRESULT     hr;

		*pgrfBINDF = m_nBindFlags;

		ULONG cbSize = pbindInfo->cbSize;		// remember incoming cbSize
		memset(pbindInfo, 0, cbSize);			// zero out structure
		pbindInfo->cbSize = cbSize;				// restore cbSize

        LPTSTR  szVerb = W2T(m_bstrVerb);
        if (lstrcmpi(TEXT("GET"),szVerb) == 0 || m_bstrVerb.Length() == 0) {
            pbindInfo->dwBindVerb = BINDVERB_GET;
        } else if (lstrcmpi(szVerb,"POST") == 0) {
            pbindInfo->dwBindVerb = BINDVERB_POST;
            if (m_bFormPost) {
                pbindInfo->grfBindInfoF = BINDINFOF_URLENCODESTGMEDDATA;
            }
        } else if (lstrcmpi(szVerb,"PUT") == 0) {
            pbindInfo->dwBindVerb = BINDVERB_PUT;
        } else {
            pbindInfo->dwBindVerb = BINDVERB_CUSTOM;
            pbindInfo->szCustomVerb = (LPWSTR)CoTaskMemAlloc((m_bstrVerb.Length() + 1) * sizeof(WCHAR));
            CopyMemory(pbindInfo->szCustomVerb,m_bstrVerb.m_str,(m_bstrVerb.Length() + 1) * sizeof(WCHAR));
        }

        if (m_bFormPost) (*pgrfBINDF) |= BINDF_FORMS_SUBMIT;

        hr = PackPostData(&pbindInfo->stgmedData,&pbindInfo->cbstgmedData,pbindInfo->grfBindInfoF);
        if (FAILED(hr)) {
            if (pbindInfo->szCustomVerb) {
                CoTaskMemFree(pbindInfo->szCustomVerb);
                pbindInfo->szCustomVerb = NULL;
            }
            // Nullify the data that can be unsafe in some applications
            pbindInfo->grfBindInfoF = 0;
            pbindInfo->dwBindVerb = BINDVERB_GET;
            return E_INVALIDARG;
        }
        pbindInfo->dwCodePage = m_uCP;		
		return S_OK;
	}

	STDMETHOD(OnDataAvailable)(DWORD grfBSCF, DWORD dwSize, FORMATETC * /*pformatetc*/, STGMEDIUM *pstgmed)	{
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::OnDataAvailable\n"));
		HRESULT hr = S_OK;

		// Get the Stream passed
		if (BSCF_FIRSTDATANOTIFICATION & grfBSCF) {
			if (!m_spStream && pstgmed->tymed == TYMED_ISTREAM)
				m_spStream = pstgmed->pstm;
		}

		DWORD dwRead = dwSize - m_dwTotalRead;  // Minimum amount available that hasn't been read
		DWORD dwActuallyRead = 0;               // Placeholder for amount read during this pull

		// If there is some data to be read then go ahead and read them
		if (m_spStream)	{
			if (dwRead > 0) {
				BYTE* pBytes = NULL;
				ATLTRY(pBytes = new BYTE[dwRead + 1]);
				if (pBytes == NULL) return E_OUTOFMEMORY;
				hr = m_spStream->Read(pBytes, dwRead, &dwActuallyRead);
				if (SUCCEEDED(hr)) {
					pBytes[dwActuallyRead] = 0;
					if (dwActuallyRead>0) {
						if (m_pFunc) (m_pT->*m_pFunc)(this, pBytes, dwActuallyRead);
						m_dwTotalRead += dwActuallyRead;
					}
				}
				delete[] pBytes;
			}
		}

		if (BSCF_LASTDATANOTIFICATION & grfBSCF)
			m_spStream.Release();
		return hr;
	}

	STDMETHOD(OnObjectAvailable)(REFIID /*riid*/, IUnknown * /*punk*/) {
		ATLTRACE2(atlTraceControls,2,_T("ccBindStatusCallback::OnObjectAvailable"));
		return S_OK;
	}

    virtual BOOL    QueryBindPermission() {
        HRESULT     hr;
        BOOL        bPermitted = FALSE;
        LPOLESTR    pwsz = NULL;
        BYTE    tmpbuff[2048];
        DWORD   dw;
        DWORD   dwFlags = 0;

        hr = m_spMoniker->GetDisplayName(m_spBindCtx,NULL,&pwsz);
        if (!FAILED(hr)) {
            
            hr = CoInternetQueryInfo(pwsz,QUERY_USES_NETWORK,0,tmpbuff,16,&dw,0);
            if (!FAILED(hr) && !(*(BOOL*)tmpbuff)) dwFlags |= PERMITBIND_INFO_NONNETWORK;

            LPWSTR  wszRel = L"/";
            hr = CoInternetCombineUrl(pwsz,wszRel,0,(LPWSTR)tmpbuff,1024,&dw,0);
            tmpbuff[2046] = 0;
            tmpbuff[2047] = 0;
            if (FAILED(hr)) {
                bPermitted = (m_pT->*m_pFuncPermit)(this, pwsz, dwFlags,NULL);
            } else {
                bPermitted = (m_pT->*m_pFuncPermit)(this, pwsz, dwFlags, (LPCWSTR)tmpbuff);
            }
            CoTaskMemFree(pwsz);
            return bPermitted;
        }
        return TRUE;
    }

	HRESULT _StartAsyncDownload(BSTR bstrURL, IUnknown* pUnkContainer, long lRelative,LPCWSTR wszBaseURL) {
		m_dwTotalRead = 0;
		m_dwAvailableToRead = 0;
		HRESULT hr = S_OK;
		CComQIPtr<IServiceProvider, &IID_IServiceProvider> spServiceProvider(pUnkContainer);
		CComPtr<IBindHost>	spBindHost;
		CComPtr<IStream>	spStream;
		if (spServiceProvider)
			spServiceProvider->QueryService(SID_IBindHost, IID_IBindHost, (void**)&spBindHost);

		if (spBindHost == NULL) {
            if (lRelative > 0 && !wszBaseURL) return E_INVALIDARG;
            if (lRelative && wszBaseURL) {
                // Attmpt to calc relative URL on our own
                long     n = 0x400;
                hr =     S_FALSE;
                LPWSTR   pwsz = NULL;
                while (hr == S_FALSE && n < 0x4000) {
                    if (pwsz) delete [] pwsz;
                    pwsz = new WCHAR[n];
                    if (!pwsz) return E_OUTOFMEMORY;
                    hr = ::CoInternetCombineUrl(wszBaseURL,bstrURL,0,pwsz,n,&dwSize,0);
                    n += 0x400;
                }
                if (hr != S_OK) {
                    delete [] pwsz;
                    return E_FAIL;
                }
                hr = CreateURLMoniker(NULL, pwsz, &m_spMoniker);
                delete [] pwsz;
            } else {
                hr = CreateURLMoniker(NULL, bstrURL, &m_spMoniker);
            }

			//if (lRelative > 0) return E_NOINTERFACE;  // relative asked for, but no IBindHost
			
			if (SUCCEEDED(hr)) hr = CreateBindCtx(0, &m_spBindCtx);

			if (SUCCEEDED(hr)) hr = RegisterBindStatusCallback(m_spBindCtx, static_cast<IBindStatusCallback*>(this), 0, 0L);
			else m_spMoniker.Release();

            if (m_pFuncPermit) {
                if (!QueryBindPermission()) return S_FALSE;
            }

			if (SUCCEEDED(hr)) hr = m_spMoniker->BindToStorage(m_spBindCtx, 0, IID_IStream, (void**)&spStream);
        } else {
			hr = CreateBindCtx(0, &m_spBindCtx);
			if (SUCCEEDED(hr)) hr = RegisterBindStatusCallback(m_spBindCtx, static_cast<IBindStatusCallback*>(this), 0, 0L);

			if (SUCCEEDED(hr)) {
				if (lRelative) hr = spBindHost->CreateMoniker(bstrURL, m_spBindCtx, &m_spMoniker, 0);
				else hr = CreateURLMoniker(NULL, bstrURL, &m_spMoniker);
			}

			if (SUCCEEDED(hr)) {

                /*
                ////////// TESTS
                CComPtr<IMoniker>   spMoniker;
                hr = spBindHost->CreateMoniker(L"",m_spBindCtx,&spMoniker,0);
                if (!FAILED(hr)) {
                    LPOLESTR    pwsz = NULL;
                    hr = m_spMoniker->GetDisplayName(m_spBindCtx,NULL,&pwsz);
                    if (!FAILED(hr)) {
                        STRING  str;
                        str = pwsz;
                        VL_THREAD_TRACE((STRPTR)str);
                        BYTE    tmpbuff[1024];
                        DWORD   dw;
                        hr = CoInternetQueryInfo(pwsz,QUERY_USES_NETWORK,0,tmpbuff,1024,&dw,0);
                        wsprintf(str.Allocate(1024),"Uses network: hr=%x, b=%x, dw=%u\n",hr,(*(BOOL*)tmpbuff),dw);
                        VL_THREAD_TRACE((STRPTR)str);

                        hr = CoInternetQueryInfo(pwsz,(QUERYOPTION)13,0,tmpbuff,1024,&dw,0);
                        wsprintf(str.Allocate(1024),"Is secure: hr=%x, b=%x, dw=%u\n",hr,(*(BOOL*)tmpbuff),dw);
                        VL_THREAD_TRACE((STRPTR)str);

                        hr = CoInternetQueryInfo(pwsz,(QUERYOPTION)14,0,tmpbuff,1024,&dw,0);
                        wsprintf(str.Allocate(1024),"Is safe: hr=%x, b=%x, dw=%u\n",hr,(*(BOOL*)tmpbuff),dw);
                        VL_THREAD_TRACE((STRPTR)str);
                    
                        LPWSTR  wszRel = L"/test.asp";
                        hr = CoInternetCombineUrl(pwsz,wszRel,0,(LPWSTR)tmpbuff,512,&dw,0);
                        tmpbuff[1022] = 0;
                        tmpbuff[1023] = 0;
                        STRING  str1;
                        str1.SetFromBuff((LPWSTR)tmpbuff,512);
                        wsprintf(str.Allocate(1024),"Combine test: hr=%x, dw=%u, url=%s\n",hr,dw,(STRPTR)str1);
                        VL_THREAD_TRACE((STRPTR)str);

                        hr = ::CoInternetParseUrl(pwsz,PARSE_SERVER,0,(LPWSTR)tmpbuff,512,&dw,0);
                        tmpbuff[1022] = 0;
                        tmpbuff[1023] = 0;
                        str1.SetFromBuff((LPWSTR)tmpbuff,512);
                        wsprintf(str.Allocate(1024),"Parse: hr=%x, dw=%u, url=%s\n",hr,dw,(STRPTR)str1);
                        VL_THREAD_TRACE((STRPTR)str);


                        ::CoTaskMemFree(pwsz);
                    }
                }
                ////////// TESTS
                */
                if (m_pFuncPermit) {
                    if (!QueryBindPermission()) return S_FALSE;
                }

				hr = spBindHost->MonikerBindToStorage(m_spMoniker, m_spBindCtx, static_cast<IBindStatusCallback*>(this), IID_IStream, (void**)&spStream);
				ATLTRACE2(atlTraceControls,2,_T("Bound"));
			}
		}
		return hr;
	}
    HRESULT     PackPostData(STGMEDIUM* pmed,DWORD* pdwSize,DWORD grfBindInfoF) {
        CComVariant v;
        HRESULT hr;
        LPVOID pv = NULL;
        long    LBound,UBound;
        ULONG   cbWritten;
        LARGE_INTEGER  li;



        hr = ::VariantCopyInd(&v,&m_vPostData);
        
        if (FAILED(hr)) return hr;

        if (v.vt == (VT_UI1 | VT_ARRAY)) {
            if (SafeArrayGetDim(v.parray) != 1) {
                return E_INVALIDARG;
            }
            hr = SafeArrayGetLBound(v.parray,1,&LBound);
            if (FAILED(hr)) return hr;
            hr = SafeArrayGetUBound(v.parray,1,&UBound);
            if (FAILED(hr)) return hr;

            if (UBound < LBound) return S_OK; // Nothing to post

            // Binary data - pass as IStream
            hr = ::CreateStreamOnHGlobal(NULL,TRUE,&pmed->pstm);
            if (!FAILED(hr)) {
                // Put the data into the memory stream
            
                hr = SafeArrayAccessData(v.parray,&pv);
                if (FAILED(hr)) {
                    pmed->pstm->Release();
                    pmed->pstm = NULL;
                    return hr;
                }

                hr = pmed->pstm->Write(pv,UBound - LBound + 1,&cbWritten);
                SafeArrayUnaccessData(v.parray);
                if (FAILED(hr)) {
                    pmed->pstm->Release();
                    pmed->pstm = NULL;
                    return hr;
                }
                // Ok
                *pdwSize = cbWritten;
                pmed->tymed = TYMED_ISTREAM;
                li.QuadPart = 0;
                pmed->pstm->Seek(li,STREAM_SEEK_SET,NULL);
                return S_OK;
            } else {
                return hr;
            }
        } else if (v.vt == VT_EMPTY || v.vt == VT_NULL) {
            // Nothing
            return S_OK;
        } else if (v.vt == VT_UNKNOWN || v.vt == VT_DISPATCH) {
            CComQIPtr<IStream>  spSrcStrm = v.punkVal;
            if (spSrcStrm) {
                // Note if a stream is passed it must be positioned correctly
                // Most often this means in the beginning.
                pmed->pstm = (IStream*)spSrcStrm;
                if (pmed->pstm) {
                    pmed->pstm->AddRef();
                    pmed->tymed = TYMED_ISTREAM;
                    // Now we must get the data size
                    STATSTG     st;
                    ZeroMemory(&st,sizeof(STATSTG));
                    hr = pmed->pstm->Stat(&st,STATFLAG_NONAME);
                    if (!FAILED(hr)) {
                        *pdwSize = (DWORD)st.cbSize.QuadPart;
                    }
                    return S_OK;
                } else {
                    return E_FAIL;
                }
            }
        } 
        // If nothing else works
        
        // Try to convert to string
        hr = v.ChangeType(VT_BSTR);
        if (FAILED(hr)) return hr;

        UBound = WideCharToMultiByte(m_uCP,0,v.bstrVal,-1,NULL,0,NULL,NULL);
        if (grfBindInfoF & BINDINFOF_URLENCODESTGMEDDATA) {
            HGLOBAL hg = ::GlobalAlloc(GMEM_MOVEABLE | GMEM_SHARE | GMEM_ZEROINIT, UBound);
            if (!hg) return E_OUTOFMEMORY;

            pv = ::GlobalLock(hg);
            if (!pv) {
                ::GlobalFree(hg);
                return E_OUTOFMEMORY;
            }

            WideCharToMultiByte(m_uCP,0,v.bstrVal,-1,(LPSTR)pv,UBound,NULL,NULL);

            ::GlobalUnlock(hg);
    
            pmed->hGlobal = hg;
            pmed->tymed = TYMED_HGLOBAL;
            *pdwSize = UBound-1;
        } else {
            // Force packing into an IStream
            hr = ::CreateStreamOnHGlobal(NULL,TRUE,&pmed->pstm);
            if (!FAILED(hr)) {
                // Put the data into the memory stream

                pv = new CHAR[UBound];
                if (!pv) return E_OUTOFMEMORY;

                WideCharToMultiByte(m_uCP,0,v.bstrVal,-1,(LPSTR)pv,UBound,NULL,NULL);

                hr = pmed->pstm->Write(pv,UBound,&cbWritten);
                delete [] ((CHAR*)pv);
                if (FAILED(hr)) {
                    pmed->pstm->Release();
                    pmed->pstm = NULL;
                    return hr;
                }
                if (cbWritten != (ULONG)UBound) {
                    pmed->pstm->Release();
                    pmed->pstm = NULL;
                    return E_OUTOFMEMORY;
                }
                // Ok
                *pdwSize = cbWritten-1;
                pmed->tymed = TYMED_ISTREAM;
                li.QuadPart = 0;
                pmed->pstm->Seek(li,STREAM_SEEK_SET,NULL);
                return S_OK;
            } else {
                return hr;
            }

        }
        return S_OK;
        
    }
    // lRelative -1 - any way possible (relative first), 0 - global, 1 - relative only

	HRESULT StartAsyncDownload( T*                      pT,
                                TPOOLLIB_PDATAAVAILABLE pFunc,
                                TPOOLLIB_PPROGRESS      pProgress,
                                BSTR                    bstrURL,
                                BSTR                    bstrVerb = NULL,
                                IUnknown*               pUnkContainer = NULL,
                                long                    lRelative = -1,
                                VARIANT*                pvData = NULL,
                                BOOL                    bFormPost = FALSE,
                                UINT                    uCP = CP_ACP,
                                IUnknown*               punkHold = NULL,
                                DWORD                   dwID = 0,
                                int                     nBindf = nBindFlags,
                                TPOOLLIB_PBINDPERMIT    pFuncPermit = NULL,
                                LPCTSTR                 szBaseURL = NULL
                                ) {
		m_pT = pT;
		m_pFunc = pFunc;
        m_pFuncProgress = pProgress;
        m_pFuncPermit = pFuncPermit;
        if (bstrVerb) m_bstrVerb = bstrVerb;
        if (pvData) m_vPostData = *pvData;
        m_bFormPost = bFormPost;
        m_uCP = uCP;
        m_dwTransferID = dwID;
        m_nBindFlags = nBindf;

        HRESULT hr;

        int nBaseSize = 0;
        if (szBaseURL && szBaseURL[0]) nBaseSize = MultiByteToWideChar(m_uCP,0,szBaseURL,-1,NULL,0);
        if (nBaseSize) {
            LPWSTR  pwsz = new WCHAR[nBaseSize];
            if (!pwsz) return E_OUTOFMEMORY;

            MultiByteToWideChar(m_uCP,0,szBaseURL,-1,pwsz,nBaseSize);

            hr = _StartAsyncDownload(bstrURL, pUnkContainer, lRelative, pwsz);

            delete [] pwsz;
        } else {
		    hr = _StartAsyncDownload(bstrURL, pUnkContainer, lRelative, NULL);
        }
        
        if (SUCCEEDED(hr)) {
            // Hold in memory
            m_spHold = punkHold;
        }
        return hr;
	}

	static HRESULT Download(    T*                      pT, 
                                IUnknown*               punkHold,
                                DWORD                   dwID,
                                TPOOLLIB_PDATAAVAILABLE pFunc, 
                                BSTR                    bstrURL, 
                                IUnknown*               pUnkContainer = NULL,
                                long                    lRelative = -1,
                                LPCTSTR                 szBaseURL = NULL,
                                TPOOLLIB_PPROGRESS      pProgress = NULL,
                                int                     nBindf = nBindFlags) {
		CComObject<ccBindStatusCallback<T, nBindFlags> > *pbsc;
		HRESULT hRes = CComObject<ccBindStatusCallback<T, nBindFlags> >::CreateInstance(&pbsc);
		if (FAILED(hRes)) return hRes;
        CComPtr<IUnknown>   spThis; // We must hold the object in memory until the function retunrs
        pbsc->QueryInterface(IID_IUnknown,(void**)&spThis);
		return pbsc->StartAsyncDownload(pT, pFunc, pProgress, bstrURL, NULL, pUnkContainer, lRelative,NULL,FALSE,CP_ACP,punkHold,dwID,nBindf,NULL,szBaseURL);
	}

    static HRESULT PostForm(    T*                      pT,
                                IUnknown*               punkHold,
                                DWORD                   dwID,
                                TPOOLLIB_PDATAAVAILABLE pFunc,
                                BSTR                    bstrURL,
                                BSTR                    bstrData,
                                IUnknown*               pUnkContainer = NULL,
                                long                    lRelative = -1,
                                LPCTSTR                 szBaseURL = NULL,
                                TPOOLLIB_PPROGRESS      pProgress = NULL) {

        CComObject<ccBindStatusCallback<T, nBindFlags> > *pbsc;
        HRESULT hRes = CComObject<ccBindStatusCallback<T, nBindFlags> >::CreateInstance(&pbsc);
        if (FAILED(hRes)) return hRes;

        CComPtr<IUnknown>   spThis; // We must hold the object in memory until the function retunrs
        pbsc->QueryInterface(IID_IUnknown,(void**)&spThis);

        CComVariant     v;
        v = bstrData;
        return pbsc->StartAsyncDownload(pT, pFunc, pProgress, bstrURL, L"POST", pUnkContainer, lRelative,&v,TRUE,CP_ACP,punkHold,dwID,nBindFlags,NULL,szBaseURL);
    }
    static HRESULT CustomOperation( T*                      pT,
                                    IUnknown*               punkHold,
                                    DWORD                   dwID,
                                    TPOOLLIB_PDATAAVAILABLE pFunc,
                                    BSTR                    bstrURL,
                                    BSTR                    bstrVerb,
                                    VARIANT                 vData,
                                    IUnknown*               pUnkContainer = NULL,
                                    long                    lRelative = -1,
                                    LPCTSTR                 szBaseURL = NULL,
                                    TPOOLLIB_PPROGRESS      pProgress = NULL,
                                    BOOL                    bFormPost = FALSE,
                                    UINT                    uCP = CP_ACP,
                                    TPOOLLIB_PBINDPERMIT    pFuncPermit = NULL
                                    ) {

        CComObject<ccBindStatusCallback<T, nBindFlags> > *pbsc;
        HRESULT hRes = CComObject<ccBindStatusCallback<T, nBindFlags> >::CreateInstance(&pbsc);

        if (FAILED(hRes)) return hRes;

        CComPtr<IUnknown>   spThis; // We must hold the object in memory until the function retunrs
        pbsc->QueryInterface(IID_IUnknown,(void**)&spThis);

		return pbsc->StartAsyncDownload(pT,pFunc,pProgress,bstrURL,bstrVerb,pUnkContainer,lRelative,&vData,bFormPost,uCP,punkHold,dwID,nBindFlags,pFuncPermit,szBaseURL);
    }
                                

	CComPtr<IMoniker>       m_spMoniker;
	CComPtr<IBindCtx>       m_spBindCtx;
	CComPtr<IBinding>       m_spBinding;
	CComPtr<IStream>        m_spStream;

    CComPtr<IUnknown>       m_spHold;   // Interface of the object to hold in memory

	T* m_pT;
	TPOOLLIB_PDATAAVAILABLE m_pFunc;
    TPOOLLIB_PPROGRESS      m_pFuncProgress;
    TPOOLLIB_PBINDPERMIT    m_pFuncPermit;

    // Operation details members
    CComBSTR                m_bstrVerb;
    BOOL                    m_bFormPost;
    CComVariant             m_vPostData;
    UINT                    m_uCP;

    // Information members
    CComBSTR                m_bstrMimeType;
    BOOL                    m_bDispositionAttachment;

	DWORD                   m_dwTotalRead;
	DWORD                   m_dwAvailableToRead;

    // Transfer ID
    DWORD                   m_dwTransferID;     // Not required but strongly recommended to use
    int                     m_nBindFlags;
};


#endif // _TPOOLLIB_ASYNCMONHELPER_H_