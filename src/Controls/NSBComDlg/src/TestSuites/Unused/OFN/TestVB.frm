VERSION 5.00
Object = "{6A6D1995-8DDD-4262-8C6A-126F176C1362}#1.0#0"; "Desk.dll"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3165
   ClientLeft      =   60
   ClientTop       =   375
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3165
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   735
      Left            =   2880
      TabIndex        =   0
      Top             =   240
      Width           =   1575
   End
   Begin DESKLibCtl.NSComDlg NSComDlg1 
      Left            =   120
      Top             =   120
      _cx             =   1085
      _cy             =   1085
      CancelError     =   0   'False
      FileName        =   ""
      DialogTitle     =   ""
      Filter          =   ""
      DefaultExt      =   ""
      InitDir         =   ""
      Color           =   0
      FontName        =   ""
      FontBold        =   0   'False
      FontItalic      =   0   'False
      FontStrikeThru  =   0   'False
      FontUnderLine   =   0   'False
      Min             =   8
      Max             =   72
      FilterIndex     =   0
      FontSize        =   8
      FileTitle       =   ""
      Charset         =   1
      Action          =   0
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    NSComDlg1.ShowOpen
End Sub
