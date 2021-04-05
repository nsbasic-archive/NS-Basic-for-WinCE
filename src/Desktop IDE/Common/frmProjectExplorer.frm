VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmProjectExplorer 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Project Explorer"
   ClientHeight    =   2460
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4335
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MDIChild        =   -1  'True
   MinButton       =   0   'False
   Moveable        =   0   'False
   ScaleHeight     =   164
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   289
   ShowInTaskbar   =   0   'False
   Tag             =   "1174"
   Visible         =   0   'False
   Begin MSComctlLib.ImageList imlProjectExplorer 
      Left            =   120
      Top             =   1800
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      UseMaskColor    =   0   'False
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   10
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":0000
            Key             =   "NSBasic"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":0352
            Key             =   "FolderClosed"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":06A4
            Key             =   "FolderOpen"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":09F6
            Key             =   "Form"
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":0D48
            Key             =   "UIObject"
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":109A
            Key             =   "Menu"
         EndProperty
         BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":13EC
            Key             =   "MenuBar"
         EndProperty
         BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":173E
            Key             =   "MenuElem"
         EndProperty
         BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":1A90
            Key             =   "Bitmap"
         EndProperty
         BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmProjectExplorer.frx":1DE2
            Key             =   "Module"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.TreeView expl 
      Height          =   1695
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   4335
      _ExtentX        =   7646
      _ExtentY        =   2990
      _Version        =   393217
      HideSelection   =   0   'False
      Indentation     =   556
      LabelEdit       =   1
      Style           =   7
      ImageList       =   "imlProjectExplorer"
      Appearance      =   1
   End
   Begin VB.Menu mnuRightClickProject 
      Caption         =   "Right-Click menu for Project objects"
      Visible         =   0   'False
      Begin VB.Menu mnuRightProject 
         Caption         =   "View Code"
         Index           =   0
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "-"
         Index           =   1
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "&Add Form"
         Index           =   2
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "&Set Form Order..."
         Index           =   3
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "-"
         Index           =   4
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "Add &New Module"
         Index           =   5
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "Add Existing &Module..."
         Index           =   6
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "Set Module &Order..."
         Index           =   7
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "-"
         Index           =   8
      End
      Begin VB.Menu mnuRightProject 
         Caption         =   "Add Resource"
         Index           =   9
      End
   End
   Begin VB.Menu mnuRightClickForm 
      Caption         =   "Right-Click menu for Form objects"
      Visible         =   0   'False
      Begin VB.Menu mnuRightForm 
         Caption         =   "View &Object"
         Index           =   0
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "View &Code"
         Index           =   1
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "Edit &Menu"
         Index           =   3
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "Make &Default Form"
         Index           =   4
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "&Set Tab Order..."
         Index           =   5
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "-"
         Index           =   6
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "&Add Form"
         Index           =   7
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "De&lete"
         Index           =   8
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "-"
         Index           =   9
      End
      Begin VB.Menu mnuRightForm 
         Caption         =   "P&roperties"
         Index           =   10
      End
   End
End
Attribute VB_Name = "frmProjectExplorer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'Private IconMenu As New cIconMenu

Private m_nFormIndex As Long
Private m_nBitmapIndex As Long
Private m_nModuleIndex As Long
Private m_nResourceIndex As Long
Private m_strSelection As String

Public Sub DockWindow()
'On Error Resume Next
Dim lRet As Long

   Me.Visible = False

   'Make sure we keep the ToolWindow style
   lRet = SetWindowLong(Me.hWnd, GWL_EXSTYLE, CLng(WS_EX_TOOLBOXWINDOW))

   'Set parent and resize the panel
   SetParent Me.hWnd, frmMain.picProjectExplorer.hWnd
   frmMain.picProjectExplorer_Resize
   frmMain.picPanel_Resize

   frmMain.picPanel.Refresh
   frmMain.picPanel.Visible = True
   DoEvents
   Me.Visible = True
   SendMessage Me.hWnd, WM_NCACTIVATE, 1, 0
   frmMain.mnuViewProjectExplorer.Checked = gbProjectExplorer
End Sub

Public Sub DisplayExplorer()
Dim i As Integer
Dim wk, wk2 As String
Dim tempString As String
Dim proj As CProject
Dim frm As CForm
Dim ob As Object
Dim modul As CModule
Dim resource As CResourceFile
'''''Dim Bitmap As CBitmapFile
Dim nProject As Integer
Dim nItem As Integer

repeat:
   If expl.Nodes.Count <> 0 Then
      expl.Nodes.Clear
   End If
   For Each proj In gProjects
      expl.Nodes.Add , , , ""
      nProject = expl.Nodes.Count
      FillProjectNode nProject, proj
      expl.Nodes(nProject).Expanded = True
'      If expl.Nodes(nProject).Image = Empty Then
      expl.Nodes(nProject).Image = "NSBasic"
'      End If

      'Add Forms folder
      expl.Nodes.Add nProject, tvwChild, , "Forms"
      i = expl.Nodes.Count
      expl.Nodes(i).Tag = "Forms|" & proj.GlobalID
      If proj.Forms.Count >= 1 Then
         expl.Nodes(i).Expanded = True
      End If
      expl.Nodes(i).Image = "FolderClosed"
      expl.Nodes(i).ExpandedImage = "FolderOpen"

      'Add each form
      For Each frm In proj.Forms
         expl.Nodes.Add i, tvwChild, , ""
         nItem = expl.Nodes.Count
         FillFormNode nItem, frm, proj
         expl.Nodes(nItem).Image = "Form"
         'Open form folder if this is the active form
'MMD: Fix         If aView Is frm Then expl.Nodes(nForm).Expanded = True

         'Add objects from form
'         For Each ob In frm.Controls
'            DisplayContainer nForm, frm.Controls
'         Next
         DisplayContainer nItem, frm.Controls
      Next
      
      'Add Modules folder
      expl.Nodes.Add nProject, tvwChild, , "Modules"
      i = expl.Nodes.Count
      expl.Nodes(i).Tag = "Modules|" & proj.GlobalID
      If proj.Modules.Count > 1 Then
         expl.Nodes(i).Expanded = True
      End If
      expl.Nodes(i).Image = "FolderClosed"
      expl.Nodes(i).ExpandedImage = "FolderOpen"
      
      'Add each module
      For Each modul In proj.Modules
         If modul.Name <> "main" Then
            expl.Nodes.Add i, tvwChild, , ""
            nItem = expl.Nodes.Count
            FillModuleNode nItem, modul, proj
            expl.Nodes(nItem).Image = "Module"
         End If
      Next
      
      'Add Resources folder
      expl.Nodes.Add nProject, tvwChild, , "Resources"
      i = expl.Nodes.Count
      expl.Nodes(i).Tag = "Resources|" & proj.GlobalID
      If proj.ResourceFiles.Count > 1 Then
         expl.Nodes(i).Expanded = True
      End If
      expl.Nodes(i).Image = "FolderClosed"
      expl.Nodes(i).ExpandedImage = "FolderOpen"
      
      'Add each resource
      For Each resource In proj.ResourceFiles
         expl.Nodes.Add i, tvwChild, , ""
         nItem = expl.Nodes.Count
         FillResourceNode nItem, resource, proj
         expl.Nodes(nItem).Image = "Module"
      Next
   Next

   'Open Forms folder
'   expl.Nodes(m_nFormIndex).Expanded = True
   expl.Refresh
End Sub

Private Sub DisplayContainer(nForm As Integer, col As CControls)
Dim ob As Object

   For Each ob In col
      expl.Nodes.Add nForm, tvwChild, , ""
      FillObjectNode expl.Nodes.Count, ob
      If TypeName(ob) = "CFrame" Then
         DisplayContainer expl.Nodes.Count, ob.Controls
      End If
   Next
End Sub

Private Sub FillProjectNode(nProject As Integer, ByVal proj As CProject)
   expl.Nodes(nProject).Text = proj.Name
   expl.Nodes(nProject).Tag = proj.GlobalID
   If StrComp(proj.Name, gTarget.Name) = 0 Then
      expl.Nodes(nProject).Bold = True
   Else
      expl.Nodes(nProject).Bold = False
   End If
End Sub

Private Sub FillFormNode(nForm As Integer, ByVal frm As CForm, ByVal proj As CProject)
   If Len(frm.FormMenu) = 0 Then
      expl.Nodes(nForm).Text = frm.Name
   Else
      expl.Nodes(nForm).Text = frm.Name & "[Menu]"
   End If
   expl.Nodes(nForm).Bold = (frm.GlobalID = proj.DefaultForm)
   expl.Nodes(nForm).Tag = frm.GlobalID
End Sub

Private Sub FillObjectNode(nOb As Integer, ByVal ob As Object)
   expl.Nodes(nOb).Text = ob.Name
   expl.Nodes(nOb).Tag = ob.GlobalID
   expl.Nodes(nOb).Image = "UIObject"
End Sub

Private Sub FillModuleNode(nModule As Integer, ByVal modul As CModule, ByVal proj As CProject)
   expl.Nodes(nModule).Text = modul.Name
   expl.Nodes(nModule).Tag = modul.GlobalID
End Sub
Private Sub FillResourceNode(nResource As Integer, ByVal resource As CResourceFile, ByVal proj As CProject)
   Dim ResType As String
   If resource.ResType = 0 Then ResType = " (bitmap)"
   If resource.ResType = 1 Then ResType = " (file)"
   If resource.ResType = 2 Then ResType = " (wave)"
   If resource.ResType = 3 Then ResType = " (installer)"
   expl.Nodes(nResource).Text = resource.Name & ResType
   expl.Nodes(nResource).Tag = resource.GlobalID
End Sub

Private Sub expl_Collapse(ByVal Node As MSComctlLib.Node)
   If Left(Node.Tag, 4) = "form" Then
      frmMain.CloseMDIChild Node.Tag
   End If
End Sub

Private Sub expl_Expand(ByVal Node As MSComctlLib.Node)
   If Left(Node.Tag, 4) = "form" Then
      ViewObject Node.Tag
   End If
End Sub

Private Sub expl_KeyUp(KeyCode As Integer, Shift As Integer)
   If KeyCode = 93 Then expl_MouseUp 2, 0, -expl.Left, -expl.Top
End Sub

Private Sub expl_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim o2 As Object
Dim v2 As Object
Dim tempIndex As Integer
Dim arrTag() As String
Dim mnu As VB.Menu

   'Mouse coordinates are sent in as negative from KeyUp-Key=93
   'The is the Windows "Menu" key.
   'If menu key is used, the negative coordinates are the origin
   'of the expl object.  This makes the menu popup show at the top
   'left of expl when the key is pressed, otherwise at mouse location
   'when right-click occurs
   '  if x < 0 and y < 0 then
   '     PopupMenu mnuMenu, , -x, -y
   '  else
   '     PopupMenu mnuMenu
   '  end if

   'Locate the object being clicked on
      
   If expl.SelectedItem Is Nothing Then Exit Sub
   Set o2 = LocateObject(expl.SelectedItem.Tag)
   If o2 Is Nothing Then
      If gbProperties Then gfProperties.Object = Nothing
      Exit Sub
   End If

   Select Case Left(o2.GlobalID, InStr(o2.GlobalID, "|") - 1)
   Case "project"
      If gbProperties Then gfProperties.Object = o2
      If Button = vbRightButton Then PopupMenu mnuRightClickProject
      gbUpdatefrmScreen = True
     Exit Sub
   Case "form"
      Set v2 = frmMain.GetMDIChild(o2.GlobalID)
      If Not v2 Is Nothing Then
         v2.ClearSelection
         If gbProperties Then gfProperties.Object = o2
      End If
      If Button = vbRightButton Then PopupMenu mnuRightClickForm
      Exit Sub
   Case "object"
      gbUpdatefrmScreen = True
      If Not o2.Ctl Is Nothing Then 'Not o2.Obj.Control Is Nothing Then
         o2.Ctl.Visible = True
         o2.Ctl.parent.SetSelection o2
      End If
   Case "module"
      If gbProperties Then gfProperties.Object = o2
      ViewCode expl.SelectedItem.Tag
   Case Else
      gbUpdatefrmScreen = False
      If gbProperties Then gfProperties.Object = o2
   End Select

   If Button <> vbRightButton Then Exit Sub
   frmMain.RightClickMenu 1, expl.SelectedItem.Tag
End Sub  'expl_MouseUp

Private Sub SetFormOrder()
Dim fReorder As New frmReorder

   Set fReorder.gProj = gTarget
   fReorder.Show vbModal
End Sub

Private Sub SetModuleOrder()
Dim fReorder As New frmReorder

   Set fReorder.gProj = gTarget
   fReorder.OrderModules = True
   fReorder.Show vbModal
End Sub

Private Sub Form_Load()
   LoadResStrings Me
   Me.Left = -(Me.Width + 1)
   gbProjectExplorer = True
   If gbPlainText Then
      On Error GoTo badFont
      Me.FontName = gLabelFontName
      Me.Font.Charset = gLabelCharset
      On Error GoTo 0
      expl.Font.Name = gLabelFontName
      expl.Font.Charset = gLabelCharset
      
   End If
   Exit Sub
badFont:
   On Error GoTo 0
   gLanguage = "English"
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "Language", gLanguage
   LoadStringTable
   gLabelFontName = gStringTable(3348) 'MS Sans Serif if Western
   gLabelCharset = gStringTable(3350) '0 if western
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "IDEFontName", gLabelFontName  '01/19/01 GH
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "IDEFontSize", Str(gLabelFontSize)  '01/19/01 GH
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "IDEFontCharset", Str(gLabelCharset)  '01/19/01 GH
   MWinReg.SetRegValue MWinReg.hKey, "Software\NSBasic\" & kProduct & "\Editor", "FontName", gLabelFontName '03/26/01 GH
   MWinReg.SetRegValue MWinReg.hKey, "Software\NSBasic\" & kProduct & "\Editor", "FontCharSet", Str(gLabelCharset) '03/26/01 GH
   MsgBox "Bad Font setting." & gStringTable(3346) 'Restart NS Basic to see new language setting.

End Sub

Private Sub Form_Resize()
   If Me.WindowState = vbMinimized Then Exit Sub
   Me.ScaleMode = 3
   With expl
      .Width = Me.Width \ Screen.TwipsPerPixelX - 8 '* .left
      If Me.Height \ Screen.TwipsPerPixelY - (.Top + 25) > 0 Then
         .Height = Me.Height \ Screen.TwipsPerPixelY - (.Top + 25)
      End If
   End With
End Sub

Private Sub Form_Unload(Cancel As Integer)
   gbProjectExplorer = False
   frmMain.picPanel_Resize
   frmMain.mnuViewProjectExplorer.Checked = gbProjectExplorer
End Sub

Public Function GetNode(ByVal strTag As String) As MSComctlLib.Node
Dim i As Integer

   For i = 1 To expl.Nodes.Count
      If expl.Nodes(i).Tag = strTag Then
         Set GetNode = expl.Nodes(i)
         Exit Function
      End If
   Next
End Function

Public Sub RemoveNode(ByVal strID As String)
Dim nod As MSComctlLib.Node

   Set nod = GetNode(strID).parent
   expl.Nodes.Remove GetNode(strID).Index
   If nod Is Nothing Then Exit Sub
   If nod.Children < 1 Then nod.Expanded = False
End Sub

Public Sub ExpandNode(ByVal strID As String, ByVal bExpand As Boolean)
Dim nod As MSComctlLib.Node

   Set nod = GetNode(strID)
   If Not nod Is Nothing Then
      If bExpand Then
         nod.Expanded = True
      Else
         nod.Expanded = False
      End If
   End If
End Sub

Public Sub AddNewForm(ByRef frm As CForm, ByRef proj As CProject)
Dim nod As MSComctlLib.Node

   Set nod = GetNode("Forms|" & proj.GlobalID)   'Forms folder
   nod.Expanded = True
   Set nod = expl.Nodes.Add(nod.Index, tvwChild, , "")
   FillFormNode nod.Index, frm, proj
   nod.Image = "Form"
   Set expl.SelectedItem = nod
   nod.EnsureVisible
End Sub

Public Sub AddNewControl(ByVal obj As Object, ByVal par As Object)
Dim nod As MSComctlLib.Node

   Set nod = GetNode(par.GlobalID)  'Parent
   If nod Is Nothing Then Exit Sub
   nod.Expanded = True
   Set nod = expl.Nodes.Add(nod.Index, tvwChild, , "")
   FillObjectNode nod.Index, obj
   nod.Image = "UIObject"
   Set expl.SelectedItem = nod
   nod.EnsureVisible
End Sub

Public Sub AddNewModule(ByRef modul As CModule, ByRef proj As CProject)
Dim nod As MSComctlLib.Node

   Set nod = GetNode("Modules|" + proj.GlobalID) 'Modules folder
   nod.Expanded = True
   Set nod = expl.Nodes.Add(nod.Index, tvwChild, , "")
   FillModuleNode nod.Index, modul, proj
   nod.Image = "Module"
   Set expl.SelectedItem = nod
   nod.EnsureVisible
End Sub
Public Sub AddNewResourceFile(ByRef resource As CResourceFile, ByRef proj As CProject)
Dim nod As MSComctlLib.Node

   Set nod = GetNode("Resources|" + proj.GlobalID) 'Resources folder
   nod.Expanded = True
   Set nod = expl.Nodes.Add(nod.Index, tvwChild, , "")
   FillResourceNode nod.Index, resource, proj
   nod.Image = "Module"
   Set expl.SelectedItem = nod
   nod.EnsureVisible
End Sub

Public Sub UpdateTarget()
Dim i As Integer

   For i = 1 To gProjects.Count
      FillProjectNode GetNode(gProjects(i).GlobalID).Index, gProjects(i)
   Next
   SetCaption
End Sub

Public Sub SetCaption()
   Me.Caption = gStringTable(1301)
   If gTarget Is Nothing Then Exit Sub

   Me.Caption = Me.Caption & " - " & gTarget.Name
End Sub

Public Sub ShowActive(Optional obj As Object)

   If obj Is Nothing Then
      Set expl.SelectedItem = Nothing
      Exit Sub
   End If
   On Error GoTo ShowActiveErr1
   Set expl.SelectedItem = GetNode(obj.GlobalID)
   If gbProperties Then gfProperties.Object = obj 'LocateObject(obj.GlobalID)
   Exit Sub

ShowActiveErr1:
   Set expl.SelectedItem = GetNode(obj.obj.GlobalID)
   If gbProperties Then gfProperties.Object = LocateObject(obj.obj.GlobalID)
End Sub

Public Sub UpdateObjectNode(ByVal obj As Object, ByVal strGlobalID As String)
Dim nod As MSComctlLib.Node

   Set nod = GetNode(strGlobalID)
   If nod Is Nothing Then Exit Sub
   Select Case Left(strGlobalID, InStr(strGlobalID, "|") - 1)
   Case "project": FillProjectNode nod.Index, obj
   Case "form": FillFormNode nod.Index, obj, obj.Project
   Case "object": FillObjectNode nod.Index, obj
   Case "module": FillModuleNode nod.Index, obj, LocateProject(strGlobalID)
   Case "resource": FillResourceNode nod.Index, obj, LocateProject(strGlobalID)
   End Select
End Sub

Private Sub mnuRightProject_Click(Index As Integer)
   Select Case Index
   Case 0: ViewCode expl.SelectedItem.Tag
   'Case 1 'Separator
   Case 2: ProjectAddForm LocateProject(expl.SelectedItem.Tag)
   Case 3: SetFormOrder
   'Case 4 'Separator
   Case 5: ProjectNewModule LocateProject(expl.SelectedItem.Tag)
   Case 6: ProjectAddModule LocateProject(expl.SelectedItem.Tag)
   Case 7: SetModuleOrder
   'case 8 'Separator
   Case 9: ProjectAddResourceFile LocateProject(expl.SelectedItem.Tag)
   End Select
End Sub

Private Sub mnuRightForm_Click(Index As Integer)
   Select Case Index
   Case 0: ViewObject expl.SelectedItem.Tag
   Case 1: ViewCode expl.SelectedItem.Tag
   'Case 2 'Separator
   Case 3: OpenMenuEditor expl.SelectedItem.Tag
   Case 4
      Dim strOldDefault As String
      strOldDefault = LocateProject(expl.SelectedItem.Tag).DefaultForm
      LocateProject(expl.SelectedItem.Tag).DefaultForm = expl.SelectedItem.Tag
      UpdateObjectNode LocateObject(expl.SelectedItem.Tag), expl.SelectedItem.Tag
      UpdateObjectNode LocateObject(strOldDefault), strOldDefault
   Case 5
      Dim fReorder As New frmReorder
      Set fReorder.gForm = LocateObject(expl.SelectedItem.Tag)
      fReorder.Show vbModal
   'Case 6 'Separator
   Case 7: ProjectAddForm LocateProject(expl.SelectedItem.Tag)
   Case 8: ProjectRemoveForm LocateObject(expl.SelectedItem.Tag)
   'Case 8 'Separator
   'Case 9: Debug.Print "Properties"
   End Select
End Sub
