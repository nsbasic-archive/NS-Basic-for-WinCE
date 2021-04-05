Attribute VB_Name = "MNSBasic"
Option Explicit

Public Const menusOn = False 'do not show menu icons during debugging.

Global gTarget As CProject
Global gProjectDir As String 'The current project directory
Global gDemoSW As String
Global gnToolboxTool As Integer
Global gfToolbox As New frmToolbox
Global gbToolbox As Boolean
Global gfProjectExplorer As New frmProjectExplorer
Global gbProjectExplorer As Boolean
Global gfProperties As New frmProperties
Global gbProperties As Boolean
Global gbUpdatefrmScreen As Boolean
Global gProjects As New Collection
Global gbWantGrid As Boolean
Global gnGridIncr As Integer
Global gbAutoSave As Boolean      '01/10/01 MMD
Global CERem As CCERemote  'ghactivesync
Global gInstallAppDirs As String
Global gInstallFiles As String
Global gInstallCount As Integer
Global gSamplesDirectory As String
Global gResourceDirectory As String
Public Type PropertyInfo
   Name As String
   Val As String
   Type As Integer
   Data As String
End Type
Global gPropInfo As PropertyInfo
Global gInstallWindows As String
Global gInstallTo As String
Global gInstallRegisterList As String

Public Type MemberType
   Name As String
   InvokeKinds As Integer
   HelpString As String
End Type

Global GlobalPath As String
'Global installationDirectory As String

Public Const knInvalidChars As Integer = 1406 'Resource ID
Public Const kClipboardHeader = "NS Basic Clipboard"
Public Const kClipboardForm = 1
Public Const kClipboardObject = 2
Public Const kClipboardMenu = 3
Public Const kClipboardMenuBar = 4
Public Const kClipboardMenuElem = 5

Public Const kFindCase As Integer = &H1
Public Const kFindWord As Integer = &H2
Public Const kFindModule As Integer = &H10
Public Const kFindProject As Integer = &H20
Public Const kFindSelected As Integer = &H40

#If NSBasic_Desktop Then
   Public Const kProduct As String = "Desktop"
   Public Const kProductExtension As String = ".nsd"
#End If
#If NSBasic_CE Then
   Public Const kProduct As String = "CE"
   Public Const kProductExtension As String = ".nsb"
   Private Declare Function Version Lib "NSBPictB.dll" () As Integer
#End If
#If NSBasic_X Then
   Public Const kProduct As String = "X"
   Public Const kProductExtension As String = ".nsx"
#End If

Public gstrFind As String
Public gstrReplace As String
Public gbNewFind As Boolean
Public gbFindAny As Boolean
Public gbFindOne As Boolean
Public gbFindAbort As Boolean
Public garrSearchMap() As String
Public gnSearchStart As Integer
Public gnSearchLoc As Integer
Public gnFindFlags As Integer
Public gnReplaceCount As Integer
Public gSearchSel As Range

Global gbPlainText As Boolean
Global DownloadOption As String  '04/03/01 GH
Global NeedInitialization As Integer

Global g_strTrue As String
Global g_strFalse As String

Public gbWinNT2000 As Boolean
Public gDemoCodeLines As Integer
Public gOptionExplicitStripped As Boolean

Sub Main()
Dim Index As Integer
Dim userID As Long
Dim username As String
Dim itemIndex As Integer
Dim reg As String
Dim i As Integer
Dim Count As Long
Dim randNo As Long
Dim strSN As String
Dim trace As Boolean
Dim recentPath As String
trace = False
If trace Then MsgBox "sub main 1"


'   LogErrors = True
'   LogErr ""
   If trace Then MsgBox "sub main 2"

   'Registry key we want to use
   'MMD: Need to develop this to allow IDE to serve multiple platforms
   MWinReg.hKey = HKEY_CURRENT_USER
   MWinReg.SubKey = "Software\NSBasic\" & kProduct

   PlatformInit
   If trace Then MsgBox "sub main 3"
   g_strTrue = True
   g_strFalse = False

   Randomize
   
   installationDirectory = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "InstallDir1", "c:\Program Files\nsbasic\" & kProduct)
   GlobalPath = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "InstallDir1", "c:\NSBasic\" & kProduct)
   
   MakeGlobalDirectories
   If trace Then MsgBox "sub main 4"
   
   gLanguage = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "Language", "English")
   LoadStringTable
   If trace Then MsgBox "sub main 5"

   gSerialNumber = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "SerialNumber", "Unregistered Demo")
   If trace Then MsgBox "sub main 5.0.1"
   gnGridIncr = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "GridIncr", "4"))
   If trace Then MsgBox "sub main 5.0.2"
   gbWantGrid = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "WantGrid", True)
   If trace Then MsgBox "sub main 5.1"
   gbAutoSave = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "AutoSave", False)
   gbPlainText = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "PlainText", False)
   If trace Then MsgBox "sub main 5.2"
   gLabelFontName = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "IDEFontName", gStringTable(3348)) 'MS Sans Serif
   gLabelCharset = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "IDEFontCharset", gStringTable(3350))) '0
   gLabelFontSize = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "IDEFontSize", gStringTable(3349))) '01/19/00 GH
   If trace Then MsgBox "sub main 5.3"
   GetPlatformUserPrefs
   DownloadOption = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "DownloadOption", "POSE") '04/04/01 GH
   gSamplesDirectory = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "SamplesDirectory", "")
   gResourceDirectory = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ResourceDirectory", installationDirectory & "\Controls\WM")
   recentPath = gSamplesDirectory
   If trace Then MsgBox "sub main 5.4"
   #If NSBasic_CE Then
   gnLanguage = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "InstallerLanguage", "0"))
   gnPlatform = Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "Platform", "0"))
   If gnPlatform > 4 Then gnPlatform = 0 'due to bug in early version of demo
   gbCompressCab = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "CompressCab", False)
   gbDeleteWorkFiles = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "DeleteWorkFiles", True)
   gbRetainCabFiles = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "RetainCabFiles", False)
   #End If
   If trace Then MsgBox "sub main 5.5"
   If Mid(recentPath, 2, 1) = ":" Then ChDrive Left(recentPath, 2) 'ignore network drives
   ChDir recentPath
   If trace Then MsgBox "sub main 6"
   
   MNSBCodeMax_Initialize
   If trace Then MsgBox "sub main 7"

   CheckSerialNumber
'   Load frmRegister
'   frmRegister.CheckSerialNumber
'   Unload frmRegister

   NeedInitialization = 0
   If trace Then MsgBox "sub main 8"

   On Error Resume Next 'can happen if terminating
   frmMain.Show
   On Error GoTo 0
   
   If trace Then MsgBox "sub main 9"
End Sub

Public Sub CMaxPrepFindReplace(ByVal cMax As CodeMax4Ctl.CodeMax)
   cMax.ExecuteCmd cmCmdSetFindText, gstrFind
   cMax.ExecuteCmd cmCmdSetReplaceText, gstrReplace
   
   'Case sensitivity
   cMax.ExecuteCmd IIf(gnFindFlags And kFindCase, cmCmdCaseSensitiveOn, cmCmdCaseSensitiveOff)
   'Whole word
   cMax.ExecuteCmd IIf(gnFindFlags And kFindWord, cmCmdWholeWordOn, cmCmdWholeWordOff)
End Sub

Public Function CMaxFindNext(ByVal cMax As CodeMax4Ctl.CodeMax) As Boolean
Dim range1 As CodeMax4Ctl.Range
Dim range2 As CodeMax4Ctl.Range

'   CMaxPrepFindReplace cMax

   'Selected Text
   Set range1 = cMax.GetSel(True)
'   If gnFindFlags And kFindSelected Then
'      range.EndColNo = range.StartColNo
'      range.EndLineNo = range.StartLineNo
'   Else
'      range.StartColNo = range.EndColNo
'      range.StartLineNo = range.EndLineNo
'   End If
'   cMax.SetSel range, True

   cMax.ExecuteCmd cmCmdFindNext, 0
   If StrComp(cMax.SelText, gstrFind, vbTextCompare) = 0 Then
      Set range2 = cMax.GetSel(True)
      If range2.StartLineNo > range1.StartLineNo _
            Or ((range2.StartLineNo = range1.StartLineNo) And (range2.EndColNo > range1.EndColNo)) Then
         CMaxFindNext = True
      Else
         range1.StartColNo = range1.EndColNo
         range1.StartLineNo = range1.EndLineNo
         cMax.SetSel range1, True
         If gnFindFlags And kFindModule Then
            If MsgBox(gStringTable(3306), vbYesNo + vbQuestion) = vbYes Then
               '"End of search area reached, do you want to start from the beginning?
               range1.StartColNo = 0
               range1.EndColNo = 0
               range1.StartLineNo = 0
               range1.EndLineNo = 0
               cMax.SetSel range1, True
               CMaxFindNext = CMaxFindNext(cMax)
            End If
         End If
      End If
   End If
End Function

Public Function FindNext() As Boolean
Dim frm As frmCode
Dim sel As Range
Dim txt As String

   CMaxPrepFindReplace frmMain.cmaxFind
   txt = GetCode(garrSearchMap(gnSearchLoc))
   If Len(txt) = 0 Then Exit Function
   frmMain.cmaxFind.Text = txt

lblFindNextFailed:
   While frmMain.cmaxFind.TextLength = 0 And gnSearchLoc >= 0
      gnSearchLoc = (gnSearchLoc + 1) Mod (UBound(garrSearchMap) + 1)
      If gnSearchLoc = gnSearchStart Then
         gnSearchLoc = -1
      Else
         frmMain.cmaxFind.Text = GetCode(garrSearchMap(gnSearchLoc))
      End If
   Wend
   If frmMain.cmaxFind.TextLength = 0 Then Exit Function

   'Set selection to match current code window, if one is open
   Set frm = frmMain.GetMDIChild(garrSearchMap(gnSearchLoc))
   If Not frm Is Nothing Then
      'Do something tricky here to set selection
      Set sel = frm.GetSel
      If Not sel.IsEmpty Then
         If gnFindFlags And kFindSelected Then
            frmMain.cmaxFind.Text = frm.SelText
         Else
            'Move to end of selection and begin searching from there
            sel.Empty
            frmMain.cmaxFind.SetSel sel, True
         End If
      End If
   End If

   'Do the find
   gbFindOne = False
'   frmMain.cmaxFind.ExecuteCmd cmCmdFindNext, 0
   gbFindOne = CMaxFindNext(frmMain.cmaxFind)
   gbNewFind = False
   If gbFindOne Then
      FindNext = True
      Set frm = ViewCode(garrSearchMap(gnSearchLoc))
      frm.SetSel frmMain.cmaxFind.GetSel(True)
   Else
'      gnSearchLoc = (gnSearchLoc + 1) Mod (UBound(garrSearchMap) + 1)
      frmMain.cmaxFind.Text = ""
      GoTo lblFindNextFailed
   End If
End Function

Sub ShowStatus(Optional ByVal strStatus As String = "", Optional bAutoClear As Boolean = False)
   frmMain.sbStatusBar.Panels(1).Text = strStatus
   frmMain.tmrStatus.Enabled = False
   If bAutoClear Then frmMain.tmrStatus.Enabled = True
End Sub

Sub ShowCoordinates(X As Integer, Y As Integer, Optional bLocal As Boolean = False) ', Optional bAutoClear As Boolean = False)
   If X = -44 And Y = -44 Then
      frmMain.sbStatusBar.Panels(2).Text = ""
   Else
      If bLocal Then
         frmMain.sbStatusBar.Panels(2).Text = "x: " & X & "   y: " & Y
      Else
         frmMain.sbStatusBar.Panels(2).Text = "X: " & X & "   Y: " & Y
      End If
   End If
'   frmMain.tmrStatus.Enabled = False
'   If bAutoClear Then frmMain.tmrStatus.Enabled = True
End Sub

Sub ShowDimensions(W As Integer, H As Integer) ', Optional bAutoClear As Boolean = False)
   If W = -44 And H = -44 Then
      frmMain.sbStatusBar.Panels(3).Text = ""
   Else
      frmMain.sbStatusBar.Panels(3).Text = "W: " & W & "   H: " & H
   End If
'   frmMain.tmrStatus.Enabled = False
'   If bAutoClear Then frmMain.tmrStatus.Enabled = True
End Sub

Sub ShowCursor(L As Long, c As Long)
   frmMain.sbStatusBar.Panels(2).Text = "Line: " & L & "   Col: " & c
End Sub

Sub ProjectAddForm(Optional ByVal proj As CProject = Nothing)
Dim frm As CForm
'Dim fScreen As New frmScreen

   If proj Is Nothing Then Set proj = gTarget
   Set frm = proj.AddNewForm
   If gbProjectExplorer Then gfProjectExplorer.AddNewForm frm, proj
   ViewObject frm.GlobalID
'   fScreen.Object = frm
'   fScreen.Show
'   frmMain.AddMDIChild fScreen
End Sub

Sub ProjectRemoveForm(ByVal frm As CForm, Optional ByVal proj As CProject)
Dim f As Form

   'First close the Palm Screen displaying the form and any of its code windows
   Set f = frmMain.RemoveMDIChild(frm.GlobalID)
   If Not f Is Nothing Then Unload f
   Set f = frmMain.RemoveMDIChild(frm.GlobalID & "|before")
   If Not f Is Nothing Then Unload f
   Set f = frmMain.RemoveMDIChild(frm.GlobalID & "|after")
   If Not f Is Nothing Then Unload f
   Set f = frmMain.RemoveMDIChild(frm.GlobalID & "|event")
   If Not f Is Nothing Then Unload f
   Set f = frmMain.RemoveMDIChild(frm.GlobalID & "|help")
   If Not f Is Nothing Then Unload f
   If proj Is Nothing Then Set proj = gTarget
   proj.RemoveForm frm.GlobalID
   gfProjectExplorer.RemoveNode frm.GlobalID
   If gbProperties Then gfProperties.Object = proj
   proj.Dirty = True
End Sub

Sub ProjectAddModule(Optional ByVal proj As CProject = Nothing)
Dim modul As CModule
Dim strName As String
Dim strPath As String
Dim maxModules As Integer
Dim arrPaths() As String

   If proj Is Nothing Then Set proj = gTarget
   strPath = frmMain.ShowNewOpen(False, "Module", "*.bas")
   
   'User gave no module
   If strPath = "" Then
      Beep
      Exit Sub
   End If
   
   arrPaths = Split(strPath, """")
   maxModules = 0
   
   While maxModules < UBound(arrPaths) Or (maxModules = 0 And UBound(arrPaths) = 0)
      If UBound(arrPaths) > 0 Then
         strPath = arrPaths(maxModules) & arrPaths(maxModules + 1)
      End If
   
      'Suggest a name for the module, based on the file it came from
      strName = Mid(strPath, InStrRev(strPath, "\") + 1)
      strName = Left(strName, InStrRev(strName, ".") - 1)
      strName = Replace(strName, " ", "_")
      strName = Replace(strName, ".", "_")
   
      'User gave module that didn't open
      Set modul = proj.AddModule(strName, strPath)
      If modul Is Nothing Then
         MsgBox gStringTable(3461) & strPath, vbCritical  '   "Unable to open "
'         Beep
'         Exit Sub
      End If
      
      'Module is good and added, display it
      If gbProjectExplorer Then gfProjectExplorer.AddNewModule modul, proj
      If UBound(arrPaths) > 1 Then
         arrPaths(maxModules + 2) = arrPaths(maxModules)
      End If
      maxModules = maxModules + 2
   Wend
'      ViewCode modul.GlobalID
End Sub

Sub ProjectNewModule(Optional ByVal proj As CProject = Nothing)
Dim modul As CModule

   If proj Is Nothing Then Set proj = gTarget
   Set modul = proj.AddNewModule
   If gbProjectExplorer Then gfProjectExplorer.AddNewModule modul, proj
   ViewCode modul.GlobalID
End Sub

Sub ProjectRemoveModule(ByVal modul As CModule, Optional ByVal proj As CProject)
Dim f As Form

   Set f = frmMain.RemoveMDIChild(modul.GlobalID)
   If Not f Is Nothing Then Unload f
   If proj Is Nothing Then Set proj = gTarget
   proj.RemoveModule modul.GlobalID
   gfProjectExplorer.RemoveNode modul.GlobalID
   If gbProperties Then gfProperties.Object = proj
   proj.Dirty = True
End Sub

Sub ProjectAddResourceFile(Optional ByVal proj As CProject = Nothing)
Dim resource As CResourceFile
Dim strName As String
Dim strPath As String
Dim maxResources As Integer
Dim arrPaths() As String
Dim ResType As Integer
Dim register As String
Dim sharedFile As String
Dim p As Integer

   If proj Is Nothing Then Set proj = gTarget
   strPath = frmMain.ShowNewOpen(False, "Resource", "*.*")
   
   'User gave no module
   If strPath = "" Then
      Beep
      Exit Sub
   End If
      
   If InStr(LCase(gResourceDirectory), LCase(installationDirectory & "\Controls\")) Then
      p = InStrRev(strPath, "\")
      strPath = "{controls}" & Mid(strPath, p)
   Else
      strPath = GetRelativePath(CurDir, strPath)
   End If
   
   arrPaths = Split(strPath, """")
   maxResources = 0
   
   While maxResources < UBound(arrPaths) Or (maxResources = 0 And UBound(arrPaths) = 0)
      If UBound(arrPaths) > 0 Then
         strPath = arrPaths(maxResources) & arrPaths(maxResources + 1)
      End If
   
      'Suggest a name for the Resource, based on the file it came from
      strName = Mid(strPath, InStrRev(strPath, "\") + 1)
      strName = Left(strName, InStrRev(strName, ".") - 1)
      strName = Replace(strName, " ", "_")
      strName = Replace(strName, ".", "_")
   
      'determine resource type
      Select Case LCase(Right(strPath, 4))
      Case ".bmp": ResType = 0
      Case ".wav": ResType = 2
      Case Else:
         #If NSBasic_CE Then
         ResType = 3 'installer file
         #Else
         ResType = 1 'file
         #End If
      End Select
      
      'User gave resource that didn't open
      #If NSBasic_CE Then
         If Right(strPath, 4) = ".ocx" Or Right(strPath, 4) = ".dll" Then
            sharedFile = "True"
            register = "True"
         Else
            sharedFile = "False"
            register = "False"
         End If
      #Else
         sharedFile = "False"
         register = "False"
      #End If

      Set resource = proj.AddResourceFile(strName, strPath, ResType, register, sharedFile, 0)
      If resource Is Nothing Then
         MsgBox gStringTable(3461) & strPath, vbCritical  '   "Unable to open "
      End If
      
      'Resource is good and added, display it
      If gbProjectExplorer Then gfProjectExplorer.AddNewResourceFile resource, proj
      If UBound(arrPaths) > 1 Then
         arrPaths(maxResources + 2) = arrPaths(maxResources)
      End If
      maxResources = maxResources + 2
   Wend
End Sub
Sub ProjectRemoveResourceFile(ByVal resource As CResourceFile, Optional ByVal proj As CProject)
Dim f As Form

   Set f = frmMain.RemoveMDIChild(resource.GlobalID)
   If Not f Is Nothing Then Unload f
   If proj Is Nothing Then Set proj = gTarget
   proj.RemoveResourceFile resource.GlobalID
   gfProjectExplorer.RemoveNode resource.GlobalID
   If gbProperties Then gfProperties.Object = proj
   proj.Dirty = True
End Sub
Public Function quote(strVal As String) As String
   quote = Chr(34) + strVal + Chr(34)
End Function

Public Function UnQuote(strVal As String) As String
'   If Left(strVal, 1) = """" And Right(strVal, 1) = """" Then
   If Mid(strVal, 1, 1) = """" And Mid(strVal, Len(strVal)) = """" Then
      UnQuote = Mid(strVal, 2, Len(strVal) - 2)
   Else
      UnQuote = strVal
   End If
End Function

Function BoolStr(bVal As Boolean) As String
   If bVal Then BoolStr = "True" Else BoolStr = "False"
End Function

Function UnBoolStr(strVal As String) As Boolean
   If strVal = "True" Then UnBoolStr = True Else UnBoolStr = False
End Function

Public Function ValidClipboard() As Integer
Dim strClip As String

   ValidClipboard = 0
   If Clipboard.GetFormat(vbCFText) Then
      If (Left(Clipboard.GetText, Len(kClipboardHeader)) = kClipboardHeader) Then
         strClip = Mid(Clipboard.GetText, Len(kClipboardHeader & vbCrLf) + 2)
         Select Case Left(strClip, InStr(strClip, """") - 1)
         Case "vew", "Form": ValidClipboard = kClipboardForm
         Case "mnu": ValidClipboard = kClipboardMenu
         Case "menubar": ValidClipboard = kClipboardMenuBar
         Case "menuelem": ValidClipboard = kClipboardMenuElem
         Case Else: ValidClipboard = kClipboardObject
         End Select
      End If
   End If
End Function

'Sub PasteForm(ByRef strLines() As String, ByVal proj As CProject)
'Dim frm As CForm
'
'   If strLines(0) <> kClipboardHeader Then Exit Sub
'   Select Case LCase(UnQuote(strLines(1)))
'   Case "vew", "form"
'      Set frm = proj.AddNewForm
'      frm.Paste strLines
''      model.ViewCollection.Add View
''      projectDirty = True
''      RebuildProjectExplorer
''      Refresh
'      If UBound(strLines) > 1 Then PasteObject strLines, frm
'   End Select
'   gfProjectExplorer.AddNewForm frm, proj
'End Sub
'
'Function PasteObject(ByRef strLines() As String, ByRef frm As CForm) As Object
'Dim pasteObj As Object
'Dim fScreen As frmScreen
'
'   Select Case LCase(UnQuote(strLines(1)))
'   Case "bmp": Set pasteObj = New CUIBitmap
'   Case "but": Set pasteObj = New CUIButton
'   Case "chk": Set pasteObj = New CUICheckbox
'   Case "cho": Set pasteObj = New CUIPushbutton
'   Case "fld": Set pasteObj = New CUIField
'   Case "gad": Set pasteObj = New CUIGadget
'   Case "lbl": Set pasteObj = New CUILabel
'   Case "lst": Set pasteObj = New CUIList
'   Case "pop": Set pasteObj = New CUIPopup
'   Case "rpt": Set pasteObj = New CUIRepeater
'   Case "scr": Set pasteObj = New CUIScrollbar
'   Case "sel": Set pasteObj = New CUISelector
'   Case "shf": Set pasteObj = New CUIGraffitiShiftIndicator
''   Case "tbl": Set pasteObj = New cUITable
'   End Select
'   frm.AddNewObject pasteObj
'   pasteObj.Paste strLines
'   gfProjectExplorer.AddNewControl pasteObj, frm
'   Set fScreen = frmMain.GetMDIChild(frm.GlobalID)
'   If Not fScreen Is Nothing Then
'      fScreen.AddUIObject pasteObj
'   End If
''   pasteObj.drawDesignLayout
''   frm.ObjectCollection.Add pasteObj
'   If UBound(strLines) > 1 Then
'      PasteObject strLines, frm
'   Else
''      RebuildProjectExplorer
'      Set PasteObject = pasteObj
'   End If
'End Function

Public Function ImgNum(iml As ImageList, strKey As String) As Long
   ImgNum = iml.ListImages(strKey).Index - 1
End Function

Function trimWhiteSpace(ByVal s As String, Optional direction As Integer = 2) As String
   Dim ws As String

   'When trimming off whitespace...
   ' Direction = 0 for left only
   ' Direction = 1 for right only
   ' Direction = 2 for left and right
   ws = " " & vbCr & vbLf & vbTab
   If direction = 0 Or direction = 2 Then
      'Trim leading whitespace
'      Do While InStr(1, ws, Left(s, 1)) > 0 And Len(s) > 0
      Do While InStr(1, ws, Mid(s, 1, 1)) > 0 And Len(s) > 0
         s = Mid(s, 2)
      Loop
   End If
   
   If direction = 1 Or direction = 2 Then
      'Trim trailing whitespace
'      Do While InStr(1, ws, Right(s, 1)) > 0 And Len(s) > 0
      Do While InStr(1, ws, Mid(s, Len(s))) > 0 And Len(s) > 0
'         s = Left(s, Len(s) - 1)
         s = Mid(s, 1, Len(s) - 1)
      Loop
   End If
   trimWhiteSpace = s
End Function

Public Function ValidFileName(ByVal strText As String) As Boolean
Dim arrChar() As String
Dim i As Integer

   arrChar = Split(gStringTable(knInvalidChars))
   For i = 0 To UBound(arrChar)
      If InStr(strText, arrChar(i)) > 0 Then
         MsgBox gStringTable(knInvalidChars + 1), vbCritical + vbOKOnly
         ValidFileName = False
         Exit Function
      End If
   Next
   ValidFileName = True
End Function

Public Function LegalObjectName(ByVal strText As String) As Boolean
Dim arrChar() As String
Dim str1 As String
Dim i As Integer

   arrChar = Split(gStringTable(1409), "a")
   For i = 0 To UBound(arrChar)
      If InStr(strText, arrChar(i)) > 0 Then
         MsgBox gStringTable(1410) & "'" & strText & "'", vbCritical + vbOKOnly
         LegalObjectName = False
         Exit Function
      End If
   Next
'   str1 = Left(strText, 1)
   str1 = Mid(strText, 1, 1)
   If str1 >= "a" And str1 <= "z" Or str1 >= "A" And str1 <= "Z" Then
      LegalObjectName = True
   Else
      MsgBox gStringTable(1410) & "'" & strText & "'", vbCritical + vbOKOnly
      LegalObjectName = False
   End If
End Function

Public Sub InvalidProperty()
   MsgBox gStringTable(1407), vbOKOnly + vbCritical
End Sub

Public Function ActiveProject() As CProject
   If Not frmMain.ActiveForm Is Nothing Then Set ActiveProject = LocateProject(frmMain.ActiveForm.GlobalID)
   If ActiveProject Is Nothing Then Set ActiveProject = gTarget
End Function

Public Function GetCode(ByVal strMixed As String, Optional ByVal strScript As String) As String
Dim obj As Object

   If strScript = "" Then strScript = Mid(strMixed, InStrRev(strMixed, "|") + 1)
   Set obj = LocateObject(strMixed)
   If Left(strMixed, Len("object")) = "object" Then
      GetCode = obj.obj.GetCode(strScript, False)
   Else
      GetCode = obj.GetCode(strScript, False)
   End If
End Function

Public Sub PutScript(ByVal strCode As String, ByVal strGID As String)
Dim obj As Object

   Set obj = LocateObject(strGID)
   If obj Is Nothing Then Exit Sub
'   If Left(strGID, Len("object")) = "object" Then
   If Mid(strGID, 1, Len("object")) = "object" Then
      obj.obj.PutScript strCode, Mid(strGID, InStrRev(strGID, "|") + 1)
   Else
      obj.PutScript strCode, Mid(strGID, InStrRev(strGID, "|") + 1)
   End If
End Sub

Public Function CreateObjectEx(ByRef astrType As String) As Object
Dim locobj As Object
Dim strType As String
   strType = LCase(astrType)
   
   Select Case strType
   '*** These objects have their own custom wrappers
   Case "commandbutton": Set CreateObjectEx = New CCommandButton
   Case "gradientbutton": Set CreateObjectEx = New CGradientButton
   Case "label": Set CreateObjectEx = New CLabel
   Case "textbox": Set CreateObjectEx = New CTextBox
   Case "listbox": Set CreateObjectEx = New CListBox
   Case "checkbox": Set CreateObjectEx = New CCheckBox
   Case "combobox": Set CreateObjectEx = New CComboBox
   Case "optionbutton": Set CreateObjectEx = New COptionButton
   Case "date": Set CreateObjectEx = New CDTDate
   Case "time": Set CreateObjectEx = New CDTTime
   Case "picturebox": Set CreateObjectEx = New CPictureBox
   Case "output"
      Set CreateObjectEx = New CPictureBox
      CreateObjectEx.Tag = "Output"
   Case "frame": Set CreateObjectEx = New CFrame
   Case "tributton": Set CreateObjectEx = New CTriButton
   Case "hscrollbar": Set CreateObjectEx = New CHScrollBar
   Case "vscrollbar": Set CreateObjectEx = New CVScrollBar
   '*** All other objects use the CActiveXCtl wrapper
   Case Else: Set CreateObjectEx = New CActiveXCtl
   End Select
End Function
Public Function StripCode(ByRef code As String) As String
   'remove all 'comments
   'remove all REM statements
   'remove all whitespace
   Dim arrCode() As String
   Dim line As Variant
   Dim p As Long
   Dim i As Long
   Dim quote As String
   Dim X As Integer
   quote = Chr(34)
   
   arrCode = Split(code, vbCrLf)
   For i = 0 To UBound(arrCode)
      line = Trim(arrCode(i))
      If Left(line, 1) = "'" Then line = ""
      If LCase(Left(line, 4)) = "rem " Then line = ""
      For p = 1 To Len(line)
         If Mid(line, p, 1) = quote Then 'skip to next quote
            p = InStr(p + 1, line, quote)
         End If
         If p = 0 Then Exit For 'GWH 01.23.2006
         If Mid(line, p, 1) = "'" Then
            line = Left(line, p)
         End If
      Next
      arrCode(i) = line
   Next
   StripCode = Join(arrCode, vbCrLf)
   'This prevents an invalid character when loading on the device.
   X = (Len(StripCode)) Mod 16
   If X <> 0 Then StripCode = StripCode & String(16 - X, " ")

 End Function

Function EnQuote(astrText As String) As String
   EnQuote = Replace(astrText, """", """""")
End Function
Public Function getPlatform() As String
   Select Case gnPlatform
      Case 0: getPlatform = "WM"
      Case 1: getPlatform = "1824"
      Case 2: getPlatform = "2577" 'treat 2336 as 2577
      Case 3: getPlatform = "2577"
      Case 4: getPlatform = "4000"
   End Select
End Function
Public Function getPlatformName() As String
   Select Case gnPlatform
      Case 0: getPlatformName = "Windows Mobile files"
      Case 1: getPlatformName = "1824 files"
      Case 2: getPlatformName = "2336 files" 'treat 2336 as 2577
      Case 3: getPlatformName = "2577 files"
      Case 4: getPlatformName = "4000 files"
   End Select
End Function
Public Function getProcessorType() As String
   Select Case gnPlatform
      Case 0: getProcessorType = "2577"
      Case 1: getProcessorType = "1824"
      Case 2: getProcessorType = "2336"
      Case 3: getProcessorType = "2577"
      Case 4: getProcessorType = "4000"
   End Select
End Function
