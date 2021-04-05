// CodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "CodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCodeDlg dialog


CCodeDlg::CCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCodeDlg)
	m_strCode = _T("");
	//}}AFX_DATA_INIT
}


void CCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCodeDlg)
	DDX_Text(pDX, IDC_CODE, m_strCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCodeDlg, CDialog)
	//{{AFX_MSG_MAP(CCodeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCodeDlg message handlers

BOOL CCodeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
   SetActiveWindow();
   ( (CEdit *)GetDlgItem( IDC_CODE ) )->SetSel( 0, 0 );
   ( (CEdit *)GetDlgItem( IDC_CODE ) )->HideCaret();
   return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
} // OnInitDialog
/////////////////////////////////////////////////////////////////////////////
// CPrefsDlg dialog


CPrefsDlg::CPrefsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrefsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrefsDlg)
	m_nGrid = 0;
	m_bGridSnap = FALSE;
	//}}AFX_DATA_INIT
}


void CPrefsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrefsDlg)
	DDX_Text(pDX, IDC_GRIDSIZE, m_nGrid);
	DDV_MinMaxInt(pDX, m_nGrid, 4, 20);
	DDX_Check(pDX, IDC_GRIDSNAP, m_bGridSnap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrefsDlg, CDialog)
	//{{AFX_MSG_MAP(CPrefsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrefsDlg message handlers

BOOL CPrefsDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   ( (CSpinButtonCtrl *)GetDlgItem( IDC_SPIN1 ) )->SetRange( 4, 20 );
	
   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
} // OnInitDialog
