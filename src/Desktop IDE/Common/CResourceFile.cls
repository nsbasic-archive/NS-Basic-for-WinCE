VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CResourceFile"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Private m_strGlobalID As String
Private m_strPathName As String  'relative path to project
Private m_bRegister As Boolean
Private m_strName As String
Private m_nResType As Integer
Private m_bSharedFile As Boolean
Private m_nInstallTo As Integer
Public Dirty As Boolean

Public Function PropertyList() As String()
#If NSBasic_CE Then
   PropertyList = Split("Name,Path,Resource Type,Install to,Register,Shared File", ",")
#End If
#If NSBasic_Desktop Then
   PropertyList = Split("Name,Path,Resource Type,Register", ",")
#End If
End Function

Public Function GetProperty(ByVal astrProperty As String, ByRef pvPropVal As Variant) As EXPROPERTIESLISTLibCtl.EditTypeEnum
   Select Case astrProperty
   Case "Name": GetProperty = Edit: pvPropVal = m_strName
   Case "Path": GetProperty = EditFile: pvPropVal = m_strPathName
   Case "Resource Type": GetProperty = EditEnum: pvPropVal = m_nResType
   Case "Register": GetProperty = EditBoolean: pvPropVal = m_bRegister
   Case "Shared File": GetProperty = EditBoolean: pvPropVal = m_bSharedFile
   Case "Install to": GetProperty = EditEnum: pvPropVal = m_nInstallTo
   End Select
End Function

Public Function SetProperty(astrProperty As String, ByVal vNewValue As Variant) As Variant
Dim X As Integer
   If CurDir <> gProjectDir Then 'Property window can change current directory
      If Mid(gProjectDir, 2, 1) = ":" Then ChDrive Left(gProjectDir, 2) 'ignore network drives
      ChDir gProjectDir
   End If
   
   Select Case astrProperty
   Case "Name": m_strName = vNewValue
   Case "Path":
      m_strPathName = GetRelativePath(gProjectDir, vNewValue)
      Select Case LCase(Right(m_strPathName, 4))
      Case ".bmp": ResType = 0
      Case ".wav": ResType = 2
      Case ".ocx":
         #If NSBasic_CE Then
         ResType = 3 'installer file
         sharedFile = True
         register = True
         #Else
         ResType = 1 'file
         #End If
      Case ".dll":
         #If NSBasic_CE Then
         ResType = 3 'installer file
         sharedFile = True
         register = True
         #Else
         ResType = 1 'file
         #End If
      Case Else:
         #If NSBasic_CE Then
         ResType = 3 'installer file
         #Else
         ResType = 1 'file
         #End If
      End Select
   Case "Register":
      'If LCase(Right(Path, 4)) <> ".dll" And LCase(Right(Path, 4)) <> ".ocx" Then vNewValue = False
      m_bRegister = vNewValue
      register = m_bRegister
   Case "Resource Type": m_nResType = vNewValue
   Case "Shared File":
      m_bSharedFile = vNewValue
      sharedFile = m_bshared
   Case "Install to": m_nInstallTo = vNewValue
   End Select
   GetProperty astrProperty, SetProperty
End Function

Public Property Get GlobalID() As String
   GlobalID = m_strGlobalID
End Property
Public Property Let GlobalID(strID As String)
   m_strGlobalID = strID
End Property

Public Property Get Path() As String
   Path = m_strPathName
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

Public Property Get ResType() As Integer
   ResType = m_nResType
End Property
Public Property Let ResType(nNewValue As Integer)
   m_nResType = nNewValue
End Property

Public Property Get register() As Boolean
   register = m_bRegister
End Property
Public Property Let register(bNewValue As Boolean)
   m_bRegister = bNewValue
End Property

Public Property Get installTo() As Integer
   installTo = m_nInstallTo
End Property
Public Property Let installTo(nNewValue As Integer)
   m_nInstallTo = nNewValue
End Property

Public Property Get sharedFile() As Boolean
   sharedFile = m_bSharedFile
End Property
Public Property Let sharedFile(bNewValue As Boolean)
   m_bSharedFile = bNewValue
End Property




