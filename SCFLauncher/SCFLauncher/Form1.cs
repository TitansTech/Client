using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Threading;

namespace SCFLauncher
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("kernel32")]
        private static extern long WritePrivateProfileString(string section, string key, string val, string filePath);
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string section, string key, string def, StringBuilder retVal, int size, string filePath);

        private string INILauncher = Application.StartupPath + @"\SCFLauncher.ini";

        private string SkinURL;
        private string GetServerVersion;
        private string ServerPath;
        private int ClientVersion;

        private string name;
        private string home;
        private string forum;
        private string reg;
        private string news1;
        private string news2;
        private Thread Ver_Thread;

        private delegate void ButtonDelegate();

        private void ConnectButton()
        {
            try
            {
                Form1 form1 = (Form1)System.Windows.Forms.Application.OpenForms["Form1"];
                form1.Invoke(new ButtonDelegate(form1.EnableButton), new object[] {  });
            }
            catch (Exception)
            {
            }
        }

        public void EnableButton()
        {
            try
            {
                Connectcmd.BackgroundImage = global::SCFLauncher.Properties.Resources.reg_1;
                Connectcmd.Enabled = true;
            }catch(Exception)
            {}
        }

        public void Start()
        {
            try
            {
                Ver_Thread = new Thread(CompareVersions);
                Ver_Thread.IsBackground = true;
                Ver_Thread.Start();
            }
            catch (Exception)
            { }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                StringBuilder temp = new StringBuilder(512);

                GetPrivateProfileString("Launcher", "SkinURL", "", temp, 511, INILauncher);
                SkinURL = temp.ToString();
                GetPrivateProfileString("AutoUpdate", "ServerVersion", "", temp, 511, INILauncher);
                GetServerVersion = temp.ToString();
                GetPrivateProfileString("AutoUpdate", "UpdatePath", "", temp, 511, INILauncher);
                ServerPath = temp.ToString();
                GetPrivateProfileString("Client", "SCFVersion", "0", temp, 511, ".\\SCFVersion.ini");
                ClientVersion = Convert.ToInt32(temp.ToString());
                GetSkin();
                Start();

                GetPrivateProfileString("Launcher", "Name", "", temp, 511, INILauncher);
                name = temp.ToString();
                GetPrivateProfileString("Launcher", "Home", "", temp, 511, INILauncher);
                home = temp.ToString();
                GetPrivateProfileString("Launcher", "Forum", "", temp, 511, INILauncher);
                forum = temp.ToString();
                GetPrivateProfileString("Launcher", "Reg", "", temp, 511, INILauncher);
                reg = temp.ToString();
                GetPrivateProfileString("Launcher", "News1", "", temp, 511, INILauncher);
                news1 = temp.ToString();
                GetPrivateProfileString("Launcher", "News2", "", temp, 511, INILauncher);
                news2 = temp.ToString();

                GetPrivateProfileString("Launcher", "News1Visible", "0", temp, 511, INILauncher);
                WebBrowser1.Visible = Convert.ToBoolean(Convert.ToInt32(temp.ToString()));
                GetPrivateProfileString("Launcher", "News2Visible", "0", temp, 511, INILauncher);
                WebBrowser2.Visible = Convert.ToBoolean(Convert.ToInt32(temp.ToString()));

                Label3.Text = name;
                WebBrowser1.Navigate(news1);
                WebBrowser2.Navigate(news2);
            }
            catch (Exception)
            {}
        }
        private void GetSkin()
        {
            try
            {
                WebRequest requestPic = WebRequest.Create(SkinURL);
                WebResponse responsePic = requestPic.GetResponse();
                Image webImage = Image.FromStream(responsePic.GetResponseStream());
                this.BackgroundImage = webImage;
            }
            catch (Exception)
            { }
        }

        private void CompareVersions()
        {
            WebClient w = new WebClient();
            int ServerVersion;

            try
            {
                ServerVersion = Convert.ToInt32(w.DownloadString(GetServerVersion));
            }
            catch (Exception)
            {
                MessageBox.Show("Unable to connect with Version Server!");
                return;
            }
            try
            {
                if (ServerVersion > ClientVersion)
                {
                    Process App = new Process();
                    App.StartInfo.FileName = "SCFAutoUpdate.exe";
                    App.StartInfo.Arguments = GetServerVersion + " " + ServerPath;
                    App.StartInfo.WorkingDirectory = Application.StartupPath;
                    App.Start();
                    Application.Exit();
                }
                w.Dispose();
                ConnectButton();
            }
            catch (Exception)
            { }
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Process.Start("IExplore.exe", home);
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            Process.Start("IExplore.exe", forum);
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            Process.Start("IExplore.exe", reg);
        }
        private Point pos;

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            pos = new Point(e.X, e.Y);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Location = new Point(e.X - pos.X + this.Left, e.Y - pos.Y + this.Top);
            }
        }

        private void Connectcmd_Click(object sender, EventArgs e)
        {
            this.TopMost = false;
            Process App = new Process();
            App.StartInfo.FileName = "scfmain.exe";
            App.StartInfo.Arguments = "run";
            App.StartInfo.WorkingDirectory = Application.StartupPath;
            App.Start();
            App.WaitForInputIdle();
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.TopMost = false;
            Options form = new Options();
            form.ShowDialog();
            this.TopMost = true;
        }
    }
}
