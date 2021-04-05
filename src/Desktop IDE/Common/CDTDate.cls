VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CDTDate"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Intrinsic As New INSBIntrinsic
#If NSBasic_CE Then
Private Const kStrPropertyList As String = "Name,Date,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,LongFormat,Height,Left,TabStop,TabDown,TabLeft,TabRight,TabUp,Tag,Text,Top,Width"
Private Const kStrMethodList As String = "Hide,Move,SetFocus,Show,TabIndex"
#End If
#If NSBasic_Desktop Then
Private Const kStrPropertyList As String = "Name,Date,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,LongFormat,Height,Left,TabStop,Tag,Text,Top,Timer,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,SetFocus,Show"
#End If
#If NSBasic_X Then
Private Const kStrPropertyList As String = "Name,Date,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,LongFormat,Height,Left,TabStop,Tag,Text,Top,Timer,Visible,Width"
Private Const kStrMethodList As String = "Hide,Move,SetFocus,Show"
#End If
Private Const kStrTypeName As String = "Date"
Private Const kStrClassID As String = "VB.Label"

'Module level variables
Private WithEvents m_Ctl As VB.Label
Attribute m_Ctl.VB_VarHelpID = -1
Private WithEvents m_Sub As VB.PictureBox
Attribute m_Sub.VB_VarHelpID = -1

'Add member variables here for control specific properties
Private m_bEnabled As Boolean
Private m_bFontBold As Boolean
Private m_bFontItalic As Boolean
Private m_strFontName As String
Private m_dFontSize As Double
Private m_bFontStrikethru As Boolean
Private m_bFontUnderline As Boolean
Private m_bLongFormat As Boolean
Private m_bTabStop As Boolean
Private m_strText As String
Private m_bTabDown As String
Private m_bTabLeft As String
Private m_bTabRight As String
Private m_bTabUp As String

'Constants for default property values
Private Const kEnabled As Boolean = True
Private Const kFontName As String = "Tahoma"
Private Const kFontSize As Double = 8
Private Const kLongFormat As Boolean = False
Private Const kTabStop As Boolean = True

Private Sub Class_Initialize()
   Set m_Intrinsic.Object = Me
   'Initialize property member variables here
   m_bEnabled = kEnabled
   m_strFontName = kFontName
   m_dFontSize = kFontSize
   m_bLongFormat = kLongFormat
   m_bTabStop = kTabStop
End Sub

Public Function AddObject(astrType As String, astrName As String, X As Integer, Y As Integer, W As Integer, H As Integer) As Object
Static bLoaded As Boolean

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
   m_Ctl.Appearance = 0
   m_Ctl.Caption = astrName
   m_Ctl.FontBold = True
   m_Ctl.Alignment = vbCenter
   m_Ctl.BorderStyle = 1
   m_Ctl.Visible = True
   Move X, Y, W, H
   'Initialize this object
   If Not bLoaded Then
      bLoaded = True
      Name = astrName
      'Width = 95                      'gh Why is this here?
      #If NSBasic_Desktop Then         'gh
         m_Intrinsic.Visible = True    'gh
      #End If                          'gh
   End If
   'Restore properties from object to control
   m_Intrinsic.AddObject "", "", 0, 0, 0, 0

   'Return newly created control
   Set AddObject = m_Sub
'   Set AddObject = m_Ctl
End Function

Public Sub DeleteObject()
   m_Intrinsic.Form.Controls.Remove m_Ctl.Name
   m_Intrinsic.Form.Controls.Remove m_Sub.Name
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
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontStrikethru = " & m_bFontStrikethru & vbCrLf
   If m_bFontUnderline Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".FontUnderline = " & m_bFontUnderline & vbCrLf
   If m_bLongFormat Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".LongFormat = True" & vbCrLf
   If Not m_bTabStop Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabStop = False" & vbCrLf
   If m_Intrinsic.TabDown <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabDown = """ & EnQuote(m_Intrinsic.TabDown) & """" & vbCrLf
   If m_Intrinsic.TabLeft <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabLeft = """ & EnQuote(m_Intrinsic.TabLeft) & """" & vbCrLf
   If m_Intrinsic.TabRight <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabRight = """ & EnQuote(m_Intrinsic.TabRight) & """" & vbCrLf
   If m_Intrinsic.TabUp <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabUp = """ & EnQuote(m_Intrinsic.TabUp) & """" & vbCrLf
   If m_Intrinsic.Tag <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Tag = """ & EnQuote(m_Intrinsic.Tag) & """" & vbCrLf
   If m_strText <> "" Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Text = """ & EnQuote(m_strText) & """" & vbCrLf
#If NSBasic_Desktop Then
   If m_Intrinsic.Visible <> True Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Visible = " & BoolStr(m_Intrinsic.Visible) & vbCrLf
#End If
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
   If Not m_Intrinsic.Form Is Nothing Then
      Set m_Ctl.Container = m_Intrinsic.Form
   End If
   Set m_Intrinsic.Form = Nothing
End Sub

'Add specific properties here
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
'   m_Ctl.Font.Bold = vNewValue
'   m_bFontBold = m_Ctl.Font.Bold
   m_bFontBold = vNewValue
End Property

Public Property Get FontItalic() As Variant
   FontItalic = m_bFontItalic
End Property
Public Property Let FontItalic(ByVal vNewValue As Variant)
   m_Ctl.Font.Italic = vNewValue
   m_bFontItalic = m_Ctl.Font.Italic
End Property

Public Property Get FontName() As Variant
   FontName = m_strFontName
End Property
Public Property Let FontName(ByVal vNewValue As Variant)
   m_Ctl.Font.Name = vNewValue
   m_strFontName = m_Ctl.Font.Name
End Property

Public Property Get FontSize() As Variant
   FontSize = m_dFontSize
End Property
Public Property Let FontSize(ByVal vNewValue As Variant)
   m_Ctl.Font.Size = vNewValue
   m_dFontSize = m_Ctl.Font.Size
End Property

Public Property Get FontStrikethru() As Variant
   FontStrikethru = m_bFontStrikethru
End Property
Public Property Let FontStrikethru(ByVal vNewValue As Variant)
   m_Ctl.Font.Strikethrough = vNewValue
   m_bFontStrikethru = m_Ctl.Font.Strikethrough
End Property

Public Property Get FontUnderline() As Variant
   FontUnderline = m_bFontUnderline
End Property
Public Property Let FontUnderline(ByVal vNewValue As Variant)
   m_Ctl.Font.Underline = vNewValue
   m_bFontUnderline = m_Ctl.Font.Underline
End Property

Public Property Get LongFormat() As Boolean
   LongFormat = m_bLongFormat
End Property
Public Property Let LongFormat(ByVal vNewValue As Boolean)
   'No equivalent
   m_bLongFormat = vNewValue
End Property

Public Property Get TabStop() As Boolean
   TabStop = m_bTabStop
End Property
Public Property Let TabStop(ByVal vNewValue As Boolean)
   'No equivalent
   m_bTabStop = vNewValue
End Property

Public Property Get Text() As String
   Text = m_strText
End Property
Public Property Let Text(ByVal vNewValue As String)
   'No equivalent
   m_strText = vNewValue
End Property

Public Property Get Name() As String
   Name = m_Intrinsic.Name
End Property
Public Property Let Name(ByVal RHS As String)
   m_Intrinsic.Name = RHS
   m_Ctl.Caption = m_Intrinsic.Name
End Property

Public Property Get Left() As Integer
   Left = m_Intrinsic.Left
End Property
Public Property Let Left(ByVal RHS As Integer)
   m_Sub.Left = RHS
   m_Ctl.Left = 0
   m_Intrinsic.Left = m_Sub.Left
'   m_Ctl.Left = RHS
'   m_Intrinsic.Left = m_Ctl.Left
End Property

Public Property Get Top() As Integer
   Top = m_Intrinsic.Top
End Property
Public Property Let Top(ByVal RHS As Integer)
   m_Sub.Top = RHS
   m_Ctl.Top = 0
   m_Intrinsic.Top = m_Sub.Top
'   m_Ctl.Top = RHS
'   m_Intrinsic.Top = m_Ctl.Top
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
Public Property Get TabDown() As String
   TabDown = m_Intrinsic.TabDown
End Property
Public Property Let TabDown(ByVal RHS As String)
   m_Intrinsic.TabDown = RHS
End Property

Public Property Get TabLeft() As String
   TabLeft = m_Intrinsic.TabLeft
End Property
Public Property Let TabLeft(ByVal RHS As String)
   m_Intrinsic.TabLeft = RHS
End Property

Public Property Get TabRight() As String
   TabRight = m_Intrinsic.TabRight
End Property
Public Property Let TabRight(ByVal RHS As String)
   m_Intrinsic.TabRight = RHS
End Property

Public Property Get TabUp() As String
   TabUp = m_Intrinsic.TabUp
End Property
Public Property Let TabUp(ByVal RHS As String)
   m_Intrinsic.TabUp = RHS
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

Public Property Get Ctl() As VB.PictureBox
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

Private Sub m_Ctl_DblClick()
   m_Intrinsic.Form.DragEnd
   ViewCode m_Intrinsic.GlobalID, m_Intrinsic.Name & "_Change"
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

Public Property Get CEType() As String
   CEType = kStrTypeName
End Property

