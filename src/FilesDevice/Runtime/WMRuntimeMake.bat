del *.CAB


..\Cabwiz Runtime.inf /err err.log /cpu WM

del *.DAT

..\ezsetup -l english  -i WMRuntime.ini -r RuntimeReadme.txt -e ..\..\files\license.txt -o Runtime.WM.exe

del *.tmp