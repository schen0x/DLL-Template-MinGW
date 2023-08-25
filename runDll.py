from ctypes import *
myDll = ctypes.WinDLL (".\\dist\\myDll.dll")
myDll.test();

