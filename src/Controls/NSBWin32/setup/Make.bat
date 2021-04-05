del *.CAB

set dllname=NSBWin32
set fileCabwiz="d:\program files\windows ce tools\wce420\pocket pc 2003\tools\cabwiz.exe"
set ezsetup="..\..\ezsetup.exe"

%fileCabwiz% %dllname%.inf /err err.log /cpu PocketPC_MIPS PocketPC_ARM PocketPC_SH3 PocketPC4_ARM PPC_MIPS PPC_SH3 HPC2000_ARM HPC2000_MIPS HPCPro_ARM HPCPro_MIPS HPCPro_SH3 HPCPro_SH4 HPC_1824 HPC_2336 HPC_2577

rem These have to be renamed so total length<256 characters
rem This restriction goes away with ActiveSync 4.1

rename %dllname%.PocketPC_MIPS.cab N.PocketPCMIPS.cab
rename %dllname%.PocketPC_ARM.cab  N.PocketPCARM.cab 
rename %dllname%.PocketPC_SH3.cab  N.PocketPCSH3.cab  
rename %dllname%.PocketPC4_ARM.cab N.PocketPC4ARM.cab  
rename %dllname%.PPC_MIPS.cab      N.PPCMIPS.cab  
rename %dllname%.PPC_SH3.cab       N.PPCSH3.cab  
rename %dllname%.HPC2000_ARM.cab   N.HPC2000ARM.cab  
rename %dllname%.HPC2000_MIPS.cab  N.HPC2000MIPS.cab  
rename %dllname%.HPCPro_ARM.cab    N.HPCProARM.cab  
rename %dllname%.HPCPro_MIPS.cab   N.HPCProMIPS.cab  
rename %dllname%.HPCPro_SH3.cab    N.HPCProSH3.cab  
rename %dllname%.HPCPro_SH4.cab    N.HPCProSH4.cab  
rename %dllname%.HPC_1824.cab      N.HPC1824.cab  
rename %dllname%.HPC_2336.cab      N.HPC2336.cab  
rename %dllname%.HPC_2577.cab      N.HPC2577.cab 

del *.DAT

%ezsetup% -i %dllname%.ini -r Readme.txt -e license.txt -o %dllname%.exe

del *.CAB
del *.tmp