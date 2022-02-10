#include <windows.h>

typedef unsigned int (*RtlAdjustPrivilegeType)(int Privilege, bool Enable, bool CurrentThread, bool *Enabled);
typedef unsigned int (*NtRaiseHardErrorType)(unsigned int ErrorStatus, unsigned int NumberOfParameters, unsigned int UnicodeStringParameterMask, int *Parameters, unsigned int ValidResponseOption, unsigned int *Response);

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	HMODULE ntdll = LoadLibraryA("ntdll.dll");
	if (ntdll != NULL) {
		RtlAdjustPrivilegeType RtlAdjustPrivilege = (RtlAdjustPrivilegeType)GetProcAddress(ntdll, "RtlAdjustPrivilege");
		NtRaiseHardErrorType NtRaiseHardError = (NtRaiseHardErrorType)GetProcAddress(ntdll, "NtRaiseHardError");
		if (RtlAdjustPrivilege != NULL && NtRaiseHardError != NULL) {
			bool Enabled = false;
			RtlAdjustPrivilege(19, true, false, &Enabled);
			unsigned int Response = 0;
			NtRaiseHardError(3222357268, 0, 0, (int *)0, 6, &Response);
			FreeLibrary(ntdll);
			return 0;
		} else {
			FreeLibrary(ntdll);
			return 2;
		}
	} else {
		return 1;
	}
}
