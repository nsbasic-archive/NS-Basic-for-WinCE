del *.CAB

..\Cabwiz MSCE.inf /err err.log /cpu HPC_1824 HPC_2336 HPC_2577 HPC_4000
del *.DAT

..\ezsetup -l english -i WinCE.ini -r Readme.txt -e ..\..\files\license.txt -o MSCEControls.WinCE.exe




..\Cabwiz MSCE.inf /err err.log /cpu WM 
del *.DAT

..\ezsetup -l english -i WM.ini -r Readme.txt -e ..\..\files\license.txt -o MSCEControls.WM.exe

del *.tmp

copy *.exe ..\..\Files\Installers
copy *.cab ..\..\Files\cabfiles
del *.cab