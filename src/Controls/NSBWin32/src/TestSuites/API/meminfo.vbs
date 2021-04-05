Set api = CreateObject("NSBasic.win32.api")

WScript.Echo "Total phys:" & (api.GetMemoryStatus(0)) / 1024 & "K"
WScript.Echo "Avail phys:" & api.GetMemoryStatus(1) / 1024 & "K"
WScript.Echo "Total Pagefile:" & (api.GetMemoryStatus(2)) / 1024 & "K"
WScript.Echo "Avail Pagefile:" & api.GetMemoryStatus(3) / 1024 & "K"
WScript.Echo "Total Virtual:" & (api.GetMemoryStatus(4)) / 1024 & "K"
WScript.Echo "Avail Virtual:" & api.GetMemoryStatus(5) / 1024 & "K"
WScript.Echo "Sys free mem:" & api.GetMemoryStatus(6) & "%"
