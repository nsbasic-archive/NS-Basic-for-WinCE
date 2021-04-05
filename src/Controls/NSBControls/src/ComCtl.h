/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Dec 05 14:51:46 2006
 */
/* Compiler settings for E:\NSBCE7\Controls\NSBControls\src\ComCtl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __ComCtl_h__
#define __ComCtl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __INSListItem_FWD_DEFINED__
#define __INSListItem_FWD_DEFINED__
typedef interface INSListItem INSListItem;
#endif 	/* __INSListItem_FWD_DEFINED__ */


#ifndef __INSListView_FWD_DEFINED__
#define __INSListView_FWD_DEFINED__
typedef interface INSListView INSListView;
#endif 	/* __INSListView_FWD_DEFINED__ */


#ifndef __INSColumnItems_FWD_DEFINED__
#define __INSColumnItems_FWD_DEFINED__
typedef interface INSColumnItems INSColumnItems;
#endif 	/* __INSColumnItems_FWD_DEFINED__ */


#ifndef __INSComCtlInt_FWD_DEFINED__
#define __INSComCtlInt_FWD_DEFINED__
typedef interface INSComCtlInt INSComCtlInt;
#endif 	/* __INSComCtlInt_FWD_DEFINED__ */


#ifndef __INSComCtlColl_FWD_DEFINED__
#define __INSComCtlColl_FWD_DEFINED__
typedef interface INSComCtlColl INSComCtlColl;
#endif 	/* __INSComCtlColl_FWD_DEFINED__ */


#ifndef __INSListSubItem_FWD_DEFINED__
#define __INSListSubItem_FWD_DEFINED__
typedef interface INSListSubItem INSListSubItem;
#endif 	/* __INSListSubItem_FWD_DEFINED__ */


#ifndef __INSListSubItemsInt_FWD_DEFINED__
#define __INSListSubItemsInt_FWD_DEFINED__
typedef interface INSListSubItemsInt INSListSubItemsInt;
#endif 	/* __INSListSubItemsInt_FWD_DEFINED__ */


#ifndef __INSFont_FWD_DEFINED__
#define __INSFont_FWD_DEFINED__
typedef interface INSFont INSFont;
#endif 	/* __INSFont_FWD_DEFINED__ */


#ifndef __INSListSubItems_FWD_DEFINED__
#define __INSListSubItems_FWD_DEFINED__
typedef interface INSListSubItems INSListSubItems;
#endif 	/* __INSListSubItems_FWD_DEFINED__ */


#ifndef __INSBListImage_FWD_DEFINED__
#define __INSBListImage_FWD_DEFINED__
typedef interface INSBListImage INSBListImage;
#endif 	/* __INSBListImage_FWD_DEFINED__ */


#ifndef __INSBImageList_FWD_DEFINED__
#define __INSBImageList_FWD_DEFINED__
typedef interface INSBImageList INSBImageList;
#endif 	/* __INSBImageList_FWD_DEFINED__ */


#ifndef __INSColumnHeader_FWD_DEFINED__
#define __INSColumnHeader_FWD_DEFINED__
typedef interface INSColumnHeader INSColumnHeader;
#endif 	/* __INSColumnHeader_FWD_DEFINED__ */


#ifndef __INSColumnHeaders_FWD_DEFINED__
#define __INSColumnHeaders_FWD_DEFINED__
typedef interface INSColumnHeaders INSColumnHeaders;
#endif 	/* __INSColumnHeaders_FWD_DEFINED__ */


#ifndef __INSListItems_FWD_DEFINED__
#define __INSListItems_FWD_DEFINED__
typedef interface INSListItems INSListItems;
#endif 	/* __INSListItems_FWD_DEFINED__ */


#ifndef __INSListViewEvent_FWD_DEFINED__
#define __INSListViewEvent_FWD_DEFINED__
typedef interface INSListViewEvent INSListViewEvent;
#endif 	/* __INSListViewEvent_FWD_DEFINED__ */


#ifndef ___INSListViewEvents_FWD_DEFINED__
#define ___INSListViewEvents_FWD_DEFINED__
typedef interface _INSListViewEvents _INSListViewEvents;
#endif 	/* ___INSListViewEvents_FWD_DEFINED__ */


#ifndef __NSListView_FWD_DEFINED__
#define __NSListView_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSListView NSListView;
#else
typedef struct NSListView NSListView;
#endif /* __cplusplus */

#endif 	/* __NSListView_FWD_DEFINED__ */


#ifndef ___INSBImageListEvents_FWD_DEFINED__
#define ___INSBImageListEvents_FWD_DEFINED__
typedef interface _INSBImageListEvents _INSBImageListEvents;
#endif 	/* ___INSBImageListEvents_FWD_DEFINED__ */


#ifndef __NSBImageList_FWD_DEFINED__
#define __NSBImageList_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSBImageList NSBImageList;
#else
typedef struct NSBImageList NSBImageList;
#endif /* __cplusplus */

#endif 	/* __NSBImageList_FWD_DEFINED__ */


#ifndef __NSBListImage_FWD_DEFINED__
#define __NSBListImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSBListImage NSBListImage;
#else
typedef struct NSBListImage NSBListImage;
#endif /* __cplusplus */

#endif 	/* __NSBListImage_FWD_DEFINED__ */


#ifndef __NSColumnHeaders_FWD_DEFINED__
#define __NSColumnHeaders_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSColumnHeaders NSColumnHeaders;
#else
typedef struct NSColumnHeaders NSColumnHeaders;
#endif /* __cplusplus */

#endif 	/* __NSColumnHeaders_FWD_DEFINED__ */


#ifndef __NSColumnHeader_FWD_DEFINED__
#define __NSColumnHeader_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSColumnHeader NSColumnHeader;
#else
typedef struct NSColumnHeader NSColumnHeader;
#endif /* __cplusplus */

#endif 	/* __NSColumnHeader_FWD_DEFINED__ */


#ifndef __NSListItems_FWD_DEFINED__
#define __NSListItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSListItems NSListItems;
#else
typedef struct NSListItems NSListItems;
#endif /* __cplusplus */

#endif 	/* __NSListItems_FWD_DEFINED__ */


#ifndef __NSListItem_FWD_DEFINED__
#define __NSListItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSListItem NSListItem;
#else
typedef struct NSListItem NSListItem;
#endif /* __cplusplus */

#endif 	/* __NSListItem_FWD_DEFINED__ */


#ifndef __NSListSubItems_FWD_DEFINED__
#define __NSListSubItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSListSubItems NSListSubItems;
#else
typedef struct NSListSubItems NSListSubItems;
#endif /* __cplusplus */

#endif 	/* __NSListSubItems_FWD_DEFINED__ */


#ifndef __NSListSubItem_FWD_DEFINED__
#define __NSListSubItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSListSubItem NSListSubItem;
#else
typedef struct NSListSubItem NSListSubItem;
#endif /* __cplusplus */

#endif 	/* __NSListSubItem_FWD_DEFINED__ */


#ifndef __NSListViewEvent_FWD_DEFINED__
#define __NSListViewEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSListViewEvent NSListViewEvent;
#else
typedef struct NSListViewEvent NSListViewEvent;
#endif /* __cplusplus */

#endif 	/* __NSListViewEvent_FWD_DEFINED__ */


#ifndef ___INSFontEvents_FWD_DEFINED__
#define ___INSFontEvents_FWD_DEFINED__
typedef interface _INSFontEvents _INSFontEvents;
#endif 	/* ___INSFontEvents_FWD_DEFINED__ */


#ifndef __NSFont_FWD_DEFINED__
#define __NSFont_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSFont NSFont;
#else
typedef struct NSFont NSFont;
#endif /* __cplusplus */

#endif 	/* __NSFont_FWD_DEFINED__ */


#ifndef __NSColumnItems_FWD_DEFINED__
#define __NSColumnItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSColumnItems NSColumnItems;
#else
typedef struct NSColumnItems NSColumnItems;
#endif /* __cplusplus */

#endif 	/* __NSColumnItems_FWD_DEFINED__ */


#ifndef __NSComCtlColl_FWD_DEFINED__
#define __NSComCtlColl_FWD_DEFINED__

#ifdef __cplusplus
typedef class NSComCtlColl NSComCtlColl;
#else
typedef struct NSComCtlColl NSComCtlColl;
#endif /* __cplusplus */

#endif 	/* __NSComCtlColl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __NSBControlsLib_LIBRARY_DEFINED__
#define __NSBControlsLib_LIBRARY_DEFINED__

/* library NSBControlsLib */
/* [helpstring][version][uuid] */ 

typedef /* [public][public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ComCtl_0000_0001
    {	NSLVColumnLeft	= 0,
	NSLVColumnRight	= 1,
	NSLVColumnCenter	= 2
    }	NSListColumnAlignment;

typedef /* [public][public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ComCtl_0000_0002
    {	lvwIcon	= 0,
	lvwSmallIcon	= 2,
	lvwList	= 3,
	lvwReport	= 1
    }	NSListViewConstants;

typedef /* [public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ComCtl_0000_0003
    {	lvwFindExact	= 0,
	lvwFindPartial	= 1,
	lvwFindSubstring	= 2
    }	NSListViewFindConstants;

typedef /* [public][public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ComCtl_0000_0004
    {	lvwAscending	= 0,
	lvwDescending	= 1
    }	NSListSortOrderConstants;

typedef /* [public][public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ComCtl_0000_0005
    {	lvwTextSort	= 0,
	lvwNumSort	= 1,
	lvwTextSortByTag	= 2,
	lvwNumSortByTag	= 3
    }	NSListSortTypeConstants;

typedef /* [public][public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ComCtl_0000_0006
    {	lvwNone	= 0,
	lvwAutoLeft	= 1,
	lvwAutoTop	= 2
    }	NSListArrangeConstants;





EXTERN_C const IID LIBID_NSBControlsLib;

#ifndef __INSListItem_INTERFACE_DEFINED__
#define __INSListItem_INTERFACE_DEFINED__

/* interface INSListItem */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSListItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F4A3DB6-FC84-41CA-9B3F-FDDEEDD190CB")
    INSListItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Key( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Selected( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Selected( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Indent( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Indent( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Icon( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Icon( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubItems( 
            /* [retval][out] */ INSListSubItems __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Checked( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Checked( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartLabelEdit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnsureVisible( 
            /* [defaultvalue][in] */ VARIANT_BOOL bPartialOk = 0) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListItem( 
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsSubItem( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_X( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_X( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Y( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Y( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSListItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Key )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Key )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Tag )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Selected )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Selected )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Indent )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Indent )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Icon )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Icon )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubItems )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ INSListSubItems __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Checked )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Checked )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartLabelEdit )( 
            INSListItem __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnsureVisible )( 
            INSListItem __RPC_FAR * This,
            /* [defaultvalue][in] */ VARIANT_BOOL bPartialOk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListItem )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsSubItem )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_X )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_X )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Y )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Y )( 
            INSListItem __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Index )( 
            INSListItem __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        END_INTERFACE
    } INSListItemVtbl;

    interface INSListItem
    {
        CONST_VTBL struct INSListItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSListItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSListItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSListItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSListItem_get_Key(This,pVal)	\
    (This)->lpVtbl -> get_Key(This,pVal)

#define INSListItem_put_Key(This,newVal)	\
    (This)->lpVtbl -> put_Key(This,newVal)

#define INSListItem_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define INSListItem_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define INSListItem_putref_Tag(This,newVal)	\
    (This)->lpVtbl -> putref_Tag(This,newVal)

#define INSListItem_get_Text(This,pVal)	\
    (This)->lpVtbl -> get_Text(This,pVal)

#define INSListItem_put_Text(This,newVal)	\
    (This)->lpVtbl -> put_Text(This,newVal)

#define INSListItem_get_Selected(This,pVal)	\
    (This)->lpVtbl -> get_Selected(This,pVal)

#define INSListItem_put_Selected(This,newVal)	\
    (This)->lpVtbl -> put_Selected(This,newVal)

#define INSListItem_get_Indent(This,pVal)	\
    (This)->lpVtbl -> get_Indent(This,pVal)

#define INSListItem_put_Indent(This,newVal)	\
    (This)->lpVtbl -> put_Indent(This,newVal)

#define INSListItem_get_Icon(This,pVal)	\
    (This)->lpVtbl -> get_Icon(This,pVal)

#define INSListItem_put_Icon(This,newVal)	\
    (This)->lpVtbl -> put_Icon(This,newVal)

#define INSListItem_get_SubItems(This,pVal)	\
    (This)->lpVtbl -> get_SubItems(This,pVal)

#define INSListItem_get_Checked(This,pVal)	\
    (This)->lpVtbl -> get_Checked(This,pVal)

#define INSListItem_put_Checked(This,newVal)	\
    (This)->lpVtbl -> put_Checked(This,newVal)

#define INSListItem_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#define INSListItem_StartLabelEdit(This)	\
    (This)->lpVtbl -> StartLabelEdit(This)

#define INSListItem_EnsureVisible(This,bPartialOk)	\
    (This)->lpVtbl -> EnsureVisible(This,bPartialOk)

#define INSListItem_get_ListItem(This,pVal)	\
    (This)->lpVtbl -> get_ListItem(This,pVal)

#define INSListItem_get_IsSubItem(This,pVal)	\
    (This)->lpVtbl -> get_IsSubItem(This,pVal)

#define INSListItem_get_X(This,pVal)	\
    (This)->lpVtbl -> get_X(This,pVal)

#define INSListItem_put_X(This,newVal)	\
    (This)->lpVtbl -> put_X(This,newVal)

#define INSListItem_get_Y(This,pVal)	\
    (This)->lpVtbl -> get_Y(This,pVal)

#define INSListItem_put_Y(This,newVal)	\
    (This)->lpVtbl -> put_Y(This,newVal)

#define INSListItem_get_Index(This,pVal)	\
    (This)->lpVtbl -> get_Index(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Key_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Key_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSListItem_put_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Tag_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Tag_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListItem_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListItem_putref_Tag_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListItem_putref_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Text_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Text_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSListItem_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Selected_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Selected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Selected_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListItem_put_Selected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Indent_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Indent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Indent_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListItem_put_Indent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Icon_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Icon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Icon_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListItem_put_Icon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_SubItems_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ INSListSubItems __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_SubItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Checked_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Checked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Checked_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListItem_put_Checked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_ListView_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListItem_StartLabelEdit_Proxy( 
    INSListItem __RPC_FAR * This);


void __RPC_STUB INSListItem_StartLabelEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListItem_EnsureVisible_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [defaultvalue][in] */ VARIANT_BOOL bPartialOk);


void __RPC_STUB INSListItem_EnsureVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_ListItem_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_ListItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_IsSubItem_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_IsSubItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_X_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_X_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListItem_put_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Y_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListItem_put_Y_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListItem_put_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItem_get_Index_Proxy( 
    INSListItem __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListItem_get_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListItem_INTERFACE_DEFINED__ */


#ifndef __INSListView_INTERFACE_DEFINED__
#define __INSListView_INTERFACE_DEFINED__

/* interface INSListView */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSListView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D80F92F-3CBB-4EBE-A3B2-88B5F2E3C77E")
    INSListView : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR strCaption) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *pstrCaption) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindItems( 
            /* [in] */ BSTR Text,
            /* [defaultvalue][in] */ VARIANT_BOOL bSubItems,
            /* [defaultvalue][in] */ VARIANT_BOOL bTags,
            /* [defaultvalue][in] */ NSListViewFindConstants nPartial,
            /* [retval][out] */ INSComCtlColl __RPC_FAR *__RPC_FAR *ppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnSelectAll( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectedItems( 
            /* [retval][out] */ INSComCtlColl __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Columns( 
            /* [retval][out] */ INSColumnHeaders __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFocus( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ long __RPC_FAR *phwnd) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnHeaders( 
            /* [retval][out] */ INSColumnHeaders __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_View( 
            /* [retval][out] */ NSListViewConstants __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_View( 
            /* [in] */ NSListViewConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListItems( 
            /* [retval][out] */ INSListItems __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HideSelection( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HideSelection( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MultiSelect( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MultiSelect( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SortOrder( 
            /* [retval][out] */ NSListSortOrderConstants __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SortOrder( 
            /* [in] */ NSListSortOrderConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Arrange( 
            /* [retval][out] */ NSListArrangeConstants __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Arrange( 
            /* [in] */ NSListArrangeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HideColumnHeaders( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HideColumnHeaders( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LabelEdit( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LabelEdit( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LabelWrap( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LabelWrap( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sorted( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sorted( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Checkboxes( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Checkboxes( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FullRowSelect( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FullRowSelect( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GridLines( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GridLines( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowColumnReorder( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowColumnReorder( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubItemImages( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubItemImages( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TrackSelect( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TrackSelect( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UnderlineCold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UnderlineCold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UnderlineHot( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UnderlineHot( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SmallIcons( 
            /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_SmallIcons( 
            /* [in] */ INSBImageList __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Icons( 
            /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Icons( 
            /* [in] */ INSBImageList __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateIcons( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SortHeaders( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SortHeaders( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SortKey( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SortKey( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomSort( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomSort( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnHeaderIcons( 
            /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_ColumnHeaderIcons( 
            /* [in] */ INSBImageList __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextBackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextBackColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ INSFont __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ INSFont __RPC_FAR *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListView __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSListView __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSListView __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSListView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSListView __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            INSListView __RPC_FAR * This,
            /* [in] */ BSTR strCaption);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pstrCaption);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindItems )( 
            INSListView __RPC_FAR * This,
            /* [in] */ BSTR Text,
            /* [defaultvalue][in] */ VARIANT_BOOL bSubItems,
            /* [defaultvalue][in] */ VARIANT_BOOL bTags,
            /* [defaultvalue][in] */ NSListViewFindConstants nPartial,
            /* [retval][out] */ INSComCtlColl __RPC_FAR *__RPC_FAR *ppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnSelectAll )( 
            INSListView __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SelectedItems )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSComCtlColl __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Columns )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSColumnHeaders __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFocus )( 
            INSListView __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            INSListView __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Height )( 
            INSListView __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Top )( 
            INSListView __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Left )( 
            INSListView __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Window )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *phwnd);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TabStop )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TabStop )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColumnHeaders )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSColumnHeaders __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_View )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ NSListViewConstants __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_View )( 
            INSListView __RPC_FAR * This,
            /* [in] */ NSListViewConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListItems )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSListItems __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HideSelection )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HideSelection )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MultiSelect )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MultiSelect )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SortOrder )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ NSListSortOrderConstants __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SortOrder )( 
            INSListView __RPC_FAR * This,
            /* [in] */ NSListSortOrderConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Arrange )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ NSListArrangeConstants __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Arrange )( 
            INSListView __RPC_FAR * This,
            /* [in] */ NSListArrangeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HideColumnHeaders )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HideColumnHeaders )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LabelEdit )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LabelEdit )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LabelWrap )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LabelWrap )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Sorted )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Sorted )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Checkboxes )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Checkboxes )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FullRowSelect )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FullRowSelect )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridLines )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridLines )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllowColumnReorder )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AllowColumnReorder )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubItemImages )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubItemImages )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TrackSelect )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TrackSelect )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UnderlineCold )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UnderlineCold )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UnderlineHot )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UnderlineHot )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SmallIcons )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_SmallIcons )( 
            INSListView __RPC_FAR * This,
            /* [in] */ INSBImageList __RPC_FAR *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Icons )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Icons )( 
            INSListView __RPC_FAR * This,
            /* [in] */ INSBImageList __RPC_FAR *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateIcons )( 
            INSListView __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SortHeaders )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SortHeaders )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SortKey )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SortKey )( 
            INSListView __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CustomSort )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CustomSort )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColumnHeaderIcons )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_ColumnHeaderIcons )( 
            INSListView __RPC_FAR * This,
            /* [in] */ INSBImageList __RPC_FAR *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Tag )( 
            INSListView __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            INSListView __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TextBackColor )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TextBackColor )( 
            INSListView __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TextColor )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TextColor )( 
            INSListView __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Font )( 
            INSListView __RPC_FAR * This,
            /* [retval][out] */ INSFont __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Font )( 
            INSListView __RPC_FAR * This,
            /* [in] */ INSFont __RPC_FAR *newVal);
        
        END_INTERFACE
    } INSListViewVtbl;

    interface INSListView
    {
        CONST_VTBL struct INSListViewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListView_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSListView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSListView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSListView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSListView_put_Caption(This,strCaption)	\
    (This)->lpVtbl -> put_Caption(This,strCaption)

#define INSListView_get_Caption(This,pstrCaption)	\
    (This)->lpVtbl -> get_Caption(This,pstrCaption)

#define INSListView_put_Enabled(This,vbool)	\
    (This)->lpVtbl -> put_Enabled(This,vbool)

#define INSListView_get_Enabled(This,pbool)	\
    (This)->lpVtbl -> get_Enabled(This,pbool)

#define INSListView_FindItems(This,Text,bSubItems,bTags,nPartial,ppObj)	\
    (This)->lpVtbl -> FindItems(This,Text,bSubItems,bTags,nPartial,ppObj)

#define INSListView_UnSelectAll(This)	\
    (This)->lpVtbl -> UnSelectAll(This)

#define INSListView_get_SelectedItems(This,pVal)	\
    (This)->lpVtbl -> get_SelectedItems(This,pVal)

#define INSListView_get_Columns(This,pVal)	\
    (This)->lpVtbl -> get_Columns(This,pVal)

#define INSListView_SetFocus(This)	\
    (This)->lpVtbl -> SetFocus(This)

#define INSListView_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)

#define INSListView_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)

#define INSListView_get_Height(This,pVal)	\
    (This)->lpVtbl -> get_Height(This,pVal)

#define INSListView_put_Height(This,newVal)	\
    (This)->lpVtbl -> put_Height(This,newVal)

#define INSListView_get_Top(This,pVal)	\
    (This)->lpVtbl -> get_Top(This,pVal)

#define INSListView_put_Top(This,newVal)	\
    (This)->lpVtbl -> put_Top(This,newVal)

#define INSListView_get_Left(This,pVal)	\
    (This)->lpVtbl -> get_Left(This,pVal)

#define INSListView_put_Left(This,newVal)	\
    (This)->lpVtbl -> put_Left(This,newVal)

#define INSListView_get_Visible(This,pVal)	\
    (This)->lpVtbl -> get_Visible(This,pVal)

#define INSListView_put_Visible(This,newVal)	\
    (This)->lpVtbl -> put_Visible(This,newVal)

#define INSListView_get_Window(This,phwnd)	\
    (This)->lpVtbl -> get_Window(This,phwnd)

#define INSListView_put_TabStop(This,vbool)	\
    (This)->lpVtbl -> put_TabStop(This,vbool)

#define INSListView_get_TabStop(This,pbool)	\
    (This)->lpVtbl -> get_TabStop(This,pbool)

#define INSListView_get_ColumnHeaders(This,pVal)	\
    (This)->lpVtbl -> get_ColumnHeaders(This,pVal)

#define INSListView_get_View(This,pVal)	\
    (This)->lpVtbl -> get_View(This,pVal)

#define INSListView_put_View(This,newVal)	\
    (This)->lpVtbl -> put_View(This,newVal)

#define INSListView_get_ListItems(This,pVal)	\
    (This)->lpVtbl -> get_ListItems(This,pVal)

#define INSListView_get_HideSelection(This,pVal)	\
    (This)->lpVtbl -> get_HideSelection(This,pVal)

#define INSListView_put_HideSelection(This,newVal)	\
    (This)->lpVtbl -> put_HideSelection(This,newVal)

#define INSListView_get_MultiSelect(This,pVal)	\
    (This)->lpVtbl -> get_MultiSelect(This,pVal)

#define INSListView_put_MultiSelect(This,newVal)	\
    (This)->lpVtbl -> put_MultiSelect(This,newVal)

#define INSListView_get_SortOrder(This,pVal)	\
    (This)->lpVtbl -> get_SortOrder(This,pVal)

#define INSListView_put_SortOrder(This,newVal)	\
    (This)->lpVtbl -> put_SortOrder(This,newVal)

#define INSListView_get_Arrange(This,pVal)	\
    (This)->lpVtbl -> get_Arrange(This,pVal)

#define INSListView_put_Arrange(This,newVal)	\
    (This)->lpVtbl -> put_Arrange(This,newVal)

#define INSListView_get_HideColumnHeaders(This,pVal)	\
    (This)->lpVtbl -> get_HideColumnHeaders(This,pVal)

#define INSListView_put_HideColumnHeaders(This,newVal)	\
    (This)->lpVtbl -> put_HideColumnHeaders(This,newVal)

#define INSListView_get_LabelEdit(This,pVal)	\
    (This)->lpVtbl -> get_LabelEdit(This,pVal)

#define INSListView_put_LabelEdit(This,newVal)	\
    (This)->lpVtbl -> put_LabelEdit(This,newVal)

#define INSListView_get_LabelWrap(This,pVal)	\
    (This)->lpVtbl -> get_LabelWrap(This,pVal)

#define INSListView_put_LabelWrap(This,newVal)	\
    (This)->lpVtbl -> put_LabelWrap(This,newVal)

#define INSListView_get_Sorted(This,pVal)	\
    (This)->lpVtbl -> get_Sorted(This,pVal)

#define INSListView_put_Sorted(This,newVal)	\
    (This)->lpVtbl -> put_Sorted(This,newVal)

#define INSListView_get_Checkboxes(This,pVal)	\
    (This)->lpVtbl -> get_Checkboxes(This,pVal)

#define INSListView_put_Checkboxes(This,newVal)	\
    (This)->lpVtbl -> put_Checkboxes(This,newVal)

#define INSListView_get_FullRowSelect(This,pVal)	\
    (This)->lpVtbl -> get_FullRowSelect(This,pVal)

#define INSListView_put_FullRowSelect(This,newVal)	\
    (This)->lpVtbl -> put_FullRowSelect(This,newVal)

#define INSListView_get_GridLines(This,pVal)	\
    (This)->lpVtbl -> get_GridLines(This,pVal)

#define INSListView_put_GridLines(This,newVal)	\
    (This)->lpVtbl -> put_GridLines(This,newVal)

#define INSListView_get_AllowColumnReorder(This,pVal)	\
    (This)->lpVtbl -> get_AllowColumnReorder(This,pVal)

#define INSListView_put_AllowColumnReorder(This,newVal)	\
    (This)->lpVtbl -> put_AllowColumnReorder(This,newVal)

#define INSListView_get_SubItemImages(This,pVal)	\
    (This)->lpVtbl -> get_SubItemImages(This,pVal)

#define INSListView_put_SubItemImages(This,newVal)	\
    (This)->lpVtbl -> put_SubItemImages(This,newVal)

#define INSListView_get_TrackSelect(This,pVal)	\
    (This)->lpVtbl -> get_TrackSelect(This,pVal)

#define INSListView_put_TrackSelect(This,newVal)	\
    (This)->lpVtbl -> put_TrackSelect(This,newVal)

#define INSListView_get_UnderlineCold(This,pVal)	\
    (This)->lpVtbl -> get_UnderlineCold(This,pVal)

#define INSListView_put_UnderlineCold(This,newVal)	\
    (This)->lpVtbl -> put_UnderlineCold(This,newVal)

#define INSListView_get_UnderlineHot(This,pVal)	\
    (This)->lpVtbl -> get_UnderlineHot(This,pVal)

#define INSListView_put_UnderlineHot(This,newVal)	\
    (This)->lpVtbl -> put_UnderlineHot(This,newVal)

#define INSListView_get_SmallIcons(This,pVal)	\
    (This)->lpVtbl -> get_SmallIcons(This,pVal)

#define INSListView_putref_SmallIcons(This,newVal)	\
    (This)->lpVtbl -> putref_SmallIcons(This,newVal)

#define INSListView_get_Icons(This,pVal)	\
    (This)->lpVtbl -> get_Icons(This,pVal)

#define INSListView_putref_Icons(This,newVal)	\
    (This)->lpVtbl -> putref_Icons(This,newVal)

#define INSListView_UpdateIcons(This)	\
    (This)->lpVtbl -> UpdateIcons(This)

#define INSListView_get_SortHeaders(This,pVal)	\
    (This)->lpVtbl -> get_SortHeaders(This,pVal)

#define INSListView_put_SortHeaders(This,newVal)	\
    (This)->lpVtbl -> put_SortHeaders(This,newVal)

#define INSListView_get_SortKey(This,pVal)	\
    (This)->lpVtbl -> get_SortKey(This,pVal)

#define INSListView_put_SortKey(This,newVal)	\
    (This)->lpVtbl -> put_SortKey(This,newVal)

#define INSListView_get_CustomSort(This,pVal)	\
    (This)->lpVtbl -> get_CustomSort(This,pVal)

#define INSListView_put_CustomSort(This,newVal)	\
    (This)->lpVtbl -> put_CustomSort(This,newVal)

#define INSListView_get_ColumnHeaderIcons(This,pVal)	\
    (This)->lpVtbl -> get_ColumnHeaderIcons(This,pVal)

#define INSListView_putref_ColumnHeaderIcons(This,newVal)	\
    (This)->lpVtbl -> putref_ColumnHeaderIcons(This,newVal)

#define INSListView_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define INSListView_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define INSListView_putref_Tag(This,newVal)	\
    (This)->lpVtbl -> putref_Tag(This,newVal)

#define INSListView_get_BackColor(This,pVal)	\
    (This)->lpVtbl -> get_BackColor(This,pVal)

#define INSListView_put_BackColor(This,newVal)	\
    (This)->lpVtbl -> put_BackColor(This,newVal)

#define INSListView_get_TextBackColor(This,pVal)	\
    (This)->lpVtbl -> get_TextBackColor(This,pVal)

#define INSListView_put_TextBackColor(This,newVal)	\
    (This)->lpVtbl -> put_TextBackColor(This,newVal)

#define INSListView_get_TextColor(This,pVal)	\
    (This)->lpVtbl -> get_TextColor(This,pVal)

#define INSListView_put_TextColor(This,newVal)	\
    (This)->lpVtbl -> put_TextColor(This,newVal)

#define INSListView_get_Font(This,pVal)	\
    (This)->lpVtbl -> get_Font(This,pVal)

#define INSListView_putref_Font(This,newVal)	\
    (This)->lpVtbl -> putref_Font(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Caption_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ BSTR strCaption);


void __RPC_STUB INSListView_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Caption_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pstrCaption);


void __RPC_STUB INSListView_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Enabled_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB INSListView_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Enabled_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB INSListView_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListView_FindItems_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ BSTR Text,
    /* [defaultvalue][in] */ VARIANT_BOOL bSubItems,
    /* [defaultvalue][in] */ VARIANT_BOOL bTags,
    /* [defaultvalue][in] */ NSListViewFindConstants nPartial,
    /* [retval][out] */ INSComCtlColl __RPC_FAR *__RPC_FAR *ppObj);


void __RPC_STUB INSListView_FindItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListView_UnSelectAll_Proxy( 
    INSListView __RPC_FAR * This);


void __RPC_STUB INSListView_UnSelectAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_SelectedItems_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSComCtlColl __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_SelectedItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Columns_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSColumnHeaders __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Columns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListView_SetFocus_Proxy( 
    INSListView __RPC_FAR * This);


void __RPC_STUB INSListView_SetFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Width_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Width_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListView_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Height_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Height_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListView_put_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Top_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Top_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListView_put_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Left_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Left_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListView_put_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Visible_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Visible_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Window_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *phwnd);


void __RPC_STUB INSListView_get_Window_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_TabStop_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB INSListView_put_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_TabStop_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB INSListView_get_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_ColumnHeaders_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSColumnHeaders __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_ColumnHeaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_View_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ NSListViewConstants __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_View_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_View_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ NSListViewConstants newVal);


void __RPC_STUB INSListView_put_View_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_ListItems_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSListItems __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_ListItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_HideSelection_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_HideSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_HideSelection_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_HideSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_MultiSelect_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_MultiSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_MultiSelect_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_MultiSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_SortOrder_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ NSListSortOrderConstants __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_SortOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_SortOrder_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ NSListSortOrderConstants newVal);


void __RPC_STUB INSListView_put_SortOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Arrange_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ NSListArrangeConstants __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Arrange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Arrange_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ NSListArrangeConstants newVal);


void __RPC_STUB INSListView_put_Arrange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_HideColumnHeaders_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_HideColumnHeaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_HideColumnHeaders_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_HideColumnHeaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_LabelEdit_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_LabelEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_LabelEdit_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_LabelEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_LabelWrap_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_LabelWrap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_LabelWrap_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_LabelWrap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Sorted_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Sorted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Sorted_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_Sorted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Checkboxes_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Checkboxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Checkboxes_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_Checkboxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_FullRowSelect_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_FullRowSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_FullRowSelect_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_FullRowSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_GridLines_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_GridLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_GridLines_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_GridLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_AllowColumnReorder_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_AllowColumnReorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_AllowColumnReorder_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_AllowColumnReorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_SubItemImages_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_SubItemImages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_SubItemImages_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_SubItemImages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_TrackSelect_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_TrackSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_TrackSelect_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_TrackSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_UnderlineCold_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_UnderlineCold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_UnderlineCold_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_UnderlineCold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_UnderlineHot_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_UnderlineHot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_UnderlineHot_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_UnderlineHot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_SmallIcons_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_SmallIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListView_putref_SmallIcons_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ INSBImageList __RPC_FAR *newVal);


void __RPC_STUB INSListView_putref_SmallIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Icons_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Icons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListView_putref_Icons_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ INSBImageList __RPC_FAR *newVal);


void __RPC_STUB INSListView_putref_Icons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListView_UpdateIcons_Proxy( 
    INSListView __RPC_FAR * This);


void __RPC_STUB INSListView_UpdateIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_SortHeaders_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_SortHeaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_SortHeaders_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_SortHeaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_SortKey_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_SortKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_SortKey_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSListView_put_SortKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_CustomSort_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_CustomSort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_CustomSort_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListView_put_CustomSort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_ColumnHeaderIcons_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSBImageList __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_ColumnHeaderIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListView_putref_ColumnHeaderIcons_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ INSBImageList __RPC_FAR *newVal);


void __RPC_STUB INSListView_putref_ColumnHeaderIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Tag_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_Tag_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListView_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListView_putref_Tag_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListView_putref_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_BackColor_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_BackColor_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSListView_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_TextBackColor_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_TextBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_TextBackColor_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSListView_put_TextBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_TextColor_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSListView_get_TextColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListView_put_TextColor_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSListView_put_TextColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListView_get_Font_Proxy( 
    INSListView __RPC_FAR * This,
    /* [retval][out] */ INSFont __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListView_get_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListView_putref_Font_Proxy( 
    INSListView __RPC_FAR * This,
    /* [in] */ INSFont __RPC_FAR *newVal);


void __RPC_STUB INSListView_putref_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListView_INTERFACE_DEFINED__ */


#ifndef __INSColumnItems_INTERFACE_DEFINED__
#define __INSColumnItems_INTERFACE_DEFINED__

/* interface INSColumnItems */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSColumnItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BE0098C3-1034-4AC7-AFC8-1BD754460ACE")
    INSColumnItems : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSColumnItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSColumnItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSColumnItems __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSColumnItems __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSColumnItems __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSColumnItems __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSColumnItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSColumnItems __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSColumnItems __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            INSColumnItems __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            INSColumnItems __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSColumnItemsVtbl;

    interface INSColumnItems
    {
        CONST_VTBL struct INSColumnItemsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSColumnItems_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSColumnItems_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSColumnItems_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSColumnItems_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSColumnItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSColumnItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSColumnItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSColumnItems_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define INSColumnItems_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define INSColumnItems_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnItems_get_Item_Proxy( 
    INSColumnItems __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnItems_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnItems_get_Count_Proxy( 
    INSColumnItems __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSColumnItems_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnItems_get__NewEnum_Proxy( 
    INSColumnItems __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnItems_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSColumnItems_INTERFACE_DEFINED__ */


#ifndef __INSComCtlInt_INTERFACE_DEFINED__
#define __INSComCtlInt_INTERFACE_DEFINED__

/* interface INSComCtlInt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INSComCtlInt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CAD9BF99-DCFA-41bc-93D2-7CF620082FA1")
    INSComCtlInt : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NSInitialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NSTerminate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSComCtlIntVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSComCtlInt __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSComCtlInt __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSComCtlInt __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NSInitialize )( 
            INSComCtlInt __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NSTerminate )( 
            INSComCtlInt __RPC_FAR * This);
        
        END_INTERFACE
    } INSComCtlIntVtbl;

    interface INSComCtlInt
    {
        CONST_VTBL struct INSComCtlIntVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSComCtlInt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSComCtlInt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSComCtlInt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSComCtlInt_NSInitialize(This)	\
    (This)->lpVtbl -> NSInitialize(This)

#define INSComCtlInt_NSTerminate(This)	\
    (This)->lpVtbl -> NSTerminate(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INSComCtlInt_NSInitialize_Proxy( 
    INSComCtlInt __RPC_FAR * This);


void __RPC_STUB INSComCtlInt_NSInitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INSComCtlInt_NSTerminate_Proxy( 
    INSComCtlInt __RPC_FAR * This);


void __RPC_STUB INSComCtlInt_NSTerminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSComCtlInt_INTERFACE_DEFINED__ */


#ifndef __INSComCtlColl_INTERFACE_DEFINED__
#define __INSComCtlColl_INTERFACE_DEFINED__

/* interface INSComCtlColl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSComCtlColl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1E05FB74-12F4-4004-9C64-8934F903E1C2")
    INSComCtlColl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSComCtlCollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSComCtlColl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSComCtlColl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSComCtlColl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSComCtlColl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSComCtlColl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSComCtlColl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSComCtlColl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            INSComCtlColl __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSComCtlColl __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            INSComCtlColl __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSComCtlCollVtbl;

    interface INSComCtlColl
    {
        CONST_VTBL struct INSComCtlCollVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSComCtlColl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSComCtlColl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSComCtlColl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSComCtlColl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSComCtlColl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSComCtlColl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSComCtlColl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSComCtlColl_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define INSComCtlColl_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define INSComCtlColl_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComCtlColl_get_Count_Proxy( 
    INSComCtlColl __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSComCtlColl_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComCtlColl_get_Item_Proxy( 
    INSComCtlColl __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSComCtlColl_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSComCtlColl_get__NewEnum_Proxy( 
    INSComCtlColl __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSComCtlColl_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSComCtlColl_INTERFACE_DEFINED__ */


#ifndef __INSListSubItem_INTERFACE_DEFINED__
#define __INSListSubItem_INTERFACE_DEFINED__

/* interface INSListSubItem */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSListSubItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAF8890C-040A-4FED-A499-05F5061856AD")
    INSListSubItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Icon( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Icon( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Index( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE CorrectIndexIfGreater( 
            /* [in] */ long lSubIndex,
            /* [in] */ long lCorrection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListItem( 
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsSubItem( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListSubItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListSubItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListSubItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSListSubItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Icon )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Icon )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Index )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Index )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Key )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Tag )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CorrectIndexIfGreater )( 
            INSListSubItem __RPC_FAR * This,
            /* [in] */ long lSubIndex,
            /* [in] */ long lCorrection);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListItem )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsSubItem )( 
            INSListSubItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        END_INTERFACE
    } INSListSubItemVtbl;

    interface INSListSubItem
    {
        CONST_VTBL struct INSListSubItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListSubItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListSubItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListSubItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListSubItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSListSubItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSListSubItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSListSubItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSListSubItem_get_Text(This,pVal)	\
    (This)->lpVtbl -> get_Text(This,pVal)

#define INSListSubItem_put_Text(This,newVal)	\
    (This)->lpVtbl -> put_Text(This,newVal)

#define INSListSubItem_get_Icon(This,pVal)	\
    (This)->lpVtbl -> get_Icon(This,pVal)

#define INSListSubItem_put_Icon(This,newVal)	\
    (This)->lpVtbl -> put_Icon(This,newVal)

#define INSListSubItem_get_Index(This,pVal)	\
    (This)->lpVtbl -> get_Index(This,pVal)

#define INSListSubItem_put_Index(This,newVal)	\
    (This)->lpVtbl -> put_Index(This,newVal)

#define INSListSubItem_get_Key(This,pVal)	\
    (This)->lpVtbl -> get_Key(This,pVal)

#define INSListSubItem_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define INSListSubItem_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define INSListSubItem_putref_Tag(This,newVal)	\
    (This)->lpVtbl -> putref_Tag(This,newVal)

#define INSListSubItem_CorrectIndexIfGreater(This,lSubIndex,lCorrection)	\
    (This)->lpVtbl -> CorrectIndexIfGreater(This,lSubIndex,lCorrection)

#define INSListSubItem_get_ListItem(This,pVal)	\
    (This)->lpVtbl -> get_ListItem(This,pVal)

#define INSListSubItem_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#define INSListSubItem_get_IsSubItem(This,pVal)	\
    (This)->lpVtbl -> get_IsSubItem(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_Text_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListSubItem_put_Text_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSListSubItem_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_Icon_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_Icon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListSubItem_put_Icon_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListSubItem_put_Icon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_Index_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListSubItem_put_Index_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListSubItem_put_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_Key_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_Tag_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListSubItem_put_Tag_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListSubItem_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSListSubItem_putref_Tag_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSListSubItem_putref_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListSubItem_CorrectIndexIfGreater_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [in] */ long lSubIndex,
    /* [in] */ long lCorrection);


void __RPC_STUB INSListSubItem_CorrectIndexIfGreater_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_ListItem_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_ListItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_ListView_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItem_get_IsSubItem_Proxy( 
    INSListSubItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListSubItem_get_IsSubItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListSubItem_INTERFACE_DEFINED__ */


#ifndef __INSListSubItemsInt_INTERFACE_DEFINED__
#define __INSListSubItemsInt_INTERFACE_DEFINED__

/* interface INSListSubItemsInt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INSListSubItemsInt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D3862116-DC38-4ecc-A4D0-DC980778DAAF")
    INSListSubItemsInt : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ColumnRemoveUpdate( 
            /* [in] */ long lSubIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ColumnInsertUpdate( 
            /* [in] */ long lSubIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ColumnsClear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListSubItemsIntVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListSubItemsInt __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListSubItemsInt __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListSubItemsInt __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ColumnRemoveUpdate )( 
            INSListSubItemsInt __RPC_FAR * This,
            /* [in] */ long lSubIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ColumnInsertUpdate )( 
            INSListSubItemsInt __RPC_FAR * This,
            /* [in] */ long lSubIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ColumnsClear )( 
            INSListSubItemsInt __RPC_FAR * This);
        
        END_INTERFACE
    } INSListSubItemsIntVtbl;

    interface INSListSubItemsInt
    {
        CONST_VTBL struct INSListSubItemsIntVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListSubItemsInt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListSubItemsInt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListSubItemsInt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListSubItemsInt_ColumnRemoveUpdate(This,lSubIndex)	\
    (This)->lpVtbl -> ColumnRemoveUpdate(This,lSubIndex)

#define INSListSubItemsInt_ColumnInsertUpdate(This,lSubIndex)	\
    (This)->lpVtbl -> ColumnInsertUpdate(This,lSubIndex)

#define INSListSubItemsInt_ColumnsClear(This)	\
    (This)->lpVtbl -> ColumnsClear(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INSListSubItemsInt_ColumnRemoveUpdate_Proxy( 
    INSListSubItemsInt __RPC_FAR * This,
    /* [in] */ long lSubIndex);


void __RPC_STUB INSListSubItemsInt_ColumnRemoveUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INSListSubItemsInt_ColumnInsertUpdate_Proxy( 
    INSListSubItemsInt __RPC_FAR * This,
    /* [in] */ long lSubIndex);


void __RPC_STUB INSListSubItemsInt_ColumnInsertUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INSListSubItemsInt_ColumnsClear_Proxy( 
    INSListSubItemsInt __RPC_FAR * This);


void __RPC_STUB INSListSubItemsInt_ColumnsClear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListSubItemsInt_INTERFACE_DEFINED__ */


#ifndef __INSFont_INTERFACE_DEFINED__
#define __INSFont_INTERFACE_DEFINED__

/* interface INSFont */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSFont;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8877CF8C-D275-4599-B47B-1157AA62A059")
    INSFont : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Italic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Italic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Underline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Underline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Strikethru( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Strikethru( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Charset( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Charset( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Size( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hFont( 
            /* [retval][out] */ OLE_HANDLE __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSFontVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSFont __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSFont __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSFont __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSFont __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSFont __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSFont __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSFont __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Bold )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Bold )( 
            INSFont __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Italic )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Italic )( 
            INSFont __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            INSFont __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Underline )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Underline )( 
            INSFont __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Strikethru )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Strikethru )( 
            INSFont __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Charset )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Charset )( 
            INSFont __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Size )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Size )( 
            INSFont __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hFont )( 
            INSFont __RPC_FAR * This,
            /* [retval][out] */ OLE_HANDLE __RPC_FAR *pVal);
        
        END_INTERFACE
    } INSFontVtbl;

    interface INSFont
    {
        CONST_VTBL struct INSFontVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSFont_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSFont_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSFont_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSFont_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSFont_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSFont_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSFont_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSFont_get_Bold(This,pVal)	\
    (This)->lpVtbl -> get_Bold(This,pVal)

#define INSFont_put_Bold(This,newVal)	\
    (This)->lpVtbl -> put_Bold(This,newVal)

#define INSFont_get_Italic(This,pVal)	\
    (This)->lpVtbl -> get_Italic(This,pVal)

#define INSFont_put_Italic(This,newVal)	\
    (This)->lpVtbl -> put_Italic(This,newVal)

#define INSFont_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define INSFont_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define INSFont_get_Underline(This,pVal)	\
    (This)->lpVtbl -> get_Underline(This,pVal)

#define INSFont_put_Underline(This,newVal)	\
    (This)->lpVtbl -> put_Underline(This,newVal)

#define INSFont_get_Strikethru(This,pVal)	\
    (This)->lpVtbl -> get_Strikethru(This,pVal)

#define INSFont_put_Strikethru(This,newVal)	\
    (This)->lpVtbl -> put_Strikethru(This,newVal)

#define INSFont_get_Charset(This,pVal)	\
    (This)->lpVtbl -> get_Charset(This,pVal)

#define INSFont_put_Charset(This,newVal)	\
    (This)->lpVtbl -> put_Charset(This,newVal)

#define INSFont_get_Size(This,pVal)	\
    (This)->lpVtbl -> get_Size(This,pVal)

#define INSFont_put_Size(This,newVal)	\
    (This)->lpVtbl -> put_Size(This,newVal)

#define INSFont_get_hFont(This,pVal)	\
    (This)->lpVtbl -> get_hFont(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Bold_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Bold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Bold_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSFont_put_Bold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Italic_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Italic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Italic_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSFont_put_Italic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Name_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Name_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSFont_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Underline_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Underline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Underline_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSFont_put_Underline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Strikethru_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Strikethru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Strikethru_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSFont_put_Strikethru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Charset_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Charset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Charset_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB INSFont_put_Charset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_Size_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSFont_put_Size_Proxy( 
    INSFont __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB INSFont_put_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSFont_get_hFont_Proxy( 
    INSFont __RPC_FAR * This,
    /* [retval][out] */ OLE_HANDLE __RPC_FAR *pVal);


void __RPC_STUB INSFont_get_hFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSFont_INTERFACE_DEFINED__ */


#ifndef __INSListSubItems_INTERFACE_DEFINED__
#define __INSListSubItems_INTERFACE_DEFINED__

/* interface INSListSubItems */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSListSubItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C7DE55E-B102-4269-BF95-0E3AC9C6B468")
    INSListSubItems : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByIndex( 
            /* [in] */ long Index,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveByIndex( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefinedCount( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListItem( 
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemIfExists( 
            /* [in] */ long Index,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListSubItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListSubItems __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListSubItems __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSListSubItems __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            INSListSubItems __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            INSListSubItems __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            INSListSubItems __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ItemByIndex )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveByIndex )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ long Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefinedCount )( 
            INSListSubItems __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListItem )( 
            INSListSubItems __RPC_FAR * This,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSListSubItems __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ItemIfExists )( 
            INSListSubItems __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSListSubItemsVtbl;

    interface INSListSubItems
    {
        CONST_VTBL struct INSListSubItemsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListSubItems_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListSubItems_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListSubItems_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListSubItems_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSListSubItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSListSubItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSListSubItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSListSubItems_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define INSListSubItems_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define INSListSubItems_Remove(This,Index)	\
    (This)->lpVtbl -> Remove(This,Index)

#define INSListSubItems_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define INSListSubItems_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INSListSubItems_get_ItemByIndex(This,Index,pVal)	\
    (This)->lpVtbl -> get_ItemByIndex(This,Index,pVal)

#define INSListSubItems_RemoveByIndex(This,Index)	\
    (This)->lpVtbl -> RemoveByIndex(This,Index)

#define INSListSubItems_get_DefinedCount(This,pVal)	\
    (This)->lpVtbl -> get_DefinedCount(This,pVal)

#define INSListSubItems_get_ListItem(This,pVal)	\
    (This)->lpVtbl -> get_ListItem(This,pVal)

#define INSListSubItems_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#define INSListSubItems_get_ItemIfExists(This,Index,pVal)	\
    (This)->lpVtbl -> get_ItemIfExists(This,Index,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListSubItems_Clear_Proxy( 
    INSListSubItems __RPC_FAR * This);


void __RPC_STUB INSListSubItems_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_Count_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListSubItems_Remove_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [in] */ VARIANT Index);


void __RPC_STUB INSListSubItems_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_Item_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get__NewEnum_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_ItemByIndex_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_ItemByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListSubItems_RemoveByIndex_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [in] */ long Index);


void __RPC_STUB INSListSubItems_RemoveByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_DefinedCount_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_DefinedCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_ListItem_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_ListItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_ListView_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE INSListSubItems_get_ItemIfExists_Proxy( 
    INSListSubItems __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListSubItems_get_ItemIfExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListSubItems_INTERFACE_DEFINED__ */


#ifndef __INSBListImage_INTERFACE_DEFINED__
#define __INSBListImage_INTERFACE_DEFINED__

/* interface INSBListImage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSBListImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2251AD4-8088-4A24-9E3D-2B0FA1ADF48F")
    INSBListImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Key( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSBListImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSBListImage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSBListImage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSBListImage __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Key )( 
            INSBListImage __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Key )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            INSBListImage __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Tag )( 
            INSBListImage __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Index )( 
            INSBListImage __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        END_INTERFACE
    } INSBListImageVtbl;

    interface INSBListImage
    {
        CONST_VTBL struct INSBListImageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSBListImage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSBListImage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSBListImage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSBListImage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSBListImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSBListImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSBListImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSBListImage_get_Key(This,pVal)	\
    (This)->lpVtbl -> get_Key(This,pVal)

#define INSBListImage_put_Key(This,newVal)	\
    (This)->lpVtbl -> put_Key(This,newVal)

#define INSBListImage_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define INSBListImage_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define INSBListImage_putref_Tag(This,newVal)	\
    (This)->lpVtbl -> putref_Tag(This,newVal)

#define INSBListImage_get_Index(This,pVal)	\
    (This)->lpVtbl -> get_Index(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBListImage_get_Key_Proxy( 
    INSBListImage __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSBListImage_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBListImage_put_Key_Proxy( 
    INSBListImage __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSBListImage_put_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBListImage_get_Tag_Proxy( 
    INSBListImage __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSBListImage_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBListImage_put_Tag_Proxy( 
    INSBListImage __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSBListImage_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSBListImage_putref_Tag_Proxy( 
    INSBListImage __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSBListImage_putref_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBListImage_get_Index_Proxy( 
    INSBListImage __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSBListImage_get_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSBListImage_INTERFACE_DEFINED__ */


#ifndef __INSBImageList_INTERFACE_DEFINED__
#define __INSBImageList_INTERFACE_DEFINED__

/* interface INSBImageList */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSBImageList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E6FA50A-373A-45A1-87FB-A44880E577E4")
    INSBImageList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadBitmap( 
            /* [in] */ BSTR bstrBmp,
            /* [optional][in] */ VARIANT Key,
            /* [retval][out] */ long __RPC_FAR *plIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hImageList( 
            /* [retval][out] */ OLE_HANDLE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaskColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaskColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseMaskColor( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseMaskColor( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageIndex( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddIcon( 
            /* [in] */ VARIANT vData,
            /* [optional][in] */ VARIANT vKey,
            /* [defaultvalue][in] */ VARIANT_BOOL bCursor,
            /* [retval][out] */ long __RPC_FAR *plIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadResource( 
            /* [optional][in] */ VARIANT vFile,
            /* [optional][in] */ VARIANT vIndex,
            /* [optional][in] */ VARIANT vType,
            /* [optional][in] */ VARIANT vKey,
            /* [retval][out] */ long __RPC_FAR *plIndex) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSBListImage __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSBImageListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSBImageList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSBImageList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSBImageList __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Height )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadBitmap )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ BSTR bstrBmp,
            /* [optional][in] */ VARIANT Key,
            /* [retval][out] */ long __RPC_FAR *plIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hImageList )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ OLE_HANDLE __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            INSBImageList __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaskColor )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaskColor )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UseMaskColor )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UseMaskColor )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            INSBImageList __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Tag )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ImageIndex )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddIcon )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT vData,
            /* [optional][in] */ VARIANT vKey,
            /* [defaultvalue][in] */ VARIANT_BOOL bCursor,
            /* [retval][out] */ long __RPC_FAR *plIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadResource )( 
            INSBImageList __RPC_FAR * This,
            /* [optional][in] */ VARIANT vFile,
            /* [optional][in] */ VARIANT vIndex,
            /* [optional][in] */ VARIANT vType,
            /* [optional][in] */ VARIANT vKey,
            /* [retval][out] */ long __RPC_FAR *plIndex);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSBImageList __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSBListImage __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSBImageListVtbl;

    interface INSBImageList
    {
        CONST_VTBL struct INSBImageListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSBImageList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSBImageList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSBImageList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSBImageList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSBImageList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSBImageList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSBImageList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSBImageList_get_Height(This,pVal)	\
    (This)->lpVtbl -> get_Height(This,pVal)

#define INSBImageList_put_Height(This,newVal)	\
    (This)->lpVtbl -> put_Height(This,newVal)

#define INSBImageList_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)

#define INSBImageList_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)

#define INSBImageList_LoadBitmap(This,bstrBmp,Key,plIndex)	\
    (This)->lpVtbl -> LoadBitmap(This,bstrBmp,Key,plIndex)

#define INSBImageList_Remove(This,Index)	\
    (This)->lpVtbl -> Remove(This,Index)

#define INSBImageList_get_hImageList(This,pVal)	\
    (This)->lpVtbl -> get_hImageList(This,pVal)

#define INSBImageList_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define INSBImageList_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define INSBImageList_get_BackColor(This,pVal)	\
    (This)->lpVtbl -> get_BackColor(This,pVal)

#define INSBImageList_put_BackColor(This,newVal)	\
    (This)->lpVtbl -> put_BackColor(This,newVal)

#define INSBImageList_get_MaskColor(This,pVal)	\
    (This)->lpVtbl -> get_MaskColor(This,pVal)

#define INSBImageList_put_MaskColor(This,newVal)	\
    (This)->lpVtbl -> put_MaskColor(This,newVal)

#define INSBImageList_get_UseMaskColor(This,pVal)	\
    (This)->lpVtbl -> get_UseMaskColor(This,pVal)

#define INSBImageList_put_UseMaskColor(This,newVal)	\
    (This)->lpVtbl -> put_UseMaskColor(This,newVal)

#define INSBImageList_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define INSBImageList_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define INSBImageList_putref_Tag(This,newVal)	\
    (This)->lpVtbl -> putref_Tag(This,newVal)

#define INSBImageList_get_ImageIndex(This,Index,pVal)	\
    (This)->lpVtbl -> get_ImageIndex(This,Index,pVal)

#define INSBImageList_AddIcon(This,vData,vKey,bCursor,plIndex)	\
    (This)->lpVtbl -> AddIcon(This,vData,vKey,bCursor,plIndex)

#define INSBImageList_LoadResource(This,vFile,vIndex,vType,vKey,plIndex)	\
    (This)->lpVtbl -> LoadResource(This,vFile,vIndex,vType,vKey,plIndex)

#define INSBImageList_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_Height_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBImageList_put_Height_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSBImageList_put_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_Width_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBImageList_put_Width_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSBImageList_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSBImageList_LoadBitmap_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ BSTR bstrBmp,
    /* [optional][in] */ VARIANT Key,
    /* [retval][out] */ long __RPC_FAR *plIndex);


void __RPC_STUB INSBImageList_LoadBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSBImageList_Remove_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT Index);


void __RPC_STUB INSBImageList_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_hImageList_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ OLE_HANDLE __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_hImageList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_Count_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSBImageList_Clear_Proxy( 
    INSBImageList __RPC_FAR * This);


void __RPC_STUB INSBImageList_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_BackColor_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBImageList_put_BackColor_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSBImageList_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_MaskColor_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_MaskColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBImageList_put_MaskColor_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB INSBImageList_put_MaskColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_UseMaskColor_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_UseMaskColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBImageList_put_UseMaskColor_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSBImageList_put_UseMaskColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_Tag_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSBImageList_put_Tag_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSBImageList_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSBImageList_putref_Tag_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSBImageList_putref_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_ImageIndex_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_ImageIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSBImageList_AddIcon_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT vData,
    /* [optional][in] */ VARIANT vKey,
    /* [defaultvalue][in] */ VARIANT_BOOL bCursor,
    /* [retval][out] */ long __RPC_FAR *plIndex);


void __RPC_STUB INSBImageList_AddIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSBImageList_LoadResource_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [optional][in] */ VARIANT vFile,
    /* [optional][in] */ VARIANT vIndex,
    /* [optional][in] */ VARIANT vType,
    /* [optional][in] */ VARIANT vKey,
    /* [retval][out] */ long __RPC_FAR *plIndex);


void __RPC_STUB INSBImageList_LoadResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSBImageList_get_Item_Proxy( 
    INSBImageList __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ INSBListImage __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSBImageList_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSBImageList_INTERFACE_DEFINED__ */


#ifndef __INSColumnHeader_INTERFACE_DEFINED__
#define __INSColumnHeader_INTERFACE_DEFINED__

/* interface INSColumnHeader */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSColumnHeader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82C4960F-2CF3-497C-9FA5-1D32C5AAF174")
    INSColumnHeader : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Alignment( 
            /* [retval][out] */ NSListColumnAlignment __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Alignment( 
            /* [in] */ NSListColumnAlignment newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Index( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Key( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubItemIndex( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubItemIndex( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Icon( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Icon( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Position( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Position( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColumnItems( 
            /* [retval][out] */ INSColumnItems __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SortType( 
            /* [retval][out] */ NSListSortTypeConstants __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SortType( 
            /* [in] */ NSListSortTypeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowImage( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowImage( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSColumnHeaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSColumnHeader __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSColumnHeader __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSColumnHeader __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alignment )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ NSListColumnAlignment __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Alignment )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ NSListColumnAlignment newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Index )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Index )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Key )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Key )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubItemIndex )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubItemIndex )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Tag )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Tag )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Tag )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Icon )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Icon )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Position )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Position )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColumnItems )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ INSColumnItems __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SortType )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ NSListSortTypeConstants __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SortType )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ NSListSortTypeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowImage )( 
            INSColumnHeader __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowImage )( 
            INSColumnHeader __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } INSColumnHeaderVtbl;

    interface INSColumnHeader
    {
        CONST_VTBL struct INSColumnHeaderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSColumnHeader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSColumnHeader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSColumnHeader_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSColumnHeader_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSColumnHeader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSColumnHeader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSColumnHeader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSColumnHeader_get_Text(This,pVal)	\
    (This)->lpVtbl -> get_Text(This,pVal)

#define INSColumnHeader_put_Text(This,newVal)	\
    (This)->lpVtbl -> put_Text(This,newVal)

#define INSColumnHeader_get_Alignment(This,pVal)	\
    (This)->lpVtbl -> get_Alignment(This,pVal)

#define INSColumnHeader_put_Alignment(This,newVal)	\
    (This)->lpVtbl -> put_Alignment(This,newVal)

#define INSColumnHeader_get_Index(This,pVal)	\
    (This)->lpVtbl -> get_Index(This,pVal)

#define INSColumnHeader_put_Index(This,newVal)	\
    (This)->lpVtbl -> put_Index(This,newVal)

#define INSColumnHeader_get_Key(This,pVal)	\
    (This)->lpVtbl -> get_Key(This,pVal)

#define INSColumnHeader_put_Key(This,newVal)	\
    (This)->lpVtbl -> put_Key(This,newVal)

#define INSColumnHeader_get_SubItemIndex(This,pVal)	\
    (This)->lpVtbl -> get_SubItemIndex(This,pVal)

#define INSColumnHeader_put_SubItemIndex(This,newVal)	\
    (This)->lpVtbl -> put_SubItemIndex(This,newVal)

#define INSColumnHeader_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define INSColumnHeader_put_Tag(This,newVal)	\
    (This)->lpVtbl -> put_Tag(This,newVal)

#define INSColumnHeader_putref_Tag(This,newVal)	\
    (This)->lpVtbl -> putref_Tag(This,newVal)

#define INSColumnHeader_get_Icon(This,pVal)	\
    (This)->lpVtbl -> get_Icon(This,pVal)

#define INSColumnHeader_put_Icon(This,newVal)	\
    (This)->lpVtbl -> put_Icon(This,newVal)

#define INSColumnHeader_get_Position(This,pVal)	\
    (This)->lpVtbl -> get_Position(This,pVal)

#define INSColumnHeader_put_Position(This,newVal)	\
    (This)->lpVtbl -> put_Position(This,newVal)

#define INSColumnHeader_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#define INSColumnHeader_get_ColumnItems(This,pVal)	\
    (This)->lpVtbl -> get_ColumnItems(This,pVal)

#define INSColumnHeader_get_SortType(This,pVal)	\
    (This)->lpVtbl -> get_SortType(This,pVal)

#define INSColumnHeader_put_SortType(This,newVal)	\
    (This)->lpVtbl -> put_SortType(This,newVal)

#define INSColumnHeader_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)

#define INSColumnHeader_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)

#define INSColumnHeader_get_ShowImage(This,pVal)	\
    (This)->lpVtbl -> get_ShowImage(This,pVal)

#define INSColumnHeader_put_ShowImage(This,newVal)	\
    (This)->lpVtbl -> put_ShowImage(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Text_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Text_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSColumnHeader_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Alignment_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ NSListColumnAlignment __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Alignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Alignment_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ NSListColumnAlignment newVal);


void __RPC_STUB INSColumnHeader_put_Alignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Index_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Index_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSColumnHeader_put_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Key_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Key_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INSColumnHeader_put_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_SubItemIndex_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_SubItemIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_SubItemIndex_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSColumnHeader_put_SubItemIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Tag_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Tag_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSColumnHeader_put_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_putref_Tag_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSColumnHeader_putref_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Icon_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Icon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Icon_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB INSColumnHeader_put_Icon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Position_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Position_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Position_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSColumnHeader_put_Position_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_ListView_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_ColumnItems_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ INSColumnItems __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_ColumnItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_SortType_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ NSListSortTypeConstants __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_SortType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_SortType_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ NSListSortTypeConstants newVal);


void __RPC_STUB INSColumnHeader_put_SortType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_Width_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_Width_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INSColumnHeader_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_get_ShowImage_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeader_get_ShowImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSColumnHeader_put_ShowImage_Proxy( 
    INSColumnHeader __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSColumnHeader_put_ShowImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSColumnHeader_INTERFACE_DEFINED__ */


#ifndef __INSColumnHeaders_INTERFACE_DEFINED__
#define __INSColumnHeaders_INTERFACE_DEFINED__

/* interface INSColumnHeaders */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSColumnHeaders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EB2A0DA-AFF9-49D4-BA6D-E2B8AAAEEA66")
    INSColumnHeaders : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [optional][in] */ VARIANT Index,
            /* [optional][in] */ VARIANT Key,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Width,
            /* [optional][in] */ VARIANT Alignment,
            /* [optional][in] */ VARIANT Icon,
            /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *ppObj) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSColumnHeadersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSColumnHeaders __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSColumnHeaders __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            INSColumnHeaders __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [optional][in] */ VARIANT Index,
            /* [optional][in] */ VARIANT Key,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Width,
            /* [optional][in] */ VARIANT Alignment,
            /* [optional][in] */ VARIANT Icon,
            /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *ppObj);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSColumnHeaders __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSColumnHeadersVtbl;

    interface INSColumnHeaders
    {
        CONST_VTBL struct INSColumnHeadersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSColumnHeaders_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSColumnHeaders_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSColumnHeaders_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSColumnHeaders_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSColumnHeaders_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSColumnHeaders_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSColumnHeaders_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSColumnHeaders_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define INSColumnHeaders_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define INSColumnHeaders_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define INSColumnHeaders_Remove(This,Index)	\
    (This)->lpVtbl -> Remove(This,Index)

#define INSColumnHeaders_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INSColumnHeaders_Add(This,Index,Key,Text,Width,Alignment,Icon,ppObj)	\
    (This)->lpVtbl -> Add(This,Index,Key,Text,Width,Alignment,Icon,ppObj)

#define INSColumnHeaders_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_get_Count_Proxy( 
    INSColumnHeaders __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSColumnHeaders_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_Clear_Proxy( 
    INSColumnHeaders __RPC_FAR * This);


void __RPC_STUB INSColumnHeaders_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_get_Item_Proxy( 
    INSColumnHeaders __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnHeaders_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_Remove_Proxy( 
    INSColumnHeaders __RPC_FAR * This,
    /* [in] */ VARIANT Index);


void __RPC_STUB INSColumnHeaders_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_get__NewEnum_Proxy( 
    INSColumnHeaders __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnHeaders_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_Add_Proxy( 
    INSColumnHeaders __RPC_FAR * This,
    /* [optional][in] */ VARIANT Index,
    /* [optional][in] */ VARIANT Key,
    /* [optional][in] */ VARIANT Text,
    /* [optional][in] */ VARIANT Width,
    /* [optional][in] */ VARIANT Alignment,
    /* [optional][in] */ VARIANT Icon,
    /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *ppObj);


void __RPC_STUB INSColumnHeaders_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSColumnHeaders_get_ListView_Proxy( 
    INSColumnHeaders __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSColumnHeaders_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSColumnHeaders_INTERFACE_DEFINED__ */


#ifndef __INSListItems_INTERFACE_DEFINED__
#define __INSListItems_INTERFACE_DEFINED__

/* interface INSListItems */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSListItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F00D35A3-7256-4235-87F1-639ECB7E636E")
    INSListItems : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [optional][in] */ VARIANT Index,
            /* [optional][in] */ VARIANT Key,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Icon,
            /* [optional][in] */ VARIANT Indent,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *ppObj) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListItems __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListItems __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSListItems __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSListItems __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSListItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSListItems __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            INSListItems __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            INSListItems __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            INSListItems __RPC_FAR * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSListItems __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            INSListItems __RPC_FAR * This,
            /* [optional][in] */ VARIANT Index,
            /* [optional][in] */ VARIANT Key,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Icon,
            /* [optional][in] */ VARIANT Indent,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *ppObj);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSListItems __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            INSListItems __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSListItemsVtbl;

    interface INSListItems
    {
        CONST_VTBL struct INSListItemsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListItems_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListItems_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListItems_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListItems_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSListItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSListItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSListItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSListItems_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define INSListItems_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define INSListItems_Remove(This,Index)	\
    (This)->lpVtbl -> Remove(This,Index)

#define INSListItems_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define INSListItems_Add(This,Index,Key,Text,Icon,Indent,ppObj)	\
    (This)->lpVtbl -> Add(This,Index,Key,Text,Icon,Indent,ppObj)

#define INSListItems_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#define INSListItems_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItems_get_Count_Proxy( 
    INSListItems __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListItems_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListItems_Clear_Proxy( 
    INSListItems __RPC_FAR * This);


void __RPC_STUB INSListItems_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListItems_Remove_Proxy( 
    INSListItems __RPC_FAR * This,
    /* [in] */ VARIANT Index);


void __RPC_STUB INSListItems_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItems_get_Item_Proxy( 
    INSListItems __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListItems_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INSListItems_Add_Proxy( 
    INSListItems __RPC_FAR * This,
    /* [optional][in] */ VARIANT Index,
    /* [optional][in] */ VARIANT Key,
    /* [optional][in] */ VARIANT Text,
    /* [optional][in] */ VARIANT Icon,
    /* [optional][in] */ VARIANT Indent,
    /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *ppObj);


void __RPC_STUB INSListItems_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItems_get_ListView_Proxy( 
    INSListItems __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListItems_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListItems_get__NewEnum_Proxy( 
    INSListItems __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListItems_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListItems_INTERFACE_DEFINED__ */


#ifndef __INSListViewEvent_INTERFACE_DEFINED__
#define __INSListViewEvent_INTERFACE_DEFINED__

/* interface INSListViewEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INSListViewEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3A0D93C6-1F25-4AD3-AB31-2BE7420C1B1A")
    INSListViewEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Column( 
            /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubItem( 
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Event( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cancel( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Cancel( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListView( 
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INSListViewEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INSListViewEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INSListViewEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INSListViewEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INSListViewEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INSListViewEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INSListViewEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INSListViewEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Column )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubItem )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Event )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Cancel )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Cancel )( 
            INSListViewEvent __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Key )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListView )( 
            INSListViewEvent __RPC_FAR * This,
            /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } INSListViewEventVtbl;

    interface INSListViewEvent
    {
        CONST_VTBL struct INSListViewEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSListViewEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INSListViewEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INSListViewEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INSListViewEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INSListViewEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INSListViewEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INSListViewEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INSListViewEvent_get_Column(This,pVal)	\
    (This)->lpVtbl -> get_Column(This,pVal)

#define INSListViewEvent_get_Item(This,pVal)	\
    (This)->lpVtbl -> get_Item(This,pVal)

#define INSListViewEvent_get_SubItem(This,pVal)	\
    (This)->lpVtbl -> get_SubItem(This,pVal)

#define INSListViewEvent_get_Event(This,pVal)	\
    (This)->lpVtbl -> get_Event(This,pVal)

#define INSListViewEvent_get_Text(This,pVal)	\
    (This)->lpVtbl -> get_Text(This,pVal)

#define INSListViewEvent_get_Cancel(This,pVal)	\
    (This)->lpVtbl -> get_Cancel(This,pVal)

#define INSListViewEvent_put_Cancel(This,newVal)	\
    (This)->lpVtbl -> put_Cancel(This,newVal)

#define INSListViewEvent_get_Key(This,pVal)	\
    (This)->lpVtbl -> get_Key(This,pVal)

#define INSListViewEvent_get_ListView(This,pVal)	\
    (This)->lpVtbl -> get_ListView(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_Column_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ INSColumnHeader __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_Column_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_Item_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ INSListItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_SubItem_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ INSListSubItem __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_SubItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_Event_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_Event_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_Text_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_Cancel_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_put_Cancel_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB INSListViewEvent_put_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_Key_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INSListViewEvent_get_ListView_Proxy( 
    INSListViewEvent __RPC_FAR * This,
    /* [retval][out] */ INSListView __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB INSListViewEvent_get_ListView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INSListViewEvent_INTERFACE_DEFINED__ */


#ifndef ___INSListViewEvents_DISPINTERFACE_DEFINED__
#define ___INSListViewEvents_DISPINTERFACE_DEFINED__

/* dispinterface _INSListViewEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__INSListViewEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F401398D-6196-49da-9E40-5498402F545E")
    _INSListViewEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _INSListViewEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _INSListViewEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _INSListViewEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _INSListViewEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _INSListViewEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _INSListViewEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _INSListViewEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _INSListViewEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _INSListViewEventsVtbl;

    interface _INSListViewEvents
    {
        CONST_VTBL struct _INSListViewEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _INSListViewEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _INSListViewEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _INSListViewEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _INSListViewEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _INSListViewEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _INSListViewEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _INSListViewEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___INSListViewEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_NSListView;

#ifdef __cplusplus

class DECLSPEC_UUID("F7A4DFE2-C262-457E-B0C5-B4789D02988D")
NSListView;
#endif

#ifndef ___INSBImageListEvents_DISPINTERFACE_DEFINED__
#define ___INSBImageListEvents_DISPINTERFACE_DEFINED__

/* dispinterface _INSBImageListEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__INSBImageListEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("67B081B1-8A58-4230-9FEC-9029F407CEE7")
    _INSBImageListEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _INSBImageListEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _INSBImageListEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _INSBImageListEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _INSBImageListEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _INSBImageListEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _INSBImageListEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _INSBImageListEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _INSBImageListEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _INSBImageListEventsVtbl;

    interface _INSBImageListEvents
    {
        CONST_VTBL struct _INSBImageListEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _INSBImageListEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _INSBImageListEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _INSBImageListEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _INSBImageListEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _INSBImageListEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _INSBImageListEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _INSBImageListEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___INSBImageListEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_NSBImageList;

#ifdef __cplusplus

class DECLSPEC_UUID("E4FD27CF-BA94-452F-A486-82CFA4D09868")
NSBImageList;
#endif

EXTERN_C const CLSID CLSID_NSBListImage;

#ifdef __cplusplus

class DECLSPEC_UUID("B62F1938-B1CD-4E78-9FCB-8CAD1F997DB9")
NSBListImage;
#endif

EXTERN_C const CLSID CLSID_NSColumnHeaders;

#ifdef __cplusplus

class DECLSPEC_UUID("682F2EB8-9B45-4CF7-8C0E-2A1514265CB0")
NSColumnHeaders;
#endif

EXTERN_C const CLSID CLSID_NSColumnHeader;

#ifdef __cplusplus

class DECLSPEC_UUID("0B4E0F87-C549-40D2-9B6C-34E7F105C10C")
NSColumnHeader;
#endif

EXTERN_C const CLSID CLSID_NSListItems;

#ifdef __cplusplus

class DECLSPEC_UUID("71427340-76E0-43DD-8EB7-26C775D9F34C")
NSListItems;
#endif

EXTERN_C const CLSID CLSID_NSListItem;

#ifdef __cplusplus

class DECLSPEC_UUID("D781A7C5-EFBF-4B7F-B2AB-04CB123EC507")
NSListItem;
#endif

EXTERN_C const CLSID CLSID_NSListSubItems;

#ifdef __cplusplus

class DECLSPEC_UUID("3E6044B6-7C40-4E52-967A-46A4231D398F")
NSListSubItems;
#endif

EXTERN_C const CLSID CLSID_NSListSubItem;

#ifdef __cplusplus

class DECLSPEC_UUID("C7AC974A-EEDC-4D8A-9E74-A6E28CA5B0FD")
NSListSubItem;
#endif

EXTERN_C const CLSID CLSID_NSListViewEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("93B251F7-8671-4F70-B12F-CF6C88F12820")
NSListViewEvent;
#endif

#ifndef ___INSFontEvents_DISPINTERFACE_DEFINED__
#define ___INSFontEvents_DISPINTERFACE_DEFINED__

/* dispinterface _INSFontEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__INSFontEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E9ABD6FF-4B89-48CE-881D-243A7950E0FA")
    _INSFontEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _INSFontEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _INSFontEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _INSFontEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _INSFontEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _INSFontEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _INSFontEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _INSFontEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _INSFontEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _INSFontEventsVtbl;

    interface _INSFontEvents
    {
        CONST_VTBL struct _INSFontEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _INSFontEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _INSFontEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _INSFontEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _INSFontEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _INSFontEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _INSFontEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _INSFontEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___INSFontEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_NSFont;

#ifdef __cplusplus

class DECLSPEC_UUID("07679CF2-323B-46A7-87CB-A8DC600BC4BE")
NSFont;
#endif

EXTERN_C const CLSID CLSID_NSColumnItems;

#ifdef __cplusplus

class DECLSPEC_UUID("83ACFE88-E502-4379-8178-6740F32D81D6")
NSColumnItems;
#endif

EXTERN_C const CLSID CLSID_NSComCtlColl;

#ifdef __cplusplus

class DECLSPEC_UUID("30861775-4F37-435A-AAEB-D954D1621487")
NSComCtlColl;
#endif
#endif /* __NSBControlsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
