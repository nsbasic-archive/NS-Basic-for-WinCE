@echo off
del compileErr.txt

REM set general variables for eVC4 build
set evc="c:\Program Files\Microsoft eMbedded C++ 4.0\COMMON\EVC\bin\evc.exe"
set OUTPUTPATH=e:\NSBCE8\Files\Controls

REM  ------------ Pocket PC 2003/Windows Mobile -------------
echo Pocket PC 2003 
echo -------- Pocket PC 2003/Windows Mobile  >> ..\compileErr.txt
%evc% "NSBCE Stub.vcw" /MAKE "NSBCE Stub - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="POCKET PC 2003" /REBUILD 1 >> ..\compileErr.txt
copy "ARMV4Rel\NSBCE Stub.exe" %OUTPUTPATH%\WM
del /q ARMV4Rel

REM  ------------ Standard SDK -------------
echo Standard SDK - ARMV4
echo -------- Standard SDK - ARMV4 >> ..\compileErr.txt
%evc% "NSBCE Stub.vcw" /MAKE "NSBCE Stub - Win32 (WCE ARMV4) Release" /CLEAN /CEConfig="COMMONCEDEV420" /REBUILD 1 >> ..\compileErr.txt
copy "ARMV4Rel\NSBCE Stub.exe" %OUTPUTPATH%\2577
echo Standard SDK - ARMV4i
echo -------- Standard SDK - ARMV4i >> ..\compileErr.txt
%evc% "NSBCE Stub.vcw" /MAKE "NSBCE Stub - Win32 (WCE ARMV4I) Release" /CLEAN /CEConfig="COMMONCEDEV420" /REBUILD 1 >> ..\compileErr.txt
copy "ARMV4iRel\NSBCE Stub.exe" %OUTPUTPATH%\1824
echo Standard SDK - MIPSII
echo -------- Standard SDK - MIPSII >> ..\compileErr.txt
%evc% "NSBCE Stub.vcw" /MAKE "NSBCE Stub - Win32 (WCE MIPSII) Release" /CLEAN /CEConfig="COMMONCEDEV420" /REBUILD 1 >> ..\compileErr.txt
copy "MIPSIIRel\NSBCE Stub.exe" %OUTPUTPATH%\4000
del /q ARMV4Rel
del /q ARMV4iRel
del /q MIPSIIRel

echo All Builds Complete!

cd ..
