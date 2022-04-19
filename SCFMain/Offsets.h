#include "stdafx.h"

#if(VERSION==10743)

/*
=============================================
	1.07G+ OFFSETS
=============================================
*/
//Protocol Address 1.06B+
#define MainProtocolCore ((void(*)(unsigned char,unsigned char*,int,...))0x0066A030)	//0066A850  /$  8B4424 04     MOV EAX,DWORD PTR SS:[ESP+4]             ;  ntdll.7C910228

#define ProtocolCore_addr						0x00664EC3								//006656E3  |.  E8 68510000   ||CALL mainG+_C.0066A850
#define DataSend_addr							0x00404ED0								//00406480  /$  55            PUSH EBP
#define DataSendThisCall_addr					0x92DE10								//00406471  |.  8B0D E0BE9200 MOV ECX,DWORD PTR DS:[92BEE0]            ; |mainG+_C.08189A18

//3DMain Sky 1.06B+
//#define Display_addr							0x607E8B		//NOT FOUNDED (1.06B+)							//????
#define SkyHook_addr							0x005AFA60								//0059FDB0  /$  51            PUSH ECX
#define Blend_addr								0x00626431								//00616851  /$  55            PUSH EBP
#define UnBlend_addr							0x006264B0								//006168D0  /$  55            PUSH EBP

//Fixes 1.06B+
//#define NewOrbsFix_addr						0x00770630+2							//No need //NOT FOUNDED (1.06B+)							//????

//1.06B+ Offsets
#define IMAGE_BASE_EXE							0x00400000								//0x00400000
#define BASE_OF_CODE_EXE						0x00001000								//0x00001000
#define HEADER_text_RSize						0x004DE000								//0x004DD000
#define HEADER_rdata_RSize						0x00034000								//0x00033000

//1.06B+
#define IP_IN_MAIN								0x91751C								//???? 0x914144
#define VERSION_IN_MAIN							0x92DDF4								//0040B865  |.  8A88 C4BE9200 |MOV CL,BYTE PTR DS:[EAX+92BEC4]
#define SERIAL_IN_MAIN							0x92DDFC								//0040B8AE  |.  8A91 CCBE9200 |MOV DL,BYTE PTR DS:[ECX+92BECC]

//Items 1.06B+

#define SKILL									0xC2									//Same
#define ITEMBASE								0x444									//005BB891  |.  2D 44040000   SUB EAX,444		///  ASCII "Data\Item\"
#define MaxIndex								0x200									//Same
#define SWORD									(ITEMBASE + (0 * MaxIndex))
#define AXE										(ITEMBASE + (1 * MaxIndex))
#define MACE									(ITEMBASE + (2 * MaxIndex))
#define SPEAR									(ITEMBASE + (3 * MaxIndex))
#define BOW										(ITEMBASE + (4 * MaxIndex))
#define STAFF									(ITEMBASE + (5 * MaxIndex))
#define SHIELD									(ITEMBASE + (6 * MaxIndex)) 
#define HELM									(ITEMBASE + (7 * MaxIndex))
#define ARMOR									(ITEMBASE + (8 * MaxIndex))
#define PANTS									(ITEMBASE + (9 * MaxIndex))
#define GLOVES									(ITEMBASE + (10 * MaxIndex))
#define BOOTS									(ITEMBASE + (11 * MaxIndex))
#define MISC1									(ITEMBASE + (12 * MaxIndex))
#define MISC2									(ITEMBASE + (13 * MaxIndex))
#define MISC3									(ITEMBASE + (14 * MaxIndex))
#define SCROLL									(ITEMBASE + (15 * MaxIndex))

#define ITEMGETPOS(x,y) 						( (ITEMBASE + (x * MaxIndex)) + y)

#define TYPEMAX									16
#define INDEXMAX								512

#define ITEMGET(x,y) 							( (x)*INDEXMAX + (y) )


#define LoadDMDHookAddr							0x0060D41B								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad1							0x59C3F2C								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad2							0x9C8F8									//005FD7C0  |.  8B88 F8C80900 MOV ECX,DWORD PTR DS:[EAX+9C8F8]
#define ASMItemLoad3							0x0060D426								//005FD7C6  |.  C641 50 01    MOV BYTE PTR DS:[ECX+50],1

#define LoadSMD ((int(*) ( int , char *, char *,char * ))	0x00608A6E )				//005F8E0E  /.  55            PUSH EBP
#define LoadBMD ((int(*) ( int , char *, char *,int ))		0x00608C63 )				//005F9003  /$  55            PUSH EBP
#define LoadTEX ((int(*) ( int , char * , int, int, int ))	0x006085B0 )				//005F8950  /$  55            PUSH EBP


#define LoadSAddr1								0x00917DEC								//004DB854  |> \68 144A9100   PUSH mainG+_C.00914A14                   ;  ASCII "rb"
#define LoadSAddr2								0x008A3793								//004CEB3F  |.  E8 4FEB3C00   CALL mainG+_C.0089D693
#define LoadSAddr3								0x59B8DDC								//004DB8A3  |> \8B15 64629B05 MOV EDX,DWORD PTR DS:[59B6264]
#define LoadSAddr4								0x004EC4D2								//004DAE72  |.  E8 DE010000   |CALL mainG+_C.004DB055
#define LoadSAddr5								0x004EC430 								//004DADD0  /$  55            PUSH EBP
#define LoadSAddr6								0x005118E5								//005003E5   .  8B45 0C       MOV EAX,DWORD PTR SS:[EBP+C]
#define LoadSAddr7								0x004ECA08								//004DB3A8  /$  55            PUSH EBP
#define LoadSAddr8								0x008A646A								//

#define ShineHookAddr							0x005F4C3E								//005E4FDE  |> \817D 08 5C0C0>CMP DWORD PTR SS:[EBP+8],0C5C
#define ShineCompareValue						0x0C5C									//0x0C5C
#define ShineReturn								0x005F4C53								//005E4FF3  |> \8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define ShineExit								0x005F4EC7								//005E5267  |> \D945 10       FLD DWORD PTR SS:[EBP+10]

#define LoadSHookAddr1							0x004ECF3F								//004DB8DF  |.  E8 63FFFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define LoadSHookAddr2							0x004ECFC1								//004DB961  |.  E8 E1FEFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define Shine__Level_Addr_Return				0x0060420F								//005F45AF  |.  8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Less					0x0060421F								//005F45BF  |> \8B55 08       MOV EDX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Jewel					0x00604A0D								//005F4DAD  |.  E8 14791C00   CALL mainG+_C.007BC6C6
#define Shine__LevelHookAddr					0x00604209								//005F45A9  |> \837D F8 03    CMP DWORD PTR SS:[EBP-8],3

#define JewelHook1_AllowToUseHookAddr			0x0076B5F2								//00771D22  |.  3D 0E1C0000   ||CMP EAX,1C0E
#define JewelHook1_AllowToUse_Addr_Return		0x0076B5F9								//00771D29  |> \8B8D 64FFFFFF ||MOV ECX,DWORD PTR SS:[EBP-9C]          ;  mainG+_C.0045FF08
#define JewelHook1_AllowToUse_Addr_Exit			0x0076B61A								//00771D4A  |> \8B45 88       ||MOV EAX,DWORD PTR SS:[EBP-78]

#define JewelHook2__LevelItemHookAddr			0x0076CB85								//007732B5  |.  3D 0E1C0000   CMP EAX,1C0E
#define JewelHook2__LevelItem_Addr_Return		0x0076CB9C								//007732CC  |> \32C0          XOR AL,AL
#define JewelHook2__LevelItem_Addr_Allow		0x0076CB98								//007732C8  |.  B0 01         MOV AL,1

#define JewelHook3__AllowToPutHookAddr			0x00792C5F								//0079920F  |.  81FA 0E1C0000 CMP EDX,1C0E
#define JewelHook3__AllowToPut_Addr_Return		0x00792C67								//00799217  |.  8B45 EC       MOV EAX,DWORD PTR SS:[EBP-14]
#define JewelHook3__AllowToPut_Addr_Allow		0x00792CA2								//00799252  |> \8B55 E8       MOV EDX,DWORD PTR SS:[EBP-18]

#define JewelHook4__AllowToPutLevelHookAddr		0x00792D52								//00799302  |.  81F9 0E1C0000 CMP ECX,1C0E
#define JewelHook4__AllowToPutLevel_Addr_Return	0x00792D60								//00799310  |> \C645 D8 00    MOV BYTE PTR SS:[EBP-28],0
#define JewelHook4__AllowToPutLevel_Addr_Allow	0x00792D64								//00799314  |> \8B55 EC       MOV EDX,DWORD PTR SS:[EBP-14]

#define JewelHook5__SoundHookAddr				0x005F387A								//005E3C1A  |.  817D FC 0D1C0>CMP DWORD PTR SS:[EBP-4],1C0D
#define JewelHook5__Sound_Addr_Allow			0x005F38B0								//005E3C50  |> \6A 00         PUSH 0                                   ; /Arg3 = 00000000
#define JewelHook5__Sound_Addr_Return			0x005F3883								//005E3C23  |.  817D FC 0E1C0>CMP DWORD PTR SS:[EBP-4],1C0E

//3DMain 1.06B+
#define Camera_GlClip_addr						0x0047D7E5//0x004A7AB8+6							//00622F48  |.  C705 70A79200>MOV DWORD PTR DS:[92A770],450FC000
#define Camera_Zoom_addr						0x004A7839//0x004A7833+6							//00622CC3  |> \C705 74A79200>MOV DWORD PTR DS:[92A774],420C0000
#define Camera_RotY_addr						0x8E198C								//006231EB  |> \D905 EC128E00 FLD DWORD PTR DS:[8E12EC]
#define Camera_RotZ_addr						0x818BBA0								//00622D97  |.  C705 28901808>MOV DWORD PTR DS:[8189028],C2200000
#define Camera_PosZ_addr						0x8E1364								//005CE7B5  |.  D825 5C038E00 |FSUB DWORD PTR DS:[8E035C]
#define Camera_ClipX_addr						0x8E227C								//005CC3F3  |.  D905 B4118E00 FLD DWORD PTR DS:[8E11B4]
#define Camera_ClipY_addr						0x5DBDF3//0x005DBFD6+3							//005CC376  |> \C745 94 00001>MOV DWORD PTR SS:[EBP-6C],45160000


#define WingsHookAddr							0x0052D0D0								//
#define WingsExit								0x0052D158								//
#define WingsReturn								0x0052D13D								//

#define WingsPropertyHookAddr					0x005C4D1A								//
#define WingsPropertyExit						0x005C4D2C								//
#define WingsPropertyReturn						0x005C4D21								//


//MiniMap 1.06B+
/*
#define LoadObject								((void(*) (char * ,DWORD,DWORD,DWORD,DWORD ) ) 0x006D5F7E )
#define PCode									0x7B70
#define CallObject								((void(*) () ) 0x005EE256 )
#define MapNumber								0x008AEAE4
#define MiniMap_JNZ_NOP							0x0061D186
#define MiniMap_Map31_NOP						0x006F4C02
#define MiniMapCheck_1_Addr						0x006F2CAA
#define MiniMapCheck_2_Addr						0x007473A0
#define MiniMapCheck_3_Addr						0x005F3235
*/
#endif

#if(VERSION==10748)
/*
=============================================
	1.07G+ OFFSETS
=============================================
*/
#define MainProtocolCore ((void(*)(unsigned char,unsigned char*,int,...))0x00684B60)	//0066A850  /$  8B4424 04     MOV EAX,DWORD PTR SS:[ESP+4]             ;  ntdll.7C910228

#define ProtocolCore_addr						0x0067F123								//006656E3  |.  E8 68510000   ||CALL mainG+_C.0066A850
#define DataSend_addr							0x00404FE0								//00406480  /$  55            PUSH EBP
#define DataSendThisCall_addr					0x959C20								//00406471  |.  8B0D E0BE9200 MOV ECX,DWORD PTR DS:[92BEE0]            ; |mainG+_C.08189A18

#define IMAGE_BASE_EXE							0x00400000								//0x00400000
#define BASE_OF_CODE_EXE						0x00001000								//0x00001000
#define HEADER_text_RSize						0x005719AC								//0x004DD000
#define HEADER_rdata_RSize						0x00001E24								//0x00033000

#define IP_IN_MAIN								0x9415CC								//???? 0x914144
#define VERSION_IN_MAIN							0x959C04								//0040B865  |.  8A88 C4BE9200 |MOV CL,BYTE PTR DS:[EAX+92BEC4]
#define SERIAL_IN_MAIN							0x959C0C								//0040B8AE  |.  8A91 CCBE9200 |MOV DL,BYTE PTR DS:[ECX+92BECC]

#define SKILL									0xC3									//Same
#define ITEMBASE								0x488									//005BB891  |.  2D 44040000   SUB EAX,444		///  ASCII "Data\Item\"
#define MaxIndex								0x200									//Dont Know
#define SWORD									(ITEMBASE + (0 * MaxIndex))
#define AXE										(ITEMBASE + (1 * MaxIndex))
#define MACE									(ITEMBASE + (2 * MaxIndex))
#define SPEAR									(ITEMBASE + (3 * MaxIndex))
#define BOW										(ITEMBASE + (4 * MaxIndex))
#define STAFF									(ITEMBASE + (5 * MaxIndex))
#define SHIELD									(ITEMBASE + (6 * MaxIndex)) 
#define HELM									(ITEMBASE + (7 * MaxIndex))
#define ARMOR									(ITEMBASE + (8 * MaxIndex))
#define PANTS									(ITEMBASE + (9 * MaxIndex))
#define GLOVES									(ITEMBASE + (10 * MaxIndex))
#define BOOTS									(ITEMBASE + (11 * MaxIndex))
#define MISC1									(ITEMBASE + (12 * MaxIndex))
#define MISC2									(ITEMBASE + (13 * MaxIndex))
#define MISC3									(ITEMBASE + (14 * MaxIndex))
#define SCROLL									(ITEMBASE + (15 * MaxIndex))

#define ITEMGETPOS(x,y) 						( (ITEMBASE + (x * MaxIndex)) + y)

#define TYPEMAX									16
#define INDEXMAX								512

#define ITEMGET(x,y) 							( (x)*INDEXMAX + (y) )


#define LoadDMDHookAddr							0x00624512								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad1							0x59F1C1C								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad2							0xA09C8									//005FD7C0  |.  8B88 F8C80900 MOV ECX,DWORD PTR DS:[EAX+9C8F8]
#define ASMItemLoad3							0x0062451E								//005FD7C6  |.  C641 50 01    MOV BYTE PTR DS:[ECX+50],1

#define LoadSMD ((int(*) ( int , char *, char *,char * ))	0x0061F1A9 )				//005F8E0E  /.  55            PUSH EBP
#define LoadBMD ((int(*) ( int , char *, char *,int ))		0x0061F39E )				//005F9003  /$  55            PUSH EBP
#define LoadTEX ((int(*) ( int , char * , int, int, int ))	0x0061EDD0 )				//005F8950  /$  55            PUSH EBP


#define LoadSAddr1								0x00942084								//004DB854  |> \68 144A9100   PUSH mainG+_C.00914A14                   ;  ASCII "rb"
#define LoadSAddr2								0x008CD8E3								//004CEB3F  |.  E8 4FEB3C00   CALL mainG+_C.0089D693
#define LoadSAddr3								0x59E6ACC								//004DB8A3  |> \8B15 64629B05 MOV EDX,DWORD PTR DS:[59B6264]
#define LoadSAddr4								0x004F40D2								//004DAE72  |.  E8 DE010000   |CALL mainG+_C.004DB055
#define LoadSAddr5								0x004F4030 								//004DADD0  /$  55            PUSH EBP
#define LoadSAddr6								0x0051A461								//005003E5   .  8B45 0C       MOV EAX,DWORD PTR SS:[EBP+C]
#define LoadSAddr7								0x004F4608								//004DB3A8  /$  55            PUSH EBP
#define LoadSAddr8								0x008D05BA								//

#define ShineHookAddr							0x0060A4FC								//005E4FDE  |> \817D 08 5C0C0>CMP DWORD PTR SS:[EBP+8],0C5C
#define ShineCompareValue						0x0CA0									//0x0C5C
#define ShineReturn								0x0060A511								//005E4FF3  |> \8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define ShineExit								0x0060A857								//005E5267  |> \D945 10       FLD DWORD PTR SS:[EBP+10]

#define LoadSHookAddr1							0x004F4B3F								//004DB8DF  |.  E8 63FFFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define LoadSHookAddr2							0x004F4BC1								//004DB961  |.  E8 E1FEFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define Shine__Level_Addr_Return				0x0061A863								//005F45AF  |.  8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Less					0x0061A873								//005F45BF  |> \8B55 08       MOV EDX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Jewel					0x0061B061								//005F4DAD  |.  E8 14791C00   CALL mainG+_C.007BC6C6
#define Shine__LevelHookAddr					0x0061A85D								//005F45A9  |> \837D F8 03    CMP DWORD PTR SS:[EBP-8],3

#define JewelHook1_AllowToUseHookAddr			0x0078EC02								//00771D22  |.  3D 0E1C0000   ||CMP EAX,1C0E
#define JewelHook1_AllowToUse_Addr_Return		0x0078EC09								//00771D29  |> \8B8D 64FFFFFF ||MOV ECX,DWORD PTR SS:[EBP-9C]          ;  mainG+_C.0045FF08
#define JewelHook1_AllowToUse_Addr_Exit			0x0078EC2A								//00771D4A  |> \8B45 88       ||MOV EAX,DWORD PTR SS:[EBP-78]

#define JewelHook2__LevelItemHookAddr			0x0079028F								//007732B5  |.  3D 0E1C0000   CMP EAX,1C0E
#define JewelHook2__LevelItem_Addr_Return		0x007902A6								//007732CC  |> \32C0          XOR AL,AL
#define JewelHook2__LevelItem_Addr_Allow		0x007902A2								//007732C8  |.  B0 01         MOV AL,1

#define JewelHook3__AllowToPutHookAddr			0x007B8175								//0079920F  |.  81FA 0E1C0000 CMP EDX,1C0E
#define JewelHook3__AllowToPut_Addr_Return		0x007B817D								//00799217  |.  8B45 EC       MOV EAX,DWORD PTR SS:[EBP-14]
#define JewelHook3__AllowToPut_Addr_Allow		0x007B81D3								//00799252  |> \8B55 E8       MOV EDX,DWORD PTR SS:[EBP-18]

#define JewelHook4__AllowToPutLevelHookAddr		0x007B829D								//00799302  |.  81F9 0E1C0000 CMP ECX,1C0E
#define JewelHook4__AllowToPutLevel_Addr_Return	0x007B82AB								//00799310  |> \C645 D8 00    MOV BYTE PTR SS:[EBP-28],0
#define JewelHook4__AllowToPutLevel_Addr_Allow	0x007B82AF								//00799314  |> \8B55 EC       MOV EDX,DWORD PTR SS:[EBP-14]

#define JewelHook5__SoundHookAddr				0x00609110								//005E3C1A  |.  817D FC 0D1C0>CMP DWORD PTR SS:[EBP-4],1C0D
#define JewelHook5__Sound_Addr_Allow			0x00609146								//005E3C50  |> \6A 00         PUSH 0                                   ; /Arg3 = 00000000
#define JewelHook5__Sound_Addr_Return			0x00609119								//005E3C23  |.  817D FC 0E1C0>CMP DWORD PTR SS:[EBP-4],1C0E

#define WingsHookAddr							0x00537894								//
#define WingsCall1								0x004B3BFA								//
#define WingsCall2								0x00535E4E								//
#define WingsReturn								0x005378AA								//

#define WingsPropertyHookAddr					0x005D80EB								//
#define WingsPropertyExit						0x005D8CA1								//
#define WingsPropertyReturn						0x005D80F6								//

//3DMain 1.06B+
#define Camera_GlClip_addr						0x0047D955//0x004A7AB8+6							//00622F48  |.  C705 70A79200>MOV DWORD PTR DS:[92A770],450FC000
#define Camera_Zoom_addr						0x004A7A29//0x004A7833+6							//00622CC3  |> \C705 74A79200>MOV DWORD PTR DS:[92A774],420C0000
#define Camera_RotY_addr						0x90B984								//006231EB  |> \D905 EC128E00 FLD DWORD PTR DS:[8E12EC]
#define Camera_RotZ_addr						0x8203920								//00622D97  |.  C705 28901808>MOV DWORD PTR DS:[8189028],C2200000
#define Camera_PosZ_addr						0x90B35C								//005CE7B5  |.  D825 5C038E00 |FSUB DWORD PTR DS:[8E035C]
#define Camera_ClipX_addr						0x90C28C								//005CC3F3  |.  D905 B4118E00 FLD DWORD PTR DS:[8E11B4]
#define Camera_ClipY_addr						0x5F0433//0x005DBFD6+3							//005CC376  |> \C745 94 00001>MOV DWORD PTR SS:[EBP-6C],45160000
#endif


#if(VERSION==10806)
/*
=============================================
	1.07G+ OFFSETS
=============================================
*/
#define MainProtocolCore ((void(*)(unsigned char,unsigned char*,int,...))0x00686250)	//0066A850  /$  8B4424 04     MOV EAX,DWORD PTR SS:[ESP+4]             ;  ntdll.7C910228

#define ProtocolCore_addr						0x00680803								//006656E3  |.  E8 68510000   ||CALL mainG+_C.0066A850
#define DataSend_addr							0x00404FE0								//00406480  /$  55            PUSH EBP
#define DataSendThisCall_addr					0x95AD40								//00406471  |.  8B0D E0BE9200 MOV ECX,DWORD PTR DS:[92BEE0]            ; |mainG+_C.08189A18

#define IMAGE_BASE_EXE							0x00400000								//0x00400000
#define BASE_OF_CODE_EXE						0x00001000								//0x00001000
#define HEADER_text_RSize						0x00572A8C								//0x004DD000
#define HEADER_rdata_RSize						0x00001E42								//0x00033000

#define IP_IN_MAIN								0x942684								//???? 0x914144
#define VERSION_IN_MAIN							0x95AD24								//0040B865  |.  8A88 C4BE9200 |MOV CL,BYTE PTR DS:[EAX+92BEC4]
#define SERIAL_IN_MAIN							0x95AD2C								//0040B8AE  |.  8A91 CCBE9200 |MOV DL,BYTE PTR DS:[ECX+92BECC]

#define SKILL									0xC3									//Same
#define ITEMBASE								0x488									//005BB891  |.  2D 44040000   SUB EAX,444		///  ASCII "Data\Item\"
#define MaxIndex								0x200									//Dont Know
#define SWORD									(ITEMBASE + (0 * MaxIndex))
#define AXE										(ITEMBASE + (1 * MaxIndex))
#define MACE									(ITEMBASE + (2 * MaxIndex))
#define SPEAR									(ITEMBASE + (3 * MaxIndex))
#define BOW										(ITEMBASE + (4 * MaxIndex))
#define STAFF									(ITEMBASE + (5 * MaxIndex))
#define SHIELD									(ITEMBASE + (6 * MaxIndex)) 
#define HELM									(ITEMBASE + (7 * MaxIndex))
#define ARMOR									(ITEMBASE + (8 * MaxIndex))
#define PANTS									(ITEMBASE + (9 * MaxIndex))
#define GLOVES									(ITEMBASE + (10 * MaxIndex))
#define BOOTS									(ITEMBASE + (11 * MaxIndex))
#define MISC1									(ITEMBASE + (12 * MaxIndex))
#define MISC2									(ITEMBASE + (13 * MaxIndex))
#define MISC3									(ITEMBASE + (14 * MaxIndex))
#define SCROLL									(ITEMBASE + (15 * MaxIndex))

#define ITEMGETPOS(x,y) 						( (ITEMBASE + (x * MaxIndex)) + y)

#define TYPEMAX									16
#define INDEXMAX								512

#define ITEMGET(x,y) 							( (x)*INDEXMAX + (y) )


#define LoadDMDHookAddr							0x0062597C								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad1							0x59F2CFC								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad2							0xA09C8									//005FD7C0  |.  8B88 F8C80900 MOV ECX,DWORD PTR DS:[EAX+9C8F8]
#define ASMItemLoad3							0x00625988								//005FD7C6  |.  C641 50 01    MOV BYTE PTR DS:[ECX+50],1

#define LoadSMD ((int(*) ( int , char *, char *,char * ))	0x00620629 )				//005F8E0E  /.  55            PUSH EBP
#define LoadBMD ((int(*) ( int , char *, char *,int ))		0x0062081E )				//005F9003  /$  55            PUSH EBP
#define LoadTEX ((int(*) ( int , char * , int, int, int ))	0x00620250 )				//005F8950  /$  55            PUSH EBP


#define LoadSAddr1								0x0094313C								//004DB854  |> \68 144A9100   PUSH mainG+_C.00914A14                   ;  ASCII "rb"
#define LoadSAddr2								0x008CF0C3								//004CEB3F  |.  E8 4FEB3C00   CALL mainG+_C.0089D693
#define LoadSAddr3								0x59E7BAC								//004DB8A3  |> \8B15 64629B05 MOV EDX,DWORD PTR DS:[59B6264]
#define LoadSAddr4								0x004F44F2								//004DAE72  |.  E8 DE010000   |CALL mainG+_C.004DB055
#define LoadSAddr5								0x004F4450 								//004DADD0  /$  55            PUSH EBP
#define LoadSAddr6								0x0051A881								//005003E5   .  8B45 0C       MOV EAX,DWORD PTR SS:[EBP+C]
#define LoadSAddr7								0x004F4A28								//004DB3A8  /$  55            PUSH EBP
#define LoadSAddr8								0x008D1D9A								//

#define ShineHookAddr							0x0060B97C								//005E4FDE  |> \817D 08 5C0C0>CMP DWORD PTR SS:[EBP+8],0C5C
#define ShineCompareValue						0x0CA0									//0x0C5C
#define ShineReturn								0x0060B991								//005E4FF3  |> \8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define ShineExit								0x0060BCD7								//005E5267  |> \D945 10       FLD DWORD PTR SS:[EBP+10]

#define LoadSHookAddr1							0x004F4F5F								//004DB8DF  |.  E8 63FFFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define LoadSHookAddr2							0x004F4FE1								//004DB961  |.  E8 E1FEFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define Shine__Level_Addr_Return				0x0061BCE3								//005F45AF  |.  8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Less					0x0061BCF3								//005F45BF  |> \8B55 08       MOV EDX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Jewel					0x0061C4E1								//005F4DAD  |.  E8 14791C00   CALL mainG+_C.007BC6C6
#define Shine__LevelHookAddr					0x0061BCDD								//005F45A9  |> \837D F8 03    CMP DWORD PTR SS:[EBP-8],3

#define JewelHook1_AllowToUseHookAddr			0x0078FF52								//00771D22  |.  3D 0E1C0000   ||CMP EAX,1C0E
#define JewelHook1_AllowToUse_Addr_Return		0x0078FF59								//00771D29  |> \8B8D 64FFFFFF ||MOV ECX,DWORD PTR SS:[EBP-9C]          ;  mainG+_C.0045FF08
#define JewelHook1_AllowToUse_Addr_Exit			0x0078FF7A								//00771D4A  |> \8B45 88       ||MOV EAX,DWORD PTR SS:[EBP-78]

#define JewelHook2__LevelItemHookAddr			0x007915DF								//007732B5  |.  3D 0E1C0000   CMP EAX,1C0E
#define JewelHook2__LevelItem_Addr_Return		0x007915F6								//007732CC  |> \32C0          XOR AL,AL
#define JewelHook2__LevelItem_Addr_Allow		0x007915F2								//007732C8  |.  B0 01         MOV AL,1

#define JewelHook3__AllowToPutHookAddr			0x007B99B2								//0079920F  |.  81FA 0E1C0000 CMP EDX,1C0E
#define JewelHook3__AllowToPut_Addr_Return		0x007B99BA								//00799217  |.  8B45 EC       MOV EAX,DWORD PTR SS:[EBP-14]
#define JewelHook3__AllowToPut_Addr_Allow		0x007B9A10								//00799252  |> \8B55 E8       MOV EDX,DWORD PTR SS:[EBP-18]

#define JewelHook4__AllowToPutLevelHookAddr		0x007B9ADA								//00799302  |.  81F9 0E1C0000 CMP ECX,1C0E
#define JewelHook4__AllowToPutLevel_Addr_Return	0x007B9AE8								//00799310  |> \C645 D8 00    MOV BYTE PTR SS:[EBP-28],0
#define JewelHook4__AllowToPutLevel_Addr_Allow	0x007B9AEC								//00799314  |> \8B55 EC       MOV EDX,DWORD PTR SS:[EBP-14]

#define JewelHook5__SoundHookAddr				0x0060A590								//005E3C1A  |.  817D FC 0D1C0>CMP DWORD PTR SS:[EBP-4],1C0D
#define JewelHook5__Sound_Addr_Allow			0x0060A5C6								//005E3C50  |> \6A 00         PUSH 0                                   ; /Arg3 = 00000000
#define JewelHook5__Sound_Addr_Return			0x0060A599								//005E3C23  |.  817D FC 0E1C0>CMP DWORD PTR SS:[EBP-4],1C0E

#define WingsHookAddr							0x00537CC3								//
#define WingsCall1								0x004B405A								//
#define WingsCall2								0x0053627D								//
#define WingsReturn								0x00537CD9								//

#define WingsPropertyHookAddr					0x005D8B3E								//
#define WingsPropertyExit						0x005D9AA5								//
#define WingsPropertyReturn						0x005D8B49								//

//3DMain 1.06B+
#define Camera_GlClip_addr						0x0047D965//0x004A7AB8+6							//00622F48  |.  C705 70A79200>MOV DWORD PTR DS:[92A770],450FC000
#define Camera_Zoom_addr						0x004A7BE9//0x004A7833+6							//00622CC3  |> \C705 74A79200>MOV DWORD PTR DS:[92A774],420C0000
#define Camera_RotY_addr						0x90C98C								//006231EB  |> \D905 EC128E00 FLD DWORD PTR DS:[8E12EC]
#define Camera_RotZ_addr						0x8204A00								//00622D97  |.  C705 28901808>MOV DWORD PTR DS:[8189028],C2200000
#define Camera_PosZ_addr						0x90C35C								//005CE7B5  |.  D825 5C038E00 |FSUB DWORD PTR DS:[8E035C]
#define Camera_ClipX_addr						0x90D284								//005CC3F3  |.  D905 B4118E00 FLD DWORD PTR DS:[8E11B4]
#define Camera_ClipY_addr						0x5F18B3//0x005DBFD6+3							//005CC376  |> \C745 94 00001>MOV DWORD PTR SS:[EBP-6C],45160000
#endif



#if(VERSION==10348)
/*
=============================================
	1.03V+ OFFSETS
=============================================
*/
#define MainProtocolCore ((void(*)(unsigned char,unsigned char*,int,...))0x0068E0D0)	//0066A850  /$  8B4424 04     MOV EAX,DWORD PTR SS:[ESP+4]             ;  ntdll.7C910228

#define ProtocolCore_addr						0x0068858D								//006656E3  |.  E8 68510000   ||CALL mainG+_C.0066A850
#define DataSend_addr							0x00405000								//00406480  /$  55            PUSH EBP
#define DataSendThisCall_addr					0x97DDD8								//00406471  |.  8B0D E0BE9200 MOV ECX,DWORD PTR DS:[92BEE0]            ; |mainG+_C.08189A18

#define IMAGE_BASE_EXE							0x00400000								//0x00400000
#define BASE_OF_CODE_EXE						0x00001000								//0x00001000
#define HEADER_text_RSize						0x0052B000								//0x004DD000
#define HEADER_rdata_RSize						0x00036000								//0x00033000

#define IP_IN_MAIN								0x966516								//???? 0x914144
#define VERSION_IN_MAIN							0x97DDBC								//0040B865  |.  8A88 C4BE9200 |MOV CL,BYTE PTR DS:[EAX+92BEC4]
#define SERIAL_IN_MAIN							0x97DDC4								//0040B8AE  |.  8A91 CCBE9200 |MOV DL,BYTE PTR DS:[ECX+92BECC]

#define SKILL									0xC3									//Same
#define ITEMBASE								0x493									//005BB891  |.  2D 44040000   SUB EAX,444		///  ASCII "Data\Item\"
#define MaxIndex								0x200									//Dont Know
#define SWORD									(ITEMBASE + (0 * MaxIndex))
#define AXE										(ITEMBASE + (1 * MaxIndex))
#define MACE									(ITEMBASE + (2 * MaxIndex))
#define SPEAR									(ITEMBASE + (3 * MaxIndex))
#define BOW										(ITEMBASE + (4 * MaxIndex))
#define STAFF									(ITEMBASE + (5 * MaxIndex))
#define SHIELD									(ITEMBASE + (6 * MaxIndex)) 
#define HELM									(ITEMBASE + (7 * MaxIndex))
#define ARMOR									(ITEMBASE + (8 * MaxIndex))
#define PANTS									(ITEMBASE + (9 * MaxIndex))
#define GLOVES									(ITEMBASE + (10 * MaxIndex))
#define BOOTS									(ITEMBASE + (11 * MaxIndex))
#define MISC1									(ITEMBASE + (12 * MaxIndex))
#define MISC2									(ITEMBASE + (13 * MaxIndex))
#define MISC3									(ITEMBASE + (14 * MaxIndex))
#define SCROLL									(ITEMBASE + (15 * MaxIndex))

#define ITEMGETPOS(x,y) 						( (ITEMBASE + (x * MaxIndex)) + y)

#define TYPEMAX									16
#define INDEXMAX								512

#define ITEMGET(x,y) 							( (x)*INDEXMAX + (y) )


#define LoadDMDHookAddr							0x0062D3F7							//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad1							0x5A16A94									//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad2							0xA1444									//005FD7C0  |.  8B88 F8C80900 MOV ECX,DWORD PTR DS:[EAX+9C8F8]
#define ASMItemLoad3							0x0062D403									//005FD7C6  |.  C641 50 01    MOV BYTE PTR DS:[ECX+50],1

#define LoadSMD ((int(*) ( int , char *, char *,char * ))	0x00627BF9 )						//005F8E0E  /.  55            PUSH EBP
#define LoadBMD ((int(*) ( int , char *, char *,int ))		0x00627DEE )						//005F9003  /$  55            PUSH EBP
#define LoadTEX ((int(*) ( int , char * , int, int, int ))	0x00627820 )						//005F8950  /$  55            PUSH EBP


#define LoadSAddr1								0x00966F94								//004DB854  |> \68 144A9100   PUSH mainG+_C.00914A14                   ;  ASCII "rb"
#define LoadSAddr2								0x008EFED3								//004CEB3F  |.  E8 4FEB3C00   CALL mainG+_C.0089D693
#define LoadSAddr3								0x5A0B944								//004DB8A3  |> \8B15 64629B05 MOV EDX,DWORD PTR DS:[59B6264]
#define LoadSAddr4								0x004F6E62								//004DAE72  |.  E8 DE010000   |CALL mainG+_C.004DB055
#define LoadSAddr5								0x004F6DC0 								//004DADD0  /$  55            PUSH EBP
#define LoadSAddr6								0x0051D2AF								//005003E5   .  8B45 0C       MOV EAX,DWORD PTR SS:[EBP+C]
#define LoadSAddr7								0x004F7398								//004DB3A8  /$  55            PUSH EBP
#define LoadSAddr8								0x008F2B3A								//

#define ShineHookAddr							0x00610FE2								//005E4FDE  |> \817D 08 5C0C0>CMP DWORD PTR SS:[EBP+8],0C5C
#define ShineCompareValue						0x0CAB									//0x0C5C
#define ShineReturn								0x00610FF7								//005E4FF3  |> \8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define ShineExit								0x0061137D								//005E5267  |> \D945 10       FLD DWORD PTR SS:[EBP+10]

#define LoadSHookAddr1							0x004F78CF								//004DB8DF  |.  E8 63FFFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define LoadSHookAddr2							0x004F7951								//004DB961  |.  E8 E1FEFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define Shine__Level_Addr_Return				0x0062303E								//005F45AF  |.  8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Less					0x0062304E								//005F45BF  |> \8B55 08       MOV EDX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Jewel					0x0062383C								//005F4DAD  |.  E8 14791C00   CALL mainG+_C.007BC6C6
#define Shine__LevelHookAddr					0x00623038								//005F45A9  |> \837D F8 03    CMP DWORD PTR SS:[EBP-8],3

#define JewelHook1_AllowToUseHookAddr			0x007A5DD8								//00771D22  |.  3D 0E1C0000   ||CMP EAX,1C0E
#define JewelHook1_AllowToUse_Addr_Return		0x007A5DDF								//00771D29  |> \8B8D 64FFFFFF ||MOV ECX,DWORD PTR SS:[EBP-9C]          ;  mainG+_C.0045FF08
#define JewelHook1_AllowToUse_Addr_Exit			0x007A5E00								//00771D4A  |> \8B45 88       ||MOV EAX,DWORD PTR SS:[EBP-78]

#define JewelHook2__LevelItemHookAddr			0x007A7613								//007732B5  |.  3D 0E1C0000   CMP EAX,1C0E
#define JewelHook2__LevelItem_Addr_Return		0x007A762A								//007732CC  |> \32C0          XOR AL,AL
#define JewelHook2__LevelItem_Addr_Allow		0x007A7626								//007732C8  |.  B0 01         MOV AL,1

#define JewelHook3__AllowToPutHookAddr			0x007D24D9	//nose							//0079920F  |.  81FA 0E1C0000 CMP EDX,1C0E
#define JewelHook3__AllowToPut_Addr_Return		0x007D24E1	//nose							//00799217  |.  8B45 EC       MOV EAX,DWORD PTR SS:[EBP-14]
#define JewelHook3__AllowToPut_Addr_Allow		0x007D2537	//nose							//00799252  |> \8B55 E8       MOV EDX,DWORD PTR SS:[EBP-18]

#define JewelHook4__AllowToPutLevelHookAddr		0x007D260C								//00799302  |.  81F9 0E1C0000 CMP ECX,1C0E
#define JewelHook4__AllowToPutLevel_Addr_Return	0x007D2619								//00799310  |> \C645 D8 00    MOV BYTE PTR SS:[EBP-28],0
#define JewelHook4__AllowToPutLevel_Addr_Allow	0x007D261D								//00799314  |> \8B55 EC       MOV EDX,DWORD PTR SS:[EBP-14]

#define JewelHook5__SoundHookAddr				0x0060FBF6								//005E3C1A  |.  817D FC 0D1C0>CMP DWORD PTR SS:[EBP-4],1C0D
#define JewelHook5__Sound_Addr_Allow			0x0060FC2C								//005E3C50  |> \6A 00         PUSH 0                                   ; /Arg3 = 00000000
#define JewelHook5__Sound_Addr_Return			0x0060FBFF								//005E3C23  |.  817D FC 0E1C0>CMP DWORD PTR SS:[EBP-4],1C0E


#define JewelHook6__AllowToUse2HookAddr			0x007A75BE
#define JewelHook6__AllowToUse2_Addr_Return		0x007A75EF
#define JewelHook6__AllowToUse2_Addr_Exit		0x007A75C6

#define WingsHookAddr							0x0053BECC								//
#define WingsCall1								0x004B65AA								//
#define WingsCall2								0x0053A43D								//
#define WingsReturn								0x0053BEE2								//

#define WingsPropertyHookAddr					0x005DD930								//
#define WingsPropertyExit						0x005DE890								//
#define WingsPropertyReturn						0x005DD93B								//

//3DMain 1.06B+//DE ACA EN ADELANTE
#define Camera_GlClip_addr						0x0047FC01//0x004A7AB8+6							//00622F48  |.  C705 70A79200>MOV DWORD PTR DS:[92A770],450FC000
#define Camera_Zoom_addr						0x004A9F89//0x004A7833+6							//00622CC3  |> \C705 74A79200>MOV DWORD PTR DS:[92A774],420C0000
#define Camera_RotY_addr						0x92E984								//006231EB  |> \D905 EC128E00 FLD DWORD PTR DS:[8E12EC]
#define Camera_RotZ_addr						0x82305C0								//00622D97  |.  C705 28901808>MOV DWORD PTR DS:[8189028],C2200000
#define Camera_PosZ_addr						0x92E35C								//005CE7B5  |.  D825 5C038E00 |FSUB DWORD PTR DS:[8E035C]
#define Camera_ClipX_addr						0x92F274								//005CC3F3  |.  D905 B4118E00 FLD DWORD PTR DS:[8E11B4]
#define Camera_ClipY_addr						0x5F6801//0x005DBFD6+3							//005CC376  |> \C745 94 00001>MOV DWORD PTR SS:[EBP-6C],45160000
#endif


#if(VERSION==10349)
/*
=============================================
	1.03V+ OFFSETS
=============================================
*/
#define MainProtocolCore ((void(*)(unsigned char,unsigned char*,int,...))0x0068C3A0)	//0066A850  /$  8B4424 04     MOV EAX,DWORD PTR SS:[ESP+4]             ;  ntdll.7C910228

#define ProtocolCore_addr						0x00686309								//006656E3  |.  E8 68510000   ||CALL mainG+_C.0066A850
#define DataSend_addr							0x00405000								//00406480  /$  55            PUSH EBP
#define DataSendThisCall_addr					0x9AA35C								//00406471  |.  8B0D E0BE9200 MOV ECX,DWORD PTR DS:[92BEE0]            ; |mainG+_C.08189A18

#define IMAGE_BASE_EXE							0x00400000							//0x00400000
#define BASE_OF_CODE_EXE						0x00001000							//0x00001000
#define HEADER_text_RSize						0x00556000								//0x004DD000
#define HEADER_rdata_RSize						0x00037000							//0x00033000

#define IP_IN_MAIN								0x9928BE							//???? 0x914144
#define VERSION_IN_MAIN							0x9AA340								//0040B865  |.  8A88 C4BE9200 |MOV CL,BYTE PTR DS:[EAX+92BEC4]
#define SERIAL_IN_MAIN							0x9AA348								//0040B8AE  |.  8A91 CCBE9200 |MOV DL,BYTE PTR DS:[ECX+92BECC]

#define SKILL									0xC3									//Same
#define ITEMBASE								0x493									//005BB891  |.  2D 44040000   SUB EAX,444		///  ASCII "Data\Item\"
#define MaxIndex								0x200									//Dont Know
#define SWORD									(ITEMBASE + (0 * MaxIndex))
#define AXE										(ITEMBASE + (1 * MaxIndex))
#define MACE									(ITEMBASE + (2 * MaxIndex))
#define SPEAR									(ITEMBASE + (3 * MaxIndex))
#define BOW										(ITEMBASE + (4 * MaxIndex))
#define STAFF									(ITEMBASE + (5 * MaxIndex))
#define SHIELD									(ITEMBASE + (6 * MaxIndex)) 
#define HELM									(ITEMBASE + (7 * MaxIndex))
#define ARMOR									(ITEMBASE + (8 * MaxIndex))
#define PANTS									(ITEMBASE + (9 * MaxIndex))
#define GLOVES									(ITEMBASE + (10 * MaxIndex))
#define BOOTS									(ITEMBASE + (11 * MaxIndex))
#define MISC1									(ITEMBASE + (12 * MaxIndex))
#define MISC2									(ITEMBASE + (13 * MaxIndex))
#define MISC3									(ITEMBASE + (14 * MaxIndex))
#define SCROLL									(ITEMBASE + (15 * MaxIndex))

#define ITEMGETPOS(x,y) 						( (ITEMBASE + (x * MaxIndex)) + y)

#define TYPEMAX									16
#define INDEXMAX								512

#define ITEMGET(x,y) 							( (x)*INDEXMAX + (y) )


#define LoadDMDHookAddr							0x0062B5C3		//nose					//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad1							1				//nose								//005FD7BB  |.  A1 B4139C05   MOV EAX,DWORD PTR DS:[59C13B4]
#define ASMItemLoad2							0x0A93			//nose							//005FD7C0  |.  8B88 F8C80900 MOV ECX,DWORD PTR DS:[EAX+9C8F8]
#define ASMItemLoad3							0x0062B5CA		//nose								//005FD7C6  |.  C641 50 01    MOV BYTE PTR DS:[ECX+50],1

#define LoadSMD ((int(*) ( int , char *, char *,char * ))	0x00625E53 )						//005F8E0E  /.  55            PUSH EBP
#define LoadBMD ((int(*) ( int , char *, char *,int ))		0x00626048 )						//005F9003  /$  55            PUSH EBP
#define LoadTEX ((int(*) ( int , char * , int, int, int ))	0x00625A70 )						//005F8950  /$  55            PUSH EBP


#define LoadSAddr1								0x00993434								//004DB854  |> \68 144A9100   PUSH mainG+_C.00914A14                   ;  ASCII "rb"
#define LoadSAddr2								0x009197B3								//004CEB3F  |.  E8 4FEB3C00   CALL mainG+_C.0089D693
#define LoadSAddr3								0x5A392F4								//004DB8A3  |> \8B15 64629B05 MOV EDX,DWORD PTR DS:[59B6264]
#define LoadSAddr4								0x004F6EF2								//004DAE72  |.  E8 DE010000   |CALL mainG+_C.004DB055
#define LoadSAddr5								0x004F6E50 								//004DADD0  /$  55            PUSH EBP
#define LoadSAddr6								0x0051DABF								//005003E5   .  8B45 0C       MOV EAX,DWORD PTR SS:[EBP+C]
#define LoadSAddr7								0x004F7428								//004DB3A8  /$  55            PUSH EBP
#define LoadSAddr8								0x0091C41A								//

#define ShineHookAddr							0x0060F1A4								//005E4FDE  |> \817D 08 5C0C0>CMP DWORD PTR SS:[EBP+8],0C5C
#define ShineCompareValue						0x0CAB									//0x0C5C
#define ShineReturn								0x0060F1B9								//005E4FF3  |> \8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define ShineExit								0x0060F53F								//005E5267  |> \D945 10       FLD DWORD PTR SS:[EBP+10]

#define LoadSHookAddr1							0x004F796C								//004DB8DF  |.  E8 63FFFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define LoadSHookAddr2							0x004F79E7								//004DB961  |.  E8 E1FEFFFF   CALL mainG+_C.004DB847                   ; \mainG+_C.004DB847
#define Shine__Level_Addr_Return				0x0062128C								//005F45AF  |.  8B4D 08       MOV ECX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Less					0x0062129C								//005F45BF  |> \8B55 08       MOV EDX,DWORD PTR SS:[EBP+8]             ;  mainG+_C.<ModuleEntryPoint>
#define Shine__Level_Addr_Jewel					0x00621A8A								//005F4DAD  |.  E8 14791C00   CALL mainG+_C.007BC6C6
#define Shine__LevelHookAddr					0x00621286								//005F45A9  |> \837D F8 03    CMP DWORD PTR SS:[EBP-8],3

#define JewelHook1_AllowToUseHookAddr			0x007A7D18								//00771D22  |.  3D 0E1C0000   ||CMP EAX,1C0E
#define JewelHook1_AllowToUse_Addr_Return		0x007A7D1F								//00771D29  |> \8B8D 64FFFFFF ||MOV ECX,DWORD PTR SS:[EBP-9C]          ;  mainG+_C.0045FF08
#define JewelHook1_AllowToUse_Addr_Exit			0x007A7D40								//00771D4A  |> \8B45 88       ||MOV EAX,DWORD PTR SS:[EBP-78]

#define JewelHook2__LevelItemHookAddr			0x007A9553								//007732B5  |.  3D 0E1C0000   CMP EAX,1C0E
#define JewelHook2__LevelItem_Addr_Return		0x007A956A								//007732CC  |> \32C0          XOR AL,AL
#define JewelHook2__LevelItem_Addr_Allow		0x007A9566								//007732C8  |.  B0 01         MOV AL,1

#define JewelHook3__AllowToPutHookAddr			0x007ED359								//0079920F  |.  81FA 0E1C0000 CMP EDX,1C0E
#define JewelHook3__AllowToPut_Addr_Return		0x007ED361								//00799217  |.  8B45 EC       MOV EAX,DWORD PTR SS:[EBP-14]
#define JewelHook3__AllowToPut_Addr_Allow		0x007ED3B7								//00799252  |> \8B55 E8       MOV EDX,DWORD PTR SS:[EBP-18]

#define JewelHook4__AllowToPutLevelHookAddr		0x007ED48C								//00799302  |.  81F9 0E1C0000 CMP ECX,1C0E
#define JewelHook4__AllowToPutLevel_Addr_Return	0x007ED499								//00799310  |> \C645 D8 00    MOV BYTE PTR SS:[EBP-28],0
#define JewelHook4__AllowToPutLevel_Addr_Allow	0x007ED49D								//00799314  |> \8B55 EC       MOV EDX,DWORD PTR SS:[EBP-14]

#define JewelHook5__SoundHookAddr				0x0060DDA3								//005E3C1A  |.  817D FC 0D1C0>CMP DWORD PTR SS:[EBP-4],1C0D
#define JewelHook5__Sound_Addr_Allow			0x0060DDD9								//005E3C50  |> \6A 00         PUSH 0                                   ; /Arg3 = 00000000
#define JewelHook5__Sound_Addr_Return			0x0060DDAC								//005E3C23  |.  817D FC 0E1C0>CMP DWORD PTR SS:[EBP-4],1C0E


#define JewelHook6__AllowToUse2HookAddr			0x007A94FE
#define JewelHook6__AllowToUse2_Addr_Return		0x007A952F
#define JewelHook6__AllowToUse2_Addr_Exit		0x007A9506

#define WingsHookAddr							0x0053D08D								//
#define WingsCall1								0x004B65AA								//
#define WingsCall2								0x0053B5FE								//
#define WingsReturn								0x0053D092								//

#define WingsPropertyHookAddr					0x005DBA3C								//
#define WingsPropertyExit						0x005DC99C								//
#define WingsPropertyReturn						0x005DBA47								//

//3DMain 1.06B+
#define Camera_GlClip_addr						0x0047FC31//0x004A7AB8+6							//00622F48  |.  C705 70A79200>MOV DWORD PTR DS:[92A770],450FC000
#define Camera_Zoom_addr						0x004AA119//0x004A7833+6							//00622CC3  |> \C705 74A79200>MOV DWORD PTR DS:[92A774],420C0000
#define Camera_RotY_addr						0x959984								//006231EB  |> \D905 EC128E00 FLD DWORD PTR DS:[8E12EC]
#define Camera_RotZ_addr						0x825DF68								//00622D97  |.  C705 28901808>MOV DWORD PTR DS:[8189028],C2200000
#define Camera_PosZ_addr						0x95935C								//005CE7B5  |.  D825 5C038E00 |FSUB DWORD PTR DS:[8E035C]
#define Camera_ClipX_addr						0x95A274								//005CC3F3  |.  D905 B4118E00 FLD DWORD PTR DS:[8E11B4]
#define Camera_ClipY_addr						0x5F480C//0x005DBFD6+3							//005CC376  |> \C745 94 00001>MOV DWORD PTR SS:[EBP-6C],45160000
#endif