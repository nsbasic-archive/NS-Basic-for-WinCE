del *.CAB

set fileCabwiz="d:\program files\Microsoft eMbedded Tools\EVB\cabwiz.exe"
set fileEZSetup="e:\nsbce6\FilesDevice\ezsetup.exe"

%fileCabwiz% Setup.inf /err err.log /cpu PocketPC

del *.DAT

%fileEZSetup% -i Setup.ini -r Readme.txt -e eula.txt -o NSBasicShowcase.exe

del *.xCAB
del *.tmp