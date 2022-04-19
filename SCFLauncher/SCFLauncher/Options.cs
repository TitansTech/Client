using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Microsoft.Win32;

namespace SCFLauncher
{
    public partial class Options : Form
    {
        public Options()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string rutaClave = "Software\\Webzen\\Mu\\Config";
                RegistryKey clave = default(RegistryKey);
                clave = Registry.LocalMachine.OpenSubKey(rutaClave, true);
                if ((clave == null))
                {
                    clave = Registry.CurrentUser.CreateSubKey(rutaClave);

                    clave.SetValue("ID", TextBox1.Text);

                    if ((CheckBox1.Checked == true))
                    {
                        clave.SetValue("MusicOnOff", 1);
                    }
                    else
                    {
                        clave.SetValue("MusicOnOff", 0);
                    }

                    if ((CheckBox2.Checked == true))
                    {
                        clave.SetValue("SoundOnOff", 1);
                    }
                    else
                    {
                        clave.SetValue("SoundOnOff", 0);
                    }

                    if ((CheckBox3.Checked == true))
                    {
                        clave.SetValue("WindowMode", 1);
                    }
                    else
                    {
                        clave.SetValue("WindowMode", 0);
                    }

                    if (RadioButton1.Checked == true)
                    {
                        clave.SetValue("Resolution", 0);
                    }
                    else if (RadioButton2.Checked == true)
                    {
                        clave.SetValue("Resolution", 1);
                    }
                    else if (RadioButton3.Checked == true)
                    {
                        clave.SetValue("Resolution", 2);
                    }
                    else if (RadioButton4.Checked == true)
                    {
                        clave.SetValue("Resolution", 3);
                    }

                    clave.Close();
                    clave = null;
                }
                else
                {
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            this.Close();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Options_Load(object sender, EventArgs e)
        {
            int Resolution = 0;
            int Music = 0;
            int Sound = 0;
            int WindowMode = 0;
            try
            {
                string rutaClave = "Software\\Webzen\\Mu\\Config";
                RegistryKey clave = default(RegistryKey);
                clave = Registry.LocalMachine.OpenSubKey(rutaClave, true);
                if ((clave == null))
                {

                    clave = Registry.CurrentUser.CreateSubKey(rutaClave);
                    // clave.SetValue("#X-Upload", ExePath)
                    TextBox1.Text = clave.GetValue("ID").ToString();
                    Resolution = Convert.ToInt32(clave.GetValue("Resolution"));
                    Music = Convert.ToInt32(clave.GetValue("MusicOnOff"));
                    Sound = Convert.ToInt32(clave.GetValue("SoundOnOff"));
                    WindowMode = Convert.ToInt32(clave.GetValue("WindowMode"));
                    if ((Music == 1)) CheckBox1.Checked = true;
                    if ((Sound == 1)) CheckBox2.Checked = true;
                    if ((WindowMode == 1)) CheckBox3.Checked = true;
                    switch ((Resolution))
                    {
                        case 0:
                            RadioButton1.Checked = true;
                            break;
                        case 1:
                            RadioButton2.Checked = true;
                            break;
                        case 2:
                            RadioButton3.Checked = true;
                            break;
                        case 3:
                            RadioButton4.Checked = true;
                            break;
                    }
                    clave.Close();
                    clave = null;
                }
                else
                {
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
