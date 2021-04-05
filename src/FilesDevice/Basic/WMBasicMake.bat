del *.CAB

..\cabwiz Basic.inf /err err.log /cpu WM 
del *.DAT

..\ezsetup -l english -i WMBasic.ini -r BASICReadme.txt -e ..\..\files\license.txt -o Basic.WM.exe
del *.tmp

copy *.exe ..\..\files\installers
copy *.cab ..\..\files\cabfiles