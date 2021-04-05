BYTE        HexCharToByte(TCHAR ch) {
    if (ch >= 0x30 && ch <= 0x39) return (BYTE)(ch - 0x30);
    if (ch >= 0x41 && ch <= 0x46) return (BYTE)(ch - 0x40 + 9);
    if (ch >= 0x61 && ch <= 0x66) return (BYTE)(ch - 0x60 + 9);
    if (ch == TEXT(' ') || ch == TEXT('\t') || ch == TEXT('\n') || ch == TEXT('\r')) return 0x40; // Skip
    return 0x80; // Not valid
}

HRESULT     BinDataToHexText(LPBYTE pData,DWORD dwLen,BSTR* pbstr,BYTE bFlags /*= 0*/) {
    if (!pbstr) return E_POINTER;
    ccBSTR      bstr;
    if (!pData || !dwLen) {
        *pbstr = bstr.Copy();
        return S_OK;
    }
    BSTR bstrPtr;
    if (bFlags & 0x02) {
        bstrPtr = bstr.Alloc(dwLen * 3 - 1);
    } else {
        bstrPtr = bstr.Alloc(dwLen * 2);
    }
    if (!bstrPtr) return E_OUTOFMEMORY;

    DWORD   dw,dwStrPos;
    BYTE    bt;

	for (dw = 0,dwStrPos = 0; dw < dwLen; dw++ ) {

        bt = (pData[dw] >> 4) & 0x0F;
        if (bFlags & 0x01) {
            bstrPtr[dwStrPos] = (WCHAR)((bt < 10)?(bt + 0x30):(bt + 0x60 - 9));
        } else {
            bstrPtr[dwStrPos] = (WCHAR)((bt < 10)?(bt + 0x30):(bt + 0x40 - 9));
        }
        dwStrPos++;

        bt = pData[dw] & 0x0F;
        if (bFlags & 0x01) {
            bstrPtr[dwStrPos] = (WCHAR)((bt < 10)?(bt + 0x30):(bt + 0x60 - 9));
        } else {
            bstrPtr[dwStrPos] = (WCHAR)((bt < 10)?(bt + 0x30):(bt + 0x40 - 9));
        }
        dwStrPos++;

        if (bFlags & 0x02) {
            if (dw < dwLen - 1) {
                bstrPtr[dwStrPos] = L' ';
                dwStrPos++;
            }
        }
	}
    bstrPtr[dwStrPos] = L'\0';
	*pbstr = bstr.Copy();
    
    if (!(*pbstr)) return E_OUTOFMEMORY;
    return S_OK;
}


HRESULT     HexTextToBinData(BSTR bstr,LPBYTE pData,DWORD dwLen,DWORD* pdwSize /*= NULL*/) {
    if (!bstr) return S_OK; // Write nothing
    UINT uLen = ::SysStringLen(bstr);
    if (!uLen) return S_OK;

    if (!pData || !dwLen) return S_OK;

    UINT i,j;
    BYTE b,bCur,bSpace,bBytePos;
    for (i = 0,j = 0,bCur = 0,bSpace = TRUE,bBytePos = 0; i < uLen && j < dwLen;i++) {
        b = HexCharToByte(bstr[i]);
        if (b & 0x80) return DISP_E_TYPEMISMATCH;

        if ((b & 0x40) && !bSpace) {
            // Submit what we have
            if (bBytePos > 0) {
                pData[j] = bCur;
                j++;
            }
            bCur = 0;
            bSpace = TRUE;
            continue;
        } else if ((b & 0x40) && bSpace) {
            continue;
        } else {
            // Digit
            bCur <<= 4;
            bCur |= b & 0x0F;
            bBytePos ++;
            if (bBytePos > 1) {
                // Submit
                pData[j] = bCur;
                j++;
                bCur = 0;
                bBytePos = 0;
            }
            bSpace = FALSE;
        }
    }
    if (bBytePos > 1 && j < dwLen) {
        pData[j] = bCur;
    }
    if (pdwSize) *pdwSize = j;
    return S_OK;
}
#ifdef _NEWOBJECTS_CCBUFFER_H_
    HRESULT     BinDataToHexText(ccBuffer& buff,BSTR* pbstr,BYTE bFlags) {
        return BinDataToHexText(buff.GetPtr(),buff.DataSize(),pbstr,bFlags);
    }
    HRESULT     HexTextToBinData(BSTR bstr,ccBuffer& buff) {
        DWORD dw = (DWORD)::SysStringLen(bstr);
        buff.Reset(dw / 2,256);
        LPBYTE pData = buff.Prepare(dw / 2);
        if (!pData) return E_OUTOFMEMORY;
        DWORD dwBinSize = 0;
        HRESULT hr = HexTextToBinData(bstr,pData,dw / 2,&dwBinSize);
        if (FAILED(hr)) return hr;
        buff.Commit(dwBinSize);
        return S_OK;
    }
#endif // _NEWOBJECTS_CCBUFFER_H_