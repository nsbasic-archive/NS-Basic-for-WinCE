VERSION 5.00
Begin VB.Form frmAbout 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "About NS Basic/CE"
   ClientHeight    =   3660
   ClientLeft      =   45
   ClientTop       =   300
   ClientWidth     =   6675
   ClipControls    =   0   'False
   Icon            =   "frmAbout.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3660
   ScaleWidth      =   6675
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Tag             =   "3453"
   Begin VB.CommandButton cmdOK 
      Cancel          =   -1  'True
      Caption         =   "1404[OK]"
      Default         =   -1  'True
      Height          =   345
      Left            =   5040
      TabIndex        =   5
      Tag             =   "1404"
      Top             =   2655
      Width           =   1467
   End
   Begin VB.TextBox txtWarning 
      Height          =   1575
      Left            =   240
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   4
      Tag             =   "1403"
      Text            =   "frmAbout.frx":5C12
      Top             =   2040
      Width           =   4695
   End
   Begin VB.PictureBox picIcon 
      AutoSize        =   -1  'True
      BackColor       =   &H00C0C0C0&
      ClipControls    =   0   'False
      Height          =   1605
      Left            =   240
      Picture         =   "frmAbout.frx":5C26
      ScaleHeight     =   1545
      ScaleMode       =   0  'User
      ScaleWidth      =   1290
      TabIndex        =   0
      TabStop         =   0   'False
      Top             =   240
      Width           =   1350
   End
   Begin VB.Label lblDescription 
      Caption         =   "1122[App Description]"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   8.25
         Charset         =   238
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   690
      Left            =   1800
      TabIndex        =   3
      Tag             =   "1122"
      Top             =   1200
      Width           =   4695
   End
   Begin VB.Label lblTitle 
      Caption         =   "1120[Application Title]"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   13.5
         Charset         =   238
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   480
      Left            =   1800
      TabIndex        =   2
      Tag             =   "1120"
      Top             =   240
      Width           =   3255
   End
   Begin VB.Line Line1 
      BorderColor     =   &H00808080&
      BorderStyle     =   6  'Inside Solid
      Index           =   1
      X1              =   225
      X2              =   6480
      Y1              =   2040
      Y2              =   2040
   End
   Begin VB.Line Line1 
      BorderColor     =   &H00FFFFFF&
      BorderWidth     =   2
      Index           =   0
      X1              =   240
      X2              =   6480
      Y1              =   2040
      Y2              =   2040
   End
   Begin VB.Label lblVersion 
      Caption         =   "1120[Version]"
      Height          =   225
      Left            =   1800
      TabIndex        =   1
      Tag             =   "1120"
      Top             =   840
      Width           =   3735
   End
End
Attribute VB_Name = "frmAbout"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
   LoadResStrings Me, False
   Set picIcon.Picture = LoadPicture(installationDirectory & gStringTable(3410))
   'put beta version message here...
   #If NSBasic_Desktop Then
      lblVersion.Caption = lblVersion.Caption & " " & app.Major & "." & app.Minor & "." & app.Revision & "b" '& " Beta 5" 'beta message
   #Else
      lblVersion.Caption = lblVersion.Caption & " " & app.Major & "." & app.Minor & "." & app.Revision & "b"  '& " Beta 1" 'beta message
   #End If
   If allowRegistration = 0 Then lblVersion.Caption = lblVersion.Caption & " Demo"
End Sub

Private Sub cmdOK_Click()
   Unload Me
End Sub

