<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: VNSB - Win32 (WCE MIPS) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"WMIPSRel/VNSB.res" /i "\NSBCE6\VNSB\Source" /d "MIPS" /d "_MIPS_" /d UNDER_CE=211 /d _WIN32_WCE=211 /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" /r "E:\NSBCE6\VNSB\Source\VNSB.rc"" 
Creating temporary file "C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP527.tmp" with contents
[
/nologo /W3 /O2 /D _WIN32_WCE=211 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=211 /D "UNICODE" /D "_AFXDLL" /D "WIN32_PLATFORM_HPCPRO" /D "_UNICODE" /FR"WMIPSRel/" /Fo"WMIPSRel/" /MC /c 
"E:\NSBCE6\VNSB\Source\CodeDlg.cpp"
"E:\NSBCE6\VNSB\Source\ComObjectDlg.cpp"
"E:\NSBCE6\VNSB\Source\MainFrm.cpp"
"E:\NSBCE6\VNSB\Source\MenuEditorDlg.cpp"
"E:\NSBCE6\VNSB\Source\NSBForm.cpp"
"E:\NSBCE6\VNSB\Source\NSBFormObjectView.cpp"
"E:\NSBCE6\VNSB\Source\PropEditorDlg.cpp"
"E:\NSBCE6\VNSB\Source\SelectObjectDlg.cpp"
"E:\NSBCE6\VNSB\Source\StdAfx.cpp"
"E:\NSBCE6\VNSB\Source\VNSB.cpp"
"E:\NSBCE6\VNSB\Source\VNSBDlg.cpp"
"E:\NSBCE6\VNSB\Source\VNSBDoc.cpp"
"E:\NSBCE6\VNSB\Source\VNSBView.cpp"
]
Creating command line "clmips.exe @C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP527.tmp" 
Creating temporary file "C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP528.tmp" with contents
[
/nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:no /pdb:"WMIPSRel/VNSB.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /out:"WMIPSRel/VNSB.exe" /machine:MIPS /subsystem:windowsce,2.11 
.\WMIPSRel\CodeDlg.obj
.\WMIPSRel\ComObjectDlg.obj
.\WMIPSRel\MainFrm.obj
.\WMIPSRel\MenuEditorDlg.obj
.\WMIPSRel\NSBForm.obj
.\WMIPSRel\NSBFormObjectView.obj
.\WMIPSRel\PropEditorDlg.obj
.\WMIPSRel\SelectObjectDlg.obj
.\WMIPSRel\StdAfx.obj
.\WMIPSRel\VNSB.obj
.\WMIPSRel\VNSBDlg.obj
.\WMIPSRel\VNSBDoc.obj
.\WMIPSRel\VNSBView.obj
.\WMIPSRel\VNSB.res
]
Creating command line "link.exe @C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP528.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
CodeDlg.cpp
ComObjectDlg.cpp
MainFrm.cpp
MenuEditorDlg.cpp
NSBForm.cpp
NSBFormObjectView.cpp
PropEditorDlg.cpp
SelectObjectDlg.cpp
StdAfx.cpp
VNSB.cpp
VNSBDlg.cpp
VNSBDoc.cpp
E:\NSBCE6\VNSB\Source\VNSBDoc.cpp(463) : warning C4101: 'dwChecksumSeed' : unreferenced local variable
VNSBView.cpp
Generating Code...
Linking...




<h3>Results</h3>
VNSB.exe - 0 error(s), 1 warning(s)
</pre>
</body>
</html>
