#include "../stdafx.h"
#include <stdio.h>
#include "../TitanAddOn.h" 
#include "../Offsets.h" 
#include "../stdafx.h"
#include "../Headers/Map.h"
/*
int IsMiniMap = 1;

void LoadImageJgpForMap(char* ImagePatch,DWORD PrintCode)
{
	LoadObject(ImagePatch,PrintCode,0x2601,0x2900,1);
}

int LoadMap(int Map)
{
    char FullMapName[200];
	sprintf(FullMapName,"Maps\\%d.jpg",Map);
	LoadImageJgpForMap(FullMapName,PCode);
	return Map;
}

bool MapChecker1(int Map)
{
	if(IsMiniMap == 0)
	{
		return 0;
	}
	if(
		Map	== 0	||	// Lorencia
		Map == 1	||	// Dungeun
		Map == 2	||	// Devias
		Map == 3	||	// Noria
		Map == 4	||	// LostTower
		Map == 6	||	// Stadium
		Map == 7	||	// Atlans
		Map == 8	||	// Tarcan
		Map == 10	||	// Icarus
		Map == 30	||	// Valey of Loren
		Map == 31	||	// Land of Trials
		Map == 33	||	// Aida
		Map == 34	||	// CryWolf
		Map == 37	||	// KantruRemain
		Map == 38	||	// KantruRelic
		Map == 41	||	// Baracche
		Map == 51	||	// Elbeland
		Map == 56	||	// Swamp
		Map == 57	||	// Raklion
		Map == 63		// Vulcano
		)
	{
		return 1;
	}
	return 0;
}

void MapChecker2()
{
	int Map = *(int*)(MapNumber);

	if(
		Map == 0	||	// Lorencia
		Map == 1	||	// Dungeun
		Map == 2	||	// Devias
		Map == 3	||	// Noria
		Map == 4	||	// LostTower
		Map == 6	||	// Stadium
		Map == 7	||	// Atlans
		Map == 8	||	// Tarcan
		Map == 10	||	// Icarus
		Map == 30	||	// Valey of Loren
		Map == 31	||	// Land of Trials
		Map == 33	||	// Aida
		Map == 34	||	// CryWolf
		Map == 37	||	// KantruRemain
		Map == 38	||	// KantruRelic
		Map == 41	||	// Baracche
		Map == 51	||	// Elbeland
		Map == 56	||	// Swamp
		Map == 57	||	// Raklion
		Map == 63		// Vulcano
		)
	{
		LoadMap(Map);
	}
	CallObject();
}


void MiniMapInit()
{
	*(BYTE*)(MiniMap_JNZ_NOP)	= 0x90;
	*(BYTE*)(MiniMap_JNZ_NOP+1)	= 0x90;

	memset((BYTE*)MiniMap_Map31_NOP,0x90,30);

	*(DWORD*)(MiniMapCheck_1_Addr+1) = (DWORD)MapChecker1 - MiniMapCheck_1_Addr-5;
	*(DWORD*)(MiniMapCheck_2_Addr+1) = (DWORD)MapChecker1 - MiniMapCheck_2_Addr-5;
	*(DWORD*)(MiniMapCheck_3_Addr+1) = (DWORD)MapChecker2 - MiniMapCheck_3_Addr-5;
}
*/