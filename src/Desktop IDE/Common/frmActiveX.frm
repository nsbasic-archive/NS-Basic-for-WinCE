VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmActiveX 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "ActiveX Controls"
   ClientHeight    =   3750
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6030
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3750
   ScaleWidth      =   6030
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Tag             =   "3447"
   Begin VB.CommandButton btnCopy 
      Caption         =   "3445 (&Copy to Clipboard)"
      Enabled         =   0   'False
      Height          =   495
      Left            =   4680
      TabIndex        =   5
      Tag             =   "3445"
      Top             =   3120
      Width           =   1215
   End
   Begin MSComDlg.CommonDialog dlgCommon 
      Left            =   5040
      Top             =   2160
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      Filter          =   "ActiveX Controls (*.dll;*.ocx)|*.dll;*.ocx"
   End
   Begin VB.CommandButton btnAdd 
      Caption         =   "1508 (&Add)"
      Height          =   375
      Left            =   4680
      TabIndex        =   2
      Tag             =   "1508"
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton btnRemove 
      Caption         =   "1058  (&Remove)"
      Enabled         =   0   'False
      Height          =   375
      Left            =   4680
      TabIndex        =   1
      Tag             =   "1058"
      Top             =   1680
      Width           =   1215
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "1106 (OK)"
      Default         =   -1  'True
      Height          =   375
      Left            =   4680
      TabIndex        =   0
      Tag             =   "1106"
      Top             =   120
      Width           =   1215
   End
   Begin MSComctlLib.TreeView tvwActiveX 
      Height          =   2895
      Left            =   120
      TabIndex        =   3
      Top             =   120
      Width           =   4335
      _ExtentX        =   7646
      _ExtentY        =   5106
      _Version        =   393217
      HideSelection   =   0   'False
      Indentation     =   556
      LabelEdit       =   1
      Style           =   6
      Appearance      =   1
   End
   Begin VB.Label lblAddObject 
      AutoSize        =   -1  'True
      Caption         =   "AddObject"
      BeginProperty Font 
         Name            =   "Courier New"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Left            =   120
      TabIndex        =   4
      Top             =   3240
      Visible         =   0   'False
      Width           =   1080
   End
End
Attribute VB_Name = "frmActiveX"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private m_col As Collection
Private m_strControls As String
Private m_bLoading As Boolean

Private Sub btnAdd_Click()
   On Error GoTo err_cancel
   dlgCommon.Filter = "ActiveX Controls (*.dll;*.ocx)|*.dll;*.ocx"
   dlgCommon.ShowOpen

   If dlgCommon.filename <> "" Then AddFile dlgCommon.filename
err_cancel:
End Sub

Private Sub btnCopy_Click()
   Clipboard.Clear
   Clipboard.SetText lblAddObject.Caption
End Sub

Private Sub btnOK_Click()
Dim nod As MSComctlLib.Node
Dim strAXS As String

   strAXS = ""
   For Each nod In tvwActiveX.Nodes
      If nod.Children > 0 Then
         If nod.Tag Then
            strAXS = strAXS & nod.Text & "|"
         End If
      End If
   Next
   If Len(strAXS) > 0 Then strAXS = Left(strAXS, Len(strAXS) - 1)

   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "ActiveXControls", strAXS
   Unload Me
End Sub

Private Sub btnRemove_Click()
   tvwActiveX.Nodes.Remove tvwActiveX.SelectedItem.Index
   Set tvwActiveX.SelectedItem = Nothing
   btnRemove.Enabled = False
End Sub

Private Sub Form_Load()
Dim arrAXS() As String
Dim i As Integer

   LoadResStrings Me, False
   
   'Prepare the dialog
   Set m_col = New Collection
   tvwActiveX.Nodes.Clear
   lblAddObject.Caption = "AddObject"
   m_bLoading = True

   'Add the built-in ActiveX controls
   arrAXS = Split(kActiveXControls, "|")
   For i = 0 To UBound(arrAXS)
      AddFile arrAXS(i), False
   Next

   'Load ActiveX controls specified by the user
   m_strControls = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ActiveXControls", "")
   If Len(m_strControls) > 0 Then
      arrAXS = Split(m_strControls, "|")
      For i = 0 To UBound(arrAXS)
         AddFile arrAXS(i)
      Next
   End If
   Set tvwActiveX.SelectedItem = Nothing
   If tvwActiveX.Nodes.Count > 0 Then tvwActiveX.Nodes(1).EnsureVisible
   m_bLoading = False
End Sub

Private Function AddFile(ByVal astrFile As String, Optional ByVal bCustom As Boolean = True) As Boolean
Dim tli As TypeLibInfo
Dim cci As CoClassInfo
Dim nod As Node
Dim strKey As String
Dim strFile As String
Dim strProgID As String
Dim nIndex As Integer
Dim bInsertable As Boolean

   'No duplicates
   If Not m_bLoading Then
      If InStr(1, m_strControls, astrFile, vbTextCompare) Then Exit Function
      If bCustom And InStr(1, kActiveXControls, Mid(astrFile, InStrRev(astrFile, "\") + 1), vbTextCompare) Then Exit Function
   End If

   'Ensure that the file is valid and contains controls
   On Error Resume Next
   err.Clear
   Set tli = TypeLibInfoFromFile(astrFile)
   If err <> 0 Then Exit Function
   If tli.CoClasses.Count = 0 Then Exit Function

   'set up key
   If InStr(1, astrFile, "\") > 0 Then
      strFile = Mid(astrFile, InStrRev(astrFile, "\") + 1)
   Else
      strFile = astrFile
   End If
   strKey = Left(strFile, InStrRev(strFile, ".") - 1)

   'Convert simple file names to full path
   astrFile = tli.CoClasses(1).parent.ContainingFile

   On Error GoTo 0
   'Add parent node, then each CoClass
   tvwActiveX.Nodes.Add , , , astrFile
   nIndex = tvwActiveX.Nodes.Count
   tvwActiveX.Nodes(nIndex).Expanded = True
   tvwActiveX.Nodes(nIndex).Tag = bCustom
   tvwActiveX.Nodes(nIndex).Bold = Not bCustom
   For Each cci In tli.CoClasses
'Debug.Print cci.Name, cci.Guid
      bInsertable = MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "CLSID\" & cci.Guid & "\Control")
'      If bInsertable Then bInsertable = MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "CLSID\" & cci.Guid & "\Insertable")
      bInsertable = True 'GH: let's try being generous
      If bInsertable Then
         strProgID = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "CLSID\" & cci.Guid & "\ProgID", "", "")
         If strProgID <> "" Then
            m_col.Add strProgID, cci.Name
            tvwActiveX.Nodes.Add nIndex, tvwChild, , cci.Name
            tvwActiveX.Nodes(tvwActiveX.Nodes.Count).Tag = strProgID
         End If
      End If
   Next
   If bCustom Then
      tvwActiveX.Nodes(nIndex).EnsureVisible
      Set tvwActiveX.SelectedItem = tvwActiveX.Nodes(nIndex)
   End If
   AddFile = True
End Function

Private Sub tvwActiveX_NodeClick(ByVal Node As MSComctlLib.Node)
   If Node.Children = 0 Then
      lblAddObject.Caption = "AddObject """ & Node.Tag & """"
      btnRemove.Enabled = False
      btnCopy.Enabled = True
   Else
      btnRemove.Enabled = Node.Tag
      btnCopy.Enabled = False
   End If
   lblAddObject.Visible = (Node.Children = 0)
End Sub
