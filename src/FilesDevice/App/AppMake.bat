del *.CAB

..\cabwiz App.inf /err err.log /cpu WM /compress
..\ezsetup -i e:\nsbce8\filesdevice\app\App.ini -r Readme.txt -e EULA.txt -o Project1.Installer.exe

del *.tmp, *.DAT