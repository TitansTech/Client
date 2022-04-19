
#include "../stdafx.h" 
#include "../Offsets.h" 
#include "../TitanAddOn.h" 
#include "../Headers/AntiHack.h"
#include <tlhelp32.h>

char *mainip    = (char*)(IP_IN_MAIN); 

void CheckIP()
{
	char ip [20] = {0};
	wsprintf(ip,"%s",mainip);
	if(!stricmp(ip,config.ip))
	{
		return;
	}
	exit(0);
	//exit(1);
}

void SetIP()
{
	memcpy(mainip,config.ip,20);
}

void SystemProcessesScan(void * lpParam)
{
	while(true)
	{	
		CheckIP();
		Sleep(60000);
	}
	_endthread();
}

void Monitor_Start()
{
#if (WL_PROTECT==1) 
	VM_START_WITHLEVEL(13)
#endif
	_beginthread( SystemProcessesScan, 0, NULL  );
#if (WL_PROTECT==1) 
	VM_END
#endif
}