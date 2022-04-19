/////--------1.05D+ o F+
//#define NewOrbsFix_addr							0x007377D9
//#define MasterLevelShow_Addr					0x006D5F3D
//#define SelectCharacter_Addr1					0x005E9B51
//#define SelectCharacter_Addr2					0x005E9B66

/*
=============================================
	1.06B+ OFFSETS
=============================================
*/
//Protocol Address 1.06B+
#define MainProtocolCore ((void(*)(unsigned char,unsigned char*,int,...))0x0064A3E0)
#define ProtocolCore_addr						0x00648023
#define DataSend_addr							0x00404F30
#define DataSendThisCall_addr					0x8C20C0

//3DMain Sky 1.06B+
#define Display_addr							0x607E8B
#define SkyHook_addr							0x58C8D0
#define Blend_addr								0x5FAA11
#define UnBlend_addr							0x5FAA90

//1.06B+ Offsets
#define IMAGE_BASE_EXE							0x00400000
#define BASE_OF_CODE_EXE						0x00000400
#define HEADER_text_RSize						0x0047A000
#define HEADER_rdata_RSize						0x0002E000

//1.06B+
#define IP_IN_MAIN								0x8ABE54
#define VERSION_IN_MAIN							0x8C20A4
#define SERIAL_IN_MAIN							0x8C20AC

//Items 1.06B+

#define SKILL		0xC2
#define ITEMBASE	0x362
#define MaxIndex	0x200
#define SWORD		(ITEMBASE + (0 * MaxIndex))
#define AXE			(ITEMBASE + (1 * MaxIndex))
#define MACE		(ITEMBASE + (2 * MaxIndex))
#define SPEAR		(ITEMBASE + (3 * MaxIndex))
#define BOW			(ITEMBASE + (4 * MaxIndex))
#define STAFF		(ITEMBASE + (5 * MaxIndex))
#define SHIELD		(ITEMBASE + (6 * MaxIndex)) 
#define HELM		(ITEMBASE + (7 * MaxIndex))
#define ARMOR		(ITEMBASE + (8 * MaxIndex))
#define PANTS		(ITEMBASE + (9 * MaxIndex))
#define GLOVES		(ITEMBASE + (10 * MaxIndex))
#define BOOTS		(ITEMBASE + (11 * MaxIndex))
#define MISC1		(ITEMBASE + (12 * MaxIndex))
#define MISC2		(ITEMBASE + (13 * MaxIndex))
#define MISC3		(ITEMBASE + (14 * MaxIndex))
#define SCROLL		(ITEMBASE + (15 * MaxIndex))

#define ITEMGETPOS(x,y) ( (ITEMBASE + (x * MaxIndex)) + y)

#define TYPEMAX		16
#define INDEXMAX	512

#define ITEMGET(x,y) ( (x)*INDEXMAX + (y))


#define ASMItemLoad1		0x59542CC
#define ASMItemLoad2		0x8F190
#define ASMItemLoad3		0x005E32D2

#define LoadSMD ((int(*) ( int , char *, char *,char * )) 0x005DF2BE )
#define LoadBMD ((int(*) ( int , char *, char *,int )) 0x005DF4B3 )
#define LoadTEX ((int(*) ( int , char * , int, int, int )) 0x005DEE00 )


#define LoadSAddr1	0x008AC614
#define LoadSAddr2	0x00844FC9
#define LoadSAddr3	0x594917C
#define LoadSAddr4	0x004CD445
#define LoadSAddr5	0x004CD1C0
#define LoadSAddr6	0x004F2440
#define LoadSAddr7	0x004CD798

#define LoadDMDHookAddr							0x005E32C6
#define ShineHookAddr							0x005CD3FC
#define LoadSHookAddr1							0x004CDCCF
#define LoadSHookAddr2							0x004CDD51
#define Shine__Level_Addr_Return				0x005DACD0	
#define Shine__Level_Addr_Less					0x005DACE0
#define Shine__Level_Addr_Jewel					0x005DB4A0	
#define Shine__LevelHookAddr					0x005DACCA

#define JewelHook1_AllowToUseHookAddr			0x0074A35B
#define JewelHook2__LevelItemHookAddr			0x0074B6F8
#define JewelHook3__AllowToPutHookAddr			0x0076F415
#define JewelHook4__AllowToPutLevelHookAddr		0x0076F4F6
#define JewelHook5__SoundHookAddr				0x005CC038

#define WingsHookAddr							0x0050C85F
#define WingsExit								0x0050C8E7
#define WingsReturn								0x0050C891

#define WingsPropertyHookAddr					0x005A0E9A
#define WingsPropertyExit						0x005A0EAC
#define WingsPropertyReturn						0x005A0EA1

#define ShineReturn								0x005CD411
#define ShineExit								0x005CD685

#define JewelHook1_AllowToUse_Addr_Return		0x0074A362	
#define JewelHook1_AllowToUse_Addr_Exit			0x0074A383
#define JewelHook2__LevelItem_Addr_Return		0x0074B70F
#define JewelHook2__LevelItem_Addr_Allow		0x0074B70B
#define JewelHook3__AllowToPut_Addr_Return		0x0076F41D
#define JewelHook3__AllowToPut_Addr_Allow		0x0076F458
#define JewelHook4__AllowToPutLevel_Addr_Return	0x0076F504
#define JewelHook4__AllowToPutLevel_Addr_Allow	0x0076F508
#define JewelHook5__Sound_Addr_Allow			0x005CC06E
#define JewelHook5__Sound_Addr_Return			0x005CC041

//MiniMap 1.06B+
#define LoadObject								((void(*) (char * ,DWORD,DWORD,DWORD,DWORD ) ) 0x006D5F7E )
#define PCode									0x7B70
#define CallObject								((void(*) () ) 0x005EE256 )
#define MapNumber								0x008AEAE4
#define MiniMap_JNZ_NOP							0x0061D186
#define MiniMap_Map31_NOP						0x006F4C02
#define MiniMapCheck_1_Addr						0x006F2CAA
#define MiniMapCheck_2_Addr						0x007473A0
#define MiniMapCheck_3_Addr						0x005F3235
#define LoadSAddr8	0x00844E04

//3DMain 1.06B+
#define Camera_GlClip_addr						0x00606ACE
#define Camera_Zoom_addr						0x00606849
#define Camera_RotY_addr						0x87DEA4
#define Camera_RotZ_addr						0x8117398
#define Camera_PosZ_addr						0x87CF4C
#define Camera_ClipX_addr						0x87DD74
#define Camera_ClipY_addr						0x005B53D9 
