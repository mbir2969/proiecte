using System.Windows.Forms;

namespace Lab2
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
            this.showParentButton = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.showChildButton = new System.Windows.Forms.Button();
            this.addButton = new System.Windows.Forms.Button();
            this.deleteButton = new System.Windows.Forms.Button();
            this.modifyButton = new System.Windows.Forms.Button();
            this.generateTextFieldButton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize) (this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize) (this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // showParentButton
            // 
            this.showParentButton.Location = new System.Drawing.Point(38, 34);
            this.showParentButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.showParentButton.Name = "showParentButton";
            this.showParentButton.Size = new System.Drawing.Size(165, 65);
            this.showParentButton.TabIndex = 0;
            this.showParentButton.Text = "Afisare parinte";
            this.showParentButton.UseVisualStyleBackColor = true;
            this.showParentButton.Click += new System.EventHandler(this.showParentButton_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(38, 106);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 82;
            this.dataGridView1.RowTemplate.Height = 41;
            this.dataGridView1.Size = new System.Drawing.Size(1398, 516);
            this.dataGridView1.TabIndex = 1;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(38, 710);
            this.dataGridView2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 82;
            this.dataGridView2.RowTemplate.Height = 41;
            this.dataGridView2.Size = new System.Drawing.Size(1398, 516);
            this.dataGridView2.TabIndex = 2;
            this.dataGridView2.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellContentClick);
            // 
            // showChildButton
            // 
            this.showChildButton.Location = new System.Drawing.Point(38, 641);
            this.showChildButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.showChildButton.Name = "showChildButton";
            this.showChildButton.Size = new System.Drawing.Size(167, 65);
            this.showChildButton.TabIndex = 3;
            this.showChildButton.Text = "Afisare copil";
            this.showChildButton.UseVisualStyleBackColor = true;
            this.showChildButton.Click += new System.EventHandler(this.showChildButton_Click);
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point(1589, 800);
            this.addButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(198, 65);
            this.addButton.TabIndex = 4;
            this.addButton.Text = "Adaugare";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // deleteButton
            // 
            this.deleteButton.Location = new System.Drawing.Point(1589, 943);
            this.deleteButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.deleteButton.Name = "deleteButton";
            this.deleteButton.Size = new System.Drawing.Size(198, 65);
            this.deleteButton.TabIndex = 5;
            this.deleteButton.Text = "Stergere";
            this.deleteButton.UseVisualStyleBackColor = true;
            this.deleteButton.Click += new System.EventHandler(this.deleteButton_Click);
            // 
            // modifyButton
            // 
            this.modifyButton.Location = new System.Drawing.Point(1589, 869);
            this.modifyButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.modifyButton.Name = "modifyButton";
            this.modifyButton.Size = new System.Drawing.Size(198, 65);
            this.modifyButton.TabIndex = 16;
            this.modifyButton.Text = "Modificare";
            this.modifyButton.UseVisualStyleBackColor = true;
            this.modifyButton.Click += new System.EventHandler(this.modifyButton_Click);
            // 
            // generateTextFieldButton
            // 
            this.generateTextFieldButton.Location = new System.Drawing.Point(1589, 189);
            this.generateTextFieldButton.Name = "generateTextFieldButton";
            this.generateTextFieldButton.Size = new System.Drawing.Size(198, 73);
            this.generateTextFieldButton.TabIndex = 18;
            this.generateTextFieldButton.Text = "Genereaza Text Field";
            this.generateTextFieldButton.UseVisualStyleBackColor = true;
            this.generateTextFieldButton.Click += new System.EventHandler(this.generateTextFieldButton_Click);
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(1528, 306);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(392, 436);
            this.panel1.TabIndex = 19;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1945, 1759);
            this.Controls.Add(this.generateTextFieldButton);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.modifyButton);
            this.Controls.Add(this.deleteButton);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.showChildButton);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.showParentButton);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize) (this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize) (this.dataGridView2)).EndInit();
            this.ResumeLayout(false);
        }

        private System.Windows.Forms.Panel panel1;

        private System.Windows.Forms.Button showParentButton;

        #endregion

        private System.Windows.Forms.Button generateTextFieldButton;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Button showChildButton;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button deleteButton;
        private System.Windows.Forms.Button modifyButton;
    }
}