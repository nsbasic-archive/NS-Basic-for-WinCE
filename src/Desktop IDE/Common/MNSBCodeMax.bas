Attribute VB_Name = "MNSBCodeMax"
'This module does all the CodeMax stuff
Option Explicit

Global Const kKeywords = "|Abs|AddObject|AllowDebug|Array|Asc|AscB|AscW|Atn|Bye|ByRef|ByVal|Call|Case|" & _
"CBool|CByte|CCur|CDate|CDbl|Chain|Chr|ChrB|ChrW|CInt|Class|CLng|Const|" & _
"Cos|CreateObject|CSng|CStr|CurrentPath|Date|DateAdd|DateDiff|" & _
"DatePart|DateSerial|DateValue|Day|Declare|Default|Dim|DoEvents|Each|Else|ElseIf|Empty|End If|" & _
"Eqv|Erase|Error|Eval|Execute|Exit For|Exit Function|Exit Sub|Exp|Explicit|False|Filter|" & _
"Fix|FormatCurrency|FormatDateTime|FormatNumber|FormatPercent|Function|" & _
"GetCommandLine|GetLocale|GetObject|GetRef|" & _
"Global|Gosub|Goto|Hex|Hour|If|In|InputBox|InStr|InStrRev|Int|" & _
"IsArray|IsDate|IsEmpty|IsNull|IsNumeric|IsObject|Join|KeyPreview|" & _
"LBound|LCase|Left|LeftB|Len|LenB|Let|LoadPicture|Log|Loop|LTrim|Mid|MidB|Minute|" & _
"Mod|Month|MonthName|MsgBox|New|Not|Nothing|Now|NSBVersion|Null|Oct|On|" & _
"Option|Preserve|Print|Private|Property|Public|Randomize|Redim|Rem|" & _
"Replace|RGB|Right|RightB|Rnd|Round|RTrim|Second|Select|Set|SetLocale|" & _
"SetMenu|SetParent|Sgn|ShellExecute|ShowFullScreen|ShowOKButton|Sin|Sleep|Space|SpecialFolder|Split|" & _
"Sqr|Step|Stop|StrComp|String|StrReverse|Sub|SysInfo|Tan|Then|Time|" & _
"TimeSerial|TimeValue|To|True|Trim|TypeName|UBound|UCase|UnEscape|Until|" & _
"UpdateScreen|VarType|WaitCursor|WaveVolume|WeekDay|WeekDayName|Year|" & _
"vbBlack|vbRed|vbGreen|vbYellow|vbBlue|vbMagenta|vbCyan|vbWhite|" & _
"vbCR|vbCrLf|vbFormFeed|vbLf|vbNewLine|vbNullChar|vbNullString|vbTab|vbVerticalTab|" & _
"vbEMPTY|vbNULL|vbINTEGER|vbLONG|vbSINGLE|vbDOUBLE|vbCURRENCY|vbDATE|vbSTRING|vbOBJECT|" & _
"vbERROR|vbBOOLEAN|vbVARIANT|vbDATAOBJECT|vbDECIMAL|vbBYTE|vbARRAY|" & _
"vbBINARYCOMPARE|vbTEXTCOMPARE|vbSUNDAY|vbMONDAY|vbTUESDAY|vbWEDNESDAY|vbTHURSDAY|vbFRIDAY|vbSATURDAY|" & _
"vbFIRSTJAN1|vbFIRSTFOURDAYS|vbFIRSTFULLWEEK|vbUSESYSTEM|vbUSESYSTEMDAYOFWEEK|" & _
"vbGENERALDATE|vbLONGDATE|vbSHORTDATE|vbLONGTIME|vbSHORTTIME|vbOKOnly|vbOKCancel|vbAbortRetryIgnore|vbYesNoCancel|vbYesNo|vbRetryCancel|vbCritical|vbQuestion|vbExclamation|vbInformation|vbDefaultButton1|vbDefaultButton2|vbDefaultButton3|vbDefaultButton4|vbApplicationModal|vbSystemModal|" & _
"vbOK |vbCancel|vbAbort|vbRetry|vbIgnore|vbYes|vbNo|"


Const kOperators = "& ^  -  *  /  \  +  =  <>  <  >  <=  >=  Mod  Is  And  Eqv  Imp  Not  Or  Xor"

Global Const CM_NSB_EDITSELECTALL = 4400
Global Const CM_NSB_EDITFIND = 4401
Global cmGlobals As CodeMax4Ctl.Globals
Global cmLanguage As New CodeMax4Ctl.language

'Let's set CodeMax and Code Window stuffs here... once
Sub MNSBCodeMax_Initialize()
Dim hotKey As CodeMax4Ctl.hotKey
Dim trace As Boolean
   If trace Then MsgBox "CodeMax_Initialize" & 1
   Set hotKey = New CodeMax4Ctl.hotKey
   If Not cmGlobals Is Nothing Then
      MsgBox gStringTable(3425) '"MNSBCodeMax_Initialize recall"
      Exit Sub
   End If
   Set cmGlobals = New CodeMax4Ctl.Globals
   If trace Then MsgBox "CodeMax_Initialize" & 2

   'Unregister some built-in CodeMax shortcuts
   hotKey.Modifiers1 = 2
   'Ctrl+F Find...
   hotKey.VirtKey1 = "F"
   hotKey.Unbind
   'Call CMGlobals.UnregisterHotKey(hotKey)  'CM4 Fixut: hotkeys
   'Ctrl+H Replace...
   hotKey.VirtKey1 = "H"
   hotKey.Unbind
   'Call CMGlobals.UnregisterHotKey(hotKey)  'CM4 Fixut: hotkeys
   'Ctrl+V Paste
   hotKey.VirtKey1 = "V"
   hotKey.Unbind
   'Call CMGlobals.UnregisterHotKey(hotKey)  'CM4 Fixut: hotkeys
   'Ctrl+X Cut
   hotKey.VirtKey1 = "X"
   hotKey.Unbind
   'Call CMGlobals.UnregisterHotKey(hotKey)  'CM4 Fixut: hotkeys
   'Ctrl+Z Undo
   hotKey.VirtKey1 = "Z"
   hotKey.Unbind
   'Call CMGlobals.UnregisterHotKey(hotKey)  'CM4 Fixut: hotkeys

   'Ctrl+A Edit->Select All
   'Call CMGlobals.RegisterCommand(CM_NSB_EDITSELECTALL, "Select All", "Selects all text in the active pane.")  'CM4 Fixut: hotkeys
   hotKey.VirtKey1 = "A"
   'Call CMGlobals.RegisterHotKey(hotKey, CM_NSB_EDITSELECTALL)  'CM4 Fixut: hotkeys

   'Register Find, Find Next, Replace
'   Call CMGlobals.RegisterCommand(cmCmdFind, "NS Basic Find", "Help out NS Basic Find")
'   Call CMGlobals.UnregisterCommand(cmCmdFind)
   If trace Then MsgBox "CodeMax_Initialize" & 3
   CreateLanguage
   If trace Then MsgBox "CodeMax_Initialize" & 4
End Sub

Sub MNSBCodeMax_SavePrefs(scriptObj As CodeMax4Ctl.CodeMax)
Dim key As String
   
   key = "HKCU\Software\NSBasic\" & kProduct & "\Editor"
   cmGlobals.SaveSettingsToRegistry (key)
   scriptObj.SaveSettingsToRegistry (key)
End Sub

Sub MNSBCodeMax_SetScriptPrefs(ByRef scriptObj As CodeMax4Ctl.CodeMax)
Dim key As String
   
   key = "HKCU\Software\NSBasic\" & kProduct & "\Editor"
   cmGlobals.LoadSettingsFromRegistry (key)
   scriptObj.LoadSettingsFromRegistry (key)
End Sub

Sub CreateLanguage()
   '--------------------------------------
   ' create A new language
   'Dim l As New CodeMax4Ctl.Language
#If NSBasic_CE Then
   cmLanguage.Name = "NS Basic/CE"
#End If
#If NSBasic_Desktop Then
   cmLanguage.Name = "NS Basic/Desktop"
#End If
   
   ' Basic allows parameter blocks to start with whitespace
   cmLanguage.WhitespaceAsParamBlock = True
   cmLanguage.WordChars = "[\w]"
   
   '--------------------------------------
   ' create a 'Whitespace' scope tokenset.
   ' this is necessary so we can support
   ' parameter blocks that start with whitespace
   ' instead of '('
   Dim Whitespace As New CodeMax4Ctl.TokenSet
   Whitespace.Name = "Whitespace"
   Whitespace.ID = cmTsIdWhitespace
   ' Whitespace can exist at the global scope
   Call Whitespace.ValidScopes.Add(Nothing)
   ' define the whitespace token
   Call Whitespace.Tokens.Add("\s+", True)
   ' add 'Whitespace' to the language
   Call cmLanguage.TokenSets.Add(Whitespace)
   
   '--------------------------------------
   ' create a 'Scope Keywords' scope tokenset
   Dim ScopeKeywords As New CodeMax4Ctl.TokenSet
   ScopeKeywords.ID = cmTsIdScopeKeywords
   ScopeKeywords.Type = CodeMax4Ctl.cmTokenSetType.cmTsTypeScope
   ScopeKeywords.Name = "Scope Keywords"
   ScopeKeywords.CaseSensitive = False
   ScopeKeywords.NormalizeCase = True
   
   ' Scopes keywords can be nested or exist at the global scope
'   Dim ts As CodeMax4Ctl.ITokenSets
   Call ScopeKeywords.ValidScopes.Add(ScopeKeywords)
   Call ScopeKeywords.ValidScopes.Add(Nothing)
   ScopeKeywords.ForeColor = RGB(0, 0, 255) ' red
   ' scopes can autoindent
   ScopeKeywords.AutoIndent = True
   ScopeKeywords.Tokens.Add ("{"):        ScopeKeywords.Tokens2.Add ("}")
   ScopeKeywords.Tokens.Add ("["):        ScopeKeywords.Tokens2.Add ("]")
   ScopeKeywords.Tokens.Add ("For"):      ScopeKeywords.Tokens2.Add ("Next")
   ScopeKeywords.Tokens.Add ("Do"):       ScopeKeywords.Tokens2.Add ("Loop")
   ScopeKeywords.Tokens.Add ("While"):    ScopeKeywords.Tokens2.Add ("WEnd")
   ScopeKeywords.Tokens.Add ("With"):     ScopeKeywords.Tokens2.Add ("End With")
   ScopeKeywords.Tokens.Add ("Function"): ScopeKeywords.Tokens2.Add ("End Function")
   ScopeKeywords.Tokens.Add ("Class"):    ScopeKeywords.Tokens2.Add ("End Class")
   ScopeKeywords.Tokens.Add ("Sub"):      ScopeKeywords.Tokens2.Add ("End Sub")
   ScopeKeywords.Tokens.Add ("Property"): ScopeKeywords.Tokens2.Add ("End Property")
   ScopeKeywords.Tokens.Add ("Select"):   ScopeKeywords.Tokens2.Add ("End Select")
   
   ' add 'Scope Keywords' to the language
   Call cmLanguage.TokenSets.Add(ScopeKeywords)
   Call Whitespace.ValidScopes.Add(ScopeKeywords)

   '--------------------------------------
   ' create an empty 'Text' tokenset as a catch-all
   ' for text in all scopes
   ' Note: this is added later to the language
   ' definition because it has the lowest precedence.
   ' we create it now so it can be referenced by
   ' other tokensets
   Dim Text As New CodeMax4Ctl.TokenSet
   Text.ID = cmTsIdText
   Text.Name = "Text"
   Call Text.ValidScopes.Add(ScopeKeywords)
   Call Text.ValidScopes.Add(Nothing)

   '--------------------------------------------
   ' create a 'Parameter Block' scope tokenset.
   ' This is necessary for CodeMax to automatically
   ' support Parameter Info tooltips.
   '--------------------------------------------
   Dim ParamBlock As New CodeMax4Ctl.TokenSet
   ParamBlock.Name = "Parameter Block"
   ParamBlock.ID = cmTsIdParameterBlocks
   ParamBlock.Type = cmTsTypeScope
   
   ' Parameter block keywords are valid within 'Scope Keywords',
   ' other parameter blocks, and the global scope
   Call ParamBlock.ValidScopes.Add(ScopeKeywords)
   Call ParamBlock.ValidScopes.Add(ParamBlock)
   Call ParamBlock.ValidScopes.Add(Nothing)
   ParamBlock.Hidden = True    'this tokenset is hidden -- the user should be able to change its properties
   ParamBlock.InheritFrom = Text 'inherit color settings from 'Text'
   Dim t As CodeMax4Ctl.IToken
   
   Set t = ParamBlock.Tokens.Add("(")
   t.Action = cmCmdParameterInfo   'invoke parameter help when starting a parameter block
   Set t = ParamBlock.Tokens2.Add(")")
   t.Action = cmCmdCommitMember   'commit the selected member in a popup when closing a parameter block
   ' add this scope to the language
   Call cmLanguage.TokenSets.Add(ParamBlock)

   '--------------------------------------
   ' create a 'Comments' scope tokenset
   Dim Comments As New CodeMax4Ctl.TokenSet
   Comments.Type = CodeMax4Ctl.cmTokenSetType.cmTsTypeScope
   Comments.ID = cmTsIdLineComments
   Comments.Name = "Comments"
   'Comments.FontStyle = cmFontItalic
   
   ' comments can be nested within scope keywords
   ' or exist at the global scope
   Call Comments.ValidScopes.Add(ScopeKeywords)
   Call Comments.ValidScopes.Add(Nothing)
   Comments.ForeColor = RGB(0, 128, 0) ' green
   Comments.Tokens.Add ("'")
   Comments.Tokens.Add ("Rem")
   ' add 'Comments' to the language
   Call cmLanguage.TokenSets.Add(Comments)

   '----------------------------------------------------------------------
   ' create a 'Escape Sequences' tokenset for embedded quotes in strings
   Dim EscSequence As New CodeMax4Ctl.TokenSet
   EscSequence.Name = "Escape Sequences"
   EscSequence.ID = cmTsIdEscapeSeqs
   EscSequence.ForeColor = RGB(0, 128, 0) ' green
   EscSequence.Tokens.Add (Chr$(34) + Chr$(34))
   ' add 'EscSequence' to the language
   Call cmLanguage.TokenSets.Add(EscSequence)

   '--------------------------------------
   ' create a 'Strings' scope tokenset
   Dim Strings As New CodeMax4Ctl.TokenSet
   Strings.Type = CodeMax4Ctl.cmTokenSetType.cmTsTypeScope
   Strings.ID = cmTsIdStrings
   Strings.Name = "Strings"
   Strings.CaseSensitive = False
   Strings.NormalizeCase = True
   ' Strings can be nested within scope keywords
   ' or exist at the global scope
   Call Strings.ValidScopes.Add(ScopeKeywords)
   Call Strings.ValidScopes.Add(ParamBlock)
   Call Strings.ValidScopes.Add(Nothing)
   'Strings.ForeColor = vbMagenta 'RGB(0, 255, 0) ' green
   Call Strings.Tokens.Add(Chr(34))   ' double quotes (")
   Call Strings.Tokens2.Add(Chr(34))   ' double quotes (")
   ' add 'Strings' to the language
   Call cmLanguage.TokenSets.Add(Strings)

   ' EscSequence can be nested within strings
   Call EscSequence.ValidScopes.Add(Strings)

   '--------------------------------------
   ' create a 'Keywords' list tokenset
   Dim Keywords As New CodeMax4Ctl.TokenSet
   Dim keywordList, i As Integer
   keywordList = Split(kKeywords, "|")
   Keywords.ID = cmTsIdKeywords
   Keywords.Name = "Keywords"
   Keywords.CaseSensitive = False
   Keywords.NormalizeCase = True
   ' keywords are valid within 'Scope Keywords'
   ' and the global scope
   Call Keywords.ValidScopes.Add(ScopeKeywords)
   Call Keywords.ValidScopes.Add(ParamBlock)
   Call Keywords.ValidScopes.Add(Nothing)
   Keywords.ForeColor = RGB(0, 0, 255)    ' blue
   'Keywords.FontStyle = CodeMax4CtcmLanguagecmFontStyle.cmFontBold
   For i = 1 To UBound(keywordList)
     Call Keywords.Tokens.Add(keywordList(i))
   Next
   ' add 'Keywords' to the language
   Call cmLanguage.TokenSets.Add(Keywords)
   
   '--------------------------------------
   ' create an 'Operators' list tokenset
   Dim Operators As New CodeMax4Ctl.TokenSet
   Dim operatorList
   operatorList = Split(kOperators)
   Operators.ID = cmTsIdOperators
   Operators.Name = "Operators"
   Operators.CaseSensitive = False
   Operators.NormalizeCase = True
   ' Operators are valid within 'Scope Keywords', 'parameter blocks' and the global scope
   Call Operators.ValidScopes.Add(ScopeKeywords)
   Call Operators.ValidScopes.Add(ParamBlock)
   Call Operators.ValidScopes.Add(Nothing)
   Dim tok As CodeMax4Ctl.IToken
   Set tok = Operators.Tokens.Add(".")
   tok.Action = cmCmdListMembers 'invoke a memberlist when '.' is typed
   Set tok = Operators.Tokens.Add("=")
   tok.Action = cmCmdCommitMember 'commit the selected member in a popup when finishing a parameter
   For i = 1 To UBound(operatorList)
     If operatorList(i) <> "" Then
        Call Operators.Tokens.Add(operatorList(i))
     End If
   Next
   ' add 'Operators' to the language
   Call cmLanguage.TokenSets.Add(Operators)

   '--------------------------------------------
   ' create a 'Argument Separater' scope tokenset.
   ' This is necessary for CodeMax to support bolding
   ' of the current parameter in a Parameter Info
   ' tooltip.
   '--------------------------------------------
   Dim ArgSep As New CodeMax4Ctl.TokenSet
   ArgSep.Name = "Argument Separators"
   ArgSep.ID = cmTsIdArgSeparators
   ArgSep.CaseSensitive = False
   ArgSep.NormalizeCase = True
   
   ' argument separators are only valid within parameter blocks
   Call ArgSep.ValidScopes.Add(Nothing)
   Call ArgSep.ValidScopes.Add(ParamBlock)
   Call ArgSep.ValidScopes.Add(ScopeKeywords)
   ArgSep.Hidden = True    'this tokenset is hidden -- the user should be able to change its properties
   ArgSep.InheritFrom = Text 'inherit color settings from 'Text'
   Set t = ArgSep.Tokens.Add(",")
   t.Action = cmCmdCommitMember   'commit the selected member in a popup when finishing a parameter
   ' add this scope to the language
   Call cmLanguage.TokenSets.Add(ArgSep)

   ' add the 'text' tokenset as the last tokenset
   ' in the language so it will have the lowest
   ' precedence and therefore not override all
   ' other tokensets
   Call cmLanguage.TokenSets.Add(Text)

   '--------------------------------------
   ' make the language available to the user
   Call cmLanguage.register
        
   '--------------------------------------
   ' create a memberlist for the Err global
   ' variable so we can hand it to CodeMax
   ' at a later time in OnQueryMemberList().
   ' We could create this memberlist on the fly
   ' every time OnQueryMemberList() is called, but
   ' since this memberlist is static and won't change,
   ' we might as well construct it now for the best
   ' performance later.
   Dim ErrMethods As New CodeMax4Ctl.MemberList
   Dim mem As CodeMax4Ctl.IMember
   
   ErrMethods.Name = "Err Methods"
   ErrMethods.language = cmLanguage
   ErrMethods.CaseSensitive = False
    
   Set mem = ErrMethods.Add("Clear", "", cmImgMethod)
      mem.HelpString = "Clear the error information"
   Set mem = ErrMethods.Add("Description", "", cmImgProperty)
      mem.HelpString = "Textual description of the error"
   Set mem = ErrMethods.Add("Source", "", cmImgProperty)
      mem.HelpString = "error source"
   Set mem = ErrMethods.Add("Number", "", cmImgProperty)
      mem.HelpString = "The error code number"
   Set mem = ErrMethods.Add("Raise", "Raise(Number, [Source[, Description[, HelpFile[, HelpDescription]]]])", cmImgMethod)
      mem.HelpString = "force an error"
   Call ErrMethods.register
    
   '--------------------------------------
   ' create a memberlist for global functions.
   Dim GblMethods As New CodeMax4Ctl.MemberList
   Dim s As String
   Dim strKey As String
   Dim p As Integer
   Dim comment As String
   
   GblMethods.language = cmLanguage
   GblMethods.Name = "Global Methods"
   GblMethods.CaseSensitive = False
   For i = 100 To 299
      s = gStringTable(i)
      If Left(s, 13) = "String Table:" Then Exit For
      comment = ""
      p = InStr(s, "'")
      If p Then
         comment = Mid(s, p + 1)
         s = Left(s, p - 2)
      End If
      
      strKey = Split(Split(Split(s, " ")(0), "[")(0), "(")(0)
      Set mem = GblMethods.Add(strKey, s, cmImgMethod)
      mem.HelpString = comment
   Next
   Call GblMethods.register

   '------------------------------------------
   ' create member lists for intrinsic objects
   Dim intrinMems As CodeMax4Ctl.MemberList
   Dim strsIntrinsics() As String, strTrinsic As String
   Dim strsProps() As String, strProp As String
   Dim strsMethods() As String, strMethod As String
   Dim objSic As Object
   Dim j As Integer
   
   strsIntrinsics = Split(kIntrinsics & "Output ", " ")
   For i = 0 To UBound(strsIntrinsics) - 1
      Set objSic = CreateObjectEx(strsIntrinsics(i))
      Set intrinMems = New CodeMax4Ctl.MemberList
      intrinMems.language = cmLanguage
      intrinMems.Name = objSic.CEType
      intrinMems.CaseSensitive = False
      
      'properties
      strsProps = objSic.PropertyList
      ReDim Preserve strsProps(UBound(strsProps) + 1) As String
      strsProps(UBound(strsProps)) = "Timer"
      For j = 0 To UBound(strsProps)
         Set mem = intrinMems.Add(strsProps(j), "", cmImgProperty)
         'mem.helpstring = foo
         Set mem = Nothing
      Next
      
      'methods
      strsMethods = objSic.MethodList
      For j = 0 To UBound(strsMethods)
         Set mem = intrinMems.Add(strsMethods(j), "", cmImgMethod)
         'mem.helpstring = foo
         Set mem = Nothing
      Next
      
      Call intrinMems.register
      Set objSic = Nothing
      Set intrinMems = Nothing
   Next

'   cmLanguage.SaveXmlDefinition "d:\dev\ce\nsbce.xml"

'   Dim SIType As SearchItem
'   Dim SIMember As SearchItem
'   Dim dllName As String
'
'   dllName = "cmax20.ocx"
'   With TypeLibInfoFromFile(dllName)
'      .SearchDefault = 3
'      For Each SIType In .GetTypes
''Debug.Print "---------- ControlID = " & .Name & "." & SIType.Name
'         For Each SIMember In .GetMembers(SIType.SearchData)
''Debug.Print SIMember, SIMember.InvokeKinds, .GetMemberInfo(SIType.SearchData, SIMember.InvokeKinds, SIMember.MemberId).HelpString
'         Next
'      Next
'   End With


'   Dim TypeLibrary As TypeLibInfo
'   Dim memInfo As MemberInfo
'
'   Set TypeLibrary = tli.TypeLibInfoFromFile(dllName)
'   TypeLibrary.SearchDefault = 3
'   For Each SIType In TypeLibrary.GetTypes
'      For Each SIMember In TypeLibrary.GetMembers(SIType.SearchData)
'         Set memInfo = TypeLibrary.GetMemberInfo(SIType.SearchData, SIMember.InvokeKinds, SIMember.MemberId)
'         If SIMember.InvokeKinds = 1 Then
''Debug.Print "h"
'         End If
'      Next
'   Next
End Sub

Function getMemberCollection(dllName As String) As Collection
'return a collection of class collections
Dim TypeLibrary As TypeLibInfo
Dim searchClass As SearchItem
Dim searchMember As SearchItem
Dim memInfo As MemberInfo
Dim member As MemberType
Set TypeLibrary = tli.TypeLibInfoFromFile(dllName)
TypeLibrary.SearchDefault = 3
Set getMemberCollection = New Collection

For Each searchClass In TypeLibrary.GetTypes
   For Each searchMember In TypeLibrary.GetMembers(searchClass.SearchData)
      Set memInfo = TypeLibrary.GetMemberInfo(searchClass.SearchData, searchMember.InvokeKinds, searchMember.MemberId)
      member.Name = searchMember.Name
      member.InvokeKinds = searchMember.InvokeKinds
      member.HelpString = memInfo.HelpString
      'getMemberCollection.Add member
   Next
Next
End Function



