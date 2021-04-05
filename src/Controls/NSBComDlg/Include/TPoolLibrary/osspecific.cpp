// Common (yet)

// Independent conversion. But supports only 1,2,4,8 byte values
// Uses the compiler supplied shifting to ensure correct reading
BOOL    cc_osReadBigEndian(LPVOID pTo,LPVOID pFrom,int nSize) {
    switch (nSize) {
        case 1:
            *((BYTE*)pTo) = *((BYTE*)pFrom);
        return TRUE;
        case 2:
            *((WORD*)pTo) = (((BYTE*)pFrom)[0] << 8) | ((BYTE*)pFrom)[1];
        return TRUE;
        case 4:
            *((DWORD*)pTo) = (((BYTE*)pFrom)[0] << 24) | (((BYTE*)pFrom)[1] << 16) | (((BYTE*)pFrom)[2] << 8) | ((BYTE*)pFrom)[3];
        return TRUE;
        case 8:
		#ifdef SHx
			((ULARGE_INTEGER*)pTo)->LowPart = (((BYTE*)pFrom)[4] << 24) | (((BYTE*)pFrom)[5] << 16) | (((BYTE*)pFrom)[6] << 8) | ((BYTE*)pFrom)[7];
			((ULARGE_INTEGER*)pTo)->HighPart = (((BYTE*)pFrom)[0] << 24) | (((BYTE*)pFrom)[1] << 16) | (((BYTE*)pFrom)[2] << 8) | (((BYTE*)pFrom)[3]);
		#else
            ((ULARGE_INTEGER*)pTo)->QuadPart =  (((BYTE*)pFrom)[0] << 56) | (((BYTE*)pFrom)[1] << 48) | (((BYTE*)pFrom)[2] << 40) | (((BYTE*)pFrom)[3] << 32) | (((BYTE*)pFrom)[4] << 24) | (((BYTE*)pFrom)[5] << 16) | (((BYTE*)pFrom)[6] << 8) | ((BYTE*)pFrom)[7];
		#endif
        return TRUE;
    }
    return FALSE;
}
BOOL    cc_osReadLittleEndian(LPVOID pTo,LPVOID pFrom,int nSize) {
    switch (nSize) {
        case 1:
            *((BYTE*)pTo) = *((BYTE*)pFrom);
        return TRUE;
        case 2:
            *((WORD*)pTo) = (((BYTE*)pFrom)[1] << 8) | ((BYTE*)pFrom)[0];
        return TRUE;
        case 4:
            *((DWORD*)pTo) = (((BYTE*)pFrom)[3] << 24) | (((BYTE*)pFrom)[2] << 16) | (((BYTE*)pFrom)[1] << 8) | ((BYTE*)pFrom)[0];
        return TRUE;
        case 8:
			#ifdef SHx
				((ULARGE_INTEGER*)pTo)->LowPart = (((BYTE*)pFrom)[3] << 24) | (((BYTE*)pFrom)[2] << 16) | (((BYTE*)pFrom)[1] << 8) | ((BYTE*)pFrom)[0];
				((ULARGE_INTEGER*)pTo)->HighPart = (((BYTE*)pFrom)[7] << 24) | (((BYTE*)pFrom)[6] << 16) | (((BYTE*)pFrom)[5] << 8) | (((BYTE*)pFrom)[4]);
			#else
				((ULARGE_INTEGER*)pTo)->QuadPart = (((BYTE*)pFrom)[7] << 56) | (((BYTE*)pFrom)[6] << 48) | (((BYTE*)pFrom)[5] << 40) | (((BYTE*)pFrom)[4] << 32) | (((BYTE*)pFrom)[3] << 24) | (((BYTE*)pFrom)[2] << 16) | (((BYTE*)pFrom)[1] << 8) | ((BYTE*)pFrom)[0];
			#endif
        return TRUE;
    }
    return FALSE;
}

LPVOID  cc_osByteOrderConvert(LPVOID pTo, LPVOID pFrom, DWORD dwFlags, UINT nSize, UINT nCount) {
    LPBYTE  pbTo = (LPBYTE)pTo;
    LPBYTE  pbFrom = (LPBYTE)pFrom;
    UINT    i,n;

    if (dwFlags & 0x00000004) {
        // Trivial
        memcpy(pTo,pFrom,nSize * nCount);
    } else {
        switch (dwFlags & 0x00000003) {
            case 0x0:
            case 0x3:
                memcpy(pTo,pFrom,nSize * nCount);
            break;
            case 0x2:
            case 0x1:
                // Little endian to big endian
                // Big endian to little endian
                // In fact reversing
                for (n = 0; n < nCount; n++) {
                    for (i = 0; i < nSize; i++) pbTo[ ((n + 1) * nSize) - i - 1] = pbFrom[n * nSize + i];
                }
            break;
        }
    }
    return pTo;
}

DWORD   cc_osStrByteLen(LPSTR sz) {
    if (!sz) return 0;
    DWORD i;
    for (i = 0; sz[i] != '\0' ;i++);
    return i;
}
DWORD   cc_osStrByteLenW(LPWSTR sz) {
    if (!sz) return 0;
    DWORD i;
    for (i = 0; sz[i] != L'\0' ;i++);
    return i * sizeof(WCHAR);
}
DWORD   cc_osStrByteLenT(LPTSTR sz) {
    #ifdef UNICODE
        return cc_osStrByteLenW(sz);
    #else
        return cc_osStrByteLen(sz);
    #endif
}

