VERSION 5.00
Object = "{BCA00000-0F85-414C-A938-5526E9F1E56A}#4.0#0"; "cmax40.dll"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Object = "{6FBA474E-43AC-11CE-9A0E-00AA0062BB4C}#1.0#0"; "sysinfo.ocx"
Begin VB.MDIForm frmMain 
   AutoShowChildren=   0   'False
   BackColor       =   &H8000000C&
   Caption         =   "1401[NS Basic/CE]"
   ClientHeight    =   8310
   ClientLeft      =   225
   ClientTop       =   855
   ClientWidth     =   11880
   Icon            =   "frmMain.frx":0000
   LinkTopic       =   "MDIForm1"
   StartUpPosition =   3  'Windows Default
   Tag             =   "1401"
   Begin SysInfoLib.SysInfo SysInfo 
      Left            =   1560
      Top             =   1080
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
   End
   Begin VB.PictureBox picBox 
      Align           =   1  'Align Top
      Height          =   615
      Left            =   0
      ScaleHeight     =   555
      ScaleWidth      =   11820
      TabIndex        =   8
      Top             =   360
      Visible         =   0   'False
      Width           =   11880
      Begin CodeMax4Ctl.CodeMax cmaxFind 
         Height          =   495
         Left            =   1080
         OleObjectBlob   =   "frmMain.frx":8D62
         TabIndex        =   9
         Top             =   0
         Width           =   855
      End
   End
   Begin VB.Timer tmrStatus 
      Enabled         =   0   'False
      Interval        =   3000
      Left            =   2760
      Top             =   1080
   End
   Begin VB.PictureBox picToolbox 
      Align           =   3  'Align Left
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   7065
      Left            =   0
      ScaleHeight     =   7065
      ScaleWidth      =   840
      TabIndex        =   7
      Top             =   975
      Width           =   840
   End
   Begin VB.PictureBox picPanel 
      Align           =   4  'Align Right
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   7065
      Left            =   8400
      ScaleHeight     =   7065
      ScaleWidth      =   3480
      TabIndex        =   2
      Top             =   975
      Visible         =   0   'False
      Width           =   3480
      Begin VB.PictureBox picProperties 
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   855
         Left            =   240
         ScaleHeight     =   855
         ScaleWidth      =   495
         TabIndex        =   6
         Top             =   3120
         Visible         =   0   'False
         Width           =   495
      End
      Begin VB.PictureBox picProjectExplorer 
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   855
         Left            =   240
         ScaleHeight     =   855
         ScaleWidth      =   495
         TabIndex        =   5
         Top             =   1920
         Visible         =   0   'False
         Width           =   495
      End
      Begin VB.PictureBox picSplit 
         Appearance      =   0  'Flat
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   135
         Left            =   240
         MouseIcon       =   "frmMain.frx":8E52
         MousePointer    =   99  'Custom
         ScaleHeight     =   135
         ScaleWidth      =   495
         TabIndex        =   4
         Top             =   2880
         Visible         =   0   'False
         Width           =   495
      End
      Begin VB.PictureBox picWidth 
         Appearance      =   0  'Flat
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   2055
         Left            =   0
         MouseIcon       =   "frmMain.frx":9064
         MousePointer    =   99  'Custom
         ScaleHeight     =   2055
         ScaleWidth      =   135
         TabIndex        =   3
         Top             =   1920
         Width           =   135
      End
   End
   Begin MSComDlg.CommonDialog dlgCommonDialog 
      Left            =   2160
      Top             =   1080
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      FontName        =   "Tahoma"
   End
   Begin MSComctlLib.StatusBar sbStatusBar 
      Align           =   2  'Align Bottom
      Height          =   270
      Left            =   0
      TabIndex        =   0
      Top             =   8040
      Width           =   11880
      _ExtentX        =   20955
      _ExtentY        =   476
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   5
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            AutoSize        =   1
            Object.Width           =   10160
            Text            =   "Status"
            TextSave        =   "Status"
         EndProperty
         BeginProperty Panel2 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Coordinates"
         EndProperty
         BeginProperty Panel3 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Dimensions"
         EndProperty
         BeginProperty Panel4 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            Style           =   6
            TextSave        =   "3/27/2012"
         EndProperty
         BeginProperty Panel5 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            Style           =   5
            AutoSize        =   2
            TextSave        =   "7:54 AM"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tbToolBar 
      Align           =   1  'Align Top
      Height          =   360
      Left            =   0
      TabIndex        =   1
      Top             =   0
      Width           =   11880
      _ExtentX        =   20955
      _ExtentY        =   635
      ButtonWidth     =   609
      ButtonHeight    =   582
      Appearance      =   1
      Style           =   1
      ImageList       =   "imlToolbarIcons"
      DisabledImageList=   "imlDisabledToolbarIcons"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628} 
         NumButtons      =   24
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "New"
            Object.ToolTipText     =   "1087"
            ImageIndex      =   1
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Open"
            Object.ToolTipText     =   "1088"
            ImageIndex      =   2
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Save"
            Object.ToolTipText     =   "1089"
            ImageIndex      =   3
         EndProperty
         BeginProperty Button4 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button5 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Print"
            Object.ToolTipText     =   "1090"
            ImageIndex      =   4
         EndProperty
         BeginProperty Button6 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button7 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Undo"
            Object.ToolTipText     =   "1091"
            ImageIndex      =   5
         EndProperty
         BeginProperty Button8 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Redo"
            Object.ToolTipText     =   "1092"
            ImageIndex      =   6
         EndProperty
         BeginProperty Button9 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button10 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Cut"
            Object.ToolTipText     =   "1093"
            ImageIndex      =   7
         EndProperty
         BeginProperty Button11 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Copy"
            Object.ToolTipText     =   "1094"
            ImageIndex      =   8
         EndProperty
         BeginProperty Button12 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Paste"
            Object.ToolTipText     =   "1095"
            ImageIndex      =   9
         EndProperty
         BeginProperty Button13 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Delete"
            Object.ToolTipText     =   "1096"
            ImageIndex      =   10
         EndProperty
         BeginProperty Button14 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button15 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Find"
            Object.ToolTipText     =   "1097"
            ImageIndex      =   11
         EndProperty
         BeginProperty Button16 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button17 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Add Form"
            Object.ToolTipText     =   "1098"
            ImageIndex      =   12
         EndProperty
         BeginProperty Button18 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Add Bitmap"
            Object.ToolTipText     =   "1099"
            ImageIndex      =   13
         EndProperty
         BeginProperty Button19 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Add Module"
            Object.ToolTipText     =   "1100"
            ImageIndex      =   14
         EndProperty
         BeginProperty Button20 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button21 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Compile"
            Object.ToolTipText     =   "3370"
            ImageIndex      =   15
         EndProperty
         BeginProperty Button22 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Style           =   3
         EndProperty
         BeginProperty Button23 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Properties"
            Object.ToolTipText     =   "1102"
            ImageIndex      =   16
         EndProperty
         BeginProperty Button24 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Menu Editor"
            Object.ToolTipText     =   "1103"
            ImageIndex      =   17
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList ilsIcons32 
      Left            =   960
      Top             =   2280
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   16776960
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   5
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":9276
            Key             =   "PRJ"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":9EC8
            Key             =   "nul"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":FAEA
            Key             =   "std"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1570C
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1B32E
            Key             =   "TEXT"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList ilsIcons16 
      Left            =   960
      Top             =   2880
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   16776960
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   2
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1BF80
            Key             =   "PRJ"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1C2D2
            Key             =   "TEXT"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList imlToolbarIcons 
      Left            =   960
      Top             =   1080
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483633
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   17
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1C624
            Key             =   "New"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1C976
            Key             =   "Open"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1CCC8
            Key             =   "Save"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1D01A
            Key             =   "Print"
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1D36C
            Key             =   "Undo"
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1D6BE
            Key             =   "Redo"
         EndProperty
         BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1DA10
            Key             =   "Cut"
         EndProperty
         BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1DD62
            Key             =   "Copy"
         EndProperty
         BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1E0B4
            Key             =   "Paste"
         EndProperty
         BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1E406
            Key             =   "Delete"
         EndProperty
         BeginProperty ListImage11 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1E758
            Key             =   "Find"
         EndProperty
         BeginProperty ListImage12 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1EAAA
            Key             =   "Form"
         EndProperty
         BeginProperty ListImage13 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1EDFC
            Key             =   "Bitmap"
         EndProperty
         BeginProperty ListImage14 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1F14E
            Key             =   "Module"
         EndProperty
         BeginProperty ListImage15 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1F4A0
            Key             =   "Compile"
         EndProperty
         BeginProperty ListImage16 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1F7F2
            Key             =   "Properties"
         EndProperty
         BeginProperty ListImage17 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1FB44
            Key             =   "MenuEditor"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList imlDisabledToolbarIcons 
      Left            =   960
      Top             =   1680
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483633
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   17
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":1FE96
            Key             =   "New"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":201E8
            Key             =   "Open"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":2053A
            Key             =   "Save"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":2088C
            Key             =   "Print"
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":20BDE
            Key             =   "Undo"
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":20F30
            Key             =   "Redo"
         EndProperty
         BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":21282
            Key             =   "Cut"
         EndProperty
         BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":215D4
            Key             =   "Copy"
         EndProperty
         BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":21926
            Key             =   "Paste"
         EndProperty
         BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":21C78
            Key             =   "Delete"
         EndProperty
         BeginProperty ListImage11 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":21FCA
            Key             =   "Find"
         EndProperty
         BeginProperty ListImage12 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":2231C
            Key             =   "Form"
         EndProperty
         BeginProperty ListImage13 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":2266E
            Key             =   "Bitmap"
         EndProperty
         BeginProperty ListImage14 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":229C0
            Key             =   "Module"
         EndProperty
         BeginProperty ListImage15 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":22D12
            Key             =   "Compile"
         EndProperty
         BeginProperty ListImage16 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":23064
            Key             =   "Properties"
         EndProperty
         BeginProperty ListImage17 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmMain.frx":233B6
            Key             =   "MenuEditor"
         EndProperty
      EndProperty
   End
   Begin VB.Menu mnuFile 
      Caption         =   "1000"
      Begin VB.Menu mnuFileNewProject 
         Caption         =   "1001"
         Shortcut        =   ^N
      End
      Begin VB.Menu mnuFileOpenProject 
         Caption         =   "1002"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuFileOpenSample 
         Caption         =   "3490"
      End
      Begin VB.Menu mnuFileBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFileSaveProject 
         Caption         =   "1003"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuFileSaveProjectAs 
         Caption         =   "1004"
      End
      Begin VB.Menu mnuFileBar2 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFilePageSetup 
         Caption         =   "1008"
      End
      Begin VB.Menu mnuFilePrint 
         Caption         =   "1009"
      End
      Begin VB.Menu mnuFileBar4 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFileMRU 
         Caption         =   ""
         Index           =   1
      End
      Begin VB.Menu mnuFileMRU 
         Caption         =   ""
         Index           =   2
      End
      Begin VB.Menu mnuFileMRU 
         Caption         =   ""
         Index           =   3
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFileMRU 
         Caption         =   ""
         Index           =   4
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFileBar6 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFileExit 
         Caption         =   "1010"
      End
   End
   Begin VB.Menu mnuEdit 
      Caption         =   "1011"
      Begin VB.Menu mnuEditUndo 
         Caption         =   "1012"
         Shortcut        =   ^Z
      End
      Begin VB.Menu mnuEditRedo 
         Caption         =   "1013"
         Shortcut        =   ^Y
      End
      Begin VB.Menu mnuEditBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuEditCut 
         Caption         =   "1014"
         Shortcut        =   ^X
      End
      Begin VB.Menu mnuEditCopy 
         Caption         =   "1015"
         Shortcut        =   ^C
      End
      Begin VB.Menu mnuEditPaste 
         Caption         =   "1016"
         Shortcut        =   ^V
      End
      Begin VB.Menu mnuEditDelete 
         Caption         =   "1017"
      End
      Begin VB.Menu mnuEditSelectAll 
         Caption         =   "1018"
         Shortcut        =   ^A
      End
      Begin VB.Menu mnuEditBar1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuEditFind 
         Caption         =   "1019"
         Shortcut        =   ^F
      End
      Begin VB.Menu mnuEditFindNext 
         Caption         =   "1020"
         Shortcut        =   {F3}
         Visible         =   0   'False
      End
      Begin VB.Menu mnuEditReplace 
         Caption         =   "1021"
         Shortcut        =   ^H
      End
      Begin VB.Menu mnuEditGoTo 
         Caption         =   "1022"
         Shortcut        =   ^T
      End
      Begin VB.Menu editSep3 
         Caption         =   "-"
         Visible         =   0   'False
      End
      Begin VB.Menu mnuEditPreferences 
         Caption         =   "1218"
         Visible         =   0   'False
      End
   End
   Begin VB.Menu mnuView 
      Caption         =   "1023"
      Begin VB.Menu mnuViewProjectExplorer 
         Caption         =   "1118"
         Shortcut        =   ^R
      End
      Begin VB.Menu mnuViewProperties 
         Caption         =   "1077"
         Shortcut        =   {F4}
      End
      Begin VB.Menu mnuViewToolbox 
         Caption         =   "1076"
         Shortcut        =   ^B
      End
      Begin VB.Menu mnuViewBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuViewToolbar 
         Caption         =   "1024"
         Checked         =   -1  'True
      End
      Begin VB.Menu mnuViewStatusBar 
         Caption         =   "1025"
         Checked         =   -1  'True
      End
      Begin VB.Menu mnuViewBar1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuViewRefresh 
         Caption         =   "1026"
      End
   End
   Begin VB.Menu mnuProject 
      Caption         =   "1027"
      Begin VB.Menu mnuProjectAddForm 
         Caption         =   "1028"
      End
      Begin VB.Menu mnuProjectAddMenu 
         Caption         =   "1029"
      End
      Begin VB.Menu mnuProjectAddBitmap 
         Caption         =   "1030"
      End
      Begin VB.Menu mnuProjectAddNewModule 
         Caption         =   "1516"
      End
      Begin VB.Menu mnuProjectAddExistingModule 
         Caption         =   "1517"
      End
      Begin VB.Menu mnuProjectAddResourceFile 
         Caption         =   "1521"
      End
      Begin VB.Menu mnuProjectBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuProjectStartupCode 
         Caption         =   "1031"
      End
      Begin VB.Menu mnuProjectTerminationCode 
         Caption         =   "1032"
      End
      Begin VB.Menu mnuProjectHelpCode 
         Caption         =   "1033"
         Visible         =   0   'False
         Begin VB.Menu mnuProjectSetTargetList 
            Caption         =   ""
            Index           =   0
         End
      End
   End
   Begin VB.Menu mnuFormat 
      Caption         =   "1040"
      Begin VB.Menu mnuFormatAlign 
         Caption         =   "1041"
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1042"
            Index           =   0
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1043"
            Index           =   1
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1044"
            Index           =   2
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "-"
            Index           =   3
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1045"
            Index           =   4
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1046"
            Index           =   5
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1047"
            Index           =   6
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "-"
            Index           =   7
         End
         Begin VB.Menu mnuFormatAlignItem 
            Caption         =   "1048"
            Index           =   8
         End
      End
      Begin VB.Menu mnuFormatMakeSameSize 
         Caption         =   "1049"
         Begin VB.Menu mnuFormatMakeSameSizeItem 
            Caption         =   "1050"
            Index           =   0
         End
         Begin VB.Menu mnuFormatMakeSameSizeItem 
            Caption         =   "1051"
            Index           =   1
         End
         Begin VB.Menu mnuFormatMakeSameSizeItem 
            Caption         =   "1052"
            Index           =   2
         End
      End
      Begin VB.Menu mnuFormatBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFormatSizeToGrid 
         Caption         =   "1053"
      End
      Begin VB.Menu mnuFormatBar1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFormatHorizontalSpacing 
         Caption         =   "1054"
         Begin VB.Menu mnuFormatHorizontalSpacingItem 
            Caption         =   "1055"
            Index           =   0
         End
         Begin VB.Menu mnuFormatHorizontalSpacingItem 
            Caption         =   "1056"
            Index           =   1
         End
         Begin VB.Menu mnuFormatHorizontalSpacingItem 
            Caption         =   "1057"
            Index           =   2
         End
         Begin VB.Menu mnuFormatHorizontalSpacingItem 
            Caption         =   "1058"
            Index           =   3
         End
      End
      Begin VB.Menu mnuFormatVerticalSpacing 
         Caption         =   "1059"
         Begin VB.Menu mnuFormatVerticalSpacingItem 
            Caption         =   "1055"
            Index           =   0
         End
         Begin VB.Menu mnuFormatVerticalSpacingItem 
            Caption         =   "1056"
            Index           =   1
         End
         Begin VB.Menu mnuFormatVerticalSpacingItem 
            Caption         =   "1057"
            Index           =   2
         End
         Begin VB.Menu mnuFormatVerticalSpacingItem 
            Caption         =   "1058"
            Index           =   3
         End
      End
      Begin VB.Menu mnuFormatBar2 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFormatCenter 
         Caption         =   "1064"
         Begin VB.Menu mnuFormatCenterItem 
            Caption         =   "1065"
            Index           =   0
         End
         Begin VB.Menu mnuFormatCenterItem 
            Caption         =   "1066"
            Index           =   1
         End
      End
      Begin VB.Menu mnuFormatBar3 
         Caption         =   "-"
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFormatOrder 
         Caption         =   "1067"
         Visible         =   0   'False
         Begin VB.Menu mnuFormatOrderItem 
            Caption         =   "1068"
            Index           =   0
         End
         Begin VB.Menu mnuFormatOrderItem 
            Caption         =   "1069"
            Index           =   1
         End
         Begin VB.Menu mnuFormatOrderItem 
            Caption         =   "1070"
            Index           =   2
         End
         Begin VB.Menu mnuFormatOrderItem 
            Caption         =   "1071"
            Index           =   3
         End
      End
   End
   Begin VB.Menu mnuRunCE 
      Caption         =   "1215"
      Begin VB.Menu mnuRunCEStart 
         Caption         =   "3370"
         Shortcut        =   {F5}
      End
      Begin VB.Menu mnuRunUpdateAppOnDevice 
         Caption         =   "3372"
         Shortcut        =   {F6}
      End
      Begin VB.Menu mnuRunCEBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuRunInstallDeviceIDE 
         Caption         =   "3373"
      End
      Begin VB.Menu mnuRunExtraInstallers 
         Caption         =   "3374"
      End
   End
   Begin VB.Menu mnuTools 
      Caption         =   "1072"
      Begin VB.Menu mnuToolsMenuEditor 
         Caption         =   "1073"
         Shortcut        =   ^E
      End
      Begin VB.Menu mnuToolsActiveX 
         Caption         =   "3446"
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   1
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   2
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   3
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   4
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   5
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   6
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   7
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   8
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   9
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   10
      End
      Begin VB.Menu mnuToolsList 
         Caption         =   ""
         Index           =   11
      End
      Begin VB.Menu mnuToolsBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuToolsOptions 
         Caption         =   "1074"
      End
      Begin VB.Menu mnuToolsBar1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuRunStartVirtualCE 
         Caption         =   "3436"
      End
   End
   Begin VB.Menu mnuWindow 
      Caption         =   "1075"
      Begin VB.Menu mnuWindowCascade 
         Caption         =   "1078"
      End
      Begin VB.Menu mnuWindowTileHorizontal 
         Caption         =   "1079"
      End
      Begin VB.Menu mnuWindowTileVertical 
         Caption         =   "1080"
      End
      Begin VB.Menu mnuWindowBar1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuWindowList 
         Caption         =   ""
         Index           =   0
      End
      Begin VB.Menu mnuWindowWindows 
         Caption         =   "1081"
         Visible         =   0   'False
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "1082"
      Begin VB.Menu mnuHelpReadMe 
         Caption         =   "3473"
      End
      Begin VB.Menu mnuHelpTopics 
         Caption         =   "1084"
      End
      Begin VB.Menu mnuHelpHandbook 
         Caption         =   "3501"
      End
      Begin VB.Menu mnuHelpRegister 
         Caption         =   "1083"
      End
      Begin VB.Menu mnuHelpWWW 
         Caption         =   "1085"
      End
      Begin VB.Menu mnuHelpPalmCreatorID 
         Caption         =   "1119"
      End
      Begin VB.Menu mnuHelpPOSE 
         Caption         =   "1305"
      End
      Begin VB.Menu mnuHelpTechNotes 
         Caption         =   "3352"
      End
      Begin VB.Menu mnuHelpTutorials 
         Caption         =   "3489"
      End
      Begin VB.Menu mnuHelpBigRedToolbox 
         Caption         =   "1305"
      End
      Begin VB.Menu mnuHelpBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuHelpAbout 
         Caption         =   "1086"
      End
   End
   Begin VB.Menu mnuRight 
      Caption         =   "Right-Click Menu"
      Visible         =   0   'False
      Begin VB.Menu mnuRightItem 
         Caption         =   "1500"
         Index           =   0
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1501"
         Index           =   1
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1502"
         Index           =   3
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1503"
         Index           =   4
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   5
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1504"
         Index           =   6
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1505"
         Index           =   7
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1506"
         Index           =   8
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1507"
         Index           =   9
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   10
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1014"
         Index           =   11
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1015"
         Index           =   12
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1016"
         Index           =   13
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1017"
         Index           =   14
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   15
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1508"
         Index           =   16
         Begin VB.Menu mnuRightAddItem 
            Caption         =   "1509"
            Index           =   0
         End
         Begin VB.Menu mnuRightAddItem 
            Caption         =   "1510"
            Index           =   1
         End
         Begin VB.Menu mnuRightAddItem 
            Caption         =   "1511"
            Index           =   2
         End
         Begin VB.Menu mnuRightAddItem 
            Caption         =   "-"
            Index           =   3
         End
         Begin VB.Menu mnuRightAddItem 
            Caption         =   "1512"
            Index           =   4
         End
         Begin VB.Menu mnuRightAddItem 
            Caption         =   "1513"
            Index           =   5
         End
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1028"
         Index           =   17
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1029"
         Index           =   18
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1514"
         Index           =   19
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1515"
         Index           =   20
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1030"
         Index           =   21
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   22
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1516"
         Index           =   23
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1517"
         Index           =   24
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   25
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1518"
         Index           =   26
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1519"
         Index           =   27
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1520"
         Index           =   28
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   29
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1522"
         Index           =   30
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "-"
         Index           =   31
      End
      Begin VB.Menu mnuRightItem 
         Caption         =   "1038"
         Index           =   32
      End
   End
   Begin VB.Menu mnuRightEditCode 
      Caption         =   "Edit menu for right-click in code window"
      Visible         =   0   'False
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1012"
         Index           =   0
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1013"
         Index           =   1
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1014"
         Index           =   3
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1015"
         Index           =   4
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1016"
         Index           =   5
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1017"
         Index           =   6
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1018"
         Index           =   7
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "-"
         Index           =   8
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1019"
         Index           =   9
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1021"
         Index           =   10
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1022"
         Index           =   11
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "-"
         Index           =   12
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1181"
         Index           =   13
         Begin VB.Menu mnuRightEditAdvanced 
            Caption         =   "1182"
            Index           =   0
         End
         Begin VB.Menu mnuRightEditAdvanced 
            Caption         =   "1183"
            Index           =   1
         End
         Begin VB.Menu mnuRightEditAdvanced 
            Caption         =   "1184"
            Index           =   2
         End
         Begin VB.Menu mnuRightEditAdvanced 
            Caption         =   "1185"
            Index           =   3
         End
         Begin VB.Menu mnuRightEditAdvanced 
            Caption         =   "1186"
            Index           =   4
         End
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "-"
         Index           =   14
      End
      Begin VB.Menu mnuRightEdit 
         Caption         =   "1102"
         Index           =   15
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Declare Function SendMessage Lib "USER32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Any) As Long
Private Declare Function OSWinHelp% Lib "USER32" Alias "WinHelpA" (ByVal hWnd&, ByVal helpFile$, ByVal wCommand%, dwData As Any)
Private Declare Function AddFontResource Lib "GDI32" Alias "AddFontResourceA" (ByVal p1 As String) As Long
Private Declare Function RemoveFontResource Lib "GDI32" Alias "RemoveFontResourceA" (ByVal p1 As String) As Long
Const EM_UNDO = &HC7
Const HWND_BROADCAST = &HFFFF
Const WM_FONTCHANGE = 29

Dim gnToolboxTool As Integer
Dim m_bSizing As Boolean
Public Children As New Collection
Public ActiveFormIsCode As Boolean
Private m_nGlobalIDSerial As Integer

Private Function bTestIDE(ByRef bTest As Boolean) As Boolean
   bTest = True
End Function

Public Function bRunningIDE() As Boolean
   ' Return TRUE if program is running in IDE, else FALSE
   Debug.Assert Not bTestIDE(bRunningIDE)
End Function

Private Sub cmaxFind_Change()
   gbFindOne = True
End Sub

Private Sub cmaxFind_FindWrapped(ByVal lCmd As CodeMax4Ctl.cmCommand, ByVal bForward As Boolean)
   If UBound(garrSearchMap) = 0 Then
      'Need to come up with a way to stop infinite looping within a single module
      'cmaxFind_FindWrapped = False
      cmaxFind.CancelEvent
   Else
      'cmaxFind_FindWrapped = True
   End If
End Sub

Private Sub cmaxFind_SelChange()
Dim sel As Range

   Set sel = cmaxFind.GetSel(True)
   If Not sel.IsEmpty Then
      If gnFindFlags And kFindSelected Then
      End If
      gbFindOne = True
      gbFindAny = True
   End If
End Sub

Private Sub MDIForm_Load()
Dim strProj As String
Dim bShowSplash As Boolean
Dim trace As Boolean
Dim n

   trace = False
   
   'Customize the window for CED
   If trace Then MsgBox 1
   mnuEditSelectAll.Visible = False
   mnuProjectAddMenu.Visible = False
   mnuProjectAddBitmap.Visible = False
   'mnuProjectAddExistingModule.Visible = False
   'mnuProjectAddNewModule.Visible = False
   mnuProjectBar0.Visible = False
   mnuProjectStartupCode.Visible = False
   mnuProjectTerminationCode.Visible = False
   mnuFormatAlign.Visible = False
   mnuFormatMakeSameSize.Visible = False
   mnuFormatBar0.Visible = False
   mnuFormatBar1.Visible = False
   mnuFormatHorizontalSpacing.Visible = False
   mnuFormatVerticalSpacing.Visible = False
   mnuHelpPalmCreatorID.Visible = False
   mnuHelpPOSE.Visible = False
   mnuRunStartVirtualCE.Visible = False
   #If NSBasic_Desktop Or NSBasic_X Then
      mnuRunCEBar0.Visible = False
      mnuHelpBigRedToolbox.Visible = False
      mnuRunUpdateAppOnDevice.Visible = False
      mnuRunExtraInstallers.Visible = False
      mnuRunInstallDeviceIDE.Visible = False
   #End If
   tbToolBar.Buttons(18).Visible = False
   tbToolBar.Buttons(19).Visible = False
   Me.Icon = frmIcon.Icon
   Set CERem = New CCERemote  'ghactivesync
   If trace Then MsgBox 2

   If allowRegistration = 0 Then
      Load frmDemoSplash
      frmDemoSplash.Show 1
   End If
   If trace Then MsgBox 3
   
   'LaunchEmulator gbLaunchEmulator
   m_nGlobalIDSerial = 1
   If trace Then MsgBox 4
   
   LoadResStrings Me
   gnToolboxTool = 1
   Me.Left = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "MainLeft", 450)
   Me.Top = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "MainTop", 450)
   Me.Width = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "MainWidth", 12450)
   Me.Height = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "MainHeight", 9450)
   picPanel.Width = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "MainPanel1", picPanel.Width)
   picSplit.Tag = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "MainPanel2", 50)
   If trace Then MsgBox 5
   ShowStatus
   
   gbWinNT2000 = (SysInfo.OSPlatform = 2)
   gbWinNT2000 = True
   If trace Then MsgBox 6
   
   DoEvents
   If trace Then MsgBox 6.1
   gfToolbox.DockWindow
   If trace Then MsgBox 6.2
   gfProjectExplorer.DockWindow
   If trace Then MsgBox 6.3
   gfProperties.DockWindow
   If trace Then MsgBox 7
   
   ParseCommandLine 'Were we started from command line?
   strProj = gCommandLineProject
   If trace Then MsgBox 7.1
   If strProj <> "" Then
      If Right(strProj, 1) = """" Then
         strProj = Mid(strProj, InStr(1, strProj, """") + 1)
         strProj = Left(strProj, Len(strProj) - 1)
      End If
      If trace Then MsgBox 7.2
'      strProj = Mid(strProj, 2, Len(strProj) - 2)
'MsgBox strProj
      'this code seems to help a bug in Vista not happen as often
      Set n = New frmScreen
      DoEvents
      OpenProject strProj
   Else
      If trace Then MsgBox 7.21
      bShowSplash = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ShowSplash", True)
      If bShowSplash Then
         If trace Then MsgBox 7.22
         strProj = ShowNewOpen(True, "Project", "*.nsp")
         Select Case strProj
         Case "std", "nul"
            LoadNewProject strProj
         Case ""
            'this code seems to help a bug in Vista not happen as often
            Set n = New frmScreen
            DoEvents
         Case Else
            OpenProject strProj
            If gTarget Is Nothing Then Exit Sub
            If Right(LCase(gTarget.PathName), 4) = ".txt" Then
               gTarget.PathName = Left(gTarget.PathName, Len(gTarget.PathName) - 4) & kProductExtension 'name should end in .nsb, even if loaded as .txt
            End If
         End Select
      Else
         If trace Then MsgBox "7.23"
         LoadNewProject "std"
      End If
   End If
   If trace Then MsgBox 8
   
   UpdateMRU
   If trace Then MsgBox 9
   
   UpdateTools
   If trace Then MsgBox 10
   
   SetWindowList
   If trace Then MsgBox 11

   'If InStr(LCase(gCommandLineOptions), "-dependancies") Then getDependancies
   If trace Then MsgBox 12
   If InStr(gCommandLineOptions, "-compile") Then CompileImmediately
End Sub

Private Sub LoadNewProject(strTemplate As String)
Dim proj As New CProject
Dim openProj As CProject
Dim i As Integer
Dim strName As String
Dim trace As Boolean

trace = False

   If trace Then MsgBox "LoadNewProject " & 1
   'Ensure project has unique name
   i = 0
   strName = ""
   Do While Len(strName) = 0
      i = i + 1
      strName = "Project" & i
      For Each openProj In gProjects
         If StrComp(openProj.Name, strName, vbTextCompare) = 0 Then
            strName = ""
         End If
      Next
   Loop
   If trace Then MsgBox "LoadNewProject " & 2
   
   'Assign global ID #
   proj.GlobalID = m_nGlobalIDSerial
   m_nGlobalIDSerial = m_nGlobalIDSerial + 1
   proj.Name = strName
   Select Case strTemplate
   Case "nul"
      'Do nothing
   Case "std"
      proj.AddNewForm
   End Select
   If trace Then MsgBox "LoadNewProject " & 3
   
   'Add a main module and open project for business
   gProjectDir = CurDir
   proj.AddNewModule "main"
   If trace Then MsgBox "LoadNewProject " & 3.1
   AddProject proj
   If trace Then MsgBox "LoadNewProject " & 3.2
   #If NSBasic_CE Then
   gTarget.PutScript "ShowOKButton True 'Set Close button to OK" & vbCrLf, ""
   #End If
   If trace Then MsgBox "LoadNewProject " & 4
   
   gbNewFind = True
   DoEvents
   If gbProjectExplorer Then gfProjectExplorer.ShowActive proj
   If trace Then MsgBox "LoadNewProject " & 5
End Sub

Private Sub OpenProject(ByVal strProj As String)
Dim strPath As String
Dim proj As New CProject
Dim openProj As CProject
Dim res As String
Dim trace As Boolean
trace = False

   Screen.MousePointer = vbHourglass
   If trace Then MsgBox "Open Project " & 1

   'Assign global ID #
   proj.GlobalID = m_nGlobalIDSerial
   Set gTarget = proj
   m_nGlobalIDSerial = m_nGlobalIDSerial + 1
   If trace Then MsgBox "Open Project " & 2
   
   If proj.OpenProject(strProj) Then
      If trace Then MsgBox "Open Project " & 3
      'Ensure project has unique name
      gTarget.MakePath = gTarget.PathName
      For Each openProj In gProjects
         If StrComp(openProj.Name, proj.Name, vbTextCompare) = 0 Then
            MsgBox gStringTable(3327) + proj.Name '("A project named " + proj.Name + " is already open"
            Set proj = Nothing
            Screen.MousePointer = vbNormal
            Set gTarget = Nothing
            Exit Sub
         End If
      Next
    
      'Store path from last opened project
      strPath = Left(strProj, InStrRev(strProj, "\") - 1)
      SetRegValue MWinReg.hKey, MWinReg.SubKey, "RecentPath", strPath
   Else
      If trace Then MsgBox "Open Project " & 4
      Select Case proj.NSB_FileFormat
      Case nsbFFSealed: MsgBox gStringTable(3382) '"Invalid Serial Number used on Encrypted File"
      Case nsbFFError: MsgBox gStringTable(3328) + strProj '"Error opening project file '" + strProj + "'"
      Case nsbFFUnopened: MsgBox gStringTable(3383) & " " & strProj '"File not found or Serial number not entered."
      End Select
      Set gTarget = Nothing
      Set proj = Nothing
      Screen.MousePointer = vbNormal
      Exit Sub
   End If
   If trace Then MsgBox "Open Project " & 5
   AddProject proj
   If trace Then MsgBox "Open Project " & 6
   UpdateRecent proj.PathName
    If trace Then MsgBox "Open Project " & 6.1
  
   gbNewFind = True
   If trace Then MsgBox "Open Project " & 6.2
   DoEvents
   If trace Then MsgBox "Open Project " & 6.3
   If gbProjectExplorer Then gfProjectExplorer.ShowActive proj
   If trace Then MsgBox "Open Project " & 6.4
   proj.Dirty = False
   If trace Then MsgBox "Open Project " & 6.5
   Screen.MousePointer = vbNormal
   If trace Then MsgBox "Open Project " & 9

End Sub

Private Sub AddProject(proj As CProject)
Dim frm As CForm, frmX As CForm
Dim fScreen As New frmScreen
Dim itm
Dim trace As Boolean

trace = False

   If trace Then MsgBox "AddProject " & 1
   gProjects.Add proj, proj.GlobalID
   Set gTarget = proj

   'Pick a form to open, the default form or the first form
   Set frm = proj.GetDefaultForm
   If trace Then MsgBox "AddProject " & 2

   gfProjectExplorer.DisplayExplorer
   UpdateProjectList
   If trace Then MsgBox "AddProject " & 3

   If Not frm Is Nothing Then
      If trace Then MsgBox "AddProject " & 3.1
      fScreen.Object = frm
      fScreen.Move 0, 0
      fScreen.Show
      AddMDIChild fScreen
   Else
      'Show code window here
      If trace Then MsgBox "AddProject " & 3.2
      ViewCode proj.GlobalID
   End If
   If trace Then MsgBox "AddProject " & 4
End Sub

Public Function RemoveProject(ByVal proj As CProject) As Boolean
Dim frm As Form
Dim obj As Object
Dim nAction As Integer
Dim fCode As frmCode
Dim bDirty As Boolean

   'If nothing is open, remove is already successful
   If proj Is Nothing Then
      RemoveProject = True
      Exit Function
   End If

   'Find out if project is dirty
   bDirty = proj.Dirty
   If Not bDirty Then
      For Each frm In Children
         If proj Is LocateProject(frm.GlobalID) Then
            If frm.Dirty Then
               bDirty = True
               Exit For
            End If
         End If
      Next
   End If

   If bDirty Then
      nAction = MsgBox(gStringTable(3329) & proj.Name & "?", vbYesNoCancel) 'save
      If nAction = vbCancel Then Exit Function
   End If
   RemoveProject = True

   'Close all project windows
   For Each frm In Children
      If proj Is LocateProject(frm.GlobalID) Then
         Unload frm
      End If
   Next
   
   If nAction = vbYes Then SaveProject proj

   'Remove from Project Explorer
   gfProjectExplorer.RemoveNode proj.GlobalID

   'Clear Properties Window
   If gbProperties Then gfProperties.Object = Nothing

   gProjects.Remove proj.GlobalID
   If gProjects.Count > 0 Then
      Set gTarget = gProjects(1)
   Else
      Set gTarget = Nothing
   End If
   UpdateProjectList
End Function

Private Sub MDIForm_QueryUnload(Cancel As Integer, UnloadMode As Integer)
Dim proj As CProject

   For Each proj In gProjects
      If proj.Dirty Then
         Select Case MsgBox(gStringTable(3329) & proj.Name & "?", vbYesNoCancel)
         Case vbYes:
            PutTheCodeBack
            SaveProject proj
         Case vbNo
         Case vbCancel
            Cancel = 1
            Exit For
         End Select
      End If
   Next
End Sub

Private Sub MDIForm_Unload(Cancel As Integer)
Dim fontDir As String
Dim lParam As Long
Dim i As Integer

'   If gIDEID <> 0 Then RegValueDelete HKEY_CURRENT_USER, "Software\NSBasic\CE", (gIDEID)
'   If Not dlgCommonDialog Is Nothing Then Unload dlgCommonDialog
   If Me.WindowState = vbNormal Then
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "MainLeft", Me.Left
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "MainTop", Me.Top
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "MainWidth", Me.Width
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "MainHeight", Me.Height
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "MainPanel1", picPanel.Width
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "MainPanel2", picSplit.Tag
   End If
   Unload frmIcon
   'If gEmCEID <> 0 Then RegValueDelete MWinReg.hKey, MWinReg.SubKey, (gIDEID)
End Sub

Private Sub mnuEdit_Click()
Dim fCode As frmCode

   If ActiveForm Is Nothing Then
      mnuEditUndo.Enabled = False
      mnuEditRedo.Enabled = False
      mnuEditCut.Enabled = False
      mnuEditCopy.Enabled = False
      mnuEditPaste.Enabled = False
      mnuEditDelete.Enabled = False
      mnuEditSelectAll.Enabled = False
      mnuEditGoTo.Enabled = False
   Else
      Select Case TypeName(ActiveForm)
      Case "frmScreen"
         mnuEditUndo.Enabled = False
         mnuEditRedo.Enabled = False
         mnuEditCut.Enabled = ActiveForm.Selection.Count > 0
         mnuEditCopy.Enabled = True
         mnuEditPaste.Enabled = ActiveForm.ValidPaste
         mnuEditDelete.Enabled = ActiveForm.Selection.Count > 0
         mnuEditSelectAll.Enabled = True
         mnuEditGoTo.Enabled = False
      Case "frmCode"
         Set fCode = ActiveForm
         mnuEditUndo.Enabled = fCode.CanUndo
         mnuEditRedo.Enabled = fCode.CanRedo
         mnuEditCut.Enabled = fCode.CanCut
         mnuEditCopy.Enabled = fCode.CanCopy
         mnuEditPaste.Enabled = ActiveForm.ValidPaste
         mnuEditDelete.Enabled = fCode.CanCopy
         mnuEditSelectAll.Enabled = True
         mnuEditGoTo.Enabled = True
      End Select
   End If
   mnuEditFind.Enabled = (Not gTarget Is Nothing)
   mnuEditFindNext.Enabled = (Not gTarget Is Nothing)
   mnuEditReplace.Enabled = (Not gTarget Is Nothing)
End Sub

Private Sub mnuEditDelete_Click()
   If ActiveForm Is Nothing Then Exit Sub
   Select Case TypeName(ActiveForm)
   Case "frmScreen", "frmCode": ActiveForm.Delete
   End Select
End Sub

Private Sub mnuEditFind_Click()
   If ActiveForm Is Nothing Then Exit Sub
   PutTheCodeBack
   frmFind.Form = ActiveForm
   frmFind.FindReplace = False
   frmFind.Show 'not vbModal
   SetTopmostWindow frmFind.hWnd
   'ActiveForm.Show
End Sub

Private Sub mnuEditGoTo_Click()
   If ActiveForm Is Nothing Then Exit Sub
   If TypeName(ActiveForm) <> "frmCode" Then Exit Sub
   ActiveForm.GoToLine
End Sub

Private Sub mnuEditPreferences_Click()
'Dim fPreferences As New frmPreferences

'   fPreferences.Show vbModal
End Sub

Private Sub mnuEditRedo_Click()
   ActiveForm.Redo
End Sub

Private Sub mnuEditReplace_Click()
   PutTheCodeBack
   frmFind.Form = ActiveForm
   frmFind.FindReplace = True
   frmFind.Show 'not vbModal
   SetTopmostWindow frmFind.hWnd
End Sub

Private Sub mnuEditSelectAll_Click()
   If ActiveForm Is Nothing Then Exit Sub
   Select Case TypeName(ActiveForm)
   Case "frmScreen", "frmCode": ActiveForm.SelectAll
   End Select
End Sub

Private Sub mnuFile_Click()
   Me.mnuFileMRU(1) = Me.mnuFormat
End Sub

Private Sub mnuFileExport_Click()
Dim fSelectModules As New frmSelectModules

   If gTarget Is Nothing Then Exit Sub
   'Put the code away and save the project as is
   mnuFileSaveProject_Click
   
   Set fSelectModules.Project = gTarget
   fSelectModules.Show vbModal
   
   If fSelectModules.DialogOK And fSelectModules.Selections <> "" Then
      gTarget.Export fSelectModules.Selections
   End If
End Sub

Private Sub MakeExe()
Dim res As Integer
Dim outputfile As String
Dim code As String
Dim optionExplicit As String
Dim p As Integer
Dim resource As CResourceFile
   
   code = gTarget.Make
      
   gTarget.MakePath = gTarget.Name & ".exe"
   outputfile = gTarget.MakePath

   Select Case UCase(Right(outputfile, 3))
   Case "EXE"
#If NSBasic_CE = 1 Then
      res = fnAddscriptVCE(installationDirectory & "\Controls\" & getPlatform & "\Basic.exe", outputfile, StripCode(code), gTarget.Icon)
      'res = fnAddscriptVCE(installationDirectory & "\Controls\" & getPlatform & "\Basic.exe", outputfile, code, gTarget.Icon)
      If res <> 0 Then
         Select Case res
         Case 1: MsgBox gStringTable(3448) & installationDirectory & "\Controls\" & getPlatform & "\Basic.exe" 'could not open input file
         Case 2: MsgBox gStringTable(3449) & outputfile 'could not open output file
         Case 3: MsgBox gStringTable(3450) 'AddScript: BeginUpdateResourceA failed.
         Case 4: MsgBox gStringTable(3451) 'AddScript: UpdateResourceA failed.
         Case 5: MsgBox gStringTable(3452) 'AddScript: Icon failed.
         End Select
         Exit Sub
      End If
#End If
   InjectResources (outputfile)
#If NSBasic_CE = 0 Then
      gTarget.MakePath = dlgCommonDialog.filename
      mnuRunDesktop
#End If
   Case "NSB"
      res = WriteFile(code, outputfile, 0, nsbFFNormal)
      If res <= 0 Then
         MsgBox gStringTable(3466) & res '"Save Project File Error "
      End If
   Case "TXT"
      res = WriteFile(code, outputfile, 0, nsbFFtext)
      If res <= 0 Then
         MsgBox gStringTable(3466) & res '"Save Project File Error "
      End If
   End Select

gotcancel:
   If Mid(gProjectDir, 2, 1) = ":" Then ChDrive Left(gProjectDir, 2) 'ignore network drives
   ChDir gProjectDir
 
End Sub

Private Sub mnuFileMRU_Click(Index As Integer)
Dim proj As CProject

   For Each proj In gProjects
      If proj.PathName = mnuFileMRU(Index).Tag And proj.Saved Then
         MsgBox gStringTable(3330) '"Project is already open"
         Exit Sub
      End If
   Next
   'This line commented out to prevent multiple projects open at once.
'   OpenProject mnuFileMRU(index).Tag
   If RemoveProject(gTarget) Then OpenProject mnuFileMRU(Index).Tag
End Sub

Private Sub mnuFileOpenSample_Click()
   dlgCommonDialog.DialogTitle = gStringTable(3490) '"Open Sample Project"
   dlgCommonDialog.CancelError = True
   dlgCommonDialog.filename = ""
   dlgCommonDialog.InitDir = gSamplesDirectory
   #If NSBasic_CE Then
   dlgCommonDialog.DefaultExt = "nsb"
   dlgCommonDialog.Filter = "NSBasic Files (*.nsb)|*.nsb"
   #End If
   #If NSBasic_Desktop Then
   dlgCommonDialog.DefaultExt = "nsd"
   dlgCommonDialog.Filter = "NSBasic Files (*.nsd)|*.nsd"
   #End If
   #If NSBasic_X Then
   dlgCommonDialog.DefaultExt = "nsx"
   dlgCommonDialog.Filter = "NSBasic Files (*.nsx)|*.nsx"
   #End If
   On Error GoTo gotcancel
   dlgCommonDialog.ShowOpen
   On Error GoTo 0
   If RemoveProject(gTarget) Then OpenProject dlgCommonDialog.filename
   
gotcancel:
End Sub

Public Sub mnuFileSaveProject_Click()
Dim proj As CProject

   If Not ActiveForm Is Nothing Then Set proj = LocateProject(ActiveForm.GlobalID)
   If proj Is Nothing Then Set proj = gTarget
   If proj Is Nothing Then Exit Sub
   ShowStatus gStringTable(3231), True '"Saving..."
   PutTheCodeBack
   SaveProject proj
End Sub

Private Sub SaveModule(ByVal modul As CModule)
   If Not modul.PathName Then
      mnuFileSaveModuleAs_Click
      Exit Sub
   End If
   
   modul.Save
End Sub

Private Sub SaveProject(ByVal proj As CProject)

   'Check this flag, sending to Save As if project has never been saved
   If Not proj.Saved Then
      mnuFileSaveProjectAs_Click
      Exit Sub
   End If
   proj.Save
   
   UpdateRecent gTarget.PathName
   proj.Dirty = False
End Sub

Private Sub mnuFileSaveModuleAs_Click()
Dim obj As Object

   If ActiveForm Is Nothing Then Exit Sub
   If TypeName(ActiveForm) <> "frmCode" Then Exit Sub
   Set obj = LocateObject(ActiveForm.GlobalID)
   If TypeName(obj) <> "CModule" Then Exit Sub
   SaveModuleAs obj.GlobalID
End Sub

Public Function SaveModuleAs(strGlobalID As String) As Boolean
Dim modul As CModule
   
   Set modul = LocateObject(strGlobalID)
   If modul Is Nothing Then Exit Function
   
   dlgCommonDialog.DialogTitle = gStringTable(3470) '"Save Module As"
   dlgCommonDialog.CancelError = True
   dlgCommonDialog.DefaultExt = "bas"
   'dlgCommonDialog.Filter = "Code Modules (*.bas)|*.bas|Text Files (*.txt)|*.txt"
   dlgCommonDialog.Filter = "Code Modules (*.bas, *.cod)|*.bas;*.cod|Text Files (*.txt)|*.txt|All Files (*.*)|*.*"
   If modul.PathName <> "" Then
      dlgCommonDialog.filename = Left(modul.PathName, Len(modul.PathName) - 4)
      dlgCommonDialog.FilterIndex = IIf(LCase(Right(modul.PathName, 4)) = ".bas", 1, 2)
   Else
      dlgCommonDialog.filename = modul.Name
   End If
   dlgCommonDialog.flags = cdlOFNLongNames + cdlOFNNoReadOnlyReturn + cdlOFNOverwritePrompt
   On Error GoTo gotcancel
   dlgCommonDialog.ShowSave

   If Mid(gProjectDir, 2, 1) <> ":" Then ChDrive Left(gProjectDir, 2) 'ignore network drives
   ChDir gProjectDir
   modul.PathName = GetRelativePath(CurDir, dlgCommonDialog.filename)
   'Save As merely sets the Saved flag, then lets Save do all the work
   SaveModuleAs = True
   modul.Save
   Exit Function
   
gotcancel:
   If Mid(gProjectDir, 2, 1) = ":" Then ChDrive Left(gProjectDir, 2)
   ChDir gProjectDir
End Function

Private Sub mnuFileSaveProjectAs_Click()
Dim proj As CProject
Dim frm As Form

   If Not ActiveForm Is Nothing Then Set proj = LocateProject(ActiveForm.GlobalID)
   If proj Is Nothing Then Set proj = gTarget
   If proj Is Nothing Then Exit Sub

   dlgCommonDialog.DialogTitle = gStringTable(1004) '"Save Project As"
   dlgCommonDialog.CancelError = True
   dlgCommonDialog.DefaultExt = Right(kProductExtension, 3)
   dlgCommonDialog.Filter = "Project Files (*" & kProductExtension & ")|*" & kProductExtension & "|Text Files (*.txt)|*.txt"
   If proj.PathName <> "" Then
      dlgCommonDialog.filename = Left(proj.PathName, Len(proj.PathName) - 4)
      'dlgCommonDialog.FilterIndex = IIf(Right(proj.PathName, 3) = Right(kProductExtension, 3), 1, 2)
      dlgCommonDialog.FilterIndex = 1 'default save as .nsb
   Else
      dlgCommonDialog.filename = proj.Name
      dlgCommonDialog.FilterIndex = 1
   End If
   dlgCommonDialog.flags = cdlOFNLongNames + cdlOFNNoReadOnlyReturn + cdlOFNOverwritePrompt
   On Error GoTo gotcancel
   dlgCommonDialog.ShowSave

   proj.PathName = dlgCommonDialog.filename
   proj.MakePath = proj.PathName
   gProjectDir = CurDir
   'proj.PathName = Left(proj.PathName, Len(proj.PathName) - 4) & kProductExtension
   proj.Saved = True
   proj.Name = Left(dlgCommonDialog.FileTitle, Len(dlgCommonDialog.FileTitle) - 4)
   If gbProjectExplorer Then gfProjectExplorer.UpdateTarget
   If gbProperties Then gfProperties.ShowObject
   For Each frm In Children
      frm.SetCaption
   Next
   'Save As merely sets the Saved flag, then lets Save do all the work
   mnuFileSaveProject_Click
   If Right(LCase(proj.PathName), 4) = ".txt" Then
      proj.PathName = Left(proj.PathName, Len(proj.PathName) - 4) & kProductExtension
   End If
gotcancel:
   Exit Sub
End Sub

Private Sub mnuFormat_Click()
Dim bEnabled As Boolean
Dim i As Integer
Dim fScreen As frmScreen

   If Not ActiveForm Is Nothing Then
      Set fScreen = IIf(TypeName(ActiveForm) = "frmScreen", ActiveForm, Nothing)
      If fScreen Is Nothing Then
         bEnabled = False
      Else
         bEnabled = fScreen.Selection.Count > 0
      End If
   End If
   For i = 0 To mnuFormatAlignItem.UBound
      If mnuFormatAlignItem(i).Caption <> "-" Then mnuFormatAlignItem(i).Enabled = bEnabled
   Next
   For i = 0 To mnuFormatMakeSameSizeItem.UBound
      If mnuFormatMakeSameSizeItem(i).Caption <> "-" Then mnuFormatMakeSameSizeItem(i).Enabled = bEnabled
   Next
   mnuFormatSizeToGrid.Enabled = bEnabled
   For i = 0 To mnuFormatCenterItem.UBound
      If mnuFormatCenterItem(i).Caption <> "-" Then mnuFormatCenterItem(i).Enabled = bEnabled
   Next
   For i = 0 To mnuFormatHorizontalSpacingItem.UBound
      If mnuFormatHorizontalSpacingItem(i).Caption <> "-" Then mnuFormatHorizontalSpacingItem(i).Enabled = bEnabled
   Next
   For i = 0 To mnuFormatVerticalSpacingItem.UBound
      If mnuFormatVerticalSpacingItem(i).Caption <> "-" Then mnuFormatVerticalSpacingItem(i).Enabled = bEnabled
   Next
End Sub

Private Sub mnuFormatAlignItem_Click(Index As Integer)
   'Lefts, Centers, Rights, -, Tops, Middles, Bottoms, -, Grid
   ActiveForm.Format 0, Index
End Sub

Private Sub mnuFormatCenterItem_Click(Index As Integer)
   'Horizontally, Vertically
   ActiveForm.Format 5, Index
End Sub

Private Sub mnuFormatHorizontalSpacingItem_Click(Index As Integer)
   'Equal, Increase, Decrease, Remove
   ActiveForm.Format 3, Index
End Sub

Private Sub mnuFormatMakeSameSizeItem_Click(Index As Integer)
   'Width, Height, Both
   ActiveForm.Format 1, Index
End Sub

Private Sub mnuFormatOrderItem_Click(Index As Integer)
   'Front, Forward, Backward, Back
   ActiveForm.Format 6, Index
End Sub

Private Sub mnuFormatSizeToGrid_Click()
   'Size To Grid
   ActiveForm.Format 2, 0
End Sub

Private Sub mnuFormatVerticalSpacingItem_Click(Index As Integer)
   'Equal, Increase, Decrease, Remove
   ActiveForm.Format 4, Index
End Sub



Private Sub mnuHelpPalmCreatorID_Click()
   openWebPage "http://www.palmos.com/dev/tech/palmos/creatorid/"
End Sub

Private Sub mnuHelpPOSE_Click()
   openWebPage "http://www.palmos.com/dev/tech/tools/emulator/"
End Sub

Private Sub mnuHelpRegister_Click()
   frmRegister.Show vbModal, Me
End Sub

Private Sub mnuHelpTopics_Click()
   Dim helpFile As String
   
   helpFile = installationDirectory & "\Lang\" & gLanguage & ".chm"
   On Error GoTo tryhlp
   Open helpFile For Input As #99
   Close #99
   GoTo getHelp
   
tryhlp:
   Resume tryhlp1
tryhlp1:
   helpFile = installationDirectory & "\Lang\" & gLanguage & ".hlp"
   On Error GoTo useEnglish
   Open helpFile For Input As #99
   Close #99
   GoTo getHelp
   
useEnglish:
   On Error GoTo 0
   helpFile = installationDirectory & "\Lang\English.chm"
   
getHelp:
   On Error GoTo 0
   If Right(helpFile, 3) = "chm" Then
      err = ShellExecute(0, "Open", helpFile, vbNullString, vbNullString, 5)
   Else
      dlgCommonDialog.helpFile = helpFile
      dlgCommonDialog.HelpCommand = cdlHelpContents
      dlgCommonDialog.HelpContext = 0
      dlgCommonDialog.ShowHelp
   End If
End Sub
Private Sub mnuHelpTechNotes_Click()
   Dim PathName As String
   PathName = installationDirectory & "\TechNotes\index.htm"
   openWebPage PathName
End Sub
Private Sub mnuHelpHandbook_Click()
   Dim filename As String
   filename = installationDirectory & "\lang\Handbook.pdf"
   err = ShellExecute(0, "Open", filename, vbNullString, vbNullString, 5)
End Sub
Private Sub mnuHelpTutorials_Click()
   Dim PathName As String
   PathName = installationDirectory & "\TechNotes\TT.index.htm"
   openWebPage PathName
End Sub
Private Sub mnuHelpReadMe_Click()
   Dim PathName As String
   PathName = installationDirectory & "\ReadMe.htm"
   openWebPage PathName
End Sub
Private Sub mnuHelpBigRedToolbox_Click()
   Dim PathName As String
   'PathName = InstallationDirectory & "\BigRedToolbox\index.htm"
   PathName = "http://www.nsbasic.com/ce/info/BigRedToolbox/"
   openWebPage PathName
End Sub

Private Sub mnuProject_Click()
   mnuProjectAddForm.Enabled = (Not gTarget Is Nothing)
   mnuProjectAddMenu.Enabled = (Not gTarget Is Nothing)
   mnuProjectAddBitmap.Enabled = (Not gTarget Is Nothing)
   mnuProjectAddNewModule.Enabled = (Not gTarget Is Nothing)
   mnuProjectAddExistingModule.Enabled = (Not gTarget Is Nothing)
   mnuProjectAddResourceFile.Enabled = (Not gTarget Is Nothing)
   mnuProjectStartupCode.Enabled = (Not gTarget Is Nothing)
   mnuProjectTerminationCode.Enabled = (Not gTarget Is Nothing)
   'mnuProjectSetTarget.Enabled = (Not gTarget Is Nothing)
   'If gTarget Is Nothing Then Exit Sub
End Sub

Private Sub mnuProjectAddExistingModule_Click()
   ProjectAddModule
End Sub

Private Sub mnuProjectAddForm_click()
   ProjectAddForm
End Sub

Private Sub mnuProjectAddNewModule_Click()
   ProjectNewModule
End Sub

Private Sub mnuProjectAddResourceFile_Click()
   ProjectAddResourceFile
End Sub

Private Sub mnuProjectSetTargetList_Click(Index As Integer)
   'This allows the user to manually change the target project
   Set gTarget = LocateObject(mnuProjectSetTargetList(Index).Tag)
   UpdateProjectList
End Sub

Private Sub mnuProjectStartupCode_Click()
   ViewCode gTarget.GlobalID, "startup"
End Sub

Private Sub mnuProjectTerminationCode_Click()
   ViewCode gTarget.GlobalID, "termination"
End Sub

'Translate to mnuRightItem equivalent
Private Sub mnuRightAddItem_Click(Index As Integer)
   Select Case Index
   Case 0, 1: mnuRightItem_Click Index + 17
   Case Else: mnuRightItem_Click Index + 19
   End Select
End Sub

Private Sub mnuRightEdit_Click(Index As Integer)
   Select Case Index
   Case 0: ActiveForm.Undo
   Case 1: ActiveForm.Redo
   'Case 2
   Case 3: ActiveForm.Cut
   Case 4: ActiveForm.Copy
   Case 5: ActiveForm.Paste
   Case 6: ActiveForm.Delete
   Case 7: ActiveForm.SelectAll
   'Case 8
   Case 9: mnuEditFind_Click
   Case 10: mnuEditReplace_Click
   Case 11: mnuEditGoTo_Click
   'Case 12
   Case 13 'Advanced
   'Case 14
   Case 15: ActiveForm.ShowProperties
   End Select
End Sub

Private Sub mnuRightEditAdvanced_Click(Index As Integer)
   Select Case Index
   Case 0: mnuRightEditAdvanced(0).Checked = ActiveForm.ShowWhitespace
   Case 1: ActiveForm.CommentSelection True
   Case 2: ActiveForm.CommentSelection False
   Case 3: ActiveForm.SetRepeatCount
   Case 4: ActiveForm.ExecuteCommand
   End Select
End Sub

Private Sub mnuRightEditCode_Click()
   If TypeName(ActiveForm) <> "frmCode" Then Exit Sub
   mnuRightEdit(0).Enabled = ActiveForm.CanUndo
   mnuRightEdit(1).Enabled = ActiveForm.CanRedo
   '-
   mnuRightEdit(3).Enabled = ActiveForm.CanCut
   mnuRightEdit(4).Enabled = ActiveForm.CanCopy
   If ActiveForm.CanPaste Then
      If Left(Clipboard.GetText, Len(kClipboardHeader)) = kClipboardHeader Then
         mnuRightEdit(5).Enabled = False
      Else
         mnuRightEdit(5).Enabled = True
      End If
   End If
   mnuRightEdit(6).Enabled = ActiveForm.CanCut
End Sub

'0  View O&bject              1500
'1  View C&ode                1501
'2  -
'3  View &Startup Code        1502
'4  View &Termination Code    1503
'5  -
'6  View &Before Code         1504
'7  View &After Code          1505
'8  View &Event Code          1506
'9  View &Help Code           1507
'10 -
'11 Cu&t                   1014
'12 &Copy                  1015
'13 &Paste                 1016
'14 &Delete                1017
'15 -
'16 &Add                      1508
'-0  &Form                    1509
'-1  &Menu                    1510
'-2  &Bitmap                  1511
'-3  -
'-4  &New Module              1512
'-5  &Existing Module...      1513
'-6  &Add Resource            1521
'17 Add &Form              1028
'18 Add &Menu              1029
'19 Add &MenuBar              1514
'20 Add &Dropdown             1515
'21 Add &Bitmap            1030
'22 -
'23 Add &New Module           1516
'24 Add &Existing Module...   1517
'25 -
'26 Re&move Project           1518
'27 Re&move Bitmap            1519
'28 Re&move Module            1520
'29 -
'30 Remove Resource           1522
'31 -
'32 P&roperties...            1038
Private Sub mnuRightItem_Click(Index As Integer)
Dim nClickSource As Integer
Dim strGlobalID As String

   nClickSource = Left(frmMain.mnuRight.Tag, 1)
   strGlobalID = Mid(frmMain.mnuRight.Tag, 2)
   frmMain_mnuRightItem_Click Index, nClickSource, strGlobalID
End Sub

Private Sub MakeInstaller()
   Dim Data As String
   Dim Dummy As String
   Dim res As Integer
   Dim Title As String
   
   If gTarget Is Nothing Then Exit Sub
         
   If Dir(gTarget.Name & ".exe") = "" Then
      MsgBox gStringTable(3483) & gTarget.Name & ".exe" 'File not found:
      Exit Sub
   End If
   
   MakeReadMe
   MakeEULA
   MakeAppInf
   MakeAppIni
   MakeShortcutXML
   MakeAppBat
   
   On Error Resume Next
   Kill "App." & getPlatform & ".cab"
   Kill "App.Installer.exe"
   On Error GoTo 0
   
   res = ExecCmd("App.bat 1> Installer.log 2> InstallerErr.log")
   
   'clean up error files
   If Dir("InstallerErr.log") <> "" Then If FileLen("InstallerErr.log") <= 2 Then Kill "InstallerErr.log"
   If Dir("InstallerCabWiz.log") <> "" Then If FileLen("InstallerCabWiz.log") <= 2 Then Kill "InstallerCabWiz.log"
   If Dir("InstallerErr.log") = "" And Dir("InstallerCabWiz.log") = "" Then
      Kill "Installer.log"
      If gbDeleteWorkFiles = True Then
         On Error Resume Next
         Kill "App.bat"
         Kill "App.inf"
         Kill "App.ini"
         Kill "Shortcut.xml"
         On Error GoTo 0
      End If
   Else
      MsgBox gStringTable(3482) 'A problem occurred when making the installer.
      Exit Sub
   End If
   
   Title = gTarget.Title
   If Title = "" Then Title = gTarget.Name
   
   If gbRetainCabFiles = False Then
      On Error Resume Next
      Kill Title & ".Installer.cab"
      On Error GoTo 0
   End If
   
   If gbActiveSyncRun Then
      res = ShellExecute(frmMain.hWnd, "open", Chr(34) & Title & ".installer.exe" & Chr(34), "", Dummy, SW_SHOWNORMAL)
   Else
      If gbCompiling = False Then
         MsgBox gStringTable(3486) & vbCrLf & Left(gTarget.Path, Len(gTarget.Path) - 4) & ".installer.exe" 'Installer successfully created:"
      End If
   End If

End Sub







Private Sub mnuRunInstallDeviceIDE_Click()
Dim installer As String
Dim Dummy As String
Dim res As Integer

   If gnPlatform = 0 Then
      installer = installationDirectory & "\installers\Basic.WM.exe"
   Else
      installer = installationDirectory & "\installers\Basic.WinCE.exe"
   End If
   res = ShellExecute(frmMain.hWnd, "open", installer, "", Dummy, SW_SHOWNORMAL)

   frmRegister.butSetDevice_Click
End Sub



Private Sub mnuRunUpdateAppOnDevice_Click()
Dim temp
Dim NSBPath As String
Dim VCEPath As String
Dim executePathname As String
Dim desktopPathname As String
Dim devicePathname As String
Dim deviceType As String
Dim bCopied As Boolean
Dim trace As Boolean
trace = False

   'Make sure project is saved
   If trace Then MsgBox "mnuRunCEActiveSync 1"
   mnuFileSaveProject_Click
   If trace Then MsgBox "mnuRunCEActiveSync 2"
   If gTarget Is Nothing Then Exit Sub
   If trace Then MsgBox "mnuRunCEActiveSync 3"
   If Not gTarget.Saved Or gTarget.Dirty Then
      MsgBox gStringTable(3364) '"The project must be saved before it can be run."
      Exit Sub
   End If
   MakeExe

   If trace Then MsgBox "mnuRunCEActiveSync 4"

   desktopPathname = Left(gTarget.PathName, Len(gTarget.PathName) - 4) & ".exe"

   If gTarget.InstallDir <> "" Then
      devicePathname = CERem.GetSpecialFolderPath(38) & "\" & gTarget.InstallDir  '"Program Files"
   Else
      devicePathname = CERem.GetSpecialFolderPath(38) & "\" & gTarget.Name        '"Program Files"
   End If
   devicePathname = devicePathname & "\" & gTarget.Name & ".exe"
      
   If desktopPathname = "" Then Exit Sub
   If trace Then MsgBox "mnuRunCEActiveSync 5"
   
   If CERem.Init Then
      bCopied = CERem.CopyFileToCEDevice(desktopPathname, devicePathname)
      DoEvents
      If trace Then MsgBox "mnuRunCEActiveSync 6"
      If bCopied Then
         'get path to basic.exe (not needed any more - it's built into actual program)
         'NSBPath = CERem.GetRegValue(HKEY_CLASSES_ROOT, "nsbfile", "nsbfile\Shell\Open\Command", "Default")
         'If NSBPath = "" Then
         '   MsgBox gStringTable(3369) 'Program copied to device, but cannot be run.
         '   Exit Sub
         'End If
         If trace Then MsgBox "mnuRunCEActiveSync 7"
         If gbActiveSyncRun Then
            Call CERem.RapiGetError
            DoEvents
            If trace Then MsgBox "mnuRunCEActiveSync 9"
            Call CERem.ExecuteOnDevice(devicePathname, "")
         End If
      Else
         MsgBox gStringTable(3367) & devicePathname '"Check Device Install Path"
      End If
      If trace Then MsgBox "mnuRunCEActiveSync 10"
      CERem.UnInit
    End If
End Sub

Private Sub mnuRunExtraInstallers_Click()
'Dim deviceType As String
'Dim installFile As String

   On Error GoTo err
   dlgCommonDialog.DialogTitle = "Installers"
   dlgCommonDialog.InitDir = installationDirectory + "\Installers"
   dlgCommonDialog.filename = ""
   dlgCommonDialog.Filter = "Installers (*.exe)|*.exe"
   dlgCommonDialog.DefaultExt = "psf"
   dlgCommonDialog.CancelError = True
   dlgCommonDialog.ShowOpen
   RunInstaller (dlgCommonDialog.filename)

err:
End Sub

Private Sub RunInstaller(installFile As String)
Dim taskID As Integer

   taskID = 0
   On Error Resume Next
   taskID = Shell(installFile, vbNormalFocus)
   On Error GoTo 0
   If taskID = 0 Then
      MsgBox gStringTable(3381) & installFile '"Install files not found"
   End If
End Sub
Private Function getCEDeviceType() As String
Dim deviceType As String
Dim deviceProcessorType As Integer

    deviceType = "None"
    deviceProcessorType = MWinReg.GetRegValue(MWinReg.hKey, "Software\Microsoft\Windows CE Services", "DeviceProcessorType", 0)
    deviceType = MWinReg.GetRegValue(MWinReg.hKey, "Software\Microsoft\Windows CE Services", "DeviceType", "None")
    If deviceType = "None" Then
       MsgBox gStringTable(3380) '"ActiveSync must be run first."
    End If
    If deviceType <> "PocketPC" Then
      deviceType = CStr(deviceProcessorType)
    End If
    getCEDeviceType = deviceType
    ShowStatus "Installing to device type " & deviceType & ".", True
End Function

Private Sub mnuTools_Click()
   mnuToolsMenuEditor.Enabled = (gProjects.Count > 0)
End Sub

Private Sub mnuToolsActiveX_Click()
   ManageActiveX
End Sub

Private Sub mnuToolsList_Click(Index As Integer)
Dim PathName As String
Dim err As Integer

   'PathName = Chr(34) & installationDirectory & "\tools\" & mnuToolsList(Index).Tag & ".exe" & Chr(34)
   PathName = Chr(34) & installationDirectory & "\tools\" & mnuToolsList(Index).Tag & Chr(34)
   'Shell PathName, vbNormalFocus
   err = ShellExecute(app.hInstance, "Open", PathName, "", "", 5)

End Sub

Private Sub mnuToolsMenuEditor_Click()
   MenuEditor
End Sub

Private Sub mnuToolsOptions_Click()
Dim fOptions As New frmOptions

   fOptions.Show vbModal, Me
   If Not ActiveForm Is Nothing Then ActiveForm.Refresh
End Sub

Private Sub mnuWindowList_Click(Index As Integer)
   GetMDIChild(mnuWindowList(Index).Tag).ZOrder
End Sub

Private Sub mnuViewProjectExplorer_Click()
   If gbProjectExplorer Then
      Unload gfProjectExplorer
   Else
      gfProjectExplorer.DisplayExplorer
      gfProjectExplorer.DockWindow
   End If
End Sub

Private Sub mnuViewProperties_Click()
   If gbProperties Then
      Unload gfProperties
   Else
      gfProperties.DockWindow
   End If
End Sub

Private Sub mnuViewToolbox_Click()
   If gbToolbox Then
      Unload gfToolbox
   Else
      gfToolbox.DockWindow
   End If
End Sub

Private Sub picSplit_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   m_bSizing = True
   SetParent picSplit.hWnd, frmMain.hWnd
   UpdateWindow picSplit.hWnd
End Sub

Private Sub picSplit_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim pt As POINTAPI

   If m_bSizing Then
      GetCursorPos pt
      ScreenToClient frmMain.hWnd, pt
'      ScreenToClient picPanel.hwnd, pt
      picSplit.Move picPanel.Left + picWidth.Width, pt.Y * Screen.TwipsPerPixelY, picSplit.Width, 45
'      picSplit.Move picWidth.Width, pt.Y * Screen.TwipsPerPixelY, picSplit.Width, 45
''      picWidth.BackColor = &H8000000C
      picSplit.BackColor = vbBlack
   End If
End Sub

Private Sub picSplit_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim pt As POINTAPI

   m_bSizing = False
   GetCursorPos pt
   ScreenToClient picPanel.hWnd, pt
   picSplit.BackColor = &H8000000F
''   picWidth.BackColor = &H80000002
   SetParent picSplit.hWnd, picPanel.hWnd
'   picSplit.Tag = round(((-pt.Y * Screen.TwipsPerPixelY) / picPanel.Height) * 100)
   picSplit.Tag = Round((picSplit.Top - picPanel.Top) / picPanel.Height * 100)
   picPanel_Resize
   UpdateWindow picSplit.hWnd
End Sub

Public Sub picToolbox_Resize()
''   picToolbox.Width = tbToolbox.Width
Dim L As Long

   L = GetWindow(picToolbox.hWnd, GW_CHILD)
   If L <> 0 Then
      MoveWindow L, -3, -3, picToolbox.Width / Screen.TwipsPerPixelX + 8, picToolbox.Height / Screen.TwipsPerPixelY + 9, True
      UpdateWindow L
   End If
End Sub

Public Sub picPanel_Resize()
'On Error Resume Next
Dim nSplit As Integer

   If Me.WindowState = vbMinimized Then Exit Sub
   If Not gbProjectExplorer And Not gbProperties Then
      picPanel.Visible = False
   Else
      picWidth.Move 0, 0, 90, picPanel.Height
      picSplit.Visible = False
      If gbProjectExplorer And gbProperties Then
         'Need to show picSplit first
         nSplit = ((picPanel.Height - 90) * picSplit.Tag) \ 100
         nSplit = IIf(nSplit < 0, 0, nSplit)
         nSplit = IIf(nSplit > picPanel.Height - 110, picPanel.Height - 110, nSplit)
         picSplit.Move picWidth.Width, nSplit, picPanel.Width - picWidth.Width, 90
         picSplit.Visible = True
         'Now show other pics
         picProjectExplorer.Move picWidth.Width, 0, picPanel.Width - picWidth.Width, picSplit.Top
         picProjectExplorer.Visible = True
         If (picPanel.Height - (picSplit.Top + picSplit.Height) > 0) Then
            picProperties.Move picWidth.Width, picSplit.Top + picSplit.Height, picPanel.Width - picWidth.Width, picPanel.Height - (picSplit.Top + picSplit.Height)
         End If
         picProperties.Visible = True
      ElseIf gbProjectExplorer Then
         picProjectExplorer.Move picWidth.Width, 0, picPanel.Width - picWidth.Width, picPanel.Height
         picProjectExplorer.Visible = True
         picProperties.Visible = False
      Else
         picProperties.Move picWidth.Width, 0, picPanel.Width - picWidth.Width, picPanel.Height
         picProperties.Visible = True
         picProjectExplorer.Visible = False
      End If
      picWidth.Refresh
      picSplit.Refresh
   End If
End Sub

Public Sub picProjectExplorer_Resize()
Dim L As Long

   L = GetWindow(picProjectExplorer.hWnd, GW_CHILD)
   If L <> 0 Then
      Call MoveWindow(L, -3, -3, picProjectExplorer.Width / Screen.TwipsPerPixelX + 8, picProjectExplorer.Height / Screen.TwipsPerPixelY + 9, True)
      Call UpdateWindow(L)
   End If
End Sub

Public Sub picProperties_Resize()
Dim L As Long

   L = GetWindow(picProperties.hWnd, GW_CHILD)
   If L <> 0 Then
      Call MoveWindow(L, -3, -3, picProperties.Width / Screen.TwipsPerPixelX + 8, picProperties.Height / Screen.TwipsPerPixelY + 9, True)
      Call UpdateWindow(L)
   End If
End Sub

Private Sub picWidth_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   m_bSizing = True
   SetParent picWidth.hWnd, frmMain.hWnd
   UpdateWindow picWidth.hWnd
End Sub

Private Sub picWidth_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim pt As POINTAPI

   If m_bSizing Then
      GetCursorPos pt
      ScreenToClient frmMain.hWnd, pt
      picWidth.Move pt.X * Screen.TwipsPerPixelX, picPanel.Top, 45, picPanel.Height
''      picWidth.BackColor = &H8000000C
      picWidth.BackColor = vbBlack
   End If
End Sub

Private Sub picWidth_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim pt As POINTAPI
Dim NewWidth As Integer

   If m_bSizing Then
      GetCursorPos pt
      ScreenToClient frmMain.hWnd, pt
      m_bSizing = False
      picWidth.BackColor = &H8000000F
''      picWidth.BackColor = &H80000002
      SetParent picWidth.hWnd, picPanel.hWnd
      NewWidth = Me.Width - picWidth.Left - picWidth.Width
      If NewWidth <= 100 Then NewWidth = 100
      picPanel.Width = NewWidth
      picPanel_Resize
      UpdateWindow picWidth.hWnd
   End If
End Sub

Public Sub UpdateToolbar()
   If TypeName(ActiveForm) <> "frmCode" Then Exit Sub
   tbToolBar.Buttons(7).Enabled = ActiveForm.CanUndo
   tbToolBar.Buttons(8).Enabled = ActiveForm.CanRedo
   tbToolBar.Buttons(10).Enabled = ActiveForm.CanCut
   tbToolBar.Buttons(11).Enabled = ActiveForm.CanCopy
   tbToolBar.Buttons(12).Enabled = ActiveForm.CanPaste
End Sub

Private Sub tbToolBar_ButtonClick(ByVal Button As MSComctlLib.Button)
   On Error Resume Next
   Select Case Button.key
   Case "New": mnuFileNewProject_click
   Case "Open": mnuFileOpenProject_click
   Case "Save": mnuFileSaveProject_Click
   Case "Print": mnuFilePrint_Click
   Case "Undo": mnuEditUndo_Click
   Case "Redo": mnuEditRedo_Click
   Case "Cut": mnuEditCut_Click
   Case "Copy": mnuEditCopy_Click
   Case "Paste": mnuEditPaste_Click
   Case "Delete": mnuRightItem_Click 14
   Case "Find": mnuEditFind_Click
   Case "Add Form": mnuProjectAddForm_click
   Case "Compile": mnuRunCEStart_Click
   Case "Properties": mnuViewProperties_Click
   Case "Menu Editor": mnuToolsMenuEditor_Click
   End Select
End Sub

Private Sub mnuHelpAbout_Click()
   frmAbout.Show vbModal, Me
End Sub

Private Sub mnuHelpSearchForHelpOn_Click()
   Dim nRet As Integer

   'if there is no helpfile for this project display a message to the user
   'you can set the HelpFile for your application in the
   'Project Properties dialog
   If Len(app.helpFile) = 0 Then
      MsgBox gStringTable(3333), vbInformation, Me.Caption '"Unable to display Help Contents. There is no Help associated with this project."
   Else
      On Error Resume Next
      nRet = OSWinHelp(Me.hWnd, app.helpFile, 261, 0)
      If err Then
         MsgBox err.Description
      End If
   End If
End Sub

Private Sub mnuHelpContents_Click()
   Dim nRet As Integer

   'if there is no helpfile for this project display a message to the user
   'you can set the HelpFile for your application in the
   'Project Properties dialog
   If Len(app.helpFile) = 0 Then
      MsgBox gStringTable(3333), vbInformation, Me.Caption ' "Unable to display Help Contents. There is no Help associated with this project."
   Else
      On Error Resume Next
      nRet = OSWinHelp(Me.hWnd, app.helpFile, 3, 0)
      If err Then
         MsgBox err.Description
      End If
   End If
End Sub

Private Sub mnuWindowArrangeIcons_Click()
   Me.Arrange vbArrangeIcons
End Sub

Private Sub mnuWindowTileVertical_Click()
   Me.Arrange vbTileVertical
End Sub

Private Sub mnuWindowTileHorizontal_Click()
   Me.Arrange vbTileHorizontal
End Sub

Private Sub mnuWindowCascade_Click()
   Me.Arrange vbCascade
End Sub

Private Sub mnuWindowNewWindow_Click()
   LoadNewProject "std"
End Sub

Private Sub mnuHelpWWW_Click()
#If NSBasic_Desktop Then
   openWebPage "http://www.nsbasic.com/desktop/"
#Else
   openWebPage "http://www.nsbasic.com/ce/"
#End If
End Sub

Private Sub mnuViewOptions_Click()
   frmOptions.Show vbModal, Me
End Sub

Private Sub mnuViewRefresh_Click()
Dim frm As Form

   Set frm = ActiveForm
   If frm Is Nothing Then Exit Sub
   frm.Visible = False
   frm.Visible = True
End Sub

Private Sub mnuViewStatusBar_Click()
   mnuViewStatusBar.Checked = Not mnuViewStatusBar.Checked
   sbStatusBar.Visible = mnuViewStatusBar.Checked
End Sub

Private Sub mnuViewToolbar_Click()
   mnuViewToolbar.Checked = Not mnuViewToolbar.Checked
   tbToolBar.Visible = mnuViewToolbar.Checked
End Sub

Private Sub mnuEditPaste_Click()
   If ActiveForm Is Nothing Then Exit Sub
   Select Case TypeName(ActiveForm)
   Case "frmScreen", "frmCode": ActiveForm.Paste
   End Select
'   On Error Resume Next
'   ActiveForm.rtfText.SelRTF = Clipboard.GetText
End Sub

Private Sub mnuEditCopy_Click()
   If ActiveForm Is Nothing Then Exit Sub
   Select Case TypeName(ActiveForm)
   Case "frmScreen", "frmCode": ActiveForm.Copy
   End Select
'   On Error Resume Next
'   Clipboard.SetText ActiveForm.rtfText.SelRTF
'
End Sub

Private Sub mnuEditCut_Click()
   If ActiveForm Is Nothing Then Exit Sub
   Select Case TypeName(ActiveForm)
   Case "frmScreen", "frmCode": ActiveForm.Cut
   End Select
'   On Error Resume Next
'   Clipboard.SetText ActiveForm.rtfText.SelRTF
'   ActiveForm.rtfText.SelText = vbNullString
'
End Sub

Private Sub mnuEditUndo_Click()
   ActiveForm.Undo
End Sub

Private Sub mnuFileExit_click()
   Unload Me
End Sub

Private Sub mnuFileSend_Click()
   'ToDo: Add 'mnuFileSend_Click' code.
   MsgBox "Add 'mnuFileSend_Click' code."
End Sub

Private Sub mnuFilePrint_Click()
Dim strGID As String

   On Error Resume Next
   If ActiveForm Is Nothing Then Exit Sub

   With dlgCommonDialog
      .DialogTitle = "Print"
      .CancelError = True
      .flags = cdlPDReturnDC + cdlPDNoPageNums
      .ShowPrinter
      If err = MSComDlg.cdlCancel Then Exit Sub
   End With
   PutTheCodeBack
   PrintProject
End Sub

Private Sub mnuFilePrintPreview_Click()
   'ToDo: Add 'mnuFilePrintPreview_Click' code.
   MsgBox "Add 'mnuFilePrintPreview_Click' code."
End Sub

Private Sub mnuFilePageSetup_Click()
   On Error Resume Next
   With dlgCommonDialog
      .DialogTitle = "Page Setup"
      .CancelError = True
      .flags = cdlPDPrintSetup
      .ShowPrinter
   End With
End Sub

Private Sub mnuFileProperties_Click()
   'ToDo: Add 'mnuFileProperties_Click' code.
   MsgBox "Add 'mnuFileProperties_Click' code."
End Sub

Private Sub mnuFileSaveAll_Click()
Dim proj As CProject

   For Each proj In gProjects
      SaveProject proj
   Next
End Sub

Private Sub mnuFileSaveAs_click()
Dim sFile As String

   If ActiveForm Is Nothing Then Exit Sub

   With dlgCommonDialog
      .DialogTitle = "Save As"
      .CancelError = False
      'ToDo: set the flags and attributes of the common dialog control
      .Filter = "All Files (*.*)|*.*"
      .ShowSave
      If Len(.filename) = 0 Then
         Exit Sub
      End If
      sFile = .filename
   End With
   ActiveForm.Caption = sFile
   ActiveForm.rtfText.SaveFile sFile
End Sub

Private Sub mnuFileClose_click()
   'ToDo: Add 'mnuFileClose_Click' code.
   MsgBox "Add 'mnuFileClose_Click' code."
End Sub

Private Sub mnuFileOpenProject_click()
Dim strProj As String
Dim trace As Boolean
trace = False

   If trace Then MsgBox "mnuFileOpenProject" & 1
   strProj = ShowNewOpen(False, "Project", "*.nsb")
   If trace Then MsgBox "mnuFileOpenProject" & 2
   If strProj <> "" Then
      If RemoveProject(gTarget) Then OpenProject strProj
      If gTarget Is Nothing Then Exit Sub
      If Right(LCase(gTarget.PathName), 4) = ".txt" Then
         gTarget.PathName = Left(gTarget.PathName, Len(gTarget.PathName) - 4) & kProductExtension 'name should end in .nsb, even if loaded as .txt
      End If
   End If

End Sub

Private Sub mnuFileNewProject_click()
Dim fNewProject As New frmNewProject
Dim strNew As String

   If MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ShowSplash", True) Then
      fNewProject.Show vbModal
      strNew = fNewProject.ProjectTemplate
      'This should open the frmSelProj with only the "New" tab
      '...when templates are added
      If RemoveProject(gTarget) Then LoadNewProject strNew
   Else
      LoadNewProject "std"
   End If
End Sub

Private Sub UpdateProjectList()
Dim i As Integer
Dim proj As CProject

   'Update Target
''   For Each proj In gProjects
''      If proj.Name = gstr Target Then
''         Set gTarget = proj
''      End If
''   Next

   'Update Target Menu
   For i = 1 To mnuProjectSetTargetList.UBound
      mnuProjectSetTargetList(i).Visible = False
   Next
   For i = 0 To gProjects.Count - 1
      If i > mnuProjectSetTargetList.UBound Then Load mnuProjectSetTargetList(i)
      mnuProjectSetTargetList(i).Caption = gProjects(i + 1).Name
      mnuProjectSetTargetList(i).Tag = gProjects(i + 1).GlobalID
      If StrComp(gProjects(i + 1).Name, gTarget.Name) = 0 Then
         mnuProjectSetTargetList(i).Checked = True
      Else
         mnuProjectSetTargetList(i).Checked = False
      End If
      mnuProjectSetTargetList(i).Visible = True
   Next

   'Update Project Explorer
   If gbProjectExplorer Then gfProjectExplorer.UpdateTarget

   'mnuRun_Click
End Sub

Public Sub ActiveFormChange(nActivate As Integer)
Dim i As Integer
Dim fCode As frmCode

   If nActivate Then
      ActiveForm.DisplaySelection
      If Not ActiveForm Is Nothing Then
         Select Case TypeName(ActiveForm)
         Case "frmScreen"
            ActiveFormIsCode = False
            mnuFormat.Visible = True
            mnuEditUndo.Enabled = False
            mnuEditRedo.Enabled = False
            tbToolBar.Buttons(7).Enabled = False
            tbToolBar.Buttons(8).Enabled = False
         Case "frmCode"
            Set fCode = ActiveForm
            ActiveFormIsCode = True
            mnuFormat.Visible = False
            mnuEditUndo.Enabled = fCode.CanUndo
            mnuEditRedo.Enabled = fCode.CanRedo
            mnuEditCut.Enabled = fCode.CanCut
            mnuEditCopy.Enabled = fCode.CanCopy
            mnuEditPaste.Enabled = fCode.CanPaste
            UpdateToolbar
         Case "frmProperties": Exit Sub
         End Select
         For i = 0 To mnuWindowList.UBound
            mnuWindowList(i).Checked = False
            If ActiveForm.GlobalID = mnuWindowList(i).Tag Then mnuWindowList(i).Checked = True
         Next
      End If
   Else
   End If
End Sub

Public Property Get Project(ByVal strName As String) As CProject
Dim proj As CProject

   strName = "project|" & strName
   For Each proj In gProjects
      If StrComp(proj.GlobalID, strName) = 0 Then
         Set Project = proj
         Exit Property
      End If
   Next
End Property

Public Sub AddMDIChild(frm As Form)
   Children.Add frm
   If Left(frm.GlobalID, 4) = "form" Then
      If gbProjectExplorer Then gfProjectExplorer.ExpandNode frm.GlobalID, True
   End If
   SetWindowList
End Sub

Public Function RemoveMDIChild(strGlobalID As String) As Form
Dim i As Integer

   On Error GoTo ErrorRemovingMDIChild
   For i = 1 To Children.Count
      If Children(i).GlobalID = strGlobalID Then
         Set RemoveMDIChild = Children(i)
         Children.Remove i
         Exit For
      End If
   Next
   If Left(strGlobalID, 4) = "form" Then
      If gbProjectExplorer Then gfProjectExplorer.ExpandNode strGlobalID, False
   End If
   SetWindowList
ErrorRemovingMDIChild:
   On Error GoTo 0
End Function

Public Sub CloseMDIChild(strGlobalID As String)
Dim frm As Form

   Set frm = GetMDIChild(strGlobalID)
   If Not frm Is Nothing Then frm.Hide
'   If Not frm Is Nothing Then Unload frm
End Sub

Private Sub SetWindowList()
Dim i As Integer
Dim frm As Form

   'Clear the menu first
   For i = 0 To mnuWindowList.UBound
      mnuWindowList(i).Visible = False
'      mnuWindowList(i).Checked = False
   Next
   mnuWindowBar1.Visible = False

   i = 0
   For Each frm In Children
      If i > mnuWindowList.UBound Then Load mnuWindowList(i)
      If i < 9 Then
         mnuWindowList(i).Caption = "&" & (i + 1) & " " & frm.Caption
      Else
         mnuWindowList(i).Caption = frm.Caption
      End If
      mnuWindowList(i).Tag = frm.GlobalID
'      If frm Is ActiveForm Then mnuWindowList(i).Checked = True
      mnuWindowList(i).Visible = True
      i = i + 1
   Next
   If i > 0 Then mnuWindowBar1.Visible = True
End Sub

Public Function GetMDIChild(strGlobalID As String) As Form
   For Each GetMDIChild In Children
      If GetMDIChild.GlobalID = strGlobalID Then Exit Function
   Next
   Set GetMDIChild = Nothing
End Function

Private Sub tmrStatus_Timer()
   tmrStatus.Enabled = False
   sbStatusBar.Panels(1).Text = ""
End Sub

Sub pause(secs)
   secs = 0
   Dim t As Long
   Dim i As Integer
   t = Timer
   Do While Timer - t < secs
      i = 1
   Loop
End Sub
Public Sub PrintCode(strGlobalID As String)
Dim ob As Object
Dim strCode As String

   On Error GoTo err_PrintCode

   Set ob = LocateObject(strGlobalID)
   strCode = Mid(strGlobalID, InStrRev(strGlobalID, "|") + 1)
   If ob.GetCode(strCode) = "" Then Exit Sub
   Select Case TypeName(ob)
   Case "CProject"
      Select Case strCode
      Case "startup"
         PrintCommon "Program", "Startup Code", ob.GetCode(strCode)
      Case "termination"
         PrintCommon "Program", "Termination Code", ob.GetCode(strCode)
      End Select
   Case "CForm"
      Select Case strCode
      Case "before"
         PrintCommon "Form Code(Before form drawn)", _
               "Form = " + ob.Name + "/" + ob.Title, _
               ob.GetCode(strCode)
      Case "after"
         PrintCommon "Form Code(After form drawn)", _
               "Form = " + ob.Name + "/" + ob.Title, _
               ob.GetCode(strCode)
      Case "event"
         PrintCommon "Form Event Code", _
               "Form = " + ob.Name + "/" + ob.Title, _
               ob.GetCode(strCode)
      End Select
   Case "CCodeModule"
      PrintCommon "Module", ob.Name, ob.GetCode(strCode)
   Case "CMenuElem"
      PrintCommon "Menu", ob.Caption, ob.GetCode(strCode)
   Case Else
      PrintCommon "Form Object for form = " + ob.obj.Form.Name _
            + "/" + ob.obj.Form.Title, _
            "Id #" + Str(ob.obj.IdNo) + " " + ob.obj.Name + "/" + ob.obj.Label, _
            ob.obj.script
   End Select

'Fall through to this error handler, because it closes our document either way
err_PrintCode:
   Printer.EndDoc
End Sub

Public Sub PrintForm(strGlobalID As String)
Dim frm As CForm
Dim ob As Object

   On Error GoTo err_PrintForm

   Set frm = LocateObject(strGlobalID)

'Fall through to this error handler, because it closes our document either way
err_PrintForm:
   Printer.EndDoc
End Sub

Public Sub PrintCommon(t1 As String, t2 As String, script As String)
   Dim i As Long
   Dim j As Long
   Dim prtLine As String
   Printer.Orientation = dlgCommonDialog.Orientation
   Printer.Font.Size = 8
   Printer.Font.Bold = True
   Printer.Font.Name = GetRegValue(MWinReg.hKey, "Software\NSBasic\" & kProduct & "\Editor", "FontName", "Courier New")
   Printer.Print vbCrLf

   Printer.Print Tab; String(166, "-")
   Printer.Print Tab; "Project = " + gTarget.Name
   Printer.Font.Size = Printer.Font.Size + 2
   Printer.Print Tab; t1
   Printer.Print Tab; t2
   Printer.Font.Size = Printer.Font.Size - 2
   Printer.Font.Bold = False
   Printer.Print vbCrLf
   'Printer.Print Script
   i = 1
   Do While i < Len(script)
      j = InStr(i, script, Chr$(10))
'sgBox "i=" + str(i) + "  j=" + str(j)
      If Not j = 0 Then
        If (j - i) > 80 Then
          j = i + 80
          Printer.Print Tab; Mid(script, i, j - i + 1) + " >>"
          i = j + 1
        Else
          Printer.Print Tab; Mid(script, i, j - i);
          i = j + 1
        End If
      Else
        Printer.Print Tab; Mid(script, i, Len(script) - i + 1)
        Exit Do
      End If
   Loop
   Printer.EndDoc
End Sub

'0  View O&bject              1500
'1  View C&ode                1501
'2  -
'3  View &Startup Code        1502
'4  View &Termination Code    1503
'5  -
'6  View &Before Code         1504
'7  View &After Code          1505
'8  View &Event Code          1506
'9  View &Help Code           1507
'10 -
'11 Cu&t                   1014
'12 &Copy                  1015
'13 &Paste                 1016
'14 &Delete                1017
'15 -
'16 &Add                      1508
'-0  &Form                    1509
'-1  &Menu                    1510
'-2  &Bitmap                  1511
'-3  -
'-4  &New Module              1512
'-5  &Existing Module...      1513
'17 Add &Form                 1028
'18 Add &Menu                 1029
'19 Add &MenuBar              1514
'20 Add &Dropdown             1515
'21 Add &Bitmap               1030
'22 -
'23 Add &New Module           1516
'24 Add &Existing Module...   1517
'25 -
'26 Re&move Project           1518
'27 Re&move Bitmap            1519
'28 Re&move Module            1520
'29 -
'30 Remove Resource           1522
'31 -
'32 P&roperties...            1038
'nClickSource = 0: Project Explorer Window
'nClickSource = 1: Palm Screen
Public Sub RightClickMenu(nClickSource As Integer, strGlobalID As String)
Dim i As Integer

   'First hide all menu items
   'Skip last two because separator and "Properties..." is always visible
   mnuRightItem(mnuRightItem.UBound - 1).Visible = True
   mnuRightItem(mnuRightItem.UBound).Visible = True
   For i = 0 To mnuRightItem.UBound - 2
      mnuRightItem(i).Visible = False
   Next

   'Now choose which menu items to show for object type and window source
   Select Case Left(strGlobalID, InStr(1, strGlobalID, "|") - 1)
   Case "project"
      mnuRightItem(3).Visible = True   'Startup
      mnuRightItem(4).Visible = True   'Termination
      mnuRightItem(5).Visible = True   'Separator
      mnuRightItem(13).Visible = True  'Paste
      mnuRightItem(13).Enabled = (ValidClipboard = kClipboardForm Or ValidClipboard = kClipboardMenu)
      mnuRightItem(15).Visible = True  'Separator
      mnuRightItem(16).Visible = True  'Add ->
      mnuRightItem(25).Visible = True  'Separator
      mnuRightItem(26).Visible = True  'Remove Project
   Case "form"
      If nClickSource = 0 Then
         mnuRightItem(0).Visible = True   'View Object
         mnuRightItem(2).Visible = True   'Separator
      End If
      mnuRightItem(6).Visible = True   'View Before Code
      mnuRightItem(10).Visible = True  'Separator
      If nClickSource = 0 Then mnuRightItem(11).Visible = True       'Cut
      mnuRightItem(12).Visible = True                                'Copy
      mnuRightItem(13).Visible = True
      mnuRightItem(13).Enabled = (ValidClipboard = kClipboardObject) 'Paste
      If nClickSource = 0 Then mnuRightItem(14).Visible = True       'Delete
      mnuRightItem(15).Visible = True  'Separator
      mnuRightItem(17).Visible = True
   Case "object"
      If nClickSource = 0 Then mnuRightItem(0).Visible = True  'View Object
      mnuRightItem(6).Visible = True                           'View Code
      mnuRightItem(10).Visible = True                           'Separator
      mnuRightItem(11).Visible = True                          'Cut
      mnuRightItem(12).Visible = True                          'Copy
      mnuRightItem(14).Visible = True                          'Delete
      'mnuRightItem(15).Visible = True                          'Separator
      'mnuRightItem(16).Visible = True                          'Add ->
   Case "menu"
      mnuRightItem(11).Visible = True                          'Cut
      mnuRightItem(12).Visible = True                          'Copy
      mnuRightItem(13).Visible = True                          'Paste
      mnuRightItem(13).Enabled = (ValidClipboard = kClipboardMenuBar)
      mnuRightItem(14).Visible = True                          'Delete
      mnuRightItem(15).Visible = True                          'Separator
'      mnuRightItem(16).Visible = True                          'Add ->
      mnuRightItem(19).Visible = True                          'Add MenuBar
   Case "menubar"
      mnuRightItem(11).Visible = True                          'Cut
      mnuRightItem(12).Visible = True                          'Copy
      mnuRightItem(13).Visible = True                          'Paste
      mnuRightItem(13).Enabled = (ValidClipboard = kClipboardMenuElem)
      mnuRightItem(14).Visible = True                          'Delete
      mnuRightItem(15).Visible = True                          'Separator
'      mnuRightItem(16).Visible = True                          'Add ->
      mnuRightItem(20).Visible = True                          'Add Dropdown
   Case "menuelem"
      mnuRightItem(1).Visible = True                           'View Code
      mnuRightItem(2).Visible = True                           'Separator
      mnuRightItem(11).Visible = True                          'Cut
      mnuRightItem(12).Visible = True                          'Copy
      mnuRightItem(14).Visible = True                          'Delete
'      mnuRightItem(15).Visible = True                          'Separator
'      mnuRightItem(16).Visible = True                          'Add ->
   Case "bitmap"
      mnuRightItem(16).Visible = True                          'Add ->
      mnuRightItem(25).Visible = True                          'Separator
      mnuRightItem(27).Visible = True                          'Remove Bitmap
   Case "module"
      mnuRightItem(6).Visible = True                           'View Code
      mnuRightItem(10).Visible = True                          'Separator
      mnuRightItem(28).Visible = True                          'Remove Module
   Case "resource"
      mnuRightItem(30).Visible = True                          'Remove Resource
      mnuRightItem(31).Visible = True                          'Separator
   Case Else 'Folders
      mnuRightItem(17).Visible = True                          'Add Form
      mnuRightItem(18).Visible = True                          'Add Menu
      mnuRightItem(21).Visible = True                          'Add Bitmap
      mnuRightItem(22).Visible = True                          'Separator
      mnuRightItem(23).Visible = True                          'Add New Module
      mnuRightItem(24).Visible = True                          'Add Existing Module
      mnuRightItem(26).Visible = False                      'Hide Separator
      mnuRightItem(27).Visible = False                      'Hide Properties
   End Select
   mnuRight.Tag = nClickSource & strGlobalID
   PopupMenu mnuRight
End Sub

Sub UpdateRecent(app As String)  'Manage recent files list
Dim i As Integer
Dim k As Integer
Dim strRecent(20) As String
Dim res As String
   
   strRecent(0) = app
   If Dir(installationDirectory + "\recent.dat", vbNormal) = "" Then
      For i = 1 To UBound(strRecent)
         strRecent(i) = ""
      Next
   Else
      Open installationDirectory + "\recent.dat" For Input As #1
      On Error GoTo nextFile
      For i = 1 To UBound(strRecent)
         Input #1, strRecent(i)
         If Dir(strRecent(i)) = "" Then
            strRecent(i) = ""
         End If
nextFile:
      Next
      On Error GoTo 0
      Close #1
   End If
   
   'Ensure no duplicates...
   For i = 1 To UBound(strRecent)
      If StrComp(strRecent(0), strRecent(i), vbTextCompare) = 0 Then strRecent(i) = ""
   Next

   'Now, write out the pathnames
   Open installationDirectory + "\recent.dat" For Output As #1
   k = 0
   For i = 0 To UBound(strRecent)
      If strRecent(i) <> "" Then
         k = k + 1
         Write #1, strRecent(i)
      End If
   Next
   Do While k < UBound(strRecent)
      Write #1, ""
      k = k + 1
   Loop
   Close #1
   UpdateMRU
End Sub

Private Sub UpdateMRU()
Dim i As Integer
Dim strPath As String

   Open installationDirectory + "\recent.dat" For Input As #1
   For i = 1 To mnuFileMRU.UBound
      Input #1, strPath
      If strPath <> "" And Dir(strPath) <> "" Then
         mnuFileMRU(i).Caption = "&" & i & " " & Mid(strPath, InStrRev(strPath, "\") + 1)
         mnuFileMRU(i).Tag = strPath
         mnuFileMRU(i).Visible = True
      Else
         mnuFileMRU(i).Visible = False
      End If
   Next
   Close #1
   mnuFileBar2.Visible = mnuFileMRU(1).Visible
End Sub
Private Sub UpdateTools()
Dim i As Integer
Dim j As Integer
Dim strPath As String
Dim hFile As Long
Dim WFD As WIN32_FIND_DATA
   
   i = 0
   hFile = FindFirstFile(installationDirectory & "\Tools\*.*", WFD)
   If hFile <> INVALID_HANDLE_VALUE Then
      Do
      strPath = Left(WFD.cFileName, InStr(WFD.cFileName, Chr(0)) - 1)
      If (LCase(Right(strPath, 4)) = ".exe" Or LCase(Right(strPath, 4)) = ".bat" Or LCase(Right(strPath, 4)) = ".lnk") And i < mnuToolsList.UBound Then
         strPath = Mid(strPath, 1, InStrRev(strPath, ".") - 1)
         If strPath = "v_ppc" Then
            mnuRunStartVirtualCE.Visible = True
            mnuToolsBar1.Visible = True
            GoTo skipitem1
         Else
            mnuRunStartVirtualCE.Visible = False
            mnuToolsBar1.Visible = False
         End If
         i = i + 1
         mnuToolsList(i).Caption = strPath
         mnuToolsList(i).Tag = Left(WFD.cFileName, InStr(WFD.cFileName, Chr(0)) - 1)
         mnuToolsList(i).Visible = True
      End If
skipitem1:
         Loop While FindNextFile(hFile, WFD)
      hFile = FindClose(hFile)
   End If
   
   For j = i + 1 To mnuToolsList.UBound
      mnuToolsList(j).Visible = False
   Next
End Sub


Public Function FindNext(ByVal strText As String) As Boolean
   cmaxFind.Text = strText
   FindNext = CMaxFindNext(cmaxFind)
   cmaxFind.Text = ""
End Function

Public Sub ReplaceAll(ByVal strGID As String)
Dim fCode As frmCode
Dim strScript As String
Dim bObject As Boolean
Dim obj As Object

   strScript = Mid(strGID, InStrRev(strGID, "|") + 1)
   If Left(strGID, Len("object")) = "object" Then bObject = True

   Set fCode = GetMDIChild(strGID)
   If fCode Is Nothing Then
      Set obj = LocateObject(strGID)
      If bObject Then
         cmaxFind.Text = obj.obj.GetCode(strScript, False)
      Else
         cmaxFind.Text = obj.GetCode(strScript, False)
      End If
      If cmaxFind.Text = "" Then Exit Sub
      CMaxPrepFindReplace cmaxFind
      cmaxFind.ExecuteCmd cmCmdReplaceAllInBuffer
      If bObject Then
         obj.obj.PutScript cmaxFind.Text, strScript
      Else
         obj.PutScript cmaxFind.Text, strScript
      End If
      cmaxFind.Text = ""
   Else
      CMaxPrepFindReplace fCode.editor
      fCode.editor.ExecuteCmd cmCmdReplaceAllInBuffer
   End If
End Sub

Public Function ShowNewOpen(bShowNew As Boolean, sType As String, strDefExt As String) As String
Dim strRecent As String
Dim strRecentPath As String
Dim s1 As String
Dim s2 As String
Dim i As Integer
Dim p As Integer
Dim arrExt() As String

   frmNewOpen.ShowNew = bShowNew

   If frmNewOpen.ShowNew Then
      frmNewOpen.AddNewType "Standard", "std"
      frmNewOpen.AddNewType "Formless", "nul"
'      frmNewOpen.AddNewType "Project File", "PRJ"
'      frmNewOpen.AddNewType "Text File", "TEXT"
      frmNewOpen.NewImageList = ilsIcons32
   End If

   If Dir(installationDirectory + "\recent.dat", vbNormal) <> "" Then
      Open installationDirectory + "\recent.dat" For Input As #1
      For i = 1 To 20
         Input #1, strRecent
         If strRecent <> "" Then
         On Error GoTo nextFile
            If Dir(strRecent) <> "" Then
               s1 = Mid(strRecent, InStrRev(strRecent, "\") + 1)
               s2 = Left(strRecent, Len(strRecent) - Len(s1))
               frmNewOpen.AddExistItem s1, s2, "PRJ"
               If strRecentPath = "" Then strRecentPath = s2
            End If
         End If
nextFile:
      Next
      On Error GoTo 0
      Close #1
   End If

   frmNewOpen.ExistingImageList = ilsIcons16

   Set frmNewOpen.cD = New cCommonDialog
   'frmNewOpen.cD.InitDir = GlobalPath & "\Projects"
   If strRecentPath <> "" Then frmNewOpen.cD.InitDir = strRecentPath
   frmNewOpen.cD.flags = cdlOFNFileMustExist + cdlOFNPathMustExist
   If sType <> "Project" Then frmNewOpen.cD.flags = frmNewOpen.cD.flags + cdlOFNAllowMultiselect
   
   'Set up filter, default extension, and displayed index in file type picker
   Select Case sType
   Case "Project"
      frmNewOpen.cD.Filter = "Project Files (*" & kProductExtension & ")|*" & kProductExtension & "|Text Files (*.txt)|*.txt|All Files (*.*)|*.*"
   Case "Module"
      frmNewOpen.cD.Filter = "Code Modules (*.bas, *.cod)|*.bas;*.cod|Text Files (*.txt)|*.txt|All Files (*.*)|*.*"
   Case "Resource"
      frmNewOpen.cD.InitDir = gResourceDirectory
      frmNewOpen.cD.Filter = "Resource Files (*.*)|*.*"
   End Select
   frmNewOpen.cD.DefaultExt = Right(strDefExt, 3)
   arrExt = Split(frmNewOpen.cD.Filter, "|", , vbTextCompare)
   For i = 1 To UBound(arrExt) - 1 Step 2
      If InStr(1, arrExt(i), strDefExt, vbTextCompare) > 0 Then Exit For
   Next
   frmNewOpen.cD.FilterIndex = IIf(i < UBound(arrExt), i \ 2 + 1, 1)
   
   frmNewOpen.cD.HookDialog = True

   'Make Dialog owner Me
   frmNewOpen.cD.hWnd = Me.hWnd
   Load frmNewOpen

   frmNewOpen.cD.ShowOpen

   If Not frmNewOpen.Cancelled Then
      ShowNewOpen = frmNewOpen.filename
   
      If sType = "Resource" Then
         p = InStrRev(frmNewOpen.filename, "\") - 1
         gResourceDirectory = Left(frmNewOpen.filename, p)
         If CurDir <> gProjectDir Then 'Property window can change current directory
            If Mid(gProjectDir, 2, 1) = ":" Then ChDrive Left(gProjectDir, 2) 'ignore network drives
            ChDir gProjectDir
         End If
      End If
   End If

   Unload frmNewOpen
   Set frmNewOpen = Nothing
End Function

Public Sub SetCaptions()
Dim frm As Form

   For Each frm In Children
      frm.SetCaption
   Next
   gfProjectExplorer.SetCaption
   gfProjectExplorer.UpdateTarget
   gfProperties.SetCaption
End Sub

Public Sub PutTheCodeBack()
Dim frm As Form

   For Each frm In Children
      If TypeName(frm) = "frmCode" Then frm.PutTheCodeBack
   Next
End Sub
Private Sub mnuRunCEStart_Click()
   'Make sure project is saved
   mnuFileSaveProject_Click
   If gTarget Is Nothing Then Exit Sub
   If Not gTarget.Saved Or gTarget.Dirty Then
      MsgBox gStringTable(3364) '"The project must be saved before it can be run."
      Exit Sub
   End If
#If NSBasic_Desktop Then
   mnuRunDesktop
#End If
#If NSBasic_CE Then
   MakeExe
   MakeInstaller
#End If
End Sub

Private Sub mnuRunDesktop()
Dim res As Integer
Dim outputfile As String
Dim code As String
Dim optionExplicit As String
Dim p As Integer
Dim resource As CResourceFile

   If gbSaveBeforeRun Then gTarget.Save
   'outputFile = Left(gTarget.PathName, Len(gTarget.PathName) - 4) & ".exe"
   If gTarget.MakePath = "" Then gTarget.MakePath = gTarget.PathName
   outputfile = Left(gTarget.MakePath, Len(gTarget.MakePath) - 4) & ".exe"
   code = StripCode(gTarget.Make())
   'res = fnAddscriptV(installationDirectory & "\NSBDesktopRuntime.exe", outputFile, code, gTarget.Icon)
   res = fnAddscriptUTF8(installationDirectory & "\NSBDesktopRuntime.exe", outputfile, code, gTarget.Icon)
   If res <> 0 Then
      Select Case res
         Case 1: MsgBox gStringTable(3448) & installationDirectory & "\NSBDesktopRuntime.exe" 'could not open input file
         Case 2: MsgBox gStringTable(3449) & outputfile 'could not open output file
         Case 3: MsgBox gStringTable(3450) 'AddScript: BeginUpdateResourceA failed.
         Case 4: MsgBox gStringTable(3451) 'AddScript: UpdateResourceA failed.
         Case 5: MsgBox gStringTable(3452) 'AddScript: Icon failed.
      End Select
      Exit Sub
    End If
    
    'Insert Project Properties into the exe file
    If res <> 0 Then
      Select Case res
         Case 1: MsgBox gStringTable(3460) & installationDirectory & "\NSBDesktopRuntime.exe" 'SetVersionEntry: Could not open file to read resource:
         Case 2: MsgBox gStringTable(3455) & outputfile 'SetVersionEntry: could not open output file
         Case 3: MsgBox gStringTable(3456) 'SetVersionEntry: Could not load resource.
         Case 4: MsgBox gStringTable(3457) 'SetVersionEntry: : Resource was empty.
         Case 5: MsgBox gStringTable(3458) 'SetVersionEntry: : Could not open file for writing.
         Case 6: MsgBox gStringTable(3459) 'SetVersionEntry: : Could not update resource.
      End Select
      Exit Sub
    End If
    
    res = setVersionEntry(outputfile, "CompanyName", gTarget.CompanyName)
    'assume if the first one worked, the others will as well
    res = setVersionEntry(outputfile, "FileDescription", gTarget.FileDescription)
    res = setVersionEntry(outputfile, "InternalName", gTarget.Name)
    res = setVersionEntry(outputfile, "OriginalFilename", gTarget.Name)
    res = setVersionEntry(outputfile, "Comments", gTarget.Comments)
    res = setVersionEntry(outputfile, "LegalCopyright", gTarget.LegalCopyright)
    res = setVersionEntry(outputfile, "LegalTrademarks", gTarget.LegalTrademarks)
    res = setVersionEntry(outputfile, "VersionMajor", gTarget.VersionMajor)
    res = setVersionEntry(outputfile, "VersionMinor", gTarget.VersionMinor)
    res = setVersionEntry(outputfile, "Revision", gTarget.Revision)
    res = setVersionEntry(outputfile, "Title", gTarget.Title)
    res = setVersionFixed(outputfile, Val(gTarget.VersionMajor), Val(gTarget.VersionMinor), Val(gTarget.Revision), 0)
    If res <> 0 Then
      Select Case res
         Case 1: MsgBox gStringTable(3454) & installationDirectory & "\NSBDesktopRuntime.exe" 'SetVersionEntry: Could not open file to read resource:
         Case 2: MsgBox gStringTable(3450) 'SetVersionEntry: could not open output file
         Case 3: MsgBox gStringTable(3455) 'SetVersionEntry: Could not load resource.
      End Select
      Exit Sub
   End If
   InjectResources (outputfile)
   If gbActiveSyncRun Then
      Shell Chr(34) & outputfile & Chr(34), vbNormalFocus
   End If

End Sub

Private Function ParseCommandLine()
   Dim CommandLine As String
   Dim p As Integer
   CommandLine = Trim(command())
   If CommandLine = "" Then
      gCommandLineProject = ""
      gCommandLineOptions = ""
   ElseIf Left(CommandLine, 1) = Chr(34) Then  '"programname.prj" option1 option2...
      p = InStr(CommandLine, kProductExtension)
      If p = 0 Then p = InStr(CommandLine, ".txt")
      gCommandLineProject = Mid(CommandLine, 2, p + 2)
      gCommandLineOptions = Trim(Mid(CommandLine, p + 4))
   Else  'programname.prj option1 option2...
      p = InStr(CommandLine, " ")
      If p = 0 Then
         gCommandLineProject = CommandLine
         gCommandLineOptions = ""
      Else
         gCommandLineProject = Trim(Left(CommandLine, p))
         gCommandLineOptions = Trim(Mid(CommandLine, p))
      End If
   End If
   'MsgBox "CommandLine:" & CommandLine & "." & vbCr & "Project:" & gCommandLineProject & "." & vbCr & "Options:" & gCommandLineOptions & "."
End Function

#If 1 = 0 Then
Sub getDependancies()  'Not currently used
'write a list of ActiveX controls to programFile.tmp
'collect ObjectIDs for all controls usedn from AddObject statements
Dim arrCode() As String
Dim stmt As String
Dim objectID As String
Dim CLSID As String
Dim dllList As String
Dim p As Integer
Dim p1 As Integer
Dim p2 As Integer
Dim i As Integer
Dim quote As String
Dim ignoreObjectList
Dim InProcServer32 As String
Dim filename As String

quote = Chr(34)
ignoreObjectList = "checkbox combobox commandbutton date frame label listbox optionbutton output textbox time"
dllList = "mscepicture.dll,mscefile.dll,"

arrCode = Split(LCase(gTarget.GenerateCode()), vbCrLf)
For i = 0 To UBound(arrCode)
   stmt = arrCode(i)
   p = InStr(stmt, "addobject") + 10
   If p = 10 Then GoTo nexti 'not an addobject statement
   If InStr(stmt, "execute") Then p = p + 1
   p1 = InStr(p, stmt, quote)
   p2 = InStr(p1 + 1, stmt, quote)
   If p1 = 0 Or p2 < p1 + 2 Then GoTo nexti 'not a valid object name
   objectID = LCase(Mid(stmt, p1 + 1, p2 - p1 - 1))
   If InStr(ignoreObjectList, objectID) Then GoTo nexti 'not an external object
   Select Case objectID
   Case "ado":
      If InStr(dllList, "adoce31.dll") = 0 Then dllList = dllList & "adoce31.dll,adocedb31.dll,adoceoledb31.dll, msdaer.dll,"
   Case "comm":
       If InStr(dllList, "mscecomm.dll") = 0 Then dllList = dllList & "mscecomm.dll,"
   Case "dialog":
       If InStr(dllList, "mscecomdlg.dll") = 0 Then dllList = dllList & "mscecomdlg.dll,"
   Case "file":
       If InStr(dllList, "mscefile.dll") = 0 Then dllList = dllList & "mscefile.dll,"
   Case "filesystem":
       If InStr(dllList, "mscefile.dll") = 0 Then dllList = dllList & "mscefile.dll,"
   Case "finance":
       If InStr(dllList, "finance.dll") = 0 Then dllList = dllList & "finance.dll,"
   Case "grid":
       If InStr(dllList, "mscegrid.dll") = 0 Then dllList = dllList & "mscegrid.dll,"
   Case "image":
       If InStr(dllList, "msceimage.dll") = 0 Then dllList = dllList & "msceimage.dll,"
   Case "imagelist":
       If InStr(dllList, "msceimagelist.dll") = 0 Then dllList = dllList & "msceimagelist.dll,"
   Case "listview":
       If InStr(dllList, "mscelistview.dll") = 0 Then dllList = dllList & "mscelistview.dll,"
   Case "picturebox":
       If InStr(dllList, "mscepicture.dll") = 0 Then dllList = dllList & "mscepicture.dll,"
   Case "tabstrip":
       If InStr(dllList, "mscetabstrip.dll") = 0 Then dllList = dllList & "mscetabstrip.dll,"
   Case "treeview":
       If InStr(dllList, "mscectreeview.dll") = 0 Then dllList = dllList & "mscetreeview.dll,"
   Case "winsock":
       If InStr(dllList, "mscewinsock.dll") = 0 Then dllList = dllList & "mscewinsock.dll,"
   Case Else:
      'not a standard - need to look it up in registry
      'will only work for controls that also have an entry on the desktop
      If MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "\" & objectID & "\CLSID\") Then
         CLSID = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "\" & objectID & "\CLSID\", "", "")
      Else
         'is there a CurVer key to look up the objectID with?
         If MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "\" & objectID & "\CurVer\") Then
            objectID = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "\" & objectID & "\CurVer\", "", "")
            If MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "\" & objectID & "\CLSID\") Then
               CLSID = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "\" & objectID & "\CLSID\", "", "")
            Else
               If InStr(dllList, objectID) = 0 Then dllList = dllList & objectID & " not found,"
            End If
         Else
            If InStr(dllList, objectID) = 0 Then dllList = dllList & objectID & " not found,"
         End If
      End If
      
      If MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "\CLSID\" & CLSID) Then
         InProcServer32 = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "\CLSID\" & CLSID & "\InProcServer32\", "", "")
         If InStr(dllList, InProcServer32) = 0 Then dllList = dllList & InProcServer32 & ","
      Else
         If InStr(dllList, objectID) = 0 Then dllList = dllList & objectID & " Not found,"
      End If
   End Select
nexti:
Next
      
'write out the result
filename = gTarget.Name & ".tmp"
Open filename For Binary As #1
Put #1, , "NSBVersion " & app.Major & "." & app.Minor & "." & app.Revision & vbCrLf
Put #1, , "[Controls]" & vbCrLf
arrCode = Split(dllList, ",")
For i = 0 To UBound(arrCode) - 1
   Put #1, , arrCode(i) & vbCrLf
Next
Close #1

End Sub
#End If

Sub MakeReadMe()
   'If ReadMe.txt does not exist, make a stub
   If gTarget.ReadMe <> "" And Dir(gTarget.ReadMe) <> "" Then Exit Sub
   If gTarget.ReadMe = "" And Dir("ReadMe.txt") <> "" Then Exit Sub
   Dim FileNumber As Integer
   Dim Data As String
   Dim company As String
   company = gTarget.CompanyName
   If company = "" Then company = gTarget.Name & "Co"
   
   ShowStatus "Making ReadMe File", True
   FileNumber = FreeFile
   
   Data = gStringTable(3480)
   Data = Replace(Data, "%appname%", gTarget.Name)
   Data = Replace(Data, "%companyname%", company)
            
   Open "ReadMe.txt" For Binary As #FileNumber
   Put #FileNumber, , Data
   Close #FileNumber
   
End Sub
Sub MakeEULA()
   'If EULA.txt does not exist, make a stub
   If gTarget.EULA <> "" And Dir(gTarget.EULA) <> "" Then Exit Sub
   If gTarget.EULA = "" And Dir("EULA.txt") <> "" Then Exit Sub
   Dim FileNumber As Integer
   Dim Data As String
   Dim company As String
   company = gTarget.CompanyName
   If company = "" Then company = gTarget.Name & "Co"
   
   ShowStatus "Making EULA File", True
   FileNumber = FreeFile
   Data = gStringTable(3481)
   Data = Replace(Data, "%appname%", gTarget.Name)
   Data = Replace(Data, "%companyname%", company)
            
   Open "EULA.txt" For Binary As #FileNumber
   Put #FileNumber, , Data
   Close #FileNumber
End Sub
Sub MakeAppInf()

   Dim FileNumber As Integer
   Dim Data As String
   Dim inFile As String
   Dim progfiles As String
   Dim progfilesInstallList As String
   Dim DllFiles As String
   Dim registerList As String
   Dim WindowsInstallList As String
   Dim i As Integer
   Dim s() As String
   Dim company As String
   Dim Title As String
   Dim File As String
   Dim directory As String
   Dim p As Integer
   Dim flags As String
   Dim res As CResourceFile
   Dim Count As Integer
   Dim appdirs As String
   Dim Files As String
   Dim installToFiles As String
   Dim windowsFiles As String
   Dim Path As String
   Dim allowedcharacters As String
   Dim InstallDir As String
   Dim DirToInstall_FileList() As String
   Dim DirToInstallDir As String
   Dim DirList() As String
   Dim fromDir
   Dim copyFiles
   Dim iconPath As String
   Dim iconName As String
   
   ShowStatus "Modifying AppInf File", True

   company = gTarget.CompanyName
   If company = "" Then company = gTarget.Name & "Co"
   Title = gTarget.Title
   If Title = "" Then Title = gTarget.Name
         
   If Not isValidPath(CurDir) Then Exit Sub
   
   'prepare file data for main exe file
   Count = 2
   installToFiles = Chr(34) & gTarget.Name & ".exe" & Chr(34) & ",,,0x00000000" & vbCrLf
   Files = gTarget.Name & ".exe = " & Count & vbCrLf
   p = InStrRev(gTarget.PathName, "\")
   If p = 0 Then p = 2 'if path is something like c:\file
   directory = Left(gTarget.PathName, p - 1)
   appdirs = Count & " =, " & Chr(34) & "File " & Count & Chr(34) & ",," & directory & vbCrLf
   
   'If there is a name.png file, add it to the installer
   iconName = gTarget.Name & ".png"
   iconPath = CurDir
   If Dir(iconPath & "\" & iconName) = "" Then
      'if it doesn't exist the home directory, look for it with the icon
      If InStr(gTarget.Icon, ":") Then
         iconPath = gTarget.Icon 'absolution path
      Else
         iconPath = Replace(CurDir & "\" & gTarget.Icon, ".\", "") 'relative path
      End If
      iconPath = Left(iconPath, InStrRev(iconPath, "\") - 1)
   End If
   
   If Dir(iconPath & "\" & iconName) <> "" Then
      Count = Count + 1
      appdirs = appdirs & Count & " =, " & Chr(34) & "File " & Count & Chr(34) & ",," & iconPath & vbCrLf 'directory to find icon
      Files = Files & iconName & " = " & Count & vbCrLf 'the name of the icon
      installToFiles = installToFiles & Chr(34) & iconName & Chr(34) & ",,,0x00000000" & vbCrLf
   End If
   
   'prepare file data for additional files
   registerList = ""
   windowsFiles = ""
   For Each res In gTarget.ResourceFiles
      If res.ResType = 3 Then 'installer resources only
         If Left(LCase(res.PathName), 10) = "{controls}" Then
            Path = installationDirectory & "\controls\" & getPlatform & "\" & Mid(res.PathName, 12)
         Else
            Path = GetAbsolutePath(res.PathName, "")
         End If
         If Not isValidPath(Path) Then Exit Sub
        
         If Dir(Path) = "" Then 'File not found:
            MsgBox "MakeAppInf:" & gStringTable(3483) & Path & vbCrLf _
            & "installationDirectory=" & installationDirectory & vbCrLf _
            & "res.PathName=" & res.PathName
            Exit Sub
         End If
         
         p = InStrRev(Path, "\")
         If p = 0 Then p = 2 'if path is something like c:\file
         directory = Left(Path, p - 1)
         File = Mid(Path, p + 1)
         Count = Count + 1
         appdirs = appdirs & Count & " =, " & Chr(34) & "File " & Count & Chr(34) & ",," & directory & vbCrLf
         Files = Files & File & "=" & Count & vbCrLf
         
         If res.installTo = 0 Then
            installToFiles = installToFiles & Chr(34) & File & Chr(34) & ",,,0x00000000" & vbCrLf
         Else
            If res.sharedFile Then
               flags = ",,,0x80000000"
            Else
               flags = ",,,0x00000000"
            End If
            windowsFiles = windowsFiles & Chr(34) & File & Chr(34) & flags & vbCrLf
         End If
         
         If res.register Then
            registerList = registerList & "," & File
         End If
      End If
   Next
   
   If gTarget.InstallDir <> "" Then
      InstallDir = gTarget.InstallDir
   Else
      InstallDir = gTarget.Name
   End If
      
   DirList = Split(gTarget.DirToInclude, ",")
   DirToInstallDir = ""
   copyFiles = ""
   For Each fromDir In DirList
      fromDir = Trim(fromDir)
      DirToInstall_FileList = getDirToInstall_FileList(fromDir)
      If UBound(DirToInstall_FileList) > 0 Then
         Count = Count + 1
         p = InStrRev(gTarget.PathName, "\")
         If p = 0 Then p = 2 'if path is something like c:\file
         directory = Left(gTarget.PathName, p - 1)
         DirToInstallDir = DirToInstallDir & vbCrLf & "Files." & fromDir & " =    0,%InstallDir%" & "\" & InstallDir & "\" & fromDir
         appdirs = appdirs & Count & " =, " & Chr(34) & fromDir & Chr(34) & ",," & directory & "\" & fromDir & vbCrLf
         installToFiles = installToFiles & vbCrLf & "; Install into \Program Files\" & InstallDir & "\" & fromDir & vbCrLf
         installToFiles = installToFiles & "[Files." & fromDir & "]" & vbCrLf
         copyFiles = copyFiles & ",Files." & fromDir
         For i = 1 To UBound(DirToInstall_FileList)
            If DirToInstall_FileList(i) <> iconName Then
               Files = Files & DirToInstall_FileList(i) & " = " & Count & vbCrLf
               installToFiles = installToFiles & Chr(34) & DirToInstall_FileList(i) & Chr(34) & ",,,0x00000000" & vbCrLf
            End If
         Next
      End If
   Next
   
   'Read in the template
   inFile = installationDirectory & "\App_Template.inf"
   FileNumber = FreeFile
   Open inFile For Binary Access Read As #FileNumber
   Data = String$(LOF(FileNumber), 32) 'fill buffer before reading
   Get #FileNumber, , Data
   Close #FileNumber
   
   'do substitutions
   Data = Replace(Data, "%companyname%", company)
   Data = Replace(Data, "%apptitle%", Title)
   Data = Replace(Data, "%appdir%", CurDir)
   Data = Replace(Data, "%platform%", getPlatform)
   Data = Replace(Data, "%platformName%", getPlatformName)
   Data = Replace(Data, "%processorType%", getProcessorType)
   Data = Replace(Data, "%controlsdir%", installationDirectory & "\controls\" & getPlatform)
   Data = Replace(Data, "%appname%", gTarget.Name)
   Data = Replace(Data, "%registerlist%", registerList)
   Data = Replace(Data, "%files%", Files)
   Data = Replace(Data, "%appdirs%", appdirs)
   Data = Replace(Data, "%installToFiles%", installToFiles)
   Data = Replace(Data, "%dirtoinstalldir%", DirToInstallDir)
   Data = Replace(Data, "%windowsFiles%", windowsFiles)
   Data = Replace(Data, "%deviceInstallDir%", InstallDir)
   Data = Replace(Data, "%copyfiles%", copyFiles)
   
   'Delete the old file and write out the new one
   On Error Resume Next
   Kill "App.inf"
   On Error GoTo 0
   
   'write out the new file
   Open "App.inf" For Binary As #FileNumber
   Put #FileNumber, , Data
   Close #FileNumber
   
End Sub
Function getDirToInstall_FileList(fromDir) As String()
'returns a string with info based on DirToInstall
'element 0 is the name of the directory
'element 1 to n are the file names in the directory
Dim Cmd As String
Dim FileNumber As Integer
Dim s As String
Dim Files As String
Dim i As Integer
Dim res As Integer
Dim p As Integer
Dim directory As String
Dim q As String
FileNumber = FreeFile
q = Chr(34)

   getDirToInstall_FileList = Split("")
   If fromDir = "" Then Exit Function
   
   p = InStrRev(gTarget.PathName, "\")
   If p = 0 Then p = 2 'if path is something like c:\file
   directory = Left(gTarget.PathName, p)
   
   On Error Resume Next
   Kill "cmd.bat"
   Kill "FileList.tmp"
   On Error GoTo 0
   Open "cmd.bat" For Binary As #FileNumber
   s = "dir /B " & q & directory & fromDir & q & " > " & q & directory & "FileList.tmp" & q
   Put #FileNumber, , s
   Close #FileNumber
   
   res = ExecCmd("cmd.bat")
   
   Open directory & "FileList.tmp" For Input As #FileNumber
   i = 1
   Files = ""
   Do While Not EOF(FileNumber)
      Input #1, s
      Files = Files & "," & s
      i = i + 1
   Loop
   Close #FileNumber
   Kill "cmd.bat"
   Kill "FileList.tmp"
   
   If i > 1 Then Files = fromDir & Files
   getDirToInstall_FileList = Split(Files, ",")

End Function
Function isValidPath(s As String) As Boolean
Dim i As Integer
Dim allowedcharacters As String
'CabWiz does not allow special characters in file names. Need to check them.

   allowedcharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_.\:()- "
   
   For i = 1 To Len(s)
      If InStr(allowedcharacters, Mid(s, i, 1)) = 0 Then
         MsgBox gStringTable(3496) & Mid(s, i, 1) & vbCrLf & s 'Illegal character in path
         isValidPath = False
         Exit Function
      End If
   Next
   isValidPath = True
End Function

Sub MakeAppIni()
   Dim FileNumber As Integer
   Dim Data As String
   Dim Title As String
   Title = IIf(gTarget.Title = "", gTarget.Name, gTarget.Title)
   
   ShowStatus "Making ini File", True
   FileNumber = FreeFile
   
   Data = "[CEAppManager]" & vbCrLf
   Data = Data & "Version = 1.0" & vbCrLf
   Data = Data & "Component = " & Title & vbCrLf & vbCrLf
   Data = Data & "[" & Title & "]" & vbCrLf
   Data = Data & "Description = App" & vbCrLf
   Data = Data & "CabFiles = App." & getPlatform & ".cab" & vbCrLf
   
   On Error Resume Next
   Kill "App.ini"
   On Error GoTo 0
   
   Open "App.ini" For Binary As #FileNumber
   Put #FileNumber, , Data
   Close #FileNumber
End Sub
Sub MakeAppBat()
   Dim FileNumber As Integer
   Dim Data As String
   Dim EULA As String
   Dim ReadMe As String
   Dim language As String
   Dim compress As String
   Dim Title As String
   
   ShowStatus "Making Bat File", True
      
   EULA = gTarget.EULA
   If EULA = "" Then EULA = "EULA.txt"
   ReadMe = gTarget.ReadMe
   If ReadMe = "" Then ReadMe = "ReadMe.txt"
   Select Case gnLanguage
      Case 0: language = "english"
      Case 1: language = "german"
      Case 2: language = "french"
      Case 3: language = "italien"
      Case 4: language = "swedish"
      Case 5: language = "portuguese"
      Case 6: language = "spanish"
   End Select
   compress = IIf(gbCompressCab, " /compress", "")
   Title = gTarget.Title
   If Title = "" Then Title = gTarget.Name
   
   Data = ""
   Data = Data & Chr(34) & installationDirectory & "\cabwiz" & Chr(34) & " App.inf /postxml Shortcut.XML /err InstallerCabWiz.log /cpu " & getPlatform & compress & vbCrLf
   Data = Data & "copy " & Chr(34) & installationDirectory & "\ezsetup.exe" & Chr(34) & " ." & vbCrLf
   Data = Data & "ezsetup -l " & language & " -i App.ini -r " & ReadMe & " -e " & EULA & " -o App.Installer.exe" & vbCrLf
   Data = Data & "del /Q *.tmp  ezsetup.exe" & vbCrLf
   Data = Data & "move /Y App." & getPlatform & ".CAB " & Chr(34) & gTarget.Name & ".Installer.cab" & Chr(34) & vbCrLf
   Data = Data & "move /Y App.Installer.exe " & Chr(34) & Title & ".Installer.exe" & Chr(34) & vbCrLf
   
   On Error Resume Next
   Kill "App.bat"
   On Error GoTo 0
   
   FileNumber = FreeFile
   Open "App.bat" For Binary As #FileNumber
   Put #FileNumber, , Data
   Close #FileNumber
End Sub
Sub MakeShortcutXML()
   Dim FileNumber As Integer
   Dim Data As String
   Dim Title As String
   Dim InstallDir As String
   
   Title = gTarget.Title
   If Title = "" Then Title = gTarget.Name
   InstallDir = gTarget.InstallDir
   If InstallDir = "" Then InstallDir = gTarget.Name

   
   ShowStatus "Making Shortcut.XML File", True
   FileNumber = FreeFile
   
   Data = Data & "<characteristic type=""FileOperation"">" & vbCrLf
   Data = Data & "<characteristic type=""%CE11%"" translation=""install"">" & vbCrLf
   Data = Data & "<characteristic type=""MakeDir"" />" & vbCrLf
   Data = Data & "<characteristic type=""" & Title & ".lnk"" translation=""install"">" & vbCrLf
   Data = Data & "<characteristic type=""Shortcut"">" & vbCrLf
   Data = Data & "<parm name=""Source"" value=""%InstallDir%\" & InstallDir & "\" & gTarget.Name & ".exe"" translation=""install"" />" & vbCrLf
   Data = Data & "</characteristic>" & vbCrLf
   Data = Data & "</characteristic>" & vbCrLf
   Data = Data & "</characteristic>" & vbCrLf
   Data = Data & "</characteristic>" & vbCrLf
 
   On Error Resume Next
   Kill "Shortcut.XML"
   On Error GoTo 0
   
   Open "Shortcut.XML" For Binary As #FileNumber
   Put #FileNumber, , Data
   Close #FileNumber
End Sub
Private Function CompileImmediately()
gbActiveSyncRun = False
gbCompiling = True
#If NSBasic_Desktop Then
   mnuRunDesktop
#End If
#If NSBasic_CE Then
   MakeExe
   MakeInstaller
#End If

Dim frm As Form
For Each frm In Forms
   If frm.Name <> "frmMain" Then
      Unload frm
      Set frm = Nothing
   End If
Next
Unload Me
End Function

