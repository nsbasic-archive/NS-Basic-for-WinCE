// VNSBDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "VNSBDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNSBFormNameDlg dialog


CNSBFormNameDlg::CNSBFormNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNSBFormNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNSBFormNameDlg)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CNSBFormNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNSBFormNameDlg)
	DDX_Text(pDX, IDC_FORMNAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNSBFormNameDlg, CDialog)
	//{{AFX_MSG_MAP(CNSBFormNameDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNSBFormNameDlg message handlers

extern void SetWaitCursor(BOOL bWait); //this is in vnsb.cpp - it should probably be someplace else.

BOOL CNSBFormNameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

   SetActiveWindow();
   SetWaitCursor( false );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
} // OnInitDialog
