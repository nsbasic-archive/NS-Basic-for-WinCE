Attribute VB_Name = "MTypeInfo"
Option Explicit

Private Declare Function ProgIDFromCLSID Lib "ole32.dll" (pCLSID As GUID, lpszProgID As Long) As Long
Private Declare Function CLSIDFromString Lib "ole32.dll" (ByVal lpszProgID As Long, pCLSID As GUID) As Long
Private Declare Function CLSIDFromProgID Lib "ole32.dll" (ByVal lpszProgID As Long, pCLSID As GUID) As Long
Private Declare Function StringFromCLSID Lib "ole32.dll" (pCLSID As GUID, lpszProgID As Long) As Long
Private Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (pDest As Any, pSrc As Any, ByVal ByteLen As Long)

Private Type GUID
   Data1 As Long
   Data2 As Integer
   Data3 As Integer
   Data4(7) As Byte
End Type

Public Function GetDLLName(sProdID As String) As String
Dim udtCLSID As GUID
Dim lngRet As Long
Dim strCLSID As String * 255
Dim pProgID As Long
'Dim objReg As New CRegSettings
Dim sSection As String
Dim pCLSID As Long

   lngRet = CLSIDFromProgID(StrPtr(sProdID), udtCLSID)
   'Convert CLSID to a string and get the pointer back.
   lngRet = StringFromCLSID(udtCLSID, pCLSID)
   'Get the CLSID string and display it.
   StringFromPointer pCLSID, strCLSID
   sSection = "CLSID\" & Left(strCLSID, 38) & "\InprocServer32"

   GetDLLName = MWinReg.GetRegValue(HKEY_CLASSES_ROOT, sSection, "", "*")
End Function

Private Sub StringFromPointer(pOLESTR As Long, strOut As String)
Dim ByteArray(255) As Byte
Dim intTemp As Integer
Dim intCount As Integer
Dim i As Integer

   intTemp = 1

   'Walk the string and retrieve the first byte of each WORD.
   While intTemp <> 0
      CopyMemory intTemp, ByVal pOLESTR + i, 2
      ByteArray(intCount) = intTemp
      intCount = intCount + 1
      i = i + 2
   Wend

   'Copy the byte array to our string.
   CopyMemory ByVal strOut, ByteArray(0), intCount
End Sub
