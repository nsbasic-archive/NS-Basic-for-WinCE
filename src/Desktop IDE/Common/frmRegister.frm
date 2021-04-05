VERSION 5.00
Begin VB.Form frmRegister 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "NS Basic/Palm Registration"
   ClientHeight    =   3090
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5730
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3090
   ScaleWidth      =   5730
   StartUpPosition =   3  'Windows Default
   Tag             =   "1176"
   Begin VB.CommandButton butSetDevice 
      Caption         =   "Set Device"
      Enabled         =   0   'False
      Height          =   375
      Left            =   2640
      TabIndex        =   6
      Top             =   2640
      Width           =   1455
   End
   Begin VB.CommandButton butCancel 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4200
      TabIndex        =   5
      Tag             =   "1146"
      Top             =   2640
      Width           =   1455
   End
   Begin VB.CommandButton butDone 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   1080
      TabIndex        =   0
      Tag             =   "1106"
      Top             =   2640
      Width           =   1455
   End
   Begin VB.TextBox fldSerialNumber 
      Height          =   285
      Left            =   2400
      TabIndex        =   2
      Text            =   "Unregistered Demo"
      Top             =   1080
      Width           =   3255
   End
   Begin VB.Label Label3 
      Caption         =   $"frmRegister.frx":0000
      Height          =   855
      Left            =   120
      TabIndex        =   4
      Tag             =   "1180"
      Top             =   1560
      Width           =   5535
   End
   Begin VB.Label Label2 
      Caption         =   "&Serial Number:"
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Tag             =   "1178"
      Top             =   1125
      Width           =   2055
   End
   Begin VB.Label Label1 
      Caption         =   $"frmRegister.frx":00DD
      Height          =   855
      Left            =   120
      TabIndex        =   1
      Tag             =   "1177"
      Top             =   120
      Width           =   5535
      WordWrap        =   -1  'True
   End
End
Attribute VB_Name = "frmRegister"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub butDone_Click()
Dim oldDemoSW As String

   If allowRegistration = 1 Then
      oldDemoSW = gDemoSW
      gSerialNumber = fldSerialNumber.Text
      CheckSerialNumber
      If gDemoSW = "n" Then 'save the serial number
         res = MWinReg.SetRegValue(MWinReg.hKey, MWinReg.SubKey, "SerialNumber", gSerialNumber)
      End If
      If oldDemoSW = "y" And gDemoSW = "n" Then MsgBox gStringTable(3263) '"Congratulations!  You now have a full licenced version."
      If oldDemoSW = "n" And gDemoSW = "y" Then
         MsgBox gStringTable(3264) '"Reverting to Unregistered Demo.  Please reenter your Serial Number."
         Exit Sub
      End If
   Else
      MsgBox gStringTable(3265) '"This is a Demo copy - it cannot be registered.  Please contact NS Basic Corporation to obtain a full copy with all the latest features."
   End If
   Unload Me
End Sub

Private Sub butCancel_Click()
  Unload Me
End Sub


Public Sub butSetDevice_Click()
'create a password file and copy to device
Dim serialNumberString As String
Dim filename As String
Dim bCopied As Boolean

serialNumberString = "Serial:" & gSerialNumber
filename = installationDirectory & "\Basic Prefs.txt"

Open filename For Binary As #1
Put #1, , serialNumberString
Close #1
bCopied = CERem.CopyFileToCEDevice(filename, "\Windows\Basic Prefs.txt")
If bCopied Then
   MsgBox gStringTable(3441) 'Device successfully registered."
Else
   MsgBox gStringTable(3442) 'Device not registered.
End If
Kill filename

End Sub

Private Sub Form_Initialize()
   'InitCommonControls
End Sub

Private Sub Form_Load()
   LoadResStrings Me
   If allowRegistration = 0 Then
      Label2.Enabled = False
      fldSerialNumber.Enabled = False
      butSetDevice.Enabled = False
      gSerialNumber = "Unregistered Demo"
   End If

   If Len(gSerialNumber) Then
      fldSerialNumber.Text = gSerialNumber
      butSetDevice.Enabled = True
   Else
      fldSerialNumber.Text = "Unregistered Demo"
      butSetDevice.Enabled = False
   End If
   
   #If NSBasic_Desktop Then
      butSetDevice.Visible = False
      butDone.Left = butSetDevice.Left
   #End If
   
End Sub

