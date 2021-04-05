// NSBFastFile.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <winreg.h>
#include "NSBFastFile.h"

// Setting this to 1 makes the dll function on time.
// Setting this to 0 makes the dll function on serial number from the registry.
#define TIME_EXP 0

using namespace std;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

// Originally NSBReadFile, this function has been renamed to obfuscate
//
//                      NSBReadFile( LPCTSTR lpszFileName, UINT nLen, DWORD dwSerialNumber, LPTSTR lpszText )
nsbFileFormat __stdcall NSBPictureBoxShow( LPCTSTR lpszPictureBoxName, UINT gwl, DWORD hWnd, LPWSTR lpszText )
{
	FILE *fIn;
	DWORD fChecksum, fFileFlag, fExtra, fCheck, fSerialNumFromFile;
	LPWSTR lpszActualText = lpszText;
	WCHAR *pBuf;
	bool bForce = false;

	if( hWnd == 0 )
		hWnd = NSBPBVersion();
//	else if( hWnd != NSBPBVersion() )
//	{
//		sprintf( lpszText, "hWnd = %lu, NSBPBVersion = %lu", hWnd, NSBPBVersion() );
//		return nsbFFTest;
//	}
	if( hWnd <= 0 )
		return nsbFFUnopened;

	// Open file for reading
	fIn = fopen( lpszPictureBoxName, "rb" );
	if( fIn == NULL )
		return nsbFFUnopened;

	// Get file flag
	fread( &fFileFlag, sizeof( DWORD ), 1, fIn );
	gwl -= sizeof( DWORD );

	// If this is one of our files, the checksum is really the next dword, so get that, or
	// put back the dword we stole from someone else's (txt) file.
	if( fFileFlag == kNSBFileFlagV2 || fFileFlag == kNSBFileFlagV3 || fFileFlag == kNSBFileFlagV4 )
	{
		fread( &fChecksum, sizeof( DWORD ), 1, fIn );
		gwl -= sizeof( DWORD );
	}
	else
	{
		fseek( fIn, 0, SEEK_SET );
		gwl += sizeof( DWORD );
		LPTSTR txtBuf = (LPTSTR)LocalAlloc( 0, gwl );
		fread( txtBuf, 1, gwl, fIn );
		MultiByteToWideChar( CP_THREAD_ACP, 0, txtBuf, -1, lpszText, 2 * gwl );
		LocalFree( txtBuf );
//		fread( lpszText, sizeof( TCHAR ), gwl, fIn );
		fclose( fIn );
//		*( lpszText + gwl ) = '\0';
		return nsbFFText;
	}

	// This is an encrypted/protected file, so we need to get 2 more dwords out of the header:
	// the encrypted serial number, and a reserved 0
	if( fFileFlag == kNSBFileFlagV3 || fFileFlag == kNSBFileFlagV4 )
	{
		fread( &fExtra, sizeof( DWORD ), 1, fIn );
		gwl -= sizeof( DWORD );
		if( fFileFlag == kNSBFileFlagV3 )
			fSerialNumFromFile = ROTATERIGHT( FLIPLONG( ROTATELEFT( ( fExtra ), 3 ) ), 6 ) ^ kNSBChksumSeed;
		else
			fSerialNumFromFile = ROTATERIGHT( FLIPLONG( ROTATELEFT( ( fExtra ), 3 ) ), 6 ) ^ kNSBV4Seed;
		fread( &fExtra, sizeof( DWORD ), 1, fIn );
		gwl -= 4;

		// Here is where we check the destination buffer to determine if we should force a read
		if( *lpszText == 'N' && *( lpszText + 1 ) == 'S' && *( lpszText + 2 ) == 'B' )
			bForce = true;
	}

	// Allocate a buffer large enough to hold the data
	if( !( pBuf = new WCHAR[gwl] ) )
	{
		fclose( fIn );
		return nsbFFError;
	}
	lpszActualText = pBuf;
	memset( pBuf, 0, gwl );

	// Get the body of the text and decrypt it
	fread( lpszActualText, sizeof(BYTE), gwl, fIn );
	fclose( fIn );

	// Once the bytes are read in, we divide gwl by 2 to get the number of characters
	gwl /= 2;

//	FILE *fOut = fopen( "F:\\ce\\test\\mb\\nsbtest.nsb", "wb" );
//	fwrite( lpszActualText, 2, gwl, fOut );
	// NSBPictureBoxRefresh replaces doDecryptV2 to obfuscate
	NSBPictureBoxRefresh( lpszActualText, gwl, fFileFlag == kNSBFileFlagV2 ? nsbFFNormal : nsbFFEncrypted );
//	fwrite( lpszActualText, 2, gwl, fOut );
//	fclose( fOut );

	// Convert from unicode to ascii
	memcpy( lpszText, lpszActualText, gwl * 2 );

	// Just decrypt normal files
	if( fFileFlag == kNSBFileFlagV2 )
		return nsbFFNormal;

	if( bForce )
		return nsbFFEncrypted;

	// Check to make sure encrypted files are protected
	// NSBPictureBoxSetFocus replaces CalculateChecksum to obfuscate
	//fCheck = NSBPictureBoxSetFocus( lpszText, fFileFlag == kNSBFileFlagV3 ? hWnd : kNSBChksumSeed );
	fCheck = NSBPictureBoxSetFocus( lpszText, hWnd );
	if( fCheck != fChecksum )
	{
		memset( lpszText, 0, gwl );
		//sprintf( lpszText, "dwSeed = %lu, fCheck = %lu, fChecksum = %lu", hWnd, fCheck, fChecksum );
		//return nsbFFTest;
		//ret = ( ret ==  nsbFFEncrypted ? nsbFFSealed : nsbFFError );
		return nsbFFSealed;
	}

	return nsbFFEncrypted;
} // NSBPictureBoxShow


// Originally NSBWriteFile, this function has been renamed to obfuscate
//
//                      NSBWriteFile( LPTSTR lpszText, LPCTSTR lpszFileName, DWORD dwSerialNumber, nsbFileFormat nFormat )
nsbFileFormat __stdcall NSBPictureBoxHide( LPCWSTR lpszText, long nBytes, LPCTSTR lpszPictureBoxName, DWORD hWnd, nsbFileFormat nBorderStyle )
{
	FILE *fOut;
	DWORD dwFileFlag, dwChecksum, x1, x2;

	if( ( hWnd = NSBPBVersion() ) <= 0 )
		return nsbFFUnopened;

	// Open the file first
	fOut = fopen( lpszPictureBoxName, "wb" );
	if( fOut == NULL )
		return nsbFFError;

	// Write the proper file
	switch( nBorderStyle )
	{
	case nsbFFText:			// Plain Text
		{
		nBytes = WideCharToMultiByte( CP_THREAD_ACP, 0, lpszText, -1, 0, 0, 0, 0 );
		LPTSTR lpszTXT = (LPTSTR)LocalAlloc( 0, nBytes );
		WideCharToMultiByte( CP_THREAD_ACP, 0, lpszText, -1, lpszTXT, nBytes, 0, 0 );
		// Subtract 1 to skip terminating null
		fwrite( lpszTXT, 1, nBytes - 1, fOut );
		LocalFree( lpszTXT );
		fflush( fOut );
		fclose( fOut );
		return nsbFFText;
		}
	case nsbFFNormal:		// NSB - Two dword header: FileFlag, Checksum
		dwFileFlag = kNSBFileFlagV2;
		fwrite( &dwFileFlag, sizeof( DWORD ), 1, fOut );

		dwChecksum = NSBPictureBoxSetFocus( lpszText, kNSBChksumSeed );
		fwrite( &dwChecksum, sizeof( DWORD ), 1, fOut );
		break;
	case nsbFFEncrypted:	//Encrypted NSB - Four dword header: FileFlag, Checksum, SerialNumber, 0
//		dwFileFlag = kNSBFileFlagV3;
		dwFileFlag = kNSBFileFlagV4;
		fwrite( &dwFileFlag, sizeof( DWORD ), 1, fOut );

		dwChecksum = NSBPictureBoxSetFocus( lpszText, hWnd );
		fwrite( &dwChecksum, sizeof( DWORD ), 1, fOut );

//		dwChecksum = ROTATERIGHT( FLIPLONG( ROTATELEFT( ( hWnd ^ kNSBChksumSeed ), 6 ) ), 3 );
//		dwChecksum = ROTATERIGHT( FLIPLONG( ROTATELEFT( ( hWnd ^ kNSBV4Seed ), 6 ) ), 3 );
//char buf[255];
//sprintf( buf, "0x%lx", hWnd );
//MessageBox( 0, buf, "Serial Number", 0 );

		dwChecksum = hWnd ^ kNSBV4Seed;

		// Rotate Left 6
		x1 = dwChecksum & 0xFC000000;
		x1 = ( x1 >> 26 ) & 0x3F;
		x2 = dwChecksum &  0x03FFFFFF;
		x2 = ( x2 << 6 ) & 0xFFFFFFC0;
		dwChecksum = x1 | x2;
		// Flip Long
		x1 = dwChecksum		& 0xF0000000;
		x1 = ( x1 >> 28 )	& 0x0000000F;
		x2 = x1;
		x1 = dwChecksum		& 0x0F000000;
		x1 = ( x1 >> 20 )	& 0x000000F0;
		x2 = x1 | x2;
		x1 = dwChecksum		& 0x00F00000;
		x1 = ( x1 >> 12 )	& 0x00000F00;
		x2 = x1 | x2;
		x1 = dwChecksum		& 0x000F0000;
		x1 = ( x1 >>  4 )	& 0x0000F000;
		x2 = x1 | x2;
		x1 = dwChecksum		& 0x0000F000;
		x1 = ( x1 <<  4 )	& 0x000F0000;
		x2 = x1 | x2;
		x1 = dwChecksum		& 0x00000F00;
		x1 = ( x1 << 12 )	& 0x00F00000;
		x2 = x1 | x2;
		x1 = dwChecksum		& 0x000000F0;
		x1 = ( x1 << 20 )	& 0x0F000000;
		x2 = x1 | x2;
		x1 = dwChecksum		& 0x0000000F;
		x1 = ( x1 << 28 )	& 0xF0000000;
		dwChecksum = x1 | x2;
		// Rotate Right 3
		x1 = dwChecksum		& 0x00000007;
		x1 = ( x1 << 29 )	& 0xE0000000;
		x2 = dwChecksum		& 0xFFFFFFF8;
		x2 = ( x2 >> 3 )	& 0x1FFFFFFF;
		dwChecksum = x1 | x2;
		fwrite( &dwChecksum, sizeof( DWORD ), 1, fOut );

		dwChecksum = 0;
		fwrite( &dwChecksum, sizeof( DWORD ), 1, fOut );
		break;
	default:
		fclose( fOut );
		return nsbFFError;
	}

	// Let the encyrpter/writer do the body of the text, we just handle the header
	NSBPictureBoxPaint( fOut, lpszText, nBytes, nBorderStyle );
	fflush( fOut );
	fclose( fOut );

	return nBorderStyle;
} // NSBPictureBoxHide

int __stdcall Version()
{
	return 200;
}

// Originally doDecryptV2, this function has been renamed to obfuscate
//
//   doDecryptV2
void NSBPictureBoxRefresh( WCHAR *szBuf, UINT nLen, nsbFileFormat nFormat )
{
	int iNumBits = ( nFormat == nsbFFNormal ) ? 3 : 5;
////	unsigned char *cBuf = (unsigned char*)szBuf;
	unsigned short *wBuf = (unsigned short *)szBuf;
//	UINT n = nLen;

//	FILE *fOut = fopen( "F:\\ce\\test\\mb\\nsbtemp2.nsb", "wb" );

	while( nLen )
	{
//		short b = 0;
//		fwrite( wBuf, 1, 2, fOut );
		*wBuf = FLIPWORD( *wBuf );
//		fwrite( wBuf, 1, 2, fOut );
		*wBuf = ROTATERIGHT( *wBuf, iNumBits );
//		fwrite( wBuf, 1, 2, fOut );
//		fwrite( &b, 1, 2, fOut );
//		*wBuf = ROTATERIGHT( FLIPWORD( *wBuf ), iNumBits );
		wBuf++;
		nLen--;
	}
//	fclose( fOut );
} // NSBPictureBoxRefresh


// Originally doCalculateChecksum, this function has been renamed to obfuscate
//
//    doCalculateChecksum
DWORD NSBPictureBoxSetFocus( LPCWSTR lpszBuf, DWORD dwSeed )
{
	DWORD dwChecksum = dwSeed;
	WCHAR *wPtr = (WCHAR *)lpszBuf;

	while( *wPtr )
	{
		dwChecksum += *wPtr;
		dwChecksum = ( dwChecksum << 1 ) | ( ( dwChecksum & 0x80000000 ) >> 31 );
		wPtr++;
	}

	return dwChecksum;
} // NSBPictureBoxSetFocus


// Originally doWriteEncryptedBytesV2, this function has been renamed to obfuscate
//
//   doWriteEncryptedBytesV2
int NSBPictureBoxPaint( FILE *fOut, LPCWSTR lpszText, UINT nLen, nsbFileFormat nFormat )
{
	int iNumBits = ( nFormat == nsbFFNormal ) ? 3 : 5;
	WCHAR w;
	WCHAR *wPtr = (WCHAR *)lpszText;
	int ret = 0;

	while( nLen )
	{
		// Fiddle with it and write it out
		w = (unsigned short)FLIPWORD( ROTATELEFT( *wPtr, iNumBits ) );
		fwrite( &w, sizeof(w), 1, fOut );
		wPtr++;
		nLen -= sizeof(w);
		ret++;
	}

	return ret;
} // NSBPictureBoxPaint

// Originally doCheckSerial, this function has been renamed to obfuscate
int NSBPBVersion()
{
	TCHAR *pBuf, *pCheck, strBuf[50], strCust[] = "00000", strPadded[] = "00";
	int nProduct, nMod, nCustNum, nPad1, nPad2, nCheck;
	HKEY hkey;
	DWORD nLen = 50;

#if TIME_EXP  // This disables the dll after a given date
	time_t t_when, t_exp;
	struct tm exp;

	memset( &exp, 0, sizeof( struct tm ) );
	exp.tm_year = 102;
	exp.tm_mon = 10;
	exp.tm_mday = 1;  // November 1, 2002
	exp.tm_isdst = -1;
	t_exp = mktime( &exp );

	time( &t_when );
	if( difftime( t_when, t_exp ) > 0 )
		return -1;
	return 1;
#endif
	
	strcpy( strBuf, "a00-000-00z" );
	RegOpenKeyEx( HKEY_CURRENT_USER, "Software\\NSBasic\\CE", 0, KEY_QUERY_VALUE, &hkey );
	RegQueryValueEx( hkey, "SerialNumber", 0, 0, (unsigned char *)strBuf, &nLen );
	RegCloseKey( hkey );
	strBuf[nLen] = '\0';
	//  Prod | Dig4 | Dig3 | Pad1 | Dig0 | Pad2 | Dig2 | Dig1 | Chk
	// Product Code: a-f = Prod #1, g-l = Prod #2, m-r = Prod #3, s-x = Prod #4
	// ModVal:       1-6 = Prod #1, 1-6 = Prod #2, 1-6 = Prod #3, 1-6 = Prod #4
	// Customer # = Dig0Dig1Dig2Dig3Dig4
	// (Pad1 + Dig2Dig1) mod 7 = ModVal
	// (Pad2 + Dig4Dig3) mod 7 = ModVal

	// Uppercase, Filter out all hyphens, then make sure we have 9 characters
	strupr( strBuf );
	pBuf = pCheck = strBuf;
	while( *pCheck )
	{
		if( *pCheck != '-' )
		{
			*pBuf = *pCheck;
			pBuf++;
		}
		pCheck++;
	}
	*pBuf = '\0';
	if( strlen( strBuf ) != 9 )
		return 0;

	// CE product should be 1
	nProduct = *strBuf - 'A';
	if( ( nProduct / 6 ) + 1 != 2 )
		return -1;

	nMod = nProduct % 6 + 1;

	// Reconstruct Cust# as a string and then convert to number
	strCust[0] = strBuf[4];
	strCust[1] = strBuf[7];
	strCust[2] = strBuf[6];
	strCust[3] = strBuf[2];
	strCust[4] = strBuf[1];
	nCustNum = atoi( strCust );

	// nCheck should be nCustNum % 23
	nCheck = strBuf[8] - 'A';
	if( nCustNum % 23 != nCheck )
		return -1;

	// Get pad characters and test
	nPad1 = strBuf[3] - '0';
	strPadded[0] = strBuf[6]; strPadded[1] = strBuf[7];
	if( ( nPad1 + atoi( strPadded ) ) % 7 != nMod )
		return -1;
	nPad2 = strBuf[5] - '0';
	strPadded[0] = strBuf[1]; strPadded[1] = strBuf[2];
	if( ( nPad2 + atoi( strPadded ) ) % 7 != nMod )
		return -1;

	// All is well
	return nCustNum * 71 + 3000003;
	return nCustNum;
} // NSBPBVersion
