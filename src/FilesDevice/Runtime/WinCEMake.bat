..\Cabwiz Runtime.inf /err err.log /cpu HPC_1824 HPC_2336 HPC_2577 HPC_4000 /compress
del *.DAT

..\ezsetup -l english -i WinCE.ini -r RuntimeReadme.txt -e ..\..\files\license.txt -o Runtime.WinCE.exe
del *.tmp

