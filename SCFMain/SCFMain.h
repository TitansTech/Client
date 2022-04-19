#include "stdafx.h"
extern "C" __declspec(dllexport) bool	Init();

void DataSend(LPBYTE Bufffer,int aLen);
//void ItemInit();
void ItemInit(void * lpParam);
void ReplaceBytes(DWORD Address, BYTE ReplaceTo, int HowMany);
bool FileExists(char * name);