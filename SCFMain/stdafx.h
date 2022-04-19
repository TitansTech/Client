#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <math.h>
#include <mmsystem.h>
#include <math.h>
#include <stdio.h>
#include <process.h>
#include <shellapi.h>

//#define _WIN32_WINNT    0x0500
static HINSTANCE hInstance;


//--------------------------
// WinLicense Protection
//--------------------------
// 0 : Dissabled
// 1 : Enabled
#define WL_PROTECT	1

#if (WL_PROTECT==1)
#include "Protect\\WinLicenseSDK.h"
#pragma comment (lib,"Protect\\WinlicenseSDK.lib")
#endif

#pragma warning(disable:4244 4005 4996 4005 4102)