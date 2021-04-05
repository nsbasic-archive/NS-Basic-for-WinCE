#include "oledateconversions.h"


int _MonthDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

#define MIN_DATE                (-657434L)  // about year 100
#define MAX_DATE                2958465L    // about year 9999
#define HALF_SECOND  (1.0/172800.0)

BOOL hlpOleDateFromSystemType(SYSTEMTIME* pst, DATE& dtDest) {
	if (pst->wYear > 9999 || pst->wMonth < 1 || pst->wMonth > 12)
		return FALSE;

	BOOL bLeapYear = ((pst->wYear & 3) == 0) &&
		((pst->wYear % 100) != 0 || (pst->wYear % 400) == 0);

	int nDaysInMonth =
		_MonthDays[pst->wMonth] - _MonthDays[pst->wMonth-1] +
		((bLeapYear && pst->wDay == 29 && pst->wMonth == 2) ? 1 : 0);

	if (pst->wDay < 1 || pst->wDay > nDaysInMonth ||
		pst->wHour > 23 || pst->wMinute > 59 ||
		pst->wSecond > 59)
	{
		return FALSE;
	}

	long nDate;
	double dblTime;

	nDate = pst->wYear*365L + pst->wYear/4 - pst->wYear/100 + pst->wYear/400 +
		_MonthDays[pst->wMonth-1] + pst->wDay;

	if (pst->wMonth <= 2 && bLeapYear)
		--nDate;

	//  Offset so that 12/30/1899 is 0
	nDate -= 693959L;

	dblTime = (((long)pst->wHour * 3600L) +  // hrs in seconds
		((long)pst->wMinute * 60L) +  // mins in seconds
		((long)pst->wSecond)) / 86400.;

	dtDest = (double) nDate + ((nDate >= 0) ? dblTime : -dblTime);
	return TRUE;
}

// Tolerates 0 year, month and and day, treats them as 12/30/1899
BOOL hlpOleDateFromSystemTime(SYSTEMTIME* pstIn, DATE& dtDest) {
	SYSTEMTIME st;
	memcpy(&st,pstIn,sizeof(SYSTEMTIME));
	if (st.wYear == 0 && st.wMonth == 0 && st.wDay == 0) {
		st.wYear = (WORD)1899;
		st.wMonth = 12;
		st.wDay = 30;
	}
	return hlpOleDateFromSystemType(&st,dtDest);
}


BOOL hlpOleDateToSystemType(DATE dtSrc, SYSTEMTIME& tmDest)
{
	// The legal range does not actually span year 0 to 9999.
	if (dtSrc > MAX_DATE || dtSrc < MIN_DATE) // about year 100 to about 9999
		return FALSE;

	ZeroMemory(&tmDest,sizeof(SYSTEMTIME));

	long nDays;             // Number of days since Dec. 30, 1899
	long nDaysAbsolute;     // Number of days since 1/1/0
	long nSecsInDay;        // Time in seconds since midnight
	long nMinutesInDay;     // Minutes in day

	long n400Years;         // Number of 400 year increments since 1/1/0
	long n400Century;       // Century within 400 year block (0,1,2 or 3)
	long n4Years;           // Number of 4 year increments since 1/1/0
	long n4Day;             // Day within 4 year block
							//  (0 is 1/1/yr1, 1460 is 12/31/yr4)
	long n4Yr;              // Year within 4 year block (0,1,2 or 3)
	BOOL bLeap4 = TRUE;     // TRUE if 4 year block includes leap year

	double dblDate = dtSrc; // tempory serial date

	// If a valid date, then this conversion should not overflow
	nDays = (long)dblDate;

	// Round to the second
	dblDate += ((dtSrc > 0.0) ? HALF_SECOND : -HALF_SECOND);

	nDaysAbsolute = (long)dblDate + 693959L; // Add days from 1/1/0 to 12/30/1899

	dblDate = fabs(dblDate);
	nSecsInDay = (long)((dblDate - floor(dblDate)) * 86400.);

	// Calculate the day of week (sun=1, mon=2...)
	//   -1 because 1/1/0 is Sat.  +1 because we want 1-based
	// <time.h>
	tmDest.wDayOfWeek = (WORD)(int)((nDaysAbsolute - 1) % 7L) + 1;

	// Leap years every 4 yrs except centuries not multiples of 400.
	n400Years = (long)(nDaysAbsolute / 146097L);

	// Set nDaysAbsolute to day within 400-year block
	nDaysAbsolute %= 146097L;

	// -1 because first century has extra day
	n400Century = (long)((nDaysAbsolute - 1) / 36524L);

	// Non-leap century
	if (n400Century != 0)
	{
		// Set nDaysAbsolute to day within century
		nDaysAbsolute = (nDaysAbsolute - 1) % 36524L;

		// +1 because 1st 4 year increment has 1460 days
		n4Years = (long)((nDaysAbsolute + 1) / 1461L);

		if (n4Years != 0)
			n4Day = (long)((nDaysAbsolute + 1) % 1461L);
		else
		{
			bLeap4 = FALSE;
			n4Day = (long)nDaysAbsolute;
		}
	}
	else
	{
		// Leap century - not special case!
		n4Years = (long)(nDaysAbsolute / 1461L);
		n4Day = (long)(nDaysAbsolute % 1461L);
	}

	if (bLeap4)
	{
		// -1 because first year has 366 days
		n4Yr = (n4Day - 1) / 365;

		if (n4Yr != 0)
			n4Day = (n4Day - 1) % 365;
	}
	else
	{
		n4Yr = n4Day / 365;
		n4Day %= 365;
	}

	// n4Day is now 0-based day of year. Save 1-based day of year, year number
	//tmDest..tm_yday = (int)n4Day + 1;
	tmDest.wYear = (WORD)(n400Years * 400 + n400Century * 100 + n4Years * 4 + n4Yr);

	// Handle leap year: before, on, and after Feb. 29.
	if (n4Yr == 0 && bLeap4)
	{
		// Leap Year
		if (n4Day == 59)
		{
			/* Feb. 29 */
			tmDest.wMonth = 2;
			tmDest.wDay = 29;
			goto DoTime;
		}

		// Pretend it's not a leap year for month/day comp.
		if (n4Day >= 60)
			--n4Day;
	}

	// Make n4DaY a 1-based day of non-leap year and compute
	//  month/day for everything but Feb. 29.
	++n4Day;

	// Month number always >= n/32, so save some loop time */
	for (tmDest.wMonth = (WORD)((n4Day >> 5) + 1);
		n4Day > _MonthDays[tmDest.wMonth]; tmDest.wMonth++);

	tmDest.wDay = (WORD)(int)(n4Day - _MonthDays[tmDest.wMonth-1]);

DoTime:
	if (nSecsInDay == 0) {
		tmDest.wHour = 0;
		tmDest.wMinute = tmDest.wSecond = 0;
	} else {
		tmDest.wSecond = (WORD)((int)nSecsInDay % 60L);
		nMinutesInDay = nSecsInDay / 60L;
		tmDest.wMinute = (WORD)((int)nMinutesInDay % 60);
		tmDest.wHour = (WORD)((int)nMinutesInDay / 60);
	}

	return TRUE;
}
BOOL hlpOleDateAdd(char chInterval,int n,DATE dt,DATE& dtDest) {
	SYSTEMTIME st;
	int		i;
	switch (chInterval) {
		case 'Y': // Years
			if (!hlpOleDateToSystemType(dt,st)) return FALSE;
			st.wYear = (WORD)((int)st.wYear + n);
			return hlpOleDateFromSystemType(&st,dtDest);
		break;
		case 'M': // months
			if (!hlpOleDateToSystemType(dt,st)) return FALSE;
			st.wMonth --;
			i = (int)st.wMonth + n;
			if (i >= 0) {
				st.wYear += (WORD)(i / 12);
				st.wMonth = (WORD)(i % 12 + 1);
			} else {
				i = -i;
				st.wMonth = 12 - ((i - 1) % 12);
				st.wYear -= ((i - 1) / 12) + 1;
			}
			return hlpOleDateFromSystemType(&st,dtDest);
		break;
		case 'D': // days
			dtDest = dt + (double)n;
			return TRUE;
		break;
		case 'h': // hours
			dtDest = dt + ((long)n * 3600L) / 86400.;
			return TRUE;
		break;
		case 'm': // minute
			dtDest = dt + ((long)n * 60L) / 86400.;
			return TRUE;
		break;
		case 's': // second
			dtDest = dt + ((long)n / 86400.);
			return TRUE;
		break;
	}
	return FALSE;
}
// dt2 - dt1
BOOL hlpOleDateDiff(char chInterval,DATE dt1,DATE dt2,int& nResult) {
	SYSTEMTIME	st1;
	SYSTEMTIME	st2;
	int		i;
	switch (chInterval) {
		case 'Y': // Years
			if (hlpOleDateToSystemType(dt1, st1) && hlpOleDateToSystemType(dt2, st2)) {
				nResult = (int)st2.wYear - (int)st1.wYear;
				return TRUE;
			}
		break;
		case 'M': // months
			if (hlpOleDateToSystemType(dt1, st1) && hlpOleDateToSystemType(dt2, st2)) {
				i = ((int)st2.wYear - (int)st1.wYear) * 12; // years
				nResult = i + ((int)st2.wMonth - (int)st1.wMonth);
				return TRUE;
			}
		break;
		case 'D': // days
			nResult = (int)(dt2 - dt1);
			return TRUE;
		break;
		case 'h': // hours
			nResult = (int)(((dt2 - dt1) * 86400.) / 3600L);
			return TRUE;
		break;
		case 'm': // minute
			nResult = (int)(((dt2 - dt1) * 86400.) / 60L);
			return TRUE;
		break;
		case 's': // second
			nResult = (int)((dt2 - dt1) * 86400.);
			return TRUE;
		break;
	}
	return FALSE;
}

#ifdef OLEDATECONV_HELPERS_PARSERS
	BOOL ODC_ParseDateTime(LPCSTR szTime,SYSTEMTIME& stDest) {
		char _l[32];
		ZeroMemory(&stDest,sizeof(SYSTEMTIME));
		int n = sscanf(szTime,"%4hu-%2hu-%2hu%10[ \t]%2hu:%2hu:%2hu",&stDest.wYear,&stDest.wMonth,&stDest.wDay,_l,&stDest.wHour,&stDest.wMinute,&stDest.wSecond);
		if (n < 3) {
			ZeroMemory(&stDest,sizeof(SYSTEMTIME));
			// Try time only
			n = sscanf(szTime,"%2hu:%2hu:%2hu",&stDest.wHour,&stDest.wMinute,&stDest.wSecond);
			if (n < 2) {
				return FALSE;
			}
		}
		return TRUE;
	}
#endif // OLEDATECONV_HELPERS_PARSERS