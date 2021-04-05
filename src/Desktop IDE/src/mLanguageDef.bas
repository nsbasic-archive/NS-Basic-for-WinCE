Attribute VB_Name = "mLanguageDef"
Option Explicit
Const kKeywords = " Abs AddObject And Array Asc Atn Bye ByRef ByVal Call Case " & _
"CBool CByte CCur CDate CDbl Chain Chr CInt Class CLng Const " & _
"Cos CreateObject CSng CStr CurrentPath Date DateAdd DateDiff " & _
"DatePart DateSerial DateValue Day Dim DoEvents Each Else ElseIf " & _
"End If Eqv Erase Error Eval Execute Exit Exp Explicit False Filter " & _
"Fix FormatCurrency FormatDateTime FormatNumber Format Percent Function " & _
"GetCommandLine GetLocale GetObject GetRef " & _
"Global Gosub Goto Hex Hour If In InStr InStrRev Int InputBox " & _
"IsArray IsDate IsEmpty IsNull IsNumeric IsObject Isarray Join " & _
"LoadPicture Lbound Lcase Left LeftB Len LenB Log LTrim RTrim Mid MidB Minute " & _
"Month MonthName MsgBox Mod Not Now NSBVersion Nothing Oct On " & _
"Option Print Private Property Public Randomize Redim Rem " & _
"Replace RGB Right RightB Round Rnd Second Select Set SetLocale " & _
"SetMenu SetParent Step Stop Sgn ShellExecute ShowOKButton Sin Sleep Space Split " & _
"Sqr StrComp String StrReverse Sub Tan Then To True Time " & _
"TimeSerial TimeValue Trim TypeName Ubound Ucase UnEscape Until " & _
"UpdateScreen Vartype WaitCursor WeekDay WeekDayName Year"
Const kOperators = "& ^  -  *  /  \  +  =  <>  <  >  <=  >=  Mod  Is  Like  And  Eqv  Imp  Not  Or  Xor"

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
    Dim ts As CodeMax4Ctl.ITokenSets
    Call ScopeKeywords.ValidScopes.Add(ScopeKeywords)
    Call ScopeKeywords.ValidScopes.Add(Nothing)
    ScopeKeywords.ForeColor = RGB(255, 0, 0) ' red
    ' scopes can autoindent
    ScopeKeywords.AutoIndent = True
    ScopeKeywords.Tokens.Add ("{")
    ScopeKeywords.Tokens2.Add ("}")
    ScopeKeywords.Tokens.Add ("[")
    ScopeKeywords.Tokens2.Add ("]")
    ScopeKeywords.Tokens.Add ("For")
    ScopeKeywords.Tokens2.Add ("Next")
    ScopeKeywords.Tokens.Add ("Do")
    ScopeKeywords.Tokens2.Add ("Loop")
    ScopeKeywords.Tokens.Add ("While")
    ScopeKeywords.Tokens2.Add ("WEnd")
    ScopeKeywords.Tokens.Add ("With")
    ScopeKeywords.Tokens2.Add ("End With")
    ScopeKeywords.Tokens.Add ("Function")
    ScopeKeywords.Tokens2.Add ("End Function")
    ScopeKeywords.Tokens.Add ("Class")
    ScopeKeywords.Tokens2.Add ("End Class")
    ScopeKeywords.Tokens.Add ("Sub")
    ScopeKeywords.Tokens2.Add ("End Sub")
    ScopeKeywords.Tokens.Add ("If")
    ScopeKeywords.Tokens.Add ("Else")
    ScopeKeywords.Tokens.Add ("ElseIf")
    ScopeKeywords.Tokens2.Add ("End If")
    ScopeKeywords.Tokens.Add ("Select Case")
    ScopeKeywords.Tokens.Add ("Case")
    ScopeKeywords.Tokens2.Add ("End Select")
    
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
    keywordList = Split(kKeywords)
    Keywords.ID = cmTsIdKeywords
    Keywords.Name = "Keywords"
    Keywords.CaseSensitive = False
    Keywords.NormalizeCase = True
    ' keywords are valid within 'Scope Keywords'
    ' and the global scope
    Call Keywords.ValidScopes.Add(ScopeKeywords)
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
    Call cmLanguage.Register
        
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
   ErrMethods.Language = cmLanguage
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
   Call ErrMethods.Register
    
   '--------------------------------------
   ' create a memberlist for global functions.
   Dim GblMethods As New CodeMax4Ctl.MemberList
   Dim s As String
   Dim strKey As String
   Dim p As Integer
   Dim comment As String
   
   GblMethods.Language = cmLanguage
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
   Call GblMethods.Register

   '------------------------------------------
   ' create member lists for intrinsic objects
   Dim intrinMems As CodeMax4Ctl.MemberList
   Dim strsIntrinsics() As String, strTrinsic As String
   Dim strsProps() As String, strProp As String
   Dim objSic As Object
   Dim j As Integer
   
   strsIntrinsics = Split(kIntrinsics & "Output ", " ")
   For i = 0 To UBound(strsIntrinsics) - 1
      Set objSic = CreateObjectEx(strsIntrinsics(i))
      strsProps = objSic.PropertyList
      Set intrinMems = New CodeMax4Ctl.MemberList
      intrinMems.Language = cmLanguage
      intrinMems.Name = objSic.CEType
      intrinMems.CaseSensitive = False
      For j = 0 To UBound(strsProps)
         Set mem = intrinMems.Add(strsProps(j), "", cmImgProperty)
         'mem.helpstring = foo
         Set mem = Nothing
      Next
      Call intrinMems.Register
      Set objSic = Nothing
      Set intrinMems = Nothing
   Next


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

