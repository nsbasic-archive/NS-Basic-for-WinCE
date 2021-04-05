// CCMISC.H
//
// 20-Mar-2006
//
// Misc. routines etc.
//
// This file must be included after all the other TPoolLibrary files
//
///////////////////////////////////////////

#ifndef _CCMISC_H_
#define _CCMISC_H_

#ifdef CC_BINTOHEX_ROUTINES
    #ifndef _TPOOLLIBRARY_AUTMATIONHLP_TYPEPACKERS_H_
        #error CC_BINTOHEX_ROUTINES require automation type packers (automationhlp.h)
    #endif
    
    BYTE        HexCharToByte(TCHAR ch);

    HRESULT     BinDataToHexText(LPBYTE pData,DWORD dwLen,BSTR* pbstr,BYTE bFlags = 0);
    HRESULT     HexTextToBinData(BSTR bstr,LPBYTE pData,DWORD dwLen,DWORD* pdwSize = NULL);

    #ifdef _NEWOBJECTS_CCBUFFER_H_
        
        HRESULT     BinDataToHexText(ccBuffer& buff,BSTR* pbstr,BYTE bFlags = 0);
        HRESULT     HexTextToBinData(BSTR bstr,ccBuffer& buff);        

    #endif // _NEWOBJECTS_CCBUFFER_H_

#endif // CC_BINTOHEX_ROUTINES

#ifndef SELF
    #define RESETBITS(x,y)			((y) ^ ((x) | (y)))
    #define SETBITS(x,y)		    ((x) | (y))
    #define SWAPXY(x,y)             ((x)^=(y)^=(x)^=(y))
    #define TOGBOOL(b) 		        ((b) = !(b))
    #define XOR(x,y)                ((!(x) && (y)) || ((x) && !(y)))
    #define SELF	                (*this)

    // EXCEPTION HANDLING
    #define TRY_                __try
    #define CATCH_(x)           __except( (::GetExceptionCode() == (x))?EXCEPTION_EXECUTE_HANDLER:EXCEPTION_CONTINUE_SEARCH )
    #define CATCHALL_           __except( EXCEPTION_EXECUTE_HANDLER )
    #define FINALLY_            __finally
    #define LEAVE_              __leave

#endif // SELF

#endif // _CCMISC_H_