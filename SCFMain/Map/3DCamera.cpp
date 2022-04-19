#include "../stdafx.h"
#include "../stdafx.h"
#include "../Offsets.h" 
#include "../Headers/Map.h" 
#include "../Headers/Sky.h" 
#include "../TitanAddOn.h" 
#include "../GuiConnect.h" 


//bool InitCamera = true;
//struct CameraStruct {
//	float Zoom;
//	float RotY;
//	float RotZ;
//	float PosZ;
//	float ClipX;
//	float ClipY;
//	float GlClip;
//} Camera;

int Camera_MouseX, Camera_MouseY;
bool Camera_Move_State = false;
bool Camera_Status = true;
bool Camera_Zoom_State = false;

HINSTANCE Camera_hInstance;
HHOOK Camera_Mouse,Camera_Teclado;

float *Camera_GlClip  = (float*) Camera_GlClip_addr;//		  2000.000
float *Camera_RotZ    = (float*) Camera_RotZ_addr;  //		 -48.50000
float *Camera_RotY    = (float*) Camera_RotY_addr;	//		 -45.00000
float *Camera_Zoom    = (float*) Camera_Zoom_addr;  //		  35.00000
float *Camera_PosZ	  = (float*) Camera_PosZ_addr;  //		  150.0000
float *Camera_ClipX   = (float*) Camera_ClipX_addr; //        1190.000
float *Camera_ClipY   = (float*) Camera_ClipY_addr; //        2400.000

//int	  *Map			  = (int*)MapNumber;


//TSkyHook SkyHook = (TSkyHook) SkyHook_addr;
//TBlend Blend = (TBlend) Blend_addr;
//TUnBlend UnBlend = (TUnBlend) UnBlend_addr;


void HookOffset(DWORD my, DWORD tohook, BYTE type)
{
	*(BYTE*)tohook = type;
	*(DWORD*)(tohook+1) = my - (tohook+5);
}

void Main3DInit()
{	
	Camera_Mouse = SetWindowsHookEx(WH_MOUSE, Camera_MouseProc, Camera_hInstance, GetCurrentThreadId());	
	Camera_Teclado = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)Camera_KeybProc, Camera_hInstance, GetCurrentThreadId());
	
	//HookOffset((DWORD)&Display,Display_addr,0xE8);
}

void Camera_Reset()
{
			*Camera_Zoom	= 35;
			*Camera_RotY	= -48.5;
			*Camera_RotZ	= -45;
			*Camera_PosZ	= 150;
			*Camera_ClipX	= 1190;
			*Camera_ClipY	= 2400;
}

LRESULT CALLBACK Camera_KeybProc(int nCode, WPARAM wParam, LPARAM lParam)
{		
	int Key = wParam;
	if(nCode == HC_ACTION)
	{
		if(Key == VK_HOME)
		{
			bool IsDown = !(lParam >> 31);
			if(IsDown)
			{
				Camera_Reset();
				CallNextHookEx(0, nCode, wParam, lParam);
				return 1;
			}
		}
		if(Key == VK_INSERT)//0x4A)
		{
			bool IsDown = !(lParam >> 31);
			if(IsDown)
			{
				//gui.SEND_OpenMuTab();
				BYTE OpenTab[] = {0xC6,0x05,0xFB,0x0F,0x01};
				DataSend(OpenTab,5);
			}
		}
	}
	//	else if(Key == VK_END)
	//	{
	//		bool IsDown = !(lParam >> 31);
	//		if(IsDown)
	//		{
	//			ShowMiniMap = !ShowMiniMap;
	//			CallNextHookEx(0, nCode, wParam, lParam);
	//			return 1;
	//		}
	//	}
	//}
	return CallNextHookEx(Camera_Teclado, nCode, wParam, lParam);
}

LRESULT CALLBACK Camera_MouseProc(int code, WPARAM wParam, LPARAM lParam)
{
	if(Camera_Status)
	{
		MOUSEHOOKSTRUCTEX* mhs = (MOUSEHOOKSTRUCTEX*)lParam;
		if(wParam == WM_MOUSEWHEEL)
		{
			if(Camera_Zoom_State)
			{
				int direction = mhs->mouseData;
				if(direction > 0){
					if(*Camera_Zoom > 12){ *Camera_Zoom -= 2; }
				}
				else if(direction < 0){
					if(*Camera_Zoom < 60){ *Camera_Zoom += 2; }
				}
				*Camera_ClipX  = 1190 + (abs(*Camera_PosZ - 150) * 3) + 3000;
				*Camera_ClipY  = 2400 + (abs(*Camera_PosZ - 150) * 3) + 3000;
				*Camera_GlClip = 3000 + (abs(*Camera_PosZ - 150) * 3) + 1500;
			}
		}
		else if(wParam == WM_RBUTTONDOWN){
			Camera_Zoom_State = true;
		}
		else if(wParam == WM_RBUTTONUP){
			Camera_Zoom_State = false;
		}
		else if(wParam == WM_MBUTTONDOWN){
			Camera_MouseX = mhs->pt.x;
			Camera_MouseY = mhs->pt.y;
			Camera_Move_State = true;
		}
		else if(wParam == WM_MBUTTONUP){
			Camera_Move_State = false;
		}
		else if(wParam == WM_MOUSEMOVE){
			if(Camera_Move_State)
			{
				if(Camera_MouseX < mhs->pt.x){
					*Camera_RotZ += 8;
					if (*Camera_RotZ > 315) *Camera_RotZ = -45;
				}
				else if(Camera_MouseX > mhs->pt.x){
					*Camera_RotZ -= 8;
					if (*Camera_RotZ < -405) *Camera_RotZ = -45;
				}
				if(Camera_MouseY < mhs->pt.y){
					if(*Camera_RotY < -45){	
						*Camera_PosZ -= 44;
						*Camera_RotY += (float)2.42;
					}
				}
				else if(Camera_MouseY > mhs->pt.y){
					if(*Camera_RotY > -90){
                        *Camera_PosZ += 44;
						*Camera_RotY -= (float)2.42;
					}
				}

				Camera_MouseX = mhs->pt.x;
				Camera_MouseY = mhs->pt.y;

				*Camera_ClipX  = 1190 + (abs(*Camera_PosZ - 150) * 3) + 3000;
				*Camera_ClipY  = 2400 + (abs(*Camera_PosZ - 150) * 3) + 3000;
				*Camera_GlClip = 3000 + (abs(*Camera_PosZ - 150) * 3) + 1500;
			}
		}
	}
    return CallNextHookEx(Camera_Mouse, code, wParam, lParam);
}

/////////////////////SKY///////////////////
//
//
//
//void InitDisplay()
//{
//	if(Sky)
//	{
//		char texturepath[256];
//		sprintf(texturepath,"%s",".\\Data\\Interface\\Null.bmp");
//		if(!FileExists(texturepath))
//		{
//			MessageBox(0,"Cannot find blank texture","Error",0);
//			ExitProcess(0);
//		}
//		blankimage = auxDIBImageLoad(texturepath);
//
//		try
//		{
//			for(int i=0 ; i<30; i++)
//			{
//				for(int j=0; j<6; j++)
//				{
//					images[i][j] = blankimage;
//				}
//		
//				sprintf(texturepath,".\\Data\\Interface\\World%d\\Back.bmp",i+1);
//				if(FileExists(texturepath))
//					images[i][0] = auxDIBImageLoad(texturepath);
//				sprintf(texturepath,".\\Data\\Interface\\World%d\\Bottom.bmp",i+1);
//				if(FileExists(texturepath))
//					images[i][1] = auxDIBImageLoad(texturepath);
//				sprintf(texturepath,".\\Data\\Interface\\World%d\\Front.bmp",i+1);
//				if(FileExists(texturepath))
//					images[i][2] = auxDIBImageLoad(texturepath);
//				sprintf(texturepath,".\\Data\\Interface\\World%d\\Left.bmp",i+1);
//				if(FileExists(texturepath))
//					images[i][3] = auxDIBImageLoad(texturepath);
//				sprintf(texturepath,".\\Data\\Interface\\World%d\\Right.bmp",i+1);
//				if(FileExists(texturepath))
//					images[i][4] = auxDIBImageLoad(texturepath);
//				sprintf(texturepath,".\\Data\\Interface\\World%d\\Top.bmp",i+1);
//				if(FileExists(texturepath))
//					images[i][5] = auxDIBImageLoad(texturepath);
//			}
//		}
//		catch(...){}
//
//		for(int i=0 ; i<30; i++)
//		{
//			for(int j=0; j<6; j++)
//			{
//				glGenTextures(1, &textures[i][j]);
//				glBindTexture(GL_TEXTURE_2D, textures[i][j]);
//				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//				glTexImage2D(GL_TEXTURE_2D, 0, 3, images[i][j]->sizeX, images[i][j]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, images[i][j]->data);	
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//			}
//		}
//
//		skycolor.r = 1.0f;
//		skycolor.g = 1.0f;
//		skycolor.b = 1.0f;
//
//		if(SkyDayNight)
//		{
//			skycolordirection = 1;
//			SetTimer(FindWindow("MU",NULL),2,5000,(TIMERPROC)SkyTimerProc);
//			ChangeSky();
//		}
//	}
//
//	DisplayInitialized = 1;
//}
//
//
//VOID CALLBACK SkyTimerProc(HWND hwnd,UINT uMsg,UINT_PTR idEvent,DWORD dwTime)
//{
//	ChangeSky();	
//}
//
//void ChangeSky()
//{
//	SYSTEMTIME sm; 
//	GetLocalTime(&sm);
//	int hourstate = sm.wHour % 2;
//	float minutestate = (float)sm.wMinute / 60.0f;
//	if(hourstate == 0)
//	{
//		skycolor.r = minutestate;
//		skycolor.g = minutestate;
//		skycolor.b = minutestate;
//	}
//	else
//	{
//		skycolor.r = 1.0f - minutestate;
//		skycolor.g = 1.0f - minutestate;
//		skycolor.b = 1.0f - minutestate;
//	}
//}
//
///*bool CanDrawSky()
//{
//	char texturepath[256];
//	sprintf_s(texturepath,".\\Data\\Interface\\World%d\\Top.bmp",*Map+1);
//		if(FileExists(texturepath))
//			return true;
//	return false;
//}*/
//
//void Display()
//{
//	SkyHook();
//	Sky = 1;
//	if(!DisplayInitialized)
//		InitDisplay();
//
//	/*if(Sky && CanDrawSky())
//	{
//		double x_cam, y_cam, z_cam;
//		GetCamCoords(&x_cam,&y_cam,&z_cam);
//
//		Blend(1);
//		glColor3d(skycolor.r,skycolor.g,skycolor.b);
//
//		glBindTexture(GL_TEXTURE_2D, textures[*Map][5]);
//			glBegin(GL_QUADS); 
//				//TOP OK
//				glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam-3000, y_cam+3000, 1500); 
//				glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam+3000, y_cam+3000, 1500);
//				glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam+3000, y_cam-3000, 1500);
//				glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam-3000, y_cam-3000, 1500);
//			glEnd();
//
//			glBindTexture(GL_TEXTURE_2D, textures[*Map][1]);
//			glBegin(GL_QUADS); 
//				//BOTTOM
//				glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam-2800, y_cam-2800, 0); 
//				glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam+2800, y_cam-2800, 0);
//				glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam+2800, y_cam-2800, 0);
//				glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam-2800, y_cam-2800, 0); 
//			glEnd();
//
//			glBindTexture(GL_TEXTURE_2D, textures[*Map][2]);
//			glBegin(GL_QUADS); 
//				//FRONT OK -> capovolta
//				glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam-2800, y_cam+2800, 0); 
//				glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam+2800, y_cam+2800, 0);
//				glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam+2800, y_cam+2800, 3000);
//				glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam-2800, y_cam+2800, 3000);
//			glEnd();
//
//			glBindTexture(GL_TEXTURE_2D, textures[*Map][0]);
//			glBegin(GL_QUADS);
//				//BACK OK
//				glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam-2800, y_cam-2800, 3000); 
//				glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam+2800, y_cam-2800, 3000);
//				glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam+2800, y_cam-2800, 0);
//				glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam-2800, y_cam-2800, 0);
//			glEnd();
//
//			glBindTexture(GL_TEXTURE_2D, textures[*Map][3]);
//			glBegin(GL_QUADS);
//				//LEFT OK -> capovolta
//				glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam-2800, y_cam-3000, 0); 
//				glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam-2800, y_cam+3000, 0);
//				glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam-2800, y_cam+3000, 3000);
//				glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam-2800, y_cam-3000, 3000);
//			glEnd();
//
//			glBindTexture(GL_TEXTURE_2D, textures[*Map][4]);
//			glBegin(GL_QUADS);
//				//RIGHT OK
//				glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam+2800, y_cam-3000, 3000); 
//				glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam+2800, y_cam+3000, 3000);
//				glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam+2800, y_cam+3000, 3000);
//				glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam+2800, y_cam-3000, 3000);
//			glEnd();
//
//		UnBlend();
//	}*/
//}
//
//void GetCamCoords(double* x_cam, double* y_cam, double* z_cam)
//{
//	double m[16];
//	glGetDoublev(GL_MODELVIEW_MATRIX, m);
//	*x_cam = -m[12] * m[0] - m[13] * m[1] - m[14] * m[2];
//	*y_cam = -m[12] * m[4] - m[13] * m[5] - m[14] * m[6];
//	*z_cam = -m[12] * m[8] - m[13] * m[9] - m[14] * m[10];
//}