#include <Windows.h>
#include <iostream>

#include "lol.hpp"
#include "sigscan.h"
#include "encrypt.h"

/* 
	Roblox ret_check bypass
	Credits: Ilkay & Roka (reworking) <3

	Use this for your retarded roblox pasta if you want.
	The function is now inlined so you can't use it anymore.
*/

namespace ret_check
{
	// ret_check typedef for casting int sub_xxxxx.
	using ret_check_def = int(*)();

	// Get base address, this is an internal dll so we just use GetModuleHandleA.
	uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));

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
	// :troll:
	printf(_("[+] ret_check minhook function\n"));
	printf(_("[~] bypassing ret_check\n"));

	// returning true because i'm a dunk nigger.
	return TRUE;
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