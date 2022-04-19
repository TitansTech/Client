#define TYPEMAX		16
#define INDEXMAX	512

#define ITEMGET(x,y) ( (x)*INDEXMAX + (y))

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

struct PMSG_CHATDATA
{
	PBMSG_HEAD h;	//	
	char chatid[10];	//	3
	char chatmsg[60];	//	D
};

struct SDHP_BUYSVSHOP
{
	PBMSG_HEAD h;	// C1:01
	BYTE SubCode;
	int ItemID;
	BYTE Days;
	BYTE mLevel;
	BYTE mOpt;
	BYTE mExc;
	BYTE mLuck;
	BYTE mSkill;
	BYTE mHarmony;
};


struct SDHP_RECVMARRY
{
	PBMSG_HEAD h;	// C1:FA:10
	BYTE SubCode;
	char Name[10];
	int Divorce;
	int ForceDivorce;
	int TraceCost;
	BYTE Map;
	BYTE Xpos1;
	BYTE Ypos1;
	BYTE Xpos2;
	BYTE Ypos2;
};