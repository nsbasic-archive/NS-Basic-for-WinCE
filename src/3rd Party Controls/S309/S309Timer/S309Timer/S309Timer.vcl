<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309Timer - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Arm/S309Timer.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309Timer\S309Timer.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309Timer.res" /i "Arm" /d "ARM" /d "_ARM_" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "C:\Source\WindowsCE\ActiveX\S309Timer\S309Timer.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP5F3.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309Timer.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309Timer\S309Timer.cpp"
"C:\Source\WindowsCE\ActiveX\S309Timer\S309TimerCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309Timer\S309TimerPpg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP5F3.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP5F4.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309Timer.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309Timer\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP5F4.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP5F5.tmp" with contents
[
/nologo /stack:0x10000,0x1000 /dll /incremental:no /pdb:"Arm/S309Timer.pdb" /def:".\S309Timer.def" /out:"Arm/S309Timer.ocx" /implib:"Arm/S309Timer.lib" /machine:ARM /subsystem:windowsce,3.00 
.\Intermediate\S309Timer.obj
.\Intermediate\S309TimerCtl.obj
.\Intermediate\S309TimerPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309Timer.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP5F5.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309Timer.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
S309Timer.cpp
S309TimerCtl.cpp
S309TimerPpg.cpp
Generating Code...
Linking...
.\S309Timer.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\S309Timer.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\S309Timer.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\S309Timer.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library Arm/S309Timer.lib and object Arm/S309Timer.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP600.bat" with contents
[
@echo off
mkdir  ".\Arm WIN32_PLATFORM_PSPC=310 300"
del /q ".\Arm WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\Arm\*.*" ".\Arm WIN32_PLATFORM_PSPC=310 300\"
del /q ".\Arm\*.*"
rmdir ".\Arm"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP600.bat"

.\Arm\S309Timer.exp
.\Arm\S309Timer.lib
.\Arm\S309Timer.ocx
.\Arm\S309Timer.tlb
4 File(s) copied




<h3>Results</h3>
S309Timer.ocx - 0 error(s), 4 warning(s)
<h3>
--------------------Configuration: S309Timer - Win32 (WCE x86) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "X86/S309Timer.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309Timer\S309Timer.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309Timer.res" /i "X86" /d "x86" /d "_i386_" /d "_X86_" /d _WIN32_WCE=300 /d UNDER_CE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "C:\Source\WindowsCE\ActiveX\S309Timer\S309Timer.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP601.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309Timer.pch" /Yu"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"C:\Source\WindowsCE\ActiveX\S309Timer\S309Timer.cpp"
"C:\Source\WindowsCE\ActiveX\S309Timer\S309TimerCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309Timer\S309TimerPpg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP601.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP602.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309Timer.pch" /Yc"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"C:\Source\WindowsCE\ActiveX\S309Timer\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP602.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP603.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /dll /incremental:no /pdb:"X86/S309Timer.pdb" /def:".\S309Timer.def" /out:"X86/S309Timer.ocx" /implib:"X86/S309Timer.lib" /machine:IX86 /subsystem:windowsce,3.00 
.\Intermediate\S309Timer.obj
.\Intermediate\S309TimerCtl.obj
.\Intermediate\S309TimerPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309Timer.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP603.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309Timer.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
S309Timer.cpp
S309TimerCtl.cpp
S309TimerPpg.cpp
Generating Code...
Linking...
.\S309Timer.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\S309Timer.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\S309Timer.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\S309Timer.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library X86/S309Timer.lib and object X86/S309Timer.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP60E.bat" with contents
[
@echo off
mkdir  ".\X86 WIN32_PLATFORM_PSPC=310 300"
del /q ".\X86 WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\X86\*.*" ".\X86 WIN32_PLATFORM_PSPC=310 300\"
del /q ".\X86\*.*"
rmdir ".\X86"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP60E.bat"

.\X86\S309Timer.exp
.\X86\S309Timer.lib
.\X86\S309Timer.ocx
.\X86\S309Timer.tlb
4 File(s) copied




<h3>Results</h3>
S309Timer.ocx - 0 error(s), 4 warning(s)
</pre>
</body>
</html>
