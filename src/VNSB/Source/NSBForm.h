// NSBForm.h: interface for the CNSBForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NSBFORM_H__BE6760B2_C46C_11D2_BD63_00A0C9962E16__INCLUDED_)
#define AFX_NSBFORM_H__BE6760B2_C46C_11D2_BD63_00A0C9962E16__INCLUDED_

#include "ComObjectDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNSBFormObject : public CObject  
{
public:
	CComObDesc *m_pComObDesc;
	CString m_strCLSID;
	CString ParseArgument( CString &strArg );
	BOOL DefaultPropertyValue( int nKey, CString &strValue );
	void MoveKey( int nKey, CStringArray &aKeys, int nDir );
	int PropertyToKey( CString &strProperty, NSBObject *pNSBObject );
	void CallMethod( CString &strMethod, CString &strValue );
#ifdef _DEBUG
void Dump( CDumpContext &dc ) const
{
   CObject::Dump( dc );
   dc << _T( "  Name   " ) << m_strObjectName << _T( "\n" );
   dc << _T( "  Type   " ) << m_strObjectType << _T( "\n" );
   dc << _T( "  Bounds " ) << m_rectBounds << _T( "\n" );
   dc << _T( "  Properties\n" );
   POSITION pos = m_mapProperties.GetStartPosition();
   while( pos != NULL )
   {
      CString strKey, strVal;
      m_mapProperties.GetNextAssoc( pos, strKey, strVal );
      dc << _T( "    " ) << strKey << _T( ":" ) << strVal << _T( "\n" );
   }
} // Dump
#endif
	CNSBFormObject( CNSBFormObject *pFormOb );
	BOOL HasProperty( INT nPropertyID );
	void SetProperty( CString &strProperty, CString &strValue );
	CNSBFormObject( LPCTSTR lpszObjectType, LPCTSTR lpszObjectName, INT nObjectID, CRect &rectBounds = CRect( 5, 5, 120, 23 ) );
	CString GenerateCode( INT nIndex );
	CString KeyToProperty( INT nKey );
	static NSBObject NSBPropGroupList[NUM_NSBPROPERTYGROUPS];
	static NSBProperty NSBPropertyList[NUM_NSBPROPERTIES];
	static NSBObject NSBObjectList[NUM_NSBOBJECTS];
	INT m_nObjectType;
	void SetRect( CRect rect );
   CPropertyMap   m_mapProperties;
	CRect          m_rectBounds;
	CString        m_strObjectType;
	CString        m_strObjectName;
	INT            m_nObjectID;
	virtual ~CNSBFormObject();
};

typedef CTypedPtrArray<CObArray,CNSBFormObject*> CNSBFormObjectArray;

class CNSBFormSubMenu : public CObject
{
public:
	CString GetMenuKey();
	CNSBFormSubMenu( CNSBFormSubMenu *pMenu );
	CNSBFormSubMenu( CString strCaption );
   CString m_strItem;
   CTypedPtrArray<CObArray,CNSBFormSubMenu*> m_aSubMenu;
   CNSBFormSubMenu();
   virtual ~CNSBFormSubMenu();
};

typedef CTypedPtrArray<CObArray,CNSBFormSubMenu*> NSBFormMenu;

class CNSBForm : public CObject  
{
public:
	void Hibernate();
	BOOL AddMenuItem( NSBFormMenu *pMenu, CString &strMenu, CString &strItem );
	void ParseCode();
	CString m_strCode;
	int PasteFormObject( CNSBFormObject *pFormOb );
	CNSBFormObject *AddFormObject( LPCTSTR lpszType, LPCTSTR lpszName, CRect &rectBounds );
	void DoGenerateMenu( NSBFormMenu *pFormMenu, CString &strCode, CString strMenu );
	void DeleteFormObject( CNSBFormObject *pFormOb );
	CString GenerateMenu();
	void GenerateCode();
	void SetFormName( CString &strName );
	CNSBFormObject *m_pOutput;
	void DeleteFormMenu();
	NSBFormMenu m_aFormMenu;
	int NumObjects( int nObjectID = 0, LPCTSTR lpszProgID = NULL );
	int AddFormObject( NSBObject aoDef, int nObject );
	int m_nNextFormObject;
	CString m_strName;
	int m_nWidth;
	int m_nHeight;
	CNSBFormObjectArray m_aObjects;
	CNSBForm( CString &strName );
	virtual ~CNSBForm();
};

#endif // !defined(AFX_NSBFORM_H__BE6760B2_C46C_11D2_BD63_00A0C9962E16__INCLUDED_)
