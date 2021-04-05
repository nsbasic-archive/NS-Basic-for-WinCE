<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: EVC4 - Win32 (WCE ARMV4) Release MinDependency--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "output/Desk.tlb" /o "NUL" /win32 "E:\NSBCE7\Controls\NSBComDlg\src\Desk.idl""
Creating command line "rc.exe /l 0x409 /fo"output/Desk.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "NDEBUG" /d "UNICODE" /d "_UNICODE" /d "WIN32_PLATFORM_WFSP=200" /d "ARM" /d "_ARM_" /d "ARMV4" /r "E:\NSBCE7\Controls\NSBComDlg\src\Desk.rc"" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA14.tmp" with contents
[
/nologo /W3 /I "../include" /D "_USRDLL" /D "WIN32_PLATFORM_WFSP=200" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_ATL_STATIC_REGISTRY" /Fo"output/" /O2 /MC /c 
"E:\NSBCE7\Controls\NSBComDlg\src\ComDlgMiniEnum.cpp"
"E:\NSBCE7\Controls\NSBComDlg\src\Desk.cpp"
"E:\NSBCE7\Controls\NSBComDlg\src\NSComDlg.cpp"
"E:\NSBCE7\Controls\NSBComDlg\src\NSComDlgFlags.cpp"
"E:\NSBCE7\Controls\NSBComDlg\src\StdAfx.cpp"
"E:\NSBCE7\Controls\NSBComDlg\src\whichplatform.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA14.tmp" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA15.tmp" with contents
[
commdlg.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"output/NSBComDlg.pdb" /def:".\Desk.def" /out:"output/NSBComDlg.dll" /implib:"output/NSBComDlg.lib" /subsystem:windowsce,4.20 /align:"4096" /MACHINE:ARM 
.\output\ComDlgMiniEnum.obj
.\output\Desk.obj
.\output\NSComDlg.obj
.\output\NSComDlgFlags.obj
.\output\StdAfx.obj
.\output\whichplatform.obj
.\output\Desk.res
]
Creating command line "link.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA15.tmp"
<h3>Output Window</h3>
Creating Type Library...
Desk.idl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
basetsd.h
ocidl.idl
oleidl.idl
Compiling resources...
Compiling...
ComDlgMiniEnum.cpp
Desk.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
NSComDlg.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
NSComDlgFlags.cpp
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
whichplatform.cpp
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
.\Desk.def : warning LNK4222: exported symbol 'DllCanUnloadNow' should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol 'DllGetClassObject' should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol 'DllRegisterServer' should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol 'DllUnregisterServer' should not be assigned an ordinal
   Creating library output/NSBComDlg.lib and object output/NSBComDlg.exp
NSBComDlg.exp : warning LNK4070: /OUT:Desk.DLL directive in .EXP differs from output filename 'output/NSBComDlg.dll'; ignoring directive
Signing E:\NSBCE7\Controls\NSBComDlg\src\output\NSBComDlg.dll
Warning: This file is signed, but not timestamped.
Succeeded





<h3>Results</h3>
NSBComDlg.dll - 0 error(s), 5 warning(s)
</pre>
</body>
</html>
