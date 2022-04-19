
#ifndef CAMERA_H
#define CAMERA_H

#include <windows.h>
#include <stdio.h>

//#pragma data_seg(".SHAREDDATA")
//	static HHOOK KeyboardHook = NULL;
//	static HHOOK MouseHook = NULL;
//#pragma data_seg()
//#pragma comment(linker, "/SECTION:.SHAREDDATA,RWS")

//MiniMap

//void MiniMapInit();

//3DCamera



//void Display();
void Main3DInit();
void Camera_Reset();

LRESULT CALLBACK Camera_KeybProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Camera_MouseProc(int code, WPARAM wParam, LPARAM lParam);

#endif //CAMERA_H