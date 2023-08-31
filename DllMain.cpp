#include "DllMain.hpp"
#include <stdint.h>
#include <windows.h>

extern "C" __declspec(dllexport) BOOL
    test(uint64_t RCX, uint64_t RDX, uint64_t R8, uint64_t R9) {
  MessageBox(NULL, L"test()", L" Success ", 0);
  wchar_t buffer[40] = {};
  wsprintfW(buffer, L"P1:%lx P2:%lx P3:%lx P4:%lx", RCX, RDX, R8, R9);
  MessageBox(NULL, buffer, L" Success ", 0);

  return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
  case DLL_PROCESS_ATTACH:
    MessageBox(NULL, L"Case1 (P_Attach)", L"Success", 0);
  case DLL_PROCESS_DETACH:
    MessageBox(NULL, L"Case0 (P_Detach)", L"Success", 0);
    break;
  case DLL_THREAD_ATTACH:
    MessageBox(NULL, L"Case2 (T_Attach)", L"Success", 0);
    break;
  case DLL_THREAD_DETACH:
    MessageBox(NULL, L"Case3 (T_Detach)", L"Success", 0);
    break;
  case 4:
    MessageBox(NULL, L"Case4", L"Success", 0);
    break;
  case 5:
    MessageBox(NULL, L"Case5", L"Success", 0);
    test(5, 5, 5, 5);
    break;
  }
  return TRUE;
}
