# Roblox Ret_Check Bypass

RetCheck is basically a Roblox Check that prevents you from doing basic things like allocating console etc, and it's detecting most of basic dlls functions without a working bypass, if you try to for example Allocate a console with Ret_Check, your game will crash, and sometimes gives an "Unexpected client behiavour" error.

This is a simple Ret_Check hooking that i reworked, credits: ilkay#4710 (the guy with who i'm currently making a roblox exec)

<br>

Feel free to use this to bypass ret_check.

<br>


```cpp
// M3m0ryH4cker#7089
void Unprotect(DWORD Address, int RetNum)
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
```


<br>
```cpp
// Here we are returning Ret_Check false for an UHQ+ bypass (Top G)

auto hook_ret_check()->int
{
	// :troll:
	printf(_("[+] ret_check minhook function\n"));
	printf(_("[~] bypassing ret_check\n"));

	// returning false = undetected ultra high quality bypass (i'm a dunk nigger)
	return 0;
}
```
