VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CModule"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Private m_strGlobalID As String
Private m_strPathName As String  'relative path to project
Private m_bSaved As Boolean
Private m_strCode As String
Public NSB_FileFormat As nsbFileFormat
Private m_strName As String
Public Dirty As Boolean

Public Sub Save()
Dim res As Integer

   'New module this session, never been saved to file
   If m_strPathName = "" Then
      m_strPathName = m_strName & ".bas"
      frmMain.SaveModuleAs GlobalID
      If Mid(gProjectDir, 2, 1) = ":" Then ChDrive Left(gProjectDir, 2) 'ignore network drives
      If gProjectDir <> "" Then ChDir gProjectDir
      Exit Sub
   End If

   res = WriteFile(m_strCode, m_strPathName, 0, nsbFFtext)
   If res <= 0 Then
      MsgBox gStringTable(3463) & res '"Save Error "
   End If
End Sub

Public Function OpenModule(strName As String, strFileName As String) As Boolean
   OpenModule = True
   Name = strName

   If strName = "main" Then
      m_strPathName = strFileName
      Exit Function
   End If

   If strFileName <> "" Then
      'Decrypt the file
      NSB_FileFormat = ReadFile(strFileName, m_strCode, 0)
      If NSB_FileFormat < nsbFFtext Then
         OpenModule = False
         Exit Function
      End If

      'If file is valid, set project properties
      m_strPathName = strFileName
      m_bSaved = True
   End If
End Function

Public Function PropertyList() As String()
#If NSBasic_CE Then
   PropertyList = Split("Name,Path", ",")
#End If
#If NSBasic_Desktop Then
   PropertyList = Split("Name,Path", ",")
#End If
End Function

Public Function GetProperty(ByVal astrProperty As String, ByRef pvPropVal As Variant) As EXPROPERTIESLISTLibCtl.EditTypeEnum
   Select Case astrProperty
   Case "Name": GetProperty = EXPROPERTIESLISTLibCtl.Edit: pvPropVal = m_strName
   Case "Path": GetProperty = EXPROPERTIESLISTLibCtl.ReadOnly: pvPropVal = Path
   End Select
End Function

Public Function SetProperty(astrProperty As String, ByVal vNewValue As Variant) As Variant
   Select Case astrProperty
   Case "Name": m_strName = vNewValue
   Case "Path"
   End Select
   GetProperty astrProperty, SetProperty
End Function

Public Function GetCode(ByVal strCode As String, Optional bNull As Boolean) As String
   GetCode = m_strCode
   If GetCode = "" Then GetCode = vbCrLf
End Function
Public Sub SetCode(ByVal strCode As String)
   m_strCode = strCode
End Sub

'strCode reserved for later use.
Public Sub PutScript(ByVal strText As String, ByVal strCode As String)
   m_strCode = strText
   Dirty = True
End Sub

Public Property Get GlobalID() As String
   GlobalID = m_strGlobalID
End Property
Public Property Let GlobalID(strID As String)
   m_strGlobalID = strID
End Property

Public Property Get Saved() As Boolean
   Saved = m_bSaved
End Property
Public Property Let Saved(bNewValue As Boolean)
   m_bSaved = bNewValue
End Property

'Read-Only version of the property for display in the properties window
Public Property Get Path() As String
   Path = m_strPathName
End Property

Public Property Get filename() As String
   If m_strPathName = "" Then
      filename = "<unsaved module>"
   Else
      filename = Mid(m_strPathName, InStrRev(m_strPathName, "\") + 1)
   End If
End Property

Public Property Get PathName() As String
   PathName = m_strPathName
End Property
Public Property Let PathName(strNewValue As String)
   m_strPathName = strNewValue
End Property

Public Property Get Name() As String
   Name = m_strName
End Property
Public Property Let Name(strNewValue As String)
   m_strName = strNewValue
End Property
