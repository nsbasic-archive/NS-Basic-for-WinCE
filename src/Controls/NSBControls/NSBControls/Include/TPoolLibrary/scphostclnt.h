#ifndef _SCPHOSTCLNT_H_
#define _SCPHOSTCLNT_H_

//MIDL_INTERFACE("6CEAA770-C22C-11d4-9979-0040332BA2EA")
struct
    IScpMan : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_versionString( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT varKey,
            /* [in] */ VARIANT varItem,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarPlace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [in] */ VARIANT varKey,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_locked( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadEngine( 
            /* [in] */ BSTR bstrEngine,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddText( 
            /* [in] */ BSTR bstrText,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_script( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastError( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddEventHandler( 
            /* [in] */ BSTR bstrItem,
            /* [in] */ BSTR bstrSubItem,
            /* [in] */ BSTR bstrEvent,
            /* [in] */ BSTR bstrCode,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddEx( 
            /* [in] */ VARIANT varKey,
            /* [in] */ VARIANT varItem,
            /* [defaultvalue][optional][in] */ long lOptions,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarPlace) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsDefined( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTextEx( 
            /* [in] */ BSTR bstrText,
            /* [defaultvalue][in] */ long lLineNumber,
            /* [defaultvalue][in] */ long lContext,
            /* [optional][in] */ VARIANT varItemCtx,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastErrorEx( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR bstrText,
            /* [optional][in] */ VARIANT vItemCtx,
            /* [retval][out] */ VARIANT __RPC_FAR *pVarResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Option( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
		virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scriptObject( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    

const CLSID CLSID_ScpMan = {0x6CEAA772,0xC22C,0x11d4,{0x99,0x79,0x00,0x40,0x33,0x2B,0xA2,0xEA}};
const IID IID_IScpMan = {0x6CEAA770,0xC22C,0x11d4,{0x99,0x79,0x00,0x40,0x33,0x2B,0xA2,0xEA}};


// Every Interface returned by the functions here must be released after use !

class SCPHOSTCLNT {
    IScpMan*    m_pScpMan;
public:
	UINT		m_uCP;
    SCPHOSTCLNT();
    SCPHOSTCLNT(IScpMan*);
    virtual ~SCPHOSTCLNT();

    virtual BOOL CreateInstance();

    virtual BOOL    Success();

	virtual	HRESULT			Detach(IScpMan** ppObj);
    virtual int             Add(LPCTSTR,IDispatch*);
    virtual int             AddEx(LPCTSTR,IDispatch*,long);
    virtual int             Count();
    virtual IDispatch*      Item(LPCTSTR);
    virtual IDispatch*      Item(int);
    virtual BOOL            Clear();
    virtual BOOL            Remove(LPCTSTR);
    virtual BOOL            Remove(int);
    virtual BOOL            IsLocked();
    virtual BOOL            LoadEngine(LPCTSTR);
    virtual BOOL            AddCode(LPCTSTR);
    virtual BOOL            AddCodeEx(LPCTSTR,long,long);
    virtual BOOL            AddEventHandler(LPCTSTR,LPCTSTR,LPCTSTR,LPCTSTR);
    virtual BOOL            Connect();
    virtual BOOL            Run();
    virtual BOOL            Stop();
    virtual BOOL            Close();
    virtual IDispatch*      GetScriptDispatch();
	virtual IDispatch*      GetScriptObject();
    virtual int             GetLastError(LPTSTR,int);
    virtual IDispatch*      GetSelfDispatch();
};
/*
BSTR    _PackInBSTR(LPCTSTR,UINT uCP);
*/

#include <automationhlp.h>

#endif //_SCPHOSTCLNT_H_