// ccRegKey and ccRegKeyBinder classes.
//  First implements easy access to the registry
//  Second implements bindings between data members of a class derived from it
//      and registry values.
//  See the attached ccRegKey-README.TXT for more information
//
// This code is freeware and is provided AS IS without warranty.
//
// Michael Elfial - newObejcts 2001
////////////////////////////////////////

#ifndef _CC_CCREGKEY_H_
#define _CC_CCREGKEY_H_

#ifndef _CC_CLASS_ATTRIBUTES
    #define _CC_CLASS_ATTRIBUTES
#endif _CC_CLASS_ATTRIBUTES

    
class ccRegKey {
    HKEY        hkKey;
    LPTSTR      szBuffer;
    public:
    ccRegKey() {
        hkKey = NULL;
        szBuffer = NULL;
    }
    ~ccRegKey() {
        if (hkKey) RegCloseKey(hkKey);
        if (szBuffer) delete [] szBuffer;
    }
    bool    Open(HKEY hkParent,LPCTSTR szKey,REGSAM samDesired = KEY_ALL_ACCESS,bool bDontCreate = FALSE) {
        if (!szKey) return false;
        if (hkKey) Close();
        if (bDontCreate) {
            if (RegOpenKeyEx(hkParent,szKey,0,samDesired,&hkKey) != ERROR_SUCCESS) {
                hkKey = NULL;
                return false;
            }
        } else {
            if (RegCreateKeyEx(hkParent,szKey,0,NULL,REG_OPTION_NON_VOLATILE,samDesired,NULL,&hkKey,NULL) != ERROR_SUCCESS) {
                hkKey = NULL;
                return false;
            }
        }
        return true;
    }
    void Close() {
        if (hkKey) RegCloseKey(hkKey);
        hkKey = NULL;
    }
    ccRegKey*   GetEnumKeys(DWORD* n,REGSAM samDesired = KEY_ALL_ACCESS) {
        if (!hkKey) return NULL;
        ClearBuffer(MAX_PATH+1);
        if (RegEnumKey(hkKey,*n,szBuffer,MAX_PATH+1) != ERROR_SUCCESS) {
            return NULL;
        }
        ccRegKey*   prk = new ccRegKey;
        if (prk) {
            if (prk->Open(hkKey,szBuffer,samDesired)) {
                (*n)++;
                return prk;
            }
            delete prk;
            return NULL;
        }
        return prk;
    }
    LPTSTR  EnumValues(DWORD* n,BOOL* pbMore = NULL,DWORD* pdwType = NULL) {
        ClearBuffer(MAX_PATH);
        if (!hkKey) {
            if (pbMore) *pbMore = FALSE;
            if (pdwType) *pdwType = NULL;
            return szBuffer;
        }
        DWORD   dwType,cbData;
        LONG    l = RegEnumValue(hkKey,*n,szBuffer,&cbData,NULL,&dwType,NULL,NULL);
        switch (l) {
            case ERROR_SUCCESS:
                (*n)++;
                if (pbMore) *pbMore = TRUE;
                if (pdwType) *pdwType = dwType;
                return szBuffer;
            default:
                if (pbMore) *pbMore = FALSE;
                if (pdwType) *pdwType = NULL;
                return szBuffer;
        }
    }
    LPTSTR  String(LPCTSTR szValue,bool* pbError = NULL,DWORD dwSize = 0) {
        DWORD   dwType,cbData;
        ClearBuffer(dwSize);
        if (!hkKey) return szBuffer;
        cbData = dwSize;
        LONG l = RegQueryValueEx(hkKey,szValue,NULL,&dwType,(LPBYTE)szBuffer,&cbData);
        if (pbError) *pbError = false;
        switch (l) {
            case ERROR_MORE_DATA:
                ClearBuffer(cbData);
                if (RegQueryValueEx(hkKey,szValue,NULL,&dwType,(LPBYTE)szBuffer,&cbData) != ERROR_SUCCESS) {
                    ClearBuffer();
                    if (pbError) *pbError = true;
                    break;
                }                
            case ERROR_SUCCESS:
                if (dwType != REG_SZ && dwType != REG_MULTI_SZ && dwType != REG_EXPAND_SZ) {
                    ClearBuffer();
                    if (pbError) *pbError = true;
                }
            break;
            default:
                if (pbError) *pbError = true;
                ClearBuffer();
        }
        return szBuffer;        
    }
    inline LPTSTR  CurrentString() {
           return szBuffer;
    }
    DWORD   Number(LPCTSTR szValue,bool* pbError = NULL) {
        DWORD   dwResult,dwType,cbData = sizeof(DWORD);
        if (pbError) *pbError = false;
        if (RegQueryValueEx(hkKey,szValue,NULL,&dwType,(LPBYTE)&dwResult,&cbData) != ERROR_SUCCESS) {
            if (pbError) *pbError = true;
            return 0;
        } 
        return dwResult;
    }
    bool    SetString(LPCTSTR szValue,LPCTSTR szString) {
        if (!szString || !hkKey) return false;
        return (RegSetValueEx(hkKey,szValue,0,REG_SZ,(LPBYTE)szString,lstrlen(szString) + 1) == ERROR_SUCCESS);
    }
    bool    SetNumber(LPCTSTR szValue,DWORD dwNumber) {
        if (!szValue || !hkKey) return false;
        return (RegSetValueEx(hkKey,szValue,0,REG_DWORD,(LPBYTE)&dwNumber,sizeof(DWORD)) == ERROR_SUCCESS);
    }
    HKEY    GetKey() {
        return hkKey;
    }
    BOOL    IsValid() {
        return (hkKey)?TRUE:FALSE;
    }
private:
    inline void ClearBuffer(DWORD dwSize = 0) { 
        if (szBuffer) delete [] szBuffer;
        if (dwSize < 1) szBuffer = new TCHAR[1];
        else szBuffer = new TCHAR[dwSize];
        if (szBuffer) szBuffer[0] = '\0';
    }
};

// BINDING MACROS
#define BEGIN_REGBIND_MAP() void _DoRegistryTransfer(ccRegKey& rk,bool bDirection,bool bAutoCalled) {\
                bool bErr; bErr;
#define BEGIN_REGBIND_MAP2(key,loc) inline LPTSTR _GetRegistryDefaultLocation() { return (LPTSTR)loc; }\
            inline HKEY _GetRegistryDefaultBranch() { return (HKEY)key; }\
            void _DoRegistryTransfer(ccRegKey& rk,bool bDirection,bool bAutoCalled) {\
                bool bErr; bErr;
#define END_REGBIND_MAP() }

// Macros without default values - defaults are 0 for numbers and empty for strings
#define REGBIND_ENTRY_DWORD(n,x) if (bDirection) {\
                rk.SetNumber(n,x);\
            } else {\
                x = rk.Number(n);\
            }
#define REGBIND_ENTRY_STRING(n,xbuff,xsize) if (bDirection) {\
                rk.SetString(n,xbuff);\
            } else {\
                lstrcpyn(xbuff,rk.String(n),xsize);\
            }            
#define REGBIND_ENTRY_STRINGPTR(n,xptr) if (!bDirection) {\
                if (!bAutoCalled && xptr) delete [] xptr;\
                xptr = new TCHAR[lstrlen(rk.String(n)) + 1];\
                if (xptr) lstrcpy(xptr,rk.CurrentString());\
            } else {\
                rk.SetString(n,xptr);\
                if (bAutoCalled && xptr) {\
                    delete [] xptr; xptr = NULL;\
                }\
            }
#define REGBIND_ENTRY_CLSID(n,x) _BindClassIDHelper(rk,bDirection,n,&x,&CLSID_NULL);
                
// Macros with defaults
#define REGBIND_ENTRY_DWORD2(n,x,d) if (bDirection) {\
                rk.SetNumber(n,x);\
            } else {\
                x = rk.Number(n,&bErr);\
                if (bErr) x = d;\
            }
#define REGBIND_ENTRY_STRING2(n,xbuff,xsize,d) if (bDirection) {\
                    rk.SetString(n,xbuff);\
            } else {\
                lstrcpyn(xbuff,rk.String(n,&bErr),xsize);\
                if (bErr) lstrcpyn(xbuff,d,xsize);\
            }            
#define REGBIND_ENTRY_STRINGPTR2(n,xptr,d) if (!bDirection) {\
                    if (!bAutoCalled && xptr) delete [] xptr;\
                    xptr = new TCHAR[lstrlen(rk.String(n,&bErr)) + 1];\
                    if (bErr) {\
                        delete [] xptr;\
                        xptr = new TCHAR[lstrlen(d) + 1];\
                        if (xptr) lstrcpy(xptr,d);\
                    } else {\
                        if (xptr) lstrcpy(xptr,rk.CurrentString());\
                    }\
            } else {\
                rk.SetString(n,xptr);\
                if (bAutoCalled && xptr) {\
                    delete [] xptr; xptr = NULL;\
                }\
            }
#define REGBIND_ENTRY_CLSID2(n,x,d) _BindClassIDHelper(rk,bDirection,n,&x,&d);


                            
// Add calls to the StoreRegistryValues and RestoreRegistryValues
// in the appropriate locations in your class. Usualy these places will
// be constructor/destructor members. Alternativelly use the bAuto parameter
template <class T,bool bAuto = false,bool bAutoSave = false>
class _CC_CLASS_ATTRIBUTES ccRegKeyBinder {
    public:
    ccRegKeyBinder() {
        T* pt = static_cast<T*>(this);
        if (bAuto) pt->RestoreRegistryValues(true);
    }
    ~ccRegKeyBinder() {
        T* pt = static_cast<T*>(this);
        if (bAutoSave) pt->StoreRegistryValues();
    }
    // for destructors autocall
    inline bool StoreRegistryValues(bool bDestruct) {
        T* pt = static_cast<T*>(this);
        ccRegKey rk;
        if (    !rk.Open(   ((hkRoot)?hkRoot:pt->_GetRegistryDefaultBranch()),
                            ((szKey)?szKey:pt->_GetRegistryDefaultLocation()),
                            KEY_ALL_ACCESS)) return false;
        pt->_DoRegistryTransfer(rk,true,true);
        return true;
    }
    inline bool StoreRegistryValues(HKEY hkRoot = NULL,LPCTSTR szKey = NULL) {
        T* pt = static_cast<T*>(this);
        ccRegKey rk;
        if (    !rk.Open(   ((hkRoot)?hkRoot:pt->_GetRegistryDefaultBranch()),
                            ((szKey)?szKey:pt->_GetRegistryDefaultLocation()),
                            KEY_ALL_ACCESS)) return false;
        pt->_DoRegistryTransfer(rk,true,false);
        return true;
    }
    // for constructors autocall
    inline bool RestoreRegistryValues(bool bConstruct) {
        T* pt = static_cast<T*>(this);
        ccRegKey rk;
        if (    !rk.Open(   pt->_GetRegistryDefaultBranch(),
                            pt->_GetRegistryDefaultLocation(),
                            KEY_READ)) return false;
        pt->_DoRegistryTransfer(rk,false,bConstruct);
        return true;
    }
    inline bool RestoreRegistryValues(HKEY hkRoot = NULL,LPCTSTR szKey = NULL) {
        T* pt = static_cast<T*>(this);
        ccRegKey rk;
        if (    !rk.Open(   ((hkRoot)?hkRoot:pt->_GetRegistryDefaultBranch()),
                            ((szKey)?szKey:pt->_GetRegistryDefaultLocation()),
                            KEY_READ)) return false;
        pt->_DoRegistryTransfer(rk,false,false);
        return true;
    }
    // helpers
    inline void _BindClassIDHelper(ccRegKey& rk,bool bDirection,LPCTSTR name,CLSID* clsid,const CLSID* def) {
        OLECHAR     szClsid[256];
        #ifndef UNICODE
            CHAR  szTemp[256];
        #endif
        HRESULT     hr;
        if (bDirection) {
            LPOLESTR    pszClsid;
            hr = StringFromCLSID(*clsid,&pszClsid);
            if (!FAILED(hr)) {
                #ifndef UNICODE
                    // convert it
                    WideCharToMultiByte(CP_ACP,0,pszClsid,-1,szTemp,256,NULL,NULL);
                    rk.SetString(name,szTemp);
                #else
                    rk.SetString(name,pszClsid);
                #endif
                // write it
                CoTaskMemFree(pszClsid);
            }
        } else {
            bool bErr;

            #ifndef UNICODE
                lstrcpyn(szTemp,rk.String(name,&bErr),256);
                MultiByteToWideChar(CP_ACP,0,szTemp,-1,szClsid,256);
            #else
                lstrcpyn(szClsid,rk.String(name,&bErr),256);
            #endif

            if (bErr) { 
                CopyMemory(clsid,def,sizeof(CLSID));
            } else {
                hr = CLSIDFromString((LPOLESTR)szClsid,clsid);
                if (FAILED(hr)) {
                    // Set defaults again
                    CopyMemory(clsid,def,sizeof(CLSID));
                }
            }
        }
    }
    inline LPTSTR _GetRegistryDefaultLocation() {return NULL;};
    inline HKEY _GetRegistryDefaultBranch() {return (HKEY)HKEY_CURRENT_USER;};
        
    // Map defines it in the user class
    void _DoRegistryTransfer(ccRegKey& rk,bool bDirection) {
        //
    }
};

#endif // _CC_CCREGKEY_H_