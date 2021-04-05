cd ..\Script
call compile

cd ..\Basic
call WMBasicMake
call WinCEMake
copy *.exe ..\..\Files\Installers
copy *.bat ..\..\Files\cabfiles

cd ..\Runtime
call WMRuntimeMake
call WinCEMake
copy *.exe ..\..\Files\Installers
copy *.bat ..\..\Files\cabfiles

cd ..\RuntimeFat
call WMBasicMake
call WinCEMake
copy *.exe ..\..\Files\Installers
copy *.bat ..\..\Files\cabfiles

cd ..


