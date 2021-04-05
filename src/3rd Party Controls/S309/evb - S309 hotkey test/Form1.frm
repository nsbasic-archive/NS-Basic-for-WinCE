VERSION 5.00
Object = "{95299E18-49EF-11D3-AE2E-00608CC1DD62}#1.1#0"; "S309HotKey.ocx"
Begin VB.Form Form1 
   Caption         =   "Start"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnEnd 
      Caption         =   "End"
      Height          =   495
      Left            =   2160
      TabIndex        =   1
      Top             =   1440
      Width           =   1575
   End
   Begin VB.CommandButton btnStart 
      Caption         =   "Start"
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Top             =   1440
      Width           =   1575
   End
   Begin S309HOTKEYLib.S309HotKey S309HotKey1 
      Height          =   1125
      Left            =   360
      TabIndex        =   2
      Top             =   480
      Width           =   3000
      _Version        =   65537
      _ExtentX        =   1296
      _ExtentY        =   873
      _StockProps     =   0
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub btnEnd_Click()
    Dim bReturn As Boolean
    
    bReturn = S309HotKey1.UnregisterAll()
   btnStart.Caption = "Start"
End Sub

Private Sub btnStart_Click()
    Dim nIndex1 As Integer
    Dim nIndex2 As Integer
    Dim nIndex3 As Integer
    Dim nIndex4 As Integer
    Dim nIndex5 As Integer
    Dim bReturn As Boolean
    Dim bAlt As Boolean
    Dim bControl As Boolean
    Dim bShift As Boolean
    Dim bWindows As Boolean
    
    For nIndex1 = 1 To 255
        For nIndex2 = 0 To 1
            For nIndex3 = 0 To 1
                For nIndex4 = 0 To 1
                    For nIndex5 = 0 To 1
        If nIndex1 <> 91 Then
                        bAlt = (nIndex2 = 0)
                        bControl = (nIndex3 = 0)
                        bShift = (nIndex4 = 0)
                        bWindows = (nIndex5 = 0)
                        bReturn = S309HotKey1.Register(nIndex1, bAlt, bControl, bShift, bWindows)
                        If Not bReturn Then
                            MsgBox "Register Error " & Str(nIndex1) & Chr(nIndex1) & " Alt=" & CStr(bAlt) & " Control=" & CStr(bControl) & " Shift=" & CStr(bShift) & " Windows=" & CStr(bWindows)
                        End If
        End If
                    Next nIndex5
                Next nIndex4
            Next nIndex3
        Next nIndex2
    Next nIndex1
    btnStart.Caption = "Started"
'    bReturn = S309HotKey1.Register((4 * 16) + 1, False, True, False, False)
End Sub

Private Sub S309HotKey1_HotKeyDown(ByVal nKey As Integer, ByVal bAlt As Boolean, ByVal bControl As Boolean, ByVal bShift As Boolean, ByVal bWindows As Boolean)
    MsgBox "HotkeyDown " & Str(nKey) & Chr(nKey) & " Alt=" & CStr(bAlt) & " Control=" & CStr(bControl) & " Shift=" & CStr(bShift) & " Windows=" & CStr(bWindows)
End Sub

Private Sub S309HotKey1_HotKeyUp(ByVal nKey As Integer, ByVal bAlt As Boolean, ByVal bControl As Boolean, ByVal bShift As Boolean, ByVal bWindows As Boolean)
    MsgBox "HotkeyUP " & Str(nKey)
End Sub
