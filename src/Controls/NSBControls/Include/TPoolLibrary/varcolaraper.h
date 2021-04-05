#ifndef _VARCOLHELPER_H_
#define _VARCOLHELPER_H_


MIDL_INTERFACE("94A837CD-193F-11D5-999C-0040332BA2EA")
    IVarDictionary : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [optional][in] */ VARIANT varIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT varKey,
            /* [in] */ VARIANT varItem,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarPlace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [in] */ VARIANT VarKey,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Root( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Root( 
            /* [in] */ VARIANT vVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Missing( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Missing( 
            /* [in] */ VARIANT varVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Item( 
            /* [optional][in] */ VARIANT varIndex,
            /* [in] */ VARIANT varVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Info( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Info( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_firstItemAsRoot( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_firstItemAsRoot( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ VARIANT VarKey,
            /* [in] */ VARIANT VarItem,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarPlace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_itemsAssignmentAllowed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_itemsAssignmentAllowed( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_classVersion( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_enumItems( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_enumItems( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_allowUnnamedValues( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_allowUnnamedValues( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_allowDuplicateNames( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_allowDuplicateNames( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };

const CLSID CLSID_VarDictionary = {0x94A837CE,0x193F,0x11D5,{0x99,0x9C,0x00,0x40,0x33,0x2B,0xA2,0xEA}};
const IID IID_IVarDictionary = {0x94A837CD,0x193F,0x11D5,{0x99,0x9C,0x00,0x40,0x33,0x2B,0xA2,0xEA}};


// Every Interface returned by the functions here must be released after use !

class VARDICTIONARY {
    IScpMan*    m_pScpMan;
public:
    SCPHOSTCLNT();
    SCPHOSTCLNT(IScpMan*);
    virtual ~SCPHOSTCLNT();

    virtual BOOL CreateInstance();

    virtual BOOL    Success();

    virtual int             Add(LPCTSTR,IDispatch*);
    virtual int             Count();
    virtual IDispatch*      Item(LPCTSTR);
    virtual IDispatch*      Item(int);
    virtual BOOL            Clear();
    virtual BOOL            Remove(LPCTSTR);
    virtual BOOL            Remove(int);
    virtual BOOL            IsLocked();
    virtual BOOL            LoadEngine(LPCTSTR);
    virtual BOOL            AddCode(LPCTSTR);
    virtual BOOL            AddEventHandler(LPCTSTR,LPCTSTR,LPCTSTR,LPCTSTR);
    virtual BOOL            Connect();
    virtual BOOL            Run();
    virtual BOOL            Stop();
    virtual BOOL            Close();
    virtual IDispatch*      GetScriptDispatch();
    virtual int             GetLastError(LPTSTR,int);
    virtual IDispatch*      GetSelfDispatch();
};

BSTR    _PackInBSTR(LPCTSTR);

#include <automationhlp.h>

#endif //_VARCOLHELPER_H_