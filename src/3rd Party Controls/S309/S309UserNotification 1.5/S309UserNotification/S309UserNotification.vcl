<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309UserNotification - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Arm/S309UserNotification.tlb" /mktyplib203 /o "NUL" /win32 "W:\ActiveX\S309UserNotification\S309UserNotification.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309UserNotification.res" /i "Arm" /d "ARM" /d "_ARM_" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "W:\ActiveX\S309UserNotification\S309UserNotification.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP179.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"W:\ActiveX\S309UserNotification\Res.cpp"
"W:\ActiveX\S309UserNotification\S309Alert.cpp"
"W:\ActiveX\S309UserNotification\S309Alerts.cpp"
"W:\ActiveX\S309UserNotification\S309Icon.cpp"
"W:\ActiveX\S309UserNotification\S309UserNotification.cpp"
"W:\ActiveX\S309UserNotification\S309UserNotificationCtl.cpp"
"W:\ActiveX\S309UserNotification\S309UserNotificationPpg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP179.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP17A.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=300 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_PSPC=310" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"W:\ActiveX\S309UserNotification\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP17A.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP17B.tmp" with contents
[
/nologo /dll /incremental:no /pdb:"Arm/S309UserNotification105.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /def:".\S309UserNotification.def" /out:"Arm/S309UserNotification105.ocx" /implib:"Arm/S309UserNotification105.lib" /machine:ARM /subsystem:windowsce,3.00 
.\Intermediate\Res.obj
.\Intermediate\S309Alert.obj
.\Intermediate\S309Alerts.obj
.\Intermediate\S309Icon.obj
.\Intermediate\S309UserNotification.obj
.\Intermediate\S309UserNotificationCtl.obj
.\Intermediate\S309UserNotificationPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309UserNotification.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP17B.tmp"
<h3>Output Window</h3>
Creating Type Library...
S309UserNotification.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
Res.cpp
S309Alert.cpp
S309Alerts.cpp
S309Icon.cpp
S309UserNotification.cpp
S309UserNotificationCtl.cpp
S309UserNotificationPpg.cpp
Generating Code...
Linking...
   Creating library Arm/S309UserNotification105.lib and object Arm/S309UserNotification105.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP186.bat" with contents
[
@echo off
mkdir  ".\Arm WIN32_PLATFORM_PSPC=310 300"
del /q ".\Arm WIN32_PLATFORM_PSPC=310 300\*.*"
xcopy ".\Arm\*.*" ".\Arm WIN32_PLATFORM_PSPC=310 300\"
del /q ".\Arm\*.*"
rmdir ".\Arm"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP186.bat"

A subdirectory or file .\Arm WIN32_PLATFORM_PSPC=310 300 already exists.
.\Arm\S309UserNotification.tlb
.\Arm\S309UserNotification105.exp
.\Arm\S309UserNotification105.lib
.\Arm\S309UserNotification105.ocx
4 File(s) copied




<h3>Results</h3>
S309UserNotification105.ocx - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
