
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0286 */
/* at Fri Jan 26 06:35:55 2007
 */
/* Compiler settings for E:\NSBCE7\Controls\NSBComDlg\src\Desk.idl:
    Os (OptLev=s), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_INSComDlgFlags,0xBF531F0F,0x5139,0x408A,0xA5,0x6D,0xE6,0x2B,0x03,0xF2,0x30,0xEE);


MIDL_DEFINE_GUID(IID, IID_IComDlgMiniEnum,0x71480CE5,0x596C,0x4045,0x8A,0xED,0x03,0x67,0x52,0xC8,0xCC,0x0A);


MIDL_DEFINE_GUID(IID, IID_INSComDlg,0xE7C7890C,0x6667,0x4EF1,0x8D,0x64,0xCD,0xC0,0x4B,0xDE,0xDE,0x14);


MIDL_DEFINE_GUID(IID, LIBID_NSBComDlgLib,0x6A6D1995,0x8DDD,0x4262,0x8C,0x6A,0x12,0x6F,0x17,0x6C,0x13,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_NSComDlg,0x9DF344D4,0x66FB,0x4660,0xA5,0x69,0xAC,0x85,0x86,0xCF,0xE9,0xFF);


MIDL_DEFINE_GUID(CLSID, CLSID_NSComDlgFlags,0x772336BC,0x25F1,0x4EC5,0xA7,0x9C,0x60,0x59,0x60,0xD2,0x77,0xE6);


MIDL_DEFINE_GUID(CLSID, CLSID_ComDlgMiniEnum,0x5E1D838C,0x8B6B,0x492B,0x9C,0x44,0x07,0x6B,0x13,0x57,0xC9,0x34);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/

