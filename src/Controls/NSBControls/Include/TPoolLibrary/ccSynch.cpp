// ccSynch.cpp

ccCriticalSection::ccCriticalSection(BOOL bAssumeValid) {
    InitializeObjectLock(bAssumeValid);
}

ccCriticalSection::~ccCriticalSection() {
	#ifndef TPOOLLIBRARY_DUMMYCRITICALSECTION
    	if (m_bValid) DeleteCriticalSection(&m_cs);
    #endif // TPOOLLIBRARY_DUMMYCRITICALSECTION
}
BOOL    ccCriticalSection::InitializeObjectLock(BOOL bAssumeValid) {
		#ifndef TPOOLLIBRARY_DUMMYCRITICALSECTION
	        TRY_ {
	            InitializeCriticalSection(&m_cs);
	            m_bValid = TRUE;
	        } CATCH_(STATUS_NO_MEMORY) {
	            m_bValid = FALSE;
	        }
	        m_bAssumeValid = bAssumeValid;
	        return m_bValid;
        #else 
        	return TRUE;
        #endif // TPOOLLIBRARY_DUMMYCRITICALSECTION
}
BOOL    ccCriticalSection::Lock() {
	#ifndef TPOOLLIBRARY_DUMMYCRITICALSECTION
	    if (!m_bValid) {
	        if (m_bAssumeValid) return TRUE;
	        else {
	            if (!InitializeObjectLock()) return FALSE;
	        }
	    }
	    TRY_ {
	        EnterCriticalSection(&m_cs);
	    } CATCH_(STATUS_INVALID_HANDLE) {
	        LeaveCriticalSection(&m_cs);
	        return FALSE;
	    }
	#endif // TPOOLLIBRARY_DUMMYCRITICALSECTION
    return TRUE;
}
void    ccCriticalSection::UnLock() {
	#ifndef TPOOLLIBRARY_DUMMYCRITICALSECTION
	    if (m_bValid) {
	        LeaveCriticalSection(&m_cs);
	    }
 	#endif
}


// ccCriticalSectionCond

ccCriticalSectionCond::ccCriticalSectionCond(BOOL bActive):ccCriticalSection(FALSE) {
	m_bActive = bActive;
}
ccCriticalSectionCond::~ccCriticalSectionCond() {
	// Nothing
}
BOOL ccCriticalSectionCond::Lock() {
	if (m_bActive) {
		return ccCriticalSection::Lock();
	}
	return FALSE;
}
void ccCriticalSectionCond::UnLock() {
	if (m_bActive) {
		ccCriticalSection::UnLock();
	}
}
void	ccCriticalSectionCond::SetActive(BOOL b) {
	m_bActive = b;
}


// ccEvent =====================
//    HANDLE  m_hEvent;
ccEvent::ccEvent(BOOL bAutoreset,LPTSTR szEvent) {
    m_hEvent = ::CreateEvent(NULL,bAutoreset,FALSE,szEvent);
}
ccEvent::~ccEvent() {
    if (m_hEvent) CloseHandle(m_hEvent);
}
BOOL    ccEvent::Reset() {
    return ::ResetEvent(m_hEvent);
}
BOOL    ccEvent::Pulse() {
    return ::PulseEvent(m_hEvent);
}
BOOL    ccEvent::Set() {
    return ::SetEvent(m_hEvent);
}
BOOL    ccEvent::Wait(DWORD dwTimeOut) {
    if (::WaitForSingleObject(m_hEvent,dwTimeOut) == WAIT_OBJECT_0) return TRUE;
    return FALSE;
}
BOOL    ccEvent::IsSet() {
    if (::WaitForSingleObject(m_hEvent,0) == WAIT_OBJECT_0) return TRUE;
    else return FALSE;
}
BOOL    ccEvent::CheckAndReset() {
    if (::WaitForSingleObject(m_hEvent,0) == WAIT_OBJECT_0) {
        ::ResetEvent(m_hEvent);
        return TRUE;
    } else return FALSE;
}
ccEvent::operator HANDLE() {
     return m_hEvent;
}
BOOL    ccEvent::IsValid() {
    if (m_hEvent) {
        if (m_hEvent != INVALID_HANDLE_VALUE) return TRUE;
    }
    return FALSE;
}

ccEventHolder::ccEventHolder(ccEvent* evnt,BOOL bSet) { 
  m_evnt = evnt;
  m_bSet = bSet;
}
ccEventHolder::~ccEventHolder() {
  if (m_evnt) {
      if (m_bSet) {
          m_evnt->Set();
      } else {
          m_evnt->Reset();
      }
  }
}

// ccMutex ================================
ccMutex::ccMutex(BOOL bOwned,LPTSTR szMutex) {
    m_hMutex = ::CreateMutex(NULL,bOwned,szMutex);
}
ccMutex::~ccMutex() {
    if (m_hMutex) CloseHandle(m_hMutex);   
}

ccMutex::operator HANDLE() {
     return m_hMutex;
}
BOOL    ccMutex::IsValid() {
    if (m_hMutex) {
        if (m_hMutex != INVALID_HANDLE_VALUE) return TRUE;
    }
    return FALSE;
}
void    ccMutex::Release() {
    ::ReleaseMutex(m_hMutex);
}
BOOL    ccMutex::Wait(DWORD dwTimeOut) {
    if (::WaitForSingleObject(m_hMutex,dwTimeOut) == WAIT_OBJECT_0) return TRUE;
    return FALSE;
}
BOOL    ccMutex::IsOwned() {
    if (::WaitForSingleObject(m_hMutex,0) == WAIT_OBJECT_0) return TRUE;
    else return FALSE;
}


#ifdef TPOOLLIBRARY_SEMAPHORE
	// SEMAPHOREOBJECT ============================
	ccSemaphore::ccSemaphore(LONG lMax,LPTSTR szSemaphore) {
		m_hSemaphore = ::CreateSemaphore(NULL,lMax,lMax,szSemaphore);
	}
	ccSemaphore::~ccSemaphore() {
		if (m_hSemaphore) ::CloseHandle(m_hSemaphore);
	}

	ccSemaphore::operator HANDLE() {
		return m_hSemaphore;
	}
	BOOL    ccSemaphore::IsValid() {
		if (m_hSemaphore) {
			if (m_hSemaphore != INVALID_HANDLE_VALUE) return TRUE;
		}
		return FALSE;
	}
	BOOL    ccSemaphore::Release(LONG lInc) {
		return ::ReleaseSemaphore(m_hSemaphore,lInc,NULL);
	}
	BOOL    ccSemaphore::Wait(DWORD dwTimeOut) {
		if (::WaitForSingleObject(m_hSemaphore,dwTimeOut) == WAIT_OBJECT_0) return TRUE;
		return FALSE;
	}
#endif // TPOOLLIBRARY_SEMAPHORE
