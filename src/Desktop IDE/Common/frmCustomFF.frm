VERSION 5.00
Begin VB.Form frmCustomFF 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Custom Form Factor"
   ClientHeight    =   2655
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   4815
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2655
   ScaleWidth      =   4815
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CheckBox chkMenuTop 
      Caption         =   "3433 (&Menu at Top)"
      Height          =   255
      Left            =   240
      TabIndex        =   8
      Tag             =   "3433"
      Top             =   1560
      Width           =   2655
   End
   Begin VB.TextBox txtHeight 
      Height          =   285
      Left            =   2520
      TabIndex        =   7
      Text            =   "320"
      Top             =   1080
      Width           =   2055
   End
   Begin VB.TextBox txtWidth 
      Height          =   285
      Left            =   240
      TabIndex        =   5
      Text            =   "240"
      Top             =   1080
      Width           =   2055
   End
   Begin VB.TextBox txtName 
      Height          =   285
      Left            =   240
      TabIndex        =   3
      Text            =   "Custom 1"
      Top             =   360
      Width           =   4335
   End
   Begin VB.CommandButton btnCancel 
      Cancel          =   -1  'True
      Caption         =   "1135 (Cancel)"
      Height          =   375
      Left            =   3360
      TabIndex        =   1
      Tag             =   "1135"
      Top             =   2160
      Width           =   1215
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "1106 (OK)"
      Default         =   -1  'True
      Height          =   375
      Left            =   2040
      TabIndex        =   0
      Tag             =   "1106"
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "3432 (&Height in Pixels:)"
      Height          =   195
      Left            =   2520
      TabIndex        =   6
      Tag             =   "3432"
      Top             =   840
      Width           =   1620
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "3431 (&Width in Pixels:)"
      Height          =   195
      Left            =   240
      TabIndex        =   4
      Tag             =   "3431"
      Top             =   840
      Width           =   1575
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "3430 (Name:)"
      Height          =   195
      Left            =   240
      TabIndex        =   2
      Tag             =   "3430"
      Top             =   120
      Width           =   960
   End
End
Attribute VB_Name = "frmCustomFF"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub btnCancel_Click()
   Unload Me
End Sub

Private Sub btnOK_Click()
Dim strTemp As String

   'Validate all entries
   If txtName.Text = "" Then
      MsgBox gStringTable(3421) '"Form Factor must be named", vbOKOnly + vbCritical
      txtName.SetFocus
      Exit Sub
   End If
   If Val(txtWidth.Text) <= 0 Then
      MsgBox gStringTable(3421) '"Form Factor Width must be greater than 0", vbOKOnly + vbCritical
      txtWidth.SetFocus
      Exit Sub
   End If
   If Val(txtHeight.Text) <= 0 Then
      MsgBox gStringTable(3421) '"Form Factor Height must be greater than 0", vbOKOnly + vbCritical
      txtHeight.SetFocus
      Exit Sub
   End If

   'All is well, save the registry info and get out
   'Add to list
   strTemp = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Form Factors", "Pocket PC|Handheld PC")
   strTemp = strTemp & "|" & txtName.Text
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Form Factors", strTemp
   'X Y M
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", txtName.Text & " X", CInt(Val(txtWidth.Text))
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", txtName.Text & " Y", CInt(Val(txtHeight.Text))
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", txtName.Text & " M", IIf(chkMenuTop.Value <> 0, "Top", "Bottom")
   Unload Me
End Sub

Private Sub Form_Load()
Dim i As Integer
   LoadResStrings Me, False

   'Find the first unused Custom "Custom 1", "Custom 2", ...
   'RES: Custom
   For i = 1 To 100
      If Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Custom " & i & " X", "-1")) < 0 Then Exit For
   Next
   txtName = "Custom " & i
End Sub
