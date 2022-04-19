// TitanMainConfig.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <math.h>
#include <mmsystem.h>
#include <math.h>
#include <stdio.h>
#include <process.h>
#include <shellapi.h>

int InitItems2(char * FilePath);
void ReadItemFile(LPSTR FileName);
int InitConfig(char * FilePath);
void ReadConfigFile(LPSTR FileName);
void WriteTxt(LPSTR FileName,LPSTR String);

int _tmain(int argc, _TCHAR* argv[])
{
	//remove( ".\\Item.ttc" );
	//remove( ".\\Config.ttc" );
	//InitConfig(".\\SCFMain.ini");
	//InitItems2(".\\SCFMain.ini");
	ReadConfigFile(".\\Config.ttc");
	return 0;
}

static unsigned char bBuxCode[3]={0xAB, 0xDC, 0xEF};	// Xox Key for some interesthing things :)
void BuxConvert(char* buf, int size)
{
	int n;

	for (n=0;n<size;n++)
	{
		buf[n]^=bBuxCode[n%3] ;		// Nice trick from WebZen
	}
}
void WriteTxt(LPSTR FileName,LPSTR String)
{
	FILE *f;
	f = fopen (FileName,"a+");
	char Print[255]={0};
	wsprintf(Print,"%s\n",String);
	if (fputs (Print,f) == EOF) 
	{
	}
	fclose (f);
}



void ReadConfigFile(LPSTR FileName)
{
	int LineCount=0;
	FILE *fp;
	char sLineTxt[3000] = {0};
	BOOL bRead = FALSE;
	
	char path[255]; 

	if((fp=fopen(FileName, "r")) == NULL)
	{
		return;
	}

	rewind(fp);
		
	while(fgets(sLineTxt, 3000, fp) != NULL)
	{
		BuxConvert(sLineTxt,strlen(sLineTxt));		

		if(strlen(sLineTxt)>10)
		{
		//	int Type,start=0;
		//	sscanf(sLineTxt, "%d %d", &Type,&start);
		//	char sBuf[255]={0};
		//	wsprintf(sBuf,"%d\t%d",Type,start);
		//	WriteTxt("Config2.log",sBuf);
		//}else
		//{
			char serial[100]={0};
			char ver[100]={0};
			char ip[100]={0};
			char web1[512]={0};
			char web2[512]={0};
			int Type=0;
			int start=0;
			sscanf(sLineTxt, "%s %s %s %s %s %d %d", ip,ver,serial,web1,web2, &Type,&start);
			char sBuf[3000]={0};
			wsprintf(sBuf,"%s\t%s\t%s\t%s\t%s\t%d\t%d",ip,ver,serial,web1,web2,Type,start);
			//WriteTxt("Config2.log",sBuf);
		}
	}

	rewind(fp);
	fclose(fp);
}

int InitConfig(char * FilePath)
{	
	char sBuf[3000]={0};

	char serial[100]={0};
	char ver[100]={0};
	char ip[100]={0};
	char web1[512]={0};
	char web2[512]={0};
	GetPrivateProfileString("Config","IP","",ip,20,FilePath);
	GetPrivateProfileString("Version","ClientExeSerial","",serial,17,FilePath);
	GetPrivateProfileString("Version","ClientExeVersion","",ver,6,FilePath);
	int loadItems = GetPrivateProfileInt("Config", "LoadNewItems",0, FilePath) ;
	int camera = GetPrivateProfileInt("Config", "Load3DCamera",0, FilePath) ;
	GetPrivateProfileString("Web","ItemImagesDir","",web1,511,FilePath);
	GetPrivateProfileString("Web","DonateWeb","",web2,511,FilePath);
	wsprintf(sBuf,"%s\t%s\t%s\t%s\t%s\t%d\t%d",ip,ver,serial,web1,web2,loadItems,camera);
	BuxConvert(sBuf,strlen(sBuf));
	WriteTxt("Config.ttc",sBuf);
	
	//ReadConfigFile("Config.ttc");

	return 1;
}

int InitItems2(char * FilePath)
{
	
	for(int i = 0; i < 16; i++)
	{
		char etiqueta[50];
		wsprintf(etiqueta,"Items %d", i);
		int start = GetPrivateProfileInt(etiqueta, "CustomIndexStart",-1, FilePath) ;

		char sBuf[255]={0};
		wsprintf(sBuf,"%d\t%d",i,start);
		//WriteTxt("Item.log",sBuf);
		BuxConvert(sBuf,strlen(sBuf));
		WriteTxt("Item.ttc",sBuf);
	}

	for(int i = 0; i < 16; i++)
	{
		char etiqueta[50];
		wsprintf(etiqueta,"Items %d", i);
		
			for(int j=0;j<256;j++)
			{
				char etiquetaindexGlow[50];
				wsprintf(etiquetaindexGlow,"Index_%d-Glow", j);
				char etiquetaindexType[50];
				wsprintf(etiquetaindexType,"Index_%d-Type", j);
				char etiquetaindexMLevel[50];
				wsprintf(etiquetaindexMLevel,"Index_%d-MaxLevel", j);

				int type = GetPrivateProfileInt(etiqueta, etiquetaindexType,0, FilePath) ;
				int Glow = GetPrivateProfileInt(etiqueta, etiquetaindexGlow,-1, FilePath) ;
				int MaxLevel = GetPrivateProfileInt(etiqueta, etiquetaindexMLevel,13, FilePath) ;
					


				if(type != 0 || Glow != -1)
				{
					if(Glow == -1)
						Glow = 0;
					if(type != 2 && MaxLevel == 13)
						MaxLevel = -1;
					char sBuf[255]={0};
					wsprintf(sBuf,"%d\t%d\t%d\t%d\t%d",i,j,type,Glow,MaxLevel);
					//WriteTxt("Item.log",sBuf);
					BuxConvert(sBuf,strlen(sBuf));
					WriteTxt("Item.ttc",sBuf);
				}
		}
	}	
	
	//ReadItemFile("Item.ttc");
	exit(1);
	return 1;
}

void ReadItemFile(LPSTR FileName)
{
	int LineCount=0;
	FILE *fp;
	char sLineTxt[255] = {0};
	BOOL bRead = FALSE;
	
	char path[255]; 

	if((fp=fopen(FileName, "r")) == NULL)
	{
		return;
	}

	rewind(fp);
		
	while(fgets(sLineTxt, 255, fp) != NULL)
	{
		BuxConvert(sLineTxt,strlen(sLineTxt));		

		if(strlen(sLineTxt)>10)
		{
			int Type,ID,IT,Glow,ILM=0;
			sscanf(sLineTxt, "%d %d %d %d %d", &Type,&ID,&IT,&Glow,&ILM);
			char sBuf[255]={0};
			wsprintf(sBuf,"%d\t%d\t%d\t%d\t%d",Type,ID,IT,Glow,ILM);
			WriteTxt("Item2.log",sBuf);
		}else
		{
			int Type,start=0;
			sscanf(sLineTxt, "%d %d", &Type,&start);
			char sBuf[255]={0};
			wsprintf(sBuf,"%d\t%d",Type,start);
			WriteTxt("Item2.log",sBuf);

		}
	}

	rewind(fp);
	fclose(fp);
}