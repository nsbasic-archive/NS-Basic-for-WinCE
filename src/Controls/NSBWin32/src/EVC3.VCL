<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: EVC3 - Win32 (WCE ARM) PPC2002_Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "output/Desk.tlb" /o "NUL" /win32 "E:\NSBCE6\Controls\NSBWin32\src\Desk.idl""
Creating command line "rc.exe /l 0x409 /fo"output/Desk.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "ARM" /d "_ARM_" /r "E:\NSBCE6\Controls\NSBWin32\src\Desk.rc"" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP58C.tmp" with contents
[
/nologo /W3 /I "../Include" /I "../include" /D "_USRDLL" /D "WIN32_PLATFORM_PSPC=310" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_ATL_STATIC_REGISTRY" /Fo"output/" /Oxs /MC /c 
"E:\NSBCE6\Controls\NSBWin32\src\API.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\APIPosPoint.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\Desk.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\MiniEnum.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\RAS.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\RASConState.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\RASEntry.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\Registry.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\StdAfx.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\Timer.cpp"
"E:\NSBCE6\Controls\NSBWin32\src\Tray.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP58C.tmp" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP58D.tmp" with contents
[
ceshell.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"output/NSBWin32.pdb" /def:".\Desk.def" /out:"output/NSBWin32.dll" /implib:"output/NSBWin32.lib" /subsystem:windowsce,3.00 /align:"4096" /MACHINE:ARM 
.\output\API.obj
.\output\APIPosPoint.obj
.\output\Desk.obj
.\output\MiniEnum.obj
.\output\RAS.obj
.\output\RASConState.obj
.\output\RASEntry.obj
.\output\Registry.obj
.\output\StdAfx.obj
.\output\Timer.obj
.\output\Tray.obj
.\output\Desk.res
]
Creating command line "link.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP58D.tmp"
<h3>Output Window</h3>
Creating Type Library...
Desk.idl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
ocidl.idl
oleidl.idl
Compiling resources...
Compiling...
API.cpp
APIPosPoint.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Desk.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
MiniEnum.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
RAS.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
RASConState.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
RASEntry.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Registry.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
StdAfx.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Timer.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Tray.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Generating Code...
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Linking...
.\Desk.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library output/NSBWin32.lib and object output/NSBWin32.exp
NSBWin32.exp : warning LNK4070: /OUT:Desk.DLL directive in .EXP differs from output filename "output/NSBWin32.dll"; ignoring directive




<h3>Results</h3>
NSBWin32.dll - 0 error(s), 5 warning(s)
</pre>
</body>
</html>
