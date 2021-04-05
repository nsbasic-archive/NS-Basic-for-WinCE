Set ras = CreateObject("NSBasic.win32.RAS")
WScript.Echo("Indexing")
Set e = ras.Entries
For I = 1 To e.Count
    WScript.Echo e.Item(I)
Next

WScript.Echo("All entries")
For Each I In ras.Entries
    WScript.Echo I.Name
    WScript.Echo "  Name: " & I.Name
    WScript.Echo "  Domain: " & I.Domain
    WScript.Echo "  Callback: " & I.CallbackNumber
    WScript.Echo "  UserName: " & I.UserName
    WScript.Echo "  PhoneNumber (override only): " & I.PhoneNumber
    WScript.Echo "  Has Saved Password: " & I.HasPassword
    WScript.Echo "  =================="
    WScript.Echo "  Is active: " & I.IsActive
    WScript.Echo "  "
    Set state = I.Status
    WScript.Echo "  State: " & state.State
    WScript.Echo "  Error: " & state.ErrorNumber
    WScript.Echo "  DeviceType: " & state.DeviceType
    WScript.Echo "  DeviceName: " & state.DeviceName
Next

WScript.Echo ""
WScript.Echo ""
WScript.Echo "Connections:"
For Each I In ras.Connections
    WScript.Echo I.Name
    I.Disconnect
Next