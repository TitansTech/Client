using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Net;
using ICSharpCode.SharpZipLib.Zip;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Threading;


namespace SCFAutoUpdate
{
    public partial class Form1 : Form
    {

        [DllImport("kernel32")]
        private static extern long WritePrivateProfileString(string section, string key, string val, string filePath);
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string section, string key, string def, StringBuilder retVal, int size, string filePath);
        Thread t;

        public Form1()
        {
            InitializeComponent();
        }

        public static string ServerPath;
        public static string GetServerVersion;
        private int ClientVersion;
        private const string INIPath = ".\\SCFAutoUpdate.ini";

        private void Form1_Load(object sender, EventArgs e)
        {
            StringBuilder temp = new StringBuilder(512);
            GetPrivateProfileString("Client", "SCFVersion", "0", temp, 511, ".\\SCFVersion.ini");
            ClientVersion = Convert.ToInt32(temp.ToString());
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Enabled = false;
            t = new Thread(CompareVersions);
            t.IsBackground = true;
            t.Start();

            //CompareVersions();
        }
        private void UnZip(string FileName, string TargetDir)
        {
            FastZip Zip = new FastZip();
            Zip.ExtractZip(FileName, TargetDir, null);
        }

        private void CompareVersions()
        {
            WebClient w = new WebClient();
            int ServerVersion;
            
			try
            {
                ServerVersion = Convert.ToInt32(w.DownloadString(GetServerVersion));
			}catch(Exception ex)
			{
				MessageBox.Show(ex.Message);
                Application.Exit();
				return;
			}
            if (ServerVersion > ClientVersion)
            {
                this.Cursor = Cursors.WaitCursor;
                ProgressTotal.Maximum = ServerVersion - ClientVersion;
                for (int i = ClientVersion; i < ServerVersion; i++)
                {
                    int x = i + 1;
                    ProgressFile.Value = 0;
                    string FileName = "Update" + x + ".zip";
                    bool ok = DownloadChunks(ServerPath + FileName, FileName);
                    try
                    {
                        if(ok == true)
                            UnZip(FileName, Application.StartupPath);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                    if (File.Exists(FileName) == true)
                        File.Delete(FileName);
                    WritePrivateProfileString("Client", "SCFVersion", x.ToString(), ".\\SCFVersion.ini");
                    ProgressTotal.Value += 1; 
                }
            }
            this.Cursor = Cursors.Default;
            w.Dispose();
            Process App = new Process();
            App.StartInfo.FileName = "SCFLauncher.exe";
            App.StartInfo.WorkingDirectory = Application.StartupPath;
            App.Start();
            Application.Exit();
        }

        private bool DownloadChunks(string sURL, string Filename)
        {
            WebRequest URLReq;
            WebResponse URLRes;
            byte[] bBuffer = new byte[1001];
            int iBytesRead = 0;
            try
            {
                URLReq = WebRequest.Create(sURL);
                URLRes = URLReq.GetResponse();
                Stream sChunks = URLReq.GetResponse().GetResponseStream();
                ProgressFile.Maximum = Convert.ToInt32(URLRes.ContentLength);
                FileStream FileStreamer = new FileStream(Filename, FileMode.Create);

                do
                {
                    iBytesRead = sChunks.Read(bBuffer, 0, 1000);
                    FileStreamer.Write(bBuffer, 0, iBytesRead);
                    if (ProgressFile.Value + iBytesRead <= ProgressFile.Maximum)
                    {
                        ProgressFile.Value += iBytesRead;
                    }
                    else
                    {
                        ProgressFile.Value = ProgressFile.Maximum;
                    }
                }
                while (!(iBytesRead == 0));
                ProgressFile.Value = ProgressFile.Maximum;
                sChunks.Close();
                FileStreamer.Close();
                return true;
            }
            catch(Exception)// ex)
            {
                //MessageBox.Show(ex.Message);
                return false;
            }
        }
    }
}
