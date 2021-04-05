[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{7C16A57E-A293-42D4-A4DA-A876EF7EB196}
AppName=NS Basic CE
AppVerName=NS Basic CE 8.2
AppPublisher=NS BASIC Corporation
AppPublisherURL=http://www.nsbasic.com
AppSupportURL=http://www.nsbasic.com
AppUpdatesURL=http://www.nsbasic.com
DefaultDirName={pf}\NSBasic\CE
DefaultGroupName=NS Basic CE 8.2
LicenseFile=c:\files\NSBCE8\Files\license.TXT
OutputDir=c:\files\NSBCE8\Setup
;OutputBaseFilename=NSBasic_CE
;Password=BE50368
Compression=lzma
SolidCompression=true
AppCopyright=2010 NS BASIC Corporation
PrivilegesRequired=admin
#include "NSBCE.VariableData.isi"

[Languages]
Name: english; MessagesFile: compiler:Default.isl
Name: basque; MessagesFile: compiler:Languages\Basque.isl
Name: brazilianportuguese; MessagesFile: compiler:Languages\BrazilianPortuguese.isl
Name: catalan; MessagesFile: compiler:Languages\Catalan.isl
Name: czech; MessagesFile: compiler:Languages\Czech.isl
Name: danish; MessagesFile: compiler:Languages\Danish.isl
Name: dutch; MessagesFile: compiler:Languages\Dutch.isl
Name: finnish; MessagesFile: compiler:Languages\Finnish.isl
Name: french; MessagesFile: compiler:Languages\French.isl
Name: german; MessagesFile: compiler:Languages\German.isl
Name: hebrew; MessagesFile: compiler:Languages\Hebrew.isl
Name: hungarian; MessagesFile: compiler:Languages\Hungarian.isl
Name: italian; MessagesFile: compiler:Languages\Italian.isl
Name: norwegian; MessagesFile: compiler:Languages\Norwegian.isl
Name: polish; MessagesFile: compiler:Languages\Polish.isl
Name: portuguese; MessagesFile: compiler:Languages\Portuguese.isl
Name: russian; MessagesFile: compiler:Languages\Russian.isl
Name: slovak; MessagesFile: compiler:Languages\Slovak.isl
Name: slovenian; MessagesFile: compiler:Languages\Slovenian.isl
Name: spanish; MessagesFile: compiler:Languages\Spanish.isl

[Tasks]
Name: desktopicon; Description: {cm:CreateDesktopIcon}; GroupDescription: {cm:AdditionalIcons}; Flags: unchecked

[Files]
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

Source: ..\NSBasic.exe; DestDir: {app}; Flags: ignoreversion
Source: ..\Files\App_template.inf; DestDir: {app}; Flags: comparetimestamp
Source: ..\Files\NSBasic.exe.manifest; DestDir: {app}; Flags: comparetimestamp
Source: ..\Files\Readme.htm; DestDir: {app}
Source: ..\Files\Recent.dat; DestDir: {app}; Flags: comparetimestamp
Source: ..\FilesDevice\cabwiz.ddf; DestDir: {app}
Source: ..\FilesDevice\Cabwiz.exe; DestDir: {app}; Flags: comparetimestamp
Source: ..\FilesDevice\ezsetup.exe; DestDir: {app}
Source: ..\Files\dll\ceFileCopy.exe; DestDir: {app}

Source: ..\Files\dll\adocedt31.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\cmax40.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\CMDLGD6.dll; DestDir: {sys}; Flags: regserver sharedfile restartreplace uninsneveruninstall
Source: ..\Files\dll\COMDLG32.OCX; DestDir: {sys}; Flags: regserver sharedfile restartreplace uninsneveruninstall
Source: ..\Files\dll\ExMenu.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\ExPropertiesList.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\finance.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\mscecomdlg.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\MSCECOMM.DLL; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\MSCEFILE.DLL; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\MSCEGRID.DLL; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\msceimage.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\msceimagelist.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\mscelistview.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\mscepicture.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\mscetabstrip.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\mscetreeview.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\mscewinsock.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\MSCOMCTL.OCX; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\msscript.ocx; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\MSVBVM60.DLL; DestDir: {sys}; OnlyBelowVersion: 0,6; Flags: restartreplace uninsneveruninstall sharedfile regserver
Source: ..\Files\dll\MSWINSCK.OCX; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\NSBAddScript.dll; DestDir: {sys}; Flags: sharedfile
Source: ..\Files\dll\NSBComDlg.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\NSBControls.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\NSBPictB.dll; DestDir: {sys}; Flags: sharedfile
Source: ..\Files\dll\NSBWin32.dll; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\NSCEPictureBox.ocx; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\OLEAUT32.DLL; DestDir: {sys}; OnlyBelowVersion: 0,6; Flags: restartreplace uninsneveruninstall sharedfile regserver
Source: ..\Files\dll\SerialXP.dll; DestDir: {sys}; Flags: regserver sharedfile
;Source: ..\Files\dll\stdole32.tlb; DestDir: {sys}; Flags: sharedfile restartreplace uninsneveruninstall regtypelib
Source: ..\Files\dll\SYSINFO.OCX; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\TLBINF32.DLL; DestDir: {sys}; Flags: regserver sharedfile
Source: ..\Files\dll\unicows.dll; DestDir: {sys}; Flags: sharedfile

Source: ..\Files\technotes\images\.DS_Store; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\Adoce.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\BigIcon.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut00.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut01.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut02.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut03.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut04.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut05.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut06.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut07.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut08.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut09.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut10.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut11.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut12.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut13.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut21.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut22.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut23.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut24.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ceTut25.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\collection.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\DLLMaker.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\event.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\gem.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\gem_blue2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\gem_green2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\gem_red.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\gradientbuttons.bmp; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\HelloDialogDetail.JPG; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\iconview.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\Icon_; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\listview.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\ListViewObjModel.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\method.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\NSBImageListObjModel.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\obj.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\pixel.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\prop_r.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\prop_ro.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\prop_rw.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\prop_w.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS001.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS002.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS004.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS005.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS006.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS007.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS008.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS009.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS010.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS011.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\PS012.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\reportview.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\shot_001.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\smallicons1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\smalliconview.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN02.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN04.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN06.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN07.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN08.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN08color.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN08font.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN08Help.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN08SaveAs.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN08SelectFile.GIF; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16c.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16d.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16e.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16f.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16g.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16h.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16i.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16j.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16k.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN16l.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN25a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN25b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN25c.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN25d.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN30a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN30b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN30c.jpg; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN32a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN32b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN34.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35c.jpg; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35d.jpg; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35e.jpg; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35f.jpg; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN35g.jpg; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN39a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN39b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.01.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.02.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.03.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.04.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.05.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.06.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.07.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.08.png; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN41.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN42a.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN42b.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TN42c.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.10.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.11.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.6.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.7.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.8.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT01.9.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT02.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT02.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT02.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT02.4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT02.5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT02.6.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.6.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.7.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT03.8.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.6.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.7.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT04.8.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.6.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT05.7.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT06.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT06.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT06.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT06.4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT06.5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT07.1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT07.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT07.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT08.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT08.2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\TT08.3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut1.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut10.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut2.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut3.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut4.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut5.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut6.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut7.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut8.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\tut9.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\images\up.gif; DestDir: {app}\technotes\images
Source: ..\Files\technotes\ceTut1.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\ceTut2.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\index.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\SQLite.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\SQLiteSample.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN01.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN01a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN02.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN02a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN02b.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03a.101.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03b.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03c.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03d.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03e.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03f.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03g.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03h.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03i.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03j.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03k.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03l.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03m.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03n.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN03o.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN04.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN05.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN06.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN06a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN07.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN08.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN08a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN09.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN11.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN11a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN11b.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN12.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN13.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN14.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN15.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN16.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN19.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN21.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN22.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN23.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN25.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN26.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN27.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN28.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN29.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN30.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN30a.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN30b.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN31.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN32.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN33.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN34.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN35.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN36.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN37.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN38.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN39.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN40.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN41.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TN42.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT.index.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT01.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT02.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT03.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT04.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT05.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT06.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT07.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT08.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\TT09.htm; DestDir: {app}\technotes\
Source: ..\Files\technotes\WINCEAPI.TXT; DestDir: {app}\technotes\
Source: ..\Files\technotes\WINCEAPI.zip; DestDir: {app}\technotes\

Source: ..\Files\Controls\WM\adoce31.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\adocedb31.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\adoceoledb31.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\Basic.exe; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\DialogX.ocx; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\finance.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\HashCryptStreams.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEComDlg.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEComm.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEFile.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEGrid.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEImage.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEImageList.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEListView.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEPicture.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCETabStrip.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCETreeView.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\MSCEWinSock.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\NetStreams.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\newObjectsPack1.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\NSBComDlg.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\NSBControls.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\NSBPhone.ocx; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\NSBWin32.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\NSCEPictureBox.ocx; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\SerialCE.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\SQLITE3COMUTF8.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp
Source: ..\Files\Controls\WM\vbscript.dll; DestDir: {app}\Controls\WM; Flags: comparetimestamp

Source: ..\Files\Controls\1824\Basic.exe; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\DialogX.ocx; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\finance.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEComDlg.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEComm.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEFile.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEGrid.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEImage.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEImageList.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEListView.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEPicture.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCETabStrip.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCETreeView.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\MSCEWinSock.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NetStreams.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\newObjectsPack1.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NSBCE Stub.exe; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NSBComDlg.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NSBControls.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NSBPhone.ocx; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NSBWin32.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\NSCEPictureBox.ocx; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\SerialCE.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\SQLITE3COMUTF8.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp
Source: ..\Files\Controls\1824\vbscript.dll; DestDir: {app}\Controls\1824; Flags: comparetimestamp

Source: ..\Files\Controls\2577\Basic.exe; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\DialogX.ocx; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\finance.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEComDlg.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEComm.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEFile.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEGrid.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEImage.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEImageList.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEListView.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEPicture.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCETabStrip.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCETreeView.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\MSCEWinSock.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NetStreams.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\newObjectsPack1.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NSBCE Stub.exe; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NSBComDlg.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NSBControls.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NSBPhone.ocx; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NSBWin32.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\NSCEPictureBox.ocx; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\SerialCE.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\SQLITE3COMUTF8.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp
Source: ..\Files\Controls\2577\vbscript.dll; DestDir: {app}\Controls\2577; Flags: comparetimestamp

Source: ..\Files\Controls\4000\Basic.exe; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\DialogX.ocx; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\finance.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEComDlg.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEComm.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEFile.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEGrid.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEImage.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEImageList.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEListView.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEPicture.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCETabStrip.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCETreeView.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\MSCEWinSock.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NetStreams.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\newObjectsPack1.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NSBCE Stub.exe; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NSBComDlg.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NSBControls.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NSBPhone.ocx; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NSBWin32.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\NSCEPictureBox.ocx; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\SerialCE.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\SQLITE3COMUTF8.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp
Source: ..\Files\Controls\4000\vbscript.dll; DestDir: {app}\Controls\4000; Flags: comparetimestamp

Source: ..\Files\images\AlexGridProperties.GIF; DestDir: {app}\images\
Source: ..\Files\images\AlexGridProperties.JPG; DestDir: {app}\images\
Source: ..\Files\images\BigIcon.GIF; DestDir: {app}\images\
Source: ..\Files\images\BigIcon.jpg; DestDir: {app}\images\
Source: ..\Files\images\CodeWindow.JPG; DestDir: {app}\images\
Source: ..\Files\images\Full IDE.JPG; DestDir: {app}\images\
Source: ..\Files\images\menueditor.JPG; DestDir: {app}\images\
Source: ..\Files\images\NSBCEbox.jpg; DestDir: {app}\images\
Source: ..\Files\images\NSBPbox.jpg; DestDir: {app}\images\
Source: ..\Files\images\Options1.JPG; DestDir: {app}\images\
Source: ..\Files\images\Options2.JPG; DestDir: {app}\images\
Source: ..\Files\images\Options3.JPG; DestDir: {app}\images\
Source: ..\Files\images\Options4.JPG; DestDir: {app}\images\

Source: ..\Files\Lang\Deutsch.chm; DestDir: {app}\Lang\
Source: ..\Files\Lang\English.chm; DestDir: {app}\Lang\
Source: ..\Files\Lang\Nippon.chm; DestDir: {app}\Lang\
Source: ..\Files\Lang\StrTable_Deutsch.txt; DestDir: {app}\Lang\
Source: ..\Files\Lang\StrTable_English.txt; DestDir: {app}\Lang\
Source: ..\Files\Lang\StrTable_Espanol.txt; DestDir: {app}\Lang\
Source: ..\Files\Lang\StrTable_Nippon.txt; DestDir: {app}\Lang\
Source: ..\Files\Lang\Handbook.pdf; DestDir: {app}\Lang\

Source: ..\Files\installers\Basic.WM.exe; DestDir: {app}\Installers
Source: ..\Files\installers\Basic.WinCE.exe; DestDir: {app}\Installers

Source: ..\Files\Tools\eVB2NSB.exe; DestDir: {app}\Tools\
Source: ..\Files\Tools\Tools.txt; DestDir: {app}\Tools\

Source: ..\Files\Samples\DialogX\DialogX.nsb; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\DialogX.nsp; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\FindDialog.nsb; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\FindDialog.nsp; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\HelloDialog.nsb; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\HelloDialog.nsp; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\Inputbox.nsb; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\Inputbox.nsp; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\Login.nsb; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\DialogX\Login.nsp; DestDir: {userdocs}\NSBasic Samples\CE\DialogX\
Source: ..\Files\Samples\NetStreams\TCPClient2.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NetStreams\
Source: ..\Files\Samples\NetStreams\TCPClient2.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NetStreams\
Source: ..\Files\Samples\NSBComDlg\Color.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\Color.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\File.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\File.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\FilePlayGround.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\FilePlayGround.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\Font.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\Font.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\NSBComDlg.All.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\NSBComDlg.All.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBComDlg\PegHelp.zip; DestDir: {userdocs}\NSBasic Samples\CE\NSBComDlg\
Source: ..\Files\Samples\NSBControls\bigicons1.bmp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\bigicons2.bmp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\EULA.txt; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\ImgLoad.exe; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\ImgLoad.Installer.exe; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\ImgLoad.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\ImgLoad.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\iml.bmp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\README-FIRST.TXT; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\ReadMe.txt; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\ResDLL1.dll; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\Sample1.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\Sample1.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\Sample2.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\Sample2.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\smallicons1.bmp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBControls\smallicons2.bmp; DestDir: {userdocs}\NSBasic Samples\CE\NSBControls\
Source: ..\Files\Samples\NSBWin32\API.DialogBox.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.DialogBox.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.InputBox.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\MPbar.bas; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample1.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample1.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample2.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample2.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample3.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample3.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample4.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\API.Sample4.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\RAS.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\RAS.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\Timer.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\Timer.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\Tray.nsb; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\Tray.nsp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\NSBWin32\traysample.bmp; DestDir: {userdocs}\NSBasic Samples\CE\NSBWin32\
Source: ..\Files\Samples\Resources\App.ico; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\Resources\Dino160wide16bit.bmp; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\Resources\finance.dll; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\Resources\MyText.txt; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\Resources\Resources.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\Resources\Resources.nsp; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\Resources\Super.wav; DestDir: {userdocs}\NSBasic Samples\CE\Resources\
Source: ..\Files\Samples\SerialTools\SerialTools.Simple.nsb; DestDir: {userdocs}\NSBasic Samples\CE\SerialTools\
Source: ..\Files\Samples\SerialTools\SerialTools.Simple.nsp; DestDir: {userdocs}\NSBasic Samples\CE\SerialTools\
Source: ..\Files\Samples\SerialTools\SerialTools.WithEvents.nsb; DestDir: {userdocs}\NSBasic Samples\CE\SerialTools\
Source: ..\Files\Samples\SerialTools\SerialTools.WithEvents.nsp; DestDir: {userdocs}\NSBasic Samples\CE\SerialTools\
Source: ..\Files\Samples\Tutorials\01 HelloPgm.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\02 MyProject02.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\03 Add2MsgBox.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\04 ComboBoxExample.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\05 TempConversion.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\05 TempConversion.nsp; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\06 FileIO_1.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\06 FileIO_1.nsp; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\07 HttpPop3.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\07 HttpPop3.nsp; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\08 HttpStocks.nsb; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\08 HttpStocks.nsp; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\Tutorials\Convert_mod.bas; DestDir: {userdocs}\NSBasic Samples\CE\Tutorials\
Source: ..\Files\Samples\ADOCE.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\ADOCE.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\App.ico; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\basic.htp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\benchmark.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\checkbox.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\comboBox.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\commandButton.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\CommonDlg.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\CommonDlg.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\dateTime.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Declare2.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Declare.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\file.bmp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\FileBrowse.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\FileBrowse.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\FileIO.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\FileIO.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\folder.bmp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\FullScreen.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\FullScreen.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\GradientButton.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\GradientButton.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Grid.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Grid.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\HelloWorldFormless.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\HelloWorldStandard.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\HTMLview.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\HTMLview.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\clock.gif; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\label.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\ListBox.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\menubar.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\MultiButton.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\nsbasic.htc; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Objects.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\optionButton.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Phone.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Phone.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\QSketch.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\RPNCalc.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\SerialComms.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\SerialComms.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\SMS Send.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\SMS Send.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\SQLite.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\SQLite.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\Symbol.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\TCPClient.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\TCPClient.nsp; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\TCPServer VB6.zip; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\textBox.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\TekLogixScan.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\TwoForms.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\winsock.nsb; DestDir: {userdocs}\NSBasic Samples\CE
Source: ..\Files\Samples\winsock.nsp; DestDir: {userdocs}\NSBasic Samples\CE


[Icons]
Name: {group}\NS Basic CE 8.2; Filename: {app}\NSBasic.exe; IconIndex: 0
Name: {group}\ReadMe; Filename: {app}\ReadMe.htm; IconIndex: 0
Name: {group}\Hello World; Filename: {app}\{userdocs}\NSBasic Samples\CE\HelloWorldStandard.nsb; IconIndex: 0
Name: {group}\Uninstall; Filename: {uninstallexe}; IconIndex: 0
Name: {commondesktop}\NS Basic CE 8.2; Filename: {app}\NSBasic.exe; Tasks: desktopicon; IconIndex: 0

[Run]
Filename: {app}\NSBasic.exe; Description: {cm:LaunchProgram,NS Basic/CE}; Flags: nowait postinstall skipifsilent

[Dirs]
Name: {app}\Controls
Name: {app}\images
Name: {app}\Controls\WM
Name: {app}\Controls\1824
Name: {app}\Controls\2577
Name: {app}\Controls\4000
Name: {app}\Installers
Name: {app}\technotes
Name: {app}\technotes\images
Name: {app}\Lang
Name: {app}\Tools
Name: {userdocs}\NSBasic Samples; Tasks: ; Languages: 
Name: {userdocs}\NSBasic Samples\CE
Name: {userdocs}\NSBasic Samples\CE\DialogX
Name: {userdocs}\NSBasic Samples\CE\NetStreams
Name: {userdocs}\NSBasic Samples\CE\NSBComDlg
Name: {userdocs}\NSBasic Samples\CE\NSBControls
Name: {userdocs}\NSBasic Samples\CE\NSBWin32
Name: {userdocs}\NSBasic Samples\CE\Resources
Name: {userdocs}\NSBasic Samples\CE\SerialTools
Name: {userdocs}\NSBasic Samples\CE\Tutorials

[Registry]
Root: HKCR; SubKey: .nsb; ValueType: string; ValueData: NS Basic/CE; Flags: uninsdeletekey
Root: HKCR; SubKey: NS Basic/CE; ValueType: string; ValueData: program; Flags: uninsdeletekey
Root: HKCR; SubKey: NS Basic/CE\Shell\Open\Command; ValueType: string; ValueData: """{app}\NSBasic.exe"" ""%1"""; Flags: uninsdeletevalue
Root: HKCR; Subkey: NS Basic/CE\DefaultIcon; ValueType: string; ValueData: {app}\NSBasic.exe,-1; Flags: uninsdeletevalue
Root: HKCU; Subkey: Software
Root: HKCU; Subkey: Software\NSBasic
Root: HKCU; Subkey: Software\NSBasic\CE
Root: HKCU; Subkey: Software\NSBasic\CE; ValueType: string; ValueName: InstallDir1; ValueData: {app}
Root: HKCU; Subkey: Software\NSBasic\CE; ValueType: string; ValueName: SamplesDirectory; ValueData: {userdocs}\NSBasic Samples\CE
Root: HKCU; Subkey: Software\NSBasic\CE; ValueType: string; ValueName: ResourceDirectory; ValueData: {app}\Controls\WM
