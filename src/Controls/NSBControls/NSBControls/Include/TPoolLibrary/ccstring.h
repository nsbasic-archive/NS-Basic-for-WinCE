// CCSTRING.H
//
// TPoolLibrary (14-Mar-2006)
// STRING OBJECTS
////////////////////////////////

#ifndef _CC_STRINGCLASS_H_
#define _CC_STRINGCLASS_H_

// Concepts
// ========
//
// Two types of classes are introduced here:
// STRINGOBJECT-s and STRINGMAN-s
// STRINGOBJECT encapsulates basic/traditional string functionality
// at the other hand STRINGMAN has its own operators that can be used to 
// realize different behaviour of strings or realize operations over them -
// and of course easy way to use it.
// 
// For example - tokenization of string must be realized as STRTOK class (for example)
// and its operators STRTOK[i] must return appropriate part of string
// This gives ability to change your string manipulation utilities without changing
// end code
//
// STRINGMAN defines set of operators and its view must not be changed in the subclasses
// but of course, you can define more operators.

#ifndef STROBJ_ERROR_OK
    // ERRORS
    #define STROBJ_ERROR_INVALID			0x0001              // invalid object
    #define STROBJ_ERROR_OPERATIONFAILED    0x0002              // invalid object
    #define STROBJ_ERROR_OK					0x0000              // Normal
#endif // STROBJ_ERROR_OK

// URLENCODE flags
#ifndef STRINGURLENC_ALL
    #define STRINGURLENC_ALL                0x0
    #define STRINGURLENC_SPACES             0x1
    #define STRINGURLENC_PERCENT            0x2
    #define STRINGURLENC_PERCENTANDSPACES   0x3
#define

#ifndef STRMAN_F_CASEINSENSETIVE
    // STRINGMAN FLAGS
    #define STRMAN_F_USESOURCE			0x0001				// Uses source object - must not delete it on deletion
    #define STRMAN_F_CASEINSENSETIVE	0x0002				// case insensetive operations
    // Flags masked as reserved use for your objects >= 0x0010
    #define STRMAN_F_SYSTEMRESERVED		0x000F
#endif // STRMAN_F_CASEINSENSETIVE

class ccString;
typedef ccString*           PccString;
typedef ccString*           LPccString;

class STRINGMANAGER;
typedef _PTR(STRINGMANAGER)      PSTRINGMANAGER;
typedef _LPTR(STRINGMANAGER)     LPSTRINGMANAGER;

class REGEXPBASE;
typedef _PTR(REGEXPBASE)      PREGEXPBASE;
typedef _LPTR(REGEXPBASE)     LPREGEXPBASE;


// Regular expression base class
// In the present moment this class is not entirely defined
class ccStrSearchBase {
public:
    virtual int     Find(ccString&,int*)=0;     // Finds match in the given string from
                                                // the current position returs -1 if not found
                                                // Sets found length in the int pointed by the second parameter
                                                // Length must be >= 0
    virtual void    Reset()=0;                  // Resets internal state (if applicable)
    virtual BOOL    SetMask(ccString&) = 0;     // Set string with rules - syntax depends on the RegExp object
                                                // returns TRUE if the syntax is correct and FALSE if not
};

// String manipulator class
// ========================
//
// For example tokenizator, regular expression etc.
// this class attaches to string or to copy of string and manipulates it
// manipulated string must not be manipulated with other manipulator - because of position settings
// but you can do this if you take care about position
//
// Base class was defined with stub members to avoid errors when using subclasses

class STRINGMANAGER{
protected:
	PSTRING	        m_pstr;
private:
	DWORD			m_dwFlags;
public:
	STRINGMANAGER();
	STRINGMANAGER(STRING&);									// passes parameters
	virtual ~STRINGMANAGER();

	// internal members
				BOOL				Is(DWORD dw)				// tests for flags
				{
					return (m_dwFlags & dw)?TRUE:FALSE;
				};
				DWORD				SetFlags(DWORD dw)			// sets some flags
				{
					SETBITS(m_dwFlags,dw);
					return m_dwFlags;
				};
				DWORD				ResetFlags(DWORD dw)		// resets some flags
				{
					RESETBITS(m_dwFlags,dw);
					return m_dwFlags;
				};

	// Setup members
	virtual		STRINGMANAGER&		Set(STRPTR);				// for example sets mask for match (or does nothing)
	virtual		STRINGMANAGER&		Set(STR);					// for example sets mask for match (or does nothing)
	virtual		STRINGMANAGER&		SetPos(int);				// for example sets position in string (or does nothing)
	virtual		STRINGMANAGER&		Reset();					// for example resets manipulator (or does nothing)
	virtual		int					GetPos();					// for example gets current position
	virtual		STRING		        Get();						// for example gets current part
    // Danger in some situations. Be careful for a lifetime colisions of the
    // attached string and the manager
	virtual		STRINGMANAGER&	 	AttachTo(STRING&);	        // must attach manipulator to string
	virtual		STRINGMANAGER&		UseCopyOf(STRING&);	        // must copy object and use copy ! copy must be deleted on deletion
                                    
	virtual		BOOL				Success();					// must return usability of the object (is object operational)
                                    
	// "navigation" members         
	virtual		STRING		        Next();						// goes to the next token/match etc.
	virtual		STRING		        Prev();						// goes to the prev token/match etc.

	virtual		STRING		        operator [] (int);			// cares for indexed operations
	virtual		STRING		        operator [] (STRPTR);		// cares about operations depending to one string parameter
	virtual							operator STRPTR ();			// must return pointer to position in string or NULL
			
	virtual		void				Delete();					// deletes object	
};

// String object
// =============
//
// Encapsulates basic string functionality
// Subclassing allowed but preffered way in most cases will be definition of own string manipulators
// Subclass STRINGOBJECT only in case you want to enhance basic string functionality




class ccString {
    LPTSTR      m_szString;
    BYTE        m_btError;                              // error - last operation
	LONG		m_nPos;									// used for some operations internaly
    LONG        m_nPosLen;                              // remembered length for operations
public:
	
		ccString();                                               // creates empty string
		ccString(LPTSTR szInit,BYTE btState = STROBJ_ERROR_OK);   // creates empty string
		ccString(ccString& str);                                  // creates and initializes with STRPTR
		ccString(BYTE);                                           // creates empty string with error set to param
		STRING(PccString);                                        // creates and initializes with STRPTR
		
        // This needs to be virtual in order to support some cross-DLL usages
	    virtual ~STRING();                                        // deletes string
	
    /*
    #ifdef COMMON_DEBUG_OBJECTS
    	static DWORD sdo_objectCount;
    	static void	 sdo_INC();
    	static void	 sdo_DEC();
    	static DWORD sdo_GET();
    #endif
    */
    
protected:
            BOOL            EnlargeBuffer(LONG);
public:
            void            ResetContents();

	        void		    SetError(BYTE btErr = STROBJ_ERROR_INVALID);	// sets error status

		    BOOL            Create(LPTSTR);                                 // internal initializator                
		    LPTSTR          CopyTo(LPTSTR,int cChars=0);// returns pointer to string
#ifndef UNICODE
    			LPWSTR          CopyToW(LPWSTR,int cChars);// returns pointer to string
#endif
                STRPTR          Allocate(int);
				BOOL            Success() const;                  // validates operating status            
				int             Length();                   // returns length of string              
			    int				FindChar(STR ch,int nPos = 0);		// returns index of a first character occurence
                int             FindLastChar(STR,int nPos = 0);     // returns index of a last character occurence
				int				FindChar(STRPTR,int nPos = 0);  			// returns index of a first character occurence
                int             FindLastChar(STRPTR,int nPos = 0);       // returns index of a last character occurence
			    int				FindSubString(const STRPTR,int pos=0);		
														// finds first occurence of string from pos
                int				FindSubStringCaseInsensetive(STRPTR,int pos=0);		
														// finds first occurence of string from pos														
			    STRPTR			GetStrPtr() const;				// returns pointer to the internal string
		#ifdef UNICODE
			    STRING&	        Set(const STRPTR,UINT uCP = CP_ACP);				// Sets string
		#else
				STRING&	        Set(const STRPTR);				// Sets string
		#endif // UNICODE
   			    STRING&	        Set(const STRPTR,int);			// Sets string from non-zero terminated string
                STRING&         LoadString(UINT,HINSTANCE hModule = NULL);               // Loads resource string
        #ifndef COMMON_EXCLUDE_SOMEOLEFEATURES                			
            #ifndef UNICODE
                STRING&	Set(LPCOLESTR,UINT uCP = CP_ACP);			    // Sets string from BSTR source
            #endif // UNICODE
        #endif            
        
                STRING&         SetFromBuff(LPSTR sz, int nChars = -1, UINT uCP = CP_ACP);
                STRING&         SetFromBuff(LPWSTR wsz, int nChars = -1, UINT uCP = CP_ACP);
        
static          LPWSTR          AnsiToUnicode(UINT,LPCSTR,int convLen = -1); // Emits new string of the type
static          LPSTR           UnicodeToAnsi(UINT,LPCWSTR,int convLen = -1);
			    STRING&	        AttachTo(STRPTR);			// Attaches to given STRPTR - STRPTR must not be used after !
            
            // Operations
                STRING          Left(int nChars = -1);					// returns left n symbols
			    STRING      	Right(int nChars = -1);				
			    STRING          Mid(int,int);				// (n,m) returns m symbols from n-th position
			    STRING          Mid(STRPTR,int);			// (address,m) returns m symbols from position specified by the address
			    STR&			Char(int);					// gets n-th character
			    STRING	        Concat(STRPTR);				// Concatenates strings returns self
			    STRING          SafeConcat(STR,STRPTR);     // checks that string ends with char and adds char if not found
			                                            // before concatenation
			    STRING	        Insert(STRPTR,int);			// inserts substring at the position
			    STRING	        Replace(STRPTR,int,int);	// replace at the pos n characters
			    STRING	        Remove(int,int);			// removes at position n characters
            // Specific utilities
                STRING	        ReplaceTrailing(STRPTR,STRPTR szWith);	// Replaces last characters existing in the given charset
                STRING	        ReplaceStarting(STRPTR,STRPTR szWith);	// Replaces first characters existing in the given charset
                STRING	        ReplaceCharacters(STRPTR szChars,STRPTR szWith);	// Replaces characters existing in the given charset with the corresponding in the 2-nd parameter
                STRING	        RemoveCharacters(STRPTR szChars);	// Replaces characters existing in the given charset with the corresponding in the 2-nd parameter
                STRING          Trim(STRPTR sz = NULL);
				STRING          dbEscape(); // Escapes string for DB usage
                STRING	        URLEncode(int nType = 0, UINT uCP = CP_ACP);
				STRING	        URLEncodeUTF8(int nType = 0, UINT uCP = CP_ACP);
                STRING			URLDecode(UINT uCP = CP_ACP);
				STRING			URLDecodeUTF8(UINT uCP = CP_ACP,BOOL* pbErr = NULL);
                STRING          HTMLEncode();
                STRING          DirPathName(int nMaxSize = MAX_PATH);
                STRING          ExtractFileName(int nMaxSize = MAX_PATH);
				STRING          ExtractFileNameOnly(int nMaxSize = MAX_PATH);
                STRING          FullPathName(int nMaxSize = MAX_PATH);
                STRING          ExtractExtension(int nMaxSize = MAX_PATH);

			// helpers
			    void			SetPos(int);
			    int				GetPos();
			    int				GetNormalizedPos();			// returns dedicated position (not out of string)

			// operations
			    BOOL			IsEmpty()					// checks is string empty or not usable
			    { return ((m_szString == NULL) || !Success() || (Length() == 0))?TRUE:FALSE; };
			    BOOL			IsNull()					// checks is string empty and not usable
			    { return ((m_szString == NULL) || !Success())?TRUE:FALSE; };
			    BOOL			IsEqual(STRPTR,BOOL bCase = FALSE);		// TRUE = Case sens/ FALSE = insens comparation
                int             Lookup(STRPTR sz,BOOL bCase = FALSE,int nLimit = -1);
                                // Looks for occurence of the STRING in the given buffer.
                                // The buffer can be non-zero terminated - non-negative nLimit.
                BOOL            Beginning(STRPTR sz,BOOL bCase = FALSE,int nLimit = -1);
                int             LookupFirstChar(STRPTR sz,BOOL bCase = FALSE,int nLimit = -1);

			// OPERATORS returning NEW strings
			// -------------------------------
                //
                STRING	        operator*(int n);
                friend  STRING	operator*(int n,STRING str);

			    STRING	        operator+(STRPTR sz);
				// concatenates two strings and returns new one
                friend STRING	operator+(STRPTR,STRING);
				// concatenates two strings and returns new one
                STRING	        operator+(STRING);
				// concatenates two strings and returns new one
                STRING	        operator-(STRING);
                STRING          operator-(STRPTR);
                friend STRING   operator-(STRPTR,STRING);
                // returns the non-matching resting part of the string
                // The right string must exactly mathch teh beginning of the 
                // first
			    STRING	        operator/(STRING so);
				// returns left part of string up to so (or empty if not found)
			    STRING	        operator%(STRING so);
				// returns right part of string after so (or empty if not found)
			    STRING	        operator/(STRPTR);
				// returns left part of string up to so (or empty if not found)
			    STRING	        operator%(STRPTR);
				// returns right part of string after so (or empty if not found)
                STRING	        operator/(STR);
				// returns left part of string up to so (or empty if not found)
			    STRING	        operator%(STR);
				// returns right part of string after so (or empty if not found)
				STRING			operator/(int);
				STRING			operator%(int);

                friend STRING   operator/(STRPTR sz,STRING s) {
                    STRING str = sz;
                    return (str / s);
                }
                friend STRING   operator%(STRPTR sz,STRING s) {
                    STRING str = sz;
                    return (str % s);
                }

			// Operators returning SELF or BASIC TYPE VALUEs
			// ---------------------------------------------
			    STRING&	        operator=(const STRING& so);
				// Sets string to givven and return self
			    STRING&	        operator=(const STRPTR sz) {return Set(sz); }
				// Sets string to givven and return self
            #ifndef COMMON_EXCLUDE_SOMEOLEFEATURES                				
            #ifndef UNICODE
                STRING&         operator=(LPCOLESTR bstr) { return Set(bstr); }
                // gets string from BSTR
            #endif
            #endif
			    BOOL			operator==(STRPTR sz) {return ((sz == GetStrPtr()) || (lstrcmp(sz,GetStrPtr()) == 0))?TRUE:FALSE; };
				// returns TRUE if strings are equal
                BOOL			operator!=(STRPTR sz) {return !(SELF == sz);};
				// returns TRUE if strings are equal
            // CONVERSIONS ********************************************************
            // ********************************************************************
    						operator STRPTR () const { return GetStrPtr(); }
			    // returns pointer to string
                int			    toInt();
			    // returns converted to integer (defaults to 0 if impossible)
                double          toDouble();
			    // returns converted to double (defaults to 0 if impossible)			    
                float           toFloat() { return (float)toDouble(); }
                __int64         toInt64();
                unsigned __int64 toUnsignedInt64();
                unsigned int    toUnsigned();
				unsigned int    toHex();
			    // returns converted to unsigned integer (defaults to 0 if impossible)
                LPWSTR          toUnicode(UINT uCodePage = CP_ACP); 
                // Emits new UNICODE string 
                LPSTR           toAnsi(UINT uCodePage = CP_ACP);
                // Emits new ANSI string
                STRING          toUpper();
                STRING          toLower();
                STRING          toCapitalized();
            #ifndef COMMON_EXCLUDE_SOMEOLEFEATURES                
                BSTR            toBSTR(UINT uCP = CP_ACP);
            #endif
                STR&    		operator [] (int n) { return Char(n); }
				// returns n-th char
                void            ResetPos() {
                    m_nPos = -1;
                    m_nPosLen = 0;
                }
			    STRING	        operator () (int n) { 
                    STRING  str(SELF);
                    str.SetPos(n); 
                    str.m_nPosLen = 0;
                    return str; 
                }
				// Set current pos to n
			    STRING	        operator () (STRPTR sz) { 
                    STRING  str(SELF);
                    str.SetPos(FindSubString(sz,GetPos())); 
                    if (sz) str.m_nPosLen = lstrlen(sz);
                    else str.m_nPosLen = 0;
                    return str; 
                };
				// Sets current pos to pos of first occurence of STRPTR	 str("efg") <<= "123"
                STRING	        operator () (STRING str) { 
                    STRING  s(SELF);
                    s.SetPos(FindSubString(str,GetPos())); 
                    s.m_nPosLen = str.Length();
                    return s; 
                };
				// Sets current pos to pos of first occurence of STRPTR	 str("efg") <<= "123"
                STRING	        operator [] (STRPTR sz) { 
                    STRING  str(SELF);
                    str.SetPos(FindSubString(sz,GetPos())); 
                    if (str.GetPos() < 0) return str;
                    int l = (sz)?lstrlen(sz):0;
                    str.m_nPosLen = -l;
                    str.SetPos(str.GetPos() + l);
                    return str; 
                };
                STRING	        operator [] (STRING str) { 
                    STRING  s(SELF);
                    s.SetPos(FindSubString(str,GetPos())); 
                    if (s.GetPos() < 0) return s;
                    int l = str.Length();
                    s.m_nPosLen = -l;
                    s.SetPos(s.GetPos() + l);
                    return s; 
                };
                STRING	        operator () (REGEXPBASE& re) { 
                    STRING  s(SELF);
                    s.SetPos(re.Find(SELF,&s.m_nPosLen)); 
                    return s; 
                };
				// Sets current pos to pos of first occurence of STRPTR	 str("efg") <<= "123"
                STRING	        operator [] (REGEXPBASE& re) { 
                    STRING  str(SELF);
                    int l;
                    str.SetPos(re.Find(SELF,&l)); 
                    if (str.GetPos() < 0) return str;
                    str.m_nPosLen = -l;
                    str.SetPos(str.GetPos() + l);
                    return str; 
                };
                STRING          operator()() {
                    if (m_nPos >= 0) return Mid(GetNormalizedPos(),m_nPosLen);
                    STRING str;
                    return str;
                }

                // returns allocated BSTR
			    STRING	        operator << (STRPTR);		        // Inserts string in the current position and retutns result
                STRING	        operator << (STRING);		        // Inserts string in the current position and retutns result
			    STRING	        operator >> (STRING);		        // Inserts string in the current position of the right string and retutns result
                STRING	        operator >> (STRPTR);		        // Concatenates to right string and returns result
                friend  STRING	operator >> (STRPTR,STRING);		// Inserts string in the current position and returns result

                STRING	        operator <  (STRPTR);		        // Replace string in the current position and retutn result
                STRING	        operator <  (STRING);		        // Replace string in the current position and retutn result
			    STRING	        operator >  (STRING);		        // Replace string in the current position and retutn result
                friend  STRING	operator >  (STRPTR,STRING);		// Replace string in the current position and retutn result
            
			    STRING&	        operator <<=(STRPTR);		        // inserts string in the current position (SetPos)
                STRING&	        operator <<=(STRING);		        // inserts string in the current position (SetPos)
                STRING&	        operator <= (STRPTR);		        // Replaces with given string previously found substring
                STRING&	        operator <= (STRING);		        // Replaces with given string previously found substring

			    // Other
			    void			Delete() { delete this; }
				// forcibly deletes this object
			    PSTRING	        CopySelf();					// copies self with current position

			    STRING&	  operator += (STRPTR sz);
                STRING&   operator += (STR ch);
                STRING&   operator += (int n);
                STRING&   operator += (__int64 nn);
                STRING&   operator += (unsigned int u);
                STRING&   operator += (double v);

                STRING&   operator = (STR ch);
                STRING&   operator = (int n);
                STRING&   operator = (__int64 nn);
                STRING&   operator = (unsigned int u);
                STRING&   operator = (double v);

                STRING   operator + (STR ch);
                STRING   operator + (int n);
                STRING   operator + (__int64 nn);
                STRING   operator + (unsigned int u);
                STRING   operator + (double v);

                friend STRING   operator + (STR ch,STRING str);
                friend STRING   operator + (int n,STRING str);
                friend STRING   operator + (__int64 nn,STRING str);
                friend STRING   operator + (unsigned int u,STRING str);
                friend STRING   operator + (double v,STRING str);
				// concates the current string and returns SELF
                // *** AVOID USING THIS MEMBER ***
			    void			Format(STRPTR, ...);		// like sprintf over the current string
};

LPSTR			ConvertWStrToUTF8(LPCWSTR wsz); // Converts WStr to UTF8 MB string. Returns NULL on error or allocated buff that must be deleted on success.
LPWSTR			ConvertUTF8ToWStr(LPCSTR sz,BOOL* pbErr = NULL); // Converts MB UTF8 str to WStr. Returns NULL on error or allocated buff that must be deleted on success.

DWORD			ParseHex(LPSTR sz,int* pnCharRead = NULL,int nMaxDigits = 8); // Parses hex number from string, pnCharRead receives the chars read if present.

LPSTR			URLEncodeString(LPSTR sz,int nType = 0); // URL Encodes a MB string (which can be UTF-8 of course).
LPSTR			URLDecodeString(LPSTR sz);


/*
class ASTRING {
public:
};
class USTRING {
	WCHAR	m_wszString;
	int		m_nSize;

	STRINGENC();
	STRINGENC(STRINGENC& us);

	USTRING&	Set(CHAR sz, UINT uCP = CP_ACP);
	USTRING&	Set(WHAR sz);

	CHAR*		URL

	
	
};
*/

#endif // _STRINGCLASS_H_