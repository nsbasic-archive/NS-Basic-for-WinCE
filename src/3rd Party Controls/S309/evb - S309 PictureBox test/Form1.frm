VERSION 5.00
Object = "{D4D7C4B5-2CC5-11D3-AE29-00608CC1DD62}#2.3#0"; "S309PI~1.OCX"
Begin VB.Form Form1 
   BackColor       =   &H008080FF&
   Caption         =   "Form1"
   ClientHeight    =   9375
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8760
   LinkTopic       =   "Form1"
   ScaleHeight     =   625
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   584
   StartUpPosition =   3  'Windows Default
   Tag             =   "xxx"
   Begin S309PICTUREBOXLib.S309PictureBox S309PictureBox2 
      Height          =   7695
      Left            =   3960
      TabIndex        =   1
      Top             =   120
      Width           =   4695
      _Version        =   131075
      _ExtentX        =   8281
      _ExtentY        =   13573
      _StockProps     =   11
      BackColor       =   16777215
      ResourceBitmapID=   -1
      Picture         =   " "
   End
   Begin S309PICTUREBOXLib.S309PictureBox S309PictureBox1 
      Height          =   1320
      Left            =   120
      TabIndex        =   0
      Tag             =   "xxx"
      Top             =   120
      Width           =   1875
      _Version        =   131075
      _ExtentX        =   3307
      _ExtentY        =   2328
      _StockProps     =   11
      BackColor       =   33023
      Appearance      =   1
      BorderStyle     =   1
      PlayingCard     =   1
      ScrollBars      =   3
      ResourceBitmapID=   -1
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
Me.S309PictureBox1.Tag = "x"
Me.S309PictureBox2.DrawText CStr(Me.S309PictureBox1.UserMode)
Me.S309PictureBox1.BackColor = vbRed
'Me.S309PictureBox1.Picture = "c:\test1.bmp"
Me.S309PictureBox1.PlayingCard = 40
Me.S309PictureBox2.DrawText CStr(Me.S309PictureBox1.UserMode)
Me.S309PictureBox2.DrawText CStr(Me.S309PictureBox1.ImageHeight) & " " & CStr(Me.S309PictureBox1.Height)
Me.S309PictureBox1.ScrollBars = 3
'Me.S309PictureBox1.AutoSize = False
Me.S309PictureBox1.Height = Me.S309PictureBox1.ImageHeight + 50
Me.S309PictureBox1.Width = Me.S309PictureBox1.ImageWidth - 10
Me.S309PictureBox2.DrawText CStr(Me.S309PictureBox1.ImageHeight) & " " & CStr(Me.S309PictureBox1.Height)
End Sub

Private Sub S309PictureBox1_HScroll(ByVal nSBCode As Long, bRefresh As Boolean, nPos As Long, nMove As Long, ByVal nMin As Long, ByVal nMax As Long, ByVal nPage As Long, ByVal nCX As Long, ByVal nCY As Long)
Me.S309PictureBox2.DrawText CStr(nSBCode) & " " & CStr(nPos) & " " & CStr(nMove) & " " & CStr(nPage) & " " & CStr(nMax)
If nSBCode = 5 Then
'    bRefresh = True
End If
End Sub

Private Sub S309PictureBox1_VScroll(ByVal nSBCode As Long, bRefresh As Boolean, nPos As Long, nMove As Long, ByVal nMin As Long, ByVal nMax As Long, ByVal nPage As Long, ByVal nCX As Long, ByVal nCY As Long)
Me.S309PictureBox2.DrawText CStr(nSBCode) & " " & CStr(nPos) & " " & CStr(nMove) & " " & CStr(nMax) & " " & CStr(nPage) & " " & " " & CStr(nCX) & " " & CStr(nCY) & " " & CStr(Me.S309PictureBox1.ImageHeight) & " " & CStr(Me.S309PictureBox1.Height)
If nSBCode = 5 Then
'    bRefresh = True
End If
End Sub
