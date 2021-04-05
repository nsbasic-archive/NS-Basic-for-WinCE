#define kNSBFileFlagV2	0xFF0011DD
#define kNSBFileFlagV3	0xFF0022DD
#define kNSBFileFlagV4	0xFF0044DD
#define kNSBChksumSeed	0xF163808F
#define kNSBV4Seed		0xF808361F

typedef enum
{
	nsbFFTest = -44,
	nsbFFSealed = -2,
	nsbFFError = -1,
	nsbFFUnopened = 0,
	nsbFFText = 1,
	nsbFFNormal = 2,
	nsbFFEncrypted = 3
} nsbFileFormat;

// NSBReadFile
nsbFileFormat __stdcall		NSBPictureBoxShow( LPCTSTR lpszPictureBoxName, UINT gwl, DWORD hWnd, LPTSTR lpszText );
// NSBWriteFile
nsbFileFormat __stdcall		NSBPictureBoxHide( LPCWSTR lpszText, LPCTSTR lpszPictureBoxName, DWORD hWnd, nsbFileFormat nBorderStyle );
// Version Protection
int __stdcall	Version();
// doDecryptV2
void	NSBPictureBoxRefresh( WCHAR *szBuf, UINT nLen, nsbFileFormat nFormat );
// doCalculateChecksum
DWORD	NSBPictureBoxSetFocus( LPCWSTR lpszBuf, DWORD dwSeed );
// doWriteEncyptedBytesV2
int	NSBPictureBoxPaint( FILE *fOut, LPCWSTR lpszText, UINT nLen, nsbFileFormat nFormat );
// doCheckSerial
int NSBPBVersion();

#define ROTATELEFT(xrl,count)  ( ( ( xrl ) << count ) | ( ( xrl ) >> ( ( 8 * sizeof( xrl ) ) - count ) ) )
#define ROTATERIGHT(xrr,count) ( ( ( xrr ) >> count ) | ( ( xrr ) << ( ( 8 * sizeof( xrr ) ) - count ) ) )

#define FLIPNIBBLE(xfn) ( ( xfn & 0xF0 >> 4 ) | ( xfn & 0x0F << 4 ) )
#define FLIPWORD(xfw)   ( ( FLIPNIBBLE( ( xfw & 0xFF00 ) >> 8 ) ) | ( ( FLIPNIBBLE( xfw & 0xFF ) ) << 8 ) )
#define FLIPLONG(xfl)   ( ( FLIPWORD( ( xfl & 0xFFFF0000 ) >> 16 ) ) | ( ( FLIPWORD( xfl & 0xFFFF ) ) << 16 ) )
