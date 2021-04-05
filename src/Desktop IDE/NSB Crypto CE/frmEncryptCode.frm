VERSION 5.00
Begin VB.Form frmEncryptCode 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Code"
   ClientHeight    =   4920
   ClientLeft      =   2565
   ClientTop       =   1500
   ClientWidth     =   6150
   Icon            =   "frmEncryptCode.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4920
   ScaleWidth      =   6150
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.TextBox txtCode 
      Height          =   4215
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   120
      Width           =   5895
   End
   Begin VB.CommandButton btnCancel 
      Cancel          =   -1  'True
      Caption         =   "&Cancel"
      Height          =   375
      Left            =   4920
      TabIndex        =   3
      Top             =   4455
      Width           =   1095
   End
   Begin VB.CommandButton btnEncrypt 
      Caption         =   "&Encrypt"
      Height          =   375
      Left            =   3720
      TabIndex        =   2
      Top             =   4455
      Width           =   1095
   End
   Begin VB.CommandButton btnSave 
      Caption         =   "&Save"
      Height          =   375
      Left            =   2490
      TabIndex        =   1
      Top             =   4455
      Width           =   1095
   End
End
Attribute VB_Name = "frmEncryptCode"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Public FileName As String
Public SerialNumber As Double
Public ReturnValue As Integer

Private Sub btnSave_Click()
   ReturnValue = WriteFile(txtCode.Text, FileName, SerialNumber, IIf(LCase(Right(FileName, 3)) = "txt", nsbfftext, nsbFFNormal))
   Unload Me
End Sub

Private Sub btnEncrypt_Click()
   ReturnValue = WriteFile(txtCode.Text, FileName, SerialNumber, IIf(LCase(Right(FileName, 3)) = "txt", nsbfftext, nsbFFEncrypted))
   Unload Me
End Sub

Private Sub btnCancel_Click()
   ReturnValue = nsbFFUnopened
   Unload Me
End Sub

Private Sub Form_Load()
    'center the form
    Me.Move (Screen.Width - Me.Width) / 2, (Screen.Height - Me.Height) / 2
    Me.Caption = "Code: " & FileName
End Sub

