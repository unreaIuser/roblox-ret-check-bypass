#include <Windows.h>
#include <iostream>

#include "lol.hpp"
#include "sigscan.h"
#include "encrypt.h"

/*
	Roblox ret_check bypass
	Credits: Ilkay & Roka (reworking) & M3m0ryH4cker#7089 <3

	Use this for your retarded roblox pasta if you want.
	The function is now inlined so you can't use it anymore.
*/

void Disable_Ret(DWORD Address, int RetNum)
{
	DWORD Function = Address;
	for (int i = 0; i < RetNum; Function++)
	{
		char AddressOPCode = *(char*)Function;
		if (AddressOPCode == 0x72) /* Checks if the address is a JB. */
		{
			char AddressSecondOPCode = *(char*)(Function + 0x12);
			if (AddressSecondOPCode == 0x72)
			{
				WriteProcessMemory(GetCurrentProcess(), *(LPVOID*)&Function, "\xEB", 1, NULL);
				i++;
			}
		}
	}
}

namespace ret_check
{
	// ret_check typedef for casting int sub_xxxxx.
	using ret_check_def = int(*)();

	// Get base address, this is an internal dll so we just use GetModuleHandleA.
	uintptr_t base = reinterpret_cast<uintptr_t>(SAFE_CALL(GetModuleHandleA)((nullptr))); // Using SAFE_CALL because i'm a black coton farmer :pray:

	// Ret_check address offset.
	uintptr_t ret_check(0x133337);
}

namespace SDK
{
	// Simple variable that will resolve the theory of niggeron invented by albert niggaton in 1508.
	const auto ret_check = reinterpret_cast<ret_check::ret_check_def>(ret_check::base + ret_check::ret_check);
}

auto final_scene()->int
{
	printf(_("[+] ret_check: 0x%x"), SDK::ret_check);
	printf(_("[+] hook: 0x%x"), hook_ret_check);
}

auto hook_ret_check()->int
{
	DWORD retcheck;
	ret_check::ret_check = retcheck;

	// :troll:
	printf(_("[+] ret_check minhook function\n"));
	printf(_("[~] bypassing ret_check\n"));

	Disable_Ret(retcheck, 0); // Disabling Ret_Check

	// returning false = undetected ultra high quality bypass (i'm a dunk nigger)
	return 0;
}

/* Hooking ret_check using an external hook because my parents left me when i was kid + they adopted me. */
void hook(__int64 addr, __int64 func, __int64* orig)
{
	// Use your own hook (;
}

auto init()->void
{
	if (!SAFE_CALL(GetModuleHandleA)(_(".dll")))
	{
		// Make sure Roblox is opened with Steam overlay.
		printf(_("[-] dirty.dll not loaded.")); // too bad
		return;
	}

	// Sigscanning Steam DXGI PResentScene.
	uintptr_t XboxGameBar_PresentScene = sig_scan(_(".dll"), _("01 ?? ?? 33 ?? 77"));

	if (XboxGameBar_PresentScene)
	{
		hook(XboxGameBar_PresentScene, (__int64)hook_ret_check, (__int64*)&SDK::ret_check);
		printf(_("[+] Hooked XboxGameBar_PresentScene %p"), XboxGameBar_PresentScene);
	}

	else { printf(_("[-] XboxGameBar_PresentScene couldn't be hooked, too bad nigga")); }

	printf(_("[~] bypassed ret_check\n")); // 100% real and approved by real federal entities.

}

bool __stdcall DllMain(HMODULE dll_module, DWORD reason_for_calling, LPVOID reserved)
{
	// unreferencing those useless nigget modules
	UNREFERENCED_PARAMETER(dll_module);
	UNREFERENCED_PARAMETER(reserved);

	if (reason_for_calling == 1)
	{
		// Calling our init function.
		init();
	}

	return TRUE;
}
