<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: S309UserNotification - Win32 (WCE MIPS) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Mips/S309UserNotification.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309UserNotification.res" /i "Mips" /d "MIPS" /d "_MIPS_" /d UNDER_CE=211 /d _WIN32_WCE=211 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3BD.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationPpg.cpp"
]
Creating command line "clmips.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3BD.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3BE.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\StdAfx.cpp"
]
Creating command line "clmips.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3BE.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3BF.tmp" with contents
[
/nologo /dll /incremental:no /pdb:"Mips/S309UserNotification.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /def:".\S309UserNotification.def" /out:"Mips/S309UserNotification.ocx" /implib:"Mips/S309UserNotification.lib" /machine:MIPS /subsystem:windowsce,2.11 
.\Intermediate\S309UserNotification.obj
.\Intermediate\S309UserNotificationCtl.obj
.\Intermediate\S309UserNotificationPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309UserNotification.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3BF.tmp"
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
S309UserNotification.cpp
S309UserNotificationCtl.cpp
S309UserNotificationPpg.cpp
Generating Code...
Linking...
   Creating library Mips/S309UserNotification.lib and object Mips/S309UserNotification.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C6.bat" with contents
[
@echo off
mkdir  ".\Mips WIN32_PLATFORM_HPCPRO 211"
del /q ".\Mips WIN32_PLATFORM_HPCPRO 211\*.*"
xcopy ".\Mips\*.*" ".\Mips WIN32_PLATFORM_HPCPRO 211\"
del /q ".\Mips\*.*"
del /q ".\Mips\*.*"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C6.bat"

.\Mips\S309UserNotification.exp
.\Mips\S309UserNotification.lib
.\Mips\S309UserNotification.ocx
.\Mips\S309UserNotification.tlb
4 File(s) copied




<h3>Results</h3>
S309UserNotification.ocx - 0 error(s), 0 warning(s)
<h3>
--------------------Configuration: S309UserNotification - Win32 (WCE x86em) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Emu/S309UserNotification.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309UserNotification.res" /i "Emu" /d UNDER_CE=211 /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=211 /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL" "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C7.tmp" with contents
[
/nologo /W3 /O2 /D UNDER_CE=211 /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=211 /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_X86_" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /Fp"Intermediate/S309UserNotification.pch" /Yu"stdafx.h" /Fo"Intermediate/" /Gz /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationPpg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C7.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C8.tmp" with contents
[
/nologo /W3 /O2 /D UNDER_CE=211 /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=211 /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_X86_" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /Fp"Intermediate/S309UserNotification.pch" /Yc"stdafx.h" /Fo"Intermediate/" /Gz /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C8.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C9.tmp" with contents
[
/nologo /subsystem:windows /dll /incremental:no /pdb:"Emu/S309UserNotification.pdb" /nodefaultlib:libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib /def:".\S309UserNotification.def" /out:"Emu/S309UserNotification.ocx" /implib:"Emu/S309UserNotification.lib" /machine:I386 /windowsce:emulation 
.\Intermediate\S309UserNotification.obj
.\Intermediate\S309UserNotificationCtl.obj
.\Intermediate\S309UserNotificationPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309UserNotification.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3C9.tmp"
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
S309UserNotification.cpp
S309UserNotificationCtl.cpp
S309UserNotificationPpg.cpp
Generating Code...
Linking...
   Creating library Emu/S309UserNotification.lib and object Emu/S309UserNotification.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D2.bat" with contents
[
@echo off
mkdir  ".\Emu WIN32_PLATFORM_HPCPRO 211"
del /q ".\Emu WIN32_PLATFORM_HPCPRO 211\*.*"
xcopy ".\Emu\*.*" ".\Emu WIN32_PLATFORM_HPCPRO 211\"
del /q ".\Emu\*.*"
del /q ".\Emu\*.*"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D2.bat"

.\Emu\S309UserNotification.exp
.\Emu\S309UserNotification.lib
.\Emu\S309UserNotification.ocx
.\Emu\S309UserNotification.tlb
4 File(s) copied



<h3>Results</h3>
S309UserNotification.ocx - 0 error(s), 0 warning(s)
<h3>
--------------------Configuration: S309UserNotification - Win32 (WCE SH3) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Sh3/S309UserNotification.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309UserNotification.res" /i "Sh3" /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=211 /d _WIN32_WCE=211 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D3.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationPpg.cpp"
]
Creating command line "shcl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D3.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D4.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\StdAfx.cpp"
]
Creating command line "shcl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D4.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D5.tmp" with contents
[
/nologo /dll /incremental:no /pdb:"Sh3/S309UserNotification.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /def:".\S309UserNotification.def" /out:"Sh3/S309UserNotification.ocx" /implib:"Sh3/S309UserNotification.lib" /machine:SH3 /subsystem:windowsce,2.11 
.\Intermediate\S309UserNotification.obj
.\Intermediate\S309UserNotificationCtl.obj
.\Intermediate\S309UserNotificationPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309UserNotification.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3D5.tmp"
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
S309UserNotification.cpp
S309UserNotificationCtl.cpp
S309UserNotificationPpg.cpp
Generating Code...
Linking...
   Creating library Sh3/S309UserNotification.lib and object Sh3/S309UserNotification.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DC.bat" with contents
[
@echo off
mkdir  ".\Sh3 WIN32_PLATFORM_HPCPRO 211"
del /q ".\Sh3 WIN32_PLATFORM_HPCPRO 211\*.*"
xcopy ".\Sh3\*.*" ".\Sh3 WIN32_PLATFORM_HPCPRO 211\"
del /q ".\Sh3\*.*"
del /q ".\Sh3\*.*"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DC.bat"

.\Sh3\S309UserNotification.exp
.\Sh3\S309UserNotification.lib
.\Sh3\S309UserNotification.ocx
.\Sh3\S309UserNotification.tlb
4 File(s) copied




<h3>Results</h3>
S309UserNotification.ocx - 0 error(s), 0 warning(s)
<h3>
--------------------Configuration: S309UserNotification - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Arm/S309UserNotification.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309UserNotification.res" /i "Arm" /d "ARM" /d "_ARM_" /d UNDER_CE=211 /d _WIN32_WCE=211 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DD.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yu"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationPpg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DD.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DE.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yc"stdafx.h" /Fo"Intermediate/" /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DE.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DF.tmp" with contents
[
/nologo /dll /incremental:no /pdb:"Arm/S309UserNotification.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /def:".\S309UserNotification.def" /out:"Arm/S309UserNotification.ocx" /implib:"Arm/S309UserNotification.lib" /machine:ARM /subsystem:windowsce,2.11 
.\Intermediate\S309UserNotification.obj
.\Intermediate\S309UserNotificationCtl.obj
.\Intermediate\S309UserNotificationPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309UserNotification.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3DF.tmp"
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
S309UserNotification.cpp
S309UserNotificationCtl.cpp
S309UserNotificationPpg.cpp
Generating Code...
Linking...
   Creating library Arm/S309UserNotification.lib and object Arm/S309UserNotification.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3E8.bat" with contents
[
@echo off
mkdir  ".\Arm WIN32_PLATFORM_HPCPRO 211"
del /q ".\Arm WIN32_PLATFORM_HPCPRO 211\*.*"
xcopy ".\Arm\*.*" ".\Arm WIN32_PLATFORM_HPCPRO 211\"
del /q ".\Arm\*.*"
del /q ".\Arm\*.*"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3E8.bat"

.\Arm\S309UserNotification.exp
.\Arm\S309UserNotification.lib
.\Arm\S309UserNotification.ocx
.\Arm\S309UserNotification.tlb
4 File(s) copied




<h3>Results</h3>
S309UserNotification.ocx - 0 error(s), 0 warning(s)
<h3>
--------------------Configuration: S309UserNotification - Win32 (WCE SH4) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "Sh4/S309UserNotification.tlb" /mktyplib203 /o "NUL" /win32 "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.odl""
Creating command line "rc.exe /l 0x409 /fo"Intermediate/S309UserNotification.res" /i "Sh4" /d "SHx" /d "SH4" /d "_SH4_" /d UNDER_CE=211 /d _WIN32_WCE=211 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.rc"" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3E9.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yu"stdafx.h" /Fo"Intermediate/" /Qsh4 /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotification.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationCtl.cpp"
"C:\Source\WindowsCE\ActiveX\S309UserNotification\S309UserNotificationPpg.cpp"
]
Creating command line "shcl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3E9.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3EA.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /Fp"Intermediate/S309UserNotification.pch" /Yc"stdafx.h" /Fo"Intermediate/" /Qsh4 /MC /c 
"C:\Source\WindowsCE\ActiveX\S309UserNotification\StdAfx.cpp"
]
Creating command line "shcl.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3EA.tmp" 
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3EB.tmp" with contents
[
/nologo /dll /incremental:no /pdb:"Sh4/S309UserNotification.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /def:".\S309UserNotification.def" /out:"Sh4/S309UserNotification.ocx" /implib:"Sh4/S309UserNotification.lib" /machine:SH4 /subsystem:windowsce,2.11 
.\Intermediate\S309UserNotification.obj
.\Intermediate\S309UserNotificationCtl.obj
.\Intermediate\S309UserNotificationPpg.obj
.\Intermediate\StdAfx.obj
.\Intermediate\S309UserNotification.res
]
Creating command line "link.exe @C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3EB.tmp"
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
S309UserNotification.cpp
S309UserNotificationCtl.cpp
S309UserNotificationPpg.cpp
Generating Code...
Linking...
   Creating library Sh4/S309UserNotification.lib and object Sh4/S309UserNotification.exp
Creating temporary file "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3F2.bat" with contents
[
@echo off
mkdir  ".\Sh4 WIN32_PLATFORM_HPCPRO 211"
del /q ".\Sh4 WIN32_PLATFORM_HPCPRO 211\*.*"
xcopy ".\Sh4\*.*" ".\Sh4 WIN32_PLATFORM_HPCPRO 211\"
del /q ".\Sh4\*.*"
del /q ".\Sh4\*.*"
del /q ".\Intermediate\*.*"
]
Creating command line "C:\DOCUME~1\tmyhrer\LOCALS~1\Temp\RSP3F2.bat"

.\Sh4\S309UserNotification.exp
.\Sh4\S309UserNotification.lib
.\Sh4\S309UserNotification.ocx
.\Sh4\S309UserNotification.tlb
4 File(s) copied




<h3>Results</h3>
S309UserNotification.ocx - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
