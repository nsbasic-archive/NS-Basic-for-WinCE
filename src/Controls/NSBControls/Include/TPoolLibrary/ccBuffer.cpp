// BUFFER.CPP



BOOL    ccBuffer::Init(unsigned long max,unsigned long unit) {
    m_dwUnit    = (unit > CCBUFFER_DEFAULT_UNIT)?unit:CCBUFFER_DEFAULT_UNIT;
    m_dwMaxSize = (max > m_dwUnit)?max:m_dwUnit;
    m_dwMaxSize = ((m_dwMaxSize / m_dwUnit) + 1) * m_dwUnit;
    m_pBuff     = new BYTE[m_dwUnit];
    m_dwSize    = m_dwUnit;
    m_dwPos     = 0;
    #ifndef BUFFER_NOSTRINGLINES
        m_szReadMask = new TCHAR[(lstrlen(CCBUFFER_READMASK) + 1)];
        m_szWriteMask= new TCHAR[(lstrlen(CCBUFFER_WRITEMASK) + 1)];
        if (m_szReadMask) lstrcpy(m_szReadMask,CCBUFFER_READMASK);
        if (m_szWriteMask) lstrcpy(m_szWriteMask,CCBUFFER_WRITEMASK);
    #endif //BUFFER_NOSTRINGLINES
    return TRUE;
}


ccBuffer::ccBuffer() {
    Init(0,0);
}
ccBuffer::ccBuffer(DWORD max) {
    Init(max,0);
}
ccBuffer::ccBuffer(DWORD max,DWORD unit) {
    Init(max,unit);
}

ccBuffer::~ccBuffer() {
    if (m_pBuff) delete m_pBuff;
    #ifndef BUFFER_NOSTRINGLINES
        if (m_szReadMask) delete m_szReadMask;
        if (m_szWriteMask) delete m_szWriteMask;
    #endif BUFFER_NOSTRINGLINES
}
DWORD   ccBuffer::Enlarge(DWORD morebytes) {
    if (m_dwSize == m_dwMaxSize) return 0;
    DWORD   dwNewSize = m_dwSize + ((morebytes / m_dwUnit) + 1) * m_dwUnit;
    LPBYTE  pBuff;
    if (dwNewSize > m_dwMaxSize) {
        dwNewSize = m_dwMaxSize;
        if (morebytes > (dwNewSize - m_dwSize)) return 0;
    }

    pBuff = new BYTE[dwNewSize];
    if (!pBuff) return 0;
    
    CopyMemory (pBuff,m_pBuff,m_dwPos);
    m_dwSize = dwNewSize;
    delete m_pBuff;
    m_pBuff = pBuff;
    return dwNewSize;
}
void    ccBuffer::ResetContent() {
    m_dwPos = 0;
}
void    ccBuffer::Reset() {
    if (m_pBuff) delete m_pBuff;
    m_pBuff     = new BYTE[m_dwUnit];
    m_dwSize    = m_dwUnit;
    m_dwPos     = 0;    
}
void    ccBuffer::Reset(DWORD max,DWORD unit) {
    if (m_pBuff) delete m_pBuff;
    Init(max,unit);    
}
BOOL    ccBuffer::Validate() {
    if (!m_pBuff) return FALSE;
    return TRUE;
}
DWORD   ccBuffer::BuffSize() {
    return m_dwSize;
}
DWORD   ccBuffer::Put(LPBYTE p,DWORD len) {
    DWORD   dwSpace = m_dwSize - m_dwPos;
    LPBYTE  lp;

    if (dwSpace < len) {
        if (!Enlarge(len - dwSpace)) return 0;
    }
    // OK - add data
    lp = (LPBYTE)&(m_pBuff[m_dwPos]);
    CopyMemory(lp,p,len);
    m_dwPos += len;
    return len;
}
DWORD   ccBuffer::Pad(BYTE bt,DWORD len) {
    DWORD   dwSpace = m_dwSize - m_dwPos;
    if (dwSpace < len) {
        if (!Enlarge(len - dwSpace)) return 0;
    }
    // OK - add data
    DWORD i;
    for (i = 0; i < len; i++) {
        m_pBuff[m_dwPos + i] = bt;
    }
    m_dwPos += len;
    return len;
}
LPBYTE  ccBuffer::Prepare(DWORD len) {
	DWORD   dwSpace = m_dwSize - m_dwPos;
    LPBYTE  lp;

    if (dwSpace < len) {
        if (!Enlarge(len - dwSpace)) return NULL;
    }
    // OK - return pointer
    lp = (LPBYTE)&(m_pBuff[m_dwPos]);
	return lp;
}
DWORD   ccBuffer::Commit(DWORD len) {
	DWORD   dwSpace = m_dwSize - m_dwPos;

    if (dwSpace < len) return 0;
    // OK - commit data
    m_dwPos += len;
    return len;
}
DWORD   ccBuffer::TransferTo(ccBuffer* pBuf) {
    if (!pBuf) return 0;
    BYTE    buff[256];
    DWORD   cnt;
    DWORD   bytes = 0;
    do {
        cnt = Get(buff,256);
        //
        if (cnt) {
            if (pBuf->Put(buff,cnt) != cnt) return bytes;
        }
        bytes += cnt;
    } while (cnt);
    return bytes;    
}
DWORD   ccBuffer::DataSize() {
    return m_dwPos;
}
DWORD   ccBuffer::Get(LPBYTE p,DWORD len) {
    DWORD   l = min(len,m_dwPos);
    if (!l) return 0;
    
    CopyMemory(p,m_pBuff,l);
    CopyMemory(m_pBuff,&(m_pBuff[l]),m_dwPos-l);
    m_dwPos -= l;
    
    return l;
}
LPBYTE  ccBuffer::GetPtr() {
    return m_pBuff;
}
DWORD   ccBuffer::Peek(LPBYTE p,DWORD len) {
    DWORD   l = min(len,m_dwPos);
    if (!l) return 0;
    CopyMemory(p,m_pBuff,l);
    return l;
}
DWORD   ccBuffer::Skip(DWORD len) {
    DWORD   l = min(len,m_dwPos);
    if (!l) return 0;
    CopyMemory(m_pBuff,&(m_pBuff[l]),m_dwPos-l);
    m_dwPos -= l;
    return l;
}

DWORD   ccBuffer::FindSequence(LPBYTE p,DWORD len) {
    DWORD   i,j;
    if (!p) return CCBUFFER_ERROR;

    for (i = 0;i < (m_dwPos - len);i++) {
	    for (j = 0;j < len;j++) {
	        if (p[j] != m_pBuff[i+j]) goto BUFFER_FindSequence1;
        }
        return i;
        BUFFER_FindSequence1:
        continue;
    }
    return CCBUFFER_ERROR;
}
DWORD	ccBuffer::GetMaxSize() {
	return m_dwMaxSize;
}
DWORD	ccBuffer::GetUnitSize() {
    return m_dwUnit;
}

HRESULT ccBuffer::ToSafeArray(SAFEARRAY** ppsa) {
    return PackDataInSafeArray(*this,ppsa);
}
HRESULT ccBuffer::FromSafeArray(SAFEARRAY* psa) {
    return UnPackDataFromSafeArray(psa,*this,TRUE);
}
HRESULT ccBuffer::ToVariant(VARIANT* pVar) {
    return PackDataInVariant(*this,pVar);
}
HRESULT ccBuffer::FromVariant(VARIANT v) {
    return UnPackDataFromVariant(v,*this,TRUE);
}


#ifndef BUFFER_NOSTRINGLINES
    void    ccBuffer::SetEndOfStringMasks(LPTSTR endofstr,LPTSTR strterminator) {
    
        if (endofstr) {
            if (m_szReadMask) delete m_szReadMask;
            m_szReadMask = new TCHAR[lstrlen(endofstr)+1];
            if (m_szReadMask)
                lstrcpy(m_szReadMask,endofstr);
        }
        if (strterminator) {
            if (m_szWriteMask) delete m_szWriteMask;
            m_szWriteMask = new TCHAR[lstrlen(strterminator)+1];
            if (strterminator)
                lstrcpy(m_szWriteMask,strterminator);
        }
    }
    DWORD   ccBuffer::Put(LPTSTR sz) {
        DWORD   len = lstrlen(sz) * sizeof(TCHAR);
        return Put((LPBYTE)sz,len);
    }
    DWORD   ccBuffer::PutLine(LPTSTR sz) {
        DWORD       l1,l2;

        l1 = Put(sz);
        if (l1) {
            l2 = Put(m_szWriteMask);
            if (l2) {
                return l1+l2;
            }
        }
        return 0;
    }
    DWORD   ccBuffer::FindFromSet(LPTSTR sz) {
        DWORD   len = m_dwPos / sizeof(TCHAR);
        LPTSTR  pBuff = (LPTSTR)m_pBuff;
        DWORD   i,j,l;

        if (!sz) return CCBUFFER_ERROR;
        l = lstrlen(sz);
        for (i = 0;i < len;i++) {
            for (j = 0;j <= l;j++) {
                if (sz[j] == pBuff[i]) return i * sizeof(TCHAR);
            }
        }

        return CCBUFFER_ERROR;
    }
    DWORD   ccBuffer::FindNotFromSet(LPTSTR sz) {
        DWORD   len = m_dwPos / sizeof(TCHAR);
        LPTSTR  pBuff = (LPTSTR)m_pBuff;
        DWORD   i,j,l;

        if (!sz) return 0;
        l = lstrlen(sz);
        for (i = 0;i < len;i++) {
            for (j = 0;j <= l;j++) {
                if (sz[j] == pBuff[i]) goto LBL011_XXFDG;
            }
            return i * sizeof(TCHAR);
    LBL011_XXFDG:
            i;
        }
        return m_dwPos;
    }
    LPTSTR  ccBuffer::GetLine() {
        DWORD   l = FindFromSet(m_szReadMask);
        LPTSTR  lpsz;
        DWORD   tmp;

         if (l != CCBUFFER_ERROR) {
            lpsz = (LPTSTR)(new LPBYTE[l + sizeof(TCHAR)]);
            if (!lpsz) return NULL;
            tmp = Get((LPBYTE)lpsz,l);
            lpsz[l / sizeof(TCHAR)] = '\0';
        } else lpsz = NULL;
        l = FindNotFromSet(m_szReadMask);
        if (l) {
            Skip(l);
        }
        return lpsz;
    }
#endif BUFFER_NOSTRINGLINES

#ifdef COMMON_DEBUG_CONSOLE
	void	ccBuffer::Dump() {
		DWORD i,j,b;
		_tprintf(_TEXT("\n")); 
		CHAR	txt[17];
 		ZeroMemory(&txt,17);
		for (i = 0; i < m_dwPos; i++) {
			if (!(i % 16)) {
				_tprintf(_TEXT("\t"));
				for (j = 0;j < 16;j++) {
					if (txt[j] >= 0x20) {
						_tprintf(_TEXT("%hc"),txt[j]);
					} else {
						_tprintf(_TEXT("."));
					}
				}
				_tprintf(_TEXT("\n"));
				ZeroMemory(&txt,17);
			}
			b = m_pBuff[i];
			_tprintf(_TEXT("%2X "),b);
			txt[i%16] = m_pBuff[i];
		}
		_tprintf(_TEXT("\n"));
	}
#endif // COMMON_DEBUG_CONSOLE

HRESULT PackDataInSafeArray(ccBuffer& buff,SAFEARRAY** ppArray) {
    return PackDataInSafeArray(buff.GetPtr(),(ULONG)buff.DataSize(),ppArray);
}
HRESULT UnPackDataFromSafeArray(SAFEARRAY* psa,ccBuffer& buff,BOOL bReset) {
    if (!psa) return E_POINTER;

    HRESULT     hr;
    
    // Unpack array data
    long  lLBound,lUBound;
    LPVOID  pData;

    hr = SafeArrayGetLBound(psa,1,&lLBound);
    if (FAILED(hr)) return hr;
    hr = SafeArrayGetUBound(psa,1,&lUBound);
    if (FAILED(hr)) return hr;

    if (lUBound < lLBound) {
        return S_OK; // Empty array
    }

    hr = SafeArrayAccessData(psa,&pData);
    if (FAILED(hr)) return hr;

    long cb = lUBound - lLBound + 1;

    if (bReset) {
        buff.Reset(cb + 1,buff.GetUnitSize());
    }

    LPBYTE pb = buff.Prepare((DWORD)cb);
    if (!pb) {
        SafeArrayUnaccessData(psa);
        return E_OUTOFMEMORY;
    }
    CopyMemory(pb,pData,cb);
    SafeArrayUnaccessData(psa);
    buff.Commit(cb);
	return S_OK;
}
HRESULT PackDataInVariant(ccBuffer& buff,VARIANT* pVar) {
    SAFEARRAY* psa = NULL;
    HRESULT hr = PackDataInSafeArray(buff,&psa);
    if (FAILED(hr)) return hr;
    ::VariantInit(pVar);
    pVar->vt = VT_UI1 | VT_ARRAY;
    pVar->parray = psa;
    return S_OK;
}
HRESULT UnPackDataFromVariant(VARIANT v,ccBuffer& buff,BOOL bReset) {
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
	
    
    hr = UnPackDataFromSafeArray(psa,buff,bReset);
	::VariantClear(&vTemp);
	return hr;
}