#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "SCFMain.h" 
#include "Offsets.h" 
#include "Headers/Map.h" 
#include "Headers/AntiHack.h" 
#include "GUIConnect.h" 

char *mainVersion   = (char*)(VERSION_IN_MAIN); 
char *mainSerial    = (char*)(SERIAL_IN_MAIN); 

char* GetTokenString(char * str)
{
	char seps[2] = " ";
	return strtok(str, seps);
}


int GetTokenNumber(char * str)
{
	char seps[2] = " ";
	char * szToken = strtok(str, seps);

	if ( szToken != NULL )
	{
		return atoi(szToken);
	}

	return 0;
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

bool FileExists(char * name)
{
	if(CreateFile(name,0,0,0,OPEN_EXISTING,0,0) == INVALID_HANDLE_VALUE)
		return false;
	return true;
}
void ReplaceBytes(DWORD Address, BYTE ReplaceTo, int HowMany)
{
	for(int i=0;i<HowMany;i++)
		*(BYTE*)(Address+i) = ReplaceTo;
}
__declspec() void HookForMiniMap();

void ProtocolCore(unsigned char protoNum,unsigned char* aRecv,int aLen,int aIndex)
{
	switch(protoNum)
	{
		//case 0xD3:
		case 0xF1:
		case 0xF3:
		{
			gui.SEND_VShopClose((SDHP_OPENVSHOP *)aRecv);
		}break;
		case 0xFA:
		{
			switch(aRecv[3])
			{
				case 0x00:
				{
					gui.SEND_VShopInfo((SDHP_SENDSVSHOP *)aRecv);
					//VShop.SetInfo((SDHP_SENDSVSHOP *)aRecv);
				}break;
				case 0x01:
				{
					gui.SEND_VShopShow((SDHP_OPENVSHOP *)aRecv);
					//VShop.Show((SDHP_OPENVSHOP *)aRecv);
				}break;
			}
			return;
		}break;
	}
	MainProtocolCore(protoNum,aRecv,aLen,aIndex);
}


void DataSend(LPBYTE Bufffer,int aLen)
{
	_asm
	{
		Mov Edi,DataSend_addr
		Push aLen
		Push Bufffer
		MOV ECX,DWORD PTR DS:[DataSendThisCall_addr]
		Call Edi
	}
}

extern "C" __declspec(dllexport) bool Init ()
{		
	gui.LoadGUI("XMuGUIEngine.dll");

	LPWSTR *szArglist;
	int argc = 0;
	szArglist = CommandLineToArgvW(GetCommandLineW(), &argc);
	if( NULL == szArglist )
	{
		//exit(1);
	}
	else 					
	{
		char cmdLine[512]={0};
		wsprintf(cmdLine,"%ws", szArglist[1]);
		if(strcmp(cmdLine,"run"))
		{
			gui.LauncherExec();
			exit(1);
		}
	}	

	DWORD dwOld1;
	LPVOID lpAddress1;
	lpAddress1  = (LPVOID) (IMAGE_BASE_EXE + BASE_OF_CODE_EXE); // 
	char FilePath[] = ".\\SCFMain.ini";
	
	if(gui.SEND_Init() == false)
		exit(1);
	
	if ( VirtualProtect (lpAddress1,HEADER_text_RSize+HEADER_rdata_RSize,PAGE_EXECUTE_READWRITE,&dwOld1 )	)
	{ 

#if (WL_PROTECT==1)

	int MyCheckVar;
	VM_START_WITHLEVEL(15)
		CHECK_PROTECTION(MyCheckVar, 0x95450743)  
		if (MyCheckVar != 0x95450743)
		{			
			exit(1);
		}
	VM_END
#endif
		*(DWORD*)(ProtocolCore_addr+1) = (DWORD)&ProtocolCore - (ProtocolCore_addr+5);

		SetIP(1);
		if(GetPrivateProfileInt("Config", "LoadAntiHack",0, FilePath) == 1)
			Monitor_Start();

		if(GetPrivateProfileInt("Config", "LoadNewItems",0, FilePath) == 1)
			_beginthread( ItemInit, 0, NULL  );
			//ItemInit();

		if(GetPrivateProfileInt("Config", "Load3DCamera",0, FilePath) == 1)
			Main3DInit();

		if(GetPrivateProfileInt("Config", "LoadMiniMap",0, FilePath) == 1)
			MiniMapInit();

		if(GetPrivateProfileInt("Config", "LoadgWall",0, FilePath) == 1)
			gui.SEND_gWall();

		int pSize  = GetPrivateProfileInt("FileSize", "PlayerBMD",0, FilePath);
		int iSize  = GetPrivateProfileInt("FileSize", "ItemBMD",0, FilePath);
		int iSkill = GetPrivateProfileInt("FileSize", "SkillBMD",0, FilePath);

		if(pSize != 0)
			CheckFileSize("Data/Player/player.bmd",pSize);
		if(iSize != 0)
			CheckFileSize("Data/Local/item.bmd",iSize);
		if(iSkill != 0)
			CheckFileSize("Data/Local/skill.bmd",iSkill);

		char sBuf[100]={0};
		GetPrivateProfileString("Version","ClientExeSerial","osmdh4syh30adaup",sBuf,17,FilePath);
		memcpy(mainSerial,sBuf,16);
		GetPrivateProfileString("Version","ClientExeVersion","2296=",sBuf,6,FilePath);
		memcpy(mainVersion,sBuf,5);


		//*(BYTE*)(NewOrbsFix_addr-2) = 0xEB;
		//*(BYTE*)(NewOrbsFix_addr-1) = 0x60;
		//ReplaceBytes(NewOrbsFix_addr,0x90,65);
		
		//ReplaceBytes(MasterLevelShow_Addr,0x90,5);
		//ReplaceBytes(MasterLevelShow_Addr+8,0x90,2);

		//--Change Map of Select Character
		//*(BYTE*)(SelectCharacter_Addr1+1)=0x4E;
		//*(DWORD*)(SelectCharacter_Addr2+6)=0x0000004E;
		//Change Map of Select Character--

		//VirtualProtect (lpAddress1,HEADER_text_RSize+HEADER_rdata_RSize,PAGE_EXECUTE_READ,&dwOld1 );
	}
	return true;
}