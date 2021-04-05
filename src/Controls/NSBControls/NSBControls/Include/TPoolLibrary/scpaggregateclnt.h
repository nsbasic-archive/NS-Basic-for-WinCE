#ifndef _SCPAGGREGATECLNT_H_
#define _SCPAGGREGATECLNT_H_

MIDL_INTERFACE("E2F94D77-401E-4AC8-AC84-AFDAF408620B")
    IScpAggregate : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_versionString( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddEx( 
            /* [in] */ VARIANT varKey,
            /* [in] */ VARIANT varItem,
            /* [defaultvalue][optional][in] */ long lOptions,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarPlace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [in] */ VARIANT varKey,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddEngine( 
            /* [in] */ BSTR bstrEngine,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTextEx( 
            /* [in] */ BSTR bstrLanguage,
            /* [in] */ BSTR bstrText,
            /* [defaultvalue][in] */ long lLineNumber,
            /* [defaultvalue][in] */ long lContext,
            /* [optional][in] */ VARIANT varItemCtx,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [defaultvalue][in] */ long lOrder,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_script( 
            /* [optional][in] */ VARIANT varLanguage,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastError( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddEventHandler( 
            /* [in] */ BSTR bstrItem,
            /* [in] */ BSTR bstrSubItem,
            /* [in] */ BSTR bstrEvent,
            /* [in] */ BSTR bstrCode,
            /* [in] */ BSTR bstrLanguage,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsDefined( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT vKey,
            /* [in] */ VARIANT vItem,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarPlace) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddText( 
            /* [in] */ BSTR bstrLanguage,
            /* [in] */ BSTR bstrText,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Option( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastErrorEx( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WhereIsDefined( 
            /* [in] */ VARIANT varMember,
            /* [defaultvalue][in] */ long lType,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarResult) = 0;
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scriptObject( 
            /* [in] */ VARIANT varLanguage,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_errorHost( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_errorHost( 
            /* [in] */ long newVal) = 0;
        
    };


const CLSID CLSID_ScpAggregate = {0x2E98DDC5,0x3BFD,0x4794,{0x8F,0x7B,0x2D,0xAD,0xF4,0x26,0x59,0xBD}};
const IID IID_IScpAggregate = {0xE2F94D77,0x401E,0x4AC8,{0xAC,0x84,0xAF,0xDA,0xF4,0x08,0x62,0x0B}};


// Every Interface returned by the functions here must be released after use !

class SCPAGGREGATECLNT {
    IScpAggregate*    m_pScpAgg;
public:
	UINT			  m_uCP;

    SCPAGGREGATECLNT();
    SCPAGGREGATECLNT(IScpAggregate*);
    virtual ~SCPAGGREGATECLNT();

    virtual BOOL CreateInstance();

    virtual BOOL    Success();

	virtual HRESULT			Detach(IScpAggregate** ppObj);
    virtual int             Add(LPCTSTR,IDispatch*);
    virtual int             AddEx(LPCTSTR,IDispatch*,long);
    virtual int             Count();
    virtual IDispatch*      Item(LPCTSTR);
    virtual IDispatch*      Item(int);
    virtual BOOL            Clear();
    virtual BOOL            Remove(LPCTSTR);
    virtual BOOL            Remove(int);
    virtual BOOL            AddEngine(LPCTSTR);
    virtual BOOL            AddCode(LPCTSTR,LPCTSTR);
    virtual BOOL            AddCodeEx(LPCTSTR,LPCTSTR,long = 0,long = 0);
    virtual BOOL            AddEventHandler(LPCTSTR,LPCTSTR,LPCTSTR,LPCTSTR,LPCTSTR);
    virtual BOOL            Connect();
    virtual BOOL            Run(long = 0);
    virtual BOOL            Stop();
    virtual BOOL            Close();
    virtual IDispatch*      GetScriptDispatch(LPCTSTR);
    virtual IDispatch*      GetScriptDispatch(int = 0);
    virtual int             WhereIsDefined(LPCTSTR);
    virtual int             GetErrorHost();
    virtual void            SetErrorHost(int n);
    
    virtual int             GetLastError(LPTSTR,int);
    virtual IDispatch*      GetSelfDispatch();
};

#include <scphostclnt.h>
//BSTR    _PackInBSTR(LPCTSTR,UINT uCP = CP_ACP);


#endif //_SCPAGGREGATECLNT_H_