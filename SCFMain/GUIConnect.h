
#include "Utils.h"
#include "Packets.h" 


class GUI
{
public:
	void LoadGUI(LPSTR GuiDLL);
	HINSTANCE hDllHinstance;
	char *  (*GET_VShopBuy)(SDHP_BUYSVSHOP*);
	void  (*SEND_VShopInfo)(SDHP_SENDSVSHOP*);
	BOOL  (*SEND_VShopShow)(SDHP_OPENVSHOP*);
	BOOL  (*SEND_VShopClose)(SDHP_OPENVSHOP*);
	bool  (*SEND_Init)();
	void  (*SEND_gWall)();
	void  (*LauncherExec)();
};

extern GUI gui;