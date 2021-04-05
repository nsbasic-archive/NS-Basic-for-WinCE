VERSION 5.00
Object = "{D4D7C4B5-2CC5-11D3-AE29-00608CC1DD62}#2.8#0"; "S309PictureBox.ocx"
Object = "{33A46DD6-1C42-40D3-8730-EE7136491FBB}#1.0#0"; "S309PR~1.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1 
      Height          =   2595
      Left            =   120
      TabIndex        =   1
      Top             =   240
      Width           =   4335
   End
   Begin S309PICTUREBOXLib.S309PictureBox S309PictureBox1 
      Height          =   1215
      Left            =   240
      TabIndex        =   0
      Top             =   1680
      Width           =   1695
      _Version        =   131080
      _ExtentX        =   2990
      _ExtentY        =   2143
      _StockProps     =   11
   End
   Begin S309PROPERTYBAGLib.S309PropertyBag S309PropertyBag1 
      Left            =   3600
      Top             =   2760
      _Version        =   65536
      _ExtentX        =   873
      _ExtentY        =   661
      _StockProps     =   0
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
    Dim Properties As S309Properties
    Dim Property As S309Property
    Dim xcontrol As S309Control
    Dim xcontrols As S309Controls
    Dim lIndex As Long
    Dim var As Variant
    
    Me.S309PropertyBag1.Controls.Add (Me.S309PictureBox1.Object)
    Set xcontrols = Me.S309PropertyBag1.Controls
    Set xcontrol = xcontrols.Item(1)
    Set Properties = xcontrol.Properties
    Properties.Save False, True
    lIndex = Properties.Count
'    MsgBox MsgBox(lIndex)
    For Each Property In Properties
        lIndex = lIndex - 1
        Me.List1.AddItem Property.Name & " = " & CStr(Property.Value)
    Next
End Sub
