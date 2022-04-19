#include "stdafx.h"

extern "C" __declspec(dllexport) bool	Init();
extern "C" __declspec(dllexport) void LauncherShow ();
extern "C" __declspec(dllexport) void gWall_AntiHack ();

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size);
void Launcher_Show();