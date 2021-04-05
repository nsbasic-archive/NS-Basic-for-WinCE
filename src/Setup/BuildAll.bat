Rem Compile IDEs and build installers

set vb="c:\program files\microsoft visual studio\vb98\vb6"
set projectName="c:\files\nsbce8\Desktop IDE\NSBasic_CE.vbp"
set outputPath="c:\files\nsbce8"

Rem Do Full version

set constants=NSBasic_CE=1:ccaAllowRegistration=1
%vb% /m %projectname% /outdir %outputPath% /d %constants%

copy NSBCE.Full.isi NSBCE.VariableData.isi
"c:\program files\Inno Setup 5\iscc" /Q NSBCE.iss


Rem Do Demo version

set constants=NSBasic_CE=1:ccaAllowRegistration=0
%vb% /m %projectname% /outdir %outputPath% /d %constants%

copy NSBCE.Demo.isi NSBCE.VariableData.isi
"c:\program files\Inno Setup 5\iscc" /Q NSBCE.iss

del NSBCE.VariableData.isi
