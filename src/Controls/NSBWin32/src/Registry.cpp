// Registry.cpp : Implementation of CRegistry
#include "stdafx.h"
#include "Desk.h"
#include "Registry.h"

/////////////////////////////////////////////////////////////////////////////
// CRegistry

STDMETHODIMP CRegistry::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IRegistry
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CRegistry::get_Key(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (long)((DWORD)m_hkRoot & 0xFFFF);
	return S_OK;
}
STDMETHODIMP CRegistry::put_Key(long newVal) {
	m_hkRoot = (HKEY)((DWORD)newVal | 0x80000000);
	return S_OK;
}

STDMETHODIMP CRegistry::get_Path(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bstrPath.Copy();
	return S_OK;
}

STDMETHODIMP CRegistry::put_Path(BSTR newVal) {
	m_bstrPath = newVal;
	return S_OK;
}

STDMETHODIMP CRegistry::get_Name(BSTR *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = m_bstrValName.Copy();
	return S_OK;
}

STDMETHODIMP CRegistry::put_Name(BSTR newVal) {
	m_bstrValName = newVal;
	return S_OK;
}

STDMETHODIMP CRegistry::get_Version(long *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = 201;
	return S_OK;
}

STDMETHODIMP CRegistry::get_ValueType(long *pVal) {
    if (!pVal) return E_POINTER;
	LONG lResult;
	HKEY hk;

    if (!m_bstrPath.Length() || !m_bstrValName.Length()) {
        return Error(IDS_E_PATHORVALNAME);
    }
    
	lResult = ::RegOpenKeyEx( m_hkRoot, m_bstrPath, 0, KEY_READ, &hk);
	if (lResult == ERROR_SUCCESS) {
		lResult = ::RegQueryValueEx( hk, m_bstrValName, NULL, (LPDWORD)pVal, NULL, NULL );
		::RegCloseKey(hk);
        
    } 
    if (lResult != ERROR_SUCCESS) {
		return Error(IDS_E_VALUEFAILED);
	}
	return S_OK;
}

STDMETHODIMP CRegistry::put_ValueType(long newVal) {
	m_lType = newVal;
	return S_OK;
}

STDMETHODIMP CRegistry::GetPathName(long lPath, BSTR *bstrPath) {
	if (!bstrPath) return E_POINTER;

    LONG    lResult;
	HKEY    hk;
	TCHAR   szName[512];
    szName[0] = TEXT('\0');
	DWORD   dwSize = 512;

	lResult = ERROR_SUCCESS;

    if (m_bstrPath.Length()) {
        lResult = ::RegOpenKeyEx(m_hkRoot, m_bstrPath, 0, KEY_READ, &hk);
    } else {
        hk = m_hkRoot;
    }
	if (lResult != ERROR_SUCCESS) {
		return Error(IDS_E_OPENPATHFAILED);
	}

	lResult = ::RegEnumKeyEx(hk,lPath,szName,&dwSize, NULL, NULL, NULL, NULL );
    
    if( lResult == ERROR_SUCCESS )  {
        *bstrPath = ::SysAllocString(szName);
    }
    if ((m_dwBehavior & NSBASIC_REGISTRY_ENDENUMEMPTY) && (lResult == ERROR_NO_MORE_ITEMS)) {
        *bstrPath = ::SysAllocString(L"");
        lResult = ERROR_SUCCESS;
    }

	if (m_bstrPath.Length()) ::RegCloseKey(hk);

	if (lResult == ERROR_SUCCESS)  return S_OK;

    return Error(IDS_E_OPENPATHFAILED);	
}

STDMETHODIMP CRegistry::GetValueName(long lVal, BSTR *bstrVal) {
    if (!bstrVal) return E_POINTER;

    LONG    lResult;
	HKEY    hk;
	TCHAR   szName[512];
	DWORD   dwSize = 512;

	lResult = ERROR_SUCCESS;

    if (m_bstrPath.Length()) {
        lResult = ::RegOpenKeyEx(m_hkRoot,m_bstrPath, 0, KEY_READ, &hk);
    } else {
        hk = m_hkRoot;
    }
	if (lResult != ERROR_SUCCESS) {
		return Error(IDS_E_OPENPATHFAILED);
	}
	
	lResult = ::RegEnumValue( hk, lVal, szName, &dwSize, NULL, NULL, NULL, NULL);

    if (lResult == ERROR_SUCCESS) {
        *bstrVal = ::SysAllocString(szName);
    }
    if ((m_dwBehavior & NSBASIC_REGISTRY_ENDENUMEMPTY) && (lResult == ERROR_NO_MORE_ITEMS)) {
        *bstrVal = ::SysAllocString(L"");
        lResult = ERROR_SUCCESS;
    }

	if (m_bstrPath.Length()) ::RegCloseKey(hk);
	if (lResult == ERROR_SUCCESS) return S_OK;
	return Error(IDS_E_OPENPATHFAILED);
}

STDMETHODIMP CRegistry::CreatePath() {
	LONG    lResult;
	HKEY    hk;
	DWORD   dwDisp;

	if(!m_bstrPath.Length()) {
        return Error(IDS_E_PATHNOTSPEC);
	}
	lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	if (lResult == ERROR_SUCCESS) {
		RegCloseKey(hk);
		return S_OK;
	}
	return Error(IDS_E_CREATEKEYFAILED);
}

STDMETHODIMP CRegistry::DeletePath() {
	LONG lResult;

	if (!m_bstrPath.Length()) {
        return Error(IDS_E_PATHNOTSPEC);
	}
	lResult = ::RegDeleteKey( m_hkRoot, m_bstrPath);
    return ((lResult == ERROR_SUCCESS)?S_OK:Error(IDS_E_DELETEKEYFAILED));
}

STDMETHODIMP CRegistry::DeleteValue() {

	LONG    lResult;
	HKEY    hk;

	if(!m_bstrPath.Length() || !m_bstrValName.Length()) {
		return Error(IDS_E_PATHORVALNAME);
	}
	lResult = ::RegOpenKeyEx( m_hkRoot, m_bstrPath, 0, KEY_ALL_ACCESS, &hk);
	if (lResult != ERROR_SUCCESS) return Error(IDS_E_OPENPATHFAILED);
		
	lResult = ::RegDeleteValue(hk, m_bstrValName);
	::RegCloseKey(hk);

    return ((lResult == ERROR_SUCCESS)?S_OK:Error(IDS_E_DELETEVALUEFAILED));
}
STDMETHODIMP CRegistry::get_Value(VARIANT *pVal) {
	if (!pVal) return E_POINTER;

    if (!m_bstrPath.Length()) {
		return Error(IDS_E_PATHNOTSPEC);
	}

    LONG    lResult;
    HKEY    hk;
    HRESULT hr;

    lResult = ::RegOpenKeyEx( m_hkRoot, m_bstrPath, 0, KEY_READ, &hk);
    if (lResult != ERROR_SUCCESS) return Error(IDS_E_OPENPATHFAILED);

    DWORD   dwType, dwSize;

    lResult = ::RegQueryValueEx(hk, m_bstrValName, NULL, &dwType, NULL, &dwSize );
    if (lResult != ERROR_SUCCESS) return Error(IDS_E_VALUEFAILED);

	ccBuffer    buff(dwSize);
    LPBYTE      pData = NULL;

    if (dwSize) {
        pData = buff.Prepare(dwSize);
        if (!pData) {
            ::RegCloseKey(hk);
            return E_OUTOFMEMORY;
        }
        lResult = ::RegQueryValueEx(hk,m_bstrValName,NULL, &dwType,pData, &dwSize);
        if (lResult != ERROR_SUCCESS) {
            ::RegCloseKey(hk);
            return Error(IDS_E_VALUEFAILED);
        }
        buff.Commit(dwSize);
        pData = buff.GetPtr();  // Currently the pointer remains the same after commit but
                                // to ensure any future changes will not harm us we re-obtain it

    }

    // from <winreg.h> for reference
    /*
        #define REG_NONE                    ( 0 )   // No value type
        #define REG_SZ                      ( 1 )   // Unicode nul terminated string
        #define REG_EXPAND_SZ               ( 2 )   // Unicode nul terminated string
                                                    // (with environment variable references)
        #define REG_BINARY                  ( 3 )   // Free form binary
        #define REG_DWORD                   ( 4 )   // 32-bit number
        #define REG_DWORD_LITTLE_ENDIAN     ( 4 )   // 32-bit number (same as REG_DWORD)
        #define REG_DWORD_BIG_ENDIAN        ( 5 )   // 32-bit number
        #define REG_LINK                    ( 6 )   // Symbolic Link (unicode)
        #define REG_MULTI_SZ                ( 7 )   // Multiple Unicode strings
        #define REG_RESOURCE_LIST           ( 8 )   // Resource list in the resource map
        #define REG_FULL_RESOURCE_DESCRIPTOR ( 9 )  // Resource list in the hardware description
        #define REG_RESOURCE_REQUIREMENTS_LIST ( 10 )
     */

    ccBSTR      bstr;
    BYTE        temp[16];
    DWORD       dwMiscFlags;
    LPVOID      pv;
    BSTR        bstrPtr;
    LONG        i = 0;

    // The arrays do not consume much memory if empty - so we can afford
    // to declare whatever we may need
    ccSafeArray<BYTE,VT_UI1>            csaByteArray;
    ccSafeArray<VARIANT,VT_VARIANT>     csaBSTRArray;
    ccVariant                           var;

    switch (dwType) {
        case REG_SZ:
        case REG_EXPAND_SZ:
        case REG_LINK:
            // Return as BSTR
            bstr = (LPCOLESTR)buff.GetPtr();
            bstr.CopyTo(pVal);
        break;
        case REG_DWORD_BIG_ENDIAN:
        case REG_DWORD_LITTLE_ENDIAN:
            dwMiscFlags = (dwType == REG_DWORD_LITTLE_ENDIAN)?BOCF_FROM_LITTLEENDIAN:BOCF_FROM_BIGENDIAN;
            dwMiscFlags |= COMMON_SYSTEM_BYTEORDER;
            cc_osByteOrderConvert(temp, pData, dwMiscFlags,sizeof(DWORD),1);
            pVal->vt = VT_UI4;
            pVal->ulVal = *((DWORD*)temp);
        break;
        case REG_BINARY:
            if (m_dwBehavior & NSBASIC_REGISTRY_BINASBYTES) {
                // Return as binary
                hr = csaByteArray.Create(1,(long)dwSize);
                if (FAILED(hr)) return hr;
                pv = csaByteArray.AccessData();
                if (!pv) return E_OUTOFMEMORY;
                CopyMemory(pv,pData,dwSize);
                hr = csaByteArray.CopyTo(pVal);
                if (FAILED(hr)) return hr;
            } else {
                // Return as hex
                bstr.Empty();
                hr = BinDataToHexText(pData,dwSize,&bstr,((m_dwBehavior & NSBASIC_REGISTRY_HEXWITHSPACES)?0x02:0));
                if (FAILED(hr)) return hr;
                hr = bstr.CopyTo(pVal);
                if (FAILED(hr)) return hr;
            }
        break;
        case REG_MULTI_SZ:
            bstrPtr = (BSTR)pData;
            csaBSTRArray.Destroy(); //Create(1,1);
            i = 0;
            do {
                bstr = bstrPtr;
                var = bstr;
                if (!csaBSTRArray.IsValid()) csaBSTRArray.Create(1,1);
                else csaBSTRArray.Inflate(1);
                hr = csaBSTRArray.PutElement(var,i);
                if (FAILED(hr)) return hr;
                bstrPtr += bstr.Length() + 1;
                i++;
            } while ((bstr.Length() > 0) && ((LPBYTE)bstrPtr < (pData + dwSize)));

            hr = csaBSTRArray.CopyTo(pVal);
            if (FAILED(hr)) return hr;
        break;
        default:
            return Error(IDS_E_REGTYPEUNSUPPORTED);

    }
	return S_OK;

}

STDMETHODIMP CRegistry::put_Value(VARIANT newVal) {
    if (!m_bstrPath.Length()) return Error(IDS_E_PATHNOTSPEC);
    ccVariant   v;
    HRESULT     hr;
    LONG        lResult;
    DWORD       dwDisp;
    HKEY        hk;
    ccBSTR      bstr;

    hr = ::VariantResolveToValue(&v,&newVal);
    if (FAILED(hr)) return hr;

    if (m_lType == REG_SZ) {
        hr = v.ChangeType(VT_BSTR);
        if (FAILED(hr)) return hr;

        bstr = v.bstrVal;

        lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	    if (lResult != ERROR_SUCCESS) return Error(IDS_E_CREATEKEYFAILED);

        lResult = ::RegSetValueEx(hk, m_bstrValName, 0, REG_SZ, (LPBYTE)(BSTR)bstr,(bstr.Length() + 1) * sizeof(WCHAR)); 
        if (lResult != ERROR_SUCCESS) {
            ::RegCloseKey(hk);
            return Error(IDS_E_SETVALUEFAILED);
        }
        ::RegCloseKey(hk);
        return S_OK;
    } else if (m_lType == REG_DWORD) {
        hr = v.ChangeType(VT_UI4);
        if (FAILED(hr)) return hr;

        lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	    if (lResult != ERROR_SUCCESS) return Error(IDS_E_CREATEKEYFAILED);

        lResult = ::RegSetValueEx(hk, m_bstrValName, 0, REG_DWORD, (LPBYTE)&v.ulVal,sizeof(DWORD)); 
        if (lResult != ERROR_SUCCESS) {
            ::RegCloseKey(hk);
            return Error(IDS_E_SETVALUEFAILED);
        }
        ::RegCloseKey(hk);
        return S_OK;
    } else if (m_lType == REG_BINARY) {
        // On Put we have additional opportunity - to guess what to do over the type of the
        // argument instead of using an instance level flag (see m_dwBehavior flags)
        if (v.vt == (VT_ARRAY | VT_UI1)) {
            // Byte array - the standard binary data representation in variants
            // We support only 1-d arrays!!!
            ccSafeArray<BYTE,VT_UI1>    csaBytes = v.parray;
            v.ReleaseControl();
            if (csaBytes.Dims() > 1) return Error(IDS_E_MULTIDIMARRAYNOTSUPPORTED);
            UINT    uElements = csaBytes.Elements();
            LPBYTE  pb = (LPBYTE)csaBytes.AccessData();
            if (!pb) return E_OUTOFMEMORY;

            lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	        if (lResult != ERROR_SUCCESS) return Error(IDS_E_CREATEKEYFAILED);

            lResult = ::RegSetValueEx(hk, m_bstrValName, 0, REG_BINARY, pb,uElements); 
            if (lResult != ERROR_SUCCESS) {
                ::RegCloseKey(hk);
                return Error(IDS_E_SETVALUEFAILED);
            }
            ::RegCloseKey(hk);
            return S_OK;
        } else if (v.vt == VT_BSTR) {
            bstr <= v.bstrVal;
            v.ReleaseControl();
            UINT        uLen = bstr.Length();
            BSTR        p = bstr;
            ccBuffer    buff;
            
            hr = HexTextToBinData(bstr,buff);
            if (FAILED(hr)) return hr;

            lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	        if (lResult != ERROR_SUCCESS) return Error(IDS_E_CREATEKEYFAILED);

            lResult = ::RegSetValueEx(hk, m_bstrValName, 0, REG_BINARY, buff.GetPtr(),(DWORD)buff.DataSize()); 
            if (lResult != ERROR_SUCCESS) {
                ::RegCloseKey(hk);
                return Error(IDS_E_SETVALUEFAILED);
            }
            ::RegCloseKey(hk);
            return S_OK;
        } else {
            return DISP_E_TYPEMISMATCH;
        }
    } else if (m_lType == REG_MULTI_SZ) {
        if (v.vt == (VT_ARRAY | VT_VARIANT)) {
            ccSafeArray<VARIANT,VT_VARIANT> csaVars = v.parray;
            v.ReleaseControl();
            ccBuffer    buff(0x100000); // A sensible limit
            ccVariant   varElement;

            for (LONG i = csaVars.LBound();i <= csaVars.UBound(); i++) {
                varElement.Clear();
                varElement <= csaVars[i];
                hr = varElement.ChangeType(VT_BSTR);
                if (FAILED(hr)) return hr;
                buff.Put((LPBYTE)varElement.bstrVal,((DWORD)::SysStringLen(varElement.bstrVal) + 1) * sizeof(WCHAR));
            }
            buff.Put((LPBYTE)(L"\0"),sizeof(WCHAR));
            
            lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	        if (lResult != ERROR_SUCCESS) return Error(IDS_E_CREATEKEYFAILED);

            lResult = ::RegSetValueEx(hk, m_bstrValName, 0, REG_MULTI_SZ, buff.GetPtr(),buff.DataSize()); 
            if (lResult != ERROR_SUCCESS) {
                ::RegCloseKey(hk);
                return Error(IDS_E_SETVALUEFAILED);
            }
            ::RegCloseKey(hk);
            return S_OK;

            
        } else {
            hr = v.ChangeType(VT_BSTR);
            if (FAILED(hr)) return hr;

            bstr = v.bstrVal;

            lResult = ::RegCreateKeyEx(m_hkRoot, m_bstrPath, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, &dwDisp );
	        if (lResult != ERROR_SUCCESS) return Error(IDS_E_CREATEKEYFAILED);

            lResult = ::RegSetValueEx(hk, m_bstrValName, 0, REG_SZ, (LPBYTE)(BSTR)bstr,(bstr.Length() + 1) * sizeof(WCHAR)); 
            if (lResult != ERROR_SUCCESS) {
                ::RegCloseKey(hk);
                return Error(IDS_E_SETVALUEFAILED);
            }
            ::RegCloseKey(hk);
            return S_OK;
        }
    } else {
        return Error(IDS_E_REGTYPEUNSUPPORTED);
    }
}

STDMETHODIMP CRegistry::get_UseRawBinary(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_dwBehavior & NSBASIC_REGISTRY_BINASBYTES)?TRUE:FALSE;
	return S_OK;
}

STDMETHODIMP CRegistry::put_UseRawBinary(VARIANT_BOOL newVal) {
	m_dwBehavior = m_dwBehavior & ~((DWORD)NSBASIC_REGISTRY_BINASBYTES);
    m_dwBehavior |= newVal?NSBASIC_REGISTRY_BINASBYTES:0;
	return S_OK;
}

STDMETHODIMP CRegistry::get_HexWithSpaces(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_dwBehavior & NSBASIC_REGISTRY_HEXWITHSPACES)?TRUE:FALSE;
	return S_OK;
}

STDMETHODIMP CRegistry::put_HexWithSpaces(VARIANT_BOOL newVal) {
	m_dwBehavior = m_dwBehavior & ~((DWORD)NSBASIC_REGISTRY_HEXWITHSPACES);
    m_dwBehavior |= newVal?NSBASIC_REGISTRY_HEXWITHSPACES:0;
	return S_OK;
}

STDMETHODIMP CRegistry::get_ReturnEmptyForEnumEnd(VARIANT_BOOL *pVal) {
	if (!pVal) return E_POINTER;
    *pVal = (m_dwBehavior & NSBASIC_REGISTRY_ENDENUMEMPTY)?VARIANT_TRUE:VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CRegistry::put_ReturnEmptyForEnumEnd(VARIANT_BOOL newVal) {
	m_dwBehavior = m_dwBehavior & ~((DWORD)NSBASIC_REGISTRY_ENDENUMEMPTY);
    m_dwBehavior |= newVal?NSBASIC_REGISTRY_ENDENUMEMPTY:0;
	return S_OK;
}
