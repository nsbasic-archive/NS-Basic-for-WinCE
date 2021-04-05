Attribute VB_Name = "MAPI"
Option Explicit

Type RECT
    Left As Long
    Top As Long
    Right As Long
    Bottom As Long
End Type

Type POINTAPI
    X As Long
    Y As Long
End Type

Type Msg
   hWnd As Long
   message As Long
   wParam As Long
   lParam As Long
   Time As Long
   pt As POINTAPI
End Type

Type NMHDR
   hwndFrom As Long
   idfrom As Long
   code As Long
End Type

Type ToolTipText
   hdr As NMHDR
   lpszText As Long
   szText As String * 80
   hInst As Long
   uFlags As Long
End Type

Public Type MINMAXINFO
   ptReserved As POINTAPI
   ptMaxSize As POINTAPI
   ptMaxPosition As POINTAPI
   ptMinTrackSize As POINTAPI
   ptMaxTrackSize As POINTAPI
End Type

Public gHWndToolTip As Long

Public Type TOOLINFO
   cbSize As Long
   uFlags As Long
   hWnd As Long
   uId As Long
   rct As RECT
   hInst As Long
   lpszText As Long
End Type


Public Declare Function GetParent Lib "USER32" (ByVal hWnd As Long) As Long
Public Declare Function SetParent Lib "USER32" (ByVal hWndChild As Long, ByVal hWndNewParent As Long) As Long
Public Declare Function GetWindowRect Lib "USER32" (ByVal hWnd As Long, lpRect As RECT) As Long
Public Declare Function ScreenToClient Lib "USER32" (ByVal hWnd As Long, lpPoint As POINTAPI) As Long
Public Declare Sub GetCursorPos Lib "USER32" (lpPoint As POINTAPI)

Public Declare Function MoveWindow Lib "USER32" (ByVal hWnd As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal bRepaint As Long) As Long
Public Declare Function ShowWindow Lib "USER32" (ByVal hWnd As Long, ByVal nCmdShow As Long) As Long
Public Declare Function SendMessageLong Lib "USER32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Public Declare Function SendMessageString Lib "USER32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As String) As Long
Public Declare Function GetWindow Lib "USER32" (ByVal hWnd As Long, ByVal wCmd As Long) As Long
Public Declare Function UpdateWindow Lib "USER32" (ByVal hWnd As Long) As Long
#If UNICODE Then
Public Declare Function SetWindowLong Lib "USER32" Alias "SetWindowLongW" (ByVal hWnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Any) As Long
Public Declare Function GetWindowLong Lib "USER32" Alias "GetWindowLongW" (ByVal hWnd As Long, ByVal nIndex As Long) As Long
Public Declare Function CallWindowProc Lib "USER32" Alias "CallWindowProcW" (ByVal lpPrevWndFunc As Long, ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
#Else
Public Declare Function SetWindowLong Lib "USER32" Alias "SetWindowLongA" (ByVal hWnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Any) As Long
Public Declare Function GetWindowLong Lib "USER32" Alias "GetWindowLongA" (ByVal hWnd As Long, ByVal nIndex As Long) As Long
Public Declare Function CallWindowProc Lib "USER32" Alias "CallWindowProcA" (ByVal lpPrevWndFunc As Long, ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
#End If
Public Declare Function GetSystemMetrics Lib "USER32" (ByVal nIndex As Long) As Long
Public Const SM_CXVSCROLL = 2
Private Declare Function PathRelativePathToW Lib "shlwapi.dll" _
    (ByVal pszPath As Long, _
     ByVal pszFrom As Long, _
     ByVal dwAttrFrom As Long, _
     ByVal pszTo As Long, _
     ByVal dwAttrTo As Long) As Boolean

Declare Function FindWindowEx Lib "USER32" Alias "FindWindowExA" (ByVal hWnd1 As Long, ByVal hWnd2 As Long, ByVal lpsz1 As String, ByVal lpsz2 As String) As Long
Declare Function fnAddscriptV Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal outFile As String, ByVal script As Variant, ByVal Icon As String) As Integer
Declare Function fnAddscriptVCE Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal outFile As String, ByVal script As Variant, ByVal Icon As String) As Integer
Declare Function fnAddscriptUTF8 Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal outFile As String, ByVal script As String, ByVal Icon As String) As Integer
Declare Function fnAddscript Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal outFile As String, ByVal script As String, ByVal Icon As String) As Integer
Declare Function setVersionEntry Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal key As String, ByVal Value As String) As Integer
Declare Function setVersionFixed Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal v1 As Integer, ByVal v2 As Integer, ByVal v3 As Integer, ByVal v4 As Integer) As Integer
Declare Function setResource Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal ResType As Integer, ByVal ID As Integer, ByVal resString As String, ByVal resLen As Integer) As Integer
Declare Function setResourceFile Lib "NSBaddScript" _
    (ByVal inFile As String, ByVal ResType As Integer, ByVal ID As Integer, ByVal resFile As String) As Integer
   
'Declare constants used by GetWindow.
Public Const GW_CHILD = 5
Public Const GW_HWNDFIRST = 0
Public Const GW_HWNDLAST = 1
Public Const GW_HWNDNEXT = 2
Public Const GW_HWNDPREV = 3
Public Const GW_OWNER = 4

'Dialog Internal Controls
Public Const fdlgChxReadOnly = &H410
Public Const fdlgcmbSaveAsType = &H470
Public Const fdlgCmbSaveInFindIn = &H471
Public Const fdlgEdtFileName = &H480
Public Const fdlgIDCANCEL = 2
Public Const fdlgIDOK = 1
Public Const fdlgLBLstFiles = &H460
Public Const fdlgLVLstFiles = &H461
Public Const fdlgPshHelp = &H40E
Public Const fdlgStcFileName = &H442
Public Const fdlgStcSaveAsType = &H441
Public Const fdlgStcSaveInFindIn = &H443

Public Const SWP_NOSIZE = &H1
Public Const SWP_NOMOVE = &H2
Public Const SWP_NOZORDER = &H4
Public Const SWP_NOREDRAW = &H8
Public Const SWP_NOACTIVATE = &H10
Public Const SWP_FRAMECHANGED = &H20
Public Const SWP_SHOWWINDOW = &H40
Public Const SWP_HIDEWINDOW = &H80
Public Const SWP_NOCOPYBITS = &H100
Public Const SWP_NOOWNERZORDER = &H200
Public Const SWP_DRAWFRAME = SWP_FRAMECHANGED
Public Const SWP_NOREPOSITION = SWP_NOOWNERZORDER

Public Const SWP_MOVEHIDE = SWP_NOSIZE Or SWP_HIDEWINDOW

'Key Const
Public Const VK_TAB = &H9
Public Const VK_SHIFT = &H10
Public Const VK_CONTROL = &H11

'Traps Alter Key
Public Const KBH_MASK = &H20000000

'Hook Const
Public Const WH_KEYBOARD = 2

'For Trapping Tab Key on Dialog Box
Declare Function CallNextHookEx Lib "USER32" (ByVal hHook As Long, ByVal nCode As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function UnhookWindowsHookEx Lib "USER32" (ByVal hHook As Long) As Long
Declare Function SetWindowsHookEx Lib "USER32" Alias "SetWindowsHookExA" (ByVal idHook As Long, ByVal lpfn As Long, ByVal hMod As Long, ByVal dwThreadId As Long) As Long

Declare Function PostMessage Lib "USER32" Alias "PostMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function EnableWindow Lib "USER32" (ByVal hWnd As Long, ByVal fEnable As Long) As Long
Declare Function SetWindowPos Lib "USER32" (ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long) As Long
Declare Function GetKeyState Lib "USER32" (ByVal nVirtKey As Long) As Integer
Declare Function GetFocusAPI Lib "USER32" Alias "GetFocus" () As Long
Declare Function SetFocusAPI Lib "USER32" Alias "SetFocus" (ByVal hWnd As Long) As Long
Declare Function GetDlgItem Lib "USER32" (ByVal hDlg As Long, ByVal nIDDlgItem As Long) As Long
Declare Function SendMessage Lib "USER32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Integer, ByVal lParam As Integer) As Long
Declare Function SetDlgItemText& Lib "USER32" Alias "SetDlgItemTextA" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal lpString As String)
Declare Function GetDlgItemText& Lib "USER32" Alias "GetDlgItemTextA" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal lpString As String, ByVal nMaxCount As Long)
Declare Function SetDlgItemInt& Lib "USER32" (ByVal hDlg As Long, ByVal nIDDlgItem As Long, ByVal wValue As Long, ByVal bSigned As Long)

Public Const WM_CLOSE = &H10&
Public Const WM_COMMAND = &H111&
Public Const WM_USER = &H400&
Public Const HWND_TOPMOST = -1

Public Const CDM_FIRST = (WM_USER + 100)
Public Const CDM_GETFILEPATH = (CDM_FIRST + &H1)

Public Const MAX_PATH = 260

'Extended Window Constants
Public Const WS_EX_TOPMOST = &H8
Public Const WS_EX_TRANSPARENT = &H20
Public Const WS_EX_TOOLWINDOW = &H80
Public Const WS_EX_WINDOWEDGE = &H100
Public Const WS_EX_CLINTEDGE = &H200
Public Const WS_EX_CONTROLPARENT = &H10000
Public Const WS_EX_TOOLBOXWINDOW = (WS_EX_WINDOWEDGE Or WS_EX_TOOLWINDOW Or WS_EX_TOPMOST)
' Public Const WS_EX_TRANSPARENT = &H20&
Public Const WS_EX_NOPARENTNOTIFY = &H4&
'Public Const WS_DLGFRAME = &H400000
Public Const WS_OVERLAPPED = &H0&
Public Const WS_CAPTION = &HC00000
Public Const WS_MAXIMIZEBOX = &H10000
Public Const WS_MINIMIZEBOX = &H20000
Public Const WS_SYSMENU = &H80000
Public Const WS_THICKFRAME = &H40000
Public Const WS_VISIBLE = &H10000000
Public Const WS_OVERLAPPEDWINDOW = (WS_OVERLAPPED Or WS_CAPTION Or WS_SYSMENU Or WS_THICKFRAME Or WS_MINIMIZEBOX Or WS_MAXIMIZEBOX)
Public Const DS_MODALFRAME = &H80
Public Const GWL_EXSTYLE As Long = (-20)
Public Const GWL_WNDPROC As Long = (-4&)
Public Const WS_CLIPCHILDREN = &H2000000
Public Const WS_CLIPSIBLINGS = &H4000000
Public Const WS_VSCROLL = &H200000

Public Const WM_ACTIVATE = &H6
Public Const WM_NCACTIVATE = &H86
Public Const WM_NCHITTEST = &H84
Public Const WM_WINDOWPOSCHANGING = &H46
Public Const WM_KILLFOCUS = &H8
Public Const WM_PAINT = &HF
Public Const WM_NCPAINT = &H85
Public Const WM_GETDLGCODE = &H87
Public Const WM_NCMOUSEMOVE = &HA0
Public Const WM_NCLBUTTONDOWN = &HA1
Public Const WM_NCLBUTTONUP = &HA2
Public Const WM_NCLBUTTONDBLCLK = &HA3
Public Const WM_NCRBUTTONDOWN = &HA4
Public Const WM_NCRBUTTONUP = &HA5
Public Const WM_NCRBUTTONDBLCLK = &HA6
Public Const WM_NCMBUTTONDOWN = &HA7
Public Const WM_NCMBUTTONUP = &HA8
Public Const WM_NCMBUTTONDBLCLK = &HA9
Public Const WM_SYSCOMMAND = &H112
Public Const WM_EXITSIZEMOVE = &H232
Public Const WM_LBUTTONDBLCLK = &H203
Public Const WM_GETMINMAXINFO = &H24
Public Const WM_MOUSEMOVE = &H200
Public Const WM_LBUTTONDOWN = &H201
Public Const WM_LBUTTONUP = &H202
Public Const WM_RBUTTONDOWN = &H204
Public Const WM_RBUTTONUP = &H205
Public Const WM_MBUTTONDOWN = &H207
Public Const WM_MBUTTONUP = &H208
Public Const WM_NOTIFY = &H4E

Public Const TTM_RELAYEVENT = (WM_USER + 7)

'ToolTip Notification
Public Const H_MAX As Long = &HFFFFFFFF + 1
Public Const TTN_FIRST = (H_MAX - 520&)
#If UNICODE Then
  Public Const TTN_NEEDTEXTW = (TTN_FIRST - 10&)
  Public Const TTN_NEEDTEXT = TTN_NEEDTEXTW
#Else
  Public Const TTN_NEEDTEXTA = (TTN_FIRST - 0&)
  Public Const TTN_NEEDTEXT = TTN_NEEDTEXTA
#End If

Private m_hKeyHook  As Long

'Declarations for web access
Private Const SW_SHOW = 5       ' Displays Window in its current size
                                      ' and position
Private Const SW_SHOWNORMAL = 1 ' Restores Window if Minimized or
                                      ' Maximized

Declare Function ShellExecute Lib "shell32.dll" Alias _
         "ShellExecuteA" (ByVal hWnd As Long, ByVal lpOperation As _
         String, ByVal lpFile As String, ByVal lpParameters As String, _
         ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long
Private Declare Function FindExecutable Lib "shell32.dll" Alias _
         "FindExecutableA" (ByVal lpFile As String, ByVal lpDirectory As _
         String, ByVal lpResult As String) As Long
         
'code for execCmd 07/19/01 GH
Private Type STARTUPINFO
      cb As Long
      lpReserved As String
      lpDesktop As String
      lpTitle As String
      dwX As Long
      dwY As Long
      dwXSize As Long
      dwYSize As Long
      dwXCountChars As Long
      dwYCountChars As Long
      dwFillAttribute As Long
      dwFlags As Long
      wShowWindow As Integer
      cbReserved2 As Integer
      lpReserved2 As Long
      hStdInput As Long
      hStdOutput As Long
      hStdError As Long
   End Type

   Private Type PROCESS_INFORMATION
      hProcess As Long
      hThread As Long
      dwProcessId As Long
      dwThreadId As Long
   End Type

   Private Declare Function WaitForSingleObject Lib "kernel32" (ByVal _
      hHandle As Long, ByVal dwMilliseconds As Long) As Long

   Private Declare Function CreateProcessA Lib "kernel32" (ByVal _
      lpApplicationName As String, ByVal lpCommandLine As String, ByVal _
      lpProcessAttributes As Long, ByVal lpThreadAttributes As Long, _
      ByVal bInheritHandles As Long, ByVal dwCreationFlags As Long, _
      ByVal lpEnvironment As Long, ByVal lpCurrentDirectory As String, _
      lpStartupInfo As STARTUPINFO, lpProcessInformation As _
      PROCESS_INFORMATION) As Long

   Public Declare Function CloseHandle Lib "kernel32" _
      (ByVal hObject As Long) As Long

   Private Declare Function GetExitCodeProcess Lib "kernel32" _
      (ByVal hProcess As Long, lpExitCode As Long) As Long

   Private Const NORMAL_PRIORITY_CLASS = &H20&
   Private Const INFINITE = -1&
   'end of code for execCmd 07/19/01 GH
   
   Public Const CB_SHOWDROPDOWN = &H14F
   Public Const CB_GETITEMHEIGHT = &H154

   
   'File API Functions ----------------------------------------------------------
Public Const INVALID_HANDLE_VALUE As Long = -1
Public Const FILE_ATTRIBUTE_DIRECTORY As Long = &H10
Public Const SHGFI_TYPENAME As Long = &H400
Public Const FILE_READ_DATA As Long = &H1 ' File pipe
Public Const GENERIC_READ As Long = &H80000000
Public Const FILE_SHARE_READ As Long = &H1
Public Const OPEN_EXISTING As Long = &H3

Public Type SHFILEINFO
   hIcon As Long
   iIcon As Long
   dwAttributes As Long
   szDisplayName As String * MAX_PATH
   szTypeName As String * 80
End Type

Public Type SYSTEMTIME
   wYear As Integer
   wMonth As Integer
   wDayOfWeek As Integer
   wDay As Integer
   wHour As Integer
   wMinute As Integer
   wSecond As Integer
   wMilliseconds As Integer
End Type

Public Type FILETIME
   dwLowDateTime As Long
   dwHighDateTime As Long
End Type

Public Type WIN32_FIND_DATA
   dwFileAttributes As Long
   ftCreationTime As FILETIME
   ftLastAccessTime As FILETIME
   ftLastWriteTime As FILETIME
   nFileSizeHigh As Long
   nFileSizeLow As Long
   dwReserved0 As Long
   dwReserved1 As Long
   cFileName As String * MAX_PATH
   cAlternate As String * 14
End Type

Public Type FILE_PARAMS
   fAttributes As Long
   sFileRoot As String
   sFileNameExt As String
End Type

Public Declare Function FindClose Lib "kernel32" _
  (ByVal hFindFile As Long) As Long
   
Public Declare Function FindFirstFile Lib "kernel32" _
   Alias "FindFirstFileA" _
  (ByVal lpFileName As String, _
   lpFindFileData As WIN32_FIND_DATA) As Long
   
Public Declare Function FindNextFile Lib "kernel32" _
   Alias "FindNextFileA" _
  (ByVal hFindFile As Long, _
   lpFindFileData As WIN32_FIND_DATA) As Long
   
Public Declare Function CreateFile Lib "Kernel32.dll" Alias "CreateFileA" ( _
   ByVal lpFileName As String, ByVal dwDesiredAccess As Long, _
   ByVal dwShareMode As Long, ByRef lpSecurityAttributes As Any, _
   ByVal dwCreationDisposition As Long, ByVal dwFlagsAndAttributes As Long, _
   ByVal hTemplateFile As Long) As Long

Public Declare Function ReadFileAPI Lib "Kernel32.dll" Alias "ReadFile" ( _
   ByVal hFile As Long, _
   ByRef lpBuffer As Any, ByVal nNumberOfBytesToRead As Long, _
   ByRef lpNumberOfBytesRead As Long, ByRef lpOverlapped As Any) As Long

Private Declare Function GetFullPathName Lib "kernel32" Alias "GetFullPathNameA" _
   (ByVal lpFileName As String, ByVal nBufferLength As Long, ByVal lpBuffer As String, ByVal lpFilePart As String) As Long

   
'***************** Resource Handling ***********************

Private Declare Function UpdateResource Lib "kernel32" Alias "UpdateResourceA" _
   (ByVal hUpdate As Long, ByVal lpType As Long, ByVal lpName As String, _
   ByVal wLanguage As Long, _
   lpData As Any, ByVal cbData As Long) As Long

Private Declare Function UpdateResourceStr Lib "kernel32" Alias "UpdateResourceA" _
   (ByVal hUpdate As Long, ByVal lpType As String, ByVal lpName As String, _
   ByVal wLanguage As Long, _
   lpData As Any, ByVal cbData As Long) As Long

Private Declare Function BeginUpdateResource Lib "kernel32" _
   Alias "BeginUpdateResourceA" (ByVal pFileName As String, _
   ByVal bDeleteExistingResources As Long) As Long

Private Declare Function EndUpdateResource Lib "kernel32" _
   Alias "EndUpdateResourceA" (ByVal hUpdate As Long, _
   ByVal fDiscard As Long) As Long

Private Declare Function GetObject Lib "GDI32" Alias "GetObjectA" _
   (ByVal hObject As Long, ByVal nCount As Long, lpObject As Any) As Long

Private Declare Function GetDIBits Lib "GDI32" (ByVal hDC As Long, _
   ByVal hBmp As Long, ByVal uStartScan As Long, ByVal cScanLines As Long, _
   lpvBits As Any, lpbm As BITMAPINFOHEADER, ByVal fuColorUse As Long) As Long

Private Declare Sub CopyMemory Lib "kernel32" _
    Alias "RtlMoveMemory" (Destination As Any, _
    Source As Any, ByVal Length As Long)

Private Type BITMAPINFOHEADER '40 bytes
   biSize As Long
   biWidth As Long
   biHeight As Long
   biPlanes As Integer
   biBitCount As Integer
   biCompression As Long
   biSizeImage As Long
   biXPelsPerMeter As Long
   biYPelsPerMeter As Long
   biClrUsed As Long
   biClrImportant As Long
   End Type

Private Type BITMAP       ' DDB bitmap info
   bmType As Long
   bmWidth As Long
   bmHeight As Long
   bmWidthBytes As Long
   bmPlanes As Integer
   bmBitsPixel As Integer
   bmBits As Long
   End Type

Private Type BITMAPFILEHEADER  ' 14-byte "BM" .bmp file header
   bfType As Integer
   bfSize As Long
   bfReserved1 As Integer
   bfReserved2 As Integer
   bfOffBits As Long
   End Type

Public Declare Function InitCommonControls Lib "Comctl32" () As Long

Declare Function CreateSolidBrush Lib "GDI32" (ByVal crColor As Long) As Long
Declare Function DeleteObject Lib "GDI32" (ByVal hObject As Long) As Long
Declare Function FillRect Lib "USER32" (ByVal hDC As Long, lpRect As RECT, ByVal hBrush As Long) As Long
   
Public Const CSIDL_PROGRAM_FILES = &H26

Type ChooseColorStruct
    lStructSize As Long
    hwndOwner As Long
    hInstance As Long
    rgbResult As Long
    lpCustColors As Long
    flags As Long
    lCustData As Long
    lpfnHook As Long
    lpTemplateName As String
End Type

Declare Function ChooseColor Lib "comdlg32.dll" Alias "ChooseColorA" _
    (lpChoosecolor As ChooseColorStruct) As Long
Declare Function OleTranslateColor Lib "oleaut32.dll" (ByVal lOleColor _
    As Long, ByVal lHPalette As Long, lColorRef As Long) As Long
    
Const CC_RGBINIT = &H1&
Const CC_FULLOPEN = &H2&
Const CC_PREVENTFULLOPEN = &H4&
Const CC_SHOWHELP = &H8&
Const CC_ENABLEHOOK = &H10&
Const CC_ENABLETEMPLATE = &H20&
Const CC_ENABLETEMPLATEHANDLE = &H40&
Const CC_SOLIDCOLOR = &H80&
Const CC_ANYCOLOR = &H100&
Const CLR_INVALID = &HFFFF

   
Public Function ExecCmd(cmdline$)         '07/19/01 gh
   Dim proc As PROCESS_INFORMATION
   Dim start As STARTUPINFO
   Dim ret As Long

   ' Initialize the STARTUPINFO structure:
   start.cb = Len(start)

   ' Start the shelled application:
   ret = CreateProcessA(vbNullString, cmdline$, 0&, 0&, 1&, NORMAL_PRIORITY_CLASS, 0&, vbNullString, start, proc)

   ' Wait for the shelled application to finish:
      ret = WaitForSingleObject(proc.hProcess, INFINITE)
      Call GetExitCodeProcess(proc.hProcess, ret&)
      Call CloseHandle(proc.hThread)
      Call CloseHandle(proc.hProcess)
      ExecCmd = ret&
End Function

Public Sub InstallHook()
   If m_hKeyHook = 0 Then
      m_hKeyHook = SetWindowsHookEx(WH_KEYBOARD, AddressOf TabKeyProc, 0&, app.ThreadID)
   End If
End Sub
Public Sub RemoveHook()
   If m_hKeyHook <> 0 Then
      UnhookWindowsHookEx m_hKeyHook
      m_hKeyHook = 0
   End If
End Sub

Public Property Get GetCDlgFileName(ByVal hDlg As Long) As String
Dim sBuf As String
Dim iPos As Long
Dim hWnd As Long
   hWnd = GetParent(hDlg)
   sBuf = String$(MAX_PATH, 0)
   SendMessageString hWnd, CDM_GETFILEPATH, 260, sBuf
   iPos = InStr(sBuf, vbNullChar)
   If iPos > 0 Then
'      GetCDlgFileName = Left$(sBuf, iPos - 1)
      GetCDlgFileName = Mid(sBuf, 1, iPos - 1)
   End If
End Property

Public Function TabKeyProc(ByVal nCode As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
  
 If nCode >= 0 And Not (frmNewOpen Is Nothing) Then
  If wParam = 9 Then
      
   If (lParam And &HC0000000) = 0 And (lParam And KBH_MASK) <> 0 Then
    'do nothing
   ElseIf GetKeyState(VK_CONTROL) <= 1 Then
    
    If GetKeyState(VK_SHIFT) < 0 And GetKeyState(VK_TAB) < 0 Then
     If lParam = 135200769 Or lParam = 1208942593 Or lParam = 983041 Or 1074724865 Then
      If frmNewOpen.SetBackwardFocus Then
       TabKeyProc = 1&: Exit Function
      End If
     End If

    ElseIf GetKeyState(VK_TAB) < 0 Then
     If lParam = 135200769 Or lParam = 1208942593 Or lParam = 983041 Or 1074724865 Then
      If frmNewOpen.SetForwardFocus Then
       TabKeyProc = 1&: Exit Function
      End If
     End If
    
    End If
   
   End If
  
  ElseIf wParam = 13 Then
   If frmNewOpen.IsNew Then
    If Not (frmNewOpen.lvwNew.SelectedItem Is Nothing) Then
     If frmNewOpen.lvwNew.SelectedItem.Text <> "" Then
      frmNewOpen.cmdNewOpen.Value = True
      TabKeyProc = 1: Exit Function
     End If
    End If
   End If
  End If
 
 End If
         
 TabKeyProc = CallNextHookEx(m_hKeyHook, nCode, wParam, lParam)
         
End Function
Sub openWebPage(pageName As String)
      
      Dim filename, Dummy As String
      Dim BrowserExec As String * 255
      Dim RetVal As Long
      Dim FileNumber As Integer

      RetVal = ShellExecute(frmMain.hWnd, "open", pageName, Dummy, Dummy, SW_SHOWNORMAL)
      If RetVal <= 32 Then        ' Error
         MsgBox gStringTable(3326), vbExclamation ' "Web Page not Opened" "URL Failed"
      End If
      Exit Sub

      ' First, create a known, temporary HTML file
      BrowserExec = Space(255)
      filename = "C:\temphtm.HTM"
      FileNumber = FreeFile                    ' Get unused file number
      Open filename For Output As #FileNumber  ' Create temp HTML file
          Write #FileNumber, "<HTML> <\HTML>"  ' Output text
      Close #FileNumber                        ' Close file
      ' Then find the application associated with it
      RetVal = FindExecutable(filename, Dummy, BrowserExec)
      BrowserExec = Trim(BrowserExec)
      ' If an application is found, launch it!
      If RetVal <= 32 Or IsEmpty(BrowserExec) Then ' Error
          MsgBox gStringTable(3325), vbExclamation '"Could not find associated Browser"
      Else
            RetVal = ShellExecute(frmMain.hWnd, "open", BrowserExec, Chr(34) & pageName & Chr(34), Dummy, SW_SHOWNORMAL)
            If RetVal <= 32 Then        ' Error
                MsgBox gStringTable(3326), vbExclamation ' "Web Page not Opened" "URL Failed"
            End If
      End If
      Kill filename                   ' delete temp HTML file
End Sub
'*******************************************************************************
' GetRelativePath (FUNCTION)
'
' PARAMETERS:
' (In) - sFromDirectory - String - Path for directory
' (In) - sToFile        - String - Path for file
'
' RETURN VALUE:
' String - The compacted path (empty if failed)
'
' DESCRIPTION:
' GetRelativePath demonstrates when given a directory path and a file path how
' to return the relative path from the directory to the file.
'*******************************************************************************
Public Function GetRelativePath(ByVal sFromDirectory As String, _
                                ByVal sToFile As String) As String
                                
    Dim sRelativePath   As String
    Dim bResult         As Boolean
    
    Const MAX_PATH As Long = 260
    
    sRelativePath = Space(MAX_PATH)
    
    ' Set "Attr" to vbDirectory for directories and 0 for files
    bResult = PathRelativePathToW(StrPtr(sRelativePath), StrPtr(sFromDirectory), vbDirectory, StrPtr(sToFile), 0)
    
    If bResult Then
        GetRelativePath = Left(sRelativePath, InStr(sRelativePath, Chr(0)) - 1)
    End If

   If (LCase(Left(sFromDirectory, 2)) <> LCase(Left(sToFile, 2))) Or _
      (Mid(sToFile, 2, 1) <> ":") Then
      GetRelativePath = sToFile 'file is on a different drive or network
   End If

End Function
Public Function GetAbsolutePath(ByVal BasePath As String, ByVal FN As String) As String
   Dim sReturn As String
   Dim p As Long

   sReturn = String(260, 0)
   If Right$(BasePath, 1) <> "\" Then
      BasePath = BasePath & "\"
   End If
   If GetFullPathName(BasePath & FN, 260, sReturn, p) = 0 Then
      GetAbsolutePath = FN
   Else
      GetAbsolutePath = Left$(sReturn, InStr(1, sReturn, Chr(0)) - 2)
   End If
End Function

Public Function ReadFileViaAPI(astrFile As String, ByRef astrText As String) As Boolean

Dim hFile As Long
Dim FBuf() As Byte
Dim bytesRead As Long

hFile = CreateFile(astrFile, GENERIC_READ, FILE_SHARE_READ, ByVal 0&, OPEN_EXISTING, 0, 0)
If hFile <> INVALID_HANDLE_VALUE Then
   ReDim FBuf(FileLen(astrFile)) As Byte
   Call ReadFileAPI(hFile, FBuf(0), FileLen(astrFile), bytesRead, ByVal 0&)
   Call CloseHandle(hFile)
   astrText = ByteArrayToString(FBuf)
   ReadFileViaAPI = True
Else
   ReadFileViaAPI = False
End If
End Function
Private Function ByteArrayToString(bytArray() As Byte) As String
    Dim sAns As String
    Dim iPos As String
    
    sAns = StrConv(bytArray, vbUnicode)
    iPos = InStr(sAns, Chr(0))
    If iPos > 0 Then sAns = Left(sAns, iPos - 1)
    
    ByteArrayToString = sAns
 
 End Function
Public Sub SetTopmostWindow(ByVal hWnd As Long, Optional topmost As Boolean = True)
    Const HWND_NOTOPMOST = -2
    Const HWND_TOPMOST = -1
    Const SWP_NOMOVE = &H2
    Const SWP_NOSIZE = &H1
    SetWindowPos hWnd, IIf(topmost, HWND_TOPMOST, HWND_NOTOPMOST), 0, 0, 0, 0, _
        SWP_NOMOVE + SWP_NOSIZE
End Sub

Function InjectBMPResource(resID As String, exeName As String, bmpFile As String)
   Const resLang = &H0      ' Lang neutral
   Dim rSize&, bmpHeader As BITMAPFILEHEADER
   Dim PicBmp() As Byte       ' DIB buffer
   Dim hUpt As Long, ret As Long
   
   'Read DIB direct from .BMP file
   rSize = FileLen(bmpFile) - Len(bmpHeader)
   ReDim PicBmp(rSize - 1)
   Open bmpFile For Binary As #1
   Get #1, , bmpHeader  ' we just skip the first 14 bytes
   Get #1, , PicBmp     ' Here's the DIB bitmap
   Close #1
   
   'plug it straight in to UpdateResource
   hUpt = BeginUpdateResource(exeName, 0)
   ret = UpdateResource(hUpt, 2, UCase(resID), resLang, PicBmp(0), rSize)
   ret = EndUpdateResource(hUpt, 0) ' 0 = change
   InjectBMPResource = ret
End Function

Function InjectWaveResource(resID As String, exeName As String, inFile As String)
   Const resLang = &H0     ' Lang Neutral
   Dim filedata() As Byte
   Dim hUpt As Long, ret As Long
   
   'Read input file
   Dim rSize As Long
   rSize = FileLen(inFile)
   ReDim filedata(rSize - 1)
   Open inFile For Binary As #1
   Get #1, , filedata
   Close #1
   
   'plug it straight in to UpdateResource
   hUpt = BeginUpdateResource(exeName, 0)  ' use 1 to clear all existing!
   ret = UpdateResourceStr(hUpt, "WAVE", UCase(resID), resLang, filedata(0), rSize)
   ret = EndUpdateResource(hUpt, 0) ' 0 = change
   InjectWaveResource = ret
End Function

Function InjectDataResource(resID As String, exeName As String, inFile As String)
   Const resLang = &H0     ' Lang Neutral
   Dim filedata() As Byte
   Dim hUpt As Long, ret As Long
   
   'Read input file
   Dim rSize As Long
   
   rSize = FileLen(inFile)
   ReDim filedata(rSize - 1)
   Open inFile For Binary As #1
   Get #1, , filedata
   Close #1
   
   'plug it straight in to UpdateResource
   hUpt = BeginUpdateResource(exeName, 0)  ' use 1 to clear all existing!
   ret = UpdateResource(hUpt, 10, UCase(resID), resLang, filedata(0), rSize) '10 is RT_RCDATA
   ret = EndUpdateResource(hUpt, 0) ' 0 = change
   InjectDataResource = ret
End Function
Function InjectHiResResource(exeName As String)
   Const resLang = &H0     ' Lang Neutral
   Dim filedata() As Byte
   ReDim filedata(2)
   Dim hUpt As Long, ret As Long
   
   filedata(0) = CByte(1)
   filedata(1) = CByte(0)
   
   'plug it straight in to UpdateResource
   hUpt = BeginUpdateResource(exeName, 0)  ' use 1 to clear all existing!
   ret = UpdateResourceStr(hUpt, "CEUX", "HI_RES_AWARE", resLang, filedata(0), 2)
   ret = EndUpdateResource(hUpt, 0) ' 0 = change
   InjectHiResResource = ret
End Function

Sub InjectResources(outputfile As String)
Dim resource As CResourceFile
Dim res As Integer
Dim GradientButtons() As String
Dim gb As String
Dim Path As String
Dim i As Integer
   
   If gTarget.HiRes Then res = InjectHiResResource(outputfile)

   For Each resource In gTarget.ResourceFiles
      If resource.ResType <> 3 Then
         Path = resource.PathName
         If Left(LCase(resource.PathName), 10) = "{controls}" Then
            Path = installationDirectory & "\controls\" & getPlatform & "\" & Mid(resource.PathName, 12)
         End If
         
         If Dir(Path) = "" Then
            MsgBox gStringTable(3483) & Path 'File not found
            Exit Sub
         End If
         
         Select Case resource.ResType
         Case 0: 'picture
               res = InjectBMPResource(resource.Name, outputfile, Path)
         Case 1: 'file
               res = InjectDataResource(resource.Name, outputfile, Path)
         Case 2: 'WAV
               res = InjectWaveResource(resource.Name, outputfile, Path)
         End Select
      End If
   Next
   
   GradientButtons = Split(gTarget.GradientButtons, "|")
   For i = 1 To UBound(GradientButtons) - 1
      gb = GradientButtons(i)
      res = InjectBMPResource(UCase(gb), outputfile, gTarget.Name & "_" & gb & ".bmp")
   Next
   
End Sub
Public Sub DrawGradient(lDestHDC As Long, lDestWidth As Long, lDestHeight As Long, lStartColor As Long, lEndColor As Long, iStyle As Integer)
'lDestHDC - The hDC of the object you want to draw to
'lDestWidth - The Width of the Gradient
'lDestHeight - The Height of the Gradient
'lStartColor - The color the gradient starts out with
'lEndColor - The color the gradient ends up with
'iStyle - 0 for left to right gradient or 1 for top to bottom gradient.

'Set Autoredraw to true to reduce flickering while resizing the form.

   Dim udtRect As RECT
   Dim iBlueStart As Integer
   Dim iBlueEnd As Integer
   Dim iRedStart As Integer
   Dim iRedEnd As Integer
   Dim iGreenStart As Integer
   Dim iGreenEnd As Integer

   Dim hBrush As Long

   'On Error Resume Next

   'Calculate the beginning colors
   iBlueStart = Int(lStartColor / &H10000)
   iGreenStart = Int(lStartColor - (iBlueStart * &H10000)) \ CLng(&H100)
   iRedStart = lStartColor - (iBlueStart * &H10000) - CLng(iGreenStart * CLng(&H100))

   'Calculate the End colors
   iBlueEnd = Int(lEndColor / &H10000)
   iGreenEnd = Int(lEndColor - (iBlueEnd * &H10000)) \ CLng(&H100)
   iRedEnd = lEndColor - (iBlueEnd * &H10000) - CLng(iGreenEnd * CLng(&H100))

   Const intBANDWIDTH = 1

   Dim sngBlueCur As Single
   Dim sngBlueStep As Single
   Dim sngGreenCur As Single
   Dim sngGreenStep As Single
   Dim sngRedCur As Single
   Dim sngRedStep As Single

   Dim iHeight As Integer
   Dim iWidth As Integer
   Dim intY As Integer
   Dim iDrawEnd As Integer

   Dim lReturn As Long

   iHeight = lDestHeight + 1
   iWidth = lDestWidth

   sngBlueCur = iBlueStart
   sngGreenCur = iGreenStart
   sngRedCur = iRedStart

   'Calculate the size of the color bars
   If iStyle = 0 Then 'left to right
      sngBlueStep = intBANDWIDTH * (iBlueEnd - iBlueStart) / (iWidth - 4)
      sngGreenStep = intBANDWIDTH * (iGreenEnd - iGreenStart) / (iWidth - 4)
      sngRedStep = intBANDWIDTH * (iRedEnd - iRedStart) / (iWidth - 4)
      With udtRect
         .Left = 0
         .Top = 0
         .Right = intBANDWIDTH + 3
         .Bottom = iHeight
      End With
      iDrawEnd = iWidth
   ElseIf iStyle = 1 Then  'top to bottom
      sngBlueStep = intBANDWIDTH * (iBlueEnd - iBlueStart) / (iHeight - 4)
      sngGreenStep = intBANDWIDTH * (iGreenEnd - iGreenStart) / (iHeight - 4)
      sngRedStep = intBANDWIDTH * (iRedEnd - iRedStart) / (iHeight - 4)
      With udtRect
         .Left = 0
         .Top = 0
         .Right = iWidth  '- 2
         .Bottom = intBANDWIDTH + 2
      End With
      iDrawEnd = iHeight
   End If

   'Draw the Gradient
   'For intY = 0 To (iDrawEnd / 15) - 5 Step intBANDWIDTH
   For intY = 0 To iDrawEnd - 4 Step intBANDWIDTH
      hBrush = CreateSolidBrush(RGB(sngRedCur, sngGreenCur, sngBlueCur))
      lReturn = FillRect(lDestHDC, udtRect, hBrush)

      lReturn = DeleteObject(hBrush)
      sngBlueCur = sngBlueCur + sngBlueStep
      sngGreenCur = sngGreenCur + sngGreenStep
      sngRedCur = sngRedCur + sngRedStep
      If iStyle = 0 Then 'left to right
         udtRect.Left = udtRect.Left + intBANDWIDTH
         udtRect.Right = udtRect.Right + intBANDWIDTH
      ElseIf iStyle = 1 Then 'top to bottom
         udtRect.Top = udtRect.Top + intBANDWIDTH
         udtRect.Bottom = udtRect.Bottom + intBANDWIDTH
      End If
   Next
End Sub
