# Microsoft Developer Studio Project File - Name="S309HotKey" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86em) Dynamic-Link Library" 0x7f02
# TARGTYPE "Win32 (WCE SH3) Dynamic-Link Library" 0x8102
# TARGTYPE "Win32 (WCE PPC) Dynamic-Link Library" 0x8402
# TARGTYPE "Win32 (WCE x86) Dynamic-Link Library" 0x8302
# TARGTYPE "Win32 (WCE MIPSFP) Dynamic-Link Library" 0x8702
# TARGTYPE "Win32 (WCE ARM) Dynamic-Link Library" 0x8502
# TARGTYPE "Win32 (WCE SH4) Dynamic-Link Library" 0x8602
# TARGTYPE "Win32 (WCE MIPS) Dynamic-Link Library" 0x8202

CFG=S309HotKey - Win32 (WCE MIPS) Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "S309HotKey.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "S309HotKey.mak" CFG="S309HotKey - Win32 (WCE MIPS) Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "S309HotKey - Win32 (WCE MIPS) Release" (based on "Win32 (WCE MIPS) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE SH4) Release" (based on "Win32 (WCE SH4) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE SH3) Release" (based on "Win32 (WCE SH3) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE ARM) Release" (based on "Win32 (WCE ARM) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE MIPSFP) Release" (based on "Win32 (WCE MIPSFP) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE x86) Release" (based on "Win32 (WCE x86) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE PPC) Release" (based on "Win32 (WCE PPC) Dynamic-Link Library")
!MESSAGE "S309HotKey - Win32 (WCE x86em) Release" (based on "Win32 (WCE x86em) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "Palm-size PC 2.11"
# PROP WCE_FormatVersion "6.0"

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRel"
# PROP BASE Intermediate_Dir "WMIPSRel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Mips"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=clmips.exe
RSC=rc.exe
MTL=midl.exe
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
# ADD LINK32 /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /out:"Emu/S309HotKey.ocx" /windowsce:emulation
# Begin Special Build Tool
OutDir=.\Emu
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH4Rel"
# PROP BASE Intermediate_Dir "WCESH4Rel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Sh4"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /Qsh4 /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /Qsh4 /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "SHx" /d "SH4" /d "_SH4_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "SHx" /d "SH4" /d "_SH4_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:SH4 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /dll /machine:SH4 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\Sh4
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH3Rel"
# PROP BASE Intermediate_Dir "WCESH3Rel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Sh3"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /dll /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\Sh3
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEARMRel"
# PROP BASE Intermediate_Dir "WCEARMRel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Arm"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /dll /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\Arm
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSFPRel"
# PROP BASE Intermediate_Dir "WMIPSFPRel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "MipsFp"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /QMFWCE /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /QMFWCE /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /dll /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\MipsFp
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEX86Rel"
# PROP BASE Intermediate_Dir "WCEX86Rel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "X86"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "x86" /D "_i386_" /D "_x86_" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /Yu"stdafx.h" /Gs8192 /GF /c
# ADD CPP /nologo /MT /W3 /O2 /D "x86" /D "_i386_" /D "_x86_" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /Gs8192 /GF /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "x86" /d "_i386_" /d "_x86_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "x86" /d "_i386_" /d "_x86_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /base:"0x00010000" /dll /machine:IX86 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /base:"0x00010000" /dll /machine:IX86 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\X86
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEPPCRel"
# PROP BASE Intermediate_Dir "WCEPPCRel"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "PPC"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=clppc.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "PPC" /D "_PPC_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "PPC" /D "_PPC_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "ppc" /d "_ppc_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "ppc" /d "_ppc_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:PPC /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /dll /machine:PPC /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\PPC
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "S309HotKey___Win32__WCE_x86em__Release"
# PROP BASE Intermediate_Dir "S309HotKey___Win32__WCE_x86em__Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Emu"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CEx86Corelibc) /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib
# Begin Special Build Tool
IntDir=.\Intermediate
OutDir=.\Emu
SOURCE="$(InputPath)"
PostBuild_Cmds=mkdir  "$(OutDir) $(Emulation Platform Name)"	del /q "$(OutDir) $(Emulation Platform Name)\*.*"	xcopy "$(OutDir)\*.*" "$(OutDir) $(Emulation Platform Name)\"	del /q "$(OutDir)\*.*"	rmdir "$(OutDir)"	del /q "$(IntDir)\*.*"
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "S309HotKey - Win32 (WCE MIPS) Release"
# Name "S309HotKey - Win32 (WCE SH4) Release"
# Name "S309HotKey - Win32 (WCE SH3) Release"
# Name "S309HotKey - Win32 (WCE ARM) Release"
# Name "S309HotKey - Win32 (WCE MIPSFP) Release"
# Name "S309HotKey - Win32 (WCE x86) Release"
# Name "S309HotKey - Win32 (WCE PPC) Release"
# Name "S309HotKey - Win32 (WCE x86em) Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\S309HotKey.cpp

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

DEP_CPP_S309H=\
	".\S309HotKey.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\S309HotKey.def
# End Source File
# Begin Source File

SOURCE=.\S309HotKey.odl

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\S309HotKey.rc

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\S309HotKeyCtl.cpp

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

DEP_CPP_S309HO=\
	".\S309HotKey.h"\
	".\S309HotKeyCtl.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\S309HotKeyPpg.cpp

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

DEP_CPP_S309HOT=\
	".\S309HotKey.h"\
	".\S309HotKeyPpg.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH4) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE SH3) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE ARM) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE MIPSFP) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /QMFWCE
# ADD CPP /QMFWCE /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE PPC) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "S309HotKey - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\S309HotKey.h
# End Source File
# Begin Source File

SOURCE=.\S309HotKeyCtl.h
# End Source File
# Begin Source File

SOURCE=.\S309HotKeyPpg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\S309HotKeyCtl.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
