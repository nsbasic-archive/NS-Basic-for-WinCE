cd Basic
call WMBasicMake
call WinCEMake
copy *.exe ..\..\Files\Installers
copy *.cab ..\..\Files\cabfiles
del *.cab

cd ..\Runtime
call WMRuntimeMake
call WinCEMake
copy *.exe ..\..\Files\Installers
copy *.cab ..\..\Files\cabfiles
del *.cab

cd ..\RuntimeFat
call WMBasicMake
call WinCEMake
copy *.exe ..\..\Files\Installers
copy *.cab ..\..\Files\cabfiles
del *.cab

cd ..

