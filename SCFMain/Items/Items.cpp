#include "../stdafx.h"
#include <string.h>
#include "../SCFMain.h" 
#include "../Offsets.h" 
#include "../stdafx.h" 

struct CItems
{
	char ModelName[64];
	BYTE Glow;
	BYTE Type;
	BYTE MaxLevel;
};

int WingCount=0;
int WingID[65] = {0};
CItems CItem[9058];
int CItem_Start[16];

static char ItemTypeText[18][50] =
{
	"SCF_SWORD",
	"SCF_AXE",
	"SCF_MACE",
	"SCF_SPEAR",
	"SCF_BOW",
	"SCF_STAFF",
	"SCF_SHIELD",
	"SCF_HELM",
	"SCF_ARMOR",
	"SCF_PANTS",
	"SCF_GLOVES",
	"SCF_BOOTS",
	"SCF_MISC1",
	"SCF_MISC2",
	"SCF_MISC3",
	"SCF_SCROLL",
	"SCF_WINGS",
	"SCF_JEWEL"
};

int InitItems2(char * FilePath)
{
	for(int i = 0; i < 16; i++)
	{
		for(int j=0;j<MaxIndex;j++)
		{
			CItem[ITEMGETPOS(i,j)].Glow = 0xFF;
			CItem[ITEMGETPOS(i,j)].MaxLevel = 13;
		}
	}	
#if (WL_PROTECT==1) 
	int CheckCode;   
	VM_START_WITHLEVEL(14)
	CHECK_CODE_INTEGRITY(CheckCode, 0x95450743)  	 
	if (CheckCode == 0x95450743)
	{	
#endif
	for(int i = 0; i < 16; i++)
	{
		char etiqueta[50];
		wsprintf(etiqueta,"Items %d", i);
		CItem_Start[i] = GetPrivateProfileInt(etiqueta, "CustomIndexStart",-1, FilePath) ;
		if(CItem_Start[i] >= 0)
		{
			for(int j=CItem_Start[i];j<MaxIndex;j++)
			{
				char etiquetaindexGlow[50];
				wsprintf(etiquetaindexGlow,"Index_%d-Glow", j);
				char etiquetaindexType[50];
				wsprintf(etiquetaindexType,"Index_%d-Type", j);
				char etiquetaindexMLevel[50];
				wsprintf(etiquetaindexMLevel,"Index_%d-MaxLevel", j);

				CItem[ITEMGETPOS(i,j)].Type = GetPrivateProfileInt(etiqueta, etiquetaindexType,0, FilePath) ;
				CItem[ITEMGETPOS(i,j)].MaxLevel = GetPrivateProfileInt(etiqueta, etiquetaindexMLevel,0, FilePath) ;
				switch(CItem[ITEMGETPOS(i,j)].Type)
				{
					case 0:
					{
Comun:
						strcpy(CItem[ITEMGETPOS(i,j)].ModelName, ItemTypeText[i]);
					}break;
					case 1:
					{
						if(i==12)
						{
							WingCount++;
							strcpy(CItem[ITEMGETPOS(i,j)].ModelName, ItemTypeText[16]);
							WingID[WingCount] = ITEMGETPOS(i,j);
						}else
						{
							goto Comun;
						}
					}break;
					case 2:
					{
						strcpy(CItem[ITEMGETPOS(i,j)].ModelName, ItemTypeText[17]);
					}break;
				}
				CItem[ITEMGETPOS(i,j)].Glow = GetPrivateProfileInt(etiqueta, etiquetaindexGlow,0, FilePath) ;

			}
		}
	}	
	
#if (WL_PROTECT==1) 
	}
	VM_END
#endif
	return 1;
}

int LoadModel2()
{
	for(int i = 0; i < 16; i++)
	{
		if(CItem_Start[i] >= 0)
		{
			for(int j=CItem_Start[i];j<MaxIndex;j++)
			{
				char etiqueta[2048];
				wsprintf(etiqueta,".\\Data\\Item\\%s%02d.bmd", CItem[ITEMGETPOS(i,j)].ModelName,j);
				if(FileExists(etiqueta) == true)
				{
					LoadBMD ( ITEMGETPOS(i,j), "Data\\Item\\" , CItem[ITEMGETPOS(i,j)].ModelName ,  j );
					LoadTEX ( ITEMGETPOS(i,j) , "Item\\" , 0x2901 , 0x2600 , 1);
				}else
				{
					CItem[ITEMGETPOS(i,j)].Glow = 0xFF;
				}
			}
		}
	}
	return 1;
}


BYTE Glow(int ItemID)
{
	return CItem[ItemID].Glow;
}

void _declspec(naked) Shine () 
{
	__asm
	{
		CMP DWORD PTR SS:[EBP+0x08],0x0B7A
		JNZ EXTRAITEMSCASES
		MOV DWORD PTR SS:[EBP-0x04],0x24
Exit:
		MOV EDI, ShineExit
		JMP EDI

EXTRAITEMSCASES:	

		MOV ECX,DWORD PTR SS:[EBP+0x08]
		PUSH ECX
		CALL Glow
		CMP AL,-1
		JE Gold
		MOV BYTE PTR SS:[EBP-0x04],AL
		JMP Exit
Gold:
		MOV EDI, ShineReturn
		JMP EDI
	}
}




int decode ( int adr , int len )
{
	// EXAMPLE DECODE YOUR SMD FILES
	/*
	char * x = (char*) adr;
	for ( int a = 0 ; a < len ; a++ )
	{
		*(x+a) = *(x+a) ^ 192;
	}*/

	return 1;
}



// MAIN ITEMS LOADING PROCEDURE
// REWRITENN FROM MAIN.EXE TO HOOK NEW ITEMS
__declspec( naked ) int LoadS ( char * hpath , int typ ) 
{
	__asm
	{
		PUSH    EBP
		MOV     EBP, ESP

		CMP     hpath , 0
		JNZ     SHORT ispath
		XOR     AL, AL
		JMP     end
ispath:	
		PUSH    LoadSAddr1
		MOV     EAX, hpath
		PUSH    EAX
		MOV		EDI , LoadSAddr2
		CALL    EDI
		ADD     ESP, 8
		MOV     DWORD PTR DS:[LoadSAddr3], EAX
		CMP     DWORD PTR DS:[LoadSAddr3], 0
		JNZ     isopen
		XOR     AL, AL
		JMP     end
isopen:	
		// READ ----------------------------
		MOV		EDI , LoadSAddr4 // read file
		CALL    EDI
		CALL    EDI
		// ---------------------------------


		// DECODE & OPTIONAL UNPACK --------
		MOV	EAX , DWORD PTR DS:[LoadSAddr3]
		MOV	ECX , DWORD PTR [EAX+4]
		MOV	EDX , DWORD PTR [EAX+8]

		PUSH	ECX // DATA LENGTH
		PUSH	EDX // DATA ADDRESS
		CALL	decode
		ADD		ESP , 8
		// ---------------------------------


		CMP     typ , 0
		JNZ     is1
		MOV		EDI , LoadSAddr5
		CALL    EDI
		MOV     CL, BYTE PTR SS:[EBP+10]
		PUSH    ECX
		MOV		EDI , LoadSAddr6
		CALL    EDI
		ADD     ESP, 4
is1:	
		CMP     typ , 1
		JNZ     isnot
		MOV		EDI , LoadSAddr7
		CALL    EDI
isnot:	
		MOV     EDX, DWORD PTR DS:[LoadSAddr3]
		PUSH    EDX
		MOV		EDI , LoadSAddr8
		CALL    EDI
		ADD     ESP, 4

		MOV     AL, 1
end:	
		POP     EBP
		RETN
	}
}

WORD IsJewel(WORD Item)
{
	int x=0;
	int y=0;
	if((Item >= (6144)) && (Item < 6656))
	{
		if(CItem_Start[12] >= 0)
		{
			x = 12;
			y = Item-6144;
		}
	}else if((Item >= (6656)) && (Item < 7168))
	{
		if(CItem_Start[13] >= 0)		
		{
			x = 13;
			y = Item-6656;
		}
	}else if((Item >= (7168)) && (Item < 7680))
	{
		if(CItem_Start[14] >= 0)		
		{
			x = 14;
			y = Item-7168;
		}
	}
	if(x>0 && y>0)
	{
		if((CItem[ITEMGETPOS(x,y)].Glow != 0xFF) && (CItem[ITEMGETPOS(x,y)].Type == 2))
		{
			return CItem[ITEMGETPOS(x,y)].MaxLevel;
		}
	}
	return 0;
}


void _declspec(naked) JewelHook1_AllowToUse () 
{
	DWORD Item;
	__asm
	{
		MOV Item,EAX
	}

	if(Item != 0x1C0E && IsJewel(Item) == 0)
	{
		goto Exit;
	}

	__asm
	{
		MOV EDI,JewelHook1_AllowToUse_Addr_Return
		JMP EDI
	}

Exit:
	__asm
	{
		MOV EDI,JewelHook1_AllowToUse_Addr_Exit
		JMP EDI
	}
}


void _declspec(naked) JewelHook2__LevelItem () 
{
	DWORD Item;
	DWORD Level;

	__asm
	{
		MOV Item,EAX
		MOV EDX,DWORD PTR SS:[EBP-4]
		MOV Level,EDX
	}

	if(Item == 0x1C0E )
	{
		if(Level >= 0 && Level <= 8)
		{
			goto Allow;
		}
	}

	WORD MLevel;
	MLevel = IsJewel(Item);
	if(MLevel > 0 )
	{
		if(Level >= 0 && Level <= MLevel)
		{
			goto Allow;
		}
	}

	__asm
	{
		MOV EDI,JewelHook2__LevelItem_Addr_Return
		JMP EDI
	}

Allow:
	__asm
	{
		MOV EDI,JewelHook2__LevelItem_Addr_Allow
		JMP EDI
	}
}


void _declspec(naked) JewelHook3__AllowToPut () 
{
	DWORD Item;

	__asm
	{
		MOV Item,EDX
	}

	if(Item == 0x1C0E )
	{
		goto Allow;
	}

	if(IsJewel(Item) > 0 )
	{
		goto Allow;
	}

	__asm
	{
		MOV EDI,JewelHook3__AllowToPut_Addr_Return
		JMP EDI
	}

Allow:
	__asm
	{
		MOV EDI,JewelHook3__AllowToPut_Addr_Allow
		JMP EDI
	}
}




void _declspec(naked) JewelHook4__AllowToPutLevel () 
{
	DWORD Item;
	DWORD Level;

	__asm
	{
		MOV Item,ECX
		MOV EDX,DWORD PTR SS:[EBP-0x2C]
		MOV Level,EDX
	}

	if(Item == 0x1C0E )
	{
		if(Level < 9)
		{
			goto Allow;
		}
	}

	WORD MLevel;
	MLevel = IsJewel(Item);

	if(MLevel > 0 )
	{
		if(Level < MLevel)
		{
			goto Allow;
		}
	}

	__asm
	{
		MOV EDI,JewelHook4__AllowToPutLevel_Addr_Return
		JMP EDI
	}

Allow:
	__asm
	{
		MOV EDI,JewelHook4__AllowToPutLevel_Addr_Allow
		JMP EDI
	}
}

void _declspec(naked) JewelHook5__Sound()
{
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x04]
		CMP EDX,0x1C0D
		JE Allow
		PUSH EDX
		CALL IsJewel
		CMP EAX,0
		JG Allow
		MOV EDI,JewelHook5__Sound_Addr_Return
		JMP EDI
Allow:
		MOV EDI,JewelHook5__Sound_Addr_Allow
		JMP EDI
	}
}

int GetWingID(int WingNum)
{
	return WingID[WingNum];
}
void _declspec(naked) Wings () 
{

	__asm
	{

		CMP BYTE PTR SS:[EBP-0x30],0x07
		JE GO
		CMP BYTE PTR SS:[EBP-0x30],0x04
		JE GO2
Out1:
		MOV EDI, WingsReturn
		JMP EDI
GO:
		MOV EDX,DWORD PTR SS:[EBP-0x08]
		MOV WORD PTR DS:[EDX+0x1C0],0x1B8C
Exit:
		MOV EDI, WingsExit
		JMP EDI
GO2:
		MOV EDX,0
WhileStart:
		CMP EDX,WingCount
		JE Out1

		ADD EDX,1
		MOV EAX,DWORD PTR SS:[EBP+0x0C]
		XOR ECX,ECX
		MOV CL,BYTE PTR DS:[EAX+0x10]
		XOR EAX,EAX
		IMUL EAX,EDX,4
		CMP CL,AL
		JE Continue
		XOR EAX,EAX
		MOV AL,AL
		ADD AL,1
		CMP CL,AL
		JE GoldFenrir
		JMP WhileStart

GoldFenrir:
		SUB EAX,1
Continue:
		MOV EDI,EDX
		MOV EDX,EAX
		MOV EAX,DWORD PTR SS:[EBP+0x0C]
		XOR ECX,ECX
		MOV CL,BYTE PTR DS:[EAX+0x10]
		SUB CL,DL
		MOV BYTE PTR DS:[EAX+0x10],CL

		PUSH EDI
		CALL GetWingID
		MOV EDX,DWORD PTR SS:[EBP-0x08]
		MOV WORD PTR DS:[EDX+0x1C0],AX
		JMP Exit
	}
}

int IsWing(WORD Item)
{
	if(CItem_Start[12] >= 0)
	{
		if((Item > (6144+43)) && (Item < 6656))
		{
			int x = 12;
			int y = Item-6144;

			if((CItem[ITEMGETPOS(x,y)].Glow != 0xFF) && (CItem[ITEMGETPOS(x,y)].Type == 1))
			{
				return 1;
			}
		}
	}
	return 0;
}

void _declspec(naked) WingsProperty () 
{
//	__asm
//	{
//		MOV EDI,ECX
//		PUSH CX
//		CALL IsWing
//		CMP EAX,1
//		JE OK
//		MOV ECX,EDI
//		CMP CX,0x1828
//		JLE OK
//		MOV EDI, WingsPropertyReturn
//		JMP EDI
//OK:
//		MOV EDI,WingsPropertyExit
//		JMP EDI
//	}
	WORD ItemID;
	__asm
	{
		CMP CX,0x1828
		JLE OK
		MOV ItemID,CX
	}
	if(IsWing(ItemID) == 1)
	{
		__asm
		{		
OK:
			MOV EDI,WingsPropertyExit
			JMP EDI

		}
	}else
	{
		__asm
		{
			//MOV EAX,EBX
			MOV EDI, WingsPropertyReturn
			JMP EDI
		}
	}
}


void _declspec(naked) LoadDMD () 
{
	//LoadModel ( Items[6].ModelPath , Items[6].ModelName , Items[6].TextureDir , Items[6].Section , Items[6].Id );
	//LoadModel ( Items[7].ModelPath , Items[7].ModelName , Items[7].TextureDir , Items[7].Section , Items[7].Id );
	//LoadModel ( Items[8].ModelPath , Items[8].ModelName , Items[8].TextureDir , Items[8].Section , Items[8].Id );
	LoadModel2();
	__asm
	{
		//MOV		EAX , ASMItemLoad1
		MOV EDX,DWORD PTR DS:[ASMItemLoad1]
		MOV EAX,DWORD PTR DS:[EDX+ASMItemLoad2]
		MOV EDI,ASMItemLoad3
		JMP EDI
	}
}

BOOL IsJewel1(WORD Item)
{
	if((CItem[Item].Glow != 0xFF) && (CItem[Item].Type == 2))
	{
		return 1;
	}
	return 0;
}
BOOL IsWing1(WORD Item)
{
	if(CItem_Start[12] >= 0)
	{
		if((CItem[Item].Glow != 0xFF) && (CItem[Item].Type == 1))
		{
			return 1;
		}
	}
	return 0;
}

void _declspec(naked) Shine__Level()
{
	__asm
	{

		MOV ECX,DWORD PTR SS:[EBP+0x08]
		MOV EDX,DWORD PTR DS:[ECX+0x30]
		PUSH EDX
		CALL IsJewel1
		CMP EAX,1
		JE Jewel
		PUSH EDX
		CALL IsWing1
		CMP EAX,1
		JE Less

		CMP DWORD PTR SS:[EBP-0x08],0x03	//Level
		JL Less
		MOV EDI,Shine__Level_Addr_Return	//Glow
		JMP EDI
Less:
		MOV EDI,Shine__Level_Addr_Less		//No Glow
		JMP EDI

Jewel:
		MOV EDI,Shine__Level_Addr_Jewel		//Glow +10
		JMP EDI
	}
}

void ItemInit(void * lpParam)
//void ItemInit()
{
	InitItems2(".\\SCFMain.ini");

	//LoadDMD

	ReplaceBytes(LoadDMDHookAddr,0x90,12);
	*(DWORD*)((LoadDMDHookAddr + 1)) = (DWORD)&LoadDMD - (LoadDMDHookAddr+5);
	*(BYTE*)(LoadDMDHookAddr) = 0xE9;

	//Shine

	ReplaceBytes(ShineHookAddr+5,0x90,4);
	*(DWORD*)((ShineHookAddr + 1)) = (DWORD)&Shine - (ShineHookAddr+5);
	*(BYTE*)(ShineHookAddr) = 0xE9;
	
	ReplaceBytes(Shine__LevelHookAddr,0x90,6);
	*(DWORD*)((Shine__LevelHookAddr + 1)) = (DWORD)&Shine__Level - (Shine__LevelHookAddr+5);
	*(BYTE*)(Shine__LevelHookAddr) = 0xE9;

	//Wings

	ReplaceBytes(WingsHookAddr+5,0x90,1);
	*(DWORD*)((WingsHookAddr + 1)) = (DWORD)&Wings - (WingsHookAddr+5);
	*(BYTE*)(WingsHookAddr) = 0xE9;

	*(DWORD*)((WingsPropertyHookAddr + 1)) = (DWORD)&WingsProperty - (WingsPropertyHookAddr+5);
	*(BYTE*)(WingsPropertyHookAddr) = 0xE9;

	//Jewels

	*(DWORD*)((JewelHook1_AllowToUseHookAddr + 1)) = (DWORD)&JewelHook1_AllowToUse - (JewelHook1_AllowToUseHookAddr+5);
	*(BYTE*)(JewelHook1_AllowToUseHookAddr) = 0xE9;

	*(DWORD*)((JewelHook2__LevelItemHookAddr + 1)) = (DWORD)&JewelHook2__LevelItem - (JewelHook2__LevelItemHookAddr+5);
	*(BYTE*)(JewelHook2__LevelItemHookAddr) = 0xE9;

	*(DWORD*)((JewelHook3__AllowToPutHookAddr + 1)) = (DWORD)&JewelHook3__AllowToPut - (JewelHook3__AllowToPutHookAddr+5);
	*(BYTE*)(JewelHook3__AllowToPutHookAddr) = 0xE9;

	*(DWORD*)((JewelHook4__AllowToPutLevelHookAddr + 1)) = (DWORD)&JewelHook4__AllowToPutLevel - (JewelHook4__AllowToPutLevelHookAddr+5);
	*(BYTE*)(JewelHook4__AllowToPutLevelHookAddr) = 0xE9;

	ReplaceBytes(JewelHook5__SoundHookAddr,0x90,7);
	*(DWORD*)((JewelHook5__SoundHookAddr + 1)) = (DWORD)&JewelHook5__Sound - (JewelHook5__SoundHookAddr+5);
	*(BYTE*)(JewelHook5__SoundHookAddr) = 0xE9;

	//LoadS

	_asm
	{
		pushad

			mov eax,LoadSHookAddr1+1
			mov ecx,offset LoadS
			sub ecx,LoadSHookAddr1+5
			mov [eax],ecx

			mov eax,LoadSHookAddr2+1
			mov ecx,offset LoadS
			sub ecx,LoadSHookAddr2+5
			mov [eax],ecx

		popad
	}
	_endthread();
}