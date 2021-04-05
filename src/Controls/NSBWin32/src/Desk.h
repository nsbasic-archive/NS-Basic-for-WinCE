
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0286 */
/* at Fri Jan 26 07:09:33 2007
 */
/* Compiler settings for E:\NSBCE7\Controls\NSBWin32\src\Desk.idl:
    Os (OptLev=s), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Desk_h__
#define __Desk_h__

/* Forward Declarations */ 

#ifndef __IAPI_FWD_DEFINED__
#define __IAPI_FWD_DEFINED__
typedef interface IAPI IAPI;
#endif 	/* __IAPI_FWD_DEFINED__ */


#ifndef ___IAPIEvents_FWD_DEFINED__
#define ___IAPIEvents_FWD_DEFINED__
typedef interface _IAPIEvents _IAPIEvents;
#endif 	/* ___IAPIEvents_FWD_DEFINED__ */


#ifndef __IRegistry_FWD_DEFINED__
#define __IRegistry_FWD_DEFINED__
typedef interface IRegistry IRegistry;
#endif 	/* __IRegistry_FWD_DEFINED__ */


#ifndef __API_FWD_DEFINED__
#define __API_FWD_DEFINED__

#ifdef __cplusplus
typedef class API API;
#else
typedef struct API API;
#endif /* __cplusplus */

#endif 	/* __API_FWD_DEFINED__ */


#ifndef ___IRegistryEvents_FWD_DEFINED__
#define ___IRegistryEvents_FWD_DEFINED__
typedef interface _IRegistryEvents _IRegistryEvents;
#endif 	/* ___IRegistryEvents_FWD_DEFINED__ */


#ifndef __ITimer_FWD_DEFINED__
#define __ITimer_FWD_DEFINED__
typedef interface ITimer ITimer;
#endif 	/* __ITimer_FWD_DEFINED__ */


#ifndef __Registry_FWD_DEFINED__
#define __Registry_FWD_DEFINED__

#ifdef __cplusplus
typedef class Registry Registry;
#else
typedef struct Registry Registry;
#endif /* __cplusplus */

#endif 	/* __Registry_FWD_DEFINED__ */


#ifndef ___ITimerEvents_FWD_DEFINED__
#define ___ITimerEvents_FWD_DEFINED__
typedef interface _ITimerEvents _ITimerEvents;
#endif 	/* ___ITimerEvents_FWD_DEFINED__ */


#ifndef __ITray_FWD_DEFINED__
#define __ITray_FWD_DEFINED__
typedef interface ITray ITray;
#endif 	/* __ITray_FWD_DEFINED__ */


#ifndef __Timer_FWD_DEFINED__
#define __Timer_FWD_DEFINED__

#ifdef __cplusplus
typedef class Timer Timer;
#else
typedef struct Timer Timer;
#endif /* __cplusplus */

#endif 	/* __Timer_FWD_DEFINED__ */


#ifndef ___ITrayEvents_FWD_DEFINED__
#define ___ITrayEvents_FWD_DEFINED__
typedef interface _ITrayEvents _ITrayEvents;
#endif 	/* ___ITrayEvents_FWD_DEFINED__ */


#ifndef __IRAS_FWD_DEFINED__
#define __IRAS_FWD_DEFINED__
typedef interface IRAS IRAS;
#endif 	/* __IRAS_FWD_DEFINED__ */


#ifndef __Tray_FWD_DEFINED__
#define __Tray_FWD_DEFINED__

#ifdef __cplusplus
typedef class Tray Tray;
#else
typedef struct Tray Tray;
#endif /* __cplusplus */

#endif 	/* __Tray_FWD_DEFINED__ */


#ifndef ___IRASEvents_FWD_DEFINED__
#define ___IRASEvents_FWD_DEFINED__
typedef interface _IRASEvents _IRASEvents;
#endif 	/* ___IRASEvents_FWD_DEFINED__ */


#ifndef __IMiniEnum_FWD_DEFINED__
#define __IMiniEnum_FWD_DEFINED__
typedef interface IMiniEnum IMiniEnum;
#endif 	/* __IMiniEnum_FWD_DEFINED__ */


#ifndef __IRASEntry_FWD_DEFINED__
#define __IRASEntry_FWD_DEFINED__
typedef interface IRASEntry IRASEntry;
#endif 	/* __IRASEntry_FWD_DEFINED__ */


#ifndef __IRASConState_FWD_DEFINED__
#define __IRASConState_FWD_DEFINED__
typedef interface IRASConState IRASConState;
#endif 	/* __IRASConState_FWD_DEFINED__ */


#ifndef __IAPIPosPoint_FWD_DEFINED__
#define __IAPIPosPoint_FWD_DEFINED__
typedef interface IAPIPosPoint IAPIPosPoint;
#endif 	/* __IAPIPosPoint_FWD_DEFINED__ */


#ifndef __RAS_FWD_DEFINED__
#define __RAS_FWD_DEFINED__

#ifdef __cplusplus
typedef class RAS RAS;
#else
typedef struct RAS RAS;
#endif /* __cplusplus */

#endif 	/* __RAS_FWD_DEFINED__ */


#ifndef __MiniEnum_FWD_DEFINED__
#define __MiniEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class MiniEnum MiniEnum;
#else
typedef struct MiniEnum MiniEnum;
#endif /* __cplusplus */

#endif 	/* __MiniEnum_FWD_DEFINED__ */


#ifndef __RASEntry_FWD_DEFINED__
#define __RASEntry_FWD_DEFINED__

#ifdef __cplusplus
typedef class RASEntry RASEntry;
#else
typedef struct RASEntry RASEntry;
#endif /* __cplusplus */

#endif 	/* __RASEntry_FWD_DEFINED__ */


#ifndef __RASConState_FWD_DEFINED__
#define __RASConState_FWD_DEFINED__

#ifdef __cplusplus
typedef class RASConState RASConState;
#else
typedef struct RASConState RASConState;
#endif /* __cplusplus */

#endif 	/* __RASConState_FWD_DEFINED__ */


#ifndef __APIPosPoint_FWD_DEFINED__
#define __APIPosPoint_FWD_DEFINED__

#ifdef __cplusplus
typedef class APIPosPoint APIPosPoint;
#else
typedef struct APIPosPoint APIPosPoint;
#endif /* __cplusplus */

#endif 	/* __APIPosPoint_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IAPI_INTERFACE_DEFINED__
#define __IAPI_INTERFACE_DEFINED__

/* interface IAPI */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAPI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2DBB9E8E-F774-46F9-BB23-96122A994A2A")
    IAPI : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindWindow( 
            /* [in] */ BSTR bstrTitle,
            /* [retval][out] */ long __RPC_FAR *plhWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseCapture( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendMessage( 
            /* [in] */ long lWnd,
            /* [in] */ long lMsg,
            /* [in] */ long wParam,
            /* [in] */ long lParam,
            /* [retval][out] */ long __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendMessageText( 
            /* [in] */ long lWnd,
            /* [in] */ long lMsg,
            /* [in] */ long wParam,
            /* [in] */ BSTR bText,
            /* [retval][out] */ long __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowFromPoint( 
            /* [in] */ long lXpos,
            /* [in] */ long lYpos,
            /* [retval][out] */ long __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChildWindowFromPoint( 
            /* [in] */ long lWnd,
            /* [in] */ long lXpos,
            /* [in] */ long lYpos,
            /* [retval][out] */ long __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostMessage( 
            /* [in] */ long lWnd,
            /* [in] */ long lMsg,
            /* [in] */ long wParam,
            /* [in] */ long lParam,
            /* [retval][out] */ long __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForegroundWindow( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForegroundWindow( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Focus( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Focus( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Capture( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Capture( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableKeyboard( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableKeyboard( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WindowText( 
            /* [in] */ long lWnd,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WindowText( 
            /* [in] */ long lWnd,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SystemColor( 
            /* [in] */ long lColor,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SystemColor( 
            /* [in] */ long lColor,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TopMost( 
            /* [in] */ long lWnd,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TopMost( 
            /* [in] */ long lWnd,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWindow( 
            /* [in] */ long lWnd,
            /* [in] */ long lType,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassName( 
            /* [in] */ long lWnd,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowWindow( 
            /* [in] */ long lWnd,
            /* [in] */ long lFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAsyncKeyState( 
            /* [in] */ long lKey,
            /* [retval][out] */ long __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendKeys( 
            /* [in] */ BSTR bstrKeys,
            /* [defaultvalue][in] */ VARIANT_BOOL bSilent = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMemoryStatus( 
            /* [in] */ long lType,
            /* [retval][out] */ VARIANT __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStorageStatus( 
            /* [in] */ long lInfo,
            /* [optional][in] */ VARIANT v,
            /* [retval][out] */ VARIANT __RPC_FAR *pvResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPowerStatus( 
            /* [in] */ VARIANT v,
            /* [retval][out] */ VARIANT __RPC_FAR *pvResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SystemParameters( 
            VARIANT vType,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SystemParameters( 
            VARIANT vType,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_SystemParameters( 
            VARIANT vType,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateShortcut( 
            /* [in] */ BSTR bShortcut,
            /* [in] */ BSTR bTarget) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToRecent( 
            /* [in] */ BSTR bstrPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSpecialFolder( 
            /* [in] */ VARIANT vType,
            /* [retval][out] */ BSTR __RPC_FAR *pRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetShortcutTarget( 
            /* [in] */ BSTR bstrShortcut,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindWindowByClass( 
            /* [in] */ BSTR bClass,
            /* [retval][out] */ long __RPC_FAR *lRet) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClipText( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClipText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CursorPos( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SystemVersion( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WindowLong( 
            /* [in] */ long lWnd,
            /* [in] */ long lVal,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WindowLong( 
            /* [in] */ long lWnd,
            /* [in] */ long lVal,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Ticks( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SystemTime( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SystemTime( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalTime( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LocalTime( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WindowParent( 
            /* [in] */ long lWnd,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WindowParent( 
            /* [in] */ long lWnd,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OSType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAPIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAPI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAPI __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAPI __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAPI __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAPI __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAPI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAPI __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindWindow )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR bstrTitle,
            /* [retval][out] */ long __RPC_FAR *plhWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseCapture )( 
            IAPI __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendMessage )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lMsg,
            /* [in] */ long wParam,
            /* [in] */ long lParam,
            /* [retval][out] */ long __RPC_FAR *plRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendMessageText )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lMsg,
            /* [in] */ long wParam,
            /* [in] */ BSTR bText,
            /* [retval][out] */ long __RPC_FAR *plRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WindowFromPoint )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lXpos,
            /* [in] */ long lYpos,
            /* [retval][out] */ long __RPC_FAR *plRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChildWindowFromPoint )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lXpos,
            /* [in] */ long lYpos,
            /* [retval][out] */ long __RPC_FAR *plRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostMessage )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lMsg,
            /* [in] */ long wParam,
            /* [in] */ long lParam,
            /* [retval][out] */ long __RPC_FAR *plRet);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForegroundWindow )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForegroundWindow )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Focus )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Focus )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Capture )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Capture )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EnableKeyboard )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_EnableKeyboard )( 
            IAPI __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WindowText )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WindowText )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SystemColor )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lColor,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SystemColor )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lColor,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TopMost )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TopMost )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWindow )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lType,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClassName )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowWindow )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAsyncKeyState )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lKey,
            /* [retval][out] */ long __RPC_FAR *plRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendKeys )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR bstrKeys,
            /* [defaultvalue][in] */ VARIANT_BOOL bSilent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemoryStatus )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lType,
            /* [retval][out] */ VARIANT __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStorageStatus )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lInfo,
            /* [optional][in] */ VARIANT v,
            /* [retval][out] */ VARIANT __RPC_FAR *pvResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPowerStatus )( 
            IAPI __RPC_FAR * This,
            /* [in] */ VARIANT v,
            /* [retval][out] */ VARIANT __RPC_FAR *pvResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SystemParameters )( 
            IAPI __RPC_FAR * This,
            VARIANT vType,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SystemParameters )( 
            IAPI __RPC_FAR * This,
            VARIANT vType,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_SystemParameters )( 
            IAPI __RPC_FAR * This,
            VARIANT vType,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateShortcut )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR bShortcut,
            /* [in] */ BSTR bTarget);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToRecent )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR bstrPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpecialFolder )( 
            IAPI __RPC_FAR * This,
            /* [in] */ VARIANT vType,
            /* [retval][out] */ BSTR __RPC_FAR *pRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShortcutTarget )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR bstrShortcut,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindWindowByClass )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR bClass,
            /* [retval][out] */ long __RPC_FAR *lRet);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClipText )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ClipText )( 
            IAPI __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CursorPos )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SystemVersion )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WindowLong )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lVal,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WindowLong )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long lVal,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Ticks )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SystemTime )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SystemTime )( 
            IAPI __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LocalTime )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LocalTime )( 
            IAPI __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WindowParent )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WindowParent )( 
            IAPI __RPC_FAR * This,
            /* [in] */ long lWnd,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OSType )( 
            IAPI __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        END_INTERFACE
    } IAPIVtbl;

    interface IAPI
    {
        CONST_VTBL struct IAPIVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAPI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAPI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAPI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAPI_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAPI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAPI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAPI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAPI_FindWindow(This,bstrTitle,plhWnd)	\
    (This)->lpVtbl -> FindWindow(This,bstrTitle,plhWnd)

#define IAPI_ReleaseCapture(This)	\
    (This)->lpVtbl -> ReleaseCapture(This)

#define IAPI_SendMessage(This,lWnd,lMsg,wParam,lParam,plRet)	\
    (This)->lpVtbl -> SendMessage(This,lWnd,lMsg,wParam,lParam,plRet)

#define IAPI_SendMessageText(This,lWnd,lMsg,wParam,bText,plRet)	\
    (This)->lpVtbl -> SendMessageText(This,lWnd,lMsg,wParam,bText,plRet)

#define IAPI_WindowFromPoint(This,lXpos,lYpos,plRet)	\
    (This)->lpVtbl -> WindowFromPoint(This,lXpos,lYpos,plRet)

#define IAPI_ChildWindowFromPoint(This,lWnd,lXpos,lYpos,plRet)	\
    (This)->lpVtbl -> ChildWindowFromPoint(This,lWnd,lXpos,lYpos,plRet)

#define IAPI_PostMessage(This,lWnd,lMsg,wParam,lParam,plRet)	\
    (This)->lpVtbl -> PostMessage(This,lWnd,lMsg,wParam,lParam,plRet)

#define IAPI_get_ForegroundWindow(This,pVal)	\
    (This)->lpVtbl -> get_ForegroundWindow(This,pVal)

#define IAPI_put_ForegroundWindow(This,newVal)	\
    (This)->lpVtbl -> put_ForegroundWindow(This,newVal)

#define IAPI_get_Focus(This,pVal)	\
    (This)->lpVtbl -> get_Focus(This,pVal)

#define IAPI_put_Focus(This,newVal)	\
    (This)->lpVtbl -> put_Focus(This,newVal)

#define IAPI_get_Capture(This,pVal)	\
    (This)->lpVtbl -> get_Capture(This,pVal)

#define IAPI_put_Capture(This,newVal)	\
    (This)->lpVtbl -> put_Capture(This,newVal)

#define IAPI_get_EnableKeyboard(This,pVal)	\
    (This)->lpVtbl -> get_EnableKeyboard(This,pVal)

#define IAPI_put_EnableKeyboard(This,newVal)	\
    (This)->lpVtbl -> put_EnableKeyboard(This,newVal)

#define IAPI_get_WindowText(This,lWnd,pVal)	\
    (This)->lpVtbl -> get_WindowText(This,lWnd,pVal)

#define IAPI_put_WindowText(This,lWnd,newVal)	\
    (This)->lpVtbl -> put_WindowText(This,lWnd,newVal)

#define IAPI_get_SystemColor(This,lColor,pVal)	\
    (This)->lpVtbl -> get_SystemColor(This,lColor,pVal)

#define IAPI_put_SystemColor(This,lColor,newVal)	\
    (This)->lpVtbl -> put_SystemColor(This,lColor,newVal)

#define IAPI_get_TopMost(This,lWnd,pVal)	\
    (This)->lpVtbl -> get_TopMost(This,lWnd,pVal)

#define IAPI_put_TopMost(This,lWnd,newVal)	\
    (This)->lpVtbl -> put_TopMost(This,lWnd,newVal)

#define IAPI_GetWindow(This,lWnd,lType,pVal)	\
    (This)->lpVtbl -> GetWindow(This,lWnd,lType,pVal)

#define IAPI_get_ClassName(This,lWnd,pVal)	\
    (This)->lpVtbl -> get_ClassName(This,lWnd,pVal)

#define IAPI_ShowWindow(This,lWnd,lFlag)	\
    (This)->lpVtbl -> ShowWindow(This,lWnd,lFlag)

#define IAPI_GetAsyncKeyState(This,lKey,plRet)	\
    (This)->lpVtbl -> GetAsyncKeyState(This,lKey,plRet)

#define IAPI_SendKeys(This,bstrKeys,bSilent)	\
    (This)->lpVtbl -> SendKeys(This,bstrKeys,bSilent)

#define IAPI_GetMemoryStatus(This,lType,pResult)	\
    (This)->lpVtbl -> GetMemoryStatus(This,lType,pResult)

#define IAPI_GetStorageStatus(This,lInfo,v,pvResult)	\
    (This)->lpVtbl -> GetStorageStatus(This,lInfo,v,pvResult)

#define IAPI_GetPowerStatus(This,v,pvResult)	\
    (This)->lpVtbl -> GetPowerStatus(This,v,pvResult)

#define IAPI_get_SystemParameters(This,vType,pVal)	\
    (This)->lpVtbl -> get_SystemParameters(This,vType,pVal)

#define IAPI_put_SystemParameters(This,vType,newVal)	\
    (This)->lpVtbl -> put_SystemParameters(This,vType,newVal)

#define IAPI_putref_SystemParameters(This,vType,newVal)	\
    (This)->lpVtbl -> putref_SystemParameters(This,vType,newVal)

#define IAPI_CreateShortcut(This,bShortcut,bTarget)	\
    (This)->lpVtbl -> CreateShortcut(This,bShortcut,bTarget)

#define IAPI_AddToRecent(This,bstrPath)	\
    (This)->lpVtbl -> AddToRecent(This,bstrPath)

#define IAPI_GetSpecialFolder(This,vType,pRet)	\
    (This)->lpVtbl -> GetSpecialFolder(This,vType,pRet)

#define IAPI_GetShortcutTarget(This,bstrShortcut,pVal)	\
    (This)->lpVtbl -> GetShortcutTarget(This,bstrShortcut,pVal)

#define IAPI_FindWindowByClass(This,bClass,lRet)	\
    (This)->lpVtbl -> FindWindowByClass(This,bClass,lRet)

#define IAPI_get_ClipText(This,pVal)	\
    (This)->lpVtbl -> get_ClipText(This,pVal)

#define IAPI_put_ClipText(This,newVal)	\
    (This)->lpVtbl -> put_ClipText(This,newVal)

#define IAPI_get_Version(This,pVal)	\
    (This)->lpVtbl -> get_Version(This,pVal)

#define IAPI_get_CursorPos(This,pVal)	\
    (This)->lpVtbl -> get_CursorPos(This,pVal)

#define IAPI_get_SystemVersion(This,pVal)	\
    (This)->lpVtbl -> get_SystemVersion(This,pVal)

#define IAPI_get_WindowLong(This,lWnd,lVal,pVal)	\
    (This)->lpVtbl -> get_WindowLong(This,lWnd,lVal,pVal)

#define IAPI_put_WindowLong(This,lWnd,lVal,newVal)	\
    (This)->lpVtbl -> put_WindowLong(This,lWnd,lVal,newVal)

#define IAPI_get_Ticks(This,pVal)	\
    (This)->lpVtbl -> get_Ticks(This,pVal)

#define IAPI_get_SystemTime(This,pVal)	\
    (This)->lpVtbl -> get_SystemTime(This,pVal)

#define IAPI_put_SystemTime(This,newVal)	\
    (This)->lpVtbl -> put_SystemTime(This,newVal)

#define IAPI_get_LocalTime(This,pVal)	\
    (This)->lpVtbl -> get_LocalTime(This,pVal)

#define IAPI_put_LocalTime(This,newVal)	\
    (This)->lpVtbl -> put_LocalTime(This,newVal)

#define IAPI_get_WindowParent(This,lWnd,pVal)	\
    (This)->lpVtbl -> get_WindowParent(This,lWnd,pVal)

#define IAPI_put_WindowParent(This,lWnd,newVal)	\
    (This)->lpVtbl -> put_WindowParent(This,lWnd,newVal)

#define IAPI_get_OSType(This,pVal)	\
    (This)->lpVtbl -> get_OSType(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_FindWindow_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR bstrTitle,
    /* [retval][out] */ long __RPC_FAR *plhWnd);


void __RPC_STUB IAPI_FindWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_ReleaseCapture_Proxy( 
    IAPI __RPC_FAR * This);


void __RPC_STUB IAPI_ReleaseCapture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_SendMessage_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lMsg,
    /* [in] */ long wParam,
    /* [in] */ long lParam,
    /* [retval][out] */ long __RPC_FAR *plRet);


void __RPC_STUB IAPI_SendMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_SendMessageText_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lMsg,
    /* [in] */ long wParam,
    /* [in] */ BSTR bText,
    /* [retval][out] */ long __RPC_FAR *plRet);


void __RPC_STUB IAPI_SendMessageText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_WindowFromPoint_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lXpos,
    /* [in] */ long lYpos,
    /* [retval][out] */ long __RPC_FAR *plRet);


void __RPC_STUB IAPI_WindowFromPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_ChildWindowFromPoint_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lXpos,
    /* [in] */ long lYpos,
    /* [retval][out] */ long __RPC_FAR *plRet);


void __RPC_STUB IAPI_ChildWindowFromPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_PostMessage_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lMsg,
    /* [in] */ long wParam,
    /* [in] */ long lParam,
    /* [retval][out] */ long __RPC_FAR *plRet);


void __RPC_STUB IAPI_PostMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_ForegroundWindow_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_ForegroundWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_ForegroundWindow_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPI_put_ForegroundWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_Focus_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_Focus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_Focus_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPI_put_Focus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_Capture_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_Capture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_Capture_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPI_put_Capture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_EnableKeyboard_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_EnableKeyboard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_EnableKeyboard_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IAPI_put_EnableKeyboard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_WindowText_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_WindowText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_WindowText_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAPI_put_WindowText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_SystemColor_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lColor,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_SystemColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_SystemColor_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lColor,
    /* [in] */ long newVal);


void __RPC_STUB IAPI_put_SystemColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_TopMost_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_TopMost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_TopMost_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IAPI_put_TopMost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetWindow_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lType,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_GetWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_ClassName_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_ClassName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_ShowWindow_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lFlag);


void __RPC_STUB IAPI_ShowWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetAsyncKeyState_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lKey,
    /* [retval][out] */ long __RPC_FAR *plRet);


void __RPC_STUB IAPI_GetAsyncKeyState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_SendKeys_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR bstrKeys,
    /* [defaultvalue][in] */ VARIANT_BOOL bSilent);


void __RPC_STUB IAPI_SendKeys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetMemoryStatus_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lType,
    /* [retval][out] */ VARIANT __RPC_FAR *pResult);


void __RPC_STUB IAPI_GetMemoryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetStorageStatus_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lInfo,
    /* [optional][in] */ VARIANT v,
    /* [retval][out] */ VARIANT __RPC_FAR *pvResult);


void __RPC_STUB IAPI_GetStorageStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetPowerStatus_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ VARIANT v,
    /* [retval][out] */ VARIANT __RPC_FAR *pvResult);


void __RPC_STUB IAPI_GetPowerStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_SystemParameters_Proxy( 
    IAPI __RPC_FAR * This,
    VARIANT vType,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_SystemParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_SystemParameters_Proxy( 
    IAPI __RPC_FAR * This,
    VARIANT vType,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IAPI_put_SystemParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IAPI_putref_SystemParameters_Proxy( 
    IAPI __RPC_FAR * This,
    VARIANT vType,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IAPI_putref_SystemParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_CreateShortcut_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR bShortcut,
    /* [in] */ BSTR bTarget);


void __RPC_STUB IAPI_CreateShortcut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_AddToRecent_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR bstrPath);


void __RPC_STUB IAPI_AddToRecent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetSpecialFolder_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ VARIANT vType,
    /* [retval][out] */ BSTR __RPC_FAR *pRet);


void __RPC_STUB IAPI_GetSpecialFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_GetShortcutTarget_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR bstrShortcut,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAPI_GetShortcutTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAPI_FindWindowByClass_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR bClass,
    /* [retval][out] */ long __RPC_FAR *lRet);


void __RPC_STUB IAPI_FindWindowByClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_ClipText_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_ClipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_ClipText_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAPI_put_ClipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_Version_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_CursorPos_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_CursorPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_SystemVersion_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_SystemVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_WindowLong_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lVal,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_WindowLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_WindowLong_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long lVal,
    /* [in] */ long newVal);


void __RPC_STUB IAPI_put_WindowLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_Ticks_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_Ticks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_SystemTime_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_SystemTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_SystemTime_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IAPI_put_SystemTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_LocalTime_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_LocalTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_LocalTime_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IAPI_put_LocalTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_WindowParent_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_WindowParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPI_put_WindowParent_Proxy( 
    IAPI __RPC_FAR * This,
    /* [in] */ long lWnd,
    /* [in] */ long newVal);


void __RPC_STUB IAPI_put_WindowParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPI_get_OSType_Proxy( 
    IAPI __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IAPI_get_OSType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAPI_INTERFACE_DEFINED__ */



#ifndef __DESKLib_LIBRARY_DEFINED__
#define __DESKLib_LIBRARY_DEFINED__

/* library DESKLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DESKLib;

#ifndef ___IAPIEvents_DISPINTERFACE_DEFINED__
#define ___IAPIEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAPIEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IAPIEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8CDE0F97-EBED-4583-87E5-403A2C242986")
    _IAPIEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IAPIEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IAPIEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IAPIEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IAPIEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IAPIEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IAPIEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IAPIEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IAPIEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IAPIEventsVtbl;

    interface _IAPIEvents
    {
        CONST_VTBL struct _IAPIEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IAPIEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IAPIEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IAPIEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IAPIEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IAPIEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IAPIEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IAPIEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IAPIEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IRegistry_INTERFACE_DEFINED__
#define __IRegistry_INTERFACE_DEFINED__

/* interface IRegistry */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRegistry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73C23FBF-77FA-4B2E-92AB-6A78B28AF32B")
    IRegistry : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Key( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Path( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ValueType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ValueType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPathName( 
            /* [in] */ long lPath,
            /* [retval][out] */ BSTR __RPC_FAR *bstrPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetValueName( 
            /* [in] */ long lVal,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreatePath( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeletePath( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteValue( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseRawBinary( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseRawBinary( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HexWithSpaces( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HexWithSpaces( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReturnEmptyForEnumEnd( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReturnEmptyForEnumEnd( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegistryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegistry __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegistry __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRegistry __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Key )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Key )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Path )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Path )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ValueType )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ValueType )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPathName )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ long lPath,
            /* [retval][out] */ BSTR __RPC_FAR *bstrPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValueName )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ long lVal,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreatePath )( 
            IRegistry __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeletePath )( 
            IRegistry __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteValue )( 
            IRegistry __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UseRawBinary )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UseRawBinary )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HexWithSpaces )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HexWithSpaces )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReturnEmptyForEnumEnd )( 
            IRegistry __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReturnEmptyForEnumEnd )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IRegistryVtbl;

    interface IRegistry
    {
        CONST_VTBL struct IRegistryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegistry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegistry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegistry_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegistry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRegistry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRegistry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRegistry_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRegistry_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IRegistry_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#define IRegistry_get_Key(This,pVal)	\
    (This)->lpVtbl -> get_Key(This,pVal)

#define IRegistry_put_Key(This,newVal)	\
    (This)->lpVtbl -> put_Key(This,newVal)

#define IRegistry_get_Path(This,pVal)	\
    (This)->lpVtbl -> get_Path(This,pVal)

#define IRegistry_put_Path(This,newVal)	\
    (This)->lpVtbl -> put_Path(This,newVal)

#define IRegistry_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IRegistry_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IRegistry_get_Version(This,pVal)	\
    (This)->lpVtbl -> get_Version(This,pVal)

#define IRegistry_get_ValueType(This,pVal)	\
    (This)->lpVtbl -> get_ValueType(This,pVal)

#define IRegistry_put_ValueType(This,newVal)	\
    (This)->lpVtbl -> put_ValueType(This,newVal)

#define IRegistry_GetPathName(This,lPath,bstrPath)	\
    (This)->lpVtbl -> GetPathName(This,lPath,bstrPath)

#define IRegistry_GetValueName(This,lVal,bstrVal)	\
    (This)->lpVtbl -> GetValueName(This,lVal,bstrVal)

#define IRegistry_CreatePath(This)	\
    (This)->lpVtbl -> CreatePath(This)

#define IRegistry_DeletePath(This)	\
    (This)->lpVtbl -> DeletePath(This)

#define IRegistry_DeleteValue(This)	\
    (This)->lpVtbl -> DeleteValue(This)

#define IRegistry_get_UseRawBinary(This,pVal)	\
    (This)->lpVtbl -> get_UseRawBinary(This,pVal)

#define IRegistry_put_UseRawBinary(This,newVal)	\
    (This)->lpVtbl -> put_UseRawBinary(This,newVal)

#define IRegistry_get_HexWithSpaces(This,pVal)	\
    (This)->lpVtbl -> get_HexWithSpaces(This,pVal)

#define IRegistry_put_HexWithSpaces(This,newVal)	\
    (This)->lpVtbl -> put_HexWithSpaces(This,newVal)

#define IRegistry_get_ReturnEmptyForEnumEnd(This,pVal)	\
    (This)->lpVtbl -> get_ReturnEmptyForEnumEnd(This,pVal)

#define IRegistry_put_ReturnEmptyForEnumEnd(This,newVal)	\
    (This)->lpVtbl -> put_ReturnEmptyForEnumEnd(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_Value_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_Value_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IRegistry_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_Key_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_Key_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IRegistry_put_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_Path_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_Path_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_Path_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRegistry_put_Path_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_Name_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_Name_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRegistry_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_Version_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_ValueType_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_ValueType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_ValueType_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IRegistry_put_ValueType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_GetPathName_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ long lPath,
    /* [retval][out] */ BSTR __RPC_FAR *bstrPath);


void __RPC_STUB IRegistry_GetPathName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_GetValueName_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ long lVal,
    /* [retval][out] */ BSTR __RPC_FAR *bstrVal);


void __RPC_STUB IRegistry_GetValueName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_CreatePath_Proxy( 
    IRegistry __RPC_FAR * This);


void __RPC_STUB IRegistry_CreatePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_DeletePath_Proxy( 
    IRegistry __RPC_FAR * This);


void __RPC_STUB IRegistry_DeletePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_DeleteValue_Proxy( 
    IRegistry __RPC_FAR * This);


void __RPC_STUB IRegistry_DeleteValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_UseRawBinary_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_UseRawBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_UseRawBinary_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IRegistry_put_UseRawBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_HexWithSpaces_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_HexWithSpaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_HexWithSpaces_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IRegistry_put_HexWithSpaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRegistry_get_ReturnEmptyForEnumEnd_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IRegistry_get_ReturnEmptyForEnumEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRegistry_put_ReturnEmptyForEnumEnd_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IRegistry_put_ReturnEmptyForEnumEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegistry_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_API;

#ifdef __cplusplus

class DECLSPEC_UUID("9217A3CE-4560-45D0-853C-F4CBCAD694C4")
API;
#endif

#ifndef ___IRegistryEvents_DISPINTERFACE_DEFINED__
#define ___IRegistryEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IRegistryEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IRegistryEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6A5801CA-412D-40F3-9387-0A18DC86A172")
    _IRegistryEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IRegistryEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IRegistryEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IRegistryEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IRegistryEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IRegistryEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IRegistryEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IRegistryEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IRegistryEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IRegistryEventsVtbl;

    interface _IRegistryEvents
    {
        CONST_VTBL struct _IRegistryEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IRegistryEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IRegistryEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IRegistryEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IRegistryEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IRegistryEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IRegistryEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IRegistryEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IRegistryEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ITimer_INTERFACE_DEFINED__
#define __ITimer_INTERFACE_DEFINED__

/* interface ITimer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITimer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("68AC877B-3C13-4AAA-A133-FD57B844403B")
    ITimer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Interval( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Interval( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( 
            /* [defaultvalue][in] */ long lInterval = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITimerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITimer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITimer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITimer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITimer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITimer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITimer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITimer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interval )( 
            ITimer __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Interval )( 
            ITimer __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            ITimer __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            ITimer __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            ITimer __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Start )( 
            ITimer __RPC_FAR * This,
            /* [defaultvalue][in] */ long lInterval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            ITimer __RPC_FAR * This);
        
        END_INTERFACE
    } ITimerVtbl;

    interface ITimer
    {
        CONST_VTBL struct ITimerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITimer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITimer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITimer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITimer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITimer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITimer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITimer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITimer_get_Interval(This,pVal)	\
    (This)->lpVtbl -> get_Interval(This,pVal)

#define ITimer_put_Interval(This,newVal)	\
    (This)->lpVtbl -> put_Interval(This,newVal)

#define ITimer_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define ITimer_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define ITimer_get_Version(This,pVal)	\
    (This)->lpVtbl -> get_Version(This,pVal)

#define ITimer_Start(This,lInterval)	\
    (This)->lpVtbl -> Start(This,lInterval)

#define ITimer_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITimer_get_Interval_Proxy( 
    ITimer __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ITimer_get_Interval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITimer_put_Interval_Proxy( 
    ITimer __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ITimer_put_Interval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITimer_get_Tag_Proxy( 
    ITimer __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB ITimer_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITimer_put_Tag_Proxy( 
    ITimer __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB ITimer_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITimer_get_Version_Proxy( 
    ITimer __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ITimer_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITimer_Start_Proxy( 
    ITimer __RPC_FAR * This,
    /* [defaultvalue][in] */ long lInterval);


void __RPC_STUB ITimer_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITimer_Stop_Proxy( 
    ITimer __RPC_FAR * This);


void __RPC_STUB ITimer_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITimer_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Registry;

#ifdef __cplusplus

class DECLSPEC_UUID("602E25DA-DBE7-4358-A542-1DFEC6793443")
Registry;
#endif

#ifndef ___ITimerEvents_DISPINTERFACE_DEFINED__
#define ___ITimerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITimerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITimerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("871BBB2C-37F0-40FD-8315-15CE6F053240")
    _ITimerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITimerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ITimerEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ITimerEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ITimerEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ITimerEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ITimerEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ITimerEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ITimerEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ITimerEventsVtbl;

    interface _ITimerEvents
    {
        CONST_VTBL struct _ITimerEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITimerEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ITimerEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ITimerEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ITimerEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ITimerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ITimerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ITimerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITimerEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ITray_INTERFACE_DEFINED__
#define __ITray_INTERFACE_DEFINED__

/* interface ITray */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D8ECB90-92AE-44DF-BDD0-E556B1215FE6")
    ITray : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Image( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Image( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddImage( 
            /* [in] */ BSTR bstrImage,
            /* [retval][out] */ long __RPC_FAR *plAdded) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveImage( 
            /* [in] */ long lImage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tip( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tip( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITray __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITray __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITray __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITray __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITray __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITray __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITray __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            ITray __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            ITray __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            ITray __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Image )( 
            ITray __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Image )( 
            ITray __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddImage )( 
            ITray __RPC_FAR * This,
            /* [in] */ BSTR bstrImage,
            /* [retval][out] */ long __RPC_FAR *plAdded);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveImage )( 
            ITray __RPC_FAR * This,
            /* [in] */ long lImage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tip )( 
            ITray __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tip )( 
            ITray __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ITrayVtbl;

    interface ITray
    {
        CONST_VTBL struct ITrayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITray_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITray_get_Version(This,pVal)	\
    (This)->lpVtbl -> get_Version(This,pVal)

#define ITray_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define ITray_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define ITray_get_Image(This,pVal)	\
    (This)->lpVtbl -> get_Image(This,pVal)

#define ITray_put_Image(This,newVal)	\
    (This)->lpVtbl -> put_Image(This,newVal)

#define ITray_AddImage(This,bstrImage,plAdded)	\
    (This)->lpVtbl -> AddImage(This,bstrImage,plAdded)

#define ITray_RemoveImage(This,lImage)	\
    (This)->lpVtbl -> RemoveImage(This,lImage)

#define ITray_get_Tip(This,pVal)	\
    (This)->lpVtbl -> get_Tip(This,pVal)

#define ITray_put_Tip(This,newVal)	\
    (This)->lpVtbl -> put_Tip(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITray_get_Version_Proxy( 
    ITray __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ITray_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITray_get_Tag_Proxy( 
    ITray __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB ITray_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITray_put_Tag_Proxy( 
    ITray __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB ITray_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITray_get_Image_Proxy( 
    ITray __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ITray_get_Image_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITray_put_Image_Proxy( 
    ITray __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ITray_put_Image_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITray_AddImage_Proxy( 
    ITray __RPC_FAR * This,
    /* [in] */ BSTR bstrImage,
    /* [retval][out] */ long __RPC_FAR *plAdded);


void __RPC_STUB ITray_AddImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITray_RemoveImage_Proxy( 
    ITray __RPC_FAR * This,
    /* [in] */ long lImage);


void __RPC_STUB ITray_RemoveImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITray_get_Tip_Proxy( 
    ITray __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ITray_get_Tip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITray_put_Tip_Proxy( 
    ITray __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ITray_put_Tip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITray_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Timer;

#ifdef __cplusplus

class DECLSPEC_UUID("ACE050A1-EEF9-435B-8D29-0D676727188B")
Timer;
#endif

#ifndef ___ITrayEvents_DISPINTERFACE_DEFINED__
#define ___ITrayEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITrayEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITrayEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B076D927-5D10-4BEF-988B-0C7F8D6C9678")
    _ITrayEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITrayEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ITrayEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ITrayEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ITrayEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ITrayEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ITrayEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ITrayEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ITrayEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ITrayEventsVtbl;

    interface _ITrayEvents
    {
        CONST_VTBL struct _ITrayEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITrayEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ITrayEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ITrayEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ITrayEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ITrayEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ITrayEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ITrayEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITrayEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IRAS_INTERFACE_DEFINED__
#define __IRAS_INTERFACE_DEFINED__

/* interface IRAS */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRAS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49A756A5-39EA-48FC-989B-83EAE678223E")
    IRAS : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhoneBook( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PhoneBook( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Entries( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Connections( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Entry( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRASVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRAS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRAS __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRAS __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRAS __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRAS __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRAS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRAS __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PhoneBook )( 
            IRAS __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PhoneBook )( 
            IRAS __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Entries )( 
            IRAS __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IRAS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Connections )( 
            IRAS __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Entry )( 
            IRAS __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } IRASVtbl;

    interface IRAS
    {
        CONST_VTBL struct IRASVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRAS_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRAS_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRAS_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRAS_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRAS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRAS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRAS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRAS_get_PhoneBook(This,pVal)	\
    (This)->lpVtbl -> get_PhoneBook(This,pVal)

#define IRAS_put_PhoneBook(This,newVal)	\
    (This)->lpVtbl -> put_PhoneBook(This,newVal)

#define IRAS_get_Entries(This,pVal)	\
    (This)->lpVtbl -> get_Entries(This,pVal)

#define IRAS_get_Version(This,pVal)	\
    (This)->lpVtbl -> get_Version(This,pVal)

#define IRAS_get_Connections(This,pVal)	\
    (This)->lpVtbl -> get_Connections(This,pVal)

#define IRAS_get_Entry(This,bstrName,pVal)	\
    (This)->lpVtbl -> get_Entry(This,bstrName,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRAS_get_PhoneBook_Proxy( 
    IRAS __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRAS_get_PhoneBook_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRAS_put_PhoneBook_Proxy( 
    IRAS __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRAS_put_PhoneBook_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRAS_get_Entries_Proxy( 
    IRAS __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IRAS_get_Entries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRAS_get_Version_Proxy( 
    IRAS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IRAS_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRAS_get_Connections_Proxy( 
    IRAS __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IRAS_get_Connections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRAS_get_Entry_Proxy( 
    IRAS __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IRAS_get_Entry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRAS_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Tray;

#ifdef __cplusplus

class DECLSPEC_UUID("5334D155-E526-4A1D-B03F-86B112DC8D3A")
Tray;
#endif

#ifndef ___IRASEvents_DISPINTERFACE_DEFINED__
#define ___IRASEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IRASEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IRASEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E0F161FC-1226-4E35-84FB-06B4A7CA4513")
    _IRASEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IRASEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IRASEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IRASEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IRASEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IRASEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IRASEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IRASEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IRASEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IRASEventsVtbl;

    interface _IRASEvents
    {
        CONST_VTBL struct _IRASEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IRASEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IRASEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IRASEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IRASEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IRASEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IRASEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IRASEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IRASEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IMiniEnum_INTERFACE_DEFINED__
#define __IMiniEnum_INTERFACE_DEFINED__

/* interface IMiniEnum */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMiniEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A0C668E-6D87-4946-8659-46ECB8CA3C28")
    IMiniEnum : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long lIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMiniEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMiniEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMiniEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMiniEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMiniEnum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMiniEnum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMiniEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMiniEnum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IMiniEnum __RPC_FAR * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IMiniEnum __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IMiniEnum __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } IMiniEnumVtbl;

    interface IMiniEnum
    {
        CONST_VTBL struct IMiniEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMiniEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMiniEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMiniEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMiniEnum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMiniEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMiniEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMiniEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMiniEnum_get_Item(This,lIndex,pVal)	\
    (This)->lpVtbl -> get_Item(This,lIndex,pVal)

#define IMiniEnum_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IMiniEnum_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMiniEnum_get_Item_Proxy( 
    IMiniEnum __RPC_FAR * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IMiniEnum_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMiniEnum_get_Count_Proxy( 
    IMiniEnum __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMiniEnum_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMiniEnum_get__NewEnum_Proxy( 
    IMiniEnum __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IMiniEnum_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMiniEnum_INTERFACE_DEFINED__ */


#ifndef __IRASEntry_INTERFACE_DEFINED__
#define __IRASEntry_INTERFACE_DEFINED__

/* interface IRASEntry */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRASEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E70A835-EB6B-4E19-812A-089E735C4476")
    IRASEntry : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallbackNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallbackNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UserName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Domain( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Domain( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Validate( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhoneNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PhoneNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasPassword( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HasPassword( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetState( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRASEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRASEntry __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRASEntry __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRASEntry __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CallbackNumber )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CallbackNumber )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UserName )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UserName )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Domain )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Domain )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Password )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PhoneNumber )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PhoneNumber )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IRASEntry __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IRASEntry __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IRASEntry __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )( 
            IRASEntry __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IRASEntry __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasPassword )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HasPassword )( 
            IRASEntry __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsActive )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IRASEntry __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetState )( 
            IRASEntry __RPC_FAR * This);
        
        END_INTERFACE
    } IRASEntryVtbl;

    interface IRASEntry
    {
        CONST_VTBL struct IRASEntryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRASEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRASEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRASEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRASEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRASEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRASEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRASEntry_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRASEntry_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IRASEntry_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IRASEntry_get_CallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_CallbackNumber(This,pVal)

#define IRASEntry_put_CallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_CallbackNumber(This,newVal)

#define IRASEntry_get_UserName(This,pVal)	\
    (This)->lpVtbl -> get_UserName(This,pVal)

#define IRASEntry_put_UserName(This,newVal)	\
    (This)->lpVtbl -> put_UserName(This,newVal)

#define IRASEntry_get_Domain(This,pVal)	\
    (This)->lpVtbl -> get_Domain(This,pVal)

#define IRASEntry_put_Domain(This,newVal)	\
    (This)->lpVtbl -> put_Domain(This,newVal)

#define IRASEntry_put_Password(This,newVal)	\
    (This)->lpVtbl -> put_Password(This,newVal)

#define IRASEntry_Validate(This,pbResult)	\
    (This)->lpVtbl -> Validate(This,pbResult)

#define IRASEntry_get_PhoneNumber(This,pVal)	\
    (This)->lpVtbl -> get_PhoneNumber(This,pVal)

#define IRASEntry_put_PhoneNumber(This,newVal)	\
    (This)->lpVtbl -> put_PhoneNumber(This,newVal)

#define IRASEntry_Connect(This)	\
    (This)->lpVtbl -> Connect(This)

#define IRASEntry_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IRASEntry_Load(This)	\
    (This)->lpVtbl -> Load(This)

#define IRASEntry_Update(This)	\
    (This)->lpVtbl -> Update(This)

#define IRASEntry_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IRASEntry_get_HasPassword(This,pVal)	\
    (This)->lpVtbl -> get_HasPassword(This,pVal)

#define IRASEntry_put_HasPassword(This,newVal)	\
    (This)->lpVtbl -> put_HasPassword(This,newVal)

#define IRASEntry_get_IsActive(This,pVal)	\
    (This)->lpVtbl -> get_IsActive(This,pVal)

#define IRASEntry_get_Status(This,pVal)	\
    (This)->lpVtbl -> get_Status(This,pVal)

#define IRASEntry_ResetState(This)	\
    (This)->lpVtbl -> ResetState(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_Name_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_Name_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRASEntry_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_CallbackNumber_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_CallbackNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_CallbackNumber_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRASEntry_put_CallbackNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_UserName_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_UserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_UserName_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRASEntry_put_UserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_Domain_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_Domain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_Domain_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRASEntry_put_Domain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_Password_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRASEntry_put_Password_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_Validate_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);


void __RPC_STUB IRASEntry_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_PhoneNumber_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_PhoneNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_PhoneNumber_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IRASEntry_put_PhoneNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_Connect_Proxy( 
    IRASEntry __RPC_FAR * This);


void __RPC_STUB IRASEntry_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_Disconnect_Proxy( 
    IRASEntry __RPC_FAR * This);


void __RPC_STUB IRASEntry_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_Load_Proxy( 
    IRASEntry __RPC_FAR * This);


void __RPC_STUB IRASEntry_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_Update_Proxy( 
    IRASEntry __RPC_FAR * This);


void __RPC_STUB IRASEntry_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_Delete_Proxy( 
    IRASEntry __RPC_FAR * This);


void __RPC_STUB IRASEntry_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_HasPassword_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_HasPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRASEntry_put_HasPassword_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IRASEntry_put_HasPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_IsActive_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASEntry_get_Status_Proxy( 
    IRASEntry __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IRASEntry_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASEntry_ResetState_Proxy( 
    IRASEntry __RPC_FAR * This);


void __RPC_STUB IRASEntry_ResetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRASEntry_INTERFACE_DEFINED__ */


#ifndef __IRASConState_INTERFACE_DEFINED__
#define __IRASConState_INTERFACE_DEFINED__

/* interface IRASConState */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRASConState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("16825776-A0C8-4BBE-A94F-F4E265FB317D")
    IRASConState : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceType( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRASConStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRASConState __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRASConState __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRASConState __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRASConState __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRASConState __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRASConState __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRASConState __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_State )( 
            IRASConState __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorNumber )( 
            IRASConState __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DeviceType )( 
            IRASConState __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DeviceName )( 
            IRASConState __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRASConState __RPC_FAR * This);
        
        END_INTERFACE
    } IRASConStateVtbl;

    interface IRASConState
    {
        CONST_VTBL struct IRASConStateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRASConState_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRASConState_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRASConState_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRASConState_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRASConState_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRASConState_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRASConState_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRASConState_get_State(This,pVal)	\
    (This)->lpVtbl -> get_State(This,pVal)

#define IRASConState_get_ErrorNumber(This,pVal)	\
    (This)->lpVtbl -> get_ErrorNumber(This,pVal)

#define IRASConState_get_DeviceType(This,pVal)	\
    (This)->lpVtbl -> get_DeviceType(This,pVal)

#define IRASConState_get_DeviceName(This,pVal)	\
    (This)->lpVtbl -> get_DeviceName(This,pVal)

#define IRASConState_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASConState_get_State_Proxy( 
    IRASConState __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IRASConState_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASConState_get_ErrorNumber_Proxy( 
    IRASConState __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IRASConState_get_ErrorNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASConState_get_DeviceType_Proxy( 
    IRASConState __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASConState_get_DeviceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRASConState_get_DeviceName_Proxy( 
    IRASConState __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IRASConState_get_DeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRASConState_Refresh_Proxy( 
    IRASConState __RPC_FAR * This);


void __RPC_STUB IRASConState_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRASConState_INTERFACE_DEFINED__ */


#ifndef __IAPIPosPoint_INTERFACE_DEFINED__
#define __IAPIPosPoint_INTERFACE_DEFINED__

/* interface IAPIPosPoint */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAPIPosPoint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A41DAE7D-A1CD-4E15-BAA1-A4AAD050CEEB")
    IAPIPosPoint : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_X( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_X( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Y( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Y( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Right( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Right( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bottom( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bottom( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [in] */ long lIndex,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ long lIndex,
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAPIPosPointVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAPIPosPoint __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAPIPosPoint __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_X )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_X )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Y )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Y )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Left )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Top )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Right )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Right )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Bottom )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Bottom )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            IAPIPosPoint __RPC_FAR * This,
            /* [in] */ long lIndex,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IAPIPosPointVtbl;

    interface IAPIPosPoint
    {
        CONST_VTBL struct IAPIPosPointVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAPIPosPoint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAPIPosPoint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAPIPosPoint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAPIPosPoint_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAPIPosPoint_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAPIPosPoint_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAPIPosPoint_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAPIPosPoint_get_X(This,pVal)	\
    (This)->lpVtbl -> get_X(This,pVal)

#define IAPIPosPoint_put_X(This,newVal)	\
    (This)->lpVtbl -> put_X(This,newVal)

#define IAPIPosPoint_get_Y(This,pVal)	\
    (This)->lpVtbl -> get_Y(This,pVal)

#define IAPIPosPoint_put_Y(This,newVal)	\
    (This)->lpVtbl -> put_Y(This,newVal)

#define IAPIPosPoint_get_Left(This,pVal)	\
    (This)->lpVtbl -> get_Left(This,pVal)

#define IAPIPosPoint_put_Left(This,newVal)	\
    (This)->lpVtbl -> put_Left(This,newVal)

#define IAPIPosPoint_get_Top(This,pVal)	\
    (This)->lpVtbl -> get_Top(This,pVal)

#define IAPIPosPoint_put_Top(This,newVal)	\
    (This)->lpVtbl -> put_Top(This,newVal)

#define IAPIPosPoint_get_Right(This,pVal)	\
    (This)->lpVtbl -> get_Right(This,pVal)

#define IAPIPosPoint_put_Right(This,newVal)	\
    (This)->lpVtbl -> put_Right(This,newVal)

#define IAPIPosPoint_get_Bottom(This,pVal)	\
    (This)->lpVtbl -> get_Bottom(This,pVal)

#define IAPIPosPoint_put_Bottom(This,newVal)	\
    (This)->lpVtbl -> put_Bottom(This,newVal)

#define IAPIPosPoint_get_Value(This,lIndex,pVal)	\
    (This)->lpVtbl -> get_Value(This,lIndex,pVal)

#define IAPIPosPoint_put_Value(This,lIndex,newVal)	\
    (This)->lpVtbl -> put_Value(This,lIndex,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_X_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_X_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_Y_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_Y_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_Left_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_Left_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_Top_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_Top_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_Right_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_Right_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_Right_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_Right_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_Bottom_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_Bottom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_Bottom_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_Bottom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_get_Value_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IAPIPosPoint_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAPIPosPoint_put_Value_Proxy( 
    IAPIPosPoint __RPC_FAR * This,
    /* [in] */ long lIndex,
    /* [in] */ long newVal);


void __RPC_STUB IAPIPosPoint_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAPIPosPoint_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_RAS;

#ifdef __cplusplus

class DECLSPEC_UUID("38CE02DD-7A75-4077-A1A8-DEC520CD618A")
RAS;
#endif

EXTERN_C const CLSID CLSID_MiniEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("EF7E635B-8F0C-4EE1-B99D-E2A0C83A4763")
MiniEnum;
#endif

EXTERN_C const CLSID CLSID_RASEntry;

#ifdef __cplusplus

class DECLSPEC_UUID("26CABC11-3169-41F8-8353-AFC2A5EA572B")
RASEntry;
#endif

EXTERN_C const CLSID CLSID_RASConState;

#ifdef __cplusplus

class DECLSPEC_UUID("2E99A06C-AC25-401D-9526-C65C1F4EEF53")
RASConState;
#endif

EXTERN_C const CLSID CLSID_APIPosPoint;

#ifdef __cplusplus

class DECLSPEC_UUID("B98C4618-BB8B-40C1-9B6B-CDE95B2CA62F")
APIPosPoint;
#endif
#endif /* __DESKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


