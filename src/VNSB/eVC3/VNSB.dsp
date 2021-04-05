# Microsoft Developer Studio Project File - Name="VNSB" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86) Application" 0x8301
# TARGTYPE "Win32 (WCE ARM) Application" 0x8501
# TARGTYPE "Win32 (WCE PPC) Application" 0x8401
# TARGTYPE "Win32 (WCE x86em) Application" 0x7f01
# TARGTYPE "Win32 (WCE SH3) Application" 0x8101
# TARGTYPE "Win32 (WCE SH4) Application" 0x8601
# TARGTYPE "Win32 (WCE MIPS) Application" 0x8201
# TARGTYPE "Win32 (WCE MIPSFP) Application" 0x8701
# TARGTYPE "Win32 (WCE CEF) Application" 0x8a01

CFG=VNSB - Win32 (WCE MIPS) Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VNSB.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VNSB.mak" CFG="VNSB - Win32 (WCE MIPS) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VNSB - Win32 (WCE MIPS) Release" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "VNSB - Win32 (WCE MIPS) Debug" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "VNSB - Win32 (WCE SH4) Release" (based on "Win32 (WCE SH4) Application")
!MESSAGE "VNSB - Win32 (WCE SH4) Debug" (based on "Win32 (WCE SH4) Application")
!MESSAGE "VNSB - Win32 (WCE SH3) Release" (based on "Win32 (WCE SH3) Application")
!MESSAGE "VNSB - Win32 (WCE SH3) Debug" (based on "Win32 (WCE SH3) Application")
!MESSAGE "VNSB - Win32 (WCE ARM) Release" (based on "Win32 (WCE ARM) Application")
!MESSAGE "VNSB - Win32 (WCE ARM) Debug" (based on "Win32 (WCE ARM) Application")
!MESSAGE "VNSB - Win32 (WCE MIPSFP) Release" (based on "Win32 (WCE MIPSFP) Application")
!MESSAGE "VNSB - Win32 (WCE MIPSFP) Debug" (based on "Win32 (WCE MIPSFP) Application")
!MESSAGE "VNSB - Win32 (WCE x86) Release" (based on "Win32 (WCE x86) Application")
!MESSAGE "VNSB - Win32 (WCE x86) Debug" (based on "Win32 (WCE x86) Application")
!MESSAGE "VNSB - Win32 (WCE x86em) Release" (based on "Win32 (WCE x86em) Application")
!MESSAGE "VNSB - Win32 (WCE x86em) Debug" (based on "Win32 (WCE x86em) Application")
!MESSAGE "VNSB - Win32 (WCE PPC) Release" (based on "Win32 (WCE PPC) Application")
!MESSAGE "VNSB - Win32 (WCE PPC) Debug" (based on "Win32 (WCE PPC) Application")
!MESSAGE "VNSB - Win32 (WCE CEF) Debug" (based on "Win32 (WCE CEF) Application")
!MESSAGE "VNSB - Win32 (WCE CEF) Release" (based on "Win32 (WCE CEF) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "H/PC Pro 2.11"
# PROP WCE_FormatVersion "6.02"

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRel"
# PROP BASE Intermediate_Dir "WMIPSRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSRel"
# PROP Intermediate_Dir "WMIPSRel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /QMRWCE /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WMIPSDbg"
# PROP BASE Intermediate_Dir "WMIPSDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WMIPSDbg"
# PROP Intermediate_Dir "WMIPSDbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrtMTDebug) /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /M$(CECrtMTDebug) /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /QMRWCE /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH4Rel"
# PROP BASE Intermediate_Dir "WCESH4Rel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCESH4Rel"
# PROP Intermediate_Dir "WCESH4Rel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=shcl.exe
# ADD BASE CPP /nologo /Qsh4 /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /Qsh4 /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH4 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH4 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCESH4Dbg"
# PROP BASE Intermediate_Dir "WCESH4Dbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCESH4Dbg"
# PROP Intermediate_Dir "WCESH4Dbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=shcl.exe
# ADD BASE CPP /nologo /Qsh4 /MC /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /Qsh4 /MC /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH4" /D "_SH4_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "SHx" /d "SH4" /d "_SH4_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "SHx" /d "SH4" /d "_SH4_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH4 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH4 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH3Rel"
# PROP BASE Intermediate_Dir "WCESH3Rel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCESH3Rel"
# PROP Intermediate_Dir "WCESH3Rel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCESH3Dbg"
# PROP BASE Intermediate_Dir "WCESH3Dbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCESH3Dbg"
# PROP Intermediate_Dir "WCESH3Dbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrtMTDebug) /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMTDebug) /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH3 /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEARMRel"
# PROP BASE Intermediate_Dir "WCEARMRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCEARMRel"
# PROP Intermediate_Dir "WCEARMRel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCEARMDbg"
# PROP BASE Intermediate_Dir "WCEARMDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCEARMDbg"
# PROP Intermediate_Dir "WCEARMDbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSFPRel"
# PROP BASE Intermediate_Dir "WMIPSFPRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSFPRel"
# PROP Intermediate_Dir "WMIPSFPRel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clmips.exe
# ADD BASE CPP /nologo /QMFWCE /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /QMFWCE /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WMIPSFPDbg"
# PROP BASE Intermediate_Dir "WMIPSFPDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WMIPSFPDbg"
# PROP Intermediate_Dir "WMIPSFPDbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clmips.exe
# ADD BASE CPP /nologo /QMFWCE /MC /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /QMFWCE /MC /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEX86Rel"
# PROP BASE Intermediate_Dir "WCEX86Rel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCEX86Rel"
# PROP Intermediate_Dir "WCEX86Rel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "x86" /D "_i386_" /D "_x86_" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /Yu"stdafx.h" /Gs8192 /GF /c
# ADD CPP /nologo /MT /W3 /O2 /D "x86" /D "_i386_" /D "_x86_" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "NDEBUG" /D "i_386_" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /Gs8192 /GF /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:IX86 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:IX86 /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCEX86Dbg"
# PROP BASE Intermediate_Dir "WCEX86Dbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCEX86Dbg"
# PROP Intermediate_Dir "WCEX86Dbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Zi /Od /D "x86" /D "_i386_" /D "_x86_" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "DEBUG" /D "i_386_" /D "_AFXDLL" /Yu"stdafx.h" /Gs8192 /GF /c
# ADD CPP /nologo /MTd /W3 /Zi /Od /D "x86" /D "_i386_" /D "_x86_" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "DEBUG" /D "i_386_" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /Gs8192 /GF /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "x86" /d "_i386_" /d "_x86_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "x86" /d "_i386_" /d "_x86_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:IX86 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:IX86 /nodefaultlib:"$(CENoDefaultLib)" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "x86emRel"
# PROP BASE Intermediate_Dir "x86emRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "x86emRel"
# PROP Intermediate_Dir "x86emRel"
# PROP Target_Dir ""
EMPFILE=empfile.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
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
# ADD BASE LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /nodefaultlib:"$(CENoDefaultLib)" /windowsce:emulation

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "x86emDbg"
# PROP BASE Intermediate_Dir "x86emDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "x86emDbg"
# PROP Intermediate_Dir "x86emDbg"
# PROP Target_Dir ""
EMPFILE=empfile.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_" /d "_AFXDLL"
# ADD RSC /l 0x409 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /nodefaultlib:"$(CENoDefaultLib)" /windowsce:emulation

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEPPCRel"
# PROP BASE Intermediate_Dir "WCEPPCRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCEPPCRel"
# PROP Intermediate_Dir "WCEPPCRel"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clppc.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "PPC" /D "_PPC_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "PPC" /D "_PPC_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
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
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:PPC /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:PPC /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCEPPCDbg"
# PROP BASE Intermediate_Dir "WCEPPCDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCEPPCDbg"
# PROP Intermediate_Dir "WCEPPCDbg"
# PROP Target_Dir ""
PFILE=pfile.exe
CPP=clppc.exe
# ADD BASE CPP /nologo /M$(CECrtMTDebug) /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "PPC" /D "_PPC_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMTDebug) /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "PPC" /D "_PPC_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "ppc" /d "_ppc_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "ppc" /d "_ppc_" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:PPC /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:PPC /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCECEFDbg"
# PROP BASE Intermediate_Dir "WCECEFDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCECEFDbg"
# PROP Intermediate_Dir "WCECEFDbg"
# PROP Target_Dir ""
CPP=clcef.exe
# ADD BASE CPP /nologo /W3 /Zi /Od /D "CEF" /D "UNICODE" /D UNDER_CE=$(CEVersion) /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /cef /TP /c
# ADD CPP /nologo /W3 /Zi /Od /D "CEF" /D "UNICODE" /D UNDER_CE=$(CEVersion) /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /cef /TP /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "CEF" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
# ADD RSC /l 0x409 /r /d "CEF" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=linkcef.exe
# ADD BASE LINK32 $(CEx86Corelibc) commctrl.lib coredll.lib /nologo /entry:"WinMainCRTStartup" /base:"0x00010000" /debug /machine:CEE /nodefaultlib:$(CENoDefaultLib) /subsystem:$(CESubsystem) /Fixed:no
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 $(CEx86Corelibc) commctrl.lib coredll.lib /nologo /entry:"WinMainCRTStartup" /base:"0x00010000" /debug /machine:CEE /nodefaultlib:$(CENoDefaultLib) /subsystem:$(CESubsystem) /Fixed:no
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCECEFDbg"
# PROP BASE Intermediate_Dir "WCECEFDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCECEFDbg"
# PROP Intermediate_Dir "WCECEFDbg"
# PROP Target_Dir ""
CPP=clcef.exe
# ADD BASE CPP /nologo /W3 /Zi /Od /D "CEF" /D "UNICODE" /D UNDER_CE=$(CEVersion) /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /cef /TP /c
# ADD CPP /nologo /W3 /Zi /Od /D "CEF" /D "UNICODE" /D UNDER_CE=$(CEVersion) /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /cef /TP /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "CEF" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
# ADD RSC /l 0x409 /r /d "CEF" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=linkcef.exe
# ADD BASE LINK32 $(CEx86Corelibc) commctrl.lib coredll.lib /nologo /entry:"WinMainCRTStartup" /base:"0x00010000" /debug /machine:CEE /nodefaultlib:$(CENoDefaultLib) /subsystem:$(CESubsystem) /Fixed:no
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 $(CEx86Corelibc) commctrl.lib coredll.lib /nologo /entry:"WinMainCRTStartup" /base:"0x00010000" /debug /machine:CEE /nodefaultlib:$(CENoDefaultLib) /subsystem:$(CESubsystem) /Fixed:no
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ENDIF 

# Begin Target

# Name "VNSB - Win32 (WCE MIPS) Release"
# Name "VNSB - Win32 (WCE MIPS) Debug"
# Name "VNSB - Win32 (WCE SH4) Release"
# Name "VNSB - Win32 (WCE SH4) Debug"
# Name "VNSB - Win32 (WCE SH3) Release"
# Name "VNSB - Win32 (WCE SH3) Debug"
# Name "VNSB - Win32 (WCE ARM) Release"
# Name "VNSB - Win32 (WCE ARM) Debug"
# Name "VNSB - Win32 (WCE MIPSFP) Release"
# Name "VNSB - Win32 (WCE MIPSFP) Debug"
# Name "VNSB - Win32 (WCE x86) Release"
# Name "VNSB - Win32 (WCE x86) Debug"
# Name "VNSB - Win32 (WCE x86em) Release"
# Name "VNSB - Win32 (WCE x86em) Debug"
# Name "VNSB - Win32 (WCE PPC) Release"
# Name "VNSB - Win32 (WCE PPC) Debug"
# Name "VNSB - Win32 (WCE CEF) Debug"
# Name "VNSB - Win32 (WCE CEF) Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CodeDlg.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_CODED=\
	".\CodeDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ComObjectDlg.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_COMOB=\
	".\ComObjectDlg.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_MAINF=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_MAINF=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_MAINF=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MenuEditorDlg.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_MENUE=\
	".\ComObjectDlg.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_MENUE=\
	".\ComObjectDlg.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_MENUE=\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NSBForm.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_NSBFO=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_NSBFO=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_NSBFO=\
	".\NSBForm.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NSBFormObjectView.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_NSBFOR=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_NSBFOR=\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_NSBFOR=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_NSBFOR=\
	".\NSBFormObjectView.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_NSBFOR=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_NSBFOR=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PropEditorDlg.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_PROPE=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_PROPE=\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_PROPE=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_PROPE=\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_PROPE=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_PROPE=\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SelectObjectDlg.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_SELEC=\
	".\NSBObjects.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_SELEC=\
	".\NSBObjects.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_SELEC=\
	".\NSBObjects.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_SELEC=\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_SELEC=\
	".\NSBObjects.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_SELEC=\
	".\NSBObjects.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /QMFWCE
# ADD CPP /QMFWCE /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /QMFWCE
# ADD CPP /QMFWCE /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VNSB.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_VNSB_=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_VNSB_=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_VNSB_=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_VNSB_=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_VNSB_=\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VNSB.rc

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VNSBDlg.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_VNSBD=\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_VNSBD=\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_VNSBD=\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_VNSBD=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_VNSBD=\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_VNSBD=\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VNSBDoc.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_VNSBDO=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_VNSBDO=\
	".\MainFrm.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_VNSBDO=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_VNSBDO=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_VNSBDO=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	".\VNSBDoc.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_VNSBDO=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\MainFrm.h"\
	".\MenuEditorDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDlg.h"\
	".\VNSBDoc.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VNSBView.cpp

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

DEP_CPP_VNSBV=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

DEP_CPP_VNSBV=\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

DEP_CPP_VNSBV=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

DEP_CPP_VNSBV=\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

DEP_CPP_VNSBV=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

DEP_CPP_VNSBV=\
	".\CodeDlg.h"\
	".\ComObjectDlg.h"\
	".\NSBForm.h"\
	".\NSBFormObjectView.h"\
	".\NSBObjects.h"\
	".\PropEditorDlg.h"\
	".\SelectObjectDlg.h"\
	".\StdAfx.h"\
	".\VNSB.h"\
	".\VNSBDoc.h"\
	".\VNSBView.h"\
	

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CodeDlg.h
# End Source File
# Begin Source File

SOURCE=.\ComObjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MenuEditorDlg.h
# End Source File
# Begin Source File

SOURCE=.\NSBForm.h
# End Source File
# Begin Source File

SOURCE=.\NSBFormObjectView.h
# End Source File
# Begin Source File

SOURCE=.\NSBObjects.h
# End Source File
# Begin Source File

SOURCE=.\PropEditorDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SelectObjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VNSB.h
# End Source File
# Begin Source File

SOURCE=.\VNSBDlg.h
# End Source File
# Begin Source File

SOURCE=.\VNSBDoc.h
# End Source File
# Begin Source File

SOURCE=.\VNSBView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\backgrou.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Cmdbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\VNSB.ico
# End Source File
# Begin Source File

SOURCE=.\res\VNSB.rc2
# PROP Exclude_From_Scan -1

!IF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPS) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH4) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE SH3) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE ARM) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE MIPSFP) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE x86em) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE PPC) Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Debug"

!ELSEIF  "$(CFG)" == "VNSB - Win32 (WCE CEF) Release"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\RoadMap.txt
# End Source File
# End Target
# End Project
