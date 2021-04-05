; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "VNSB.h"
LastPage=0

ClassCount=15
Class1=CVNSBApp
Class2=CVNSBDoc
Class3=CVNSBView
Class4=CMainFrame
Class5=CAboutDlg

ResourceCount=14
Resource1=IDD_MENU_EDITOR
Class6=CNSBFormObjectView
Resource2=IDD_MENU_ITEM_EDITOR
Class7=CNSBFormNameDlg
Resource3=IDR_MAINFRAME (VNSB_STANDALONE)
Class8=CPropEditorDlg
Class9=CCustomEditor
Resource4=IDD_PROPERTY_EDITOR (_WIN32_WCE_300)
Class10=CSelectObjectDlg
Resource5=IDD_PROPERTY_EDITOR (VERSION_211)
Class11=CMenuEditorDlg
Resource6=IDD_FORMNAME
Class12=CMenuItemEditorDlg
Resource7=IDD_SHOW_CODE
Resource8=IDD_ABOUTBOX
Class13=CCodeDlg
Resource9=IDR_MAINFRAME
Resource10=IDD_PROPERTY_EDITOR (_WIN32_WCE_211)
Resource11=IDD_PROPERTY_EDITOR
Resource12=IDD_PREFS
Class14=CPrefsDlg
Resource13=IDD_SELECT_OBJECT
Class15=CComObjectDlg
Resource14=IDD_COMOBJECTS

[CLS:CVNSBApp]
Type=0
HeaderFile=VNSB.h
ImplementationFile=VNSB.cpp
Filter=N
LastObject=CVNSBApp

[CLS:CVNSBDoc]
Type=0
HeaderFile=VNSBDoc.h
ImplementationFile=VNSBDoc.cpp
Filter=T
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_OBJECTS_SHOWCODE

[CLS:CVNSBView]
Type=0
HeaderFile=VNSBView.h
ImplementationFile=VNSBView.cpp
Filter=C
LastObject=CVNSBView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=VNSB.cpp
ImplementationFile=VNSB.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308353
Control2=IDC_STATIC,static,1342308353
Control3=IDC_STATIC,static,1342177283
Control4=IDC_ABOUT_VERSION,static,1342308481

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FORM_ADD
Command2=ID_FORM_DELETE
Command3=ID_FORM_SETDEFAULT
Command4=ID_FORM_EXIT
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_CLEAR
Command9=ID_EDIT_SELECT_OBJECT
Command10=ID_EDIT_PROPERTIES
Command11=ID_EDIT_PREFS
Command12=ID_FORM_MENU
Command13=ID_OBJECTS_SHOWCODE
Command14=ID_HELP
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_CLEAR
Command2=ID_EDIT_COPY
Command3=ID_FORM_ADD
Command4=ID_EDIT_SELECT_OBJECT
Command5=ID_FORM_MENU
Command6=ID_FILE_NEW
Command7=ID_FILE_OPEN
Command8=ID_EDIT_PROPERTIES
Command9=ID_FILE_SAVE
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_EDIT_CUT
Command18=ID_EDIT_UNDO
CommandCount=18

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_APP_EXIT
CommandCount=7

[CLS:CNSBFormObjectView]
Type=0
HeaderFile=NSBFormObjectView.h
ImplementationFile=NSBFormObjectView.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC
LastObject=CNSBFormObjectView

[DLG:IDD_FORMNAME]
Type=1
Class=CNSBFormNameDlg
ControlCount=1
Control1=IDC_FORMNAME,edit,1350631552

[CLS:CNSBFormNameDlg]
Type=0
HeaderFile=VNSBDlg.h
ImplementationFile=VNSBDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNSBFormNameDlg

[DLG:IDD_PROPERTY_EDITOR]
Type=1
Class=CPropEditorDlg
ControlCount=9
Control1=IDC_PROPERTIES,combobox,1344340227
Control2=IDC_EDITSINGLE,edit,1082196096
Control3=IDC_LIST,combobox,1075904771
Control4=IDC_NUMBER,edit,1082204288
Control5=IDC_EDITMULTI,edit,1084297412
Control6=IDC_EDITLIST,combobox,1075904514
Control7=IDC_CHOOSE,button,1073807360
Control8=IDC_APPLY,button,1073807360
Control9=IDC_OBJECT_NAME,edit,1350631552

[CLS:CPropEditorDlg]
Type=0
HeaderFile=PropEditorDlg.h
ImplementationFile=PropEditorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPropEditorDlg
VirtualFilter=dWC

[CLS:CCustomEditor]
Type=0
HeaderFile=CustomEditor.h
ImplementationFile=CustomEditor.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CCustomEditor

[DLG:IDD_SELECT_OBJECT]
Type=1
Class=CSelectObjectDlg
ControlCount=1
Control1=IDC_OBJECT_LIST,listbox,1352730883

[CLS:CSelectObjectDlg]
Type=0
HeaderFile=SelectObjectDlg.h
ImplementationFile=SelectObjectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSelectObjectDlg
VirtualFilter=dWC

[DLG:IDD_MENU_EDITOR]
Type=1
Class=CMenuEditorDlg
ControlCount=4
Control1=IDC_MENU_TREE,SysTreeView32,1350631487
Control2=IDC_ADDMENUITEM,button,1342242816
Control3=IDC_ADDSUBMENUITEM,button,1342242816
Control4=IDC_DELETEMENUITEM,button,1342242816

[CLS:CMenuEditorDlg]
Type=0
HeaderFile=MenuEditorDlg.h
ImplementationFile=MenuEditorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMenuEditorDlg
VirtualFilter=dWC

[DLG:IDD_MENU_ITEM_EDITOR]
Type=1
Class=CMenuItemEditorDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CAPTION,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_MENUKEY,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ACCELERATOR,edit,1350631552

[CLS:CMenuItemEditorDlg]
Type=0
HeaderFile=MenuEditorDlg.h
ImplementationFile=MenuEditorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMenuItemEditorDlg
VirtualFilter=dWC

[MNU:IDR_MAINFRAME (VNSB_STANDALONE)]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_CLEAR
Command12=ID_EDIT_SELECT_OBJECT
Command13=ID_EDIT_PROPERTIES
Command14=ID_FORM_MENU
Command15=ID_OBJECTS_SHOWCODE
Command16=ID_OBJECTS_GRID
Command17=ID_GRID_SIZE
Command18=ID_FORM_ADD
Command19=ID_FORM_DELETE
Command20=ID_FORM_SETDEFAULT
Command21=ID_FORM_MENU
Command22=ID_HELP
Command23=ID_APP_ABOUT
CommandCount=23

[DLG:IDD_SHOW_CODE]
Type=1
Class=CCodeDlg
ControlCount=1
Control1=IDC_CODE,edit,1353779396

[CLS:CCodeDlg]
Type=0
HeaderFile=CodeDlg.h
ImplementationFile=CodeDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCodeDlg

[DLG:IDD_PROPERTY_EDITOR (_WIN32_WCE_211)]
Type=1
Class=CPropEditorDlg
ControlCount=11
Control1=IDC_PROPERTIES,combobox,1344340227
Control2=IDC_EDITSINGLE,edit,1082196096
Control3=IDC_LIST,combobox,1075904771
Control4=IDC_NUMBER,edit,1082204288
Control5=IDC_EDITMULTI,edit,1082200196
Control6=IDC_EDITLIST,combobox,1075904770
Control7=IDC_DATE,SysDateTimePick32,1073807364
Control8=IDC_TIME,SysDateTimePick32,1073807369
Control9=IDC_CHOOSE,button,1073807360
Control10=IDC_APPLY,button,1073807360
Control11=IDC_OBJECT_NAME,edit,1350631552

[DLG:IDD_PROPERTY_EDITOR (VERSION_211)]
Type=1
Class=CPropEditorDlg
ControlCount=11
Control1=IDC_PROPERTIES,combobox,1344340227
Control2=IDC_EDITSINGLE,edit,1082196096
Control3=IDC_LIST,combobox,1075904771
Control4=IDC_NUMBER,edit,1082204288
Control5=IDC_EDITMULTI,edit,1082200196
Control6=IDC_EDITLIST,combobox,1075904770
Control7=IDC_DATE,SysDateTimePick32,1073807364
Control8=IDC_TIME,SysDateTimePick32,1073807369
Control9=IDC_CHOOSE,button,1073807360
Control10=IDC_APPLY,button,1073807360
Control11=IDC_OBJECT_NAME,edit,1350631552

[DLG:IDD_PROPERTY_EDITOR (_WIN32_WCE_300)]
Type=1
Class=CPropEditorDlg
ControlCount=11
Control1=IDC_PROPERTIES,combobox,1344340227
Control2=IDC_EDITSINGLE,edit,1082196096
Control3=IDC_LIST,combobox,1075904771
Control4=IDC_NUMBER,edit,1082204288
Control5=IDC_EDITMULTI,edit,1084297412
Control6=IDC_EDITLIST,combobox,1075904514
Control7=IDC_DATE,SysDateTimePick32,1073807364
Control8=IDC_TIME,SysDateTimePick32,1073807369
Control9=IDC_CHOOSE,button,1073807360
Control10=IDC_APPLY,button,1073807360
Control11=IDC_OBJECT_NAME,edit,1350631552

[DLG:IDD_COMOBJECTS]
Type=1
Class=CComObjectDlg
ControlCount=1
Control1=IDC_OBJECTS,listbox,1353777411

[CLS:CComObjectDlg]
Type=0
HeaderFile=ComObjectDlg.h
ImplementationFile=ComObjectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CComObjectDlg
VirtualFilter=dWC

[DLG:IDD_PREFS]
Type=1
Class=CPrefsDlg
ControlCount=5
Control1=IDC_GRIDSNAP,button,1342242819
Control2=IDC_STATIC,static,1342308352
Control3=IDC_GRIDSIZE,edit,1350639744
Control4=IDC_SPIN1,msctls_updown32,1342177334
Control5=IDC_STATIC,button,1342177287

[CLS:CPrefsDlg]
Type=0
HeaderFile=codedlg.h
ImplementationFile=codedlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPrefsDlg

