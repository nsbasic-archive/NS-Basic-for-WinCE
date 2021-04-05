VERSION 5.00
Object = "{35D28C93-F7DB-423A-B1FB-3A7B80B7D7F4}#1.0#0"; "ExPropertiesList.dll"
Begin VB.Form frmProperties 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Properties"
   ClientHeight    =   6015
   ClientLeft      =   32805
   ClientTop       =   285
   ClientWidth     =   5895
   LinkTopic       =   "Properties"
   MaxButton       =   0   'False
   MDIChild        =   -1  'True
   MinButton       =   0   'False
   Moveable        =   0   'False
   ScaleHeight     =   6015
   ScaleWidth      =   5895
   ShowInTaskbar   =   0   'False
   Tag             =   "1175"
   Visible         =   0   'False
   Begin EXPROPERTIESLISTLibCtl.PropertiesList propList 
      Height          =   4095
      Left            =   1080
      OleObjectBlob   =   "frmProperties.frx":0000
      TabIndex        =   0
      Top             =   960
      Width           =   3255
   End
End
Attribute VB_Name = "frmProperties"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'Dim m_PropGrid As New CPropertiesGrid
Dim m_Obj As Object
Dim m_bIntrinsic As Boolean

'Space sandwich helps us search this list for exact matches
Private HiddenProperties As New Collection

Private Sub Form_Load()
Dim bytResData() As Byte
Dim strResData As String
Dim arrResData() As String
Dim i As Integer
   
   LoadResStrings Me, False

   gbProperties = True
   Me.Left = -(Me.Width + 1)

   bytResData = LoadResData(200, "DESIGNTIME")
   strResData = StrConv(bytResData, vbUnicode)
   arrResData = Split(strResData, vbCrLf)

   'Create a new collection and add each of the properties in the list
   'Properties are indexed by name just so they can be accessed easier
   If HiddenProperties.Count = UBound(arrResData) Then Exit Sub
   For i = 1 To UBound(arrResData)
      HiddenProperties.Add arrResData(i), arrResData(i)
   Next
   With propList
      .BackColorAlternate = 15790320
      .Option(exFontCharSet) = "0,2,128,255"
      .Select propList
   End With

End Sub

Private Sub Form_Resize()
   With propList
      .Width = Me.ScaleWidth
      .Height = Me.ScaleHeight
      .Left = 0
      .Top = 0
      .DescriptionHeight = 48
   End With
End Sub

Public Sub DockWindow()
'On Error Resume Next
Dim lRet As Long

   Me.Visible = False

   'Make sure we keep the ToolWindow style
   lRet = SetWindowLong(Me.hWnd, GWL_EXSTYLE, CLng(WS_EX_TOOLBOXWINDOW))

   'Set parent and resize the panel
   SetParent Me.hWnd, frmMain.picProperties.hWnd
   frmMain.picProperties_Resize
   frmMain.picPanel_Resize

   frmMain.picPanel.Refresh
   frmMain.picPanel.Visible = True
   DoEvents
   Me.Visible = True
   SendMessage Me.hWnd, WM_NCACTIVATE, 1, 0
   frmMain.mnuViewProperties.Checked = gbProperties

   ShowObject
End Sub

Private Sub Form_Unload(Cancel As Integer)
   gbProperties = False
   frmMain.picPanel_Resize
   frmMain.mnuViewProperties.Checked = gbProperties
End Sub

Public Property Let Object(ByRef obj As Object)
   If obj Is Nothing And m_Obj Is Nothing Then ShowObject
   If obj Is m_Obj Then Exit Property
   Set m_Obj = obj
   ShowObject
End Property

Public Sub ShowObject()
Dim arrProperties() As String
Dim i As Integer
Dim nType As EXPROPERTIESLISTLibCtl.EditTypeEnum
Dim vVal As Variant


'If Not m_Obj Is Nothing Then MsgBox m_Obj.Name
   If TypeName(m_Obj) = "CActiveXCtl" Then
      m_bIntrinsic = False
      'On Error Resume Next
      If m_Obj.Control Is Nothing Then
         propList.Select m_Obj
      Else
         propList.ShowHidden = True
         'propList.Select m_Obj.Control.control '2009.05.08 GWH changed to eliminate error
         propList.Select m_Obj.Control
      End If
      On Error GoTo 0
      propList.Refresh
   Else
      If m_Obj Is Nothing Then
         propList.Clear
         Exit Sub
      End If
      m_bIntrinsic = True
      arrProperties = m_Obj.PropertyList
      With propList
         .Clear
         .BeginUpdate
         For i = 0 To UBound(arrProperties)
            If Len(arrProperties(i)) > 0 Then
               nType = m_Obj.GetProperty(arrProperties(i), vVal)
               Select Case nType
'               Case EditFile:
'                  Set c = .Add(arrProperties(i), CStr(vVal), nType)
'                  With .Add(arrProperties(i), CStr(vVal), EditEnum)
'                     Select Case arrProperties(i)
'                     Case "Icon":
'                        .Option(exEditFileTitle) = "Icon"
'                        .Option(exEditFileFilter) = "All Pictures Files|*.bmp;*.dib;*.gif;*.jpg;*.wmf;*.emf;*.ico;*.cur|Bitmaps (*.bmp;*.dib)|;*.bmp;*.dib|GIF Images (*.gif)|*.gif|JPEG Images (*.jpg)|*.jpg|Metafiles (*.wmf;*.emf)|*.wmf;*.emf|Icons (*.ico;*.cur)|*.ico;*.cur|All Files (*.*)|*.*" '"All Icon Files|Icons (*.ico)|*.ico"
'                     End Select
'                  End With
               Case EditBoolean:
                  .Add arrProperties(i), CBool(vVal), nType
               Case EditEnum:
                  With .Add(arrProperties(i), CStr(vVal), EditEnum)
                     Select Case arrProperties(i)
                     Case "Alignment":
                        .AddValue 0, "0-Left"
                        .AddValue 1, "1-Right"
                        .AddValue 2, "2-Center"
                     Case "Appearance":
                        .AddValue 0, "0-Flat"
                        .AddValue 1, "1-3D"
                     Case "BorderStyle":
                        .AddValue 0, "0-None"
                        .AddValue 1, "1-Line"
                     Case "DrawStyle":
                        .AddValue 0, "0-Visible"
                        .AddValue 1, "1-Not Visible"
                     Case "FillStyle":
                        .AddValue 0, "0-Solid"
                        .AddValue 1, "1-Transparent"
                     Case "GradientStyle":
                        .AddValue 0, "Left to Right"
                        .AddValue 1, "Top to Bottom"
                     Case "ScrollBars":
                        .AddValue 0, "0-None"
                        .AddValue 1, "1-Horizontal"
                        .AddValue 2, "2-Vertical"
                        .AddValue 3, "3-Both"
                     Case "Resource Type":
                        .AddValue 0, "Bitmap Resource"
                        .AddValue 1, "File Resource"
                        .AddValue 2, "Wave Resource"
                        #If NSBasic_CE Then
                        .AddValue 3, "Installer File"
                        #End If
                     Case "Style":
                        .AddValue 0, "0-Editable"
                        .AddValue 2, "2-Read Only"
                     Case "WindowLong":
                        .AddValue 0, "0-ExWindowStyle"
                        .AddValue 1, "1-WindowStyle"
                     Case "Install to":
                        .AddValue 0, "Project Install Dir"
                        .AddValue 1, "Windows"
                     End Select
                  End With
               Case Else:
                  Set c = .Add(arrProperties(i), CStr(vVal), nType)
               End Select
            End If
         Next
         .EndUpdate
         .Refresh
      End With
   End If
'Debug.Print propList.Interfaces(propList.Object)
   SetCaption
End Sub

Public Property Get Object() As Object
   Set Object = m_Obj
End Property

Public Sub SetCaption()
   Me.Caption = gStringTable(1302)
   If m_Obj Is Nothing Then Exit Sub

   Me.Caption = Me.Caption & " - " & m_Obj.Name
End Sub

Private Sub propList_IncludeProperty(ByVal Property As EXPROPERTIESLISTLibCtl.IProperty, Cancel As Boolean)
Dim strExclude As String
   
   On Error Resume Next
   If Property.Name = "Name" And m_bIntrinsic = False Then
      Cancel = True
      Exit Sub
   End If
   strExclude = HiddenProperties(Property.Name)
   If Len(strExclude) > 0 Then
      Cancel = True
      Exit Sub
   End If
   If Property.ReadOnly Then
      Select Case Property.Name
      Case "Name": Cancel = True
      Case "Index": Cancel = True
      End Select
      Exit Sub
   End If
   'GWH Code added to only display a few properties of extrinsics
   Select Case Property.Name
      Case "Top": Cancel = False
      Case "Left": Cancel = False
      Case "Height": Cancel = False
      Case "Width": Cancel = False
      Case Else: Cancel = True
   End Select
End Sub

Private Sub propList_PropertyChange(ByVal Property As EXPROPERTIESLISTLibCtl.IProperty, Value As Variant)
Dim i As Integer
Dim c As Integer

   With propList
      Select Case Property.Name
      Case "Name"
         'Validation of object name takes place here
         If gTarget.ValidObjectName(Value, m_Obj.GlobalID) <> "" Then
            MsgBox gTarget.ValidObjectName(Value, m_Obj.GlobalID)
            Value = Property.Value
         End If
         For i = 1 To Len(Value)
            c = Asc(UCase(Mid(Value, i, 1)))
            If Not ((c >= Asc("A") And c <= Asc("Z")) Or (c >= Asc("0") And c <= Asc("9")) Or c = Asc("_")) Then
               Mid(Value, i, 1) = "_"
            End If
         Next
         Me.Caption = gStringTable(1302) & " - " & Value
      Case "Left"
         'This and remaining location properties actually move screen object
         m_Obj.Move Val(Value), .Property("Top").Value, .Property("Width").Value, .Property("Height").Value
         Value = m_Obj.Left
      Case "Top"
         m_Obj.Move .Property("Left").Value, Val(Value), .Property("Width").Value, .Property("Height").Value
         Value = m_Obj.Top
      Case "Width"
         m_Obj.Move .Property("Left").Value, .Property("Top").Value, Val(Value), .Property("Height").Value
         Value = m_Obj.Width
      Case "Height"
         m_Obj.Move .Property("Left").Value, .Property("Top").Value, .Property("Width").Value, Val(Value)
         Value = m_Obj.Height
      End Select
      
      'Tell object in question that property has changed
      If m_bIntrinsic Then
         Value = m_Obj.SetProperty(Property.Name, Value)
      End If
   End With
   
   'Update the proper window captions, if the "Name" property has been changed
   If Property.Name = "Name" Then
      If gbProjectExplorer Then gfProjectExplorer.UpdateObjectNode m_Obj, m_Obj.GlobalID
      Select Case TypeName(m_Obj)
      Case "CForm"
         Dim fScreen As frmScreen
         Set fScreen = frmMain.GetMDIChild(m_Obj.GlobalID)
         If Not fScreen Is Nothing Then fScreen.SetCaption
      Case "CModule"
         Dim fCode As frmCode
         Set fCode = frmMain.GetMDIChild(m_Obj.GlobalID)
         If Not fCode Is Nothing Then fCode.SetCaption
      End Select
   End If
   
   'gTarget.Dirty = True
End Sub

