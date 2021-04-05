// CCOSPECIFIC.H
//
// TPoolLibrary (14-Mar-2006)
// HELPER ROUTINES FOR PORTABILITY
//
// Note that this is a stand-alone subset of the osspecific routines from the Jacked-Objects library
// This file will extend in future to cover some new areas as required by the rest of the stand alone
// TPollLibrary
//
// If used with Jacked-Objects you can define CC_BYTEORDER_NOSTDPROCNAMES for quick testing
// However note that this library duplicates the Jacked-Objects functionality
// and should be excluded in such case
///////////////////////////////////

/*
    Note that currently only Windows OS variants are supported
 */



#ifndef _CC_OSSPECIFIC_H_
#define _CC_OSSPECIFIC_H_

#pragma message("Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp")

#define _RESETBITS(x,y)			((y) ^ ((x) | (y)))
#define _SETBITS(x,y)		    ((x) | (y))

// Byte order
// Platform safe compiler independent functions
// Support only 1,2,4,8 byte size

// Little endian to big endian
BOOL    cc_osReadBigEndian(LPVOID pTo,LPVOID pFrom,int nSize);
// Big endian to little endian
BOOL    cc_osReadLittleEndian(LPVOID pTo,LPVOID pFrom,int nSize);

// With these falgs one can invoke the more universal routines to convert correctly
#ifndef BOCF_FROM_LITTLEENDIAN
    // Byte order converter routine
    // Flags:
    // Source (media)
    #define BOCF_FROM_LITTLEENDIAN          0x00000000
    #define BOCF_FROM_BIGENDIAN             0x00000001
    // Machine
    #define BOCF_TO_LITTLEENDIAN            0x00000000
    #define BOCF_TO_BIGENDIAN               0x00000002
    #define BOCF_TRIVIAL                    0x00000004

    #define BOCF_INVERTSLOTS(x)         ( ((~x) & 0x00000003) | ((x) & 0xFFFFFFFC) )
#endif

// Assume little endian if nothing else is said
#ifndef COMMON_SYSTEM_BYTEORDER
     #pragma message("Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)")
     #define COMMON_SYSTEM_BYTEORDER					0x00000000
     #define COMMON_SYSTEM_BYTEORDER_UNICODE			0x00000000
#endif

LPVOID  cc_osByteOrderConvert(LPVOID pTo, LPVOID pFrom, DWORD dwFlags, UINT nSize, UINT nCount);


// Length without the 0=terminator
DWORD   cc_osStrByteLen(LPSTR);
DWORD   cc_osStrByteLenW(LPWSTR);
DWORD   cc_osStrByteLenT(LPTSTR);

// A template function to invet the byte order of basic types
template <class T>
T   cc_osInvertByteOrder(T v, BOOL bConvert) {
    if (bConvert) {
        T  result;
        cc_osByteOrderConvert(&result,&v, (DWORD)0x01, (UINT)sizeof(T), 1);
        return result;
    } else {
        return v;
    }
}
// A template function to invet the byte order of basic types depending on the flags supplied
// Requires the 
// #define COMMON_SYSTEM_BYTEORDER					0x00000000
template <class T>
T   cc_osInvertByteOrderF(T v, BYTE btSrc) {
    if (bConvert) {
        T  result;
        cc_osByteOrderConvert(&result,&v, (DWORD)(btSrc | COMMON_SYSTEM_BYTEORDER), (UINT)sizeof(T), 1);
        return result;
    } else {
        return v;
    }
}

// For compatibility with Jacked-Objects these can be turned off
#ifndef CC_BYTEORDER_NOSTDPROCNAMES
    #pragma message("Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)")
    #define osReadBigEndian cc_osReadBigEndian
    #define osReadLittleEndian cc_osReadLittleEndian
    #define osByteOrderConvert cc_osByteOrderConvert
    #define osInvertByteOrder cc_osInvertByteOrder
    #define osInvertByteOrderF cc_osInvertByteOrderF
#endif

// Inline string conversion utilities - very similar to those supplied by ATL
// but a bit more flexible
/*
    Usage:
    Routine(...) {
        _STRCONV_INIT;
        ......
        String_Type var = _STRCONV_XXX(source[,cp]);
        ......

    Note: The application can check if var is null if it wants to insure against out of memory situations

 */
#ifndef COMMON_STRCONV_INLINE_UTILS
#define COMMON_STRCONV_INLINE_UTILS

    #pragma message("Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)")

    #define _STRCONV_INIT   int _sc_length; _sc_length; LPWSTR _sc_wstr; _sc_wstr; LPSTR _sc_astr; _sc_astr

    #define _STRCONV_A_W(_a,_cp) (\
        (_a == NULL)?NULL:(_sc_length = strlen((LPSTR)_a),\
            _sc_wstr = (LPWSTR)_alloca((_sc_length + 1)*sizeof(WCHAR)),\
            ::MultiByteToWideChar(_cp,0,(LPSTR)_a,-1,_sc_wstr,_sc_length+1),\
            _sc_wstr))

    #define _STRCONV_W_A(_w,_cp) (\
        (_w == NULL)?NULL:(_sc_length = ::WideCharToMultiByte(_cp,0,(LPWSTR)_w,-1,NULL,0,NULL,NULL),\
            _sc_astr = (LPSTR)_alloca((_sc_length + 1)*2),\
            ::WideCharToMultiByte(_cp,0,(LPWSTR)_w,-1,_sc_astr,_sc_length+1,NULL,NULL),\
            _sc_astr))

    #ifdef UNICODE
        #define _STRCONV_A_T _STRCONV_A_W
        #define _STRCONV_T_A _STRCONV_W_A
        #define _STRCONV_W_T(_a,_cp) ((LPTSTR)_a)
        #define _STRCONV_T_W(_a,_cp) ((LPTSTR)_a)
    #else
        #define _STRCONV_A_T(_a,_cp) ((LPTSTR)_a)
        #define _STRCONV_T_A(_a,_cp) ((LPTSTR)_a)
        #define _STRCONV_W_T _STRCONV_W_A
        #define _STRCONV_T_W _STRCONV_A_W
    #endif

    #define _STRCONV_A2W(_t) _STRCONV_A_W(_t,CP_ACP)
    #define _STRCONV_W2A(_t) _STRCONV_W_A(_t,CP_ACP)
    #define _STRCONV_A2T(_t) _STRCONV_A_T(_t,CP_ACP)
    #define _STRCONV_T2A(_t) _STRCONV_T_A(_t,CP_ACP)
    #define _STRCONV_W2T(_t) _STRCONV_W_T(_t,CP_ACP)
    #define _STRCONV_T2W(_t) _STRCONV_T_W(_t,CP_ACP)

    #define _STRCONV_T_B(_t,_cp) ::SysAllocString((LPOLESTR)_STRCONV_T_W(_t,_cp))
    #define _STRCONV_A_B(_t,_cp) ::SysAllocString((LPOLESTR)_STRCONV_A_W(_t,_cp))
    #define _STRCONV_W_B(_t,_cp) ::SysAllocString((LPOLESTR)_t)

    #define _STRCONV_T2B(_t) _STRCONV_T_B(_t,CP_ACP)
    #define _STRCONV_A2B(_t) _STRCONV_A_B(_t,CP_ACP)
    #define _STRCONV_W2B(_t) _STRCONV_W_B(_t,CP_ACP)


    inline HRESULT _WCompareStr(LPCWSTR wsz1,LPCWSTR wsz2,BOOL bCase = FALSE,LCID lcid = LOCALE_USER_DEFAULT) {
        // To avoid problems on some systems we must convert to ANSI
        _STRCONV_INIT;
        LPTSTR  sz1 = NULL;
        LPTSTR  sz2 = NULL;
        sz1 = _STRCONV_W2T(wsz1);
        sz2 = _STRCONV_W2T(wsz2);
        int r = ::CompareString(lcid,((bCase)?0:NORM_IGNORECASE),sz1,-1,sz2,-1);
        if (r == CSTR_EQUAL) return S_OK;
        else return S_FALSE;
    }
#endif // COMMON_STRCONV_INLINE_UTILS

#ifdef _WIN32_WCE
	#if _WIN32_WCE <= 211
		#define	STATUS_INVALID_HANDLE	((DWORD)-1)
		#include <ctype.h>
		#define ZeroMemory(Destination,Length) memset((Destination),0,(Length))
		#define CopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
	#endif
#endif


#endif // _OSSPECIFIC_H_

