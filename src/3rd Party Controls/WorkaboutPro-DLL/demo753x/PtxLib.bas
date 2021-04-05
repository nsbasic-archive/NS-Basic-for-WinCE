Attribute VB_Name = "PtxLib"
Option Explicit
Dim BacklightObject As Object
Dim SystemObject As Object
Dim PeripheralsObject As Object
Dim ScannerObject As Object
Dim IndicatorsObject As Object
Dim PowerManagement As Object
Dim NDisObj As Object


Public Declare Sub Sleep Lib "Coredll" (ByVal dwMilliseconds As Long)


Public Sub SC_ScannerEvent()
    Dim bc As Variant ' the scancode that we just got
    ScannerTest.Scancode = ScannerObject.barcodedata ' get the property in which barcode is stored
    ScannerTest.symb = ScannerObject.symbology
End Sub







