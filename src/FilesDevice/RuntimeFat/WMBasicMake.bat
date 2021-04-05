del *.CAB

..\Cabwiz RuntimeFat.inf /err err.log /cpu WM

del *.DAT

..\ezsetup -l english -i WMBasic.ini -r BASICReadme.txt -e ..\..\files\license.txt -o RuntimeFat.WM.exe

del *.tmp