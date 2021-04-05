// MenuEditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "NSBForm.h"
#include "MenuEditorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuEditorDlg dialog


CMenuEditorDlg::CMenuEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMenuEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMenuEditorDlg)
	//}}AFX_DATA_INIT
}


void CMenuEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMenuEditorDlg)
	DDX_Control(pDX, IDC_MENU_TREE, m_cMenuTree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMenuEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CMenuEditorDlg)
	ON_BN_CLICKED(IDC_ADDMENUITEM, OnAddMenuItem)
	ON_BN_CLICKED(IDC_DELETEMENUITEM, OnDeleteMenuItem)
	ON_BN_CLICKED(IDC_ADDSUBMENUITEM, OnAddSubmenuItem)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_MENU_TREE, OnEndLabelEditMenuTree)
	ON_NOTIFY(TVN_BEGINLABELEDIT, IDC_MENU_TREE, OnBeginLabelEditMenuTree)
	ON_NOTIFY(TVN_SELCHANGED, IDC_MENU_TREE, OnSelChangedMenuTree)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuEditorDlg message handlers

BOOL CMenuEditorDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Set window name
   CString strText;
   strText.Format( _T( "%s Menu" ), m_pForm->m_strName );
   SetWindowText( strText );

   // Set menu editor contents
   if( m_pForm->m_aFormMenu.GetSize() != NULL )
      SetMenu( &m_pForm->m_aFormMenu );
   m_cMenuTree.SelectItem( m_cMenuTree.GetNextItem( NULL, TVGN_CHILD ) );

#ifdef _PPC_
   CRect rect;
   GetClientRect( &rect );
   SetWindowPos( &wndTopMost, ( GetSystemMetrics( SM_CXSCREEN ) - rect.right ) / 2, 0,
                 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW );
#endif
   SetActiveWindow();
   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}

void CMenuEditorDlg::SetMenu( NSBFormMenu *pFormMenu, HTREEITEM htParent )
{
   for( int i = 0; i < pFormMenu->GetSize(); i++ )
   {
      CNSBFormSubMenu *pSubMenu = new CNSBFormSubMenu( ( *pFormMenu )[i] );
//      pMenu->Add( pSubMenu );
      HTREEITEM htItem = m_cMenuTree.InsertItem( ( *pFormMenu )[i]->m_strItem, htParent );
      if( ( *pFormMenu )[i]->m_aSubMenu.GetSize() > 0 )
         SetMenu( &( ( *pFormMenu )[i]->m_aSubMenu ), htItem );
   }
} // SetMenu

void CMenuEditorDlg::GetMenu( NSBFormMenu *pMenu, HTREEITEM htItem )
{
   while( htItem )
   {
      INT i;
      CNSBFormSubMenu *pSubMenu = new CNSBFormSubMenu( m_cMenuTree.GetItemText( htItem ) );
      i = pMenu->Add( pSubMenu );
      if( m_cMenuTree.ItemHasChildren( htItem ) )
      {
         HTREEITEM htChild = m_cMenuTree.GetChildItem( htItem );
         GetMenu( &( ( *pMenu )[i]->m_aSubMenu ), htChild );
      }
      htItem = m_cMenuTree.GetNextSiblingItem( htItem );
   }
} // GetMenu

void CMenuEditorDlg::OnAddMenuItem()
{
   CMenuItemEditorDlg dlg;
   if( dlg.DoModal() == IDOK )
   {
      CString strItem;
      dlg.GetItem( strItem );
      if( !strItem.IsEmpty() )
      {
         HTREEITEM htSibling = m_cMenuTree.GetSelectedItem();
         HTREEITEM htParent = m_cMenuTree.GetParentItem( htSibling );
         HTREEITEM htNew = m_cMenuTree.InsertItem( strItem, htParent, htSibling );
         m_cMenuTree.Expand( htParent, TVE_EXPAND );
         m_cMenuTree.SelectItem( htNew );
         m_cMenuTree.EnsureVisible( htNew );
      }
   }
   SetActiveWindow();
} // OnAddMenuItem

void CMenuEditorDlg::OnAddSubmenuItem() 
{
   CMenuItemEditorDlg dlg;
   if( dlg.DoModal() == IDOK )
   {
      CString strItem;
      dlg.GetItem( strItem );
      if( !strItem.IsEmpty() )
      {
         HTREEITEM htParent = m_cMenuTree.GetSelectedItem();
         HTREEITEM htChild = m_cMenuTree.GetChildItem( htParent );
         HTREEITEM htTemp = htChild;
         while( htTemp != NULL )
         {
            htChild = htTemp;
            htTemp = m_cMenuTree.GetNextSiblingItem( htChild );
         }
         if( htChild == NULL )
            htChild = TVI_LAST;
         HTREEITEM htNew = m_cMenuTree.InsertItem( strItem, htParent, htChild );
         m_cMenuTree.Expand( htParent, TVE_EXPAND );
         if( htParent != NULL )
            m_cMenuTree.SelectItem( htParent );
         else
            m_cMenuTree.SelectItem( htNew );
         m_cMenuTree.EnsureVisible( htNew );
      }
   }
   SetActiveWindow();
} // OnAddSubmenuItem

void CMenuEditorDlg::OnDeleteMenuItem() 
{
   HTREEITEM htSelected = m_cMenuTree.GetSelectedItem();
   if( htSelected != NULL )
   {
      TRACE( _T( "Menu Tree Items Remaining %d\n" ), m_cMenuTree.GetCount() );
      TRACE( _T( "Deleting...\n" ) );
      m_cMenuTree.DeleteItem( htSelected );
      TRACE( _T( "Menu Tree Items Remaining %d\n" ), m_cMenuTree.GetCount() );
   }
   return;
} // OnDeleteMenuItem

void CMenuEditorDlg::OnEndLabelEditMenuTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
   HTREEITEM htItem = m_cMenuTree.GetSelectedItem();
   CString strItem;
   m_cMenuTree.GetEditControl()->GetWindowText( strItem );
   m_cMenuTree.SetItemText( htItem, strItem );
	*pResult = 0;
}

void CMenuEditorDlg::OnBeginLabelEditMenuTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
   TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
   HTREEITEM htItem = m_cMenuTree.GetSelectedItem();
   CString strItem = m_cMenuTree.GetItemText( htItem );

   CMenuItemEditorDlg dlg;
   dlg.SetItem( strItem );
   if( dlg.DoModal() == IDOK )
   {
      dlg.GetItem( strItem );
      m_cMenuTree.GetEditControl()->SetWindowText( strItem );
   }
   *pResult = 0;
}

void CMenuEditorDlg::OnSelChangedMenuTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;
}

void CMenuEditorDlg::OnOK()
{
   m_pForm->DeleteFormMenu();
   GetMenu( &m_pForm->m_aFormMenu, m_cMenuTree.GetNextItem( NULL, TVGN_CHILD ) );
   CDialog::OnOK();
} // OnOK

/////////////////////////////////////////////////////////////////////////////
// CMenuItemEditorDlg dialog


CMenuItemEditorDlg::CMenuItemEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMenuItemEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMenuItemEditorDlg)
	m_strAccelerator = _T("");
	m_strCaption = _T("");
	m_strMenuKey = _T("");
	//}}AFX_DATA_INIT
}


void CMenuItemEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMenuItemEditorDlg)
	DDX_Text(pDX, IDC_ACCELERATOR, m_strAccelerator);
	DDX_Text(pDX, IDC_CAPTION, m_strCaption);
	DDX_Text(pDX, IDC_MENUKEY, m_strMenuKey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMenuItemEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CMenuItemEditorDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuItemEditorDlg message handlers

BOOL CMenuItemEditorDlg::OnInitDialog() 
{
   CDialog::OnInitDialog();

   if( m_strCaption.GetLength() > 0 || m_strMenuKey.GetLength() > 0 || m_strAccelerator.GetLength() > 0 )
      SetWindowText( _T( "Edit Menu Item" ) );
   else
      SetWindowText( _T( "Add Menu Item" ) );
#ifdef _PPC_
   CRect rect;
   GetClientRect( &rect );
   SetWindowPos( &wndTopMost, ( GetSystemMetrics( SM_CXSCREEN ) - rect.right ) / 2, 0,
                 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW );
#endif
   SetActiveWindow();
   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
} // OnInitDialog

void CMenuItemEditorDlg::SetItem( CString strItem )
{
   int i;

   i = strItem.Find( _T( "||" ) );
   if( i >= 0 )
   {
      m_strCaption = strItem.Left( i );
      m_strMenuKey = strItem.Right(  strItem.GetLength() - ( i + 2 ) );
   }
   else
   {
      m_strCaption = strItem;
   }
   i = m_strCaption.Find( _T( "\t" ) );
   if( i >= 0 )
   {
      m_strAccelerator = m_strCaption.Right( i + 2 );
      m_strCaption = m_strCaption.Left( i );
   }
} // SetItem

void CMenuItemEditorDlg::GetItem( CString &strItem )
{
   if( m_strAccelerator.GetLength() > 0 )
      strItem.Format( _T( "%s\t%s%s%s" ), m_strCaption, m_strAccelerator,
                     ( m_strMenuKey.GetLength() > 0 ? _T( "||" ) : _T( "" ) ),
                     m_strMenuKey );
   else
      strItem.Format( _T( "%s%s%s" ), m_strCaption,
                     ( m_strMenuKey.GetLength() > 0 ? _T( "||" ) : _T( "" ) ),
                     m_strMenuKey );
} // GetItem

void CMenuEditorDlg::OnClose() 
{
   CWnd *pParent = GetParent();
   pParent->SetActiveWindow();
	CDialog::OnClose();
}
