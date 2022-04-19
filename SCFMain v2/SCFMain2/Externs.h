

extern "C" __declspec(dllexport) bool Init();
extern "C" __declspec(dllexport) void LauncherShow ();
extern "C" __declspec(dllexport) BOOL GET_VShopClose(SDHP_OPENVSHOP * lpMsg);
extern "C" __declspec(dllexport) void GET_VShopInfo(SDHP_SENDSVSHOP * lpMsg);
extern "C" __declspec(dllexport) BOOL GET_VShopShow(SDHP_OPENVSHOP * lpMsg);
extern "C" __declspec(dllexport) void LauncherExec();