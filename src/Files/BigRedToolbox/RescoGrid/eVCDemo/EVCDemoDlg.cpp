// EVCDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EVCDemo.h"
#include "EVCDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEVCDemoDlg dialog

CEVCDemoDlg::CEVCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEVCDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEVCDemoDlg)
	m_Value = _T("");
	m_WordWrap = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEVCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEVCDemoDlg)
	DDX_Control(pDX, IDC_VALUE, m_ValueEdit);
	DDX_Control(pDX, IDC_GRID, m_Grid);
	DDX_Text(pDX, IDC_VALUE, m_Value);
	DDX_Check(pDX, IDC_WORDWRAP, m_WordWrap);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEVCDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CEVCDemoDlg)
	ON_BN_CLICKED(IDC_WORDWRAP, OnWordwrap)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEVCDemoDlg message handlers

BOOL CEVCDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	m_Grid.SetCols(2);
	m_Grid.SetRows(1);
	m_Grid.SetTextMatrix(0, 0, _T("No."));
	m_Grid.SetTextMatrix(0, 1, _T("Value"));
	m_Value = _T("");

	UpdateData(FALSE);

	m_ValueEdit.SetFocus();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CEVCDemoDlg::OnWordwrap() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	m_Grid.SetWordWrap(m_WordWrap);

	m_ValueEdit.SetFocus();
}

void CEVCDemoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	CString item;
	VARIANT v;

	item.Format(_T("%d\t%s"), m_Grid.GetRows(), m_Value);

	V_VT(&v) = VT_I4;
	V_I4(&v) = m_Grid.GetRows();

	m_Grid.AddItem(item, &v);

	m_Value = _T("");
	UpdateData(FALSE);

	m_ValueEdit.SetFocus();
}

void CEVCDemoDlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	if (m_Grid.GetRow() >= 0 && m_Grid.GetRowSel() >= 0)
	{
		int s, e;
		if (m_Grid.GetRow() < m_Grid.GetRowSel())
		{
			s = m_Grid.GetRow() + 1;
			e = m_Grid.GetRowSel() + 1;
		}
		else
		{
			s = m_Grid.GetRowSel() + 1;
			e = m_Grid.GetRow() + 1;
		}

		for (int i = s; i <= e; i++)
		{
			m_Grid.RemoveItem(s);
		}

		for (i = 1; i < m_Grid.GetRows(); i++)
		{
			CString n;
			n.Format(_T("%d"), i);
			m_Grid.SetTextMatrix(i, 0, n);
		}

		m_Grid.SetColSel(-1);
		m_Grid.SetRowSel(-1);
		m_Grid.SetCol(0);
		m_Grid.SetRow(0);
	}
	else
		AfxMessageBox(_T("No row selected!"));

	m_ValueEdit.SetFocus();
}

BEGIN_EVENTSINK_MAP(CEVCDemoDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CEVCDemoDlg)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()
