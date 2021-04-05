Attribute VB_Name = "MErrLogger"
Global LogErrors As Boolean

Public Sub LogErr(strLogEntry As String)
Dim chan As Integer
   
   If Not LogErrors Then Exit Sub
   
   On Error Resume Next
   chan = FreeFile
   Open "c:\\Desktop IDE\\errlog.txt" For Append As #chan
   If Len(strLogEntry) > 0 Then
      Print #chan, Now; Tab; strLogEntry
   Else
      Print #chan, "**********" & vbCrLf & "***" & vbCrLf & "**********"
   End If
   Close #chan
End Sub
