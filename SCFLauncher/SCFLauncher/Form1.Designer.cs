namespace SCFLauncher
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Connectcmd = new System.Windows.Forms.Button();
            this.Button4 = new System.Windows.Forms.Button();
            this.Button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.Button5 = new System.Windows.Forms.Button();
            this.WebBrowser2 = new System.Windows.Forms.WebBrowser();
            this.WebBrowser1 = new System.Windows.Forms.WebBrowser();
            this.Label3 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Connectcmd
            // 
            this.Connectcmd.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Connectcmd.BackgroundImage")));
            this.Connectcmd.Enabled = false;
            this.Connectcmd.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Connectcmd.Location = new System.Drawing.Point(576, 277);
            this.Connectcmd.Name = "Connectcmd";
            this.Connectcmd.Size = new System.Drawing.Size(160, 51);
            this.Connectcmd.TabIndex = 1;
            this.Connectcmd.UseVisualStyleBackColor = true;
            this.Connectcmd.Click += new System.EventHandler(this.Connectcmd_Click);
            // 
            // Button4
            // 
            this.Button4.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Button4.BackgroundImage")));
            this.Button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Button4.Location = new System.Drawing.Point(662, 38);
            this.Button4.Name = "Button4";
            this.Button4.Size = new System.Drawing.Size(74, 20);
            this.Button4.TabIndex = 22;
            this.Button4.UseVisualStyleBackColor = true;
            this.Button4.Click += new System.EventHandler(this.Button4_Click);
            // 
            // Button3
            // 
            this.Button3.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Button3.BackgroundImage")));
            this.Button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Button3.Location = new System.Drawing.Point(582, 38);
            this.Button3.Name = "Button3";
            this.Button3.Size = new System.Drawing.Size(74, 20);
            this.Button3.TabIndex = 21;
            this.Button3.UseVisualStyleBackColor = true;
            this.Button3.Click += new System.EventHandler(this.Button3_Click);
            // 
            // button2
            // 
            this.button2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button2.BackgroundImage")));
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Location = new System.Drawing.Point(502, 38);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(74, 20);
            this.button2.TabIndex = 20;
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Button5
            // 
            this.Button5.BackColor = System.Drawing.Color.Transparent;
            this.Button5.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Button5.ForeColor = System.Drawing.Color.Red;
            this.Button5.Image = global::SCFLauncher.Properties.Resources.Close;
            this.Button5.Location = new System.Drawing.Point(732, 12);
            this.Button5.Name = "Button5";
            this.Button5.Size = new System.Drawing.Size(16, 15);
            this.Button5.TabIndex = 23;
            this.Button5.UseVisualStyleBackColor = false;
            this.Button5.Click += new System.EventHandler(this.Button5_Click);
            // 
            // WebBrowser2
            // 
            this.WebBrowser2.IsWebBrowserContextMenuEnabled = false;
            this.WebBrowser2.Location = new System.Drawing.Point(494, 71);
            this.WebBrowser2.MinimumSize = new System.Drawing.Size(20, 20);
            this.WebBrowser2.Name = "WebBrowser2";
            this.WebBrowser2.ScrollBarsEnabled = false;
            this.WebBrowser2.Size = new System.Drawing.Size(242, 197);
            this.WebBrowser2.TabIndex = 25;
            // 
            // WebBrowser1
            // 
            this.WebBrowser1.IsWebBrowserContextMenuEnabled = false;
            this.WebBrowser1.Location = new System.Drawing.Point(23, 71);
            this.WebBrowser1.MinimumSize = new System.Drawing.Size(20, 20);
            this.WebBrowser1.Name = "WebBrowser1";
            this.WebBrowser1.ScrollBarsEnabled = false;
            this.WebBrowser1.Size = new System.Drawing.Size(457, 246);
            this.WebBrowser1.TabIndex = 24;
            // 
            // Label3
            // 
            this.Label3.AutoSize = true;
            this.Label3.BackColor = System.Drawing.Color.Transparent;
            this.Label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.Label3.Location = new System.Drawing.Point(236, 37);
            this.Label3.Name = "Label3";
            this.Label3.Size = new System.Drawing.Size(71, 20);
            this.Label3.TabIndex = 26;
            this.Label3.Text = "Server: ";
            // 
            // button1
            // 
            this.button1.BackgroundImage = global::SCFLauncher.Properties.Resources.opt_btn;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(494, 295);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 22);
            this.button1.TabIndex = 27;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::SCFLauncher.Properties.Resources.Skin;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(761, 341);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Label3);
            this.Controls.Add(this.WebBrowser2);
            this.Controls.Add(this.WebBrowser1);
            this.Controls.Add(this.Button5);
            this.Controls.Add(this.Button4);
            this.Controls.Add(this.Button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.Connectcmd);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "SCFLauncher";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Connectcmd;
        internal System.Windows.Forms.Button Button4;
        internal System.Windows.Forms.Button Button3;
        internal System.Windows.Forms.Button button2;
        internal System.Windows.Forms.Button Button5;
        internal System.Windows.Forms.WebBrowser WebBrowser2;
        internal System.Windows.Forms.WebBrowser WebBrowser1;
        internal System.Windows.Forms.Label Label3;
        internal System.Windows.Forms.Button button1;

    }
}

