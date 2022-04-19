


class ENGINE
{
public:
	HINSTANCE hDllHinstance;
	bool LoadEngine(LPSTR EngineDLL);
	void  (*eDataSend)(BYTE,LPBYTE);
};


extern ENGINE eng;