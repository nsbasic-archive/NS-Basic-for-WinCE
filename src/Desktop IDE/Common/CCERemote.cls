VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CCERemote"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Option Explicit
Const GENERIC_READ = &H80000000
Const FILE_SHARE_READ = &H1
Const CREATE_ALWAYS = 2
Const OPEN_EXISTING = 3
Const FILE_ATTRIBUTE_NORMAL = &H80
Const GENERIC_WRITE = &H40000000
Const OPEN_ALWAYS = 4
Const FILE_END = 2
Const FILE_CURRENT = 1
Const FILE_ATTRIBUTE_DIRECTORY = &H10

Private Type OVERLAPPED
        Internal As Long
        InternalHigh As Long
        offset As Long
        OffsetHigh As Long
        hEvent As Long
End Type
 
Private Type SECURITY_ATTRIBUTES
        nLength As Long
        lpSecurityDescriptor As Long
        bInheritHandle As Long
End Type

 Private Type PROCESS_INFORMATION
     hProcess As Long
     hThread As Long
     dwProcessId As Long
     dwThreadId As Long
 End Type
 
 Private Type RAPIINIT
     cbSize As Long
     heRapiInit As Long
     hrRapiInit As Long
 End Type
 Private Type FILETIME
        dwLowDateTime As Long
        dwHighDateTime As Long
  End Type

 Private Type LPCE_FIND_DATA
     dwFileAttributes As Long
     ftCreationTime As FILETIME
     ftLastAccessTime As FILETIME
     ftLastWriteTime As FILETIME
     nFileSizeHigh As Long
     nFileSizeLow As Long
     dwOID As Long
     cFileName As String * 255
 End Type

Enum enHKEY
 HKEY_CLASSES_ROOT1 = &H80000000
 HKEY_CURRENT_USER1 = &H80000001
 HKEY_LOCAL_MACHINE = &H80000002
 HKEY_USERS = &H80000003
 HKEY_PERFORMANCE_DATA = &H80000004
 HKEY_CURRENT_CONFIG = &H80000005
 HKEY_DYN_DATA = &H80000006
End Enum

        
' Windows Declarations
Private Declare Function MultiByteToWideChar Lib "kernel32" (ByVal CodePage As Long, ByVal dwFlags As Long, ByVal lpMultiByteStr As String, ByVal cchMultiByte As Long, ByVal lpWideCharStr As String, ByVal cchWideChar As Long) As Long
Private Declare Function WaitForSingleObject Lib "kernel32" (ByVal hHandle As Long, ByVal dwMilliseconds As Long) As Long
Private Declare Function WriteFile Lib "kernel32" (ByVal hFile As Long, ByVal lpBuffer As String, ByVal nNumberOfBytesToWrite As Long, lpNumberOfBytesWritten As Long, ByVal lpOverlapped As Long) As Long
Private Declare Function CreateFile Lib "kernel32" Alias "CreateFileA" (ByVal lpFileName As String, ByVal dwDesiredAccess As Long, ByVal dwShareMode As Long, ByVal lpSecurityAttributes As Long, ByVal dwCreationDisposition As Long, ByVal dwFlagsAndAttributes As Long, ByVal hTemplateFile As Long) As Long
Private Declare Function CloseHandle Lib "kernel32" (ByVal hObject As Long) As Long
Private Declare Function SetFilePointer Lib "kernel32" (ByVal hFile As Long, ByVal lDistanceToMove As Long, lpDistanceToMoveHigh As Long, ByVal dwMoveMethod As Long) As Long
Private Declare Function GetFileSize Lib "kernel32" (ByVal hFile As Long, lpFileSizeHigh As Long) As Long
Private Declare Function ReadFile Lib "kernel32" (ByVal hFile As Long, ByVal lpBuffer As Any, ByVal nNumberOfBytesToRead As Long, lpNumberOfBytesRead As Long, ByVal lpOverlapped As Long) As Long
Private Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (pDst As Any, pSrc As Any, ByVal ByteLen As Long)

' CE Remote Declarations
Private Declare Function CeRapiInit Lib "rapi.dll" () As Long
Private Declare Function CeRapiInitEx Lib "rapi.dll" (RrApIn As RAPIINIT) As Long
Private Declare Sub CeRapiUninit Lib "rapi.dll" ()
Private Declare Function CeGetTempPath Lib "rapi.dll" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
Private Declare Function CeCreateFile Lib "rapi.dll" (ByVal lpFileName As String, ByVal dwDesiredAccess As Long, ByVal dwShareMode As Long, ByVal lpSecurityAttributes As Long, ByVal dwCreationDisposition As Long, ByVal dwFlagsAndAttributes As Long, ByVal hTemplateFile As Long) As Long
Private Declare Function CeReadFile Lib "rapi.dll" (ByVal hFile As Long, ByVal lpBuffer As String, ByVal nNumberOfBytesToRead As Long, lpNumberOfBytesRead As Long, ByVal lpOverlapped As Long) As Long
Private Declare Function CeCopyFile Lib "rapi.dll" (ByVal lpExistingFileName As String, ByVal lpNewFileName As String, ByVal bFailIfExists As Long) As Long
Private Declare Function CeWriteFile Lib "rapi.dll" (ByVal hFile As Long, ByVal lpBuffer As String, ByVal nNumberOfBytesToRead As Long, lpNumberOfBytesRead As Long, ByVal lpOverlapped As Long) As Long
Private Declare Function CeGetFileSize Lib "rapi.dll" (ByVal hFile As Long, lpFileSizeHigh As Long) As Long
Private Declare Function CeCloseHandle Lib "rapi.dll" (hObject As Long) As Long
Private Declare Function CeSHCreateShortcut Lib "rapi.dll" (ByVal lpszShortcut As String, ByVal lpszTarget As String) As Long
Private Declare Function CeCreateProcess Lib "rapi.dll" (ByVal lpApplicationName As String, ByVal lpCommandLine As String, ByVal lpProcessAttributes As Long, ByVal lpThreadAttributes As Long, ByVal bInheritHandles As Long, ByVal dwCreationFlags As Long, ByVal lpEnvironment As Long, ByVal lpCurrentDirectory As Long, ByVal lpStartupInfo As Long, lpProcessInformation As PROCESS_INFORMATION) As Long
Private Declare Function CeRapiGetError Lib "rapi.dll" () As Long

Private Declare Function CeRegQueryValueEx Lib "rapi.dll" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, lpType As Long, lpData As Any, lpcbData As Long) As Long

Private Declare Function CeRegOpenKeyEx Lib "rapi.dll" (ByVal hKey As Long, ByVal lpszSubKey As String, ByVal ulOptions As String, ByVal samDesired As Long, phkResult As Long) As Long

Private Declare Function CeFindFirstFile Lib "rapi.dll" (ByVal pFileName As String, findData As LPCE_FIND_DATA) As Long
Private Declare Function CeFindNextFile Lib "rapi.dll" (ByVal hFindFile As Long, findData As LPCE_FIND_DATA) As Long
Private Declare Function CeFindClose Lib "rapi.dll" (ByVal hFindFile As Long) As Long
Private Declare Function CeCreateDirectory Lib "rapi.dll" (ByVal pFileName As String, atrrib As SECURITY_ATTRIBUTES) As Long
Private Declare Function CeGetSpecialFolderPath Lib "rapi.dll" (ByVal nFolder As Integer, ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long

Private Type tFiles
  Name As String
  Attrib As String
End Type
Dim Files() As tFiles
Event Progress(TotalBytesTransferred As Long, TotalFileSize As Long)

Public Function Init() As Boolean
  Dim hRes As Long
  Dim dwRet As Long
  Dim ri As RAPIINIT
   Init = True
   ri.cbSize = Len(ri)
   On Error GoTo noActiveSync
   hRes = CeRapiInitEx(ri)
   On Error GoTo 0
   dwRet = WaitForSingleObject(ri.heRapiInit, 5000)

    If dwRet <> 0 Or ri.hrRapiInit <> 0 Then
       'Could not initialize Rapi
       CeRapiUninit
       Init = False
    End If
    Exit Function
noActiveSync:
   MsgBox gStringTable(3368) 'ActiveSync not found."
   Init = False
End Function


Public Function ExecuteOnDevice(filename As String, Optional CommandLine As String) As Long
 Dim ret As Long
 Dim Info As PROCESS_INFORMATION
 Dim fName As String
 Dim cLine As String
 'fName = StrConv(fileName & " " & CommandLine, vbUnicode)
 fName = StrConv(filename, vbUnicode)
 cLine = StrConv(CommandLine, vbUnicode)
 ret = CeCreateProcess(fName, cLine, 0&, 0&, False, 0, 0&, 0&, 0&, Info)
 'MsgBox "executeOnDevice returns " & ret & " " & fileName
 If ret <> 0 Then
   ExecuteOnDevice = ret
 End If
End Function

Public Function CopyFile(ByVal ExistingFileName As String, ByVal NewFileName As String, Optional OverWrite As Boolean = False) As Boolean
   Dim ret As Long
   CopyFile = False
   ExistingFileName = StrConv(ExistingFileName, vbUnicode)
   NewFileName = StrConv(NewFileName, vbUnicode)
   ret = CeCopyFile(ExistingFileName, NewFileName, OverWrite)
   If ret <> 0 Then
      CopyFile = True
   End If
End Function

Public Sub UnInit()
   CeRapiUninit
End Sub

Public Function CopyFileToCEDevice(DesktopSourceFile As String, CEDestinationFile As String) As Boolean
   Dim res As Integer
   Dim command As String
   Dim q As String
   q = Chr(34)
   
   If Left(CEDestinationFile, 1) = "\" Then CEDestinationFile = Mid(CEDestinationFile, 2)
   command = q & installationDirectory & "\ceFileCopy.exe" & q & " /v " & q & DesktopSourceFile & q & " " & q & CEDestinationFile & q
   res = ExecCmd(command)
   If res = 0 Then
      CopyFileToCEDevice = True
   Else
      CopyFileToCEDevice = False
   End If
End Function

Public Function oldCopyFileToCEDevice(DesktopSourceFile As String, CEDestinationFile As String) As Boolean
 Dim hFile As Long
Dim fout As Long
Dim fName As String
Dim ret As Long
Dim sBuffer As String
Dim inBytes As Long
Dim BufferSize As Integer
Dim lSize As Long
Dim hSize As Long
Dim LoopTimes As Long
Dim BytesWritten As Long
Dim TotalBytesWritten As Long
Dim temp As String
Dim i As Integer
temp = ""

  'CopyFileToCEDevice = False
  
  'Open CE File
  fName = StrConv(CEDestinationFile, vbUnicode)
  fout = CeCreateFile(fName, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)
  If fout = -1 Then
    Exit Function
  End If
  'Open Desktop File
  hFile = CreateFile(DesktopSourceFile, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)
  If hFile <> -1 Then
     'Get File Size
     lSize = GetFileSize(hFile, hSize)
     BufferSize = 8192
     sBuffer = Space(BufferSize)
     inBytes = 8192
        
     Do While inBytes = 8192
        If ReadFile(hFile, sBuffer, BufferSize, inBytes, 0) <> 0 Then
            Call CeWriteFile(fout, sBuffer, inBytes, BytesWritten, 0)
           TotalBytesWritten = TotalBytesWritten + BytesWritten
           RaiseEvent Progress(TotalBytesWritten, lSize)
           For i = 1 To 16
           temp = temp & " " & Hex(Asc(Mid(sBuffer, i, 1)))
           Next
           MsgBox temp
        End If
     Loop
     'CopyFileToCEDevice = True
  End If
  
  CeCloseHandle fout
  CloseHandle hFile
End Function



Public Function CopyFileToDesktop(CESource As String, DesktopDestination As String) As Boolean
  Dim hFile As Long
  Dim fout As Integer
  Dim fName As String
  Dim ret As Long
  Dim sBuffer As String
  Dim inBytes As Long
  Dim BufferSize As Integer
  Dim lSize As Long
  Dim hSize As Long
  Dim LoopTimes As Long
  Dim BytesWritten As Long
  Dim TotalBytesWritten As Long
  CopyFileToDesktop = False
  'Open Desktop File
  fout = CreateFile(DesktopDestination, GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)
  'Open CE File
  fName = StrConv(CESource, vbUnicode)
  hFile = CeCreateFile(fName, GENERIC_READ, FILE_SHARE_READ, vbNull, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, vbNull)
  If hFile <> -1 Then
     'Get File Size
     lSize = CeGetFileSize(hFile, hSize)
     BufferSize = 4096
     sBuffer = Space(BufferSize)
     inBytes = 4096
        
     Do While inBytes = 4096
        If CeReadFile(hFile, sBuffer, BufferSize, inBytes, False) <> 0 Then
           Call WriteFile(fout, sBuffer, inBytes, BytesWritten, 0)
           TotalBytesWritten = TotalBytesWritten + BytesWritten
           RaiseEvent Progress(TotalBytesWritten, lSize)
        End If
     Loop
     CopyFileToDesktop = True
  End If
  
  CeCloseHandle hFile
  CloseHandle fout
End Function

Public Function CreateShortcut(ShortcutName As String, Target As String) As Boolean
   CreateShortcut = CeSHCreateShortcut(StrConv(ShortcutName, vbUnicode), StrConv(Target, vbUnicode))
End Function

Public Function FindFirst(filename As String) As Boolean
    Dim findData As LPCE_FIND_DATA
    Dim handle As Long
    FindFirst = False
    filename = StrConv(filename, vbUnicode)
    handle = CeFindFirstFile(filename, findData)
    If handle <> -1 Then
       FindFirst = True
     End If
End Function
Public Sub PrintDirectory(Path As String)
    Dim findData As LPCE_FIND_DATA
    Dim searchPath As String
    Dim handle As Long
    Dim filename As String
    ReDim Files(100)
    Dim i As Integer
    searchPath = Path + "*"
    i = 0
    handle = CeFindFirstFile(searchPath, findData)
    If handle = -1 Then
        'handle = CeGetLastError
    Else
        'Return filename is Unicode
        filename = StrConv(findData.cFileName, vbFromUnicode)
        filename = Left(filename, InStr(filename, Chr(0)) - 1)
        'lblFileCount.Caption = lblFileCount.Caption + 1
        'Refresh
        If (findData.dwFileAttributes And FILE_ATTRIBUTE_DIRECTORY) Then
            'PrintDirectory (Path + fileName + "\")
            filename = Left(filename, InStr(filename, Chr(0)) - 1)
            Files(i).Name = Path + filename
        End If
        'lstFiles.AddItem Path + fileName
         'Files(i).Name = Path + fileName
    End If
    While Not (CeFindNextFile(handle, findData) = 0)
        'Return filename is Unicode
        filename = StrConv(findData.cFileName, vbFromUnicode)
       
        If (findData.dwFileAttributes And FILE_ATTRIBUTE_DIRECTORY) Then
            'PrintDirectory (Path + fileName + "\")
            filename = Left(filename, InStr(filename, Chr(0)) - 1)
            Files(i).Name = Path + filename
            'Debug.Print Path + fileName
        End If
        'lstFiles.AddItem Path + fileName
        'Files(i).Name = Path + fileName
        
        findData.cFileName = Space(225)
    Wend
    
End Sub


Public Function GetRegValue(hKey As enHKEY, sKey As String, sPath As String, sName As String) As String
Dim ret As Long
Dim hRes As Long
Dim hType As Long
Dim sData As String
Dim lResult As Long
  sData = Space(255)
  lResult = 255
  ret = CeRegOpenKeyEx(hKey, StrConv(sPath, vbUnicode), 0, 0&, hRes)
  If ret = 0 Then
     ret = CeRegQueryValueEx(hRes, StrConv(sName, vbUnicode), 0&, ByVal hType, ByVal sData, lResult)
     GetRegValue = StrConv(Left(sData, lResult - 1), vbFromUnicode)
  End If
   
End Function
Public Function UnicodeToAnsi(cFileName() As Byte) As String
    Dim Index As Integer
    Dim filename As String
    filename = ""
    While Not (cFileName(Index) = 0)
        filename = filename + ChrW(cFileName(Index))
        Index = Index + 1
    Wend

    UnicodeToAnsi = filename
End Function

Public Function CreateDirectory(ByVal sDirName As String) As Boolean
Dim ret As Long
Dim curattr As SECURITY_ATTRIBUTES
CreateDirectory = False
   sDirName = StrConv(sDirName, vbUnicode)
   ret = CeCreateDirectory(sDirName, curattr)
   If ret > -1 Then
      CreateDirectory = True
   End If
End Function
Public Function RapiGetError() As Long
    RapiGetError = CeRapiGetError()
End Function
Public Function GetSpecialFolderPath(ByVal nFolder As Long) As String
   Dim s As String
   Dim res As Long
   Dim nBufferLength As Long
   s = Space(255)
   nBufferLength = 255
   If Init Then
      res = CeGetSpecialFolderPath(nFolder, nBufferLength, ByVal s)
      UnInit
      GetSpecialFolderPath = StrConv(Left(s, nBufferLength - 1), vbFromUnicode)
      GetSpecialFolderPath = Left(GetSpecialFolderPath, InStr(GetSpecialFolderPath, Chr(0)) - 1)
   End If
End Function


