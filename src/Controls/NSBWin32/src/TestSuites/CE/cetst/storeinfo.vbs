Set api = CreateObject("NSBasic.win32.api")

Host.WriteLine "Default store size:" & api.GetStorageStatus(0) / 1024 & "K"
Host.WriteLine "Default store free:" & api.GetStorageStatus(1) / 1024 & "K"
Host.WriteLine "Default store free to user:" & api.GetStorageStatus(2) / 1024 & "K"

Host.WriteLine "C: store size:" & api.GetStorageStatus(0,"C:\") / 1024 & "K"
Host.WriteLine "C: free:" & api.GetStorageStatus(1,"C:\") / 1024 & "K"
Host.WriteLine "C: free to user:" & api.GetStorageStatus(2,"C:\") / 1024 & "K"

Host.WriteLine "Power - on AC:" & api.GetPowerStatus(0)
Host.WriteLine "Power - BatteryFlag:" & api.GetPowerStatus(1)
Host.WriteLine "Power - BatteryLifePercent:" & api.GetPowerStatus(2)
Host.WriteLine "Power - BatteryLifeTime:" & api.GetPowerStatus(3)
Host.WriteLine "Power - BatteryFullLifeTime:" & api.GetPowerStatus(4)
