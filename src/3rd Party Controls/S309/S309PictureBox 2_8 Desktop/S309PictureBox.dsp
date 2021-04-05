# Microsoft Developer Studio Project File - Name="S309PictureBox" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=S309PictureBox - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "S309PictureBox.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "S309PictureBox.mak" CFG="S309PictureBox - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "S309PictureBox - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "S309PictureBox - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "S309PictureBox - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "S309PictureBox - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "Desktop"
# PROP WCE_FormatVersion "6.0"
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "S309PictureBox - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Desktop"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 version.lib wininet.lib Msimg32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"Desktop/S309PictureBox208.ocx"
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Desktop
TargetPath=.\Desktop\S309PictureBox208.ocx
InputPath=.\Desktop\S309PictureBox208.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /u /s /c "$(TargetPath)" 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "S309PictureBox - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DesktopDebug"
# PROP Intermediate_Dir "DesktopDebug"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 version.lib wininet.lib Msimg32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"DesktopDebug/S309PictureBox208.ocx" /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DesktopDebug
TargetPath=.\DesktopDebug\S309PictureBox208.ocx
InputPath=.\DesktopDebug\S309PictureBox208.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /u /s /c "$(TargetPath)" 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "S309PictureBox - Win32 Unicode Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DesktopDebugU"
# PROP Intermediate_Dir "DesktopDebugU"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 version.lib wininet.lib Msimg32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"DesktopDebugU/S309PictureBox208.ocx" /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DesktopDebugU
TargetPath=.\DesktopDebugU\S309PictureBox208.ocx
InputPath=.\DesktopDebugU\S309PictureBox208.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /u /s /c "$(TargetPath)" 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "S309PictureBox - Win32 Unicode Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU"
# PROP BASE Intermediate_Dir "ReleaseU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "DesktopU"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 version.lib wininet.lib Msimg32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"DesktopU/S309PictureBox208.ocx"
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DesktopU
TargetPath=.\DesktopU\S309PictureBox208.ocx
InputPath=.\DesktopU\S309PictureBox208.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /u /s /c "$(TargetPath)" 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "S309PictureBox - Win32 Release"
# Name "S309PictureBox - Win32 Debug"
# Name "S309PictureBox - Win32 Unicode Debug"
# Name "S309PictureBox - Win32 Unicode Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\file_ver.cpp
# End Source File
# Begin Source File

SOURCE=.\S309Bitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\S309PictureBox.cpp
# End Source File
# Begin Source File

SOURCE=.\S309PictureBox.def
# End Source File
# Begin Source File

SOURCE=.\S309PictureBox.odl
# End Source File
# Begin Source File

SOURCE=.\S309PictureBox.rc
# End Source File
# Begin Source File

SOURCE=.\S309PictureBoxCtl.cpp
# End Source File
# Begin Source File

SOURCE=.\S309PictureBoxPpg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UrlImage.cpp
# End Source File
# Begin Source File

SOURCE=.\UrlImageData.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\file_ver.h
# End Source File
# Begin Source File

SOURCE=.\file_ver.inl
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\S309Bitmap.h
# End Source File
# Begin Source File

SOURCE=.\S309PictureBox.h
# End Source File
# Begin Source File

SOURCE=.\S309PictureBoxCtl.h
# End Source File
# Begin Source File

SOURCE=.\S309PictureBoxPpg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UrlImage.h
# End Source File
# Begin Source File

SOURCE=.\UrlImageData.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\BlankCard.bmp
# End Source File
# Begin Source File

SOURCE=.\BlankCardPocketPC.bmp
# End Source File
# Begin Source File

SOURCE=.\BlankFaceCard.bmp
# End Source File
# Begin Source File

SOURCE=.\Joker.bmp
# End Source File
# Begin Source File

SOURCE=.\JokerPocketPC.bmp
# End Source File
# Begin Source File

SOURCE=.\S309PictureBox.ico
# End Source File
# Begin Source File

SOURCE=.\S309PictureBoxCtl.bmp
# End Source File
# Begin Source File

SOURCE=.\Suit1.bmp
# End Source File
# Begin Source File

SOURCE=.\suit1PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=.\Suit2.bmp
# End Source File
# Begin Source File

SOURCE=.\suit2PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=.\Suit3.bmp
# End Source File
# Begin Source File

SOURCE=.\suit3PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=.\Suit4.bmp
# End Source File
# Begin Source File

SOURCE=.\suit4PocketPC.bmp
# End Source File
# Begin Source File

SOURCE=.\Wild0.bmp
# End Source File
# Begin Source File

SOURCE=.\Wild1.bmp
# End Source File
# Begin Source File

SOURCE=.\Wild2.bmp
# End Source File
# Begin Source File

SOURCE=.\Wild2PPC.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
