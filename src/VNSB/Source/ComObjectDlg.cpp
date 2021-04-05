// ComObjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "ComObjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComObjectDlg dialog


CComObjectDlg::CComObjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComObjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComObjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CComObjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComObjectDlg)
	DDX_Control(pDX, IDC_OBJECTS, m_cObList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComObjectDlg, CDialog)
	//{{AFX_MSG_MAP(CComObjectDlg)
	ON_LBN_DBLCLK(IDC_OBJECTS, OnDblClkObjects)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComObjectDlg message handlers

//////////////////////////////////////////////////////////////////////
// CComObDesc Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComObDesc::CComObDesc()
{

}

CComObDesc::~CComObDesc()
{

}

CComObDesc::CComObDesc( LPCTSTR lpszCLSID, LPCTSTR lpszProgID )
{
   m_strCLSID = lpszCLSID;
   if( lpszProgID == NULL )
   {
      m_strProgID = lpszCLSID;
      m_strName = _T( "COM_Server" );
   }
   else
   {
      m_strProgID = lpszProgID;
      _stscanf( lpszProgID, _T( "%*[^.].%[^.]" ), m_strName.GetBuffer( 128 ) );
      m_strName.ReleaseBuffer();
   }
   m_mapProperties.RemoveAll();
} // CComObDesc

BOOL CComObjectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
   CString strKey;
   CComObDesc *pValue;
   POSITION pos = m_pMapComObDescs->GetStartPosition();
   while( pos != NULL )
   {
      m_pMapComObDescs->GetNextAssoc( pos, strKey, pValue );
      if( pValue != NULL )
         m_cObList.AddString( (LPCTSTR)strKey );
   }
   m_pComObDesc = NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CComObjectDlg::OnDblClkObjects() 
{
   OnOK();
} // OnDblClkObjects

void CComObjectDlg::OnOK()
{
   int nSel = m_cObList.GetCurSel();
   CString strName;
   m_cObList.GetText( nSel, strName );
   m_pMapComObDescs->Lookup( strName, m_pComObDesc );
   CDialog::OnOK();
} // OnOK

void CComObDesc::GetProperties()
{
   GUID guid;
   DWORD dwStatus;
   IDispatch *pDisp;
   ITypeInfo *ti;
   TYPEATTR *ta;
   BSTR bName, bInterface;
   int i;
   FUNCDESC *fd;

   CLSIDFromString( m_strCLSID.GetBuffer( m_strCLSID.GetLength() + 1 ), &guid );

   // Create an instance of it's IDispatch interface
   dwStatus = CoCreateInstance( guid, 0, CLSCTX_SERVER, IID_IDispatch, (void **)&pDisp );
   if( dwStatus != S_OK )
      goto err1;

   // Now get a pointer to the ITypeInfo interface
   dwStatus = pDisp->GetTypeInfo( 0, 0, &ti );
   if( dwStatus != S_OK )
      goto err2;

   // This gets the name of the interface, such as IInterface
   ti->GetDocumentation( -1, &bInterface, NULL, NULL, NULL );
   // Fill the TYPEATTR structure, describing the ITypeInfo interface
   dwStatus = ti->GetTypeAttr( &ta );
   if( dwStatus != S_OK )
      goto err3;

   //  Loop through each function available from the interface
   for( i = 0; i < ta->cFuncs; i++ )
   {
      // Fill the FUNCDESC structure based on the current function #
      dwStatus = ti->GetFuncDesc( i, &fd );
      if( dwStatus == S_OK )
      {
         dwStatus = ti->GetDocumentation( fd->memid, &bName, NULL, NULL, NULL );
         // Now determine if it's a property
         // Don't mess with properties that take multiple arguments
         if( ( fd->invkind == INVOKE_PROPERTYPUT || fd->invkind == INVOKE_PROPERTYPUTREF )
             && ( fd->cParams == 1 ) )
         {
            CString strName( bName );
            // Get a description of the parameter
            WORD nNSBType = GetTypeDesc( &fd->lprgelemdescParam[0].tdesc );
            if( ( nNSBType & NSBP_TYPE_ARRAY ) || ( nNSBType & NSBP_TYPE_POINTER ) )
               m_mapProperties.SetAt( bName, NSBP_TYPE_STRINGLIST );
            else
               m_mapProperties.SetAt( bName, nNSBType );
         }
         ti->ReleaseFuncDesc( fd ); //  Release FUNCDESC memory
      }
      SysFreeString( bName );       //  Release function name memory
   }

err3:
   SysFreeString( bInterface );     //  Release Interface name memory
   ti->Release();                   //  Release ITypeInfo
err2:
   pDisp->Release();                //  Release IDispatch
err1:
   return;
}

WORD CComObDesc::GetTypeDesc( TYPEDESC *pTypeDesc, int nIndirection )
{
   if( pTypeDesc->vt == VT_PTR )
   {
      // It's a pointer, find out what it points to
      return GetTypeDesc( pTypeDesc->lptdesc, ++nIndirection ) | NSBP_TYPE_POINTER;
   }

   if( pTypeDesc->vt == VT_SAFEARRAY )
   {
      //  It's a SAFEARRAY type find out what it's an array of
      return GetTypeDesc( pTypeDesc->lptdesc, ++nIndirection ) | NSBP_TYPE_ARRAY;
   }

/*
#define NSBP_TYPE_STRING1     0
#define NSBP_TYPE_STRINGN     1
#define NSBP_TYPE_STRINGLIST  2
#define NSBP_TYPE_BOOL        3
#define NSBP_TYPE_INT         4
#define NSBP_TYPE_DATE        5
#define NSBP_TYPE_TIME        6
#define NSBP_TYPE_COLOR       7
#define NSBP_TYPE_ALIGNMENT   8
#define NSBP_TYPE_STYLE       9
#define NSBP_TYPE_SCROLLBARS  10
#define NSBP_TYPE_FONTNAME    11
#define NSBP_TYPE_FONTSIZE    12
#define NSBP_TYPE_BORDERSTYLE 13
*/
   switch( pTypeDesc->vt )
   {
/*
   case VT_I1:       // char
   case VT_I2:       // short
   case VT_I4:       // long
   case VT_I8:       // __int64
*/
   case VT_UI1:      // BYTE
   case VT_UI2:      // unsigned short
   case VT_UI4:      // unsigned long
   case VT_UI8:      // unsigned __int64
   case VT_UINT:     // unsigned int
      return NSBP_TYPE_INT;
   case VT_I1:       // char
   case VT_I2:       // short
   case VT_I4:       // long
   case VT_I8:       // __int64
   case VT_INT:      // int
   case VT_R4:       // float
   case VT_R8:       // double
   case VT_CY:       // currency
      return NSBP_TYPE_STRING1;
   case VT_DATE:     return NSBP_TYPE_DATE;
   case VT_BSTR:     // BStr
   case VT_LPSTR:    // char *
   case VT_LPWSTR:   // TCHAR *
      return NSBP_TYPE_STRINGN;
   case VT_BOOL:     return NSBP_TYPE_BOOL;

   case VT_VARIANT:
   case VT_HRESULT:
   case VT_VOID:
   case VT_USERDEFINED:
   case VT_DECIMAL:
   case VT_UNKNOWN:
   case VT_DISPATCH:
   case VT_ERROR:
   default:
      // For lack of any editor (or clue
      return NSBP_TYPE_STRING1;
   }
}
