@echo off
REM Set path names (system dependant)
SET EVC3="c:\Program Files\Microsoft eMbedded Tools\COMMON\EVC\bin\evc.exe"
SET EVC4="c:\Program Files\Microsoft eMbedded C++ 4.0\COMMON\EVC\bin\evc.exe"
SET MSVC6="c:\Program Files\Microsoft Visual Studio\Common\MSDev98\Bin\MSDEV.EXE"
SET OUTPUTPATH=e:\NSBCE7\Controls\NSBControls\Binaries

REM SDK NAMES
 SET DLLNAME=NSBControls.dll
 
REM EVC3 SDKs
 SET POCKETPC_SDK=Pocket PC
 SET POCKETPC_2002_SDK=Pocket PC 2002
 SET PPC_SDK=Palm-size PC 2.11
 SET HPCPRO_SDK=H/PC Pro 2.11
 SET HPC2000_SDK=HPC 2000
 
REM EVC4 SDKs 
 SET POCKETPC_2003_SDK=POCKET PC 2003
 REM SET STD_SDK4=STANDARDSDK_420
 SET STD_SDK4=COMMONCEDEV420


DEL compileErr.txt
DEL results.txt
CD  SRC



REM --- POCKET PC 2000 ---
ECHO POCKET PC 2000
SET VC=%EVC3%
mkdir %OUTPUTPATH%\PocketPC 2>> ..\compileErr.txt

ECHO Pocket PC - ARM
ECHO Pocket PC - ARM>> ..\compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE Arm) PPC_ARM_Release" /CLEAN /CEConfig="%POCKETPC_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% Pocket PC - ARM>> ..\results.txt
mkdir %OUTPUTPATH%\PocketPC\arm 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PocketPC\arm
del /Q output

echo Pocket PC - SH3
echo Pocket PC - SH3>> ..\compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE SH3) PPC_SH3_Release" /CLEAN /CEConfig="%POCKETPC_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% Pocket PC - SH3>> ..\results.txt
mkdir %OUTPUTPATH%\PocketPC\sh3 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PocketPC\sh3
del /Q output

echo Pocket PC - MIPS
echo Pocket PC - MIPS>> ..\compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE MIPS) PPC_MIPS_Release" /CLEAN /CEConfig="%POCKETPC_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% Pocket PC - MIPS>> ..\results.txt
mkdir %OUTPUTPATH%\PocketPC\mips 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PocketPC\mips
del /Q output



REM --- Palm-sized PC ---
ECHO Palm-sized PC
SET VC=%EVC3%
mkdir %OUTPUTPATH%\PPC 2>> ..\compileErr.txt

echo Palm-size PC - SH3
echo Palm-size PC - SH3>> ..\compileErr.txt
%VC% EVC3.vcw /MAKE "EVC3 - Win32 (WCE SH3) PALMSIZED_SH3_Release" /CLEAN /CEConfig="%PPC_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% Palm-size PC - SH3>> ..\results.txt
mkdir %OUTPUTPATH%\PPC\sh3 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PPC\sh3
del /q output

echo Palm-size PC - MIPS
echo Palm-size PC - MIPS>> ..\compileErr.txt
%VC% EVC3.vcw /MAKE "EVC3 - Win32 (WCE MIPS) PALMSIZED_MIPS_Release" /CLEAN /CEConfig="%PPC_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% Palm-size PC - MIPS>> ..\results.txt
mkdir %OUTPUTPATH%\PPC\mips 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PPC\mips
del /q output



REM ------------ HPC/Pro -------------
SET VC=%EVC3%
ECHO HPC/Pro
mkdir %OUTPUTPATH%\HPCPRO 2>> ..\compileErr.txt

echo HPC/Pro - ARM
echo HPC/Pro - ARM>> ..\compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE Arm) HPC_ARM_Release" /CLEAN /CEConfig="%HPCPRO_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% HPC/Pro - ARM>> ..\results.txt
mkdir %OUTPUTPATH%\HPCPRO\arm 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPCPRO\arm
del /q output

echo HPC/Pro - SH3
echo HPC/Pro - SH3 >> compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE SH3) HPC_SH3_Release" /CLEAN /CEConfig="%HPCPRO_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% HPC/Pro - SH3>> ..\results.txt
mkdir %OUTPUTPATH%\HPCPRO\SH3 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPCPRO\SH3
del /q output

echo HPC/Pro - SH4
echo HPC/Pro - SH4 >> compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE SH4) HPC_SH4_Release" /CLEAN /CEConfig="%HPCPRO_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% HPC/Pro - SH4>> ..\results.txt
mkdir %OUTPUTPATH%\HPCPRO\SH4 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPCPRO\SH4
del /q output

echo HPC/Pro - MIPS
echo HPC/Pro - MIPS >> compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE MIPS) HPC_MIPS_Release" /CLEAN /CEConfig="%HPCPRO_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% HPC/Pro - MIPS>> ..\results.txt
mkdir %OUTPUTPATH%\HPCPRO\MIPS 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPCPRO\MIPS
del /q output



REM ------------ HPC 2000 -------------
SET VC=%EVC3%
ECHO HPC 2000
mkdir %OUTPUTPATH%\HPC2000 2>> ..\compileErr.txt

echo HPC 2000 - ARM
echo HPC 2000 - ARM>> ..\compileErr.txt
%VC% EVC3.vcw /MAKE "EVC3 - Win32 (WCE Arm) HPC2K_ARM_Release" /CLEAN /CEConfig="%HPC2000_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% HPC 2000 - ARM>> ..\results.txt
mkdir %OUTPUTPATH%\HPC2000\ARM 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPC2000\ARM
del /q output

echo HPC 2000 - MIPS
echo HPC 2000 - MIPS>> ..\compileErr.txt
%VC% EVC3.vcw /MAKE "EVC3 - Win32 (WCE MIPS) HPC2K_MIPS_Release" /CLEAN /CEConfig="%HPC2000_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% HPC 2000 - MIPS>> ..\results.txt
mkdir %OUTPUTPATH%\HPC2000\MIPS 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPC2000\MIPS
del /q output



REM --- POCKET PC 2002 ---
ECHO POCKET PC 2002
SET VC=%EVC3%
mkdir %OUTPUTPATH%\PocketPC2002 2>> ..\compileErr.txt

ECHO Pocket PC 2002 - ARM
ECHO Pocket PC 2002 - ARM>> ..\compileErr.txt
%VC%  EVC3.vcw /MAKE "EVC3 - Win32 (WCE Arm) PPC2002_Release" /CLEAN /CEConfig="%POCKETPC_2002_SDK%" /REBUILD 1>> ..\compileErr.txt
ECHO %ERRORLEVEL% Pocket PC 2002 - ARM>> ..\results.txt
mkdir %OUTPUTPATH%\PocketPC2002\arm 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PocketPC2002\arm
del /q output


REM  ------------ Pocket PC 2003 -------------
echo Pocket PC 2003 
SET VC=%EVC4%
mkdir %OUTPUTPATH%\PocketPC2003 2>> ..\compileErr.txt

echo Pocket PC 2003
echo Pocket PC 2003  >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE ARMV4) PPC_2003_Release" /CLEAN /CEConfig="%POCKETPC_2003_SDK%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Pocket PC 2003 - ARM>> ..\results.txt
mkdir %OUTPUTPATH%\PocketPC2003 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\PocketPC2003
del /q output


REM  ------------ Standard SDK -------------
REM --- Using COMMONCEDEV420 SDK -----------
ECHO COMMONCEDEV420 SDK
SET VC=%EVC4%

echo Standard SDK - ARMV4
echo Standard SDK - ARMV4 >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE ARMV4) CE42_ARM4_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - ARMV4>> ..\results.txt
mkdir %OUTPUTPATH%\HPC_2577 2>> ..\compileErr.txt
mkdir %OUTPUTPATH%\CE420_ARMV4 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPC_2577
copy output\%DLLNAME% %OUTPUTPATH%\CE420_ARMV4
del /q output

echo Standard SDK - ARMV4I
echo Standard SDK - ARMV4I >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE ARMV4I) CE42_ARM4I_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - ARMV4I>> ..\results.txt
mkdir %OUTPUTPATH%\HPC_1824 2>> ..\compileErr.txt
mkdir %OUTPUTPATH%\CE420_ARMV4I 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\HPC_1824
copy output\%DLLNAME% %OUTPUTPATH%\CE420_ARMV4I
del /q output

echo Standard SDK - EMU
echo Standard SDK - EMU >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE emulator) CE42_EMU_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - EMU>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_EMU 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_EMU
del /q output

echo Standard SDK - MIPSII
echo Standard SDK - MIPSII >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE MIPSII) CE42_MIPSII_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - MIPSII>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_MIPSII 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_MIPSII
del /q output

echo Standard SDK - MIPSIIFP
echo Standard SDK - MIPSIIFP >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE MIPSII_FP) CE42_MIPSIIFP_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - MIPSIIFP>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_MIPSIIFP 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_MIPSIIFP
del /q output

echo Standard SDK - MIPSIV
echo Standard SDK - MIPSIV >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE MIPSIV) CE42_MIPSIV_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - MIPSIV>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_MIPSIV 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_MIPSIV
del /q output

echo Standard SDK - MIPSIVFP
echo Standard SDK - MIPSIVFP >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE MIPSIV_FP) CE42_MIPSIVFP_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - MIPSIVFP>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_MIPSIVFP 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_MIPSIVFP
del /q output

echo Standard SDK - SH3
echo Standard SDK - SH3 >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE SH3) CE42_SH3_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - SH3>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_SH3 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_SH3
del /q output

echo Standard SDK - SH4
echo Standard SDK - SH4 >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE SH4) CE42_SH4_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - SH4>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_SH4 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_SH4
del /q output

echo Standard SDK - x86
echo Standard SDK - x86 >> ..\compileErr.txt
%VC% EVC4.VCW /MAKE "EVC4 - Win32 (WCE x86) CE42_X86_Release" /CLEAN /CEConfig="%STD_SDK4%" /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Standard SDK - x86>> ..\results.txt
mkdir %OUTPUTPATH%\CE420_X86 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\CE420_X86
del /q output



REM  ------------ Desktop -------------
ECHO Desktop
SET VC=%MSVC6%

echo Desktop - x86
echo Desktop - x86>> ..\compileErr.txt
%VC% Desk.dsw /MAKE "ComCtl - Win32 Unicode Release MinDependency" /CLEAN /REBUILD 1 >> ..\compileErr.txt
ECHO %ERRORLEVEL% Desktop - x86>> ..\results.txt
mkdir %OUTPUTPATH%\Desktop 2>> ..\compileErr.txt
copy output\%DLLNAME% %OUTPUTPATH%\Desktop
del /q output




cd ..
ECHO COMPLETED
type results.txt