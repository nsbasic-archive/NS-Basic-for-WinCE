// VNSBDoc.cpp : implementation of the CVNSBDoc class
//

#include "stdafx.h"
#include "VNSB.h"

#include "VNSBDoc.h"
#include "MainFrm.h"
#include "VNSBDlg.h"
#include "MenuEditorDlg.h"
#include "CodeDlg.h"
//#include "ComObjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ROTATELEFT(x,count)  ( ( (x) << count ) | ( (x) >> ( ( 8 * sizeof( x ) ) - count ) ) )
#define ROTATERIGHT(x,count) ( ( (x) >> count ) | ( (x) << ( ( 8 * sizeof( x ) ) - count ) ) )

#define FLIPNIBBLE(x) ( ( ( x&0xf0 >> 4 ) | ( x&0x0f << 4 ) ) )

#define FLIPWORD(x) ( ( FLIPNIBBLE( (x&0xFF00) >> 8 ) ) | ( ( FLIPNIBBLE(x&0xFF) ) << 8 ) )

#define FLIPLONG(x) ( ( ( FLIPWORD( (x&0xFFFF0000) >> 16 ) ) ) | ( ( FLIPWORD(x&0xFFFF) << 16 ) ) )

#define kNSBFileFlagV1 0xFF0000DD
#define kNSBFileFlagV2 0xFF0011DD
#define kNSBFileFlagV3 0xFF0022DD

extern unsigned long giSerialNumber;
extern bool gbProtectedFile;	//Is the file protected (not editable?)

#ifdef _POCKET
extern HANDLE ghMutex;
#endif
/////////////////////////////////////////////////////////////////////////////
// CVNSBDoc

IMPLEMENT_DYNCREATE(CVNSBDoc, CDocument)

BEGIN_MESSAGE_MAP(CVNSBDoc, CDocument)
	//{{AFX_MSG_MAP(CVNSBDoc)
	ON_COMMAND(ID_FORM_MENU, OnFormMenu)
	ON_UPDATE_COMMAND_UI(ID_FORM_MENU, OnUpdateFormMenu)
	ON_COMMAND(ID_FORM_ADD, OnFormAdd)
	ON_UPDATE_COMMAND_UI(ID_FORM_ADD, OnUpdateFormAdd)
	ON_COMMAND(ID_FORM_DELETE, OnFormDelete)
	ON_UPDATE_COMMAND_UI(ID_FORM_DELETE, OnUpdateFormDelete)
	ON_COMMAND(ID_FORM_SETDEFAULT, OnFormSetdefault)
	ON_UPDATE_COMMAND_UI(ID_FORM_SETDEFAULT, OnUpdateFormSetdefault)
	ON_COMMAND(ID_FORM_EXIT, OnFormExit)
	ON_UPDATE_COMMAND_UI(ID_FORM_EXIT, OnUpdateFormExit)
	ON_UPDATE_COMMAND_UI(ID_OBJECTS_SHOWCODE, OnUpdateObjectsShowCode)
	ON_COMMAND(ID_OBJECTS_SHOWCODE, OnObjectsShowCode)
	ON_COMMAND(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVNSBDoc construction/destruction

CVNSBDoc::CVNSBDoc()
{
   m_mapComObDescs.RemoveAll();
   m_mapComObNames.RemoveAll();
   m_pForm = NULL;
   // Registry monkeying, for now...
   HKEY hKey;
   DWORD dwDisp, dwGrid, dwSize;
   RegCreateKeyEx( HKEY_CURRENT_USER, _T( "Software\\NSBasic\\NSBasic" ), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp );
   if( RegQueryValueEx( hKey, _T( "Grid" ), 0, &dwDisp, (unsigned char *)&dwGrid, &dwSize ) == ERROR_SUCCESS )
      m_nGrid = dwGrid;
   else
   {
      m_nGrid = 10;
      dwGrid = m_nGrid;
      RegSetValueEx( hKey, _T( "Grid" ), 0, REG_DWORD, (unsigned char *)&dwGrid, sizeof( DWORD ) );
   }
   RegCloseKey( hKey );
} // CVNSBDoc

CVNSBDoc::~CVNSBDoc()
{
   CString strKey;
   CComObDesc *pValue;
   POSITION pos = m_mapComObDescs.GetStartPosition();
   while( pos != NULL )
   {
      m_mapComObDescs.GetNextAssoc( pos, strKey, pValue );
      m_mapComObDescs.RemoveKey( (LPCTSTR)strKey );
      delete pValue;
   }
}

BOOL CVNSBDoc::OnNewDocument()
{
   if( !CDocument::OnNewDocument() )
      return FALSE;

   while( m_mapForms.GetCount() < 1 )
      OnFormAdd();
// TODO: Fix problem where switching to a new project doesn't update the visible form
   UpdateAllViews( NULL, MAKEWPARAM( HINT_SWITCH_FORM, 0 ) );
   return TRUE;
} // OnNewDocument


NSBObject CVNSBDoc::AddObjectList[NUM_NSBOBJECTS] = NSB_OBJECTS;

/////////////////////////////////////////////////////////////////////////////
// CVNSBDoc serialization

void CVNSBDoc::Serialize(CArchive& ar)
{
   ASSERT_VALID( this );
   if( ar.IsStoring() )
   {
      WriteToArchive( ar );
   }
   else
   {
      CFile* pFile = ar.GetFile();
      ASSERT( pFile->GetPosition() == 0 );
      DWORD nFileSize = pFile->GetLength();

      // ReadFromArchive takes the number of characters as argument
      ReadFromArchive( ar, (UINT)nFileSize / sizeof( TCHAR ) );
   }
   ASSERT_VALID( this );
}

/////////////////////////////////////////////////////////////////////////////
// CVNSBDoc diagnostics

#ifdef _DEBUG
void CVNSBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVNSBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVNSBDoc commands

BOOL CVNSBDoc::OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo )
{
//   if( nCode == WM_LBUTTONDBLCLK )
//      AfxMessageBox( _T( "DblClk" ) );
   // If pHandlerInfo is NULL, then handle the message
   if( pHandlerInfo == NULL )
   {
      // Filter the commands sent to add object options
      if( ( nID >= (UINT)AddObjectList[0].m_nObjectID )
        && ( nID <= (UINT)AddObjectList[NUM_NSBOBJECTS - 1].m_nObjectID ) )
      {
         if( nCode == CN_COMMAND )
            DoToolsAddObject( nID - (UINT)AddObjectList[0].m_nObjectID, nID );
         else if( nCode == CN_UPDATE_COMMAND_UI )
            DoUpdateToolsAddObject( (CCmdUI *)pExtra );
         return TRUE;
      }
      else if( ( nID >= (UINT)ID_FIRST_FORM )
             && ( nID <= (UINT)( ID_FIRST_FORM + m_mapForms.GetCount() - 1 ) ) )
      {
         if( nCode == CN_COMMAND )
            DoFormSwitch( nID - (UINT)ID_FIRST_FORM, nID );
         else if( nCode == CN_UPDATE_COMMAND_UI )
            DoUpdateFormSwitch( nID - (UINT)ID_FIRST_FORM, (CCmdUI *)pExtra );
         return TRUE;
      }
   }
   return CDocument::OnCmdMsg( nID, nCode, pExtra, pHandlerInfo );
} // OnCmdMsg

void CVNSBDoc::DoToolsAddObject( int nIndex, UINT nID )
{
   int i, nObject;
   if( AddObjectList[nIndex].m_nFlag & NSBOB_TYPE_NSB )
   {
      for( i = 0, nObject = 0; i < m_aForms.GetSize(); i++ )
      {
         CNSBForm *pForm = m_mapForms[m_aForms[i]];
         nObject += pForm->NumObjects( AddObjectList[nIndex].m_nObjectID );
      }
      nObject = m_pForm->AddFormObject( AddObjectList[nIndex], nObject );
      UpdateAllViews( NULL, MAKEWPARAM( HINT_OBJECT_ADD, nObject ) );
      SetModifiedFlag();
   }
   else if( AddObjectList[nIndex].m_nObjectID == NSBOB_COM_OB )
   {
      if( m_mapComObDescs.IsEmpty() )
         GetComServers();
      if( m_mapComObDescs.IsEmpty() )
      {
         AfxMessageBox( _T( "No ActiveX Controls or COM Servers registered." ) );
         return;
      }
      CComObjectDlg Dlg;
      Dlg.m_pMapComObDescs = &m_mapComObDescs;
      if( Dlg.DoModal() == IDOK )
      {
         if( Dlg.m_pComObDesc == NULL )
            return;
         for( i = 0, nObject = 0; i < m_aForms.GetSize(); i++ )
         {
            CNSBForm *pForm = m_mapForms[m_aForms[i]];
            nObject += pForm->NumObjects( 0, (LPCTSTR)Dlg.m_pComObDesc->m_strProgID );
         }
         // Combine "Prog.ID {CLS-ID}" to pass as object type - to be parsed by CFormObject constructor
         CString strObjectType( Dlg.m_pComObDesc->m_strProgID + _T( " " ) + Dlg.m_pComObDesc->m_strCLSID );
         // Create generic, unique name for object
         CString strObjectName; strObjectName.Format( _T( "%s%d" ), (LPCTSTR)Dlg.m_pComObDesc->m_strName, nObject + 1 );
         // Add object to form
         CNSBFormObject *pFormOb = m_pForm->AddFormObject( (LPCTSTR)strObjectType,
                                                           (LPCTSTR)strObjectName,
                                                           CRect( 5, 30, 120, 53 ) );
         // Add a pointer to the object's description structure
         pFormOb->m_pComObDesc = Dlg.m_pComObDesc;
         // Display last object added to form
         UpdateAllViews( NULL, MAKEWPARAM( HINT_OBJECT_ADD, m_pForm->NumObjects() - 1 ) );
         SetModifiedFlag();
      }
   }
   else
      AfxMessageBox( AddObjectList[nIndex].m_strObjectType );
} // DoAddObject

void CVNSBDoc::DoUpdateToolsAddObject( CCmdUI *pCmdUI )
{
   pCmdUI->Enable( TRUE );
} // DoUpdateAddObject

void CVNSBDoc::DeleteContents() 
{
   POSITION pos = m_mapForms.GetStartPosition();
   while( pos != NULL )
   {
      CString strKey;
      CNSBForm *pForm;
      m_mapForms.GetNextAssoc( pos, strKey, pForm );
      delete pForm;
   }
   m_mapForms.RemoveAll();
   m_aForms.RemoveAll();
   if( m_pForm )
      delete m_pForm;
   m_pForm = NULL;

	CDocument::DeleteContents();
} // DeleteContents

void CVNSBDoc::OnFormMenu() 
{
   CMenuEditorDlg dlg;
   dlg.m_pForm = m_pForm;
   if( dlg.DoModal() == IDOK )
      SetModifiedFlag();
} // OnAddMenu

void CVNSBDoc::OnUpdateFormMenu( CCmdUI* pCmdUI )
{
   CString text;
#ifdef _POCKET
   text.LoadString( m_pForm->m_aFormMenu.GetSize() ? IDS_FORM_EDITMENU_POCKET : IDS_FORM_ADDMENU_POCKET );
#else
   text.LoadString( m_pForm->m_aFormMenu.GetSize() ? IDS_FORM_EDITMENU : IDS_FORM_ADDMENU );
#endif
   pCmdUI->SetText( text );
   pCmdUI->Enable();
} // OnUpdateAddMenu

void CVNSBDoc::SetFormMenu()
{
#ifdef VNSB_STANDALONE
   CMenu *pFormMenu = ( (CMainFrame*)AfxGetMainWnd() )->GetMenu()->GetSubMenu( 3 );
#else
   CMenu *pFormMenu = ( (CMainFrame*)AfxGetMainWnd() )->GetMenu()->GetSubMenu( 0 );
#endif

   // First remove all the chaff...
   UINT nForm;
   for( nForm = 0; nForm < pFormMenu->GetMenuItemCount(); nForm++ )
      if( pFormMenu->GetMenuItemID( nForm ) == 0 )
      {
         nForm++;
         break;
      }
#ifdef _POCKET
   while( pFormMenu->GetMenuItemID( nForm ) != 0 )
      pFormMenu->DeleteMenu( nForm, MF_BYPOSITION );
#else
#  ifdef VNSB_STANDALONE
   while( nForm < pFormMenu->GetMenuItemCount() )
      pFormMenu->DeleteMenu( nForm, MF_BYPOSITION );
#  else
   while( pFormMenu->GetMenuItemID( nForm ) != 0 )
      pFormMenu->DeleteMenu( nForm, MF_BYPOSITION );
#  endif
#endif

   // Insert one menu item per form
   CString strKey;
   for( int i = 0; i < m_aForms.GetSize(); i++ )
   {
#ifdef _POCKET
      strKey = m_aForms[i];
#else
      strKey.Format( ( i < 9 ? _T( "&%d %s" ) : _T( "%d %s" ) ), i + 1, m_aForms[i] );
#endif
      if( m_aForms[i] == m_strDefaultForm )
         strKey += _T( " (Default)" );
#ifdef _POCKET
      pFormMenu->InsertMenu( nForm++, MF_BYPOSITION | MF_STRING, ID_FIRST_FORM + i, strKey );
#else
#  ifdef VNSB_STANDALONE
      pFormMenu->AppendMenu( MF_STRING, ID_FIRST_FORM + i, strKey );
#  else
      pFormMenu->InsertMenu( nForm++, MF_BYPOSITION | MF_STRING, ID_FIRST_FORM + i, strKey );
#  endif
#endif
   }
} // SetFormMenu

void CVNSBDoc::OnFormAdd() 
{
   int i = m_mapForms.GetCount() + 1;
   CString strName;

   strName.Format( _T( "Form%d" ), i );
   CNSBForm *pForm = NULL;
   m_mapForms.Lookup( strName, pForm );
   while( pForm != NULL )
   {
      i++;
      strName.Format( _T( "Form%d" ), i );
      m_mapForms.Lookup( strName, pForm );
   }
   CNSBFormNameDlg getName;
   getName.m_strName = strName;
   if( getName.DoModal() == IDOK )
   {
      if( m_mapForms.Lookup( getName.m_strName, pForm ) )
      {
         MessageBox( NULL, _T( "Form names must be unique" ), _T( "VNSB" ), MB_ICONSTOP | MB_ICONERROR | MB_OK );
         return;
      }
      AddForm( getName.m_strName );
      SetFormMenu();
      UpdateAllViews( NULL, MAKEWPARAM( HINT_SWITCH_FORM, 0 ) );
   }
} // OnFormAdd

void CVNSBDoc::OnUpdateFormAdd(CCmdUI* pCmdUI) 
{
   pCmdUI->Enable();
} // OnUpdateFormAdd

void CVNSBDoc::OnFormDelete() 
{
   for( int i = 0; i < m_aForms.GetSize(); i++ )
      if( m_pForm->m_strName == m_aForms[i] )
      {
         m_aForms.RemoveAt( i );
         break;
      }
   m_mapForms.RemoveKey( m_pForm->m_strName );
   if( m_strDefaultForm == m_pForm->m_strName )
      m_strDefaultForm.Empty();
   delete m_pForm;

   POSITION pos = m_mapForms.GetStartPosition();
   CString strKey;
   m_mapForms.GetNextAssoc( pos, strKey, m_pForm );

   SetFormMenu();
   UpdateAllViews( NULL, MAKEWPARAM( HINT_SWITCH_FORM, 0 ) );
   SetModifiedFlag();
} // OnFormDelete

void CVNSBDoc::OnUpdateFormDelete(CCmdUI* pCmdUI) 
{
   pCmdUI->Enable( m_mapForms.GetCount() > 1 );
} // OnUpdateFormDelete

void CVNSBDoc::OnFormSetdefault() 
{
   if( m_strDefaultForm == m_pForm->m_strName )
      m_strDefaultForm.Empty();
   else
      m_strDefaultForm = m_pForm->m_strName;
   SetModifiedFlag();
   SetFormMenu();
} // OnFormSetDefault

void CVNSBDoc::OnUpdateFormSetdefault( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( TRUE );
   if( m_pForm->m_strName == m_strDefaultForm )
      pCmdUI->SetText( _T( "Clear Default Form" ) );
   else
      pCmdUI->SetText( _T( "Set Default Form" ) );
} // OnUpdateFormSetDefault

void CVNSBDoc::DoFormSwitch( int nIndex, UINT nID )
{
   if( m_pForm != NULL )
      m_pForm->Hibernate();
   m_mapForms.Lookup( m_aForms[nIndex], m_pForm );
   m_pForm->ParseCode();
   UpdateAllViews( NULL, MAKEWPARAM( HINT_SWITCH_FORM, nID ) );
} // DoFormSwitch

void CVNSBDoc::DoUpdateFormSwitch( int nIndex, CCmdUI *pCmdUI )
{
   pCmdUI->Enable( TRUE );
   if( m_aForms[nIndex] == m_pForm->m_strName )
      pCmdUI->SetCheck( 1 );
   else
      pCmdUI->SetCheck( 0 );
} // DoUpdateFormSwitch

BOOL CVNSBDoc::GenerateCode( CString &strCode )
{
   CString strTemp, strGrid;

   if( !m_strDefaultForm.IsEmpty() )
      strCode += m_strDefaultForm + _T( "_Show  'Default Form\r\n\r\n" );

   CNSBForm *pForm;
   for( int i = 0; i < m_aForms.GetSize(); i++ )
   {
      m_mapForms.Lookup( m_aForms[i], pForm );
      if( pForm->m_strCode.IsEmpty() )
         pForm->GenerateCode();
      strCode += pForm->m_strCode;
   }
   m_pForm->m_strCode.Empty();

   strTemp.LoadString( IDS_CODE_BEGIN_GENERATED );
   strGrid.Format( _T( "\r\n'GRID %d\r\n\r\n" ), m_nGrid );
   strCode = strTemp + strGrid + strCode;
   strTemp.LoadString( IDS_CODE_END_GENERATED );
   strCode += strTemp + _T( "\r\n" );
#ifdef _DEBUG
   afxDump << strCode << _T( "\n" ); // #ifdef _DEBUG
#endif
   return TRUE;
} // GenerateCode

void CVNSBDoc::ReadFromArchive( CArchive &ar, UINT nLen )
{
	ASSERT_VALID( this );

	LPVOID hText = LocalAlloc( LPTR, ( nLen + 1 ) * sizeof( TCHAR ) );
	DWORD dwChecksum, dwFileFlag, dwFileExtra1, dwFileExtra2; //, dwChecksumSeed;
	LPTSTR lpszActualText;
	UINT nRealLen = nLen;
	DWORD dwSerialNumFromFile;

	ASSERT( hText );

	if( hText == NULL )
		AfxThrowMemoryException();

	LPTSTR lpszText = (LPTSTR)LocalLock( hText );
	ASSERT( lpszText != NULL );

	lpszActualText = lpszText;

	// pop off our DWORD which is our checksum..
	ar.Read( &dwChecksum, sizeof( DWORD ) );
	dwFileFlag = dwChecksum;
	nLen -= ( sizeof( DWORD ) / sizeof( TCHAR ) );
	if( dwChecksum == kNSBFileFlagV1 || dwChecksum == kNSBFileFlagV2 || dwChecksum == kNSBFileFlagV3 )
	{
		ar.Read( &dwChecksum, sizeof( DWORD ) );
		nLen -= ( sizeof( DWORD ) / sizeof( TCHAR ) );
	}
	else
   { //oops!  Not one of my files, so we need to give back the four chars we stole!
		memcpy( lpszText, &dwChecksum, sizeof( DWORD ) );
		lpszActualText = (TCHAR *)( (char *)lpszActualText + sizeof( DWORD ) );	
		dwChecksum = dwFileFlag = 0;
	}
	if( dwFileFlag == kNSBFileFlagV3 )
   { //eight more bytes in the header for v3 format!
		ar.Read( &dwFileExtra1, sizeof( DWORD ) );
		nLen -= ( sizeof( DWORD ) / sizeof( TCHAR ) );
		dwSerialNumFromFile = ROTATERIGHT( FLIPLONG( ROTATELEFT( ( dwFileExtra1 ), 3 ) ), 6 ) ^ 0xF163808F;
		ar.Read( &dwFileExtra2, sizeof( DWORD ) );
		nLen -= ( sizeof( DWORD ) / sizeof( TCHAR ) );
	}
	// MMD 2002-10-15 This is not needed in VNSB
	/*
	switch( dwFileFlag )
	{
	case kNSBFileFlagV3:
		dwChecksumSeed = giSerialNumber;
//      dwChecksumSeed = dwSerialNumFromFile;
		break;
	default:
		dwChecksumSeed = 0xF163808F;
		break;
	}
	*/

	if( ar.Read( lpszActualText, nLen * sizeof( TCHAR ) ) != nLen * sizeof( TCHAR ) )
	{
		LocalUnlock( hText );
		LocalFree( hText );
		AfxThrowArchiveException( CArchiveException::endOfFile );
	}
	// Replace the editing edit buffer with the newly loaded data
	lpszText[nRealLen] = '\0';

	if( dwFileFlag == kNSBFileFlagV2 || dwFileFlag == kNSBFileFlagV3 )
   {  //encrypted v2 or v3, so de-encrypt it
      doDecryptV2( lpszText, nLen, dwFileFlag );
	}

	// MMD 2002-10-15 This is not needed in VNSB
	//DWORD dwCheck = doCalculateChecksum( lpszText, dwChecksumSeed );
	
/*
	{
      TCHAR szBuf[200];
      wsprintf( szBuf,L"SN = %lu fromfile = %lu\ndwcheck = %lu dwchecksum = %lu",
                giSerialNumber, dwSerialNumFromFile, dwCheck, dwChecksum );
      ::MessageBox(0,szBuf,L"",MB_OK);
	}

	if( dwFileFlag == kNSBFileFlagV3 && dwCheck != dwChecksum )
	{
		//gbCloseOnEnd=true;
		//gbAllowSave=false;
		//gbShowEditorWindow=false;
		gbProtectedFile = true;
	}
	else
	{
		//SetFlagsForLaunchMode();
		gbProtectedFile = false;
	}
	
	if( dwCheck == dwChecksum )
	{
		gbFileHasValidChecksum = true;
	}
*/	

	// MMD 2002-10-15 This is not needed in VNSB
	//gbProtectedFile = ( dwCheck != dwChecksum );
/*
   if( gbProtectedFile )
      MessageBox( NULL, _T( "Protected File" ), _T( "" ), MB_OK );
   else
      MessageBox( NULL, _T( "Unprotected File" ), _T( "" ), MB_OK );
*/	

	// MMD 2002-10-15 This is not needed in VNSB
	//if( !gbProtectedFile )
	{
		ParseCode( lpszText );
		UpdateAllViews( NULL );
	}
	LocalUnlock( hText );
	LocalFree( hText );
	ASSERT_VALID( this );
} // ReadFromArchive

void CVNSBDoc::WriteToArchive( CArchive &ar )
{
   DWORD dwSeed, dwFileFlag;

   ASSERT_VALID( this );

   CString strCode;
   if( !GenerateCode( strCode ) )
   {
      MessageBox( NULL, _T( "Unable to generate code" ), _T( "VNSB" ), MB_ICONSTOP | MB_ICONERROR | MB_OK );
      return;
   }
//   AfxMessageBox( strCode );
   if( !m_strCode.IsEmpty() )
      strCode = m_strCode + _T( "\r\n" ) + strCode;
      
   LPTSTR lpszText = strCode.LockBuffer();
   ASSERT( lpszText != NULL );

   UINT nLen = strCode.GetLength();
   TRY
   {
      DWORD dwChecksum;

      if( 0 ) //gdwPrefFlags & kPrefSaveProtected )
      {
         dwFileFlag = kNSBFileFlagV3;
         ar.Write( &dwFileFlag, sizeof( DWORD ) );

         dwSeed = giSerialNumber;
         dwChecksum = doCalculateChecksum( lpszText, dwSeed );
         ar.Write( &dwChecksum, sizeof( DWORD ) );

         dwChecksum = ROTATERIGHT( FLIPLONG( ROTATELEFT( ( giSerialNumber ^ 0xF163808F ), 6 ) ), 3 );

         ar.Write( &dwChecksum, sizeof( DWORD ) );
         dwChecksum = 0;
         ar.Write( &dwChecksum, sizeof( DWORD ) );
      }
      else
      {
         dwFileFlag = kNSBFileFlagV2;
         ar.Write( &dwFileFlag, sizeof( DWORD ) );
         dwSeed = 0xf163808f;
         dwChecksum = doCalculateChecksum( lpszText, dwSeed );
         ar.Write( &dwChecksum, sizeof( DWORD ) );
      }

      //ar.Write( lpszText, nLen * sizeof( TCHAR ) );
      doWriteEncryptedBytesV2( ar, lpszText, nLen, dwFileFlag );
   }
   CATCH_ALL( e )
   {
      strCode.UnlockBuffer();
      THROW_LAST();
   }
   END_CATCH_ALL
   strCode.UnlockBuffer();
   ASSERT_VALID( this );
} // WriteToArchive

DWORD CVNSBDoc::doCalculateChecksum(TCHAR *szBuf, DWORD dwSeed)
{
   const TCHAR *szText = szBuf;
   DWORD dwChecksum;

   dwChecksum = dwSeed;//0xf163808f;

   while( *szBuf )
   {
      dwChecksum += *szBuf;
      dwChecksum = ( dwChecksum << 1 ) + ( ( dwChecksum & 0x80000000 ) >> 31 );
      szBuf++;
   }
   return dwChecksum;
} // doCalculateChecksum

BOOL CVNSBDoc::ParseCode( LPCTSTR lpszText )
{
   CString strTemp, strParse;
   INT i, nLen, nState;

   m_strCode = lpszText;
   nLen = m_strCode.GetLength();

   // First, get pre-code
   strTemp.LoadString( IDS_CODE_BEGIN_GENERATED );
   if( ( i = m_strCode.Find( strTemp ) ) < 0 )
   {
      // No GENERATED_CODE, so just add a first form.
      if( m_pForm == NULL )
      {
         while( m_mapForms.GetCount() < 1 )
            OnFormAdd();
         m_strDefaultForm = m_aForms[0];
      }
      SetFormMenu();
      return TRUE;
   }
   strParse = m_strCode.Mid( i + strTemp.GetLength() );
   m_strCode = m_strCode.Left( i );
   m_strCode.TrimRight();
   if( !m_strCode.IsEmpty() )
      m_strCode += _T( "\r\n" );

   // Now, snip post-code
   strTemp.LoadString( IDS_CODE_END_GENERATED );
   if( ( i = strParse.Find( strTemp ) ) >= 0 )
   {
      nLen = strParse.GetLength();
      strTemp = strParse.Mid( i + strTemp.GetLength() );
      strTemp.TrimRight();
      strTemp.TrimLeft();
      if( !strTemp.IsEmpty() )
      {
         strTemp += _T( "\r\n" );
         if( m_strCode.IsEmpty() )
            m_strCode = strTemp;
         else
            m_strCode += _T( "\r\n" ) + strTemp;
      }
      strParse = strParse.Left( i );
      strParse.TrimLeft();
      strParse.TrimRight();
   }
   strParse += _T( "\r\nVXNXSXB\r\n" );
#ifdef _DEBUG
afxDump << m_strCode;  // #ifdef _DEBUG
afxDump << strParse;   // #ifdef _DEBUG
#endif

   CString strForm, strKey, strFormName;
   // Set state variable and loop through parse code
   strForm.Empty();
   nState = PARSE_STATE_GRID_SIZE;

   strTemp = strParse.SpanExcluding( _T( "\r\n" ) );
//afxDump << _T( "|" ) << strTemp << _T( "|\n" );
   strParse = strParse.Mid( strTemp.GetLength() + 2 );

   strKey = strTemp.SpanExcluding( _T( " (." ) );
   strKey.TrimLeft();
   strKey.MakeUpper();
   // Loop through each line and parse
   // When a pattern is matched, parse it and break
   // if no pattern match
   while( nState < PARSE_STATE_EXIT )
   {
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
      switch( nState )
      {
      case PARSE_STATE_GRID_SIZE:
         nState = PARSE_STATE_DEFAULT_FORM;
         if( strKey == _T( "'GRID" ) )
         {
            _stscanf( strTemp, _T( "'GRID %d" ), &m_nGrid );
            if( m_nGrid < 4 )
               m_nGrid = 4;
            if( m_nGrid > 20 )
               m_nGrid = 20;
            break;
         }
         else
            continue;
      case PARSE_STATE_DEFAULT_FORM:  // Looking for <Formname>, stop at DIM
//afxDump << _T( "|-0- " ) << strTemp << _T( " -0-|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
         // Skip blank lines and comments, when searching for default form
         if( strKey.IsEmpty() || strKey[0] == '\'' || strKey == _T( "REM" ) )
            break;
         if( strKey == _T( "DIM" ) )
         {
            nState = PARSE_STATE_NEW_FORM;
            continue;
         }
         if( strKey.Right( 5 ) != _T( "_SHOW" ) )
            break;
         m_strDefaultForm = strTemp.Left( strKey.GetLength() - 5 );
//afxDump << _T( "m_strDefaultForm: " ) << m_strDefaultForm << _T( "\n" );
//afxDump << _T( "Default Form: " ) << m_strDefaultForm << _T( "\n" );
         nState = PARSE_STATE_NEW_FORM;
         break;
      case PARSE_STATE_NEW_FORM:  // Looking for DIM, stop at VXNXSXB
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
         if( m_pForm == NULL && strKey.IsEmpty() )
            break;
         if( strKey == _T( "VXNXSXB" ) )
         {
            if( !strForm.IsEmpty() )
            {
               strForm.TrimRight();
               m_pForm->m_strCode = strForm + _T( "\r\n" );
//afxDump << m_pForm->m_strName << _T( ":\n" ) << m_pForm->m_strCode;
            }
            nState = PARSE_STATE_EXIT;
            continue;
         }
         if( strKey != _T( "DIM" ) )
         {
            strForm += strTemp + _T( "\r\n" );
            break;
         }
         _stscanf( strTemp, _T( "%*[dimDIM] %lS" ), strFormName.GetBuffer( 64 ) );
         strFormName.ReleaseBuffer();
//afxDump << _T( "Form Name: " ) << strFormName << _T( "\n" );
         if( !strForm.IsEmpty() )
         {
            strForm.TrimRight();
            m_pForm->m_strCode = strForm + _T( "\r\n" );
//afxDump << m_pForm->m_strName << _T( ":\n" ) << m_pForm->m_strCode;
         }
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
         AddForm( strFormName );
         strForm = strTemp + _T( "\r\n" );
         break;
      }
      strTemp = strParse.SpanExcluding( _T( "\r\n" ) );
//afxDump << _T( "|" ) << strTemp << _T( "|\n" );
      if( strTemp.GetLength() != strParse.GetLength() )
         strParse = strParse.Mid( strTemp.GetLength() + 2 );

      strKey = strTemp.SpanExcluding( _T( " (." ) );
//afxDump << _T( "Raw Keyword: " ) << strKey << _T( "\n" );
      strKey.TrimLeft();
      strKey.MakeUpper();
   }
   if( m_pForm == NULL )
   {
      OnFormAdd();
      if( m_aForms.GetSize() == 1 && m_strDefaultForm.IsEmpty() )
         m_strDefaultForm = m_aForms[0];
   }
   SetFormMenu();
   m_pForm->ParseCode();
//   afxDump << _T( "\n\n" ) << m_pForm->m_strName << _T( ":\n" ) << m_pForm->m_strCode << _T( "\n" );

   return TRUE;
} // ParseCode

void CVNSBDoc::doDecryptV2( TCHAR *szBuf, UINT nLen, DWORD dwFileFlag )
{
   int iNumBits = ( dwFileFlag == kNSBFileFlagV2 ) ? 3 : 5;
   int nTCHARSize = sizeof( TCHAR );
   TCHAR *pBuf = szBuf;
   while( nLen )
   {
      if( nTCHARSize == 2 )
         *pBuf = (unsigned short)FLIPWORD( *pBuf );
      else
         *pBuf = (unsigned short)FLIPNIBBLE( *pBuf );

      *pBuf = ROTATERIGHT( *pBuf, iNumBits );
      *pBuf++;
      nLen--;
   }
} // doDecryptV2

void CVNSBDoc::doWriteEncryptedBytesV2( CArchive &ar, const TCHAR *szBuf, UINT nLen, DWORD dwFileFlag )
{
   int iNumBits = ( dwFileFlag == kNSBFileFlagV2 ) ? 3 : 5;
   const TCHAR *pBuf = szBuf;
   int nTCHARSize = sizeof( TCHAR );
   while( nLen )
   {
      TCHAR c = ROTATELEFT( *pBuf, iNumBits );
      if( nTCHARSize == 2 )
         c = (unsigned short)FLIPWORD( c );
      else
         c = (unsigned short)FLIPNIBBLE( c );
      ar.Write( &c, sizeof( TCHAR ) );

      pBuf++;
      nLen--;
   }
} // doWriteEncryptedBytesV2

void CVNSBDoc::AddForm( CString strName )
{
   m_pForm = new CNSBForm( strName );
   m_mapForms[strName] = m_pForm;
   m_aForms.Add( strName );
   SetModifiedFlag();
} // AddForm

void CVNSBDoc::OnFormExit() 
{
#ifdef _POCKET
   if( IsModified() )
      if( !DoFileSave() )
         return;
#else
   if( !SaveModified() )
      return;
#endif
   SHELLEXECUTEINFO sei;
   memset( &sei, 0, sizeof( SHELLEXECUTEINFO ) );

   sei.cbSize = sizeof( SHELLEXECUTEINFO );
#if _WIN32_WCE >= 211
   sei.fMask  = SEE_MASK_NOCLOSEPROCESS;
#endif
   sei.hwnd   = AfxGetMainWnd()->m_hWnd;
   sei.lpVerb = _T( "OPEN" );
//   sei.lpFile = _T( "\\Windows\\pword.exe" );
//   sei.lpFile = _T( "\\VNSB.exe" );
//   sei.lpFile = _T( "\\Program Files\\NS Basic\\basic.exe" );
   const TCHAR *szTempPath = _T( "\\Temp\\NSB_TEMP.nsb" );
   TCHAR szKey[256], szVNSBPath[MAX_PATH];
   HKEY hSubKey;
   LONG lResult;

   _tcscpy( szKey, _T( "\\Software\\apps\\NSB Basic" ) );
   lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE, szKey, 0, 0, &hSubKey );
   if( lResult != ERROR_SUCCESS )
   {
      //use default path
      _tcscpy( szVNSBPath, _T( "\\Program Files\\NS Basic\\basic.exe" ) );
   }
   else
   {
      TCHAR strValueName[MAX_PATH];
      DWORD dwValueNameLength = sizeof( strValueName ) / sizeof( TCHAR );
      DWORD dwType;

      lResult = RegQueryValueEx( hSubKey, _T( "InstallDir" ), 0, &dwType,
                                 (unsigned char *)strValueName, &dwValueNameLength );

      if( lResult == ERROR_SUCCESS )
      {
         _tcscpy( szVNSBPath, strValueName );  //"program files"
         _tcscat( szVNSBPath, _T( "\\NS BASIC\\" ) );   //"\\NS BASIC\\"
         _tcscat( szVNSBPath, _T( "BASIC.EXE" ) );  //"VNSB.EXE"
      }
      else
         _tcscpy( szVNSBPath, _T( "\\Program Files\\NS Basic\\basic.exe" ) );//default
      RegCloseKey( hSubKey );
   }
   sei.lpFile = szVNSBPath;

   CString strParams;
   strParams.Format( _T( "\"%s\" \"%s\"" ),
                     ( (CVNSBApp *)AfxGetApp() )->m_strMagicFileName,
                     ( (CVNSBApp *)AfxGetApp() )->m_strRealFileName );
   sei.lpParameters = strParams;
   sei.nShow = SW_SHOWNORMAL;
#ifdef _POCKET
   CloseHandle( ghMutex );
#endif
   if( ShellExecuteEx( &sei ) )
      PostQuitMessage( 0 );
} // OnFormExit

void CVNSBDoc::OnUpdateFormExit( CCmdUI* pCmdUI ) 
{
   pCmdUI->Enable();
} // OnUpdateFormExit

BOOL CVNSBDoc::SaveModified() 
{
   if( !IsModified() )
      return TRUE;        // ok to continue

   // get name/title of document
   CString name = m_strTitle;
   if( name.IsEmpty() )
      name = _T( "Untitled" );

   CWnd *pMain = AfxGetMainWnd();
   switch( MessageBox( pMain->m_hWnd, _T( "Save changes?" ), _T( "VNSB" ),
           MB_ICONQUESTION | MB_YESNOCANCEL ) )
   {
   case IDCANCEL:
      return FALSE;       // don't continue

   case IDYES:  // If so, either Save or Update, as appropriate
      if( !DoFileSave() )
         return FALSE;       // don't continue
      break;

   case IDNO:   // If not saving changes, revert the document
      break;

   default:
      ASSERT( FALSE );
      break;
   }
   return TRUE;    // keep going
} // SaveModified

void CVNSBDoc::DoFormExit()
{
   OnFormExit();
} // DoFormExit

void CVNSBDoc::OnUpdateObjectsShowCode(CCmdUI* pCmdUI) 
{
   pCmdUI->Enable( !m_strCode.IsEmpty() );
} // OnUpdateObjectsShowCode

void CVNSBDoc::OnObjectsShowCode() 
{
   CCodeDlg dlg;
   dlg.m_strCode = m_strCode;
   dlg.DoModal();
} // OnObjectsShowCode

BOOL CVNSBDoc::UniqueObjectName( CString &strObjectName )
{
   INT n = 0;
   if( strObjectName == _T( "Output" ) )
      return FALSE;
   if( strObjectName == _T( "Err" ) )
      return FALSE;
   for( INT i = 0; i < m_aForms.GetSize(); i++ )
   {
      CNSBForm *pForm;
      m_mapForms.Lookup( m_aForms[i], pForm );
      for( INT j = 0; j < pForm->m_aObjects.GetSize(); j++ )
      {
         if( strObjectName == pForm->m_aObjects[j]->m_strObjectName )
            n++;
      }
   }
   return n < 2 ? TRUE : FALSE;
} // UniqueObjectName

void CVNSBDoc::GetComServers()
{
   HKEY hKey, hSubKey, hTestKey;
   LONG lStatus;
   DWORD dwSize, dwType, dwLen;
   int iKey;
   CString strCLSID, strName, strProgID, strMiscStatus;

   hKey = NULL;                     //  Open CLSID part of HKEY_CLASSES_ROOT
   lStatus = RegOpenKeyEx( HKEY_CLASSES_ROOT, _T( "CLSID" ), 0, 0, &hKey );
   if( lStatus != ERROR_SUCCESS )
   {
//      MessageBox( _T( "Unable to open CLSID key" ), _T( "ObjTest1" ), MB_OK );
      return;
   }

   iKey = 0;
   dwSize = 64;
   dwLen = 256;
   // Look at each key in HKCR/CLSID
   while( RegEnumKeyEx( hKey, iKey, strCLSID.GetBuffer( dwSize ), &dwSize, NULL, NULL, NULL, NULL ) == ERROR_SUCCESS )
   {
      strCLSID.ReleaseBuffer();
      strCLSID.MakeUpper();
      if( dwSize )
      {
         hSubKey = NULL;
         lStatus = RegOpenKeyEx( hKey, (LPCTSTR)strCLSID, 0, 0, &hSubKey );
         //  If we open the {XXXX} key
         if( lStatus == ERROR_SUCCESS )
         {
            dwSize = 128;                         //  And get it's default value
            lStatus = RegQueryValueEx( hSubKey, NULL, NULL, &dwType, (unsigned char *)strName.GetBuffer( dwSize ), &dwSize );
            strName.ReleaseBuffer();
            if( lStatus == ERROR_SUCCESS )
            {  // Must be a "Control" before we look at it.
               lStatus = RegOpenKeyEx( hSubKey, _T( "Control" ), 0, 0, &hTestKey );
               RegCloseKey( hTestKey );
               if( lStatus == ERROR_SUCCESS )
               {  // Must have a MiscStatus == "0" before we use it.
                  lStatus = RegOpenKeyEx( hSubKey, _T( "MiscStatus" ), 0, 0, &hTestKey );
                  if( lStatus == ERROR_SUCCESS )
                  {
                     dwLen = 128;
                     RegQueryValueEx( hTestKey, NULL, NULL, &dwType, (unsigned char *)strMiscStatus.GetBuffer( dwLen ), &dwLen );
                     strMiscStatus.ReleaseBuffer();
                     if( strMiscStatus.Compare( _T( "0" ) ) == 0 )
                     {  // Lets get a ProgID, look for version independent, first
//                        m_cListView.AddString( (LPCTSTR)strName );
                        strProgID.Empty();
                        lStatus = RegOpenKeyEx( hSubKey, _T( "VersionIndependentProgID" ), 0, 0, &hTestKey );
                        if( lStatus == ERROR_SUCCESS )
                        {
                           dwLen = 128;
                           RegQueryValueEx( hTestKey, NULL, NULL, &dwType, (unsigned char *)strProgID.GetBuffer( dwLen ), &dwLen );
                           strProgID.ReleaseBuffer();
                        }
                        RegCloseKey( hTestKey );
                        if( strProgID.IsEmpty() )
                        {  // Use strict ProgID, if version independent not available
                           lStatus = RegOpenKeyEx( hSubKey, _T( "ProgID" ), 0, 0, &hTestKey );
                           if( lStatus == ERROR_SUCCESS )
                           {
                              dwLen = 128;
                              RegQueryValueEx( hTestKey, NULL, NULL, &dwType, (unsigned char *)strProgID.GetBuffer( dwLen ), &dwLen );
                              strProgID.ReleaseBuffer();
                           }
                           RegCloseKey( hTestKey );
                        }

                        // So far we've found the promise of an object, by asking many
                        // questions in the registry... if we can't actually create one,
                        // it will all be for naught.
/*
                        GUID guid;
                        DWORD dwStatus;
                        IDispatch *pDisp;
                        CLSIDFromString( strCLSID.GetBuffer( strCLSID.GetLength() + 1 ),
                                         &guid );
                        dwStatus = CoCreateInstance( guid, 0, CLSCTX_SERVER, IID_IDispatch,
                                                     (void **)&pDisp );
                        if( dwStatus == S_OK )
                        {
                           pDisp->Release();
*/
                           // Add to the object description map with the important string(s)
                           CComObDesc *pObDesc;
                           if( !strProgID.IsEmpty() )
                              pObDesc = new CComObDesc( (LPCTSTR)strCLSID, (LPCTSTR)strProgID );
                           else
                              pObDesc = new CComObDesc( (LPCTSTR)strCLSID );
                           m_mapComObDescs[strName] = pObDesc;
                           m_mapComObNames[pObDesc->m_strProgID] = strName;
//                        }
                     }
                  }
                  RegCloseKey( hTestKey );
               }
            }
            RegCloseKey( hSubKey );          //  Done with object key...close it
         }
      }
      dwSize = 64;
      ++iKey;
   }
   strCLSID.ReleaseBuffer();
   RegCloseKey( hKey );
} // GetComServers

CComObDesc *CVNSBDoc::GetComObDesc( LPCTSTR lpszProgID )
{
   if( m_mapComObDescs.IsEmpty() )
      GetComServers();
   CString strName;
   if( m_mapComObNames.Lookup( lpszProgID, strName ) )
   {
      CComObDesc *pComObDesc;
      if( m_mapComObDescs.Lookup( (LPCTSTR)strName, pComObDesc ) )
         return pComObDesc;
   }
   return NULL;
} // GetComObDesc

BOOL CVNSBDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

//	::MessageBox( 0, _T( "OnOpenDocument" ), _T( "Debug" ), MB_OK );
   while( m_mapForms.GetCount() < 1 )
      OnFormAdd();
	
	return TRUE;
}

void CVNSBDoc::OnOk() 
{
   AfxGetMainWnd()->SendMessage( WM_CLOSE, 0, 0 );
}
