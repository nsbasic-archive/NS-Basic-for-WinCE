Set api = CreateObject("NSBasic.win32.api")
WScript.Echo "Finding window"
lw = api.FindWindow("test")
WScript.Echo "Found: " & lw
' api.ForegroundWindow = lw
'api.Focus = lw
' api.SendKeys chr(20) & "ABCDEFGH", False
api.SendKeys "ABCDEFGH", False