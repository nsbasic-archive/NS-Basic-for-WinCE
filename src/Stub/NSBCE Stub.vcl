<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: NSBCE Stub - Win32 (WCE ARMV4I) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMV4IRel/NSBCE Stub.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WCE_PLATFORM_COMMONCEDEV420" /d "THUMB" /d "_THUMB_" /d "ARM" /d "_ARM_" /d "ARMV4I" /r "E:\NSBCE8\Stub\NSBCE Stub.rc"" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP103.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=420 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_COMMONCEDEV420" /D "ARMV4I" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /FR"ARMV4IRel/" /Fo"ARMV4IRel/" /O2 /MC /c 
"E:\NSBCE8\Stub\NSBCE Stub.cpp"
"E:\NSBCE8\Stub\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP103.tmp" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP104.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:"ARMV4IRel/NSBCE Stub.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IRel/NSBCE Stub.exe" /subsystem:windowsce,4.20 /align:"4096" 
".\ARMV4IRel\NSBCE Stub.obj"
.\ARMV4IRel\StdAfx.obj
".\ARMV4IRel\NSBCE Stub.res"
]
Creating command line "link.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSP104.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
NSBCE Stub.cpp
StdAfx.cpp
Generating Code...
Linking...
Creating command line "bscmake.exe /nologo /o"ARMV4IRel/NSBCE Stub.bsc"  ".\ARMV4IRel\NSBCE Stub.sbr" .\ARMV4IRel\StdAfx.sbr"
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
NSBCE Stub.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
