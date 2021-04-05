<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309PictureBox - Win32 (WCE x86) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "X86/S309PictureBox.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309PictureBox\S309PictureBox.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309PictureBox.res" /i "X86" /d "x86" /d "_i386_" /d "_X86_" /d UNDER_CE=300 /d "UNICODE" /d _WIN32_WCE=300 /d "NDEBUG" /d "_AFXDLL" /d "WIN32_PLATFORM_PSPC=310" /r "W:\ActiveX\S309PictureBox\S309PictureBox.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1548.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309PictureBox.pch" /Yu"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"W:\ActiveX\S309PictureBox\Res.cpp"
"W:\ActiveX\S309PictureBox\S309Bitmap.cpp"
"W:\ActiveX\S309PictureBox\S309PictureBox.cpp"
"W:\ActiveX\S309PictureBox\S309PictureBoxCtl.cpp"
"W:\ActiveX\S309PictureBox\S309PictureBoxPpg.cpp"
"W:\ActiveX\S309PictureBox\UrlImage.cpp"
"W:\ActiveX\S309PictureBox\UrlImageData.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1548.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1549.tmp" with contents
[
/nologo /W3 /O2 /D "x86" /D "_i386_" /D "_X86_" /D _WIN32_WCE=300 /D UNDER_CE=300 /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309PictureBox.pch" /Yc"stdafx.h" /Fo"Intermediate/" /Gs8192 /GF /c 
"W:\ActiveX\S309PictureBox\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1549.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP154A.tmp" with contents
[
wininet.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /dll /incremental:no /pdb:"X86/S309PictureBox208.pdb" /def:".\S309PictureBox.def" /out:"X86/S309PictureBox208.ocx" /implib:"X86/S309PictureBox208.lib" /machine:IX86 /subsystem:windowsce,3.00 
.\Intermediate\Res.obj
.\Intermediate\S309Bitmap.obj
.\Intermediate\S309PictureBox.obj
.\Intermediate\S309PictureBoxCtl.obj
.\Intermediate\S309PictureBoxPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\UrlImage.obj
.\Intermediate\UrlImageData.obj
.\Intermediate\S309PictureBox.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP154A.tmp"
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
Res.cpp
S309Bitmap.cpp
S309PictureBox.cpp
S309PictureBoxCtl.cpp
S309PictureBoxPpg.cpp
UrlImage.cpp
UrlImageData.cpp
Generating Code...
Linking...
   Creating library X86/S309PictureBox208.lib and object X86/S309PictureBox208.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1555.bat" with contents
[
@echo off
mkdir  ".\X86 WIN32_PLATFORM_PSPC=310 300"
del /q ".\X86 WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\X86\*.*" ".\X86 WIN32_PLATFORM_PSPC=310 300\"
del /q ".\X86\*.*"
rmdir ".\X86"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP1555.bat"

.\X86\S309PictureBox.tlb
.\X86\S309PictureBox208.exp
.\X86\S309PictureBox208.lib
.\X86\S309PictureBox208.ocx
4 File(s) copied




<h3>Results</h3>
S309PictureBox208.ocx - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
