' Constants
Const   HKEY_CLASSES_ROOT           =   &H0
Const   HKEY_CURRENT_USER           =   &H1
Const   HKEY_LOCAL_MACHINE          =   &H2
Const   HKEY_USERS                  =   &H3
Const   HKEY_PERFORMANCE_DATA       =   &H4
Const   HKEY_CURRENT_CONFIG         =   &H5
Const   HKEY_DYN_DATA               =   &H6


Const   REG_SZ                      = 1
Const   REG_EXPAND_SZ               = 2
Const   REG_BINARY                  = 3
Const   REG_DWORD                   = 4
Const   REG_DWORD_LITTLE_ENDIAN     = 4
Const   REG_DWORD_BIG_ENDIAN        = 5
Const   REG_LINK                    = 6
Const   REG_MULTI_SZ                = 7


WScript.Echo "Creating the object"
Set r = CreateObject("NSBasic.win32.Registry")

WScript.Echo "Enumerate the keys in the HKCU\Software"
r.Key = HKEY_CURRENT_USER
r.Path = "Software"
r.ReturnEmptyForEnumEnd = True
Dim nPath, sPath
nPath = 0
Do
    sPath = r.GetPathName(nPath)
    nPath = nPath + 1
    WScript.Echo "    " & sPath
Loop While sPath <> ""

WScript.Echo "Enumerate the keys in the HKLM"
r.Key = HKEY_LOCAL_MACHINE
r.Path = ""
nPath = 0
Do
    sPath = r.GetPathName(nPath)
    nPath = nPath + 1
    WScript.Echo "    " & sPath
Loop While sPath <> ""
    
WScript.Echo "Dump the keys and values in HKCU\Software\Microsoft\Internet Explorer\Toolbar"
Sub EnumKeys(rootKey,startPath,ident)
    Dim nPath,sPath
    Dim r
    Set r = CreateObject("NSBasic.win32.Registry")
    r.ReturnEmptyForEnumEnd = True
    r.Key = rootKey
    r.Path = startPath
    r.HexWithSpaces = True
    r.UseRawBinary = False
    
    nPath = 0
    Do
        sPath = r.GetValueName(nPath)
        If sPath <> "" Then
            nPath = nPath + 1
            r.Name = sPath
            WScript.Echo ident & "(" & r.ValueType & ")" & sPath & "=" & CStr(r.Value)
        End If
    Loop While sPath <> ""
    
    nPath = 0
    Do
        sPath = r.GetPathName(nPath)
        If sPath <> "" Then
            nPath = nPath + 1
            WScript.Echo ident & "[" & sPath & "]"
            EnumKeys rootKey, startPath & "\" & sPath, ident & "    "
        End If
    Loop While sPath <> ""
End Sub

EnumKeys HKEY_CURRENT_USER, "Software\Microsoft\Internet Explorer\Toolbar", "    "


WScript.Echo "Create a key HKCU\Software\NSBasic Registry test"
r.Key = HKEY_CURRENT_USER
r.Path = "Software\NSBasic Registry test"
r.CreatePath

WScript.Echo "  Set a string value there"
r.Name = "ATextValue"
r.Value = "ATextValue's value"

WScript.Echo "  Set a DWORD value there"
r.Name = "ADWORDValue"
r.Value = 21

WScript.Echo "  Set a BINARY value there"
r.Name = "BinValue1"
r.ValueType = REG_BINARY
r.UseRawBinary = False
r.Value = "0102    A1FE 03 6 C          C3"

WScript.Echo "  Set a Multi-string value there"
r.Name = "MultiSZValue"
r.ValueType = REG_MULTI_SZ

Dim arr(2)
arr(0) = "String 1"
arr(1) = "String 2"
arr(2) = "String 3"
r.Value = arr

WScript.Echo "  Read the Multi-string value back"
Dim a
a = r.Value
If Not IsArray(a) Then
    WScript.Echo "    (not a string)"
    WScript.Echo "    " & CStr(a)
Else
    For I = LBound(a) To UBound(a)
        WScript.Echo "    " & I & "=" & a(I)
    Next
End If


