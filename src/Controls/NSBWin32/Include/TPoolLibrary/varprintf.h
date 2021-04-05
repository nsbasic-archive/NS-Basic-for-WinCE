#ifndef _TPOOLLIBRARY_VARPRINTF_H_
#define _TPOOLLIBRARY_VARPRINTF_H_

// <tchar.h>
#define _VTEXT(x)	L ## x
#define _VCHAR		WCHAR

struct	VarPrintfSettings {
    VarPrintfSettings(BOOL bDefault = FALSE);
	_VCHAR		chDecimal;	// Decimal point character
	_VCHAR		szDateFormat[64];	// y|Y d m
	_VCHAR		szTimeFormat[64];	// y|Y d m
	_VCHAR		szDateTimeFormat[64];	// y|Y d m
	_VCHAR		szAMSymbol[32];
	_VCHAR		szPMSymbol[32];
	_VCHAR		szNullName[16]; // Name of the null
	_VCHAR		szNaNName[16]; // Name of the NaN
	_VCHAR		szAutoFormat[32];
	_VCHAR		szListSeparator[16];
	_VCHAR		szWeekDaysNames[7][32];
	_VCHAR		szMonths[12][32];
};

// This supplies parameter from a source (it can be anything)
// This proc should be implemented and passed to the processor
typedef HRESULT	(*SUPPLYPARAMPROC)(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal);

typedef BOOL	(*CONSUMESTRINGPROC)(LPVOID pvData,const _VCHAR* pvsz,long lChars);

// Specific implementations

// Suppliers
// SAFEARRAY(VARIANT) Supplier
HRESULT		VarPrintfSupplyFromSafeArray(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal);
struct		_VarPrintfSupplyFromCollectionData {
	DISPCALLER*	pdc;
	long		lBaseIndex;
};
HRESULT		VarPrintfSupplyCollection(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal);

// Consumers
BOOL		VarPrintfConsumeToWSTR(LPVOID pvData,const _VCHAR* pvsz,long lChars);

static	long VarPrintf(
					   CONSUMESTRINGPROC	pfnConsumer,
					   LPVOID				pvCData,
					   const _VCHAR*		vszFormat,
					   // Here we will put some extensions
					   SUPPLYPARAMPROC		pfnSupplier,
					   LPVOID				pvSData,
					   VarPrintfSettings*	pfmtSet);

// Ready to use functions

static  long BSTRPrintf(BSTR bstrFormat,VarPrintfSettings* fmtSet,SAFEARRAY* psa,BSTR* pbstrResult);
static  long BSTRCPrintf(BSTR bstrFormat,VarPrintfSettings* fmtSet,IUnknown* pColl,BSTR* pbstr);

// For usage in C++
HRESULT		VarPrintfSupplyFromVARIANTArray(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal);
// In ATL you need to create an array CSimpleArray<CComVariant> and pass it to the function
// This may be a bit inconvenient but it is safer and more portable than using varying argument list
long BSTRPrintfVARIANTArray(BSTR bstrFormat,VarPrintfSettings* fmtSet,VARIANT* pvars,long lCount,BSTR* pbstr);



#endif // _TPOOLLIBRARY_VARPRINTF_H_