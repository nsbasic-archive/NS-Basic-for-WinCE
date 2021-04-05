Attribute VB_Name = "MNSBCrypto"
#If NSBasic_CE Then
   Private Declare Function NSBPictureBoxShow Lib "NSBPictB.dll" (ByVal astrFileName As String, ByVal nLen As Long, ByVal nSerialNumber As Long, ByVal lpszText As Long) As Integer
   Private Declare Function NSBPictureBoxHide Lib "NSBPictB.dll" (ByVal lpszText As Long, ByVal nBytes As Long, ByVal astrFileName As String, ByVal nSerialNumber As Long, ByVal nFormat As Integer) As Integer
#End If

Private Const kNSBFileFlagV2 As Double = 4278194653#  '&hFF0011DD
Private Const kNSBFileFlagV3 As Double = 4278199005#  '&hFF0022DD
Private Const kNSBFileFlagV4 As Double = 4278207709#  '&hFF0044DD
#If NSBasic_Desktop Then
   Private Const kDemoSerialNumber As String = "o10-300-00B"
#Else
   Private Const kDemoSerialNumber As String = "L10-603-00B"
#End If
#If ccaAllowRegistration = 1 Then
   Public Const allowRegistration = 1
#Else
   Public Const allowRegistration = 0
#End If
Global gSerialNumber As String

Public Enum nsbFileFormat
   nsbFFTest = -44
   nsbFFSealed = -2
   nsbFFError = -1
   nsbFFUnopened = 0
   nsbFFtext = 1
   nsbFFNormal = 2
   nsbFFEncrypted = 3
   nsbFFExecute = 44
End Enum

'Take a file name, a string to return text in, and serial number
'Return true or false to show success, with successful text stored in pass by reference text
Public Function ReadFile(astrFile As String, ByRef astrText As String, ByVal afSN As Long) As nsbFileFormat
Dim nLen As Long
Dim fFileFlag As Double
Dim sPtr As Long
Dim hFile As Long
Dim FBuf() As Byte
Dim bytesRead As Long


hFile = CreateFile(astrFile, FILE_READ_DATA, FILE_SHARE_READ, ByVal 0&, OPEN_EXISTING, 0, 0)
If hFile <> INVALID_HANDLE_VALUE Then
   'Find file, get file length, open and get file flag
   nLen = FileLen(astrFile)
   ReDim FBuf(nLen) As Byte

#If NSBasic_Desktop Then
   Call ReadFileAPI(hFile, FBuf(0), nLen, bytesRead, ByVal 0&)
   Call CloseHandle(hFile)
   astrText = ByteArrayToString(FBuf)
   ReadFile = nsbFFtext
#End If

#If NSBasic_CE Then
   If LCase(Right(astrFile, 4)) = kProductExtension Then
      Call ReadFileAPI(hFile, FBuf(0), 4, bytesRead, ByVal 0&)
      fFileFlag = Asc(FBuf(0))
      fFileFlag = fFileFlag + Asc(FBuf(1)) * 256#          '&h100
      fFileFlag = fFileFlag + Asc(FBuf(2)) * 65536#        '&h10000
      fFileFlag = fFileFlag + Asc(FBuf(3)) * 16777216#     '&h1000000
   Else
      fFileFlag = 0
   End If
   CloseHandle hFile
   
   Select Case fFileFlag
   Case kNSBFileFlagV2  'Normal NSB file
      astrText = String((nLen - 8) \ 2 + 1, vbNullChar)
   Case kNSBFileFlagV3, kNSBFileFlagV4  'Encrypted file
      astrText = String((nLen - 16) \ 2 + 1, vbNullChar)
   Case Else            'Any other file type
      astrText = String(2 * (nLen + 1), vbNullChar)
   End Select
      
   sPtr = StrPtr(astrText)
   If gSerialNumber = "Unregistered Demo" Then 'set serial number temporarily
      changeSerialNumber kDemoSerialNumber
      ReadFile = NSBPictureBoxShow(astrFile, nLen, afSN, sPtr)
      changeSerialNumber "Unregistered Demo"
   Else
      ReadFile = NSBPictureBoxShow(astrFile, nLen, afSN, sPtr)
   End If

   If fFileFlag = 0 Then
      astrText = Left(astrText, nLen)
   Else
      astrText = Left(astrText, InStr(1, astrText, vbNullChar) - 1)
   End If
#End If

Else
   ReadFile = nsbFFUnopened
End If

End Function
'Take some text, a file name to write it to, and a serial number
'Return nsbFFError or successful file format
Public Function WriteFile(ByVal astrText As String, ByVal astrFile As String, ByVal afSN As Long, Optional ByVal anEncrypt As Integer = 2) As nsbFileFormat
Dim sPtr As Long
Dim chan As Variant
 
#If NSBasic_CE Then
   If UCase(Right(astrFile, 4)) = ".TXT" Then anEncrypt = nsbFFtext

   sPtr = StrPtr(astrText)
   If gSerialNumber = "Unregistered Demo" Then 'set serial number temporarily
      changeSerialNumber kDemoSerialNumber
      WriteFile = NSBPictureBoxHide(sPtr, LenB(astrText), astrFile, afSN, anEncrypt)
      changeSerialNumber "Unregistered Demo"
   Else
      WriteFile = NSBPictureBoxHide(sPtr, LenB(astrText), astrFile, afSN, anEncrypt)
   End If
#End If

#If NSBasic_Desktop Then 'NS Basic/Desktop is not encrypted.
   chan = FreeFile()
   On Error GoTo already_deleted
   Kill astrFile
already_deleted:
   
   On Error GoTo cannot_write
   Open astrFile For Binary As #chan
   Put #chan, , astrText
   Close #chan
   WriteFile = nsbFFtext
   Exit Function
cannot_write:
   WriteFile = nsbFFError
#End If

End Function

Sub changeSerialNumber(serNo As String)
Dim res As Integer
   res = MWinReg.SetRegValue(MWinReg.hKey, MWinReg.SubKey, "SerialNumber", serNo)
End Sub
Private Function ByteArrayToString(bytArray() As Byte) As String
    Dim sAns As String
    Dim iPos As String
    
    sAns = StrConv(bytArray, vbUnicode)
    iPos = InStr(sAns, Chr(0))
    If iPos > 0 Then sAns = Left(sAns, iPos - 1)
    
    ByteArrayToString = sAns
 
 End Function
