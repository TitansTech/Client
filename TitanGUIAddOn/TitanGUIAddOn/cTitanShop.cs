using System;
using System.Collections.Generic;
using System.Text;

namespace TitanGUIAddOn
{
    public class cTitanShop
    {
        public const int MaxType = 16;
        public const int MaxIndex = 512;

        public struct IINDEX
        {
            public int Num;
            public string Name;
            public int Skill;
            public string Equiped;
            public int Price_1Day;
            public int Price_7Days;
            public int Price_30Days;
            public int Price_Forever;
        };
        public struct ITYPE
        {
            public ITYPE(IINDEX[] arr)
            {
                Name = "";
                IndexCount = 0;
                index = arr;
            }
            public string Name;
            public IINDEX[] index;
            public int IndexCount;
        };

        public ITYPE[] item = new ITYPE[MaxType];

        public void ReadShop(string txtPath)
        {
            for (int i = 0; i < MaxType; i++)
            {
                item[i] = new ITYPE(new IINDEX[MaxIndex]);
            }

            int Count = 0;
            int Token;
            ReadScript r = new ReadScript(txtPath);
            while (true)
            {
                int rType = Convert.ToInt32(r.GetToken());

                if (rType == 1)
                {
                    while (true)
                    {
                        Token = Convert.ToInt32(r.GetToken());
                        if (r.TokenString == "end")
                        {
                            break;
                        }
                        if (Count >= MaxType)
                            break;
                        item[Count].Name = r.TokenString;
                        Count++;
                    }
                }
                Token = Convert.ToInt32(r.GetToken());
                rType = Convert.ToInt32(r.TokenNumber);

                if (rType == 2)
                {
                    while (true)
                    {
                        Token = Convert.ToInt32(r.GetToken());
                        if (r.TokenString == "end")
                        {
                            break;
                        }
                        int type = Convert.ToInt32(r.TokenNumber);

                        if (type >= MaxType)
                            System.Windows.Forms.Application.Exit();

                        if (item[type].IndexCount >= MaxIndex)
                            break;

                        Token = Convert.ToInt32(r.GetToken());
                        int Index = Convert.ToInt32(r.TokenNumber);

                        item[type].index[item[type].IndexCount].Num = Index;

                        Token = Convert.ToInt32(r.GetToken());
                        int Skill = Convert.ToInt32(r.TokenNumber);

                        item[type].index[item[type].IndexCount].Skill = Skill;

                        string stat = "";
                        string use = "";

                        Token = Convert.ToInt32(r.GetToken());
                        int Def = Convert.ToInt32(r.TokenNumber);
                        if (Def > 0)
                            stat += "\r\nBasic Defense: " + Def.ToString();

                        Token = Convert.ToInt32(r.GetToken());
                        int DmgMin = Convert.ToInt32(r.TokenNumber);
                        if (DmgMin > 0)
                            stat += "\r\nBasic Min Damage: " + DmgMin.ToString();

                        Token = Convert.ToInt32(r.GetToken());
                        int DmgMax = Convert.ToInt32(r.TokenNumber);
                        if (DmgMax > 0)
                            stat += "\r\nBasic Max Damage: " + DmgMax.ToString();

                        Token = Convert.ToInt32(r.GetToken());
                        int DmgMag = Convert.ToInt32(r.TokenNumber);
                        if (DmgMag > 0)
                            stat += "\r\nBasic Magic Damage: " + DmgMag.ToString();

                        Token = Convert.ToInt32(r.GetToken());
                        int DW = Convert.ToInt32(r.TokenNumber);
                        switch (DW)
                        {
                            case 1:
                                {
                                    use = "\r\nDark Wizard";
                                } break;
                            case 2:
                                {
                                    use = "\r\nSoul Master";
                                } break;
                            case 3:
                                {
                                    use = "\r\nGrand Master";
                                } break;
                        };

                        Token = Convert.ToInt32(r.GetToken());
                        int DK = Convert.ToInt32(r.TokenNumber);
                        switch (DK)
                        {
                            case 1:
                                {
                                    use += "\r\nDark Knight";
                                } break;
                            case 2:
                                {
                                    use += "\r\nBlade Knight";
                                } break;
                            case 3:
                                {
                                    use += "\r\nBlade Master";
                                } break;
                        };

                        Token = Convert.ToInt32(r.GetToken());
                        int ELF = Convert.ToInt32(r.TokenNumber);
                        switch (ELF)
                        {
                            case 1:
                                {
                                    use += "\r\nElf";
                                } break;
                            case 2:
                                {
                                    use += "\r\nMuse Elf";
                                } break;
                            case 3:
                                {
                                    use += "\r\nHigh Elf";
                                } break;
                        };

                        Token = Convert.ToInt32(r.GetToken());
                        int MG = Convert.ToInt32(r.TokenNumber);
                        switch (MG)
                        {
                            case 1:
                                {
                                    use += "\r\nMagic Gladiator";
                                } break;
                            case 3:
                                {
                                    use += "\r\nDuel Master";
                                } break;
                        };

                        Token = Convert.ToInt32(r.GetToken());
                        int DL = Convert.ToInt32(r.TokenNumber);
                        switch (DL)
                        {
                            case 1:
                                {
                                    use += "\r\nDark Lord";
                                } break;
                            case 3:
                                {
                                    use += "\r\nLord Master";
                                } break;
                        };

                        Token = Convert.ToInt32(r.GetToken());
                        int SU = Convert.ToInt32(r.TokenNumber);
                        switch (SU)
                        {
                            case 1:
                                {
                                    use += "\r\nSummoner";
                                } break;
                            case 2:
                                {
                                    use += "\r\nBloody Summoner";
                                } break;
                            case 3:
                                {
                                    use += "\r\nDimension Master";
                                } break;
                        };

                        Token = Convert.ToInt32(r.GetToken());
                        int RF = Convert.ToInt32(r.TokenNumber);
                        switch (RF)
                        {
                            case 1:
                                {
                                    use += "\r\nRage Fighter";
                                } break;
                            case 3:
                                {
                                    use += "\r\nFist Master";
                                } break;
                        };
                        item[type].index[item[type].IndexCount].Equiped = stat + "\r\n\r\nCan be Equiped by" + use;

                        Token = Convert.ToInt32(r.GetToken());
                        int Price_1 = Convert.ToInt32(r.TokenNumber);
                        item[type].index[item[type].IndexCount].Price_1Day = Price_1;
                        Token = Convert.ToInt32(r.GetToken());
                        int Price_7 = Convert.ToInt32(r.TokenNumber);
                        item[type].index[item[type].IndexCount].Price_7Days = Price_7;
                        Token = Convert.ToInt32(r.GetToken());
                        int Price_30 = Convert.ToInt32(r.TokenNumber);
                        item[type].index[item[type].IndexCount].Price_30Days = Price_30;
                        Token = Convert.ToInt32(r.GetToken());
                        int Price_F = Convert.ToInt32(r.TokenNumber);
                        item[type].index[item[type].IndexCount].Price_Forever = Price_F;

                        Token = Convert.ToInt32(r.GetToken());
                        item[type].index[item[type].IndexCount].Name = r.TokenString;

                        item[type].IndexCount++;
                    }
                }
                break;
            }
        }
    }
}
