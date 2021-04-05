VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CFrame"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Intrinsic As New INSBIntrinsic
#If NSBasic_CE Then
Private Const kStrPropertyList As String = "Name,Alignment,BackColor,Caption,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Height,Left,Tag,Top,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,Show"
#End If
#If NSBasic_Desktop Then
Private Const kStrPropertyList As String = "Name,Alignment,BackColor,Caption,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Height,Left,Tag,Top,Timer,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,Show"
#End If
#If NSBasic_X Then
Private Const kStrPropertyList As String = "Name,Alignment,BackColor,Caption,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Height,Left,Tag,Top,Timer,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,Show"
#End If
Private Const kStrTypeName As String = "Frame"
Private Const kStrClassID As String = "VB.Frame"

'Module level variables
Private WithEvents m_Ctl As VB.Frame
Attribute m_Ctl.VB_VarHelpID = -1
Private WithEvents m_Sub As VB.PictureBox
Attribute m_Sub.VB_VarHelpID = -1

'Add member variables here for control specific properties
Private m_nAlignment As AlignmentConstants
Private m_vBackColor As OLE_COLOR
'Private m_nBorderStyle As BorderStyleEnum
Private m_strCaption As String
Private m_bEnabled As Boolean
Private m_bFontBold As Boolean
Private m_bFontItalic As Boolean
Private m_strFontName As String
Private m_dFontSize As Double
Private m_bFontStrikethru As Boolean
Private m_bFontUnderline As Boolean
Private m_vForeColor As OLE_COLOR

'Constants for default property values
Private Const kAlignment As Integer = 0
Private Const kBackColor As Long = &HC0C0C0 '&HFFFFFF
'Private Const kBorderStyle As Integer = flexBorderNone
Private Const kEnabled As Boolean = True
Private Const kFontName As String = "Tahoma"
Private Const kFontSize As Double = 8
Private Const kForeColor As Long = 0

Public Controls As New CControls

Private Sub Class_Initialize()
   Set m_Intrinsic.Object = Me
   'Initialize property member variables here
   m_nAlignment = kAlignment
   m_vBackColor = kBackColor
'   m_nBorderStyle = kBorderStyle
   m_bEnabled = kEnabled
   m_strFontName = kFontName
   m_dFontSize = kFontSize
   m_vForeColor = kForeColor
End Sub

Public Function AddObject(astrType As String, astrName As String, X As Integer, Y As Integer, W As Integer, H As Integer) As Object
Static bLoaded As Boolean
Dim obj As Object

   'Initialize return value
   Set AddObject = Nothing

   'Ensure proper type for this object, then convert to ClassID
   If StrComp(astrType, kStrTypeName, vbTextCompare) <> 0 Then Exit Function
   astrType = kStrClassID

   'Create control
   Set m_Sub = m_Intrinsic.Form.Controls.Add("VB.PictureBox", Replace(m_Intrinsic.GlobalID, "|", "_") & "_Sub")
   m_Sub.ScaleMode = vbPixels
   m_Sub.BackColor = vbRed
   m_Sub.Appearance = Flat
   m_Sub.BorderStyle = 0
   Set m_Ctl = m_Intrinsic.Form.Controls.Add(kStrClassID, Replace(m_Intrinsic.GlobalID, "|", "_"))
   Set m_Ctl.Container = m_Sub
   m_Ctl.Visible = True
   Move X, Y, W, H
   'Initialize this object
   If Not bLoaded Then
      bLoaded = True
      Name = astrName
      If Not m_Intrinsic.Form.CreatingForm Then m_strCaption = Name
      '#If NSBasic_Desktop Then         'gh
         m_Intrinsic.Visible = True    'gh
      '#End If                          'gh
   End If
   'Restore properties from object to control
   m_Intrinsic.AddObject "", "", 0, 0, 0, 0

   'Show children
   For Each obj In Controls
      m_Intrinsic.Form.RestoreControl obj, m_Intrinsic.Object
   Next

   'Return newly created control
   Set AddObject = m_Sub
End Function

Public Sub DeleteObject()
Dim ctrl As Object

   For Each ctrl In Controls
      ctrl.DeleteObject
   Next
   
   m_Intrinsic.Form.Controls.Remove m_Ctl.Name
   m_Intrinsic.Form.Controls.Remove m_Sub.Name
End Sub

Public Sub AddControl(Ctl As Object)
   Controls.Add Ctl
End Sub

Public Function RemoveControl(astrName As String) As Boolean
Dim i As Integer

   RemoveControl = True
   For i = 1 To Controls.Count
      If Controls(i).Name = astrName Then
         Controls.Remove i
         Exit Function
      End If
      If TypeName(Controls(i)) = "CFrame" Then
         If Controls(i).RemoveControl(astrName) Then Exit Function
      End If
   Next
   RemoveControl = False
End Function

Public Function ValidObjectName(astrName As String, astrGID As String) As Boolean
Dim Ctl As Object

   ValidObjectName = False

   For Each Ctl In Controls
      If StrComp(Ctl.Name, astrName, vbTextCompare) = 0 Then
         If Len(astrGID) > 0 Then
            If Ctl.GlobalID <> astrGID Then
               Exit Function
            End If
         Else
            Exit Function
         End If
      End If
      If TypeName(Ctl) = "CFrame" Then
         If Not Ctl.ValidObjectName(astrName, astrGID) Then
            Exit Function
         End If
      End If
   Next
   ValidObjectName = True
End Function

Function LocateObjectByName(astrName As String) As Object
Dim frm As CForm
Dim Ctl As Object

   If Len(astrName) = 0 Then Exit Function

   For Each Ctl In Controls
      If StrComp(Ctl.Name, astrName, vbTextCompare) = 0 Then
         Set LocateObjectByName = Ctl
         Exit Function
      End If
      If TypeName(Ctl) = "CFrame" Then
         Set LocateObjectByName = Ctl.LocateObjectByName(astrName)
         If Not LocateObjectByName Is Nothing Then Exit Function
      End If
   Next
End Function

Public Property Get Form() As frmScreen
   Set Form = m_Intrinsic.Form
End Property
Public Sub SetForm(ByVal RHS As frmScreen)
   Set m_Intrinsic.Form = RHS
End Sub

Public Function GenerateCode(kOb As String) As String
Dim strCode As String
Dim Ctl As Object

   strCode = "      AddObject """ & kStrTypeName & """, """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & Trim(kOb) & vbCrLf
   If m_nAlignment <> kAlignment Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Alignment = " & m_nAlignment & vbCrLf
   'If m_vBackColor <> kBackColor Then
      strCode = strCode & "      " & m_Intrinsic.Name & ".BackColor = " & m_vBackColor & vbCrLf
'   If m_nBorderStyle <> kBorderStyle Then _
'      strCode = strCode & "      " & m_Intrinsic.Name & ".BorderStyle = " & m_nBorderStyle & vbCrLf
   If m_strCaption <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Caption = """ & EnQuote(m_strCaption) & """" & vbCrLf
   If m_bEnabled <> kEnabled Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Enabled = " & BoolStr(m_bEnabled) & vbCrLf
   If m_bFontBold Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontBold = True" & vbCrLf
   If m_bFontItalic Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontItalic = True" & vbCrLf
   If m_strFontName <> kFontName Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontName = """ & m_strFontName & """" & vbCrLf
   If m_dFontSize <> kFontSize Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontSize = " & Str(m_dFontSize) & vbCrLf
   If m_bFontStrikethru Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontStrikethru = True" & vbCrLf
   If m_bFontUnderline Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontUnderline = True" & vbCrLf
   If m_vForeColor <> kForeColor Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".ForeColor = " & m_vForeColor & vbCrLf
   If m_Intrinsic.Tag <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Tag = """ & EnQuote(m_Intrinsic.Tag) & """" & vbCrLf
'#If NSBasic_Desktop Then
   If m_Intrinsic.Visible <> True Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Visible = " & BoolStr(m_Intrinsic.Visible) & vbCrLf
'#End If
   
   For Each Ctl In Controls
      strCode = strCode & "      '--------" & vbCrLf & Ctl.GenerateCode(m_Intrinsic.Name)
   Next
'   strCode = Replace(strCode, "***NSBasicFrame***", m_Intrinsic.Name)
   
   GenerateCode = strCode
End Function

Public Function PropertyList() As String()
   PropertyList = Split(kStrPropertyList, ",")
End Function
Public Function MethodList() As String()
   MethodList = Split(kStrMethodList, ",")
End Function

Public Function GetProperty(ByVal astrProperty As String, pvPropVal As Variant) As EXPROPERTIESLISTLibCtl.EditTypeEnum
   GetProperty = m_Intrinsic.GetProperty(astrProperty, pvPropVal)
End Function

Public Function SetProperty(ByVal astrProperty As String, ByVal avNewValue As Variant) As Variant
   SetProperty = m_Intrinsic.SetProperty(astrProperty, avNewValue)
End Function

Public Sub Move(ByVal X As Long, ByVal Y As Long, ByVal W As Long, ByVal H As Long)
   m_Intrinsic.Move X, Y, W, H
End Sub

Public Sub Unload()
Dim obj As Object

   On Error Resume Next
   For Each obj In Controls
      obj.Unload
   Next
   Set m_Ctl.Container = m_Intrinsic.Form
   Set m_Intrinsic.Form = Nothing
End Sub

'Add specific properties here
Public Property Get Alignment() As AlignmentConstants
   Alignment = m_nAlignment
End Property
Public Property Let Alignment(ByVal vNewValue As AlignmentConstants)
 '  m_Ctl.Alignment = vNewValue
 '  m_nAlignment = m_Ctl.Alignment
   m_nAlignment = vNewValue
End Property

Public Property Get BackColor() As OLE_COLOR
   BackColor = m_vBackColor
End Property
Public Property Let BackColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.BackColor = vNewValue
   m_vBackColor = m_Ctl.BackColor
End Property

'Public Property Get BorderStyle() As BorderStyleEnum
'   BorderStyle = m_nBorderStyle
'End Property
'Public Property Let BorderStyle(ByVal vNewValue As BorderStyleEnum)
'   vNewValue = CInt(vNewValue) Mod 2
'   m_Ctl.BorderStyle = vNewValue
'   m_nBorderStyle = m_Ctl.BorderStyle
'End Property

Public Property Get Caption() As String
   Caption = m_strCaption
End Property
Public Property Let Caption(ByVal vNewValue As String)
   m_Ctl.Caption = vNewValue
   m_strCaption = m_Ctl.Caption
End Property

Public Property Get Enabled() As Boolean
   Enabled = m_bEnabled
End Property
Public Property Let Enabled(ByVal vNewValue As Boolean)
   m_bEnabled = vNewValue
End Property

Public Property Get FontBold() As Variant
   FontBold = m_bFontBold
End Property
Public Property Let FontBold(ByVal vNewValue As Variant)
   m_Ctl.FontBold = vNewValue
   m_bFontBold = m_Ctl.FontBold
End Property

Public Property Get FontItalic() As Variant
   FontItalic = m_bFontItalic
End Property
Public Property Let FontItalic(ByVal vNewValue As Variant)
   m_Ctl.FontItalic = vNewValue
   m_bFontItalic = m_Ctl.FontItalic
End Property

Public Property Get FontName() As Variant
   FontName = m_strFontName
End Property
Public Property Let FontName(ByVal vNewValue As Variant)
   m_Ctl.FontName = vNewValue
   m_strFontName = m_Ctl.FontName
End Property

Public Property Get FontSize() As Variant
   FontSize = m_dFontSize
End Property
Public Property Let FontSize(ByVal vNewValue As Variant)
   m_Ctl.FontSize = vNewValue
   m_dFontSize = m_Ctl.FontSize
End Property

Public Property Get FontStrikethru() As Variant
   FontStrikethru = m_bFontStrikethru
End Property
Public Property Let FontStrikethru(ByVal vNewValue As Variant)
   m_Ctl.FontStrikethru = vNewValue
   m_bFontStrikethru = m_Ctl.FontStrikethru
End Property

Public Property Get FontUnderline() As Variant
   FontUnderline = m_bFontUnderline
End Property
Public Property Let FontUnderline(ByVal vNewValue As Variant)
   m_Ctl.FontUnderline = vNewValue
   m_bFontUnderline = m_Ctl.FontUnderline
End Property

Public Property Get ForeColor() As OLE_COLOR
   ForeColor = m_vForeColor
End Property
Public Property Let ForeColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.ForeColor = vNewValue
   m_vForeColor = m_Ctl.ForeColor
End Property

Public Property Get Name() As String
   Name = m_Intrinsic.Name
End Property
Public Property Let Name(ByVal RHS As String)
   m_Intrinsic.Name = RHS
End Property

Public Property Get Left() As Integer
   Left = m_Intrinsic.Left
End Property
Public Property Let Left(ByVal RHS As Integer)
   m_Sub.Left = RHS
   m_Ctl.Left = 0
   m_Intrinsic.Left = m_Sub.Left
End Property

Public Property Get Top() As Integer
   Top = m_Intrinsic.Top
End Property
Public Property Let Top(ByVal RHS As Integer)
   m_Sub.Top = RHS
   m_Ctl.Top = 0
   m_Intrinsic.Top = m_Sub.Top
End Property

Public Property Get Width() As Integer
   Width = m_Intrinsic.Width
End Property
Public Property Let Width(ByVal RHS As Integer)
   m_Sub.Width = RHS
   m_Ctl.Width = m_Sub.Width
   m_Intrinsic.Width = m_Ctl.Width
End Property

Public Property Get Height() As Integer
   Height = m_Intrinsic.Height
End Property
Public Property Let Height(ByVal RHS As Integer)
   m_Sub.Height = RHS
   m_Ctl.Height = m_Sub.Height
   m_Intrinsic.Height = m_Ctl.Height
End Property

Public Property Get Tag() As String
   Tag = m_Intrinsic.Tag
End Property
Public Property Let Tag(ByVal RHS As String)
   m_Intrinsic.Tag = RHS
End Property

Public Property Get Visible() As Boolean
   Visible = m_Intrinsic.Visible
End Property
Public Property Let Visible(ByVal RHS As Boolean)
   m_Intrinsic.Visible = RHS
End Property

Public Property Get Ctl() As PictureBox
   Set Ctl = m_Sub
End Property

Public Property Get GlobalID() As String
   GlobalID = m_Intrinsic.GlobalID
End Property
Public Property Let GlobalID(ByVal RHS As String)
   m_Intrinsic.GlobalID = RHS
End Property

Public Property Get ClassID() As String
   ClassID = kStrTypeName
End Property

Private Sub Class_Terminate()
   Set m_Ctl = Nothing
   Set m_Sub = Nothing
End Sub

Private Sub m_Ctl_DblClick()
   m_Intrinsic.Form.DragEnd
   ViewCode m_Intrinsic.GlobalID ', m_Intrinsic.Name & "_Click"
End Sub

Private Sub m_Ctl_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   If Shift <> vbNormal Then Exit Sub
   If Button = vbLeftButton Then
      m_Intrinsic.Form.DragBegin Me
   End If
   If Button = vbRightButton Then
      m_Intrinsic.Form.ShowPopup Me
   End If
End Sub

Private Sub m_Ctl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
   ShowCoordinates (X) \ Screen.TwipsPerPixelX, (Y) \ Screen.TwipsPerPixelY, True
End Sub

Public Property Get CEType() As String
   CEType = kStrTypeName
End Property