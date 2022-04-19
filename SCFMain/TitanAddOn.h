#include "stdafx.h"
extern "C" __declspec(dllexport) bool	Init();

void BuxConvert(char* buf, int size);
void DataSend(LPBYTE Bufffer,int aLen);
void ItemInit(void * lpParam);
void ReplaceBytes(DWORD Address, BYTE ReplaceTo, int HowMany);
bool FileExists(char * name);


struct Config
{
	char serial[100];
	char ver[100];
	char ip[100];
	char web1[512];
	char web2[512];
	int loadItems;
	int camera;
};
extern Config config;