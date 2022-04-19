using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace TitanGUIAddOn
{
    public partial class TitanMsgBox : Form
    {
        public TitanMsgBox()
        {
            InitializeComponent();
        }

        private void ok_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Yes;
        }

        private void cancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.No;
        }

        public void MessageBoxType(string Message, MessageBoxButtons btns)
        {
            textLbl.Text = Message;
            if (btns == MessageBoxButtons.YesNo)
            {
                yes.Visible = true;
                no.Visible = true;
            }
            else if (btns == MessageBoxButtons.OK)
            {
                ok.Visible = true;
            }
        }

        private void ok_Click_1(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }
    }
}
