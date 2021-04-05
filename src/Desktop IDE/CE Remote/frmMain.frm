VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmMain 
   Caption         =   "NS Basic/CE Remote"
   ClientHeight    =   7095
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5775
   LinkTopic       =   "Form1"
   ScaleHeight     =   7095
   ScaleWidth      =   5775
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame Frame3 
      Caption         =   "Remote Execute"
      Height          =   1815
      Left            =   120
      TabIndex        =   20
      Top             =   5160
      Width           =   5535
      Begin VB.TextBox txtLaunch 
         Height          =   285
         Left            =   120
         TabIndex        =   14
         Text            =   "\Windows\pxl.exe"
         Top             =   480
         Width           =   4815
      End
      Begin VB.CommandButton cmdExecute 
         Height          =   495
         Left            =   5040
         Picture         =   "frmMain.frx":0000
         Style           =   1  'Graphical
         TabIndex        =   17
         ToolTipText     =   "Remote Execute"
         Top             =   360
         Width           =   375
      End
      Begin VB.TextBox txtFile 
         Height          =   285
         Left            =   120
         TabIndex        =   16
         Text            =   "Book1.pxl"
         Top             =   1200
         Width           =   4815
      End
      Begin VB.Label Label6 
         AutoSize        =   -1  'True
         Caption         =   "Pro&gram:"
         Height          =   195
         Left            =   120
         TabIndex        =   13
         Top             =   240
         Width           =   630
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "Co&mmand:"
         Height          =   195
         Left            =   120
         TabIndex        =   15
         Top             =   960
         Width           =   750
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Remote File Copy"
      Height          =   1815
      Left            =   120
      TabIndex        =   19
      Top             =   3120
      Width           =   5535
      Begin VB.TextBox txtSource 
         Height          =   285
         Left            =   120
         TabIndex        =   8
         Top             =   480
         Width           =   4815
      End
      Begin VB.TextBox txtDestination 
         Height          =   285
         Left            =   120
         TabIndex        =   11
         Text            =   "\My Documents"
         Top             =   1200
         Width           =   4815
      End
      Begin VB.CommandButton cmdBrowse 
         Caption         =   ".&.."
         Height          =   495
         Left            =   5040
         TabIndex        =   9
         ToolTipText     =   "Browse local files"
         Top             =   360
         Width           =   375
      End
      Begin VB.CommandButton cmdUpload 
         Height          =   495
         Left            =   5040
         Picture         =   "frmMain.frx":0442
         Style           =   1  'Graphical
         TabIndex        =   12
         ToolTipText     =   "Upload to device"
         Top             =   1080
         Width           =   375
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Local &Source:"
         Height          =   195
         Left            =   120
         TabIndex        =   7
         Top             =   240
         Width           =   990
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "Remote De&stination Folder:"
         Height          =   195
         Left            =   120
         TabIndex        =   10
         Top             =   960
         Width           =   1920
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Remote Connection"
      Height          =   2295
      Left            =   120
      TabIndex        =   18
      Top             =   120
      Width           =   5535
      Begin VB.ComboBox cmbPlatforms 
         Height          =   315
         Left            =   120
         Sorted          =   -1  'True
         Style           =   2  'Dropdown List
         TabIndex        =   1
         Top             =   480
         Width           =   5295
      End
      Begin VB.ComboBox cmbDevices 
         Height          =   315
         Left            =   120
         Style           =   2  'Dropdown List
         TabIndex        =   3
         Top             =   1200
         Width           =   5295
      End
      Begin VB.CommandButton cmdConnect 
         Caption         =   "&Connect"
         Height          =   375
         Left            =   1080
         TabIndex        =   4
         Top             =   1680
         Width           =   1215
      End
      Begin VB.CommandButton cmdDisconnect 
         Caption         =   "&Disconnect"
         Height          =   375
         Left            =   3240
         TabIndex        =   5
         Top             =   1680
         Width           =   1215
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         Caption         =   "&Platform:"
         Height          =   195
         Left            =   120
         TabIndex        =   0
         Top             =   240
         Width           =   615
      End
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         Caption         =   "De&vice:"
         Height          =   195
         Left            =   120
         TabIndex        =   2
         Top             =   960
         Width           =   555
      End
   End
   Begin MSComDlg.CommonDialog dlgCommon 
      Left            =   0
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton cmdInstall 
      Caption         =   "&Install NS Basic"
      Height          =   315
      Left            =   2160
      TabIndex        =   6
      Top             =   2640
      Width           =   1575
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public CERem As CCERemote2

Private Sub cmdBrowse_Click()
   dlgCommon.FileName = txtSource.Text
   dlgCommon.DefaultExt = ".nsb"
   dlgCommon.Filter = "NS Basic Files (*.nsb)|*.nsb|Text Files (*.txt)|*.txt|All Files|*.*"
   dlgCommon.FilterIndex = 1
   dlgCommon.ShowOpen
   txtSource.Text = dlgCommon.FileName
   txtSource.Tag = dlgCommon.FileTitle
End Sub

Private Sub cmdConnect_Click()
   CERem.StorePrefs
   CERem.Connect
End Sub

Private Sub cmdDisconnect_Click()
   CERem.Disconnect
End Sub

Private Sub cmdExecute_Click()
   CERem.Execute txtLaunch.Text, txtFile.Text
End Sub

Private Sub cmdInstall_Click()
   CERem.NSBInstall
End Sub

Private Sub cmdUpload_Click()
Dim strDestination As String

   If txtSource.Text = "" Then
      MsgBox "No source file selected."
      Exit Sub
   End If
   If Right(txtDestination.Text, 1) = "\" Then
      strDestination = txtDestination.Text & txtSource.Tag
   Else
      strDestination = txtDestination.Text & "\" & txtSource.Tag
   End If
   
   CERem.FileCopy txtSource, strDestination
End Sub

Private Sub Form_Load()
   MWinReg.hKey = HKEY_CURRENT_USER
   MWinReg.SubKey = "Software\NSBasic\CE"
   Set CERem = New CCERemote2
   CERem.Attach cmbPlatforms, cmbDevices
End Sub


