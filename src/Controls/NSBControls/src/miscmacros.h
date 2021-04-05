#ifndef _NSCOMCTL_MISCMACROS_H_
#define _NSCOMCTL_MISCMACROS_H_

#define NSINITIALIZE(p) \
    if (p) { \
        INSComCtlInt* __pnscci = NULL; \
        if (!FAILED(p->QueryInterface(IID_INSComCtlInt,(void**)&__pnscci))) { \
            __pnscci->NSInitialize(); \
            __pnscci->Release(); \
        } \
    }

#define NSTERMINATE(p) \
    if (p) { \
        INSComCtlInt* __pnscci = NULL; \
        if (!FAILED(p->QueryInterface(IID_INSComCtlInt,(void**)&__pnscci))) { \
            __pnscci->NSTerminate(); \
            __pnscci->Release(); \
        } \
    }

#define NSLV_GetCheckState(hwndLV, i) \
    ((((UINT)(::SendMessage((hwndLV), LVM_GETITEMSTATE, (WPARAM)i, LVIS_STATEIMAGEMASK))) >> 12) -1)

#define NSLV_SetCheckState(hwndLV, i, fCheck) \
  ListView_SetItemState(hwndLV, i, INDEXTOSTATEIMAGEMASK((fCheck)?2:1), LVIS_STATEIMAGEMASK)
    


#endif // _NSCOMCTL_MISCMACROS_H_