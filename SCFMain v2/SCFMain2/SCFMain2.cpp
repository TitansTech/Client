// Archivo DLL principal.

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include < stdlib.h >
#include < vcclr.h >
#include "SCFMain2.h" 
#include "iostream"
#include "windows.h"
#include "Utils.h"
#include "Packets.h"
#include "Externs.h"
#include "EngineConnection.h"
#include "cTitanShop.h"
#include "cMuTab.h"

using namespace std;
using namespace System::Diagnostics;
using namespace SCFMain2;

ENGINE eng;

void OpenShop(void * lpParam)
{
	tShop::Open();
}
void OpenShopThread(void * lpParam)
{
	_beginthread( OpenShop, 0, NULL  );
	Sleep(1000);
	while(Opened)
	{
		Sleep(1000);
	}
	tShop::Close();
}

void OpenTab(void * lpParam)
{
	tMuTab ^tab = gcnew tMuTab();
	tab->SetData();
	tab->ShowDialog();
}

void OpenTabThread(void * lpParam)
{
	if(cTabOpened == 0)
	{
		_beginthread( OpenTab, 0, NULL  );
		while(true)
		{
			HWND MyWin = FindWindow(0,"TitanTab");
			if( MyWin > 0)
			{
				RECT rect; 
				GetWindowRect(MyWin, &rect); 
				SetWindowPos(MyWin, 
				HWND_TOPMOST, 
				rect.left, 
				rect.top, 
				rect.right - rect.left, 
				rect.bottom - rect.top, 
				SWP_SHOWWINDOW);
				break;
			}
			Sleep(1000);
		}
	}
}

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
}

extern "C" __declspec(dllexport) BOOL GET_VShopClose(SDHP_OPENVSHOP * lpMsg)
{
	Opened = 0;
	return 1;
}

extern "C" __declspec(dllexport) void GET_VShopInfo(SDHP_SENDSVSHOP * lpMsg)
{
	tShop::LoadMaxs(lpMsg->mExc,lpMsg->mOpt,lpMsg->mLevel,lpMsg->mLuck,lpMsg->mSkill,lpMsg->mHarmony);
	tShop::LoadValues(lpMsg->pLevel,lpMsg->pOpt,lpMsg->pExc,lpMsg->pLuck,lpMsg->pSkill,lpMsg->pHarmony);
}

extern "C" __declspec(dllexport) BOOL GET_VShopShow(SDHP_OPENVSHOP * lpMsg)
{
	if(lpMsg->Open == 0)
	{
		Opened = 0;
	}else
	{
		if(Opened == 0)
		{
			tShop::vipMoney = lpMsg->VipMoney;
			_beginthread( OpenShopThread, 0, NULL  );
		}
	}
	return TRUE;
}

extern "C" __declspec(dllexport) void GET_OpenMuTab()
{
	_beginthread( OpenTabThread, 0, NULL  );
}

extern "C" __declspec(dllexport) BOOL GET_CloseMuTab()
{
	cTabOpened = 0;
	return 1;
}

extern "C"  __declspec(dllexport) void GET_MarryInfo(SDHP_RECVMARRY * lpMsg)
{
	RecvMarryInfo(lpMsg->Name,lpMsg->Divorce,lpMsg->ForceDivorce,lpMsg->TraceCost,lpMsg->Map,lpMsg->Xpos1,lpMsg->Xpos2,lpMsg->Ypos1,lpMsg->Ypos2);
}

extern "C" __declspec(dllexport) void GET_WebInfo(char * web1, char * web2)
{
	tShop::LoadWebs(gcnew String(web1),gcnew String(web2));
}


extern "C" __declspec(dllexport) bool Init ()
{	
	Opened = 0;
	cTabOpened = 0;
	return (eng.LoadEngine("TitanAddOn.dll"));
}


void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] =0xC6;		// Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
}
void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
{
	lpBuf[0] =0xC6;	// Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}