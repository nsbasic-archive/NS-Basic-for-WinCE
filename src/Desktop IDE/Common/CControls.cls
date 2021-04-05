VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CControls"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Collection" ,"CProperty"
Attribute VB_Ext_KEY = "Member0" ,"CProperty"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

'local variable to hold collection
Private mCol As New Collection

Public Function Add(ctrl As Object) As Object ', Optional sKey As String) As CControl
   'set the properties passed into the method
'   If IsObject(Value) Then
'      Set ctrl.Value = Value
'   Else
'      ctrl.Value = Value
'   End If
'   'objNewMember.Name = Name

'   If Len(sKey) = 0 Then
'      mCol.Add ctrl, ctrl.Name
'   Else
'      mCol.Add ctrl, sKey
'   End If

   mCol.Add ctrl
   'return the object
   Set Add = ctrl
End Function

Public Property Get Item(nIndex As Integer) As Object
Attribute Item.VB_UserMemId = 0
   Set Item = mCol(nIndex)
End Property

Public Property Get Count() As Long
   Count = mCol.Count
End Property

Public Sub Remove(nIndex As Integer)
   mCol.Remove nIndex
End Sub

Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
   Set NewEnum = mCol.[_NewEnum]
End Property
