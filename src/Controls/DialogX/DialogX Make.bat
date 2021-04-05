del *.CAB

"E:\Program Files\Microsoft eMbedded Tools\EVB\Cabwiz.exe" DialogX.inf /err err.log /cpu HPC_SH3 HPC_MIPS HPCPro_ARM HPCPro_SH3 HPCPro_SH4 HPCPro_MIPS PPC_SH3 PPC_MIPS PocketPC_MIPS PocketPC_SH3 PocketPC_ARM

del *.DAT

..\ezsetup -i DialogX.ini -r DialogXReadme.txt -e e:\NSBCE\300\all\license.txt -o DialogX.exe

del *.CAB