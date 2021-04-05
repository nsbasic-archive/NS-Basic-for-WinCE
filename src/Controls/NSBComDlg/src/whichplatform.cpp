#include "stdafx.h"

int WhichPlatform() {
  #ifdef _WIN32_WCE
      OSVERSIONINFO  osvi;
      TCHAR      szBuf[MAX_PATH];
      osvi.dwOSVersionInfoSize = sizeof(osvi);
      GetVersionEx(&osvi);
      switch (osvi.dwPlatformId) {
        case VER_PLATFORM_WIN32_CE:
          // Get platform string
          if (TRUE == SystemParametersInfo(SPI_GETPLATFORMTYPE, MAX_PATH, szBuf, 0)) {
            if (0 == lstrcmp(szBuf, __TEXT("PocketPC"))) {
              // Pocket PC 2003
              return WPLATFORM_POCKETPC2002;
            } else if (0 == lstrcmp(szBuf, __TEXT("Palm PC2"))) {
                // Pocket PC
                return WPLATFORM_POCKETPC;
            } else {
                 return WPLATFORM_UNSPECIFIED;
            }
          }
        break;
        default:
          return WPLATFORM_UNSPECIFIED; 
          break;
      }
  #endif
  return WPLATFORM_UNSPECIFIED;
}
