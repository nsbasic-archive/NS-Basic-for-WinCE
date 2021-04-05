VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CIDELanguage"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

Private m_Obj As Object
Private Engine As CIDEEngine
Public Pasting As Boolean

Public Sub Init(ByRef aEngine As CIDEEngine, Optional ByRef aObj As Object = Nothing)
   Set Engine = aEngine
   If Not aObj Is Nothing Then Set m_Obj = aObj
End Sub

Public Sub AddObject(astrType, Optional astrName, Optional aX, Optional aY, Optional aW, Optional aH, Optional aParent)
Dim obj As Object
Dim strName As String
Dim X As Integer, Y As Integer, W As Integer, H As Integer

#If NSBasic_Desktop Then
   If UCase(astrType) = "FORM" Then
      Engine.Form.Width = aW
      Engine.Form.Height = aH
      Engine.Engine.AddObject Engine.Form.Name, Engine.Form, True
      Exit Sub
   End If
#End If
#If NSBasic_CE Then
   If UCase(astrType) = "FORM" Then astrType = "Frame"
   If LCase(astrType) = "nscepicturebox.nscepictureboxctrl.1" Then astrType = "picturebox"
#End If

   If Not IsMissing(astrName) Then strName = astrName
   If Not IsMissing(aX) Then X = aX
   If Not IsMissing(aY) Then Y = aY
   If Not IsMissing(aW) Then W = aW
   If Not IsMissing(aH) Then H = aH
   If IsMissing(aParent) Or IsEmpty(aParent) Then Set aParent = Nothing

   If IsEmpty(strName) Then
      strName = astrType
   Else
      If Trim(strName) = "" Then strName = astrType
   End If

'   If Right(astrName, 5) = "_Copy" And Pasting Then
'      X = X + 5
'      Y = Y + 5
'   End If
   Set obj = Engine.Screen.AddObject(astrType, strName, X, Y, W, H, aParent)
''   Engine.Screen.AddControl (astrType), X, Y, True
''   Set Ctl = Engine.Screen.CurrentControl
''   Ctl.Name = strName: Ctl.Width = W: Ctl.Height = H
   On Error Resume Next
   If TypeName(obj) = "CPictureBox" And Engine.Screen.Object.Controls.Count = 0 Then
      Engine.Engine.AddObject astrName, obj, True
   ElseIf TypeName(obj) = "CActiveXCtl" Then
      Engine.Engine.AddObject obj.Name, obj.Control.Object, True
      If err.Number = -2147024809 Then
         MsgBox "In form '" & Engine.Form.Name & "':" & vbCrLf & err.Description, vbCritical + vbOKOnly, "AddObject """ & astrType & """, """ & strName & """"
      End If
   Else
      Engine.Engine.AddObject obj.Name, obj, True
      If err.Number = -2147024809 Then
         MsgBox "In form '" & Engine.Form.Name & "':" & vbCrLf & err.Description, vbCritical + vbOKOnly, "AddObject """ & astrType & """, """ & strName & """"
      End If
   End If
End Sub

Public Sub SetMenu(ByVal astrName, ByVal vMenu)
   If Engine.Loading Then
      If Engine.Form Is Nothing Then Exit Sub
      Engine.Form.FormMenu = Engine.Form.FormMenu & "   SetMenu """ & astrName & """, Array(""" & Join(vMenu, Chr(8)) & """)" & vbCrLf
      Engine.Form.FormMenu = Replace(Engine.Form.FormMenu, Chr(8), """, """)
   Else
      If m_Obj Is Nothing Then Exit Sub
      m_Obj.SetMenu CStr(astrName), vMenu
   End If
End Sub

Public Sub UpdateScreen()
   'Dummy function to catch UpdateScreen call in Form_Load
End Sub

'Public Sub Execute(stmt As String)
'You'd think this might be needed, to interpret the Execute statement in the generated code.
'You'd be wrong. The Execute executes as a VB statement, calling the AddObject subroutine about.
'As Marcus would say, "Sweet!"  02.03.2005 GH
'End Sub

