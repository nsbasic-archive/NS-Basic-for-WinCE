Attribute VB_Name = "MCERemote"
Public goPManager As Object
Public goPlatform As Object
Public goDevice As Object
Public goConnect As Object
Public gstrSN As String
Public gstrInstall As String
Public gstrPlatform As String
Public gstrDevice As String
Private gcmbPlatform As ComboBox
Private gcmbDevice As ComboBox
Private Const CERPREF As String = "_NSBPref.txt"

Public Sub CERInitialize(cmbPlat As ComboBox, cmbDev As ComboBox)
   Set gcmbPlatform = cmbPlat
   Set gcmbDevice = cmbDev
   Set goPManager = CreateObject("PlatformManager.PlatformManager")
   gstrSN = MWinReg.GetRegValue(HKEY_CURRENT_USER, "Software\\NSBasic\\CE", "SerialNumber", "Bingle")
   gstrInstall = MWinReg.GetRegValue(HKEY_CURRENT_USER, "Software\\NSBasic\\CE", "InstallDir1", "Bingle")
   gstrPlatform = MWinReg.GetRegValue(HKEY_CURRENT_USER, "Software\\NSBasic\\CE", "CERPlatform", "Pocket PC 2002")
   gstrDevice = MWinReg.GetRegValue(HKEY_CURRENT_USER, "Software\\NSBasic\\CE", "CERDevice", "Pocket PC 2002 Emulation")
End Sub

Public Sub CERNSBInstall()
Dim fs As New FileSystemObject
Dim ts As TextStream
   
   Set ts = fs.CreateTextFile(gstrInstall & "\" & CERPREF, True)
   ts.Write "Serial:" & gstrSN
   ts.Close
   
   If goConnect Is Nothing Then CERConnect
   CERFileCopy gstrInstall & "\Basic.exe", "\Program Files\NS Basic\Basic.exe"
   CERFileCopy gstrInstall & "\Basic.lnk", "\Windows\Start Menu\Basic.lnk"
   CERFileCopy gstrInstall & "\" & CERPREF, "\Windows\Basic Prefs.txt"
   fs.DeleteFile gstrInstall & "\" & CERPREF, True
End Sub

Public Sub CERConnect()
Dim oDevice As Object

   On Error GoTo err_CERConnect
   Set oDevice = goPManager.GetPlatform(gstrPlatform).GetDevice(gstrDevice)
   Set goConnect = oDevice.Attach("cemgr", 20000)
   Set oDevice = Nothing
   Exit Sub

err_CERConnect:
   
End Sub

Public Sub CERDisconnect()
   If Not goConnect Is Nothing Then Set goConnect = Nothing
End Sub

Public Sub CERListPlatforms(cmb As ComboBox)
   On Error Resume Next
   cmb.Clear
   For Each goPlatform In goPManager.EnumPlatforms
      cmb.AddItem goPlatform.Name
   Next
End Sub

Public Sub CERListDevices(astrPlatform As String, cmb As ComboBox)
   On Error Resume Next
   cmb.Clear
   For Each goDevice In goPManager.GetPlatform(astrPlatform).EnumDevices
      cmb.AddItem goDevice.Name
   Next
   cmb.ListIndex = 0
End Sub

Public Sub CERFileCopy(astrSource As String, astrDest As String)
   On Error GoTo err_CERFileCopy
   goConnect.FileCopy astrSource, astrDest, 1
   Exit Sub

err_CERFileCopy:
   Select Case Err.Number
   Case 75: MsgBox "File is open, or path is invalid", vbCritical, App.Title
   Case 91: MsgBox "No connection established", vbCritical, App.Title
   Case -2147221500: MsgBox "Connection has been broken", vbCritical, App.Title
   End Select
End Sub
