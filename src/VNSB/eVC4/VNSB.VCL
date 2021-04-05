<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: VNSB - Win32 (WCE MIPSII) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"MIPSIIRel/VNSB.res" /i "\NSBCE6\VNSB\Source" /d UNDER_CE=400 /d _WIN32_WCE=400 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WCE_PLATFORM_STANDARDSDK" /d "MIPS" /d "_MIPS_" /d "R4000" /d "MIPSII" /d "_AFXDLL" /r "E:\NSBCE6\VNSB\Source\VNSB.rc"" 
Creating temporary file "C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP539.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "MIPS" /D "_MIPS_" /D "R4000" /D "MIPSII" /D UNDER_CE=400 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_AFXDLL" /Fo"MIPSIIRel/" /O2 /MC /c 
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
Creating command line "clmips.exe @C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP539.tmp" 
Creating temporary file "C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP53A.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:no /pdb:"MIPSIIRel/VNSB.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"MIPSIIRel/VNSB.exe" /subsystem:windowsce,4.00 /align:"4096" 
.\MIPSIIRel\CodeDlg.obj
.\MIPSIIRel\ComObjectDlg.obj
.\MIPSIIRel\MainFrm.obj
.\MIPSIIRel\MenuEditorDlg.obj
.\MIPSIIRel\NSBForm.obj
.\MIPSIIRel\NSBFormObjectView.obj
.\MIPSIIRel\PropEditorDlg.obj
.\MIPSIIRel\SelectObjectDlg.obj
.\MIPSIIRel\StdAfx.obj
.\MIPSIIRel\VNSB.obj
.\MIPSIIRel\VNSBDlg.obj
.\MIPSIIRel\VNSBDoc.obj
.\MIPSIIRel\VNSBView.obj
.\MIPSIIRel\VNSB.res
]
Creating command line "link.exe @C:\DOCUME~1\ADMINI~1.BIG\LOCALS~1\Temp\RSP53A.tmp"
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
e:\nsbce6\vnsb\source\vnsbdoc.cpp(463) : warning C4101: 'dwChecksumSeed' : unreferenced local variable
VNSBView.cpp
Generating Code...
Linking...





<h3>Results</h3>
VNSB.exe - 0 error(s), 1 warning(s)
</pre>
</body>
</html>
