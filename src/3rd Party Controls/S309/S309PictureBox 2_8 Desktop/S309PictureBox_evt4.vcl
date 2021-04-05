<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309PictureBox - Win32 (WCE ARMV4T) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "ARMV4T/S309PictureBox.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309PictureBox\S309PictureBox.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309PictureBox.res" /i "ARMV4T" /d UNDER_CE=400 /d _WIN32_WCE=400 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WCE_PLATFORM_STANDARDSDK" /d "THUMB" /d "_THUMB_" /d "ARM" /d "_ARM_" /d "ARMV4T" /d "_AFXDLL" /r "W:\ActiveX\S309PictureBox\S309PictureBox.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP191E.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=400 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_STANDARDSDK" /D "THUMB" /D "_THUMB_" /D "ARMV4T" /D UNDER_CE=400 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_AFXDLL" /Fp"Intermediate/S309PictureBox_evt4.pch" /YX /Fo"Intermediate/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"W:\ActiveX\S309PictureBox\Res.cpp"
"W:\ActiveX\S309PictureBox\S309PictureBox.cpp"
"W:\ActiveX\S309PictureBox\S309PictureBoxCtl.cpp"
"W:\ActiveX\S309PictureBox\S309PictureBoxPpg.cpp"
"W:\ActiveX\S309PictureBox\StdAfx.cpp"
"W:\ActiveX\S309PictureBox\UrlImage.cpp"
"W:\ActiveX\S309PictureBox\UrlImageData.cpp"
]
Creating command line "clthumb.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP191E.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP191F.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"ARMV4T/S309PictureBox.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /def:".\S309PictureBox.def" /out:"ARMV4T/S309PictureBox.ocx" /implib:"ARMV4T/S309PictureBox.lib" /subsystem:windowsce,4.00 /MACHINE:THUMB 
.\Intermediate\Res.obj
.\Intermediate\S309PictureBox.obj
.\Intermediate\S309PictureBoxCtl.obj
.\Intermediate\S309PictureBoxPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\UrlImage.obj
.\Intermediate\UrlImageData.obj
.\Intermediate\S309PictureBox.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP191F.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309PictureBox.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
basetsd.h
Compiling resources...
Compiling...
Res.cpp
S309PictureBox.cpp
S309PictureBoxCtl.cpp
S309PictureBoxPpg.cpp
StdAfx.cpp
UrlImage.cpp
UrlImageData.cpp
Linking...
   Creating library ARMV4T/S309PictureBox.lib and object ARMV4T/S309PictureBox.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP192C.bat" with contents
[
@echo off
mkdir  ".\ARMV4T WCE_PLATFORM_STANDARDSDK 400"
del /q ".\ARMV4T WCE_PLATFORM_STANDARDSDK 400\*.*"
xcopy ".\ARMV4T\*.*" ".\ARMV4T WCE_PLATFORM_STANDARDSDK 400\"
del /q ".\ARMV4T\*.*"
rmdir ".\ARMV4T"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP192C.bat"

A subdirectory or file .\ARMV4T WCE_PLATFORM_STANDARDSDK 400 already exists.
.\ARMV4T\S309PictureBox.exp
.\ARMV4T\S309PictureBox.lib
.\ARMV4T\S309PictureBox.ocx
.\ARMV4T\S309PictureBox.tlb
4 File(s) copied



<h3>Results</h3>
S309PictureBox.ocx - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
