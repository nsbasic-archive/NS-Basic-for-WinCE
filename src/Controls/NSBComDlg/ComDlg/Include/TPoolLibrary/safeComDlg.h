#ifndef _TPOOLLIB_SAFECOMDLG_H_
#define _TPOOLLIB_SAFECOMDLG_H_

/*
    This file contains full (to some extent of course) definitions of the main
    common dialog functions from Win32. They are implemented using GetProcAddress
    in order to achieve LIB independency. All the routines return error if the
    function is not defined on the particular platform.

    All the structure and routine definitions end with _SC suffix in order to avoid
    conflicts with the standard commdlg. As the functions and the structures are not 
    used extensively this requires minimal effort.

    The constant names are the same as in the standard include file.


 */

typedef UINT (APIENTRY *LPOFNHOOKPROC_SC) (HWND, UINT, WPARAM, LPARAM);

// OPENFILENAME

typedef struct tagOFNA_SC {
   DWORD        lStructSize;
   HWND         hwndOwner;
   HINSTANCE    hInstance;
   LPCSTR       lpstrFilter;
   LPSTR        lpstrCustomFilter;
   DWORD        nMaxCustFilter;
   DWORD        nFilterIndex;
   LPSTR        lpstrFile;
   DWORD        nMaxFile;
   LPSTR        lpstrFileTitle;
   DWORD        nMaxFileTitle;
   LPCSTR       lpstrInitialDir;
   LPCSTR       lpstrTitle;
   DWORD        Flags;
   WORD         nFileOffset;
   WORD         nFileExtension;
   LPCSTR       lpstrDefExt;
   LPARAM       lCustData;
   LPOFNHOOKPROC_SC lpfnHook;
   LPCSTR       lpTemplateName;
#ifdef _MAC
   LPEDITMENU   lpEditInfo;
   LPCSTR       lpstrPrompt;
#endif
} OPENFILENAMEA_SC, *LPOPENFILENAMEA_SC;

typedef struct tagOFNW_SC {
   DWORD        lStructSize;
   HWND         hwndOwner;
   HINSTANCE    hInstance;
   LPCWSTR      lpstrFilter;
   LPWSTR       lpstrCustomFilter;
   DWORD        nMaxCustFilter;
   DWORD        nFilterIndex;
   LPWSTR       lpstrFile;
   DWORD        nMaxFile;
   LPWSTR       lpstrFileTitle;
   DWORD        nMaxFileTitle;
   LPCWSTR      lpstrInitialDir;
   LPCWSTR      lpstrTitle;
   DWORD        Flags;
   WORD         nFileOffset;
   WORD         nFileExtension;
   LPCWSTR      lpstrDefExt;
   LPARAM       lCustData;
   LPOFNHOOKPROC_SC lpfnHook;
   LPCWSTR      lpTemplateName;
#ifdef _MAC
   LPEDITMENU   lpEditInfo;
   LPCSTR       lpstrPrompt;
#endif
} OPENFILENAMEW_SC, *LPOPENFILENAMEW_SC;

#ifdef UNICODE
    typedef OPENFILENAMEW_SC OPENFILENAME_SC;
    typedef LPOPENFILENAMEW_SC LPOPENFILENAME_SC;
#else
    typedef OPENFILENAMEA_SC OPENFILENAME_SC;
    typedef LPOPENFILENAMEA_SC LPOPENFILENAME_SC;
#endif // UNICODE


typedef UINT (APIENTRY *LPCCHOOKPROC_SC) (HWND, UINT, WPARAM, LPARAM);

typedef struct tagCHOOSECOLORA_SC {
   DWORD        lStructSize;
   HWND         hwndOwner;
   HWND         hInstance;
   COLORREF     rgbResult;
   COLORREF*    lpCustColors;
   DWORD        Flags;
   LPARAM       lCustData;
   LPCCHOOKPROC_SC lpfnHook;
   LPCSTR       lpTemplateName;
} CHOOSECOLORA_SC, *LPCHOOSECOLORA_SC;

typedef struct tagCHOOSECOLORW_SC {
   DWORD        lStructSize;
   HWND         hwndOwner;
   HWND         hInstance;
   COLORREF     rgbResult;
   COLORREF*    lpCustColors;
   DWORD        Flags;
   LPARAM       lCustData;
   LPCCHOOKPROC_SC lpfnHook;
   LPCWSTR      lpTemplateName;
} CHOOSECOLORW_SC, *LPCHOOSECOLORW_SC;


#ifdef UNICODE
    typedef CHOOSECOLORW_SC CHOOSECOLOR_SC;
    typedef LPCHOOSECOLORW_SC LPCHOOSECOLOR_SC;
#else
    typedef CHOOSECOLORA_SC CHOOSECOLOR_SC;
    typedef LPCHOOSECOLORA_SC LPCHOOSECOLOR_SC;
#endif // UNICODE

typedef UINT (APIENTRY *LPCFHOOKPROC_SC) (HWND, UINT, WPARAM, LPARAM);

typedef struct tagCHOOSEFONTA_SC {
   DWORD           lStructSize;
   HWND            hwndOwner;          // caller's window handle
   HDC             hDC;                // printer DC/IC or NULL
   LPLOGFONTA      lpLogFont;          // ptr. to a LOGFONT struct
   INT             iPointSize;         // 10 * size in points of selected font
   DWORD           Flags;              // enum. type flags
   COLORREF        rgbColors;          // returned text color
   LPARAM          lCustData;          // data passed to hook fn.
   LPCFHOOKPROC_SC    lpfnHook;           // ptr. to hook function
   LPCSTR          lpTemplateName;     // custom template name
   HINSTANCE       hInstance;          // instance handle of.EXE that
                                       //   contains cust. dlg. template
   LPSTR           lpszStyle;          // return the style field here
                                       // must be LF_FACESIZE or bigger
   WORD            nFontType;          // same value reported to the EnumFonts
                                       //   call back with the extra FONTTYPE_
                                       //   bits added
   WORD            ___MISSING_ALIGNMENT__;
   INT             nSizeMin;           // minimum pt size allowed &
   INT             nSizeMax;           // max pt size allowed if
                                       //   CF_LIMITSIZE is used
} CHOOSEFONTA_SC, *LPCHOOSEFONTA_SC;

typedef struct tagCHOOSEFONTW_SC {
   DWORD           lStructSize;
   HWND            hwndOwner;          // caller's window handle
   HDC             hDC;                // printer DC/IC or NULL
   LPLOGFONTW      lpLogFont;          // ptr. to a LOGFONT struct
   INT             iPointSize;         // 10 * size in points of selected font
   DWORD           Flags;              // enum. type flags
   COLORREF        rgbColors;          // returned text color
   LPARAM          lCustData;          // data passed to hook fn.
   LPCFHOOKPROC_SC    lpfnHook;           // ptr. to hook function
   LPCWSTR         lpTemplateName;     // custom template name
   HINSTANCE       hInstance;          // instance handle of.EXE that
                                       //   contains cust. dlg. template
   LPWSTR          lpszStyle;          // return the style field here
                                       // must be LF_FACESIZE or bigger
   WORD            nFontType;          // same value reported to the EnumFonts
                                       //   call back with the extra FONTTYPE_
                                       //   bits added
   WORD            ___MISSING_ALIGNMENT__;
   INT             nSizeMin;           // minimum pt size allowed &
   INT             nSizeMax;           // max pt size allowed if
                                       //   CF_LIMITSIZE is used
} CHOOSEFONTW_SC, *LPCHOOSEFONTW_SC;

#ifdef UNICODE
    typedef CHOOSEFONTW_SC CHOOSEFONT_SC;
    typedef LPCHOOSEFONTW_SC LPCHOOSEFONT_SC;
#else
    typedef CHOOSEFONTA_SC CHOOSEFONT_SC;
    typedef LPCHOOSEFONTA_SC LPCHOOSEFONT_SC;
#endif // UNICODE

// The flags and constants
#ifndef TPOOLLIB_NOCOMDLGFLAGS


#define OFN_READONLY                 0x00000001
#define OFN_OVERWRITEPROMPT          0x00000002
#define OFN_HIDEREADONLY             0x00000004
#define OFN_NOCHANGEDIR              0x00000008
#define OFN_SHOWHELP                 0x00000010
#define OFN_ENABLEHOOK               0x00000020
#define OFN_ENABLETEMPLATE           0x00000040
#define OFN_ENABLETEMPLATEHANDLE     0x00000080
#define OFN_NOVALIDATE               0x00000100
#define OFN_ALLOWMULTISELECT         0x00000200
#define OFN_EXTENSIONDIFFERENT       0x00000400
#define OFN_PATHMUSTEXIST            0x00000800
#define OFN_FILEMUSTEXIST            0x00001000
#define OFN_CREATEPROMPT             0x00002000
#define OFN_SHAREAWARE               0x00004000
#define OFN_NOREADONLYRETURN         0x00008000
#define OFN_NOTESTFILECREATE         0x00010000
#define OFN_NONETWORKBUTTON          0x00020000
#define OFN_NOLONGNAMES              0x00040000     // force no long names for 4.x modules
#if(WINVER >= 0x0400)
#define OFN_EXPLORER                 0x00080000     // new look commdlg
#define OFN_NODEREFERENCELINKS       0x00100000
#define OFN_LONGNAMES                0x00200000     // force long names for 3.x modules
#define OFN_ENABLEINCLUDENOTIFY      0x00400000     // send include message to callback
#define OFN_ENABLESIZING             0x00800000
#endif /* WINVER >= 0x0400 */



#define CC_RGBINIT               0x00000001
#define CC_FULLOPEN              0x00000002
#define CC_PREVENTFULLOPEN       0x00000004
#define CC_SHOWHELP              0x00000008
#define CC_ENABLEHOOK            0x00000010
#define CC_ENABLETEMPLATE        0x00000020
#define CC_ENABLETEMPLATEHANDLE  0x00000040
#if(WINVER >= 0x0400)
#define CC_SOLIDCOLOR            0x00000080
#define CC_ANYCOLOR              0x00000100
#endif /* WINVER >= 0x0400 */

#define CF_SCREENFONTS             0x00000001
#define CF_PRINTERFONTS            0x00000002
#define CF_BOTH                    (CF_SCREENFONTS | CF_PRINTERFONTS)
#define CF_SHOWHELP                0x00000004L
#define CF_ENABLEHOOK              0x00000008L
#define CF_ENABLETEMPLATE          0x00000010L
#define CF_ENABLETEMPLATEHANDLE    0x00000020L
#define CF_INITTOLOGFONTSTRUCT     0x00000040L
#define CF_USESTYLE                0x00000080L
#define CF_EFFECTS                 0x00000100L
#define CF_APPLY                   0x00000200L
#define CF_ANSIONLY                0x00000400L
#if(WINVER >= 0x0400)
#define CF_SCRIPTSONLY             CF_ANSIONLY
#endif /* WINVER >= 0x0400 */
#define CF_NOVECTORFONTS           0x00000800L
#define CF_NOOEMFONTS              CF_NOVECTORFONTS
#define CF_NOSIMULATIONS           0x00001000L
#define CF_LIMITSIZE               0x00002000L
#define CF_FIXEDPITCHONLY          0x00004000L
#define CF_WYSIWYG                 0x00008000L // must also have CF_SCREENFONTS & CF_PRINTERFONTS
#define CF_FORCEFONTEXIST          0x00010000L
#define CF_SCALABLEONLY            0x00020000L
#define CF_TTONLY                  0x00040000L
#define CF_NOFACESEL               0x00080000L
#define CF_NOSTYLESEL              0x00100000L
#define CF_NOSIZESEL               0x00200000L
#if(WINVER >= 0x0400)
#define CF_SELECTSCRIPT            0x00400000L
#define CF_NOSCRIPTSEL             0x00800000L
#define CF_NOVERTFONTS             0x01000000L
#endif /* WINVER >= 0x0400 */

// these are extra nFontType bits that are added to what is returned to the
// EnumFonts callback routine

#define SIMULATED_FONTTYPE    0x8000
#define PRINTER_FONTTYPE      0x4000
#define SCREEN_FONTTYPE       0x2000
#define BOLD_FONTTYPE         0x0100
#define ITALIC_FONTTYPE       0x0200
#define REGULAR_FONTTYPE      0x0400

#endif


typedef BOOL (APIENTRY *LPProc_GetOpenFileNameA)(LPOPENFILENAMEA_SC);
typedef BOOL (APIENTRY *LPProc_GetOpenFileNameW)(LPOPENFILENAMEW_SC);
typedef BOOL (APIENTRY *LPProc_GetSaveFileNameA)(LPOPENFILENAMEA_SC);
typedef BOOL (APIENTRY *LPProc_GetSaveFileNameW)(LPOPENFILENAMEW_SC);

typedef BOOL (APIENTRY *LPProc_ChooseColorA)(LPCHOOSECOLORA_SC);
typedef BOOL (APIENTRY *LPProc_ChooseColorW)(LPCHOOSECOLORW_SC);

typedef BOOL (APIENTRY *LPProc_ChooseFontA)(LPCHOOSEFONTA_SC);
typedef BOOL (APIENTRY *LPProc_ChooseFontW)(LPCHOOSEFONTW_SC);


#ifdef UNICODE
    #define LPProc_GetOpenFileName LPProc_GetOpenFileNameW
    #define LPProc_GetSaveFileName LPProc_GetSaveFileNameW
    #define LPProc_ChooseColor LPProc_ChooseColorW
    #define LPProc_ChooseFont LPProc_ChooseFontW
#else
    #define LPProc_GetOpenFileName LPProc_GetOpenFileNameA
    #define LPProc_GetSaveFileName LPProc_GetSaveFileNameA
    #define LPProc_ChooseColor LPProc_ChooseColorA
    #define LPProc_ChooseFont LPProc_ChooseFontA
#endif


BOOL GetOpenFileName_SC(LPOPENFILENAME_SC pofn);
BOOL GetSaveFileName_SC(LPOPENFILENAME_SC pofn);
BOOL ChooseColor_SC(LPCHOOSECOLOR_SC pcc);
BOOL ChooseFont_SC(LPCHOOSEFONT_SC pcf);



#endif // _TPOOLLIB_SAFECOMDLG_H_