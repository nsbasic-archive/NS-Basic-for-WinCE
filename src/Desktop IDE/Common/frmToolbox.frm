VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmToolbox 
   BorderStyle     =   4  'Fixed ToolWindow
   ClientHeight    =   6930
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   345
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MDIChild        =   -1  'True
   MinButton       =   0   'False
   Moveable        =   0   'False
   ScaleHeight     =   6930
   ScaleWidth      =   345
   ShowInTaskbar   =   0   'False
   Begin MSComctlLib.Toolbar tbToolbox 
      Height          =   4620
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   375
      _ExtentX        =   661
      _ExtentY        =   8149
      ButtonWidth     =   609
      ButtonHeight    =   582
      Style           =   1
      ImageList       =   "imlToolbox"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628} 
         NumButtons      =   14
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Cursor"
            ImageIndex      =   1
            Style           =   1
            Value           =   1
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Button"
            Object.ToolTipText     =   "1202"
            ImageIndex      =   2
            Style           =   1
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "List"
            Object.ToolTipText     =   "1203"
            ImageIndex      =   3
            Style           =   1
         EndProperty
         BeginProperty Button4 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Label"
            Object.ToolTipText     =   "1204"
            ImageIndex      =   4
            Style           =   1
         EndProperty
         BeginProperty Button5 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Field"
            Object.ToolTipText     =   "1205"
            ImageIndex      =   5
            Style           =   1
         EndProperty
         BeginProperty Button6 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "PushButton"
            Object.ToolTipText     =   "1206"
            ImageIndex      =   6
            Style           =   1
         EndProperty
         BeginProperty Button7 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Checkbox"
            Object.ToolTipText     =   "1207"
            ImageIndex      =   7
            Style           =   1
         EndProperty
         BeginProperty Button8 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "PopupTrigger"
            Object.ToolTipText     =   "1208"
            ImageIndex      =   8
            Style           =   1
         EndProperty
         BeginProperty Button9 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Selector"
            Object.ToolTipText     =   "1209"
            ImageIndex      =   9
            Style           =   1
         EndProperty
         BeginProperty Button10 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Bitmap"
            Object.ToolTipText     =   "1210"
            ImageIndex      =   10
            Style           =   1
         EndProperty
         BeginProperty Button11 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Gadget"
            Object.ToolTipText     =   "1211"
            ImageIndex      =   11
            Style           =   1
         EndProperty
         BeginProperty Button12 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Repeater"
            Object.ToolTipText     =   "1212"
            ImageIndex      =   12
            Style           =   1
         EndProperty
         BeginProperty Button13 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "Scrollbar"
            Object.ToolTipText     =   "1213"
            ImageIndex      =   13
            Style           =   1
         EndProperty
         BeginProperty Button14 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Key             =   "GraffitiShiftIndicator"
            Object.ToolTipText     =   "1214"
            ImageIndex      =   14
            Style           =   1
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList imlToolbox 
      Left            =   0
      Top             =   5880
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   16777215
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   14
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":0000
            Key             =   "Cursor"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":0352
            Key             =   "Button"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":06A4
            Key             =   "List"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":09F6
            Key             =   "Label"
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":0D48
            Key             =   "Field"
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":109A
            Key             =   "PushButton"
         EndProperty
         BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":13EC
            Key             =   "Checkbox"
         EndProperty
         BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":173E
            Key             =   "PopupTrigger"
         EndProperty
         BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":1A90
            Key             =   "Selector"
         EndProperty
         BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":1DE2
            Key             =   "Bitmap"
         EndProperty
         BeginProperty ListImage11 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":2134
            Key             =   "Gadget"
         EndProperty
         BeginProperty ListImage12 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":2486
            Key             =   "Repeater"
         EndProperty
         BeginProperty ListImage13 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":27D8
            Key             =   "Scrollbar"
         EndProperty
         BeginProperty ListImage14 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmToolbox.frx":2B2A
            Key             =   "GraffitiShiftIndicator"
         EndProperty
      EndProperty
   End
   Begin VB.Menu mnuRight 
      Caption         =   "Right-Click Menu"
      Visible         =   0   'False
      Begin VB.Menu mnuRightActiveX 
         Caption         =   "3446"
      End
   End
End
Attribute VB_Name = "frmToolbox"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Sub DockWindow()
'On Error Resume Next
Dim lRet As Long
   'Hide first
   Me.Visible = False
   'Make sure we keep the ToolWindow style
   lRet = SetWindowLong(Me.hWnd, GWL_EXSTYLE, CLng(WS_EX_TOOLBOXWINDOW))
   'Set parent window and its size
   SetParent Me.hWnd, frmMain.picToolbox.hWnd
   frmMain.picToolbox.Width = Me.Width
   frmMain.picToolbox_Resize
'   Me.Move 0, 0
   
   'Show everything
   frmMain.picToolbox.Visible = True
   DoEvents
   Me.Visible = True
   SendMessage Me.hWnd, WM_NCACTIVATE, 1, 0
   
   'Keep track of some info
   frmMain.mnuViewToolbox.Checked = True
End Sub

Private Sub Form_Load()
Dim i As Integer
Dim j As Integer
Dim li As ListImage
   
   gbToolbox = True
   gnToolboxTool = 1
   
   'Load images and set imagelist
   tbToolbox.ImageList = Nothing
   imlToolbox.ListImages.Clear
   imlToolbox.MaskColor = vbCyan
   imlToolbox.UseMaskColor = True
   For i = 101 To 101 + (knToolboxButtons - 1)
      If InStr(LCase(" Pointer " & kIntrinsics & kActiveXNames & "ActiveX "), " " & LCase(LoadResString(i) & " ")) Then
         Set li = imlToolbox.ListImages.Add(, LoadResString(i), LoadResPicture(i, 0))
      End If
   Next
   tbToolbox.ImageList = imlToolbox
   UpdateTools
   
   Me.Width = tbToolbox.Width
   LoadResStrings Me
End Sub

Public Sub UpdateTools()
Dim arrAXS() As String
Dim strAXCustom As String
Dim tli As TypeLibInfo
Dim cci As CoClassInfo
Dim ProgID As String
Dim nIndex As Integer
Dim i As Integer
Dim btn As MSComctlLib.Button
Dim li As ListImage
Dim intrinsics As String
Dim p As Integer
Dim cR As New cResources
Dim L As Long
Dim lIndex As Long
Dim lCount As Long
Dim sType As String
Dim CI As cFileIcon
Dim vName As Variant

   'Clear toolbox and add pointer plus intrinsic objects
   tbToolbox.Buttons.Clear
   p = 0
   For i = 1 To knToolboxButtons
      If InStr(LCase("Pointer " & kIntrinsics), LCase(LoadResString(i + 100) + " ")) Then
         p = p + 1
         Set btn = tbToolbox.Buttons.Add(p, , , tbrCheck, p)
         With btn
            .ToolTipText = LoadResString(i + 100)
            .Tag = .ToolTipText
            If i = 1 Then
               .Value = tbrPressed
               .ToolTipText = ""
            End If
         End With
      End If
   Next
   
   'Add NSBasic ActiveX Controls
   arrAXS = Split(kActiveXControls, "|")
   On Error GoTo err_UpdateTools
   For i = 0 To UBound(arrAXS)
      Set tli = TypeLibInfoFromFile(arrAXS(i))
      cR.File = arrAXS(i)
      cR.GetResourceTypes
      lIndex = cR.IndexOfResourceType(crGroupIcon)
      If lIndex <> 0 Then
         sType = "Icon"
         Set CI = New cFileIcon
      Else
         sType = "Bitmap"
         lIndex = cR.IndexOfResourceType(crBitmap)
         Set CI = Nothing
      End If
      If lIndex <> 0 Then
         cR.GetResourceNames lIndex
         lCount = cR.ResourceNameCount(lIndex)
      End If
      cR.UnloadModule
      L = 1
      For Each cci In tli.CoClasses
         'If MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "CLSID\" & cci.Guid & "\Control") Then 'GH Be generous - show them all
            ProgID = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "CLSID\" & cci.GUID & "\ProgID", "", "")
            If Len(ProgID) > 0 Then
               On Error Resume Next
               If lCount > 0 And L <= lCount And Not CI Is Nothing Then
'Debug.Print cci.Name, CR.ResourceName(lIndex, l), sType
                  'Load icon from file
                  vName = cR.ResourceName(lIndex, L)
                  If VarType(vName) = vbLong Then
                     CI.LoadIconFromEXE arrAXS(i), vName
                  Else
                     CI.LoadIconFromEXE arrAXS(i), , vName
                  End If
                  Set li = imlToolbox.ListImages(L & "_" & arrAXS(i))
                  If err <> 0 Then
                     err.Clear
                     Set li = imlToolbox.ListImages.Add(, L & "_" & arrAXS(i), CI.IconPicture(Me.hDC, 1))
                  End If
               End If
               If li Is Nothing Then
                  Set li = imlToolbox.ListImages(cci.Name)
               End If
               'If err <> 0 Then Set li = imlToolbox.ListImages("ActiveX")
               If li Is Nothing Then
               Else
                  On Error GoTo 0
                  Set btn = tbToolbox.Buttons.Add(tbToolbox.Buttons.Count + 1, , , tbrCheck, li.Index)
                  btn.ToolTipText = cci.Name
                  btn.Tag = ProgID
                  Set li = Nothing
               End If
            End If
         'End If
         L = L + 1
      Next
   Next

   'Retrieve user appointed custom controls and append to end of list
   strAXCustom = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ActiveXControls", "")
   If Len(strAXCustom) > 0 Then
      arrAXS = Split(strAXCustom, "|")
      strAXCustom = ""
      'Display all custom ActiveX controls
      For i = 0 To UBound(arrAXS)
         On Error Resume Next
         Set tli = TypeLibInfoFromFile(arrAXS(i))
         If err <> 0 Then
            'MsgBox gStringTable(3415) & arrAXS(i) 'Unable to get TypeLib info. Please reinstall.
            arrAXS(i) = ""
         Else
            strAXCustom = strAXCustom & IIf(strAXCustom <> "", "|", "") & arrAXS(i)
         End If
         MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "ActiveXControls", strAXCustom
      Next

      For i = 0 To UBound(arrAXS)
         If arrAXS(i) <> "" Then
            On Error GoTo err_UpdateToolsContinue
            Set tli = TypeLibInfoFromFile(arrAXS(i))
            cR.File = arrAXS(i)
            cR.GetResourceTypes
            lIndex = cR.IndexOfResourceType(crGroupIcon)
            If lIndex <> 0 Then
               sType = "Icon"
               Set CI = New cFileIcon
            Else
               sType = "Bitmap"
               lIndex = cR.IndexOfResourceType(crBitmap)
               Set CI = Nothing
            End If
            If lIndex <> 0 Then
               cR.GetResourceNames lIndex
               lCount = cR.ResourceNameCount(lIndex)
            End If
            cR.UnloadModule
            L = 1
            For Each cci In tli.CoClasses
               If MWinReg.RegKeyExists(HKEY_CLASSES_ROOT, "CLSID\" & cci.GUID & "\Control") Then
                  ProgID = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, "CLSID\" & cci.GUID & "\ProgID", "", "")
                  If Len(ProgID) > 0 Then
                     If lCount > 0 And L <= lCount And Not CI Is Nothing Then
'Debug.Print cci.Name, CR.ResourceName(lIndex, l), sType
                        'Load icon from file
                        vName = cR.ResourceName(lIndex, L)
                        If VarType(vName) = vbLong Then
                           CI.LoadIconFromEXE arrAXS(i), vName
                        Else
                           CI.LoadIconFromEXE arrAXS(i), , vName
                        End If
                        On Error Resume Next
                        For Each li In imlToolbox.ListImages
                           If li.key = L & "_" & arrAXS(i) Then Exit For
                        Next
                        If li Is Nothing Then
                           Set li = imlToolbox.ListImages.Add(, L & "_" & arrAXS(i), CI.IconPicture(Me.hDC, 1))
                        End If
                     End If
                     On Error GoTo err_UpdateToolsContinue 'GH 12.10.2004
                     If li Is Nothing Then
                        Set li = imlToolbox.ListImages("ActiveX")
                     End If
                     On Error GoTo 0
                     Set btn = tbToolbox.Buttons.Add(tbToolbox.Buttons.Count + 1, , , tbrCheck, li.Index)
                     btn.ToolTipText = cci.Name
                     btn.Tag = ProgID
                     Set li = Nothing
                  End If
               End If
               L = L + 1
            Next
         End If
err_UpdateToolsContinue:
'RES
         'If err <> 0 Then MsgBox gStringTable(3415) & arrAXS(i)  'Unable to get TypeLib info. Please reinstall.
         err.Clear
      Next
   End If
   tbToolbox.Width = tbToolbox.Buttons(1).Width * 2
   Exit Sub

err_UpdateTools:
'RES
   MsgBox gStringTable(3415) & arrAXS(i)  'Unable to get TypeLib info. Please reinstall.
    End
End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   If Button <> vbRightButton Or Shift <> 0 Then Exit Sub
   PopupMenu mnuRight
End Sub

Private Sub mnuRightActiveX_Click()
   ManageActiveX
End Sub

Public Property Get ProgID() As String
   If gnToolboxTool = 1 Then Exit Function
   ProgID = tbToolbox.Buttons(gnToolboxTool).Tag
End Property

Public Property Get ControlName() As String
   If gnToolboxTool = 1 Then Exit Function
   ControlName = tbToolbox.Buttons(gnToolboxTool).ToolTipText
End Property

Private Sub Form_Unload(Cancel As Integer)
   gbToolbox = False
   frmMain.picToolbox.Visible = False
   frmMain.mnuViewToolbox.Checked = False
End Sub

Private Sub tbToolbox_ButtonClick(ByVal Button As MSComctlLib.Button)
   ToolboxSelect Button.Index
#If NSBasic_Desktop Then
   If frmMain.ActiveFormIsCode Then
      frmMain.ActiveForm.InsertText "AddObject """ & Me.ProgID & """, """ & Me.ControlName & """, 0, 0, 0, 0" & vbCrLf
   End If
#End If
End Sub

Public Sub ToolboxSelect(nTool As Integer)
Dim nIndex As Integer

   'This deselects on if, selects on else
   If nTool = gnToolboxTool And nTool <> 1 Then
      nIndex = 1
   Else
      nIndex = nTool
   End If
   tbToolbox.Buttons(gnToolboxTool).Value = tbrUnpressed
   gnToolboxTool = nIndex
   tbToolbox.Buttons(gnToolboxTool).Value = tbrPressed
   'CED: Put the object type in tag for global access...
   Me.Tag = tbToolbox.Buttons(gnToolboxTool).ToolTipText
End Sub
