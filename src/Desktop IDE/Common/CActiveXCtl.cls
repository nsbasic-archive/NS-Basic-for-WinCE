VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CActiveXCtl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

Private WithEvents m_Ctl As VBControlExtender
Attribute m_Ctl.VB_VarHelpID = -1
Private WithEvents m_Lbl As VB.Label
Attribute m_Lbl.VB_VarHelpID = -1
Private WithEvents m_Sub As VB.PictureBox
Attribute m_Sub.VB_VarHelpID = -1

Private m_VisObj As Object
Private m_Screen As frmScreen
Private clickTime As Double
Private m_strName As String
Private m_strType As String
Private m_nLeft As Integer
Private m_nTop As Integer
Private m_nWidth As Integer
Private m_nHeight As Integer
Private m_sTag As String
Private m_strGlobalID As String
Private m_bNonVisible As Boolean
Public Loaded As Boolean

Private Properties As New Collection

Public Function PropertyList() As String()
Dim strProps As String
Dim prop As CProperty

   For Each prop In Properties
      strProps = strProps & "," & prop.Name
   Next
   PropertyList = Split(Mid(strProps, 2), ",")
End Function

Public Function AddObject(astrType As String, astrName As String, X As Integer, Y As Integer, W As Integer, H As Integer) As Object
Dim strClass As String

   Set AddObject = Nothing
   m_strName = astrName
   m_nLeft = X
   m_nTop = Y
   m_nWidth = W
   m_nHeight = H
   Select Case LCase(astrType)
   Case "filectl.file.1", "filectl.filesystem.1", "cecomdlg.commondialog.1", "cecomm.comm.1", "ceimagelist.imagelistctrl.1", "winsock.winsock.1"
      m_nWidth = m_Screen.TextWidth(astrName) + 24
      m_nHeight = m_Screen.TextHeight("1") + 8
   End Select
   'Initialize this wrapper object by type
   m_bNonVisible = True 'that remains to be seen
'   Set AddObject = InitOCX(strClass, astrName)
   Set AddObject = InitOCX(astrType, astrName)
End Function

Public Sub DeleteObject()
   On Error Resume Next 'GH: Temporary kludge. m_Ctl.Name is not being set properly by NSListControl.
   m_Screen.Controls.Remove m_Lbl.Name
   m_Screen.Controls.Remove m_Ctl.Name
   m_Screen.Controls.Remove m_Sub.Name
End Sub

Public Function GenerateCode(kOb As String) As String
Dim strCode As String
Dim prop As CProperty
Dim q As String
Dim qq As String

   q = Chr(34)
   qq = Chr(34) & " & chr(34) & " & Chr(34)

   If Not m_Ctl Is Nothing Then
      Update
'      Unload
'      Set m_Lbl.Container = m_Sub
   End If
   
   Select Case LCase(m_strType)
   Case "filectl.file.1", "filectl.filesystem.1", "cecomdlg.commondialog.1", "cecomm.comm.1", "ceimagelist.imagelistctrl.1", "winsock.winsock.1"
      strCode = "AddObject " & qq & m_strType & qq & ", " & qq & m_strName & qq & ", " & m_nLeft & ", " & m_nTop & ", 0, 0, " & Trim(kOb)
      strCode = "      NSExecute " & q & strCode & q & vbCrLf
   Case Else
      #If NSBasic_Desktop Then
         strCode = "      AddObject """ & m_strType & """, """ & m_strName & """, " & m_nLeft & ", " & m_nTop & ", " & m_nWidth & ", " & m_nHeight & ", " & Trim(kOb) & vbCrLf
      #End If
      #If NSBasic_CE Then
         strCode = "AddObject " & qq & m_strType & qq & ", " & qq & m_strName & qq & ", " & m_nLeft & ", " & m_nTop & ", " & m_nWidth & ", " & m_nHeight & ", " & Trim(kOb)
         strCode = "      NSExecute " & q & strCode & q & vbCrLf
      #End If
   End Select

   
   For Each prop In Properties
      If ((prop.Name = "Text" Or prop.Name = "Clip") And m_strType = "GridCtrl.GridCtrl.1") _
      Or ((prop.Name = "TabsPersist") And m_strType = "CETabStrip.TabStrip.1") Then
      Else
         If prop.Changed Then
            strCode = strCode & "      " & m_strName & "." & prop.Name & " = " & IIf(prop.ReturnType = vbString, """" & prop.Value & """", prop.Value) & vbCrLf
         End If
      End If
   Next
   GenerateCode = strCode
End Function

Private Sub Class_Terminate()
   If Not m_Screen Is Nothing Then
      If Not m_Lbl Is Nothing Then
         On Error Resume Next
         m_Screen.Controls.Remove m_Lbl.Name
         Set m_Lbl = Nothing
         m_Screen.Controls.Remove m_Sub.Name
         Set m_Sub = Nothing
      End If
   End If
End Sub

Private Sub m_Ctl_GotFocus()
   m_Screen.DragBegin Me
End Sub

Private Sub m_Ctl_LostFocus()
   m_Screen.DragEnd
End Sub

Private Sub m_Ctl_ObjectEvent(Info As EventInfo)
'Debug.Print "CActiveXCtl.Event", Info.Name
   If Info.Name = "MouseDown" Or Info.Name = "Click" Then
      If Info.EventParameters(0) = vbLeftButton Then
         If Timer - clickTime < gdblClickTime Then
            ViewCode GlobalID
            Exit Sub
         End If
         m_Screen.DragBegin Me
         'ReleaseCapture
      ElseIf Info.EventParameters(0) = vbRightButton Then
         m_Screen.ShowPopup Me
      End If
   ElseIf Info.Name = "KeyDown" Then
      m_Screen.KeyDown Info.EventParameters(0), Info.EventParameters(1)
   End If
End Sub

Private Sub m_Lbl_DblClick()
   ViewCode GlobalID
End Sub

Private Sub m_Lbl_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   If Shift <> vbNormal Then Exit Sub
   If Button = vbLeftButton Then
      clickTime = Timer
      m_Screen.DragBegin Me
   End If
   If Button = vbRightButton Then
      m_Screen.ShowPopup Me
   End If
End Sub

Public Sub SetForm(ByVal RHS As frmScreen)
   Set m_Screen = RHS
End Sub

Public Function InitOCX(astrType As String, astrObjName As String) As Control
Dim strType As String
Dim ti As TypeInfo
Dim tli As TypeLibInfo
Dim ifi As InterfaceInfo
Dim mi As MemberInfo
Dim prop As CProperty
Dim nPutGet As Integer  '1 = get, 2 = put, 3 = put + get
Dim strProp As String
Dim strDummy As String

   m_strType = astrType
#If NSBasic_CE Then
'   On Error GoTo err_TotalAbort
   strDummy = "NSBasic_CE.ActiveXDummy"
#End If
#If NSBasic_Desktop Then
'   If UBound(Split(astrType, ".")) > 1 Then
'      astrType = Split(astrType, ".")(0) & "." & Split(astrType, ".")(1)
'   End If
   strDummy = "NSBasic_Desktop.ActiveXDummy"
#End If
   On Error Resume Next
   Set m_Ctl = m_Screen.Controls.Add(astrType, astrObjName)
   If err <> 0 Then
      err.Clear
      Set m_Ctl = m_Screen.Controls.Add(strDummy, astrObjName)
   End If
   On Error GoTo Dump_N_Run

   Set ti = ClassInfoFromObject(m_Ctl.Object)
   strType = ti.Name

   'Get the main interface
   Set ifi = ti.DefaultInterface

   'Main interface has properties and methods, lets look for hide, show or visible
   For Each mi In ifi.Members
   'Debug.Print mi.Name
      If mi.Name = "Visible" Or mi.Name = "Hide" Or mi.Name = "Show" Then
         m_bNonVisible = False
         Exit For
      End If
   Next

Dump_N_Run:
   'if it is non-visible, add an additional Label control to manage things
   'Return the label if no visible control exists
   'm_VisObj is used to mess with the object that is visible
'   If True Then 'm_bNonVisible Then
      Set m_Sub = m_Screen.Controls.Add("VB.PictureBox", Replace(GlobalID, "|", "_") & "_Sub")
      m_Sub.ScaleMode = vbPixels
      m_Sub.BackColor = vbRed
      m_Sub.Appearance = Flat
      m_Sub.BorderStyle = 0
      Set m_Lbl = m_Screen.Controls.Add("VB.Label", "NSB_NV_" & astrObjName)
      Set m_Lbl.Container = m_Sub
      m_Lbl.BackColor = vbWhite
      m_Lbl.BorderStyle = vbFixedSingle
      m_Lbl.Appearance = 0
      m_Lbl.FontBold = True
      m_Lbl.Caption = m_strName
      m_Lbl.Alignment = vbCenter
      m_Lbl.Visible = True
      Set InitOCX = m_Sub
'      Set InitOCX = m_Lbl
'      Set m_VisObj = m_Lbl
      Move (m_nLeft), (m_nTop), (m_nWidth), (m_nHeight)
'   Else
'      Set InitOCX = m_Ctl
'      Set m_VisObj = m_Ctl
'   End If

   If ifi Is Nothing Then GoTo Dump_N_Run2
   On Error GoTo Dump_N_Run2

   'Don't fetch properties more than once
   If Properties.Count > 0 Then
      ReHook
      Loaded = True
      Exit Function
   End If

   'Check each interface member, looking for (simple read/write) design-time properties
   strProp = ""
   For Each mi In ifi.Members
      'Don't use location/size or properties that take an argument
      If mi.Parameters.Count = 0 And InStr(1, "Left;Top;Width;Height;Visible", mi.Name, vbTextCompare) < 1 Then
         'This indirect section looks for two properties (get/put) with the same name
         Select Case mi.InvokeKind
         Case INVOKE_PROPERTYGET
            If strProp = mi.Name Then
               nPutGet = nPutGet + 1
            Else
               strProp = mi.Name
               nPutGet = 1
            End If
         Case INVOKE_PROPERTYPUT
            If strProp = mi.Name Then
               nPutGet = nPutGet + 2
            Else
               strProp = mi.Name
               nPutGet = 2
            End If
         End Select

         'If a property meets the criteria, try to add it with a default value to this object
         If nPutGet = 3 Then
            If ((strProp = "Text" Or strProp = "Clip") And strType = "GridCtrl") _
            Or ((strProp = "TabsPersist") And strType = "TabStrip") Then
'               Debug.Print "O.J. Simpson"
            Else
               If Not IsObject(InvokeHook(m_Ctl, mi.Name, INVOKE_PROPERTYGET)) Then
                  Set prop = New CProperty
                  prop.Name = mi.Name
                  prop.ReturnType = mi.ReturnType
                  prop.DefaultValue = InvokeHook(m_Ctl, prop.Name, INVOKE_PROPERTYGET)
                  Properties.Add prop, prop.Name
               End If
            End If

            'Reset our criteria meters
            nPutGet = 0
            strProp = ""
         End If
      End If
   Next

Dump_N_Run2:
   Loaded = True
   Exit Function

err_TotalAbort:
   MsgBox err.Number & ": " & err.Description
End Function

Public Sub Rename(ByVal astrName As String)
Dim cont As Object

'Can InitOCX make this all simpler??
   'Remove ctl
   m_Screen.Controls.Remove m_strName
   'Remove lbl
   Set cont = m_Sub.Container
   m_Screen.Controls.Remove "NSB_NV_" & m_strName
   'Add new ctl
   On Error Resume Next
   Set m_Ctl = m_Screen.Controls.Add(m_strType, astrName)
   If err <> 0 Then
      err.Clear
      Set m_Ctl = m_Screen.Controls.Add("NSBasic_Desktop.ActiveXDummy", astrName)
      On Error GoTo 0
   End If
   ReHook
   'Add new lbl
   Set m_Lbl = m_Screen.Controls.Add("VB.Label", "NSB_NV_" & astrName)
   m_Lbl.BackColor = vbWhite
   m_Lbl.BorderStyle = vbFixedSingle
   m_Lbl.Appearance = 0
   m_Lbl.FontBold = True
   m_Lbl.Caption = astrName
   m_Lbl.Alignment = vbCenter
   Set m_Lbl.Container = m_Sub
   m_Lbl.Visible = True
   Move (m_nLeft), (m_nTop), (m_nWidth), (m_nHeight)
   m_strName = astrName
   If gbProperties Then
      gfProperties.Object = Nothing
      gfProperties.Object = Me
   End If
End Sub

Public Sub Move(ByVal X As Long, ByVal Y As Long, ByVal W As Long, ByVal H As Long)
   On Error Resume Next
   m_Ctl.Move X, Y, W, H
   If Not m_Sub Is Nothing Then
      m_Sub.Move X, Y, W, H
      Set m_Lbl.Container = m_Sub
      m_Lbl.Move 0, 0, W, H
   End If

   With Me
      .Left = X
      .Top = Y
      .Width = W
      .Height = H
   End With
   m_Screen.ShowHandles
End Sub

Public Sub Update()
Dim prop As CProperty

   On Error Resume Next
   For Each prop In Properties
      prop.Value = InvokeHook(m_Ctl, prop.Name, INVOKE_PROPERTYGET)
   Next

   With m_Sub
'   With m_VisObj
      m_nLeft = .Left
      m_nTop = .Top
      m_nWidth = .Width
      m_nHeight = .Height
   End With
End Sub

Public Sub Unload()
   On Error Resume Next 'gwh
   Set m_Lbl.Container = m_Sub.Container
   On Error GoTo 0
   Update
   Set m_Ctl = Nothing
   Set m_Screen = Nothing
End Sub

Public Sub ReHook()
Dim prop As CProperty

   For Each prop In Properties
      If Not IsEmpty(prop.Value) Then
         On Error Resume Next
         InvokeHook m_Ctl, prop.Name, INVOKE_PROPERTYPUT, prop.Value
      End If
   Next
End Sub

Public Property Get Name() As String
   Name = m_strName
End Property
Public Property Let Name(vNewValue As String)
   m_strName = vNewValue
   If Not m_Lbl Is Nothing Then
      m_Lbl.Caption = m_strName
   End If
End Property

Public Property Get Control() As Object
   Set Control = m_Ctl
End Property

Public Property Get Height() As Integer
   Height = m_nHeight
End Property
Public Property Let Height(ByVal vNewValue As Integer)
   m_Sub.Height = vNewValue
   m_Lbl.Height = m_Sub.Height
   m_nHeight = m_Lbl.Height
End Property

Public Property Get Left() As Integer
   Left = m_nLeft
End Property
Public Property Let Left(ByVal vNewValue As Integer)
   m_Sub.Left = vNewValue
   m_Lbl.Left = 0
   m_nLeft = m_Sub.Left
End Property

Public Property Get Top() As Integer
   Top = m_nTop
End Property
Public Property Let Top(ByVal vNewValue As Integer)
   m_Sub.Top = vNewValue
   m_Lbl.Top = 0
   m_nTop = m_Sub.Top
End Property

Public Property Get Tag() As String
   Tag = m_sTag
End Property
Public Property Let Tag(ByVal vNewValue As String)
   m_sTag = vNewValue
End Property

Public Property Get Width() As Integer
   Width = m_nWidth
End Property
Public Property Let Width(ByVal vNewValue As Integer)
   m_Sub.Width = vNewValue
   m_Lbl.Width = m_Sub.Width
   m_nWidth = m_Lbl.Width
End Property

Public Property Get Form() As frmScreen
   Set Form = m_Screen
End Property

Public Property Get ClassID() As String
   ClassID = m_strType
End Property

Public Property Get Ctl() As Object
   Set Ctl = m_Sub
'   Set Ctl = m_VisObj
End Property

Public Property Get GlobalID() As String
   GlobalID = m_strGlobalID
End Property
Public Property Let GlobalID(vNewValue As String)
   m_strGlobalID = vNewValue
End Property

Public Property Get CEType() As String
   CEType = "ActiveX"
End Property
