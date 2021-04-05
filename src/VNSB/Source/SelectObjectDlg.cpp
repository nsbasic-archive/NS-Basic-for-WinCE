// SelectObjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "SelectObjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectObjectDlg dialog


CSelectObjectDlg::CSelectObjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectObjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectObjectDlg)
	//}}AFX_DATA_INIT
}


void CSelectObjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectObjectDlg)
	DDX_Control(pDX, IDC_OBJECT_LIST, m_cObjectList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectObjectDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectObjectDlg)
	ON_LBN_DBLCLK(IDC_OBJECT_LIST, OnDblClkObjectList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectObjectDlg message handlers


BOOL CSelectObjectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

   CListBox *pListBox = (CListBox *)GetDlgItem( IDC_OBJECT_LIST );
   for( int i = 0; i < m_aObjectNames.GetSize(); i++ )
      pListBox->AddString( m_aObjectNames[i] );
   m_aObjectNames.RemoveAll();
   SetActiveWindow();
   return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
} // OnInitDialog

void CSelectObjectDlg::OnDblClkObjectList() 
{
   OnOK();
} // OnDblClkObjectList

void CSelectObjectDlg::OnOK()
{
   // CListBox
   CString strObjectName;
   CListBox *pListBox = (CListBox *)GetDlgItem( IDC_OBJECT_LIST );
   for( int i = 0; i < pListBox->GetCount(); i++ )
      if( pListBox->GetSel( i ) > 0 )
      {
         pListBox->GetText( i, strObjectName );
         m_aObjectNames.Add( strObjectName );
      }
   CDialog::OnOK();
} // OnOK
