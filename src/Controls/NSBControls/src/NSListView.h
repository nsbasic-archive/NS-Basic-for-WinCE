// NSListView.h : Declaration of the CNSListView

#ifndef __NSLISTVIEW_H_
#define __NSLISTVIEW_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include <commctrl.h>
#include "ComCtlCP.h"

class CNSColumnHeaders;
class CNSListItems;

extern _ATL_FUNC_INFO g_FontEvents[];
extern _ATL_FUNC_INFO g_ImageListEvents[];

/////////////////////////////////////////////////////////////////////////////
// CNSListView
class ATL_NO_VTABLE CNSListView : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CNSListView, INSListView, &IID_INSListView, &LIBID_COMCTLLib>,
	public CComControl<CNSListView>,
	public IPersistStreamInitImpl<CNSListView>,
	public IOleControlImpl<CNSListView>,
	public IOleObjectImpl<CNSListView>,
	public IOleInPlaceActiveObjectImpl<CNSListView>,
	public IViewObjectExImpl<CNSListView>,
	public IOleInPlaceObjectWindowlessImpl<CNSListView>,
	public ISupportErrorInfo,
	public IPersistStorageImpl<CNSListView>,
	public ISpecifyPropertyPagesImpl<CNSListView>,
	public IQuickActivateImpl<CNSListView>,
	public IDataObjectImpl<CNSListView>,
    public IConnectionPointContainerImpl<CNSListView>,
	public IProvideClassInfo2Impl<&CLSID_NSListView, &DIID__INSListViewEvents, &LIBID_COMCTLLib>,
	public CComCoClass<CNSListView, &CLSID_NSListView>,
    public IDispEventSimpleImpl<0,CNSListView,&DIID__INSFontEvents>,
    public IDispEventSimpleImpl<1,CNSListView,&DIID__INSBImageListEvents>,
    public IDispEventSimpleImpl<2,CNSListView,&DIID__INSBImageListEvents>,
    public IDispEventSimpleImpl<3,CNSListView,&DIID__INSBImageListEvents>,
	public CProxy_INSListViewEvents< CNSListView >
{
public:
	CContainedWindow m_ctlSysListView32;
	

	CNSListView() :	
		m_ctlSysListView32(_T("SysListView32"), this, 1)
	{
		m_bWindowOnly = TRUE;
        m_pColumnHeaders = NULL;
        m_pListItems = NULL;
        m_bSorted = VARIANT_FALSE;
        m_SortOrder = lvwAscending;
        m_lSortKey = -1;
        m_bCustomSort = VARIANT_FALSE;
        m_hFont = NULL;
        m_nAppearance = 0;
	    m_nBorderStyle = 1;
	    m_bEnabled = TRUE;
	    m_bTabStop = TRUE;
        m_SortType = lvwTextSort;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NSLISTVIEW)

DECLARE_PROTECT_FINAL_CONSTRUCT()

// DECLARE_WND_CLASS_EX(_T("NSBListViewHost20061"),CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,COLOR_WINDOW);

HRESULT     FinalConstruct();
void        FinalRelease();

BEGIN_COM_MAP(CNSListView)
	COM_INTERFACE_ENTRY(INSListView)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
    COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CNSListView)
    CONNECTION_POINT_ENTRY(DIID__INSListViewEvents)
END_CONNECTION_POINT_MAP()

BEGIN_SINK_MAP(CNSListView)
    SINK_ENTRY_INFO(0, DIID__INSFontEvents, 1, OnFontChange, &g_FontEvents[0])
    SINK_ENTRY_INFO(1, DIID__INSBImageListEvents, 1, OnIconsChange, &g_ImageListEvents[0])
    SINK_ENTRY_INFO(2, DIID__INSBImageListEvents, 1, OnSmallIconsChange, &g_ImageListEvents[0])
    SINK_ENTRY_INFO(3, DIID__INSBImageListEvents, 1, OnHeaderIconsChange, &g_ImageListEvents[0])
END_SINK_MAP()

// Event handlers
VOID __stdcall  OnFontChange();
HFONT           m_hFont;
VOID __stdcall  OnIconsChange();
VOID __stdcall  OnSmallIconsChange();
VOID __stdcall  OnHeaderIconsChange();


CComObject<CNSColumnHeaders>*   m_pColumnHeaders;
CComObject<CNSListItems>*       m_pListItems;
CComPtr<INSColumnHeaders>       m_spColumnHeaders;
CComPtr<INSListItems>           m_spListItems;
CComPtr<INSBImageList>          m_spIcons;
CComPtr<INSBImageList>          m_spSmallIcons;
CComPtr<INSBImageList>          m_spHeaderIcons;
CComPtr<INSFont>                m_spFont;

VARIANT_BOOL                    m_bSorted;
NSListSortOrderConstants        m_SortOrder;
long                            m_lSortKey;
VARIANT_BOOL                    m_bCustomSort;
ccVariant                       m_vTag;
NSListSortTypeConstants         m_SortType;

HRESULT _SetIconImageList();
HRESULT _SetSmallIconImageList();
HRESULT _SetHeaderIconImageList();

HRESULT _RemoveSubItemsWithIndex(long lSubItem);
HRESULT _IncrementSubItemsWithIndexAndAbove(long lSubItem);
HRESULT _RemoveAllSubItems();
// nList = 0 - Icons and SmallIcons, 1 - Icons, 2 - SmallIcons, 3 - HeaderIcons
long    _FindImageIndex(VARIANT Index,int nList);
void    _FullRedraw();

void    _ReSort();

BOOL    _CompareItem(BSTR bstr,IDispatch* pItem,VARIANT_BOOL bTags,int nPartial);

static int CALLBACK CompareItemsProc(LPARAM lp1,LPARAM lp2,LPARAM lp);


BEGIN_PROP_MAP(CNSListView)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("Caption", DISPID_CAPTION, CLSID_NULL)
	PROP_ENTRY("Enabled", 33, CLSID_NULL)
	// PROP_ENTRY("HWND", DISPID_HWND, CLSID_NULL)
	PROP_ENTRY("TabStop", DISPID_TABSTOP, CLSID_NULL)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CNSListView)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
    MESSAGE_HANDLER(WM_DESTROY,OnDestroy)

    NOTIFY_CODE_HANDLER(LVN_COLUMNCLICK,_OnColumnClick)
    NOTIFY_CODE_HANDLER(LVN_BEGINLABELEDIT,_OnBeginLabelEdit)
    NOTIFY_CODE_HANDLER(LVN_ENDLABELEDIT,_OnEndLabelEdit)
    NOTIFY_CODE_HANDLER(LVN_ITEMACTIVATE,_OnItemActivate)
    NOTIFY_CODE_HANDLER(LVN_KEYDOWN,_OnKeyDown)
    NOTIFY_CODE_HANDLER(LVN_MARQUEEBEGIN,_OnMarqueeBegin)
    NOTIFY_CODE_HANDLER(NM_CLICK ,_OnClick)
    NOTIFY_CODE_HANDLER(NM_DBLCLK ,_OnDblClick)
    NOTIFY_CODE_HANDLER(NM_RCLICK ,_OnRClick)
    NOTIFY_CODE_HANDLER(NM_RDBLCLK  ,_OnRDblClick)
    NOTIFY_CODE_HANDLER(NM_RETURN ,_OnReturn)
    NOTIFY_CODE_HANDLER(LVN_ITEMCHANGED ,_OnItemChanged)

	CHAIN_MSG_MAP(CComControl<CNSListView>)
ALT_MSG_MAP(1)
	// Replace this with message map entries for superclassed SysListView32
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    // LRESULT OnGetDispInfo(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    LRESULT _OnColumnClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnBeginLabelEdit(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnEndLabelEdit(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnItemActivate(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnKeyDown(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnMarqueeBegin(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnDblClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnRClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnRDblClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnReturn(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    LRESULT _OnItemChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	BOOL PreTranslateAccelerator(LPMSG pMsg, HRESULT& hRet)
	{
		if(pMsg->message == WM_KEYDOWN && 
			(pMsg->wParam == VK_LEFT || 
			pMsg->wParam == VK_RIGHT ||
			pMsg->wParam == VK_UP ||
			pMsg->wParam == VK_DOWN))
		{
			hRet = S_FALSE;
			return TRUE;
		}
		//TODO: Add your additional accelerator handling code here
		return FALSE;
	}

	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LRESULT lRes = CComControl<CNSListView>::OnSetFocus(uMsg, wParam, lParam, bHandled);
		if (m_bInPlaceActive)
		{
			DoVerbUIActivate(&m_rcPos,  NULL);
			if(!IsChild(::GetFocus()))
				m_ctlSysListView32.SetFocus();
		}
		return lRes;
	}

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
    LRESULT OnDestroy(UINT,WPARAM,LPARAM,BOOL&);
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		IOleInPlaceObjectWindowlessImpl<CNSListView>::SetObjectRects(prcPos, prcClip);
        RECT    rccl;
        GetClientRect(&rccl);
		int cx, cy;
		cx = prcPos->right - prcPos->left;
		cy = prcPos->bottom - prcPos->top;
        //::SetWindowPos(m_ctlSysListView32.m_hWnd, NULL, 0,
		//	0, cx,cy, SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
		::SetWindowPos(m_ctlSysListView32.m_hWnd, NULL, 0,
			0, rccl.right - rccl.left, rccl.bottom - rccl.top, SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
		return S_OK;
	}

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_INSListView,
		};
		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

    // HRESULT FireOnChanged(DISPID dispID);
    
    STDMETHOD(put_Enabled)(VARIANT_BOOL a) {
        if (m_ctlSysListView32.IsWindow()) {
            m_ctlSysListView32.EnableWindow(a);
            m_bEnabled = a;
        }
        return S_OK;

    }
    STDMETHOD(get_Enabled)(VARIANT_BOOL* a) {
        if (a) *a = (short)m_bEnabled;
        return S_OK;
    }
    
    
    

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// INSListView
public:
	STDMETHOD(get_Visible)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Visible)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Left)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Left)(/*[in]*/ long newVal);
	STDMETHOD(get_Top)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Top)(/*[in]*/ long newVal);
	STDMETHOD(get_Height)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Height)(/*[in]*/ long newVal);
	STDMETHOD(get_Width)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Width)(/*[in]*/ long newVal);
	STDMETHOD(SetFocus)();
	STDMETHOD(get_Columns)(/*[out, retval]*/ INSColumnHeaders* *pVal);
	STDMETHOD(get_SelectedItems)(/*[out, retval]*/ INSComCtlColl* *pVal);
	STDMETHOD(UnSelectAll)();
	STDMETHOD(FindItems)(/*[in]*/ BSTR Text,/*[in,defaultvalue(0)]*/ VARIANT_BOOL bSubItems,/*[in,defaultvalue(0)]*/ VARIANT_BOOL bTags,/*[in,defaultvalue(0)]*/ NSListViewFindConstants nPartial,/*[out,retval]*/ INSComCtlColl** ppObj);
	STDMETHOD(get_Font)(/*[out, retval]*/ INSFont* *pVal);
	STDMETHOD(putref_Font)(/*[in]*/ INSFont* newVal);
	STDMETHOD(get_TextColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_TextColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_TextBackColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_TextBackColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_BackColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_BackColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_Tag)(/*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_Tag)(/*[in]*/ VARIANT newVal);
    STDMETHOD(putref_Tag)(/*[in]*/ VARIANT newVal);
	STDMETHOD(get_ColumnHeaderIcons)(/*[out, retval]*/ INSBImageList* *pVal);
	STDMETHOD(putref_ColumnHeaderIcons)(/*[in]*/ INSBImageList* newVal);
	STDMETHOD(get_CustomSort)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_CustomSort)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_SortKey)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_SortKey)(/*[in]*/ long newVal);
	STDMETHOD(get_SortHeaders)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_SortHeaders)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(UpdateIcons)();
	STDMETHOD(get_Icons)(/*[out, retval]*/ INSBImageList* *pVal);
	STDMETHOD(putref_Icons)(/*[in]*/ INSBImageList* newVal);
	STDMETHOD(get_SmallIcons)(/*[out, retval]*/ INSBImageList* *pVal);
	STDMETHOD(putref_SmallIcons)(/*[in]*/ INSBImageList* newVal);
	STDMETHOD(get_UnderlineHot)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_UnderlineHot)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_UnderlineCold)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_UnderlineCold)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_TrackSelect)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_TrackSelect)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_SubItemImages)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_SubItemImages)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_AllowColumnReorder)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_AllowColumnReorder)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_GridLines)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_GridLines)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_FullRowSelect)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_FullRowSelect)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Checkboxes)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Checkboxes)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Sorted)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Sorted)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_LabelWrap)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_LabelWrap)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_LabelEdit)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_LabelEdit)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_HideColumnHeaders)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HideColumnHeaders)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Arrange)(/*[out, retval]*/ NSListArrangeConstants *pVal);
	STDMETHOD(put_Arrange)(/*[in]*/ NSListArrangeConstants newVal);
	STDMETHOD(get_SortOrder)(/*[out, retval]*/ NSListSortOrderConstants *pVal);
	STDMETHOD(put_SortOrder)(/*[in]*/ NSListSortOrderConstants newVal);
	STDMETHOD(get_MultiSelect)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_MultiSelect)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_HideSelection)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HideSelection)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ListItems)(/*[out, retval]*/ INSListItems* *pVal);
	STDMETHOD(get_View)(/*[out, retval]*/ NSListViewConstants *pVal);
	STDMETHOD(put_View)(/*[in]*/ NSListViewConstants newVal);
	STDMETHOD(get_ColumnHeaders)(/*[out, retval]*/ INSColumnHeaders* *pVal);

	CComBSTR m_bstrCaption;
	LONG m_nBorderStyle;
	BOOL m_bEnabled;
	BOOL m_bTabStop;
};

#endif //__NSLISTVIEW_H_
