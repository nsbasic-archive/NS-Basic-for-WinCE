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
      Left            =   2040
      TabIndex        =   2
      Top             =   960
      Width           =   1935
   End
   Begin S309TIMERLib.S309Timer S309Timer1 
      Height          =   735
      Left            =   240
      TabIndex        =   0
      Top             =   1200
      Width           =   735
      _Version        =   65541
      _ExtentX        =   1296
      _ExtentY        =   1296
      _StockProps     =   0
   End
   Begin VB.Label Label1 
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   3615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Me.S309Timer1.Enabled = False
    Me.S309Timer1.Enabled = True
End Sub

Private Sub S309Timer1_Timer()
        Me.Label1.Caption = CStr(Now)
End Sub
