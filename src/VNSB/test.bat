@echo off
del compileErr.txt
REM set general variables for eVC4 build
set evc="C:\Program Files\Microsoft eMbedded C++ 4.0\COMMON\EVC\bin\evc.exe"
set OUTPUTPATH=C:\E\NSBCE6\600
cd evc4

REM  ------------ Pocket PC 2003 -------------
echo ------------ Pocket PC 2003 -------------
echo ------------ Pocket PC 2003 ------------- >> ..\compileErr.txt
%evc% VNSB.vcw /MAKE "VNSB - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="POCKET PC 2003" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4Rel\VNSB.exe %OUTPUTPATH%\PocketPC2003
del  ARMV4Rel\*.obj ARMV4Rel\*.res
cd ..