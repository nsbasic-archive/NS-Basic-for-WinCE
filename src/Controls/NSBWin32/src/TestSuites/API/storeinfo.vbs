Set api = CreateObject("NSBasic.win32.api")

WScript.Echo "Default store size:" & api.GetStorageStatus(0) / 1024 & "K"
WScript.Echo "Default store free:" & api.GetStorageStatus(1) / 1024 & "K"
WScript.Echo "Default store free to user:" & api.GetStorageStatus(2) / 1024 & "K"

WScript.Echo "C: store size:" & api.GetStorageStatus(0,"C:\") / 1024 & "K"
WScript.Echo "C: free:" & api.GetStorageStatus(1,"C:\") / 1024 & "K"
WScript.Echo "C: free to user:" & api.GetStorageStatus(2,"C:\") / 1024 & "K"

WScript.Echo "Power - on AC:" & api.GetPowerStatus(0)
WScript.Echo "Power - BatteryFlag:" & api.GetPowerStatus(1)
WScript.Echo "Power - BatteryLifePercent:" & api.GetPowerStatus(2)
WScript.Echo "Power - BatteryLifeTime:" & api.GetPowerStatus(3)
WScript.Echo "Power - BatteryFullLifeTime:" & api.GetPowerStatus(4)
