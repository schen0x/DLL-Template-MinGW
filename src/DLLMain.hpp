#pragma once
#ifndef UNICODE
#define UNICODE
#define UNICODE_WAS_UNDEFINED
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define STATUS_SUCCESS 0x0

#ifdef UNICODE_WAS_UNDEFINED
#undef UNICODE
#endif
