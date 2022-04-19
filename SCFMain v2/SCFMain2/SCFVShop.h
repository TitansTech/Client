#include "stdafx.h"
#include "offsets.h"

struct PBMSG_HEAD	// Packet - Byte Type
{
public:
	void set ( LPBYTE lpBuf, BYTE head, BYTE size)	// line : 18
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	// line : 22

	void setE ( LPBYTE lpBuf, BYTE head, BYTE size)	// line : 25
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	// line : 29

	BYTE c;
	BYTE size;
	BYTE headcode;
};

struct IIndex
{
	int Index;
	int Skill;
	char Name[255];
	char Equiped[255];
	long Price;
};

struct IType
{
	char Name[255];
	IIndex item[INDEXMAX];
	int IndexCount;
};



struct SDHP_SENDSVSHOP
{
	PBMSG_HEAD h;	// C1:01
	BYTE SubCode;
	BYTE mLevel;
	BYTE mOpt;
	BYTE mExc;
	BYTE mLuck;
	BYTE mSkill;
	BYTE mHarmony;
	int pLevel;
	int pOpt;
	int pExc;
	int pLuck;
	int pSkill;
	int pHarmony;
};


struct SDHP_OPENVSHOP
{
	PBMSG_HEAD h;	// C1:01
	BYTE SubCode;
	BYTE Open;
	int VipMoney;
};

struct SDHP_BUYSVSHOP
{
	PBMSG_HEAD h;	// C1:01
	BYTE SubCode;
	int ItemID;
	BYTE mLevel;
	BYTE mOpt;
	BYTE mExc;
	BYTE mLuck;
	BYTE mSkill;
	BYTE mHarmony;
};

class cReadVShop
{
public:
	void Init();
	void SendClose();
	BOOL Show(SDHP_OPENVSHOP * lpMsg);
	void Read(char * FilePath);
	void SetInfo(SDHP_SENDSVSHOP * lpMsg);
	void Send(int Type, int Index, BYTE Level, BYTE Opt, BYTE Luck, BYTE Skill, BYTE Exc, BYTE Harmony);
//Vars:
	IType item[TYPEMAX];
	BOOL Enabled;
	int TypeCount;

	bool InfoRecv;
	bool Open;
	bool NeedClose;

	BYTE MaxExc;
	BYTE MaxOpt;
	BYTE MaxLevel;
	BYTE MaxLuck;
	BYTE MaxSkill;
	BYTE MaxHarmony;
	int pLevel;
	int pOpt;
	int pExc;
	int pLuck;
	int pSkill;
	int pHarmony;
	int VipMoney;
};

extern cReadVShop VShop;

extern "C" __declspec(dllexport) char * SET_VShopBuy(SDHP_BUYSVSHOP * lpMsg);
extern "C" __declspec(dllexport) BOOL GET_VShopClose(SDHP_OPENVSHOP * lpMsg);
extern "C" __declspec(dllexport) void GET_VShopInfo(SDHP_SENDSVSHOP * lpMsg);
extern "C" __declspec(dllexport) BOOL GET_VShopShow(SDHP_OPENVSHOP * lpMsg);
extern "C" __declspec(dllexport) void LauncherExec();