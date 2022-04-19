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

struct SDHP_RECVMARRY
{
	PBMSG_HEAD h;	// C1:FA:10
	BYTE SubCode;
	char Name[11];
	int Divorce;
	int ForceDivorce;
	int TraceCost;
	BYTE Map;
	BYTE Xpos1;
	BYTE Ypos1;
	BYTE Xpos2;
	BYTE Ypos2;
};

extern void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
extern void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size);