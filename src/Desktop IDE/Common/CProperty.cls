VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CProperty"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

Private m_strName As String
Private m_nReturnType As Integer
Private m_vValue As Variant
Private m_vDefaultValue As Variant

Public Property Get Changed() As Boolean
   Changed = m_vDefaultValue <> m_vValue
End Property

Public Property Get Value() As Variant
   Value = m_vValue
End Property
Public Property Let Value(ByVal vNewValue As Variant)
   If InStr(m_strName, "Color") > 0 Then
      m_vValue = CStr(TranslateColor(vNewValue))
   Else
      m_vValue = vNewValue
   End If
End Property

Public Property Get DefaultValue() As Variant
   DefaultValue = m_vDefaultValue
End Property
Public Property Let DefaultValue(ByVal vNewValue As Variant)
   If InStr(m_strName, "Color") > 0 Then
      m_vDefaultValue = CStr(TranslateColor(vNewValue))
   Else
      m_vDefaultValue = vNewValue
   End If
End Property

Public Property Get ReturnType() As Integer
   ReturnType = m_nReturnType
End Property
Public Property Let ReturnType(ByVal nNewValue As Integer)
   m_nReturnType = nNewValue
End Property

Public Property Get Name() As String
   Name = m_strName
End Property
Public Property Let Name(ByVal vNewValue As String)
   m_strName = vNewValue
End Property
