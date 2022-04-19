
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;
using namespace TitanGUIAddOn;


BYTE Opened = 0;

void TitanShop_ItemBuy(int Type, int Index, BYTE Days, BYTE Level, BYTE Opt, BYTE Luck, BYTE Skill, BYTE Exc, BYTE Harmony)
{
	SDHP_BUYSVSHOP pInfo = {0};
	PHeadSubSetB((LPBYTE)&pInfo, 0xFA,0x01, sizeof(pInfo));
	int ID = ITEMGET(Type,Index);
	pInfo.Days = Days;
	pInfo.ItemID = ID;
	pInfo.mLevel = Level;
	pInfo.mOpt = Opt/4;
	pInfo.mLuck = Luck;
	pInfo.mSkill = Skill;
	pInfo.mExc = Exc;
	pInfo.mHarmony = Harmony;
	eng.eDataSend(0,(LPBYTE)&pInfo);
}

namespace SCFMain2 
{
	public ref class tShop
	{
		public: static TitanShop ^titanShop;


		private: static BYTE mLevel;
		private: static BYTE mOpt;
		private: static BYTE mExc;
		private: static BYTE mLuck;
		private: static BYTE mSkill;
		private: static BYTE mHarmony;

		private: static int pLevel;
		private: static int pOpt;
		private: static int pExc;
		private: static int pLuck;
		private: static int pSkill;
		private: static int pHarmony;
		
		public: static int vipMoney;
				 
		private: static System::String ^Web1;
		private: static System::String ^Web2;

		public: static System::Void LoadMaxs(BYTE mexc, BYTE mopt, BYTE mlvl, BYTE mluck, BYTE mskill, BYTE mharmony)
		{
			mLevel = mlvl;
			mOpt = mopt;
			mExc = mexc;
			mLuck = mluck;
			mSkill = mskill;
			mHarmony = mharmony;
		}

		public: static System::Void LoadValues(int plvl, int popt, int pexc, int pluck, int pskill, int pharmony)
		{
			pLevel = plvl;
			pOpt = popt;
			pExc = pexc;
			pLuck = pluck;
			pSkill = pskill;
			pHarmony = pharmony;
		}

		public: static System::Void LoadWebs(System::String ^web1,System::String ^web2)
		{
			Web1 = web1;
			Web2 = web2;
		}

		public: static System::Void Open() 
		{
			if(Opened == 0)
			{
				Opened = 1;
				titanShop = gcnew TitanShop();
				titanShop->TryClose = false;
				titanShop->LoadData();
				titanShop->LoadMaxs(mExc,mOpt,mLevel,mLuck,mSkill,mHarmony);
				titanShop->LoadWebs(Web1,Web2);
				titanShop->LoadValues(vipMoney,pLevel,pOpt,pExc,pLuck,pSkill,pHarmony);
				if(titanShop->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					TitanShop_ItemBuy(titanShop->retItemType,titanShop->retItemIndex,titanShop->retDays,titanShop->retLevel,titanShop->retOpt,titanShop->retLuck,titanShop->retSkill,titanShop->retExc,titanShop->retHarmony);
				}
				Opened = 0;
			}
		}

		public: static System::Void Close() 
		{
			titanShop->TryClose = true;
			Opened = 0;
		}
	};
}