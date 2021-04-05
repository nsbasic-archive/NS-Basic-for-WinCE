// Include safeComDlg.h


// Platform adjustments
#ifndef SAFECOMDLG_DLLNAME
    #ifdef _WIN32_WCE
        #define SAFECOMDLG_DLLNAME TEXT("commdlg.dll")
    #else
        #define SAFECOMDLG_DLLNAME TEXT("comdlg32.dll")
    #endif
#endif

#ifdef _WIN32_WCE
    #define SAFECOMDLG_GET_OFN(x) (LPProc_GetOpenFileName)::GetProcAddress(x,L"GetOpenFileNameW");
    #define SAFECOMDLG_GET_SFN(x) (LPProc_GetSaveFileName)::GetProcAddress(x,L"GetSaveFileNameW");
    #define SAFECOMDLG_GET_CC(x)  (LPProc_ChooseColor)::GetProcAddress(x,L"ChooseColorW");
    #define SAFECOMDLG_GET_CF(x)  (LPProc_ChooseFont)::GetProcAddress(x,L"ChooseFontW");

    #define SAFECOMDLG_GET_OFN2(x) (LPProc_GetOpenFileName)::GetProcAddress(x,L"GetOpenFileName");
    #define SAFECOMDLG_GET_SFN2(x) (LPProc_GetSaveFileName)::GetProcAddress(x,L"GetSaveFileName");
    #define SAFECOMDLG_GET_CC2(x)  (LPProc_ChooseColor)::GetProcAddress(x,L"ChooseColor");
    #define SAFECOMDLG_GET_CF2(x)  (LPProc_ChooseFont)::GetProcAddress(x,L"ChooseFont");
#else
    #ifdef UNICODE
        #define SAFECOMDLG_GET_OFN(x) (LPProc_GetOpenFileName)::GetProcAddress(x,"GetOpenFileNameW");
        #define SAFECOMDLG_GET_SFN(x) (LPProc_GetSaveFileName)::GetProcAddress(x,"GetSaveFileNameW");
        #define SAFECOMDLG_GET_CC(x)  (LPProc_ChooseColor)::GetProcAddress(x,"ChooseColorW");
        #define SAFECOMDLG_GET_CF(x)  (LPProc_ChooseFont)::GetProcAddress(x,"ChooseFontW");
    #else
        #define SAFECOMDLG_GET_OFN(x) (LPProc_GetOpenFileName)::GetProcAddress(x,"GetOpenFileNameA");
        #define SAFECOMDLG_GET_SFN(x) (LPProc_GetSaveFileName)::GetProcAddress(x,"GetSaveFileNameA");
        #define SAFECOMDLG_GET_CC(x)  (LPProc_ChooseColor)::GetProcAddress(x,"ChooseColorA");
        #define SAFECOMDLG_GET_CF(x)  (LPProc_ChooseFont)::GetProcAddress(x,"ChooseFontA");
    #endif
    #define SAFECOMDLG_GET_OFN2(x) (LPProc_GetOpenFileName)::GetProcAddress(x,"GetOpenFileName");
    #define SAFECOMDLG_GET_SFN2(x) (LPProc_GetSaveFileName)::GetProcAddress(x,"GetSaveFileName");
    #define SAFECOMDLG_GET_CC2(x)  (LPProc_ChooseColor)::GetProcAddress(x,"ChooseColor");
    #define SAFECOMDLG_GET_CF2(x)  (LPProc_ChooseFont)::GetProcAddress(x,"ChooseFont");
#endif


BOOL GetOpenFileName_SC(LPOPENFILENAME_SC pofn) {
    HINSTANCE   hLib = ::LoadLibrary(SAFECOMDLG_DLLNAME);
    if (!hLib) return FALSE;

    LPProc_GetOpenFileName  pfn = SAFECOMDLG_GET_OFN(hLib);
    if (!pfn) {
        pfn = SAFECOMDLG_GET_OFN2(hLib);
        if (!pfn) return FALSE;
    }

    BOOL b = (*pfn)(pofn);

    ::FreeLibrary(hLib);   

    return b;
}
BOOL GetSaveFileName_SC(LPOPENFILENAME_SC pofn) {
    HINSTANCE   hLib = ::LoadLibrary(SAFECOMDLG_DLLNAME);
    if (!hLib) return FALSE;

    LPProc_GetSaveFileName  pfn = SAFECOMDLG_GET_SFN(hLib);
    if (!pfn) {
        pfn = SAFECOMDLG_GET_SFN2(hLib);
        if (!pfn) return FALSE;
    }

    BOOL b = (*pfn)(pofn);

    ::FreeLibrary(hLib);   

    return b;
}
BOOL ChooseColor_SC(LPCHOOSECOLOR_SC pcc) {
    HINSTANCE   hLib = ::LoadLibrary(SAFECOMDLG_DLLNAME);
    if (!hLib) return FALSE;

    LPProc_ChooseColor pfn = SAFECOMDLG_GET_CC(hLib);
    if (!pfn) {
        pfn = SAFECOMDLG_GET_CC2(hLib);
        if (!pfn) return FALSE;
    }

    BOOL b = (*pfn)(pcc);

    ::FreeLibrary(hLib);   

    return b;
}
BOOL ChooseFont_SC(LPCHOOSEFONT_SC pcf) {
    HINSTANCE   hLib = ::LoadLibrary(SAFECOMDLG_DLLNAME);
    if (!hLib) return FALSE;

    LPProc_ChooseFont  pfn = SAFECOMDLG_GET_CF(hLib);
    if (!pfn) {
        pfn = SAFECOMDLG_GET_CF2(hLib);
        if (!pfn) return FALSE;
    }

    BOOL b = (*pfn)(pcf);

    ::FreeLibrary(hLib);   

    return b;
}
