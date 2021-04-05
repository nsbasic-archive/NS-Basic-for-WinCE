Attribute VB_Name = "MWinReg"
'%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
'%  VB4 Registry Editor Demo                                            %
'%  MSVC 2.2 Registry Constants and API Prototypes                      %
'%  Written by Roger Wynn                                               %
'%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

'NOTE:
'Additional Registry Constants can be found in 'WINNT.H'.
'Additional Error Constants can be found in and 'WINERROR.H'.
'Additional Structures and Prototypes can be found in 'WIN32API.TXT',
'  but may need to be modified.

'Registry Constants
Public Const HKEY_CLASSES_ROOT = &H80000000
Public Const HKEY_CURRENT_USER = &H80000001
Public Const HKEY_LOCAL_MACHINE = &H80000002
Public Const HKEY_USERS = &H80000003

'Registry Specific Access Rights
Public Const KEY_QUERY_VALUE = &H1
Public Const KEY_SET_VALUE = &H2
Public Const KEY_CREATE_SUB_KEY = &H4
Public Const KEY_ENUMERATE_SUB_KEYS = &H8
Public Const KEY_NOTIFY = &H10
Public Const KEY_CREATE_LINK = &H20
Public Const KEY_ALL_ACCESS = &H3F

'Open/Create Options
Public Const REG_OPTION_NON_VOLATILE = 0&
Public Const REG_OPTION_VOLATILE = &H1

'Key creation/open disposition
Public Const REG_CREATED_NEW_KEY = &H1
Public Const REG_OPENED_EXISTING_KEY = &H2

'masks for the predefined standard access types
Public Const STANDARD_RIGHTS_ALL = &H1F0000
Public Const SPECIFIC_RIGHTS_ALL = &HFFFF

'Define severity codes
Public Const ERROR_SUCCESS = 0&
Public Const ERROR_ACCESS_DENIED = 5
Public Const ERROR_NO_MORE_ITEMS = 259
Public Const ERROR_MORE_DATA = 234

'Predefined Value Types
Public Const REG_NONE = (0)                         'No value type
Public Const REG_SZ = (1)                           'Unicode nul terminated string
Public Const REG_EXPAND_SZ = (2)                    'Unicode nul terminated string w/enviornment var
Public Const REG_BINARY = (3)                       'Free form binary
Public Const REG_DWORD = (4)                        '32-bit number
Public Const REG_DWORD_LITTLE_ENDIAN = (4)          '32-bit number (same as REG_DWORD)
Public Const REG_DWORD_BIG_ENDIAN = (5)             '32-bit number
Public Const REG_LINK = (6)                         'Symbolic Link (unicode)
Public Const REG_MULTI_SZ = (7)                     'Multiple Unicode strings
Public Const REG_RESOURCE_LIST = (8)                'Resource list in the resource map
Public Const REG_FULL_RESOURCE_DESCRIPTOR = (9)     'Resource list in the hardware description
Public Const REG_RESOURCE_REQUIREMENTS_LIST = (10)


'Structures Needed For Registry Prototypes
Type SECURITY_ATTRIBUTES
  nLength As Long
  lpSecurityDescriptor As Long
  bInheritHandle As Boolean
End Type

Type FILETIME
  dwLowDateTime As Long
  dwHighDateTime As Long
End Type


'Registry Function Prototypes
Declare Function RegOpenKeyEx Lib "advapi32" Alias "RegOpenKeyExA" _
  (ByVal hKey As Long, ByVal lpSubKey As String, ByVal ulOptions As Long, _
  ByVal samDesired As Long, phkResult As Long) As Long

Declare Function RegSetValueEx Lib "advapi32" Alias "RegSetValueExA" _
  (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, _
   ByVal dwType As Long, ByVal szData As String, ByVal cbData As Long) As Long

Declare Function RegSetValueExLong Lib "advapi32.dll" Alias "RegSetValueExA" _
   (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, _
   ByVal dwType As Long, lpValue As Long, ByVal cbData As Long) As Long

Declare Function RegCloseKey Lib "advapi32" (ByVal hKey As Long) As Long

Declare Function RegQueryValueEx Lib "advapi32" Alias "RegQueryValueExA" _
  (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, _
   ByRef lpType As Long, ByVal szData As String, ByRef lpcbData As Long) As Long

Declare Function RegCreateKeyEx Lib "advapi32" Alias "RegCreateKeyExA" _
  (ByVal hKey As Long, ByVal lpSubKey As String, ByVal Reserved As Long, _
   ByVal lpClass As String, ByVal dwOptions As Long, ByVal samDesired As Long, _
   lpSecurityAttributes As SECURITY_ATTRIBUTES, phkResult As Long, _
   lpdwDisposition As Long) As Long

Declare Function RegEnumKeyEx Lib "advapi32.dll" Alias "RegEnumKeyExA" _
  (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpName As String, _
   lpcbName As Long, ByVal lpReserved As Long, ByVal lpClass As String, _
   lpcbClass As Long, lpftLastWriteTime As FILETIME) As Long

Declare Function RegEnumValue Lib "advapi32.dll" Alias "RegEnumValueA" _
  (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpValueName As String, _
   lpcbValueName As Long, ByVal lpReserved As Long, lpType As Long, _
   ByVal lpData As String, lpcbData As Long) As Long

Declare Function RegDeleteKey Lib "advapi32.dll" Alias "RegDeleteKeyA" _
  (ByVal hKey As Long, ByVal lpSubKey As String) As Long

Declare Function RegDeleteValue Lib "advapi32.dll" Alias "RegDeleteValueA" _
  (ByVal hKey As Long, ByVal lpValueName As String) As Long



'Global Variables
Public SubKey As String
Public hKey As Long
Public Create As Long
'Operation Flag Values
Public Const NOOPERATION = 0
Public Const DELETEREGVALUE = 1
Public Const DELETEREGKEY = 2
Public Const GETREGVALUEDATA = 3
Public Const SETREGVALUEDATA = 4

Public Enum MWinRegDataType
   mwrdtString = 0
   mwrdtDWord = 1
End Enum

'Operation Flag
Public CurrentOperation As Integer

Function CreateRegKey(NewSubKey As String) As Boolean
Dim phkResult As Long, lResult As Long, SA As SECURITY_ATTRIBUTES

   On Error GoTo ERROR_HANDLER
   'Create key if it does not exist
   CreateRegKey = (RegCreateKeyEx(hKey, SubKey & NewSubKey, 0, "", REG_OPTION_NON_VOLATILE, _
                  KEY_ALL_ACCESS, SA, phkResult, Create) = ERROR_SUCCESS)

   'Close the key
   RegCloseKey phkResult
   Exit Function

ERROR_HANDLER:
   MsgBox "ERROR #" & Str$(err) & " : " & Error & vbCr '"Please exit and try again."
   CreateRegKey = False
End Function

Function RegKeyExists(hKey As Long, lpszSubKey As String) As Boolean
Dim lResult As Long

   RegOpenKeyEx hKey, lpszSubKey, 0, 1, lResult
   RegKeyExists = (lResult <> 0)
   If RegKeyExists Then RegCloseKey lResult
End Function

Function RegValueDelete(hKey As Long, lpszSubKey As String, lpszKey As String)
Dim lResult As Long
   
   RegOpenKeyEx hKey, lpszSubKey, 0, KEY_SET_VALUE, lResult
   RegDeleteValue lResult, lpszKey
   RegCloseKey lResult
End Function

Function GetRegValue(hKey As Long, lpszSubKey As String, szKey As String, szDefault As String) As Variant
Dim phkResult As Long, lResult As Long, szBuffer As String, lBuffSize As Long
Dim p As Integer
Dim dt As Long, dw As Long

   On Error GoTo ERROR_HANDLER

   'Create Buffer
   szBuffer = Space(255)
   lBuffSize = Len(szBuffer)
  
   'Open the key
   RegOpenKeyEx hKey, lpszSubKey, 0, 1, phkResult

   'Query the value
   lResult = RegQueryValueEx(phkResult, szKey, 0, dt, szBuffer, lBuffSize)
   
   If lResult = ERROR_MORE_DATA Then 'more data than buffersize - make it bigger
      szBuffer = Space(lBuffSize)
      lResult = RegQueryValueEx(phkResult, szKey, 0, dt, szBuffer, lBuffSize)
   End If

   'Close the key
   RegCloseKey phkResult

   'Return obtained value
   If lResult = ERROR_SUCCESS Then
      If dt = REG_DWORD Then
         dw = Asc(Mid$(szBuffer, 1, 1)) + &H100& * Asc(Mid$(szBuffer, 2, 1)) + &H10000 * Asc(Mid$(szBuffer, 3, 1)) + &H1000000 * CDbl(Asc(Mid$(szBuffer, 4, 1)))
         GetRegValue = Format$(dw, "")
      Else
          'GetRegValue = LeftB(szBuffer, lBuffSize - 1)     '02/22/01 GH
          p = InStr(1, szBuffer, Chr(0)) - 1   '02/22/01 GH
          If p < 0 Then p = 0   '02/22/01 GH
      '    GetRegValue = Left(szBuffer, p)   '02/22/01 GH
          GetRegValue = Mid(szBuffer, 1, p)  '02/22/01 GH
          'sgBox "Get key " & szKey & " " & lBuffSize & " " & Len(GetRegValue) & " " & szBuffer
      End If
  Else
    GetRegValue = szDefault
  End If
  Exit Function

ERROR_HANDLER:
  'MsgBox gStringTable(3426) & vbCr & "ERROR #" & Str$(Err) & " : " & Error & vbCr '"Please exit and try again."
  MsgBox "ERROR #" & Str$(err) & " : " & Error & vbCr '"Please exit and try again."
  GetRegValue = ""

End Function

Function SetRegValue(hKey As Long, lpszSubKey As String, ByVal sSetValue As String, ByVal sValue As String, Optional dt As Integer = REG_SZ) As Boolean
Dim phkResult As Long, lResult As Long, SA As SECURITY_ATTRIBUTES, dw As Long

   'Note: This function will create the key or value if it doesn't exist.
   On Error GoTo ERROR_HANDLER

   'Open or Create the key
   RegCreateKeyEx hKey, lpszSubKey, 0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, SA, phkResult, Create

   If dt = REG_DWORD Then
      dw = CLng(sValue)
      lResult = RegSetValueExLong(phkResult, sSetValue, 0, REG_DWORD, dw, 4)
   Else
      lResult = RegSetValueEx(phkResult, sSetValue, 0, REG_SZ, sValue, CLng(LenB(sValue) + 1))
   End If

   'Close the key
   RegCloseKey phkResult

   'Return SetRegValue Result
   SetRegValue = (lResult = ERROR_SUCCESS)
   Exit Function

ERROR_HANDLER:
  'MsgBox gStringTable(3426) & vbCr & "ERROR #" & Str$(Err) & " : " & Error & vbCr '"Please exit and try again."
  MsgBox "ERROR #" & Str$(err) & " : " & Error & vbCr '"Please exit and try again."
   SetRegValue = False
End Function



