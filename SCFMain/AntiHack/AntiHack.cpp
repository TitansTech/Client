
#include "../stdafx.h" 
#include "../Offsets.h" 
#include "../Headers/AntiHack.h"
#include <tlhelp32.h>

char *mainip    = (char*)(IP_IN_MAIN); 

#define IPCount			3

char IPS[IPCount][20] =
{
	"192.168.1.3",		//IcaruS Home
	"74.63.215.130",	//IcaruS Dedi
	"dsmu.hopto.org"	//DaRKav
};

void SetIP(int IPNum)
{
	memcpy(mainip,IPS[IPNum],20);
}

void CheckIP()
{
	char ip [20] = {0};
	wsprintf(ip,"%s",mainip);
	for(int i=0;i<IPCount;i++)
	{
		if(!stricmp(ip,IPS[i]))
		{
			return;
		}
	}
	exit(1);
}

bool GetProcessFromName(LPCTSTR szProcessName)  
{  
  
	HANDLE hProcessSnap;	  
	PROCESSENTRY32 pe32;  	  
	// Take a snapshot of all processes in the system.  	  
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0 );  	  
	if( hProcessSnap == INVALID_HANDLE_VALUE )  	  
		return false;  
	  
	// Set the size of the structure before using it.  
	pe32.dwSize = sizeof(PROCESSENTRY32);  	  
	// Retrieve information about the first process,  	  
	// and exit if unsuccessful  	  
	if( !Process32First(hProcessSnap, &pe32 ) ) 	  
	{  	  
		DWORD gle = GetLastError();  		  
		CloseHandle( hProcessSnap );     // Must clean up the snapshot object!  		  
		SetLastError(gle);  		  
		return false;  	  
	}  
	  
	// Now walk the snapshot of processes, and  	  
	// display information about each process in turn  	  
	do  	  
	{  	  
		if (stricmp(pe32.szExeFile, szProcessName) == 0) 		  
		{  		  
			CloseHandle( hProcessSnap );  			  
			SetLastError(0);  		  
			return true;  	  
		} 	  
	//hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE,	  
	//	pe32.th32ProcessID );  	  
	} while( Process32Next( hProcessSnap, &pe32 ) );  	  
	CloseHandle( hProcessSnap );  	  
	return false;    
}   

ANITHACK_PROCDUMP g_ProcessesDumps[MAX_PROCESS_DUMP] = 
{
    {0x40E04E, {0x53, 0x68, 0x61, 0x64, 0x6F, 0x77, 0x42, 0x65, 0x61, 0x73, 0x74, 0x2E, 0x41, 0x53, 0x41, 0x46, 0x2D, 0x46, 0x32, 0x31, 0x34, 0x39, 0x42, 0x33, 0x31, 0x35, 0x35, 0x5C, 0x4D, 0x79, 0x20, 0x44}},   // Speed Hack Simplifier 1.3 Test

	{0x44E076, {0x55, 0x8b, 0xec, 0x6a, 0xff, 0x68, 0x10, 0xb7, 0x49, 0x00, 0x68, 0x24, 0x44, 0x45, 0x00, 0x64, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xec, 0x58}},	// WpePro 0.9a
    {0x44E08C, {0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x58, 0x53, 0x56, 0x57, 0x89, 0x65, 0xE8, 0xFF, 0x15, 0x04, 0xF4, 0x48, 0x00, 0x33, 0xD2, 0x8A, 0xD4, 0x89, 0x15, 0xD8, 0x0A, 0x4D, 0x00}},   // WPePro 0.9x
	{0x4851C2, {0x75, 0x1C, 0x53, 0x8B, 0xCE, 0xFF, 0x75, 0xE4, 0xFF, 0x75, 0xE0, 0x57, 0xE8, 0x90, 0x01, 0xFE, 0xFF, 0xEB, 0x0B, 0x53, 0x57, 0xFF, 0x76, 0x1C, 0xFF, 0x15, 0x9C, 0xF5, 0x48, 0x00, 0x8B, 0x86}},   // WPePro 0.9x
    {0x4307BE, {0x75, 0x0A, 0x6A, 0x1C, 0xE8, 0x49, 0x01, 0x00, 0x00, 0x83, 0xC4, 0x04, 0xE8, 0xB1, 0x30, 0x00, 0x00, 0x85, 0xC0, 0x75, 0x0A, 0x6A, 0x10, 0xE8, 0x36, 0x01, 0x00, 0x00, 0x83, 0xC4, 0x04, 0xC7}},   // WPePro 1.3
    {0x44397B, {0x75, 0x07, 0x8B, 0xCF, 0xE8, 0xF8, 0xF2, 0xFF, 0xFF, 0x5F, 0x5E, 0xC2, 0x08, 0x00, 0x53, 0x56, 0x8B, 0x74, 0x24, 0x0C, 0x57, 0xFF, 0x76, 0x04, 0xFF, 0x15, 0xC4, 0x9B, 0x49, 0x00, 0x8B, 0xD8}},   // WPePro 1.3

	{0x4C8259, {0xA1, 0x38, 0xBD, 0x4C, 0x00, 0x8B, 0x00, 0x8B, 0x4D, 0xFC, 0xBA, 0xC0, 0x82, 0x4C, 0x00, 0xE8, 0x1F, 0xF1, 0xFF, 0xFF, 0x33, 0xDB, 0xE8, 0xF8, 0xBE, 0xF3, 0xFF, 0x33, 0xC0, 0x5A, 0x59, 0x59}},   // Catastrophe v0.1
    {0x4C5F31, {0x7C, 0x23, 0x8B, 0x45, 0xFC, 0x80, 0x38, 0xC1, 0x75, 0x1B, 0x8B, 0x45, 0xFC, 0x80, 0x78, 0x02, 0xF3, 0x75, 0x12, 0x8B, 0x45, 0xFC, 0x80, 0x78, 0x03, 0x00, 0x75, 0x09, 0x8B, 0x45, 0xFC, 0x80}},   // Catastrophe v0.1
    {0x4CCB71, {0xA1, 0x40, 0xFD, 0x4C, 0x00, 0x8B, 0x00, 0x8B, 0x4D, 0xFC, 0xBA, 0xD8, 0xCB, 0x4C, 0x00, 0xE8, 0xAB, 0xF2, 0xFF, 0xFF, 0x33, 0xDB, 0xE8, 0xE0, 0x75, 0xF3, 0xFF, 0x33, 0xC0, 0x5A, 0x59, 0x59}},   // Catastrophe v1.2
    {0x4CA831, {0x89, 0x55, 0xFC, 0x8B, 0x45, 0xFC, 0xE8, 0xC8, 0xA3, 0xF3, 0xFF, 0x33, 0xC0, 0x55, 0x68, 0x96, 0xA8, 0x4C, 0x00, 0x64, 0xFF, 0x30, 0x64, 0x89, 0x20, 0x8B, 0x45, 0xFC, 0xE8, 0xC2, 0xA1, 0xF3}},   // Catastrophe v1.2

    {0x4320F0, {0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00}},   // Cheat Happens v3.9b1
    {0x4340F0, {0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00}},   // Cheat Happens v3.95b1/b2
    {0x4360F0, {0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00}},   // Cheat Happens v3.95b3
    {0x440020, {0x5F, 0xE4, 0xAD, 0x60, 0x36, 0x56, 0x43, 0x4D, 0x92, 0xBD, 0xC8, 0x6F, 0xF8, 0xDE, 0xE1, 0xBD, 0x01, 0x00, 0x00, 0x00, 0x46, 0x3A, 0x5C, 0x44, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x73}},   // Cheat Happens v3.96b2

    {0x5674D4, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0x2C, 0x70, 0x56, 0x00, 0xE8, 0xC6, 0xFA, 0xE9, 0xFF, 0x8B, 0x1D, 0x98, 0xD8, 0x56, 0x00, 0x33, 0xC0, 0x55, 0x68}},   // Cheat Engine 5.0
	{0x574EC0, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0xE0, 0x49, 0x57, 0x00, 0xE8, 0xCE, 0x20, 0xE9, 0xFF, 0x8B, 0x1D, 0xF8, 0xB8, 0x57, 0x00, 0x33, 0xC0, 0x55, 0x68}},   // Cheat Engine 5.1.1
	{0x574EEC, {0xE8, 0x8B, 0xEA, 0xF1, 0xFF, 0x8D, 0x45, 0xEC, 0xE8, 0x33, 0x56, 0xFF, 0xFF, 0xE8, 0x5A, 0x1F, 0xFD, 0xFF, 0x8B, 0x03, 0xBA, 0x68, 0x50, 0x57, 0x00, 0xE8, 0x6A, 0xE6, 0xF1, 0xFF, 0x8B, 0x03}},   // Cheat Engine 5.1
	{0x4CBD70, {0x8D, 0x85, 0x7C, 0xFE, 0xFF, 0xFF, 0xBA, 0x03, 0x00, 0x00, 0x00, 0xE8, 0xB0, 0x8F, 0xF3, 0xFF, 0x8D, 0x85, 0x88, 0xFE, 0xFF, 0xFF, 0xBA, 0x04, 0x00, 0x00, 0x00, 0xE8, 0xA0, 0x8F, 0xF3, 0xFF}},   // Cheat Engine 5.1
	{0x591F94, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0x5C, 0x1A, 0x59, 0x00, 0xE8, 0x26, 0x50, 0xE7, 0xFF, 0x8B, 0x1D, 0x20, 0x89, 0x59, 0x00, 0x33, 0xC0, 0x55, 0x68}},   // Cheat Engine 5.2
	{0x5839E7, {0x8D, 0x45, 0xB0, 0x50, 0x6A, 0x08, 0x8D, 0x85, 0x78, 0xFF, 0xFF, 0xFF, 0x50, 0xA1, 0xB0, 0xA1, 0x59, 0x00, 0x8B, 0x55, 0xA4, 0x8B, 0x04, 0x90, 0x50, 0xA1, 0x28, 0xA1, 0x59, 0x00, 0x50, 0xA1}},   // Cheat Engine 5.2
	{0x5AA16C, {0xE8, 0x13, 0x40, 0xFF, 0xFF, 0xE8, 0x86, 0x2C, 0xFC, 0xFF, 0x8B, 0x03, 0xBA, 0xD4, 0xA2, 0x5A, 0x00, 0xE8, 0xC2, 0x98, 0xEE, 0xFF, 0x8B, 0x03, 0x83, 0xC0, 0x50, 0xBA, 0xF0, 0xA2, 0x5A, 0x00}},   // Cheat Engine 5.3
	{0x4CBE2B, {0x8D, 0x55, 0xF0, 0xB9, 0x04, 0x00, 0x00, 0x00, 0x8B, 0xC7, 0xE8, 0x02, 0x15, 0xF5, 0xFF, 0x8B, 0x55, 0xF0, 0x8B, 0xC3, 0xE8, 0x8C, 0xF7, 0xFD, 0xFF, 0x8D, 0x55, 0xF0, 0xB9, 0x04, 0x00, 0x00}},   // Cheat Engine 5.3
	{0x5CF354, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0x44, 0xED, 0x5C, 0x00, 0xE8, 0x62, 0x7E, 0xE3, 0xFF, 0x8B, 0x1D, 0xD4, 0x5A, 0x5D, 0x00, 0x33, 0xC0, 0x55, 0x68}},   // Cheat Engine 5.4
	{0x5FECF4, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0xE4, 0xE4, 0x5F, 0x00, 0xE8, 0x9E, 0x89, 0xE0, 0xFF, 0x8B, 0x1D, 0xEC, 0x62, 0x60, 0x00, 0x33, 0xC0, 0x55, 0x68}},   // Cheat Engine 5.5
	{0x5FED5B, {0xE8, 0x10, 0xC3, 0xE9, 0xFF, 0x8B, 0x0D, 0x64, 0x5D, 0x60, 0x00, 0x8B, 0x03, 0x8B, 0x15, 0x00, 0x1D, 0x55, 0x00, 0xE8, 0xFD, 0xC2, 0xE9, 0xFF, 0x8B, 0x0D, 0xC8, 0x5E, 0x60, 0x00, 0x8B, 0x03}},   // Cheat Engine 5.5

    {0x401350, {0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0xC0, 0x47, 0x00, 0xA1, 0x8B, 0xC0, 0x47, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0xC0, 0x47, 0x00, 0x52}},   // WildProxy v0.3
    {0x401401, {0xE8, 0xB6, 0xFF, 0xFF, 0xFF, 0x50, 0x50, 0xFF, 0x35, 0x8B, 0xC0, 0x47, 0x00, 0xE8, 0xAD, 0x54, 0x07, 0x00, 0xFF, 0x35, 0x8B, 0xC0, 0x47, 0x00, 0xE8, 0xB6, 0x54, 0x07, 0x00, 0x5F, 0xC3, 0xB9}},   // WildProxy v0.3
    {0x401320, {0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x20, 0x47, 0x00, 0xA1, 0x8B, 0x20, 0x47, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0x20, 0x47, 0x00, 0x52}},   // WildProxy v0.2
    {0x4013B0, {0xE8, 0xD7, 0xFF, 0xFF, 0xFF, 0xB9, 0xB4, 0x00, 0x00, 0x00, 0x51, 0x6A, 0x08, 0xE8, 0xF4, 0x00, 0x07, 0x00, 0x50, 0xE8, 0x60, 0x01, 0x07, 0x00, 0x0B, 0xC0, 0x75, 0x0A, 0xB8, 0xFD, 0x00, 0x00}},   // WildProxy v0.2
    {0x401320, {0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x90, 0x46, 0x00, 0xA1, 0x8B, 0x90, 0x46, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0x90, 0x46, 0x00, 0x52}},   // WildProxy v0.1
    {0x4013F9, {0xE8, 0x1A, 0x21, 0x06, 0x00, 0xA3, 0x8B, 0x90, 0x46, 0x00, 0x83, 0xF8, 0x00, 0x73, 0x91, 0xB8, 0xFC, 0x00, 0x00, 0x00, 0xE8, 0x7A, 0xFF, 0xFF, 0xFF, 0xC3, 0x83, 0x3D, 0x8B, 0x90, 0x46, 0x00}},   // WildProxy v0.1
    {0x512134, {0x75, 0x05, 0x8A, 0x16, 0x46, 0x12, 0xD2, 0x73, 0xEA, 0x02, 0xD2, 0x75, 0x05, 0x8A, 0x16, 0x46, 0x12, 0xD2, 0x73, 0x4F, 0x33, 0xC0, 0x02, 0xD2, 0x75, 0x05, 0x8A, 0x16, 0x46, 0x12, 0xD2, 0x0F}},   // WildProxy v1.0 Public
    {0x512014, {0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37}},   // WildProxy v1.0 Public
	{0x401414, {0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0xD0, 0x4B, 0x00, 0xA1, 0x8B, 0xD0, 0x4B, 0x00, 0xc1, 0xe0, 0x02, 0xa3, 0x8f, 0xd0, 0x4b, 0x00, 0x52}},	// WildProxy S3Ep2 by manzanita

    {0x4380F0, {0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00}},   // MuPie v2 Beta
    {0x401704, {0x68, 0x84, 0x24, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x80, 0x61, 0xF6}},   // MuPie HG V2
    {0x401B28, {0x68, 0xD8, 0x2A, 0x40, 0x00, 0xE8, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB9, 0xE3, 0x0E, 0xC3}},	// MuPie HG V3
	
    {0x59F001, {0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x50, 0x51, 0xEB, 0x0F, 0xB9, 0xEB, 0x0F, 0xB8, 0xEB, 0x07, 0xB9, 0xEB, 0x0F, 0x90, 0xEB, 0x08, 0xFD, 0xEB, 0x0B, 0xF2, 0xEB, 0xF5, 0xEB, 0xF6, 0xF2, 0xEB}},   // HahaMu 1.16
	{0x59F000, {0x60, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x50, 0x51, 0xeb, 0x0f, 0xb9, 0xeb, 0x0f, 0xb8, 0xeb, 0x07, 0xb9, 0xeb, 0x0f, 0x90, 0xeb, 0x08, 0xfd, 0xeb, 0x0b, 0xf2, 0xeb, 0xf5, 0xeb, 0xf6, 0xf2}},	// HaHaMu 1.16

    {0x4217E0, {0x60, 0xBE, 0x00, 0xD0, 0x41, 0x00, 0x8D, 0xBE, 0x00, 0x40, 0xFE, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11}},   // !xSpeed.net3
    {0x4317B7, {0xA1, 0x5C, 0xF4, 0x46, 0x00, 0x89, 0x45, 0xE8, 0x8B, 0x4D, 0xF0, 0x89, 0x4D, 0xDC, 0x8B, 0x55, 0xDC, 0x52, 0xE8, 0x08, 0x23, 0x01, 0x00, 0x83, 0xC4, 0x04, 0xC7, 0x45, 0xF0, 0x00, 0x00, 0x00}},   // !xSpeed.net3

	{0x40A881, {0xE8, 0x5A, 0x45, 0x00, 0x00, 0x85, 0xC0, 0x74, 0x37, 0x8B, 0x44, 0x24, 0x10, 0x89, 0xBE, 0x9C, 0x00, 0x00, 0x00, 0x85, 0xC0, 0x74, 0x1D, 0x8B, 0x8E, 0x8C, 0x01, 0x00, 0x00, 0x8B, 0x56, 0x20}},   // !Speed Gear v5/6
	{0x41FBE0, {0x8B, 0x54, 0x24, 0x08, 0x8B, 0x44, 0x24, 0x04, 0x52, 0x50, 0xE8, 0x01, 0xFF, 0xFF, 0xFF, 0x6A, 0x32, 0xE8, 0xA2, 0x32, 0xFF, 0xFF, 0xFF, 0xD6, 0x8B, 0x4C, 0x24, 0x08, 0x8B, 0x54, 0x24, 0x04}},   // Autoprision
	{0x401414, {0x68, 0xA4, 0x22, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x8E, 0xF7, 0x08}},   // 99.62t Speed Hack
    {0x401E04, {0x68, 0x28, 0x20, 0x41, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE3, 0x90, 0x67, 0x9A}},   // SpotHack 1.1
    {0x454181, {0xBE, 0x00, 0x90, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x80, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75}},   // MJB Perfect DL Bot
    {0x40970E, {0x68, 0xB4, 0x98, 0x40, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x68, 0x53, 0x56, 0x57, 0x89, 0x65, 0xE8, 0x33, 0xDB, 0x89, 0x5D}},   // Speed Gear 5
    {0x12C5B8, {0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11, 0xDB, 0x72, 0xED, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11, 0xDB, 0x11, 0xC0, 0x01, 0xDB, 0x73}},   // UoPilot
    {0x40FBB6, {0x55, 0x8B, 0xEC, 0x6A, 0xFF, 0x68, 0x48, 0x3D, 0x41, 0x00, 0x68, 0x3C, 0xFD, 0x40, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x68}},   // Game Speed Changer
    {0x438510, {0x60, 0xBE, 0x00, 0x20, 0x42, 0x00, 0x8D, 0xBE, 0x00, 0xF0, 0xFD, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},   // eXpLoRer
    {0x4BCFA4, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF0, 0x53, 0x56, 0x57, 0xB8, 0xC4, 0xCC, 0x4B, 0x00, 0xE8, 0xB1, 0x9B, 0xF4, 0xFF, 0x8B, 0x3D, 0xB0, 0x03, 0x4C, 0x00, 0x68, 0xDC, 0xD0, 0x4B, 0x00, 0x6A, 0x04}},   // Xelerator 1.4
    {0x473BBC, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF4, 0xB8, 0x04, 0x3A, 0x47, 0x00, 0xE8, 0xE0, 0x26, 0xF9, 0xFF, 0xA1, 0x1C, 0x5C, 0x47, 0x00, 0x8B, 0x00, 0xE8, 0x04, 0xBE, 0xFC, 0xFF, 0x8B, 0x0D, 0xE4, 0x5C}},   // Capotecheat(deltacholl)
    {0x55DE8C, {0x87, 0xDE, 0xF7, 0xFA, 0x9F, 0xCA, 0x05, 0x5D, 0x83, 0x67, 0x02, 0x86, 0x59, 0xBF, 0xF1, 0xB6, 0x5B, 0x1F, 0x04, 0x6E, 0x79, 0x00, 0x18, 0x57, 0x8A, 0xD0, 0xA6, 0xFA, 0x8E, 0x5A, 0xE0, 0xD8}},   // Cheat4Fun v0.9 Beta
    {0x493C90, {0x60, 0xBE, 0x00, 0xC0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x50, 0xFA, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11}},   // AutoBuff D-C
    {0x416014, {0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37}},   // HastyMu v0.2
    {0xAF4014, {0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37}},   // FunnyZhyper v5
    {0x48C000, {0xFC, 0xCF, 0xAB, 0xE7, 0x6D, 0x3A, 0x89, 0xBC, 0xB2, 0x9F, 0x73, 0x23, 0xA8, 0xFE, 0xB6, 0x49, 0x5D, 0x39, 0x5D, 0x8A, 0xCB, 0x63, 0x8D, 0xEA, 0x7D, 0x2B, 0x5F, 0xC3, 0xB1, 0xE9, 0x83, 0x29}},   // Lipsum v2
	{0x4D7D40, {0x60, 0xbe, 0x00, 0x00, 0x4a, 0x00, 0x8d, 0xbe, 0x00, 0x10, 0xf6, 0xff, 0x57, 0xeb, 0x0b, 0x90, 0x8a, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xdb, 0x75, 0x07, 0x8b, 0x1e, 0x83, 0xee, 0xfc, 0x11}},	// Perfect+MetalAutoCombo+1.0 
	{0x918FEA, {0xff, 0x40, 0x10, 0x8b, 0x45, 0xfc, 0x83, 0xe0, 0x01, 0x89, 0x45, 0xe8, 0x8b, 0x06, 0xff, 0x40, 0x14, 0xf6, 0x05, 0xf0, 0x02, 0xfe, 0x7f, 0x01, 0x0f, 0x85, 0xe6, 0x92, 0x02, 0x00, 0x39, 0x5D}},	// Razar_Code_Only
	{0x401338, {0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x40, 0x47, 0x00, 0xA1, 0x8B, 0x40, 0x47, 0x00, 0xc1, 0xe0, 0x02, 0xa3, 0x8f, 0x40, 0x47, 0x00, 0x52}},	// Speed Hack by Ziomal
	{0x401000, {0xE8, 0x9B, 0x27, 0x00, 0x00, 0x50, 0xE8, 0xA7, 0x22, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x55, 0x8B, 0xEC, 0x53, 0x56, 0x57, 0x8B, 0x7D, 0x10, 0x8B, 0x5D, 0x0C, 0x8B, 0x75, 0x08, 0x8B}},   //D-C Bypass Public Version (Darkcheats)

	{0x493C91, {0xBE, 0x00, 0xC0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x50, 0xFA, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11, 0xDB}},	// AutoCombo
	{0x41F072, {0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x41, 0x6C, 0x6C, 0x6F, 0x63, 0x00, 0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x46, 0x72, 0x65, 0x65, 0x00, 0x8B, 0x9D, 0x31, 0x05, 0x00, 0x00, 0x0B, 0xDB}},	// !Speed.net1
	{0x4711BA, {0xB8, 0x1C, 0x12, 0x47, 0x00, 0xE8, 0xE4, 0xD9, 0xFB, 0xFF, 0x8B, 0xC3, 0xE8, 0x1D, 0x6B, 0xFE, 0xFF, 0x5B, 0xC3, 0xA1, 0x0C, 0xAD, 0x47, 0x00, 0x50, 0x6A, 0x00, 0x68, 0xFF, 0x0F, 0x1F, 0x00}},	// Only 4 Muwars
	{0x4054DD, {0xBE, 0x42, 0x16, 0x4A, 0x00, 0x8B, 0xF8, 0x8B, 0xC7, 0xB9, 0x05, 0x00, 0x00, 0x00, 0xF3, 0xA5, 0x66, 0xA5, 0xA4, 0x33, 0xC0, 0xE9, 0x63, 0x23, 0x00, 0x00, 0x8B, 0x55, 0x08, 0x33, 0xC9, 0x89}},	// Olly
	{0x405501, {0xBE, 0x42, 0x06, 0x4B, 0x00, 0x8B, 0xF8, 0x8B, 0xC7, 0xB9, 0x05, 0x00, 0x00, 0x00, 0xF3, 0xA5, 0x66, 0xA5, 0xA4, 0x33, 0xC0, 0xE9, 0xE3, 0x26, 0x00, 0x00, 0x8B, 0x55, 0x08, 0x33, 0xC9, 0x89}},	// Shadow Olly
	{0x401796, {0x68, 0xE4, 0x60, 0x40, 0x00, 0xE8, 0x30, 0xFC, 0xFF, 0xFF, 0x85, 0xC0, 0x75, 0x2E, 0x6A, 0xFF, 0x6A, 0x00, 0xFF, 0x75, 0xF8, 0xE8, 0xC0, 0x05, 0x00, 0x00, 0x6A, 0x01, 0x6A, 0x1C, 0x68, 0xE8}},	// Hasty 1.4
	{0x4066A4, {0x50, 0x68, 0x19, 0x00, 0x0F, 0x00, 0x6A, 0x00, 0x68, 0x8C, 0x68, 0x40, 0x00, 0x68, 0x01, 0x00, 0x00, 0x80, 0xE8, 0xF1, 0xAC, 0xFF, 0xFF, 0x85, 0xC0, 0x0F, 0x85, 0x89, 0x00, 0x00, 0x00, 0x33}},	// Cheat Engine 5.4
	{0x5B1939, {0xBA, 0x5C, 0x51, 0x5B, 0x00, 0xE8, 0xD1, 0x3C, 0xE5, 0xFF, 0x75, 0x06, 0xC6, 0x45, 0xD6, 0x0B, 0xEB, 0x13, 0x8B, 0x45, 0xFC, 0xBA, 0x20, 0x51, 0x5B, 0x00, 0xE8, 0xBC, 0x3C, 0xE5, 0xFF, 0x75}},	// Art-Money
	{0x44A835, {0x68, 0x50, 0xA9, 0x44, 0x00, 0xA1, 0x2C, 0x46, 0x47, 0x00, 0x50, 0xE8, 0x6B, 0xC0, 0xFB, 0xFF, 0xA3, 0x9C, 0xAC, 0x47, 0x00, 0x68, 0x64, 0xA9, 0x44, 0x00, 0xA1, 0x2C, 0x46, 0x47, 0x00, 0x50}},	// Zhyper-MU [0]
	{0x44A905, {0x74, 0x65, 0x78, 0x74, 0x00, 0x00, 0x00, 0x49, 0x6D, 0x6D, 0x52, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x78, 0x74, 0x00, 0x00, 0x00, 0x49, 0x6D, 0x6D, 0x47, 0x65}},	// Zhyper-MU [2]
	{0x42E2A8, {0x0F, 0xB6, 0x05, 0xC8, 0xE3, 0x42, 0x00, 0x50, 0x8D, 0x45, 0xE4, 0x50, 0x33, 0xC9, 0xBA, 0xD4, 0xE3, 0x42, 0x00, 0x8B, 0x45, 0xF8, 0xE8, 0xAD, 0xEE, 0xFD, 0xFF, 0x8B, 0x55, 0xE4, 0x8D, 0x45}},	// Zhyper-MU [3]
	{0x42F317, {0xBA, 0x5C, 0xF3, 0x42, 0x00, 0x8D, 0x44, 0x24, 0x04, 0xE8, 0x67, 0xA1, 0xFD, 0xFF, 0x50, 0xE8, 0xB5, 0x75, 0xFD, 0xFF, 0x66, 0xA3, 0xDC, 0x52, 0x47, 0x00, 0x83, 0xC4, 0x30, 0xC3, 0x00, 0x00}},	// Zhyper-MU [4]
	{0x401024, {0x68, 0xE5, 0x40, 0x41, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x8B, 0xC6, 0x8B, 0xCF, 0xE8, 0x26, 0x43, 0x00, 0x00, 0x81, 0xEB, 0x10, 0x01, 0x00, 0x00, 0x74, 0x05, 0x4B, 0x74, 0x14, 0xEB, 0x57, 0xFF}},	// DC ByPass - By DjCheats
	{0x61AF57, {0xB8, 0xE0, 0xB0, 0x61, 0x00, 0xE8, 0xF7, 0x1B, 0xE2, 0xFF, 0xE9, 0x3B, 0x01, 0x00, 0x00, 0x8B, 0x03, 0xE8, 0x1F, 0x31, 0xE8, 0xFF, 0x8B, 0x03, 0xBA, 0x3C, 0xB2, 0x61, 0x00, 0xE8, 0xFB, 0x2C}},	// AC Tool 5.4.0
	{0x27DFF20,{0x43, 0x00, 0x61, 0x00, 0x6D, 0x00, 0x61, 0x00, 0x64, 0x00, 0x61, 0x00, 0x20, 0x00, 0x76, 0x00, 0x34, 0x00, 0x20, 0x00, 0x64, 0x00, 0x65, 0x00, 0x20, 0x00, 0x4C, 0x00, 0x69, 0x00, 0x62, 0x00}},	// DCT Injector DLL
	{0x5FC740, {0x6D, 0x6F, 0x76, 0x20, 0x5B, 0x65, 0x64, 0x78, 0x2B, 0x31, 0x5D, 0x2C, 0x22, 0x59, 0x22, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x6D, 0x6F, 0x76, 0x20, 0x5B, 0x65, 0x64, 0x78}},	// Cheat Engine 5.5
	{0x131017E,{0x52, 0x00, 0x65, 0x00, 0x61, 0x00, 0x64, 0x00, 0x28, 0x00, 0x24, 0x00, 0x43, 0x00, 0x68, 0x00, 0x65, 0x00, 0x63, 0x00, 0x6B, 0x00, 0x48, 0x00, 0x65, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x5B, 0x00}},	// Kiasu Bot
	{0x4029FF, {0x83, 0xEC, 0x08, 0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x83, 0x3D, 0x10, 0x40, 0x40, 0x00, 0x00, 0x75, 0x10, 0x83, 0x3D, 0x58, 0x50, 0x40, 0x00, 0x00, 0x75, 0x07, 0xC7, 0x45, 0xFC, 0x01}},	// Auto Click For MU
	{0x702071CD,{0x68,0x00, 0x72, 0x20, 0x70, 0xFF, 0x75, 0xFC, 0xFF, 0x15, 0x20, 0x10, 0x1F, 0x70, 0xA3, 0xE8, 0x0C, 0x23, 0x70, 0x83, 0x3D, 0xE8, 0x0C, 0x23, 0x70, 0x00, 0x74, 0x2A, 0xFF, 0x35, 0x74, 0xE2}},	// Norsefire v0.30b
	{0x402190, {0x55, 0x8B, 0xEC, 0x53, 0x56, 0x57, 0xBB, 0x00, 0x60, 0x40, 0x00, 0x66, 0x2E, 0xF7, 0x05, 0x1E, 0x28, 0x40, 0x00, 0x04, 0x00, 0x0F, 0x85, 0xDB, 0x00, 0x00, 0x00, 0x6A, 0x00, 0xFF, 0x15, 0x18}},	// Permit
	{0x402230, {0xE8, 0x07, 0x01, 0x00, 0x00, 0xB8, 0xFF, 0x00, 0x00, 0x00, 0x72, 0x36, 0xE8, 0x5E, 0x02, 0x00, 0x00, 0xE8, 0x3B, 0x04, 0x00, 0x00, 0xB8, 0xFF, 0x00, 0x00, 0x00, 0x72, 0x07, 0x53, 0xE8, 0x57}},	// Permit
	{0x48F5AE, {0x55, 0x8B, 0xEC, 0x6A, 0xFF, 0x68, 0x90, 0x8A, 0x4E, 0x00, 0x68, 0x8C, 0x44, 0x49, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x58}},	// T Search
	{0x48F619, {0xE8, 0xCE, 0x2D, 0x00, 0x00, 0x85, 0xC0, 0x75, 0x08, 0x6A, 0x10, 0xE8, 0xB2, 0x00, 0x00, 0x00, 0x59, 0x33, 0xF6, 0x89, 0x75, 0xFC, 0xE8, 0x63, 0x7A, 0x00, 0x00, 0xFF, 0x15, 0x68, 0x44, 0x4D}},	// T Search
	{0x568E9A, {0x68, 0xB8, 0xF9, 0x85, 0x13, 0xE8, 0x9D, 0x53, 0x01, 0x00, 0xB6, 0x94, 0x70, 0x4B, 0xE8, 0x87, 0xE5, 0x43, 0xE4, 0x43, 0x21, 0x7B, 0x18, 0xB7, 0xBB, 0x79, 0x6D, 0x3E, 0xF9, 0x1E, 0x5C, 0x7F}},	// Speed Gear 6
	{0x40C0B0, {0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x31, 0x5C, 0x6F, 0x62, 0x6A, 0x5C, 0x52, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x5C, 0x53, 0x70, 0x65, 0x65, 0x64, 0x20, 0x48, 0x61, 0x63}},	// Speed Hack Simplifier 1.0
	{0x41F001, {0x60, 0xE8, 0x03, 0x00, 0x00, 0x00, 0xE9, 0xEB, 0x04, 0x5D, 0x45, 0x55, 0xC3, 0xE8, 0x01, 0x00, 0x00, 0x00, 0xEB, 0x5D, 0xBB, 0xED, 0xFF, 0xFF, 0xFF, 0x03, 0xDD, 0x81, 0xEB, 0x00, 0xF0, 0x01}},	// !xSpeed.net 2
	{0x420630, {0x60, 0xBE, 0x00, 0xC0, 0x41, 0x00, 0x8D, 0xBE, 0x00, 0x50, 0xFE, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11}},	// !xSpeed.net 6
	
	{0x453180, {0x60, 0xBE, 0x00, 0x80, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x90, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},	// 
	{0x454180, {0x60, 0xBE, 0x00, 0x80, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x90, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},	// 
	{0x4011EC, {0x68, 0xEC, 0xBC, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x8F, 0x98, 0x36}},	// 
	{0x488070, {0x60, 0xBE, 0x00, 0x80, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x90, 0xFA, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11}},	// 
	{0x48A220, {0x60, 0xBE, 0x00, 0xA0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x70, 0xFA, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11}},	// 
	{0x47A1C0, {0x60, 0xBE, 0x00, 0xF0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x20, 0xFA, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},	// 
	{0x455180, {0x60, 0xBE, 0x00, 0xA0, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x70, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},	// 
	{0x401344, {0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x00, 0x47, 0x00, 0xA1, 0x8B, 0x00, 0x47, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0x00, 0x47, 0x00, 0x52}},	// 
	{0x435000, {0x60, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x50, 0x51, 0xEB, 0x0F, 0xB9, 0xEB, 0x0F, 0xB8, 0xEB, 0x07, 0xB9, 0xEB, 0x0F, 0x90, 0xEB, 0x08, 0xFD, 0xEB, 0x0B, 0xF2, 0xEB, 0xF5, 0xEB, 0xF6, 0xF2}},	// 
	{0x401318, {0x68, 0xA4, 0x1F, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEC, 0x82, 0xBE, 0x15}},	// 
	{0x4441C0, {0x60, 0xBE, 0x00, 0x00, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x10, 0xFD, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},	// 
	{0x481870, {0x60, 0xBE, 0x00, 0x30, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0xE0, 0xFA, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}},	// 
	{0x534000, {0x8D, 0x8D, 0x51, 0x2E, 0x40, 0x00, 0x50, 0x51, 0x50, 0xFF, 0x95, 0xC7, 0x2C, 0x40, 0x00, 0x89, 0x85, 0x61, 0x2E, 0x40, 0x00, 0x58, 0x8D, 0x8D, 0x0F, 0x2E, 0x40, 0x00, 0x51, 0x50, 0xFF, 0x95}},	// 
	{0x555030, {0x74, 0x37, 0x8D, 0x85, 0xFB, 0x2C, 0x40, 0x00, 0x50, 0xFF, 0x95, 0xD7, 0x2C, 0x40, 0x00, 0x8D, 0x8D, 0x51, 0x2E, 0x40, 0x00, 0x50, 0x51, 0x50, 0xFF, 0x95, 0xC7, 0x2C, 0x40, 0x00, 0x89, 0x85}},	// 
	{0x401462, {0xE8, 0xD3, 0x16, 0x0E, 0x00, 0x8B, 0xD0, 0xE8, 0x8A, 0x67, 0x0D, 0x00, 0x5A, 0xE8, 0xE8, 0x66, 0x0D, 0x00, 0xE8, 0xBF, 0x67, 0x0D, 0x00, 0x6A, 0x00, 0xE8, 0xC4, 0x7B, 0x0D, 0x00, 0x59, 0x68}},	// 
	{0x401000, {0xB8, 0x44, 0xFF, 0x41, 0x00, 0x50, 0x64, 0xFF, 0x35, 0x00, 0x00, 0x00, 0x00, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x33, 0xC0, 0x89, 0x08, 0x50, 0x45, 0x43, 0x6F, 0x6D, 0x70, 0x61, 0x63}},	// 
	{0x496CA0, {0x60, 0xBE, 0x00, 0x50, 0x46, 0x00, 0x8D, 0xBE, 0x00, 0xC0, 0xF9, 0xFF, 0xC7, 0x87, 0xA8, 0x50, 0x07, 0x00, 0x95, 0x01, 0xA9, 0x0C, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x0E, 0x90, 0x90, 0x90, 0x90}},	// 
	{0x499190, {0x60, 0xBE, 0x00, 0x30, 0x46, 0x00, 0x8D, 0xBE, 0x00, 0xE0, 0xF9, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11}},	// 
	{0x470B74, {0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF0, 0xB8, 0x3C, 0x09, 0x47, 0x00, 0xE8, 0xEC, 0x53, 0xF9, 0xFF, 0xA1, 0x44, 0x2A, 0x47, 0x00, 0x8B, 0x00, 0xE8, 0xF8, 0x34, 0xFE, 0xFF, 0xA1, 0x44, 0x2A, 0x47}},	// 
	{0x6B5000, {0x60, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x50, 0x51, 0x0F, 0xCA, 0xF7, 0xD2, 0x9C, 0xF7, 0xD2, 0x0F, 0xCA, 0xEB, 0x0F, 0xB9, 0xEB, 0x0F, 0xB8, 0xEB, 0x07, 0xB9, 0xEB, 0x0F, 0x90, 0xEB, 0x08}},	// 
	{0x4691A0, {0x60, 0xBE, 0x00, 0xE0, 0x44, 0x00, 0x8D, 0xBE, 0x00, 0x30, 0xFB, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB}}	// 
};


bool ScanProcessMemory(HANDLE hProcess)
{
	for(int i = 0; i < MAX_PROCESS_DUMP; i++)
	{
		char aTmpBuffer[MAX_DUMP_SIZE];
		SIZE_T aBytesRead = 0;
		ReadProcessMemory(hProcess, (LPCVOID)g_ProcessesDumps[i].m_aOffset, (LPVOID)aTmpBuffer, sizeof(aTmpBuffer), &aBytesRead);
		if(memcmp(aTmpBuffer, g_ProcessesDumps[i].m_aMemDump, MAX_DUMP_SIZE) == 0)
		{
			return true;
		}
	}
	return false;
}

void SystemProcessesScan(void * lpParam)
{
	while(true)
	{	
		CheckIP();
		//if(GetProcessFromName("gwall.exe") == false)
		//	exit(1);

		HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		Sleep(1000);

		if(hProcessSnap != INVALID_HANDLE_VALUE)
		{
			PROCESSENTRY32 pe32;
			pe32.dwSize = sizeof(PROCESSENTRY32);
			if(Process32First(hProcessSnap, &pe32))
			{
				do
				{

					HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
					if(hProcess != NULL)
					{
						if(ScanProcessMemory(hProcess))
						{
							ExitProcess(0);
						}
					}
				}
				while(Process32Next(hProcessSnap, &pe32));
			}
		}

		CloseHandle(hProcessSnap);
		Sleep(3000);
	}
	_endthread();
}

void Monitor_Start()
{
#if (WL_PROTECT==1) 
	VM_START_WITHLEVEL(13)
#endif
	_beginthread( gWall__Main, 0, NULL  );
	_beginthread( SystemProcessesScan, 0, NULL  );
#if (WL_PROTECT==1) 
	VM_END
#endif
}



void gWall__Main(void * lpParam)
{
	POINT p;
	HWND DebugerFound = 0;
	int KilledDebugers = 0;

	for ( int qy = 0 ; qy < 100 ; qy++)
	{
		for ( int qx = 0 ; qx < 100 ; qx++)
		{
			p.x = qx * 20;
			p.y = qy * 20;
			
			DebugerFound = WindowFromPoint(p);

			char t[255];
			GetWindowText( DebugerFound , t , 255);

			if ( strstr( strupr(t) , "SHADOW") || strstr( strupr(t) , "OLLY") || strstr( strupr(t) , "DEBUG") || strstr( strupr(t) , "CPU - MAIN") )
			{
				LONG a = GetWindowLong ( DebugerFound , GWL_HWNDPARENT );
				
				while ( a > 0 )
				{
					if ( a > 0 ) DebugerFound = (HWND) a;
					a = GetWindowLong ( DebugerFound , GWL_HWNDPARENT );
				}

				LockWindowUpdate( DebugerFound );

				TOKEN_PRIVILEGES tp;
				HANDLE hToken;
				if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
				{
					LookupPrivilegeValue(0, SE_SHUTDOWN_NAME, &tp.Privileges[0].Luid);
					tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
					tp.PrivilegeCount = 1;
					AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
					
					//!!! UNCOMMENT THIS LINE WHEN YOU COMPILE FINAL VERSION !!!
					CloseHandle(hToken);
				}
				KilledDebugers++;				
			}else if(strstr( strupr(t) , "HACK") || strstr( strupr(t) , "CHEAT"))
			{
				exit(1);
			}
		}
	}

	if ( KilledDebugers > 0 ) ExitProcess ( 0 );
	_endthread();
}

void CheckFileSize(LPSTR FileName,int FileSizeA)
{
	HANDLE hFile = CreateFileA(FileName,               // file to open
                   GENERIC_READ,          // open for reading
                   FILE_SHARE_READ,       // share for reading
                   NULL,                  // default security
                   OPEN_EXISTING,         // existing file only
                   FILE_ATTRIBUTE_NORMAL, // normal file
                   NULL);            
	DWORD FileSize = GetFileSize(hFile,NULL);
	if (FileSize != FileSizeA)
	{
		ExitProcess(0);
	}
}