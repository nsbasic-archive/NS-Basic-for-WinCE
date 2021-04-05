VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   10710
   ClientLeft      =   60
   ClientTop       =   375
   ClientWidth     =   12240
   LinkTopic       =   "Form1"
   ScaleHeight     =   10710
   ScaleWidth      =   12240
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   3600
      TabIndex        =   8
      Text            =   "Text4"
      Top             =   6360
      Width           =   1455
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   2640
      TabIndex        =   6
      Text            =   "1"
      Top             =   6360
      Width           =   615
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Command3"
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   6360
      Width           =   1575
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1800
      TabIndex        =   4
      Text            =   "Text2"
      Top             =   5280
      Width           =   1815
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Command2"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   5280
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1800
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   4680
      Width           =   1815
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   4680
      Width           =   1575
   End
   Begin MSComctlLib.ListView ListView1 
      Height          =   4455
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   7815
      _ExtentX        =   13785
      _ExtentY        =   7858
      View            =   3
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      AllowReorder    =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   0
   End
   Begin VB.Label Label1 
      Caption         =   "SubItem"
      Height          =   255
      Left            =   1920
      TabIndex        =   7
      Top             =   6360
      Width           =   615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    ListView1.ColumnHeaders.Add ListView1.ColumnHeaders.Count + 1, "c" & ListView1.ColumnHeaders.Count, Text1.Text
End Sub

Private Sub Command2_Click()
    ListView1.ListItems.Add , "I" & ListView1.ListItems.Count, Text2.Text
End Sub

Private Sub Command3_Click()
    Dim I
    For I = 1 To ListView1.ListItems.Count
        If ListView1.ListItems.Item(I).Selected Then
            ListView1.ListItems.Item(I).ListSubItems.Add CLng(Text3.Text), Text4.Text
        Else
        End If
    Next
End Sub

Private Sub Form_Load()
    'ListView1.ColumnHeaders.Add , "c" & ListView1.ColumnHeaders.Count, "Column " & ListView1.ColumnHeaders.Count
    'ListView1.ColumnHeaders.Add , "c" & ListView1.ColumnHeaders.Count, "Column " & ListView1.ColumnHeaders.Count
    'ListView1.ColumnHeaders.Add , "c" & ListView1.ColumnHeaders.Count, "Column " & ListView1.ColumnHeaders.Count
    'ListView1.ColumnHeaders.Add , "c" & ListView1.ColumnHeaders.Count, "Column " & ListView1.ColumnHeaders.Count
End Sub
