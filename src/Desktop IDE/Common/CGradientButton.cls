VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CGradientButton"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Intrinsic As New INSBIntrinsic
#If NSBasic_CE Then
Private Const kStrPropertyList As String = "Name,Alignment,BorderStyle,Caption,CaptionColor,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,GradientColor1,GradientColor2,GradientStyle,Height,Left,Top,Visible,Width"
Private Const kStrMethodList As String = "Cls,DrawCircle,DrawLine,DrawPicture,DrawPoint,DrawText,Refresh,ScaleX,ScaleY,SetScale,TextHeight,TextWidth,Hide,Move,SetFocus,Show"
#End If
#If NSBasic_Desktop Then
Private Const kStrPropertyList As String = "Name,Alignment,BorderStyle,Caption,CaptionColor,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,GradientColor1,GradientColor2,GradientStyle,Height,Left,Top,Visible,Width"
Private Const kStrMethodList As String = "Cls,DrawCircle,DrawLine,DrawPicture,DrawPoint,DrawText,Refresh,ScaleX,ScaleY,SetScale,TextHeight,TextWidth,Hide,Move,SetFocus,Show"
#End If
#If NSBasic_X Then
Private Const kStrPropertyList As String = "Name,Alignment,BorderStyle,Caption,CaptionColor,Enabled,FontBold,FontItalic,FontName,FontSize,FontStrikethru,FontUnderline,GradientColor1,GradientColor2,GradientStyle,Height,Left,Top,Visible,Width"
Private Const kStrMethodList As String = "Cls,DrawCircle,DrawLine,DrawPicture,DrawPoint,DrawText,Refresh,ScaleX,ScaleY,SetScale,TextHeight,TextWidth,Hide,Move,SetFocus,Show"
#End If
Private Const kStrTypeName As String = "GradientButton"
Private Const kStrClassID As String = "VB.PictureBox"

'Module level variables
Private WithEvents m_Ctl As VB.PictureBox
Attribute m_Ctl.VB_VarHelpID = -1

'Add member variables here for control specific properties
Private m_nAlignment As Integer
Private m_strCaption As String
Private m_vCaptionColor As OLE_COLOR
Private m_bEnabled As Boolean
Private m_bFontBold As Boolean
Private m_bFontItalic As Boolean
Private m_strFontName As String
Private m_dFontSize As Double
Private m_bFontStrikethru As Boolean
Private m_bFontTransparent As Boolean
Private m_bFontUnderline As Boolean
Private m_vGradientColor1 As OLE_COLOR
Private m_vGradientColor2 As OLE_COLOR
Private m_nGradientStyle As Integer
Private m_bVisible As Boolean
Private m_nBorderStyle As Integer

'Constants for default property values
Private Const kAlignment As Integer = 2
Private Const kCaption As String = "OK"
Private Const kCaptionColor As Long = vbWhite
Private Const kEnabled As Boolean = True
Private Const kFillColor As Long = vbBlack
Private Const kFontName As String = "Tahoma"
Private Const kFontSize As Double = 8
Private Const kGradientColor1 = &HFFFF80 'light blue
Private Const kGradientColor2 = &HFF0000 'dark blue
Private Const kGradientStyle = 1
Private Const kVisible As Boolean = True
Private Const kBorderStyle As Integer = 0

Private Sub Class_Initialize()
   Set m_Intrinsic.Object = Me
   'Initialize property member variables here
   m_nAlignment = kAlignment
   m_nBorderStyle = kBorderStyle
   m_strCaption = kCaption
   m_vCaptionColor = kCaptionColor
   m_bEnabled = kEnabled
   m_vGradientColor1 = kGradientColor1
   m_vGradientColor2 = kGradientColor2
   m_nGradientStyle = kGradientStyle
   m_strFontName = kFontName
   m_dFontSize = kFontSize
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
      m_Intrinsic.Visible = True    'gh
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
CreateGradientButtonResource

   q = Chr(34)
   qq = Chr(34) & " & chr(34) & " & Chr(34)
   
   #If NSBasic_Desktop Then
   If Left(kOb, 1) = " " Then
      strCode = "      AddObject ""GradientButton"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & vbCrLf
      strName = "      " & kOb
   Else
      strCode = "      AddObject ""GradientButton"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & ", " & kOb & vbCrLf
      If m_nBorderStyle <> kBorderStyle Then _
         strCode = strCode & "      " & m_Intrinsic.Name & ".BorderStyle = " & m_nBorderStyle & vbCrLf
      strName = "      " & m_Intrinsic.Name
   End If
   strCode = strCode & strName & ".ResourceFile = Mid(GetCommandLine, 2, InstrRev(GetCommandLine,chr(34))-2 )" & vbCrLf
   #End If
   
   #If NSBasic_CE Then
   If Left(kOb, 1) = " " Then
      strCode = "      AddObject ""GradientButton"", """ & m_Intrinsic.Name & """, " & m_Intrinsic.Left & ", " & m_Intrinsic.Top & ", " & m_Intrinsic.Width & ", " & m_Intrinsic.Height & vbCrLf
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
   strCode = strCode & strName & ".ResourceFile = GetCommandLine" & vbCrLf
   #End If
   
   strCode = strCode & strName & ".ResourceBitmapIDstr = " & q & UCase(m_Intrinsic.Name) & q & vbCrLf
   
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
   If m_Intrinsic.Visible <> True Then _
      strCode = strCode & "      " & m_Intrinsic.Name & ".Visible = " & BoolStr(m_Intrinsic.Visible) & vbCrLf
   strCode = strCode & strName & ".CommandButton = True" & vbCrLf
   strCode = strCode & strName & ".Caption = """" " & vbCrLf
   strCode = strCode & strName & ".Tag = """ & getMetaData & """"""" & vbCrLf"
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
   'RedrawGradientButton
End Function

Public Sub Move(ByVal X As Long, ByVal Y As Long, ByVal W As Long, ByVal H As Long)
   m_Intrinsic.Move X, Y, W, H
End Sub

Public Sub Unload()
   Set m_Intrinsic.Form = Nothing
   On Error Resume Next
   Set m_Ctl = Nothing
End Sub

'Add specific properties here
Public Property Get Alignment() As Integer
   Alignment = m_nAlignment
End Property
Public Property Let Alignment(ByVal RHS As Integer)
   m_nAlignment = RHS
   RedrawGradientButton
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

Public Property Get Caption() As String
   Caption = m_strCaption
End Property
Public Property Let Caption(ByVal vNewValue As String)
   m_strCaption = vNewValue
   RedrawGradientButton
End Property

Public Property Get CaptionColor() As OLE_COLOR
   CaptionColor = m_vCaptionColor
End Property
Public Property Let CaptionColor(ByVal vNewValue As OLE_COLOR)
   'm_Ctl.CaptionColor = vNewValue
   m_vCaptionColor = vNewValue
   RedrawGradientButton
End Property

Public Property Get Enabled() As Boolean
   Enabled = m_bEnabled
End Property
Public Property Let Enabled(ByVal RHS As Boolean)
   m_bEnabled = RHS
End Property

Public Property Get FontBold() As Variant
   FontBold = m_bFontBold
End Property
Public Property Let FontBold(ByVal vNewValue As Variant)
   m_Ctl.FontBold = vNewValue
   m_bFontBold = m_Ctl.FontBold
   RedrawGradientButton
End Property

Public Property Get FontItalic() As Variant
   FontItalic = m_bFontItalic
End Property
Public Property Let FontItalic(ByVal vNewValue As Variant)
   m_Ctl.FontItalic = vNewValue
   m_bFontItalic = m_Ctl.FontItalic
   RedrawGradientButton
End Property

Public Property Get FontName() As Variant
   FontName = m_strFontName
End Property
Public Property Let FontName(ByVal vNewValue As Variant)
   m_Ctl.FontName = vNewValue
   m_strFontName = m_Ctl.FontName
   RedrawGradientButton
End Property

Public Property Get FontSize() As Variant
   FontSize = m_dFontSize
End Property
Public Property Let FontSize(ByVal vNewValue As Variant)
   If vNewValue = 0 Then Exit Property
   m_Ctl.FontSize = vNewValue
   m_dFontSize = m_Ctl.FontSize
   RedrawGradientButton
End Property

Public Property Get FontStrikethru() As Variant
   FontStrikethru = m_bFontStrikethru
End Property
Public Property Let FontStrikethru(ByVal vNewValue As Variant)
   m_Ctl.FontStrikethru = vNewValue
   m_bFontStrikethru = m_Ctl.FontStrikethru
   RedrawGradientButton
End Property

Public Property Get FontTransparent() As Variant
   FontTransparent = m_bFontTransparent
End Property
Public Property Let FontTransparent(ByVal vNewValue As Variant)
   m_Ctl.FontTransparent = vNewValue
   m_bFontTransparent = m_Ctl.FontTransparent
   RedrawGradientButton
End Property

Public Property Get FontUnderline() As Variant
   FontUnderline = m_bFontUnderline
End Property
Public Property Let FontUnderline(ByVal vNewValue As Variant)
   m_Ctl.FontUnderline = vNewValue
   m_bFontUnderline = m_Ctl.FontUnderline
   RedrawGradientButton
End Property

Public Property Get GradientColor1() As OLE_COLOR
   GradientColor1 = m_vGradientColor1
End Property
Public Property Let GradientColor1(ByVal vNewValue As OLE_COLOR)
   If vNewValue >= 0 Then m_vGradientColor1 = vNewValue
   RedrawGradientButton
End Property

Public Property Get GradientColor2() As OLE_COLOR
   GradientColor2 = m_vGradientColor2
End Property
Public Property Let GradientColor2(ByVal vNewValue As OLE_COLOR)
   If vNewValue >= 0 Then m_vGradientColor2 = vNewValue
   RedrawGradientButton
End Property

Public Property Get GradientStyle() As Integer
   GradientStyle = m_nGradientStyle
End Property
Public Property Let GradientStyle(ByVal RHS As Integer)
   If RHS < 0 Or RHS > 1 Then Exit Property
   m_nGradientStyle = RHS
   RedrawGradientButton
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
   Dim Properties() As String
   Dim p As Variant
   Dim propName As String
   Dim propVal As String
   
   Properties = Split(RHS, "|")
   For Each p In Properties
      If Len(p) > 3 Then
         propName = Left(p, InStr(p, "=") - 1)
         propVal = Mid(p, InStr(p, "=") + 1)
         Select Case propName
         Case "Alignment": Alignment = propVal
         Case "Caption": Caption = propVal
         Case "CaptionColor": CaptionColor = propVal
         Case "GradientColor1": GradientColor1 = propVal
         Case "GradientColor2": GradientColor2 = propVal
         Case "GradientStyle": GradientStyle = propVal
         End Select
      End If
   Next

   'All this really does is store the RHS in the Intrinsic tag
   If m_Ctl Is Nothing Then
      m_Intrinsic.Tag = RHS
   Else
         m_Ctl.Tag = RHS
         m_Intrinsic.Tag = m_Ctl.Tag
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
   ViewCode m_Intrinsic.GlobalID, m_Intrinsic.Name & "_Click"
End Sub

Private Sub m_Ctl_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   If Shift <> vbNormal Then Exit Sub
   If Button = vbLeftButton Then
      m_Intrinsic.Form.DragBegin Me
   End If
End Sub

Public Sub SetControl(aCtl As VB.PictureBox)
   Set m_Ctl = aCtl
   m_Ctl.FontBold = m_bFontBold
   m_Ctl.FontItalic = m_bFontItalic
   m_Ctl.FontName = m_strFontName
   m_Ctl.FontSize = m_dFontSize
   m_Ctl.FontStrikethru = m_bFontStrikethru
   m_Ctl.FontTransparent = m_bFontTransparent
   m_Ctl.FontUnderline = m_bFontUnderline
End Sub

Public Property Get CEType() As String
      CEType = kStrTypeName
End Property

'These properties are useful at runtime only, where GradientButton is a picturebox.
Public Property Let resourceFile(s As String)
End Property
Public Property Let resourceBitmapIDstr(s As String)
End Property
Public Property Let commandButton(s As String)
End Property


Public Sub RedrawGradientButton()
   Dim W As Integer
   Dim H As Integer

   m_Ctl.Cls
   DrawGradient m_Ctl.hDC, m_Ctl.Width, m_Ctl.Height, GradientColor1, GradientColor2, GradientStyle
   m_Ctl.ForeColor = CaptionColor
   W = m_Ctl.TextWidth(Caption) / 15
   H = m_Ctl.TextHeight(Caption) / 15
   m_Ctl.CurrentY = (m_Ctl.Height / 2) - (H / 2)
   If Alignment = 0 Then m_Ctl.CurrentX = 5
   If Alignment = 1 Then m_Ctl.CurrentX = m_Ctl.Width - 5 - W
   If Alignment = 2 Then m_Ctl.CurrentX = (m_Ctl.Width / 2) - (W / 2)
   m_Ctl.CurrentY = m_Ctl.CurrentY * 15
   m_Ctl.CurrentX = m_Ctl.CurrentX * 15
   m_Ctl.Print Caption

End Sub

Private Sub m_Ctl_Paint()
   RedrawGradientButton
End Sub

Private Function getMetaData()
'Returns a string with properties that GradientButtons have, which are not in PictureBox
Dim s As String

s = "CEType=GradientButton|"
s = s & "Alignment=" & Alignment & "|"
s = s & "Caption=" & Caption & "|"
s = s & "CaptionColor=" & CaptionColor & "|"
s = s & "GradientColor1=" & GradientColor1 & "|"
s = s & "GradientColor2=" & GradientColor2 & "|"
s = s & "GradientStyle=" & GradientStyle & "|"
getMetaData = s

End Function

Private Function CreateGradientButtonResource()
'This function creates a form with the Gradient button on it,
'captures the image, writes it to a file,
'then adds the resource name to the list of resources to injected.
Dim filename As String
Dim W As Integer
Dim H As Integer
Dim frm As New frmScratchPad
Dim res As Integer

   'create the form
   'frm.Height = Height
   'frm.Width = Width
   frm.Show

   'create the GradientButton
   Dim obj As Control
   Set obj = frm.Controls.Add("VB.PictureBox", "Obj", frm)
   obj.Visible = True
   obj.ScaleMode = vbPixels
   obj.Left = 0
   obj.Top = 0
   obj.Width = Width
   obj.Height = Height
   obj.FontBold = FontBold
   obj.FontName = FontName
   obj.FontSize = FontSize
   obj.FontUnderline = FontUnderline
   obj.FontItalic = FontItalic
   obj.FontStrikethru = FontStrikethru
   obj.ForeColor = CaptionColor
   obj.Cls
   obj.BorderStyle = BorderStyle
   obj.AutoRedraw = True
   DrawGradient obj.hDC, Width, Height, GradientColor1, GradientColor2, GradientStyle
   obj.ForeColor = CaptionColor
   W = obj.TextWidth(Caption)
   H = obj.TextHeight(Caption)
   obj.CurrentY = (obj.Height / 2) - (H / 2)
   If Alignment = 0 Then obj.CurrentX = 5
   If Alignment = 1 Then obj.CurrentX = obj.Width - 5 - W
   If Alignment = 2 Then obj.CurrentX = (obj.Width / 2) - (W / 2)
   obj.CurrentY = obj.CurrentY
   obj.CurrentX = obj.CurrentX
   obj.Print Caption
   DoEvents
   
   'Capture the image and write to a file
   Set obj.Picture = CaptureWindow(obj.hWnd, True, 0, 0, Width, Height)
   filename = gTarget.Name & "_" & m_Intrinsic.Name & ".bmp"
   SavePicture obj.Picture, filename
   'Debug.Print filename & " saved."
   
   'Put the button on the list to be injected as a resource
   gTarget.GradientButtons = gTarget.GradientButtons & m_Intrinsic.Name & "|"
   
   'clean up
   frm.Controls.Remove "obj"
   frm.Unloadx
   
   Set frm = Nothing
End Function
