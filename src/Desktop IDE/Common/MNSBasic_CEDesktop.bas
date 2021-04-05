Attribute VB_Name = "MNSBasic_CEDesktop"
Option Explicit
Public Const knToolboxButtons = 29
Public Const EM_SETREADONLY = &HCF
#If NSBasic_CE Then
   Public Const kIntrinsics = "PictureBox Label TextBox Frame CommandButton GradientButton CheckBox OptionButton ComboBox ListBox HScrollBar VScrollBar Date Time TriButton "
   Public Const kActiveXControls = "NSBComDlg.dll|NSBControls.dll|NSBWin32.dll|MSCEFile.dll|MSCEGrid.dll|MSCEImage.dll|MSCEImageList.dll|MSCEListView.dll|MSCETabStrip.dll|MSCETreeView.dll|MSCEWinsock.dll|SerialXP.dll"
   Public Const kActiveXNames = "CommonDialog Comm File FileSystem GridCtrl ImageList ImageCtl ListViewCtrl TabStrip TreeViewCtl Winsock "
#End If
#If NSBasic_Desktop Then
   Public Const kIntrinsics = "PictureBox Label TextBox Frame CommandButton GradientButton CheckBox OptionButton ComboBox ListBox HScrollBar VScrollBar Date Time TriButton "
   Public Const kActiveXControls = "NSBComDlg.dll|NSBControls.dll|NSCEPictureBox.ocx|NSBWin32.dll"
   Public Const kActiveXNames = ""
#End If
#If NSBasic_X Then
   Public Const kIntrinsics = "PictureBox Label TextBox Frame CommandButton GradientButton CheckBox OptionButton ComboBox ListBox HScrollBar VScrollBar Date Time TriButton "
   Public Const kActiveXControls = ""
   Public Const kActiveXNames = ""
#End If
Public gdblClickTime As Double
'Global gbLaunchEmulator As Boolean
Global gnRunTarget As Integer
Global gbActiveSyncRun As Boolean
Global gbSaveBeforeRun As Boolean
Global gstrDeviceInstallPath As String
Global gFormWidth As Integer
Global gFormHeight As Integer
Global gMenuTop As Boolean
'Global gCERemote As CCERemote2
Global gCommandLineOptions As String
Global gCommandLineProject As String
Global gbCompressCab As Boolean
Global gbDeleteWorkFiles As Boolean
Global gbRetainCabFiles As Boolean
Global gnLanguage As Integer
Global gnPlatform As Integer
Global gbCompiling As Boolean

Public Declare Function GetDoubleClickTime Lib "USER32" () As Long
Public Declare Function OleTranslateColor Lib "olepro32.dll" (ByVal clr As Long, ByVal hPal As Long, ByRef colorref As Long) As Long
Private Declare Function GetCurrentProcessId Lib "kernel32" () As Long

Public Sub PlatformInit()
   gdblClickTime = GetDoubleClickTime / 1000
'   gConnect = wsDisconnected
   'Set gCERemote = New CCERemote2
End Sub

Public Function GetPlatformUserPrefs() As Boolean
Dim strFF As String

   On Error GoTo err_GetPlatformUserPrefs
'   gbLaunchEmulator = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "LaunchEmulator", True)
'   gnRunTarget = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "RunTarget", 0)
   gnRunTarget = 1
   gbActiveSyncRun = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ActiveSyncRun", True)
   gbSaveBeforeRun = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "SaveBeforeRun", True)
   gstrDeviceInstallPath = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "DeviceInstallPath", "\")

   'Test to see if form factors are registered
   'strFF = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Form Factors", "None")
   'If strFF = "None" Then
      #If NSBasic_CE Then
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Form Factors", "Pocket PC|Pocket PC Square 240|Pocket PC Landscape|Pocket PC VGA"
         'MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "Pocket PC"
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC X", 240
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Y", 320
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC M", "Bottom"
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Square 240 X", 240
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Square 240 Y", 240
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Square 240 M", "Bottom"
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Landscape X", 320
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Landscape Y", 240
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC Landscape M", "Bottom"
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC VGA X", 480
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC VGA Y", 640
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Pocket PC VGA M", "Bottom"
      #End If
      #If NSBasic_Desktop Then
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Form Factors", "VGA"
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "VGA"
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "VGA X", 640
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "VGA Y", 480
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "VGA M", "Top"
      #End If
   'End If
   #If NSBasic_CE Then
      strFF = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "Pocket PC")
   #End If
   #If NSBasic_Desktop Then
      strFF = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "VGA")
   #End If
   gFormWidth = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", strFF & " X", "240")
   gFormHeight = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", strFF & " Y", "320")
   gMenuTop = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", strFF & " M", "Bottom") = "Top"
   GetPlatformUserPrefs = True

err_GetPlatformUserPrefs:
   GetPlatformUserPrefs = False
End Function

Public Sub CheckSerialNumber()
Dim serNo As Long

#If NSBasic_CE Then
   serNo = CheckSerial(gSerialNumber, 2)
   If serNo = 1 Then serNo = 0 'pirated
   If serNo = 4746 Then serNo = 0 'pirated
   If serNo = 5910 Then serNo = 0 'purchased using stolen card
   If serNo = 6188 Then serNo = 0 'purchased using stolen card
#End If
#If NSBasic_Desktop Then
   serNo = CheckSerial(gSerialNumber, 3)
   If serNo = 1 Then serNo = 0 'used only during beta testing
   If serNo = 8 Then serNo = 0 'leaked on web board
#End If

If serNo > 0 Then
   gDemoSW = "n"
Else
   gDemoSW = "y"
   gSerialNumber = "Unregistered Demo"
End If
End Sub


Public Function CheckSerial(ByVal astrSerial As String, ByRef anProduct As Integer) As Long
Dim nProduct As Integer
Dim nMod As Integer
Dim nCustNum As Long
Dim nPad1 As Integer, nPad2 As Integer
Dim nCheck As Integer

   ' Prod | Dig4 | Dig3 | Pad1 | Dig0 | Pad2 | Dig2 | Dig1 | Chk
   'Product Code: a-f = Prod #1, g-l = Prod #2, m-r = Prod #3, s-x = Prod #4
   'ModVal:       1-6 = Prod #1, 1-6 = Prod #2, 1-6 = Prod #3, 1-6 = Prod #4
   'Customer # = Dig0Dig1Dig2Dig3Dig4
   '(Pad1 + Dig2Dig1) mod 7 = ModVal
   '(Pad2 + Dig4Dig3) mod 7 = ModVal
   astrSerial = Replace(astrSerial, "-", "")
   If Len(astrSerial) <> 9 Then
      CheckSerial = 0
      Exit Function
   End If
   CheckSerial = -1
   nProduct = (Asc(UCase(Left(astrSerial, 1))) - Asc("A"))
   'Skip check for generic test
   If anProduct = 0 Then
      anProduct = (nProduct \ 6) + 1
   Else
      If (nProduct \ 6) + 1 <> anProduct Then Exit Function
   End If
   nMod = (nProduct Mod 6) + 1
   nCustNum = Val(Mid(astrSerial, 5, 1) & StrReverse(Mid(astrSerial, 2, 2) & Mid(astrSerial, 7, 2)))
   nCheck = (Asc(UCase(Right(astrSerial, 1))) - Asc("A"))
   If nCustNum Mod 23 <> nCheck Then Exit Function
   nPad1 = Val(Mid(astrSerial, 4, 1))
   If (nPad1 + Val(Mid(astrSerial, 7, 2))) Mod 7 <> nMod Then Exit Function
   nPad2 = Val(Mid(astrSerial, 6, 1))
   If (nPad2 + Val(Mid(astrSerial, 2, 2))) Mod 7 <> nMod Then Exit Function
   CheckSerial = nCustNum
End Function

Sub MakeGlobalDirectories()

End Sub

Public Function ViewObject(strGlobalID As String) As frmScreen
Dim obj As Object

   Set ViewObject = frmMain.GetMDIChild(strGlobalID)
   If ViewObject Is Nothing Then
      Set obj = LocateObject(strGlobalID)
      Select Case TypeName(obj)
      Case "CForm"
         Set ViewObject = New frmScreen
         ViewObject.Object = obj
         If ViewObject.WindowState = vbNormal Then ViewObject.Move 0, 0
         ViewObject.Show
         frmMain.AddMDIChild ViewObject
'      Case "CModule"
      Case "CResource"
      Case Else  'View a form control
         'Locate and open an object's form
         Set ViewObject = ViewObject(obj.Form.GlobalID)
         'Select object on form
         ViewObject.SetSelection obj
      End Select
   End If
   ViewObject.Show
   ViewObject.ZOrder
'   ShowStatus ViewObject.Tag, True
End Function

Public Function ViewCode(ByVal strGlobalID As String, Optional ByVal strScript As String) As frmCode
Dim obj As Object
Dim strCode As String
Dim proj As CProject
Dim trace As Boolean
trace = False

   If trace Then MsgBox "ViewCode " & 1
   If Left(strGlobalID, Len("module")) = "module" Then
      Set obj = LocateObject(strGlobalID)
   Else
      Set obj = LocateProject(strGlobalID)
   End If
   If obj Is Nothing Then Exit Function
   
   strCode = obj.GlobalID


   If trace Then MsgBox "ViewCode " & 2
   'For the code windows, we tack on a pipe and the script type
   'ie. form|1003|project|7 -> form|1003|project|7|before
   Set ViewCode = frmMain.GetMDIChild(strCode)
   If ViewCode Is Nothing Then
      Set ViewCode = New frmCode
      ViewCode.Tag = strCode
'      If Left(strGlobalID, Len("object")) = "object" Then
'         ViewCode.IsUIObject = True
         ViewCode.Text = obj.GetCode(strScript)
'      Else
'         ViewCode.Text = proj.GetCode(strScript)
'      End If
      ViewCode.Object = obj
'      ViewCode.SetCaption
'      ViewCode.Caption = ViewCode.Caption & " - " & obj.Name
      frmMain.AddMDIChild ViewCode
   End If
   If trace Then MsgBox "ViewCode " & 3
   ViewCode.Show
   If trace Then MsgBox "ViewCode " & 3.1
   ViewCode.ZOrder
   If trace Then MsgBox "ViewCode " & 3.2
   ViewCode.ShowProc strScript
   If trace Then MsgBox "ViewCode " & 3.3
   frmMain.ActiveFormChange 1
   If trace Then MsgBox "ViewCode " & 4
End Function

Function LocateProject(ByVal strGID As String) As CProject
Dim arrGID() As String
Dim proj As CProject

   arrGID = Split(strGID, "|")
   Select Case arrGID(0)
   Case "project": Set LocateProject = frmMain.Project(arrGID(1))
   Case "form": Set LocateProject = frmMain.Project(arrGID(3))
   Case "object": Set LocateProject = frmMain.Project(arrGID(5))
''   Case "menu": Set LocateProject = frmMain.Project(arrGID(3))
   Case "module": Set LocateProject = frmMain.Project(arrGID(3))
   End Select
End Function

Function LocateObject(ByVal strGID As String) As Object
Dim arrGID() As String
Dim proj As CProject
Dim obj As Object, o2 As Object, o3 As Object
Dim frm As CForm
Dim modul As CModule
Dim resource As CResourceFile

   arrGID = Split(strGID, "|")
   Select Case arrGID(0)
   Case "project" 'project|IDE Serial#
      Set LocateObject = frmMain.Project(arrGID(1))
   Case "form" 'form|Form Resource ID|project|IDE Serial #
      Set proj = frmMain.Project(arrGID(3))
      For Each frm In proj.Forms
         If frm.GlobalID = strGID Then
            Set LocateObject = frm
            Exit For
         End If
      Next
   Case "object" 'object|Object Resource ID|form|Form Resource ID|project|IDE Serial#
      Set proj = frmMain.Project(arrGID(5))
      For Each frm In proj.Forms
         Set LocateObject = LocateContained(strGID, frm.Controls)
         If Not LocateObject Is Nothing Then Exit Function
      Next
   Case "module" 'module|Module Resource ID|project|IDE Serial#
      Set proj = frmMain.Project(arrGID(3))
      For Each modul In proj.Modules
         If modul.GlobalID = strGID Then
            Set LocateObject = modul
            Exit For
         End If
      Next
   Case "resource" 'resource|Module Resource ID|project|IDE Serial#
      Set proj = frmMain.Project(arrGID(3))
      For Each resource In proj.ResourceFiles
         If resource.GlobalID = strGID Then
            Set LocateObject = resource
            Exit For
         End If
      Next
   Case "Forms", "Menus", "Bitmaps", "Modules", "Resources" '[Forms|Menus|Bitmaps|Modules][Resources]|project|IDE Serial#
''      'Same as project... for now
      Set LocateObject = frmMain.Project(arrGID(2))
      'Set LocateObject = Nothing
   End Select
End Function

Function LocateObjectByName(astrName As String) As Object
Dim frm As CForm
Dim Ctl As Object

   If Len(astrName) = 0 Then Exit Function

   For Each frm In gTarget.Forms
      If StrComp(frm.Name, astrName, vbTextCompare) = 0 Then
         Set LocateObjectByName = frm
         Exit Function
      End If
      For Each Ctl In frm.Controls
         If StrComp(Ctl.Name, astrName, vbTextCompare) = 0 Then
            Set LocateObjectByName = Ctl
            Exit Function
         End If
         If TypeName(Ctl) = "CFrame" Then
            Set LocateObjectByName = Ctl.LocateObjectByName(astrName)
            If Not LocateObjectByName Is Nothing Then Exit Function
         End If
      Next
   Next
End Function

Private Function LocateContained(astrGID As String, col As CControls) As Object
Dim obj As Object

   For Each obj In col
      If obj.GlobalID = astrGID Then
         Set LocateContained = obj
         Exit Function
      End If
      If TypeName(obj) = "CFrame" Then
         Set LocateContained = LocateContained(astrGID, obj.Controls)
         If Not LocateContained Is Nothing Then Exit Function
      End If
   Next
End Function

Public Sub frmMain_mnuRightItem_Click(Index As Integer, nClickSource As Integer, strGlobalID As String)
Dim obj As Object
Dim proj As CProject
Dim frm As frmCode
Dim fScreen As frmScreen
Dim nod As MSComctlLib.Node
Dim strRename As String

   Set obj = LocateObject(strGlobalID)
   Set proj = LocateProject(strGlobalID)
   Select Case Left(strGlobalID, InStr(1, strGlobalID, "|") - 1)
   Case "object"
      Set fScreen = frmMain.GetMDIChild(Mid(strGlobalID, InStr(Len("object|0"), strGlobalID, "|") + 1))
   Case "module"

   Case Else
      Set fScreen = frmMain.GetMDIChild(strGlobalID)
   End Select
   If Not fScreen Is Nothing Then
      fScreen.SetSelection obj
      fScreen.CurrentControl = obj
   End If

   Select Case Index
   Case 0: ViewObject strGlobalID
   Case 6 'View Code
      If Not fScreen Is Nothing Then fScreen.ClearSelection
      ViewCode strGlobalID
   Case 7 'Rename
      strRename = InputBox("", "Rename Control", obj.Name)
      strRename = Replace(strRename, " ", "")
      If Len(strRename) > 0 Then
         obj.Rename strRename
      End If
      'MMD: Fix the reselection of ActiveX controls here.
      If Not fScreen Is Nothing Then fScreen.SetSelection obj
   Case 11: If Not fScreen Is Nothing Then fScreen.Cut
   Case 12: If Not fScreen Is Nothing Then fScreen.Copy
   Case 13: If Not fScreen Is Nothing Then fScreen.Paste
   Case 14: If Not fScreen Is Nothing Then fScreen.Delete
   Case 17: ProjectAddForm proj
   Case 26: frmMain.RemoveProject proj
   Case 28: ProjectRemoveModule obj
   Case 30: ProjectRemoveResourceFile obj
   Case 32 'Properties
      If Not gbProperties Then gfProperties.DockWindow
      gfProperties.Object = obj
   End Select
End Sub

Public Function GetTypeName(ByVal sType As String) As String
   Select Case sType
   'Use standard VB controls
   Case "PictureBox":          GetTypeName = "PictureBox.PictureBox.1"
   Case "CommandButton":       GetTypeName = "VB.CommandButton"
   Case "Label":               GetTypeName = "VB.Label"
   Case "CheckBox":            GetTypeName = "VB.CheckBox"
   Case "OptionButton":        GetTypeName = "VB.OptionButton"
   Case "TextBox":             GetTypeName = "VB.TextBox"
   Case "ComboBox":            GetTypeName = "VB.ComboBox"
   Case "ListBox":             GetTypeName = "VB.ListBox"
   Case "Date":                GetTypeName = "MSComCtl2.DTPicker"
   Case "Time":                GetTypeName = "MSComCtl2.DTPicker"
   'Use ActiveX control + CActiveXCtl
   Case "TreeView":           GetTypeName = "TREEVIEWCtl.TreeViewCtl.1"
   Case "TreeViewCtl":        GetTypeName = "TREEVIEWCtl.TreeViewCtl.1"
   Case "Grid":               GetTypeName = "GridCtrl.GridCtrl.1"
   Case "GridCtrl":           GetTypeName = "GridCtrl.GridCtrl.1"
   Case "GridCtrl.GridCtrl":  GetTypeName = "GridCtrl.GridCtrl.1"
   Case "TabStrip":           GetTypeName = "CETabStrip.TabStrip.1"
   Case "Image":              GetTypeName = "Image.ImageCtl.1"
   Case "ImageCtl":           GetTypeName = "Image.ImageCtl.1"
   Case "ListView":           GetTypeName = "ListViewCtrl.ListViewCtrl.1"
   Case "ListViewCtrl":       GetTypeName = "ListViewCtrl.ListViewCtrl.1"
   Case "Comm":               GetTypeName = "CECOMM.Comm.1"
   Case "File":               GetTypeName = "FILECTL.File.1"
   Case "FileSystem":         GetTypeName = "FILECTL.FileSystem.1"
   Case "Dialog":             GetTypeName = "CEComDlg.CommonDialog.1"
   Case "CommonDialog":       GetTypeName = "CEComDlg.CommonDialog.1"
   Case "ImageList":          GetTypeName = "CEImageList.ImageListCtrl.1"
   Case "ImageListCtrl":      GetTypeName = "CEImageList.ImageListCtrl.1"
   Case "WinSock":            GetTypeName = "WinSock.WinSock.1"
   'RES
   Case "ActiveX": GetTypeName = InputBox("Enter the ClassID for the ActiveX Control", "Add ActiveX Control")
   'Don't use
   'Case "ToolBar":            GetTypeName = "MSCECommandBar.CommandBar.1"
   'Case "CommandBar":         GetTypeName = "MSCECommandBar.CommandBar.1"
   'Cross your fingers...
   Case Else:                 GetTypeName = sType
   End Select
End Function

Public Sub OpenMenuEditor(ByVal astrGlobalID As String)
   ViewObject astrGlobalID
   MenuEditor
''Dim frm As CForm
''Dim fMenuEditor As New frmMenuEditor
''Dim strOld As String
''
''   Set frm = LocateObject(strGlobalID)
''   fMenuEditor.Form = frm
''   strOld = frm.FormMenu
''   fMenuEditor.Show vbModal, frmMain
''   If StrComp(frm.FormMenu, strOld) <> 0 Then
''      LocateProject(strGlobalID).Dirty = True
''   End If
End Sub


Public Sub MenuEditor()
Dim fMenuEditor As New frmMenuEditor
Dim frm As CForm

   If frmMain.ActiveForm Is Nothing Then Exit Sub
   If TypeName(frmMain.ActiveForm) <> "frmScreen" Then Exit Sub

   Set frm = LocateObject(frmMain.ActiveForm.GlobalID)
   fMenuEditor.Form = frm
   fMenuEditor.Show vbModal, frmMain
   frmMain.ActiveForm.UpdateMenus
   gfProjectExplorer.UpdateObjectNode frm, frm.GlobalID
End Sub

Public Function TranslateColor(ByVal clr As OLE_COLOR, Optional hPal As Long = 0) As Long
   If OleTranslateColor(clr, hPal, TranslateColor) Then
      TranslateColor = -1
   End If
End Function

Public Sub UpdateFormFactor()
Dim frm As CForm
Dim fm As Form
Dim X As Integer, Y As Integer
Dim menuTop As Boolean
Dim strFF As String

   strFF = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "Pocket PC")
   gFormWidth = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", strFF & " X", "240"))
   gFormHeight = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", strFF & " Y", "320"))
   gMenuTop = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", strFF & " M", "Bottom") = "Top"
   If Not gTarget Is Nothing Then
      For Each frm In gTarget.Forms
         frm.Width = gFormWidth
         frm.Height = gFormHeight
         frm.MenuAtTop = gMenuTop
      Next
   End If
   For Each fm In frmMain.Children
      If TypeName(fm) = "frmScreen" Then
         fm.Resize
      End If
   Next
   If gbProperties Then gfProperties.Object = gTarget
End Sub

Public Sub PrintProject()
   frmMain.PrintCommon "Program", "Code", gTarget.GenerateCode
End Sub

Public Sub ManageActiveX()
   frmActiveX.Show vbModal, frmMain
   If gbToolbox Then gfToolbox.UpdateTools
End Sub
