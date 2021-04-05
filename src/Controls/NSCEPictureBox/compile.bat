@echo off
SET OUTPUTPATH=e:\NSBCE8\Files\Controls
del compileErr.txt

REM set general variables for eVC4 build
set evc="c:\Program Files\Microsoft eMbedded C++ 4.0\COMMON\EVC\bin\evc.exe"
cd evc4

REM  ------------ Windows Mobile -------------
echo Pocket PC 2003 
echo Pocket PC 2003  >> ..\compileErr.txt
%evc% nscepicturebox.vcw /MAKE "nscepicturebox - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="POCKET PC 2003" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4Rel\nscepicturebox.ocx %OUTPUTPATH%\WM
del /q ARMV4Rel

REM  ------------ Standard SDK -------------
echo Standard SDK - ARMV4
echo Standard SDK - ARMV4 >> ..\compileErr.txt
%evc% nscepicturebox.vcw /MAKE "nscepicturebox - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="STANDARDSDK" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4Rel\nscepicturebox.ocx %OUTPUTPATH%\2577
echo Standard SDK - ARMV4i
echo Standard SDK - ARMV4i >> ..\compileErr.txt
%evc% nscepicturebox.vcw /MAKE "nscepicturebox - Win32 (WCE ARMV4I) Release" /CLEAN /CEConfig="STANDARDSDK" /REBUILD 1 >> ..\compileErr.txt
copy ARMV4iRel\nscepicturebox.ocx %OUTPUTPATH%\1824
echo Standard SDK - MIPSII
echo Standard SDK - MIPSII >> ..\compileErr.txt
%evc% nscepicturebox.vcw /MAKE "nscepicturebox - Win32 (WCE MIPSII) Release" /CLEAN /CEConfig="STANDARDSDK" /REBUILD 1 >> ..\compileErr.txt
copy MIPSIIRel\nscepicturebox.ocx %OUTPUTPATH%\4000
del /q ARMV4Rel
del /q ARMV4iRel
del /q MIPSIIRel

echo All Builds Complete!

cd ..
