VERSION 5.00
Object = "{BCA00000-0F85-414C-A938-5526E9F1E56A}#4.0#0"; "cmax40.dll"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmOptions 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Options"
   ClientHeight    =   4095
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   4950
   Icon            =   "frmOptions.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4095
   ScaleWidth      =   4950
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Tag             =   "1150"
   Begin VB.PictureBox pbTab 
      Height          =   2895
      Index           =   3
      Left            =   240
      ScaleHeight     =   2835
      ScaleWidth      =   4515
      TabIndex        =   27
      Tag             =   "3487"
      Top             =   480
      Visible         =   0   'False
      Width           =   4575
      Begin VB.CommandButton GetDeviceInfo 
         Caption         =   "Get Device Info"
         Height          =   255
         Left            =   2520
         TabIndex        =   39
         Tag             =   "3488"
         Top             =   1440
         Width           =   1815
      End
      Begin VB.ComboBox cbxPlatform 
         Height          =   315
         Left            =   1200
         TabIndex        =   38
         Text            =   "Combo1"
         Top             =   2400
         Width           =   3135
      End
      Begin VB.ComboBox cbxLanguage 
         Height          =   315
         Left            =   1200
         TabIndex        =   36
         Text            =   "Combo1"
         Top             =   1920
         Width           =   3135
      End
      Begin VB.CheckBox chkDeleteWorkFiles 
         Caption         =   "Delete Work Files"
         Height          =   375
         Left            =   240
         TabIndex        =   34
         Tag             =   "3477"
         Top             =   960
         Width           =   4095
      End
      Begin VB.CheckBox chkRetainCabFiles 
         Caption         =   "Retain CAB file"
         Height          =   195
         Left            =   240
         TabIndex        =   33
         Tag             =   "3485"
         Top             =   700
         Width           =   3975
      End
      Begin VB.CheckBox chkCompressCAB 
         Caption         =   "Create compressed CAB file"
         Height          =   375
         Left            =   240
         TabIndex        =   32
         Tag             =   "3484"
         Top             =   240
         Width           =   3975
      End
      Begin VB.Label Label4 
         Caption         =   "Platform"
         Height          =   255
         Left            =   120
         TabIndex        =   37
         Top             =   2400
         Width           =   975
      End
      Begin VB.Label Label3 
         Caption         =   "Language"
         Height          =   255
         Left            =   120
         TabIndex        =   35
         Tag             =   "3478"
         Top             =   1920
         Width           =   1215
      End
   End
   Begin CodeMax4Ctl.CodeMax cmaxPref 
      Height          =   495
      Left            =   840
      OleObjectBlob   =   "frmOptions.frx":5C12
      TabIndex        =   6
      Top             =   3600
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.CommandButton CancelButton 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   3600
      TabIndex        =   4
      Tag             =   "1146"
      Top             =   3600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   2280
      TabIndex        =   5
      Tag             =   "1106"
      Top             =   3600
      Width           =   1215
   End
   Begin MSComDlg.CommonDialog comdlg 
      Left            =   120
      Top             =   3600
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DialogTitle     =   "Plain Text Font"
      FileName        =   "*.prj"
      InitDir         =   "c:\"
   End
   Begin VB.PictureBox pbTab 
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2885
      Index           =   0
      Left            =   240
      ScaleHeight     =   2880
      ScaleWidth      =   4455
      TabIndex        =   7
      TabStop         =   0   'False
      Top             =   480
      Visible         =   0   'False
      Width           =   4455
      Begin VB.PictureBox Picture1 
         Height          =   1335
         Left            =   120
         ScaleHeight     =   1275
         ScaleWidth      =   4155
         TabIndex        =   28
         Top             =   0
         Width           =   4215
         Begin VB.OptionButton optShowSplash 
            Caption         =   "Prompt for pr&oject"
            Height          =   255
            Index           =   0
            Left            =   360
            TabIndex        =   30
            Tag             =   "1156"
            Top             =   840
            Width           =   3855
         End
         Begin VB.OptionButton optShowSplash 
            Caption         =   "Create d&efault project"
            Height          =   255
            Index           =   1
            Left            =   360
            TabIndex        =   29
            Tag             =   "1157"
            Top             =   480
            Width           =   3855
         End
         Begin VB.Label Label5 
            Caption         =   "When NS Basic starts"
            Height          =   255
            Left            =   240
            TabIndex        =   31
            Tag             =   "1155"
            Top             =   120
            Width           =   1695
         End
      End
      Begin VB.CommandButton butEditorPrefs 
         Caption         =   "&Editor Preferences..."
         Height          =   315
         Left            =   2040
         TabIndex        =   24
         Tag             =   "1158"
         Top             =   1680
         Width           =   2295
      End
      Begin VB.ListBox lstLanguage 
         Height          =   1035
         Left            =   120
         TabIndex        =   10
         Top             =   1680
         Width           =   1815
      End
      Begin VB.Label Label1 
         Caption         =   "&Language"
         Height          =   255
         Left            =   120
         TabIndex        =   9
         Tag             =   "3474"
         Top             =   1440
         Width           =   1815
      End
   End
   Begin VB.PictureBox pbTab 
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2885
      Index           =   1
      Left            =   240
      ScaleHeight     =   2880
      ScaleWidth      =   4455
      TabIndex        =   8
      TabStop         =   0   'False
      Top             =   480
      Visible         =   0   'False
      Width           =   4455
      Begin VB.Frame Frame3 
         Caption         =   "Screen Metrics"
         Height          =   1215
         Left            =   120
         TabIndex        =   18
         Tag             =   "3468"
         Top             =   1560
         Width           =   4215
         Begin VB.ComboBox cbxFormFactors 
            Height          =   315
            ItemData        =   "frmOptions.frx":5D02
            Left            =   1680
            List            =   "frmOptions.frx":5D0F
            Style           =   2  'Dropdown List
            TabIndex        =   20
            Top             =   240
            Width           =   2415
         End
         Begin VB.TextBox txtGridSize 
            Height          =   315
            Left            =   3240
            TabIndex        =   23
            Text            =   "Text1"
            Top             =   750
            Width           =   855
         End
         Begin VB.CheckBox chkSnapToGrid 
            Caption         =   "&Snap To Grid"
            Height          =   375
            Left            =   120
            TabIndex        =   21
            Tag             =   "1162"
            Top             =   720
            Width           =   2055
         End
         Begin VB.Label Label2 
            Alignment       =   1  'Right Justify
            AutoSize        =   -1  'True
            Caption         =   "&Form Factor:"
            Height          =   195
            Left            =   90
            TabIndex        =   19
            Tag             =   "3434"
            Top             =   285
            Width           =   885
         End
         Begin VB.Label lblGridSize 
            Alignment       =   1  'Right Justify
            AutoSize        =   -1  'True
            Caption         =   "&Grid Size:"
            Height          =   195
            Left            =   2340
            TabIndex        =   22
            Tag             =   "1163"
            Top             =   810
            Width           =   675
         End
      End
      Begin VB.Frame fraFontDisplay 
         Caption         =   "IDE Font"
         Height          =   1335
         Left            =   120
         TabIndex        =   1
         Tag             =   "1159"
         Top             =   120
         Width           =   4215
         Begin VB.CommandButton butFont 
            Caption         =   "&Font..."
            Height          =   315
            Left            =   2640
            TabIndex        =   17
            Tag             =   "1161"
            Top             =   840
            Width           =   1455
         End
         Begin VB.CheckBox chkPlainText 
            Caption         =   "&Use IDE Font"
            Height          =   255
            Left            =   120
            TabIndex        =   16
            Tag             =   "3435"
            Top             =   870
            Width           =   2055
         End
         Begin VB.Label lblExample 
            Alignment       =   2  'Center
            BackColor       =   &H80000005&
            Caption         =   "Example"
            Height          =   375
            Left            =   120
            TabIndex        =   3
            Tag             =   "1173"
            Top             =   360
            Width           =   3975
         End
         Begin VB.Label lblFontDisplay 
            Alignment       =   2  'Center
            BackColor       =   &H80000005&
            Height          =   495
            Left            =   120
            TabIndex        =   2
            Top             =   240
            Width           =   3975
         End
      End
   End
   Begin VB.PictureBox pbTab 
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2895
      Index           =   2
      Left            =   240
      ScaleHeight     =   2895
      ScaleWidth      =   4455
      TabIndex        =   11
      TabStop         =   0   'False
      Top             =   480
      Visible         =   0   'False
      Width           =   4455
      Begin VB.TextBox txtDeviceInstallPath 
         Height          =   285
         Left            =   120
         TabIndex        =   15
         Top             =   2040
         Width           =   4215
      End
      Begin VB.Frame Frame2 
         Caption         =   "Start Program"
         Height          =   1575
         Left            =   120
         TabIndex        =   12
         Tag             =   "3375"
         Top             =   120
         Width           =   4215
         Begin VB.CheckBox chkTurnDebugOn 
            Caption         =   "3470 - Turn Debug On"
            Height          =   255
            Left            =   240
            TabIndex        =   26
            Tag             =   "3475"
            Top             =   1080
            Width           =   4000
         End
         Begin VB.CheckBox chkSaveBeforeRun 
            Caption         =   "Save Before Run"
            Height          =   255
            Left            =   240
            TabIndex        =   25
            Tag             =   "3469"
            Top             =   360
            Width           =   2400
         End
         Begin VB.CheckBox chkActiveSyncRun 
            Caption         =   "&Run automatically"
            Height          =   255
            Left            =   240
            TabIndex        =   13
            Tag             =   "3378"
            Top             =   720
            Value           =   1  'Checked
            Width           =   3255
         End
      End
      Begin VB.Label lblDevInstPath 
         Caption         =   "Device Install &Path:"
         Height          =   255
         Left            =   120
         TabIndex        =   14
         Tag             =   "3379"
         Top             =   1800
         Width           =   4095
      End
   End
   Begin MSComctlLib.TabStrip tabPrefs 
      Height          =   3375
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4815
      _ExtentX        =   8493
      _ExtentY        =   5953
      _Version        =   393216
      BeginProperty Tabs {1EFB6598-857C-11D1-B16A-00C0F0283628} 
         NumTabs         =   4
         BeginProperty Tab1 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "General"
            Object.Tag             =   "1440"
            Object.ToolTipText     =   "1441"
            ImageVarType    =   2
         EndProperty
         BeginProperty Tab2 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "Design Screen"
            Object.Tag             =   "1444"
            Object.ToolTipText     =   "1445"
            ImageVarType    =   2
         EndProperty
         BeginProperty Tab3 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "Start"
            Object.Tag             =   "1220"
            ImageVarType    =   2
         EndProperty
         BeginProperty Tab4 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "Installer"
            Object.Tag             =   "3476"
            ImageVarType    =   2
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmOptions"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Enum enTabs
   tbsNone = -1
   tbsGeneral = 0
   tbsEditor = 1
   tbsScreen = 2
   tbsStart = 3
   tbsInstaller = 4
End Enum

Private m_nTab As enTabs
Private m_bFontChanged As Boolean

Private Sub butEditorPrefs_Click()
   MNSBCodeMax_SetScriptPrefs cmaxPref
   cmaxPref.ExecuteCmd cmCmdProperties, 0  'CM4 fixup: get prefs
   'save values in Registry
   MNSBCodeMax_SavePrefs cmaxPref
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "codeFontName", cmaxPref.Font.Name
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "codeFontSize", cmaxPref.Font.Size
End Sub

Private Sub butFont_Click()
   'Prepare common dialog
   comdlg.flags = cdlCFBoth
   comdlg.FontName = gLabelFontName
   comdlg.FontSize = gLabelFontSize
   comdlg.CancelError = True

   On Error GoTo fontDlgCancel
   comdlg.ShowFont

   m_bFontChanged = True
   lblExample.FontBold = comdlg.FontBold
   lblExample.FontItalic = comdlg.FontItalic
   lblExample.FontName = comdlg.FontName
   lblExample.FontSize = comdlg.FontSize
   'MsgBox lblExample.Font.Charset

fontDlgCancel:
   On Error GoTo 0
End Sub

Private Sub CancelButton_Click()
   Unload Me
End Sub

Private Sub cbxFormFactors_Click()
Dim nScreen As Long

   nScreen = cbxFormFactors.ItemData(cbxFormFactors.ListIndex)
   If nScreen = 0 Then
      'Create custom factor
      frmCustomFF.Show vbModal, Me

      'Update combobox
      LoadFormFactors

      cbxFormFactors.ListIndex = cbxFormFactors.ListCount - 2 '-1 = "Custom...", -2 = New item
      Exit Sub
   End If
End Sub

Private Sub chkPlainText_Click()
   butFont.Enabled = chkPlainText
End Sub

Private Sub cmaxPref_PropsChange()
   MNSBCodeMax_SavePrefs cmaxPref
End Sub



Private Sub Form_Load()
   Dim i As Integer
   Dim s() As String
         
   LoadResStrings Me
   Me.Icon = frmIcon.Icon

   'Update objects from current options
   'Tab 1
   If MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey, "ShowSplash", True) Then
      optShowSplash(0).Value = True
   Else
      optShowSplash(1).Value = True
   End If
   getLanguages
      
   'Tab 2
   lblExample.FontName = gLabelFontName
   lblExample.FontSize = gLabelFontSize
   lblExample.Font.Charset = gLabelCharset
   chkPlainText = IIf(gbPlainText, 1, 0)
   butFont.Enabled = chkPlainText
   LoadFormFactors
   chkSnapToGrid = IIf(gbWantGrid, 1, 0)
   txtGridSize = gnGridIncr
   
   'Tab 3
   #If NSBasic_CE Then
   chkSaveBeforeRun.Visible = False 'redundant, now that the file is always saved.
   #End If
   chkActiveSyncRun.Value = IIf(gbActiveSyncRun, 1, 0)
   chkSaveBeforeRun.Value = IIf(gbSaveBeforeRun, 1, 0)
   chkTurnDebugOn.Value = IIf(MWinReg.GetRegValue(HKEY_CURRENT_USER, "Software\Microsoft\Windows Script\Settings", "JITDebug", "0") = "0", 0, 1)
   #If NSBasic_CE Then
      txtDeviceInstallPath = False
      txtDeviceInstallPath = gstrDeviceInstallPath
      chkTurnDebugOn.Visible = False
   #End If
   #If NSBasic_Desktop Then
      txtDeviceInstallPath.Visible = False
      lblDevInstPath.Visible = False
   #End If
   
   'Tab 4 - Installer
   #If NSBasic_CE Then
      chkDeleteWorkFiles.Value = IIf(gbDeleteWorkFiles, 1, 0)
      chkRetainCabFiles.Value = IIf(gbRetainCabFiles, 1, 0)
      chkCompressCAB.Value = IIf(gbCompressCab, 1, 0)
      cbxLanguage.AddItem "English"
      cbxLanguage.AddItem "German"
      cbxLanguage.AddItem "French"
      cbxLanguage.AddItem "Italian"
      cbxLanguage.AddItem "Swedish"
      cbxLanguage.AddItem "Portuguese"
      cbxLanguage.AddItem "Spanish"
      cbxLanguage.ListIndex = gnLanguage
      
      cbxPlatform.AddItem "WM - Windows Mobile"
      cbxPlatform.AddItem "1824 - ARMV4i/ARM720"
      cbxPlatform.AddItem "2336 - ARM920"
      cbxPlatform.AddItem "2577 - ARMV4/StrongARM/SA1100"
      cbxPlatform.AddItem "4000 - MIPSII"
      cbxPlatform.ListIndex = gnPlatform
   #End If
      
   #If NSBasic_Desktop Then
      tabPrefs.Tabs.Remove tbsInstaller
   #End If
   
   m_nTab = tbsNone
   ShowTab tbsGeneral
End Sub

Private Sub LoadFormFactors()
Dim strFactor As String
Dim strFFactors As String
Dim arrFFactors() As String
Dim i As Integer
Dim ff As Integer
Dim nScreen As Long

   cbxFormFactors.Clear
   'Get the name of the default factor
   strFactor = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "Pocket PC")
   'Get the list of saved factors
   strFFactors = MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "Form Factors", "Pocket PC|Handheld PC")
   arrFFactors = Split(strFFactors, "|")
   'Loop through each factor and add to the combobox
   For i = 0 To UBound(arrFFactors)
      cbxFormFactors.AddItem arrFFactors(i)
      'Get menu (M) and screen size info (X,Y) for this form factor
      nScreen = IIf(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors\", arrFFactors(i) & " M", "Bottom") = "Top", &H1000000, 0)
      nScreen = nScreen + Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors\", arrFFactors(i) & " X", "240")) * &H1000&
      nScreen = nScreen + Val(MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors\", arrFFactors(i) & " Y", "320"))
      cbxFormFactors.ItemData(i) = nScreen
      'Remember the currently selected factor
      If arrFFactors(i) = strFactor Then ff = i
   Next
   'RES
   'Add the ability to create your own factor
   cbxFormFactors.AddItem "Custom..."
   cbxFormFactors.ItemData(UBound(arrFFactors) + 1) = 0
   'Display the currently selected factor
   cbxFormFactors.ListIndex = ff
End Sub

Private Sub getLanguages()
Dim s, Name
Dim hFile As Long
Dim WFD As WIN32_FIND_DATA
Dim i As Integer

   i = 0
   hFile = FindFirstFile(installationDirectory & "\Lang\StrTable_*.txt", WFD)
   If hFile <> INVALID_HANDLE_VALUE Then
      Do
         Name = Left(WFD.cFileName, InStr(WFD.cFileName, Chr(0)) - 1)
         lstLanguage.AddItem Mid(Name, 10, Len(Name) - 13)
      Loop While FindNextFile(hFile, WFD)
      hFile = FindClose(hFile)
   End If
   For i = 0 To lstLanguage.ListCount - 1
      If lstLanguage.List(i) = gLanguage Then lstLanguage.Selected(i) = True
   Next
End Sub

Private Sub Form_Unload(Cancel As Integer)
   'gCERemote.Detatch
End Sub

Private Sub GetDeviceInfo_Click()
   Dim s As String
   Dim s1 As String
   
   s = ""
   s1 = MWinReg.GetRegValue(MWinReg.hKey, "Software\Microsoft\Windows CE Services", "DeviceProcessorType", 0)
   s = s & gStringTable(3491) & s1 & vbCrLf
   
   s1 = MWinReg.GetRegValue(MWinReg.hKey, "Software\Microsoft\Windows CE Services", "DeviceType", "None")
   s = s & gStringTable(3492) & s1 & vbCrLf
   
   s1 = MWinReg.GetRegValue(MWinReg.hKey, "Software\Microsoft\Windows CE Services", "DeviceOEMInfo", "None")
   s = s & gStringTable(3493) & s1 & vbCrLf
   
   s1 = MWinReg.GetRegValue(MWinReg.hKey, "Software\Microsoft\Windows CE Services", "DeviceVersion", "None")
   s = s & gStringTable(3494) & s1 & vbCrLf
   
   MsgBox s, vbOKOnly, gStringTable(3495) '"Info from last device connected:"
   
End Sub

Private Sub OKButton_Click()
Dim oldPath As String

   'Tab 1
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "ShowSplash", optShowSplash(0).Value
'   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "LaunchEmulator", IIf(chkLaunchEmulator.Value, True, False)
   If gLanguage <> lstLanguage.List(lstLanguage.ListIndex) Then
      gLanguage = lstLanguage.List(lstLanguage.ListIndex)
      LoadStringTable
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "Language", gLanguage
      gLabelFontName = gStringTable(3348) 'MS Sans Serif if Western
      gLabelCharset = gStringTable(3350) '0 if western
      If gLabelCharset <> 0 Then chkPlainText = 1
      lblExample.Font.Charset = gLabelCharset
      lblExample.Font.Name = gLabelFontName
      m_bFontChanged = True
      MsgBox gStringTable(3346) 'Restart NS Basic to see new language setting.
   End If
      
   'Tab 2
   gbPlainText = chkPlainText
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "PlainText", gbPlainText
   If m_bFontChanged Then
      gLabelFontName = lblExample.FontName
      gLabelFontSize = lblExample.FontSize
      gLabelCharset = lblExample.Font.Charset
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "IDEFontName", gLabelFontName  '01/19/01 GH
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "IDEFontSize", Str(gLabelFontSize)  '01/19/01 GH
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "IDEFontCharset", Str(gLabelCharset)  '01/19/01 GH
      MWinReg.SetRegValue MWinReg.hKey, "Software\NSBasic\" & kProduct & "\Editor", "FontName", gLabelFontName '03/26/01 GH
      MWinReg.SetRegValue MWinReg.hKey, "Software\NSBasic\" & kProduct & "\Editor", "FontCharSet", Str(gLabelCharset) '03/26/01 GH
   End If
   If MWinReg.GetRegValue(MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", "Pocket PC") <> cbxFormFactors.Text Then
      MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey & "\Form Factors", "", cbxFormFactors.Text
      UpdateFormFactor
   End If
   gbWantGrid = chkSnapToGrid
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "WantGrid", gbWantGrid
   gnGridIncr = Val(txtGridSize)
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "GridIncr", gnGridIncr
   
   'Tab 3
'   gnRunTarget = IIf(optRunTarget(0).Value, 0, 1)
   gnRunTarget = 1
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "RunTarget", gnRunTarget
   gbActiveSyncRun = chkActiveSyncRun.Value
   gbSaveBeforeRun = chkSaveBeforeRun.Value
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "ActiveSyncRun", gbActiveSyncRun
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "SaveBeforeRun", gbSaveBeforeRun
   MWinReg.SetRegValue HKEY_CURRENT_USER, "Software\Microsoft\Windows Script\Settings", "JITDebug", chkTurnDebugOn.Value, REG_DWORD
   If txtDeviceInstallPath = "" Then txtDeviceInstallPath = "\"
   gstrDeviceInstallPath = txtDeviceInstallPath
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "DeviceInstallPath", gstrDeviceInstallPath
   
   'Tab 4
   #If NSBasic_CE Then
   gnLanguage = cbxLanguage.ListIndex
   gnPlatform = cbxPlatform.ListIndex
   gbCompressCab = chkCompressCAB.Value
   gbDeleteWorkFiles = chkDeleteWorkFiles.Value
   gbRetainCabFiles = chkRetainCabFiles.Value
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "InstallerLanguage", gnLanguage
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "Platform", gnPlatform
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "CompressCab", gbCompressCab
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "DeleteWorkFiles", gbDeleteWorkFiles
   MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "RetainCabFiles", gbRetainCabFiles
   Select Case gnPlatform
      Case 0: gResourceDirectory = installationDirectory & "\Controls\WM"
      Case 1: gResourceDirectory = installationDirectory & "\Controls\1824"
      Case 2: gResourceDirectory = installationDirectory & "\Controls\2366"
      Case 3: gResourceDirectory = installationDirectory & "\Controls\2557"
      Case 4: gResourceDirectory = installationDirectory & "\Controls\4000"
    End Select
    MWinReg.SetRegValue MWinReg.hKey, MWinReg.SubKey, "resourceDirectory", gResourceDirectory
  #End If
   
   Unload Me
End Sub


Private Sub tabPrefs_Click()
      ShowTab tabPrefs.SelectedItem.Index - 1
End Sub

Private Sub ShowTab(nTab As enTabs)
   If m_nTab <> tbsNone Then pbTab(m_nTab).Visible = False
   m_nTab = nTab
   pbTab(m_nTab).Visible = True
End Sub

