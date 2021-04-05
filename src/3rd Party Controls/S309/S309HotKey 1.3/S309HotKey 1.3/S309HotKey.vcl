<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309HotKey - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Arm/S309HotKey.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309HotKey\S309HotKey.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309HotKey.res" /i "Arm" /d "ARM" /d "_ARM_" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "W:\ActiveX\S309HotKey\S309HotKey.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSPB.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309HotKey.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"W:\ActiveX\S309HotKey\S309HotKey.cpp"
"W:\ActiveX\S309HotKey\S309HotKeyCtl.cpp"
"W:\ActiveX\S309HotKey\S309HotKeyPpg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSPB.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSPC.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309HotKey.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"W:\ActiveX\S309HotKey\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSPC.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSPD.tmp" with contents
[
/nologo /stack:0x10000,0x1000 /dll /incremental:no /pdb:"Arm/S309HotKey.pdb" /def:".\S309HotKey.def" /out:"Arm/S309HotKey.ocx" /implib:"Arm/S309HotKey.lib" /machine:ARM /subsystem:windowsce,3.00 
.\Intermediate\S309HotKey.obj
.\Intermediate\S309HotKeyCtl.obj
.\Intermediate\S309HotKeyPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309HotKey.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSPD.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309HotKey.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
S309HotKey.cpp
S309HotKeyCtl.cpp
S309HotKeyPpg.cpp
Generating Code...
Linking...
.\S309HotKey.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\S309HotKey.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\S309HotKey.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\S309HotKey.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library Arm/S309HotKey.lib and object Arm/S309HotKey.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP18.bat" with contents
[
@echo off
mkdir  ".\Arm WIN32_PLATFORM_PSPC=310 300"
del /q ".\Arm WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\Arm\*.*" ".\Arm WIN32_PLATFORM_PSPC=310 300\"
del /q ".\Arm\*.*"
rmdir ".\Arm"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP18.bat"

.\Arm\S309HotKey.exp
.\Arm\S309HotKey.lib
.\Arm\S309HotKey.ocx
.\Arm\S309HotKey.tlb
4 File(s) copied




<h3>Results</h3>
S309HotKey.ocx - 0 error(s), 4 warning(s)
<h3>
--------------------Configuration: S309HotKey - Win32 (WCE x86) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "X86/S309HotKey.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309HotKey\S309HotKey.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309HotKey.res" /i "X86" /d "x86" /d "_i386_" /d "_X86_" /d _WIN32_WCE=300 /d UNDER_CE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "W:\ActiveX\S309HotKey\S309HotKey.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP19.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309HotKey.pch" /Yu"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"W:\ActiveX\S309HotKey\S309HotKey.cpp"
"W:\ActiveX\S309HotKey\S309HotKeyCtl.cpp"
"W:\ActiveX\S309HotKey\S309HotKeyPpg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP19.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1A.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309HotKey.pch" /Yc"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"W:\ActiveX\S309HotKey\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1A.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1B.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /dll /incremental:no /pdb:"X86/S309HotKey.pdb" /def:".\S309HotKey.def" /out:"X86/S309HotKey.ocx" /implib:"X86/S309HotKey.lib" /machine:IX86 /subsystem:windowsce,3.00 
.\Intermediate\S309HotKey.obj
.\Intermediate\S309HotKeyCtl.obj
.\Intermediate\S309HotKeyPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309HotKey.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1B.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309HotKey.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
S309HotKey.cpp
S309HotKeyCtl.cpp
S309HotKeyPpg.cpp
Generating Code...
Linking...
.\S309HotKey.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\S309HotKey.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\S309HotKey.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\S309HotKey.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library X86/S309HotKey.lib and object X86/S309HotKey.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP26.bat" with contents
[
@echo off
mkdir  ".\X86 WIN32_PLATFORM_PSPC=310 300"
del /q ".\X86 WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\X86\*.*" ".\X86 WIN32_PLATFORM_PSPC=310 300\"
del /q ".\X86\*.*"
rmdir ".\X86"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP26.bat"

.\X86\S309HotKey.exp
.\X86\S309HotKey.lib
.\X86\S309HotKey.ocx
.\X86\S309HotKey.tlb
4 File(s) copied




<h3>Results</h3>
S309HotKey.ocx - 0 error(s), 4 warning(s)
</pre>
</body>
</html>
