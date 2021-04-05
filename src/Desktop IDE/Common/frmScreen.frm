VERSION 5.00
Object = "{31B71AF0-EEE4-420F-88EF-801D166BBE60}#1.0#0"; "ExMenu.dll"
Begin VB.Form frmScreen 
   AutoRedraw      =   -1  'True
   ClientHeight    =   6870
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5175
   Icon            =   "frmScreen.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MDIChild        =   -1  'True
   ScaleHeight     =   458
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   345
   Begin VB.PictureBox picHandle 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000002&
      BorderStyle     =   0  'None
      FillColor       =   &H8000000D&
      FillStyle       =   0  'Solid
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   8.25
         Charset         =   238
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000009&
      Height          =   375
      Index           =   0
      Left            =   2040
      ScaleHeight     =   375
      ScaleWidth      =   375
      TabIndex        =   2
      Top             =   5520
      Visible         =   0   'False
      Width           =   375
   End
   Begin VB.PictureBox pbScreenCont 
      Appearance      =   0  'Flat
      BackColor       =   &H00FF0000&
      ForeColor       =   &H80000008&
      Height          =   4335
      Left            =   600
      ScaleHeight     =   287
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   287
      TabIndex        =   0
      Top             =   960
      Width           =   4335
      Begin EXMENULibCtl.ExMenu menuBar 
         Height          =   390
         Left            =   120
         TabIndex        =   3
         TabStop         =   0   'False
         Top             =   3960
         Width           =   4095
         _cx             =   2010979383
         _cy             =   2010972848
         Border          =   8
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         BackColor       =   -2147483633
         ForeColor       =   -2147483641
         SelBackColor    =   12426892
         SelForeColor    =   0
         Appearance      =   0
         MenuBarBorder   =   0
         OpenMode        =   0
         ShadowColor     =   -2147483644
         PopupBackColor  =   -2147483633
         PopupForeColor  =   -2147483641
         HighLightBorderColor=   8388608
         Enabled         =   -1  'True
         PictureDisplay  =   48
         Visibility      =   100
         SepAcc          =   "     "
         OpenOnClick     =   -1  'True
         ToolTipDelay    =   500
         ToolTipPopDelay =   5000
         ToolTipWidth    =   196
         ScrollOnDrop    =   -1  'True
         AllowChevron    =   -1
         ChevronImage    =   -1
         SelectOn        =   -1
         Template        =   ""
      End
      Begin VB.PictureBox pbScreen 
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         BackColor       =   &H00C0C0C0&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   3495
         Left            =   120
         ScaleHeight     =   233
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   273
         TabIndex        =   1
         Tag             =   "Output"
         Top             =   360
         Width           =   4095
      End
      Begin VB.Image Image1 
         Height          =   360
         Left            =   15
         Picture         =   "frmScreen.frx":000C
         Stretch         =   -1  'True
         Top             =   0
         Width           =   360
      End
      Begin VB.Label lblTitlebar 
         BackColor       =   &H00FF0000&
         Caption         =   "[1120]NS Basic/CE"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   255
         Left            =   420
         TabIndex        =   4
         Tag             =   "1120"
         Top             =   75
         Width           =   2895
      End
   End
End
Attribute VB_Name = "frmScreen"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Option Compare Text
  
Private Type POINTAPI
   X As Long
   Y As Long
End Type

Private Type RECT
   Left As Long
   Top As Long
   Right As Long
   Bottom As Long
End Type

'Windows declarations
Private Declare Function SetCapture Lib "USER32" (ByVal hWnd As Long) As Long
Private Declare Function ClipCursor Lib "USER32" (lpRect As Any) As Long
Private Declare Function ReleaseCapture Lib "USER32" () As Long
Private Declare Function GetWindowRect Lib "USER32" (ByVal hWnd As Long, lpRect As RECT) As Long
Private Declare Function GetCursorPos Lib "USER32" (lpPoint As POINTAPI) As Long
Private Declare Function ScreenToClient Lib "USER32" (ByVal hWnd As Long, lpPoint As POINTAPI) As Long
Private Declare Function GetDC Lib "USER32" (ByVal hWnd As Long) As Long
Private Declare Function ReleaseDC Lib "USER32" (ByVal hWnd As Long, ByVal hDC As Long) As Long
Private Declare Function SelectObject Lib "GDI32" (ByVal hDC As Long, ByVal hObject As Long) As Long
Private Declare Function DeleteObject Lib "GDI32" (ByVal hObject As Long) As Long
Private Declare Function GetStockObject Lib "GDI32" (ByVal nIndex As Long) As Long
Private Declare Function CreatePen Lib "GDI32" (ByVal nPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long) As Long
Private Declare Function SetROP2 Lib "GDI32" (ByVal hDC As Long, ByVal nDrawMode As Long) As Long
Private Declare Function Rectangle Lib "GDI32" (ByVal hDC As Long, ByVal X1 As Long, ByVal Y1 As Long, ByVal X2 As Long, ByVal Y2 As Long) As Long
Private Declare Function SetProp Lib "USER32" Alias "SetPropA" (ByVal hWnd&, ByVal lpString$, ByVal hData&) As Long

Private Const NULL_BRUSH = 5
Private Const PS_SOLID = 0
Private Const R2_NOT = 6

Enum ControlState
   StateNothing = 0
   StateDragging
   StateSizing
End Enum

Private m_CurrCtl As Object
Private m_DragState As ControlState
Private m_DragHandle As Integer
Private m_DragRect As New CRect
Private m_DragRect2 As New CRect
Private m_DragPoint As POINTAPI

Public DesignMode As Boolean

Private Const WM_NCLBUTTONDOWN As Long = &HA1&
Private Const HTCAPTION As Long = 2&

Private Declare Function SendMessage Lib "USER32" Alias "SendMessageA" (ByVal hWnd&, ByVal wMsg&, wParam As Any, lParam As Any) As Long

Private m_bMoving As Boolean
Private m_MenuCode As String
Private CurrentMenuID As Integer
Private dragCol As New Collection

Private m_CopyObject As Object

Public FormName As String
Public FormDefault As Boolean
Public bChanged As Boolean
Private bInit As Boolean

Public bAddNewForm As Boolean
Public CreatingForm As Boolean
Private m_bLoading As Boolean

Const kScreenLeft = 5
Const kScreenTop = 5
Const kScreenWidth = 240
Const kScreenHeight = 320
Const kTitleHeight = 13
Const kTitleLineHeight = 2
Const kTitleBarHeight = 26

Public Selection As New Collection
Private m_MenuMap As New Collection
Private m_nMagFactor As Integer
Private m_bNewObject As Boolean
Private m_Form As CForm

Private Sub Form_Load()
Dim Ctl As Object
Dim trace As Boolean
trace = False

   If trace Then MsgBox "frmScreen.form_load " & 1
   Me.Move 0, 0
   LoadResStrings Me, True
   DragInit

   m_nMagFactor = 1

   Resize
   m_Form.SetOutput Me

   If trace Then MsgBox "frmScreen.form_load " & 2
   'MMD: Add Form objects here
   For Each Ctl In m_Form.Controls
      On Error Resume Next
      Ctl.Loaded = True
      On Error GoTo 0
      RestoreControl Ctl
   Next
   If trace Then MsgBox "frmScreen.form_load " & 3
   UpdateMenus
   If trace Then MsgBox "frmScreen.form_load " & 4
   Image1.Picture = frmIcon.Icon
   If trace Then MsgBox "frmScreen.form_load " & 5
   pbScreen_DrawGrid
End Sub

Public Sub Resize()
   'First set screen size and, screen menu size and location
   '+2 and -2 are for the single pixel border around the pbScreenCont
   With pbScreenCont
      .Left = kScreenLeft
      .Top = kScreenTop
      .Width = m_Form.Width + 2
      .Height = m_Form.Height + 2
      .BackColor = IIf(m_Form.MenuAtTop, &HE7DFE7, vbBlue)
   End With
   With menuBar
      .Left = 0
      .Height = 26
      .Width = pbScreenCont.ScaleWidth
      If m_Form.MenuAtTop Then
         .Top = 0 'kTitleBarHeight
'         pbScreen.Top = .Top + .Height
      Else
         .Top = pbScreenCont.ScaleHeight - .Height
'         pbScreen.Top = kTitleBarHeight
      End If
   End With
   With pbScreen
      .Left = 0
      .Top = kTitleBarHeight
      .Width = pbScreenCont.Width
#If NSBasic_Desktop Then
      .Height = pbScreenCont.Height - menuBar.Height - 2
#Else
      .Height = pbScreenCont.Height - menuBar.Height - (2 + kTitleBarHeight)
#End If
   End With

   'Now set window size
   If Me.WindowState = vbNormal Then
      With Me
         .Width = (2 * kScreenLeft + m_Form.Width + 10) * Screen.TwipsPerPixelX
         .Height = (2 * kScreenTop + m_Form.Height + 36) * Screen.TwipsPerPixelY
      End With
   End If
End Sub

Private Sub Form_Activate()
   If gbUpdatefrmScreen Then frmMain.ActiveFormChange 1
   frmMain.ActiveFormIsCode = False
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
   'This coordinate (-44, -44) automatically clears coordinates
   If frmMain.ActiveForm Is Me And Selection.Count <> 1 Then ShowCoordinates -44, -44
End Sub

Private Sub Form_Resize()
'#If NSBasic_Desktop Then
'   If Not m_bLoading Then
'      m_Form.Width = Me.Width / Screen.TwipsPerPixelX - 10 - 2 * kScreenLeft
'      m_Form.Height = Me.Height / Screen.TwipsPerPixelY - 36 - 2 * kScreenTop
'      If m_Form.Height < 26 Then m_Form.Height = 26
'   Resize
'   End If
'#End If
#If NSBasic_CE Then
   If WindowState = vbNormal Then
      With Me
         .Width = (2 * kScreenLeft + m_Form.Width + 10) * Screen.TwipsPerPixelX
         .Height = (2 * kScreenTop + m_Form.Height + 36) * Screen.TwipsPerPixelY
      End With
   End If
#End If
End Sub

'Private Sub Form_GotFocus()
'''''   Set gCurrentForm = Me
'Beep
'Debug.Print "frmScreen.Form_GotFocus()"

'''   frmProperties.FocusMoved
'End Sub

'''Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
'''Dim i As Integer
'''
'''   On Error GoTo geterr
'''   frmProperties.FocusMoved
'''   If Button = vbLeftButton And m_bDesignMode Then
'''      'Hit test over light-weight (non-windowed) controls
'''      For i = 0 To (Controls.Count - 1)
'''         If Not TypeOf Controls(i) Is menu And Controls(i).Visible And Not Controls(i).Name = "picHandle" Then
'''            m_DragRect.SetRectToCtrl Controls(i)
'''            If m_DragRect.PtInRect(X, Y) Then
'''               DragBegin Controls(i)
'''               Exit Sub
'''            End If
'''         End If
'''      Next i
'''
'''geterr:
'''      'No control is active
'''      CurrentControl = Nothing
'''      'Hide sizing handles
'''      ShowHandles False
'''      manager.Resized Me, FormName
'''      MDIForm1.PosControl 0, 0
'''      MDIForm1.SizeControl 0, 0
'''   End If
'''
'''   If Button = vbRightButton Then
'''      If Not m_CopyObject Is Nothing Then
'''         MDIForm1.mnuCopyCtl.Enabled = False
'''         MDIForm1.mnuPasteCtl.Enabled = True
'''         MDIForm1.mnuDeleteCtl.Enabled = False
'''         PopupMenu MDIForm1.mnuContrMenu
'''      End If
'''   End If
'''End Sub

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
'Beep
'Debug.Print "frmScreen.Form_KeyDown"
   If KeyCode = vbKeyV And (Shift And vbCtrlMask) Then ' Copy Control
'''      If Not m_CopyObject Is Nothing Then
'''         AddControl TypeName(m_CopyObject), m_CopyObject
'''      End If
   End If
   If KeyCode = vbKeyC And (Shift And vbCtrlMask) Then ' Paste Control
'''      CopyCtl m_CurrCtl
   End If
   If KeyCode = vbKeyDelete Or KeyCode = vbKeyBack Then ' Delete control
''''       ShowHandles False
''''       manager.DELETE m_CurrCtl
''''       manager.Resized Me, FormName
      Delete
   End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
Dim obj As Object

   If m_Form Is Nothing Then Exit Sub

   m_Form.Unload

   ClearSelection False
'''''   For Each obj In m_Form.ObjectCollection
'''''      obj.obj.Control = Nothing
'''''   Next
'MMD: I don't like this code
   frmMain.RemoveMDIChild Me.Tag
   If gbProperties Then gfProperties.Object = Nothing
   frmMain.ActiveFormChange 0
End Sub

Private Sub menuBar_Select(ByVal ID As Long)
   ViewCode m_Form.GlobalID, m_MenuMap(Trim(Str(ID))) & "_Click"
End Sub

Private Sub pbScreen_Click()
   If m_bNewObject Then
      m_bNewObject = False
   Else
      If m_DragState = StateNothing And gnToolboxTool = 1 Then ClearSelection
      m_DragState = StateNothing
   End If
End Sub

Private Sub pbScreen_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
   CurrentControl = Nothing
End Sub

Private Sub pbScreen_DrawGrid()
Dim row As Integer
Dim col As Integer

   If m_Form Is Nothing Then Exit Sub

   pbScreen.Cls

   'Now paint the grid
   If gbWantGrid Then
      With pbScreen
         .DrawMode = vbCopyPen
         .DrawStyle = vbSolid
         .DrawWidth = 1

         For row = 0 To m_Form.Height Step gnGridIncr
            For col = 0 To m_Form.Width Step gnGridIncr
               pbScreen.PSet (col, row), vbGrayText
            Next
         Next
      End With
   End If
End Sub

Public Sub ClearSelection(Optional bDisplaySelection As Boolean = True)
Dim filename As String
Dim dirName As String
   
   While Selection.Count > 0
   
      If 1 = 0 Then
      'If it's a gradientButton, save its image as a file, then inject it as a resource
      If Selection(1).CEType = "GradientButton" Then
         Set Selection(1).Ctl.Picture = CaptureWindow(Selection(1).Ctl.hWnd, True, 0, 0, Selection(1).Ctl.Width, Selection(1).Ctl.Height)
         filename = gTarget.Name & "_" & Selection(1).Name & ".bmp"
         SavePicture Selection(1).Ctl.Picture, filename
         'Debug.Print filename & " saved."
      End If
      End If

      Selection.Remove 1
   Wend
   
   ShowHandles False
   If bDisplaySelection Then DisplaySelection
   ShowCoordinates -44, -44
   ShowDimensions -44, -44
End Sub

Public Sub AddSelectionItem(ByVal obj As Object)
   Selection.Add obj, obj.GlobalID
   DisplaySelection
End Sub

Public Sub SetSelection(ByVal obj As Object)
   ClearSelection False
   AddSelectionItem obj
End Sub

Public Sub RemoveSelectionItem(ByVal obj As Object)
   Selection.Remove obj.obj.GlobalID
   DisplaySelection
End Sub

Public Sub DisplaySelection()
   Select Case Selection.Count
   Case 0
      If gbProjectExplorer Then gfProjectExplorer.ShowActive m_Form
      If gbProperties Then gfProperties.Object = m_Form
      ShowCoordinates -44, -44
      ShowDimensions -44, -44
   Case 1
      If gbProjectExplorer Then gfProjectExplorer.ShowActive Selection(1)
      If gbProperties Then gfProperties.Object = Selection(1)
      ShowCoordinates Selection(1).Left, Selection(1).Top
      ShowDimensions Selection(1).Width, Selection(1).Height
   Case Else
      If gbProjectExplorer Then gfProjectExplorer.ShowActive m_Form
      If gbProperties Then gfProperties.Object = Nothing
      ShowCoordinates -44, -44
      ShowDimensions -44, -44
   End Select
End Sub

Public Sub MouseMoveSelection(ByRef X As Integer, ByRef Y As Integer, nLeft As Integer, nTop As Integer, Optional ByVal obj As Object = Nothing, Optional nForceGrid As Integer = 0)
Dim baseX As Integer, baseY As Integer
Dim bGridPref As Boolean

   'bGridPref allows temporary suspension/enforcement of grid
   bGridPref = gbWantGrid
   Select Case nForceGrid
   Case vbShiftMask: gbWantGrid = True
   Case vbCtrlMask: gbWantGrid = False
   End Select

   'Coordinate + delta gives proposed new coordinate
   'SnapToGrid finds nearest grid coordinate (GC) to proposed new coordinate
   'Subtracting current position from nearest GC determines how much we should move
   X = SnapToGrid(nLeft + X) - nLeft
   Y = SnapToGrid(nTop + Y) - nTop

   If obj Is Nothing Then
      For Each obj In Selection
         obj.Left = obj.Left + X
         obj.Top = obj.Top + Y
      Next
   Else
      obj.Left = obj.Left + X
      obj.Top = obj.Top + Y
   End If
   gbWantGrid = bGridPref
End Sub

Public Sub ResizeSelectionToGrid(Optional ByVal obj As Object = Nothing, Optional nForceGrid As Integer = 0)
Dim bGridPref As Boolean

   'bGridPref allows temporary suspension/enforcement of grid
   bGridPref = gbWantGrid
   Select Case nForceGrid
   Case vbShiftMask: gbWantGrid = True
   Case vbCtrlMask: gbWantGrid = False
   End Select

   If obj Is Nothing Then
      For Each obj In Selection
         MouseMoveSelection 0, 0, obj.Left, obj.Top, obj
         obj.Width = SnapToGrid(obj.Width)
         obj.Height = SnapToGrid(obj.Height)
      Next
   Else
      MouseMoveSelection 0, 0, obj.Left, obj.Top, obj
      obj.Width = SnapToGrid(obj.Width)
      obj.Height = SnapToGrid(obj.Height)
   End If
   gbWantGrid = bGridPref
End Sub

Public Sub Format(nType As Integer, nStyle As Integer)
Dim obj As Object
Dim i As Integer
Dim nMax As Integer, nMin As Integer, nSpc As Integer, nOff As Integer

   Select Case nType
   Case 0 'Align
''      For Each obj In Selection
''         Select Case nStyle
''         Case 0 'Lefts
''            obj.obj.OrigLeft = Selection(1).obj.OrigLeft
''         Case 1 'Centers
''            obj.obj.OrigLeft = Selection(1).obj.OrigLeft + (Selection(1).obj.Width - obj.obj.Width) \ 2
''         Case 2 'Rights
''            obj.obj.OrigLeft = (Selection(1).obj.OrigLeft + Selection(1).obj.Width) - obj.obj.Width
''         Case 4 'Tops
''            obj.obj.OrigTop = Selection(1).obj.OrigTop
''         Case 5 'Middles
''            obj.obj.OrigTop = Selection(1).obj.OrigTop + (Selection(1).obj.Height - obj.obj.Height) \ 2
''         Case 6 'Bottoms
''            obj.obj.OrigTop = (Selection(1).obj.OrigTop + Selection(1).obj.Height) - obj.obj.Height
''         Case 8 'To Grid
''            MouseMoveSelection 0, 0, obj.obj.OrigLeft, obj.obj.OrigTop, obj, vbShiftMask
''         End Select
''         obj.ScreenDraw
''      Next
''   Case 1 'Same Size
''      For Each obj In Selection
''         Select Case nStyle
''         Case 0 'Width
''            obj.obj.Width = Selection(1).obj.Width
''         Case 1 'Height
''            obj.obj.Height = Selection(1).obj.Height
''         Case 2 'Both
''            obj.obj.Width = Selection(1).obj.Width
''            obj.obj.Height = Selection(1).obj.Height
''         End Select
''         obj.ScreenDraw
''      Next
   Case 2 'Size To Grid
      For Each obj In Selection
         ResizeSelectionToGrid obj, vbShiftMask
      Next
''   Case 3 'Horizontal Spacing
''      'Only need to do this stuff for equal spacing
''      If nStyle = 0 Then
''         If Selection.Count < 3 Then Exit Sub
''
''         'Initialize Min/Max, and make first pass to determine values
''         nMax = 0: nMin = Object.Width
''         For Each obj In Selection
''            If obj.obj.OrigLeft < nMin Then nMin = obj.obj.OrigLeft
''            If obj.obj.OrigLeft > nMax Then nMax = obj.obj.OrigLeft
''         Next
''         nSpc = (nMax - nMin) \ (Selection.Count - 1)
''      End If
''
''      'Cycle through selection and move objects accordingly
''      For i = 1 To Selection.Count
''         Select Case nStyle
''         Case 0 'Equal
''            Selection(i).obj.OrigLeft = nMin + (i - 1) * nSpc
''         Case 1 'Increase
''            Selection(i).obj.OrigLeft = Selection(i).obj.OrigLeft + (i - 1) * (gnGridIncr \ 2)
''         Case 2 'Decrease
''            Selection(i).obj.OrigLeft = Selection(i).obj.OrigLeft - (i - 1) * (gnGridIncr \ 2)
''         Case 3 'Remove
''            If i > 1 Then Selection(i).obj.OrigLeft = Selection(i - 1).obj.OrigLeft + Selection(i - 1).obj.Width
''         End Select
''         Selection(i).ScreenDraw
''      Next
''   Case 4 'Vertical Spacing
''      'Only need to do this stuff for equal spacing
''      If nStyle = 0 Then
''         If Selection.Count < 3 Then Exit Sub
''
''         'Initialize Min/Max, and make first pass to determine values
''         nMax = 0: nMin = Object.Height
''         For Each obj In Selection
''            If obj.obj.OrigTop < nMin Then nMin = obj.obj.OrigTop
''            If obj.obj.OrigTop > nMax Then nMax = obj.obj.OrigTop
''         Next
''         nSpc = (nMax - nMin) \ (Selection.Count - 1)
''      End If
''
''      'Cycle through selection and move objects accordingly
''      For i = 1 To Selection.Count
''         Select Case nStyle
''         Case 0 'Equal
''            Selection(i).obj.OrigTop = nMin + (i - 1) * nSpc
''         Case 1 'Increase
''            Selection(i).obj.OrigTop = Selection(i).obj.OrigTop + (i - 1) * (gnGridIncr \ 2)
''         Case 2 'Decrease
''            Selection(i).obj.OrigTop = Selection(i).obj.OrigTop - (i - 1) * (gnGridIncr \ 2)
''         Case 3 'Remove
''            If i > 1 Then Selection(i).obj.OrigTop = Selection(i - 1).obj.OrigTop + Selection(i - 1).obj.Height
''         End Select
''         Selection(i).ScreenDraw
''      Next
   Case 5 'Center
      Select Case nStyle
      Case 0 'Horizontally
         'Initialize Min/Max, and make first pass to determine values
         nMax = 0: nMin = Object.Width
         For Each obj In Selection
            If obj.Left < nMin Then nMin = obj.Left
            If (obj.Left + obj.Width) > nMax Then nMax = (obj.Left + obj.Width)
         Next
         nOff = (Object.Width - (nMax - nMin)) \ 2

         For Each obj In Selection
            obj.Left = (obj.Left - nMin) + nOff
         Next
      Case 1 'Vertically
         'Initialize Min/Max, and make first pass to determine values
         nMax = 0: nMin = Object.Height - 20
         For Each obj In Selection
            If obj.Top < nMin Then nMin = obj.Top
            If (obj.Top + obj.Height) > nMax Then nMax = (obj.Top + obj.Height)
         Next
         nOff = (Object.Height - 20 - (nMax - nMin)) \ 2

         For Each obj In Selection
            obj.Top = (obj.Top - nMin) + nOff
         Next
      End Select
''   Case 6 'Order
''      Select Case nStyle
''      Case 0 'Front
''      Case 1 'Forward
''      Case 2 'Backward
''      Case 3 'Back
''      End Select
   End Select
   If gbProperties Then
      gfProperties.Object = Nothing
      DisplaySelection
   End If
   If picHandle(1).Visible Then
      ShowHandles False
      ShowHandles True
   End If
End Sub

Public Sub SetCaption()
   'Since we've gone to single project editing, no need to attach project name
'   Me.Caption = m_Form.Project.Name & " - Form (" & m_Form.Name & ")"
Dim trace As Boolean
trace = False
If trace Then MsgBox "frmScreen.SetCaption " & 1
   Me.Caption = m_Form.Name
If trace Then MsgBox "frmScreen.SetCaption " & 2
End Sub

Public Sub UpdateScreen()
   pbScreen.Refresh
   If picHandle(1).Visible Then
      ShowHandles False
      ShowHandles
   End If
   SetCaption
End Sub

Public Sub UpdateMenus()
Dim Engine As New CIDEEngine

   menuBar.Items.Clear
   Set m_MenuMap = New Collection
   If Len(m_Form.FormMenu) > 0 Then Engine.ParseSetMenu Me, m_Form.FormMenu
   menuBar.Refresh
End Sub

Public Function SnapToGrid(nVal As Integer) As Integer
   If gbWantGrid Then
      SnapToGrid = ((nVal + gnGridIncr \ 2) \ gnGridIncr) * gnGridIncr
   Else
      SnapToGrid = nVal
   End If
End Function

Public Sub Save()
Debug.Assert False
End Sub

Public Sub Cut()
   If Selection.Count = 0 Then Exit Sub
   Copy
   Delete
End Sub

Public Sub Copy()
Dim strClip As String
Dim strTemp As String
Dim obj As Object

   If Selection.Count = 0 Then
      strClip = m_Form.Copy
   Else
      If Selection.Count = 1 And TypeName(Selection(1)) = "CForm" Then
         strClip = m_Form.Copy
      Else
         For Each obj In Selection
            strTemp = obj.Name
            strClip = strClip & """Object""" & obj.Name & vbCrLf
            obj.Name = Right(kProductExtension, 3) & strTemp
            If TypeName(obj) = "CPictureBox - not!" Then
               strClip = strClip & obj.GenerateCode(obj.Name)
            Else
               strClip = strClip & obj.GenerateCode("   " & obj.Name)
            End If
            obj.Name = strTemp
         Next
      End If
   End If
   Clipboard.SetText kClipboardHeader & vbCrLf & strClip
End Sub

Public Function ValidPaste() As Boolean
   ValidPaste = (ValidClipboard = kClipboardObject)
End Function

Public Sub Paste()
Dim arrLines() As String
Dim strObjName As String
Dim strPasteObj As String
Dim strCopy As String
Dim i As Integer
Dim Engine As New CIDEEngine
Dim par As Object

   If ValidClipboard <> kClipboardObject Then Exit Sub
   arrLines = Split(Clipboard.GetText, vbCrLf)
   strObjName = Mid(arrLines(1), InStr(2, arrLines(1), """") + 1)
   If gTarget.ValidObjectName(strObjName) = "" Then
      'paste as is
      strPasteObj = strObjName
   ElseIf gTarget.ValidObjectName(strObjName & "_Copy") = "" Then
      'paste as _Copy
      strPasteObj = strObjName & "_Copy"
   Else
      'Look for _Copy#
      For i = 1 To 100
         If gTarget.ValidObjectName(strObjName & "_Copy" & i) = "" Then
            strPasteObj = strObjName & "_Copy" & i
            Exit For
         End If
      Next
   End If

   'Eliminate clipboard header
   arrLines(0) = "": arrLines(1) = ""
   strCopy = Trim(Join(arrLines, vbCrLf))
   strCopy = Replace(strCopy, """" & Right(kProductExtension, 3) & strObjName & """", """" & strPasteObj & """")
   strCopy = Replace(strCopy, Right(kProductExtension, 3) & strObjName & ".", strPasteObj & ".")
   If CurrentControl Is Nothing Then
      strCopy = Replace(strCopy, Right(kProductExtension, 3) & strObjName, m_Form.Name)
      Set par = m_Form
   Else
      If TypeName(CurrentControl) = "CFrame" Then
         strCopy = Replace(strCopy, Right(kProductExtension, 3) & strObjName, CurrentControl.Name)
         Set par = CurrentControl
      Else
         CurrentControl = Nothing
         strCopy = Replace(strCopy, Right(kProductExtension, 3) & strObjName, m_Form.Name)
         Set par = m_Form
      End If
   End If
   #If NSBasic_Desktop Then
   strCopy = "GetCommandLine=""     "" " & vbCrLf & strCopy
   #End If
   Engine.PasteObject Me, strCopy, par
End Sub

Public Sub Delete()
   If m_CurrCtl Is Nothing Or Selection.Count = 0 Then Exit Sub
   ClearSelection
   m_Form.RemoveObject m_CurrCtl.Name
   If gbProjectExplorer Then gfProjectExplorer.RemoveNode m_CurrCtl.GlobalID
   m_CurrCtl.DeleteObject
   Set m_CurrCtl = Nothing
   m_Form.Project.Dirty = True
End Sub

''''Public Sub SelectAll()
''''Dim obj As Object
''''
''''   ClearSelection
''''   For Each obj In m_Form.ObjectCollection
''''      AddSelectionItem obj
''''   Next
''''End Sub

Public Property Get Dirty() As Boolean
   Dirty = False
End Property

''''
'''' *** OUTPUT ***
''''
  
Public Sub ApplyGrid(frm As Form)
Dim i As Integer
Dim j As Integer

   With frm
      For i = 0 To .Height \ Screen.TwipsPerPixelY Step gnGridIncr
         For j = 0 To .Width \ Screen.TwipsPerPixelX Step gnGridIncr
            PSet (j, i)
         Next
      Next
   End With
End Sub

Public Sub RestoreControl(obj As Object, Optional par As Object = Nothing)
Dim Ctl As Object
  
   On Error GoTo errHand
   obj.SetForm Me
   Set Ctl = obj.AddObject(obj.ClassID, obj.Name, obj.Left, obj.Top, obj.Width, obj.Height)
   If Ctl Is Nothing Then Exit Sub
   If par Is Nothing Then
      Set Ctl.Container = pbScreen
   Else
      Set Ctl.Container = par.Ctl
   End If

   With Ctl
      .ZOrder
      .Visible = True
   End With

   On Error GoTo 0
   bChanged = False
   DoEvents

   PlaceControl Ctl
   ShowHandles False
   Exit Sub

errHand:
'   LogErr "0x" & Hex(err.Number) & ": (" & Erl & ") " & err.Source & " - " & err.Description
'   LogErr vbTab & "RestoreControl - " & m_Form.Name & "." & obj.Name
   Resume Next
End Sub

Public Function AddObject(ByVal astrType As String, ByVal astrName As String, ByVal X As Integer, ByVal Y As Integer, ByVal W As Integer, ByVal H As Integer, ByVal par As Object) As Object
Dim obj As Object, Ctl As Object
''Dim cont As Object, fCont As Object

   'Initialize return value
   Set AddObject = Nothing

''   For Each fCont In m_Form.Controls
''      If X >= fCont.Left And X < fCont.Left + fCont.Width _
''      And Y >= fCont.Top And Y < fCont.Top + fCont.Height _
''      And (TypeName(fCont) = "CFrame" Or TypeName(fCont) = "CActiveXCtl") Then
''         Set cont = fCont
''      End If
''   Next
''   If Not cont Is Nothing Then MsgBox cont.Name, vbInformation, TypeName(cont)
      
   'This is for the new frame based form
   If LCase(astrType) = "frame" And astrName = Object.Name & "_Form" And par Is Nothing Then
      Set AddObject = m_Form.Output
      Exit Function
   End If
   If LCase(astrName) = LCase(Object.Name) And par Is m_Form.Output Then
      Set AddObject = m_Form.Output
      Exit Function
   End If

   'First create the program object
   Set obj = CreateObjectEx(astrType)
   obj.SetForm Me
   obj.GlobalID = m_Form.GetGlobalID
   If TypeName(obj) = "CActiveXCtl" Then obj.Loaded = CreatingForm

   'Use program object to create control
   On Error Resume Next
   err.Clear
   Set Ctl = obj.AddObject(astrType, astrName, X, Y, W, H)
   If err <> 0 Or Ctl Is Nothing Then
      MsgBox gStringTable(3420) & astrType '"Unable to create control: " & astrType
      Exit Function
   End If
   If Not CreatingForm Then
      obj.SetProperty ("Visible"), True
   End If
   If par Is Nothing Or par Is m_Form Or par Is m_Form.Output Then
      'do nothing
      Set par = m_Form
      m_Form.AddObject obj

      Set Ctl.Container = pbScreen
   Else
      'do something
      par.AddControl obj
      Set Ctl.Container = par.Ctl
   End If
   
   'Add the object to project explorer and display in properties window
   If gbProjectExplorer Then gfProjectExplorer.AddNewControl obj, par

   With Ctl
      .ZOrder
      .Visible = True
   End With
   bChanged = False
   DoEvents
   PlaceControl Ctl
   CurrentControl = obj
   Set AddObject = obj
End Function

Public Function AddControl(astrProgID As String, astrName As String, ByVal X As Integer, ByVal Y As Integer, ByVal bLoad As Boolean, ByVal par As Object) As Boolean
Dim sName As String
Dim Ctl As Object

   AddControl = False

   X = SnapToGrid(X)
   Y = SnapToGrid(Y)
   
   sName = CheckName(astrName)
   Set Ctl = AddObject(astrProgID, sName, X, Y, Me.TextWidth(sName) + 24, Me.TextHeight("1") + 8, par)
   AddControl = Not Ctl Is Nothing
End Function

Public Function CheckName(ByVal astrName As String) As String
'Dim ctl As Object
Dim Num As Integer
'Dim lForm As CForm
'Dim SearchLen As Integer
'Dim ContrCounter As Integer
Dim arrName() As String

'   On Error GoTo getCheckerr
'   SearchLen = 0
   arrName = Split(astrName, ".")
   If UBound(arrName) > 0 Then astrName = arrName(1)

   For Num = 1 To 1000
      CheckName = astrName & Num
      If gTarget.ValidObjectName(CheckName) = "" Then Exit Function
   Next
'   For Each lForm In gTarget.Forms
'      For Each ctl In lForm.Controls
'         If Left(ctl.Name, Len(sName)) = sName Then
'            SearchLen = Len(sName)
'         ElseIf Left(ctl.Name, Len(sName & "Ctl")) = sName & "Ctl" Then
'            SearchLen = Len(sName & "Ctl")
'         End If
'         If SearchLen > 0 Then
'            ContrCounter = Right(ctl.Name, Len(ctl.Name) - SearchLen)
'            If IsNumeric(ContrCounter) Then
'               If ContrCounter > Num Then
'                  Num = ContrCounter
'               Else
'                  Num = 1
'               End If
'               SearchLen = 0
'            End If
'         End If
'      Next
'   Next
'   CheckName = sName & Num + 1

getCheckerr:

End Function

Public Property Get MenuCode() As String
   MenuCode = m_MenuCode
End Property

Public Property Let MenuCode(ByVal strMenu As String)
Dim arrMenu() As String
Dim arrCode() As String
Dim sName As String
Dim sMenu As String
Dim vPassMenu As Variant
Dim i As Integer, j As Integer

   m_MenuCode = strMenu
   If strMenu = "" Then
      menuBar.Items.Clear
      Exit Property
   End If

   ' Parse generated code and show menu in the design mode
   menuBar.Items.Clear
   arrMenu = Split(m_MenuCode, vbCrLf)
   For i = 0 To UBound(arrMenu)
      arrCode = Split(arrMenu(i), ",")
      If UBound(arrCode) <> -1 Then
'''      sName = ExtractMenu(CStr(arrCode(0)))
'''      sMenu = ExtractMenu(CStr(arrCode(1)))
      For j = 2 To UBound(arrCode)
'''         sMenu = sMenu & "," & ExtractMenu(CStr(arrCode(j)))
      Next
      vPassMenu = Split(sMenu, ",")
      SetMenu sName, vPassMenu
      End If
   Next
   menuBar.Refresh
'   gForms(FormName).FormMenu = m_MenuCode
End Property

Public Sub SetMenu(astrName As String, avMenu As Variant)
Dim mi As EXMENULibCtl.Item
Dim mip As EXMENULibCtl.Item
Dim arrItem() As String
Dim i As Integer
Dim col As New Collection

   If StrComp(astrName, "TitleBar", vbTextCompare) = 0 Then
      AddMainMenu avMenu
      Exit Sub
   End If

   On Error Resume Next
   'This is a breadth first search... ugh!
   For Each mip In menuBar.Items
      col.Add mip
   Next
   Do While col.Count > 0
      Set mip = col.Item(1)
      col.Remove 1
      If m_MenuMap(Trim(Str(mip.ID))) = astrName Then Exit Do
      If mip.Popup Then
         For Each mi In mip.SubMenu
            col.Add mi
         Next
      End If
   Loop
   If err <> 0 Or mip Is Nothing Then
      MsgBox gStringTable(3366) & astrName 'Unable to find parent menu:
      Exit Sub
   End If
   mip.Popup = True
   On Error GoTo 0

   'Check if they try to rebuild existing menu
   For i = 0 To UBound(avMenu)
      If Left(avMenu(i), 1) = "-" Then
         'Menu separator
         mip.SubMenu.Add "", 1
      Else
         'Standard menu item
         'Menu string is either '<Caption>' or '<Caption>||<Identifier>'
         'If no explicit identifier is given, use the caption as a default
         arrItem = Split(avMenu(i), "||")
         Set mi = mip.SubMenu.Add(arrItem(0))

         'Add the newly created menu item to local maps
         m_MenuMap.Add arrItem(IIf(UBound(arrItem), 1, 0)), Trim(Str(mi.ID)) ',
      End If
   Next
   menuBar.Refresh
End Sub

Public Function CheckMenu(sMenu) As Integer
'  Dim i As Integer
'  Dim subMenu As Collection
'  Dim vMenu
'  i = 1
'  CheckMenu = -1
'  On Error GoTo Skip
'  'Set subMenu = mToolMenus(sMenu)
'  For Each vMenu In subMenu
'       oForm.tvMenuBar1.MenuItems.Remove vMenu
'       'mMenus.Remove CStr(i)
'       'i = i + 1
'  Next
'  mToolMenus.Remove (sMenu)
'  Exit Function
'Skip:
End Function

Public Sub AddMainMenu(avMenu As Variant)
Dim i As Integer
Dim arrItem() As String
Dim mi As EXMENULibCtl.Item

   'Loop through menu items and add to the root level menu
   For i = 0 To UBound(avMenu)
      'Menu string is either '<Caption>' or '<Caption>||<Identifier>'
      'If no explicit identifier is given, use the caption as a default
      arrItem = Split(avMenu(i), "||")
      Set mi = menuBar.Items.Add(arrItem(0))
      mi.ShowDown = gMenuTop 'True '(m_strPlatform <> "PocketPC")

      'Add the newly created menu item to local maps
'      m_MenuIDMap.Add arrItem(IIf(UBound(arrItem), 1, 0)), Str(mi.ID)
      m_MenuMap.Add arrItem(IIf(UBound(arrItem), 1, 0)), Trim(Str(mi.ID))
   Next
   menuBar.Refresh
End Sub

'Initialization -- Do not call more than once
Private Sub DragInit()
Dim i As Integer
Dim xHandle As Single
Dim yHandle As Single

   'Use black Picture box controls for 8 sizing handles
   'Calculate size of each handle
   xHandle = 7 '* Screen.TwipsPerPixelX
   yHandle = 7 '* Screen.TwipsPerPixelY
   'Load array of handles until we have 8
   For i = 0 To 7
      If i <> 0 Then
         Load picHandle(i)
      End If
      picHandle(i).Width = xHandle
      picHandle(i).Height = yHandle
      'Must be in front of other controls
      picHandle(i).Line (1, 1)-(Screen.TwipsPerPixelX * picHandle(i).Width - 10, Screen.TwipsPerPixelY * picHandle(i).Height - 10), vbWhite, B
      picHandle(i).ZOrder
   Next i
   'Set mousepointers for each sizing handle
   picHandle(0).MousePointer = vbSizeNWSE
   picHandle(1).MousePointer = vbSizeNS
   picHandle(2).MousePointer = vbSizeNESW
   picHandle(3).MousePointer = vbSizeWE
   picHandle(4).MousePointer = vbSizeNWSE
   picHandle(5).MousePointer = vbSizeNS
   picHandle(6).MousePointer = vbSizeNESW
   picHandle(7).MousePointer = vbSizeWE
   'Initialize current control
   CurrentControl = Nothing
End Sub

'Drags the specified control
Public Sub DragBegin(Ctl As Object)
Dim rc As RECT

   'Hide any visible handles
   Me.SetFocus
   ShowHandles False
   'Save reference to control being dragged
   CurrentControl = Ctl
   'Store initial mouse position
   GetCursorPos m_DragPoint
   'Save control position (in screen coordinates)
   'Note: control might not have a window handle
   m_DragRect.SetRectToCtrl m_CurrCtl, pbScreen.hWnd
   
   'Make initial mouse position relative to control
   m_DragPoint.X = m_DragPoint.X - m_DragRect.Left
   m_DragPoint.Y = m_DragPoint.Y - m_DragRect.Top

   'Force redraw of form without sizing handles
   'before drawing dragging rectangle
   Refresh
   'Show dragging rectangle
   DrawDragRect
   'Indicate dragging under way
   m_DragState = StateDragging

   'In order to detect mouse movement over any part of the form,
   'we set the mouse capture to the form and will process mouse
   'movement from the applicable form events
   ReleaseCapture  'This appears needed before calling SetCapture
   SetCapture pbScreen.hWnd
   'Limit cursor movement within form
   GetWindowRect pbScreen.hWnd, rc
   ClipCursor rc
   If gbProperties Then gfProperties.Object = m_CurrCtl
End Sub

'To handle all mouse message anywhere on the form, we set the mouse
'capture to the form. Mouse movement is processed here
Private Sub pbScreen_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim nWidth As Single, nHeight As Single
Dim pt As POINTAPI

   If gnToolboxTool <> 1 Then
      pbScreen.MousePointer = vbCrosshair
   Else
      pbScreen.MousePointer = vbDefault
   End If
   If frmMain.ActiveForm Is Me And Selection.Count = 0 Then ShowCoordinates X \ m_nMagFactor, Y \ m_nMagFactor

   If m_DragState = StateDragging Then
      'Save dimensions before modifying rectangle
      nWidth = m_DragRect.Right - m_DragRect.Left
      nHeight = m_DragRect.Bottom - m_DragRect.Top
      'Get current mouse position in screen coordinates
      GetCursorPos pt
      
      'Hide existing rectangle
      DrawDragRect
      'Update drag rectangle coordinates
      m_DragRect.Left = pt.X - m_DragPoint.X
      m_DragRect.Top = pt.Y - m_DragPoint.Y
      m_DragRect.Right = m_DragRect.Left + nWidth
      m_DragRect.Bottom = m_DragRect.Top + nHeight
      
      'Draw new rectangle
      DrawDragRect

      ShowCoordinates m_DragRect.Left, m_DragRect.Top
      ShowDimensions (nWidth), (nHeight)
   ElseIf m_DragState = StateSizing Then
      'Get current mouse position in window coordinates
      GetCursorPos pt
      ScreenToClient pbScreen.hWnd, pt
      'Hide existing rectangle
      DrawDragRect
      'Action depends on handle being dragged
      Select Case m_DragHandle
      Case 0
         m_DragRect.Left = pt.X
         m_DragRect.Top = pt.Y
      Case 1
         m_DragRect.Top = pt.Y
      Case 2
         m_DragRect.Right = pt.X
         m_DragRect.Top = pt.Y
      Case 3
         m_DragRect.Right = pt.X
      Case 4
         m_DragRect.Right = pt.X
         m_DragRect.Bottom = pt.Y
      Case 5
         m_DragRect.Bottom = pt.Y
      Case 6
         m_DragRect.Left = pt.X
         m_DragRect.Bottom = pt.Y
      Case 7
         m_DragRect.Left = pt.X
      End Select
      'Draw new rectangle
      DrawDragRect
   End If
End Sub

'To handle all mouse message anywhere on the form, we set the mouse
'capture to the form. Mouse up is processed here
Private Sub pbScreen_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim pointX As Integer
Dim pointY As Integer
Dim bAdd As Boolean
Dim obj As Object, parent As Object

'*** FROM MDI
   If Shift <> 0 Then Exit Sub
   'Don't do anything with the pointer tool
   If gnToolboxTool <> 1 Then

      'Add the object to project explorer and display in properties window
'''''   If gbProjectExplorer Then gfProjectExplorer.AddNewControl ob, m_Form
         
      If TypeName(CurrentControl) = "CFrame" Then 'Or TypeName(CurrentControl) = "CActiveXCtl" Then
'Debug.Print "pbScreen: Mouse Up Event - "; TypeName(CurrentControl)
         Set parent = CurrentControl
         m_DragRect2.SetRectToCtrl parent, pbScreen.hWnd
         X = X - m_DragRect2.Left
         Y = Y - m_DragRect2.Top
      Else
         Set parent = Nothing
      End If
      'Need to add object to the form object
      bAdd = AddControl(gfToolbox.ProgID, gfToolbox.ControlName, X, Y, False, parent)

      'Reset the toolbox tool
      gfToolbox.ToolboxSelect 1
      pbScreen.MousePointer = vbDefault

      If Not bAdd Then Exit Sub

      'Select the object
      DoEvents

      ClearSelection
      'Select the newly created object
      SetSelection m_CurrCtl
'      DisplaySelection

      m_bNewObject = True
      Exit Sub
   End If

'*** LEFT OVER
   If Button = vbRightButton Then
      frmMain.RightClickMenu 1, m_Form.GlobalID
      Exit Sub
   End If

'*** FROM CED ***
   'Must be a Left-Click in Drag or Resize state
   If Button <> vbLeftButton Then Exit Sub
   If m_DragState <> StateDragging And m_DragState <> StateSizing Then
      ClearSelection
      Exit Sub
   End If

   DragEnd
End Sub

Sub DragEnd()
   If m_DragState <> StateDragging And m_DragState <> StateSizing Then Exit Sub

   'Hide drag rectangle
   DrawDragRect

   If gbWantGrid Then
      'this is snap to grid
      m_DragRect.Left = SnapToGrid(m_DragRect.Left)
      m_DragRect.Top = SnapToGrid(m_DragRect.Top)
      If m_DragState = StateSizing Then
         m_DragRect.Height = SnapToGrid(m_DragRect.Height)
         m_DragRect.Width = SnapToGrid(m_DragRect.Width)
      Else
         m_DragRect.Height = m_CurrCtl.Height
         m_DragRect.Width = m_CurrCtl.Width
      End If
'      m_CurrCtl.Move pointX, pointY, m_CurrCtl.Width, m_CurrCtl.Height
   End If

   'Move control to new location
   m_DragRect.SetCtrlToRect m_CurrCtl, pbScreen.hWnd

   ''Move control to new location
   'MMD: 2004-03-19 commented out.  Fixes offset in framed controls
'   m_DragRect.SetCtrlToRect m_CurrCtl, pbScreen.hWnd
   'This updates properties after moving an object
   ClearSelection
   SetSelection m_CurrCtl

   'Restore sizing handles
   ShowHandles True
   'Free mouse movement
   ClipCursor ByVal 0&
   'Release mouse capture
   ReleaseCapture
   'Reset drag state
   m_DragState = StateNothing
'   If Right(m_CurrCtl.Name, 1) <> "R" Then
   If Mid(m_CurrCtl.Name, Len(m_CurrCtl.Name)) <> "R" Then
      ShowCoordinates m_CurrCtl.Left, m_CurrCtl.Top
      ShowDimensions m_CurrCtl.Width, m_CurrCtl.Height
   Else
      On Error Resume Next
      ShowCoordinates m_CurrCtl.Control.Left, m_CurrCtl.Control.Top
      ShowDimensions m_CurrCtl.Control.Width, m_CurrCtl.Control.Height
   End If
'' bDirtyForm = True
   DoEvents
   ShowHandles True
End Sub

Private Sub mnuCopy_Click()
   CopyCtl m_CurrCtl
End Sub

'Process MouseDown over handles
Private Sub picHandle_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim i As Integer
Dim rc As RECT

   'Handles should only be visible when a control is selected
   Debug.Assert (Not m_CurrCtl Is Nothing)

   'NOTE: m_DragPoint not used for sizing

   'Save control position in screen coordinates
   m_DragRect.SetRectToCtrl m_CurrCtl, pbScreen.hWnd

   'Track index handle
   m_DragHandle = Index

   'Hide sizing handles
   ShowHandles False

   'We need to force handles to hide themselves before drawing drag rectangle
   Refresh

   'Indicate sizing is under way
   m_DragState = StateSizing

   'Show sizing rectangle
   DrawDragRect

   'In order to detect mouse movement over any part of the form, we set the mouse capture
   'to the form and will process mouse movement from the applicable form events
   SetCapture pbScreen.hWnd

   'Limit cursor movement within form
   GetWindowRect pbScreen.hWnd, rc
   ClipCursor rc
End Sub

'Display or hide the sizing handles and arrange them for the current rectangle
Public Sub ShowHandles(Optional bShowHandles As Boolean = True)
Dim i As Integer
Dim xFudge As Long, yFudge As Long
Dim nWidth As Long, nHeight As Long

   If bShowHandles And Not m_CurrCtl Is Nothing Then
      m_DragRect.SetRectToCtrl m_CurrCtl, pbScreen.hWnd
      With m_DragRect
         'Save some calculations in variables for speed
         nWidth = (picHandle(0).Width \ 2)
         nHeight = (picHandle(0).Height \ 2)
         xFudge = 2 * nWidth '6 '* Screen.TwipsPerPixelX)
         yFudge = 2 * nHeight + pbScreen.Top '6  '* Screen.TwipsPerPixelY)
   
         'Top Left
         picHandle(0).Move (.Left - nWidth) + xFudge, (.Top - nHeight) + yFudge
         'Bottom right
         picHandle(4).Move (.Left + .Width) - nWidth + xFudge, .Top + .Height - nHeight + yFudge
         'Top center
         picHandle(1).Move .Left + (.Width / 2) - nWidth + xFudge, .Top - nHeight + yFudge
         'Bottom center
         picHandle(5).Move .Left + (.Width / 2) - nWidth + xFudge, .Top + .Height - nHeight + yFudge
         'Top right
         picHandle(2).Move .Left + .Width - nWidth + xFudge, .Top - nHeight + yFudge
         'Bottom left
         picHandle(6).Move .Left - nWidth + xFudge, .Top + .Height - nHeight + yFudge
         'Center right
         picHandle(3).Move .Left + .Width - nWidth + xFudge, .Top + (.Height / 2) - nHeight + yFudge
         'Center left
         picHandle(7).Move .Left - nWidth + xFudge, .Top + (.Height / 2) - nHeight + yFudge
      End With
   End If
   'Show or hide each handle
   For i = 0 To 7
      picHandle(i).Visible = bShowHandles
   Next i
End Sub

'Draw drag rectangle. The API is used for efficiency and also
'because drag rectangle must be drawn on the screen DC in
'order to appear on top of all controls
Private Sub DrawDragRect()
Dim hPen As Long, hOldPen As Long
Dim hBrush As Long, hOldBrush As Long
Dim hScreenDC As Long, nDrawMode As Long

   'Get DC of entire screen in order to draw on top of all controls
   hScreenDC = GetDC(pbScreen.hWnd)

   'Select GDI object
   hPen = CreatePen(PS_SOLID, 2, 0)
   hOldPen = SelectObject(hScreenDC, hPen)
   hBrush = GetStockObject(NULL_BRUSH)
   hOldBrush = SelectObject(hScreenDC, hBrush)
   nDrawMode = SetROP2(hScreenDC, R2_NOT)

   'Draw rectangle
   Rectangle hScreenDC, m_DragRect.Left, m_DragRect.Top, m_DragRect.Right, m_DragRect.Bottom

   'Restore DC
   SetROP2 hScreenDC, nDrawMode
   SelectObject hScreenDC, hOldBrush
   SelectObject hScreenDC, hOldPen
   ReleaseDC 0, hScreenDC

   'Delete GDI objects
   DeleteObject hPen
End Sub

Public Sub Resized(Ctl As Object)
'Beep
'Debug.Print "frmScreen.Resized()"
End Sub

Public Sub CopyCtl(Ctl As Object)
   If TypeName(Ctl) = "NonVisible" Then
      Set m_CopyObject = Ctl.Control
   ElseIf TypeName(Ctl) = "CommonControls" Then
      Set m_CopyObject = Ctl.Control
   ElseIf Ctl Is Nothing Then
      CopyCtl m_CurrCtl
      'Set m_CopyObject = m_CurrCtl
   Else
      Set m_CopyObject = Ctl
   End If
End Sub

Public Sub ScreenSize(ScreenWidth As Single, ScreenHeight As Single)
''''   If gInterface = INT_POCKETPC Then
''''      Me.Height = (ScreenHeight - 20) * Screen.TwipsPerPixelY
''''   Else
''''      Me.Height = ScreenHeight * Screen.TwipsPerPixelY
''''   End If
''''   Me.Width = ScreenWidth * Screen.TwipsPerPixelX
''''   DrawGridD Me, gGridSize
End Sub

Public Sub KeyDown(KeyCode As Integer, Shift As Integer)
   Call Form_KeyDown(KeyCode, Shift)
End Sub

Public Sub ChangeInterface()
''''   If gInterface = INT_PALMPC Then
''''      tvMenuBar1.Align = 1
''''      'MMD: tvMenuBar1.Orientation = mbDownward
''''   ElseIf gInterface = INT_POCKETPC Then
''''      tvMenuBar1.Align = 2
''''      'MMD: tvMenuBar1.Orientation = mbUpward
''''   End If
End Sub

Public Sub ShowPopup(Ctl As Object)
Dim m As Menu
Dim bAcX As Boolean

   SetSelection Ctl
   DoEvents

   For Each m In frmMain.mnuRightItem
      If m.Index <> frmMain.mnuRightItem.UBound Then m.Visible = False
   Next
   frmMain.mnuRightItem(6).Visible = True    'View Code
   bAcX = (TypeName(Ctl) = "CActiveXCtl")
   frmMain.mnuRightItem(7).Visible = bAcX    'Rename (For ActiveX controls)
   frmMain.mnuRightItem(10).Visible = True   '-
   frmMain.mnuRightItem(11).Visible = True   'Cut
   frmMain.mnuRightItem(12).Visible = True   'Copy
'   frmMain.mnuRightItem(13).Visible = True   'Paste
   frmMain.mnuRightItem(14).Visible = True   'Delete
   frmMain.mnuRightItem(15).Visible = True   '-
   frmMain.mnuRightItem(frmMain.mnuRightItem.UBound).Visible = True   'Properties...

   frmMain.mnuRight.Tag = "0" & Ctl.GlobalID
   PopupMenu frmMain.mnuRight
End Sub

Public Function AddObjectBack(sType, Optional sName, Optional X, Optional Y, Optional W, Optional H)
Dim btnObj As Object
Dim hidObj As Object
Dim sTypeConv As String
Dim dragControl As Object
Dim objNonVis As Object

   If Not bInit Then
      Form_Load
   End If
   If sType = "Finance" Then Exit Function
   sTypeConv = GetTypeName(sType)

   Set dragControl = CreateObjectEx(GetTypeNameBack(sType))

   On Error Resume Next

   Set btnObj = Me.Controls.Add(sTypeConv, sName)

   err.Clear
   btnObj.Visible = True
   If err.Number <> 0 Then
      Me.Controls.Remove sName
      Set btnObj = Me.Controls.Add("NSBDesign.NonVisible", sName & "R")
      Set objNonVis = Me.Controls.Add(sTypeConv, sName)
      Set btnObj.Control = objNonVis
   ElseIf TypeName(dragControl) = "CCommonControl" Then
      Me.Controls.Remove sName
      Set btnObj = Me.Controls.Add("NSBDesign.CommonControls", sName & "R")
      Set objNonVis = Me.Controls.Add(sTypeConv, sName)
      Set btnObj.Control = objNonVis
   ElseIf TypeName(dragControl) = "CNonVisible" Then
      Me.Controls.Remove sName
      Set btnObj = Me.Controls.Add("NSBDesign.NonVisible", sName & "R")
      Set objNonVis = Me.Controls.Add(sTypeConv, sName)
      Set btnObj.Control = objNonVis
   End If

   'Check if we try to copy existing control
   With btnObj
      .Visible = True
      .Left = X
      .ZOrder
      .Text = sName
      .Caption = sName
      .Width = W
      .Height = H
      .BackColor = vbWhite
      .FontName = "Tahoma"
   End With

   dragControl.Init btnObj, Me
   dragCol.Add dragControl, sName
   Set AddObjectBack = btnObj
End Function

Public Sub CutCtl()
   CopyCtl Nothing
End Sub

Public Sub AddMenuCode(sMenu As String)
   If m_MenuCode = "" Then
      m_MenuCode = sMenu
   Else
      m_MenuCode = m_MenuCode & vbCrLf & sMenu
   End If
End Sub

Public Sub Activate()
   Form_Activate
End Sub

Public Sub PlaceControl(Ctl As Control)
Dim rc As RECT

   'CurrentControl = Ctl
   'ShowHandles True

   'Free mouse movement
   ClipCursor ByVal 0&

   'Release mouse capture
   ReleaseCapture

   'Reset drag state
   m_DragState = StateNothing
'   If Right(m_CurrCtl.Name, 1) <> "R" Then
   If m_CurrCtl Is Nothing Then Exit Sub
   If Mid(m_CurrCtl.Name, Len(m_CurrCtl.Name)) <> "R" Then
      ShowCoordinates m_CurrCtl.Left, m_CurrCtl.Top
      ShowDimensions m_CurrCtl.Width, m_CurrCtl.Height
   Else
      On Error Resume Next
      ShowCoordinates m_CurrCtl.Control.Left, m_CurrCtl.Control.Top
      ShowDimensions m_CurrCtl.Control.Width, m_CurrCtl.Control.Height
   End If
End Sub

Public Function GetTypeNameBack(ByVal sType As String) As String
   If InStr(sType, ".") Then
      Select Case sType
      Case "PictureBox"
         GetTypeNameBack = "VB.PictureBox"
      Case "GridCtrl.GridCtrl.1", "GridCtrl.GridCtrl"
         GetTypeNameBack = "Grid"
      Case "FILECTL.File.1"
         GetTypeNameBack = "File"
         'GetTypeName = "NSBDesign.NonVisible"
      Case "FILECTL.FileSystem.1"
         GetTypeNameBack = "FileSystem"
      Case "CEComDlg.CommonDialog.1"
         GetTypeNameBack = "CEComDlg.CommonDialog.1"
      'Case "CommonDialog"
      '   GetTypeNameBack = "CEComDlg.CommonDialog.1"
      Case "WinSock.WinSock.1"
         GetTypeNameBack = "WinSock.WinSock.1"
      'Case "CommandButton"
      '   GetTypeNameBack = "VB." & sType
      'Case "ComboBox"
      '  GetTypeNameBack = "NSBDesign." & sType
      'Case "ListBox"
      '   GetTypeNameBack = "NSBDesign." & sType
      'Case "Label"
      '   GetTypeNameBack = "VB." & sType
      'Case "CheckBox"
      '   GetTypeNameBack = "VB." & sType
      'Case "OptionButton"
      '   GetTypeNameBack = "VB." & sType
      'Case "TextBox"
      '   GetTypeNameBack = "NSBDesign.TextBox"
      Case "CEImageList.ImageListCtrl.1"
         GetTypeNameBack = "ImageList"
      'Case "ImageListCtrl"
      '   GetTypeNameBack = "CEImageList.ImageListCtrl.1"
      Case "Image.ImageCtl.1"
         GetTypeNameBack = "Image"
      Case "ListViewCtrl.ListViewCtrl.1"
         GetTypeNameBack = "ListView"
      'Case "ListViewCtrl"
      '   GetTypeNameBack = "ListViewCtrl.ListViewCtrl.1"
      Case "TREEVIEWCtl.TreeViewCtl.1"
         GetTypeNameBack = "TreeView"
      'Case "TreeViewCtl"
      '   GetTypeNameBack = "TREEVIEWCtl.TreeViewCtl.1"
      Case "CETabStrip.TabStrip.1"
         GetTypeNameBack = "TabStrip"
      'Case "ToolBar"
      '   GetTypeNameBack = "MSCECommandBar.CommandBar.1"
      'Case "CommandBar"
      '   GetTypeNameBack = "MSCECommandBar.CommandBar.1"
      Case "CECOMM.Comm.1"
         GetTypeNameBack = "Comm"
      Case "Date", "Time"
         GetTypeNameBack = "NSBDesign." & sType
         'GetTypeNameBack = "MSComCtl2.DTPicker"
      Case Else
         GetTypeNameBack = sType
      End Select
   Else
      GetTypeNameBack = sType
   End If
End Function

Public Function GetObject(obj As Object) As Object
Dim Ctl As Object

   For Each Ctl In Object.Controls
      If Ctl.Name = obj.Name Then
         Set GetObject = Ctl
         Exit Function
      End If
   Next
End Function

Public Property Let Object(theForm As CForm)
Dim obj As Object
   m_bLoading = True
   Set m_Form = theForm
   SetCaption
   Me.Tag = m_Form.GlobalID
   m_bLoading = False
End Property
Public Property Get Object() As CForm
   Set Object = m_Form
End Property

Function OrigX() As Integer
   OrigX = kScreenLeft
End Function

Function OrigY() As Integer
   OrigY = kScreenTop
End Function

Public Function GlobalID() As String
   GlobalID = m_Form.GlobalID
End Function

Public Property Get CurrentControl() As Object
   Set CurrentControl = m_CurrCtl
End Property
Public Property Let CurrentControl(Ctl As Object)
   Set m_CurrCtl = Ctl
End Property
