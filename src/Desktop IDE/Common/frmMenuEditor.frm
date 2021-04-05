VERSION 5.00
Begin VB.Form frmMenuEditor 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Menu Editor"
   ClientHeight    =   5190
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   5310
   Icon            =   "frmMenuEditor.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5190
   ScaleWidth      =   5310
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Tag             =   "1600"
   Begin VB.CommandButton butCancel 
      Cancel          =   -1  'True
      Caption         =   "&Cancel"
      Height          =   375
      Left            =   4200
      TabIndex        =   16
      Tag             =   "1619"
      Top             =   600
      Width           =   975
   End
   Begin VB.TextBox txtCaption 
      Height          =   375
      Left            =   960
      TabIndex        =   1
      Top             =   120
      Width           =   3135
   End
   Begin VB.ComboBox cmbShortcut 
      Height          =   315
      Left            =   960
      TabIndex        =   5
      Text            =   "cmbShortcut"
      Top             =   1080
      Width           =   3135
   End
   Begin VB.CommandButton butMove 
      Height          =   345
      Index           =   3
      Left            =   1560
      Picture         =   "frmMenuEditor.frx":038A
      Style           =   1  'Graphical
      TabIndex        =   9
      ToolTipText     =   "1609"
      Top             =   1560
      UseMaskColor    =   -1  'True
      Width           =   345
   End
   Begin VB.CommandButton butMove 
      Height          =   345
      Index           =   0
      Left            =   120
      Picture         =   "frmMenuEditor.frx":06CC
      Style           =   1  'Graphical
      TabIndex        =   6
      ToolTipText     =   "MOVE LEFT"
      Top             =   1560
      UseMaskColor    =   -1  'True
      Width           =   345
   End
   Begin VB.CommandButton butNext 
      Caption         =   "&Next"
      Default         =   -1  'True
      Height          =   375
      Left            =   2040
      TabIndex        =   10
      Tag             =   "1618"
      Top             =   1560
      Width           =   975
   End
   Begin VB.TextBox txtName 
      Height          =   375
      Left            =   960
      TabIndex        =   3
      Top             =   600
      Width           =   3135
   End
   Begin VB.CommandButton butMove 
      Height          =   345
      Index           =   2
      Left            =   1080
      Picture         =   "frmMenuEditor.frx":0876
      Style           =   1  'Graphical
      TabIndex        =   8
      ToolTipText     =   "1608"
      Top             =   1560
      UseMaskColor    =   -1  'True
      Width           =   345
   End
   Begin VB.CommandButton butMove 
      Height          =   345
      Index           =   1
      Left            =   600
      Picture         =   "frmMenuEditor.frx":0BB8
      Style           =   1  'Graphical
      TabIndex        =   7
      ToolTipText     =   "MOVE RIGHT"
      Top             =   1560
      UseMaskColor    =   -1  'True
      Width           =   345
   End
   Begin VB.CommandButton butInsert 
      Caption         =   "&Insert"
      Height          =   375
      Left            =   3120
      TabIndex        =   11
      Tag             =   "1603"
      Top             =   1560
      Width           =   975
   End
   Begin VB.CommandButton butDelete 
      Caption         =   "Dele&te"
      Height          =   375
      Left            =   4200
      TabIndex        =   12
      Tag             =   "1017"
      Top             =   1560
      Width           =   975
   End
   Begin VB.ListBox lstMenu 
      Height          =   2790
      ItemData        =   "frmMenuEditor.frx":0D62
      Left            =   120
      List            =   "frmMenuEditor.frx":0D64
      TabIndex        =   14
      Top             =   2280
      Width           =   5055
   End
   Begin VB.CommandButton butOK 
      Caption         =   "&OK"
      Height          =   375
      Left            =   4200
      TabIndex        =   15
      Tag             =   "1106"
      Top             =   120
      Width           =   975
   End
   Begin VB.Label Label3 
      Caption         =   "Shortcut:"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Tag             =   "1613"
      Top             =   1155
      Width           =   855
   End
   Begin VB.Line Line1 
      X1              =   120
      X2              =   7080
      Y1              =   1440
      Y2              =   1440
   End
   Begin VB.Label Label1 
      Caption         =   "Caption:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Tag             =   "1611"
      Top             =   240
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Tag             =   "1610"
      Top             =   720
      Width           =   855
   End
   Begin VB.Label Label5 
      Caption         =   "Menu &Layout:"
      Height          =   255
      Left            =   240
      TabIndex        =   13
      Tag             =   "1614"
      Top             =   2040
      Width           =   3015
   End
   Begin VB.Menu mnuRight 
      Caption         =   "Right-Click"
      Visible         =   0   'False
      Begin VB.Menu mnuRightMove 
         Caption         =   "1601"
         Index           =   0
      End
      Begin VB.Menu mnuRightMove 
         Caption         =   "1602"
         Index           =   1
      End
      Begin VB.Menu mnuRightBar0 
         Caption         =   "-"
      End
      Begin VB.Menu mnuRightAdd 
         Caption         =   "1603"
         Index           =   0
      End
      Begin VB.Menu mnuRightAdd 
         Caption         =   "1017"
         Index           =   1
      End
   End
End
Attribute VB_Name = "frmMenuEditor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Form As CForm
Private m_Target As CMenuItem
Private m_bProgramSet As Boolean
Private m_bCancel As Boolean

Private m_col As New Collection
Private m_nItemSerial As Integer
Private Const kValidChars As String = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"
Private Const kValid As String = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz0123456789"

Private Sub Form_Load()
Dim i As Integer

   m_nItemSerial = 0
   LoadResStrings Me

''   If gbPlainText Then
''      txtCaption.FontName = gLabelFontName
''      lstMenu.FontName = gLabelFontName
''   End If
''   txtCaption.Font.Charset = gLabelCharset
''   lstMenu.Font.Charset = gLabelCharset

   'Initialize Shortcut Combobox
   cmbShortcut.Clear
   cmbShortcut.AddItem "(None)"
   For i = 0 To 9
      cmbShortcut.AddItem "Ctrl+" & i
      cmbShortcut.ItemData(i + 1) = i + 1
   Next
   For i = Asc("A") To Asc("Z")
      cmbShortcut.AddItem "Ctrl+" & Chr(i)
      cmbShortcut.ItemData(i - Asc("A") + 11) = i
   Next
   m_bCancel = True
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
Dim i As Integer
Dim j As Integer
Dim mnuItem1 As CMenuItem
Dim mnuItem2 As CMenuItem
Dim nIndent As Integer
Dim nCurrent As Integer
Dim nMaxIndent As Integer
Dim strTemp As String
Dim strParent As String

   If m_bCancel Then Exit Sub

   'Let's check the integrity of the list items
   For i = 0 To lstMenu.ListCount - 1
      Set mnuItem1 = m_col(Str(lstMenu.ItemData(i)))
      If Len(mnuItem1.Name) = 0 And Left(mnuItem1.Caption, 1) <> "-" Then
         MsgBox gStringTable(3417) '"Menu item must have a name (Use - for a menu separator)"
         Cancel = 1
         lstMenu.ListIndex = i
         txtName.SetFocus
         Exit Sub
      End If
      If Not ValidMenuName(mnuItem1.Name) Then
         MsgBox gStringTable(3416) '"Menu name can only contain [A-Z, a-z, 0-9, _], and must begin with a letter or an underscore."
         Cancel = 1
         lstMenu.ListIndex = i
         txtName.SetFocus
         SendKeys "{Home}+{End}"
         Exit Sub
      End If
   Next
   For i = 0 To lstMenu.ListCount - 2
      Set mnuItem1 = m_col(Str(lstMenu.ItemData(i)))
      Set mnuItem2 = m_col(Str(lstMenu.ItemData(i + 1)))
      If mnuItem2.Indent > mnuItem1.Indent + 1 Then
         MsgBox gStringTable(3418) '"Menu item skipped a level"
         Cancel = 1
         lstMenu.ListIndex = i + 1
         Exit Sub
      End If
   Next
   
   'Looks good, so let's rebuild the setmenu code
   'First find the maximum indent
   nMaxIndent = 0
   For i = 0 To lstMenu.ListCount - 1
      Set mnuItem1 = m_col(Str(lstMenu.ItemData(i)))
      If mnuItem1.Indent > nMaxIndent Then nMaxIndent = mnuItem1.Indent
   Next
   'We only need to build nMaxIndent - 1 levels of menus
   m_Form.FormMenu = ""
   strTemp = ""
   strParent = "TitleBar"
   For nCurrent = 0 To nMaxIndent
      For i = 0 To lstMenu.ListCount - 1
         Set mnuItem1 = m_col(Str(lstMenu.ItemData(i)))
         If mnuItem1.Indent = nCurrent Then
            strTemp = strTemp & GetSetMenu(mnuItem1) & Chr(13)
         ElseIf mnuItem1.Indent < nCurrent Then
            If Len(strTemp) > 0 Then
               strTemp = Left(strTemp, Len(strTemp) - 1)
               m_Form.FormMenu = m_Form.FormMenu & "   SetMenu """ & strParent & """, Array(" & Join(Split(strTemp, Chr(13)), ", ") & ")" & vbCrLf
               strTemp = ""
            End If
            strParent = mnuItem1.Name
         End If
      Next
      If Len(strTemp) > 0 Then
         strTemp = Left(strTemp, Len(strTemp) - 1)
         m_Form.FormMenu = m_Form.FormMenu & "   SetMenu """ & strParent & """, Array(" & Join(Split(strTemp, Chr(13)), ", ") & ")" & vbCrLf
         strTemp = ""
      End If
   Next
   'If Len(m_Form.FormMenu) > 0 Then m_Form.FormMenu = Left(m_Form.FormMenu, Len(m_Form.FormMenu) - 1)
End Sub

Private Sub butOK_Click()
   m_bCancel = False
   Unload Me
End Sub

Private Sub butCancel_Click()
   m_bCancel = True
   Unload Me
End Sub

Private Sub butMove_Click(Index As Integer)
Dim nIndex As Integer
Dim nItemData As Long
Dim nTemp As Long
Dim mnuItem As CMenuItem

   nItemData = lstMenu.ItemData(lstMenu.ListIndex)
   Set mnuItem = m_col(Str(nItemData))

   Select Case Index
   Case 0 'Move Left
      'Can't move left past titlebar (no indent)
      If mnuItem.Indent = 0 Then Exit Sub
      mnuItem.Indent = mnuItem.Indent - 1
      UpdateListItem lstMenu.ListIndex, mnuItem
   Case 1 'Move Right
      mnuItem.Indent = mnuItem.Indent + 1
      UpdateListItem lstMenu.ListIndex, mnuItem
   Case 2 'Move Up
      'Can't move above first item
      If lstMenu.ListIndex = 0 Then Exit Sub
      'Store ItemData for swapping
      nTemp = lstMenu.ItemData(lstMenu.ListIndex - 1)
      lstMenu.ItemData(lstMenu.ListIndex - 1) = nItemData
      lstMenu.ItemData(lstMenu.ListIndex) = nTemp
      'Update both entries
      UpdateListItem lstMenu.ListIndex - 1, mnuItem
      UpdateListItem lstMenu.ListIndex, m_col(Str(lstMenu.ItemData(lstMenu.ListIndex)))
      lstMenu.ListIndex = lstMenu.ListIndex - 1
   Case 3 'Move Down
      'Can't move below last item
      If lstMenu.ListIndex >= lstMenu.ListCount - 1 Then Exit Sub
      'Store ItemData for swapping
      nTemp = lstMenu.ItemData(lstMenu.ListIndex + 1)
      lstMenu.ItemData(lstMenu.ListIndex + 1) = nItemData
      lstMenu.ItemData(lstMenu.ListIndex) = nTemp
      'Update both entries
      UpdateListItem lstMenu.ListIndex + 1, mnuItem
      UpdateListItem lstMenu.ListIndex, m_col(Str(lstMenu.ItemData(lstMenu.ListIndex)))
      lstMenu.ListIndex = lstMenu.ListIndex + 1
   End Select
End Sub

Private Sub butNext_Click()
   'Add another item if at the end of list, otherwise move to next item
   If lstMenu.ListIndex >= (lstMenu.ListCount - 1) Then
      AddMenuItem "", ""
   Else
      lstMenu.ListIndex = lstMenu.ListIndex + 1
   End If

   'Move to caption field and select all
   txtCaption.SetFocus
   SendKeys "{Home}+{End}"
End Sub

Private Sub butInsert_click()
   'Insert new menu item, select it, then move to caption field
   AddMenuItem "", "", lstMenu.ListIndex
   lstMenu.ListIndex = lstMenu.ListIndex
   txtCaption.SetFocus
End Sub

Private Sub butDelete_click()
Dim nTemp As Long

   'Get the index of item to delete for proper selection after item is removed
   nTemp = lstMenu.ListIndex
   If nTemp < 0 Or lstMenu.ListCount = 0 Then Exit Sub
   m_col.Remove Str(lstMenu.ItemData(nTemp))
   lstMenu.RemoveItem nTemp
   If nTemp >= lstMenu.ListCount Then
      lstMenu.ListIndex = nTemp - 1
   Else
      lstMenu.ListIndex = nTemp
   End If
End Sub

Private Sub SetTxtCaption(ByVal strCaption As String)
   'Use this routine to programmatically set the caption,
   'so txtCaption_Change is not called
   m_bProgramSet = True
   txtCaption.Text = strCaption
   m_bProgramSet = False
End Sub

Private Sub txtCaption_Change()
Dim strTemp As String

   'Updates list item and menu item in real time
   If m_bProgramSet Then Exit Sub
   If m_Target Is Nothing Then
      strTemp = txtCaption.Text
      AddMenuItem "", ""
      txtCaption.Text = strTemp
      SendKeys "{End}{End}"
   End If
   m_Target.Caption = txtCaption.Text
   UpdateListItem lstMenu.ListIndex, m_Target
End Sub

Private Sub txtName_Change()
   'Updates menu item in real time
   m_Target.Name = txtName.Text
End Sub

Private Sub cmbShortcut_click()
   'Updates list item and menu item in real time
   If m_bProgramSet Then Exit Sub
   If m_Target Is Nothing Then Exit Sub
   If cmbShortcut.ListIndex = 0 Then
      m_Target.Shortcut = ""
   Else
      m_Target.Shortcut = cmbShortcut.Text
   End If
   UpdateListItem lstMenu.ListIndex, m_Target
End Sub

Private Sub cmbShortcut_Change()
   'Updates list item and menu item in real time
   If m_Target Is Nothing Then Exit Sub
   m_Target.Shortcut = cmbShortcut.Text
   UpdateListItem lstMenu.ListIndex, m_Target
End Sub

Private Sub UpdateListItem(nIndex As Long, mnuItem As CMenuItem)
Dim strTemp As String

   'Update the listbox item
   strTemp = String(mnuItem.Indent * 4, ".") & mnuItem.Caption
   If Len(mnuItem.Shortcut) Then strTemp = strTemp & " [" & mnuItem.Shortcut & "]"
   lstMenu.List(nIndex) = strTemp
End Sub

Private Sub ReadMenus()
Dim arrCode() As String
Dim arrMenu() As String
Dim strMenuName As String
Dim i As Integer
Dim j As Integer

'   ''Debug crutch
'Dim strTemp As String
'   strTemp = "SetMenu ""TitleBar"", Array(""&J. Lo||JLo"",""&P. Diddy||PDiddy"",""&Alba||JA"")"
'   strTemp = strTemp & vbCrLf & "SetMenu ""JLo"", Array(""Jennifer" & vbTab & "Ctrl+,||Jen"", ""&HOT" & vbTab & "Ctrl+"""")"
'   strTemp = strTemp & vbCrLf & "SetMenu ""PDiddy"", Array(""Sean John" & vbTab & "Ctrl+S||Sean"")"
'   strTemp = strTemp & vbCrLf & "SetMenu ""JA"", Array(""&Dark Angel"", ""&Idle Hands"")"
'   m_Form.FormMenu = strTemp
   
   If Len(m_Form.FormMenu) = 0 Then Exit Sub

   'Get array of individual SetMenu commands
   arrCode = Split(m_Form.FormMenu, vbCrLf)

   'Do the 'TitleBar' menu
   'Get menu name and ensure that first menu is named 'titlebar'
   strMenuName = GetMenuName(arrCode(0))
   If LCase(strMenuName) <> "titlebar" Then
      MsgBox gStringTable(3419) '"Menu Parse Error: titlebar"
      Exit Sub
   End If
   'Get menu items
   arrMenu = Split(TokenizeSetMenu(arrCode(0)), Chr(13))
   For i = 0 To UBound(arrMenu)
      AddMenuItem arrMenu(i), "titlebar"
   Next

   'Do all other menus
   For i = 1 To UBound(arrCode)
      If arrCode(i) <> "" Then
         strMenuName = GetMenuName(arrCode(i))
         arrMenu = Split(TokenizeSetMenu(arrCode(i)), Chr(13))
         For j = 0 To UBound(arrMenu)
            AddMenuItem arrMenu(j), strMenuName
         Next
      End If
   Next
End Sub

Sub AddMenuItem(strItem As String, strParent As String, Optional nIndex As Integer = -1)
Dim strCaption As String
Dim strName As String
Dim strShortcut As String
Dim strTemp As String
Dim n As Integer
Dim nIndent As Integer
Dim mnuItem As New CMenuItem

   'This for appending new items
   If Len(strItem) = 0 And Len(strParent) = 0 Then
      If lstMenu.ListCount > 0 Then
         mnuItem.Indent = m_col(Str(lstMenu.ItemData(lstMenu.ListCount - 1))).Indent
      Else
         mnuItem.Indent = 0
      End If
      If nIndex >= 0 Then
         lstMenu.AddItem "", nIndex
      Else
         lstMenu.AddItem ""
      End If
      GoTo AddMenuItem_Append
   End If

   'Look for || to split caption/name
   n = InStr(1, strItem, "||")
   If n > 0 Then
      strCaption = Left(strItem, n - 1)
      strName = Mid(strItem, n + 2)
   Else
      strCaption = strItem
      If InStr(1, strItem, vbTab) Then
         strName = Left(strItem, InStr(1, strItem, vbTab) - 1)
      End If
   End If

   'Look for tab to split caption/shortcut
   n = InStr(1, strCaption, vbTab)
   If n > 0 Then
      strShortcut = Mid(strCaption, n + 1)
      strCaption = Left(strCaption, n - 1)
   End If

   'Fill the new item with the info we just parsed
   mnuItem.Name = strName
   mnuItem.Caption = strCaption
   mnuItem.Shortcut = strShortcut
   If strParent = "titlebar" Then
      mnuItem.Indent = 0
      n = -1
   Else
      For n = 0 To lstMenu.ListCount
         'First, find the parent
         If LCase(m_col(Str(lstMenu.ItemData(n))).Name) = LCase(strParent) Then
            nIndent = m_col(Str(lstMenu.ItemData(n))).Indent
            mnuItem.Indent = nIndent + 1
            Exit For
         End If
      Next
      'Now find the parent's next sibling
      For n = n + 1 To lstMenu.ListCount - 1
         If m_col(Str(lstMenu.ItemData(n))).Indent <= nIndent Then
            Exit For
         End If
      Next
      If n > lstMenu.ListCount Then n = -1
   End If

   'Add a blank item to the listbox
   If n < 0 Then
      lstMenu.AddItem ""
   Else
      lstMenu.AddItem "", n
   End If

AddMenuItem_Append:
   'Add to the collection
   m_col.Add mnuItem, Str(m_nItemSerial)

   'Update the blank list item, based on the new menu item
   lstMenu.ItemData(lstMenu.NewIndex) = m_nItemSerial
   UpdateListItem lstMenu.NewIndex, mnuItem

   'Update the serial number
   m_nItemSerial = m_nItemSerial + 1

   'Make sure everyone is pointing at the new item
   lstMenu.ListIndex = lstMenu.NewIndex
   Set m_Target = mnuItem
End Sub

Function GetMenuName(ByRef strSetMenu As String) As String
   'Reads a '   SetMenu "...", Array(...)' line as string
   'returns the menu name "..."
   'and changes incoming string to include only the text inside of Array() call
   strSetMenu = Trim(strSetMenu)
   strSetMenu = Mid(strSetMenu, Len("SetMenu ") + 1)
   GetMenuName = Mid(strSetMenu, 2, InStr(1, strSetMenu, ",") - 3)
   strSetMenu = Mid(strSetMenu, InStr(1, strSetMenu, "Array(", vbTextCompare) + Len("Array("))
   strSetMenu = Left(strSetMenu, InStrRev(strSetMenu, ")") - 1)
End Function

Function ValidMenuName(ByVal strMenuName As String) As Boolean
Dim i As Integer

   'Ensure that menu names follow VB naming convention
   ValidMenuName = False

   If InStr(1, kValidChars, Left(strMenuName, 1)) = 0 Then Exit Function
   For i = 2 To Len(strMenuName)
      If InStr(1, kValid, Mid(strMenuName, i, 1)) = 0 Then Exit Function
   Next
   ValidMenuName = True
End Function

Function GetSetMenu(mnuItem As CMenuItem) As String
   'Builds a '   SetMenu "...", Array()' string from a menu item
   GetSetMenu = """"
   If Len(mnuItem.Name) > 0 Then GetSetMenu = "||" & mnuItem.Name & GetSetMenu
   If Len(mnuItem.Shortcut) > 0 Then
      GetSetMenu = mnuItem.Caption & vbTab & mnuItem.Shortcut & GetSetMenu
   Else
      GetSetMenu = mnuItem.Caption & mnuItem.Shortcut & GetSetMenu
   End If
   GetSetMenu = """" & GetSetMenu
End Function

Function TokenizeSetMenu(ByVal strArray As String) As String
Dim i As Integer
Dim bQuote As Boolean
Dim arrTok() As String

   'Step through one character at a time to find tokens
   'Replace unquoted commas with chr(13), and remove unquoted spaces
   bQuote = False
   For i = 1 To Len(strArray)
      If Mid(strArray, i, 1) = """" Then
         bQuote = Not bQuote
      Else
         If Not bQuote Then
            If Mid(strArray, i, 1) = "," Then
               strArray = Left(strArray, i - 1) & Chr(13) & Mid(strArray, i + 1)
            ElseIf Mid(strArray, i, 1) = " " Then
               strArray = Left(strArray, i - 1) & Mid(strArray, i + 1)
               i = i - 1
            End If
         End If
      End If
   Next

   'Now it is safe to split on chr(13)
   'Perform split, remove enclosing quotes, and rejoin with chr(13)
   arrTok = Split(strArray, Chr(13))
   For i = 0 To UBound(arrTok)
      arrTok(i) = Mid(arrTok(i), 2, Len(arrTok(i)) - 2)
   Next
   TokenizeSetMenu = Join(arrTok, Chr(13))
End Function

Private Sub UpdateDialog()
   'When a valid list item is selected, reference the menu item it displays
   'and fill the edit fields of the dialog (caption, name, shortcut)
   If lstMenu.ListIndex >= 0 Then
      Set m_Target = m_col(Str(lstMenu.ItemData(lstMenu.ListIndex)))
      txtName.Text = m_Target.Name
      SetTxtCaption m_Target.Caption
      If Len(m_Target.Shortcut) Then
         cmbShortcut.Text = m_Target.Shortcut
      Else
         m_bProgramSet = True
         cmbShortcut.ListIndex = 0
         m_bProgramSet = False
      End If
   End If
End Sub

Private Sub lstMenu_Click()
   UpdateDialog
End Sub

'This menu doesn't work in CED for some reason
Private Sub lstMenu_KeyUp(KeyCode As Integer, Shift As Integer)
   If KeyCode = 93 Then PopupMenu mnuRight
End Sub

'This menu doesn't work in CED for some reason
Private Sub lstMenu_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
   If Button = vbRightButton Then PopupMenu mnuRight
End Sub

'This menu doesn't work in CED for some reason
Private Sub mnuRightAdd_Click(Index As Integer)
   Select Case Index
   Case 0: butInsert_click
   Case 1: butDelete_click
   End Select
End Sub

'This menu doesn't work in CED for some reason
Private Sub mnuRightMove_Click(Index As Integer)
   butMove_Click Index
End Sub

Public Property Let Form(ByVal frm As CForm)
   'Assigning a form object to this property is the initialization procedure
   'of the dialog.  It sets window caption, and reads the menus from the form
   'object, to build list and menu items
   Set m_Form = frm
   Me.Caption = Me.Caption & " - " & m_Form.Name
   ReadMenus
   If lstMenu.ListCount > 0 Then lstMenu.ListIndex = 0 Else AddMenuItem "", ""
End Property
