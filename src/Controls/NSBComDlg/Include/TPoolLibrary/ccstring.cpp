// COMMONSTRIGS.CPP
//
// COMMON LIBRARY (31.01.1998)
// STRING OBJECTS
////////////////////////////////

#ifndef _COMMON_INTERNAL_STRING_ROUTINES_
#define _COMMON_INTERNAL_STRING_ROUTINES_
// internals
LONG	_Internal_FindSubString(LPTSTR sz,LPTSTR szc,LONG posbegin,LONG posmax) {
    LONG	i,j;
	LONG    l = _tcslen(szc);
	for (i = posbegin; i <= posmax; i++) {
		for (j = 0; j <	l; j++) {
			if (sz[i+j] != szc[j]) break;
		}
		if (j == l) return i;
	}
	return -1;
}
LONG	_Internal_FindSubStringNoCS(LPTSTR sz,LPTSTR szc,LONG posbegin,LONG posmax) {
	LONG	i,j;
	LONG    l = _tcslen(szc);
	for (i = posbegin; i <= posmax; i++) {
		for (j = 0; j <	l; j++) {
			//if (CharUpper((STRPTR)sz[i+j]) != CharUpper((STRPTR)szc[j])) break;
            if (CharUpper((LPTSTR)sz[i+j]) != CharUpper((LPTSTR)szc[j])) break;
		}
		if (j == l) return i;
	}
	return -1;
}
#endif // _COMMON_INTERNAL_STRING_ROUTINES_

// ccString
////////////////////////

#ifdef COMMON_DEBUG_OBJECTS
	void	 ccString::sdo_INC() { ccString::sdo_objectCount ++;}
	void	 ccString::sdo_DEC() { ccString::sdo_objectCount --;}
	DWORD 	 ccString::sdo_GET() { return ccString::sdo_objectCount;}
	DWORD    ccString::sdo_objectCount = 0;
#endif


// CONSTRUCTORS - ccString
ccString::ccString() {
	// creates empty string
	if (!Create(NULL)) m_btError = STROBJ_ERROR_INVALID;
	#ifdef COMMON_DEBUG_OBJECTS
		ccString::sdo_INC();
	#endif
}
ccString::ccString(ccString& str) {
	if ( !Create((LPTSTR)str) ) m_btError = STROBJ_ERROR_INVALID;
	m_btError = str.m_btError;
	m_nPos = str.m_nPos;
	m_nPosLen = str.m_nPosLen;
	#ifdef COMMON_DEBUG_OBJECTS
		ccString::sdo_INC();
	#endif    
}
ccString::ccString(LPTSTR szInit,BYTE btState) {
	if (!Create(szInit)) m_btError = STROBJ_ERROR_INVALID;
	if (m_btError != STROBJ_ERROR_INVALID) m_btError = btState;
	#ifdef COMMON_DEBUG_OBJECTS
		ccString::sdo_INC();
	#endif    
}
ccString::ccString(BYTE btErr) {
	Create(NULL);
	m_btError = btErr;
	#ifdef COMMON_DEBUG_OBJECTS
		ccString::sdo_INC();
	#endif
}
ccString::ccString(PccString pstr) {
	if (pstr) {
		if (pstr->Success()) {
			if (!Create(pstr->GetStrPtr())) m_btError = STROBJ_ERROR_INVALID;
		} else {
			if (!Create(NULL)) m_btError = STROBJ_ERROR_INVALID;
		}
		if (m_btError != STROBJ_ERROR_INVALID) m_btError = pstr->m_btError;
		m_nPos = pstr->m_nPos;
		m_nPosLen = pstr->m_nPosLen;
	} else {
		if (!Create(NULL)) m_btError = STROBJ_ERROR_INVALID;
	}
	#ifdef COMMON_DEBUG_OBJECTS
		ccString::sdo_INC();
	#endif	
}


// DESTRUCTOR - ccString
ccString::~ccString() {
	if (m_szString) delete [] m_szString;
    #ifdef COMMON_DEBUG_OBJECTS
		ccString::sdo_DEC();
	#endif
}










// Creation helper - ccString
BOOL            ccString::ccString(LPTSTR sz) {
	m_nPos      = -1;
	m_btError   = 0;
    m_nPosLen   = 0;

    if (sz) {
        m_szString = (STRPTR)(new BYTE[osStrByteLenT(sz) + sizeof(STR)]);
        if (!m_szString) {
            m_szString = NULL;
            return FALSE;
        }
        lstrcpy(m_szString,sz);
    } else {
        m_szString = new STR[1];
        m_szString[0] = _TEXT('\0');
    }
    return TRUE;
}

STRPTR          STRING::CopyTo(STRPTR sz,int cChars) {
	if (!sz) return NULL;
	if (cChars) {
		if (cChars < (Length() + 1)) return NULL;
	} 
	if (IsEmpty()) sz[0] = _TEXT('\0');
    else lstrcpy(sz,m_szString);
    return sz;
}
#ifndef UNICODE
    LPWSTR          STRING::CopyToW(LPWSTR szw,int cChars) {
    	int	i;
        if (cChars < 0) return NULL;
        i = MultiByteToWideChar(CP_ACP,0,m_szString,cChars,szw,cChars);
        if (i)  szw[i] = L'\0';
        else return NULL;
        return szw;
    }
#endif
STRPTR          STRING::Allocate(int nIn) {
    int n = (nIn < 1)?1:nIn;
    if (Length() >= n) return m_szString;
    STRPTR      lpsz;
    
    lpsz = new STR[n + 1];
    if (m_szString) {
        lstrcpy(lpsz,m_szString);
        delete [] m_szString;
    } else {
        lpsz[0] = _TEXT('\0');
    }
    m_szString = lpsz;
    return m_szString;
}
BOOL            STRING::Success() const {
    if (m_btError) return FALSE;
    return TRUE;
}
void			STRING::SetError(BYTE btErr) {
	m_btError = btErr;
}
int             STRING::Length() {
	if (!Success()) return 0;
	return lstrlen(m_szString);
}
void    STRING::ResetContents() {
    if (m_szString) delete [] m_szString;
    if (!Create(NULL)) m_btError = STROBJ_ERROR_INVALID;
}
STRING& STRING::SetFromBuff(LPWSTR wsz, int nChars, UINT uCP) {
    if (!wsz) {
        ResetContents();
    } else {
        int nLenFull = nChars;
        if (nChars < 0) {
            // Calculate the length
            nLenFull = wcslen(wsz);
        }
        if (m_szString) delete [] m_szString;
        m_szString = NULL;
        #ifdef UNICODE
            // UNICODE is native
            // Just copy the nLenFull chars
            m_szString = new STR[nLenFull + 1];
            if (!m_szString) {
                ResetContents();
                m_btError = STROBJ_ERROR_INVALID;
            } else {
                CopyMemory(m_szString,wsz,sizeof(WCHAR) * nLenFull);
                m_szString[nLenFull] = L'\0';
                m_btError = STROBJ_ERROR_OK;
            }
        #else
            // ANSI is native
            // We must convert
            m_szString = UnicodeToAnsi(uCP,(LPCWSTR)wsz,nLenFull);
            if (!m_szString) {
                ResetContents();
                m_btError = STROBJ_ERROR_INVALID;
            } else {
                m_szString[nLenFull] = '\0';
                m_btError = STROBJ_ERROR_OK;
            }
        #endif // UNICODE
    }
    return SELF;
}
STRING& STRING::SetFromBuff(LPSTR sz, int nChars, UINT uCP) {
    if (!sz) {
        ResetContents();
    } else {
        int nLenFull = nChars;
        if (nChars < 0) {
            // Calculate the length
            nLenFull = osStrByteLen(sz);
        }
        if (m_szString) delete [] m_szString;
        m_szString = NULL;
        #ifdef UNICODE
            // UNICODE is native
            // Convert
            m_szString = AnsiToUnicode(uCP,(LPCSTR)sz,nLenFull);
            m_btError = STROBJ_ERROR_OK;
            if (!m_szString) {
                ResetContents();
                m_btError = STROBJ_ERROR_INVALID;
            }
        #else
            // ANSI is native
            // Just copy
            m_szString = new STR[nLenFull + 1];
            if (!m_szString) {
                ResetContents();
                m_btError = STROBJ_ERROR_INVALID;
            } else {
                CopyMemory(m_szString,sz,sizeof(STR) * nLenFull);
                m_szString[nLenFull] = '\0';
                m_btError = STROBJ_ERROR_OK;
            }
            
        #endif // UNICODE
    }
    return SELF;
}

#ifdef UNICODE
STRING&	STRING::Set(const STRPTR sz,UINT uCP) {
#else
STRING&	STRING::Set(const STRPTR sz) {
#endif
	if (sz) {
        if (m_szString) delete [] m_szString;
		m_szString = (STRPTR)(new BYTE[osStrByteLenT(sz) + sizeof(STR)]);
		if (m_szString) {
			m_btError = 0;
			lstrcpy(m_szString,sz);
            ResetPos();
		} else {
			m_btError = STROBJ_ERROR_INVALID;
		}
    } else {
        ResetContents();
    }
	return SELF;
}
STRING&	  STRING::Set(const STRPTR sz,int n) {
	if (sz && n >= 0) {
        if (m_szString) delete [] m_szString;
		m_szString = new STR[n + 1];
		if (m_szString) {
			m_btError = 0;
			lstrcpyn(m_szString,sz,n+1);
            ResetPos();
		} else {
			m_btError = STROBJ_ERROR_INVALID;
		}
    } else {
        ResetContents();
    }
	return SELF;
}
STRING&   STRING::LoadString(UINT uID,HINSTANCE hModule) {
    STR _l[1024];
    if (::LoadString((hModule == NULL) ? GetModuleHandle(NULL) : hModule,uID,_l,1024)) return Set(_l);
    Set((STRPTR)NULL);
    SetError(STROBJ_ERROR_OPERATIONFAILED);
    return SELF;
}

#ifndef COMMON_EXCLUDE_SOMEOLEFEATURES                
    #ifndef UNICODE    
        STRING&	STRING::Set(LPCOLESTR ostr,UINT uCP) {
            LPSTR   lpsz = STRING::UnicodeToAnsi(uCP,ostr);
            if (lpsz) {
                Set(lpsz);
                delete [] lpsz;
            }
            return SELF;
        }
    #endif // UNICODE
#endif // COMMON_EXCLUDE_SOMEOLEFEATURES                

LPWSTR          STRING::AnsiToUnicode(UINT uCodePage,LPCSTR sz, int convLen) {
        int l;
        if (convLen < 0) {
            #ifdef _COMMON_PLATFORM_WINCE
                l = osStrByteLen((LPSTR)sz) + 1;
            #endif
            #ifdef _COMMON_PLATFORM_WINPC
                l = osStrByteLen((LPSTR)sz) + 1;
            #endif
        } else {
            l = convLen + 1;
        }
        LPWSTR  lpwsz = new WCHAR[l];
		ZeroMemory(lpwsz,l * sizeof(WCHAR));
        if (MultiByteToWideChar(uCodePage,0,sz,convLen,lpwsz,l))
            return lpwsz;
        if (lpwsz) delete [] lpwsz;
        return NULL;
}
LPSTR           STRING::UnicodeToAnsi(UINT uCodePage,LPCWSTR wsz, int convLen) {
        int reqLen;
		reqLen = WideCharToMultiByte(uCodePage,0,wsz,convLen,NULL,0,NULL,NULL);
        LPSTR  lpsz = new CHAR[reqLen + 1];
		ZeroMemory(lpsz,reqLen + 1);
        if (WideCharToMultiByte(uCodePage,0,wsz,convLen,lpsz,reqLen+1,NULL,NULL))
            return lpsz;
        if (lpsz) delete [] lpsz;
        return NULL;
}
LPWSTR          STRING::toUnicode(UINT uCodePage) {
    if (!m_szString) return NULL;
    #ifdef UNICODE
        LPWSTR  lpwsz = new WCHAR[lstrlenW(m_szString) + 1];
        lstrcpyW(lpwsz,m_szString);
        return lpwsz;
    #else
        return STRING::AnsiToUnicode(uCodePage,m_szString);
    #endif
}
LPSTR           STRING::toAnsi(UINT uCodePage) {
    if (!m_szString) return NULL;
    #ifdef UNICODE
        return STRING::UnicodeToAnsi(uCodePage,m_szString);
    #else
        LPSTR  lpsz = new CHAR[osStrByteLen(m_szString) + sizeof(CHAR)];
        lstrcpyA(lpsz,m_szString);
        return lpsz;
    #endif
}
STRING          STRING::toUpper() {
    STRING str = SELF;
    osUpperBuff(str.m_szString,str.Length());
    return str;
}
STRING          STRING::toLower() {
    STRING str = SELF;
    osLowerBuff(str.m_szString,str.Length());
    return str;
}
STRING          STRING::toCapitalized() {
    STRING str = SELF;
    if (Length()) {
        osUpperBuff(str.m_szString,1);
        osUpperBuff(&str.m_szString[1],str.Length()-1);
    }
    return str;
}
STRING   STRING::Left(int nChars) {
    if (nChars < 0 && m_nPos >= 0) {
        return Mid(0,(m_nPosLen < 0)?(m_nPos + m_nPosLen):m_nPos);
    }
	return Mid(0,nChars);
}
STRING	STRING::Right(int nChars) {
    int l = Length();
    if (nChars < 0 && m_nPos >= 0) {
        int nPos = GetNormalizedPos();
        return Mid((m_nPosLen > 0)?(m_nPos + m_nPosLen):m_nPos,Length());
    }
	return Mid(l-nChars,Length());		
}
STRING	STRING::Mid(int nPosIn,int nCharsIN) {
    register    int nPos = (nPosIn >= 0)?nPosIn:(Length() + nPosIn);
    register    int nChars = (nCharsIN > 0)?nCharsIN:(-nCharsIN);
    nPos = (nCharsIN > 0)?nPos:(nPos - nChars);
    if (nPos < 0) {
        nChars = nChars + nPos;
        nPos = 0;
    }
	
    STRING      str;
	if (nPos >= Length()) return str;
	if (nPos < 0) nPos = 0;

	STRPTR			psz = &(m_szString[nPos]);
	int				n = ((Length() - nPos) < nChars)?(Length() - nPos):nChars;
	n = (n < 0)?0:n;
	STRPTR			psz1 = new STR[n + 1];

    if (!psz1) {
        str.SetError(STROBJ_ERROR_INVALID);
        return str;
    }
	lstrcpyn(psz1,psz,n+1);
	str.Set(psz1);
	delete [] psz1;
	return str;
}
STRING          STRING::Mid(STRPTR szPos,int m) {
	int n = static_cast<int>(szPos - m_szString);
	return Mid(n,m);
}
STR&			STRING::Char(int n) {
    static STR static_constant_null_character = _TEXT('\0');
	if (n < Length() && n >= 0) return m_szString[n];
    // Dangerous !!!
	return static_constant_null_character;
}
STRING&	        STRING::operator=(const STRING& so) {
    Set((STRPTR)so);
    m_btError = so.m_btError; m_nPos = so.m_nPos; m_nPosLen = so.m_nPosLen;
    return SELF;
}

STRING	STRING::Concat(STRPTR sz) {
    STRING      str;
	STRPTR		psz;
    // Copy to str
	if(sz)
	{
		psz = new STR[Length()+lstrlen(sz)+1];
		if (!psz) {
			str.SetError(STROBJ_ERROR_OPERATIONFAILED);
			return str;
		}
		psz[0]=_TEXT('\0');
		if (m_szString) lstrcpy(psz,m_szString);
		lstrcat(psz,sz);
        str.AttachTo(psz);
		return str;
    } else {
        str.Set(GetStrPtr());
    }
	return str;
}
STRING   STRING::SafeConcat(STR ch,STRPTR sz) {
    STR      _l[2];
    _l[0] = ch; _l[1] = _TEXT('\0');
    STRING      str;
    if ((Length()==0) || (ch != m_szString[Length()-1])) str = Concat(_l);
    else str = SELF;
    return str.Concat(sz);
}
int				STRING::FindChar(STR ch,int nPos) {
	int	i;
	int	l = Length();
	int nP = (nPos >= 0)?nPos:0;
	for (i = nP; i < l; i++) {
		if (m_szString[i] == ch) return i;
	}
	return -1;
}
int				STRING::FindLastChar(STR ch,int nPos) {
	int	i;
	int	l = Length();
	for (i = l-1; i >= nPos && i >= 0; i--) {
		if (m_szString[i] == ch) return i;
	}
	return -1;
}
int				STRING::FindChar(STRPTR sz,int nPos) {
	if (!sz) return -1;
	int	i,j;
	int	l = Length();
	int nP = (nPos >= 0)?nPos:0;
	int ls = lstrlen(sz);
	for (i = nP; i < l; i++) {
		for (j = 0; j < ls; j++) {
			if (m_szString[i] == sz[j]) return i;
		}
	}
	return -1;
}
int             STRING::FindLastChar(STRPTR sz,int nPos) {
	if (!sz) return -1;
	int	i,j;
	int	l = Length();
	int ls = lstrlen(sz);
	for (i = l-1; i >= nPos && i >= 0; i--) {
		for (j = 0; j < ls; j++) {
			if (m_szString[i] == sz[j]) return i;
		}
	}
	return -1;
}
STRPTR			STRING::GetStrPtr() const {
	if (Success()) return m_szString;
	return NULL; 
}
STRING&	STRING::AttachTo(STRPTR lpsz) {
    if (m_szString) {
        delete [] m_szString;
        m_szString = NULL;
    }
    if (lpsz) m_szString = lpsz;
    else Set((STRPTR)NULL);
    ResetPos();
	return SELF;
}
void			STRING::SetPos(int n) {
	m_nPos = n;
}
int				STRING::GetNormalizedPos() {
	if (m_nPos < Length() && m_nPos >= 0) return m_nPos;
	if (m_nPos >= Length()) return Length();
	if (m_nPos < 0) return 0;
	return m_nPos;
}
int				STRING::GetPos() {
	return m_nPos;
}
STRING	        STRING::operator*(int n) {
    STRING  str;
    for (int i = 0; i < n; i++) {
        str += SELF;
    }
    return str;
}
// friend
STRING	operator*(int n,STRING str) {
    return (str * n);
}
STRING	STRING::operator + (STRPTR sz) {
	return Concat(sz);
}
STRING	STRING::operator + (STRING str) {
	return Concat((STRPTR)str);
}
//friend 
STRING	operator+(STRPTR sz,STRING strRight) {
    STRING     str(sz);
    return (str + strRight);
}
STRING	STRING::operator-(STRING strRight) {
    STRING str;
    int l = strRight.Length();
    if (l >= Length()) return str;
    register int nPos = FindSubString(strRight);
    if (nPos != 0) return str;
    str = Mid(l,Length());
    return str;
}
STRING  STRING::operator-(STRPTR sz) {
    STRING str = sz;
    return (SELF - str);
}
STRING   operator-(STRPTR sz,STRING strRight) {
    STRING str = sz;
    return (str - strRight);
}

STRING	STRING::operator << (STRPTR sz) {
    STRING  str((STRPTR)SELF);
    if (m_nPos < 0 || m_nPos > Length() || !sz) return str;
    str = Insert(sz,m_nPos);
    str.SetPos(GetPos() + lstrlen(sz));
    return str;
}
STRING	STRING::operator << (STRING str) {
    return SELF << (STRPTR)str;
}
STRING	STRING::operator >> (STRING str) {
    return str << SELF;
}
//friend  
STRING	operator >> (STRPTR sz,STRING str) {
    return str << sz;
}

STRING	STRING::operator >> (STRPTR sz) {
    STRING  str(sz);
    str.SetPos(str.Length());
    return str + SELF;
}
STRING	STRING::operator <  (STRPTR sz) {
    STRING str = Replace(sz,m_nPos,m_nPosLen);
    if (m_nPos < 0 || m_nPos > Length()) return str;
    int l = ((sz)?lstrlen(sz):0);
    str.SetPos((m_nPosLen >= 0)?(GetPos() + l):(GetPos() + l + m_nPosLen));
    return str;
}
STRING	STRING::operator <  (STRING str) {
    return SELF < (STRPTR)str;
}
STRING	STRING::operator >  (STRING str) {
    return (str < SELF);
}
//friend  
STRING	operator >  (STRPTR sz,STRING str) {
    return str < sz;
}
BOOL			STRING::IsEqual(STRPTR sz,BOOL bCase) {
	if (sz == GetStrPtr()) return TRUE;
	if (!sz) return FALSE;
	if (bCase) {
		return (lstrcmp(sz,GetStrPtr()) == 0);
	} else {
		return (lstrcmpi(sz,GetStrPtr()) == 0);
	}
}
int             STRING::Lookup(STRPTR sz,BOOL bCase /*= FALSE*/,int nLimit /*= -1*/) {
    if (!sz) return -1;
    int limit = (nLimit < 0)?lstrlen(sz):nLimit;
    int l = Length();
    limit -= l;
    int i,j;

    if (bCase) {
        for (i = 0; i < limit; i++) {
            for (j = i; j < l + i; j++) {
                if (sz[j] != m_szString[j-i]) {
                    // Not match
                    goto LBL_STRING_LOOKUP1;
                }
            }
            // Matches
            return i;
            LBL_STRING_LOOKUP1:
            // Try next
            continue;
        }
    } else {
        for (i = 0; i < limit; i++) {
            for (j = i; j < l + i; j++) {
                if (osUpper(sz[j]) != osUpper(m_szString[j-i])) {
                    // Not match
                    goto LBL_STRING_LOOKUP2;
                }
            }
            // Matches
            return i;
            LBL_STRING_LOOKUP2:
            // Try next
            continue;
        }
    }
    return -1;
}
BOOL            STRING::Beginning(STRPTR sz,BOOL bCase /* FALSE */,int nLimit /* -1 */) {
    if (!sz) return FALSE;
    int limit = (nLimit < 0)?lstrlen(sz):nLimit;
    int l = Length();
    if (l > limit) return FALSE;
    
    int i;

    if (bCase) {
        for (i = 0; i < l; i++) {
            if (sz[i] != m_szString[i]) {
                return FALSE;
            }
        }
    } else {
        for (i = 0; i < l; i++) {
            if (osUpper(sz[i]) != osUpper(m_szString[i])) {
                    return FALSE;
            }
        }
    }
    return TRUE;
}
int             STRING::LookupFirstChar(STRPTR sz,BOOL bCase,int nLimit) {
    if (!sz) return -1;
    int limit = (nLimit < 0)?lstrlen(sz):nLimit;
    int l = Length();
    int i,j;

    if (bCase) {
        for (i = 0; i < limit; i++) {
            for (j = 0; j < l; j++) {
                if (sz[i] == m_szString[j]) {
                    // match
                    return i;
                }
            }
        }
    } else {
        for (i = 0; i < limit; i++) {
            for (j = 0; j < l; j++) {
                if (osUpper(sz[i]) == osUpper(m_szString[j])) {
                    // match
                    return i;
                }
            }
        }
    }
    return -1;
}

STRING&	        STRING::operator <<=(STRPTR sz) {
    STRING      str = SELF << sz;
    SELF = (STRPTR)str;
    return SELF;
}
STRING&	        STRING::operator <<=(STRING strRight) {
    STRING      str = SELF << strRight;
    SELF = (STRPTR)str;
    return SELF;
}
STRING&	        STRING::operator <= (STRPTR sz) {
    STRING      str = SELF < sz;
    SELF = (STRPTR)str;
    return SELF;
}
STRING&	        STRING::operator <= (STRING strRight) {
    STRING      str = SELF < strRight;
    SELF = (STRPTR)str;
    return SELF;
}
PSTRING	    STRING::CopySelf() {
	PSTRING	    ps = new STRING(SELF);
	ps->SetPos(GetPos());
	ps->m_btError = m_btError;
    ps->m_nPosLen = m_nPosLen;
	return ps;
}
STRING	STRING::Insert(STRPTR sz,int n) {
	STRPTR		psz;
    STRING      str;
	if (n >=0 && n <= Length()) {
		psz = new STR[lstrlen(sz) + Length() + 1];
		if (!psz) {
			str.SetError();
			return str;
		}
		lstrcpyn(psz,GetStrPtr(),n+1);
		lstrcat(psz,sz);
		lstrcat(psz,&(m_szString[n]));
		str.AttachTo(psz);
    } else str = SELF;
	return str;
}
STRING	STRING::Replace(STRPTR sz,int posIN,int countIN) {
	STRPTR				psz;
	register	int		pos2;
    register    int     pos = posIN;
    STRING              str;
    int                 count   = countIN;
	if (pos >=0 && pos <= Length()) {
        if (count < 0) {
            pos = (pos + count >= 0)?(pos + count):0;
            count = (posIN + count >= 0)?(-count):posIN;
        }
		if ((pos + count) > Length()) pos2 = Length();
		else pos2 = pos+count;
		psz = new STR[lstrlen(sz) + Length() + 1 - pos2 + pos];
		if (!psz) {
			str.SetError();
			return str;
		}
		lstrcpyn(psz,GetStrPtr(),pos+1);
		lstrcat(psz,sz);
		lstrcat(psz,&(m_szString[pos2]));
		str.AttachTo(psz);
    } else str = SELF;
	return str;		
}
STRING	STRING::Remove(int pos,int count) {
	return Replace(_TEXT(""),pos,count);
}
STRING	STRING::ReplaceTrailing(STRPTR sz,STRPTR szWith) {
    STRING str(SELF);
    if (!sz) {
        return str;
    }
    int i,pos;
    int l = lstrlen(sz);
    for (pos = (SELF.Length() - 1); pos > 0; pos --) {
        for (i = 0; i < l; i++) {
            if (sz[i] == SELF[pos]) goto COUNTINUE_STRCLASS_RT;
        }
        break;
COUNTINUE_STRCLASS_RT:
        continue;
    }
    // now pos is last character that will not be removed
    //printf("F:%s W:%s pos:%d len:%d",sz,szWith,pos,SELF.Length());
    if (pos < (SELF.Length() - 1))
        str = Replace(szWith,pos+1,SELF.Length() - pos - 1);
    return str;
}
STRING	STRING::ReplaceStarting(STRPTR sz,STRPTR szWith) {
    if (!sz) return SELF;
    int i,pos = SELF.Length();
    int l = lstrlen(sz);
    int lSelf = SELF.Length();
    for (pos = 0; pos < lSelf; pos ++) {
        for (i = 0; i < l; i++) {
            if (sz[i] == SELF[pos]) goto CONTINUE_SO_RS;
        }
        break;
CONTINUE_SO_RS:        
        continue;
    }
    // now pos is last character that will not be removed
    return Replace(szWith,0,pos);
}
STRING          STRING::Trim(STRPTR sz) {
    STRING str(SELF);
    if (!sz) {
	    str = str.ReplaceStarting(_TEXT(" "),_TEXT(""));
	    str = str.ReplaceTrailing(_TEXT(" "),_TEXT(""));
	} else {
		str = str.ReplaceStarting(sz,_TEXT(""));
	    str = str.ReplaceTrailing(sz,_TEXT(""));
	}
    return str;
}
STRING          STRING::dbEscape() {
    if (IsEmpty()) return SELF;
    int j=0,l = Length();
    STRPTR      lpsz = new STR[l * 2 + 1];
    if (!lpsz) return SELF;    
    for (int i = 0; i < l; i++) {
        lpsz[j] = m_szString[i];
        j++;
        if (m_szString[i] == _TEXT('\'')) {
            lpsz[j] = _TEXT('\'');
            j++;
        }
    }
    STRING  str(lpsz);
    return str;
}
STRING	STRING::ReplaceCharacters(STRPTR szChars,STRPTR szWith) {
    STRING  str = m_szString;
    int j,i,l = str.Length();
    int lMask = lstrlen(szChars);
    if (lMask != lstrlen(szWith)) {
        str.SetError();
        return str;
    }
    for (i = 0; i < l; i++) {
        for (j = 0; j < lMask; j++) {
            if (str.m_szString[i] == szChars[j]) {
                str.m_szString[i] = szWith[j];
            }
        }
    }
    return str;
}
STRING	STRING::RemoveCharacters(STRPTR szChars) {
    STRING  str;
    int j,i,l = Length();
    int lMask = lstrlen(szChars);
    STRPTR  lpsz = new STR[l + 1];
    if (!lpsz) {
        str = m_szString;
        return str;
    }
    int k = 0;
    BOOL bNoCopy;
    for (i = 0; i < l; i++) {
        bNoCopy = FALSE;
        for (j = 0; j < lMask; j++) {
            if (m_szString[i] == szChars[j]) {
                bNoCopy = TRUE;
                break;
            }
        }
        if (!bNoCopy) {
            lpsz[k] = m_szString[i];
            k++;
        }
    }
    lpsz[k] = _TEXT('\0');
    str = lpsz;
    delete lpsz;
    return str;
}

STRING	STRING::URLEncodeUTF8(int nType, UINT uCP) {
	STRING	str;
	// Convert to WStr first
	LPWSTR	wsz = toUnicode(uCP);
	if (!wsz) return str;
	// Encode to UTF8
	
	LPSTR	szSrc = ConvertWStrToUTF8(wsz);
	delete [] wsz;
	if (!szSrc) return str;

	LPSTR	szDst = URLEncodeString(szSrc,nType);
	delete [] szSrc;
	if (!szDst) {
		return str;
	}
	str.SetFromBuff(szDst,-1,uCP);
	delete [] szDst;
	return str;
}
STRING	STRING::URLEncode(int nType, UINT uCP) {
	// First we must make sure the source is ANSI
	STRING	str;
	LPSTR	szSrc = toAnsi(uCP);
	if (!szSrc) return str;

	LPSTR	szDst = URLEncodeString(szSrc,nType);
	delete [] szSrc;
	if (!szDst) {
		return str;
	}
	str.SetFromBuff(szDst,-1,uCP);
	delete [] szDst;
	return str;
}
STRING	STRING::URLDecodeUTF8(UINT uCP,BOOL* pbErr) {
	// First we must make sure the source is ANSI
	STRING	str;
	LPSTR	szSrc = toAnsi(uCP);
	if (!szSrc) return str;
	
	LPSTR	szDst = URLDecodeString(szSrc);
	delete [] szSrc;
	if (!szDst) {
		return str;
	}
	// szDst is the UTF8 string
	LPWSTR wsz = ConvertUTF8ToWStr(szDst,pbErr);
	delete [] szDst;
	if (!wsz) return str;

	str.SetFromBuff(wsz,-1,uCP);
	delete [] wsz;
	return str;
}
STRING	STRING::URLDecode(UINT uCP) {
	// First we must make sure the source is ANSI
	STRING	str;
	LPSTR	szSrc = toAnsi(uCP);
	if (!szSrc) return str;

	LPSTR	szDst = URLDecodeString(szSrc);
	delete [] szSrc;
	if (!szDst) {
		return str;
	}
	str.SetFromBuff(szDst,-1,uCP);
	delete [] szDst;
	return str;
}

STRING   STRING::HTMLEncode() {
    int i;
	int l = Length();
	if (!m_szString) return SELF;
	STRPTR	lpsz = new STR[l*6 + 1];
	if (!lpsz) return SELF;
	lpsz[0] = _TEXT('\0');
	//STR	_l[10];
    int nPrintPos = 0;
	for (i = 0;i < l; i++) {
		if ( (m_szString[i] > 32) && (m_szString[i] < 48) ||
            (m_szString[i] > 57) && (m_szString[i] < 64) ) {
			nPrintPos += wsprintf(&lpsz[nPrintPos],_TEXT("&#%03u;\0"),(DWORD)m_szString[i]);
		} else {
			nPrintPos += wsprintf(&lpsz[nPrintPos],_TEXT("%c\0"),m_szString[i]);
		}
		//lstrcat(lpsz,_l);
	}
	STRING  str(lpsz);
	return str;
}
STRING          STRING::DirPathName(int nMaxSize) {
    STRING  str;
    STRPTR  lpsz = NULL;
    GetFullPathName(m_szString,(DWORD)nMaxSize,str.Allocate((DWORD)nMaxSize),&lpsz);
    if (lpsz) lpsz[0] = _TEXT('\0');
    return str;
}
STRING          STRING::ExtractFileName(int nMaxSize) {
    STRING  strTmp,str;
    STRPTR  lpsz = NULL;
    GetFullPathName(m_szString,(DWORD)nMaxSize,strTmp.Allocate((DWORD)nMaxSize),&lpsz);
    if (lpsz) str = lpsz;
    return str;
}
STRING          STRING::ExtractFileNameOnly(int nMaxSize) {
    STRING  strTmp,str;
    STRPTR  lpsz = NULL;
    GetFullPathName(m_szString,(DWORD)nMaxSize,strTmp.Allocate((DWORD)nMaxSize),&lpsz);
    if (lpsz) str = lpsz;
	long l = str.FindLastChar(_TEXT('.'));
	if (l >= 0) {
		str = str.Mid(0,l);
	}
    return str;
}
STRING          STRING::FullPathName(int nMaxSize) {
    STRING  str;
    STRPTR  lpsz = NULL;
    GetFullPathName(m_szString,(DWORD)nMaxSize,str.Allocate((DWORD)nMaxSize),&lpsz);
    return str;
}
STRING          STRING::ExtractExtension(int nMaxSize) {
    STRING  str,strTmp;
    STRPTR  lpsz = NULL;
    GetFullPathName(m_szString,(DWORD)nMaxSize,strTmp.Allocate((DWORD)nMaxSize),&lpsz);
    int l = strTmp.Length();
    if (strTmp[l-1] == _TEXT('\\') || strTmp[l-1] == _TEXT('/')) {
        str = _TEXT("");
    } else {
        str = lpsz;
        l = str.FindLastChar(_TEXT('.'));
        if (l >= 0) {
            str = str.Mid(l+1,str.Length());
        } else {
            str = _TEXT("");
        }
    }
    return str;
}
int				STRING::FindSubString(const STRPTR sz,int pos) {
	int	l = lstrlen(sz);
	if (pos > (Length() - l)) return -1;
	if (IsEmpty()) return -1;
	return	_Internal_FindSubString(m_szString,sz,pos,Length() - l);
}
int				STRING::FindSubStringCaseInsensetive(STRPTR sz,int pos) {
    int	l = lstrlen(sz);
	if (pos > (Length() - l)) return -1;
	if (IsEmpty()) return -1;
	return	_Internal_FindSubStringNoCS(m_szString,sz,pos,Length() - l);
}
STRING	STRING::operator/(int n) {
    STRING  str;
	if (n < 0) return str;
	return Left(n);
}
STRING	STRING::operator%(int n) {
    STRING  str;
	if (n >= Length()) return str;
	return Mid(n,Length());		
}
STRING	STRING::operator/(STRING so) {
	int		i = FindSubString(so,GetNormalizedPos());
    STRING  str;
	if (i < 0) return str;
	return Left(i);
}

STRING	STRING::operator%(STRING so) {
	int		i = FindSubString(so,GetNormalizedPos());
    STRING  str;
	if (i < 0) return str;
	return Mid(i + so.Length(),Length());		
}
STRING	STRING::operator/(STRPTR sz) {
	STRING	so(sz);
	return SELF / so;
}
STRING	STRING::operator%(STRPTR sz) {
	STRING	so(sz);
	return SELF % so;
}
STRING	STRING::operator/(STR ch) {
    STR     sz[2];
    sz[0] = ch; sz[1] = _TEXT('\0');
    return SELF / sz;
}
				
STRING	STRING::operator%(STR ch) {
    STR     sz[2];
    sz[0] = ch; sz[1] = _TEXT('\0');
    return SELF % sz;
}
int STRING::toInt() {
    int i;
    if (!m_szString) return 0;
    if (_stscanf(m_szString,_TEXT("%i"),&i) == 1) {
        return i;
    }
    return 0;
}

double  STRING::toDouble() {
    double i;
    if (!m_szString) return 0;
    if (_stscanf(m_szString,_TEXT("%lG"),&i) == 1) {
        return i;
    }
    return 0;
}

unsigned int    STRING::toUnsigned() {
    unsigned int i;
    if (!m_szString) return 0;
    if (_stscanf(m_szString,_TEXT("%u"),&i) == 1) {
        return i;
    }
    return 0;    
}
unsigned int    STRING::toHex() {
    unsigned int i;
    if (!m_szString) return 0;
    if (_stscanf(m_szString,_TEXT("%x"),&i) == 1) {
        return i;
    }
    return 0;    
}
__int64         STRING::toInt64() {
    __int64 i;
    if (!m_szString) return (__int64)0;
    if (_stscanf(m_szString,_TEXT("%I64i"),&i) == 1) {
        return i;
    }
    return (__int64)0;
}
unsigned __int64         STRING::toUnsignedInt64() {
    unsigned __int64 i;
    if (!m_szString) return (unsigned __int64)0;
    if (_stscanf(m_szString,_TEXT("%I64u"),&i) == 1) {
        return i;
    }
    return (unsigned __int64)0;
}
BOOL            STRING::EnlargeBuffer(int n) {
    STRPTR sz;
    if (!m_szString) {
        if (n >= 0) {
            m_szString = new STR[n+1];
            if (m_szString) { 
                m_nPos = -1;
                m_szString[0] = _TEXT('\0');
                SetError(STROBJ_ERROR_OK);
                return TRUE;
            }
            return FALSE;
        }
        return FALSE;
    } else {
        if (n > 0) {
            sz = new STR[Length() + n + 1];
            if (sz) {
                lstrcpy(sz,m_szString);
                delete m_szString;
                m_szString = sz;
                m_nPos = -1;
                SetError(STROBJ_ERROR_OK);
                return TRUE;
            } else {
                return FALSE;
            }
        } else {
            if ((-n) > Length() + 1) {
                sz = new STR[1];
                if (sz) {
                    sz[0] = _TEXT('\0');
                    delete m_szString;
                    m_nPos = -1;
                    m_szString = sz;
                    return TRUE;
                }
                return FALSE;
            }
            if ((-n) <= Length()) {
                sz = new STR[Length() + 1 - n];
                if (sz) {
                    lstrcpyn(sz,m_szString,Length() + 1 - n);
                    delete m_szString;
                    m_szString = sz;
                    m_nPos = -1;
                    SetError(STROBJ_ERROR_OK);
                    return TRUE;
                } else {
                    return FALSE;
                }
            } else {
                sz = new STR[1];
                if (sz) {
                    sz[0] = _TEXT('\0');
                    delete m_szString;
                    m_nPos = -1;
                    m_szString = sz;
                    return TRUE;
                }
                return FALSE;
            }
        }
    }
}
STRING&	  STRING::operator += (STRPTR sz) {
    SELF = (STRPTR)(SELF + sz);
    return SELF;
}
STRING&   STRING::operator += (STR ch) {
    if (EnlargeBuffer(1)) {
        int l = Length();
        m_szString[l] = ch;
        m_szString[l + 1] = _TEXT('\0');
    }
    return SELF;
}
STRING&   STRING::operator += (int n) {
    STR sz[64];
    _stprintf(sz,_TEXT("%d"),n);
    if (EnlargeBuffer(lstrlen(sz))) {
        lstrcat(m_szString,sz);
    }
    return SELF;
}
STRING&   STRING::operator += (__int64 nn) {
    STR sz[64];
    _stprintf(sz,_TEXT("%I64d"),nn);
    if (EnlargeBuffer(lstrlen(sz))) {
        lstrcat(m_szString,sz);
    }
    return SELF;
}
STRING&   STRING::operator += (unsigned int u) {
    STR sz[64];
    _stprintf(sz,_TEXT("%u"),u);
    if (EnlargeBuffer(lstrlen(sz))) {
        lstrcat(m_szString,sz);
    }
    return SELF;
}
STRING&   STRING::operator += (double v) {
    STR sz[64];
    _stprintf(sz,_TEXT("%lG"),v);
    if (EnlargeBuffer(lstrlen(sz))) {
        lstrcat(m_szString,sz);
    }
    return SELF;
}
STRING   STRING::operator + (STR ch) {
    STRING  str(SELF);
    return str += ch;
}
STRING   STRING::operator + (int n) {
    STRING  str(SELF);
    return str += n;
}
STRING   STRING::operator + (__int64 nn) {
    STRING  str(SELF);
    return str += nn;
}
STRING   STRING::operator + (unsigned int u) {
    STRING  str(SELF);
    return str += u;
}
STRING   STRING::operator + (double v) {
    STRING  str(SELF);
    return str += v;
}
// friend 
STRING   operator + (STR ch,STRING str) {
    STRING s;
    s += ch;
    return s + str;
}
// friend 
STRING   operator + (int n,STRING str) {
    STRING s;
    s += n;
    return s + str;
}
// friend 
STRING   operator + (__int64 nn,STRING str) {
    STRING s;
    s += nn;
    return s + str;
}
// friend 
STRING   operator + (unsigned int u,STRING str) {
    STRING s;
    s += u;
    return s + str;
}
// friend 
STRING   operator + (double v,STRING str) {
    STRING s;
    s += v;
    return s + str;
}
STRING&   STRING::operator = (STR ch) {
    ResetContents();
    return SELF += ch;
}
STRING&   STRING::operator = (int n) {
    ResetContents();
    return SELF += n;
}
STRING&   STRING::operator = (__int64 nn) {
    ResetContents();
    return SELF += nn;
}
STRING&   STRING::operator = (unsigned int u) {
    ResetContents();
    return SELF += u;
}
STRING&   STRING::operator = (double v) {
    ResetContents();
    return SELF += v;
}

#ifndef COMMON_EXCLUDE_SOMEOLEFEATURES                

BSTR            STRING::toBSTR(UINT uCP) {
    LPWSTR      lpwsz = toUnicode(uCP);
    if (lpwsz) {
        BSTR bstr = ::SysAllocString(lpwsz);
        delete lpwsz;
        return bstr;
    }
    return NULL;
}
#endif //COMMON_EXCLUDE_SOMEOLEFEATURES                

void STRING::Format(STRPTR Fmt, ...)
{
	int l, bufSize = Length();
	if(bufSize == 0) bufSize = lstrlen(Fmt)+1;
	STRPTR _s = new STR[bufSize];
	va_list vars;

	va_start(vars, Fmt);
	while((l = _vsntprintf(_s, bufSize-1, Fmt, vars)) < 0)
	{
		bufSize *= 2;
        delete _s;
		_s = new STR[bufSize];
		if(!_s) return;
		ZeroMemory(_s,bufSize*sizeof(STR));
	}
	va_end(vars);

	if(m_szString) delete m_szString;
	m_szString = new STR[(l+1)];
	if(!m_szString) return;
	lstrcpy(m_szString, _s);
	delete _s;
}


// STRINGMANAGER
///////////////////////

STRINGMANAGER::STRINGMANAGER() {
	m_pstr = NULL;
	m_dwFlags = 0;
}
STRINGMANAGER::STRINGMANAGER(STRING& so) {
	m_pstr = so.CopySelf();
    m_pstr->SetPos(0);
	m_dwFlags = 0;
}
STRINGMANAGER::~STRINGMANAGER() {
	if (m_pstr && !Is(STRMAN_F_USESOURCE)) m_pstr->Delete();
}

STRINGMANAGER&			STRINGMANAGER::Set(STRPTR sz) { 
	return SELF; 
}
STRINGMANAGER&			STRINGMANAGER::Set(STR ch) {
	return SELF; 
}
STRINGMANAGER&			STRINGMANAGER::SetPos(int n) {
	if (m_pstr) m_pstr->SetPos(n); 
	return SELF;
}
STRINGMANAGER&			STRINGMANAGER::Reset() {
	if (m_pstr) m_pstr->SetPos(0); 
	return SELF;
}
int					STRINGMANAGER::GetPos() {
	if (m_pstr) return m_pstr->GetPos();
	return -1;
}
STRING		STRINGMANAGER::Get() {
	if (m_pstr) return *m_pstr;
    STRING  str;
    str.SetError();
	return str;
}

STRINGMANAGER&			STRINGMANAGER::AttachTo(STRING& so) {
	if (m_pstr && !Is(STRMAN_F_USESOURCE)) m_pstr->Delete();
	m_pstr = &so;
	SetFlags(STRMAN_F_USESOURCE);
	return SELF;
}
STRINGMANAGER&			STRINGMANAGER::UseCopyOf(STRING& so) {
	if (m_pstr && !Is(STRMAN_F_USESOURCE)) m_pstr->Delete();
	m_dwFlags = 0;
	m_pstr = so.CopySelf();
	return SELF;
}

BOOL				STRINGMANAGER::Success() {
	if (!m_pstr) return FALSE;
	return TRUE;
}
STRING		STRINGMANAGER::Next() {
	return Get(); 
}
STRING		STRINGMANAGER::Prev() {
	return Get(); 
}
STRING		STRINGMANAGER::operator [] (int n) {
	return Get(); 
}
STRING		STRINGMANAGER::operator [] (STRPTR sz) {
	return Get(); 
}
					STRINGMANAGER::operator STRPTR () {
						if (Success()) {
							return &((m_pstr->GetStrPtr())[m_pstr->GetNormalizedPos()]); 
						} else return NULL;
					}

void				STRINGMANAGER::Delete() {
	delete this; 
}


// UTF-8 functions
LPSTR			ConvertWStrToUTF8(LPCWSTR wsz) {
	if (!wsz) return NULL;
	int l = osStrByteLenW((LPWSTR)wsz) / 2;
	int buffLen = l * 3 + 2;
	LPBYTE	lpsz = new BYTE[buffLen];
	if (!lpsz) return NULL;

	int j = 0,i = 0;

	for (i = 0; i < l && j < (buffLen-1); i++) {
		if (wsz[i] <= 0x7F) {
			lpsz[j] = (BYTE)wsz[i];
			j++;
		} else if (wsz[i] <= 0x7FF) {
			lpsz[j] = (BYTE)(0xC0 | (wsz[i] >> 6));
			j++;
			lpsz[j] = (BYTE)(0x80 | (wsz[i] & 0x3F));
			j++;
		} else {
		  // 3 bytes
		  lpsz[j] = (BYTE)(0xE0 | (wsz[i] >> 12));
		  j++;
		  lpsz[j] = (BYTE)(0x80 | ((wsz[i] >> 6) & 0x3F));
		  j++;
		  lpsz[j] = (BYTE)(0x80 | (wsz[i] & 0x3F));
		  j++;
		}
	}
	lpsz[j] = '\0';
	return (LPSTR)lpsz;
}

int				GetNumBytesUTF8(BYTE b) {
	if ((b & 0x80) == 0) return 0;

	BYTE cb = 0x80;
	int i = 1;
	do {
		cb = cb >> 1;
		if (cb & b) i++;
	} while (cb & b);
	return i;
}
BYTE			GetMeaningfulMaskUTF8(int n) {
	int i;
	BYTE b = 0;
	for (i = 0; i < n; i++) {
		b = b << 1;
		b = b | 0x01;
	}
	return b;
}

LPWSTR			ConvertUTF8ToWStr(LPCSTR sz,BOOL* pbErr) {
	if (pbErr) *pbErr = TRUE;
	if (!sz) return NULL;
	int l = osStrByteLen((LPSTR)sz);
	int buffSize = l + 1;
	LPWSTR	wsz = new WCHAR[buffSize];
	if (!wsz) return NULL;
	if (pbErr) *pbErr = FALSE;

	int i, stage, numChars;
	int j = 0;
	DWORD dw;

	stage = 0;
	for (i = 0; i < l; i++) {
		if (stage == 0) {
			// Determine how many bytes we have for the character
			numChars = GetNumBytesUTF8(sz[i]);
			dw = 0;
			if (numChars == 0) {
				wsz[j] = (WCHAR)(BYTE)sz[i];
				j++;
				continue;
			}
			if (numChars == 1) {
				// This is clearly an error
				if (pbErr) *pbErr = TRUE; // Indicate this and try to resume
				wsz[j] = L'?';
				j++;
				// stage = 0;
				continue;
			}
			// transfer the meaningful bits
			dw = dw | ((BYTE)sz[i] & GetMeaningfulMaskUTF8(8 - numChars - 1));
			stage = 1;
		} else {
			if ( ((BYTE)sz[i] & 0xC0) != 0x80 ) {
				// Not an UTF8 set may be
				if (pbErr) *pbErr = TRUE; // Indicate this and try to resume
				wsz[j] = L'?';
				j++;
				stage = 0;
			} else {
				dw = dw << 6;
				stage ++;
				// Put the 6 bits from this byte
				dw = dw | ((BYTE)sz[i] & 0x3F);

				if (stage >= numChars) {
					// Commit character
					if (dw >= 0x10000) {
						// error not supported
						wsz[j] = L'?';
					} else {
						wsz[j] = (WCHAR)dw;
					}
					j++;
					stage = 0; // search new character
				}
			}
		}
	}
	if (stage > 0) {
		// Uncommited character
		wsz[j] = L'?';
		j++;
	}
	wsz[j] = L'\0';
	return wsz;
}

LPSTR			URLEncodeString(LPSTR sz,int nType) {
	if (!sz) return NULL;
	int l = osStrByteLen(sz);
	// Reserve buffer
	LPSTR	lpsz = new CHAR[l * 3 + 3];
	if (!lpsz) return NULL;
	int nPrintPos = 0;
	int i;
	BYTE b;

	for (i = 0; i < l; i++) {
		if (	(sz[i] >= 0x41 && sz[i] <= 0x5A) ||
				(sz[i] >= 0x61 && sz[i] <= 0x7A) ||
				(sz[i] >= 0x30 && sz[i] <= 0x39) ||
				sz[i] == '$' ||
				sz[i] == '-' ||
				sz[i] == '_' ||
				sz[i] == '.' ||
				sz[i] == '~' ||
				sz[i] == '*' ||
				sz[i] == '!' ||
				sz[i] == '\\' ||
				sz[i] == '(' ||
				sz[i] == ')' ||
				sz[i] == ','
				) {
			lpsz[nPrintPos] = sz[i];
			nPrintPos ++;
		} else if (sz[i] == ' ') {
			if (nType == STRINGURLENC_SPACES || nType == 0 || nType == STRINGURLENC_PERCENTANDSPACES) {
				lpsz[nPrintPos] = '+';
				nPrintPos ++;
			}
		} else {
			if (nType == STRINGURLENC_PERCENT || nType == STRINGURLENC_PERCENTANDSPACES) {
				if (sz[i] == '%') {
					lpsz[nPrintPos] = '%';
					lpsz[nPrintPos + 1] = '2';
					lpsz[nPrintPos + 2] = '5';
					nPrintPos += 3;
				} else {
					lpsz[nPrintPos] = sz[i];
					nPrintPos ++;
				}
			} else if (nType == 0) {
				lpsz[nPrintPos] = '%';
				nPrintPos ++;
				b = ((BYTE)sz[i]) >> 4;
					// Hi part
					if ( b > 9 ) {
						lpsz[nPrintPos] = 'A' + (b - 0x0A);
					} else {
						lpsz[nPrintPos] = '0' + b;
					}
					nPrintPos++;
				b = ((BYTE)sz[i]) & 0x0F;
					// Hi part
					if ( b > 9 ) {
						lpsz[nPrintPos] = 'A' + (b - 0x0A);
					} else {
						lpsz[nPrintPos] = '0' + b;
					}
					nPrintPos++;
			} else {
				lpsz[nPrintPos] = sz[i];
				nPrintPos ++;
			}
		}
	}
	lpsz[nPrintPos] = '\0';
	return lpsz;
}

DWORD			ParseHex(LPSTR sz,int* pnCharRead,int nMaxDigits) {
	DWORD		dw = 0;
	if (!sz) {
		if (pnCharRead) *pnCharRead = 0;
		return 0;
	}
	int i;
	for (i = 0; i < nMaxDigits; i++) {
		if (sz[i] >= 0x30 && sz[i] <= 0x39) {
			dw = dw << 4;
			dw = dw | (sz[i] - 0x30);
		} else if (sz[i] >= 0x41 && sz[i] <= 0x46) {
			dw = dw << 4;
			dw = dw | (sz[i] - 0x41 + 0xA);
		} else if (sz[i] >= 0x61 && sz[i] <= 0x66) {
			dw = dw << 4;
			dw = dw | (sz[i] - 0x61 + 0xA);
		} else {
			break;
		}
	}
	if (pnCharRead) *pnCharRead = i;
	return dw;
}
LPSTR			URLDecodeString(LPSTR sz) {
	if (!sz) return NULL;
	int l = osStrByteLen(sz);
	int nRead; // Temporary variable for hex chars read reports.
	LPSTR	lpsz = new CHAR[l + 1];
	if (!lpsz) return NULL;
	int i, j = 0;
	BYTE	b;

	for (i = 0;i < l; i++) {
		if (sz[i] == '\0') {
			// End conversion - additional precaution
			break;
		} else if (sz[i] == '%') {
			i++;
			if (sz[i] == '%') {
				lpsz[j] = '%';
				j++;
			} else {
				b = (BYTE)ParseHex(&sz[i],&nRead,2);
				if (nRead == 0) {
					// Nothing read - skip for now
				} else {
					i += nRead - 1;
					lpsz[j] = (CHAR)b;
					j++;
				}
			}
		} else {
			if (sz[i] == '+') {
                lpsz[j] = ' ';
            } else {
			    lpsz[j] = sz[i];
            }
            j++;
		}
	}
	lpsz[j] = '\0';
	return lpsz;
}
