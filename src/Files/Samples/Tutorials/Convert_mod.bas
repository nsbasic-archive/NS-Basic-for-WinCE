Function Convert(Value, Units)
   Dim ConvtUnits

   ' Units is the number from the combo box that tells us which formula to use
	Select Case Units
   
	Case 0
		' This formula for Celsius to Fahrenheit
		ConvtUnits  = (Value * 1.8) + 32
        
	Case 1
		' This formula for Kelvin to Fahrenheit
		ConvtUnits = (Value * 1.8) - 459.67
        
	Case 2
		' This is formula for Rankine to Fahrenheit
		ConvtUnits = Value - 459.67
           
	End Select

   Convert = ConvtUnits    ' Assign the return value

End Function
