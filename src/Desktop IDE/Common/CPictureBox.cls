VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CPictureBox"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Intrinsic As New INSBIntrinsic

#If NSBasic_CE Then
Private Const kStrPropertyList As String = "Name,BackColor,BorderStyle,DrawWidth,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontTransparent,FontUnderline,ForeColor,Height,Hwnd,Left,Picture,ScaleHeight,ScaleLeft,ScaleMode,ScaleTop,ScaleWidth,Tag,Top,Width"
Private Const kStrMethodList As String = "Cls,DrawCircle,DrawLine,DrawPicture,DrawPoint,DrawText,Refresh,ScaleX,ScaleY,SetScale,TextHeight,TextWidth,Hide,Move,SetFocus,Show"
#End If
#If NSBasic_Desktop Then
Private Const kStrPropertyList As String = "Name,AlignX,AlignY,BackColor,BorderStyle,DrawWidth,DrawStyle,Enabled,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,FontWeight,ForeColor,Height,HWnd,Left,Picture,Tag,Text,Timer,Top,Visible,Width"
Private Const kStrMethodList As String = "Cls,DrawCircle,DrawLine,DrawPicture,DrawPoint,DrawText,Refresh,ScaleX,ScaleY,SetScale,TextHeight,TextWidth,Hide,Move,SetFocus,Show"
#End If
#If NSBasic_X Then
Private Const kStrPropertyList As String = "Name,AlignX,AlignY,BackColor,BorderStyle,DrawWidth,DrawStyle,Enabled,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,FontWeight,ForeColor,Height,HWnd,Left,Picture,Tag,Text,Timer,Top,Visible,Width"
Private Const kStrMethodList As String = "Cls,DrawCircle,DrawLine,DrawPicture,DrawPoint,DrawText,Refresh,ScaleX,ScaleY,SetScale,TextHeight,TextWidth,Hide,Move,SetFocus,Show"
#End If

#If NSBasic_CE Then
Private Const kStrOutputList As String = "Name,BackColor,DrawWidth,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontTransparent,FontUnderline,ForeColor,Height,Left,Picture,ScaleMode,Tag,Top,Width"
#End If
#If NSBasic_Desktop Then
Private Const kStrOutputList As String = "Name,BackColor,BorderStyle,DrawStyle,DrawWidth,Enabled,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontTransparent,FontUnderline,FontWeight,ForeColor,Height,Left,Picture,Tag,Text,Timer,Top,Width"
#End If
#If NSBasic_X Then
Private Const kStrOutputList As String = "Name,BackColor,BorderStyle,DrawStyle,DrawWidth,Enabled,FillColor,FillStyle,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontTransparent,FontUnderline,FontWeight,ForeColor,Height,Left,Picture,Tag,Text,Timer,Top,Width"
#End If

Private Const kStrTypeName As String = "PictureBox"
Private Const kStrClassID As String = "VB.PictureBox"

'Module level variables
Private WithEvents m_Ctl As VB.PictureBox
Attribute m_Ctl.VB_VarHelpID = -1

'Add member variables here for control specific properties
Private m_nAlignX As Integer
Private m_nAlignY As Integer
Private m_vBackColor As OLE_COLOR
Private m_nDrawWidth As Integer
Private m_nDrawStyle As Integer
Private m_bEnabled As Boolean
Private m_vFillColor As OLE_COLOR
Private m_bFontBold As Boolean
Private m_bFontItalic As Boolean
Private m_strFontName As String
Private m_dFontSize As Double
Private m_bFontStrikethru As Boolean
Private m_bFontTransparent As Boolean
Private m_bFontUnderline As Boolean
Private m_nFontWeight As Integer
Private m_vForeColor As OLE_COLOR
Private m_strPicture As String
Private m_nScaleHeight As Integer
Private m_nScaleLeft As Integer
Private m_nScaleTop As Integer
Private m_nScaleWidth As Integer
Private m_strText As String
Private m_nTimer As Integer
Private m_bVisible As Boolean

#If NSBasic_Desktop Or NSBasic_X Then
Private m_nScaleMode As Integer
Private m_nFillStyle As Integer
Private m_nBorderStyle As Integer
#Else
Private m_nBorderStyle As PictureBoxBorderStyle
Private m_nFillStyle As PictureBoxFillStyle
Private m_nScaleMode As PictureBoxScaleMode
#End If

'Constants for default property values
Private Const kAlignX As Integer = 0
Private Const kAlignY As Integer = 0
Private Const kBackColor As Long = &HC0C0C0
Private Const kDrawStyle As Integer = 0
Private Const kDrawWidth As Integer = 1
Private Const kEnabled As Boolean = True
Private Const kFillColor As Long = vbBlack
Private Const kFontName As String = "Tahoma"
Private Const kFontSize As Double = 8
Private Const kFontWeight As Integer = 400
Private Const kForeColor As Long = vbBlack
Private Const kText As String = ""
Private Const kTimer As Integer = 0
Private Const kVisible As Boolean = True
#If NSBasic_Desktop Or NSBasic_X Then
Private Const kBorderStyle As Integer = 1
Private Const kFillStyle As Integer = 0
Private Const kScaleMode As Integer = 3
#Else
Private Const kBorderStyle As Integer = PictureBoxBorderStyle.picFixedSingle
Private Const kFillStyle As Integer = PictureBoxFillStyle.picFSSolid
Private Const kScaleMode As Integer = PictureBoxScaleMode.picTwips
#End If

Private Sub Class_Initialize()
   Set m_Intrinsic.Object = Me
   'Initialize property member variables here
   m_nAlignX = kAlignX
   m_nAlignY = kAlignY
   m_vBackColor = kBackColor
   m_nBorderStyle = kBorderStyle
   m_nDrawStyle = kDrawStyle
   m_nDrawWidth = kDrawWidth
   m_bEnabled = kEnabled
   m_vFillColor = kFillColor
   m_nFillStyle = kFillStyle
   m_strFontName = kFontName
   m_dFontSize = kFontSize
   m_nFontWeight = kFontWeight
   m_vForeColor = kForeColor
   m_nScaleMode = kScaleMode
   m_strText = kText
   m_nTimer = kTimer
   m_bVisible = kVisible
End Sub

Public Function AddObject(astrType As String, astrName As String, X As Integer, Y As Integer, W As Integer, H As Integer) As Object
Static bLoaded As Boolean

   'Initialize return value
   Set AddObject = Nothing

   'Ensure proper type for this object, then convert to ClassID
   If StrComp(astrType, kStrTypeName, vbTextCompare) <> 0 Then Exit Function
   astrType = kStrClassID

   'Create control
   Set m_Ctl = m_Intrinsic.Form.Controls.Add(kStrClassID, Replace(m_Intrinsic.GlobalID, "|", "_"))
   Move X, Y, W, H
   'Initialize this object
   If Not bLoaded Then
      bLoaded = True
      Name = astrName
      m_nScaleLeft = m_Ctl.ScaleLeft
      m_nScaleTop = m_Ctl.ScaleTop
      m_nScaleWidth = m_Ctl.ScaleWidth
      m_nScaleHeight = m_Ctl.ScaleHeight
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
   m_Intrinsic.Form.Controls.Remove m_Ctl.Name
End Sub

Public Property Get Form() As Form 'frmScreen
   Set Form = m_Intrinsic.Form
End Property
Public Sub SetForm(ByVal RHS As frmScreen)
   Set m_Intrinsic.Form = RHS
End Sub

Public Function GenerateCode(kOb As String) As String
Dim strCode As String
Dim strName As String
Dim q As String
Dim qq As String

   q = Chr(34)
   qq = Chr(34) & " & chr(34) & " & Chr(34)
   
   If 1 = 0 Then '--------- start dead code
   'If Trim(kOb) <> "Output" Then
   If Left(kOb, 1) = " " Then
      #If NSBasic_Desktop Then
         strCode = "      AddObject ""Form"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & vbCrLf
      #End If
      strName = "      " & kOb
   Else
      #If NSBasic_CE Then
         strCode = "AddObject " & qq & kStrTypeName & qq & ", " & qq & m_Intrinsic.Name & qq & ", " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & kOb
         strCode = "      NSExecute " & q & strCode & q & vbCrLf
      #End If
      #If NSBasic_Desktop Then
         strCode = "      AddObject ""PictureBox"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & kOb & vbCrLf
      #End If
      'This property is set to 0 for Output PictureBox, not 1
      If m_nBorderStyle <> kBorderStyle Then _
         strCode = strCode & "      " & m_Intrinsic.Name & ".BorderStyle = " & m_nBorderStyle & vbCrLf
      #If NSBasic_CE Then
         'Moving the PictureBox after creation solves the 100x100 error
         strCode = strCode & "      " & m_Intrinsic.Name & ".Width = " & m_Intrinsic.Width & vbCrLf
         strCode = strCode & "      " & m_Intrinsic.Name & ".Height = " & m_Intrinsic.Height & vbCrLf
      #End If
      strName = "      " & m_Intrinsic.Name
   End If
   End If  '----------- end of dead code
   
   If 1 = 1 Then
   #If NSBasic_Desktop Then
   If Left(kOb, 1) = " " Then
      If InStr(kOb, "***NSBasicForm**") > 0 Then
         strCode = "      AddObject ""Form"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & vbCrLf
      Else
         strCode = "      AddObject ""PictureBox"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & vbCrLf
      End If
      strName = "      " & kOb
   Else
      strCode = "      AddObject ""PictureBox"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & kOb
      strCode = strCode & vbCrLf
      If m_nBorderStyle <> kBorderStyle Then _
         strCode = strCode & "      " & m_Intrinsic.Name & ".BorderStyle = " & m_nBorderStyle & vbCrLf
      strName = "      " & m_Intrinsic.Name
   End If
   #End If
   
   #If NSBasic_CE Then
   If Left(kOb, 1) = " " Then
      If InStr(kOb, "***NSBasicForm**") = 0 Then
       'This can only happen if this routine is called from frmScreen.Copy
        strCode = "      AddObject ""PictureBox"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & vbCrLf
      End If
      strName = "      " & kOb
   Else
      strCode = "AddObject " & qq & kStrTypeName & qq & ", " & qq & m_Intrinsic.Name & qq & ", " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & kOb
      strCode = "      NSExecute " & q & strCode & q & vbCrLf
      If m_nBorderStyle <> kBorderStyle Then _
         strCode = strCode & "      " & m_Intrinsic.Name & ".BorderStyle = " & m_nBorderStyle & vbCrLf
      'Moving the PictureBox after creation solves the 100x100 error
      strCode = strCode & "      " & m_Intrinsic.Name & ".Width = " & m_Intrinsic.Width & vbCrLf
      strCode = strCode & "      " & m_Intrinsic.Name & ".Height = " & m_Intrinsic.Height & vbCrLf
      strName = "      " & m_Intrinsic.Name
   End If
   #End If
   End If
   
   If m_vBackColor <> kBackColor Then _
      strCode = strCode & strName & ".BackColor = " & m_vBackColor & vbCrLf
   If m_nDrawWidth <> kDrawWidth Then _
      strCode = strCode & strName & ".DrawWidth = " & m_nDrawWidth & vbCrLf
   If m_vFillColor <> kFillColor Then _
      strCode = strCode & strName & ".FillColor = " & m_vFillColor & vbCrLf
   If m_nFillStyle <> kFillStyle Then _
      strCode = strCode & strName & ".FillStyle = " & m_nFillStyle & vbCrLf
   If m_bFontBold Then _
      strCode = strCode & strName & ".FontBold = True" & vbCrLf
   If m_bFontItalic Then _
      strCode = strCode & strName & ".FontItalic = True" & vbCrLf
   If m_strFontName <> kFontName Then _
      strCode = strCode & strName & ".FontName = """ & m_strFontName & """" & vbCrLf
   If m_dFontSize <> kFontSize Then _
      strCode = strCode & strName & ".FontSize = " & Str(m_dFontSize) & vbCrLf
   If m_bFontStrikethru Then _
      strCode = strCode & strName & ".FontStrikethru = True" & vbCrLf
   If m_bFontTransparent Then _
      strCode = strCode & strName & ".FontTransparent = True" & vbCrLf
   If m_bFontUnderline Then _
      strCode = strCode & strName & ".FontUnderline = True" & vbCrLf
   If m_vForeColor <> kForeColor Then _
      strCode = strCode & strName & ".ForeColor = " & m_vForeColor & vbCrLf
   If m_strPicture <> "" Then _
      strCode = strCode & strName & ".Picture = """ & m_strPicture & """" & vbCrLf
   If m_nScaleMode <> kScaleMode Then _
      strCode = strCode & strName & ".ScaleMode = " & m_nScaleMode & vbCrLf
   If m_Intrinsic.Tag <> "" And m_Intrinsic.Tag <> "Output" Then _
      strCode = strCode & strName & ".Tag = """ & EnQuote(m_Intrinsic.Tag) & """" & vbCrLf
   If m_strText <> "" Then _
      strCode = strCode & strName & ".Text = """ & EnQuote(m_strText) & """" & vbCrLf
#If NSBasic_Desktop Then
   If m_nAlignX <> kAlignX Then _
      strCode = strCode & strName & ".AlignX = " & m_nAlignX & vbCrLf
   If m_nAlignY <> kAlignY Then _
      strCode = strCode & strName & ".AlignY = " & m_nAlignY & vbCrLf
   If m_nDrawStyle <> kDrawStyle Then _
      strCode = strCode & strName & ".DrawStyle = " & m_nDrawStyle & vbCrLf
   If m_bEnabled <> True Then _
      strCode = strCode & strName & ".Enabled = " & BoolStr(m_bEnabled) & vbCrLf
   If m_nFontWeight <> kFontWeight Then _
      strCode = strCode & strName & ".FontWeight = " & m_nFontWeight & vbCrLf
   If m_strText <> kText Then _
      strCode = strCode & strName & ".Text = """ & EnQuote(m_strText) & """" & vbCrLf
   If m_nTimer <> kTimer Then _
      strCode = strCode & strName & ".Timer = " & m_nTimer & vbCrLf
   If m_Intrinsic.Visible <> True Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Visible = " & BoolStr(m_Intrinsic.Visible) & vbCrLf
#End If
   GenerateCode = strCode
End Function

Public Function PropertyList() As String()
   If Me.Tag = "Output" Then
      PropertyList = Split(kStrOutputList, ",")
   Else
      PropertyList = Split(kStrPropertyList, ",")
   End If
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
   On Error Resume Next
   Set m_Ctl = Nothing
'   If m_Ctl.Tag = "Output" Then Set m_Ctl = Nothing
End Sub

'Add specific properties here
Public Property Get AlignX() As Integer
   AlignX = m_nAlignX
End Property
Public Property Let AlignX(ByVal RHS As Integer)
   m_nAlignX = RHS
End Property

Public Property Get AlignY() As Integer
   AlignY = m_nAlignY
End Property
Public Property Let AlignY(ByVal RHS As Integer)
   m_nAlignY = RHS
End Property

Public Property Get BackColor() As OLE_COLOR
   BackColor = m_vBackColor
End Property
Public Property Let BackColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.BackColor = vNewValue
   m_Ctl.Refresh
   m_vBackColor = m_Ctl.BackColor
End Property

#If NSBasic_Desktop Then
Public Property Get BorderStyle() As Integer
#Else
Public Property Get BorderStyle() As PictureBoxBorderStyle
#End If
   BorderStyle = m_nBorderStyle
End Property
#If NSBasic_Desktop Then
Public Property Let BorderStyle(ByVal vNewValue As Integer)
#Else
Public Property Let BorderStyle(ByVal vNewValue As PictureBoxBorderStyle)
#End If
   vNewValue = CInt(vNewValue) Mod 2
   m_Ctl.BorderStyle = vNewValue
   m_nBorderStyle = m_Ctl.BorderStyle
End Property

Public Property Get DrawStyle() As Integer
   DrawStyle = m_nDrawStyle
End Property
Public Property Let DrawStyle(ByVal RHS As Integer)
   m_nDrawStyle = RHS
End Property

Public Property Get DrawWidth() As Integer
   DrawWidth = m_nDrawWidth
End Property
Public Property Let DrawWidth(ByVal vNewValue As Integer)
   If vNewValue <= 0 Then vNewValue = 1
   m_Ctl.DrawWidth = vNewValue
   m_nDrawWidth = m_Ctl.DrawWidth
End Property

Public Property Get Enabled() As Boolean
   Enabled = m_bEnabled
End Property
Public Property Let Enabled(ByVal RHS As Boolean)
   m_bEnabled = RHS
End Property

Public Property Get FillColor() As OLE_COLOR
   FillColor = m_vFillColor
End Property
Public Property Let FillColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.FillColor = vNewValue
   m_vFillColor = m_Ctl.FillColor
End Property

#If NSBasic_Desktop Then
Public Property Get FillStyle() As Integer
#Else
Public Property Get FillStyle() As PictureBoxFillStyle
#End If
   FillStyle = m_nFillStyle
End Property
#If NSBasic_Desktop Then
Public Property Let FillStyle(ByVal vNewValue As Integer)
#Else
Public Property Let FillStyle(ByVal vNewValue As PictureBoxFillStyle)
#End If
   m_Ctl.FillStyle = vNewValue
   m_nFillStyle = m_Ctl.FillStyle
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
   If vNewValue = 0 Then Exit Property
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

Public Property Get FontTransparent() As Variant
   FontTransparent = m_bFontTransparent
End Property
Public Property Let FontTransparent(ByVal vNewValue As Variant)
   m_Ctl.FontTransparent = vNewValue
   m_bFontTransparent = m_Ctl.FontTransparent
End Property

Public Property Get FontUnderline() As Variant
   FontUnderline = m_bFontUnderline
End Property
Public Property Let FontUnderline(ByVal vNewValue As Variant)
   m_Ctl.FontUnderline = vNewValue
   m_bFontUnderline = m_Ctl.FontUnderline
End Property

Public Property Get FontWeight() As Integer
   FontWeight = m_nFontWeight
End Property
Public Property Let FontWeight(ByVal RHS As Integer)
   m_nFontWeight = RHS
End Property

Public Property Get ForeColor() As OLE_COLOR
   ForeColor = m_vForeColor
End Property
Public Property Let ForeColor(ByVal vNewValue As OLE_COLOR)
   m_Ctl.ForeColor = vNewValue
   m_vForeColor = m_Ctl.ForeColor
End Property

Public Property Get Picture() As String
   Picture = m_strPicture
End Property
Public Property Let Picture(ByVal vNewValue As String)
   'No equivalent
   m_strPicture = vNewValue
End Property

Public Property Get ScaleHeight() As Integer
   ScaleHeight = m_nScaleHeight
End Property
Public Property Let ScaleHeight(ByVal RHS As Integer)
   If RHS <= 0 Then Exit Property
   m_Ctl.ScaleHeight = RHS
   m_nScaleHeight = m_Ctl.ScaleHeight
End Property

Public Property Get ScaleLeft() As Integer
   ScaleLeft = m_nScaleLeft
End Property
Public Property Let ScaleLeft(ByVal RHS As Integer)
   m_Ctl.ScaleLeft = RHS
   m_nScaleLeft = m_Ctl.ScaleLeft
End Property

#If NSBasic_Desktop Then
Public Property Get ScaleMode() As Integer
#Else
Public Property Get ScaleMode() As PictureBoxScaleMode
#End If
   ScaleMode = m_nScaleMode
End Property
#If NSBasic_Desktop Then
Public Property Let ScaleMode(ByVal vNewValue As Integer)
#Else
Public Property Let ScaleMode(ByVal vNewValue As PictureBoxScaleMode)
#End If
   m_Ctl.ScaleMode = vNewValue
   m_nScaleMode = m_Ctl.ScaleMode
End Property

Public Property Get ScaleTop() As Integer
   ScaleTop = m_nScaleTop
End Property
Public Property Let ScaleTop(ByVal RHS As Integer)
   m_Ctl.ScaleTop = RHS
   m_nScaleTop = m_Ctl.ScaleTop
End Property

Public Property Get ScaleWidth() As Integer
   ScaleWidth = m_nScaleWidth
End Property
Public Property Let ScaleWidth(ByVal RHS As Integer)
   If RHS <= 0 Then Exit Property
   m_Ctl.ScaleWidth = RHS
   m_nScaleWidth = m_Ctl.ScaleWidth
End Property

Public Property Get Text() As String
   Text = m_strText
End Property
Public Property Let Text(ByVal vNewValue As String)
   'No equivalent
   m_strText = vNewValue
End Property

Public Property Get Timer() As Integer
   Timer = m_nTimer
End Property
Public Property Let Timer(ByVal RHS As Integer)
   m_nTimer = RHS
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
   m_Ctl.Left = RHS
   m_Intrinsic.Left = m_Ctl.Left
End Property

Public Property Get Top() As Integer
   Top = m_Intrinsic.Top
End Property
Public Property Let Top(ByVal RHS As Integer)
   m_Ctl.Top = RHS
   m_Intrinsic.Top = m_Ctl.Top
End Property

Public Property Get Width() As Integer
   Width = m_Intrinsic.Width
End Property
Public Property Let Width(ByVal RHS As Integer)
   If Not m_Ctl Is Nothing Then
      m_Ctl.Width = IIf(RHS >= 0, RHS, m_Ctl.Width)
      m_Intrinsic.Width = m_Ctl.Width
   Else
      m_Intrinsic.Width = RHS
   End If
End Property

Public Property Get Height() As Integer
   Height = m_Intrinsic.Height
End Property
Public Property Let Height(ByVal RHS As Integer)
   If Not m_Ctl Is Nothing Then
      m_Ctl.Height = IIf(RHS > 0, RHS, 0)
      m_Intrinsic.Height = m_Ctl.Height
   Else
      m_Intrinsic.Height = RHS
   End If
End Property

Public Property Get Tag() As String
   Tag = m_Intrinsic.Tag
End Property
Public Property Let Tag(ByVal RHS As String)
   'All this really does is store the RHS in the Intrinsic tag
   If m_Ctl Is Nothing Then
      m_Intrinsic.Tag = RHS
   Else
      If m_Ctl.Tag = "Output" Then
         m_Intrinsic.Tag = RHS
      Else
         m_Ctl.Tag = RHS
         m_Intrinsic.Tag = m_Ctl.Tag
      End If
   End If
End Property

Public Property Get Visible() As Variant
   Visible = m_Intrinsic.Visible
End Property
Public Property Let Visible(ByVal vNewValue As Variant)
   m_Intrinsic.Visible = vNewValue
End Property

Public Property Get Ctl() As VB.PictureBox
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

Private Sub m_Ctl_DblClick()
   If m_Ctl.Tag = "Output" Then
      ViewCode m_Intrinsic.GlobalID, m_Intrinsic.Name & "_Load"
   Else
      ViewCode m_Intrinsic.GlobalID, m_Intrinsic.Name & "_Click"
   End If
End Sub

Private Sub m_Ctl_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   If Shift <> vbNormal Then Exit Sub
   If m_Ctl.Tag <> "Output" Then
      If Button = vbLeftButton Then
         m_Intrinsic.Form.DragBegin Me
      End If
      If Button = vbRightButton Then
         m_Intrinsic.Form.ShowPopup Me
      End If
   End If
End Sub

Public Sub SetControl(aCtl As VB.PictureBox)
   Set m_Ctl = aCtl
   m_Ctl.BackColor = m_vBackColor
   m_Ctl.DrawWidth = m_nDrawWidth
   m_Ctl.FillColor = m_vFillColor
   m_Ctl.FillStyle = m_nFillStyle
   m_Ctl.FontBold = m_bFontBold
   m_Ctl.FontItalic = m_bFontItalic
   m_Ctl.FontName = m_strFontName
   m_Ctl.FontSize = m_dFontSize
   m_Ctl.FontStrikethru = m_bFontStrikethru
   m_Ctl.FontTransparent = m_bFontTransparent
   m_Ctl.FontUnderline = m_bFontUnderline
   m_Ctl.ForeColor = m_vForeColor
'   m_Ctl.Height = m_Intrinsic.Height
'   m_Ctl.Left = m_Intrinsic.Left
'   m_Ctl.Picture = m_strPicture
'   m_Ctl.ScaleMode = m_nScaleMode
'Text
'   m_Ctl.Top = m_Intrinsic.Top
'   m_Ctl.Width = m_Intrinsic.Width
End Sub

Public Property Get CEType() As String
   If Tag = "Output" Then
      CEType = "Output"
   Else
      CEType = kStrTypeName
   End If
End Property
