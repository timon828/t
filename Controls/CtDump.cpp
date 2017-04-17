#include "stdafx.h"
#include "CtDump.h"
#include <strsafe.h>
#pragma warning(disable : 4996)

// tDump�� ���� �Ķ����
static TCHAR			g_szDumpPreFixName[MAX_PATH] = { 0, };
static TCHAR			g_szDumpPath[MAX_PATH_TDUMP] = { 0, };
static DWORD			g_dwDumpCapacityBytes = DEFAULT_DUMP_CAPACITY;
static MINIDUMP_TYPE	g_nMiniDumpType = MiniDumpNormal;
static pfnCbOnCrash		g_pfnCallback = NULL;
static LPVOID			g_pUserData = NULL;

CtDump::~CtDump()
{

}

CtDump::CtDump(IN LPCTSTR lpszDumpPreFixName/*=NULL*/, IN MINIDUMP_TYPE nMiniDumpType/*=MiniDumpNormal*/, IN DWORD dwDumpCapacityBytes/*=DEFAULT_DUMP_CAPACITY*/, IN LPCTSTR lpszDumpPath/*=NULL*/, IN pfnCbOnCrash pfnCallback/*=NULL*/, IN LPVOID lpUserData/*=NULL*/)
{
	RegisterExceptionFilter(lpszDumpPreFixName, nMiniDumpType, dwDumpCapacityBytes, lpszDumpPath, pfnCallback, lpUserData);
}

LONG CtDump::CbTopLevelExceptionFilter(struct _EXCEPTION_POINTERS *pExceptionInfo)
{
	LONG							lRtnValue = EXCEPTION_CONTINUE_SEARCH;
	HANDLE							hFile = INVALID_HANDLE_VALUE;
	BOOL							bRtnValue = FALSE;
	TCHAR							szPath[MAX_PATH_TDUMP] = { 0, };
	HMODULE							hDll = NULL;
	LPFN_MinuDumpWriteDump			pfn = NULL;
	SYSTEMTIME						stTime = { 0, };
	_MINIDUMP_EXCEPTION_INFORMATION	stExceptInfo = { 0, };

	// Dump Path�� �������� �ʴ´ٸ�, Pass
	if (INVALID_FILE_ATTRIBUTES == ::GetFileAttributes(g_szDumpPath))
	{
		// �α׵� ������ �ʵ��� �Ѵ�.
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// Callback ��� �Ǿ� ������ �켱 ȣ���Ѵ�.
	if (NULL != g_pfnCallback)
	{
		if (FALSE == (*g_pfnCallback)(g_pUserData))
		{
			WriteLogFile(g_szDumpPath, TEXT(""), &stTime, g_szDumpPreFixName, FALSE);
			lRtnValue = EXCEPTION_CONTINUE_SEARCH;
			goto FINAL;
		}
	}

	// ����, MiniDumpType�� -1 �̶��,... ����
	if ((MINIDUMP_TYPE)-1 == g_nMiniDumpType)
	{
		WriteLogFile(g_szDumpPath, TEXT(""), &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// DbgHelp.dll�� �ε��Ѵ�.
	hDll = CtDump::LoadLibrary_DbgHelp();
	if (NULL == hDll)
	{
		WriteLogFile(g_szDumpPath, TEXT(""), &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// DbgHelp.dll::MinuDumpWriteDump(...)�� ���Ѵ�.
	pfn = (LPFN_MinuDumpWriteDump)::GetProcAddress(hDll, "MiniDumpWriteDump");
	if (NULL == pfn)
	{
		WriteLogFile(g_szDumpPath, TEXT(""), &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// Dump ���� �̸��� ���Ѵ�.
	if (FALSE == CtDump::GetDumpFileFullPathName(g_szDumpPath, g_szDumpPreFixName, szPath, MAX_PATH_TDUMP, &stTime))
	{
		::GetLocalTime(&stTime);
		WriteLogFile(g_szDumpPath, TEXT(""), &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// Dump ������ Create �Ѵ�.
	hFile = ::CreateFile(szPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		WriteLogFile(g_szDumpPath, szPath, &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// ���� ������ ���� ���� �ʱ�ȭ
	stExceptInfo.ThreadId = ::GetCurrentThreadId();
	stExceptInfo.ExceptionPointers = pExceptionInfo;
	stExceptInfo.ClientPointers = NULL;

	// Dump File ���� manage�Ͽ� ���ϵ��� �����Ѵ�.
	if (FALSE == CtDump::ManageCapacity(g_szDumpPath, g_szDumpPreFixName, g_dwDumpCapacityBytes))
	{
		WriteLogFile(g_szDumpPath, szPath, &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
		goto FINAL;
	}

	// Dump ����
	bRtnValue = (*pfn)(::GetCurrentProcess(), ::GetCurrentProcessId(), hFile, MiniDumpNormal, &stExceptInfo, NULL, NULL);
	if (TRUE == bRtnValue)
	{
		WriteLogFile(g_szDumpPath, szPath, &stTime, g_szDumpPreFixName, TRUE);
		// EXCEPTION_EXECUTE_HANDLER ���� �ϸ�,
		// drwtsn32.exe�� ���� ����Ÿ� ���� ������ ���� �ʴ´�.
		// lRtnValue = EXCEPTION_EXECUTE_HANDLER;
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
	}
	else
	{
		WriteLogFile(g_szDumpPath, szPath, &stTime, g_szDumpPreFixName, FALSE);
		lRtnValue = EXCEPTION_CONTINUE_SEARCH;
	}

FINAL:

	if (INVALID_HANDLE_VALUE != hFile)
	{
		::CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;
		pfn = NULL;
	}

	if (NULL != hDll)
	{
		::FreeLibrary(hDll);
		hDll = NULL;
		pfn = NULL;
	}

	return lRtnValue;
}

VOID CtDump::SetMiniDumpTypeWhenExist(IN LPCTSTR lpszRegKeyPath, IN LPCTSTR lpszValueName)
{
	HKEY	hKey = NULL;
	LONG	lRtnValue = 0;
	DWORD	dwType = 0;
	DWORD	dwCbSize = 0;
	DWORD	dwValue = 0;

	if ((NULL == lpszRegKeyPath) || (NULL == lpszValueName))
	{
		goto FINAL;
	}

	lRtnValue = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpszRegKeyPath, 0, KEY_READ, &hKey);
	if (ERROR_SUCCESS != lRtnValue)
	{
		goto FINAL;
	}

	dwType = REG_DWORD;
	dwCbSize = sizeof(dwValue);
	lRtnValue = ::RegQueryValueEx(hKey, lpszValueName, NULL, &dwType, (LPBYTE)&dwValue, &dwCbSize);
	if (ERROR_SUCCESS != lRtnValue)
	{
		goto FINAL;
	}

	g_nMiniDumpType = (MINIDUMP_TYPE)dwValue;

FINAL:
	if (NULL != hKey)
	{
		::RegCloseKey(hKey);
		hKey = NULL;
	}
}

VOID CtDump::WriteLogFile(IN LPCTSTR lpszPath, IN LPCTSTR lpszDumpFileFullPathName, IN PSYSTEMTIME pstTimeOccur, IN LPCTSTR lpszDumpPrefixName, IN BOOL bWriteDumpSuccess)
{
	TCHAR szLogPath[MAX_PATH_TDUMP] = { 0, };
	TCHAR szSection[MAX_PATH] = { 0, };
	TCHAR szTmp[MAX_PATH] = { 0, };

	if ((NULL == lpszPath) || (NULL == lpszDumpFileFullPathName) || (NULL == pstTimeOccur) || (NULL == lpszDumpPrefixName))
	{
		return;
	}

	StringCchPrintf(szLogPath, MAX_PATH_TDUMP, TEXT("%s\\CrashDmp.log"), lpszPath);
	StringCchPrintf(szSection, MAX_PATH, TEXT("%.4d%.2d%.2d_%.2d%.2d%.2d%.3d"), pstTimeOccur->wYear, pstTimeOccur->wMonth, pstTimeOccur->wDay, pstTimeOccur->wHour, pstTimeOccur->wMinute, pstTimeOccur->wSecond, pstTimeOccur->wMilliseconds);

	::WritePrivateProfileString(szSection, TEXT("Prefix"), lpszDumpPrefixName, szLogPath);
	::WritePrivateProfileString(szSection, TEXT("DumpPath"), lpszDumpFileFullPathName, szLogPath);

	StringCchPrintf(szTmp, MAX_PATH, TEXT("%d"), ::GetCurrentProcessId());
	::WritePrivateProfileString(szSection, TEXT("ProcessId"), szTmp, szLogPath);

	::GetModuleFileName(NULL, szTmp, MAX_PATH);
	::WritePrivateProfileString(szSection, TEXT("CrashModulePath"), szTmp, szLogPath);

	if (TRUE == bWriteDumpSuccess)
		::WritePrivateProfileString(szSection, TEXT("SuccessWriteDump"), TEXT("yes"), szLogPath);
	else
		::WritePrivateProfileString(szSection, TEXT("SuccessWriteDump"), TEXT("no"), szLogPath);
}

BOOL CtDump::RegisterExceptionFilter(IN LPCTSTR lpszDumpPreFixName/*=NULL*/, IN MINIDUMP_TYPE nMiniDumpType/*=MiniDumpNormal*/, IN DWORD dwDumpCapacityBytes/*=DEFAULT_DUMP_CAPACITY*/, IN LPCTSTR lpszDumpPath/*=NULL*/, IN pfnCbOnCrash pfnCallback/*=NULL*/, IN LPVOID lpUserData/*=NULL*/)
{
	BOOL	bRtnValue = TRUE;
	DWORD	dwRtnValue = 0;

	// �Ķ���͵鸦 �����Ѵ�.
	if (NULL != lpszDumpPreFixName)
		StringCchCopy(g_szDumpPreFixName, MAX_PATH, lpszDumpPreFixName);
	else
		GetDefaultDumpPreFixName(g_szDumpPreFixName, MAX_PATH);

	if (DEFAULT_DUMP_CAPACITY != dwDumpCapacityBytes)
		g_dwDumpCapacityBytes = dwDumpCapacityBytes;

	if (NULL != lpszDumpPath)
		StringCchCopy(g_szDumpPath, MAX_PATH_TDUMP, lpszDumpPath);
	else
	{
		// NULL --> Default Path ( <.exe�� ModulePath>\Dump )
		dwRtnValue = CtDump::GetDefaultModuleDumpPath(g_szDumpPath, MAX_PATH_TDUMP);
		if (ERROR_SUCCESS != dwRtnValue)
		{
			bRtnValue = FALSE;
			goto FINAL;
		}
	}

	g_nMiniDumpType = nMiniDumpType;
	g_pfnCallback = pfnCallback;
	g_pUserData = lpUserData;

	// Exception Filter�� ����Ѵ�.
	::SetUnhandledExceptionFilter(CtDump::CbTopLevelExceptionFilter);

	bRtnValue = TRUE;

FINAL:
	return bRtnValue;
}

BOOL CtDump::GetDumpFileFullPathName(IN LPCTSTR lpszPath, IN LPCTSTR lpszDumpPreFixName, OUT LPTSTR lpszDumpFileFullPathName, IN DWORD dwCchDumpFileFullPathName, OUT PSYSTEMTIME pstTime)
{
	BOOL bRtnValue = TRUE;

	if ((NULL == lpszPath) ||
		(NULL == lpszDumpPreFixName) ||
		(NULL == lpszDumpFileFullPathName) ||
		(NULL == pstTime))
	{
		bRtnValue = FALSE;
		goto FINAL;
	}

	::GetLocalTime(pstTime);
	StringCchPrintf(lpszDumpFileFullPathName, dwCchDumpFileFullPathName,
		TEXT("%s\\%s_%.4d%.2d%.2d%.2d%.2d%.2d.dmp"),
		lpszPath,
		lpszDumpPreFixName,
		pstTime->wYear,
		pstTime->wMonth,
		pstTime->wDay,
		pstTime->wHour,
		pstTime->wMinute,
		pstTime->wSecond);
	bRtnValue = TRUE;
FINAL:
	return bRtnValue;
}

DWORD CtDump::GetFilesSize(IN LPCTSTR lpszFindFileName, OUT LPTSTR lpszEarlyFileName, IN DWORD dwCchEarlyFileName)
{
	HANDLE			hFind = INVALID_HANDLE_VALUE;
	DWORD			dwTotalBytes = 0;
	WIN32_FIND_DATA	FindFileData = { 0, };

	dwTotalBytes = 0;

	if ((NULL == lpszFindFileName) || (NULL == lpszEarlyFileName))
	{
		goto FINAL;
	}

	ZeroMemory(lpszEarlyFileName, sizeof(TCHAR) * dwCchEarlyFileName);

	// Enum File �Ѵ�.
	hFind = ::FindFirstFile(lpszFindFileName, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		dwTotalBytes = 0;
		goto FINAL;
	}

	if (TEXT('.') != FindFileData.cFileName[0])
	{
		dwTotalBytes += FindFileData.nFileSizeLow;
		StringCchCopy(lpszEarlyFileName, dwCchEarlyFileName, FindFileData.cFileName);
	}

	while (FindNextFile(hFind, &FindFileData) != 0)
	{
		if (TEXT('.') == FindFileData.cFileName[0])
			continue;

		// ���� ũ�⸦ ��� ���� ������.
		// (���� nFileHighSize�� 0�̰���?)
		dwTotalBytes += FindFileData.nFileSizeLow;

		if (TEXT('\0') == lpszEarlyFileName[0])
		{
			StringCchCopy(lpszEarlyFileName, dwCchEarlyFileName, FindFileData.cFileName);
			continue;
		}

		if (0 < _tcscmp(lpszEarlyFileName, FindFileData.cFileName))
			StringCchCopy(lpszEarlyFileName, dwCchEarlyFileName, FindFileData.cFileName);
	}

FINAL:

	if (INVALID_HANDLE_VALUE != hFind)
	{
		::FindClose(hFind);
		hFind = INVALID_HANDLE_VALUE;
	}

	return dwTotalBytes;
}

BOOL CtDump::ManageCapacity(IN LPCTSTR lpszPath, IN LPCTSTR lpszDumpPreFixName, IN DWORD dwDumpCapacityBytes)
{
	INT		i = 0;
	BOOL	bRtnValue = FALSE;
	DWORD	dwCbFileSize = 0;
	TCHAR	szFileName[MAX_PATH_TDUMP] = { 0, };
	TCHAR	szDelFileName[MAX_PATH_TDUMP] = { 0, };
	TCHAR	szEarlyFileName[MAX_PATH_TDUMP] = { 0, };

	if ((NULL == lpszPath) || (NULL == lpszDumpPreFixName))
	{
		bRtnValue = FALSE;
		goto FINAL;
	}

	// Path�� �����Ѵ�.
	StringCchPrintf(szFileName, MAX_PATH_TDUMP, TEXT("%s\\%s_*.dmp"), lpszPath, lpszDumpPreFixName);

	// �Ѳ����� 32���� ���������� ������ �� �ִ�.
	for (i = 0; i<MAX_DEL_TRY_MANAGE; i++)
	{
		dwCbFileSize = CtDump::GetFilesSize(szFileName, szEarlyFileName, MAX_PATH_TDUMP);
		if (dwCbFileSize < g_dwDumpCapacityBytes)
			break;

		// �����Ѵ�.
		StringCchPrintf(szDelFileName, MAX_PATH_TDUMP, TEXT("%s\\%s"), g_szDumpPath, szEarlyFileName);
		::DeleteFile(szDelFileName);
	}
	bRtnValue = TRUE;
FINAL:
	return bRtnValue;
}

HMODULE CtDump::LoadLibrary_DbgHelp(VOID)
{
	HMODULE	hDLL = NULL;
	TCHAR	szDbgHelp[MAX_PATH_TDUMP] = { 0, };
	LPTSTR	lpszFound = NULL;

	if (0 != ::GetModuleFileName(NULL, szDbgHelp, MAX_PATH_TDUMP))
	{
		// .exe�� Path�� DbgHelp.dll�� �ִٸ�, �̰��� LoadLibrary �Ѵ�.
		lpszFound = _tcsrchr(szDbgHelp, TEXT('\\'));
		if ((NULL != lpszFound) && (szDbgHelp < lpszFound))
		{
			*lpszFound = TEXT('\0');
			StringCchCat(szDbgHelp, MAX_PATH_TDUMP, TEXT("\\DbgHelp.dll"));

			hDLL = ::LoadLibrary(szDbgHelp);
			if (NULL != hDLL)
			{
				// success!
				goto FINAL;
			}
		}
	}

	// System32 ������ ���� dbghelp.dll�� LoadLibrary �Ѵ�.
	hDLL = CtDump::LoadLibraryFromSystem(TEXT("DbgHelp.dll"));

FINAL:
	return hDLL;
}

HMODULE CtDump::LoadLibraryFromSystem(IN LPCTSTR lpFileName)
{
	if (NULL == lpFileName)
		return NULL;

	if (0 == lpFileName[0])
		return NULL;

	const int BUF_SIZ = 4096;

	LPTSTR lpszSysDir = NULL;
	UINT nNeedSize = GetSystemDirectory(NULL, 0);
	lpszSysDir = (LPTSTR)malloc((nNeedSize + 1) * sizeof(TCHAR));
	if (NULL == lpszSysDir)
		return NULL;

	if (0 == GetSystemDirectory(lpszSysDir, nNeedSize + 1)) 
	{
		free(lpszSysDir);
		lpszSysDir = NULL;
		return NULL;
	}

	TCHAR szFullPath[BUF_SIZ] = { 0 };
	_tcsncpy(szFullPath, lpszSysDir, BUF_SIZ);
	_tcsncat(szFullPath, _T("\\"), BUF_SIZ);
	_tcsncat(szFullPath, lpFileName, BUF_SIZ);

	HMODULE hModule = LoadLibraryEx(szFullPath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

	free(lpszSysDir);
	lpszSysDir = NULL;

	if (hModule)
		return hModule;

	return NULL;
}

DWORD CtDump::GetDefaultModuleDumpPath(OUT LPTSTR lpszPath, IN DWORD dwCchPath)
{
	DWORD	dwRtnValue = ERROR_SUCCESS;
	LPTSTR	lpszFound = NULL;

	if (NULL == lpszPath)
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		goto FINAL;
	}

	// Clean Up
	ZeroMemory(lpszPath, sizeof(TCHAR) * dwCchPath);

	if (0 == ::GetModuleFileName(NULL, lpszPath, dwCchPath))
	{
		// Module Handle ���ϴµ� ����
		dwRtnValue = ::GetLastError();
		goto FINAL;
	}

	lpszFound = _tcsrchr(lpszPath, TEXT('\\'));
	if (NULL == lpszFound)
	{
		// Path ���� \�� ����?
		dwRtnValue = ERROR_PATH_NOT_FOUND;
		goto FINAL;
	}

	if (lpszFound <= lpszPath)
	{
		// Path ���� \�� ����?
		dwRtnValue = ERROR_PATH_NOT_FOUND;
		goto FINAL;
	}
	// Null ���ڷ� �������
	*lpszFound = TEXT('\0');
	// Dump ������ �߰�����
	StringCchCat(lpszPath, dwCchPath, TEXT("\\Dump"));
	// ������� �Դٸ�, ����
	dwRtnValue = ERROR_SUCCESS;
FINAL:
	return dwRtnValue;
}

DWORD CtDump::GetDefaultDumpPreFixName(OUT LPTSTR lpszDefaultDumpPreFixName, IN DWORD dwCchDefaultDumpPreFixName)
{
	DWORD	dwRtnValue = ERROR_SUCCESS;
	TCHAR	szModulePath[MAX_PATH_TDUMP] = { 0, };
	LPTSTR	lpszFound = NULL;
	LPTSTR	lpszIter = NULL;
	BOOL	bFound = FALSE;
	INT		i = 0;

	// ���� .exe�� �����̸� (Ȯ���� ����)�� dumpfile�� prefix�� �����Ѵ�.
	if (NULL == lpszDefaultDumpPreFixName)
	{
		dwRtnValue = ERROR_INVALID_PARAMETER;
		goto FINAL;
	}

	ZeroMemory(lpszDefaultDumpPreFixName, sizeof(TCHAR)*dwCchDefaultDumpPreFixName);

	if (0 == ::GetModuleFileName(NULL, szModulePath, MAX_PATH_TDUMP))
	{
		dwRtnValue = ::GetLastError();
		StringCchPrintf(lpszDefaultDumpPreFixName, dwCchDefaultDumpPreFixName, TEXT("UnKnown"));
		goto FINAL;
	}

	lpszFound = _tcsrchr(szModulePath, TEXT('\\'));
	if ((NULL == lpszFound) || (lpszFound <= szModulePath) || (TEXT('\0') == *(lpszFound + 1)))
	{
		dwRtnValue = ERROR_PATH_NOT_FOUND;
		StringCchPrintf(lpszDefaultDumpPreFixName, dwCchDefaultDumpPreFixName, TEXT("UnKnown"));
		goto FINAL;
	}

	// Ȯ���ڸ� �����Ѵ�.
	bFound = FALSE;
	for (i = 0; i<MAX_PATH; i++)
	{
		if (TEXT('\0') == *(lpszFound + i))
			break;

		if (TEXT('.') == *(lpszFound + i))
		{
			bFound = TRUE;
			*(lpszFound + i) = TEXT('\0');
			break;
		}
	}

	if (FALSE == bFound)
	{
		dwRtnValue = ERROR_PATH_NOT_FOUND;
		StringCchPrintf(lpszDefaultDumpPreFixName, dwCchDefaultDumpPreFixName, TEXT("UnKnown"));
		goto FINAL;
	}

	dwRtnValue = ERROR_SUCCESS;
	StringCchCopy(lpszDefaultDumpPreFixName, dwCchDefaultDumpPreFixName, lpszFound + 1);

FINAL:
	return dwRtnValue;
}