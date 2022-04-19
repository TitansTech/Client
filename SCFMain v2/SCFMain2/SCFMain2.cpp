// Archivo DLL principal.

#include "stdafx.h"
#include <stdio.h>
#include "SCFMain2.h" 
#include "Offsets.h" 
#include "Headers/AntiHack.h" 

#include "SCFMain2.h"
#include "iostream"
#include "windows.h"
#include "MuTabControl.h"
#include "SCFVShop.h"
#include "EngineConnection.h"

using namespace std;
using namespace System::Diagnostics;
ENGINE eng;

BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hInstance = hModule;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


bool ENGINE::LoadEngine(LPSTR EngineDLL)
{
	if(this->hDllHinstance)
	{
		FreeLibrary(this->hDllHinstance);
	}

	this->hDllHinstance=LoadLibrary(EngineDLL);

	if ( this->hDllHinstance == NULL )
	{
		return false;
	}

	this->eDataSend = (void  (*)(BYTE,LPBYTE))GetProcAddress(this->hDllHinstance, "GUICore");
	return true;
}

extern "C" __declspec(dllexport) void LauncherExec()
{
	Process^ App = gcnew Process();
	App->StartInfo->FileName = "SCFLauncher.exe";
	App->StartInfo->WorkingDirectory = Application::StartupPath;

	App->Start();
	//App->WaitForExit();
}

extern "C" __declspec(dllexport) char * SET_VShopBuy(SDHP_BUYSVSHOP * lpMsg)
{
	return ((char *)lpMsg);
}

extern "C" __declspec(dllexport) BOOL GET_VShopClose(SDHP_OPENVSHOP * lpMsg)
{
	if(VShop.Open == true)
	{
		VShop.NeedClose = true;
		VShop.SendClose();
		return 1;
	}
	return 0;
}

extern "C" __declspec(dllexport) void GET_VShopInfo(SDHP_SENDSVSHOP * lpMsg)
{
	VShop.SetInfo(lpMsg);
}

extern "C" __declspec(dllexport) BOOL GET_VShopShow(SDHP_OPENVSHOP * lpMsg)
{
	return(VShop.Show(lpMsg));
}

extern "C" __declspec(dllexport) bool Init ()
{	
	CantOpenTwise();
	VShop.Init();
	return (eng.LoadEngine("XMu.dll"));
}

extern "C" __declspec(dllexport) void gWall_AntiHack ()
{
	_beginthread( gWall__Thread, 0, NULL  );
}