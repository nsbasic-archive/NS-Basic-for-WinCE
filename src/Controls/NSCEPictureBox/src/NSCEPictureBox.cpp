// NSCEPictureBox.cpp : Implementation of CNSCEPictureBoxApp and DLL registration.

#include "stdafx.h"
#include "NSCEPictureBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CNSCEPictureBoxApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x3a697326, 0x1b43, 0x4d83, { 0x8b, 0xc2, 0x9b, 0x8b, 0xab, 0xb7, 0x8d, 0xcc } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 32;


////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxApp::InitInstance - DLL initialization

BOOL CNSCEPictureBoxApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CNSCEPictureBoxApp::ExitInstance - DLL termination

int CNSCEPictureBoxApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
