
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0286 */
/* at Thu Nov 02 15:40:38 2006
 */
/* Compiler settings for E:\NSBCE6\3rd Party Controls\RGridCtrl 2\RGridCtrl.idl:
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

#ifndef __RGridCtrl_h__
#define __RGridCtrl_h__

/* Forward Declarations */ 

#ifndef __IGrid_FWD_DEFINED__
#define __IGrid_FWD_DEFINED__
typedef interface IGrid IGrid;
#endif 	/* __IGrid_FWD_DEFINED__ */


#ifndef ___IGridEvents_FWD_DEFINED__
#define ___IGridEvents_FWD_DEFINED__
typedef interface _IGridEvents _IGridEvents;
#endif 	/* ___IGridEvents_FWD_DEFINED__ */


#ifndef __Grid_FWD_DEFINED__
#define __Grid_FWD_DEFINED__

#ifdef __cplusplus
typedef class Grid Grid;
#else
typedef struct Grid Grid;
#endif /* __cplusplus */

#endif 	/* __Grid_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __RGRIDCTRLLib_LIBRARY_DEFINED__
#define __RGRIDCTRLLib_LIBRARY_DEFINED__

/* library RGRIDCTRLLib */
/* [helpstring][version][uuid] */ 

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("DA0A462B-79ED-4108-89F7-E3E395D755B5") 
enum AllowUserResizeSettings
    {	rgridResizeNone	= 0,
	rgridResizeColumns	= 1,
	rgridResizeRows	= 2,
	rgridResizeBoth	= 3
    }	AllowUserResizeSettings;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("BD80FA4E-0200-4893-84C3-6783ED83F7F0") 
enum AlignmentSettings
    {	rgridAlignLeftTop	= 0,
	rgridAlignLeftCenter	= 1,
	rgridAlignLeftBottom	= 2,
	rgridAlignCenterTop	= 3,
	rgridAlignCenterCenter	= 4,
	rgridAlignCenterBottom	= 5,
	rgridAlignRightTop	= 6,
	rgridAlignRightCenter	= 7,
	rgridAlignRightBottom	= 8,
	rgridAlignGeneral	= 9
    }	AlignmentSettings;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("10A94FF1-094C-408b-92E6-7C1E239572A6") 
enum BorderStyleSettings
    {	rgridBorderNone	= 0,
	rgridBorderSingle	= 1
    }	BorderStyleSettings;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("6256A1A9-3EA3-4b6c-B67F-A51E4A17D93A") 
enum GridLineSettings
    {	rgridGridNone	= 0,
	rgridGridFlat	= 1,
	rgridGridInset	= 2,
	rgridGridRaised	= 3
    }	GridLineSettings;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("BA9ADDE2-6F85-4d99-97C2-85D7F99549C7") 
enum ScrollBarsSettings
    {	rgridScrollBarNone	= 0,
	rgridScrollBarHorizontal	= 1,
	rgridScrollBarVertical	= 2,
	rgridScrollBarBoth	= 3
    }	ScrollBarsSettings;

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("32FE6AD0-93F9-4fcf-A985-5C7E0D42055A") 
enum SelectionModeSettings
    {	rgridSelectionFree	= 0,
	rgridSelectionByRow	= 1,
	rgridSelectionByColumn	= 2
    }	SelectionModeSettings;

typedef /* [uuid] */  DECLSPEC_UUID("C02D50F0-76C8-4256-BAC5-50258F09F6E5") 
enum RZOrderConstants
    {	rgridBringToFront	= 0,
	rgridSendToBack	= 1
    }	RZOrderConstants;

typedef /* [uuid] */  DECLSPEC_UUID("D126BA58-5230-4ae6-BE21-842158AC9362") 
enum RHighlightConstants
    {	rgridHighlightNever	= 0,
	rgridHighlightAlways	= 1
    }	RHighlightConstants;


EXTERN_C const IID LIBID_RGRIDCTRLLib;

#ifndef __IGrid_INTERFACE_DEFINED__
#define __IGrid_INTERFACE_DEFINED__

/* interface IGrid */
/* [oleautomation][unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGrid;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9AA3AAC-599F-40EB-AADB-73348B6322A2")
    IGrid : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rows( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rows( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedRows( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedRows( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cols( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Cols( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedCols( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedCols( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColorBkg( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColorBkg( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColorFixed( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColorFixed( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GridLines( 
            /* [retval][out] */ GridLineSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GridLines( 
            /* [in] */ GridLineSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GridLinesFixed( 
            /* [retval][out] */ GridLineSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GridLinesFixed( 
            /* [in] */ GridLineSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GridColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GridColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GridColorFixed( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GridColorFixed( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowUserResizing( 
            /* [retval][out] */ AllowUserResizeSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowUserResizing( 
            /* [in] */ AllowUserResizeSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScrollBars( 
            /* [retval][out] */ ScrollBarsSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScrollBars( 
            /* [in] */ ScrollBarsSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderStyle( 
            /* [retval][out] */ BorderStyleSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderStyle( 
            /* [in] */ BorderStyleSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScrollTrack( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScrollTrack( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColorFixed( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColorFixed( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColorSel( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColorSel( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColorSel( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColorSel( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowHeightMin( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RowHeightMin( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextMatrix( 
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextMatrix( 
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextArray( 
            /* [in] */ long index,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextArray( 
            /* [in] */ long index,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Row( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Row( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Col( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Col( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellBackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellBackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellForeColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellForeColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellAlignment( 
            /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellAlignment( 
            /* [in] */ AlignmentSettings newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellLeft( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellTop( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellWidth( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellHeight( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ColAlignment( 
            /* [in] */ long index,
            /* [in] */ AlignmentSettings newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColWidth( 
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ColWidth( 
            /* [in] */ long index,
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColIsVisible( 
            /* [in] */ long index,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColPos( 
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowHeight( 
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RowHeight( 
            /* [in] */ long index,
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowIsVisible( 
            /* [in] */ long index,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowPos( 
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColSel( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ColSel( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RowSel( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RowSel( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowBigSelection( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowBigSelection( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectionMode( 
            /* [retval][out] */ SelectionModeSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SelectionMode( 
            /* [in] */ SelectionModeSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GridLineWidth( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GridLineWidth( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftCol( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LeftCol( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TopRow( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TopRow( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedAlignment( 
            /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedAlignment( 
            /* [in] */ AlignmentSettings newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontSize( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontBold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontBold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontItalic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontItalic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontUnderline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontUnderline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontWidth( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellFontStrikeThrough( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellFontStrikeThrough( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontBold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontBold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontItalic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontItalic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontUnderline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontUnderline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontWidth( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontStrikeThrough( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontStrikeThrough( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontBold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontBold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontItalic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontItalic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontSize( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontStrikeThrough( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontStrikeThrough( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontUnderline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontUnderline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FixedFontWidth( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FixedFontWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellPictureAlignment( 
            /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellPictureAlignment( 
            /* [in] */ AlignmentSettings newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WordWrap( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WordWrap( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HighLight( 
            /* [retval][out] */ RHighlightConstants __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HighLight( 
            /* [in] */ RHighlightConstants newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Redraw( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Redraw( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddItem( 
            /* [in] */ BSTR Item,
            /* [optional][in] */ VARIANT __RPC_FAR *index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [in] */ long index) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CellLoadPicture( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegistrationCode( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegistrationCode( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hWnd( 
            /* [retval][out] */ /* external definition not present */ OLE_HANDLE __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGridVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGrid __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGrid __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGrid __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGrid __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGrid __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGrid __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGrid __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Rows )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Rows )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedRows )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedRows )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Cols )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Cols )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedCols )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedCols )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColorBkg )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColorBkg )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColorFixed )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColorFixed )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridLines )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ GridLineSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridLines )( 
            IGrid __RPC_FAR * This,
            /* [in] */ GridLineSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridLinesFixed )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ GridLineSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridLinesFixed )( 
            IGrid __RPC_FAR * This,
            /* [in] */ GridLineSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridColor )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridColor )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridColorFixed )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridColorFixed )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllowUserResizing )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ AllowUserResizeSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AllowUserResizing )( 
            IGrid __RPC_FAR * This,
            /* [in] */ AllowUserResizeSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScrollBars )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ ScrollBarsSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScrollBars )( 
            IGrid __RPC_FAR * This,
            /* [in] */ ScrollBarsSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderStyle )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ BorderStyleSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BorderStyle )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BorderStyleSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScrollTrack )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScrollTrack )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForeColor )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColorFixed )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForeColorFixed )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColorSel )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForeColorSel )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColorSel )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColorSel )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RowHeightMin )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RowHeightMin )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TextMatrix )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TextMatrix )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [in] */ BSTR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TextArray )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TextArray )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ BSTR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Row )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Row )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Col )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Col )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellBackColor )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellBackColor )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellForeColor )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellForeColor )( 
            IGrid __RPC_FAR * This,
            /* [in] */ /* external definition not present */ OLE_COLOR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellAlignment )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellAlignment )( 
            IGrid __RPC_FAR * This,
            /* [in] */ AlignmentSettings newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellLeft )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellTop )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellWidth )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellHeight )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ColAlignment )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ AlignmentSettings newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColWidth )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ColWidth )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColIsVisible )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColPos )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RowHeight )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RowHeight )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RowIsVisible )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RowPos )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ColSel )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ColSel )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RowSel )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RowSel )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllowBigSelection )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AllowBigSelection )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SelectionMode )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ SelectionModeSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SelectionMode )( 
            IGrid __RPC_FAR * This,
            /* [in] */ SelectionModeSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridLineWidth )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridLineWidth )( 
            IGrid __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LeftCol )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LeftCol )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TopRow )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TopRow )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedAlignment )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedAlignment )( 
            IGrid __RPC_FAR * This,
            /* [in] */ AlignmentSettings newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontName )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontName )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontSize )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontSize )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontBold )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontBold )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontItalic )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontItalic )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontUnderline )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontUnderline )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontWidth )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontWidth )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellFontStrikeThrough )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellFontStrikeThrough )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontBold )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontBold )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontItalic )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontItalic )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontUnderline )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontUnderline )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontWidth )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontWidth )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontStrikeThrough )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontStrikeThrough )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontBold )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontBold )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontItalic )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontItalic )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontName )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontName )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontSize )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontSize )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontStrikeThrough )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontStrikeThrough )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontUnderline )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontUnderline )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FixedFontWidth )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FixedFontWidth )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellPictureAlignment )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellPictureAlignment )( 
            IGrid __RPC_FAR * This,
            /* [in] */ AlignmentSettings newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WordWrap )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WordWrap )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HighLight )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ RHighlightConstants __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HighLight )( 
            IGrid __RPC_FAR * This,
            /* [in] */ RHighlightConstants newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Redraw )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [nonbrowsable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Redraw )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            IGrid __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddItem )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR Item,
            /* [optional][in] */ VARIANT __RPC_FAR *index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveItem )( 
            IGrid __RPC_FAR * This,
            /* [in] */ long index);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IGrid __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CellLoadPicture )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RegistrationCode )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RegistrationCode )( 
            IGrid __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [nonbrowsable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hWnd )( 
            IGrid __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ OLE_HANDLE __RPC_FAR *pVal);
        
        END_INTERFACE
    } IGridVtbl;

    interface IGrid
    {
        CONST_VTBL struct IGridVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGrid_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGrid_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGrid_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGrid_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGrid_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGrid_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGrid_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGrid_get_Rows(This,pVal)	\
    (This)->lpVtbl -> get_Rows(This,pVal)

#define IGrid_put_Rows(This,newVal)	\
    (This)->lpVtbl -> put_Rows(This,newVal)

#define IGrid_get_FixedRows(This,pVal)	\
    (This)->lpVtbl -> get_FixedRows(This,pVal)

#define IGrid_put_FixedRows(This,newVal)	\
    (This)->lpVtbl -> put_FixedRows(This,newVal)

#define IGrid_get_Cols(This,pVal)	\
    (This)->lpVtbl -> get_Cols(This,pVal)

#define IGrid_put_Cols(This,newVal)	\
    (This)->lpVtbl -> put_Cols(This,newVal)

#define IGrid_get_FixedCols(This,pVal)	\
    (This)->lpVtbl -> get_FixedCols(This,pVal)

#define IGrid_put_FixedCols(This,newVal)	\
    (This)->lpVtbl -> put_FixedCols(This,newVal)

#define IGrid_get_BackColor(This,pVal)	\
    (This)->lpVtbl -> get_BackColor(This,pVal)

#define IGrid_put_BackColor(This,newVal)	\
    (This)->lpVtbl -> put_BackColor(This,newVal)

#define IGrid_get_BackColorBkg(This,pVal)	\
    (This)->lpVtbl -> get_BackColorBkg(This,pVal)

#define IGrid_put_BackColorBkg(This,newVal)	\
    (This)->lpVtbl -> put_BackColorBkg(This,newVal)

#define IGrid_get_BackColorFixed(This,pVal)	\
    (This)->lpVtbl -> get_BackColorFixed(This,pVal)

#define IGrid_put_BackColorFixed(This,newVal)	\
    (This)->lpVtbl -> put_BackColorFixed(This,newVal)

#define IGrid_get_GridLines(This,pVal)	\
    (This)->lpVtbl -> get_GridLines(This,pVal)

#define IGrid_put_GridLines(This,newVal)	\
    (This)->lpVtbl -> put_GridLines(This,newVal)

#define IGrid_get_GridLinesFixed(This,pVal)	\
    (This)->lpVtbl -> get_GridLinesFixed(This,pVal)

#define IGrid_put_GridLinesFixed(This,newVal)	\
    (This)->lpVtbl -> put_GridLinesFixed(This,newVal)

#define IGrid_get_GridColor(This,pVal)	\
    (This)->lpVtbl -> get_GridColor(This,pVal)

#define IGrid_put_GridColor(This,newVal)	\
    (This)->lpVtbl -> put_GridColor(This,newVal)

#define IGrid_get_GridColorFixed(This,pVal)	\
    (This)->lpVtbl -> get_GridColorFixed(This,pVal)

#define IGrid_put_GridColorFixed(This,newVal)	\
    (This)->lpVtbl -> put_GridColorFixed(This,newVal)

#define IGrid_get_AllowUserResizing(This,pVal)	\
    (This)->lpVtbl -> get_AllowUserResizing(This,pVal)

#define IGrid_put_AllowUserResizing(This,newVal)	\
    (This)->lpVtbl -> put_AllowUserResizing(This,newVal)

#define IGrid_get_ScrollBars(This,pVal)	\
    (This)->lpVtbl -> get_ScrollBars(This,pVal)

#define IGrid_put_ScrollBars(This,newVal)	\
    (This)->lpVtbl -> put_ScrollBars(This,newVal)

#define IGrid_get_BorderStyle(This,pVal)	\
    (This)->lpVtbl -> get_BorderStyle(This,pVal)

#define IGrid_put_BorderStyle(This,newVal)	\
    (This)->lpVtbl -> put_BorderStyle(This,newVal)

#define IGrid_get_ScrollTrack(This,pVal)	\
    (This)->lpVtbl -> get_ScrollTrack(This,pVal)

#define IGrid_put_ScrollTrack(This,newVal)	\
    (This)->lpVtbl -> put_ScrollTrack(This,newVal)

#define IGrid_get_ForeColor(This,pVal)	\
    (This)->lpVtbl -> get_ForeColor(This,pVal)

#define IGrid_put_ForeColor(This,newVal)	\
    (This)->lpVtbl -> put_ForeColor(This,newVal)

#define IGrid_get_ForeColorFixed(This,pVal)	\
    (This)->lpVtbl -> get_ForeColorFixed(This,pVal)

#define IGrid_put_ForeColorFixed(This,newVal)	\
    (This)->lpVtbl -> put_ForeColorFixed(This,newVal)

#define IGrid_get_ForeColorSel(This,pVal)	\
    (This)->lpVtbl -> get_ForeColorSel(This,pVal)

#define IGrid_put_ForeColorSel(This,newVal)	\
    (This)->lpVtbl -> put_ForeColorSel(This,newVal)

#define IGrid_get_BackColorSel(This,pVal)	\
    (This)->lpVtbl -> get_BackColorSel(This,pVal)

#define IGrid_put_BackColorSel(This,newVal)	\
    (This)->lpVtbl -> put_BackColorSel(This,newVal)

#define IGrid_get_RowHeightMin(This,pVal)	\
    (This)->lpVtbl -> get_RowHeightMin(This,pVal)

#define IGrid_put_RowHeightMin(This,newVal)	\
    (This)->lpVtbl -> put_RowHeightMin(This,newVal)

#define IGrid_get_TextMatrix(This,Row,Col,pVal)	\
    (This)->lpVtbl -> get_TextMatrix(This,Row,Col,pVal)

#define IGrid_put_TextMatrix(This,Row,Col,newVal)	\
    (This)->lpVtbl -> put_TextMatrix(This,Row,Col,newVal)

#define IGrid_get_TextArray(This,index,pVal)	\
    (This)->lpVtbl -> get_TextArray(This,index,pVal)

#define IGrid_put_TextArray(This,index,newVal)	\
    (This)->lpVtbl -> put_TextArray(This,index,newVal)

#define IGrid_get_Row(This,pVal)	\
    (This)->lpVtbl -> get_Row(This,pVal)

#define IGrid_put_Row(This,newVal)	\
    (This)->lpVtbl -> put_Row(This,newVal)

#define IGrid_get_Col(This,pVal)	\
    (This)->lpVtbl -> get_Col(This,pVal)

#define IGrid_put_Col(This,newVal)	\
    (This)->lpVtbl -> put_Col(This,newVal)

#define IGrid_get_CellBackColor(This,pVal)	\
    (This)->lpVtbl -> get_CellBackColor(This,pVal)

#define IGrid_put_CellBackColor(This,newVal)	\
    (This)->lpVtbl -> put_CellBackColor(This,newVal)

#define IGrid_get_CellForeColor(This,pVal)	\
    (This)->lpVtbl -> get_CellForeColor(This,pVal)

#define IGrid_put_CellForeColor(This,newVal)	\
    (This)->lpVtbl -> put_CellForeColor(This,newVal)

#define IGrid_get_CellAlignment(This,pVal)	\
    (This)->lpVtbl -> get_CellAlignment(This,pVal)

#define IGrid_put_CellAlignment(This,newVal)	\
    (This)->lpVtbl -> put_CellAlignment(This,newVal)

#define IGrid_get_CellLeft(This,pVal)	\
    (This)->lpVtbl -> get_CellLeft(This,pVal)

#define IGrid_get_CellTop(This,pVal)	\
    (This)->lpVtbl -> get_CellTop(This,pVal)

#define IGrid_get_CellWidth(This,pVal)	\
    (This)->lpVtbl -> get_CellWidth(This,pVal)

#define IGrid_get_CellHeight(This,pVal)	\
    (This)->lpVtbl -> get_CellHeight(This,pVal)

#define IGrid_put_ColAlignment(This,index,newVal)	\
    (This)->lpVtbl -> put_ColAlignment(This,index,newVal)

#define IGrid_get_Text(This,pVal)	\
    (This)->lpVtbl -> get_Text(This,pVal)

#define IGrid_put_Text(This,newVal)	\
    (This)->lpVtbl -> put_Text(This,newVal)

#define IGrid_get_ColWidth(This,index,pVal)	\
    (This)->lpVtbl -> get_ColWidth(This,index,pVal)

#define IGrid_put_ColWidth(This,index,newVal)	\
    (This)->lpVtbl -> put_ColWidth(This,index,newVal)

#define IGrid_get_ColIsVisible(This,index,pVal)	\
    (This)->lpVtbl -> get_ColIsVisible(This,index,pVal)

#define IGrid_get_ColPos(This,index,pVal)	\
    (This)->lpVtbl -> get_ColPos(This,index,pVal)

#define IGrid_get_RowHeight(This,index,pVal)	\
    (This)->lpVtbl -> get_RowHeight(This,index,pVal)

#define IGrid_put_RowHeight(This,index,newVal)	\
    (This)->lpVtbl -> put_RowHeight(This,index,newVal)

#define IGrid_get_RowIsVisible(This,index,pVal)	\
    (This)->lpVtbl -> get_RowIsVisible(This,index,pVal)

#define IGrid_get_RowPos(This,index,pVal)	\
    (This)->lpVtbl -> get_RowPos(This,index,pVal)

#define IGrid_get_ColSel(This,pVal)	\
    (This)->lpVtbl -> get_ColSel(This,pVal)

#define IGrid_put_ColSel(This,newVal)	\
    (This)->lpVtbl -> put_ColSel(This,newVal)

#define IGrid_get_RowSel(This,pVal)	\
    (This)->lpVtbl -> get_RowSel(This,pVal)

#define IGrid_put_RowSel(This,newVal)	\
    (This)->lpVtbl -> put_RowSel(This,newVal)

#define IGrid_get_AllowBigSelection(This,pVal)	\
    (This)->lpVtbl -> get_AllowBigSelection(This,pVal)

#define IGrid_put_AllowBigSelection(This,newVal)	\
    (This)->lpVtbl -> put_AllowBigSelection(This,newVal)

#define IGrid_get_SelectionMode(This,pVal)	\
    (This)->lpVtbl -> get_SelectionMode(This,pVal)

#define IGrid_put_SelectionMode(This,newVal)	\
    (This)->lpVtbl -> put_SelectionMode(This,newVal)

#define IGrid_get_GridLineWidth(This,pVal)	\
    (This)->lpVtbl -> get_GridLineWidth(This,pVal)

#define IGrid_put_GridLineWidth(This,newVal)	\
    (This)->lpVtbl -> put_GridLineWidth(This,newVal)

#define IGrid_get_LeftCol(This,pVal)	\
    (This)->lpVtbl -> get_LeftCol(This,pVal)

#define IGrid_put_LeftCol(This,newVal)	\
    (This)->lpVtbl -> put_LeftCol(This,newVal)

#define IGrid_get_TopRow(This,pVal)	\
    (This)->lpVtbl -> get_TopRow(This,pVal)

#define IGrid_put_TopRow(This,newVal)	\
    (This)->lpVtbl -> put_TopRow(This,newVal)

#define IGrid_get_FixedAlignment(This,pVal)	\
    (This)->lpVtbl -> get_FixedAlignment(This,pVal)

#define IGrid_put_FixedAlignment(This,newVal)	\
    (This)->lpVtbl -> put_FixedAlignment(This,newVal)

#define IGrid_get_CellFontName(This,pVal)	\
    (This)->lpVtbl -> get_CellFontName(This,pVal)

#define IGrid_put_CellFontName(This,newVal)	\
    (This)->lpVtbl -> put_CellFontName(This,newVal)

#define IGrid_get_CellFontSize(This,pVal)	\
    (This)->lpVtbl -> get_CellFontSize(This,pVal)

#define IGrid_put_CellFontSize(This,newVal)	\
    (This)->lpVtbl -> put_CellFontSize(This,newVal)

#define IGrid_get_CellFontBold(This,pVal)	\
    (This)->lpVtbl -> get_CellFontBold(This,pVal)

#define IGrid_put_CellFontBold(This,newVal)	\
    (This)->lpVtbl -> put_CellFontBold(This,newVal)

#define IGrid_get_CellFontItalic(This,pVal)	\
    (This)->lpVtbl -> get_CellFontItalic(This,pVal)

#define IGrid_put_CellFontItalic(This,newVal)	\
    (This)->lpVtbl -> put_CellFontItalic(This,newVal)

#define IGrid_get_CellFontUnderline(This,pVal)	\
    (This)->lpVtbl -> get_CellFontUnderline(This,pVal)

#define IGrid_put_CellFontUnderline(This,newVal)	\
    (This)->lpVtbl -> put_CellFontUnderline(This,newVal)

#define IGrid_get_CellFontWidth(This,pVal)	\
    (This)->lpVtbl -> get_CellFontWidth(This,pVal)

#define IGrid_put_CellFontWidth(This,newVal)	\
    (This)->lpVtbl -> put_CellFontWidth(This,newVal)

#define IGrid_get_CellFontStrikeThrough(This,pVal)	\
    (This)->lpVtbl -> get_CellFontStrikeThrough(This,pVal)

#define IGrid_put_CellFontStrikeThrough(This,newVal)	\
    (This)->lpVtbl -> put_CellFontStrikeThrough(This,newVal)

#define IGrid_get_FontName(This,pVal)	\
    (This)->lpVtbl -> get_FontName(This,pVal)

#define IGrid_put_FontName(This,newVal)	\
    (This)->lpVtbl -> put_FontName(This,newVal)

#define IGrid_get_FontSize(This,pVal)	\
    (This)->lpVtbl -> get_FontSize(This,pVal)

#define IGrid_put_FontSize(This,newVal)	\
    (This)->lpVtbl -> put_FontSize(This,newVal)

#define IGrid_get_FontBold(This,pVal)	\
    (This)->lpVtbl -> get_FontBold(This,pVal)

#define IGrid_put_FontBold(This,newVal)	\
    (This)->lpVtbl -> put_FontBold(This,newVal)

#define IGrid_get_FontItalic(This,pVal)	\
    (This)->lpVtbl -> get_FontItalic(This,pVal)

#define IGrid_put_FontItalic(This,newVal)	\
    (This)->lpVtbl -> put_FontItalic(This,newVal)

#define IGrid_get_FontUnderline(This,pVal)	\
    (This)->lpVtbl -> get_FontUnderline(This,pVal)

#define IGrid_put_FontUnderline(This,newVal)	\
    (This)->lpVtbl -> put_FontUnderline(This,newVal)

#define IGrid_get_FontWidth(This,pVal)	\
    (This)->lpVtbl -> get_FontWidth(This,pVal)

#define IGrid_put_FontWidth(This,newVal)	\
    (This)->lpVtbl -> put_FontWidth(This,newVal)

#define IGrid_get_FontStrikeThrough(This,pVal)	\
    (This)->lpVtbl -> get_FontStrikeThrough(This,pVal)

#define IGrid_put_FontStrikeThrough(This,newVal)	\
    (This)->lpVtbl -> put_FontStrikeThrough(This,newVal)

#define IGrid_get_FixedFontBold(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontBold(This,pVal)

#define IGrid_put_FixedFontBold(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontBold(This,newVal)

#define IGrid_get_FixedFontItalic(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontItalic(This,pVal)

#define IGrid_put_FixedFontItalic(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontItalic(This,newVal)

#define IGrid_get_FixedFontName(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontName(This,pVal)

#define IGrid_put_FixedFontName(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontName(This,newVal)

#define IGrid_get_FixedFontSize(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontSize(This,pVal)

#define IGrid_put_FixedFontSize(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontSize(This,newVal)

#define IGrid_get_FixedFontStrikeThrough(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontStrikeThrough(This,pVal)

#define IGrid_put_FixedFontStrikeThrough(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontStrikeThrough(This,newVal)

#define IGrid_get_FixedFontUnderline(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontUnderline(This,pVal)

#define IGrid_put_FixedFontUnderline(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontUnderline(This,newVal)

#define IGrid_get_FixedFontWidth(This,pVal)	\
    (This)->lpVtbl -> get_FixedFontWidth(This,pVal)

#define IGrid_put_FixedFontWidth(This,newVal)	\
    (This)->lpVtbl -> put_FixedFontWidth(This,newVal)

#define IGrid_get_CellPictureAlignment(This,pVal)	\
    (This)->lpVtbl -> get_CellPictureAlignment(This,pVal)

#define IGrid_put_CellPictureAlignment(This,newVal)	\
    (This)->lpVtbl -> put_CellPictureAlignment(This,newVal)

#define IGrid_get_WordWrap(This,pVal)	\
    (This)->lpVtbl -> get_WordWrap(This,pVal)

#define IGrid_put_WordWrap(This,newVal)	\
    (This)->lpVtbl -> put_WordWrap(This,newVal)

#define IGrid_get_HighLight(This,pVal)	\
    (This)->lpVtbl -> get_HighLight(This,pVal)

#define IGrid_put_HighLight(This,newVal)	\
    (This)->lpVtbl -> put_HighLight(This,newVal)

#define IGrid_get_Redraw(This,pVal)	\
    (This)->lpVtbl -> get_Redraw(This,pVal)

#define IGrid_put_Redraw(This,newVal)	\
    (This)->lpVtbl -> put_Redraw(This,newVal)

#define IGrid_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IGrid_AddItem(This,Item,index)	\
    (This)->lpVtbl -> AddItem(This,Item,index)

#define IGrid_RemoveItem(This,index)	\
    (This)->lpVtbl -> RemoveItem(This,index)

#define IGrid_put_Enabled(This,vbool)	\
    (This)->lpVtbl -> put_Enabled(This,vbool)

#define IGrid_get_Enabled(This,pbool)	\
    (This)->lpVtbl -> get_Enabled(This,pbool)

#define IGrid_CellLoadPicture(This,FileName)	\
    (This)->lpVtbl -> CellLoadPicture(This,FileName)

#define IGrid_get_RegistrationCode(This,pVal)	\
    (This)->lpVtbl -> get_RegistrationCode(This,pVal)

#define IGrid_put_RegistrationCode(This,newVal)	\
    (This)->lpVtbl -> put_RegistrationCode(This,newVal)

#define IGrid_get_hWnd(This,pVal)	\
    (This)->lpVtbl -> get_hWnd(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Rows_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_Rows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Rows_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_Rows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedRows_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedRows_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_FixedRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Cols_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_Cols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Cols_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_Cols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedCols_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedCols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedCols_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_FixedCols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_BackColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_BackColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_BackColorBkg_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_BackColorBkg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_BackColorBkg_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_BackColorBkg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_BackColorFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_BackColorFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_BackColorFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_BackColorFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_GridLines_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ GridLineSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_GridLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_GridLines_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ GridLineSettings newVal);


void __RPC_STUB IGrid_put_GridLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_GridLinesFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ GridLineSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_GridLinesFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_GridLinesFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ GridLineSettings newVal);


void __RPC_STUB IGrid_put_GridLinesFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_GridColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_GridColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_GridColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_GridColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_GridColorFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_GridColorFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_GridColorFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_GridColorFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_AllowUserResizing_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ AllowUserResizeSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_AllowUserResizing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_AllowUserResizing_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ AllowUserResizeSettings newVal);


void __RPC_STUB IGrid_put_AllowUserResizing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ScrollBars_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ ScrollBarsSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ScrollBars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ScrollBars_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ ScrollBarsSettings newVal);


void __RPC_STUB IGrid_put_ScrollBars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_BorderStyle_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ BorderStyleSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_BorderStyle_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BorderStyleSettings newVal);


void __RPC_STUB IGrid_put_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ScrollTrack_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ScrollTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ScrollTrack_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_ScrollTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ForeColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ForeColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ForeColorFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ForeColorFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ForeColorFixed_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_ForeColorFixed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ForeColorSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ForeColorSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ForeColorSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_ForeColorSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_BackColorSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_BackColorSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_BackColorSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_BackColorSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_RowHeightMin_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_RowHeightMin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_RowHeightMin_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_RowHeightMin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_TextMatrix_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ long Col,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_TextMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_TextMatrix_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ long Col,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_TextMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_TextArray_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_TextArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_TextArray_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_TextArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Row_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_Row_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Row_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_Row_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Col_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_Col_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Col_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_Col_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellBackColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellBackColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_CellBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellForeColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellForeColor_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ /* external definition not present */ OLE_COLOR newVal);


void __RPC_STUB IGrid_put_CellForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ AlignmentSettings newVal);


void __RPC_STUB IGrid_put_CellAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellLeft_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellTop_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellTop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellHeight_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ColAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ AlignmentSettings newVal);


void __RPC_STUB IGrid_put_ColAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Text_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Text_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ColWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ColWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ColWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_ColWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ColIsVisible_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ColIsVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ColPos_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ColPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_RowHeight_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_RowHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_RowHeight_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_RowHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_RowIsVisible_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_RowIsVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_RowPos_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_RowPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_ColSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_ColSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_ColSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_ColSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_RowSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_RowSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_RowSel_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_RowSel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_AllowBigSelection_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_AllowBigSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_AllowBigSelection_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_AllowBigSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_SelectionMode_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ SelectionModeSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_SelectionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_SelectionMode_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ SelectionModeSettings newVal);


void __RPC_STUB IGrid_put_SelectionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_GridLineWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_GridLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_GridLineWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IGrid_put_GridLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_LeftCol_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_LeftCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_LeftCol_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_LeftCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_TopRow_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_TopRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_TopRow_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_TopRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ AlignmentSettings newVal);


void __RPC_STUB IGrid_put_FixedAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontName_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontName_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_CellFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontSize_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontSize_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_CellFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontBold_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontBold_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_CellFontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontItalic_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontItalic_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_CellFontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontUnderline_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontUnderline_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_CellFontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_CellFontWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellFontStrikeThrough_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellFontStrikeThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellFontStrikeThrough_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_CellFontStrikeThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontName_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontName_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontSize_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontSize_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontBold_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontBold_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontItalic_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontItalic_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontUnderline_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontUnderline_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_FontWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FontStrikeThrough_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FontStrikeThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FontStrikeThrough_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FontStrikeThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontBold_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontBold_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FixedFontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontItalic_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontItalic_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FixedFontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontName_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontName_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_FixedFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontSize_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontSize_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_FixedFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontStrikeThrough_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontStrikeThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontStrikeThrough_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FixedFontStrikeThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontUnderline_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontUnderline_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_FixedFontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_FixedFontWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_FixedFontWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_FixedFontWidth_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGrid_put_FixedFontWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_CellPictureAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ AlignmentSettings __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_CellPictureAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_CellPictureAlignment_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ AlignmentSettings newVal);


void __RPC_STUB IGrid_put_CellPictureAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_WordWrap_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_WordWrap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_WordWrap_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_WordWrap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_HighLight_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ RHighlightConstants __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_HighLight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_HighLight_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ RHighlightConstants newVal);


void __RPC_STUB IGrid_put_HighLight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Redraw_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_Redraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Redraw_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IGrid_put_Redraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGrid_Clear_Proxy( 
    IGrid __RPC_FAR * This);


void __RPC_STUB IGrid_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGrid_AddItem_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR Item,
    /* [optional][in] */ VARIANT __RPC_FAR *index);


void __RPC_STUB IGrid_AddItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGrid_RemoveItem_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ long index);


void __RPC_STUB IGrid_RemoveItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_Enabled_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IGrid_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_Enabled_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB IGrid_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGrid_CellLoadPicture_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IGrid_CellLoadPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_RegistrationCode_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_RegistrationCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGrid_put_RegistrationCode_Proxy( 
    IGrid __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IGrid_put_RegistrationCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nonbrowsable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGrid_get_hWnd_Proxy( 
    IGrid __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ OLE_HANDLE __RPC_FAR *pVal);


void __RPC_STUB IGrid_get_hWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGrid_INTERFACE_DEFINED__ */


#ifndef ___IGridEvents_DISPINTERFACE_DEFINED__
#define ___IGridEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IGridEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IGridEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D5BF9E6C-D57E-4B4D-991D-2606C01707AF")
    _IGridEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IGridEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IGridEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IGridEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IGridEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IGridEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IGridEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IGridEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IGridEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IGridEventsVtbl;

    interface _IGridEvents
    {
        CONST_VTBL struct _IGridEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IGridEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IGridEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IGridEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IGridEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IGridEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IGridEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IGridEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IGridEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Grid;

#ifdef __cplusplus

class DECLSPEC_UUID("058E370E-6141-4E41-8B95-846EE04BB303")
Grid;
#endif
#endif /* __RGRIDCTRLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


