
#include "Utils.h"
#include "Packets.h" 


class GUI
{
public:
	void LoadGUI(LPSTR GuiDLL);
	HINSTANCE hDllHinstance;
	//char *  (*GET_VShopBuy)(SDHP_BUYSVSHOP*);
	void  (*SEND_VShopInfo)(SDHP_SENDSVSHOP*);
	BOOL  (*SEND_VShopShow)(SDHP_OPENVSHOP*);
	BOOL  (*SEND_VShopClose)(SDHP_OPENVSHOP*);
	void  (*SEND_WebInfo)(char*,char*);
	void  (*SEND_MarryInfo)(SDHP_RECVMARRY*);
	bool  (*SEND_Init)();
	void  (*SEND_OpenMuTab)();
	BOOL  (*SEND_CloseMuTab)();
	void  (*LauncherExec)();
};

extern GUI gui;