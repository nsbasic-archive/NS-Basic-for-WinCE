#ifndef _TPOOLLIBRARY_IPERSIST_H_
#define _TPOOLLIBRARY_IPERSIST_H_

/**
  ATL style IPersistXXXInit classes.
  ATL compatibility is kept as far as possible, but the classes are independent.
  To achieve ATL compatibility with ATL you may need to re-implement some of the members 
  in your class which inherits from them.

  Generally these classes are for use in projects where the typical
  persistence implementations are replaced with custom ones.

 */

#ifdef ATL_NO_VTABLE
    #define CLASS_NO_VTABLE ATL_NO_VTABLE
#else
    #ifndef CLASS_NO_VTABLE_DISABLE
        #define CLASS_NO_VTABLE __declspec(novtable)
    #endif
#endif

//////////////////////////////////////////////////////////////////////////////
// IPersistStreamInitImpl
template <class T,const CLSID* _pclassID = &CLSID_NULL>
class CLASS_NO_VTABLE ccPersistStreamInitImpl: 
    public IPersistStreamInit {
public:
	// IPersist
	STDMETHOD(GetClassID)(CLSID *pClassID) {
		*pClassID = *_pclassID;
		return S_OK;
	}

	// IPersistStream
	STDMETHOD(IsDirty)() {
        T* pT = static_cast<T*>(this);
		return pT->IPersistStreamInit_IsDirty();
	}
	STDMETHOD(Load)(LPSTREAM pStm) {
		T* pT = static_cast<T*>(this);
		return pT->IPersistStreamInit_Load(pStm);
	}
	STDMETHOD(Save)(LPSTREAM pStm, BOOL fClearDirty) {
		T* pT = static_cast<T*>(this);
		return pT->IPersistStreamInit_Save(pStm, fClearDirty);
	}
	STDMETHOD(GetSizeMax)(ULARGE_INTEGER FAR* /* pcbSize */) {
		return E_NOTIMPL;
	}

	// IPersistStreamInit
	STDMETHOD(InitNew)() {
        T* pT = static_cast<T*>(this);
		return pT->IPersistStreamInit_InitNew();
	}

    // OVERRIDABLES
    HRESULT IPersistStreamInit_IsDirty() {
        return S_OK; // Always dirty by default
    }

    HRESULT IPersistStreamInit_InitNew() {
        return S_OK;
    }
	HRESULT IPersistStreamInit_Load(LPSTREAM pStm)	{
		return E_NOTIMPL;

	}
	HRESULT IPersistStreamInit_Save(LPSTREAM pStm, BOOL fClearDirty) {
		return E_NOTIMPL;
	}
};

//////////////////////////////////////////////////////////////////////////////
// IPersistStorageImpl
template <class T,const CLSID* _pclassID = &CLSID_NULL>
class CLASS_NO_VTABLE ccPersistStorageImpl:
    public IPersistStorage
{
public:
	// IPersist
	STDMETHOD(GetClassID)(CLSID *pClassID) {
		*pClassID = *_pclassID;
		return S_OK;
	}

	// IPersistStorage
	STDMETHOD(IsDirty)() {
        T* pT = static_cast<T*>(this);
		return pT->IPersistStorage_IsDirty();
	}
	STDMETHOD(Load)(IStorage* pStg) {
		T* pT = static_cast<T*>(this);
		return pT->IPersistStorage_Load(pStg);
	}
	STDMETHOD(Save)(IStorage* pStg, BOOL fClearDirty) {
		T* pT = static_cast<T*>(this);
		return pT->IPersistStorage_Save(pStg, fClearDirty);
	}
    STDMETHOD(InitNew)(IStorage* pStg) {
        T* pT = static_cast<T*>(this);
		return pT->IPersistStorage_InitNew(pStg);
	}
    STDMETHOD(SaveCompleted)(IStorage*) {
		return S_OK;
	}
	STDMETHOD(HandsOffStorage)(void) {
		return S_OK;
	}

    // OVERRIDABLES
    HRESULT IPersistStorage_IsDirty() {
        return S_OK; // Always dirty by default
    }

    HRESULT IPersistStorage_InitNew(IStorage* pStg) {
        return S_OK;
    }
	HRESULT IPersistStorage_Load(IStorage* pStg)	{
		return E_NOTIMPL;

	}
	HRESULT IPersistStorage_Save(IStorage* pStg, BOOL fClearDirty) {
		return E_NOTIMPL;
	}
};




#endif // _TPOOLLIBRARY_IPERSIST_H_