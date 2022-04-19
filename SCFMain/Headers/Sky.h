
#include <gl\gl.h>
#include <gl\glu.h>
#include "glaux.h"
#pragma comment (lib,"Headers/Glaux.lib")
#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"GLu32.lib")

struct FRGB
{
	float r, g, b;
};

VOID CALLBACK SkyTimerProc(HWND hwnd,UINT uMsg,UINT_PTR idEvent,DWORD dwTime);
void ChangeSky();
void GetCamCoords(double* x_cam, double* y_cam, double* z_cam);
typedef int(*TSkyHook)();
typedef int(*TBlend) (int);
typedef int(*TUnBlend) ();

int Sky, SkyDayNight,skycolordirection,DisplayInitialized;
AUX_RGBImageRec* blankimage;
AUX_RGBImageRec* images[32][6];
unsigned int textures[32][6];
FRGB skycolor;