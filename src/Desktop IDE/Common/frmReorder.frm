VERSION 5.00
Begin VB.Form frmReorder 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Reorder Dialog"
   ClientHeight    =   3195
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6030
   Icon            =   "frmReorder.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3195
   ScaleWidth      =   6030
   ShowInTaskbar   =   0   'False
   Begin VB.ListBox lstObjects 
      Height          =   2985
      Left            =   120
      TabIndex        =   4
      Top             =   120
      Width           =   4455
   End
   Begin VB.CommandButton cmdDown 
      Enabled         =   0   'False
      Height          =   495
      Left            =   4680
      Picture         =   "frmReorder.frx":000C
      Style           =   1  'Graphical
      TabIndex        =   3
      Top             =   1920
      Width           =   1215
   End
   Begin VB.CommandButton cmdUp 
      Enabled         =   0   'False
      Height          =   495
      Left            =   4680
      Picture         =   "frmReorder.frx":044E
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   1320
      Width           =   1215
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "1135 (Cancel)"
      Height          =   375
      Left            =   4680
      TabIndex        =   1
      Tag             =   "1135"
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "1106 (OK)"
      Height          =   375
      Left            =   4680
      TabIndex        =   0
      Tag             =   "1106"
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "frmReorder"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Public gForm As CForm
Public gProj As CProject
Public OrderModules As Boolean
Private gObjs() As Object

Private Sub CancelButton_Click()
   Me.Hide
End Sub

Private Sub cmdDown_Click()
Dim strTemp As String
Dim ob As Object
Dim li As Integer

   li = lstObjects.ListIndex
   strTemp = lstObjects.List(li)
   lstObjects.RemoveItem li
   Set ob = gObjs(li)
   Set gObjs(li) = gObjs(li + 1)
   Set gObjs(li + 1) = ob
   li = li + 1
   lstObjects.AddItem strTemp, li
   lstObjects.ListIndex = li
End Sub

Private Sub cmdUp_Click()
Dim strTemp As String
Dim ob As Object
Dim li As Integer

   li = lstObjects.ListIndex
   strTemp = lstObjects.List(li)
   lstObjects.RemoveItem li
   Set ob = gObjs(li)
   Set gObjs(li) = gObjs(li - 1)
   Set gObjs(li - 1) = ob
   li = li - 1
   lstObjects.AddItem strTemp, li
   lstObjects.ListIndex = li
End Sub

Private Sub Form_Load()
Dim obj As Object
Dim i As Integer
   LoadResStrings Me, False

   If Not gForm Is Nothing Then
      If gForm.Controls.Count = 0 Then Exit Sub
      ReDim gObjs(gForm.Controls.Count - 1)
      For i = 1 To gForm.Controls.Count
         lstObjects.AddItem gForm.Controls(i).Name
         Set gObjs(i - 1) = gForm.Controls(i)
      Next
      'RES
      Caption = "Tab Order - " & gForm.Name
   Else
      If OrderModules Then
         If gProj.Modules.Count < 2 Then Exit Sub
         ReDim gObjs(gProj.Modules.Count - 1)
         For i = 1 To gProj.Modules.Count
            lstObjects.AddItem gProj.Modules(i).Name
            Set gObjs(i - 1) = gProj.Modules(i)
         Next
         'RES
         Caption = "Module Order - " & gProj.Name
      Else
         If gProj.Forms.Count = 0 Then Exit Sub
         ReDim gObjs(gProj.Forms.Count - 1)
         For i = 1 To gProj.Forms.Count
            lstObjects.AddItem gProj.Forms(i).Name
            Set gObjs(i - 1) = gProj.Forms(i)
         Next
         'RES
         Caption = "Form Order - " & gProj.Name
      End If
   End If
   If lstObjects.ListCount <> 0 Then lstObjects.ListIndex = 0
End Sub

Private Sub lstObjects_Click()
   If lstObjects.ListIndex < 0 Then
      cmdUp.Enabled = False
      cmdDown.Enabled = False
   Else
      cmdUp.Enabled = True
      cmdDown.Enabled = True
      If lstObjects.ListIndex = 0 Then cmdUp.Enabled = False
      If lstObjects.ListIndex = lstObjects.ListCount - 1 Then cmdDown.Enabled = False
   End If
End Sub

Private Sub OKButton_Click()
Dim cont As New CControls
Dim frms As New CForms
Dim mods As New Collection
Dim i As Integer
   If Not gForm Is Nothing Then
      If IsArray(gObjs) Then
         'frmMain.CloseMDIChild (gForm)  '04.11.07 GWH causes error if not commented.
         For i = 0 To UBound(gObjs)
            cont.Add gObjs(i)
         Next
         Set gForm.Controls = cont
         Set gForm = Nothing
      End If
   Else
      If IsArray(gObjs) Then
         If OrderModules Then
            For i = 0 To UBound(gObjs)
               mods.Add gObjs(i)
            Next
            While gProj.Modules.Count > 0
               gProj.Modules.Remove 1
            Wend
            Set gProj.Modules = Nothing
            Set gProj.Modules = mods
         Else
            For i = 0 To UBound(gObjs)
               frms.Add gObjs(i)
            Next
            Set gProj.Forms = frms
            Set gProj = Nothing
         End If
      End If
   End If
   If gbProjectExplorer Then gfProjectExplorer.DisplayExplorer
   Me.Hide
End Sub
