VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7365
   ClientLeft      =   60
   ClientTop       =   375
   ClientWidth     =   9555
   LinkTopic       =   "Form1"
   ScaleHeight     =   7365
   ScaleWidth      =   9555
   StartUpPosition =   3  'Windows Default
   Begin MSComctlLib.ListView ListView1 
      Height          =   2535
      Left            =   240
      TabIndex        =   2
      Top             =   1680
      Width           =   3975
      _ExtentX        =   7011
      _ExtentY        =   4471
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   0
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   615
      Left            =   960
      TabIndex        =   0
      Top             =   240
      Width           =   1335
   End
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   240
      Top             =   240
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      MaskColor       =   12632256
      _Version        =   393216
   End
   Begin VB.Label Label1 
      Caption         =   "Label1"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   960
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    ImageList1.ListImages.Add , "A", LoadPicture("G:\WORKS\WindowsNT\atl\NSBasic\ComCtl\ComCtl\Tests\ListView\iml.bmp")
    ImageList1.ListImages.Add , "B", LoadPicture("G:\WORKS\WindowsNT\atl\NSBasic\ComCtl\ComCtl\Tests\ListView\iml1.bmp")
    Label1.Caption = ImageList1.ListImages.Count
    ListView1.Icons = ImageList1
    ListView1.ListItems.Add , , "Item 1", 0
    ListView1.ListItems.Add , , "Item 2", 1
    ListView1.ListItems.Add , , "Item 3", 2
    ListView1.ListItems.Add , , "Item 4", 1
    
End Sub
