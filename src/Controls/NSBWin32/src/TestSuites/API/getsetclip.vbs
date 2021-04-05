Set api = CreateObject("NSBasic.win32.api")
WScript.Echo "Clipboard:" & api.ClipText
WScript.Echo "Setting clipboard to (Hello!)"
api.ClipText = "Hello!"