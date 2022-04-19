namespace TitanGUIAddOn
{
    partial class TitanMsgBox
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TitanMsgBox));
            this.no = new System.Windows.Forms.Button();
            this.yes = new System.Windows.Forms.Button();
            this.textLbl = new System.Windows.Forms.Label();
            this.ok = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // no
            // 
            this.no.BackColor = System.Drawing.Color.Black;
            this.no.BackgroundImage = global::TitanGUIAddOn.Properties.Resources.b_no;
            this.no.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.no.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.no.Location = new System.Drawing.Point(180, 90);
            this.no.Name = "no";
            this.no.Size = new System.Drawing.Size(54, 30);
            this.no.TabIndex = 79;
            this.no.UseVisualStyleBackColor = false;
            this.no.Visible = false;
            this.no.Click += new System.EventHandler(this.cancel_Click);
            // 
            // yes
            // 
            this.yes.BackColor = System.Drawing.Color.Black;
            this.yes.BackgroundImage = global::TitanGUIAddOn.Properties.Resources.b_yes;
            this.yes.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.yes.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.yes.Location = new System.Drawing.Point(120, 90);
            this.yes.Name = "yes";
            this.yes.Size = new System.Drawing.Size(54, 30);
            this.yes.TabIndex = 78;
            this.yes.UseVisualStyleBackColor = false;
            this.yes.Visible = false;
            this.yes.Click += new System.EventHandler(this.ok_Click);
            // 
            // textLbl
            // 
            this.textLbl.BackColor = System.Drawing.Color.Transparent;
            this.textLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textLbl.ForeColor = System.Drawing.Color.DarkGray;
            this.textLbl.Location = new System.Drawing.Point(12, 31);
            this.textLbl.Name = "textLbl";
            this.textLbl.Size = new System.Drawing.Size(328, 52);
            this.textLbl.TabIndex = 80;
            this.textLbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // ok
            // 
            this.ok.BackColor = System.Drawing.Color.Black;
            this.ok.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("ok.BackgroundImage")));
            this.ok.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ok.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.ok.Location = new System.Drawing.Point(149, 90);
            this.ok.Name = "ok";
            this.ok.Size = new System.Drawing.Size(54, 30);
            this.ok.TabIndex = 81;
            this.ok.UseVisualStyleBackColor = false;
            this.ok.Visible = false;
            this.ok.Click += new System.EventHandler(this.ok_Click_1);
            // 
            // TitanMsgBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::TitanGUIAddOn.Properties.Resources.message_back;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(352, 128);
            this.Controls.Add(this.ok);
            this.Controls.Add(this.textLbl);
            this.Controls.Add(this.no);
            this.Controls.Add(this.yes);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "TitanMsgBox";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TitanMsgBox";
            this.TopMost = true;
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button no;
        private System.Windows.Forms.Button yes;
        private System.Windows.Forms.Label textLbl;
        private System.Windows.Forms.Button ok;
    }
}