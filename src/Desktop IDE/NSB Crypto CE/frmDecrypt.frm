VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmDecrypt 
   Caption         =   "NSB Crypto/CE"
   ClientHeight    =   2175
   ClientLeft      =   5310
   ClientTop       =   5055
   ClientWidth     =   7605
   LinkTopic       =   "Form1"
   ScaleHeight     =   2175
   ScaleWidth      =   7605
   Begin VB.CommandButton btnCopy 
      Caption         =   "&Copy"
      Height          =   375
      Left            =   6120
      TabIndex        =   8
      Top             =   1680
      Width           =   975
   End
   Begin VB.CheckBox chkForceDecrypt 
      Caption         =   "Force"
      Height          =   255
      Left            =   3120
      TabIndex        =   7
      Top             =   1725
      Value           =   1  'Checked
      Width           =   735
   End
   Begin MSComDlg.CommonDialog dlgCommon 
      Left            =   2400
      Top             =   1560
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      DialogTitle     =   "Open File"
      Filter          =   "NSB Files (*.nsb)|*.nsb|Text Files (*.txt)|*.txt|All Files (*.*)|*.*"
   End
   Begin VB.CommandButton btnBrowse 
      Caption         =   "..."
      Height          =   285
      Left            =   7080
      TabIndex        =   6
      Top             =   480
      Width           =   375
   End
   Begin VB.CommandButton btnEncrypt 
      Caption         =   "&Encrypt"
      Height          =   375
      Left            =   5040
      TabIndex        =   5
      Top             =   1680
      Width           =   975
   End
   Begin VB.CommandButton butDecrypt 
      Caption         =   "&Decrypt"
      Default         =   -1  'True
      Height          =   375
      Left            =   3960
      TabIndex        =   4
      Top             =   1680
      Width           =   975
   End
   Begin VB.TextBox txtSerial 
      Height          =   285
      Left            =   120
      TabIndex        =   3
      Text            =   "3000145"
      Top             =   1080
      Width           =   6855
   End
   Begin VB.TextBox txtFilename 
      Height          =   285
      Left            =   120
      TabIndex        =   1
      Text            =   "f:\button.nsb"
      Top             =   465
      Width           =   6855
   End
   Begin VB.Label lblSerial 
      Caption         =   "Serial #:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   855
      Width           =   1935
   End
   Begin VB.Label lblFilename 
      Caption         =   "Filename:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   1935
   End
End
Attribute VB_Name = "frmDecrypt"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub btnBrowse_Click()
   On Error GoTo Err_Browse
   dlgCommon.ShowOpen
   txtFilename = dlgCommon.FileName

Err_Browse:

End Sub

Private Sub btnCopy_Click()
Dim strText As String
Dim fEncryptCode As New frmEncryptCode
Dim nFileFormat As Integer

   nFileFormat = ReadFile(txtFilename, strText, Val(txtSerial.Text), chkForceDecrypt.Value = vbChecked)
   Select Case nFileFormat
   Case nsbFFSealed
      MsgBox "Invalid Serial Number used to open encrypted file"
      Exit Sub
   Case nsbFFError
      MsgBox "Error opening file"
      Exit Sub
   Case nsbFFTest
      MsgBox "Test: " & strText
      Exit Sub
   End Select
   Clipboard.SetText strText
   Beep
End Sub

Private Sub btnEncrypt_Click()
Dim strText As String
Dim fEncryptCode As New frmEncryptCode
Dim nFileFormat As Integer

   nFileFormat = ReadFile(txtFilename, strText, Val(txtSerial.Text), chkForceDecrypt.Value = vbChecked)
   Select Case nFileFormat
   Case nsbFFSealed
      MsgBox "Invalid Serial Number used to open encrypted file"
      Exit Sub
   Case nsbFFError
      MsgBox "Error opening file"
      Exit Sub
   Case nsbFFTest
      MsgBox "Test: " & strText
      Exit Sub
   End Select

   fEncryptCode.txtCode.Text = strText
   fEncryptCode.FileName = txtFilename.Text
   fEncryptCode.SerialNumber = Val(txtSerial.Text)
   fEncryptCode.Show vbModal, Me

   Select Case fEncryptCode.ReturnValue
   Case nsbFFError 'Failure
      MsgBox "Unable to write to file " & txtFilename.Text
   Case nsbFFUnopened  'cancel
   Case nsbFFNormal  'save
      MsgBox GetHeader(nsbFFNormal) & txtFilename.Text & " Saved Successfully!"
   Case nsbFFEncrypted  'Encrypt
      MsgBox GetHeader(nsbFFEncrypted) & txtFilename.Text & " Encrypted Successfully!"
   End Select
End Sub

Private Sub butDecrypt_Click()
Dim strText As String
Dim nFileFormat As Integer

   nFileFormat = ReadFile(txtFilename, strText, Val(txtSerial.Text), chkForceDecrypt.Value = vbChecked)
   Select Case nFileFormat
   Case nsbFFSealed: MsgBox GetHeader(nsbFFEncrypted) & "Invalid Serial Number"
   Case nsbFFError: MsgBox GetHeader(nsbFFNormal) & "Unable to read file " & txtFilename.Text
   Case nsbFFUnopened: MsgBox "Unable to open file " & txtFilename.Text
   Case nsbfftext: MsgBox GetHeader(nsbfftext) & strText
   Case nsbFFNormal, nsbFFEncrypted: MsgBox GetHeader(nFileFormat) & strText
   Case nsbFFTest: MsgBox GetHeader(nsbFFEncrypted) & "Testing..." & vbCrLf & strText
   End Select
End Sub

Private Sub Form_Load()
   txtFilename.Text = "f:\button.nsb"
   btnBrowse.Caption = " " & vbCrLf & "..." & vbCrLf & "&b"
   If Len(Command) > 0 Then
      txtFilename.Text = Command
      butDecrypt_Click
      Unload Me
   End If
End Sub

Private Function GetHeader(ByVal anFileFormat As nsbFileFormat) As String
Dim f 'As File
Dim fs As New FileSystemObject
Dim ts As TextStream
Dim nLen As Long
Dim i As Integer
Dim n As Integer

   If anFileFormat = nsbFFError Then
Err_NotFound:
      GetHeader = "ERROR!" & vbCrLf
      Exit Function
   ElseIf anFileFormat = nsbFFSealed Then
      GetHeader = "Invalid Serial Number" & vbCrLf
      Exit Function
   End If

   'Find file for info
   On Error GoTo Err_NotFound
   Set f = fs.GetFile(txtFilename)
   nLen = f.Size

   If anFileFormat <> nsbfftext Then
      Set ts = fs.OpenTextFile(txtFilename, ForReading)
      On Error GoTo 0
      n = IIf(anFileFormat = nsbFFNormal, 8, 16)
      n = IIf(n < nLen, n, nLen)
      For i = 0 To n - 1
         GetHeader = GetHeader & Right("00" & Hex(Asc(ts.Read(1))), 2) & " "
         If i > 0 And (i + 1) Mod 8 = 0 Then GetHeader = GetHeader & "  "
      Next
      GetHeader = GetHeader & vbCrLf
      ts.Close
   End If
   GetHeader = GetHeader & nLen & " Bytes" & vbCrLf
End Function
