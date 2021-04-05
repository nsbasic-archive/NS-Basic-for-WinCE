VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CProject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const kStrBeginGeneratedCode = "'*** Begin Generated Code ***" & vbCrLf
Private Const kStrEndGeneratedCode = "'*** End Generated Code ***" & vbCrLf
Private Const kStrBeginDemoCode = "'*** Begin Demo Code ***"
Private Const kstrEndDemoCode = "'*** End Demo Code ***"
Private Const kStrModuleCode = "'*** Module Code "

Public Name As String
Public Forms As New CForms
Public Dirty As Boolean
Public Modules As New Collection
Public ResourceFiles As New Collection
Public GradientButtons As String

Private Engine As New CIDEEngine

Private m_strGlobalID As String
Private m_strNSPPath As String            'Location of .nsp file
Private m_strMainPath As String           'Location of main .nsb file
Private m_strMakePath As String           'Location of executable .nsb file
Private m_bSaved As Boolean
Private m_bHiRes As Boolean
Private m_strFormCode As String
Private m_strUserCode As String
Private m_strDefaultForm As String
Private m_strComments As String
Private m_strCompanyName As String
Private m_strFileDescription As String
Private m_strLegalCopyright As String
Private m_strLegalTrademarks As String
Private m_strVersionMajor As String
Private m_strVersionMinor As String
Private m_strRevision As String
Private m_strTitle As String
Private m_strIcon As String
Private m_strEULA As String
Private m_strDirToInclude As String
Private m_strInstallDir As String
Private m_strReadMe As String
Private m_strProgramFiles As String
Private m_strDllFiles As String
Public NSB_FileFormat As nsbFileFormat

Public Function PropertyList() As String()
#If NSBasic_CE Then
   PropertyList = Split("Name,Path,Comments,Company Name,Dir to Include,Encrypted,EULA (.txt),File Description,HiRes Aware,Icon (.ico),Install Dir,Legal Copyright,Legal Trademarks,ReadMe (.txt),Revision,Title,Version Major,Version Minor", ",")
#End If
#If NSBasic_Desktop Then
   PropertyList = Split("Name,Path,Comments,Company Name,File Description,Icon (.ico),Legal Copyright,Legal Trademarks,Revision,Title,Version Major,Version Minor", ",")
#End If
End Function

Public Function GetProperty(ByVal astrProperty As String, ByRef pvPropVal As Variant) As EXPROPERTIESLISTLibCtl.EditTypeEnum
   Select Case astrProperty
   Case "Name": GetProperty = EXPROPERTIESLISTLibCtl.ReadOnly: pvPropVal = Name
   Case "Path": GetProperty = EXPROPERTIESLISTLibCtl.ReadOnly: pvPropVal = Path
'   Case "Output": GetProperty = Edit: pvPropVal = m_strOutputPath
   Case "Comments": GetProperty = Edit: pvPropVal = m_strComments
   Case "Company Name": GetProperty = Edit: pvPropVal = m_strCompanyName
   Case "Dir to Include":  GetProperty = Edit: pvPropVal = m_strDirToInclude
   Case "EULA (.txt)":  GetProperty = EditFile: pvPropVal = m_strEULA
   Case "File Description": GetProperty = Edit: pvPropVal = m_strFileDescription
   Case "Install Dir": GetProperty = Edit: pvPropVal = m_strInstallDir
   Case "Legal Copyright": GetProperty = Edit: pvPropVal = m_strLegalCopyright
   Case "Legal Trademarks": GetProperty = Edit: pvPropVal = m_strLegalTrademarks
   Case "Version Major": GetProperty = Edit: pvPropVal = m_strVersionMajor
   Case "Version Minor": GetProperty = Edit: pvPropVal = m_strVersionMinor
   Case "ReadMe (.txt)":  GetProperty = EditFile: pvPropVal = m_strReadMe
   Case "Revision": GetProperty = Edit: pvPropVal = m_strRevision
   Case "Title": GetProperty = Edit: pvPropVal = m_strTitle
   Case "Encrypted": GetProperty = EditBoolean: pvPropVal = Encrypted
   Case "HiRes Aware": GetProperty = EditBoolean: pvPropVal = HiRes
   Case "Icon (.ico)": GetProperty = EditFile: pvPropVal = m_strIcon
   End Select
End Function

Public Function SetProperty(astrProperty As String, ByVal vNewValue As Variant) As Variant
   If CurDir <> gProjectDir Then 'Property window can change current directory
      If Mid(gProjectDir, 2, 1) = ":" Then ChDrive Left(gProjectDir, 2) 'ignore network drives
      ChDir gProjectDir
   End If

   Select Case astrProperty
   Case "Name"
   Case "Path"
   Case "Comments": m_strComments = vNewValue
   Case "Company Name": m_strCompanyName = vNewValue
   Case "Dir to Include": m_strDirToInclude = vNewValue
   Case "EULA (.txt)":
      If LCase(Right(vNewValue, 4)) <> ".txt" Then vNewValue = m_strEULA
      m_strEULA = GetRelativePath(gProjectDir, vNewValue)
   Case "File Description": m_strFileDescription = vNewValue
   Case "Install Dir": m_strInstallDir = vNewValue
   Case "Legal Copyright": m_strLegalCopyright = vNewValue
   Case "Legal Trademarks": m_strLegalTrademarks = vNewValue
   Case "Version Major": m_strVersionMajor = vNewValue
   Case "Version Minor": m_strVersionMinor = vNewValue
   Case "ReadMe (.txt)":
      If LCase(Right(vNewValue, 4)) <> ".txt" Then vNewValue = m_strReadMe
      m_strReadMe = GetRelativePath(gProjectDir, vNewValue)
   Case "Revision": m_strRevision = vNewValue
   Case "Title": m_strTitle = vNewValue
   Case "Encrypted": Encrypted = CBool(vNewValue)
   Case "HiRes Aware": HiRes = CBool(vNewValue)
   Case "Icon (.ico)":
      If LCase(Right(vNewValue, 4)) <> ".ico" Then vNewValue = m_strIcon
      m_strIcon = GetRelativePath(gProjectDir, vNewValue)
   End Select
   GetProperty astrProperty, SetProperty
End Function

Public Function OpenMultiFile(strFileName As String) As String
Dim strCode As String
Dim projectFileName As String
Dim modul As CModule

   'OpenMultiFile = Left(strFileName, Len(strFileName) - 4) & kProductExtension
   OpenMultiFile = strFileName
   
   'Open the Project file (.nsp)
   projectFileName = Left(strFileName, Len(strFileName) - 4) & ".nsp"
   strCode = ""
   NSB_FileFormat = ReadFile(projectFileName, strCode, 0)
   If Right(LCase(strFileName), 4) = ".txt" Then strCode = "" 'if it is a .txt file, ignore any .nsp
   If NSB_FileFormat < nsbFFtext Or InStr(strCode, "Project.AddModule") = 0 Then 'No .nsp file
      strCode = strCode & vbCrLf & "Project.AddModule ""main"", """ & OpenMultiFile & """"
   End If
   
   While Right(strCode, 1) <> """"
      strCode = Left(strCode, Len(strCode) - 1)
   Wend
   If Not Engine.ParseProject(Me, strCode) Then
      MsgBox gStringTable(3462), vbCritical, app.Title '"Project File Corrupted!"
   End If
      
   For Each modul In Modules
      If modul.Name = "main" Then
         OpenMultiFile = modul.PathName
         Exit Function
      End If
   Next
End Function

Public Function OpenProject(strFileName As String) As Boolean
Dim strCode As String
Dim strMainFile As String
Dim progDir As String
Dim trace As Boolean
trace = False

   If trace Then MsgBox ("CProject.OpenProject " & 1)
   'set current directory to where the main file is
   m_strMainPath = strFileName
   If InStr(m_strMainPath, "\") Then
      progDir = Left(m_strMainPath, InStrRev(m_strMainPath, "\") - 1)
      If Len(progDir) = 2 Then progDir = progDir & "\"
   Else
      progDir = "."
   End If
   If trace Then MsgBox ("CProject.OpenProject " & 2)
   If trace Then MsgBox ("CProject.OpenProject progdir" & progDir)
   If Mid(progDir, 2, 1) = ":" Then ChDrive Left(progDir, 2) 'ignore network drives
   ChDir progDir 'set current directory to the directory the program was loaded from
   If trace Then MsgBox ("CProject.OpenProject " & 3)

   'New multi-file project code
   m_strNSPPath = Left(strFileName, Len(strFileName) - 4) & ".nsp"
   strMainFile = OpenMultiFile(strFileName)
   If trace Then MsgBox ("CProject.OpenProject " & 4)

   'Decrypt the file
   NSB_FileFormat = ReadFile(strMainFile, strCode, 0)
   If NSB_FileFormat < nsbFFtext Then Exit Function
   If trace Then MsgBox ("CProject.OpenProject " & 5)
   
   'if it's a text file, check for things that go wrong when importing from NS Basic/CE
   If Right(strMainFile, 4) = ".txt" Then strCode = cleanTXT(strCode)

   'If file is valid, set project properties
   m_bSaved = True
   Name = Mid(m_strMainPath, InStrRev(m_strMainPath, "\") + 1)
   Name = Left(Name, Len(Name) - 4)
   If trace Then MsgBox ("CProject.OpenProject " & 6)
   
   'Separate user and form code, then run form code through IDE Engine to restore project
   SeparateCode strCode
   If trace Then MsgBox ("CProject.OpenProject " & 7)
   If Not Engine.ParseForms(Me, m_strFormCode) Then
      m_strUserCode = m_strUserCode & vbCrLf & "'!!! ERRORS FOUND IN GENERATED CODE !!!" & vbCrLf & m_strFormCode
      While Forms.Count > 0
         Forms.Remove 1
      Wend
   End If
   If trace Then MsgBox ("CProject.OpenProject " & 8)

   OpenProject = True
   gProjectDir = CurDir
'Debug.Print "Project Loaded: " & strFileName
'Debug.Print Forms.Count & " Form(s)" & vbCrLf
'Debug.Print "*** USER CODE ***"
'Debug.Print m_strUserCode
'Debug.Print "*** END USER CODE ***"
End Function

Public Sub Save()
Dim strCode As String
Dim res As Integer
Dim modul As CModule
Dim resource As CResourceFile
Dim strProj As String
Dim projectName As String
Dim projectExtension As String

   strProj = ""
   projectName = Left(m_strMainPath, Len(m_strMainPath) - 4) 'projectName without an extension
   projectExtension = LCase(Right(m_strMainPath, 4))
   gTarget.GradientButtons = ""
   'Save all code (.nsb and .bas)
   For Each modul In Modules
      If modul.Name = "main" Then
         modul.SetCode Make() 'save main module
         modul.PathName = projectName & projectExtension
         If projectExtension = ".txt" Then
            NSB_FileFormat = nsbFFtext
         Else
            If NSB_FileFormat = nsbFFtext Then NSB_FileFormat = nsbFFNormal
         End If
         res = WriteFile(modul.GetCode(""), m_strMainPath, 0, NSB_FileFormat)
         
         If res <= 0 Then
            MsgBox gStringTable(3463) & " " & modul.PathName & res '"Save Error "
         End If
      Else
         modul.Save
      End If
      strProj = strProj & "Project.AddModule """ & modul.Name & """, """ & GetRelativePath(gProjectDir, modul.PathName) & """" & vbCrLf
   Next
   For Each resource In ResourceFiles
      strProj = strProj & "Project.AddResourceFile """ & resource.Name & """,""" & resource.PathName & """,""" & resource.ResType & """,""" & resource.register & """,""" & resource.sharedFile & """,""" & resource.installTo & """" & vbCrLf
   Next
   strProj = strProj & "Project.DirToInclude = " & Chr(34) & gTarget.DirToInclude & Chr(34) & vbCrLf
   strProj = strProj & "Project.EULA = " & Chr(34) & gTarget.EULA & Chr(34) & vbCrLf
   strProj = strProj & "Project.HiRes = " & HiRes & vbCrLf
   strProj = strProj & "Project.icon = " & Chr(34) & gTarget.Icon & Chr(34) & vbCrLf
   strProj = strProj & "Project.InstallDir = " & Chr(34) & gTarget.InstallDir & Chr(34) & vbCrLf
   strProj = strProj & "Project.ReadMe = " & Chr(34) & gTarget.ReadMe & Chr(34) & vbCrLf
  
   'Write out .nsp file, but not on .txt and .exe
   If projectExtension = kProductExtension Then
      strCode = GenerateAppInfo
      If Name <> "" Then strCode = strCode & "Dim AppEXEName: AppEXEName = " & """" & Name & """" & vbCrLf
      If Path <> "" Then strCode = strCode & "Dim AppPath: AppPath = " & """" & Path & """" & vbCrLf
   
      res = WriteFile(strCode & strProj, projectName & ".nsp", 0, nsbFFtext)
      If res <= 0 Then
         MsgBox gStringTable(3464) & res '"Save Project Properties Error "
      End If
   End If
End Sub

Public Function Make() As String 'return a string with the complete program, modules included
Dim demoCode As String
Dim modul As CModule
Dim p As Integer
   
   Make = getOptionExplicit & getDemoCode()
   For Each modul In Modules
      If modul.Name = "main" Then
         modul.SetCode GenerateCode()
         Make = Make & modul.GetCode("") & vbCrLf
      Else 'wrap modules in comments
         Make = Make & kStrModuleCode & "Begin:" & modul.Name & vbCrLf
         Make = Make & modul.GetCode("") & vbCrLf
         Make = Make & kStrModuleCode & "End:" & modul.Name & vbCrLf
      End If
   Next
   If gOptionExplicitStripped Then m_strUserCode = "Option Explicit" & vbCrLf & m_strUserCode 'put Option Explicit back if stripped
End Function

Public Function getDemoCode() As String
   If allowRegistration = 0 Or gSerialNumber = "Unregistered Demo" Then
      getDemoCode = getDemoCode & kStrBeginDemoCode & vbCrLf
      getDemoCode = getDemoCode & "msgbox """ & gStringTable(3443) & """,,""" & gStringTable(1120) & """"   'Program created with Demo version of NS Basic
      getDemoCode = getDemoCode & vbCrLf & "If Datediff(""d"", 0, Now) > " & DateDiff("d", 0, Now) + 30 & " then " & vbCrLf
      getDemoCode = getDemoCode & "  msgbox """ & gStringTable(3444) & """,,""" & gStringTable(1120) & """" & vbCrLf   'Program has timed out.
      getDemoCode = getDemoCode & "  bye" & vbCrLf
      getDemoCode = getDemoCode & "end if " & vbCrLf
      getDemoCode = getDemoCode & kstrEndDemoCode & vbCrLf & vbCrLf
      gDemoCodeLines = UBound(Split(getDemoCode, vbCrLf))
   Else
      getDemoCode = ""
      gDemoCodeLines = 0
   End If
End Function

Public Function getOptionExplicit()
'make sure that Option Explicit is at the beginning of the code
Dim p As Long
   p = InStr(m_strUserCode, "Option Explicit") 'Strip Option Explicit from wherever it is
   If p > 0 Then
      m_strUserCode = Left(m_strUserCode, p - 1) & Mid(m_strUserCode, p + Len("Option Explicit" & vbCrLf)) 'move Option Explicit to top of code
      getOptionExplicit = "Option Explicit" & vbCrLf
      gOptionExplicitStripped = True
   Else
      getOptionExplicit = ""
      gOptionExplicitStripped = False
   End If
End Function

Public Function Export(astrModules As String)
Dim arrModules() As String
Dim i As Integer
Dim modul As CModule
Dim strPath As String
Dim res As Integer

   arrModules = Split(astrModules, "|")
   i = 0
   For Each modul In Modules
      If modul.filename = arrModules(i) Then
         'export module
         res = WriteFile(modul.GetCode(""), modul.Path & ".txt", 0, nsbFFtext)
         If res <= 0 Then
            MsgBox gStringTable(3465) & res '"Export Project Error "
         End If
         i = i + 1
      End If
   Next
End Function
Private Sub SeparateCode(ByRef astrCode As String)
Dim arrCode() As String
Dim nspCode As String
Dim nStartGeneratedCode As Double
Dim nEndGeneratedCode As Double
Dim nStartDemo As Double
Dim nEndDemo As Double
Dim nStartModule As Double
Dim nEndModule As Double
Dim i As Double
Dim p As Double
   
   nStartGeneratedCode = -1
   nEndGeneratedCode = -1
   nStartDemo = -1
   nEndDemo = -1
   nStartModule = -1
   nEndModule = -1

   arrCode = Split(astrCode, vbCrLf)
   
   'strip out demo code
   For i = 0 To UBound(arrCode)
      If nStartDemo < 0 Then
         If Trim(arrCode(i)) = kStrBeginDemoCode Then  'Found demo code start
            nStartDemo = i
         End If
      Else
         If Trim(arrCode(i)) = kstrEndDemoCode Then    'Found demo code end
            nEndDemo = i
            Exit For
         End If
      End If
   Next
   If nStartDemo <> -1 Then
      astrCode = ""
      For i = 0 To UBound(arrCode)
         If i < nStartDemo Or i > nEndDemo Then
            astrCode = astrCode & arrCode(i) & vbCrLf
         End If
      Next
      arrCode = Split(astrCode, vbCrLf)
   End If

   'strip out code modules
   nStartModule = 0
   If InStr(astrCode, kStrModuleCode) Then 'only do this if there actually are modules
      astrCode = ""
      For i = 0 To UBound(arrCode)
         If Left(Trim(arrCode(i)), 17) = kStrModuleCode Then
            If InStr(arrCode(i), "Begin:") Then 'start a module
               If nStartModule = 1 Then MsgBox "Code Module Begin within code module -- ignored."
               nStartModule = 1
            Else 'it must be End module message
               'test if end while not in module
               If nStartModule = 0 Then MsgBox "Code Module End outside code module -- ignored."
               nStartModule = 0
            End If
         Else
            If nStartModule = 0 Then astrCode = astrCode & arrCode(i) & vbCrLf 'only add if not in module
         End If
      Next
      arrCode = Split(astrCode, vbCrLf)
   End If

   'Gather Generated Code
   For i = 0 To UBound(arrCode)
      If nStartGeneratedCode < 0 Then
         If Trim(arrCode(i)) & vbCrLf = kStrBeginGeneratedCode Then 'Found generated code start
            nStartGeneratedCode = i
         End If
      Else
         If Trim(arrCode(i)) & vbCrLf = kStrEndGeneratedCode Then   'Found generated code end
            nEndGeneratedCode = i
            Exit For
         End If
      End If
      
      #If NSBasic_Desktop Then
      If nStartGeneratedCode = 1 And Left(arrCode(i), 16) = "'Project.Icon = " Then
         Icon = Trim(Mid(arrCode(i), 16))
      End If
      #End If
   Next

   ReadFile m_strNSPPath, nspCode, 0
   If nspCode = "" Then nspCode = GetAppInfo(arrCode, nStartGeneratedCode, nEndGeneratedCode) 'Get application info (if any)
   ParseNSPcode nspCode
   
   'Combine the Forms code and find default form, if one exists
   If nStartGeneratedCode >= 0 And nEndGeneratedCode > nStartGeneratedCode Then
      For i = nStartGeneratedCode To nEndGeneratedCode
         If Right(arrCode(i), Len("'Default Form")) = "'Default Form" Then
            m_strDefaultForm = Left(arrCode(i), InStr(arrCode(i), "_Show") - 1)
            arrCode(i) = "'" & arrCode(i)
         End If
         m_strFormCode = m_strFormCode & arrCode(i) & vbCrLf
      Next
      m_strFormCode = Replace(m_strFormCode, " NSExecute ", " Execute ")
   Else
      'This case handles a program with no form designer component
      m_strUserCode = astrCode
      If nStartGeneratedCode <> -1 Or nEndGeneratedCode <> -1 Then
         MsgBox gStringTable(3363) '"Form designer code has been modified by the user."
      End If
      Exit Sub
   End If

   'Let's gather the remaining user-edited code
   For i = 0 To nStartGeneratedCode - 1
      If InStr(arrCode(i), "'<del>") = 0 Then _
         m_strUserCode = m_strUserCode & arrCode(i) & vbCrLf 'get rid of inline generated code
   Next
   If Right(m_strUserCode, 2) = vbCrLf Then m_strUserCode = Left(m_strUserCode, Len(m_strUserCode) - 2)
   
   For i = nEndGeneratedCode + 1 To UBound(arrCode)
      If i = UBound(arrCode) And arrCode(i) = "" Then
         'deletes trailing blank line
      Else
         m_strUserCode = m_strUserCode & arrCode(i) & vbCrLf
      End If
   Next
   If m_strUserCode = vbCrLf Then m_strUserCode = ""
End Sub

'Get the first form, or the default form
Public Function GetDefaultForm() As CForm
Dim frm As CForm

   If m_strDefaultForm <> "" Then
      On Error Resume Next
      Set GetDefaultForm = Forms(m_strDefaultForm)
   Else
      If Forms.Count > 0 Then
         Set GetDefaultForm = Forms(1)
      End If
   End If
End Function

'strCode reserved for later use.
Public Function GetCode(ByVal strCode As String, Optional bNull As Boolean) As String
   GetCode = m_strUserCode
End Function

'strCode reserved for later use.
Public Sub PutScript(ByVal strText As String, ByVal strCode As String)
   m_strUserCode = strText
End Sub

Public Function GenerateCode() As String
Dim frm As CForm
Dim strCode As String
Dim X As Integer
   
   'Locate default form, and add 'Show' call
   For Each frm In Forms
      If frm.GlobalID = m_strDefaultForm Then
         strCode = strCode & frm.Name & "_Show 'Default Form" & vbCrLf & vbCrLf
      End If
   Next

   'Add the code from each form
   For Each frm In Forms
      strCode = strCode & frm.GenerateCode() & vbCrLf
   Next

   'Add generated code footer
   'If Len(Trim(strCode)) > 0 Then
   '   GenerateCode = kStrBeginGeneratedCode & vbCrLf & GenerateAppInfo & vbCrLf & strCode & CallIfExistsCode & kStrEndGeneratedCode
   '   GenerateCode = m_strUserCode & vbCrLf & GenerateCode
   'Else
   '   GenerateCode = m_strUserCode
   'End If
   
   'Add generated code footer
   GenerateCode = m_strUserCode
   
   'trim any extra vbCRLF's from the end of the string
   Do While Right(GenerateCode, 2) = vbCrLf
      GenerateCode = Left(GenerateCode, Len(GenerateCode) - 2)
   Loop
   
   If Len(Trim(strCode)) > 0 Then
      If Right(GenerateCode, 2) <> vbCrLf Then GenerateCode = GenerateCode & vbCrLf
      GenerateCode = GenerateCode & kStrBeginGeneratedCode & vbCrLf & GenerateAppInfo & vbCrLf & strCode & CallIfExistsCode & kStrEndGeneratedCode
   End If
   
End Function

Public Function AddNewModule(Optional ByVal astrName As String) As CModule
Dim tempMod As CModule
Dim i As Integer
Dim trace As Boolean
trace = False

   If trace Then MsgBox "AddNewModule " & 1
   'Find a proper name of the form 'Module%d'
   i = 1
   Do While astrName = ""
      astrName = "Module" & i
      For Each tempMod In Modules
         If StrComp(tempMod.Name, astrName, vbTextCompare) = 0 Then
            astrName = ""
         End If
      Next
      i = i + 1
   Loop
   If trace Then MsgBox "AddNewModule " & 2
   
   'Create, add, and mark project dirrrty
   Set AddNewModule = AddModule(astrName, "")
   Dirty = True
End Function

Public Function AddNewForm(Optional ByVal astrName As String) As CForm
Dim frm As New CForm
Dim tempForm As CForm
Dim i As Integer
Dim strName As String

   'Add 1 here, so first form is 1, second form is 2 ....
   frm.GlobalID = Join(Array("form", Forms.Count + 1, GlobalID), "|")

   i = 1
   Do While astrName = ""
      astrName = "Form" & i
      For Each tempForm In Forms
         If StrComp(tempForm.Name, astrName, vbTextCompare) = 0 Then
            astrName = ""
         End If
      Next
      i = i + 1
   Loop
   frm.Name = astrName

   'Set up default form
   If Forms.Count = 0 And m_strDefaultForm = "" Then
      m_strDefaultForm = frm.GlobalID
   Else
      If astrName = m_strDefaultForm Then m_strDefaultForm = frm.GlobalID
   End If

   Forms.Add frm, frm.GlobalID
   frm.Project = Me
   Set AddNewForm = frm
   Dirty = True
End Function

Public Function GenerateAppInfo() As String
Dim s As String

   s = "Dim AppBuildStamp: AppBuildStamp=" & Chr(34) & Now() & Chr(34) & vbCrLf
   If Comments <> "" Then s = s & "Dim AppComments: AppComments = """ & Comments & """" & vbCrLf
   If CompanyName <> "" Then s = s & "Dim AppCompanyName: AppCompanyName = """ & CompanyName & """" & vbCrLf
   If FileDescription <> "" Then s = s & "Dim AppFileDescription: AppFileDescription = """ & FileDescription & """" & vbCrLf
   If LegalCopyright <> "" Then s = s & "Dim AppLegalCopyright: AppLegalCopyright = """ & LegalCopyright & """" & vbCrLf
   If LegalTrademarks <> "" Then s = s & "Dim AppLegalTrademarks: AppLegalTrademarks = """ & LegalTrademarks & """" & vbCrLf
   If VersionMajor <> "" Then s = s & "Dim AppMajor: AppMajor = """ & VersionMajor & """" & vbCrLf
   If VersionMinor <> "" Then s = s & "Dim AppMinor: AppMinor = """ & VersionMinor & """" & vbCrLf
   If Revision <> "" Then s = s & "Dim AppRevision: AppRevision = """ & Revision & """" & vbCrLf
   If Title <> "" Then
      #If NSBasic_Desktop Then
      s = s & "Dim AppTitle: "
      #End If
      s = s & "AppTitle = """ & Title & """" & vbCrLf
   End If
'   If Icon <> "" Then s = s & "Dim AppIcon: AppIcon = """ & Icon & """" & vbCrLf
'   If Name <> "" Then s = s & "Dim AppEXEName: AppEXEName = """ & Name & """" & vbCrLf
'   If Path <> "" Then s = s & "Dim AppPath: AppPath = """ & Path & """" & vbCrLf

   GenerateAppInfo = s
End Function

Function GetAppInfo(arrCode, nStartGeneratedCode As Double, nEndGeneratedCode) As String
'this code is needed when loading 6.0.3 programs and earlier for the first time
'so the data for the .NSP file can be loaded.
Dim i As Double
Dim atoms() As String
Dim Value As String
Dim p As Integer

   If nStartGeneratedCode < 1 Then Exit Function
   If nEndGeneratedCode < 1 Then Exit Function
   If Left(arrCode(nStartGeneratedCode + 2), 7) <> "Dim App" And Left(arrCode(nStartGeneratedCode + 2), 7) <> "AppTitle = " Then Exit Function
   i = nStartGeneratedCode + 2
   Do While arrCode(i) <> ""
      Value = Value & arrCode(i) & vbCrLf
      i = i + 1
   Loop
   GetAppInfo = Value
End Function

Sub ParseNSPcode(code As String)
Dim i As Double
Dim arrCode() As String
Dim atoms() As String
Dim Value As String
Dim p As Integer

   If code = "" Then Exit Sub
   arrCode = Split(code, vbCrLf)

   i = 0
   Do While arrCode(i) <> ""
      atoms = Split(arrCode(i))
      If atoms(0) = "AppTitle" Then atoms(1) = atoms(0) 'AppTitle does not always have a DIM statement
      p = InStr(arrCode(i), "=")
      Value = Mid(arrCode(i), p + 2)
      If Left(Value, 1) = Chr(34) Then Value = Mid(Value, 2) 'get rid of quotes around value
      If Right(Value, 1) = Chr(34) Then Value = Mid(Value, 1, Len(Value) - 1) 'get rid of quotes around value
      
      Select Case atoms(1)
         Case "AppComments:":  Comments = Value
         Case "AppCompanyName:":  CompanyName = Value
         Case "AppFileDescription:":  FileDescription = Value
         Case "AppLegalCopyright:":  LegalCopyright = Value
         Case "AppLegalTrademarks:":  LegalTrademarks = Value
         Case "AppMajor:":  VersionMajor = Value
         Case "AppMinor:":  VersionMinor = Value
         Case "AppRevision:":  Revision = Value
         Case "AppTitle":  Title = Value
         Case "AppIcon:":  Icon = Value
         Case "HiRes:":  HiRes = Value
         'Case "AppPath:":  Path = Value
      End Select
      i = i + 1
   Loop
End Sub

Public Sub RemoveForm(strGlobalID As String)
   Forms.Remove strGlobalID
End Sub

Public Sub RemoveModule(strGlobalID As String)
Dim i As Integer
Dim modul As CModule
   Modules.Remove strGlobalID
End Sub
Public Sub RemoveResourceFile(strGlobalID As String)
Dim i As Integer
Dim resource As CResourceFile
   ResourceFiles.Remove strGlobalID
End Sub

Public Function ValidObjectName(ByVal astrName As String, Optional ByVal astrGID As String = "") As String
Dim modul As CModule
Dim frm As CForm
Dim Ctl As Object
Dim firstC As Integer

   If Len(astrName) = 0 Then Exit Function
   If StrComp(astrName, "main", vbTextCompare) = 0 Then
      ValidObjectName = gStringTable(3498) 'Main' is a reserved name
      Exit Function
   End If
   
   firstC = Asc(UCase(astrName))
   If Not (firstC >= Asc("A") And firstC <= Asc("Z")) Then
      ValidObjectName = gStringTable(3499) 'First character must be a letter.
      Exit Function
   End If

   If astrGID <> "" Then
      'Check module v. module
      Set Ctl = LocateObject(astrGID)
      If TypeName(Ctl) = "CModule" Then
         For Each modul In Modules
            If modul.GlobalID <> astrGID And modul.Name = astrName Then
               ValidObjectName = gStringTable(3500) 'Name already in use.
               Exit Function
            End If
         Next
         ValidObjectName = ""
         Exit Function
      End If
   End If
      
   'Check objects
   For Each frm In Forms
      If StrComp(frm.Name, astrName, vbTextCompare) = 0 Then
         If Len(astrGID) > 0 Then
            If frm.GlobalID <> astrGID Then
               ValidObjectName = gStringTable(3500)  'Name already in use.
               Exit Function
            End If
         Else
            MsgBox gStringTable(3500) 'Name already in use.
            Exit Function
         End If
      End If
      For Each Ctl In frm.Controls
         If StrComp(Ctl.Name, astrName, vbTextCompare) = 0 Then
            If Len(astrGID) > 0 Then
               If Ctl.GlobalID <> astrGID Then
                  ValidObjectName = gStringTable(3500)  'Name already in use.
                  Exit Function
               End If
            Else
               ValidObjectName = gStringTable(3500)  'Name already in use.
               Exit Function
            End If
         End If
         If TypeName(Ctl) = "CFrame" Then
            If Not Ctl.ValidObjectName(astrName, astrGID) Then
               ValidObjectName = gStringTable(3500)  'Name already in use.
               Exit Function
            End If
         End If
      Next
   Next
   
   ValidObjectName = ""
End Function

Private Sub Class_Initialize()
   m_bSaved = False
   NSB_FileFormat = nsbFFNormal
End Sub

Public Property Get GlobalID() As String
Attribute GlobalID.VB_UserMemId = 0
Attribute GlobalID.VB_MemberFlags = "200"
   GlobalID = m_strGlobalID
End Property
Public Property Let GlobalID(strID As String)
   m_strGlobalID = "project|" & strID
End Property

Public Property Get Saved() As Boolean
   Saved = m_bSaved
End Property
Public Property Let Saved(bNewValue As Boolean)
   m_bSaved = bNewValue
End Property

'Read-Only version of the property for display in the properties window
Public Property Get Path() As String
   Path = m_strMainPath
End Property

Public Property Get PathName() As String
   PathName = m_strMainPath
End Property
Public Property Let PathName(strNewValue As String)
   m_strMainPath = strNewValue
End Property

Public Property Get MakePath() As String
   MakePath = m_strMakePath
End Property
Public Property Let MakePath(strNewValue As String)
   m_strMakePath = strNewValue
End Property

Public Property Get DefaultForm() As String
   DefaultForm = m_strDefaultForm
End Property
Public Property Let DefaultForm(vNewValue As String)
   m_strDefaultForm = vNewValue
End Property

Public Property Get Encrypted() As Boolean
   Encrypted = (NSB_FileFormat = nsbFFEncrypted)
End Property
Public Property Let Encrypted(vNewValue As Boolean)
   If NSB_FileFormat = nsbFFtext Then Exit Property
   NSB_FileFormat = IIf(vNewValue, nsbFFEncrypted, nsbFFNormal)
End Property

Public Property Get HiRes() As Boolean
   HiRes = m_bHiRes
End Property
Public Property Let HiRes(vNewValue As Boolean)
   m_bHiRes = vNewValue
End Property

Public Property Get Comments() As String
   Comments = m_strComments
End Property
Public Property Let Comments(vNewValue As String)
   m_strComments = vNewValue
End Property

Public Property Get CompanyName() As String
   CompanyName = m_strCompanyName
End Property
Public Property Let CompanyName(vNewValue As String)
   m_strCompanyName = vNewValue
End Property

Public Property Get FileDescription() As String
   FileDescription = m_strFileDescription
End Property
Public Property Let FileDescription(vNewValue As String)
   m_strFileDescription = vNewValue
End Property

Public Property Get LegalCopyright() As String
   LegalCopyright = m_strLegalCopyright
End Property
Public Property Let LegalCopyright(vNewValue As String)
   m_strLegalCopyright = vNewValue
End Property

Public Property Get LegalTrademarks() As String
   LegalTrademarks = m_strLegalTrademarks
End Property
Public Property Let LegalTrademarks(vNewValue As String)
   m_strLegalTrademarks = vNewValue
End Property

Public Property Get VersionMajor() As String
   VersionMajor = m_strVersionMajor
End Property
Public Property Let VersionMajor(vNewValue As String)
   m_strVersionMajor = vNewValue
End Property

Public Property Get VersionMinor() As String
   VersionMinor = m_strVersionMinor
End Property
Public Property Let VersionMinor(vNewValue As String)
   m_strVersionMinor = vNewValue
End Property

Public Property Get Revision() As String
   Revision = m_strRevision
End Property
Public Property Let Revision(vNewValue As String)
   m_strRevision = vNewValue
End Property

Public Property Get Title() As String
   Title = m_strTitle
End Property
Public Property Let Title(vNewValue As String)
   m_strTitle = vNewValue
End Property

Public Property Get Icon() As String
   Icon = m_strIcon
End Property
Public Property Let Icon(vNewValue As String)
   If LCase(Right(vNewValue, 4)) <> ".ico" Then Exit Property
   m_strIcon = vNewValue
End Property

Public Property Get DirToInclude() As String
   DirToInclude = m_strDirToInclude
End Property
Public Property Let DirToInclude(vNewValue As String)
   m_strDirToInclude = vNewValue
End Property

Public Property Get EULA() As String
   EULA = m_strEULA
End Property
Public Property Let EULA(vNewValue As String)
   If LCase(Right(vNewValue, 4)) <> ".txt" Then Exit Property
   m_strEULA = vNewValue
End Property

Public Property Get InstallDir() As String
   InstallDir = m_strInstallDir
End Property
Public Property Let InstallDir(vNewValue As String)
   m_strInstallDir = vNewValue
End Property

Public Property Get ReadMe() As String
   ReadMe = m_strReadMe
End Property
Public Property Let ReadMe(vNewValue As String)
   If LCase(Right(vNewValue, 4)) <> ".txt" Then Exit Property
   m_strReadMe = vNewValue
End Property

Public Function AddModule(astrName As String, astrPath As String) As CModule
Dim modul As New CModule
Dim modu As CModule
Dim i As Integer

   i = Modules.Count

   If modul.OpenModule(astrName, astrPath) Then
GlobalIDexists:
      i = i + 1
      modul.GlobalID = Join(Array("module", i, GlobalID), "|")
      'does it exist already?
      If gTarget Is Nothing Then
      Else
         For Each modu In gTarget.Modules
            If modu.GlobalID = modul.GlobalID Then GoTo GlobalIDexists
         Next
      End If
      Modules.Add modul, modul.GlobalID
      On Error GoTo 0
      
      Set AddModule = modul
   End If
End Function
Public Function AddResourceFile(astrName As String, astrPath As String, ResType As Integer, astrRegister As String, astrSharedFile As String, installTo As Integer) As CResourceFile
Dim resource As New CResourceFile
Dim res As CResourceFile
Dim i As Integer
Dim p As Integer

   i = Modules.Count

GlobalIDexists:
   i = i + 1
   resource.GlobalID = Join(Array("resource", i, GlobalID), "|")
   'does it exist already?
   If gTarget Is Nothing Then
   Else
      For Each res In gTarget.ResourceFiles
         If res.GlobalID = resource.GlobalID Then GoTo GlobalIDexists
      Next
   End If
   ResourceFiles.Add resource, resource.GlobalID
   
   'This code is needed for samples that have not been updated to pathname with {controls]
   If InStr(LCase(astrPath), LCase(Mid(installationDirectory, 3) & "\controls\")) Then
      p = InStrRev(astrPath, "\")
      astrPath = "{controls}" & Mid(astrPath, p)
   End If
   
   resource.Name = astrName
   resource.PathName = astrPath
   resource.ResType = ResType
   resource.register = CBool(astrRegister)
   resource.sharedFile = CBool(astrSharedFile)
   resource.installTo = installTo
   
   Set AddResourceFile = resource
End Function

Public Function BuildMap() As String
Dim modul As CModule

   For Each modul In Modules
      If BuildMap <> "" Then BuildMap = BuildMap & ">"
      If modul.Name = "main" Then
         BuildMap = BuildMap & GlobalID
      Else
         BuildMap = BuildMap & modul.GlobalID
      End If
   Next
End Function

Private Function CallIfExistsCode() As String
Dim s As String
s = vbCrLf & "Sub CallIfExists(theSub)" & vbCrLf
s = s & "Dim s" & vbCrLf
s = s & "   If ScriptEngineMajorVersion < 5 Then" & vbCrLf
s = s & "      Execute(""On Error Resume Next:""&theSub) 'attempt to execute it" & vbCrLf
s = s & "   Else" & vbCrLf
s = s & "      On Error Resume Next" & vbCrLf
s = s & "      Set s = GetRef(theSub)" & vbCrLf
s = s & "      If err.Number <> 0 Then Exit Sub 'it does not exist" & vbCrLf
s = s & "      On Error GoTo 0" & vbCrLf
s = s & "      Execute (theSub) 'execute it" & vbCrLf
s = s & "   End If" & vbCrLf
CallIfExistsCode = s & "End Sub" & vbCrLf & vbCrLf
End Function

Private Function cleanTXT(s As String) As String
Dim p As Long
Dim p1 As Long
'Look for things that can go wrong when importing text

   '1. NS Basic/CE has a line like
   '   Form1.Move 0, 0, Form1_Form.Width * 15, Form1_Form.Height * 15
   'which kills the desktop.
   p = InStr(s, kStrBeginGeneratedCode)
   If p Then p = InStr(p + 1, s, ".Move 0, 0, ")
   Do While p > 0
      Mid(s, p - 5) = "'" 'comment it out
      p = InStr(p + 1, s, ".Move 0, 0, ")
   Loop
   
   cleanTXT = s
End Function
   
