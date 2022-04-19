
#define MAX_DUMP_OFFSETS 64
#define MAX_DUMP_SIZE 32
#define MAX_PROCESS_DUMP 109


typedef struct ANITHACK_PROCDUMP
{
	unsigned int m_aOffset;
	unsigned char m_aMemDump[MAX_DUMP_SIZE];
} *PANITHACK_PROCDUMP;

void Monitor_Start();
void SystemProcessesScan(void * lpParam);
bool GetProcessFromName(LPCTSTR szProcessName);
void CheckIP();
void SetIP(int IPNum);
void gWall__Main(void * lpParam);
void CheckFileSize(LPSTR FileName,int FileSizeA);