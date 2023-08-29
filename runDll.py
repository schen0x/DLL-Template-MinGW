import ctypes
myDll = ctypes.WinDLL(".\\dist\\myDll.dll");
myDll.test();

