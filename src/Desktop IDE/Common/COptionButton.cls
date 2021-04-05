VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "COptionButton"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Intrinsic As New INSBIntrinsic
#If NSBasic_CE Then
Private Const kStrPropertyList As String = "Name,Alignment,BackColor,Caption,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Group,Height,Left,TabStop,Tag,Top,Value,Width"
Private Const kStrMethodList As String = "Hide,Move,SetFocus,Show"
#End If
#If NSBasic_Desktop Then
Private Const kStrPropertyList As String = "Name,Alignment,BackColor,Caption,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Group,Height,Left,Picture,TabStop,Tag,Top,Value,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,SetFocus,Show"
#End If
#If NSBasic_X Then
Private Const kStrPropertyList As String = "Name,Alignment,BackColor,Caption,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Group,Height,Left,Picture,TabStop,Tag,Top,Value,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,SetFocus,Show"
#End If
Private Const kStrTypeName As String = "OptionButton"
Private Const kStrClassID As String = "VB.OptionButton"

'Module variables
Private WithEvents m_Ctl As VB.OptionButton
Attribute m_Ctl.VB_VarHelpID = -1
Private m_Frame As VB.Frame

'Add member variables here for control specific properties
Private m_nAlignment As AlignmentConstants
Private m_vBackColor As OLE_COLOR
Private m_strCaption As String
Private m_bEnabled As Boolean
Private m_bFontBold As Boolean
Private m_bFontItalic As Boolean
Private m_strFontName As String
Private m_dFontSize As Double
Private m_bFontStrikethru As Boolean
Private m_bFontUnderline As Boolean
Private m_vForeColor As OLE_COLOR
Private m_bGroup As Boolean
Private m_strPicture As String
Private m_bTabStop As Boolean
Private m_bValue As Boolean

'Constants for default property values
Private Const kAlignment As Integer = vbLeftJustify
Private Const kBackColor As Long = vbWhite '&HC0C0C0
Private Const kEnabled As Boolean = True
Private Const kFontName As String = "Tahoma"
Private Const kFontSize As Double = 8
Private Const kForeColor As Long = 0
Private Const kGroup As Boolean = True
Private Const kPicture As String = ""
Private Const kTabStop As Boolean = True
Private Const kValue As Boolean = False

Private Sub Class_Initialize()
   Set m_Intrinsic.Object = Me
   'Initialize property member variables here
   m_nAlignment = kAlignment
   m_vBackColor = &HC0C0C0 'kBackColor
   m_bEnabled = kEnabled
   m_strFontName = kFontName
   m_dFontSize = kFontSize
   m_vForeColor = kForeColor
   m_bGroup = kGroup
   m_strPicture = kPicture
   m_bTabStop = kTabStop
   m_bValue = kValue
End Sub

Private Sub Class_Terminate()
   If Not m_Intrinsic.Form Is Nothing Then
      If Not m_Frame Is Nothing Then
         On Error Resume Next
         m_Intrinsic.Form.Controls.Remove m_Frame.Name
         Set m_Frame = Nothing
      End If
   End If
End Sub

Public Function AddObject(astrType As String, astrName As String, X As Integer, Y As Integer, W As Integer, H As Integer) As Object
Static bLoaded As Boolean

   'Initialize return value
   Set AddObject = Nothing

   'Ensure proper type for this object, then convert to ClassID
   If StrComp(astrType, kStrTypeName, vbTextCompare) <> 0 Then Exit Function
   astrType = kStrClassID

   'Create control
   Set m_Frame = m_Intrinsic.Form.Controls.Add("VB.Frame", "NSB_F_" & Replace(m_Intrinsic.GlobalID, "|", "_"))
   m_Frame.Appearance = 0
   m_Frame.BorderStyle = 0
   Set m_Ctl = m_Intrinsic.Form.Controls.Add(kStrClassID, Replace(m_Intrinsic.GlobalID, "|", "_"))
'   Set m_Ctl.Container = m_Frame
'   m_Ctl.Visible = True
   Move X, Y, W, H
   'Initialize this object
   If Not bLoaded Then
      bLoaded = True
      m_Intrinsic.Name = astrName
      m_strCaption = m_Intrinsic.Name
      #If NSBasic_Desktop Then         'gh
         m_Intrinsic.Visible = True    'gh
      #End If                          'gh
   End If
   'Restore properties from object to control
   m_Intrinsic.AddObject "", "", 0, 0, 0, 0

   'Return newly created control
   Set AddObject = m_Ctl
End Function

Public Sub DeleteObject()
   m_Intrinsic.Form.Controls.Remove m_Frame.Name
   m_Intrinsic.Form.Controls.Remove m_Ctl.Name
End Sub

Public Property Get Form() As frmScreen
   Set Form = m_Intrinsic.Form
End Property
Public Sub SetForm(ByVal RHS As frmScreen)
   Set m_Intrinsic.Form = RHS
End Sub

Public Function GenerateCode(kOb As String) As String
Dim strCode As String

   strCode = "      AddObject """ & kStrTypeName & """, """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & Trim(kOb) & vbCrLf
   If m_nAlignment <> kAlignment Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Alignment = " & m_nAlignment & vbCrLf
   'If m_vBackColor <> kBackColor Then
      strCode = strCode & "      " & m_Intrinsic.Name & ".BackColor = " & m_vBackColor & vbCrLf
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
   If m_bGroup <> kGroup Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Group = " & BoolStr(m_bGroup) & vbCrLf
#If NSBasic_Desktop Then
   If m_strPicture <> kPicture Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Picture = """ & m_strPicture & """" & vbCrLf
   If m_Intrinsic.Visible <> True Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Visible = " & BoolStr(m_Intrinsic.Visible) & vbCrLf
#End If
   If Not m_bTabStop Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabStop = False" & vbCrLf
   If m_Intrinsic.Tag <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Tag = """ & EnQuote(m_Intrinsic.Tag) & """" & vbCrLf
   If m_bValue <> kValue Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Value = " & BoolStr(m_bValue) & vbCrLf
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
   Set m_Intrinsic.Form = Nothing
End Sub

'Add specific properties here
Public Property Get Alignment() As AlignmentConstants
   Alignment = m_nAlignment
End Property
Public Property Let Alignment(ByVal vNewValue As AlignmentConstants)
   If vNewValue <> vbLeftJustify And vNewValue <> vbRightJustify Then vNewValue = m_Ctl.Alignment
   m_Ctl.Alignment = vNewValue
   m_nAlignment = m_Ctl.Alignment
End Property

Public Property Get BackColor() As OLE_COLOR
   BackColor = m_vBackColor
End Property
Public Property Let BackColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.BackColor = vNewValue
   m_vBackColor = m_Ctl.BackColor
End Property

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
   'No Equivalent
   m_vForeColor = vNewValue
End Property

Public Property Get Group() As Variant
   Group = m_bGroup
End Property
Public Property Let Group(ByVal vNewValue As Variant)
   'No Equivalent
   m_bGroup = vNewValue
End Property

Public Property Get Picture() As String
   Picture = m_strPicture
End Property
Public Property Let Picture(ByVal vNewValue As String)
   m_strPicture = vNewValue
End Property

Public Property Get TabStop() As Boolean
   TabStop = m_bTabStop
End Property
Public Property Let TabStop(ByVal vNewValue As Boolean)
   m_Ctl.TabStop = vNewValue
   m_bTabStop = m_Ctl.TabStop
End Property

Public Property Get Value() As Boolean
   Value = m_bValue
End Property
Public Property Let Value(ByVal vNewValue As Boolean)
   m_Ctl.Value = IIf(vNewValue, 1, 0)
   m_bValue = m_Ctl.Value
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
'   m_Frame.Left = RHS
'   m_Intrinsic.Left = m_Frame.Left
   m_Ctl.Left = RHS
   m_Intrinsic.Left = m_Ctl.Left
End Property

Public Property Get Top() As Integer
   Top = m_Intrinsic.Top
End Property
Public Property Let Top(ByVal RHS As Integer)
'   m_Frame.Top = RHS
'   m_Intrinsic.Top = m_Frame.Top
   m_Ctl.Top = RHS
   m_Intrinsic.Top = m_Ctl.Top
End Property

Public Property Get Width() As Integer
   Width = m_Intrinsic.Width
End Property
Public Property Let Width(ByVal RHS As Integer)
'   m_Frame.Width = RHS
   m_Ctl.Width = IIf(RHS >= 0, RHS, m_Ctl.Width) 'm_Frame.Width
   m_Intrinsic.Width = m_Ctl.Width
End Property

Public Property Get Height() As Integer
   Height = m_Intrinsic.Height
End Property
Public Property Let Height(ByVal RHS As Integer)
'   m_Frame.Height = RHS
   m_Ctl.Height = IIf(RHS > 0, RHS, 0) 'm_Frame.Height
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

Public Property Get Ctl() As VB.OptionButton
   Set Ctl = m_Ctl
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

Private Sub m_Ctl_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
Static clickTime As Double

   If Shift <> vbNormal Then Exit Sub
   If Button = vbLeftButton Then
      If Timer - clickTime < gdblClickTime Then
         ViewCode m_Intrinsic.GlobalID, m_Intrinsic.Name & "_Click"
         Exit Sub
      End If
      clickTime = Timer
      m_Intrinsic.Form.DragBegin Me
   End If
   If Button = vbRightButton Then
      m_Intrinsic.Form.ShowPopup Me
   End If
End Sub

Public Property Get CEType() As String
   CEType = kStrTypeName
End Property

