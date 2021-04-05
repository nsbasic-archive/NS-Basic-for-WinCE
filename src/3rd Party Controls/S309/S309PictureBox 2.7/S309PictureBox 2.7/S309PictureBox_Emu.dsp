# Microsoft Developer Studio Project File - Name="S309PictureBox" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86em) Dynamic-Link Library" 0x7f02

CFG=S309PictureBox - Win32 (WCE x86em) Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "S309PictureBox_Emu.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "S309PictureBox_Emu.mak" CFG="S309PictureBox - Win32 (WCE x86em) Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "S309PictureBox - Win32 (WCE x86em) Release" (based on "Win32 (WCE x86em) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "H/PC Ver. 2.00"
# PROP WCE_FormatVersion "6.0"
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "x86emRel"
# PROP BASE Intermediate_Dir "x86emRel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Emu"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD BASE RSC /l 0x409 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /windowsce:emulation
# ADD LINK32 imgdecmp.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /out:"Emu/S309PictureBox.ocx" /windowsce:emulation
# Begin Special Build Tool
OutDir=.\Emu
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"
# End Special Build Tool
# Begin Target

# Name "S309PictureBox - Win32 (WCE x86em) Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\S309PictureBox.cpp
DEP_CPP_S309P=\
	".\S309PictureBox.h"\
	".\StdAfx.h"\
	
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
DEP_CPP_S309PI=\
	".\imgdecmp.h"\
	".\imgrendr.h"\
	".\pegcards.h"\
	".\S309PictureBox.h"\
	".\S309PictureBoxCtl.h"\
	".\S309PictureBoxPpg.h"\
	".\StdAfx.h"\
	
# End Source File
# Begin Source File

SOURCE=.\S309PictureBoxPpg.cpp
DEP_CPP_S309PIC=\
	".\S309PictureBox.h"\
	".\S309PictureBoxPpg.h"\
	".\StdAfx.h"\
	
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
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
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\BlankCard.bmp
# End Source File
# Begin Source File

SOURCE=.\BlankFaceCard.bmp
# End Source File
# Begin Source File

SOURCE=.\Joker.bmp
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

SOURCE=.\Suit2.bmp
# End Source File
# Begin Source File

SOURCE=.\Suit3.bmp
# End Source File
# Begin Source File

SOURCE=.\Suit4.bmp
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
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
