// NSBForm.cpp: implementation of the CNSBForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VNSB.h"
#include "NSBForm.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNSBForm::CNSBForm( CString &strName )
{
   m_strName = strName;
   m_nNextFormObject = 0;
   m_aFormMenu.SetSize( 0 );
   m_pOutput = new CNSBFormObject( _T( "Output" ), m_strName + _T( " Output" ), NSBOB_TYPE_OUTPUT, CRect( 0, 0, 0, 0 ) );
} // CNSBForm

CNSBForm::~CNSBForm()
{
   for( int i = 0; i < m_aObjects.GetSize(); i++ )
      delete m_aObjects[i];
   m_aObjects.RemoveAll();
   delete m_pOutput;
   DeleteFormMenu();
} // ~CNSBForm

void CNSBForm::DeleteFormMenu()
{
   for( int i = 0; i < m_aFormMenu.GetSize(); i++ )
      delete m_aFormMenu[i];
   m_aFormMenu.RemoveAll();
} // DeleteFormMenu

int CNSBForm::AddFormObject( NSBObject aoDef, int nObject )
{
   CString strObjectName;

   // 1. Name object
   strObjectName.Format( _T( "%s%d" ), aoDef.m_strUserType, nObject + 1 );

   // 2. Create object with type, name, and ID
   CNSBFormObject *pFormOb = new CNSBFormObject( aoDef.m_strObjectType, strObjectName,
      NSB_OBJECT_ID + m_nNextFormObject++ );

   // 3. Add object to storage array
   m_aObjects.Add( pFormOb );

   return m_aObjects.GetSize() - 1;
} // AddFormObject

CNSBFormObject *CNSBForm::AddFormObject( LPCTSTR lpszType, LPCTSTR lpszName, CRect &rectBounds )
{
//afxDump << strType << _T( ":" ) << strName << _T( ":" ) << rectBounds << _T( "\n" );
   CNSBFormObject *pFormOb = new CNSBFormObject( lpszType, lpszName,
                                                 NSB_OBJECT_ID + m_nNextFormObject++,
                                                 rectBounds );
   m_aObjects.Add( pFormOb );

   return pFormOb;
} // AddFormObject

int CNSBForm::PasteFormObject( CNSBFormObject *pFormOb )
{
   int i, j, k;

   // Copy object off the clipboard
   CNSBFormObject *pNewOb = new CNSBFormObject( pFormOb );
   pNewOb->m_nObjectID = m_nNextFormObject++;

   j = 0;
   CString strTail, strName = pNewOb->m_strObjectName;
   while( TRUE )
   {
      // Check for namespace crash
      for( i = 0; i < m_aObjects.GetSize(); i++ )
         if( m_aObjects[i]->m_strObjectName == pNewOb->m_strObjectName )
            break;
      // No namespace crash, don't rename object
      if( i >= m_aObjects.GetSize() )
         break;
      if( ( k = pNewOb->m_strObjectName.Find( _T( "_Copy" ) ) ) > 0 )
         strName = pNewOb->m_strObjectName.Left( k );
      if( j == 0 )
         strTail = _T( "_Copy" );
      else
         strTail.Format( _T( "_Copy%d" ), j );
      pNewOb->m_strObjectName = strName + strTail;
      j++;
   }
   return m_aObjects.Add( pNewOb );
} // PasteFormObject

void CNSBForm::DeleteFormObject( CNSBFormObject *pFormOb )
{
   for( int i = 0; i < m_aObjects.GetSize(); i++ )
      if( m_aObjects[i] == pFormOb )
      {
         delete pFormOb;
         m_aObjects.RemoveAt( i );
         break;
      }
} // DeleteFormObject

void CNSBForm::SetFormName( CString &strName )
{
   m_strName = strName;
   strName.Format( _T( "%s Output" ), strName );
   m_pOutput->m_strObjectName = strName;
} // SetFormName

int CNSBForm::NumObjects( int nObjectType, LPCTSTR lpszProgID )
{
   int i, j;
   // Return number of objects if no type is specified
   if( !nObjectType && lpszProgID == NULL )
      return m_aObjects.GetSize();

   if( lpszProgID != NULL )
   {
      // Count number of objects of specified ProgID and return
      for( i = 0, j = 0; i < m_aObjects.GetSize(); i++ )
         if( m_aObjects[i]->m_strObjectType.CompareNoCase( lpszProgID ) == 0 )
            j++;
   }
   else
   {
      // Count number of objects of specified type and return
      for( i = 0, j = 0; i < m_aObjects.GetSize(); i++ )
         if( m_aObjects[i]->m_nObjectType == nObjectType )
            j++;
   }
   return j;
} // NumObjects

void CNSBForm::GenerateCode()
{
   m_strCode.Empty();
   CString strTemp, strTemp2, strTemp3;

   // First do VXNXSXB_Load
   // Loop through form objects
   strTemp2.LoadString( IDS_CODE_OBJECT_SEPARATOR );
   for( int i = 0; i < m_aObjects.GetSize(); i++ )
   {
      strTemp += m_aObjects[i]->GenerateCode( i + 1 );
      if( i < ( m_aObjects.GetSize() - 1 ) )
         strTemp += strTemp2;
   }
   strTemp2.LoadString( IDS_CODE_FORM_LOAD );
   strTemp3.Format( strTemp2, m_aObjects.GetSize(), (LPCTSTR)strTemp );
   m_strCode += strTemp3;

   // Next, do VXNXSXB_Show
   strTemp.Empty();
   //    Menu first
   if( m_aFormMenu.GetSize() > 0 )
      strTemp.LoadString( IDS_CODE_SHOWMENU );

   //    Then Output
   strTemp += m_pOutput->GenerateCode( 0 );
   strTemp2.LoadString( IDS_CODE_FORM_SHOW );
   strTemp3.Format( strTemp2, (LPCTSTR)strTemp );
   m_strCode += strTemp3;

   // Then, do VXNXSXB_Hide
   strTemp.LoadString( IDS_CODE_FORM_HIDE );
   m_strCode += strTemp;

   // Finish, with VXNXSXB_ShowMenu
   if( m_aFormMenu.GetSize() != 0 )
   {
      strTemp = GenerateMenu();
      strTemp2.LoadString( IDS_CODE_FORM_SHOWMENU );
      strTemp3.Format( strTemp2, (LPCTSTR)strTemp );
      m_strCode += strTemp3;
   }
   CStringReplace( m_strCode, _T( "VXNXSXB" ), (LPCTSTR)m_strName );
#ifdef _DEBUG
   afxDump << m_strCode; // #ifdef _DEBUG
#endif
} // GenerateCode

CString CNSBForm::GenerateMenu()
{
   CString strCode, strTemp;

   strCode.Empty();
   if( m_aFormMenu.GetSize() != 0 )
      DoGenerateMenu( &m_aFormMenu, strCode, _T( "TitleBar" ) );
   return strCode;
} // GenerateMenu

void CNSBForm::DoGenerateMenu( NSBFormMenu *pFormMenu, CString &strCode, CString strMenu )
{
   CString strTemp, strItems;
   strTemp.LoadString( IDS_CODE_SETMENU );
   INT i;

#if _WIN32_WCE < 211
   CStringReplace( strTemp, _T( "VXNXSXB" ), strMenu );
#else
   strTemp.Replace( _T( "VXNXSXB" ), strMenu );
#endif
   for( i = 0; i < pFormMenu->GetSize(); i++ )
   {
      if( i > 0 )
         strItems += _T( ", " );
      strItems += _T( "\"" ) + ( *pFormMenu )[i]->m_strItem + _T( "\"" );
   }
   strTemp.Format( strTemp, strItems );
   strCode += strTemp;
   for( i = 0; i < pFormMenu->GetSize(); i++ )
      if( ( *pFormMenu )[i]->m_aSubMenu.GetSize() > 0 )
         DoGenerateMenu( &( ( *pFormMenu )[i]->m_aSubMenu ), strCode, ( *pFormMenu )[i]->GetMenuKey() );
} // DoGenerateMenu

//////////////////////////////////////////////////////////////////////
// CNSBFormObject Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNSBFormObject::CNSBFormObject( LPCTSTR lpszObjectType, LPCTSTR lpszObjectName,
                                INT nObjectID, CRect &rectBounds )
{
   // Initialize pointers
   m_pComObDesc = NULL;

   // Identify and name object
   m_nObjectID = nObjectID;
   m_strObjectName = lpszObjectName;

   // Find object type
   m_nObjectType = 0;
   for( int i = 0; i < NUM_NSBOBJECTS; i++ )
      if( _tcscmp( NSBObjectList[i].m_strObjectType, lpszObjectType ) == 0 )
      {
         m_nObjectType = NSBObjectList[i].m_nObjectID;
         break;
      }

   if( m_nObjectType == 0 )
   {
      // No type found, must be a COM Server
      // Get ProgID and CLSID from strObjectType "Prog.ID {CLS-ID}"
      _stscanf( lpszObjectType, _T( "%s %s" ), m_strObjectType.GetBuffer( 128 ),
                m_strCLSID.GetBuffer( 128 ) );
      m_strObjectType.ReleaseBuffer();
      m_strCLSID.ReleaseBuffer();
      m_nObjectType = NSBOB_COM_OB;
//      m_pComObDesc = 
   }
   else
   {
      m_strObjectType = lpszObjectType;
   }
   // Get properties from tables
   INT nID = m_nObjectType - NSBOB_ID;
   // Iterate through property groups
   for( int j = 0; j < NUM_NSBPROPERTYGROUPS; j++ )
   {
      // Add properties from only specified property groups
      if( ( 1 << j ) & NSBObjectList[nID].m_nBaseProperties )
      {
         // Iterate through properties in property groups
         for( int i = 0; i < MAX_OBJECT_PROPERTIES; i++ )
         {
            // Only work with initialized properties
            if( !NSBPropGroupList[j].m_aObjectProperties[i] )
               break;
            // Add all properties
            m_mapProperties[KeyToProperty( NSBPropGroupList[j].m_aObjectProperties[i] )] =
                  NSBPropGroupList[j].m_aPropertyDefaults[i];
         }
      }
   }
   for( i = 0; i < MAX_OBJECT_PROPERTIES; i++ )
   {
      if( !NSBObjectList[nID].m_aObjectProperties[i] )
         break;
      m_mapProperties[KeyToProperty( NSBObjectList[nID].m_aObjectProperties[i] )] =
               NSBObjectList[nID].m_aPropertyDefaults[i];
   }

   // Set bounding rect
   if( !rectBounds.IsRectEmpty() )
   {
      rectBounds.InflateRect( 2, 2 );
      SetRect( rectBounds );
   }
} // CNSBFormObject

CNSBFormObject::CNSBFormObject( CNSBFormObject *pFormOb )
{
   m_nObjectID     = pFormOb->m_nObjectID;
   m_nObjectType   = pFormOb->m_nObjectType;
   m_rectBounds    = pFormOb->m_rectBounds;
   m_strObjectName = pFormOb->m_strObjectName;
   m_strObjectType = pFormOb->m_strObjectType;
   CString strKey, strVal;
   POSITION pos = pFormOb->m_mapProperties.GetStartPosition();
   while( pos != NULL )
   {
      pFormOb->m_mapProperties.GetNextAssoc( pos, strKey, strVal );
      m_mapProperties[strKey] = strVal;
   }
} // CNSBFormObject

CNSBFormObject::~CNSBFormObject()
{
   m_mapProperties.RemoveAll();
} // ~CNSBFormObject

NSBObject CNSBFormObject::NSBObjectList[NUM_NSBOBJECTS] = NSB_OBJECTS;

NSBProperty CNSBFormObject::NSBPropertyList[NUM_NSBPROPERTIES] = NSB_PROPERTIES;

NSBObject CNSBFormObject::NSBPropGroupList[NUM_NSBPROPERTYGROUPS] = NSB_PROPERTY_GROUPS;

void CNSBFormObject::SetRect( CRect rect )
{
   rect.DeflateRect( 2, 2 );
   m_rectBounds = rect;

   CString strTemp;
   strTemp.Format( _T( "%d" ), rect.left );
   m_mapProperties[KeyToProperty( NSBP_LEFT )] = strTemp;
   strTemp.Format( _T( "%d" ), rect.top );
   m_mapProperties[KeyToProperty( NSBP_TOP )] = strTemp;
   strTemp.Format( _T( "%d" ), rect.right );
   m_mapProperties[KeyToProperty( NSBP_RIGHT )] = strTemp;
   strTemp.Format( _T( "%d" ), rect.bottom );
   m_mapProperties[KeyToProperty( NSBP_BOTTOM )] = strTemp;

   CString strKey, strVal;
   // Width and Height properties
   strKey = KeyToProperty( NSBP_WIDTH );
   if( m_mapProperties.Lookup( strKey, strTemp ) )
   {
      strVal.Format( _T( "%d" ), rect.right - rect.left );
      m_mapProperties[strKey] = strVal;
   }
   strKey = KeyToProperty( NSBP_HEIGHT );
   if( m_mapProperties.Lookup( strKey, strTemp ) )
   {
      strVal.Format( _T( "%d" ), rect.bottom - rect.top );
      m_mapProperties[strKey] = strVal;
   }
} // SetRect

CString CNSBFormObject::KeyToProperty( INT nKey )
{
   return NSBPropertyList[nKey - NSBP_ID].m_strName;
} // KeyToProperty

int CNSBFormObject::PropertyToKey( CString &strProperty, NSBObject *pNSBObject )
{
   NSBObject *pOb;
   if( pNSBObject->m_nFlag & NSBOB_TYPE_COM )
      return -1;
   for( INT i(0); i < NUM_NSBPROPERTYGROUPS; i++ )
   {
      if( ( ( 1 << i ) & pNSBObject->m_nBaseProperties ) == 0 )
         continue;
      pOb = &NSBPropGroupList[i];
      for( INT j(0); j < NUM_NSBPROPERTIES; j++ )
      {
         if( pOb->m_aObjectProperties[j] == 0 )
            break;
         if( KeyToProperty( pOb->m_aObjectProperties[j] ) == strProperty )
            return pOb->m_aObjectProperties[j];
      }
   }
   for( INT j(0); j < NUM_NSBPROPERTIES; j++ )
   {
      if( pNSBObject->m_aObjectProperties[j] == 0 )
         break;
      if( KeyToProperty( pNSBObject->m_aObjectProperties[j] ) == strProperty )
         return pNSBObject->m_aObjectProperties[j];
   }
   return 0;
} // PropertyToKey

//////////////////////////////////////////////////////////////////////
// CNSBFormSubMenu Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNSBFormSubMenu::CNSBFormSubMenu()
{
   m_aSubMenu.SetSize( 0 );
} // CNSBFormSubMenu

CNSBFormSubMenu::~CNSBFormSubMenu()
{
   for( int i = 0; i < m_aSubMenu.GetSize(); i++ )
      delete m_aSubMenu[i];
   m_aSubMenu.RemoveAll();
}

CNSBFormSubMenu::CNSBFormSubMenu( CString strItem )
{
   m_strItem = strItem;
   CNSBFormSubMenu();
} // CNSBFormSubMenu

CNSBFormSubMenu::CNSBFormSubMenu( CNSBFormSubMenu *pMenu )
{
   this->m_strItem = pMenu->m_strItem;
   this->m_aSubMenu.SetSize( pMenu->m_aSubMenu.GetSize() );
} // CNSBFormSubMenu

CString CNSBFormSubMenu::GetMenuKey()
{
   CString strRet = m_strItem;
   INT nSplit = strRet.Find( _T( "||" ) );
   if( nSplit > 0 )
      return strRet.Right( strRet.GetLength() - ( nSplit + 2 ) );
   return strRet;
} // GetMenuItem

CString CNSBFormObject::GenerateCode( INT nIndex )
{
//afxDump << _T( "CNSBFormObject::GenerateCode:\n" ) << (CNSBFormObject *)this << _T( "\n" );
   // Newer version, to support list property.
   CString strCode, strProperty, strKey, strVal, strTemp, strTemp2;
   INT i;
   if( nIndex > 0 )
   {
      strTemp.LoadString( IDS_CODE_ADDOBJECT );
      strCode.Format( strTemp, m_strObjectType, m_strObjectName,
                      m_rectBounds.left, m_rectBounds.top, m_rectBounds.Width(), m_rectBounds.Height(),
                      nIndex, m_strObjectName );
//afxDump << strCode;
   }
   CStringArray aKeys;
   POSITION pos = m_mapProperties.GetStartPosition();
   while( pos != NULL )
   {
      m_mapProperties.GetNextAssoc( pos, strKey, strVal );
      aKeys.Add( strKey );
   }
//afxDump << aKeys;
//for( i = 0; i < aKeys.GetSize(); i++ ) afxDump << _T( "  " ) << aKeys[i] << _T( "\n" );
   NSBObject *pNSBObject = &NSBPropGroupList[0]; //NSBPG_LOCATION;
   for( i = 0; i < MAX_OBJECT_PROPERTIES; i++ )
   {
      if( pNSBObject->m_aObjectProperties[i] == 0 )
         break;
      MoveKey( pNSBObject->m_aObjectProperties[i], aKeys, 0 );
   }
	// Rearranged base property groups have made this step unnecessary.
	// Its current form deletes the caption property
   /*
   pNSBObject = &NSBPropGroupList[1]; // NSBPG_LOCATION
   for( i = 0; i < MAX_OBJECT_PROPERTIES; i++ )
   {
      if( pNSBObject->m_aObjectProperties[i] == 0 )
         break;
      MoveKey( pNSBObject->m_aObjectProperties[i], aKeys, 0 );
   }
   */
   // Always last, so properties aren't changing while text is already displayed
   MoveKey( NSBP_CAPTION, aKeys, -1 );
   // Even laster, because it isn't really a property
   MoveKey( NSBP_LIST, aKeys, -1 );
//afxDump << _T( "After remove loc/dim and move to rear\n" );
//afxDump << aKeys;
//for( i = 0; i < aKeys.GetSize(); i++ ) afxDump << _T( "  " ) << aKeys[i] << _T( "\n" );
   // Move priority properties to the front
   pNSBObject = &NSBObjectList[m_nObjectType - NSBOB_ID];
   for( i = 0; i < MAX_PRIORITY_PROPERTIES; i++ )
   {
      if( pNSBObject->m_aPriorityProperties[i] == 0 )
         break;
      MoveKey( pNSBObject->m_aPriorityProperties[i], aKeys, 1 );
   }
//afxDump << _T( "After move to front\n" );
//afxDump << aKeys;
//for( i = 0; i < aKeys.GetSize(); i++ ) afxDump << _T( "  " ) << aKeys[i] << _T( "\n" );

   // Get the proper code generation property template
   if( nIndex > 0 )
      strTemp.LoadString( IDS_CODE_PROPERTY );
   else
      strTemp.LoadString( IDS_CODE_OUTPUT_PROPERTY );

   for( i = 0; i < aKeys.GetSize(); i++ )
   {
      int nKey = PropertyToKey( aKeys[i], pNSBObject );
      WORD nType;
      m_mapProperties.Lookup( aKeys[i], strVal );
//afxDump << _T( "  Writing property: " ) << aKeys[i] << _T( " = " ) << strVal << _T( "\n" );
//afxDump << _T( "Property List Type: " ) << NSBPropertyList[nKey - NSBP_ID].m_nType << _T( "\n" );
      if( DefaultPropertyValue( nKey, strVal ) )
         continue;
      if( nKey < 0 )       // COM Server
         m_pComObDesc->m_mapProperties.Lookup( aKeys[i], nType );
      else
         nType = NSBPropertyList[nKey - NSBP_ID].m_nType;
      switch( nType )
      {
      case NSBP_TYPE_STRING1:
      case NSBP_TYPE_STRINGN:
      case NSBP_TYPE_FONTNAME:
         if( strVal.Right( 1 ) != _T( "'" ) )
         {
//afxDump << strVal << _T( "\n" );
//            strTemp2 = _T( "\"" ) + (LPCTSTR)strVal + _T( "\"" );
            strTemp2.Format( _T( "\"%s\"" ), (LPCTSTR)strVal );
            strVal = strTemp2;
//afxDump << strVal << _T( "\n" );
         }
         break;
      case NSBP_TYPE_DATE:
      case NSBP_TYPE_TIME:
         strTemp2.Format( _T( "\"%s\"" ), (LPCTSTR)strVal );
         strVal = strTemp2;
         break;
      case NSBP_TYPE_STRINGLIST:
         {
            strVal.TrimLeft();
            CString strItem = strVal.SpanExcluding( _T( "\r\n" ) );
            strVal = strVal.Mid( strItem.GetLength() );
            strVal.TrimLeft();
            strItem.TrimRight();
            while( strItem.GetLength() || strVal.GetLength() )
            {
               if( strItem.GetLength() )
               {
                  if( strItem.Right( 1 ) != _T( "'" ) )
                  {
                     strTemp2.Format( _T( "\"%s\"" ), (LPCTSTR)strItem );
                     strItem = strTemp2;
                  }
                  strProperty.Format( _T( "  VXNXSXB(%d).AddItem %s\r\n" ), nIndex, (LPCTSTR)strItem );
                  strCode += strProperty;
               }
               strItem = strVal.SpanExcluding( _T( "\r\n" ) );
               strVal = strVal.Mid( strItem.GetLength() );
               strVal.TrimLeft();
               strItem.TrimRight();
            }
         }
         continue;
      }
      if( nIndex > 0 )
         strProperty.Format( strTemp, nIndex, (LPCTSTR)aKeys[i], (LPCTSTR)strVal );
      else
         strProperty.Format( strTemp, (LPCTSTR)aKeys[i], (LPCTSTR)strVal );
//afxDump << strProperty << _T( "\n" );
      strCode += strProperty;
   }

   return strCode;
} // GenerateCode

CString CNSBFormObject::ParseArgument( CString &strArg )
{
   CString strRet = strArg;
   if( strRet[0] == _T( '"' ) && strRet[strRet.GetLength() - 1] == _T( '"' ) )
      return strRet.Mid( 1, strRet.GetLength() - 2 );
   else
      return strRet;
} // ParseArgument

void CNSBFormObject::SetProperty( CString &strProperty, CString &strValue )
{
   m_mapProperties[strProperty] = ParseArgument( strValue );
} // SetProperty

void CNSBFormObject::CallMethod( CString &strMethod, CString &strValue )
{
   if( strMethod == _T( "ADDITEM" ) && ( m_nObjectType == NSBOB_COM_BOX || m_nObjectType == NSBOB_LIS_BOX ) )
   {
      CString strVal;
      m_mapProperties.Lookup( _T( "List" ), strVal );
      if( !strVal.IsEmpty() )
         strVal += _T( "\r\n" );
      strVal += ParseArgument( strValue );
      m_mapProperties[_T( "List" )] = strVal;
   }
} // CallMethod

BOOL CNSBFormObject::HasProperty( INT nPropertyID )
{
   NSBObject *pNSBObject = &NSBObjectList[m_nObjectType - NSBOB_ID];
   int i = 0;
   while( pNSBObject->m_aObjectProperties[i] != 0 && i < MAX_OBJECT_PROPERTIES )
   {
      if( pNSBObject->m_aObjectProperties[i] == nPropertyID )
         return TRUE;
      i++;
   }
   INT nPropertyGroups = ( pNSBObject->m_nBaseProperties );
   for( int j = 0; j < NUM_NSBPROPERTYGROUPS; j++ )
   {
      if( !( nPropertyGroups & ( 1 << j ) ) )
         continue;
      i = 0;
      while( NSBPropGroupList[j].m_aObjectProperties[i] != 0 && i < MAX_OBJECT_PROPERTIES )
      {
         if( NSBPropGroupList[j].m_aObjectProperties[i] == nPropertyID )
            return TRUE;
         i++;
      }
   }
   return FALSE;
} // HasProperty

void CNSBForm::ParseCode()
{
   if( m_strCode.IsEmpty() )
      return;
   m_pOutput = new CNSBFormObject( _T( "Output" ), m_strName + _T( " Output" ), NSBOB_TYPE_OUTPUT, CRect( 0, 0, 0, 0 ) );
#ifdef _DEBUG
//   afxDump << m_strCode;
#endif
   CString strKey, strTemp;
   int nObjects, nEndForm, nState;
   CNSBFormObject *pFormOb;
   BOOL bShowMenu;

   // Set state variables and loop through parse code
   nEndForm = 0;
   nState = PARSE_STATE_NUM_OBJECTS;

   // Get first line
   strTemp = m_strCode.SpanExcluding( _T( "\r\n" ) );
   m_strCode = m_strCode.Mid( strTemp.GetLength() );
   m_strCode.TrimLeft();
   strTemp.TrimLeft();
   // Keyword
   strKey = strTemp.SpanExcluding( _T( " (." ) );
   strKey.MakeUpper();
   while( nState < PARSE_STATE_EXIT )
   {
      if( strTemp.GetLength() != 0 )
      {
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
         switch( nState )
         {
         case PARSE_STATE_NUM_OBJECTS:  // Looking for REDIM
            if( strKey != _T( "REDIM" ) )
               break;
            _stscanf( strTemp, _T( "REDIM %*[^(](%d)" ), &nObjects );
//afxDump << _T( "Number of Objects: " ) << nObjects << _T( "\n" );
            nState = PARSE_STATE_NEW_OBJECT;
            break;
         case PARSE_STATE_NEW_OBJECT: // Looking for ADDOBJECT
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
            if( strKey != _T( "ADDOBJECT" ) )
            {
               if( nObjects == 0 )
                  nState = PARSE_STATE_SHOWMENU;
               else
                  nState = PARSE_STATE_OBJECT_PROPERTY;
               continue;
            }
            else
            {
               CString strType, strName;
               INT nL, nT, nW, nH;

               _stscanf( strTemp, _T( "ADDOBJECT \"%[^\", ]\", \"%[^\", ]\", %d%*[,] %d%*[,] %d%*[,] %d" ),
                         strType.GetBuffer( 64 ), strName.GetBuffer( 64 ), &nL, &nT, &nW, &nH );
               strType.ReleaseBuffer();
               strName.ReleaseBuffer();
//afxDump << _T( "Type: " ) << strType << _T( "\n" );
//afxDump << _T( "Name: " ) << strName << _T( "\n" );
//afxDump << _T( "  " ) << nL << _T( "  " ) << nT << _T( "  " ) << nW << _T( "  " ) << nH << _T( "\n" );
               pFormOb = AddFormObject( strType, strName, CRect( CPoint( nL, nT ), CSize( nW, nH ) ) );
               // Add Form Object
               nObjects--;
               nState = PARSE_STATE_OBJECT_PROPERTY;
            }
            break;
         case PARSE_STATE_OBJECT_PROPERTY: // Looking for <Formname>, stop at ADDOBJECT
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
            if( strKey == _T( "ADDOBJECT" ) )
            {
               nState = PARSE_STATE_NEW_OBJECT;
               continue;
            }
            else if( strKey == _T( "END" ) )
            {
               nState = PARSE_STATE_SHOWMENU;
               break;
            }
            else if( strKey.CompareNoCase( m_strName ) != 0 )
               break;
            else
            {
               CString strProperty, strValue;
               INT nScan = _stscanf( strTemp, _T( "%*[^.].%s = %[^\n]" ), strProperty.GetBuffer( 64 ), strValue.GetBuffer( 32768 ) );
               strProperty.ReleaseBuffer();
               strValue.ReleaseBuffer();
               if( nScan == 2 )
                  pFormOb->SetProperty( strProperty, strValue );
               else
               {
                  _stscanf( strTemp, _T( "%*[^.].%s %[^\n]" ), strProperty.GetBuffer( 64 ), strValue.GetBuffer( 32768 ) );
                  strProperty.ReleaseBuffer();
                  strValue.ReleaseBuffer();
                  strProperty.MakeUpper();
                  pFormOb->CallMethod( strProperty, strValue );
               }
//afxDump << _T( "Object Property: " ) << strProperty << _T( " = " ) << strValue << _T( "\n" );
               break;
            }
         case PARSE_STATE_SHOWMENU: // Looking for <Formname>_ShowMenu
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
            if( strKey == _T( "IF" ) || strKey == _T( "OUTPUT" ) )
            {
               nState = PARSE_STATE_OUTPUT_PROPERTY;
               continue;
            }
            else if( strKey.Find( _T( "_SHOWMENU" ) ) > 0 )
            {
               bShowMenu = TRUE;
               nState = PARSE_STATE_OUTPUT_PROPERTY;
            }
            break;
         case PARSE_STATE_OUTPUT_PROPERTY: // Looking for OUTPUT
            if( strKey == _T( "IF" ) )
               nState = PARSE_STATE_END_FORM;
            else if( strKey == _T( "OUTPUT" ) )
            {
               CString strProperty, strValue;
               _stscanf( strTemp, _T( "%*[^.].%s = %[^\n]" ), strProperty.GetBuffer( 32 ), strValue.GetBuffer( 65536 ) );
               strProperty.ReleaseBuffer();
               strValue.ReleaseBuffer();
               m_pOutput->SetProperty( strProperty, strValue );
//afxDump << _T( "Output Property: " ) << strProperty << _T( " = " ) << strValue << _T( "\n" );
            }
            break;
         case PARSE_STATE_END_FORM: // Looking for END, twice
            if( strKey != _T( "END" ) )
               break;
            if( nEndForm != 0 )
            {
               if( bShowMenu )
                  nState = PARSE_STATE_SETMENU;
               else
                  nState = PARSE_STATE_EXIT;
//afxDump << _T( "End of form: " ) << strFormName << _T( "\n" );
            }
            else
               nEndForm++;
            break;
         case PARSE_STATE_SETMENU: // Looking for SETMENU
//afxDump << _T( "|-- " ) << strTemp << _T( " --|\n" );
//afxDump << _T( "Keyword: " ) << strKey << _T( "\n" );
            if( strKey != _T( "SETMENU" ) )
            {
               if( !bShowMenu )
               {
                  nState = PARSE_STATE_EXIT;
                  continue;
               }
               else
                  break;
            }
            bShowMenu = FALSE;
            {
               CString strMenu, strMTemp;
               INT a = strTemp.Find( _T( ", ARRAY" ) );
               if( a < 0 )
                  break;
               strMenu = strTemp.Mid( 9, a - 10 );
//afxDump << strMenu << _T( "\n" );
               strTemp = strTemp.Mid( a + 8 );
//afxDump << strTemp << _T( "\n" );
               _stscanf( strTemp, _T( "\"%[^\"]\"" ), strMTemp.GetBuffer( 64 ) );
               strMTemp.ReleaseBuffer();
               while( !strMTemp.IsEmpty() )
               {
                  // Add the menu item....
                  AddMenuItem( &m_aFormMenu, strMenu, strMTemp );
                  strTemp = strTemp.Mid( strMTemp.GetLength() + 2 );
                  if( strTemp[0] == _T( ',' ) )
                     strTemp = strTemp.Mid( 2 );
                  strMTemp.Empty();
                  _stscanf( strTemp, _T( "\"%[^\"]\"" ), strMTemp.GetBuffer( 64 ) );
                  strMTemp.ReleaseBuffer();
               }
            }
// SETMENU "Titlebar", ARRAY("&File", "&Edit", "&Help")
//afxDump << strTemp;
            break;
         }
      }
      strTemp = m_strCode.SpanExcluding( _T( "\r\n" ) );
//if( nState == PARSE_STATE_OBJECT_PROPERTY ) afxDump << strTemp << _T( "\n" );
      m_strCode = m_strCode.Mid( strTemp.GetLength() );
      m_strCode.TrimLeft();
//if( nState == PARSE_STATE_OBJECT_PROPERTY ) afxDump << m_strCode << _T( "\n" );
      if( m_strCode.GetLength() == 0 )
         nState = PARSE_STATE_EXIT;
      else
      {
         strTemp.TrimLeft();
         strKey = strTemp.SpanExcluding( _T( " (." ) );
         strKey.MakeUpper();
      }
   }
   m_strCode.Empty();
//   for( INT i = 0; i < m_aObjects.GetSize(); i++ )
//      afxDump << m_aObjects[i];
} // ParseCode

BOOL CNSBForm::AddMenuItem( NSBFormMenu *pMenu, CString &strMenu, CString &strItem )
{
//afxDump << _T( "AddMenuItem: " ) << strMenu << _T( " : " ) << strItem << _T( "\n" );
   // Yet another example of why recursion had to be invented in the nether planes...
   if( strMenu.CompareNoCase( _T( "TITLEBAR" ) ) == 0 )
   {
      pMenu->Add( new CNSBFormSubMenu( strItem ) );
      return TRUE;
   }
   for( INT i = 0; i < pMenu->GetSize(); i++ )
   {
//afxDump << _T( "  " ) << ( *pMenu )[i]->m_strItem << _T( "\n" );
      if( ( ( *pMenu )[i]->m_strItem == strMenu )
          || ( *pMenu )[i]->m_strItem.Right( strMenu.GetLength() + 2 ) == ( _T( "||" ) + strMenu ) )
      {
         ( *pMenu )[i]->m_aSubMenu.Add( new CNSBFormSubMenu( strItem ) );
         return TRUE;
      }
      if( ( *pMenu )[i]->m_aSubMenu.GetSize() > 0 )
         if( AddMenuItem( &( ( *pMenu )[i]->m_aSubMenu ), strMenu, strItem ) )
            return TRUE;
   }
   return FALSE;
} // AddMenuItem

void CNSBFormObject::MoveKey( int nKey, CStringArray &aKeys, int nDir )
{
   CString strKey = NSBPropertyList[nKey - NSBP_ID].m_strName;
   for( INT i = 0; i < aKeys.GetSize(); i++ )
      if( aKeys[i] == strKey )
         break;
   if( i >= aKeys.GetSize() )
      return;
   aKeys.RemoveAt( i );
   switch( nDir )
   {
   case -1: aKeys.Add( strKey ); break;
   case 1:  aKeys.InsertAt( 0, strKey ); break;
   }
} // MoveKey

BOOL CNSBFormObject::DefaultPropertyValue( int nKey, CString &strValue )
{
   // This is for COM Servers
   if( nKey < 0 )
      return strValue.IsEmpty();

   //afxDump << _T( "DefaultPropertyValue: " ) << strValue << _T( "\n" );
   NSBObject *pObject = &NSBObjectList[m_nObjectType - NSBOB_ID];
   // First, look at the object, and check its overridden property defaults
   for( INT i = 0; i < MAX_OBJECT_PROPERTIES; i++ )
   {
      if( pObject->m_aObjectProperties[i] == 0 )
         break;
      if( pObject->m_aObjectProperties[i] == nKey )
         return strValue.CompareNoCase( pObject->m_aPropertyDefaults[i] ) == 0;
   }
   // Check the property groups for default property defaults
   for( INT j = 0; j < NUM_NSBPROPERTYGROUPS; j++ )
   {
      pObject = &NSBPropGroupList[j];
      for( i = 0; i < MAX_OBJECT_PROPERTIES; i++ )
      {
         if( pObject->m_aObjectProperties[i] == 0 )
            break;
         if( pObject->m_aObjectProperties[i] == nKey )
            return strValue.CompareNoCase( pObject->m_aPropertyDefaults[i] ) == 0;
      }
   }
   return FALSE;
} // DefaultPropertyValue

void CNSBForm::Hibernate()
{
   GenerateCode();
   for( int i = 0; i < m_aObjects.GetSize(); i++ )
      delete m_aObjects[i];
   m_aObjects.RemoveAll();
   delete m_pOutput;
   DeleteFormMenu();
   m_nNextFormObject = 0;
} // Hibernate
