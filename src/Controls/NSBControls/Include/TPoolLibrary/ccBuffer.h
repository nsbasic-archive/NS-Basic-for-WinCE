#ifndef  _NEWOBJECTS_CCBUFFER_H_
#define _NEWOBJECTS_CCBUFFER_H_


#pragma message("Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp")

/* ccbuffer.H
 * ccBuffer class. Supports only windows but with little changes or type definitions can be
 * ported to Unix systems.
 */

// CCBUFFER_NOSTRINGLINES - removes string lines support from BUFFER object



#define CCBUFFER_DEFAULT_UNIT     256
#define CCBUFFER_READMASK         _T("\n\r")
#define CCBUFFER_WRITEMASK        _T("\n")

#define CCBUFFER_ERROR            ((DWORD)(-1))

class ccBuffer;
typedef ccBuffer* pccBuffer;

class ccBuffer {
    unsigned char*      m_pBuff;
    unsigned long       m_dwMaxSize;
    unsigned long       m_dwUnit;
    unsigned long       m_dwSize;
    unsigned long       m_dwPos;

#ifndef CCBUFFER_NOSTRINGLINES
    LPTSTR      m_szReadMask;
    LPTSTR      m_szWriteMask;
#endif //BUFFER_NOSTRINGLINES

    int         Init(unsigned long,unsigned long);          // inits buff with (maximum size, enlarge unit size)

public:
    ccBuffer();
    ccBuffer(DWORD);
    ccBuffer(DWORD,DWORD);
    ~ccBuffer();



    DWORD   Enlarge(DWORD);             // enlarge buffer (min bytes needed) - ret: size/0
    void    ResetContent();             // resets position
    void    Reset();                    // resets all - size and pos
    void    Reset(DWORD,DWORD);         // Resets with new settings
    BOOL    Validate();
    DWORD   BuffSize();                 // rets buffsize;
    

    DWORD   Put(LPBYTE,DWORD);          // puts bytes returns bytes written
    DWORD   Pad(BYTE,DWORD);            // put Byte N times
    LPBYTE  Prepare(DWORD);          	// prepares dw bytes for writting and returns ptr to the pos
    DWORD   Commit(DWORD);          	// Commits dw bytes
    DWORD   DataSize();                 // gets actual position
    DWORD   Get(LPBYTE,DWORD);          // gets bytes
    LPBYTE  GetPtr();                   // rets pointer to buff
    DWORD   Peek(LPBYTE,DWORD);         // gets without deleting
    DWORD   Skip(DWORD);                // skips bytes from buffer

    DWORD   TransferTo(ccBuffer*);        // Transfers to another buffer

    DWORD   FindSequence(LPBYTE,DWORD); // returns first occurence of sequence in buffer
    
    DWORD	GetMaxSize();
    DWORD	GetUnitSize();

    HRESULT ToSafeArray(SAFEARRAY** ppsa);
    HRESULT FromSafeArray(SAFEARRAY* psa);
    HRESULT ToVariant(VARIANT* pVar);
    HRESULT FromVariant(VARIANT v);

    #ifdef COMMON_DEBUG_CONSOLE
    void	Dump();
    #endif // COMMON_DEBUG_CONSOLE


#ifndef BUFFER_NOSTRINGLINES
    void    SetEndOfStringMasks(LPTSTR,LPTSTR); // sets end of string mask read/write
    DWORD   Put(LPTSTR);
    DWORD   PutLine(LPTSTR);
    DWORD   FindFromSet(LPTSTR);
    DWORD   FindNotFromSet(LPTSTR);
    LPTSTR  GetLine();
#endif //BUFFER_NOSTRINGLINES
};

HRESULT PackDataInSafeArray(ccBuffer& buff,SAFEARRAY** ppArray);
HRESULT UnPackDataFromSafeArray(SAFEARRAY* psa,ccBuffer& buff,BOOL bReset = FALSE);
HRESULT PackDataInVariant(ccBuffer& buff,VARIANT* pVar);
HRESULT UnPackDataFromVariant(VARIANT v,ccBuffer& buff,BOOL bReset = FALSE);

#endif // _NEWOBJECTS_CCBUFFER_H_