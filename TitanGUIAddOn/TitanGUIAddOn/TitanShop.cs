using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace TitanGUIAddOn
{
    public partial class TitanShop : Form
    {
        private byte MaxExc;
        private byte MaxOpt;
        private byte MaxLevel;
        private byte MaxLuck;
        private byte MaxSkill;
        private byte MaxHarmony;
        private int valLevel;
        private int valOpt;
        private int valExc;
        private int valLuck;
        private int valSkill;
        private int valHarmony;
        private int VipMoney;

        private string Web1;
        private string Web2;

        public int retItemType;
        public int retItemIndex;
        public byte retDays;
        public byte retLevel;
        public byte retOpt;
        public byte retExc;
        public byte retLuck;
        public byte retSkill;
        public byte retHarmony;

        public void LoadWebs(string web1, string web2)
        {
            Web1 = web1;
            Web2 = web2;
        }

        public void LoadMaxs(byte maxexc,byte maxopt,byte maxlevel,byte maxluck,byte maxskill,byte maxharmony)
        {
            MaxExc = maxexc;
            MaxOpt = maxopt;
            MaxLevel = maxlevel;
            MaxLuck = maxluck;
            MaxSkill = maxskill;
            MaxHarmony = maxharmony;
        }

        public void LoadValues(int vipmoney,int vallevel,int valopt,int valexc,int valluck,int valskill,int valharmony)
        {
            VipMoney = vipmoney;
            valLevel = vallevel;
            valOpt = valopt;
            valExc = valexc;
            valLuck = valluck;
            valSkill = valskill;
            valHarmony = valharmony;
        }

        public TitanShop()
        {
            InitializeComponent();
        }

        cTitanShop readShop = new cTitanShop();

        public bool TryClose = false;

        private void ChangeEnabled()
        {
            if (MaxLevel == 0)
                comboLevel.Enabled = false;
            else
                comboLevel.Enabled = true;
            if (MaxOpt == 0)
                comboOpt.Enabled = false;
            else
                comboOpt.Enabled = true;
            if (MaxLuck == 0)
                checkLuck.Enabled = false;
            else
                checkLuck.Enabled = true;
            if (MaxSkill == 0)
                checkSkill.Enabled = false;
            else
                checkSkill.Enabled = true;
        }

        public void LoadData()
        {
            readShop.ReadShop(Application.StartupPath + @"\Data\Local\Titan_VipShop.txt");
        }

        private void TitanShop_Load(object sender, EventArgs e)
        {
            for (int i = 0; i < cTitanShop.MaxType; i++)
            {
                comboType.Items.Add(readShop.item[i].Name);
            }
            comboLevel.Items.Clear();

            for (int i = 0; i < MaxLevel + 1; i++)
                comboLevel.Items.Add(i.ToString());

            for (int i = 0; i < MaxOpt + 1; i++)
                comboOpt.Items.Add((i*4).ToString());

            ChangeEnabled();

            credits.Text = VipMoney.ToString();
            comboType.SelectedIndex = 0;
            comboIndex.SelectedIndex = 0;
            comboLevel.SelectedIndex = 0;
            comboOpt.SelectedIndex = 0;

            SetHarmony();
            SetExc();
        }

        private byte GetExcNum()
        {
            int tmp = 0;
            if (checkExc1.Checked == true)
                tmp = tmp + Convert.ToInt32(Math.Pow(2, 0));
            if (checkExc2.Checked == true)
                tmp = tmp + Convert.ToInt32(Math.Pow(2, 1));
            if (checkExc3.Checked == true)
                tmp = tmp + Convert.ToInt32(Math.Pow(2, 2));
            if (checkExc4.Checked == true)
                tmp = tmp + Convert.ToInt32(Math.Pow(2, 3));
            if (checkExc5.Checked == true)
                tmp = tmp + Convert.ToInt32(Math.Pow(2, 4));
            if (checkExc6.Checked == true)
                tmp = tmp + Convert.ToInt32(Math.Pow(2, 5));
            return Convert.ToByte(tmp);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CanGetSkill()
        {
            if (comboType.SelectedIndex < 6)
            {
                if (MaxSkill == 1)
                    checkSkill.Enabled = true;
            }
            else
            {
                checkSkill.Checked = false;
                checkSkill.Enabled = false;
            }
        }

        private void SetExc()
        {
            int ItemIndex = readShop.item[comboType.SelectedIndex].index[comboIndex.SelectedIndex].Num;
            if (comboType.SelectedIndex < 6)
            {
                checkExc1.Text = ("Increases Mana after monster +mana/8");
                checkExc2.Text = ("Increases Live after monster +live/8");
                checkExc3.Text = ("Increase attacking(wizardry)speed +7");
                checkExc4.Text = ("Increase dmg +2%");
                checkExc5.Text = ("Increase dmg +level/20");
                checkExc6.Text = ("Execllent damage rate +10%");
            }
            else if ((comboType.SelectedIndex >= 6 && comboType.SelectedIndex <= 11) || (comboType.SelectedIndex == 13 && (ItemIndex == 30 || (ItemIndex >= 8 && ItemIndex <= 13) || (ItemIndex >= 20 && ItemIndex <= 28))) || (comboType.SelectedIndex == 12 && ((ItemIndex >= 0 && ItemIndex <= 6) || (ItemIndex >= 36 && ItemIndex <= 43) || (ItemIndex >= 200 && ItemIndex <= 263))))
            {
                checkExc1.Text = ("Increases Zen After hunt +40%");
                checkExc2.Text = ("Defense success rate +10%");
                checkExc3.Text = ("Reflect damage +5%");
                checkExc4.Text = ("Damage decrease +4%");
                checkExc5.Text = ("Increase Mana 4%");
                checkExc6.Text = ("Increase HP +4%");
            }
            else
            {
                checkExc1.Enabled = false;
                checkExc2.Enabled = false;
                checkExc3.Enabled = false;
                checkExc4.Enabled = false;
                checkExc5.Enabled = false;
                checkExc6.Enabled = false;
                checkSkill.Enabled = false;
                checkLuck.Enabled = false;
                comboOpt.Enabled = false;
                comboLevel.Enabled = false;
            }
        }
        private void SetHarmony()
        {
            comboHarmony.Items.Clear();
            comboHarmony.Items.Add("No Harmony");
            if (MaxHarmony == 1)
            {
                if (comboType.SelectedIndex >= 0 && comboType.SelectedIndex <= 4)
                {
                    comboHarmony.Items.Add("Min Attack Power");
                    comboHarmony.Items.Add("Max Attack Power");
                    comboHarmony.Items.Add("Strength Requirement");
                    comboHarmony.Items.Add("Agility Requirement");
                    comboHarmony.Items.Add("Attack (Max,Min)");
                    comboHarmony.Items.Add("Critical Damage");
                    comboHarmony.Items.Add("Skill Power");
                    comboHarmony.Items.Add("Attack % Rate");
                    comboHarmony.Items.Add("SD - Rate");
                    comboHarmony.Items.Add("SD Ignore Rate");
                }
                else if (comboType.SelectedIndex >= 6 && comboType.SelectedIndex <= 11)
                {
                    comboHarmony.Items.Add("Defense Power");
                    comboHarmony.Items.Add("Max AG");
                    comboHarmony.Items.Add("Max HP");
                    comboHarmony.Items.Add("HP Auto Rate");
                    comboHarmony.Items.Add("MP Auto Rate");
                    comboHarmony.Items.Add("Defense Success Rate");
                    comboHarmony.Items.Add("Damage Reduction Rate");
                    comboHarmony.Items.Add("SD Rate");
                }
                else if (comboType.SelectedIndex == 5)
                {
                    comboHarmony.Items.Add("Magic Power");
                    comboHarmony.Items.Add("Strength Requirement");
                    comboHarmony.Items.Add("Agility Requirement");
                    comboHarmony.Items.Add("Skill Power");
                    comboHarmony.Items.Add("Critical Damage");
                    comboHarmony.Items.Add("SD - Rate");
                    comboHarmony.Items.Add("Attack % Rate");
                    comboHarmony.Items.Add("SD Ignore Rate");
                }
            }
            comboHarmony.SelectedIndex = 0;
        }

        private void comboType_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                comboIndex.Items.Clear();
                if (readShop.item[comboType.SelectedIndex].IndexCount == 0)
                {
                    ok.Enabled = false;
                    pIndex.Text = "0";
                    comboLevel.SelectedIndex = 0;
                    comboOpt.SelectedIndex = 0;
                    comboHarmony.SelectedIndex = 0;
                    checkLuck.Checked = false;
                    checkSkill.Checked = false;
                    checkExc1.Checked = false;
                    checkExc2.Checked = false;
                    checkExc3.Checked = false;
                    checkExc4.Checked = false;
                    checkExc5.Checked = false;
                    checkExc6.Checked = false;
                    GetTotal();
                }
                else
                {
                    ok.Enabled = true;
                }

                for (int x = 0; x < readShop.item[comboType.SelectedIndex].IndexCount; x++)
                {
                    comboIndex.Items.Add(readShop.item[comboType.SelectedIndex].index[x].Name);
                }
                ChangeEnabled();
                CanGetSkill();
                comboIndex.SelectedIndex = 0;

                SetHarmony();
                SetExc();
            }
            catch (Exception) 
            { }
        }

        private void cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private int GetTotal()
        {
            int Total = Convert.ToInt32(pOpt.Text) + Convert.ToInt32(pLvl.Text) + Convert.ToInt32(pLuck.Text) + Convert.ToInt32(pSkill.Text) + Convert.ToInt32(pExc.Text) + Convert.ToInt32(pIndex.Text);
            if (comboHarmony.SelectedIndex > 0)
                Total += valHarmony;

            pTotal.Text = Total.ToString();

            if (VipMoney >= Total)
                pTotal.ForeColor = System.Drawing.Color.GreenYellow;
            else
                pTotal.ForeColor = System.Drawing.Color.Red;

            return Total;
        }

        private int GetItemIndexVal()
        {
            cTitanShop.IINDEX item = new cTitanShop.IINDEX();
            item = readShop.item[comboType.SelectedIndex].index[comboIndex.SelectedIndex];

            if (day1RButton.Checked == true)
            {
                pIndex.Text = item.Price_1Day.ToString();
            }
            else if (day7RButton.Checked == true)
            {
                pIndex.Text = item.Price_7Days.ToString();
            }
            else if (day30RButton.Checked == true)
            {
                pIndex.Text = item.Price_30Days.ToString();
            }
            else if (dayFRButton.Checked == true)
            {
                pIndex.Text = item.Price_Forever.ToString();
            }
            return Convert.ToInt32(pIndex.Text);
        }

        private void comboIndex_SelectedIndexChanged(object sender, EventArgs e)
        {
            cTitanShop.IINDEX item = new cTitanShop.IINDEX();
            item = readShop.item[comboType.SelectedIndex].index[comboIndex.SelectedIndex];
            GetItemIndexVal();
            int Type = comboType.SelectedIndex;
            if (Type == 7)
                Type = 8;
            else if (Type > 8 && Type < 12)
                Type = 8;

            pictureBox1.ImageLocation = Web1 + Type.ToString() + "-" + item.Num + ".jpg";
            toolTip1.SetToolTip(pictureBox1, item.Equiped);

            if (item.Skill > 0)
                checkSkill.Enabled = true;
            else
            {
                checkSkill.Enabled = false;
                checkSkill.Checked = false;
            }
            GetTotal();
        }

        private void comboLevel_SelectedIndexChanged(object sender, EventArgs e)
        {
            pLvl.Text = (valLevel * Convert.ToInt32(comboLevel.Text)).ToString();
            GetTotal();
        }

        private void comboOpt_SelectedIndexChanged(object sender, EventArgs e)
        {
            pOpt.Text = ((valOpt/4) * Convert.ToInt32(comboOpt.Text)).ToString();
            GetTotal();
        }

        private void checkSkill_CheckedChanged(object sender, EventArgs e)
        {
            if (checkSkill.Checked == true)
                pSkill.Text = valSkill.ToString();
            else
                pSkill.Text = "0";

            GetTotal();
        }

        private void checkLuck_CheckedChanged(object sender, EventArgs e)
        {
            if (checkLuck.Checked == true)
                pLuck.Text = valLuck.ToString();
            else
                pLuck.Text = "0";

            GetTotal();
        }

        private void comboHarmony_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboHarmony.SelectedIndex > 0)
                pHarmony.Text = valHarmony.ToString();
            else
                pHarmony.Text = "0";

            GetTotal();
        }

        private int checkExcCount = 0;
        private void ExcCheck(bool Value)
        {
            if (Value == true)
            {
                checkExcCount++;

                if (checkExcCount >= MaxExc)
                {
                    if (checkExc1.Checked == false)
                        checkExc1.Enabled = false;
                    if (checkExc2.Checked == false)
                        checkExc2.Enabled = false;
                    if (checkExc3.Checked == false)
                        checkExc3.Enabled = false;
                    if (checkExc4.Checked == false)
                        checkExc4.Enabled = false;
                    if (checkExc5.Checked == false)
                        checkExc5.Enabled = false;
                    if (checkExc6.Checked == false)
                        checkExc6.Enabled = false;
                }
            }
            else
            {
                checkExcCount--;

                if (checkExcCount < MaxExc)
                {
                    if (checkExc1.Enabled == false)
                        checkExc1.Enabled = true;
                    if (checkExc2.Enabled == false)
                        checkExc2.Enabled = true;
                    if (checkExc3.Enabled == false)
                        checkExc3.Enabled = true;
                    if (checkExc4.Enabled == false)
                        checkExc4.Enabled = true;
                    if (checkExc5.Enabled == false)
                        checkExc5.Enabled = true;
                    if (checkExc6.Enabled == false)
                        checkExc6.Enabled = true;
                }
            }
            pExc.Text = (valExc * checkExcCount).ToString();
            GetTotal();
        }

        private void checkExc1_CheckedChanged(object sender, EventArgs e)
        {
            ExcCheck(checkExc1.Checked);
        }

        private void checkExc2_CheckedChanged(object sender, EventArgs e)
        {
            ExcCheck(checkExc2.Checked);
        }

        private void checkExc3_CheckedChanged(object sender, EventArgs e)
        {
            ExcCheck(checkExc3.Checked);
        }

        private void checkExc4_CheckedChanged(object sender, EventArgs e)
        {
            ExcCheck(checkExc4.Checked);
        }

        private void checkExc5_CheckedChanged(object sender, EventArgs e)
        {
            ExcCheck(checkExc5.Checked);
        }

        private void checkExc6_CheckedChanged(object sender, EventArgs e)
        {
            ExcCheck(checkExc6.Checked);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Process.Start("IExplore.exe", Web2);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            if (TryClose == true)
            {
                //TryClose = false;
                msg.Close();
                this.Close();
            }
        }

        private void day1RButton_CheckedChanged(object sender, EventArgs e)
        {
            GetItemIndexVal();
            GetTotal();
        }

        private void day7RButton_CheckedChanged(object sender, EventArgs e)
        {
            GetItemIndexVal();
            GetTotal();
        }

        private void day30RButton_CheckedChanged(object sender, EventArgs e)
        {
            GetItemIndexVal();
            GetTotal();
        }

        private void dayFRButton_CheckedChanged(object sender, EventArgs e)
        {
            GetItemIndexVal();
            GetTotal();
        }

        TitanMsgBox msg = new TitanMsgBox();
        private void ok_Click(object sender, EventArgs e)
        {
            if (GetTotal() > VipMoney)
                return;
            if (pIndex.Text == "0")
                return;

            if (day1RButton.Checked == true)
                retDays = 0;
            else if (day7RButton.Checked == true)
                retDays = 1;
            else if (day30RButton.Checked == true)
                retDays = 2;
            else if (dayFRButton.Checked == true)
                retDays = 3;

            retItemType = comboType.SelectedIndex;
            retItemIndex = readShop.item[comboType.SelectedIndex].index[comboIndex.SelectedIndex].Num;
            retLevel = Convert.ToByte(comboLevel.Text);
            retOpt = Convert.ToByte(comboOpt.Text);
            retExc = GetExcNum();
            retHarmony = Convert.ToByte(comboHarmony.SelectedIndex);

            if (checkLuck.Checked == true)
                retLuck = 1;
            if(checkSkill.Checked == true)
                retSkill = 1;

            msg.MessageBoxType("You will buy: " + comboIndex.Text + "\r\nCost: " + pTotal.Text + "\r\n\r\nAre you sure?", MessageBoxButtons.YesNo);
            if (msg.ShowDialog() == DialogResult.Yes)
            {
                DialogResult = DialogResult.OK;
            }
        }
    }
}
