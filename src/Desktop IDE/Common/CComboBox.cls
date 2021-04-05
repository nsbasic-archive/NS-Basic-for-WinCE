VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CComboBox"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Intrinsic As New INSBIntrinsic
#If NSBasic_CE Then
Private Const kStrPropertyList As String = "Name,BackColor,Enabled,ExpandedHeight,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Height,IntegralHeight,Left,ListIndex,Sorted,Style,TabStop,TabDown,TabLeft,TabRight,TabUp,Tag,Text,Top,Width"
Private Const kStrMethodList As String = "AddItem,Clear,RemoveItem,Hide,Move,SetFocus,Show,TabIndex"
#End If
#If NSBasic_Desktop Then
Private Const kStrPropertyList As String = "Name,BackColor,Enabled,ExpandedHeight,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Height,IntegralHeight,Left,ListIndex,Sorted,Style,TabStop,Tag,Text,Timer,Top,Visible,Width"
Private Const kStrMethodList As String = "AddItem,Clear,RemoveItem,Hide,Move,SetFocus,Show"
#End If
#If NSBasic_X Then
Private Const kStrPropertyList As String = "Name,BackColor,Enabled,ExpandedHeight,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,ForeColor,Height,IntegralHeight,Left,ListIndex,Sorted,Style,TabStop,Tag,Text,Timer,Top,Visible,Width"
Private Const kStrMethodList As String = "AddItem,Clear,RemoveItem,Hide,Move,SetFocus,Show"
#End If
Private Const kStrTypeName As String = "ComboBox"
Private Const kStrClassID As String = "VB.Label"

'Module level variables
Private WithEvents m_Ctl As VB.Label
Attribute m_Ctl.VB_VarHelpID = -1
Private WithEvents m_Sub As VB.PictureBox
Attribute m_Sub.VB_VarHelpID = -1

'Add member variables here for control specific properties
Private m_vBackColor As OLE_COLOR
Private m_bEnabled As Boolean
Private m_nExpandedHeight As Integer
Private m_bFontBold As Boolean
Private m_bFontItalic As Boolean
Private m_strFontName As String
Private m_dFontSize As Double
Private m_bFontStrikethru As Boolean
Private m_bFontUnderline As Boolean
Private m_vForeColor As OLE_COLOR
Private m_bIntegralHeight As Boolean
Private m_bSorted As Boolean
Private m_nStyle As ComboBoxConstants ' Integer
Private m_bTabStop As Boolean
Private m_strText As String
Private m_bTabDown As String
Private m_bTabLeft As String
Private m_bTabRight As String
Private m_bTabUp As String

'Constants for default property values
Private Const kBackColor As Long = &HFFFFFF
Private Const kEnabled As Boolean = True
Private Const kExpandedHeight As Integer = 60
Private Const kFontName As String = "Tahoma"
Private Const kFontSize As Double = 8
Private Const kForeColor As Long = 0
Private Const kIntegralHeight As Boolean = True
Private Const kSorted As Boolean = False
#If NSBasic_CE Then
Private Const kStyle As Integer = 2
#Else
Private Const kStyle As Integer = 0
#End If
Private Const kTabStop As Boolean = True

Private Sub Class_Initialize()
   Set m_Intrinsic.Object = Me
   'Initialize property member variables here
   m_vBackColor = kBackColor
   m_bEnabled = kEnabled
   m_nExpandedHeight = kExpandedHeight
   m_strFontName = kFontName
   m_dFontSize = kFontSize
   m_vForeColor = kForeColor
   m_bIntegralHeight = kIntegralHeight
   m_bSorted = kSorted
   m_nStyle = kStyle
   m_bTabStop = kTabStop
   m_Intrinsic.Height = 21
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
   m_Ctl.BorderStyle = 1
   m_Ctl.Caption = astrName
   m_Ctl.FontBold = True
   m_Ctl.Alignment = vbCenter
   m_Ctl.Visible = True
   Move X, Y, W, H
   'Initialize this object
   If Not bLoaded Then
      bLoaded = True
      Name = astrName
      m_nExpandedHeight = H
      m_Intrinsic.Height = 21
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

   strCode = "      AddObject """ & kStrTypeName & """, """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_nExpandedHeight & ", " & Trim(kOb) & vbCrLf
   'If m_vBackColor <> kBackColor Then
      strCode = strCode & "      " & m_Intrinsic.Name & ".BackColor = " & m_vBackColor & vbCrLf
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
   If m_bIntegralHeight Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".IntegralHeight = " & BoolStr(m_bIntegralHeight) & vbCrLf
   If m_bSorted Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Sorted = " & BoolStr(m_bSorted) & vbCrLf
   If m_nStyle <> kStyle Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Style = " & m_nStyle & vbCrLf
   If Not m_bTabStop Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".TabStop = " & m_bTabStop & vbCrLf
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
Public Property Get BackColor() As OLE_COLOR
   BackColor = m_vBackColor
End Property
Public Property Let BackColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.BackColor = vNewValue
   m_vBackColor = m_Ctl.BackColor
End Property

Public Property Get Enabled() As Boolean
   Enabled = m_bEnabled
End Property
Public Property Let Enabled(ByVal vNewValue As Boolean)
   m_bEnabled = vNewValue
End Property

Public Property Get ExpandedHeight() As Integer
   ExpandedHeight = m_nExpandedHeight
End Property
Public Property Let ExpandedHeight(ByVal RHS As Integer)
   'No equivalent
   m_nExpandedHeight = RHS
End Property

Public Property Get FontBold() As Variant
   FontBold = m_bFontBold
End Property
Public Property Let FontBold(ByVal vNewValue As Variant)
'   m_Ctl.FontBold = vNewValue
'   m_bFontBold = m_Ctl.FontBold
   m_bFontBold = vNewValue
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

Public Property Get IntegralHeight() As Boolean
   IntegralHeight = m_bIntegralHeight
End Property
Public Property Let IntegralHeight(ByVal vNewValue As Boolean)
   'No equivalent
   m_bIntegralHeight = vNewValue
End Property

Public Property Get Sorted() As Boolean
   Sorted = m_bSorted
End Property
Public Property Let Sorted(ByVal vNewValue As Boolean)
   'No equvialent
   m_bSorted = vNewValue
End Property

Public Property Get Style() As ComboBoxConstants
   Style = m_nStyle
End Property
Public Property Let Style(ByVal vNewValue As ComboBoxConstants)
   'No equivalent
   m_nStyle = vNewValue
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
Public Property Let Caption(ByVal vNewValue As String)
   'Backwards compatibility
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
'   m_Ctl.Width = max(0,RHS)
   m_Intrinsic.Width = m_Ctl.Width
End Property

Public Property Get Height() As Integer
   Height = m_Intrinsic.Height
End Property
Public Property Let Height(ByVal RHS As Integer)
   m_Sub.Height = RHS
   m_Ctl.Height = m_Sub.Height
'   m_Ctl.height = max(0,RHS)
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

Private Sub m_Ctl_KeyDown(KeyCode As Integer, Shift As Integer)
   m_Intrinsic.Form.KeyDown (KeyCode), Shift
End Sub

Public Property Get CEType() As String
   CEType = kStrTypeName
End Property
