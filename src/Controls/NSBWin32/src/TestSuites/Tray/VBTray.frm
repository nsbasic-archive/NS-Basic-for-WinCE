VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5625
   ClientLeft      =   60
   ClientTop       =   375
   ClientWidth     =   8580
   LinkTopic       =   "Form1"
   ScaleHeight     =   5625
   ScaleWidth      =   8580
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox TextBox1 
      Height          =   375
      Left            =   1920
      TabIndex        =   4
      Text            =   "Text1"
      Top             =   600
      Width           =   3135
   End
   Begin VB.CommandButton CommandButton4 
      Caption         =   "Command1"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   600
      Width           =   1695
   End
   Begin VB.CommandButton CommandButton3 
      Caption         =   "Command3"
      Height          =   375
      Left            =   1920
      TabIndex        =   2
      Top             =   120
      Width           =   1815
   End
   Begin VB.CommandButton CommandButton2 
      Caption         =   "Command2"
      Height          =   375
      Left            =   6360
      TabIndex        =   1
      Top             =   120
      Width           =   1815
   End
   Begin VB.CommandButton CommandButton1 
      Caption         =   "Command1"
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "Label1"
      Height          =   375
      Left            =   240
      TabIndex        =   5
      Top             =   1800
      Width           =   7815
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim nImage
Dim WithEvents MyTray As Tray
Attribute MyTray.VB_VarHelpID = -1
Sub CommandButton1_Click()
   MyTray.Image = 1
End Sub
Sub CommandButton2_Click()
   MyTray.Image = 0
End Sub
Sub CommandButton3_Click()
   MyTray.Image = 2
End Sub

Sub CommandButton4_Click()
   MyTray.Tip = TextBox1.Text
End Sub

Private Sub Form_Load()
   Set MyTray = New Tray
   nImage = MyTray.AddImage("traysample.bmp")
End Sub

Private Sub MyTray_Click(ByVal pSender As Object)
    Label1.Caption = "Left mouse button Click"
End Sub
Private Sub MyTray_DblClick(ByVal pSender As Object)
    Label1.Caption = "Left mouse button double click"
End Sub

Private Sub MyTray_KeyDown(ByVal pSender As Object)
    Label1.Caption = "Keyboard button has been pressed over the tray icon"
End Sub

Private Sub MyTray_RClick(ByVal pSender As Object)
    Label1.Caption = "Right mouse button click"
End Sub

Private Sub MyTray_RDblClick(ByVal pSender As Object)
    Label1.Caption = "Right mouse button double click"
End Sub
