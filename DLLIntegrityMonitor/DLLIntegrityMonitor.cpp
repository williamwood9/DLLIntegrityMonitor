#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

int main() {
	// Take a snapshot of all processes currently running
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE) {
		std::wcerr << L"CreateToolhelp32Snapshot failed. Error: " << GetLastError() << L"\n";
		return 1;
	}

	PROCESSENTRY32W entry;
	entry.dwSize = sizeof(PROCESSENTRY32W);		// REQUIRED before the first call
	
	if (!Process32FirstW(snapshot, &entry)) {
		std::wcerr << L"Process32FirstW failed. Error: " << GetLastError() << L"\n";
		return 1;
	}

	std::wcout << L"PID\tProcess Name\n";
	do {
		std::wcout << entry.th32ProcessID << L"\t" << entry.szExeFile << L"\n";
	} while (Process32NextW(snapshot, &entry));

	CloseHandle(snapshot);
	return 0;
}

