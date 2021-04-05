Public Class Form1
    Inherits System.Windows.Forms.Form
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents MainMenu1 As System.Windows.Forms.MainMenu

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        MyBase.Dispose(disposing)
    End Sub

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    Private Sub InitializeComponent()
        Me.MainMenu1 = New System.Windows.Forms.MainMenu
        Me.Button1 = New System.Windows.Forms.Button
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(72, 80)
        Me.Button1.Text = "Start"
        '
        'Form1
        '
        Me.Controls.Add(Me.Button1)
        Me.Menu = Me.MainMenu1
        Me.Text = "Benchmark Dot Net"

    End Sub

#End Region

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
