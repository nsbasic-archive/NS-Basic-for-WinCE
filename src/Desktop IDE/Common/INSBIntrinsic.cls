VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "INSBIntrinsic"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Form As frmScreen
Public Object As Object
Public Name As String
Public Left As Integer
Public Top As Integer
Public Width As Integer
Public Height As Integer
Public Tag As String
Public TabDown As String
Public TabLeft As String
Public TabRight As String
Public TabUp As String
Public Visible As Boolean
Public GlobalID As String
Private m_strPropertyList As String

Public Function PropertyList() As String()
End Function

Public Function GetProperty(ByVal astrProperty As String, ByRef pvPropVal As Variant) As EXPROPERTIESLISTLibCtl.EditTypeEnum
   Select Case astrProperty
   Case "Name": pvPropVal = Name: GetProperty = Edit
   Case "Alignment": pvPropVal = Object.Alignment: GetProperty = EditEnum
   Case "AlignX": pvPropVal = Object.AlignX: GetProperty = Edit
   Case "AlignY": pvPropVal = Object.AlignY: GetProperty = Edit
   Case "Appearance": pvPropVal = Object.Appearance: GetProperty = EditEnum
   Case "BackColor": pvPropVal = Object.BackColor: GetProperty = EditColor
   Case "BorderStyle": pvPropVal = Object.BorderStyle: GetProperty = EditEnum
   Case "Caption": pvPropVal = Object.Caption: GetProperty = Edit
   Case "CaptionColor": pvPropVal = Object.CaptionColor: GetProperty = EditColor
   Case "DrawStyle": pvPropVal = Object.DrawStyle: GetProperty = EditEnum
   Case "DrawWidth": pvPropVal = Object.DrawWidth: GetProperty = Edit
   Case "Enabled": pvPropVal = Object.Enabled: GetProperty = EditBoolean
   Case "ExpandedHeight": pvPropVal = Object.ExpandedHeight: GetProperty = Edit
   Case "FillColor": pvPropVal = Object.FillColor: GetProperty = EditColor
   Case "FillStyle": pvPropVal = Object.FillStyle: GetProperty = EditEnum
   Case "FontBold": pvPropVal = Object.FontBold: GetProperty = EditBoolean
   Case "FontItalic": pvPropVal = Object.FontItalic: GetProperty = EditBoolean
   Case "FontName": pvPropVal = Object.FontName: GetProperty = EditFontName
   Case "FontSize": pvPropVal = Object.FontSize: GetProperty = Edit
   Case "FontStrikethru": pvPropVal = Object.FontStrikethru: GetProperty = EditBoolean
   Case "FontTransparent": pvPropVal = Object.FontTransparent: GetProperty = EditBoolean
   Case "FontUnderline": pvPropVal = Object.FontUnderline: GetProperty = EditBoolean
   Case "FontWeight": pvPropVal = Object.FontWeight: GetProperty = Edit
   Case "ForeColor": pvPropVal = Object.ForeColor: GetProperty = EditColor
   Case "GradientColor1": pvPropVal = Object.GradientColor1: GetProperty = EditColor
   Case "GradientColor2": pvPropVal = Object.GradientColor2: GetProperty = EditColor
   Case "GradientStyle": pvPropVal = Object.GradientStyle: GetProperty = EditEnum
   Case "Group": pvPropVal = Object.Group: GetProperty = EditBoolean
   Case "Height": pvPropVal = Height: GetProperty = Edit
   Case "LargeChange": pvPropVal = Object.LargeChange: GetProperty = Edit
   Case "Left": pvPropVal = Left: GetProperty = Edit
   Case "Locked": pvPropVal = Object.Locked: GetProperty = EditBoolean
   Case "LowercaseOnly": pvPropVal = Object.LowercaseOnly: GetProperty = EditBoolean
   Case "Max": pvPropVal = Object.Max: GetProperty = Edit
   Case "MaxLength": pvPropVal = Object.MaxLength: GetProperty = Edit
   Case "Min": pvPropVal = Object.Min: GetProperty = Edit
   Case "Multiline": pvPropVal = Object.Multiline: GetProperty = EditBoolean
   Case "MultiSelect": pvPropVal = Object.MultiSelect: GetProperty = EditBoolean
   Case "NumbersOnly": pvPropVal = Object.NumbersOnly: GetProperty = EditBoolean
   Case "Password": pvPropVal = Object.Password: GetProperty = EditBoolean
   Case "Picture":
      #If NSBasic_Desktop Then
         pvPropVal = Object.Picture: GetProperty = EditFile
      #Else
         pvPropVal = Object.Picture: GetProperty = Edit
      #End If
   Case "ScaleHeight": pvPropVal = Object.ScaleHeight: GetProperty = Edit
   Case "ScaleLeft": pvPropVal = Object.ScaleLeft: GetProperty = Edit
   Case "ScaleMode": pvPropVal = Object.ScaleMode: GetProperty = Edit
   Case "ScaleTop": pvPropVal = Object.ScaleTop: GetProperty = Edit
   Case "ScaleWidth": pvPropVal = Object.ScaleWidth: GetProperty = Edit
   Case "Scrollbars": pvPropVal = Object.Scrollbars: GetProperty = Edit
'   Case "SmallChange": pvPropVal = Object.SmallChange: GetProperty = Edit
   Case "TabStop": pvPropVal = Object.TabStop: GetProperty = EditBoolean
   Case "TabDown": pvPropVal = Object.TabDown: GetProperty = Edit
   Case "TabLeft": pvPropVal = Object.TabLeft: GetProperty = Edit
   Case "TabRight": pvPropVal = Object.TabRight: GetProperty = Edit
   Case "TabUp": pvPropVal = Object.TabUp: GetProperty = Edit
   Case "Tag": pvPropVal = Object.Tag: GetProperty = Edit
   Case "Text": pvPropVal = Object.Text: GetProperty = Edit
   'Case "Timer": pvPropVal = Object.Timer: GetProperty = Edit
   Case "Top": pvPropVal = Top: GetProperty = Edit
   Case "UppercaseOnly": pvPropVal = Object.UppercaseOnly: GetProperty = EditBoolean
   Case "Width": pvPropVal = Width: GetProperty = Edit
   Case "Value": pvPropVal = Object.Value: GetProperty = EditBoolean
   Case "Visible": pvPropVal = Visible: GetProperty = EditBoolean
   Case "IntegralHeight": pvPropVal = Object.IntegralHeight: GetProperty = EditBoolean
   Case "Sorted": pvPropVal = Object.Sorted: GetProperty = EditBoolean
   Case "SpinBox": pvPropVal = Object.SpinBox: GetProperty = EditBoolean
   Case "Style": pvPropVal = Object.Style: GetProperty = Edit
   Case "LongFormat": pvPropVal = Object.LongFormat: GetProperty = EditBoolean
   Case Else
      'Debug.Print "INSBIntrinsic", "Missing GetProperty", astrProperty
   End Select
End Function

Public Function SetProperty(ByVal astrProperty As String, ByVal avNewValue As Variant) As Variant
   Select Case astrProperty
   Case "Name": Object.Name = avNewValue
   Case "Alignment": Object.Alignment = Val(avNewValue)
   Case "AlignX": Object.AlignX = Val(avNewValue)
   Case "AlignY": Object.AlignY = Val(avNewValue)
   Case "Appearance": Object.Appearance = Val(avNewValue)
   Case "BackColor": Object.BackColor = avNewValue
   Case "BorderStyle": Object.BorderStyle = Val(avNewValue)
   Case "Caption": Object.Caption = avNewValue
   Case "CaptionColor": Object.CaptionColor = avNewValue
   Case "DrawStyle": Object.DrawStyle = Val(avNewValue)
   Case "DrawWidth": Object.DrawWidth = Val(avNewValue)
   Case "Enabled": Object.Enabled = CBool(avNewValue)
   Case "ExpandedHeight": Object.ExpandedHeight = Val(avNewValue)
   Case "FillColor": Object.FillColor = avNewValue
   Case "FillStyle": Object.FillStyle = Val(avNewValue)
   Case "FontBold": Object.FontBold = CBool(avNewValue)
   Case "FontItalic": Object.FontItalic = CBool(avNewValue)
   Case "FontName": Object.FontName = avNewValue
   Case "FontSize": If Val(avNewValue) > 0 And Val(avNewValue) < 200 Then Object.FontSize = Val(avNewValue)
   Case "FontStrikethru": Object.FontStrikethru = CBool(avNewValue)
   Case "FontTransparent": Object.FontTransparent = CBool(avNewValue)
   Case "FontUnderline": Object.FontUnderline = CBool(avNewValue)
   Case "FontWeight": Object.FontWeight = Val(avNewValue)
   Case "ForeColor": Object.ForeColor = avNewValue
   Case "GradientColor1": Object.GradientColor1 = Val(avNewValue)
   Case "GradientColor2": Object.GradientColor2 = Val(avNewValue)
   Case "GradientStyle": Object.GradientStyle = Val(avNewValue)
   Case "FontWeight": Object.FontWeight = Val(avNewValue)
   Case "FontWeight": Object.FontWeight = Val(avNewValue)
   Case "LongFormat": Object.LongFormat = CBool(avNewValue)
   Case "Group": Object.Group = CBool(avNewValue)
   Case "Height": Object.Height = Val(avNewValue)
   Case "IntegralHeight": Object.IntegralHeight = CBool(avNewValue)
   Case "LargeChange": Object.LargeChange = Val(avNewValue)
   Case "Left": Object.Left = Val(avNewValue)
   Case "Locked": Object.Locked = CBool(avNewValue)
   Case "LowercaseOnly": Object.LowercaseOnly = CBool(avNewValue)
   Case "Max": Object.Max = Val(avNewValue)
   Case "MaxLength": Object.MaxLength = Val(avNewValue)
   Case "Min": Object.Min = Val(avNewValue)
   Case "Multiline": Object.Multiline = CBool(avNewValue)
   Case "MultiSelect": Object.MultiSelect = CBool(avNewValue)
   Case "NumbersOnly": Object.NumbersOnly = CBool(avNewValue)
   Case "Password": Object.Password = CBool(avNewValue)
   Case "Picture": Object.Picture = avNewValue
   Case "ScaleHeight": Object.ScaleHeight = Val(avNewValue)
   Case "ScaleLeft": Object.ScaleLeft = Val(avNewValue)
   Case "ScaleMode": Object.ScaleMode = Val(avNewValue)
   Case "ScaleTop": Object.ScaleTop = Val(avNewValue)
   Case "ScaleWidth": Object.ScaleWidth = Val(avNewValue)
   Case "Scrollbars": Object.Scrollbars = Val(avNewValue)
   Case "Sorted": Object.Sorted = CBool(avNewValue)
   Case "SpinBox": Object.SpinBox = CBool(avNewValue)
   Case "Style": Object.Style = Val(avNewValue)
   Case "TabStop": Object.TabStop = CBool(avNewValue)
   Case "TabDown": Object.TabDown = avNewValue
   Case "TabLeft": Object.TabLeft = avNewValue
   Case "TabRight": Object.TabRight = avNewValue
   Case "TabUp": Object.TabUp = avNewValue
   Case "Tag":
      Object.Tag = avNewValue
   Case "Text": Object.Text = avNewValue
   'Case "Timer": Object.Timer = Val(avNewValue)
   Case "Top": Object.Top = Val(avNewValue)
   Case "UppercaseOnly": Object.UppercaseOnly = CBool(avNewValue)
   Case "Value": Object.Value = CBool(avNewValue)
   Case "Visible": Visible = CBool(avNewValue)
   Case "Width": Object.Width = Val(avNewValue)
   Case Else
      'Debug.Print "INSBIntrinsic", "Missing SetProperty", astrProperty
   End Select
   GetProperty astrProperty, SetProperty
   gTarget.Dirty = True
End Function

Public Function AddObject(astrType As String, astrName As String, X As Integer, Y As Integer, W As Integer, H As Integer) As Object
Dim propList() As String
Dim i As Integer
Dim propVal As Variant

   propList = Object.PropertyList
   For i = 0 To UBound(propList)
      GetProperty propList(i), propVal
      SetProperty propList(i), propVal
   Next
End Function

Public Sub Move(ByVal X As Long, ByVal Y As Long, ByVal W As Long, ByVal H As Long)
   With Object
      .Left = X
      .Top = Y
      .Width = W
      .Height = H
   End With
   If Not Form Is Nothing Then Form.ShowHandles
End Sub

Public Function GenerateCode(kOb As String) As String
End Function
