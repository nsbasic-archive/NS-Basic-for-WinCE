@echo off
REM set general variables for eVC3 build
set evc="d:\Program Files\Microsoft eMbedded Tools\COMMON\EVC\bin\evc.exe"
set OUTPUTPATH=e:\NSBCE6\600
del compileErr.txt
cd eVC3

REM  ------------ Pocket PC -------------
echo ------------ Pocket PC -------------
echo ------------ Pocket PC ------------- >> ..\compileErr.txt
%evc%  VNSB.vcw /MAKE "VNSB - Win32 (WCE Arm) Release" /CLEAN /CEConfig="Pocket PC" /REBUILD 1 >> ..\compileErr.txt
%evc%  VNSB.vcw /MAKE "VNSB - Win32 (WCE SH3) Release" /CLEAN /CEConfig="Pocket PC" /REBUILD 1 >> ..\compileErr.txt
%evc%  VNSB.vcw /MAKE "VNSB - Win32 (WCE MIPS) Release" /CLEAN /CEConfig="Pocket PC" /REBUILD 1 >> ..\compileErr.txt
copy WCEARMRel\VNSB.exe %OUTPUTPATH%\PocketPC\arm
copy WCESH3Rel\VNSB.exe %OUTPUTPATH%\PocketPC\sh3
copy WMIPSRel\VNSB.exe %OUTPUTPATH%\PocketPC\mips
del /q WCEARMRel
del /q WCESH3Rel
del /q WMIPSRel

REM  ------------ PPC -------------
echo ------------ PPC -------------
echo ------------ PPC ------------- >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE SH3) Release" /CLEAN /CEConfig="Palm-size PC 2.11" /REBUILD 1 >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE MIPS) Release" /CLEAN /CEConfig="Palm-size PC 2.11" /REBUILD 1 >> ..\compileErr.txt
copy WCESH3Rel\VNSB.exe %OUTPUTPATH%\PPC\sh3
copy WMIPSRel\VNSB.exe  %OUTPUTPATH%\PPC\mips
del /q WCESH3Rel
del /q WMIPSRel

REM  ------------ HPC 2000 -------------
echo ------------ HPC 2000 -------------
echo ------------ HPC 2000 ------------- >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE Arm) Release" /CLEAN /CEConfig="HPC 2000" /REBUILD 1 >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE MIPS) Release" /CLEAN /CEConfig="HPC 2000" /REBUILD 1 >> ..\compileErr.txt
copy WCEARMRel\VNSB.exe %OUTPUTPATH%\HPC2000\arm
copy WMIPSRel\VNSB.exe  %OUTPUTPATH%\HPC2000\mips
del /q WCEARMRel
del /q WMIPSRel

REM  ------------ HPC/Pro -------------
echo ------------ HPC/Pro -------------
echo ------------ HPC/Pro ------------- >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE Arm) Release" /CLEAN /CEConfig="H/PC Pro 2.11" /REBUILD 1 >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE SH3) Release" /CLEAN /CEConfig="H/PC Pro 2.11" /REBUILD 1 >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE SH4) Release" /CLEAN /CEConfig="H/PC Pro 2.11" /REBUILD 1 >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE MIPS) Release" /CLEAN /CEConfig="H/PC Pro 2.11" /REBUILD 1 >> ..\compileErr.txt
copy WCEARMRel\VNSB.exe %OUTPUTPATH%\HPCPRO\arm
copy WCESH3Rel\VNSB.exe %OUTPUTPATH%\HPCPRO\sh3
copy WCESH3Rel\VNSB.exe %OUTPUTPATH%\HPCPRO\sh4
copy WMIPSRel\VNSB.exe  %OUTPUTPATH%\HPCPRO\mips
del /q WCEARMRel
del /q WCESH3Rel
del /q WCESH4Rel
del /q WMIPSRel

REM set general variables for eVC4 build
set evc="d:\Program Files\Microsoft eMbedded C++ 4.0\COMMON\EVC\bin\evc.exe"
set OUTPUTPATH=e:\NSBCE6\600
cd ..\evc4

REM  ------------ Pocket PC 2003 -------------
echo ------------ Pocket PC 2003 -------------
echo ------------ Pocket PC 2003 ------------- >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="POCKET PC 2003" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4Rel\VNSB.exe %OUTPUTPATH%\PocketPC2003
del /q ARMV4Rel

REM  ------------ Standard SDK -------------
echo Standard SDK - ARMV4
echo Standard SDK - ARMV4 >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="STANDARDSDK" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4Rel\VNSB.exe %OUTPUTPATH%\HPC_2577
echo Standard SDK - ARMV4i
echo Standard SDK - ARMV4i >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE ARMV4I) Release" /CLEAN /CEConfig="STANDARDSDK" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4iRel\VNSB.exe %OUTPUTPATH%\HPC_1824
del /q ARMV4Rel
del /q ARMV4iRel
echo Standard SDK - MIPSII >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE MIPSII) Release" /CLEAN /CEConfig="STANDARDSDK" /REBUILD 1 >> ..\compileErr.txt
copy MIPSIIRel\VNSB.exe %OUTPUTPATH%\HPC_4000
del /q ARMV4Rel
del /q ARMV4iRel
del /q MIPSIIRel
echo All Builds Complete!

cd ..
