Set api = CreateObject("NSBasic.win32.api")
Set rc = api.SystemParameters(0)
WScript.Echo "L=" & rc.left & ",T=" & rc.top & ",R=" & rc.right & ",B=" & rc.bottom
WScript.Echo "Decreasing the workarea with 30 pts on the left side"
rc.left = rc.left + 30
Set api.SystemParameters(0) = rc