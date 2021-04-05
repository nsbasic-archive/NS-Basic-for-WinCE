<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: EVC3 - Win32 (WCE ARM) PPC2002_Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "NDEBUG" /tlb "output/ComCtl.tlb" /o "NUL" /win32 "E:\NSBCE7\Controls\NSBControls\src\ComCtl.idl""
Creating command line "rc.exe /l 0x409 /fo"output/ComCtl.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "ARM" /d "_ARM_" /r "E:\NSBCE7\Controls\NSBControls\src\ComCtl.rc"" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPAC8.tmp" with contents
[
/nologo /W3 /I "..\Include" /D "_USRDLL" /D "WIN32_PLATFORM_PSPC=310" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fo"output/" /Oxs /MC /c 
"E:\NSBCE7\Controls\NSBControls\src\ComCtl.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSBImageList.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSBListImage.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSColumnHeader.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSColumnHeaders.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSColumnItems.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSComCtlColl.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSFont.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSListItem.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSListItems.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSListSubItem.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSListSubItems.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSListView.cpp"
"E:\NSBCE7\Controls\NSBControls\src\NSListViewEvent.cpp"
"E:\NSBCE7\Controls\NSBControls\src\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPAC8.tmp" 
Creating temporary file "C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPAC9.tmp" with contents
[
/nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"output/NSBControls.pdb" /def:".\ComCtl.def" /out:"output/NSBControls.dll" /implib:"output/NSBControls.lib" /subsystem:windowsce,3.00 /align:"4096" /MACHINE:ARM 
.\output\ComCtl.obj
.\output\NSBImageList.obj
.\output\NSBListImage.obj
.\output\NSColumnHeader.obj
.\output\NSColumnHeaders.obj
.\output\NSColumnItems.obj
.\output\NSComCtlColl.obj
.\output\NSFont.obj
.\output\NSListItem.obj
.\output\NSListItems.obj
.\output\NSListSubItem.obj
.\output\NSListSubItems.obj
.\output\NSListView.obj
.\output\NSListViewEvent.obj
.\output\StdAfx.obj
.\output\ComCtl.res
]
Creating command line "link.exe @C:\DOCUME~1\GEORGE~1\LOCALS~1\Temp\RSPAC9.tmp"
<h3>Output Window</h3>
Creating Type Library...
ComCtl.idl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
ocidl.idl
oleidl.idl
Compiling resources...
Compiling...
ComCtl.cpp
NSBImageList.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSBListImage.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSColumnHeader.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSColumnHeaders.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSColumnItems.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSComCtlColl.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSFont.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSListItem.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSListItems.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSListSubItem.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSListSubItems.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSListView.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
NSListViewEvent.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
StdAfx.cpp
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Generating Code...
Including osspecific helpers byte order,string lengths, etc. (osspecific.h) - link with: osspecific.cpp
Defining default machine byte order little endian - COMMON_SYSTEM_BYTEORDER[_XXXX] (osspecific.h)
Mapping the stand alone os specific routines to the default names (may conflict with Jacked-Objects) - !CC_BYTEORDER_NOSTDPROCNAMES (osspecific.h)
Inline string conversion enabled - COMMON_STRCONV_INLINE_UTILS (osspecific.h)
Including basic automation helpers DISPCALLER etc. (automationhlp.h) - link with: automationhlp.cpp
Including automation types packing classes ccVariant,ccBSTR,ccEXCEPINFO (automationhlp-typepackers.h)
Linking...
.\ComCtl.def : warning LNK4222: exported symbol "DllCanUnloadNow" should not be assigned an ordinal
.\ComCtl.def : warning LNK4222: exported symbol "DllGetClassObject" should not be assigned an ordinal
.\ComCtl.def : warning LNK4222: exported symbol "DllRegisterServer" should not be assigned an ordinal
.\ComCtl.def : warning LNK4222: exported symbol "DllUnregisterServer" should not be assigned an ordinal
   Creating library output/NSBControls.lib and object output/NSBControls.exp
NSBControls.exp : warning LNK4070: /OUT:ComCtl.DLL directive in .EXP differs from output filename "output/NSBControls.dll"; ignoring directive




<h3>Results</h3>
NSBControls.dll - 0 error(s), 5 warning(s)
</pre>
</body>
</html>
