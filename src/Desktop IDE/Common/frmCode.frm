VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{BCA00000-0F85-414C-A938-5526E9F1E56A}#4.0#0"; "cmax40.dll"
Begin VB.Form frmCode 
   Caption         =   "Code Window"
   ClientHeight    =   6435
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   10635
   Icon            =   "frmCode.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MDIChild        =   -1  'True
   ScaleHeight     =   6435
   ScaleMode       =   0  'User
   ScaleWidth      =   10635
   Visible         =   0   'False
   Begin CodeMax4Ctl.CodeMax editor 
      Height          =   5775
      Left            =   0
      OleObjectBlob   =   "frmCode.frx":038A
      TabIndex        =   0
      Top             =   600
      Width           =   10095
   End
   Begin CodeMax4Ctl.CodeMax shadow 
      Height          =   2895
      Left            =   7680
      OleObjectBlob   =   "frmCode.frx":047A
      TabIndex        =   2
      Top             =   2040
      Visible         =   0   'False
      Width           =   2895
   End
   Begin VB.ComboBox cmbProcedures 
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   8.25
         Charset         =   238
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      ItemData        =   "frmCode.frx":056A
      Left            =   0
      List            =   "frmCode.frx":0571
      Sorted          =   -1  'True
      Style           =   2  'Dropdown List
      TabIndex        =   1
      Top             =   0
      Width           =   1215
   End
   Begin MSComDlg.CommonDialog dialog 
      Left            =   10200
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DialogTitle     =   "Project Help"
      FileName        =   "*.prj"
      InitDir         =   "c:\"
   End
End
Attribute VB_Name = "frmCode"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private bDirty As Boolean                    '02/02/2001 MMD
Private header As String                     '02/02/2001 MMD
Private subheader As String                  '02/02/2001 MMD
Private m_object As Object
Private bCmbToggle As Boolean
Private arrDividers(1000) As Integer
Private dividerCount As Integer
Private rngCurrent As Range
Private bSyntax As Boolean
Private scrSyntax As New MSScriptControl.ScriptControl

Public IsUIObject As Boolean

Private Sub cmbProcedures_Click()
Dim Index As Integer

   If bCmbToggle Then Exit Sub
   bCmbToggle = True

   'Look for negative value to open "Go To Line..." dialog
   Index = cmbProcedures.ItemData(cmbProcedures.ListIndex)
   Select Case Index
   Case -1
      editor.ExecuteCmd cmCmdGotoLine, -1
   Case -2  'Main
      MysteryProcedure "Sub Main", "End Sub"
   Case -3  'Form_Load
      MysteryProcedure "Sub " & Object.Forms(1).Name & "_Load", "End Sub"
   Case -4  'Form_Unload
      MysteryProcedure "Sub " & Object.Forms(1).Name & "_Unload", "End Sub"
   Case -44 'Dummy case
      Exit Sub '09.18.08 GWH prevents error 5 when ctrl f entered
   Case Else
      'Move the cursor to the beginning of the line that follows the procedure declaration line
      'if procedure declaration is last line of file, move to beginning of procedure declaration line
      editor.SelectLine cmbProcedures.ItemData(cmbProcedures.ListIndex), True
      editor.ExecuteCmd cmCmdHome
      editor.ExecuteCmd cmCmdLineDown
   End Select
   
   'Now, reset the Procedures combobox
   ResetProcedures
   
   'Finally, transfer control back to editor
   editor.SetFocus
   bCmbToggle = False
End Sub

Private Sub MysteryProcedure(astrProcHead As String, astrProcFoot As String)
   If editor.LineCount > 0 Then editor.SelectLine editor.LineCount - 1, True
   editor.ExecuteCmd cmCmdEnd
   Select Case editor.GetLineLength(editor.LineCount - 1)
   Case 0
      If editor.LineCount > 1 And editor.GetLineLength(editor.LineCount - 2) <> 0 Then editor.AddText vbCrLf
   Case Is > 0: editor.AddText vbCrLf & vbCrLf
   End Select
   editor.AddText astrProcHead & vbCrLf & vbCrLf & astrProcFoot & vbCrLf
   editor.ExecuteCmd cmCmdLineDown
   If editor.GetLineLength(editor.GetSel(True).EndLineNo) > 0 Then editor.ExecuteCmd cmCmdLineDown
End Sub

Private Sub cmbProcedures_DropDown()
Dim strLine As String
Dim strKey As String
Dim i As Double
Dim itm As Object
If editor.LineCount = 0 Then Exit Sub

#If NSBasic_Desktop Then
Dim bMain As Boolean
Dim bForm_Load As Boolean
Dim bForm_Unload As Boolean

   bMain = False
   bForm_Load = False
   bForm_Unload = False
#End If

   'Search through code in editor one line at a time and add procedures
   cmbProcedures.Clear
   cmbProcedures.AddItem ""
   cmbProcedures.ItemData(cmbProcedures.NewIndex) = -44
   cmbProcedures.AddItem "(Go To Line...)"
   cmbProcedures.ItemData(cmbProcedures.NewIndex) = -1
   For i = 0 To editor.LineCount - 1
      strLine = Trim(editor.GetLine(i))
      If InStr(1, strLine, " ") Then
         strKey = LCase(Left(strLine, InStr(1, strLine, " ") - 1))
         If strKey = "public" Or strKey = "private" Then
            strLine = Trim(Mid(strLine, Len(strKey) + 2))
            If InStr(1, strLine, " ") > 0 Then
            strKey = LCase(Left(strLine, InStr(1, strLine, " ") - 1))
         End If
         End If
         If strKey = "sub" Or strKey = "function" Then
            If InStr(1, strLine, "(") Then
               strKey = Mid(strLine, Len(strKey) + 2, InStr(Len(strKey) + 2, strLine, "(") - (Len(strKey) + 2))
            Else
               strKey = Mid(strLine, Len(strKey) + 2)
            End If
            cmbProcedures.AddItem strKey
#If NSBasic_Desktop Then
            If StrComp(strKey, "main", vbTextCompare) = 0 Then bMain = True
            If TypeName(Object) <> "CModule" Then
               If Object.Forms.Count > 0 Then
                  If StrComp(strKey, Object.Forms(1).Name & "_load", vbTextCompare) = 0 Then bForm_Load = True
                  If StrComp(strKey, Object.Forms(1).Name & "_unload", vbTextCompare) = 0 Then bForm_Unload = True
               End If
            End If
#End If
            cmbProcedures.ItemData(cmbProcedures.NewIndex) = i
         End If
      End If
   Next
   
#If NSBasic_Desktop Then
   If Left(Object.GlobalID, 6) <> "module" Then
      If Not bMain Then
         cmbProcedures.AddItem "Main"
         cmbProcedures.ItemData(cmbProcedures.NewIndex) = -2
      End If
      If Object.Forms.Count > 0 Then
         If Not bForm_Load Then
            cmbProcedures.AddItem Object.Forms(1).Name & "_Load"
            cmbProcedures.ItemData(cmbProcedures.NewIndex) = -3
         End If
         If Not bForm_Unload Then
            cmbProcedures.AddItem Object.Forms(1).Name & "_Unload"
            cmbProcedures.ItemData(cmbProcedures.NewIndex) = -4
         End If
      End If
   End If
#End If
End Sub

Private Sub ResetProcedures()
   bCmbToggle = True
   cmbProcedures.Clear
   cmbProcedures.AddItem "(Go to...)"
   cmbProcedures.ListIndex = 0
   bCmbToggle = False
End Sub

Private Sub cmbProcedures_LostFocus()
   cmbProcedures.ListIndex = 0
End Sub

Private Sub editor_ContextMenu(ByVal X As Long, ByVal Y As Long)
   editor.CancelEvent
   PopupMenu frmMain.mnuRightEditCode
End Sub

'Private Sub editor_SelChange(ByVal Control As CodeMax4Ctl.CodeMax)
Private Sub editor_SelChange()
Dim rng As Range
Dim offset As Integer

#If NSBasic_Desktop Then
   offset = 1
#End If
#If NSBasic_CE Then
   offset = 0
#End If

   On Error GoTo err_editor_SelChange
   
   If editor.TextLength = 0 Then Exit Sub
   Set rng = editor.GetSel(True)
   frmMain.UpdateToolbar
   ShowCursor rng.EndLineNo + offset, rng.EndColNo
'Debug.Print "rng: "; rng.StartLineNo; "rngCurrent: "; rngCurrent.StartLineNo

   If rng.StartLineNo <> rngCurrent.StartLineNo Then
      editor.SetDivider rngCurrent.StartLineNo, False
      CloseBlock rngCurrent.StartLineNo
      SetNewDividers rngCurrent.StartLineNo
      CheckSyntax rngCurrent.StartLineNo
      editor.SetFocus
   End If
   
err_editor_SelChange:
   Set rngCurrent = rng
'Debug.Print "SelChange"
End Sub

Sub CheckSyntax(nLine As Integer)
Dim i As Integer
Dim s As String
Dim prevline As Long
Dim sp As String
Dim lines() As String

   If bSyntax Then
      bSyntax = False
      
      s = editor.GetLine(nLine)
      If scrSyntax.language <> "" Then
         scrSyntax.Reset
      End If
      scrSyntax.language = "VBscript"
      
      'AddCode checks syntax, and executes if there is no error.
      'By adding a second line with a syntax error, we make sure that execution does not happen.
      'Only errors on the passed through statement are reported.
      
      'cannot check some statements
      If UCase(Left(trimWhiteSpace(s), 3)) = "END" Or UCase(Left(trimWhiteSpace(s), 4)) = "EXIT" Then Exit Sub
      If UCase(Left(trimWhiteSpace(s), 4)) = "NEXT" Or UCase(Left(trimWhiteSpace(s), 4)) = "ELSE" Then Exit Sub
      If UCase(Left(trimWhiteSpace(s), 4)) = "WEND" Or UCase(Left(trimWhiteSpace(s), 4)) = "CASE" Then Exit Sub
      If InStr(UCase(s), " EXIT SUB") Then Exit Sub
      If InStr(UCase(s), " EXIT FUNCTION") Then Exit Sub
      If InStr(UCase(s), " EXIT LOOP") Then Exit Sub
      If InStr(UCase(s), " EXIT FOR") Then Exit Sub
      If UCase(Left(trimWhiteSpace(s), 4)) = "LOOP" Then Exit Sub
      If Right(trimWhiteSpace(s), 1) = "_" Then Exit Sub 'don't check line continuations
      
      prevline = nLine - 1
      Do While prevline >= 0
         sp = editor.GetLine(prevline)
         If Right(trimWhiteSpace(sp), 1) <> "_" Then Exit Do
         s = sp & vbCrLf & s
         prevline = prevline - 1
      Loop
      
      On Error Resume Next
      scrSyntax.AddCode s & vbCrLf & "a="
      If err And scrSyntax.Error.line = 1 Then
         MsgBox "Error: Line " & nLine + 1 & ", Char " & scrSyntax.Error.Column + 1 & ". " & scrSyntax.Error.Description
      End If
   End If
End Sub

Private Sub Form_Activate()
   frmMain.ActiveFormChange 1
   ShowCursor editor.GetSel(True).EndLineNo + 1, editor.GetSel(True).EndColNo
   ResetProcedures
   setAllDividers
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
   'Removed check for dirty, because it allows new modules to close without saving
'   If Dirty And typename(m_object) = "CCodeModule" Then
   If TypeName(m_object) = "CCodeModule" Then
      Cancel = Not m_object.PutScript(Text, "code")
   End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
   m_object.PutScript editor.Text, Tag
   gfProjectExplorer.UpdateObjectNode m_object, m_object.GlobalID
   
'MMD:I don't like this code
   frmMain.RemoveMDIChild GlobalID
   frmMain.ActiveFormChange 0
   frmMain.ActiveFormIsCode = False
End Sub

Function check_code() As Boolean 'check that there is no code before or after
   'Let's clean up a number of things here...
   ' 1. Clear leading white space
   ' 2. Clear trailing white space
   ' 3. Allow opening comments
   Dim temp, code, lines() As String
   Dim i As Integer

   check_code = False

   'Clean leading and trailing whitespace from code
   editor.Text = trimWhiteSpace(editor.Text, 2)

   'Don't check if empty text or code module

   check_code = True
End Function

Sub PutTheCodeBack()
   If Not bDirty Then Exit Sub
   bDirty = False

   m_object.PutScript editor.Text, Tag
End Sub

Private Sub Form_Load()
   IsUIObject = False
   bDirty = False
  
   editor.language = cmLanguage
   MNSBCodeMax_SetScriptPrefs editor
   editor.VScrollVisible = True
   editor.HScrollVisible = True
   gTarget.getDemoCode 'initialize gDemoCodeLines
   #If NSBasic_CE Then
      editor.LineNumberStart = 0 + gDemoCodeLines
   #End If
   #If NSBasic_Desktop Then
      editor.LineNumberStart = 1 + gDemoCodeLines
   #End If
   Set rngCurrent = editor.GetSel(True)
   
   'change height of cmdProcedures to 16 lines
   Dim pt As POINTAPI
   Dim rc As RECT
   Dim cWidth As Long
   Dim NewHeight As Long
   Dim oldScaleMode As Long
   Dim numItemsToDisplay As Long
   Dim itemHeight As Long
   
   numItemsToDisplay = 16

  'Save the current form scalemode, then switch to pixels
   oldScaleMode = Me.ScaleMode
   Me.ScaleMode = vbPixels
   
   cWidth = cmbProcedures.Width
  
  'get the system height of a single combo box list item
   itemHeight = SendMessage(cmbProcedures.hWnd, CB_GETITEMHEIGHT, 0, ByVal 0)
   NewHeight = itemHeight * (numItemsToDisplay + 2)
   
  'get the co-ordinates of the combo box relative to the screen
   Call GetWindowRect(cmbProcedures.hWnd, rc)
   pt.X = rc.Left
   pt.Y = rc.Top

  'then translate into co-ordinates relative to the form.
   Call ScreenToClient(Me.hWnd, pt)
   Call MoveWindow(cmbProcedures.hWnd, pt.X, pt.Y, cmbProcedures.Width, NewHeight, True)
   
  'it's done, so show the new combo height
   Call SendMessage(cmbProcedures.hWnd, CB_SHOWDROPDOWN, True, ByVal 0)
   
  'restore the original form scalemode
   Me.ScaleMode = oldScaleMode

End Sub

Sub SetCaption()
'Dim strTitle As String
Dim proj As CProject

   If IsUIObject Then
      Set proj = LocateProject(m_object.obj.GlobalID)
   Else
      Set proj = LocateProject(m_object.GlobalID)
   End If
'   Me.Caption = proj.Name
'   Exit Sub
   
   Select Case TypeName(m_object)
   Case "CMenuElem"
'      Me.caption = proj.Name & " - Menu " & Menu.Name & " [" & mnuBar.caption & " (" & mnu.caption & ")]"
      Me.Caption = proj.Name & " - Menu Dropdown (" & m_object.Caption & ")"
   Case "CProject"
      Select Case Me.Tag
      Case "startup": Me.Caption = m_object.Name & " (Startup Code)"
      Case "termination": Me.Caption = m_object.Name & " (Termination Code)"
      End Select
      Me.Caption = m_object.Name & " - " & Me.Caption
   Case "CCodeModule"
      Me.Caption = "Module - " & m_object.filename
   Case "CForm"
      Select Case Me.Tag
      Case "event": Me.Caption = proj.Name & " - Form " & m_object.Name & " (Event Code)"
      Case "before": Me.Caption = proj.Name & " - Form " & m_object.Name & " (Before Code)"
      Case "after": Me.Caption = proj.Name & " - Form " & m_object.Name & " (After Code)"
      Case "help": Me.Caption = proj.Name & " - Form " & m_object.Name & " (Help Code)"
      End Select
   Case "CModule"
      Me.Caption = proj.Name & " - " & m_object.Name
   Case Else
      Me.Caption = proj.Name & " - Form " & m_object.obj.Form.Name & " (" & m_object.obj.Name & ")"
   End Select
'   Me.caption = "NS Basic/Palm - " & strTitle

End Sub

Private Sub Form_Resize()
Dim cmaxTop As Integer

   If Me.WindowState = vbMinimized Then Exit Sub  '02/11/2001 MMD

   'cmbProcedures.Visible = False
   cmaxTop = IIf(cmbProcedures.Visible, cmbProcedures.Height, 0)
   If Me.Height < 360 Then Me.Height = 360

   With editor
      .Left = 0
      .Top = cmaxTop '0
      .Width = Me.ScaleWidth 'Me.Width - 105
      .Height = Me.ScaleHeight - cmaxTop 'Me.Height - 180
   End With
   cmbProcedures.Width = Me.ScaleWidth
End Sub

Private Sub ShowProcedure()
   cmbProcedures.Clear
   cmbProcedures.AddItem "(Declarations)"
   shadow.Text = editor.Text
 '  shadow
End Sub

Public Sub SetSel(sel As Range)
   editor.SetSel sel, True
End Sub

Public Function GetSel() As Range
   Set GetSel = editor.GetSel(True)
End Function

Public Function SelText() As String
   SelText = editor.SelText
End Function

Public Sub EditorSel(SelStart As Long, SelLength As Long)
Dim line As Integer
Dim p As Long
Dim SelRange As Range

   'convert character position in buffer to line, col
   Set SelRange = editor.GetSel(True)
   line = 0
   p = 0
   Do While (p + editor.GetLineLength(line)) < SelStart
      p = p + editor.GetLineLength(line) + Len(vbCrLf)
      line = line + 1
      If line > editor.LineCount Then Exit Sub
   Loop
   SelRange.StartLineNo = line
   SelRange.EndLineNo = line
   SelRange.StartColNo = SelStart - p
   SelRange.EndColNo = SelRange.StartColNo + SelLength
   'sgBox str(selrange.StartLineNo) + " " + str(selrange.StartColNo) + " " + str(selrange.EndColNo)
   editor.SetSel SelRange, True
End Sub

Public Sub InsertText(astrText As String)
Dim rng As Range
Dim pos As New Position

   Set rng = editor.GetSel(True)
   pos.ColNo = rng.StartColNo
   pos.LineNo = rng.StartLineNo
   
   editor.InsertText astrText, pos
End Sub

Public Function SelStart()
Dim SelRange As Range
Dim p As Integer
Dim i As Integer

   Set SelRange = editor.GetSel(True)
   p = SelRange.StartColNo
   For i = 0 To SelRange.StartLineNo - 1
      p = p + editor.GetLineLength(i) + 2
   Next
   SelStart = p
End Function

'Private Sub editor_Change(ByVal Control As CodeMax4Ctl.CodeMax)
Private Sub editor_Change()
   frmMain.UpdateToolbar
   bDirty = True                   '02/02/2001 MMD
   bSyntax = True
   gTarget.Dirty = True
   
   'setAllDividers
End Sub

'Private Function editor_CmdFailure(ByVal Control As CodeMax4Ctl.CodeMax, ByVal lCmd As CodeMax4Ctl.cmCommand, ByVal lErrCode As CodeMax4Ctl.cmCommandErr) As Boolean
Private Sub editor_CmdFailure(ByVal lCmd As CodeMax4Ctl.cmCommand, ByVal lErrCode As CodeMax4Ctl.cmCommandErr)
   'do nothing
   If lErrCode = cmErrNotFound Then
      'editor_CmdFailure = True
   End If
End Sub

'Private Sub editor_PropsChange(ByVal Control As CodeMax4Ctl.CodeMax)
Private Sub editor_PropsChange()
   MNSBCodeMax_SavePrefs editor
   editor.CancelEvent
End Sub

'Private Sub editor_RegisteredCmd(ByVal Control As CodeMax4Ctl.CodeMax, ByVal lCmd As CodeMax4Ctl.cmCommand)
Private Sub editor_RegisteredCmd(ByVal lCmd As CodeMax4Ctl.cmCommand)

End Sub

Public Property Let Text(ByRef vData As String)
   editor.Text = vData
End Property

Public Property Get Text() As String
   Text = editor.Text
End Property

Public Property Let Dirty(ByVal vData As Boolean)
   bDirty = vData
End Property

Public Property Get Dirty() As Boolean
   Dirty = bDirty
End Property

Public Property Let Object(ByVal obj As Object)
   Set m_object = obj
   SetCaption
End Property

Public Property Get Object() As Object
   Set Object = m_object
End Property

Public Property Get GlobalID() As String
   GlobalID = m_object.GlobalID '& "|" & Me.Tag
End Property

Public Sub DisplaySelection()
   If gbProjectExplorer Then gfProjectExplorer.ShowActive m_object
   If gbProperties Then gfProperties.Object = m_object
End Sub

Public Sub GoToLine()
   editor.ExecuteCmd cmCmdGotoLine, -1
End Sub

Public Sub Undo()
   editor.ExecuteCmd cmCmdUndo, 0
End Sub

Public Sub Redo()
   editor.ExecuteCmd cmCmdRedo, 0
End Sub

Public Sub Cut()
   editor.ExecuteCmd cmCmdCut, 0
   setAllDividers
End Sub

Public Sub Copy()
   editor.ExecuteCmd cmCmdCopy, 0
End Sub

Public Sub Paste()
   editor.ExecuteCmd cmCmdPaste, 0
   setAllDividers
End Sub

Public Function ValidPaste() As Boolean
   ValidPaste = Clipboard.GetFormat(vbCFText)
End Function

Public Sub Delete()
   editor.ExecuteCmd cmCmdDelete, 0
   setAllDividers
End Sub

Public Sub SelectAll()
   editor.ExecuteCmd cmCmdSelectAll, 0
End Sub

Public Function ShowWhitespace() As Boolean
   ShowWhitespace = Not editor.DisplayWhitespace
   editor.ExecuteCmd IIf(ShowWhitespace, cmCmdWhitespaceDisplayOn, cmCmdWhitespaceDisplayOff), 0
End Function

Public Sub SetRepeatCount()
   editor.ExecuteCmd cmCmdSetRepeatCount, 0
End Sub

Public Sub CommentSelection(bComment As Boolean)
   editor.ExecuteCmd IIf(bComment, cmCmdCommentSelection, cmCmdUncommentSelection), 0
   editor.CancelEvent
End Sub

Public Sub ExecuteCommand()
   editor.ExecuteCmd cmCmdChooseCmd, 0
End Sub

Public Sub ShowProperties()
   editor.ExecuteCmd cmCmdProperties, 0
End Sub

Public Sub Save()
   PutTheCodeBack
End Sub

Public Function GetFindText() As String
   'If nothing is selected, use the last find string
   'If something is selected, use the selection or first line of what is selected, whichever is shortest
   If editor.GetSel(True).IsEmpty Then
      GetFindText = gstrFind
   Else
      If InStr(editor.SelText, vbCrLf) > 0 Then
         GetFindText = gstrFind
      Else
         GetFindText = editor.SelText
      End If
   End If
End Function

Public Function FindNext() As Boolean
   FindNext = CMaxFindNext(editor)
End Function

Public Function CanUndo() As Boolean
   CanUndo = editor.CanUndo
End Function

Public Function CanRedo() As Boolean
   CanRedo = editor.CanRedo
End Function

Public Function CanCut() As Boolean
   CanCut = editor.CanCut
End Function

Public Function CanCopy() As Boolean
   CanCopy = editor.CanCopy
End Function

Public Function CanPaste() As Boolean
   CanPaste = editor.CanPaste
End Function

Public Sub ShowProc(ByVal strProc As String)
Dim r As New CodeMax4Ctl.Range

   If strProc = "" Then Exit Sub

   editor.FindText = "Sub " & strProc
   editor.ExecuteCmd cmCmdFindNext
   If editor.GetSel(True).IsEmpty Then
      If editor.LineCount > 0 Then
         r.StartColNo = 0
         r.StartLineNo = editor.LineCount
         r.Empty
         editor.SetSel r, True
      End If
      editor.AddText "Sub " & strProc & vbCrLf & vbCrLf & "End Sub" & vbCrLf & vbCrLf
      editor.ExecuteCmd cmCmdFindNext
   End If
   r.StartColNo = 0
   r.StartLineNo = editor.GetSel(True).EndLineNo + 1
   r.EndColNo = 0
   r.EndLineNo = r.StartLineNo
   editor.SetSel r, True
End Sub

' QueryMemberList is called when CodeMax needs a memberlist to display.  The application receiving
' the notification should look at the current selection and set 'List' to a memberlist that is most
' appropriate for the context.  If no memberlist should appear, call ICodeMax.CancelEvent() to prevent
' the list from appearing.  If 'List' is not set and CancelEvent() is not called, CodeMax will fall back
' to the value stored in ICodeMax.MemberList, then fall back to the current scopes (innermost to outermost)
' memberlist (ITokenSet.MemberList), then fall back to ILanguage.MemberList.
Private Sub editor_QueryMemberList(ByVal Cmd As CodeMax4Ctl.cmCommand, List As CodeMax4Ctl.IMemberList)
Dim p As CodeMax4Ctl.ILineParser
Dim sel As CodeMax4Ctl.Range
Dim obj As Object
    
    Set p = editor.CreateParser()
    Set sel = editor.GetSel(True)
'    If sel.EndLineNo = 0 Then Exit Sub
    p.LineNo = sel.EndLineNo
    p.ColNoAfterToken = sel.EndColNo
    
    ' scan backward a few tokens to see if 'Err' is one of them
    If (p.TokenText = "") Then
        Call p.GetNextToken(cmParseDirBackward)
    End If
   If p.TokenText = "=" Then
      Exit Sub
   End If
    If (p.TokenText <> ".") Then
        Call p.GetNextToken(cmParseDirBackward)
    End If
   If (p.TokenText = "." And sel.EndColNo >= p.TokenEndColNo) Then
      Call p.GetNextToken(cmParseDirBackward)
      Select Case UCase(p.TokenText)
      Case "ERR"
         Set List = cmGlobals.MemberLists("Err Methods")
         Exit Sub
      Case "OUTPUT"
         Set List = cmGlobals.MemberLists("Output")
         Exit Sub
      Case Else
         Set obj = LocateObjectByName(p.TokenText)
         If obj Is Nothing Then Exit Sub
         If obj.CEType = "ActiveX" Then
            'Stub for reading activex controls
            Exit Sub
         Else
            Set List = cmGlobals.MemberLists(obj.CEType)
            Exit Sub
         End If
      End Select
   End If
   
   Set List = cmGlobals.MemberLists("Global Methods")
End Sub

Sub setAllDividers()
   Dim i As Double
   Dim strLine As String
   clearAllDividers
   For i = 0 To editor.LineCount - 1
      strLine = LCase(Trim(editor.GetLine(i)))
      If Left(strLine, 7) = "end sub" Or Left(strLine, 12) = "end function" Then
         editor.SetDivider i, True
      End If
   Next
End Sub

Sub clearAllDividers()
   Dim i As Double
   For i = 0 To editor.LineCount - 1
      editor.SetDivider i, False
   Next
End Sub

Sub SetNewDividers(nStartLine As Long)
Dim i As Long
Dim strLine As String

   For i = nStartLine To 0 Step -1
      strLine = LCase(Trim(editor.GetLine(i)))
      If Left(strLine, 7) = "end sub" Or Left(strLine, 12) = "end function" Then
         editor.SetDivider i, True
         Exit For
      End If
   Next
   For i = nStartLine + 1 To editor.LineCount - 1
      strLine = LCase(Trim(editor.GetLine(i)))
      If Left(strLine, 7) = "end sub" Or Left(strLine, 12) = "end function" Then
         editor.SetDivider i, True
         Exit For
      End If
   Next
End Sub

Sub CloseBlock(nStartLine As Long)
Dim i As Long
Dim strLine As String
Dim bFound As Boolean
Dim procType As String
Dim pos As New Position
Static bClosing As Boolean

   If bClosing Then Exit Sub
   bClosing = True
   bFound = False
   strLine = LCase(Trim(editor.GetLine(nStartLine)))
   If Left(strLine, 4) = "sub " Or Left(strLine, 9) = "function " Then
      procType = Left(strLine, 1)
      For i = nStartLine + 1 To editor.LineCount - 1
         strLine = LCase(Trim(editor.GetLine(i)))
         If Left(strLine, 4) = "sub " Or Left(strLine, 9) = "function " Then Exit For
         If Left(strLine, 7) = "end sub" Or Left(strLine, 12) = "end function" Then
            bFound = True
            Exit For
         End If
      Next
      If Not bFound Then
         strLine = IIf(procType = "s", "End Sub", "End Function")
         pos.ColNo = editor.GetSel(True).StartColNo
         pos.LineNo = editor.GetSel(True).StartLineNo
         editor.InsertText vbCrLf & strLine & vbCrLf, pos
      End If
   End If
   bClosing = False
End Sub
