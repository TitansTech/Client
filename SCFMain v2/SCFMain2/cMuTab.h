
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;
using namespace TitanGUIAddOn;

struct MarryStruct
{
	bool Recv;
	char Name[11];
	int Divorce;
	int ForceDivorce;
	int TraceCost;
	BYTE Map;
	BYTE X1;
	BYTE Y1;
	BYTE X2;
	BYTE Y2;
};

MarryStruct Marry;

BYTE cTabOpened = 0;

void cTabTextSend(char * Text)
{
	 PMSG_CHATDATA pInfo={0};
	 pInfo.h.c = 0xC6;
	 pInfo.h.headcode = 0;
	 wsprintf(pInfo.chatmsg,"%s",Text);
	 pInfo.h.size = strlen(pInfo.chatmsg) + sizeof(pInfo.chatid) + 4;
	 eng.eDataSend(0,(LPBYTE)&pInfo);
}

void RecvMarryInfo(char * Name, int Divorce, int ForceDivorce,int TraceCost, BYTE Map, BYTE Xpos1, BYTE Ypos1, BYTE Xpos2, BYTE Ypos2)
{
	memcpy(Marry.Name,Name,sizeof(Marry.Name));
	Marry.Divorce = Divorce;
	Marry.ForceDivorce = ForceDivorce;
	Marry.TraceCost = TraceCost;
	Marry.Map = Map;
	Marry.X1 = Xpos1;
	Marry.Y1 = Ypos1;
	Marry.X2 = Xpos2;
	Marry.Y2 = Ypos2;
	Marry.Recv = true;
}

namespace SCFMain2 
{
	public ref class tMuTab:TitanTab
	{
		public: virtual System::Void SendStatus(BYTE State) override
		{
			cTabOpened = State;
		}

		public: virtual System::Void CheckState() override
		{
			if(cTabOpened == 0)
				Close();
		}

		public: System::Void SetData()
		{
			if(Marry.Recv == true)
			{
				LoadData(gcnew String(Marry.Name),Marry.Divorce,Marry.ForceDivorce,Marry.TraceCost,Marry.Map,Marry.X1,Marry.Y1,Marry.X2,Marry.Y2);
			}
		}

		public: virtual System::Void SendText(System::String ^ str) override
		{
			 pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			 size_t convertedChars = 0;
			 size_t  sizeInBytes = ((str->Length + 1) * 2);
			 errno_t err = 0;
			 char *ch = (char *)malloc(sizeInBytes);

			 err = wcstombs_s(&convertedChars, 
						ch, sizeInBytes,
						wch, sizeInBytes);
			 if (err == 0)
			 {
				cTabTextSend(ch);
			 }
		}
	};
}