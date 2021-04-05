
..\cabwiz RuntimeFat.inf /err err.log /cpu HPC_1824 HPC_2336 HPC_2577 HPC_4000 /compress
del *.DAT

..\ezsetup -l english -i WinCE.ini -r BASICReadme.txt -e ..\..\files\license.txt -o RuntimeFat.WinCE.exe

del *.tmp