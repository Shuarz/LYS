namespace WindowsForms
{
    partial class FrmDatosPantalla
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelInforma = new System.Windows.Forms.Label();
            this.btnGuardarXml = new System.Windows.Forms.Button();
            this.btnLeerTexto = new System.Windows.Forms.Button();
            this.btnGuardarTexto = new System.Windows.Forms.Button();
            this.btnAlta = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // labelInforma
            // 
            this.labelInforma.Location = new System.Drawing.Point(38, 373);
            this.labelInforma.Name = "labelInforma";
            this.labelInforma.Size = new System.Drawing.Size(265, 57);
            this.labelInforma.TabIndex = 16;
            // 
            // btnGuardarXml
            // 
            this.btnGuardarXml.BackColor = System.Drawing.Color.Silver;
            this.btnGuardarXml.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGuardarXml.Location = new System.Drawing.Point(434, 238);
            this.btnGuardarXml.Name = "btnGuardarXml";
            this.btnGuardarXml.Size = new System.Drawing.Size(101, 47);
            this.btnGuardarXml.TabIndex = 15;
            this.btnGuardarXml.Text = "Guardar archivo xml";
            this.btnGuardarXml.UseVisualStyleBackColor = false;
            this.btnGuardarXml.Click += new System.EventHandler(this.btnGuardarXml_Click);
            // 
            // btnLeerTexto
            // 
            this.btnLeerTexto.BackColor = System.Drawing.Color.Silver;
            this.btnLeerTexto.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnLeerTexto.Location = new System.Drawing.Point(300, 237);
            this.btnLeerTexto.Name = "btnLeerTexto";
            this.btnLeerTexto.Size = new System.Drawing.Size(101, 48);
            this.btnLeerTexto.TabIndex = 14;
            this.btnLeerTexto.Text = "Leer datos";
            this.btnLeerTexto.UseVisualStyleBackColor = false;
            this.btnLeerTexto.Click += new System.EventHandler(this.btnLeerTexto_Click);
            // 
            // btnGuardarTexto
            // 
            this.btnGuardarTexto.BackColor = System.Drawing.Color.Silver;
            this.btnGuardarTexto.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGuardarTexto.Location = new System.Drawing.Point(167, 237);
            this.btnGuardarTexto.Name = "btnGuardarTexto";
            this.btnGuardarTexto.Size = new System.Drawing.Size(101, 48);
            this.btnGuardarTexto.TabIndex = 13;
            this.btnGuardarTexto.Text = "Guardar datos";
            this.btnGuardarTexto.UseVisualStyleBackColor = false;
            this.btnGuardarTexto.Click += new System.EventHandler(this.btnGuardarTexto_Click);
            // 
            // btnAlta
            // 
            this.btnAlta.BackColor = System.Drawing.Color.Silver;
            this.btnAlta.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAlta.Location = new System.Drawing.Point(41, 237);
            this.btnAlta.Name = "btnAlta";
            this.btnAlta.Size = new System.Drawing.Size(101, 48);
            this.btnAlta.TabIndex = 12;
            this.btnAlta.Text = "AGREGAR UNA VENTA";
            this.btnAlta.UseVisualStyleBackColor = false;
            this.btnAlta.Click += new System.EventHandler(this.btnAlta_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(307, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 20);
            this.label1.TabIndex = 11;
            this.label1.Text = "VENTAS";
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(41, 55);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(590, 166);
            this.dataGridView1.TabIndex = 9;
            // 
            // FrmDatosPantalla
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Teal;
            this.ClientSize = new System.Drawing.Size(673, 298);
            this.Controls.Add(this.labelInforma);
            this.Controls.Add(this.btnGuardarXml);
            this.Controls.Add(this.btnLeerTexto);
            this.Controls.Add(this.btnGuardarTexto);
            this.Controls.Add(this.btnAlta);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridView1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FrmDatosPantalla";
            this.Text = "PANTALLAS";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FrmDatosPantalla_FormClosing);
            this.Load += new System.EventHandler(this.FrmDatosPantalla_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelInforma;
        private System.Windows.Forms.Button btnGuardarXml;
        private System.Windows.Forms.Button btnLeerTexto;
        private System.Windows.Forms.Button btnGuardarTexto;
        private System.Windows.Forms.Button btnAlta;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridView1;
    }
}