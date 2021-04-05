#ifndef _NSB_OBJECTS_H
#define _NSB_OBJECTS_H

typedef CMapStringToString CPropertyMap;
//typedef CMap<INT,INT,CString,CString> CPropertyMap;
typedef CMap<INT,INT,BOOL,BOOL> CPropertyMapFlag;

#define NSB_OBJECT_ID   4400


////
//
// Properties
//
////

// Property definition data structure
typedef struct
{
   TCHAR m_strName[32];
   INT   m_nType;
   INT   m_nPropertyID;
} NSBProperty;

// Base property ID and property types
#define NSBP_ID               44000
#define NSBP_TYPE_STRING1     1
#define NSBP_TYPE_STRINGN     2
#define NSBP_TYPE_STRINGLIST  3
#define NSBP_TYPE_BOOL        4
#define NSBP_TYPE_INT         5
#define NSBP_TYPE_DATE        6
#define NSBP_TYPE_TIME        7
#define NSBP_TYPE_COLOR       8
#define NSBP_TYPE_ALIGNMENT   9
#define NSBP_TYPE_STYLE       10
#define NSBP_TYPE_SCROLLBARS  11
#define NSBP_TYPE_FONTNAME    12
#define NSBP_TYPE_FONTSIZE    13
#define NSBP_TYPE_BORDERSTYLE 14

#define NSBP_TYPE_POINTER     64
#define NSBP_TYPE_ARRAY       128


// Caption
#define NSBP_CAPTION             ( NSBP_ID )
#define NSBPROP_CAPTION          { _T( "Caption" ), NSBP_TYPE_STRINGN, NSBP_CAPTION }

// Left
#define NSBP_LEFT                ( NSBP_ID + 1 )
#define NSBPROP_LEFT             { _T( "Left" ), NSBP_TYPE_INT, NSBP_LEFT }

// Top
#define NSBP_TOP                 ( NSBP_ID + 2 )
#define NSBPROP_TOP              { _T( "Top" ), NSBP_TYPE_INT, NSBP_TOP }

// Right
#define NSBP_RIGHT               ( NSBP_ID + 3 )
#define NSBPROP_RIGHT            { _T( "Right" ), NSBP_TYPE_INT, NSBP_RIGHT }

// Bottom
#define NSBP_BOTTOM              ( NSBP_ID + 4 )
#define NSBPROP_BOTTOM           { _T( "Bottom" ), NSBP_TYPE_INT, NSBP_BOTTOM }

// Height
#define NSBP_HEIGHT              ( NSBP_ID + 5 )
#define NSBPROP_HEIGHT           { _T( "Height" ), NSBP_TYPE_INT, NSBP_HEIGHT }

// Width
#define NSBP_WIDTH               ( NSBP_ID + 6 )
#define NSBPROP_WIDTH            { _T( "Width" ), NSBP_TYPE_INT, NSBP_WIDTH }

// BackColor
#define NSBP_BACKCOLOR           ( NSBP_ID + 7 )
#define NSBPROP_BACKCOLOR        { _T( "BackColor" ), NSBP_TYPE_COLOR, NSBP_BACKCOLOR }

// ForeColor
#define NSBP_FORECOLOR           ( NSBP_ID + 8 )
#define NSBPROP_FORECOLOR        { _T( "ForeColor" ), NSBP_TYPE_COLOR, NSBP_FORECOLOR }

// Font Properties
// FontName
#define NSBP_FONTNAME            ( NSBP_ID + 9 )
#define NSBPROP_FONTNAME         { _T( "FontName" ), NSBP_TYPE_FONTNAME, NSBP_FONTNAME }

// FontSize
#define NSBP_FONTSIZE            ( NSBP_ID + 10 )
#define NSBPROP_FONTSIZE         { _T( "FontSize" ), NSBP_TYPE_FONTSIZE, NSBP_FONTSIZE }

// FontBold
#define NSBP_FONTBOLD            ( NSBP_ID + 11 )
#define NSBPROP_FONTBOLD         { _T( "FontBold" ), NSBP_TYPE_BOOL, NSBP_FONTBOLD }

// FontItalic
#define NSBP_FONTITALIC          ( NSBP_ID + 12 )
#define NSBPROP_FONTITALIC       { _T( "FontItalic" ), NSBP_TYPE_BOOL, NSBP_FONTITALIC }

// FontUnderline
#define NSBP_FONTUNDERLINE       ( NSBP_ID + 13 )
#define NSBPROP_FONTUNDERLINE    { _T( "FontUnderline" ), NSBP_TYPE_BOOL, NSBP_FONTUNDERLINE }

// FontStrikeThru
#define NSBP_FONTSTRIKETHRU      ( NSBP_ID + 14 )
#define NSBPROP_FONTSTRIKETHRU   { _T( "FontStrikeThru" ), NSBP_TYPE_BOOL, NSBP_FONTSTRIKETHRU }

// FontWieght
#define NSBP_FONTWEIGHT          ( NSBP_ID + 15 )
#define NSBPROP_FONTWEIGHT       { _T( "FontWeight" ), NSBP_TYPE_BOOL, NSBP_FONTWEIGHT }

// Style
#define NSBP_STYLE               ( NSBP_ID + 16 )
#define NSBPROP_STYLE            { _T( "Style" ), NSBP_TYPE_STYLE, NSBP_STYLE }

// IntegralHeight
#define NSBP_INTEGRALHEIGHT      ( NSBP_ID + 17 )
#define NSBPROP_INTEGRALHEIGHT   { _T( "IntegralHeight" ), NSBP_TYPE_BOOL, NSBP_INTEGRALHEIGHT }

// List
#define NSBP_LIST                ( NSBP_ID + 18 )
#define NSBPROP_LIST             { _T( "List" ), NSBP_TYPE_STRINGLIST, NSBP_LIST }

// ListIndex
#define NSBP_LISTINDEX           ( NSBP_ID + 19 )
#define NSBPROP_LISTINDEX        { _T( "ListIndex" ), NSBP_TYPE_INT, NSBP_LISTINDEX }

// NewIndex
#define NSBP_NEWINDEX            ( NSBP_ID + 20 )
#define NSBPROP_NEWINDEX         { _T( "NewIndex" ), NSBP_TYPE_INT, NSBP_NEWINDEX }

// Sorted
#define NSBP_SORTED              ( NSBP_ID + 21 )
#define NSBPROP_SORTED           { _T( "Sorted" ), NSBP_TYPE_BOOL, NSBP_SORTED }

// ScrollBars
#define NSBP_SCROLLBARS          ( NSBP_ID + 22 )
#define NSBPROP_SCROLLBARS       { _T( "ScrollBars" ), NSBP_TYPE_SCROLLBARS, NSBP_SCROLLBARS }

// Multiline
#define NSBP_MULTILINE           ( NSBP_ID + 23 )
#define NSBPROP_MULTILINE        { _T( "Multiline" ), NSBP_TYPE_BOOL, NSBP_MULTILINE }

// MaxLength
#define NSBP_MAXLENGTH           ( NSBP_ID + 24 )
#define NSBPROP_MAXLENGTH        { _T( "MaxLength" ), NSBP_TYPE_INT, NSBP_MAXLENGTH }

// Alignment
#define NSBP_ALIGNMENT           ( NSBP_ID + 25 )
#define NSBPROP_ALIGNMENT        { _T( "Alignment" ), NSBP_TYPE_ALIGNMENT, NSBP_ALIGNMENT }

// Value
#define NSBP_VALUE               ( NSBP_ID + 26 )
#define NSBPROP_VALUE            { _T( "Value" ), NSBP_TYPE_BOOL, NSBP_VALUE }

// TabStop
#define NSBP_TABSTOP             ( NSBP_ID + 27 )
#define NSBPROP_TABSTOP          { _T( "TabStop" ), NSBP_TYPE_BOOL, NSBP_TABSTOP }

// LongFormat
#define NSBP_LONGFORMAT          ( NSBP_ID + 28 )
#define NSBPROP_LONGFORMAT       { _T( "LongFormat" ), NSBP_TYPE_BOOL, NSBP_LONGFORMAT }

// DateMin
#define NSBP_DATEMIN             ( NSBP_ID + 29 )
#define NSBPROP_DATEMIN          { _T( "Min" ), NSBP_TYPE_DATE, NSBP_DATEMIN }

// DateMax
#define NSBP_DATEMAX             ( NSBP_ID + 30 )
#define NSBPROP_DATEMAX          { _T( "Max" ), NSBP_TYPE_DATE, NSBP_DATEMAX }

// DateValue
#define NSBP_DATEVALUE           ( NSBP_ID + 31 )
#define NSBPROP_DATEVALUE        { _T( "Value" ), NSBP_TYPE_DATE, NSBP_DATEVALUE }

// TimeMin
#define NSBP_TIMEMIN             ( NSBP_ID + 32 )
#define NSBPROP_TIMEMIN          { _T( "Min" ), NSBP_TYPE_TIME, NSBP_TIMEMIN }

// TimeMax
#define NSBP_TIMEMAX             ( NSBP_ID + 33 )
#define NSBPROP_TIMEMAX          { _T( "Max" ), NSBP_TYPE_TIME, NSBP_TIMEMAX }

// TimeValue
#define NSBP_TIMEVALUE           ( NSBP_ID + 34 )
#define NSBPROP_TIMEVALUE        { _T( "Value" ), NSBP_TYPE_TIME, NSBP_TIMEVALUE }

// BorderStyle
#define NSBP_BORDERSTYLE         ( NSBP_ID + 35 )
#define NSBPROP_BORDERSTYLE      { _T( "BorderStyle" ), NSBP_TYPE_BORDERSTYLE, NSBP_BORDERSTYLE }

// Master property table
#define NSB_PROPERTIES     \
{                          \
   NSBPROP_CAPTION,        \
                           \
   NSBPROP_LEFT,           \
   NSBPROP_TOP,            \
   NSBPROP_RIGHT,          \
   NSBPROP_BOTTOM,         \
   NSBPROP_HEIGHT,         \
   NSBPROP_WIDTH,          \
                           \
   NSBPROP_BACKCOLOR,      \
   NSBPROP_FORECOLOR,      \
                           \
   NSBPROP_FONTNAME,       \
   NSBPROP_FONTSIZE,       \
   NSBPROP_FONTBOLD,       \
   NSBPROP_FONTITALIC,     \
   NSBPROP_FONTUNDERLINE,  \
   NSBPROP_FONTSTRIKETHRU, \
   NSBPROP_FONTWEIGHT,     \
                           \
   NSBPROP_STYLE,          \
   NSBPROP_INTEGRALHEIGHT, \
   NSBPROP_LIST,           \
   NSBPROP_LISTINDEX,      \
   NSBPROP_NEWINDEX,       \
   NSBPROP_SORTED,         \
   NSBPROP_SCROLLBARS,     \
                           \
   NSBPROP_MULTILINE,      \
   NSBPROP_MAXLENGTH,      \
                           \
   NSBPROP_ALIGNMENT,      \
   NSBPROP_VALUE,          \
   NSBPROP_TABSTOP,        \
                           \
   NSBPROP_LONGFORMAT,     \
   NSBPROP_DATEMIN,        \
   NSBPROP_DATEMAX,        \
   NSBPROP_DATEVALUE,      \
                           \
   NSBPROP_TIMEMIN,        \
   NSBPROP_TIMEMAX,        \
   NSBPROP_TIMEVALUE,      \
                           \
   NSBPROP_BORDERSTYLE,    \
}
#define NUM_NSBPROPERTIES  36


////
//
// Objects
//
////

#define MAX_TYPE_STRING          32
#define MAX_OBJECT_PROPERTIES    32
#define MAX_PRIORITY_PROPERTIES  4
#define MAX_PROPERTY_STRING      32


// Object definition data structure
typedef struct
{
   TCHAR m_strObjectType[MAX_TYPE_STRING];
   INT   m_nObjectID;
   TCHAR m_strUserType[MAX_TYPE_STRING];
   INT   m_nFlag;
   INT   m_nBaseProperties;
   INT   m_aObjectProperties[MAX_OBJECT_PROPERTIES];
   TCHAR m_aPropertyDefaults[MAX_OBJECT_PROPERTIES][MAX_PROPERTY_STRING];
   INT   m_aPriorityProperties[MAX_PRIORITY_PROPERTIES];
} NSBObject;

// Base object ID and object types
#define NSBOB_ID                    44000
#define NSBOB_TYPE_PROPERTYGROUP    -1
#define NSBOB_TYPE_OUTPUT           1 << 14
#define NSBOB_TYPE_NSB              1 << 15
#define NSBOB_TYPE_COM              1 << 16


// Base Property Groups
#define NSBPG_LOCATION        1
#define NSBPROPG_LOCATION     \
{                                                                                      \
   _T( "Location Properties" ), NSBPG_LOCATION, _T( "" ), NSBOB_TYPE_PROPERTYGROUP, 0, \
   { NSBP_LEFT, NSBP_TOP, NSBP_RIGHT, NSBP_BOTTOM, NSBP_WIDTH, NSBP_HEIGHT, },         \
   { _T( "" ), _T( "" ), _T( "" ), _T( "" ), _T( "" ), _T( "" ), },                    \
}

#define NSBPG_TEXTCAPTION     2
#define NSBPROPG_TEXTCAPTION  \
{                                                                    \
   _T( "Text & Caption Properties" ), NSBPG_TEXTCAPTION, _T( "" ),   \
   NSBOB_TYPE_PROPERTYGROUP, 0,                                      \
   { NSBP_CAPTION, },                                                \
   { _T( "" ), }                                                     \
}

#define NSBPG_COLOR           4
#define NSBPROPG_COLOR        \
{                                                     \
   _T( "Color Properties" ), NSBPG_COLOR, _T( "" ),   \
   NSBOB_TYPE_PROPERTYGROUP, 0,                       \
   { NSBP_BACKCOLOR, NSBP_FORECOLOR, },               \
   { _T( "16777215" ), _T( "0" ), }                   \
}

#define NSBPG_NSB             8
#define NSBPROPG_NSB          \
{                                                                             \
   _T( "NSB Properties" ), NSBPG_NSB, _T( "" ), NSBOB_TYPE_PROPERTYGROUP, 0,  \
   {                                                                          \
      NSBP_TABSTOP,                                                           \
      NSBP_FONTNAME, NSBP_FONTSIZE, NSBP_FONTBOLD, NSBP_FONTITALIC,           \
      NSBP_FONTUNDERLINE, NSBP_FONTSTRIKETHRU,                                \
   },                                                                         \
   {                                                                          \
      _T( "TRUE" ),                                                           \
      _T( "Arial" ), _T( "12" ), _T( "FALSE" ), _T( "FALSE" ),                \
      _T( "FALSE" ), _T( "FALSE" ),                                           \
   },                                                                         \
}

#define NSBPG_NSB_BASE  NSBPG_LOCATION + NSBPG_TEXTCAPTION + NSBPG_COLOR + NSBPG_NSB

// Property Group Table
#define NSB_PROPERTY_GROUPS   \
{                             \
   NSBPROPG_LOCATION,         \
   NSBPROPG_TEXTCAPTION,      \
   NSBPROPG_COLOR,            \
   NSBPROPG_NSB,              \
}
#define NUM_NSBPROPERTYGROUPS 4

// Output Object
#define NSBOB_OUTPUT       ( NSBOB_ID )
#define NSBOBJECT_OUTPUT   \
{                                                                    \
   _T( "Output" ), NSBOB_OUTPUT, _T( "Output" ), NSBOB_TYPE_OUTPUT,  \
   0,                                                                \
   {                                                                 \
      NSBP_BACKCOLOR, NSBP_FORECOLOR,                                \
      NSBP_FONTNAME, NSBP_FONTSIZE, NSBP_FONTBOLD, NSBP_FONTITALIC,  \
      NSBP_FONTUNDERLINE, NSBP_FONTSTRIKETHRU, NSBP_FONTWEIGHT,      \
   },                                                                \
   {                                                                 \
      _T( "12632256" ), _T( "0" ),                                   \
      _T( "Arial" ), _T( "12" ), _T( "FALSE" ), _T( "FALSE" ),       \
      _T( "FALSE" ), _T( "FALSE" ), _T( "400" ),                     \
   },                                                                \
   { NSBP_FONTNAME, },                                               \
}
// Alignment, IntegralHeight, Multiline, Scrollbars, Style, Sorted

// CheckBox
#define NSBOB_CHK_BOX      ( NSBOB_ID + 1 )
#define NSBOBJECT_CHK_BOX  \
{                                                                             \
   _T( "CheckBox" ), NSBOB_CHK_BOX, _T( "CheckBox" ), NSBOB_TYPE_NSB | 211,   \
   NSBPG_NSB_BASE,                                                            \
   { NSBP_ALIGNMENT, NSBP_VALUE, },                                           \
   { _T( "0" ), _T( "FALSE" ), },                                             \
}

// ComboBox
#define NSBOB_COM_BOX      ( NSBOB_ID + 2 )
#define NSBOBJECT_COM_BOX  \
{                                                                                \
   _T( "ComboBox" ), NSBOB_COM_BOX, _T( "ComboBox" ), NSBOB_TYPE_NSB | 211,      \
   NSBPG_NSB_BASE,                                                               \
   { NSBP_INTEGRALHEIGHT, NSBP_SORTED, NSBP_NEWINDEX, NSBP_STYLE, NSBP_LIST, },  \
   { _T( "TRUE" ), _T( "FALSE" ), _T( "-1" ), _T( "0" ), _T( "" ), },            \
   { NSBP_SORTED, },                                                             \
}

// CommandButton
#define NSBOB_COM_BUT      ( NSBOB_ID + 3 )
#define NSBOBJECT_COM_BUT  \
{                                                                                      \
   _T( "CommandButton" ), NSBOB_COM_BUT, _T( "CommandButton" ), NSBOB_TYPE_NSB | 211,  \
   NSBPG_NSB_BASE,                                                                     \
   0,                                                                                  \
   0,                                                                                  \
}

// Date
#define NSBOB_DATE         ( NSBOB_ID + 4 )
#define NSBOBJECT_DATE     \
{                                                                                      \
   _T( "Date" ), NSBOB_DATE, _T( "Date" ), NSBOB_TYPE_NSB,                             \
   NSBPG_NSB_BASE - NSBPG_COLOR,                                                       \
   { NSBP_LONGFORMAT, NSBP_DATEMIN, NSBP_DATEMAX, NSBP_DATEVALUE, NSBP_BORDERSTYLE, }, \
   { _T( "FALSE" ), _T( "-1" ), _T( "-1" ), _T( "-1" ), _T( "0" ), },                  \
}

// Label
#define NSBOB_LABEL        ( NSBOB_ID + 5 )
#define NSBOBJECT_LABEL    \
{                                                                    \
   _T( "Label" ), NSBOB_LABEL, _T( "Label" ), NSBOB_TYPE_NSB | 211,  \
   NSBPG_NSB_BASE,                                                   \
   { NSBP_ALIGNMENT, NSBP_TABSTOP, NSBP_BORDERSTYLE, },              \
   { _T( "0" ), _T( "FALSE" ), _T( "0" ), },                         \
}

// ListBox
#define NSBOB_LIS_BOX      ( NSBOB_ID + 6 )
#define NSBOBJECT_LIS_BOX  \
{                                                                                                        \
   _T( "ListBox" ), NSBOB_LIS_BOX, _T( "ListBox" ), NSBOB_TYPE_NSB | 211,                                \
   NSBPG_LOCATION + NSBPG_COLOR + NSBPG_NSB,                                                             \
   { NSBP_INTEGRALHEIGHT, NSBP_SORTED, NSBP_NEWINDEX, NSBP_SCROLLBARS, NSBP_LIST, NSBP_BORDERSTYLE, },   \
   { _T( "TRUE" ), _T( "FALSE" ), _T( "-1" ), _T( "0" ), _T( "" ), },                                    \
   { NSBP_SORTED, },                                                                                     \
}

// OptionButton
#define NSBOB_OPT_BUT      ( NSBOB_ID + 7 )
#define NSBOBJECT_OPT_BUT  \
{                                                                                   \
   _T( "OptionButton" ), NSBOB_OPT_BUT, _T( "OptionButton" ), NSBOB_TYPE_NSB | 211, \
   NSBPG_NSB_BASE,                                                                  \
   { NSBP_ALIGNMENT, NSBP_VALUE, },                                                 \
   { _T( "0" ), _T( "FALSE" ), },                                                   \
}

// TextBox
#define NSBOB_TEX_BOX      ( NSBOB_ID + 8 )
#define NSBOBJECT_TEX_BOX  \
{                                                                          \
   _T( "TextBox" ), NSBOB_TEX_BOX, _T( "TextBox" ), NSBOB_TYPE_NSB | 211,  \
   NSBPG_NSB_BASE,                                                         \
   { NSBP_MULTILINE, NSBP_MAXLENGTH, NSBP_SCROLLBARS, NSBP_BORDERSTYLE, }, \
   { _T( "FALSE" ), _T( "30000" ), _T( "0" ), _T( "0" ), },                \
   { NSBP_MULTILINE, },                                                    \
}

// Time
#define NSBOB_TIME         ( NSBOB_ID + 9 )
#define NSBOBJECT_TIME     \
{                                                                       \
   _T( "Time" ), NSBOB_TIME, _T( "Time" ), NSBOB_TYPE_NSB,              \
   NSBPG_NSB_BASE - NSBPG_COLOR,                                        \
   { NSBP_TIMEMIN, NSBP_TIMEMAX, NSBP_TIMEVALUE, NSBP_BORDERSTYLE, },   \
   { _T( "-1" ), _T( "-1" ), _T( "-1" ), _T( "0" ), },                  \
}

// ActiveX Control
#define NSBOB_COM_OB       ( NSBOB_ID + 10 )
#define NSBOBJECT_COM_OB   \
{                                                           \
   _T( "" ), NSBOB_COM_OB, _T( "ActiveX/COM Objects..." ),  \
   NSBOB_TYPE_COM | 211, NSBPG_LOCATION,                    \
}

// Master object table
#define NSB_OBJECTS     \
{                       \
   NSBOBJECT_OUTPUT,    \
   NSBOBJECT_CHK_BOX,   \
   NSBOBJECT_COM_BOX,   \
   NSBOBJECT_COM_BUT,   \
   NSBOBJECT_DATE,      \
   NSBOBJECT_LABEL,     \
   NSBOBJECT_LIS_BOX,   \
   NSBOBJECT_OPT_BUT,   \
   NSBOBJECT_TEX_BOX,   \
   NSBOBJECT_TIME,      \
   NSBOBJECT_COM_OB     \
}
#define NUM_NSBOBJECTS  11


#endif