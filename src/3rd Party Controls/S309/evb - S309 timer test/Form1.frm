VERSION 5.00
Object = "{0C993DA3-484A-11D3-AE2D-00608CC1DD62}#1.5#0"; "S309TI~1.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   615
      Left            =   2760
      TabIndex        =   0
      Top             =   360
      Width           =   1575
   End
   Begin S309TIMERLib.S309Timer S309Timer1 
      Height          =   1125
      Left            =   600
      TabIndex        =   1
      Top             =   240
      Width           =   1440
      _Version        =   65541
      _ExtentX        =   2540
      _ExtentY        =   1984
      _StockProps     =   0
      Count           =   2
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Me.S309Timer1.Enabled = Not Me.S309Timer1.Enabled
    MsgBox CStr(Me.S309Timer1.Enabled)
    Me.S309Timer1.Interval = 1000
End Sub

Private Sub S309Timer1_Timer()
    Me.Command1.Caption = "timer"
End Sub
