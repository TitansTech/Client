using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace TitanGUIAddOn
{
    public partial class TitanTab : Form
    {
        public TitanTab()
        {
            InitializeComponent();
        }

        private void botTypeTxtBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsDigit(e.KeyChar) || Char.IsControl (e.KeyChar)))
				e.Handled = true;
        }

        private void botSkillTxtBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsDigit(e.KeyChar) || Char.IsControl(e.KeyChar)))
                e.Handled = true;
        }

        private void marryTextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsLetter(e.KeyChar) || Char.IsDigit(e.KeyChar) || Char.IsControl(e.KeyChar)))
				e.Handled = true;
        }

        public void LoadData(string Name, int Divorce, int ForceDivorce, int TraceCost, byte Map, byte Xpos1, byte Ypos1, byte Xpos2, byte Ypos2)
        {
            marryString.Text = Name;
            divorceCostZen.Text = Divorce.ToString() + " Zen";
            fDivorceCostZen.Text = ForceDivorce.ToString() + " Zen";
            traceCostZen.Text = TraceCost.ToString() + " Zen";
            marryX.Text = "X: " + Xpos1.ToString() + " ~ " + Xpos2.ToString();
            marryY.Text = "Y: " + Ypos1.ToString() + " ~ " + Ypos2.ToString();
            marryMap.Text = "Map: " + Map.ToString();
        }

        public virtual void SendText(string str)
        {
        }

        public virtual void SendStatus(byte State)
        {
        }

        public virtual void CheckState()
        {
        }

        public virtual void UseForceDivorce()
        {
        }

        private void postBtn_Click(object sender, EventArgs e)
        {
            SendText("/post " + postTextBox.Text);
            postTextBox.Clear();
        }

        private void botNameTxtBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsLetter(e.KeyChar) || Char.IsDigit(e.KeyChar) || Char.IsControl(e.KeyChar)))
				e.Handled = true;
        }

        private void exitBtn_Click(object sender, EventArgs e)
        {
            CloseMe();
        }

        private void resetcmd_Click(object sender, EventArgs e)
        {
            SendText("/reset");
        }

        private void botInvokeCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet invoke");
        }

        private void botTradeCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet trade");
            CloseMe();
        }

        private void botFollowmeCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet followme");
        }

        private void botFreezeCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet freeze");
        }

        private void botKillCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet kill");
        }

        private void botCloseCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet close");
        }

        private void botPotLifeCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet pothp");
        }

        private void botPotManaCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet potmana");
        }

        private void botRelifeCmd_Click(object sender, EventArgs e)
        {
            SendText("/botpet relife");
        }

        private void botSkillCmd_Click(object sender, EventArgs e)
        {
            if(botSkillTxtBox.Text != "")
                SendText("/botpet skill " + botSkillTxtBox.Text);
        }

        private void botCreateCmd_Click(object sender, EventArgs e)
        {
            if(botTypeTxtBox.Text != "" && (botNameTxtBox.Text != "" && botNameTxtBox.Text.Length > 4))
                SendText("/botpet create " + botTypeTxtBox.Text + " " + botNameTxtBox.Text);
        }

        private void traceBtn_Click(object sender, EventArgs e)
        {
            SendText("/tracemarry");
        }

        private void divorceBtn_Click(object sender, EventArgs e)
        {
            SendText("/divorce");
        }
        private void CloseMe()
        {
            SendStatus(0);
            this.Close();
        }
        private void forcedivorceBtn_Click(object sender, EventArgs e)
        {
            SendText("/forcedivorce");
            UseForceDivorce();
        }

        private void marryAccept_Click(object sender, EventArgs e)
        {
            SendText("/acceptmarry");
        }

        private void marryBtn_Click(object sender, EventArgs e)
        {
            if(marryTextBox.Text != "" && marryTextBox.Text.Length > 4)
                SendText("/marry " + marryTextBox.Text);
        }

        private void TitanTab_Load(object sender, EventArgs e)
        {
            SendStatus(1);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            CheckState();
        }

        private void postTextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                SendText("/post " + postTextBox.Text);
                postTextBox.Clear();
            }
        }
    }
}
