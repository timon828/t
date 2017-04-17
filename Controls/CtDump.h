#pragma once
#include <dbghelp.h>

//////////////////////////////////////////////////////////////////////////
//
// ��뿹:
//
// #include "CtDump.h"
//
// winmain()
// {
//		...
//		// �뷫 �ʱ⿡...
//		CtDump::RegisterExectionFilter();	// <- �ڵ�� ����
//		..
// }
//
// Ȥ��
//
// CApp theApp;
// ...
// CtDump g_CtDump();	// <- ���� ������ ����
// ..
//
// ==> ����, TestApp.exe���� Crash�� �߻��ϸ�, 
//     (�Ķ���͸� default ������ �� �ڵ�� ���� ����������),
//
//		* TestApp.exe Path�� Dump ������ �ִ� ���, �̴� ������ TestApp_yyyymmddhhmmssmmm.dmp�� �����ȴ�.
//		* TestApp.exe Path�� Dump ������ ���� ���, ������ ������ �ʴ´�.
//		* TestApp_*.dmp�� Total ���� ũ�Ⱑ 1MB�� �Ѿ��, ���� �������� ������ ������ ����� ũ�⸦ �����Ѵ�.
//		* TestApp.exe Path�� Dump ������ CrashDmp.log ���Ͽ� ���� ���׵��� ����Ѵ�.
//		* XP/Vista�� ���, ������ ����ŷε� ������ �ȴ�. (drwtsn32, Problem Reports and Solutions ����)
//
// (�˸�) minidump �����̹Ƿ�, !analyze -v ������ ���� �� �ִ�.
// (�˸�) TestApp.exe�� User�������� ����� �� �����Ƿ�, Dump ������ everyone 777 ������ �ִ°��� ���� ���̴�.
// (�˸�) CtDump �Լ����� Thread Safe ������ ����. ����, .exe ���� �ʱ�ȭ�� �ǵ��� �� �ѹ��� ȣ���ϵ��� �Ѵ�.
// (�˸�) dbghelp.dll�� ����ϴµ�, ���� .exe�� module path ���� system32 path ������ LoadLibrary�� �õ��Ѵ�.
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Parameter :
//
//	CtDump::CtDump(...) / CtDump::RegisterExectionFilter(...)
//	�� Argument�� �����Ѵ�.
//
//	* lpszDumpPreFixName : ���������� �̸��� �����Ѵ�. �������� �ʴ� ���, ���� .exe�� ���ϸ��� �ȴ�.
//		ex) "abc"�� �����ϴ� ���, abc_yyyymmddhhmmssmmm.dmp ���ϸ����� ���� �����ȴ�.
//
//	* nMiniDumpType : ���������� Ÿ�� ����. �⺻���� MiniDumpNormal�̴�.
//		**) Ÿ���� http://msdn.microsoft.com/en-us/library/ms680519(VS.85).aspx ���� �����Ͻÿ�.
//
//	* dwDumpCapacityBytes : PreFixName���� ������� �������ϵ��� ������ ���� ũ��. �⺻���� 1048576(1MB)�̴�.
//		**) ������ ����� ���� ũ�⸦ Ȯ���Ͽ�, �Ѿ�� ��� ���� �������� ���ʷ� ������ ũ�⸦ �����ϰ� �����Ѵ�.
//
//	* lpszDumpPath : ���������� ������ Path. �⺻���� .exe�� Path �Ϻ��� Dump �����̴�.
//		ex) �⺻���� ���, C:\ttt\abc.exe�� C:\ttt\Dump\abc_~~~~.dmp�� ����ȴ�)
//
//	* pfnCallback / pfnUserData : ���������� ����� ���� ȣ����� �� �ִ� callback�� ���. �⺻���� NULL
//		**) callback ȣ��޾� UI�� ��� �� �� �ִ�. FALSE�� �����ϸ� ������ ������ �ʴ´�.
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Tool :
//
//	* CtDump::SetMiniDumpTypeWhenExist(...)
//		**) nMiniDumpType�� ������Ʈ�� ������ �����Ѵ�. (������Ʈ�� ���� �ִ°�츸 �ش�)
//		ex) CtDump::RegisterExectionFilter(..., MiniDumpScanMemory, ...);
//			CtDump::SetMiniDumpTypeWhenExist(TEXT("Sofware\....\Tmp", TEXT("minidumptype"));
//			�� ���, ���� ������Ʈ���� ���� �ִٸ�, MiniDumpScanMemory������ ������Ʈ�� ������ ����ȴ�.
//			����, �ش� ���� (DWORD)-1�� ��쿡��, ������ ������ �ʵ��� ���� ó���Ǿ���.
//
//////////////////////////////////////////////////////////////////////////

// dbghelp.dll::MinuDumpWriteDump(...)�� prototype
typedef BOOL(WINAPI *LPFN_MinuDumpWriteDump)	(HANDLE								hProcess,
	DWORD								dwPid,
	HANDLE								hFile,
	MINIDUMP_TYPE						DumpType,
	PMINIDUMP_EXCEPTION_INFORMATION	ExceptionParam,
	PMINIDUMP_USER_STREAM_INFORMATION	UserStreamParam,
	PMINIDUMP_CALLBACK_INFORMATION		CallbackParam);

// Crash �߻��� ȣ��Ǵ� Callback�� Prototype
// FALSE�� �����ϸ�, ������ ������ �ʴ´�.
typedef BOOL(*pfnCbOnCrash)	(IN LPVOID lpUserData);

// Capacity�� ���� ������ �����ϰ� write dump �ϹǷ�, Total �뷮�� �ִ� (1MB + ������ Dump File ũ��) �� �ɼ� �ִ�.
#define DEFAULT_DUMP_CAPACITY	1048576	// 1MB

// ���� ���� manage�� ����, �Ѳ����� ������ ���� ����
#define MAX_DEL_TRY_MANAGE		32

#define MAX_PATH_TDUMP		1024

class CtDump
{
public:
	CtDump(IN LPCTSTR lpszDumpPreFixName = NULL, IN MINIDUMP_TYPE nMiniDumpType = MiniDumpNormal, IN DWORD dwDumpCapacityBytes = DEFAULT_DUMP_CAPACITY, IN LPCTSTR lpszDumpPath = NULL, IN pfnCbOnCrash pfnCallback = NULL, IN LPVOID lpUserData = NULL);
	virtual ~CtDump();

public:
	static BOOL RegisterExceptionFilter(IN LPCTSTR lpszDumpPreFixName = NULL, IN MINIDUMP_TYPE nMiniDumpType = MiniDumpNormal, IN DWORD dwDumpCapacityBytes = DEFAULT_DUMP_CAPACITY, IN LPCTSTR lpszDumpPath = NULL, IN pfnCbOnCrash pfnCallback = NULL, IN LPVOID lpUserData = NULL);
	static VOID SetMiniDumpTypeWhenExist(IN LPCTSTR lpszRegKeyPath, IN LPCTSTR lpszValueName);

private:
	static LONG WINAPI CbTopLevelExceptionFilter(struct _EXCEPTION_POINTERS *pExceptionInfo);
	static VOID		WriteLogFile(IN LPCTSTR lpszPath, IN LPCTSTR lpszDumpFileFullPathName, IN PSYSTEMTIME pstTimeOccur, IN LPCTSTR lpszDumpPrefixName, IN BOOL bWriteDumpSuccess);

	// Utility
private:
	static DWORD	GetDefaultDumpPreFixName(OUT LPTSTR lpszDefaultDumpPreFixName, IN DWORD dwCchDefaultDumpPreFixName);
	static DWORD	GetDefaultModuleDumpPath(OUT LPTSTR lpszPath, IN DWORD dwCchPath);
	static HMODULE	LoadLibrary_DbgHelp(VOID);
	static HMODULE	LoadLibraryFromSystem(IN LPCTSTR lpFileName);
	static BOOL		ManageCapacity(IN LPCTSTR lpszPath, IN LPCTSTR lpszDumpPreFixName, IN DWORD dwDumpCapacityBytes);
	static BOOL		GetDumpFileFullPathName(IN LPCTSTR lpszPath, IN LPCTSTR lpszDumpPreFixName, OUT LPTSTR lpszDumpFileFullPathName, IN DWORD dwCchDumpFileFullPathName, OUT PSYSTEMTIME pstTime);
	static DWORD	GetFilesSize(IN LPCTSTR lpszFindFileName, OUT LPTSTR lpszEarlyFileName, IN DWORD dwCchEarlyFileName);
};