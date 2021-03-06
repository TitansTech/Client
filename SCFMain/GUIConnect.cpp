#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "TitanAddOn.h" 
#include "Offsets.h" 
#include "GUIConnect.h" 

GUI gui;

extern "C" __declspec(dllexport) void GUICore(BYTE Flag, LPBYTE Answer) 
{
	switch(Flag)
	{
		case 0:
		{
			int Size=0;
			if ( Answer[0] == 0xC1 || Answer[0] == 0xC3 || Answer[0] == 0xC6)
			{
				Size = Answer[1];
			}else if ( Answer[0] == 0xC2 || Answer[0] == 0xC4 )
			{
				unsigned char * pBuf;
				pBuf = &Answer[0];
				Size = pBuf[1] * 256;
				Size |= pBuf[2];
			}
			
			DataSend(Answer,Size);
		}break;

		case 1://Launcher Reply
		{
			if(Answer[0] == 0)
				exit(0);
				//exit(1);
		}break;
	}
}


void GUI::LoadGUI(LPSTR GuiDLL)
{
#if (WL_PROTECT==1)
	CODEREPLACE_START
#endif

	if(this->hDllHinstance)
	{
		FreeLibrary(this->hDllHinstance);
	}

	this->hDllHinstance=LoadLibrary(GuiDLL);

	if ( this->hDllHinstance == NULL )
	{
		exit(0);
		//exit(1);
	}
	//this->GET_VShopBuy = (char *  (*)(SDHP_BUYSVSHOP*))GetProcAddress(this->hDllHinstance, "SET_VShopBuy"); 
	this->SEND_VShopInfo = (void  (*)(SDHP_SENDSVSHOP*))GetProcAddress(this->hDllHinstance, "GET_VShopInfo"); 
	this->SEND_VShopShow = (BOOL  (*)(SDHP_OPENVSHOP*))GetProcAddress(this->hDllHinstance, "GET_VShopShow");  
	this->SEND_VShopClose = (BOOL  (*)(SDHP_OPENVSHOP*))GetProcAddress(this->hDllHinstance, "GET_VShopClose"); 
	this->SEND_MarryInfo = (void  (*)(SDHP_RECVMARRY*))GetProcAddress(this->hDllHinstance, "GET_MarryInfo");
	this->SEND_OpenMuTab = (void  (*)())GetProcAddress(this->hDllHinstance, "GET_OpenMuTab");  
	this->SEND_CloseMuTab = (BOOL  (*)())GetProcAddress(this->hDllHinstance, "GET_CloseMuTab");  
	this->SEND_Init = (bool  (*)())GetProcAddress(this->hDllHinstance, "Init"); 
	this->LauncherExec = (void  (*)())GetProcAddress(this->hDllHinstance, "LauncherExec"); 	
	this->SEND_WebInfo = (void  (*)(char*,char*))GetProcAddress(this->hDllHinstance, "GET_WebInfo"); 

#if (WL_PROTECT==1)
	CODEREPLACE_END
#endif
}