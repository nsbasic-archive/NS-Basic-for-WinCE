Attribute VB_Name = "MStringTable"
Global gStringTable(4000) As String
Global gLanguage As String
Global gLabelFontName As String
Global gLabelFontSize As Integer
Global gLabelCharset As Integer
Global installationDirectory As String

Sub LoadStringTable()
Dim message As String
Dim i As Integer
Dim chan As Integer

   On Error GoTo err_LoadStringTable
   chan = FreeFile
'   If frmMain.bRunningIDE Then
'      Open App.Path & "\..\Files\Lang\StrTable_English.txt" For Input As #chan
'   Else
      Open installationDirectory & "\Lang\StrTable_English.txt" For Input As #chan
'   End If
   
   For i = 0 To 4000
      gStringTable(i) = "String Table: " & i
   Next

   Do Until EOF(chan)
      Line Input #chan, message
      i = Val(Left(message, 4))
      gStringTable(i) = Mid(message, 6)
   Loop
   Close #chan

   If gLanguage <> "English" Then 'override English with other language
      Open installationDirectory & "\Lang\StrTable_" & gLanguage & ".txt" For Input As #chan

      Do Until EOF(chan)
         Line Input #chan, message
         On Error GoTo skipIt
         If InStr(message, "//") Then
            message = Mid(message, 1, InStr(message, "//") - 1)
         End If
         i = Val(Mid(message, 1, 4))
         gStringTable(i) = Mid(message, 6)
skipIt:
      Loop
      Close #chan
   End If

   Exit Sub

err_LoadStringTable:
   Close #chan
   MsgBox gStringTable(3472), vbCritical + vbOKOnly '"Unable to locate string resource file"
   End
End Sub

Sub LoadResStrings(frm As Form, Optional bLoadFont As Boolean = True)
Dim Ctl As Control
Dim obj As Object
Dim fnt As Object
Dim sCtlType As String
Dim nVal As Integer

   On Error Resume Next

   'set the font
   'If frm.caption <> "Demo Info" Then
   '   Set fnt = frm.font
   '   fnt.Name = gStringTable(3348) 'MS Sans Serif
   '   fnt.Size = CInt(gStringTable(3349)) '9
   'End If
   
   'set the form's caption
   frm.Caption = gStringTable(CInt(frm.Tag))
   
   'set the controls' captions using the caption
   'property for menu items and the Tag property
   'for all other controls
   For Each Ctl In frm.Controls
      'If bLoadFont Then Set ctl.font = fnt
      Ctl.FontName = gLabelFontName
      Ctl.Font.Charset = gLabelCharset
      If Ctl.Font.Size < gLabelFontSize Then Ctl.Font.Size = gLabelFontSize
      Select Case TypeName(Ctl)
      Case "Label"
         Ctl.Caption = gStringTable(CInt(Ctl.Tag))
      Case "Menu"
         Ctl.Caption = gStringTable(CInt(Ctl.Caption))
         Ctl.Tag = Ctl.Caption
      Case "TabStrip"
         For Each obj In Ctl.Tabs
            obj.Caption = gStringTable(CInt(obj.Tag))
            obj.ToolTipText = gStringTable(CInt(obj.ToolTipText))
         Next
      Case "Toolbar"
         For Each obj In Ctl.Buttons
            obj.ToolTipText = gStringTable(CInt(obj.ToolTipText))
         Next
      Case "ListView"
         For Each obj In Ctl.ColumnHeaders
            obj.Text = gStringTable(CInt(obj.Tag))
         Next
      Case "TextBox"
         Ctl.Text = gStringTable(CInt(Ctl.Tag))
      Case Else
         nVal = 0
         nVal = Val(Ctl.Tag)
         If nVal > 0 Then
            Ctl.Caption = gStringTable(nVal)
            If Len(Ctl.Caption) = 0 Then Ctl.Caption = "RES:" & Str(nVal)
         End If
         nVal = 0
         nVal = Val(Ctl.ToolTipText)
         If nVal > 0 Then
            Ctl.ToolTipText = gStringTable(nVal)
            If Len(Ctl.ToolTipText) = 0 Then Ctl.ToolTipText = "RES:" & Str(nVal)
         End If
      End Select
   Next
End Sub
