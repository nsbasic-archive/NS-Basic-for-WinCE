Host.WriteLine "Initializing ..."
Set file = Host.CreateObject("NSBasic.win32.ComDlg")
file.Reset "File"
If file.ShowOpen Then
    Host.WriteLine "File: " & file.FileName
Else
    Host.WriteLine "Cancelled"
End If
Host.WriteLine "Completed."