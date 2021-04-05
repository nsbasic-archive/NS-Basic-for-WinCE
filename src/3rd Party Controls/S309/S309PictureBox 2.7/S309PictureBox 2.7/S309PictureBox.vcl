<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309PictureBox - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Arm/S309PictureBox.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309PictureBox 2.7\S309PictureBox.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309PictureBox.res" /i "Arm" /d "ARM" /d "_ARM_" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "W:\ActiveX\S309PictureBox 2.7\S309PictureBox.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F4F.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309PictureBox.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"W:\ActiveX\S309PictureBox 2.7\S309PictureBox.cpp"
"W:\ActiveX\S309PictureBox 2.7\S309PictureBoxCtl.cpp"
"W:\ActiveX\S309PictureBox 2.7\S309PictureBoxPpg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F4F.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F50.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309PictureBox.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"W:\ActiveX\S309PictureBox 2.7\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F50.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F51.tmp" with contents
[
imgdecmp.lib /nologo /stack:0x10000,0x1000 /dll /incremental:no /pdb:"Arm/S309PictureBox.pdb" /def:".\S309PictureBox.def" /out:"Arm/S309PictureBox.ocx" /implib:"Arm/S309PictureBox.lib" /machine:ARM /subsystem:windowsce,3.00 
".\Intermediate\S309PictureBox.obj"
".\Intermediate\S309PictureBoxCtl.obj"
".\Intermediate\S309PictureBoxPpg.obj"
".\Intermediate\StdAfx.obj"
".\Intermediate\S309PictureBox.res"
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F51.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309PictureBox.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
S309PictureBox.cpp
S309PictureBoxCtl.cpp
S309PictureBoxPpg.cpp
Generating Code...
Linking...
.\S309PictureBox.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\S309PictureBox.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\S309PictureBox.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\S309PictureBox.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library Arm/S309PictureBox.lib and object Arm/S309PictureBox.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5C.bat" with contents
[
@echo off
mkdir  ".\Arm WIN32_PLATFORM_PSPC=310 300"
del /q ".\Arm WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\Arm\*.*" ".\Arm WIN32_PLATFORM_PSPC=310 300\"
del /q ".\Arm\*.*"
rmdir ".\Arm"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5C.bat"

A subdirectory or file .\Arm WIN32_PLATFORM_PSPC=310 300 already exists.
.\Arm\S309PictureBox.exp
.\Arm\S309PictureBox.lib
.\Arm\S309PictureBox.ocx
.\Arm\S309PictureBox.tlb
4 File(s) copied




<h3>Results</h3>
S309PictureBox.ocx - 0 error(s), 4 warning(s)
<h3>
--------------------Configuration: S309PictureBox - Win32 (WCE x86) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "X86/S309PictureBox.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309PictureBox 2.7\S309PictureBox.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309PictureBox.res" /i "X86" /d "x86" /d "_i386_" /d "_X86_" /d _WIN32_WCE=300 /d UNDER_CE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "W:\ActiveX\S309PictureBox 2.7\S309PictureBox.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5D.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309PictureBox.pch" /Yu"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"W:\ActiveX\S309PictureBox 2.7\S309PictureBox.cpp"
"W:\ActiveX\S309PictureBox 2.7\S309PictureBoxCtl.cpp"
"W:\ActiveX\S309PictureBox 2.7\S309PictureBoxPpg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5D.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5E.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309PictureBox.pch" /Yc"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"W:\ActiveX\S309PictureBox 2.7\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5E.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5F.tmp" with contents
[
imgdecmp.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /dll /incremental:no /pdb:"X86/S309PictureBox.pdb" /def:".\S309PictureBox.def" /out:"X86/S309PictureBox.ocx" /implib:"X86/S309PictureBox.lib" /machine:IX86 /subsystem:windowsce,3.00 
".\Intermediate\S309PictureBox.obj"
".\Intermediate\S309PictureBoxCtl.obj"
".\Intermediate\S309PictureBoxPpg.obj"
".\Intermediate\StdAfx.obj"
".\Intermediate\S309PictureBox.res"
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F5F.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309PictureBox.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
S309PictureBox.cpp
S309PictureBoxCtl.cpp
S309PictureBoxPpg.cpp
Generating Code...
Linking...
.\S309PictureBox.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\S309PictureBox.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\S309PictureBox.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\S309PictureBox.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library X86/S309PictureBox.lib and object X86/S309PictureBox.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F6A.bat" with contents
[
@echo off
mkdir  ".\X86 WIN32_PLATFORM_PSPC=310 300"
del /q ".\X86 WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\X86\*.*" ".\X86 WIN32_PLATFORM_PSPC=310 300\"
del /q ".\X86\*.*"
rmdir ".\X86"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1F6A.bat"

A subdirectory or file .\X86 WIN32_PLATFORM_PSPC=310 300 already exists.
.\X86\S309PictureBox.exp
.\X86\S309PictureBox.lib
.\X86\S309PictureBox.ocx
.\X86\S309PictureBox.tlb
4 File(s) copied




<h3>Results</h3>
S309PictureBox.ocx - 0 error(s), 4 warning(s)
</pre>
</body>
</html>
