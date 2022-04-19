#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "winVip.h"
#include "offsets.h"
#include "SCFMain2.h"
#include "EngineConnection.h"

using namespace std;
using namespace SCFMain2;
using namespace System::Runtime::InteropServices;

static value class refVShop
{
public:
	static winVip ^vipForm = gcnew winVip();
};

cReadVShop VShop;
//refVShop VShopForm;

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

void cReadVShop::Read(char * FilePath)
{
	if(this->Enabled == 1)
	{
		int Token;
		int Count=0;
		int tCount[16]={0};

		SMDFile = fopen(FilePath, "r");

		if ( SMDFile == NULL )
		{
			return;
		}

		while ( true )
		{
			int iType = GetToken();
			
			if ( iType == 1 )
			{
				while(true)
				{
					Token = GetToken();
					if ( stricmp("end", TokenString) == 0 )
					{
						break;
					}
					if ( Count >= 16)
						break;
					strcpy(this->item[Count].Name,TokenString);
					Count++;
					this->TypeCount++;
				}
			}
			
			iType = GetToken();
			iType = TokenNumber;
			if ( iType == 2 )
			{
				while(true)
				{
					Token = GetToken();
					if ( stricmp("end", TokenString) == 0 )
					{
						break;
					}
					int type = TokenNumber;
					if(type >= 16)
						exit(1);
					if(this->item[type].IndexCount >= 512)
						break;
					
					Token = GetToken();
					int Index = TokenNumber;

					this->item[type].item[this->item[type].IndexCount].Index = Index;
					
					Token = GetToken();
					strcpy(this->item[type].item[this->item[type].IndexCount].Name,TokenString);
					
					Token = GetToken();
					int Skill = TokenNumber;

					this->item[type].item[this->item[type].IndexCount].Skill = Skill;

					char t1[30] = {0};
					char t2[30] = {0};
					char t3[30] = {0};
					char t4[30] = {0};

					Token = GetToken();
					int Def = TokenNumber;
					if(Def > 0)
						wsprintf(t1,"\nBasic Defense: %d",Def);

					Token = GetToken();
					int DmgMin = TokenNumber;
					if(DmgMin > 0)
						wsprintf(t2,"\nBasic Min Damage: %d",DmgMin);

					Token = GetToken();
					int DmgMax = TokenNumber;
					if(DmgMax > 0)
						wsprintf(t3,"\nBasic Max Damage: %d",DmgMax);

					Token = GetToken();
					int DmgMag = TokenNumber;
					if(DmgMag > 0)
						wsprintf(t4,"\nBasic Magic Damage: %d",DmgMag);
					
					char c1[30]={0};
					char c2[30]={0};
					char c3[30]={0};
					char c4[30]={0};
					char c5[30]={0};
					char c6[30]={0};

					Token = GetToken();
					int DW = TokenNumber;
					switch(DW)
					{
						case 1:
						{
							strcpy(c1,"\nDark Wizard");
						}break;
						case 2:
						{
							strcpy(c1,"\nSoul Master");
						}break;
						case 3:
						{
							strcpy(c1,"\nGrand Master");
						}break;
					};

					Token = GetToken();
					int DK = TokenNumber;
					switch(DK)
					{
						case 1:
						{
							strcpy(c2,"\nDark Knight");
						}break;
						case 2:
						{
							strcpy(c2,"\nBlade Knight");
						}break;
						case 3:
						{
							strcpy(c2,"\nBlade Master");
						}break;
					};

					Token = GetToken();
					int ELF = TokenNumber;
					switch(ELF)
					{
						case 1:
						{
							strcpy(c3,"\nElf");
						}break;
						case 2:
						{
							strcpy(c3,"\nMuse Elf");
						}break;
						case 3:
						{
							strcpy(c3,"\nHigh Elf");
						}break;
					};

					Token = GetToken();
					int MG = TokenNumber;
					switch(MG)
					{
						case 1:
						{
							strcpy(c4,"\nMagic Gladiator");
						}break;
						case 3:
						{
							strcpy(c4,"\nDuel Master");
						}break;
					};

					Token = GetToken();
					int DL = TokenNumber;
					switch(DL)
					{
						case 1:
						{
							strcpy(c5,"\nDark Lord");
						}break;
						case 3:
						{
							strcpy(c5,"\nLord Master");
						}break;
					};

					Token = GetToken();
					int SU = TokenNumber;
					switch(SU)
					{
						case 1:
						{
							strcpy(c6,"\nSummoner");
						}break;
						case 2:
						{
							strcpy(c6,"\nBloody Summoner");
						}break;
						case 3:
						{
							strcpy(c6,"\nDimension Master");
						}break;
					};
					wsprintf(this->item[type].item[this->item[type].IndexCount].Equiped,"%s%s%s%s\n\nCan be equiped by:%s%s%s%s%s%s",t1,t2,t3,t4,c1,c2,c3,c4,c5,c6);
					
					Token = GetToken();
					int Price = TokenNumber;
					this->item[type].item[this->item[type].IndexCount].Price = Price;

					this->item[type].IndexCount++;
				}
			}
			break;
		}			
		fclose(SMDFile);
	}
}

// Use an other thread for show like a Dialog (making that you can see the mouse pointer ^^)

void VShop__Tread(void * lpParam)
{
	if(VShop.InfoRecv == true && VShop.Open == false)
	{
		VShop.NeedClose = false;
		VShop.Open = true;
		refVShop::vipForm->ShowDialog();
		VShop.Open = false;
		VShop.NeedClose = false;
		_endthread();
	}
}

void cReadVShop::Init()
{
	this->InfoRecv = false;
	this->Enabled = TRUE;
	this->Read(".\\Data\\Local\\SCFVShop.txt");
}

BOOL cReadVShop::Show(SDHP_OPENVSHOP * lpMsg)
{	
	if(lpMsg->Open == 1)
	{
		this->VipMoney = lpMsg->VipMoney;
		_beginthread( VShop__Tread, 0, NULL  );
		return 1;
	}
	else
	{
		VShop.NeedClose = true;
		VShop.Open = false;
		return 0;
	}
}

void cReadVShop::SetInfo(SDHP_SENDSVSHOP * lpMsg)
{
	this->MaxExc = lpMsg->mExc;
	this->MaxLevel = lpMsg->mLevel;
	this->MaxOpt = lpMsg->mOpt;
	this->MaxLuck = lpMsg->mLuck;
	this->MaxSkill = lpMsg->mSkill;
	this->MaxHarmony = lpMsg->mHarmony;
	this->pExc = lpMsg->pExc;
	this->pLevel = lpMsg->pLevel;
	this->pOpt = lpMsg->pOpt;
	this->pLuck = lpMsg->pLuck;
	this->pSkill = lpMsg->pSkill;
	this->pHarmony = lpMsg->pHarmony;
	this->InfoRecv = true;
}

void cReadVShop::SendClose()
{
	SDHP_OPENVSHOP pInfo;
	PHeadSubSetB((LPBYTE)&pInfo, 0xFA,0x02, sizeof(pInfo));
	pInfo.Open = 0;
	eng.eDataSend(0,(LPBYTE)&pInfo);
}

void cReadVShop::Send(int Type, int Index, BYTE Level, BYTE Opt, BYTE Luck, BYTE Skill, BYTE Exc, BYTE Harmony)
{
	SDHP_BUYSVSHOP pInfo;
	PHeadSubSetB((LPBYTE)&pInfo, 0xFA,0x01, sizeof(pInfo));
	int ID = ITEMGET(Type,Index);
	pInfo.ItemID = ID;
	pInfo.mLevel = Level;
	pInfo.mOpt = Opt/4;
	pInfo.mLuck = Luck;
	pInfo.mSkill = Skill;
	pInfo.mExc = Exc;
	pInfo.mHarmony = Harmony;
	eng.eDataSend(0,(LPBYTE)&pInfo);
	//SET_VShopBuy(&pInfo);
}