// ccSync.h.H
// SYNCHRONIZATION OBJECTS

/*
  Compilation constants

    TPOOLLIBRARY_DUMMYCRITICALSECTION - define to implement dummy critical sections
    TPOOLLIBRARY_SEMAPHORE - define to include semaphores (earlier Windows CE OS versions do not support semaphores

 */

#ifndef _TPOOLLIBRARY_SYNCH_H_
#define _TPOOLLIBRARY_SYNCH_H_

#pragma message ("Including SYNCHRONIZATION classes (include ccmisc.h if errors occur)")

class ccCriticalSection {
	#ifndef TPOOLLIBRARY_DUMMYCRITICALSECTION
    CRITICAL_SECTION    m_cs;                   // Critical section
    int                 m_bValid:1;             // Is section valid
    int                 m_bAssumeValid:1;       // if set to TRUE ignores lock failre
    #endif // TPOOLLIBRARY_DUMMYCRITICALSECTION
public:
    ccCriticalSection(BOOL bAssumeValid = FALSE /* exception treatement */);
    virtual ~ccCriticalSection();
protected:
    BOOL    InitializeObjectLock(BOOL bAssumeValid = FALSE);
public:
    virtual BOOL    Lock();
    virtual void    UnLock();
};

// Conditional critical section
class ccCriticalSectionCond: public ccCriticalSection {
	BOOL	m_bActive;
public:
    ccCriticalSectionCond(BOOL bActive = FALSE);
    virtual ~ccCriticalSectionCond();
public:
    virtual BOOL    Lock();
    virtual void    UnLock();
	virtual void	SetActive(BOOL b);
};

class ccLockHolder {
    ccCriticalSection* m_pol;
public:
    ccLockHolder(ccCriticalSection* pol) { m_pol = pol;m_pol->Lock(); }
    ~ccLockHolder() { m_pol->UnLock(); }
};

#define _AutoSynchronized       ccLockHolder    l_automaticLockHolder(this)
#define _AutoSynchronizedOn(x)  ccLockHolder    l_automaticLockHolder(x)


class ccEvent {
    HANDLE  m_hEvent;
    public:
    ccEvent(BOOL bAutoreset = FALSE,LPTSTR szEvent = NULL);
    ~ccEvent();
                    
            operator HANDLE();
    BOOL    Reset();
    BOOL    Pulse();
    BOOL    Set();
    BOOL    Wait(DWORD dwTimeOut = INFINITE);
    BOOL    IsSet();
    BOOL    CheckAndReset();

    BOOL    IsValid();
};

class ccEventHolder {
    ccEvent*    m_evnt;
    BOOL        m_bSet;
  public:
      ccEventHolder(ccEvent* evnt,BOOL bSet = TRUE);
      ~ccEventHolder();
};

class ccMutex {
    HANDLE  m_hMutex;
    public:
    ccMutex(BOOL bOwned = FALSE,LPTSTR szMutex = NULL);
    ~ccMutex();
                    
            operator HANDLE();
    BOOL    IsValid();
    void    Release();
    BOOL    Wait(DWORD dwTimeOut = INFINITE);
    BOOL    IsOwned();
};

#ifdef TPOOLLIBRARY_SEMAPHORE

	class ccSemaphore {
		HANDLE      m_hSemaphore;
		public:
			ccSemaphore(LONG lMax = 1,LPTSTR szSemaphore = NULL);
			~ccSemaphore();

				operator HANDLE();
		BOOL    IsValid();
		BOOL    Release(LONG lInc = 1);
		BOOL    Wait(DWORD dwTimeOut = INFINITE);
	};
#endif // TPOOLLIBRARY_SEMAPHORE

#endif // _LOCKOBJECT_H_