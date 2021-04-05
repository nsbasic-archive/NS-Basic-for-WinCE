/////////////////////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////////////////////
TCHAR* mywce_GetNextArg( TCHAR* pszArgList, TCHAR szArg[] )
{

	TCHAR*  pszSpace     = NULL;
	TCHAR*  pszTab       = NULL;
	TCHAR*  pszNextArg   = NULL;
	LPTSTR  pszArg       = &szArg[0];
	int     iWhiteCount  = 0;
	bool	bInQuote;

	if ((pszArgList == NULL) || (lstrlen(pszArgList) == 0))
		return (NULL);


	// count white space
	iWhiteCount = 0;
	pszSpace    = &pszArgList[0];
	while ((*pszSpace == (short)' ') || (*pszSpace== (short)'\t'))
	{
		pszSpace++;
		iWhiteCount++;
	}

	//skip the quote, if any
	if(*pszSpace==TEXT('"'))
	{
		bInQuote=true;
		iWhiteCount++;
		pszSpace++;
	}
	else
		bInQuote=false;

	// copy next arg to szArg
	lstrcpy( szArg, &pszArgList[iWhiteCount] );
	pszArg = &szArg[0];

	
	if(bInQuote)
	{
		TCHAR *pszQuote=0;

		pszQuote=_tcschr(szArg,TEXT('"'));
		if(pszQuote)
		{
			*pszQuote=0;
			pszNextArg=pszQuote+1;
		}
		else
			pszNextArg=&szArg[lstrlen(szArg)+1];

	}
	else
	{
		// null-terminate it
		// point pszNextArg at next arg
		pszSpace = _tcschr( szArg, (int)' ' );
		pszTab   = _tcschr( szArg, (int)'\t' );
		if ((pszSpace == NULL) && (pszTab != NULL))
		{
			pszSpace = pszTab;
		}
		else if ((pszSpace != NULL) && (pszTab != NULL))
		{
			if (pszTab < pszSpace)
				pszSpace = pszTab;
		}
		if (pszSpace)
		{
			*pszSpace = 0;
			pszNextArg = pszSpace + 1;
		}
		else
			pszNextArg = &szArg[lstrlen(szArg)+1];
	}
	// check that we have a valid arg
	ASSERT(pszArg);

	// return pointer to beginning of next arg in list
	return (pszNextArg);
}



/////////////////////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////////////////////
int mywce_GetArgCount( TCHAR* pszArgList )
{

	TCHAR*  pszSpace     = NULL;
	TCHAR*  pszTab       = NULL;
	TCHAR*  pszNextArg   = NULL;
	int     iWhiteCount  = 0;
	int     iArgCount    = 0;
	bool	bInQuote;

	
	if ((pszArgList == NULL) || (lstrlen(pszArgList) == 0))
		return (0);

	iArgCount  = 0;
	pszNextArg = pszArgList;
	while (pszNextArg != NULL)
	{
		// gobble/count white space
		iWhiteCount = 0;
		pszSpace    = pszNextArg;
		while ((*pszSpace == (short)' ') || (*pszSpace == (short)'\t'))
		{
			pszSpace++;
			iWhiteCount++;
		}
		//skip the quote, if any
		if(*pszSpace==TEXT('"'))
		{
			bInQuote=true;
			iWhiteCount++;
			pszSpace++;
		}
		else
			bInQuote=false;

		// point pszNextArg past the white space
		pszNextArg = &pszNextArg[iWhiteCount];
		// if its not null, then increment the count
		if (pszNextArg != NULL)
			iArgCount++;

		if(bInQuote)
		{
			TCHAR *pszQuote=0;
			pszQuote = _tcschr(pszNextArg,TEXT('"'));
			if(pszQuote)
				pszNextArg=pszQuote+1;
			else
				break;//done
		}
		else
		{
			// for next iteration, point pszNextArg at next arg
			pszSpace = _tcschr( pszNextArg, (int)' ' );
			pszTab   = _tcschr( pszNextArg, (int)'\t' );
			if ((pszSpace == NULL) && (pszTab != NULL))
			{
				pszSpace = pszTab;
			}
			else if ((pszSpace != NULL) && (pszTab != NULL))
			{
				if (pszTab < pszSpace)
					pszSpace = pszTab;
			}
			if (pszSpace)
				pszNextArg = pszSpace + 1;
			else
				break;  // i.e. we're done
		}
	}

	return (iArgCount);
}
#endif

void CScriptApp::ParseCommandLine(CCommandLineInfo& rCmdInfo)
{

	int iNumFiles=0;

	_tcscpy(gszRealFilename,TEXT(""));
#if defined(_WIN32_WCE)
	int     iArgCount           = mywce_GetArgCount( m_lpCmdLine );
	TCHAR   szTmp[MAX_PATH*2]   = _T("");
	TCHAR*  pszArgList          = m_lpCmdLine;
	LPCTSTR pszParam;
#endif
	{
		//TCHAR szBuf[50];
		//wsprintf(szBuf,L"%i args",iArgCount);
		//MessageBox(0,pszArgList,szBuf,MB_OK);
		if(iArgCount)
			iArgCount--;
	}

#if defined(_WIN32_WCE)
	for (int i = 0; i < iArgCount; i++)
#else
	for (int i = 1; i < __argc; i++)
#endif
	{
#if defined(_WIN32_WCE)
		pszArgList = mywce_GetNextArg( pszArgList, szTmp );

		pszParam = &szTmp[0];
		ASSERT(pszParam);
#else
		LPCTSTR pszParam = __targv[i];
#endif
		BOOL bFlag = FALSE;
#if defined(_WIN32_WCE)
		BOOL bLast = ((i + 1) == iArgCount);
#else
		BOOL bLast = ((i + 1) == __argc);
#endif
		//MessageBox(0,L"PARSE",pszParam,MB_OK);
		if (pszParam[0] == '-' || pszParam[0] == '/')
		{
			// remove flag specifier
			bFlag = TRUE;
			++pszParam;
		}
		if(!bFlag && _tcslen(pszParam)>0) //not a flag
		{	
			iNumFiles++;
			if( iNumFiles==1 && _tcsicmp(pszParam,kMagicVNSBFileName)==0)
			{//we got our "magic" filename from VNSB.  Open it instead of launching it
			 //by setting a flag, and set the path to the full path of the file..
				pszParam=kMagicVNSBFilePath;

				gbSquelchAutoLaunch=true;
				gbShowEditorWindow=true;
			}
			if(iNumFiles>1) //save off the real filename so we can restore it..
				_tcscpy(gszRealFilename,pszParam);
		}
		if(1)//bFlag && _tcslen(pszParam)>0)
		{
			rCmdInfo.ParseParam(pszParam, bFlag, bLast);
		}
	
	}


}