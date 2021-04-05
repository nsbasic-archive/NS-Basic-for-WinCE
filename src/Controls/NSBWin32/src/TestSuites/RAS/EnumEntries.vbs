Set ras = CreateObject("NSBasic.win32.RAS")
WScript.Echo("Indexing")
Set e = ras.Entries
For I = 1 To e.Count
    WScript.Echo e.Item(I)
Next

WScript.Echo("Using enum")
For Each I In ras.Entries
    WScript.Echo I.Name
    WScript.Echo "  Name: " & I.Name
    WScript.Echo "  Domain: " & I.Domain
    WScript.Echo "  Callback: " & I.CallbackNumber
    WScript.Echo "  UserName: " & I.UserName
    WScript.Echo "  PhoneNumber (override only): " & I.PhoneNumber
    WScript.Echo "  Has Saved Password: " & I.HasPassword
Next

'Set conn = ras("BAN")
'conn.Connect()
'WScript.Echo conn.IsConnected
'conn.Disconnect()