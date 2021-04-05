VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CRect"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit

'Unfortunately, a fair amount of additional logic
'is required only for line controls
#Const ADD_LINE_LOGIC = True

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

Private Declare Function ClientToScreen Lib "user32" (ByVal hWnd As Long, lpPoint As POINTAPI) As Long
Private Declare Function ScreenToClient Lib "user32" (ByVal hWnd As Long, lpPoint As POINTAPI) As Long

Private m_Rect As RECT

#If ADD_LINE_LOGIC Then

'
Private Const SWAP_NONE = &H0
Private Const SWAP_X = &H1
Private Const SWAP_Y = &H2
Private m_fRectSwap As Integer

#End If

Public Property Let Left(NewLeft As Long)
   m_Rect.Left = NewLeft
End Property

Public Property Get Left() As Long
   Left = m_Rect.Left
End Property

Public Property Let Top(NewTop As Long)
   m_Rect.Top = NewTop
End Property

Public Property Get Top() As Long
   Top = m_Rect.Top
End Property

Public Property Let Right(NewRight As Long)
   m_Rect.Right = NewRight
End Property

Public Property Get Right() As Long
   Right = m_Rect.Right
End Property

Public Property Let Bottom(NewBottom As Long)
   m_Rect.Bottom = NewBottom
End Property

Public Property Get Bottom() As Long
   Bottom = m_Rect.Bottom
End Property

Public Property Let Width(NewWidth As Long)
   m_Rect.Right = m_Rect.Left + NewWidth
End Property

Public Property Get Width() As Long
   Width = m_Rect.Right - m_Rect.Left
End Property

Public Property Let Height(NewHeight As Long)
   m_Rect.Bottom = m_Rect.Top + NewHeight
End Property

Public Property Get Height() As Long
   Height = m_Rect.Bottom - m_Rect.Top
End Property

Public Sub SetRectToCtrl(Ctl As Object, hWnd As Long)
Dim pt As POINTAPI
   
   'Get object local coords
   m_Rect.Left = Ctl.Left
   m_Rect.Top = Ctl.Top
   m_Rect.Right = Ctl.Left + Ctl.Width
   m_Rect.Bottom = Ctl.Top + Ctl.Height
   If hWnd = 0 Then Exit Sub

   'Convert local coords to palm screen absolute coords
   pt.X = m_Rect.Left
   pt.Y = m_Rect.Top
   ClientToScreen Ctl.Ctl.Container.hWnd, pt
   'ClientToScreen Ctl.Container.hWnd, pt
   ScreenToClient hWnd, pt
   m_Rect.Left = pt.X
   m_Rect.Top = pt.Y
   pt.X = m_Rect.Right
   pt.Y = m_Rect.Bottom
   ClientToScreen Ctl.Ctl.Container.hWnd, pt
   'ClientToScreen Ctl.Container.hWnd, pt
   ScreenToClient hWnd, pt
   m_Rect.Right = pt.X
   m_Rect.Bottom = pt.Y
End Sub

Public Sub SetCtrlToRect(Ctl As Object, hWnd As Long)
Dim pt As POINTAPI

   On Error Resume Next
   NormalizeRect
   
   'Convert palm screen absolute coords to local coords
   pt.X = m_Rect.Left
   pt.Y = m_Rect.Top
   ClientToScreen hWnd, pt
   ScreenToClient Ctl.Ctl.Container.hWnd, pt
   m_Rect.Left = pt.X
   m_Rect.Top = pt.Y
   pt.X = m_Rect.Right
   pt.Y = m_Rect.Bottom
   ClientToScreen hWnd, pt
   ScreenToClient Ctl.Ctl.Container.hWnd, pt
   m_Rect.Right = pt.X
   m_Rect.Bottom = pt.Y

   'Move object
   Ctl.Move m_Rect.Left, m_Rect.Top, m_Rect.Right - m_Rect.Left, m_Rect.Bottom - m_Rect.Top
End Sub

Public Sub ScreenToTwips(Ctl As Object)
Dim pt As POINTAPI

   pt.X = m_Rect.Left
   pt.Y = m_Rect.Top
   ScreenToClient Ctl.parent.hWnd, pt
   m_Rect.Left = pt.X
   m_Rect.Top = pt.Y
   pt.X = m_Rect.Right
   pt.Y = m_Rect.Bottom
   ScreenToClient Ctl.parent.hWnd, pt
   m_Rect.Right = pt.X
   m_Rect.Bottom = pt.Y
End Sub

Public Sub TwipsToScreen(Ctl As Object)
Dim pt As POINTAPI

   pt.X = m_Rect.Left
   pt.Y = m_Rect.Top
'   ClientToScreen ctl.Parent.hWnd, pt
   ClientToScreen Ctl.Container.hWnd, pt
   m_Rect.Left = pt.X
   m_Rect.Top = pt.Y
   pt.X = m_Rect.Right
   pt.Y = m_Rect.Bottom
'   ClientToScreen ctl.Parent.hWnd, pt
   ClientToScreen Ctl.Container.hWnd, pt
   m_Rect.Right = pt.X
   m_Rect.Bottom = pt.Y
End Sub

Public Sub NormalizeRect()
Dim nTemp As Long

   If m_Rect.Left > m_Rect.Right Then
      nTemp = m_Rect.Right
      m_Rect.Right = m_Rect.Left
      m_Rect.Left = nTemp
   End If
   If m_Rect.Top > m_Rect.Bottom Then
      nTemp = m_Rect.Bottom
      m_Rect.Bottom = m_Rect.Top
      m_Rect.Top = nTemp
   End If
End Sub

Public Function PtInRect(X As Single, Y As Single) As Integer
   With m_Rect
   If (X >= .Left And X < .Right) And (Y >= .Top And Y < .Bottom) Then
      PtInRect = True
   Else
      PtInRect = False
   End If
   End With
End Function
