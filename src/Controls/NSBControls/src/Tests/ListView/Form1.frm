VERSION 5.00
Object = "{9152ECB3-952A-4F35-83F5-C35F8D42375D}#1.0#0"; "ComCtl.dll"
Object = "{6A6D1995-8DDD-4262-8C6A-126F176C1362}#1.0#0"; "NSBComDlg.dll"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   11565
   ClientLeft      =   60
   ClientTop       =   375
   ClientWidth     =   13530
   LinkTopic       =   "Form1"
   ScaleHeight     =   11565
   ScaleWidth      =   13530
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command27 
      Caption         =   "Command27"
      Height          =   375
      Left            =   8040
      TabIndex        =   54
      Top             =   7080
      Width           =   1335
   End
   Begin VB.CommandButton Command26 
      Caption         =   "Command26"
      Height          =   375
      Left            =   8040
      TabIndex        =   53
      Top             =   6600
      Width           =   1335
   End
   Begin COMCTLLibCtl.NSListView NSListView1 
      Height          =   3735
      Left            =   120
      OleObjectBlob   =   "Form1.frx":0000
      TabIndex        =   0
      Top             =   100
      Width           =   8055
   End
   Begin VB.CommandButton Command25 
      Caption         =   "Font"
      Height          =   375
      Left            =   10920
      TabIndex        =   52
      Top             =   5640
      Width           =   1095
   End
   Begin VB.CommandButton Command24 
      Caption         =   "Text Color"
      Height          =   375
      Left            =   12120
      TabIndex        =   51
      Top             =   6600
      Width           =   975
   End
   Begin VB.CommandButton Command23 
      Caption         =   "Text Bk"
      Height          =   375
      Left            =   12120
      TabIndex        =   50
      Top             =   6120
      Width           =   975
   End
   Begin VB.CommandButton Command22 
      Caption         =   "BkColor"
      Height          =   375
      Left            =   12120
      TabIndex        =   49
      Top             =   5640
      Width           =   975
   End
   Begin VB.CheckBox Check1 
      Caption         =   "Prevent changes"
      Height          =   375
      Left            =   9960
      TabIndex        =   48
      Top             =   4560
      Width           =   1935
   End
   Begin VB.CommandButton Command21 
      Caption         =   "Command21"
      Height          =   375
      Left            =   8520
      TabIndex        =   47
      Top             =   4560
      Width           =   1335
   End
   Begin VB.CommandButton Command20 
      Caption         =   "..."
      Height          =   375
      Left            =   4440
      TabIndex        =   46
      Top             =   4080
      Width           =   495
   End
   Begin VB.CommandButton Command19 
      Caption         =   "Top"
      Height          =   375
      Left            =   11280
      TabIndex        =   45
      Top             =   4080
      Width           =   1335
   End
   Begin VB.CommandButton Command18 
      Caption         =   "Left"
      Height          =   375
      Left            =   9960
      TabIndex        =   44
      Top             =   4080
      Width           =   1215
   End
   Begin VB.CommandButton Command17 
      Caption         =   "No arrange"
      Height          =   375
      Left            =   8520
      TabIndex        =   43
      Top             =   4080
      Width           =   1335
   End
   Begin VB.TextBox ItemText 
      Height          =   375
      Left            =   2640
      TabIndex        =   42
      Text            =   "Item 1"
      Top             =   4080
      Width           =   1695
   End
   Begin VB.CommandButton Command16 
      Caption         =   "Del"
      Height          =   375
      Left            =   10680
      TabIndex        =   41
      Top             =   3480
      Width           =   975
   End
   Begin VB.CommandButton Command15 
      Caption         =   "Add"
      Height          =   375
      Left            =   10680
      TabIndex        =   40
      Top             =   3000
      Width           =   975
   End
   Begin VB.TextBox ColName 
      Height          =   375
      Left            =   9600
      TabIndex        =   38
      Text            =   "a"
      Top             =   3360
      Width           =   975
   End
   Begin VB.TextBox ColIndex 
      Height          =   375
      Left            =   8520
      TabIndex        =   36
      Text            =   "0"
      Top             =   3360
      Width           =   975
   End
   Begin VB.CommandButton Command14 
      Caption         =   "Command14"
      Height          =   495
      Left            =   11880
      TabIndex        =   35
      Top             =   8520
      Width           =   1455
   End
   Begin VB.CommandButton Command13 
      Caption         =   "Dump selected"
      Height          =   495
      Left            =   10320
      TabIndex        =   34
      Top             =   8520
      Width           =   1455
   End
   Begin VB.TextBox Dumper 
      Height          =   2295
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   33
      Top             =   9120
      Width           =   13215
   End
   Begin VB.CommandButton Command12 
      Caption         =   "Delete"
      Height          =   495
      Left            =   5400
      TabIndex        =   32
      Top             =   6960
      Width           =   1215
   End
   Begin VB.CommandButton Command11 
      Caption         =   "SubItem Index"
      Height          =   495
      Left            =   11520
      TabIndex        =   31
      Top             =   2160
      Width           =   1815
   End
   Begin VB.CommandButton Command10 
      Caption         =   "Get"
      Height          =   495
      Left            =   4440
      TabIndex        =   30
      Top             =   6960
      Width           =   855
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   2520
      TabIndex        =   29
      Text            =   "Text4"
      Top             =   6960
      Width           =   735
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   840
      TabIndex        =   26
      Text            =   "Text3"
      Top             =   6960
      Width           =   615
   End
   Begin VB.CommandButton Command9 
      Caption         =   "Set"
      Height          =   495
      Left            =   3480
      TabIndex        =   25
      Top             =   6960
      Width           =   855
   End
   Begin VB.CommandButton Command8 
      Caption         =   "Add one more"
      Height          =   495
      Left            =   6720
      TabIndex        =   24
      Top             =   4080
      Width           =   1455
   End
   Begin VB.CommandButton Command7 
      Caption         =   "SubItem Name"
      Height          =   495
      Left            =   11520
      TabIndex        =   23
      Top             =   1440
      Width           =   1815
   End
   Begin VB.TextBox SImage 
      Height          =   375
      Left            =   9720
      TabIndex        =   22
      Text            =   "Text3"
      Top             =   2280
      Width           =   1575
   End
   Begin VB.TextBox SText 
      Height          =   375
      Left            =   9720
      TabIndex        =   19
      Text            =   "Text4"
      Top             =   1800
      Width           =   1575
   End
   Begin VB.TextBox SCol 
      Height          =   375
      Left            =   8520
      TabIndex        =   17
      Text            =   "Text3"
      Top             =   1800
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   8400
      TabIndex        =   16
      Text            =   "Text2"
      Top             =   600
      Width           =   2775
   End
   Begin VB.CommandButton Command6 
      Caption         =   "Remove icon"
      Height          =   375
      Left            =   11280
      TabIndex        =   15
      Top             =   600
      Width           =   2055
   End
   Begin VB.CommandButton Command5 
      Caption         =   "Get Image count normal"
      Height          =   375
      Left            =   11280
      TabIndex        =   14
      Top             =   120
      Width           =   2055
   End
   Begin VB.TextBox ImgNum 
      Height          =   375
      Left            =   1920
      TabIndex        =   12
      Text            =   "1"
      Top             =   4080
      Width           =   615
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Indent"
      Height          =   495
      Left            =   6720
      TabIndex        =   10
      Top             =   5160
      Width           =   1455
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Change item text"
      Height          =   375
      Left            =   6720
      TabIndex        =   9
      Top             =   4680
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   3240
      TabIndex        =   8
      Text            =   "Text1"
      Top             =   4680
      Width           =   3375
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Add columns"
      Height          =   495
      Left            =   5160
      TabIndex        =   7
      Top             =   4080
      Width           =   1455
   End
   Begin VB.Frame Frame1 
      Caption         =   "Frame1"
      Height          =   2055
      Left            =   120
      TabIndex        =   2
      Top             =   4680
      Width           =   2895
      Begin VB.OptionButton Option4 
         Caption         =   "Option4"
         Height          =   375
         Left            =   120
         TabIndex        =   6
         Top             =   1440
         Width           =   1815
      End
      Begin VB.OptionButton Option3 
         Caption         =   "Option3"
         Height          =   375
         Left            =   120
         TabIndex        =   5
         Top             =   1080
         Width           =   1575
      End
      Begin VB.OptionButton Option2 
         Caption         =   "Option2"
         Height          =   375
         Left            =   120
         TabIndex        =   4
         Top             =   720
         Width           =   1815
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Option1"
         Height          =   375
         Left            =   120
         TabIndex        =   3
         Top             =   360
         Width           =   1815
      End
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Add Item"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   4080
      Width           =   1695
   End
   Begin DESKLibCtl.NSComDlg CDlg 
      Left            =   12120
      Top             =   5040
      _cx             =   1246057
      _cy             =   1246057
      CancelError     =   0   'False
      FileName        =   ""
      DialogTitle     =   ""
      Filter          =   "All files|*.*"
      DefaultExt      =   ""
      InitDir         =   ""
      Color           =   0
      FontName        =   ""
      FontBold        =   0   'False
      FontItalic      =   0   'False
      FontStrikeThru  =   0   'False
      FontUnderLine   =   0   'False
      Min             =   8
      Max             =   72
      FilterIndex     =   0
      FontSize        =   8
      FileTitle       =   ""
      Charset         =   1
      Action          =   0
   End
   Begin VB.Label Label9 
      Caption         =   "Key,Name"
      Height          =   255
      Left            =   9600
      TabIndex        =   39
      Top             =   3000
      Width           =   975
   End
   Begin VB.Label Label8 
      Caption         =   "Col Index"
      Height          =   255
      Left            =   8520
      TabIndex        =   37
      Top             =   3000
      Width           =   975
   End
   Begin VB.Label Label7 
      Caption         =   "Ind"
      Height          =   375
      Left            =   1680
      TabIndex        =   28
      Top             =   6960
      Width           =   615
   End
   Begin VB.Label Label6 
      Caption         =   "Col"
      Height          =   375
      Left            =   120
      TabIndex        =   27
      Top             =   6960
      Width           =   615
   End
   Begin VB.Label Label5 
      Caption         =   "Image"
      Height          =   255
      Left            =   8520
      TabIndex        =   21
      Top             =   2280
      Width           =   1095
   End
   Begin VB.Label Label4 
      Caption         =   "Text"
      Height          =   255
      Left            =   9720
      TabIndex        =   20
      Top             =   1440
      Width           =   1575
   End
   Begin VB.Label Label3 
      Caption         =   "Column"
      Height          =   255
      Left            =   8520
      TabIndex        =   18
      Top             =   1440
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "Label2"
      Height          =   375
      Left            =   8400
      TabIndex        =   13
      Top             =   120
      Width           =   2775
   End
   Begin VB.Label Label1 
      Caption         =   "Label1"
      Height          =   375
      Left            =   3240
      TabIndex        =   11
      Top             =   5160
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Set l = NSListView1.ListItems
    l.Add , ItemText.Text, ItemText.Text, CLng(ImgNum.Text)
End Sub

Private Sub Command10_Click()
    Text4.Text = NSListView1.ColumnHeaders.Item(Text3.Text).SubItemIndex
End Sub

Private Sub Command11_Click()
    For I = 1 To NSListView1.ListItems.Count
        Set Itm = NSListView1.ListItems.Item(I)
        If Itm.Selected Then
            Itm.SubItems.Item(CLng(SCol.Text)).Text = SText.Text
            Itm.SubItems.Item(CLng(SCol.Text)).Icon = CLng(SImage.Text)
        End If
    Next
End Sub

Private Sub Command12_Click()
    NSListView1.ColumnHeaders.Remove Text3.Text
End Sub

Private Sub Command13_Click()
    Dim s
    Dim I, J
    s = ""
    For I = 1 To NSListView1.ListItems.Count
        Set Itm = NSListView1.ListItems.Item(I)
        If Itm.Selected Then
            s = s & "Item " & I & ":" & vbCrLf
            For J = 1 To Itm.SubItems.DefinedCount
                s = s & vbTab & "SubItem[" & J & "] " & Itm.SubItems.ItemByIndex(J).Index & " " & Itm.SubItems.ItemByIndex(J).Text & vbCrLf
            Next
        End If
    Next
    Dumper.Text = s
End Sub

Private Sub Command14_Click()
    Dumper.Text = ""
End Sub

Private Sub Command15_Click()
    NSListView1.ColumnHeaders.Add CLng(ColIndex.Text), ColName.Text, ColName.Text, 64, , CLng(ColIndex.Text)
End Sub

Private Sub Command16_Click()
    NSListView1.ColumnHeaders.Remove CLng(ColIndex.Text)
End Sub

Private Sub Command17_Click()
    NSListView1.Arrange = lvwNone
End Sub

Private Sub Command18_Click()
    NSListView1.Arrange = lvwAutoLeft
End Sub

Private Sub Command19_Click()
    NSListView1.Arrange = lvwAutoTop
End Sub

Private Sub Command2_Click()
    NSListView1.ColumnHeaders.Add 0, "c1", "c1", 200
    NSListView1.ColumnHeaders.Add 1, "c2", "c2", 100
    NSListView1.ColumnHeaders.Add 2, "c3", "c3", 100
    NSListView1.ColumnHeaders.Add 4, "c5", "c5", 100
    NSListView1.ColumnHeaders.Add 5, "c6", "c6", 100
End Sub

Private Sub Command20_Click()
    Dim I
    For I = 1 To 64
        NSListView1.ListItems.Add , "Item" & I, "Item " & I
    Next
End Sub

Private Sub Command21_Click()
    NSListView1.LabelEdit = True
End Sub

Private Sub Command22_Click()
    CDlg.Reset "Color"
    CDlg.Color = 0
    If CDlg.ShowColor Then
        NSListView1.BackColor = CDlg.Color
    End If
End Sub

Private Sub Command23_Click()
    CDlg.Reset "Color"
    CDlg.Color = 0
    If CDlg.ShowColor Then
        NSListView1.TextBackColor = CDlg.Color
    End If
End Sub

Private Sub Command24_Click()
    CDlg.Reset "Color"
    CDlg.Color = 0
    If CDlg.ShowColor Then
        NSListView1.TextColor = CDlg.Color
    End If
End Sub

Private Sub Command25_Click()
    CDlg.Reset "Font"
    If CDlg.ShowFont Then
        NSListView1.Font.Name = CDlg.FontName
        NSListView1.Font.Bold = CDlg.FontBold
        NSListView1.Font.Charset = CDlg.Charset
        NSListView1.Font.Italic = CDlg.FontItalic
        NSListView1.Font.Size = CDlg.FontSize
        NSListView1.Font.Strikethru = CDlg.FontStrikethru
        NSListView1.Font.Underline = CDlg.FontUnderline
    End If
End Sub

Private Sub Command26_Click()
    NSListView1.Enabled = Not NSListView1.Enabled
End Sub

Private Sub Command27_Click()
    NSListView1.Top = 0
End Sub

Private Sub Command3_Click()
    Dim I, Itm
    For I = 1 To NSListView1.ListItems.Count
        Set Itm = NSListView1.ListItems.Item(I)
        If Itm.Selected Then
            Itm.Text = Text1.Text
        End If
    Next
End Sub

Private Sub Command4_Click()
    For I = 1 To NSListView1.ListItems.Count
        Set Itm = NSListView1.ListItems.Item(I)
        If Itm.Selected Then
            Itm.Indent = Itm.Indent + 1
            Label1.Caption = Itm.Indent
        End If
    Next
End Sub

Private Sub Command5_Click()
    Label2.Caption = NSListView1.Icons.Count
End Sub

Private Sub Command6_Click()
    NSListView1.Icons.Remove Text2.Text
End Sub

Private Sub Command7_Click()
    For I = 1 To NSListView1.ListItems.Count
        Set Itm = NSListView1.ListItems.Item(I)
        If Itm.Selected Then
            Itm.SubItems.Item(SCol.Text).Text = SText.Text
            Itm.SubItems.Item(SCol.Text).Icon = CLng(SImage.Text)
        End If
    Next
End Sub

Private Sub Command8_Click()
    NSListView1.ColumnHeaders.Add 3, "c4", "c4", 100
End Sub

Private Sub Command9_Click()
    NSListView1.ColumnHeaders.Item(Text3.Text).SubItemIndex = CLng(Text4.Text)
End Sub

Private Sub Form_Load()
    NSListView1.Icons.Width = 24
    NSListView1.Icons.Height = 24
    NSListView1.Icons.LoadBitmap "G:\WORKS\WindowsNT\atl\NSBasic\ComCtl\ComCtl\Tests\ListView\iml.bmp"
    NSListView1.Icons.BackColor = &H808080
    NSListView1.SmallIcons.Width = 24
    NSListView1.SmallIcons.Height = 24
    NSListView1.SmallIcons.LoadBitmap "G:\WORKS\WindowsNT\atl\NSBasic\ComCtl\ComCtl\Tests\ListView\iml.bmp"
    NSListView1.ColumnHeaderIcons.Width = 24
    NSListView1.ColumnHeaderIcons.Height = 24
    NSListView1.ColumnHeaderIcons.LoadBitmap "G:\WORKS\WindowsNT\atl\NSBasic\ComCtl\ComCtl\Tests\ListView\iml.bmp"
    NSListView1.SubItemImages = True
    NSListView1.AllowColumnReorder = True
    NSListView1.UpdateIcons
    NSListView1.FullRowSelect = True
    ' NSListView1.Checkboxes = True
End Sub

Private Sub NSListView1_OnBeginLabelEdit(ByVal pEvent As COMCTLLibCtl.INSListViewEvent)
    Dim s
    s = "OnBeginLabelEdit: " & pEvent.Item.Text
    Dumper.Text = Dumper.Text & s & vbCrLf
End Sub

Private Sub NSListView1_OnClick(ByVal pEvent As COMCTLLibCtl.INSListViewEvent)
    Dim s
    s = "OnClick: " & pEvent.Item.Text & "|" & pEvent.Item.Checked
    Dumper.Text = Dumper.Text & s & vbCrLf
End Sub

Private Sub NSListView1_OnColumnClick(ByVal pEvent As COMCTLLibCtl.INSListViewEvent)
    Dim s
    s = "OnColumnClick: " & pEvent.Column.Text
    Dumper.Text = Dumper.Text & s & vbCrLf
    NSListView1.SortKey = pEvent.Column.Index
    If NSListView1.SortOrder = lvwAscending Then
        NSListView1.SortOrder = lvwDescending
    Else
        NSListView1.SortOrder = lvwAscending
    End If
    NSListView1.Sorted = True
End Sub

Private Sub NSListView1_OnEndLabelEdit(ByVal pEvent As COMCTLLibCtl.INSListViewEvent)
    Dim s
    s = "OnEndLabelEdit: " & pEvent.Item.Text & vbCrLf
    s = s & "       " & pEvent.Text
    If Check1.Value Then pEvent.Cancel = True
    Dumper.Text = Dumper.Text & s & vbCrLf
End Sub

Private Sub NSListView1_OnItemActivate(ByVal pEvent As COMCTLLibCtl.INSListViewEvent)
    Dim s
    s = "OnItemActivate: " & pEvent.Item.Text & "|" & pEvent.Item.Checked
    Dumper.Text = Dumper.Text & s & vbCrLf
End Sub

Private Sub NSListView1_OnItemChanged(ByVal pEvent As COMCTLLibCtl.INSListViewEvent)
    Dim s
    s = "OnItemChanged: " & pEvent.Item.Text & "|" & pEvent.Item.Checked
    Dumper.Text = Dumper.Text & s & vbCrLf
End Sub

Private Sub Option1_Click()
    NSListView1.View = lvwIcon
End Sub

Private Sub Option2_Click()
    NSListView1.View = lvwSmallIcon
End Sub

Private Sub Option3_Click()
    NSListView1.View = lvwList
End Sub

Private Sub Option4_Click()
    NSListView1.View = lvwReport
End Sub
