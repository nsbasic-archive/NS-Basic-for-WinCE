<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: CE4 - Win32 (WCE ARMV4) Release MinDependency--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "output/Desk.tlb" /o "NUL" /win32 "E:\NSBCE7\Controls\NSBWin32\src\Desk.idl""
Creating command line "rc.exe /l 0x409 /fo"output/Desk.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "NDEBUG" /d "UNICODE" /d "_UNICODE" /d "WIN32_PLATFORM_WFSP=200" /d "ARM" /d "_ARM_" /d "ARMV4" /r "E:\NSBCE7\Controls\NSBWin32\src\Desk.rc"" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA2B.tmp" with contents
[
/nologo /W3 /I "../include" /D "_USRDLL" /D "WIN32_PLATFORM_WFSP=200" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_ATL_MIN_CRT" /D "_ATL_STATIC_REGISTRY" /Fp"output/CE4.pch" /Yu"stdafx.h" /Fo"output/" /O2 /MC /c 
"E:\NSBCE7\Controls\NSBWin32\src\API.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\APIPosPoint.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\Desk.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\MiniEnum.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\RAS.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\RASConState.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\RASEntry.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\Registry.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\Timer.cpp"
"E:\NSBCE7\Controls\NSBWin32\src\Tray.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA2B.tmp" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA2C.tmp" with contents
[
/nologo /W3 /I "../include" /D "_USRDLL" /D "WIN32_PLATFORM_WFSP=200" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_ATL_MIN_CRT" /D "_ATL_STATIC_REGISTRY" /Fp"output/CE4.pch" /Yc"stdafx.h" /Fo"output/" /O2 /MC /c 
"E:\NSBCE7\Controls\NSBWin32\src\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA2C.tmp" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA2D.tmp" with contents
[
ceshell.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"output/NSBWin32.pdb" /def:".\Desk.def" /out:"output/NSBWin32.dll" /implib:"output/NSBWin32.lib" /subsystem:windowsce,4.20 /align:"4096" /MACHINE:ARM 
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
Creating command line "link.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPA2D.tmp"
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
StdAfx.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Including ccBuffer (ccbuffer.h) - link with: ccbuffer.cpp
Including ccSafeArray (safearrayhelper.h)
Compiling...
API.cpp
APIPosPoint.cpp
Desk.cpp
MiniEnum.cpp
RAS.cpp
RASConState.cpp
RASEntry.cpp
Registry.cpp
Timer.cpp
Tray.cpp
Generating Code...
Linking...
.\Desk.def : warning LNK4222: exported symbol 'DllCanUnloadNow' should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol 'DllGetClassObject' should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol 'DllRegisterServer' should not be assigned an ordinal
.\Desk.def : warning LNK4222: exported symbol 'DllUnregisterServer' should not be assigned an ordinal
   Creating library output/NSBWin32.lib and object output/NSBWin32.exp
NSBWin32.exp : warning LNK4070: /OUT:Desk.DLL directive in .EXP differs from output filename 'output/NSBWin32.dll'; ignoring directive
Signing E:\NSBCE7\Controls\NSBWin32\src\output\NSBWin32.dll
Warning: This file is signed, but not timestamped.
Succeeded





<h3>Results</h3>
NSBWin32.dll - 0 error(s), 5 warning(s)
</pre>
</body>
</html>
