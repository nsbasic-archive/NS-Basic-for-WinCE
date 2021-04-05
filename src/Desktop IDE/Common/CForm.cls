VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

'local variable(s) to hold property value(s)
Private m_strName As String 'local copy
'Private m_ScreenObject As CControl 'local copy
Private m_ScreenDefault As Boolean 'local copy
Private m_Output As New CPictureBox
Private m_ScreenMenu As String
Private m_GlobalID As String
Private m_Project As CProject
Private m_strCaption As String
Private m_strPicture As String
Private m_strTag As String
Private m_nLeft As Integer
Private m_nTop As Integer
Private m_nWidth As Integer
Private m_nHeight As Integer
Public MenuAtTop As Boolean
Private m_Screen As frmScreen
Private m_nChildren As Integer
Private m_bVisible As Boolean

Public Controls As New CControls

Public Function PropertyList() As String()
#If NSBasic_CE Then
   PropertyList = m_Output.PropertyList
#End If
#If NSBasic_Desktop Then
   PropertyList = Split("Name,BackColor,BorderStyle,Caption,DrawStyle,DrawWidth,Enabled,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontTransparent,FontUnderline,FontWeight,ForeColor,Height,Left,Picture,Tag,Text,Timer,Top,Width", ",")
#End If
End Function

Public Function GetProperty(ByVal astrProperty As String, ByRef pvPropVal As Variant) As EXPROPERTIESLISTLibCtl.EditTypeEnum
   Select Case astrProperty
   Case "Name": GetProperty = Edit: pvPropVal = m_strName
   Case "BorderStyle": GetProperty = EXPROPERTIESLISTLibCtl.ReadOnly: pvPropVal = 0
   Case "Caption": GetProperty = Edit: pvPropVal = m_strCaption
   'Case "Picture": GetProperty = Edit: pvPropVal = m_strPicture
   Case "Left": GetProperty = EXPROPERTIESLISTLibCtl.ReadOnly: pvPropVal = m_nLeft
   'Case "Tag": GetProperty = Edit: pvPropVal = ""
   Case "Top": GetProperty = EXPROPERTIESLISTLibCtl.ReadOnly: pvPropVal = m_nTop
   Case "Width": GetProperty = Edit: pvPropVal = m_nWidth
   Case "Height": GetProperty = Edit: pvPropVal = m_nHeight
   Case Else: GetProperty = m_Output.GetProperty(astrProperty, pvPropVal)
   End Select
End Function

Public Function SetProperty(astrProperty As String, ByVal vNewValue As Variant) As Variant
   Select Case astrProperty
   Case "Name": vNewValue = m_Output.SetProperty(astrProperty, vNewValue): m_strName = vNewValue
   Case "Caption": m_strCaption = vNewValue
   Case "Picture": vNewValue = m_Output.SetProperty(astrProperty, vNewValue): m_strPicture = vNewValue
   Case "Width": vNewValue = m_Output.SetProperty(astrProperty, CInt(vNewValue)): m_nWidth = vNewValue
   Case "Height": vNewValue = m_Output.SetProperty(astrProperty, CInt(vNewValue)): m_nHeight = vNewValue
   Case Else: vNewValue = m_Output.SetProperty(astrProperty, vNewValue)
   End Select
   GetProperty astrProperty, SetProperty
End Function

Public Sub Move(ByVal X As Long, ByVal Y As Long, ByVal W As Long, ByVal H As Long)
'MMD: Add form resize code here....
   If H < 55 Then H = 55
   With Me
      .Width = W
      .Height = H
   End With
   m_Screen.Resize
End Sub

Public Sub AddObject(Ctl As Object)
   Controls.Add Ctl
'   Ctl.GlobalID = Join(Array("object", Controls.Count, GlobalID), "|")
End Sub

Public Function GetGlobalID() As String
   m_nChildren = m_nChildren + 1
'   GetGlobalID = Join(Array("object", Controls.Count + 1, GlobalID), "|")
   GetGlobalID = Join(Array("object", m_nChildren, GlobalID), "|")
End Function

Private Sub Class_Initialize()
   m_nChildren = 0
   m_strCaption = ""
   m_strPicture = ""
   m_nLeft = 0
   m_nTop = 0
   Width = gFormWidth
   Height = gFormHeight
   With Me
      .MenuAtTop = gMenuTop
'MMD
'      m_Output.SetForm m_Screen
'      m_Output.AddObject "PictureBox", "Output", m_nLeft, m_nTop, m_nWidth, m_nHeight
'      m_Output.BorderStyle = 0
'      m_Output.ScaleMode = 3
   End With
'   m_Output.Name = "Output"
'   m_Output.ObjectType = "Form"
End Sub

Public Function RemoveObject(astrName As String) As Boolean
Dim i As Integer

   RemoveObject = True
   For i = 1 To Controls.Count
      If Controls(i).Name = astrName Then
         Controls.Remove i
         Exit Function
      End If
      If TypeName(Controls(i)) = "CFrame" Then
         If Controls(i).RemoveControl(astrName) Then Exit Function
      End If
   Next
   RemoveObject = False
End Function

Public Function GenerateCode() As String
Dim resBytes() As Byte
Dim strControl As String
Dim Ctl As Object
'Dim i As Integer
Dim strCode As String
Dim resNo As Integer
Dim frameName As String
Dim strBuf As String

   'Get form code template, with or without menu
   #If NSBasic_CE Then
      resNo = 201
      frameName = "***NSBasicForm***_Form"
   #End If
   #If NSBasic_Desktop Then
      resNo = 301
      frameName = "***NSBasicForm***"
   #End If
   If Len(FormMenu) > 0 Then resNo = resNo + 1
   resBytes = LoadResData(resNo, "CODETEMPLATE")
   strCode = StrConv(resBytes, vbUnicode)

   'Runtime version inserts null here, lets kill it.
   While Asc(Right(strCode, 1)) = 0
      strCode = Left(strCode, Len(strCode) - 1)
   Wend

   'Add properties that modify Output object
#If NSBasic_CE Then
   strBuf = m_Output.GenerateCode("      ***NSBasicForm***")
#End If
#If NSBasic_Desktop Then
   strBuf = m_Output.GenerateCode("      ***NSBasicForm***")
   strBuf = strBuf & "      " & m_strName & ".Caption = """ & m_strCaption & """" & vbCrLf
#End If
#If NSBasic_CE Then
   'If m_Output.Tag <> "" Then strBuf = "      " & m_strName & "_Form.Tag = """ & m_Output.Tag & """" & vbCrLf
#End If
   strCode = Replace(strCode, "***NSBasicForm.Output***", strBuf)

   'Put form name into code
   strCode = Replace(strCode, "***NSBasicForm***", m_strName)
   strCode = Replace(strCode, "***NSBasicFormColor***", m_Output.BackColor) '01/31/2005 GH
   
   'Add stuff specific to the form controls, form Form_Load procedure
   For Each Ctl In Controls
      strControl = strControl & Ctl.GenerateCode(frameName) & "      '--------" & vbCrLf
   Next
   strControl = Replace(strControl, "***NSBasicForm***", m_strName)
   strCode = Replace(strCode, "***NSBasicForm.Load***", strControl)

   'Put menu code in, if we have one
   If Len(FormMenu) Then
      strCode = Replace(strCode, "***NSBasicForm.ShowMenu***", FormMenu)
   End If
   GenerateCode = strCode
'Debug.Print GenerateCode
End Function

Public Function Copy() As String
Dim strTemp As String

   strTemp = m_strName
   Copy = """Form""" & m_strName & vbCrLf
   m_strName = "NSBClipboard"
   Copy = Copy & GenerateCode
   m_strName = strTemp
End Function

Public Sub SetOutput(aForm As frmScreen)
   Set m_Screen = aForm
'   m_Output.Init "Output", aForm, aForm.pbScreen
   m_Output.GlobalID = GlobalID
   m_Output.SetControl aForm.pbScreen
   m_Output.Tag = "Output"
End Sub

Public Sub Unload()
Dim obj As Object

   'On Error Resume Next
   For Each obj In Controls
      obj.Unload
      'Controls.Remove 1  'GWH
   Next
   m_Output.Unload
   Set m_Screen = Nothing
End Sub

Public Property Get Name() As String
   Name = m_strName
End Property
Public Property Let Name(ByVal vData As String)
   m_Output.Name = vData
   m_strName = m_Output.Name
   If m_strCaption = "" Then m_strCaption = m_strName
End Property

Public Property Get FormDefault() As Boolean
   FormDefault = m_ScreenDefault
End Property
Public Property Let FormDefault(ByVal vData As Boolean)
   m_ScreenDefault = vData
End Property

Public Property Get Output() As CPictureBox
   Set Output = m_Output
End Property
Public Property Let Output(ByVal vData As CPictureBox)
   Set m_Output = vData
End Property

Public Property Get FormMenu() As String
   FormMenu = m_ScreenMenu
End Property
Public Property Let FormMenu(ByVal vData As String)
   m_ScreenMenu = vData
End Property

Public Property Let BackColor(ByVal vNewValue As OLE_COLOR)
   SetProperty "BackColor", vNewValue
End Property

Public Property Get Caption() As String
   Caption = m_strCaption
End Property
Public Property Let Caption(ByVal vNewValue As String)
   m_strCaption = vNewValue
End Property

Public Property Get Picture() As String
   Picture = m_strPicture
End Property
Public Property Let Picture(ByVal vNewValue As String)
   m_strPicture = vNewValue
End Property

Public Property Get Tag() As String
   Tag = m_strTag
End Property
Public Property Let Tag(ByVal vNewValue As String)
   m_strTag = vNewValue
End Property

Public Property Get Project() As CProject
   Set Project = m_Project
End Property
Public Property Let Project(ByVal proj As CProject)
   Set m_Project = proj
End Property

Public Property Get Height() As Integer
   Height = m_nHeight
End Property
Public Property Let Height(ByVal vNewValue As Integer)
   m_nHeight = vNewValue
   m_Output.Height = m_nHeight
End Property

Public Property Get Left() As Integer
   Left = m_nLeft
End Property

Public Property Get Top() As Integer
   Top = m_nTop
End Property

Public Property Get Width() As Integer
   Width = m_nWidth
End Property
Public Property Let Width(ByVal vNewValue As Integer)
   m_nWidth = vNewValue
   m_Output.Width = m_nWidth
End Property

Public Property Get Visible() As Boolean
   Visible = m_bVisible
End Property
Public Property Let Visible(ByVal vData As Boolean)
   m_bVisible = vData
End Property
Public Property Get GlobalID() As String
   GlobalID = m_GlobalID
End Property
Public Property Let GlobalID(ByVal vData As String)
   m_GlobalID = vData
End Property

Public Property Get CEType() As String
   CEType = "Output"
End Property


