del *.CAB

set dllname=VBScript
set fileCabwiz="d:\program files\windows ce tools\wce420\pocket pc 2003\tools\cabwiz.exe"
set ezsetup="..\..\ezsetup.exe"

%fileCabwiz% %dllname%.inf /err err.log /cpu PocketPC4_ARM HPC_1824 HPC_2336 HPC_2577

rem These have to be renamed so total length<256 characters
rem This restriction goes away with ActiveSync 4.1

rename %dllname%.PocketPC4_ARM.cab N.PocketPC4ARM.cab  
rename %dllname%.HPC_1824.cab      N.HPC1824.cab  
rename %dllname%.HPC_2336.cab      N.HPC2336.cab  
rename %dllname%.HPC_2577.cab      N.HPC2577.cab 

del *.DAT

%ezsetup% -i %dllname%.ini -r Readme.txt -e license.txt -o %dllname%.exe

del *.CAB
del *.tmp