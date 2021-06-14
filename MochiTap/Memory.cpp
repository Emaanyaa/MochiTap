#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "Memory.h"

using namespace std;

//global vars c:
DWORD gameModule = NULL;
DWORD engineModule = NULL;
DWORD clientState = NULL;

HANDLE hProcSnap = NULL;
PROCESSENTRY32 procEntry32;

HANDLE hModuleSnap = NULL;
MODULEENTRY32 modEntry32;

DWORD pID = NULL;

HANDLE processHandle = NULL;

bool getProcess(DWORD procID)
{
	//Entry value gets defined
	procEntry32.dwSize = sizeof(PROCESSENTRY32);

	//takes a current snapshot of the running processes
	hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcSnap == INVALID_HANDLE_VALUE)
	{

		std::cout << "Couldn't find processes in the snapshot :c" << std::endl;
		return false;
	}

	//If there's a next process in the snapshot window
	while (Process32Next(hProcSnap, &procEntry32))
	{

		//String compare
		if ((procID == procEntry32.th32ProcessID) && !strcmp(procEntry32.szExeFile, "csgo.exe"))
		{

			//shows procID and creates handle
			std::cout << "process: " << procEntry32.szExeFile << " ID: " << procEntry32.th32ProcessID << std::endl;
			processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procEntry32.th32ProcessID);
			pID = procEntry32.th32ProcessID;
			if (processHandle == NULL)
			{

				system("Color 4");
				std::cout << "Could not create a handle to the process :c" << std::endl;

			}
			CloseHandle(hProcSnap);
			return true;
		}
	}
	std::cout << "Couldn't find procID =" << procID << std::endl;
	CloseHandle(hProcSnap);
	return false;
}

DWORD getModule(char * moduleName)
{
	return 0;
}

uintptr_t patternScan(char * base, size_t size, char * pattern)
{
	return uintptr_t();
}

DWORD getModule(LPSTR moduleName)
{

	hModuleSnap = INVALID_HANDLE_VALUE;
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);

	if (hModuleSnap == INVALID_HANDLE_VALUE)
	{

		std::cout << " Could not take a snapshot of the process :c" << std::endl;
		CloseHandle(hModuleSnap);
		return 0;

	}

	modEntry32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hModuleSnap, &modEntry32))
	{

		if (!strcmp(moduleName, modEntry32.szModule))
		{
			CloseHandle(hModuleSnap);
			return (DWORD)modEntry32.modBaseAddr;
		}
	}

	while (Module32Next(hModuleSnap, &modEntry32))
	{
		if (!strcmp(moduleName, modEntry32.szModule))
		{
			std::cout << "module: " << modEntry32.szModule << "0x" << std::hex << std::uppercase << (DWORD)modEntry32.modBaseAddr << std::endl;
			CloseHandle(hModuleSnap);
			return (DWORD)modEntry32.modBaseAddr;
		}
	}
	std::cout << "Could not find " << moduleName << " in module snapshot." << std::dec << std::endl;
	CloseHandle(hModuleSnap);
	return false;

}


std::uint32_t find(const char* proc)
{

	auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);

	if (Process32First(snapshot, &pe)) {
		while (Process32Next(snapshot, &pe))
		{

			if (!strcmp(proc, pe.szExeFile)) {
				CloseHandle(snapshot);
				return pe.th32ProcessID;

			}
		}
	}
	CloseHandle(snapshot);
	return 0;
}

DWORD findPattern(HANDLE processHandle, const unsigned char pattern[], const char* mask, const int offset, size_t begin) {
	//pattern in format: unsigned char pattern [] = { 0x90, oxFF, 0xEE };
	//Mask in format : char* mask = "xxx?xxx";
	//Begin default is 0
	//This function searches the signature from the start or at 0x00000000(default) to 0x7FFFFFFF
	const size_t signature_size = strlen(mask);
	const size_t read_size = 4096;
	bool hit = false;

	unsigned char chunk[read_size];

	for (size_t i = begin; i < INT_MAX; i += read_size - signature_size) {
		ReadProcessMemory(processHandle, LPCVOID(i), &chunk, read_size, NULL);

		for (size_t a = 0; a < read_size; a++) {
			hit = true;

			for (size_t j = 0; j < signature_size && hit; j++) {
				if (mask[j] != '?' && chunk[a + j] != pattern[j]) {
					hit = false;
				}
			}

			if (hit) {
				return i + a + offset;
			}
		}
	}

	return NULL;
}