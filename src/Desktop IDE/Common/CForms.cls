VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CForms"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Collection" ,"CForm"
Attribute VB_Ext_KEY = "Member0" ,"CForm"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

'local variable to hold collection
Private mCol As New Collection

''Public Function Add(FormName As String, FormOutput As Object, FormDefault As Boolean, Optional sKey As String) As CForm
''Dim frm As New CForm
''
''   'set the properties passed into the method
''   frm.FormName = FormName
''   If IsObject(FormOutput) Then
''      Set frm.FormOutput = FormOutput
''   Else
''      frm.FormOutput = FormOutput
''   End If
''   frm.CurrentForm = True
''   frm.FormDefault = FormDefault
''   If Len(sKey) = 0 Then
''      mCol.Add frm
''   Else
''      mCol.Add frm, sKey
''   End If
''
''   'return the object created
''   Set Add = frm
''End Function

Public Sub Add(frm As CForm, Optional sKey As String)
   If Len(sKey) = 0 Then
      mCol.Add frm
   Else
      mCol.Add frm, sKey
   End If
End Sub

Public Property Get Item(vntIndexKey As Variant) As CForm
Attribute Item.VB_UserMemId = 0
   On Error Resume Next
   Set Item = mCol(vntIndexKey)
End Property

Public Property Get Count() As Long
   Count = mCol.Count
End Property

Public Sub Remove(vntIndexKey As Variant)
   mCol.Remove vntIndexKey
End Sub

Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
   Set NewEnum = mCol.[_NewEnum]
End Property

''Public Property Get CurrentForm() As Variant
''Dim frm As CForm
''
''   For Each frm In mCol
''      If frm.CurrentForm Then
''         Set CurrentForm = frm
''         Exit For
''      End If
''   Next
''End Property
