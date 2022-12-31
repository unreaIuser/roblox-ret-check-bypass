# Roblox Ret_Check Bypass

RetCheck is basically a Roblox Check that prevents you from doing basic things like allocating console etc, and it's detecting most of basic dlls functions without a working bypass, if you try to for example Allocate a console with Ret_Check, your game will crash, and sometimes gives an "Unexpected client behiavour" error.

<br>

Feel free to use this to bypass ret_check.

<br>

This is a simple Ret_Check hooking that i reworked, credits: ilkay#4710 (the guy with who i'm currently making a roblox exec)
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
