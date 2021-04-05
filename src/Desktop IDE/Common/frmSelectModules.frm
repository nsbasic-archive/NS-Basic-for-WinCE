VERSION 5.00
Begin VB.Form frmSelectModules 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Export to Text"
   ClientHeight    =   3975
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6015
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3975
   ScaleWidth      =   6015
   ShowInTaskbar   =   0   'False
   Begin VB.ListBox lstModules 
      Height          =   3180
      Left            =   120
      MultiSelect     =   1  'Simple
      TabIndex        =   3
      Top             =   480
      Width           =   4215
   End
   Begin VB.CommandButton cmdCancel 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4680
      TabIndex        =   1
      Tag             =   "1135"
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "&OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   4680
      TabIndex        =   0
      Tag             =   "1106"
      Top             =   120
      Width           =   1215
   End
   Begin VB.Label lblCaption 
      Caption         =   "Export the following files?"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Tag             =   "3467"
      Top             =   120
      Width           =   3495
   End
End
Attribute VB_Name = "frmSelectModules"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private m_Project As CProject
Public DialogOK As Boolean
Public DialogCancel As Boolean
Public Selections As String

Private Sub cmdCancel_Click()
   DialogCancel = True
   Unload Me
End Sub

Private Sub cmdOK_Click()
Dim i As Integer
Dim j As Integer

   DialogOK = True
   If lstModules.SelCount >= 1 Then
      Selections = ""
      For i = 0 To lstModules.SelCount - 1
         If lstModules.Selected(i) Then
            Selections = Selections & lstModules.List(i) & "|"
         End If
      Next
   End If
   
   Unload Me
End Sub

Private Sub Form_Load()
Dim modul As CModule

   DialogOK = False
   DialogCancel = False

   For Each modul In m_Project.Modules
      lstModules.AddItem modul.filename
   Next
End Sub

Public Property Set Project(aProj As CProject)
   Set m_Project = aProj
End Property

