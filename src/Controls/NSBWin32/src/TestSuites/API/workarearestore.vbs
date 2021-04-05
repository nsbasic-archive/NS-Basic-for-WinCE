Set api = CreateObject("NSBasic.win32.api")
Set rc = api.SystemParameters(0)
WScript.Echo "L=" & rc.left & ",T=" & rc.top & ",R=" & rc.right & ",B=" & rc.bottom
WScript.Echo "Restoring default work area"
' According to MSDN this should work but it does not!
' To restore the work area correctly you must remember it before making changes!
api.SystemParameters(0) = 0