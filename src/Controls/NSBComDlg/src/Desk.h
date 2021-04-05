
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0286 */
/* at Fri Jan 26 06:35:55 2007
 */
/* Compiler settings for E:\NSBCE7\Controls\NSBComDlg\src\Desk.idl:
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

#ifndef __INSComDlgFlags_FWD_DEFINED__
#define __INSComDlgFlags_FWD_DEFINED__
typedef interface INSComDlgFlags INSComDlgFlags;
#endif 	/* __INSComDlgFlags_FWD_DEFINED__ */


#ifndef __IComDlgMiniEnum_FWD_DEFINED__
#define __IComDlgMiniEnum_FWD_DEFINED__
typedef interface IComDlgMiniEnum IComDlgMiniEnum;
#endif 	/* __IComDlgMiniEnum_FWD_DEFINED__ */


#ifndef __INSComDlg_FWD_DEFINED__
#define __INSComDlg_FWD_DEFINED__
typedef interface INSComDlg INSComDlg;
#endif 	/* __INSComDlg_FWD_DEFINED__ */


#ifndef __NSComDlg_FWD_DEFINED__
#define __NSComDlg_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSComDlg NSComDlg;
#else
typedef struct NSComDlg NSComDlg;
#endif /* __cplusplus */

#endif 	/* __NSComDlg_FWD_DEFINED__ */


#ifndef __NSComDlgFlags_FWD_DEFINED__
#define __NSComDlgFlags_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSComDlgFlags NSComDlgFlags;
#else
typedef struct NSComDlgFlags NSComDlgFlags;
#endif /* __cplusplus */

#endif 	/* __NSComDlgFlags_FWD_DEFINED__ */


#ifndef __ComDlgMiniEnum_FWD_DEFINED__
#define __ComDlgMiniEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComDlgMiniEnum ComDlgMiniEnum;
#else
typedef struct ComDlgMiniEnum ComDlgMiniEnum;
#endif /* __cplusplus */

#endif 	/* __ComDlgMiniEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __INSComDlgFlags_INTERFACE_DEFINED__
#define __INSComDlgFlags_INTERFACE_DEFINED__

/* interface INSComDlgFlags */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSComDlgFlags;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF531F0F-5139-408A-A56D-E62B03F230EE")
    INSComDlgFlags : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MultiSelect( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MultiSelect( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreatePrompt( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CreatePrompt( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExtensionDifferent( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileMustExist( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileMustExist( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpButton( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpButton( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HideReadOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HideReadOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoChangeDir( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoChangeDir( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoDereferenceLinks( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoDereferenceLinks( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoReadOnlyReturn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoReadOnlyReturn( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoValidate( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoValidate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverwritePrompt( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverwritePrompt( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PathMustExist( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PathMustExist( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShareAware( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShareAware( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FullOpen( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FullOpen( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PreventFullOpen( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PreventFullOpen( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RGBInit( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RGBInit( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ANSIOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ANSIOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Effects( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Effects( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedPitchOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedPitchOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForceFontExist( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForceFontExist( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LimitSize( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LimitSize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoFaceSel( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoFaceSel( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoSimulations( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoSimulations( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoSizeSel( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoSizeSel( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoStyleSel( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoStyleSel( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoVectorFonts( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoVectorFonts( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScalableOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScalableOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScreenFonts( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScreenFonts( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TTOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TTOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WYSIWYG( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WYSIWYG( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDefaults( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrinterFonts( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PrinterFonts( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSComDlgFlagsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSComDlgFlags __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSComDlgFlags __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            INSComDlgFlags __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MultiSelect )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MultiSelect )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CreatePrompt )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CreatePrompt )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtensionDifferent )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileMustExist )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileMustExist )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpButton )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpButton )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HideReadOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HideReadOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoChangeDir )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoChangeDir )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoDereferenceLinks )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoDereferenceLinks )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoReadOnlyReturn )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoReadOnlyReturn )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoValidate )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoValidate )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OverwritePrompt )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OverwritePrompt )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PathMustExist )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PathMustExist )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReadOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReadOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShareAware )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShareAware )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FullOpen )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FullOpen )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PreventFullOpen )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PreventFullOpen )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RGBInit )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RGBInit )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ANSIOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ANSIOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Effects )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Effects )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedPitchOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedPitchOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForceFontExist )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForceFontExist )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LimitSize )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LimitSize )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoFaceSel )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoFaceSel )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoSimulations )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoSimulations )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoSizeSel )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoSizeSel )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoStyleSel )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoStyleSel )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NoVectorFonts )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoVectorFonts )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScalableOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScalableOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScreenFonts )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScreenFonts )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TTOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TTOnly )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WYSIWYG )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WYSIWYG )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaults )( 
            INSComDlgFlags __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PrinterFonts )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PrinterFonts )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            INSComDlgFlags __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } INSComDlgFlagsVtbl;

    interface INSComDlgFlags
    {
        CONST_VTBL struct INSComDlgFlagsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSComDlgFlags_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSComDlgFlags_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSComDlgFlags_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSComDlgFlags_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSComDlgFlags_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSComDlgFlags_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSComDlgFlags_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSComDlgFlags_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define INSComDlgFlags_get_MultiSelect(This,pVal)	\
    (This)->lpVtbl -> get_MultiSelect(This,pVal)

#define INSComDlgFlags_put_MultiSelect(This,newVal)	\
    (This)->lpVtbl -> put_MultiSelect(This,newVal)

#define INSComDlgFlags_get_CreatePrompt(This,pVal)	\
    (This)->lpVtbl -> get_CreatePrompt(This,pVal)

#define INSComDlgFlags_put_CreatePrompt(This,newVal)	\
    (This)->lpVtbl -> put_CreatePrompt(This,newVal)

#define INSComDlgFlags_get_ExtensionDifferent(This,pVal)	\
    (This)->lpVtbl -> get_ExtensionDifferent(This,pVal)

#define INSComDlgFlags_get_FileMustExist(This,pVal)	\
    (This)->lpVtbl -> get_FileMustExist(This,pVal)

#define INSComDlgFlags_put_FileMustExist(This,newVal)	\
    (This)->lpVtbl -> put_FileMustExist(This,newVal)

#define INSComDlgFlags_get_HelpButton(This,pVal)	\
    (This)->lpVtbl -> get_HelpButton(This,pVal)

#define INSComDlgFlags_put_HelpButton(This,newVal)	\
    (This)->lpVtbl -> put_HelpButton(This,newVal)

#define INSComDlgFlags_get_HideReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_HideReadOnly(This,pVal)

#define INSComDlgFlags_put_HideReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_HideReadOnly(This,newVal)

#define INSComDlgFlags_get_NoChangeDir(This,pVal)	\
    (This)->lpVtbl -> get_NoChangeDir(This,pVal)

#define INSComDlgFlags_put_NoChangeDir(This,newVal)	\
    (This)->lpVtbl -> put_NoChangeDir(This,newVal)

#define INSComDlgFlags_get_NoDereferenceLinks(This,pVal)	\
    (This)->lpVtbl -> get_NoDereferenceLinks(This,pVal)

#define INSComDlgFlags_put_NoDereferenceLinks(This,newVal)	\
    (This)->lpVtbl -> put_NoDereferenceLinks(This,newVal)

#define INSComDlgFlags_get_NoReadOnlyReturn(This,pVal)	\
    (This)->lpVtbl -> get_NoReadOnlyReturn(This,pVal)

#define INSComDlgFlags_put_NoReadOnlyReturn(This,newVal)	\
    (This)->lpVtbl -> put_NoReadOnlyReturn(This,newVal)

#define INSComDlgFlags_get_NoValidate(This,pVal)	\
    (This)->lpVtbl -> get_NoValidate(This,pVal)

#define INSComDlgFlags_put_NoValidate(This,newVal)	\
    (This)->lpVtbl -> put_NoValidate(This,newVal)

#define INSComDlgFlags_get_OverwritePrompt(This,pVal)	\
    (This)->lpVtbl -> get_OverwritePrompt(This,pVal)

#define INSComDlgFlags_put_OverwritePrompt(This,newVal)	\
    (This)->lpVtbl -> put_OverwritePrompt(This,newVal)

#define INSComDlgFlags_get_PathMustExist(This,pVal)	\
    (This)->lpVtbl -> get_PathMustExist(This,pVal)

#define INSComDlgFlags_put_PathMustExist(This,newVal)	\
    (This)->lpVtbl -> put_PathMustExist(This,newVal)

#define INSComDlgFlags_get_ReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_ReadOnly(This,pVal)

#define INSComDlgFlags_put_ReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_ReadOnly(This,newVal)

#define INSComDlgFlags_get_ShareAware(This,pVal)	\
    (This)->lpVtbl -> get_ShareAware(This,pVal)

#define INSComDlgFlags_put_ShareAware(This,newVal)	\
    (This)->lpVtbl -> put_ShareAware(This,newVal)

#define INSComDlgFlags_get_FullOpen(This,pVal)	\
    (This)->lpVtbl -> get_FullOpen(This,pVal)

#define INSComDlgFlags_put_FullOpen(This,newVal)	\
    (This)->lpVtbl -> put_FullOpen(This,newVal)

#define INSComDlgFlags_get_PreventFullOpen(This,pVal)	\
    (This)->lpVtbl -> get_PreventFullOpen(This,pVal)

#define INSComDlgFlags_put_PreventFullOpen(This,newVal)	\
    (This)->lpVtbl -> put_PreventFullOpen(This,newVal)

#define INSComDlgFlags_get_RGBInit(This,pVal)	\
    (This)->lpVtbl -> get_RGBInit(This,pVal)

#define INSComDlgFlags_put_RGBInit(This,newVal)	\
    (This)->lpVtbl -> put_RGBInit(This,newVal)

#define INSComDlgFlags_get_ANSIOnly(This,pVal)	\
    (This)->lpVtbl -> get_ANSIOnly(This,pVal)

#define INSComDlgFlags_put_ANSIOnly(This,newVal)	\
    (This)->lpVtbl -> put_ANSIOnly(This,newVal)

#define INSComDlgFlags_get_Effects(This,pVal)	\
    (This)->lpVtbl -> get_Effects(This,pVal)

#define INSComDlgFlags_put_Effects(This,newVal)	\
    (This)->lpVtbl -> put_Effects(This,newVal)

#define INSComDlgFlags_get_FixedPitchOnly(This,pVal)	\
    (This)->lpVtbl -> get_FixedPitchOnly(This,pVal)

#define INSComDlgFlags_put_FixedPitchOnly(This,newVal)	\
    (This)->lpVtbl -> put_FixedPitchOnly(This,newVal)

#define INSComDlgFlags_get_ForceFontExist(This,pVal)	\
    (This)->lpVtbl -> get_ForceFontExist(This,pVal)

#define INSComDlgFlags_put_ForceFontExist(This,newVal)	\
    (This)->lpVtbl -> put_ForceFontExist(This,newVal)

#define INSComDlgFlags_get_LimitSize(This,pVal)	\
    (This)->lpVtbl -> get_LimitSize(This,pVal)

#define INSComDlgFlags_put_LimitSize(This,newVal)	\
    (This)->lpVtbl -> put_LimitSize(This,newVal)

#define INSComDlgFlags_get_NoFaceSel(This,pVal)	\
    (This)->lpVtbl -> get_NoFaceSel(This,pVal)

#define INSComDlgFlags_put_NoFaceSel(This,newVal)	\
    (This)->lpVtbl -> put_NoFaceSel(This,newVal)

#define INSComDlgFlags_get_NoSimulations(This,pVal)	\
    (This)->lpVtbl -> get_NoSimulations(This,pVal)

#define INSComDlgFlags_put_NoSimulations(This,newVal)	\
    (This)->lpVtbl -> put_NoSimulations(This,newVal)

#define INSComDlgFlags_get_NoSizeSel(This,pVal)	\
    (This)->lpVtbl -> get_NoSizeSel(This,pVal)

#define INSComDlgFlags_put_NoSizeSel(This,newVal)	\
    (This)->lpVtbl -> put_NoSizeSel(This,newVal)

#define INSComDlgFlags_get_NoStyleSel(This,pVal)	\
    (This)->lpVtbl -> get_NoStyleSel(This,pVal)

#define INSComDlgFlags_put_NoStyleSel(This,newVal)	\
    (This)->lpVtbl -> put_NoStyleSel(This,newVal)

#define INSComDlgFlags_get_NoVectorFonts(This,pVal)	\
    (This)->lpVtbl -> get_NoVectorFonts(This,pVal)

#define INSComDlgFlags_put_NoVectorFonts(This,newVal)	\
    (This)->lpVtbl -> put_NoVectorFonts(This,newVal)

#define INSComDlgFlags_get_ScalableOnly(This,pVal)	\
    (This)->lpVtbl -> get_ScalableOnly(This,pVal)

#define INSComDlgFlags_put_ScalableOnly(This,newVal)	\
    (This)->lpVtbl -> put_ScalableOnly(This,newVal)

#define INSComDlgFlags_get_ScreenFonts(This,pVal)	\
    (This)->lpVtbl -> get_ScreenFonts(This,pVal)

#define INSComDlgFlags_put_ScreenFonts(This,newVal)	\
    (This)->lpVtbl -> put_ScreenFonts(This,newVal)

#define INSComDlgFlags_get_TTOnly(This,pVal)	\
    (This)->lpVtbl -> get_TTOnly(This,pVal)

#define INSComDlgFlags_put_TTOnly(This,newVal)	\
    (This)->lpVtbl -> put_TTOnly(This,newVal)

#define INSComDlgFlags_get_WYSIWYG(This,pVal)	\
    (This)->lpVtbl -> get_WYSIWYG(This,pVal)

#define INSComDlgFlags_put_WYSIWYG(This,newVal)	\
    (This)->lpVtbl -> put_WYSIWYG(This,newVal)

#define INSComDlgFlags_SetDefaults(This)	\
    (This)->lpVtbl -> SetDefaults(This)

#define INSComDlgFlags_get_PrinterFonts(This,pVal)	\
    (This)->lpVtbl -> get_PrinterFonts(This,pVal)

#define INSComDlgFlags_put_PrinterFonts(This,newVal)	\
    (This)->lpVtbl -> put_PrinterFonts(This,newVal)

#define INSComDlgFlags_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define INSComDlgFlags_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_Clear_Proxy( 
    INSComDlgFlags __RPC_FAR * This);


void __RPC_STUB INSComDlgFlags_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_MultiSelect_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_MultiSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_MultiSelect_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_MultiSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_CreatePrompt_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_CreatePrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_CreatePrompt_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_CreatePrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ExtensionDifferent_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ExtensionDifferent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_FileMustExist_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_FileMustExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_FileMustExist_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_FileMustExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_HelpButton_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_HelpButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_HelpButton_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_HelpButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_HideReadOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_HideReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_HideReadOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_HideReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoChangeDir_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoChangeDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoChangeDir_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoChangeDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoDereferenceLinks_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoDereferenceLinks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoDereferenceLinks_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoDereferenceLinks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoReadOnlyReturn_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoReadOnlyReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoReadOnlyReturn_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoReadOnlyReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoValidate_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoValidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoValidate_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoValidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_OverwritePrompt_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_OverwritePrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_OverwritePrompt_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_OverwritePrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_PathMustExist_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_PathMustExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_PathMustExist_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_PathMustExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ReadOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_ReadOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_ReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ShareAware_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ShareAware_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_ShareAware_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_ShareAware_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_FullOpen_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_FullOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_FullOpen_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_FullOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_PreventFullOpen_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_PreventFullOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_PreventFullOpen_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_PreventFullOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_RGBInit_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_RGBInit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_RGBInit_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_RGBInit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ANSIOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ANSIOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_ANSIOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_ANSIOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_Effects_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_Effects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_Effects_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_Effects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_FixedPitchOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_FixedPitchOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_FixedPitchOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_FixedPitchOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ForceFontExist_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ForceFontExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_ForceFontExist_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_ForceFontExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_LimitSize_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_LimitSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_LimitSize_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_LimitSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoFaceSel_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoFaceSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoFaceSel_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoFaceSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoSimulations_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoSimulations_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoSimulations_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoSimulations_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoSizeSel_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoSizeSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoSizeSel_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoSizeSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoStyleSel_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoStyleSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoStyleSel_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoStyleSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_NoVectorFonts_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_NoVectorFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_NoVectorFonts_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_NoVectorFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ScalableOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ScalableOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_ScalableOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_ScalableOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_ScreenFonts_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_ScreenFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_ScreenFonts_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_ScreenFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_TTOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_TTOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_TTOnly_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_TTOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_WYSIWYG_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_WYSIWYG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_WYSIWYG_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_WYSIWYG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_SetDefaults_Proxy( 
    INSComDlgFlags __RPC_FAR * This);


void __RPC_STUB INSComDlgFlags_SetDefaults_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_PrinterFonts_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_PrinterFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_PrinterFonts_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlgFlags_put_PrinterFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_get_Value_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComDlgFlags_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlgFlags_put_Value_Proxy( 
    INSComDlgFlags __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSComDlgFlags_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSComDlgFlags_INTERFACE_DEFINED__ */


#ifndef __IComDlgMiniEnum_INTERFACE_DEFINED__
#define __IComDlgMiniEnum_INTERFACE_DEFINED__

/* interface IComDlgMiniEnum */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IComDlgMiniEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71480CE5-596C-4045-8AED-036752C8CC0A")
    IComDlgMiniEnum : public IDispatch
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

    typedef struct IComDlgMiniEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IComDlgMiniEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IComDlgMiniEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IComDlgMiniEnum __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } IComDlgMiniEnumVtbl;

    interface IComDlgMiniEnum
    {
        CONST_VTBL struct IComDlgMiniEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComDlgMiniEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IComDlgMiniEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IComDlgMiniEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IComDlgMiniEnum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IComDlgMiniEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IComDlgMiniEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IComDlgMiniEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IComDlgMiniEnum_get_Item(This,lIndex,pVal)	\
    (This)->lpVtbl -> get_Item(This,lIndex,pVal)

#define IComDlgMiniEnum_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IComDlgMiniEnum_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComDlgMiniEnum_get_Item_Proxy( 
    IComDlgMiniEnum __RPC_FAR * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IComDlgMiniEnum_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComDlgMiniEnum_get_Count_Proxy( 
    IComDlgMiniEnum __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IComDlgMiniEnum_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComDlgMiniEnum_get__NewEnum_Proxy( 
    IComDlgMiniEnum __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IComDlgMiniEnum_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IComDlgMiniEnum_INTERFACE_DEFINED__ */


#ifndef __INSComDlg_INTERFACE_DEFINED__
#define __INSComDlg_INTERFACE_DEFINED__

/* interface INSComDlg */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSComDlg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7C7890C-6667-4EF1-8D64-CDC04BDEDE14")
    INSComDlg : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DialogTitle( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DialogTitle( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Filter( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Filter( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultExt( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultExt( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InitDir( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InitDir( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Color( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ INSComDlgFlags __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontBold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontBold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontItalic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontItalic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontStrikeThru( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontStrikeThru( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontUnderLine( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontUnderLine( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Min( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Min( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Max( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Max( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CancelError( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CancelError( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterIndex( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FilterIndex( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileTitle( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileTitle( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowOpen( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowSave( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowColor( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowFont( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Charset( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Charset( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Action( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Action( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileNames( 
            /* [retval][out] */ IComDlgMiniEnum __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( 
            /* [optional][in] */ VARIANT vAction) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomColors( 
            /* [in] */ long index,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomColors( 
            /* [in] */ long index,
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsPocketPC( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpCommand( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpCommand( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpContext( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpContext( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpKey( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpKey( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowHelp( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSComDlgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSComDlg __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSComDlg __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSComDlg __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileName )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileName )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DialogTitle )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DialogTitle )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Filter )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Filter )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultExt )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultExt )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InitDir )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_InitDir )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Color )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Color )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Flags )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ INSComDlgFlags __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontBold )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontBold )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontItalic )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontItalic )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontStrikeThru )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontStrikeThru )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontUnderLine )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontUnderLine )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Min )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Min )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Max )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Max )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CancelError )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CancelError )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FilterIndex )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FilterIndex )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileTitle )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileTitle )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowOpen )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowSave )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowColor )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowFont )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Charset )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Charset )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Action )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Action )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileNames )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ IComDlgMiniEnum __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            INSComDlg __RPC_FAR * This,
            /* [optional][in] */ VARIANT vAction);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CustomColors )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CustomColors )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsPocketPC )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpFile )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpFile )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpCommand )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpCommand )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContext )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContext )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpKey )( 
            INSComDlg __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpKey )( 
            INSComDlg __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowHelp )( 
            INSComDlg __RPC_FAR * This);
        
        END_INTERFACE
    } INSComDlgVtbl;

    interface INSComDlg
    {
        CONST_VTBL struct INSComDlgVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSComDlg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSComDlg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSComDlg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSComDlg_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSComDlg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSComDlg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSComDlg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSComDlg_get_FileName(This,pVal)	\
    (This)->lpVtbl -> get_FileName(This,pVal)

#define INSComDlg_put_FileName(This,newVal)	\
    (This)->lpVtbl -> put_FileName(This,newVal)

#define INSComDlg_get_DialogTitle(This,pVal)	\
    (This)->lpVtbl -> get_DialogTitle(This,pVal)

#define INSComDlg_put_DialogTitle(This,newVal)	\
    (This)->lpVtbl -> put_DialogTitle(This,newVal)

#define INSComDlg_get_Filter(This,pVal)	\
    (This)->lpVtbl -> get_Filter(This,pVal)

#define INSComDlg_put_Filter(This,newVal)	\
    (This)->lpVtbl -> put_Filter(This,newVal)

#define INSComDlg_get_DefaultExt(This,pVal)	\
    (This)->lpVtbl -> get_DefaultExt(This,pVal)

#define INSComDlg_put_DefaultExt(This,newVal)	\
    (This)->lpVtbl -> put_DefaultExt(This,newVal)

#define INSComDlg_get_InitDir(This,pVal)	\
    (This)->lpVtbl -> get_InitDir(This,pVal)

#define INSComDlg_put_InitDir(This,newVal)	\
    (This)->lpVtbl -> put_InitDir(This,newVal)

#define INSComDlg_get_Color(This,pVal)	\
    (This)->lpVtbl -> get_Color(This,pVal)

#define INSComDlg_put_Color(This,newVal)	\
    (This)->lpVtbl -> put_Color(This,newVal)

#define INSComDlg_get_Flags(This,pVal)	\
    (This)->lpVtbl -> get_Flags(This,pVal)

#define INSComDlg_get_FontName(This,pVal)	\
    (This)->lpVtbl -> get_FontName(This,pVal)

#define INSComDlg_put_FontName(This,newVal)	\
    (This)->lpVtbl -> put_FontName(This,newVal)

#define INSComDlg_get_FontBold(This,pVal)	\
    (This)->lpVtbl -> get_FontBold(This,pVal)

#define INSComDlg_put_FontBold(This,newVal)	\
    (This)->lpVtbl -> put_FontBold(This,newVal)

#define INSComDlg_get_FontItalic(This,pVal)	\
    (This)->lpVtbl -> get_FontItalic(This,pVal)

#define INSComDlg_put_FontItalic(This,newVal)	\
    (This)->lpVtbl -> put_FontItalic(This,newVal)

#define INSComDlg_get_FontStrikeThru(This,pVal)	\
    (This)->lpVtbl -> get_FontStrikeThru(This,pVal)

#define INSComDlg_put_FontStrikeThru(This,newVal)	\
    (This)->lpVtbl -> put_FontStrikeThru(This,newVal)

#define INSComDlg_get_FontUnderLine(This,pVal)	\
    (This)->lpVtbl -> get_FontUnderLine(This,pVal)

#define INSComDlg_put_FontUnderLine(This,newVal)	\
    (This)->lpVtbl -> put_FontUnderLine(This,newVal)

#define INSComDlg_get_Min(This,pVal)	\
    (This)->lpVtbl -> get_Min(This,pVal)

#define INSComDlg_put_Min(This,newVal)	\
    (This)->lpVtbl -> put_Min(This,newVal)

#define INSComDlg_get_Max(This,pVal)	\
    (This)->lpVtbl -> get_Max(This,pVal)

#define INSComDlg_put_Max(This,newVal)	\
    (This)->lpVtbl -> put_Max(This,newVal)

#define INSComDlg_get_CancelError(This,pVal)	\
    (This)->lpVtbl -> get_CancelError(This,pVal)

#define INSComDlg_put_CancelError(This,newVal)	\
    (This)->lpVtbl -> put_CancelError(This,newVal)

#define INSComDlg_get_FilterIndex(This,pVal)	\
    (This)->lpVtbl -> get_FilterIndex(This,pVal)

#define INSComDlg_put_FilterIndex(This,newVal)	\
    (This)->lpVtbl -> put_FilterIndex(This,newVal)

#define INSComDlg_get_FontSize(This,pVal)	\
    (This)->lpVtbl -> get_FontSize(This,pVal)

#define INSComDlg_put_FontSize(This,newVal)	\
    (This)->lpVtbl -> put_FontSize(This,newVal)

#define INSComDlg_get_FileTitle(This,pVal)	\
    (This)->lpVtbl -> get_FileTitle(This,pVal)

#define INSComDlg_put_FileTitle(This,newVal)	\
    (This)->lpVtbl -> put_FileTitle(This,newVal)

#define INSComDlg_ShowOpen(This,pbResult)	\
    (This)->lpVtbl -> ShowOpen(This,pbResult)

#define INSComDlg_ShowSave(This,pbResult)	\
    (This)->lpVtbl -> ShowSave(This,pbResult)

#define INSComDlg_ShowColor(This,pbResult)	\
    (This)->lpVtbl -> ShowColor(This,pbResult)

#define INSComDlg_ShowFont(This,pbResult)	\
    (This)->lpVtbl -> ShowFont(This,pbResult)

#define INSComDlg_get_Charset(This,pVal)	\
    (This)->lpVtbl -> get_Charset(This,pVal)

#define INSComDlg_put_Charset(This,newVal)	\
    (This)->lpVtbl -> put_Charset(This,newVal)

#define INSComDlg_get_Action(This,pVal)	\
    (This)->lpVtbl -> get_Action(This,pVal)

#define INSComDlg_put_Action(This,newVal)	\
    (This)->lpVtbl -> put_Action(This,newVal)

#define INSComDlg_get_FileNames(This,pVal)	\
    (This)->lpVtbl -> get_FileNames(This,pVal)

#define INSComDlg_Reset(This,vAction)	\
    (This)->lpVtbl -> Reset(This,vAction)

#define INSComDlg_get_CustomColors(This,index,pVal)	\
    (This)->lpVtbl -> get_CustomColors(This,index,pVal)

#define INSComDlg_put_CustomColors(This,index,newVal)	\
    (This)->lpVtbl -> put_CustomColors(This,index,newVal)

#define INSComDlg_get_IsPocketPC(This,pVal)	\
    (This)->lpVtbl -> get_IsPocketPC(This,pVal)

#define INSComDlg_get_HelpFile(This,pVal)	\
    (This)->lpVtbl -> get_HelpFile(This,pVal)

#define INSComDlg_put_HelpFile(This,newVal)	\
    (This)->lpVtbl -> put_HelpFile(This,newVal)

#define INSComDlg_get_HelpCommand(This,pVal)	\
    (This)->lpVtbl -> get_HelpCommand(This,pVal)

#define INSComDlg_put_HelpCommand(This,newVal)	\
    (This)->lpVtbl -> put_HelpCommand(This,newVal)

#define INSComDlg_get_HelpContext(This,pVal)	\
    (This)->lpVtbl -> get_HelpContext(This,pVal)

#define INSComDlg_put_HelpContext(This,newVal)	\
    (This)->lpVtbl -> put_HelpContext(This,newVal)

#define INSComDlg_get_HelpKey(This,pVal)	\
    (This)->lpVtbl -> get_HelpKey(This,pVal)

#define INSComDlg_put_HelpKey(This,newVal)	\
    (This)->lpVtbl -> put_HelpKey(This,newVal)

#define INSComDlg_ShowHelp(This)	\
    (This)->lpVtbl -> ShowHelp(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FileName_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FileName_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_FileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_DialogTitle_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_DialogTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_DialogTitle_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_DialogTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Filter_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Filter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_Filter_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_Filter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_DefaultExt_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_DefaultExt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_DefaultExt_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_DefaultExt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_InitDir_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_InitDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_InitDir_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_InitDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Color_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Color_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_Color_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSComDlg_put_Color_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Flags_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ INSComDlgFlags __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FontName_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FontName_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FontBold_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FontBold_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlg_put_FontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FontItalic_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FontItalic_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlg_put_FontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FontStrikeThru_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FontStrikeThru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FontStrikeThru_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlg_put_FontStrikeThru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FontUnderLine_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FontUnderLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FontUnderLine_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlg_put_FontUnderLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Min_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Min_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_Min_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSComDlg_put_Min_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Max_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Max_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_Max_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSComDlg_put_Max_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_CancelError_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_CancelError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_CancelError_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSComDlg_put_CancelError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FilterIndex_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FilterIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FilterIndex_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSComDlg_put_FilterIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FontSize_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FontSize_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB INSComDlg_put_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FileTitle_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FileTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_FileTitle_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_FileTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlg_ShowOpen_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);


void __RPC_STUB INSComDlg_ShowOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlg_ShowSave_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);


void __RPC_STUB INSComDlg_ShowSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlg_ShowColor_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);


void __RPC_STUB INSComDlg_ShowColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlg_ShowFont_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbResult);


void __RPC_STUB INSComDlg_ShowFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Charset_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Charset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_Charset_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSComDlg_put_Charset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_Action_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_Action_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_Action_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSComDlg_put_Action_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_FileNames_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ IComDlgMiniEnum __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_FileNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlg_Reset_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [optional][in] */ VARIANT vAction);


void __RPC_STUB INSComDlg_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_CustomColors_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_CustomColors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_CustomColors_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSComDlg_put_CustomColors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_IsPocketPC_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_IsPocketPC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_HelpFile_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_HelpFile_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_HelpCommand_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_HelpCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_HelpCommand_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSComDlg_put_HelpCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_HelpContext_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_HelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_HelpContext_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSComDlg_put_HelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComDlg_get_HelpKey_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSComDlg_get_HelpKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSComDlg_put_HelpKey_Proxy( 
    INSComDlg __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSComDlg_put_HelpKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSComDlg_ShowHelp_Proxy( 
    INSComDlg __RPC_FAR * This);


void __RPC_STUB INSComDlg_ShowHelp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSComDlg_INTERFACE_DEFINED__ */



#ifndef __NSBComDlgLib_LIBRARY_DEFINED__
#define __NSBComDlgLib_LIBRARY_DEFINED__

/* library NSBComDlgLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NSBComDlgLib;

EXTERN_C const CLSID CLSID_NSComDlg;

#ifdef __cplusplus

class DECLSPEC_UUID("9DF344D4-66FB-4660-A569-AC8586CFE9FF")
NSComDlg;
#endif

EXTERN_C const CLSID CLSID_NSComDlgFlags;

#ifdef __cplusplus

class DECLSPEC_UUID("772336BC-25F1-4EC5-A79C-605960D277E6")
NSComDlgFlags;
#endif

EXTERN_C const CLSID CLSID_ComDlgMiniEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("5E1D838C-8B6B-492B-9C44-076B1357C934")
ComDlgMiniEnum;
#endif
#endif /* __NSBComDlgLib_LIBRARY_DEFINED__ */

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


