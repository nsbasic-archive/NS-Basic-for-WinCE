// VarPrintf

#include "automationhlp.h"


#define etRADIX       1 /* Integer types.  %d, %x, %o, and so forth */
#define etFLOAT       2 /* Floating point.  %f */
#define etEXP         3 /* Exponentional notation. %e and %E */
#define etGENERIC     4 /* Floating or exponential, depending on exponent. %g */
#define etSIZE        5 /* Return number of characters processed so far. %n */
#define etSTRING      6 /* Strings. %s */
#define etDYNSTRING   7 /* Dynamically allocated strings. %z */
#define etPERCENT     8 /* Percent symbol. %% */
#define etCHARX       9 /* Characters. %c */
#define etERROR      10 /* Used to indicate no such conversion type */
/* The rest are extensions, not normally found in printf() */
#define etCHARLIT    11 /* Literal characters.  %' */
#define etSQLESCAPE  12 /* Strings with '\'' doubled.  %q */
#define etSQLESCAPE2 13 /* Strings with '\'' doubled and enclosed in '',
                          NULL pointers replaced by SQL NULL.  %Q */
#define etTOKEN      14 /* a pointer to a Token structure */
#define etSRCLIST    15 /* a pointer to a SrcList */
#define etDATETIME	 101
#define etDATE		 102
#define etTIME		 103
#define etEXPMAX     104 /* Exponentional notation. %e and %E */

struct _FmtTypeInfo {   
  _VCHAR	fmttype;            /* The format field code letter */
  BYTE		base;             /* The base for radix conversion */
  BYTE		flags;            /* One or more of FLAG_ constants below */
  BYTE		type;             /* Conversion paradigm */
  _VCHAR*	charset;           /* The character set for conversion */
  _VCHAR*	prefix;            /* Prefix on non-zero values in alt format */
};
struct _AutoTypeEligibility {
  VARTYPE	vt;
  _VCHAR*	types;
};

static _AutoTypeEligibility ateinfo[] = {
	{ VT_EMPTY,				_VTEXT("sdiuxXogGeEtTqQ") },
	{ VT_NULL,				_VTEXT("sdiuxXoeEgGtTqQ") },
	{ VT_I2,				_VTEXT("diuxXogGeEcsqQ") },
	{ VT_I4,				_VTEXT("diuxXogGeEcsqQ") },
	{ VT_R4,				_VTEXT("gGeEdiuxXosqQ") },
	{ VT_R8,				_VTEXT("gGeEdiuxXoTtsqQ") },
	{ VT_CY,				_VTEXT("gGeEdiuxXosqQ") },
	{ VT_DATE,				_VTEXT("tTgGeEdiuxXosqQ") },
	{ VT_BSTR,				_VTEXT("sqQgGeEdiuxXoTt") },
	{ VT_ERROR,				_VTEXT("diuxXogGeEsqQ") },
	{ VT_BOOL,				_VTEXT("diuxXogGeEsqQ") },
	{ VT_I1,				_VTEXT("diuxXogGeEcsqQ") },
	{ VT_UI1,				_VTEXT("uxXodigGeEcsqQ") },
	{ VT_UI2,				_VTEXT("uxXodigGeEcsqQ") },
	{ VT_UI4,				_VTEXT("uxXodigGeEcsqQ") },
	{ VT_INT,				_VTEXT("diuxXogGeEcsqQ") },
	{ VT_UINT,				_VTEXT("uxXodigGeEcsqQ") }
};
#define etATEINFO  (sizeof(ateinfo)/sizeof(ateinfo[0]))


#define FLAG_SIGNED  1     /* True if the value to convert is signed */
#define FLAG_INTERN  2     /* True if for internal use only */

static _FmtTypeInfo fmtinfo[] = {
  {  _VTEXT('d'), 10, 1, etRADIX,      _VTEXT("0123456789"),		0    },
  {  _VTEXT('s'),  0, 0, etSTRING,     0,							0    },
  {  _VTEXT('z'),  0, 2, etDYNSTRING,  0,							0    },
  {  _VTEXT('q'),  0, 0, etSQLESCAPE,  0,							0    },
  {  _VTEXT('Q'),  0, 0, etSQLESCAPE2, 0,							0    },
  {  _VTEXT('c'),  0, 0, etCHARX,      0,							0    },
  {  _VTEXT('o'),  8, 0, etRADIX,      _VTEXT("01234567"),			_VTEXT("0")  },
  {  _VTEXT('u'), 10, 0, etRADIX,      _VTEXT("0123456789"),		0    },
  {  _VTEXT('x'), 16, 0, etRADIX,      _VTEXT("0123456789abcdef"),	_VTEXT("x0") },
  {  _VTEXT('X'), 16, 0, etRADIX,      _VTEXT("0123456789ABCDEF"),	_VTEXT("X0") },
  {  _VTEXT('f'),  0, 1, etFLOAT,      0,							0    },
  {  _VTEXT('e'),  0, 1, etEXP,        _VTEXT("e"),					0    },
  {  _VTEXT('E'),  0, 1, etEXP,        _VTEXT("E"),					0    },
  {  _VTEXT('g'),  0, 1, etGENERIC,    _VTEXT("e"),					0    },
  {  _VTEXT('G'),  0, 1, etGENERIC,    _VTEXT("E"),					0    },
  {  _VTEXT('i'), 10, 1, etRADIX,      _VTEXT("0123456789"),		0    },
  {  _VTEXT('%'),  0, 0, etPERCENT,    0,							0    },
  {  _VTEXT('p'), 10, 0, etRADIX,      _VTEXT("0123456789"),		0    },
  {  _VTEXT('t'),  0, 0, etTIME,       0,							0    },
  {  _VTEXT('T'),  0, 0, etDATETIME,   0,							0    },
  {  _VTEXT('M'),  0, 1, etEXPMAX,     _VTEXT("E"),					0    },
};
#define etNINFO  (sizeof(fmtinfo)/sizeof(fmtinfo[0]))

VarPrintfSettings::VarPrintfSettings(BOOL bDefault /* = FALSE*/) {
    if (bDefault) {
        chDecimal = L'.';
		wcscpy(szDateFormat,L"Y-M-d");
		wcscpy(szTimeFormat,L"H:m:s");
		wcscpy(szDateTimeFormat,L"Y-M-d H:m:s");
		wcscpy(szAMSymbol,L"am");
		wcscpy(szPMSymbol,L"pm");
		wcscpy(szNullName,L"NULL");
		wcscpy(szNaNName,L"NaN");
		wcscpy(szAutoFormat,L"diuxXgGsT");

		wcscpy(szWeekDaysNames[0],L"Sunday");
		wcscpy(szWeekDaysNames[1],L"Monday");
		wcscpy(szWeekDaysNames[2],L"Tuesday");
		wcscpy(szWeekDaysNames[3],L"Wednesday");
		wcscpy(szWeekDaysNames[4],L"Thursday");
		wcscpy(szWeekDaysNames[5],L"Friday");
		wcscpy(szWeekDaysNames[6],L"Saturday");

		wcscpy(szMonths[0],L"January");
		wcscpy(szMonths[1],L"February");
		wcscpy(szMonths[2],L"March");
		wcscpy(szMonths[3],L"April");
		wcscpy(szMonths[4],L"May");
		wcscpy(szMonths[5],L"June");
		wcscpy(szMonths[6],L"July");
		wcscpy(szMonths[7],L"August");
		wcscpy(szMonths[8],L"September");
		wcscpy(szMonths[9],L"October");
		wcscpy(szMonths[10],L"November");
		wcscpy(szMonths[11],L"December");

		wcscpy(szListSeparator,L",");
    }
}

// BOOL	hlpOleDateToSystemType(DATE dtSrc, SYSTEMTIME& tmDest);


#define etBUFSIZE 512
#define etNAMELEN 256

static _VCHAR et_getdigit(long double* val, long* cnt){
	long digit;
	long double d;
	if ( (*cnt)++ >= 16 ) return _VTEXT('0');
	digit = (long)*val;
	d = digit;
	digit += _VTEXT('0');
	*val = (*val - d) * 10.0;
	return (_VCHAR)digit;
}
static long et_number(_VCHAR* buff,long precision,long l) {
	if (precision > 63 || l < 0) return 0;
	_VCHAR	buf[64];
	_VCHAR*	pbuf = NULL;
	pbuf =  &buf[63];
	long	longvalue = l;
	static _VCHAR	cset[] = _VTEXT("0123456789");
	// base = 10
	do {                                           /* Convert to ascii */
		*(--pbuf) = cset[longvalue % 10];
		longvalue = longvalue / 10;
	} while ( longvalue > 0 );
	long length = length = &buf[63] - pbuf;
	long idx;
	for ( idx = precision - length; idx > 0; idx --) {
		*(--pbuf) = _VTEXT('0');                             /* Zero pad */
	}
	length = length = &buf[63] - pbuf;
	if (length > precision) {
		pbuf += length - precision;
	}
	memcpy(buff,pbuf,sizeof(_VCHAR) * precision);
	return precision;
}
// Find left most char from set1 in set2
static _VCHAR et_findsetinset(_VCHAR* set1,_VCHAR* set2) {
	if (!set1 || !set2) return -1;
	long i,j;
	for (i = 0; set2[i] != _VTEXT('\0'); i++) {
		for (j = 0; set1[j] != _VTEXT('\0'); j++) {
			if (set2[i] == set1[j]) {
				return set2[i];
			}
		}
	}
	return _VTEXT('\0');
}
static _VCHAR et_findbesttype(VARTYPE vt,_VCHAR* allowed) {
	long i;
	for ( i = 0; i < etATEINFO; i++ ) {
		if ( vt == ateinfo[i].vt ) {
			return et_findsetinset(allowed,ateinfo[i].types);
		}
	}
	return _VTEXT('\0');
}
static long	et_fmtdatetime(_VCHAR* fmt,VarPrintfSettings* pfmtSet,DATE dt,_VCHAR* buf) {
	long i,j = 0,l;
	SYSTEMTIME	st;
	if (!hlpOleDateToSystemType(dt, st)) return 0;
	for (i = 0; fmt[i] != _VTEXT('\0'); i++) {
		switch (fmt[i]) {
			case _VTEXT('d'):
				j += et_number(&buf[j],2,(long)st.wDay);
			break;
			case _VTEXT('y'):
				j += et_number(&buf[j],2,(long)st.wYear);
			break;
			case _VTEXT('Y'):
				j += et_number(&buf[j],4,(long)st.wYear);
			break;
			case _VTEXT('D'):
				j += et_number(&buf[j],1,(long)st.wDayOfWeek);
			break;
			case _VTEXT('W'):
				if (st.wDayOfWeek > 0 && st.wDayOfWeek < 8) {
					wcscpy(&buf[j],pfmtSet->szWeekDaysNames[st.wDayOfWeek - 1]);
					j += wcslen(pfmtSet->szWeekDaysNames[st.wDayOfWeek - 1]);
				}
			break;
			case _VTEXT('O'):
				if (st.wMonth > 0 && st.wMonth <= 12) {
					wcscpy(&buf[j],pfmtSet->szMonths[st.wMonth - 1]);
					j += wcslen(pfmtSet->szMonths[st.wMonth - 1]);
				}
			break;
			case _VTEXT('M'):
				j += et_number(&buf[j],2,(long)st.wMonth);
			break;
			case _VTEXT('H'):
				j += et_number(&buf[j],2,(long)st.wHour);
			break;
			case _VTEXT('m'):
				j += et_number(&buf[j],2,(long)st.wMinute);
			break;
			case _VTEXT('s'):
				j += et_number(&buf[j],2,(long)st.wSecond);
			break;
			case _VTEXT('h'):
				if (st.wHour >= 0 && st.wHour < 13) {
					j += et_number(&buf[j],2,(long)st.wHour);
				} else {
					j += et_number(&buf[j],2,(long)st.wHour - 12);
				}
			break;
			case _VTEXT('p'):
				if (st.wHour >= 0 && st.wHour < 13) {
					l = wcslen(pfmtSet->szAMSymbol);
					memcpy(&buf[j],pfmtSet->szAMSymbol,l * sizeof(_VCHAR));
					j += l;
				} else {
					l = wcslen(pfmtSet->szPMSymbol);
					memcpy(&buf[j],pfmtSet->szPMSymbol,l * sizeof(_VCHAR));
					j += l;
				}
			break;
			default:
				buf[j++] = fmt[i];
				if (j > etBUFSIZE-2) return 0;
		}
		if (j > etBUFSIZE - 33) return 0;
	}
	return j;
}

long _vatoi(_VCHAR* namedarg,long* numErr) {
	_VCHAR	c;
	long sign = 1;
	*numErr = 0;
	c = (*(namedarg++));
	if (c == _VCHAR('\0')) {
		*numErr = 1;
		return 0;
	}
	if (c == _VCHAR('-')) {
		sign = -1;
		c = (*(namedarg++));
	} else if (c == _VCHAR('-')) {
		sign = 1;
		c = (*(namedarg++));
	}
	long width = 0;
	while ( c >= _VTEXT('0') && c <= _VTEXT('9') ) {
		width = width * 10 + c - _VTEXT('0');
		c = *(++namedarg);
	}
	return (width * sign);
}

long VarPrintf(
					   CONSUMESTRINGPROC	pfnConsumer,
					   LPVOID				pvCData,
					   const _VCHAR*		vszFormat,
					   // Here we will put some extensions
					   SUPPLYPARAMPROC		pfnSupplier,
					   LPVOID				pvSData,
					   VarPrintfSettings*	pfmtSet
					   ) {
	// Local variables
	_VCHAR					c;
	_VCHAR*					pBuffPos;

	_VCHAR*					pBuffForDeletion = NULL;

	_VCHAR					prefix = _VTEXT('\0');

	_VCHAR buf[etBUFSIZE];    // Portion buffer
	_VCHAR namedarg[etNAMELEN];	  // Named arguments

	_FmtTypeInfo*			pInfo = NULL; // Pointer to the format type information

	long					count = 0;
	long					width = 0;
	long					length = 0; // Length of different fields and/or conversions strings
	long					precision = 0;
	long					paramIndex = 0;
	long					exp = 0;

	unsigned long			longvalue = 0;
	long double				realvalue = 0;
	double					rounder;

	long					idx;	// Indexer
	BYTE					xtype;	// type of conversion

	HRESULT					hrErrorState = S_OK;
	HRESULT					hr; // Temporary results from functions called inside this body

	VARIANT					v;

	BYTE	fLeftJustify;	// "-" 
	BYTE	fPlusSign;			// "+" 
	BYTE	fBlankSign;		// " "
	BYTE	fAlternateForm;	// "#"
	BYTE	fZeroPad;			/* True if field width constant starts with zero */
	BYTE	fIntSize;			// "h", "l" ["I64" - for future implementation may be] 0 - Default (l), 1 - Word, 2 - Long, 3 - Long Long
	BYTE	fDP;            /* True if decimal point should be shown */
	BYTE	fRTZ;           /* True if trailing zeros should be removed */
	BYTE	fExp;           /* True to force display of the exponent */
	BYTE	fAllowNull;		/* Allow nulls to be handled as DB Null-s */
	BYTE	fNameIsIndex;	/* Named value is an index and not a name */
	// BYTE	fListMode;		// The variable is array

	long nsd;                   /* Number of significant digits returned */

	static _VCHAR spaces[] = _VTEXT("                                                  ");
	BOOL	b;
	#define etSPACESIZE (sizeof(spaces)-1)



	::VariantInit(&v);

	for (; (c = (*vszFormat)) != _VTEXT('\0'); ++vszFormat) {
		namedarg[0] = _VTEXT('\0');
		if (c != _VCHAR('%')) {
			// Read any literal part and send it to the consumer "as is"
			long amount;
			pBuffPos = (_VCHAR*)vszFormat;
			amount = 1;
			// Read till end of string or first formatting command
			while( ( c = (*(++vszFormat)) ) != '%' && c != _VTEXT('\0') ) amount++;
			if (!(*pfnConsumer)(pvCData,pBuffPos,amount)) {
				hrErrorState = E_OUTOFMEMORY;
				break;
			}
			count += amount;
			if( c == _VTEXT('\0') ) break; // Exit entire cycle
		}

		// Behave nicely if we end here
		// <winerror.h>
		if( ( c = (*(++vszFormat)) ) == _VTEXT('\0') ) {
			hrErrorState = DISP_E_PARAMNOTFOUND;
			(*pfnConsumer)(pvCData,_VTEXT("%"),1);
			count++;
			break;
		}
		fNameIsIndex = 0;
		// Determine name if any
		if (c == _VTEXT('[')) {
			// Name begins and ends with ']'
			long amount;
			amount = 0;
			while( ( c = (*(++vszFormat)) ) != ']' && c != _VTEXT('\0')) {
				if (amount < (etNAMELEN - 1)) namedarg[amount++] = c;
			}
			namedarg[amount] = _VTEXT('\0');
			if( c == _VTEXT('\0') ) break; // Exit entire cycle
			c = (*(++vszFormat));
		} else if (c == _VTEXT('(')) {
			fNameIsIndex = 1;
			// Index begins and ends with '(' and ')'
			long amount;
			amount = 0;
			while( ( c = (*(++vszFormat)) ) != ')' && c != _VTEXT('\0')) {
				if (amount < (etNAMELEN - 1)) namedarg[amount++] = c;
			}
			namedarg[amount] = _VTEXT('\0');
			if( c == _VTEXT('\0') ) break; // Exit entire cycle
			c = (*(++vszFormat));
			// Try to translate the index into integer
			long	lnum,numErr;
			lnum = _vatoi(namedarg,&numErr);
			if (numErr != 0) {
				hrErrorState = DISP_E_TYPEMISMATCH;
				// Error
				break;
			} else {
				paramIndex = lnum;
				namedarg[0] = _VTEXT('\0');
			}
		} else {
			namedarg[0] = _VTEXT('\0');
		}

		// Determine flags if any
		fLeftJustify = fPlusSign = fBlankSign = fAlternateForm = fZeroPad = 0;
		do{
			switch (c) {
				case _VTEXT('-'):   fLeftJustify = 1; c = _VTEXT('\0');   break;
				case _VTEXT('+'):   fPlusSign = 1; c = _VTEXT('\0');   break;
				case _VTEXT(' '):   fBlankSign = 1; c = _VTEXT('\0');   break;
				case _VTEXT('#'):   fAlternateForm = 1; c = _VTEXT('\0');   break;
				case _VTEXT('0'):   fZeroPad = 1; c = _VTEXT('\0');   break;
				default:
					break;
		  }
		} while( c == _VTEXT('\0') && ( c = (*(++vszFormat)) ) != 0 );

		// Field width
		width = 0;
		if( c == _VTEXT('*') ) {
			// We need argument
			::VariantClear(&v);
			hr = (*pfnSupplier)(pvSData,VT_I4,paramIndex++,namedarg,FALSE,&v);
			if (FAILED(hr)) {
				hrErrorState = hr;
				break;
			}
			// We have the argument
			width = v.lVal;
			::VariantClear(&v);
			if ( width < 0 ) {
				fLeftJustify = 1;
				width = -width;
			}
			c = *(++vszFormat);
		} else {
			while ( c >= _VTEXT('0') && c <= _VTEXT('9') ) {
				width = width * 10 + c - _VTEXT('0');
				c = *(++vszFormat);
			}
		}

		if( width > etBUFSIZE - 10 ) {
			width = etBUFSIZE - 10;
		}

		// Precision
		if ( c == _VTEXT('.') ) {
			precision = 0;
			c = *(++vszFormat);
			if ( c == _VTEXT('*') ) {
				// Get argument
				::VariantClear(&v);
				hr = (*pfnSupplier)(pvSData,VT_I4,paramIndex++,namedarg,FALSE,&v);
				if (FAILED(hr)) {
					hrErrorState = hr;
					break;
				}
				precision = v.lVal;
				::VariantClear(&v);
				if ( precision < 0 ) precision = -precision; // Must be positive
				c = *(++vszFormat);
			} else {
				while( c >= _VTEXT('0') && c <= _VTEXT('9') ) {
					precision = precision * 10 + c - _VTEXT('0');
					c = *(++vszFormat);
				}
			}

			// Limit the precision to prevent overflowing buf[] during conversion
			if ( precision > etBUFSIZE - 40 ) precision = etBUFSIZE - 40;

		} else {
			precision = -1;
		}

		// Get the conversion type modifier
		if ( c == _VTEXT('l') ) {
			fIntSize = 2;	// 4 - byte integer
			c = *(++vszFormat);
		} else if ( c == _VTEXT('h') ) {
			fIntSize = 1;	// 4 - byte integer
			c = *(++vszFormat);
		} else {
			fIntSize = 0;
		}

		// Get the null afinity type modifier
		if ( c == _VTEXT('N') ) {
			fAllowNull = 1;	// Nulls allowed
			c = *(++vszFormat);
		} else {
			fAllowNull = 0;
		}

		/*
		if ( c == _VTEXT(';') ) {
			fListMode = 1;	// Nulls allowed
			c = *(++vszFormat);
		} else {
			fListMode = 0;
		}
		*/

		// Fetch the info entry for the field
		pInfo = NULL;

		xtype = etERROR;

		if (c == _VTEXT('a')) {
			//if (fListMode) return -paramIndex;
			::VariantClear(&v);
			// Called with VT_VARIANT the supplier is instructed to strip the value but not
			// change its type to anything specific
			hr = (*pfnSupplier)(pvSData,VT_VARIANT,paramIndex,namedarg,(BOOL)fAllowNull,&v);
			if (FAILED(hr)) {
				return -paramIndex;
			}
			c = et_findbesttype(v.vt,pfmtSet->szAutoFormat);
			::VariantClear(&v);
		}

		for ( idx = 0; idx < etNINFO; idx++ ) {
			if ( c == fmtinfo[idx].fmttype ) {
				pInfo = &fmtinfo[idx];
				xtype = pInfo->type;
				break;
			}
		}
		// zExtra = 0;

		switch (xtype) {
			case etDATETIME:
				if (fIntSize == 0) fIntSize = 2;
			case etDATE:
			case etTIME:
				if (xtype == etTIME) {
					if (fIntSize == 1) fIntSize = 0;
				}
				::VariantClear(&v);
				hr = (*pfnSupplier)(pvSData,VT_DATE,paramIndex++,namedarg,(BOOL)fAllowNull,&v);
				if (FAILED(hr)) {
					// ERROR

					return -paramIndex;
				}
				if (v.vt == VT_NULL) {
					pBuffPos = pfmtSet->szNullName;
					length = wcslen(pfmtSet->szNullName);
					::VariantClear(&v);
					break;
				}
				if (fIntSize == 2) {
					xtype = etDATETIME;
				} else if (fIntSize == 1) {
					xtype = etDATE;
				} else {
					xtype = etTIME;
				}
				switch (xtype) {
					case etDATETIME:
						length = et_fmtdatetime(pfmtSet->szDateTimeFormat,pfmtSet,v.date,buf);
					break;
					case etDATE:
						length = et_fmtdatetime(pfmtSet->szDateFormat,pfmtSet,v.date,buf);
					break;
					case etTIME:
						length = et_fmtdatetime(pfmtSet->szTimeFormat,pfmtSet,v.date,buf);
					break;
				}
				::VariantClear(&v);
				precision = 0;
				pBuffPos = buf;
			break;

			// Long integer conversion
			case etRADIX:
				::VariantClear(&v);
				if (fIntSize == 2 || fIntSize == 0) {
					hr = (*pfnSupplier)(pvSData,VT_I4,paramIndex++,namedarg,(BOOL)fAllowNull,&v);
					if (!FAILED(hr)) longvalue = (unsigned long)v.lVal;
				} else if (fIntSize == 1) {
					hr = (*pfnSupplier)(pvSData,VT_I2,paramIndex++,namedarg,(BOOL)fAllowNull,&v);
					if (!FAILED(hr)) longvalue = (unsigned long)v.iVal;
				} else {
					hr = DISP_E_TYPEMISMATCH;
				}
				if (FAILED(hr)) {
					// ERROR

					return -paramIndex;
				}
				if (v.vt == VT_NULL) {
					pBuffPos = pfmtSet->szNullName;
					length = wcslen(pfmtSet->szNullName);
					::VariantClear(&v);
					break;
				}
				::VariantClear(&v);
				if ( longvalue == 0 && pInfo->base == 8 ) fAlternateForm = 0;
				

				if ( pInfo->flags & FLAG_SIGNED ) {
					if	( *(long*)&longvalue < 0 ) {
						//longvalue = -(long)longvalue;
						longvalue = -(*((long*)&longvalue));
						prefix = _VTEXT('-');
					} else if (fPlusSign) {
						prefix = _VTEXT('+');
					} else if (fBlankSign) {
						prefix = _VTEXT(' ');
					} else {
						prefix = _VTEXT('\0');
					}
				} else {
					prefix = _VTEXT('\0');
				}


				if ( fZeroPad && precision < width - ((prefix != _VTEXT('\0'))?1:0) ) {
					precision = width - ( (prefix != _VTEXT('\0'))?1:0 );
				}

				pBuffPos = &buf[etBUFSIZE-1];
				{
				  register _VCHAR * cset;      /* Use registers for speed */
				  register long		base;
				  cset = pInfo->charset;
				  base = pInfo->base;
				  do {                                           /* Convert to ascii */
					*(--pBuffPos) = cset[longvalue % base];
					longvalue = longvalue / base;
				  } while ( longvalue > 0 );
				}

				length = &buf[etBUFSIZE-1] - pBuffPos;
				for ( idx = precision - length; idx > 0; idx --) {
					*(--pBuffPos) = _VTEXT('0');                             /* Zero pad */
				}
				if ( prefix ) *(--pBuffPos) = prefix;               /* Add sign */
				if ( fAlternateForm && pInfo->prefix ) {      /* Add "0" or "0x" */
					_VCHAR * pre;
					_VCHAR x;
					pre = pInfo->prefix;
					if ( *pBuffPos != pre[0] ) {
						for( pre = pInfo->prefix; ( x = (*pre) ) != _VTEXT('\0'); pre++) *(--pBuffPos) = x;
					}
				}
				length = &buf[etBUFSIZE-1] - pBuffPos;
			break;

			// Floating point value conversion
			case etFLOAT:
			case etEXP:
			case etGENERIC:
			case etEXPMAX:
				if (xtype == etEXPMAX) {
					xtype = etGENERIC;
					precision = 16;
				}
				::VariantClear(&v);
				hr = (*pfnSupplier)(pvSData,VT_R8,paramIndex++,namedarg,(BOOL)fAllowNull,&v);
				if (FAILED(hr)) {
					// ERROR

					return -paramIndex;
				}
				if (v.vt == VT_NULL) {
					pBuffPos = pfmtSet->szNullName;
					length = wcslen(pfmtSet->szNullName);
					precision = 0;
					::VariantClear(&v);
					break;
				}
				realvalue = (long double)v.dblVal;
				::VariantClear(&v);
				if ( precision < 0 ) precision = 6;         /* Set default precision */
				if ( precision > etBUFSIZE - 10 ) precision = etBUFSIZE-10;
				if ( realvalue <0.0 ) {
					realvalue = -realvalue;
					prefix = _VTEXT('-');
				} else {
					if (fPlusSign) {
						prefix = _VTEXT('+');
					} else if (fBlankSign) {
						prefix = _VTEXT(' ');
					} else {
                        prefix = _VTEXT('\0');
					}
				}
				if ( pInfo->type == etGENERIC && precision > 0 ) precision--;
				rounder = 0.0;
				
				for ( idx = precision, rounder = 0.5; idx > 0; idx--, rounder *= 0.1);

				if ( pInfo->type == etFLOAT ) realvalue += rounder;
				/* Normalize realvalue to within 10.0 > realvalue >= 1.0 */
				exp = 0;

				if( realvalue > 0.0 ) {
					while ( realvalue >= 1e8 && exp <= 350 ) { realvalue *= 1e-8; exp += 8; }
					while ( realvalue >= 10.0 && exp <= 350 ) { realvalue *= 0.1; exp++; }
					while ( realvalue < 1e-8 && exp >= -350 ) { realvalue *= 1e8; exp -= 8; }
					while ( realvalue < 1.0 && exp >= -350 ) { realvalue *= 10.0; exp--; }
					if ( exp > 350 || exp < -350 ) {
						pBuffPos = pfmtSet->szNaNName;
						length = wcslen(pfmtSet->szNaNName);
						break; // Skip to transfer data point
					}
				}
				pBuffPos = buf;

				/*
				** If the field type is etGENERIC, then convert to either etEXP
				** or etFLOAT, as appropriate.
				*/
				fExp = (xtype == etEXP)?1:0;

				if ( xtype != etFLOAT ) {
					realvalue += rounder;
					if ( realvalue >= 10.0 ) { realvalue *= 0.1; exp++; }
				}

				if ( xtype == etGENERIC ) {
					fRTZ = !fAlternateForm;
					if ( exp < -4 || exp > precision ) {
						xtype = etEXP;
					} else {
						precision = precision - exp;
						xtype = etFLOAT;
					}
				} else {
					fRTZ = 0;
				}

				/*
				** The "exp+precision" test causes output to be of type etEXP if
				** the precision is too large to fit in buf[].
				*/

				nsd = 0;
				if ( xtype == etFLOAT && exp + precision < etBUFSIZE - 30 ) {
					fDP = (precision > 0 || fAlternateForm)?1:0;
					if (prefix) *(pBuffPos++) = prefix;         /* Sign */

					if (exp < 0) *(pBuffPos++) = _VTEXT('0');            /* Digits before "." */
					else for(; exp >= 0; exp--) *(pBuffPos++) = et_getdigit(&realvalue,&nsd);

					if (fDP) *(pBuffPos++) = pfmtSet->chDecimal;           /* The decimal point ===***=== - needs future adjustment */
					for ( exp++; exp < 0 && precision > 0; precision--, exp++) {
						*(pBuffPos++) = _VTEXT('0');
					}
					while ( (precision--) > 0 ) *(pBuffPos++) = et_getdigit(&realvalue,&nsd);
					*(pBuffPos--) = 0;                           /* Null terminate */
					if ( fRTZ && fDP ) {     /* Remove trailing zeros and "." */
						while ( pBuffPos >= buf && *pBuffPos == _VTEXT('0') ) *(pBuffPos--) = _VTEXT('\0');
						if( pBuffPos >= buf && *pBuffPos == pfmtSet->chDecimal ) *(pBuffPos--) = _VTEXT('\0');
					}
					pBuffPos++;
				} else {    /* etEXP or etGENERIC */
					fDP = (precision > 0 || fAlternateForm)?1:0;
					if (prefix) *(pBuffPos++) = prefix;   /* Sign */
					*(pBuffPos++) = et_getdigit(&realvalue,&nsd);  /* First digit */
					if (fDP) *(pBuffPos++) = pfmtSet->chDecimal;     /* Decimal point */
					while ((precision--) > 0) *(pBuffPos++) = et_getdigit(&realvalue,&nsd);
					pBuffPos--;                            /* point to last digit */
					if ( fRTZ && fDP) {          /* Remove tail zeros */
						while ( pBuffPos >= buf && *pBuffPos == _VTEXT('0') ) *(pBuffPos--) = _VTEXT('\0');
						if( pBuffPos >= buf && (*pBuffPos) == pfmtSet->chDecimal ) *(pBuffPos--) = _VTEXT('\0');
					}

					pBuffPos++;                            /* point to next free slot */
					if ( exp || fExp ) {
						*(pBuffPos++) = pInfo->charset[0];
						if (exp < 0) {
							*(pBuffPos++) = _VTEXT('-');
							exp = -exp; 
						} /* sign of exp */ else       { 
							*(pBuffPos++) = _VTEXT('+'); 
						}
						if (exp >= 100) {
							*(pBuffPos++) = (exp / 100) + _VTEXT('0');                /* 100's digit */
							exp %= 100;
						}
						*(pBuffPos++) = exp / 10 + _VTEXT('0');                     /* 10's digit */
						*(pBuffPos++) = exp % 10 + _VTEXT('0');                     /* 1's digit */
					}
				}

				/* The converted number is in buf[] and zero terminated. Output it.
				** Note that the number is in the usual order, not reversed as with
				** integer conversions. */
				length = pBuffPos - buf;
				pBuffPos = buf;

				/* Special case:  Add leading zeros if the flag_zeropad flag is
				** set and we are not left justified */
				if( fZeroPad && !fLeftJustify && length < width) {
					long i;
					long nPad = width - length;
					for (i = width; i >= nPad; i--) {
						pBuffPos[i] = pBuffPos[i - nPad];
					}
					  i = prefix != _VTEXT('\0');
					  while ( nPad-- ) pBuffPos[i++] = _VTEXT('0');
					  length = width;
				}
			break;

			case etPERCENT:
				buf[0] = _VTEXT('%');
				pBuffPos = buf;
				length = 1;
			break;

			case etCHARLIT:
			case etCHARX:
				if (xtype == etCHARX) {
					::VariantClear(&v);
					hr = (*pfnSupplier)(pvSData,VT_I4,paramIndex++,namedarg,(BOOL)fAllowNull,&v);
					if (FAILED(hr)) {
						// ERROR

						return -paramIndex;
					}
					if (v.vt == VT_NULL) {
						pBuffPos = pfmtSet->szNullName;
						length = wcslen(pfmtSet->szNullName);
						::VariantClear(&v);
						break;
					}
					c = (_VCHAR)v.lVal;
					::VariantClear(&v);
				} else {
					c = *(++vszFormat);
				}
				buf[0] = c;
				if ( precision >= 0 ) {
					for (idx = 1; idx < precision; idx++) buf[idx] = c;
					length = precision;
				} else {
					length = 1;
				}
				pBuffPos = buf;
			break;
			
			case etSTRING:
			case etDYNSTRING:
			case etSQLESCAPE:
			case etSQLESCAPE2:
				::VariantClear(&v);
				hr = (*pfnSupplier)(pvSData,VT_BSTR,paramIndex++,namedarg,(BOOL)fAllowNull,&v);
				if (FAILED(hr)) {
					// ERROR

					return -paramIndex;
				}
				if (v.vt == VT_NULL) {
					pBuffPos = pfmtSet->szNullName;
					length = wcslen(pfmtSet->szNullName);
					::VariantClear(&v);
					break;
				}
				// We must create buffer which will be deleted after usage
				// No exit proc from this point until the end of the case !!!!!!
				length = wcslen(v.bstrVal);
				pBuffForDeletion = new _VCHAR[length + 1];
				if (!pBuffForDeletion) {
					// Error allocating the buffer
					hrErrorState = E_OUTOFMEMORY;

					return -paramIndex;
				}
				// Copy the data
				memcpy(pBuffForDeletion,v.bstrVal,sizeof(_VCHAR) * length);
				::VariantClear(&v);
				pBuffForDeletion[length] = _VTEXT('\0');
				pBuffPos = pBuffForDeletion;

				//if( xtype==etDYNSTRING ){
				//zExtra = bufpt;
				//}
				if (xtype == etSQLESCAPE || xtype == etSQLESCAPE2) {
					// Deal with SQL escaping here
					long i,n;
					// Count the escapes
					if (xtype == etSQLESCAPE2) {
						for( i = n = 0; (c = pBuffForDeletion[i]) != 0; i++) {
							if ( c == _VTEXT('\"') )  n++;
						}
					} else {
						for( i = n = 0; (c = pBuffForDeletion[i]) != 0; i++) {
							if ( c == _VTEXT('\'') )  n++;
						}
					}
					// Allocate new buffer
					pBuffPos = new _VCHAR[length + n + 3];
					if (!pBuffPos) {
						delete [] pBuffForDeletion;
						return -paramIndex;
					}

					
					long j = 0;
					if (xtype == etSQLESCAPE2) {
						pBuffPos[j++] = _VTEXT('\"');
					} else {
						pBuffPos[j++] = _VTEXT('\'');
					}
					for(i = 0; (c = pBuffForDeletion[i]) != _VTEXT('\0'); i++) {
						pBuffPos[j++] = c;
						if (xtype == etSQLESCAPE2) {
							if (c == _VTEXT('\"')) pBuffPos[j++] = c;
						} else {
							if (c == _VTEXT('\'')) pBuffPos[j++] = c;
						}
					}
					if (xtype == etSQLESCAPE2) {
						pBuffPos[j++] = _VTEXT('\"');
					} else {
						pBuffPos[j++] = _VTEXT('\'');
					}
					pBuffPos[j] = _VTEXT('\0');
					length = j;
					delete [] pBuffForDeletion;
					pBuffForDeletion = pBuffPos;
				}
				if ( precision >= 0 && precision < length ) length = precision;
			break;
			case etERROR:
				buf[0] = '%';
				buf[1] = c;
				hrErrorState = S_OK;
				length = 1 + ((c != _VTEXT('\0')?1:0));
				pBuffPos = buf;
				if( c == _VTEXT('\0') ) vszFormat--;
			break;
		}
		if (!fLeftJustify) {
			register long nspace;
			nspace = width - length;
			if (nspace > 0) {
				count += nspace;
				while (nspace >= etSPACESIZE) {
					if (!(*pfnConsumer)(pvCData,spaces,etSPACESIZE)) {
						b = FALSE;
						goto _Consumer_Error;
					}
					nspace -= etSPACESIZE;
				}
				if (nspace > 0) {
					if (!(*pfnConsumer)(pvCData,spaces,nspace)) {
						b = FALSE;
						goto _Consumer_Error;
					}
				}
			}
		}
		if (length > 0) {
			if (!(*pfnConsumer)(pvCData,pBuffPos,length)) {
				b = FALSE;
				goto _Consumer_Error;
			}
			count += length;
		}
		if (fLeftJustify) {
			register int nspace;
			nspace = width - length;
			if (nspace > 0) {
				count += nspace;
				while (nspace >= etSPACESIZE) {
					if (!(*pfnConsumer)(pvCData,spaces,etSPACESIZE)) {
						b = FALSE;
						goto _Consumer_Error;
					}
					nspace -= etSPACESIZE;
				}
				if (nspace > 0) {
					if (!(*pfnConsumer)(pvCData,spaces,nspace)) {
						b = FALSE;
						goto _Consumer_Error;
					}
				}
			}
		}
		b = TRUE;
      _Consumer_Error:
		if (pBuffForDeletion) {
			delete [] pBuffForDeletion;
			pBuffForDeletion = NULL;
		}
		if (!b) return -((paramIndex > 0)?paramIndex:1);
	}
	::VariantClear(&v);
	return (hrErrorState == S_OK)? count:-((paramIndex > 0)?paramIndex:1);
}

HRESULT		VarPrintfSupplyFromSafeArray(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal) {
	SAFEARRAY*	psa = (SAFEARRAY*)pvData;
	if (!psa) return E_FAIL;
	long		LBound = 0,UBound = -1;
	HRESULT		hr;

	if (!(psa->fFeatures & FADF_VARIANT)) return DISP_E_TYPEMISMATCH;
	if (psa->cDims > 1) return DISP_E_TYPEMISMATCH;

	hr = ::SafeArrayGetLBound(psa,1,&LBound);
	if (FAILED(hr)) return hr;
	hr = ::SafeArrayGetUBound(psa,1,&UBound);
	if (FAILED(hr)) return hr;

	long	lIndex = lParamIndex + LBound;

	if (lIndex > UBound) return DISP_E_PARAMNOTFOUND;

	VARIANT		v;
	::VariantInit(&v);
	hr = ::SafeArrayGetElement(psa,&lIndex,&v);
	if (FAILED(hr)) return hr;
	
	VARIANT v1;
	::VariantInit(&v1);
	hr = ::VariantCopyInd(&v1,&v);
	::VariantClear(&v);
	if (FAILED(hr)) return hr;

	if (bAllowNull && v1.vt == VT_NULL) {
		hr = ::VariantCopy(pVal,&v1);
	} else {
		if (vt == VT_VARIANT) {
			hr = ::VariantResolveToValue(pVal,&v1);
		} else {
			hr = ::VariantChangeType(pVal,&v1,0,vt);
		}
	}
	::VariantClear(&v1);
	return hr;
}

HRESULT		VarPrintfSupplyCollection(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal) {
	_VarPrintfSupplyFromCollectionData*	pCD = (_VarPrintfSupplyFromCollectionData*)pvData;
	if (!pCD->pdc) return E_FAIL;

	DISPCALLER&	dc = *pCD->pdc;

	VARIANT		vIndex;
	::VariantInit(&vIndex);
	VARIANT		vResult;
	::VariantInit(&vResult);

	HRESULT	hr;

	// Init vIndex to what we must have there
	if (szName[0] == _VTEXT('\0')) {
		vIndex.vt = VT_I4;
		vIndex.lVal = pCD->lBaseIndex + lParamIndex;
	} else {
		vIndex.vt = VT_BSTR;
		vIndex.bstrVal = ::SysAllocString(szName);
	}

	dc << vIndex;
	vResult = dc.GetProperty((DISPID)DISPID_VALUE);
	::VariantClear(&vIndex);
	if (vResult.vt == VT_ERROR) {
		hr = vResult.scode;
		::VariantClear(&vResult);
		return hr;
	}
	hr = ::VariantResolveToValue(&vIndex,&vResult);
	::VariantClear(&vResult);
	if (FAILED(hr)) {
		return DISP_E_TYPEMISMATCH;
	}
	if (bAllowNull && vIndex.vt == VT_NULL) {
		hr = ::VariantCopy(pVal,&vIndex);
	} else {
		if (vt == VT_VARIANT) {
			hr = ::VariantCopyInd(pVal,&vIndex);
		} else {
			hr = ::VariantChangeType(pVal,&vIndex,0,vt);
		}
	}
	::VariantClear(&vIndex);
	return hr;
}
//HRESULT		VarPrintfSupplyFromCollection(LPVOID pvData,VARTYPE vt,long lParamIndex,VARIANT* pVal);

BOOL		VarPrintfConsumeToWSTR(LPVOID pvData,const _VCHAR* pvsz,long lChars) {
	if (!pvData) return FALSE; // Safety precaution
	LPWSTR*	ppwsz = (LPWSTR*)pvData;
	LPWSTR	pwszCursor;
	long	lexisting = 0;
	if (!(*ppwsz)) {
		*ppwsz = new WCHAR[lChars + 1];
		if (!(*ppwsz)) return FALSE;
		pwszCursor = *ppwsz;
	} else {
		lexisting = wcslen(*ppwsz);
		LPWSTR	pwszTemp = new WCHAR[lChars + 1 + lexisting];
		if (!pwszTemp) {
			delete [] (*ppwsz);
			*ppwsz = NULL;
			return FALSE;
		}
		memcpy(pwszTemp,*ppwsz,lexisting * sizeof(WCHAR));
		delete [] (*ppwsz);
		*ppwsz = pwszTemp;
		pwszCursor = (*ppwsz) + lexisting;
	}
	memcpy(pwszCursor,pvsz,lChars * sizeof(WCHAR));
	pwszCursor[lChars] = L'\0';
	return TRUE;
}

// Ready to use functions

long BSTRPrintf(BSTR bstrFormat,VarPrintfSettings* fmtSet,SAFEARRAY* psa,BSTR* pbstr) {
	if (!pbstr) return -1; // Safety precaution
	LPWSTR		pwsz = NULL;
	
	long l = VarPrintf(	VarPrintfConsumeToWSTR,
						&pwsz,
					    (_VCHAR*)bstrFormat,
						VarPrintfSupplyFromSafeArray,
						(LPVOID)psa,
						fmtSet);
	if (l < 0) {
		if (pwsz) delete [] pwsz;
		return l;
	}
	if (!pwsz) {
		*pbstr = ::SysAllocString(L"");
	} else {
		*pbstr = ::SysAllocString(pwsz);
		delete [] pwsz;
	}
	return l;
}

long BSTRCPrintf(BSTR bstrFormat,VarPrintfSettings* fmtSet,IUnknown* pColl,BSTR* pbstr) {
	if (!pbstr) return -1; // Safety precaution
	LPWSTR		pwsz = NULL;

	_VarPrintfSupplyFromCollectionData	CD; // Collection data
	// First create the supplier data set.
	DISPCALLER	dc;
	dc = pColl;
	if (!dc.IsValid()) return -1; // This collection is not supported (no IDispatch etc.)
	VARIANT	v;
	VARIANT	vI;
	::VariantInit(&v);
	::VariantInit(&vI); // Index
	vI.vt = VT_I4;
	vI.lVal = 0;
	v = dc.VariantCall((DISPID)0);
	if (v.vt == VT_ERROR) {
		CD.lBaseIndex = 1;
	} else {
		CD.lBaseIndex = 0;
	}
	::VariantClear(&vI);
	::VariantClear(&v);
	CD.pdc = &dc;

	
	long l = VarPrintf(	VarPrintfConsumeToWSTR,
						&pwsz,
					    (_VCHAR*)bstrFormat,
						VarPrintfSupplyCollection,
						(LPVOID)&CD,
						fmtSet);
	if (l < 0) {
		if (pwsz) delete [] pwsz;
		return l;
	}
	if (!pwsz) {
		*pbstr = ::SysAllocString(L"");
	} else {
		*pbstr = ::SysAllocString(pwsz);
		delete [] pwsz;
	}
	return l;
}
/////////////////////////////////////

struct  VARPRINTF_VARIANTARRAY_DESCRIPTOR {
    VARIANT*    pVars;
    long        lCount;
};

HRESULT		VarPrintfSupplyFromVARIANTArray(LPVOID pvData,VARTYPE vt,long lParamIndex,_VCHAR* szName,BOOL bAllowNull,VARIANT* pVal) {
    VARPRINTF_VARIANTARRAY_DESCRIPTOR*  pvad;
    pvad = (VARPRINTF_VARIANTARRAY_DESCRIPTOR*)pvData;
	if (!pvad) return E_FAIL;

	HRESULT		hr;

	if (lParamIndex >= pvad->lCount || lParamIndex < 0) return DISP_E_PARAMNOTFOUND;

	VARIANT		v;
	::VariantInit(&v);

    hr = ::VariantResolveToValue(&v,&pvad->pVars[lParamIndex]);

	if (FAILED(hr)) return hr;
	
	if (bAllowNull && v.vt == VT_NULL) {
		hr = ::VariantCopy(pVal,&v);
	} else {
		if (vt == VT_VARIANT) {
            hr = ::VariantCopyInd(pVal,&v);
		} else {
			hr = ::VariantChangeType(pVal,&v,0,vt);
		}
	}
	::VariantClear(&v);
	return hr;
}

long BSTRPrintfVARIANTArray(BSTR bstrFormat,VarPrintfSettings* fmtSet,VARIANT* pvars,long lCount,BSTR* pbstr) {
	if (!pbstr) return -1; // Safety precaution
	LPWSTR		pwsz = NULL;
	
    VARPRINTF_VARIANTARRAY_DESCRIPTOR   vad;

    vad.pVars = pvars;
    vad.lCount = lCount;

	long l = VarPrintf(	VarPrintfConsumeToWSTR,
						&pwsz,
					    (_VCHAR*)bstrFormat,
						VarPrintfSupplyFromVARIANTArray,
						(LPVOID)&vad,
						fmtSet);
	if (l < 0) {
		if (pwsz) delete [] pwsz;
		return l;
	}
	if (!pwsz) {
		*pbstr = ::SysAllocString(L"");
	} else {
		*pbstr = ::SysAllocString(pwsz);
		delete [] pwsz;
	}
	return l;
}

