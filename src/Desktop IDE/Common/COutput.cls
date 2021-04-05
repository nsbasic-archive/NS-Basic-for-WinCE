VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "COutput"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Private m_Output As CPictureBox

Public Property Get Output() As CPictureBox
   Set Output = m_Output
End Property
Public Property Let Output(pb As CPictureBox)
   Set m_Output = pb
End Property

Public Property Let BackColor(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.BackColor = vNewValue
End Property

Public Property Let BorderStyle(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   vNewValue = CInt(vNewValue) Mod 2
   m_Output.BorderStyle = vNewValue
End Property

Public Property Let DrawWidth(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.DrawWidth = vNewValue
End Property

Public Property Let FillColor(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FillColor = vNewValue
End Property

Public Property Let FillStyle(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FillStyle = vNewValue
End Property

Public Property Let FontBold(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontBold = vNewValue
End Property

Public Property Let FontItalic(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontItalic = vNewValue
End Property

Public Property Let FontName(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontName = vNewValue
End Property

Public Property Let FontSize(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontSize = vNewValue
End Property

Public Property Let FontStrikethru(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontStrikethru = vNewValue
End Property

Public Property Let FontTransparent(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontTransparent = vNewValue
End Property

Public Property Let FontUnderline(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.FontUnderline = vNewValue
End Property

Public Property Let ForeColor(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.ForeColor = vNewValue
End Property

Public Property Let Picture(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.Picture = vNewValue
End Property

Public Property Let ScaleMode(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.ScaleMode = vNewValue
End Property

Public Property Let Tag(vNewValue As Variant)
'   If m_Output Is Nothing Then Exit Property
   m_Output.Tag = vNewValue
End Property

Public Property Get Width() As Integer
   Width = m_Output.Width
End Property

Public Property Get Height() As Integer
   Height = m_Output.Height
End Property
