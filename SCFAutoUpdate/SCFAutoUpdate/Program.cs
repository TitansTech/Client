using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SCFAutoUpdate
{
    static class Program
    {
        /// <summary>
        /// Punto de entrada principal para la aplicación.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            try
            {
                if (args.Length > 0)
                {
                    Form1.GetServerVersion = args[0];
                    Form1.ServerPath = args[1];
                }
            }
            catch (Exception)
            {

            }
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
