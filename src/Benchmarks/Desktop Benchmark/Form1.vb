Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim limit, counter
        limit = DateAdd("S", 10, Now)
        counter = 0
        Do Until Now > limit
            counter = counter + 1
        Loop
        MsgBox(counter / 10, 0, "iterations")

    End Sub
End Class
