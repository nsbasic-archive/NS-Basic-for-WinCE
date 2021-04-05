VERSION 5.00
Begin VB.Form frmFind 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Find"
   ClientHeight    =   2085
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6750
   Icon            =   "frmFind.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2085
   ScaleWidth      =   6750
   StartUpPosition =   1  'CenterOwner
   Begin VB.CheckBox chkWholeWord 
      Caption         =   "1132[Find Whole Word &Only]"
      Height          =   255
      Left            =   2280
      TabIndex        =   8
      Tag             =   "1132"
      Top             =   1080
      Width           =   2415
   End
   Begin VB.CheckBox chkMatchCase 
      Caption         =   "1133[Match Ca&se]"
      Height          =   255
      Left            =   2280
      TabIndex        =   9
      Tag             =   "1133"
      Top             =   1440
      Width           =   2415
   End
   Begin VB.CommandButton butReplaceAll 
      Caption         =   "1137[Replace &All]"
      Height          =   375
      Left            =   4920
      TabIndex        =   13
      Tag             =   "1137"
      Top             =   1560
      Width           =   1695
   End
   Begin VB.CommandButton butReplace 
      Caption         =   "1136[&Replace]"
      Height          =   375
      Left            =   4920
      TabIndex        =   12
      Tag             =   "1136"
      Top             =   1080
      Width           =   1695
   End
   Begin VB.CommandButton butCancel 
      Cancel          =   -1  'True
      Caption         =   "1135[Cancel]"
      Height          =   375
      Left            =   4920
      TabIndex        =   11
      Tag             =   "1135"
      Top             =   600
      Width           =   1695
   End
   Begin VB.CommandButton butFindNext 
      Caption         =   "1134[Find &Next]"
      Default         =   -1  'True
      Height          =   375
      Left            =   4920
      TabIndex        =   10
      Tag             =   "1134"
      Top             =   120
      Width           =   1695
   End
   Begin VB.OptionButton optSelected 
      Caption         =   "1131[Selected &Text]"
      Height          =   255
      Left            =   240
      TabIndex        =   7
      Tag             =   "1131"
      Top             =   1560
      Width           =   1455
   End
   Begin VB.OptionButton optProject 
      Caption         =   "1130[&Current Project]"
      Height          =   375
      Left            =   240
      TabIndex        =   6
      Tag             =   "1130"
      Top             =   1080
      Width           =   1455
   End
   Begin VB.OptionButton optModule 
      Caption         =   "1129[Current &Module]"
      Height          =   495
      Left            =   240
      TabIndex        =   5
      Tag             =   "1129"
      Top             =   1080
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.TextBox txtReplace 
      Height          =   285
      Left            =   2280
      TabIndex        =   3
      Top             =   480
      Width           =   2415
   End
   Begin VB.TextBox txtFind 
      Height          =   285
      Left            =   2280
      TabIndex        =   1
      Top             =   120
      Width           =   2415
   End
   Begin VB.Frame Frame1 
      Caption         =   "1128[Search]"
      Height          =   1095
      Left            =   120
      TabIndex        =   4
      Tag             =   "1128"
      Top             =   840
      Width           =   1815
   End
   Begin VB.Label lblReplace 
      Caption         =   "1127[Replace &With:]"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Tag             =   "1127"
      Top             =   525
      Width           =   2055
   End
   Begin VB.Label lblFind 
      Caption         =   "1126[&Find What:]"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Tag             =   "1126"
      Top             =   165
      Width           =   2055
   End
End
Attribute VB_Name = "frmFind"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim origType As String
Dim searchStart As Long
Dim searchLength As Long
Dim searchCnt As Long
Dim searchType As String
Dim searchPos As Long
Dim origComplete As Boolean
Dim m_Form As Form
Private m_strFind As String
Private m_strReplace As String
Private m_idSearchStart As String            'Replacing firstSearchModule
Private m_bSearchFound As Boolean            'Replacing searchNotFoundSw
Private m_rSearchStart As CodeMax4Ctl.Range   'Replacing searchStart

Private Sub butCancel_Click()
   Unload Me
'   frmCode.Refresh
End Sub

Private Sub Form_Load()
   LoadResStrings Me

   If m_Form Is Nothing Then
      optProject.Value = True
      optSelected.Enabled = False
   Else
      If TypeName(m_Form) = "frmCode" Then
         If m_Form.GetSel().IsEmpty Then
            'Nothing is selected, so disable selection searches, and set search scope to previously used
            optSelected.Enabled = False
            If gnFindFlags And kFindModule Then
               optModule.Value = True
            Else
               optProject.Value = True
            End If
         Else
            'Something is selected, so default to a selection search
            optSelected.Enabled = True
            optSelected.Value = True
         End If
         txtFind.Text = m_Form.GetFindText
      Else 'typename(m_Form) = "frmScreen"
         'Palm Screen search, so disable selection searches, and set search scope to previously used
         optSelected.Enabled = False
         optProject.Value = True
         txtFind.Text = gstrFind
      End If
   End If
   m_strFind = txtFind.Text
   txtReplace.Text = gstrReplace
   txtFind.SelStart = 0: txtFind.SelLength = 100
   txtReplace.SelStart = 0: txtReplace.SelLength = 100
   m_strReplace = txtReplace.Text
End Sub

Private Function butCommon_Click(bReplace As Boolean) As Boolean
Dim proj As CProject
Dim nFlags As Integer
Dim i As Integer
Dim strSearchStart As String
Dim arrStr() As String

   If gTarget Is Nothing Then Exit Function

   'Get find and replace strings, set globals and determine if this is a new search
   gstrFind = txtFind.Text
   If Len(gstrFind) = 0 Then Exit Function
   If bReplace Then
      gstrReplace = txtReplace.Text
      If gstrFind <> m_strFind Or gstrReplace <> m_strReplace Then gbNewFind = True
      m_strReplace = gstrReplace
   Else
      If gstrFind <> m_strFind Then gbNewFind = True
   End If
   m_strFind = gstrFind

   'Get flags, set global and determine if this is a new search
   If optModule Then
      nFlags = kFindModule
   ElseIf optProject Then
      nFlags = kFindProject
   Else
      nFlags = kFindSelected
      Set gSearchSel = m_Form.GetSel
   End If
   If chkMatchCase Then nFlags = nFlags + kFindCase
   If chkWholeWord Then nFlags = nFlags + kFindWord
   If nFlags <> gnFindFlags Then
      gbNewFind = True
      gnFindFlags = nFlags
   End If

   'If this is a new search, set start point, current point, and scope
   If gbNewFind Or gnSearchLoc < 0 Then
      If m_Form Is Nothing Then
         'We're searching the whole project
         Set proj = ActiveProject
'         garrSearchMap = Split(proj.GlobalID, vbTab)
         garrSearchMap = Split(gTarget.BuildMap, ">")
      Else
         'Find project, and set scope according to find flags and/or currentform type
         Set proj = LocateProject(m_Form.GlobalID)
         If gnFindFlags And kFindProject Then
            garrSearchMap = Split(proj.BuildMap, ">")
         Else
            'Since we have a form, the search start is always that form
            If TypeName(m_Form) = "frmCode" Then
               garrSearchMap = Split(m_Form.GlobalID, ">")
            Else 'typename(m_Form) = "frmScreen"
               garrSearchMap = m_Form.Object.BuildMap
            End If
         End If
      End If
      
      'If search scope is project, locate starting index in search map, otherwise use 0
      gnSearchStart = 0
      If (gnFindFlags And kFindProject) And Not (m_Form Is Nothing) Then
         garrSearchMap = Split(gTarget.BuildMap, ">")
         If TypeName(m_Form) = "frmCode" Then
            'Could be a module
            strSearchStart = m_Form.GlobalID
         Else 'typename(m_Form) = "frmScreen"
            'Must be the entire project
            strSearchStart = gTarget.GlobalID
         End If

         For i = 0 To UBound(garrSearchMap)
            If garrSearchMap(i) = strSearchStart Then
               gnSearchStart = i
               Exit For
            End If
         Next
      End If
      gnSearchLoc = gnSearchStart
      gnReplaceCount = 0
   End If
   butCommon_Click = True
End Function

Private Sub butFindNext_click()
   If Not butCommon_Click(False) Then
      Beep
      Exit Sub
   End If
   If Not FindNext Then
      If Not gbFindAny Then
         MsgBox gStringTable(3320), vbExclamation '"Search text is not found"
         gbNewFind = True
      Else
         If gnSearchLoc < 0 Then
            MsgBox gStringTable(3321), vbInformation + vbOKOnly ' "End of search reached"
            gbNewFind = True
            Unload Me
         End If
      End If
   Else
      'Only look in selected text for the first occurence
      If gnFindFlags And kFindSelected Then
         optModule = True
         gnFindFlags = gnFindFlags + kFindModule - kFindSelected
      End If
   End If
End Sub

Private Sub butReplace_Click()
Dim frm As frmCode

   If Not butCommon_Click(True) Then
      Beep
      Exit Sub
   End If
   CMaxPrepFindReplace frmMain.cmaxFind
   If Not frmMain.ActiveForm Is Nothing Then
      If TypeName(frmMain.ActiveForm) = "frmCode" Then
         Set frm = frmMain.ActiveForm
         frmMain.cmaxFind.Text = frm.Text
         frmMain.cmaxFind.SetSel frm.GetSel, True
         gbFindOne = False
         frmMain.cmaxFind.ExecuteCmd cmCmdReplace, 0
         If gbFindOne Then
            frm.Text = frmMain.cmaxFind.Text
            frm.SetSel frmMain.cmaxFind.GetSel(True)
            frm.Dirty = True
            frm.PutTheCodeBack
         End If
      Else
         FindNext
      End If
   Else
      FindNext
   End If
      
End Sub

Private Sub butReplaceAll_Click()
Dim frm As frmCode
Dim i As Integer

   'Screw elegance!

   If Not butCommon_Click(True) Then
      Beep
      Exit Sub
   End If
   CMaxPrepFindReplace frmMain.cmaxFind
   If gnFindFlags And kFindSelected Then
'      Set frm = frmMain.GetMDIChild(garrSearchMap(0))
      Set frm = frmMain.ActiveForm
      garrSearchMap = Split(frm.GlobalID, "")
'      frmMain.cmaxFind.Text = GetCode(garrSearchMap(0))
      frmMain.cmaxFind.Text = GetCode(frm.GlobalID)
      frmMain.cmaxFind.SetSel gSearchSel, True
      frmMain.cmaxFind.ExecuteCmd cmCmdReplaceAllInSelection, 0
      frm.Text = frmMain.cmaxFind.Text
      frm.PutTheCodeBack
   Else
      For i = 0 To UBound(garrSearchMap)
         'First do the replace offscreen
         frmMain.cmaxFind.Text = GetCode(garrSearchMap(i))
         If Not frmMain.cmaxFind.Text = "" Then
            frmMain.cmaxFind.ExecuteCmd cmCmdReplaceAllInBuffer, 0
            'Now, if the window was open, lets put the new text in there and put the text away
            Set frm = frmMain.GetMDIChild(garrSearchMap(i))
            If Not frm Is Nothing Then
               frm.Text = frmMain.cmaxFind.Text
               frm.Dirty = True
               frm.PutTheCodeBack
            Else
               PutScript frmMain.cmaxFind.Text, garrSearchMap(i)
            End If
         End If
      Next
   End If
End Sub

Public Property Let Form(frm As Form)
   Set m_Form = frm
End Property

Public Property Let FindReplace(bFindReplace As Boolean)
   lblReplace.Visible = bFindReplace
   txtReplace.Visible = bFindReplace
   butReplace.Visible = bFindReplace
   butReplaceAll.Visible = bFindReplace
   If bFindReplace Then
      Me.Caption = gStringTable(1304)
   Else
      Me.Caption = gStringTable(1303)
   End If
End Property

