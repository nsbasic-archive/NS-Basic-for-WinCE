
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0286 */
/* at Thu Nov 02 15:40:38 2006
 */
/* Compiler settings for E:\NSBCE6\3rd Party Controls\RGridCtrl 2\RGridCtrl.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_RGRIDCTRLLib,0xE66AF347,0x1732,0x4395,0xA6,0x4E,0x5F,0xB8,0xF6,0x65,0x97,0x01);


MIDL_DEFINE_GUID(IID, IID_IGrid,0xC9AA3AAC,0x599F,0x40EB,0xAA,0xDB,0x73,0x34,0x8B,0x63,0x22,0xA2);


MIDL_DEFINE_GUID(IID, DIID__IGridEvents,0xD5BF9E6C,0xD57E,0x4B4D,0x99,0x1D,0x26,0x06,0xC0,0x17,0x07,0xAF);


MIDL_DEFINE_GUID(CLSID, CLSID_Grid,0x058E370E,0x6141,0x4E41,0x8B,0x95,0x84,0x6E,0xE0,0x4B,0xB3,0x03);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/

