#include "../stdafx.h"
#include "../Headers/AntiHack.h"
#include <tlhelp32.h>

using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;

void CantOpenTwise()
{	
	String^ processName = Process::GetCurrentProcess()->ProcessName;
	array<Process^>^instances = Process::GetProcessesByName(processName);
	if (instances->Length > 1)
	{
		exit(1);
	}
}

int ProcID = 0;

char CHEATNAME[HACKCOUNT][30] =
{
	"!xSpeed",
	"WildProxy",
	"Permit",
	"WPE Pro",
	"WPE",
	"WPEPro",
	"Catastrophe",
	"T Search",
	"UoPilot",
	"MJB Perfect DL Bot",
	"HahaMu",
	"Speed Changer",
	"Speed Hack",
	"Xelerator",
	"AutoBuff",
	"HastyMu",
	"MuPie",
	"Lipsum",
	"FunnyZhyper",
	"Auto_Buff",
	"Minimizer",
	"Jewel Drop",
	"Chaos Bot",
	"Bot MG-DK-ELF",
	"Comercio Bot",
	"Auto Buff",
	"GodMode",
	"Godlike",
	"SpotHack",
	"Cheater",
	"MU Utilidades",
	"ZhyperMu",
	"MuBot",
	"DupeHack",
	"Dupe",
	"Super Bot",
	"Auto Combo",
	"Packet"
};

void gWall__Run3(void * lpParam)
{
	POINT p;
	HWND DebugerFound = 0;
	int KilledDebugers = 0;

	for ( int qy = 0 ; qy < 100 ; qy++)
	{
		for ( int qx = 0 ; qx < 100 ; qx++)
		{
			p.x = qx * 20;
			p.y = qy * 20;
			
			DebugerFound = WindowFromPoint(p);

			char t[255];
			GetWindowText( DebugerFound , t , 255);

			if ( strstr( t , "Shadow") || strstr( t , "Olly") || strstr( t , "DebuG") || strstr( t , "CPu - main") )
			{
				LONG a = GetWindowLong ( DebugerFound , GWL_HWNDPARENT );
				
				while ( a > 0 )
				{
					if ( a > 0 ) DebugerFound = (HWND) a;
					a = GetWindowLong ( DebugerFound , GWL_HWNDPARENT );
				}

				LockWindowUpdate( DebugerFound );

				TOKEN_PRIVILEGES tp;
				HANDLE hToken;
				if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
				{
					LookupPrivilegeValue(0, SE_SHUTDOWN_NAME, &tp.Privileges[0].Luid);
					tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
					tp.PrivilegeCount = 1;
					AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
					
					//!!! UNCOMMENT THIS LINE WHEN YOU COMPILE FINAL VERSION !!!
					CloseHandle(hToken);
				}
				KilledDebugers++;				
			}
		}
	}

	if ( KilledDebugers > 0 ) ExitProcess ( 0 );
	_endthread();
}

void gWall__Thread(void * lpParam)
{
	_beginthread( gWall__Run3, 0, NULL  );
	_beginthread( gWall__Run2, 0, NULL  );
	while(true)
	{
		Sleep(1000);
		Process^ currentProcess = Process::GetCurrentProcess();
		if((INT)currentProcess->MainWindowHandle != 0)
		{
			ProcID = currentProcess->Id;
			HWND hwnd = (HWND)currentProcess->MainWindowHandle.ToInt32();
			BringWindowToTop(hwnd);	
			//SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE);
			SwitchToThisWindow(hwnd,1);
			break;
		}
	}
	_beginthread( gWall__Run1, 0, NULL  );
	_endthread();
}

void gWall__Run1(void * lpParam)
{
	while(true)
	{
		Sleep(1000);
		DWORD ProcID2;
		GetWindowThreadProcessId (GetForegroundWindow(), &ProcID2 );
		if(ProcID2 != ProcID)
			exit(1);
	}
}

bool CheckHackEngine(String ^ pName)
{
	for(int i=0;i<HACKCOUNT;i++)
	{
		String^ CheatName = gcnew String(CHEATNAME[i]);
		if(pName->Contains(CheatName->ToUpper()))
			return true;
	}
	return false;
}

bool CheckCheat(String ^ str)
{
	String^ strUp = str->ToUpper();
	if ((strUp->Contains("CHEAT") == true) || (strUp->Contains("HACK")) || (CheckHackEngine(strUp)))
	{
		return true;
	}
	return false;
}
void gWall__Run2(void * lpParam)
{
	for each(Process^ App in Process::GetProcesses())
	{
		//Sleep(1);
		try
		{
			if(CheckCheat(App->MainModule->FileVersionInfo->InternalName))
			{
				App->Kill();
				exit(1);
			}
		}catch(...)
		{};
		try
		{
			if(CheckCheat(App->MainModule->FileVersionInfo->Comments))
			{
				App->Kill();
				exit(1);
			}
		}catch(...)
		{};
		try
		{
			if(CheckCheat(App->MainModule->FileVersionInfo->FileDescription))
			{
				App->Kill();
				exit(1);
			}
		}catch(...)
		{};
		try
		{
			if(CheckCheat(App->MainModule->FileVersionInfo->ProductName))
			{
				App->Kill();
				exit(1);
			}
		}catch(...)
		{};
		try
		{
			if(CheckCheat(App->ProcessName))
			{
				App->Kill();
				exit(1);
			}
		}catch(...)
		{};							
	}
	_endthread();
}

