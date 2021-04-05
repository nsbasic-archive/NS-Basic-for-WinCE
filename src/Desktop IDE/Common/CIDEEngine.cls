VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CIDEEngine"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public WithEvents Engine As MSScriptControl.ScriptControl
Attribute Engine.VB_VarHelpID = -1
Private m_Project As CProject
Private m_Output As New COutput
Public Form As CForm
Public Screen As frmScreen
Public Loading As Boolean

Private Sub Class_Initialize()
   Set Engine = New MSScriptControl.ScriptControl
End Sub

Public Function ParseProject(ByRef aProject As CProject, ByRef astrProjCode As String) As Boolean
Dim projMod As Module

   'Build the engine
   If Engine.Language <> "" Then Engine.Reset
   Engine.Language = "VBScript"
   Engine.State = Connected
   Engine.AllowUI = True
   Engine.Timeout = NoTimeout
   
   Set projMod = Engine.Modules.Add("_NSBProject")
   Engine.AddObject "Project", aProject, True
   
   If Asc(Right(astrProjCode, 1)) < 20 Then astrProjCode = Left(astrProjCode, Len(astrProjCode) - 1)
   
   On Error Resume Next
   projMod.AddCode astrProjCode
   If err.Number <> 0 Then
      MsgBox Engine.Error.Number & ": " & Engine.Error.Description
      ParseProject = False
      Exit Function
   End If
   ParseProject = True
End Function

Public Function ParseForms(ByRef aProject As CProject, ByRef astrFormCode As String) As Boolean
Dim NSBL As New CIDELanguage
Dim a As Variant
   Set m_Project = aProject

   'Build the Engine
   If Engine.Language <> "" Then Engine.Reset
   Engine.Language = "VBScript"
   Engine.State = Connected
   Engine.AllowUI = True
   Engine.Timeout = NoTimeout
   NSBL.Init Me
   Engine.AddObject "_NSBLanguage", NSBL, True
   Engine.AddObject "Output", m_Output, True

   Loading = True

   On Error Resume Next
   Engine.AddCode astrFormCode
   If err.Number <> 0 Then
      a = Split(astrFormCode, vbCr)
      MsgBox Engine.Error.Number & ": " & Engine.Error.Description & vbCrLf & "Line: " & Engine.Error.line & "   " & "Column: " & Engine.Error.Column & vbCrLf _
      & Trim(a(Engine.Error.line - 1))
      ParseForms = False
      Exit Function
   End If

   ParseForms = CreateForms
   Loading = False
End Function

Public Sub ParseSetMenu(ByRef afrmScreen As frmScreen, ByRef astrMenuCode As String)
Dim NSBL As New CIDELanguage

   'Build the Engine
   If Engine.Language <> "" Then Engine.Reset
   Engine.Language = "VBScript"
   Engine.State = Connected
   Engine.AllowUI = True
   Engine.Timeout = NoTimeout
   NSBL.Init Me, afrmScreen
   Engine.AddObject "_NSBLanguage", NSBL, True

   On Error Resume Next
   Engine.ExecuteStatement astrMenuCode
   If err.Number <> 0 Then
      MsgBox gStringTable(Engine.Error.Description)
      Exit Sub
   End If
End Sub

Private Sub Engine_Error()
Dim strError As String
Dim nError As Integer
Dim strSource As String

   nError = Engine.Error.Number
   strError = Engine.Error.Description
   strSource = Engine.Error.Source
End Sub

Private Function CreateForms() As Boolean
Dim proc As MSScriptControl.Procedure
Dim arrTokens() As String
Dim strEvent As String
Dim strForm As String
Dim frm As CForm
Dim Ctl As Object

   CreateForms = True
   For Each proc In Engine.Procedures
      arrTokens = Split(proc.Name, "_")
      strEvent = UCase(arrTokens(UBound(arrTokens)))
      If InStr(proc.Name, "_") Then strForm = Left(proc.Name, InStrRev(proc.Name, "_") - 1)
      Select Case strEvent
      Case "LOAD"
         Set Form = m_Project.AddNewForm(strForm)
         Set Me.Screen = New frmScreen
         Me.Screen.Object = Form

         'create a form and add its objects
         On Error GoTo Error_CreateForms_Load
         Engine.Run proc.Name
         On Error GoTo 0
'         Unload Me.Screen
'         Set Me.Screen = Nothing
      Case "SHOW"
         'Create a form and add its objects
         If Form Is Nothing Then
            Set Form = m_Project.AddNewForm(strForm)
            Set Me.Screen = New frmScreen
            Me.Screen.Object = Form
         End If

         m_Output.Output = Form.Output

         On Error GoTo Error_CreateForms_Load
         Me.Screen.CreatingForm = True
         Engine.Run proc.Name
         If err <> 0 Then GoTo Error_CreateForms_Load
         On Error GoTo 0
         If Not Me.Screen Is Nothing Then
            Me.Screen.CreatingForm = False
'            Unload Me.Screen
'            frmMain.AddMDIChild Screen
            Set Me.Screen = Nothing
         End If
         Set Form = Nothing
         'Make any changes to Output
''         For Each Form In m_Project.Forms
''            If Form.Name = strForm Then
''               m_Output.Output = Form.Output
''               Engine.Run proc.Name
''               Exit For
''            End If
''         Next
      End Select
   Next
      
   'Now that the Engine has been loaded with all the forms and objects,
   'it is possible to pull the values from the actual object (like a NSBPictureBox)
   'into the screen object, so the properties can be edited. This code is turned off now,
   'but can be used to fixed a longstanding bug (if you can figure out how to iterate thru the properties)
   'On Error GoTo 0
   'For Each frm In gTarget.Forms
   '   For Each Ctl In frm.Controls
   '      If Ctl.CEType = "ActiveX" Then
   '         Ctl.Tag = Engine.Eval(Ctl.Name & ".tag")
   '         If Left(Ctl.Tag, 22) = "CEType=GradientControl" Then
   '            ChangePictureBoxToGradientButton (Ctl)
   '         End If
   '      End If
   '   Next
   'Next
   
   Exit Function

Error_CreateForms_Load:
   MsgBox gStringTable(3428) & vbCr & err.Number & ": " & err.Description, vbCritical '"Error Loading Project"
   CreateForms = False
End Function

Public Sub PasteObject(ByRef afScreen As frmScreen, ByRef astrCode As String, par As Object)
Dim NSBL As New CIDELanguage

   Set Screen = afScreen

   'Build the Engine
   If Engine.Language <> "" Then Engine.Reset
   Engine.Language = "VBScript"
   Engine.State = Connected
   Engine.AllowUI = True
   Engine.Timeout = NoTimeout
   NSBL.Init Me
   Engine.AddObject "_NSBLanguage", NSBL, True
   Engine.AddObject par.Name, par, True

   NSBL.Pasting = True

   On Error Resume Next
   Engine.AddCode astrCode
   If err.Number <> 0 Then
      MsgBox Engine.Error.Number & " " & Engine.Error.Description
      Exit Sub
   End If
End Sub

