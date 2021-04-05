# Microsoft Developer Studio Project File - Name="NSCEPictureBox" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=NSCEPictureBox - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "NSCEPictureBox.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NSCEPictureBox.mak" CFG="NSCEPictureBox - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NSCEPictureBox - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NSCEPictureBox - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NSCEPictureBox - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NSCEPictureBox - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NSCEPictureBox - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 version.lib wininet.lib Msimg32.lib /nologo /subsystem:windows /dll /machine:I386
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Release
TargetPath=.\Release\NSCEPictureBox.ocx
InputPath=.\Release\NSCEPictureBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "NSCEPictureBox - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 version.lib wininet.lib Msimg32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Debug
TargetPath=.\Debug\NSCEPictureBox.ocx
InputPath=.\Debug\NSCEPictureBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "NSCEPictureBox - Win32 Unicode Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DebugU
TargetPath=.\DebugU\NSCEPictureBox.ocx
InputPath=.\DebugU\NSCEPictureBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "NSCEPictureBox - Win32 Unicode Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU"
# PROP BASE Intermediate_Dir "ReleaseU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU"
# PROP Intermediate_Dir "ReleaseU"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\NSCEPictureBox.ocx
InputPath=.\ReleaseU\NSCEPictureBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "NSCEPictureBox - Win32 Release"
# Name "NSCEPictureBox - Win32 Debug"
# Name "NSCEPictureBox - Win32 Unicode Debug"
# Name "NSCEPictureBox - Win32 Unicode Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\file_ver.cpp
# End Source File
# Begin Source File

SOURCE=..\src\NSCEBitmap.cpp
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBox.cpp
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBox.def
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBox.odl
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBox.rc
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBoxCtl.cpp
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBoxPpg.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Res.cpp
# End Source File
# Begin Source File

SOURCE=..\src\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=..\src\UrlImage.cpp
# End Source File
# Begin Source File

SOURCE=..\src\UrlImageData.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\src\file_ver.h
# End Source File
# Begin Source File

SOURCE=..\src\file_ver.inl
# End Source File
# Begin Source File

SOURCE=..\src\imgdecmp.h
# End Source File
# Begin Source File

SOURCE=..\src\imgrendr.h
# End Source File
# Begin Source File

SOURCE=..\src\NSCEBitmap.h
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBox.h
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBoxCtl.h
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBoxPpg.h
# End Source File
# Begin Source File

SOURCE=..\src\pegcards.h
# End Source File
# Begin Source File

SOURCE=..\src\res.h
# End Source File
# Begin Source File

SOURCE=..\src\resource.h
# End Source File
# Begin Source File

SOURCE=..\src\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\src\UrlImage.h
# End Source File
# Begin Source File

SOURCE=..\src\UrlImageData.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\src\BlankCard.bmp
# End Source File
# Begin Source File

SOURCE=..\src\BlankCardHPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\BlankCardPocketPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\BlankCardPPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\BlankFaceCard.bmp
# End Source File
# Begin Source File

SOURCE=..\src\BlankFaceCardHPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\card61.bmp
# End Source File
# Begin Source File

SOURCE=..\src\card61a.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Joker.bmp
# End Source File
# Begin Source File

SOURCE=..\src\JokerHPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\JokerPocketPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\JokerPPC.bmp
# End Source File
# Begin Source File

SOURCE=.\NSCEPictureBox.ico
# End Source File
# Begin Source File

SOURCE=..\rsc\NSCEPictureBox.ico
# End Source File
# Begin Source File

SOURCE=.\NSCEPictureBoxCtl.bmp
# End Source File
# Begin Source File

SOURCE=..\rsc\NSCEPictureBoxCtl.bmp
# End Source File
# Begin Source File

SOURCE=..\src\NSCEPictureBoxCtl.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit1.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit1HPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit1PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit1PPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit2.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit2HPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit2PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit2PPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit3.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit3HPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit3PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit3PPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit4.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Suit4HPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit4PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\suit4PPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Wild0.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Wild1.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Wild2.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Wild2HPC.bmp
# End Source File
# Begin Source File

SOURCE=..\src\Wild2PPC.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=..\src\bmps.zip
# End Source File
# End Target
# End Project
