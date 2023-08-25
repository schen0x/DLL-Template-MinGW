# DLL-Template-MinGW
- x64 DLL Template
- C++
- Cross compile with MinGW

## Usage

- Cross compile the dll (Linux)

```sh
make
```

- Test the dll (Windows, python3)

```bat
python3 runDll.py
```

- On success, 2 MessageBox should pop
  - [dynamic-link-library-best-practices, MSDOC](https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-best-practices)
  - Because on first time load, DllMain is called. The `test()` function is called in the python script manually

## DLL Loading

- [dllmain, Windows App Development, MSDN](https://learn.microsoft.com/en-us/windows/win32/dlls/dllmain)
- The DllMain is optional, if exists, it is called "When the system starts or terminates a process or thread, it calls the entry-point function for each loaded DLL using the first thread of the process"; it is also called when "LoadLibrary" and "FreeLibrary" are called.

- TL;DR, the DLL Loading flow: DLLOptionalHeader."Entry Point" (DllMainCRTStartup(optional) -> ... -> DLLMain) -> finish setup
- Normally, the "AddressOfEntryPoint" (@"PE\0\0"+0x28 == 4("PE\0\0") + 20(COFF Header) + 16(OptionalHeader->AddressOfEntryPoint)) of the dll should be called by us, with "DLL_PROCESS_ATTACH", for once during the setup

```c++
// BOOL APIENTRY DllEntryPoint (
// HINSTANCE hInst,		/* [IN] Library instance handle. */
// DWORD reason,		/* [IN] Reason this function is being called. */
// LPVOID reserved      // [IN] NULL for dynamic loads, non-NULL for static loads
// );

DllEntryPoint(dllInMemBaseAddr, DLL_PROCESS_ATTACH, NULL);
```


