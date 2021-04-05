; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGridCtrlDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "gridctrldemo.h"
LastPage=0

ClassCount=8
Class1=CGridCtrl
Class2=CGridDropTarget
Class3=CInPlaceEdit
Class4=CTitleTip
Class5=CGridCtrlDemoApp
Class6=CGridCtrlDemoDlg
Class7=CComboEdit
Class8=CInPlaceList

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDD_GRIDCTRLDEMO_DIALOG (English (U.S.))
Resource3=IDD_GRIDCTRLDEMO_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDR_MENU (English (U.S.))
Resource6=IDR_MENU

[CLS:CGridCtrl]
Type=0
BaseClass=CWnd
HeaderFile=GridCtrl_src\GridCtrl.h
ImplementationFile=GridCtrl_src\GridCtrl.cpp
LastObject=CGridCtrl

[CLS:CGridDropTarget]
Type=0
BaseClass=COleDropTarget
HeaderFile=GridCtrl_src\GridDropTarget.h
ImplementationFile=GridCtrl_src\GridDropTarget.cpp

[CLS:CInPlaceEdit]
Type=0
BaseClass=CEdit
HeaderFile=GridCtrl_src\InPlaceEdit.h
ImplementationFile=GridCtrl_src\InPlaceEdit.cpp

[CLS:CTitleTip]
Type=0
BaseClass=CWnd
HeaderFile=GridCtrl_src\TitleTip.h
ImplementationFile=GridCtrl_src\TitleTip.cpp

[CLS:CGridCtrlDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=GridCtrlDemo.h
ImplementationFile=GridCtrlDemo.cpp

[CLS:CGridCtrlDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=GridCtrlDemoDlg.h
ImplementationFile=GridCtrlDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CGridCtrlDemoDlg

[CLS:CComboEdit]
Type=0
BaseClass=CEdit
HeaderFile=NewCellTypes\GridCellCombo.h
ImplementationFile=NewCellTypes\GridCellCombo.cpp
LastObject=CComboEdit

[CLS:CInPlaceList]
Type=0
BaseClass=CComboBox
HeaderFile=NewCellTypes\GridCellCombo.h
ImplementationFile=NewCellTypes\GridCellCombo.cpp
Filter=W
VirtualFilter=cWC
LastObject=CInPlaceList

[DLG:IDD_GRIDCTRLDEMO_DIALOG]
Type=1
Class=CGridCtrlDemoDlg
ControlCount=22
Control1=IDC_GRID,MFCGridCtrl,1342242816
Control2=IDC_CELL_NORMAL,button,1342308361
Control3=IDC_CELL_READONLY,button,1342177289
Control4=IDC_CELL_URL,button,1342177289
Control5=IDC_CELL_COMBO,button,1342177289
Control6=IDC_CELL_CHECK,button,1342177289
Control7=IDC_EDIT_ROWS,edit,1350770816
Control8=IDC_SPIN_ROW,msctls_updown32,1342177334
Control9=IDC_EDIT_COLS,edit,1350639744
Control10=IDC_SPIN_COL,msctls_updown32,1342177334
Control11=IDC_EDIT_FIXROWS,edit,1350639744
Control12=IDC_SPIN_FIXROW,msctls_updown32,1342177334
Control13=IDC_EDIT_FIXCOLS,edit,1350639744
Control14=IDC_SPIN_FIXCOL,msctls_updown32,1342177334
Control15=IDCANCEL,button,1342242816
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_SIZEBOX,scrollbar,1342177308
Control21=IDC_TRACE,edit,1352730820
Control22=IDC_CLEARTRACE,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[MNU:IDR_MENU]
Type=1
Class=CGridCtrlDemoDlg
Command1=IDC_PRINT_BUTTON
Command2=ID_APP_EXIT
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_SELECTALL
Command7=IDC_EDITING_REJECT_ATTEMPT
Command8=IDC_EDITING_REJECT_CHANGE
Command9=IDC_ALLOW_SELECTION
Command10=IDC_FIXEDCOL_SELECTION
Command11=IDC_FIXEDROW_SELECTION
Command12=IDC_SINGLECOLSELMODE
Command13=IDC_FILL
Command14=IDC_AUTO_SIZE
Command15=IDC_EXPAND_LAST
Command16=IDC_EXPAND_TO_FIT
Command17=IDC_EXPAND_USE_FIXED
Command18=IDC_HORZ_LINES
Command19=IDC_VERT_LINES
Command20=IDC_INSERT_ROW
Command21=IDC_DELETE_ROW
Command22=IDC_SET_FOCUS
Command23=IDC_FONT_BUTTON
Command24=IDC_EDITABLE
Command25=IDC_TITLETIPS
Command26=IDC_TRACKFOCUS
Command27=IDC_FRAMEFOCUS
Command28=IDC_HEADERSORT
Command29=IDC_ITALICS
Command30=IDC_VERTICAL_TEXT
Command31=IDC_LISTMODE
Command32=IDC_SINGLESELMODE
Command33=IDC_ROW_RESIZE
Command34=IDC_COL_RESIZE
Command35=IDC_VIRTUAL_MODE
Command36=IDC_CALLBACK_FUNCTION
Command37=ID_APP_ABOUT
CommandCount=37

[MNU:IDR_MENU (English (U.S.))]
Type=1
Class=?
Command1=IDC_PRINT_BUTTON
Command2=ID_APP_EXIT
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_SELECTALL
Command7=IDC_ALLOW_SELECTION
Command8=IDC_FIXEDCOL_SELECTION
Command9=IDC_FIXEDROW_SELECTION
Command10=IDC_SINGLECOLSELMODE
Command11=IDC_FILL
Command12=IDC_AUTO_SIZE
Command13=IDC_EXPAND_LAST
Command14=IDC_EXPAND_TO_FIT
Command15=IDC_EXPAND_USE_FIXED
Command16=IDC_HORZ_LINES
Command17=IDC_VERT_LINES
Command18=IDC_INSERT_ROW
Command19=IDC_DELETE_ROW
Command20=IDC_SET_FOCUS
Command21=IDC_FONT_BUTTON
Command22=IDC_EDITABLE
Command23=IDC_TITLETIPS
Command24=IDC_TRACKFOCUS
Command25=IDC_FRAMEFOCUS
Command26=IDC_HEADERSORT
Command27=IDC_ITALICS
Command28=IDC_VERTICAL_TEXT
Command29=IDC_LISTMODE
Command30=IDC_SINGLESELMODE
Command31=IDC_ROW_RESIZE
Command32=IDC_COL_RESIZE
Command33=IDC_VIRTUAL_MODE
Command34=IDC_CALLBACK_FUNCTION
Command35=ID_APP_ABOUT
CommandCount=35

[DLG:IDD_GRIDCTRLDEMO_DIALOG (English (U.S.))]
Type=1
Class=CGridCtrlDemoDlg
ControlCount=19
Control1=IDC_GRID,MFCGridCtrl,1342242816
Control2=IDC_CELL_NORMAL,button,1342308361
Control3=IDC_CELL_READONLY,button,1342177289
Control4=IDC_CELL_URL,button,1342177289
Control5=IDC_CELL_COMBO,button,1342177289
Control6=IDC_EDIT_ROWS,edit,1350639744
Control7=IDC_SPIN_ROW,msctls_updown32,1342177334
Control8=IDC_EDIT_COLS,edit,1350639744
Control9=IDC_SPIN_COL,msctls_updown32,1342177334
Control10=IDC_EDIT_FIXROWS,edit,1350639744
Control11=IDC_SPIN_FIXROW,msctls_updown32,1342177334
Control12=IDC_EDIT_FIXCOLS,edit,1350639744
Control13=IDC_SPIN_FIXCOL,msctls_updown32,1342177334
Control14=IDCANCEL,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_SIZEBOX,scrollbar,1342177308

[DLG:IDD_ABOUTBOX]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

