VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CCERemote2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Private goPManager As Object
Private goConnect As Object
Private gstrSN As String
Private gstrInstall As String
Private gstrPlatform As String
Private gstrDevice As String

Private WithEvents gcmbPlatform As ComboBox
Attribute gcmbPlatform.VB_VarHelpID = -1
Private WithEvents gcmbDevice As ComboBox
Attribute gcmbDevice.VB_VarHelpID = -1

Private Const kCERPrefs As String = "_NSBPref.txt"
Private Const kCERPlatformKey As String = "CERPlatform"
Private Const kCERDeviceKey As String = "CERDevice"

Private Sub Class_Initialize()
   Set goPManager = CreateObject("PlatformManager.PlatformManager.1")
   Set goConnect = Nothing
   gstrSN = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "SerialNumber", "A00-000-00Z")
   gstrInstall = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "InstallDir1", "C:\\Program Files\\NSBasic\\CE")
   gstrPlatform = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, kCERPlatformKey, "Pocket PC 2002")
   gstrDevice = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, kCERDeviceKey, "Pocket PC 2002 Emulation")
End Sub

Private Sub Class_Terminate()
   Set gcmbPlatform = Nothing
   Set gcmbDevice = Nothing
End Sub

Public Sub Attach(cmbPlat As ComboBox, cmbDev As ComboBox)
   Set gcmbPlatform = cmbPlat
   Set gcmbDevice = cmbDev
   ListPlatforms
   'gcmbPlatform.Text = gstrPlatform
   ListDevices gcmbPlatform.Text
   'gcmbDevice.Text = gstrDevice
End Sub

Public Sub Detatch()
   Set gcmbPlatform = Nothing
   Set gcmbDevice = Nothing
End Sub

Public Sub StorePrefs()
   gstrPlatform = gcmbPlatform.Text
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, kCERPlatformKey, gstrPlatform
   gstrDevice = gcmbDevice.Text
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, kCERDeviceKey, gstrDevice
End Sub

'This only works for Pocket PC 2002 Emulator.
'Separate Desktop Runtimes need to be used/available.
Public Sub NSBInstall()
Dim fs As New FileSystemObject
Dim ts As TextStream
   
   Set ts = fs.CreateTextFile(gstrInstall & "\" & kCERPrefs, True)
   ts.Write "Serial:" & gstrSN
   ts.Close
   
   If goConnect Is Nothing Then Connect
   On Error GoTo err_NSBInstall
   'RES
   FileCopy gstrInstall & "\Basic.exe", "\Program Files\NS Basic\Basic.exe"
   FileCopy gstrInstall & "\Basic.lnk", "\Windows\Start Menu\Basic.lnk"
   FileCopy gstrInstall & "\" & kCERPrefs, "\Windows\Basic Prefs.txt"
   FileCopy "F:\Windows CE Tools\wce300\Pocket PC 2002\target\x86\RegSvrCE.exe", "\Windows\RegSvrCE.exe"
   FileCopy "F:\Windows CE Tools\wce300\Pocket PC 2002\controls\x86\MSCEPicture.dll", "\Windows\MSCEPicture.dll"
   Execute "RegSvrCE", "/s MSCEPicture.dll"
   fs.DeleteFile gstrInstall & "\" & kCERPrefs, True
   Exit Sub
   
err_NSBInstall:
   fs.DeleteFile gstrInstall & "\" & kCERPrefs, True
   'RES
   MsgBox "Unable to install NS Basic/CE on Remote Device", vbCritical
End Sub

Public Sub Connect()
Dim oDevice As Object

   On Error GoTo err_Connect
   Set oDevice = goPManager.GetPlatform(gstrPlatform).GetDevice(gstrDevice)
   Set goConnect = oDevice.Attach("cemgr", 20000)
   Set oDevice = Nothing
   Exit Sub

err_Connect:
   'RES
   MsgBox "Unable to connect to Remote Device.", vbCritical
End Sub

Public Sub Disconnect()
   If Not goConnect Is Nothing Then Set goConnect = Nothing
End Sub

Public Sub ListPlatforms()
Dim oPlatform As Object

   On Error Resume Next
   gcmbPlatform.Clear
   For Each oPlatform In goPManager.EnumPlatforms
      gcmbPlatform.AddItem oPlatform.Name
   Next
End Sub

Public Sub ListDevices(astrPlatform As String)
Dim oDevice As Object

   On Error Resume Next
   gcmbDevice.Clear
   For Each oDevice In goPManager.GetPlatform(astrPlatform).EnumDevices
      gcmbDevice.AddItem oDevice.Name
   Next
   gcmbDevice.ListIndex = 0
End Sub

Public Sub FileCopy(astrSource As String, astrDest As String)
   On Error GoTo err_FileCopy
   goConnect.FileCopy astrSource, astrDest, 1
   Exit Sub

err_FileCopy:
   'RES
   Select Case Err.Number
   Case 75: MsgBox "File is open, or path is invalid", vbCritical, App.Title
   Case 91: MsgBox "No connection established", vbCritical, App.Title
   Case -2147221500: MsgBox "Connection has been broken", vbCritical, App.Title
   End Select
End Sub

Public Sub Execute(astrLaunch As String, astrFile As String)
   On Error GoTo err_Execute
   goConnect.Launch astrLaunch, astrFile
   Exit Sub
   
err_Execute:
   Debug.Assert False
End Sub

Private Sub gcmbPlatform_Click()
   On Error Resume Next
   ListDevices gcmbPlatform.Text
   gcmbDevice.ListIndex = 0
End Sub
