using System.ComponentModel;

namespace Lab3_Csharp_Interfata
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private IContainer components = null;

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
            this.logOutButton = new System.Windows.Forms.Button();
            this.dataGridViewParticipantiCautati = new System.Windows.Forms.DataGridView();
            this.nume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.varsta = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nrProbe = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.dataGridViewInscrieri = new System.Windows.Forms.DataGridView();
            this.idInscriere = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.numeParticipant = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.varstaParticipant = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.proba = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label2 = new System.Windows.Forms.Label();
            this.sixEightCheckBox = new System.Windows.Forms.CheckBox();
            this.nineElevenCheckBox = new System.Windows.Forms.CheckBox();
            this.twelveFifteenCheckBox = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.fiftyCheckBox = new System.Windows.Forms.CheckBox();
            this.oneHundreadCheckBox = new System.Windows.Forms.CheckBox();
            this.oneThousandCheckBox = new System.Windows.Forms.CheckBox();
            this.fiftyHundreadCheckBox = new System.Windows.Forms.CheckBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxAdaugareNume = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxAdaugareNrProbe = new System.Windows.Forms.TextBox();
            this.butonInscriereParticipant = new System.Windows.Forms.Button();
            this.butonCautareParticipanti = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.textBoxNrParticipanti50m = new System.Windows.Forms.TextBox();
            this.textBoxNrParticipanti100m = new System.Windows.Forms.TextBox();
            this.textBoxParticipanti1000m = new System.Windows.Forms.TextBox();
            this.textBoxParticipanti1500m = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize) (this.dataGridViewParticipantiCautati)).BeginInit();
            ((System.ComponentModel.ISupportInitialize) (this.dataGridViewInscrieri)).BeginInit();
            this.SuspendLayout();
            // 
            // logOutButton
            // 
            this.logOutButton.Location = new System.Drawing.Point(1455, 976);
            this.logOutButton.Name = "logOutButton";
            this.logOutButton.Size = new System.Drawing.Size(126, 44);
            this.logOutButton.TabIndex = 0;
            this.logOutButton.Text = "LogOut";
            this.logOutButton.UseVisualStyleBackColor = true;
            this.logOutButton.Click += new System.EventHandler(this.logOutButton_Click);
            // 
            // dataGridViewParticipantiCautati
            // 
            this.dataGridViewParticipantiCautati.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewParticipantiCautati.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {this.nume, this.varsta, this.nrProbe});
            this.dataGridViewParticipantiCautati.Location = new System.Drawing.Point(676, 49);
            this.dataGridViewParticipantiCautati.Name = "dataGridViewParticipantiCautati";
            this.dataGridViewParticipantiCautati.RowTemplate.Height = 33;
            this.dataGridViewParticipantiCautati.Size = new System.Drawing.Size(905, 397);
            this.dataGridViewParticipantiCautati.TabIndex = 1;
            // 
            // nume
            // 
            this.nume.HeaderText = "Nume";
            this.nume.Name = "nume";
            // 
            // varsta
            // 
            this.varsta.HeaderText = "Varsta";
            this.varsta.Name = "varsta";
            // 
            // nrProbe
            // 
            this.nrProbe.HeaderText = "Numar Probe";
            this.nrProbe.Name = "nrProbe";
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.label1.Location = new System.Drawing.Point(676, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(257, 37);
            this.label1.TabIndex = 2;
            this.label1.Text = "Participanti cautati";
            this.label1.TextAlign = System.Drawing.ContentAlignment.BottomLeft;
            // 
            // dataGridViewInscrieri
            // 
            this.dataGridViewInscrieri.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewInscrieri.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {this.idInscriere, this.numeParticipant, this.varstaParticipant, this.proba});
            this.dataGridViewInscrieri.Location = new System.Drawing.Point(676, 516);
            this.dataGridViewInscrieri.Name = "dataGridViewInscrieri";
            this.dataGridViewInscrieri.RowTemplate.Height = 33;
            this.dataGridViewInscrieri.Size = new System.Drawing.Size(905, 428);
            this.dataGridViewInscrieri.TabIndex = 3;
            // 
            // idInscriere
            // 
            this.idInscriere.HeaderText = "Id Inscriere";
            this.idInscriere.Name = "idInscriere";
            this.idInscriere.Width = 80;
            // 
            // numeParticipant
            // 
            this.numeParticipant.HeaderText = "Nume Participant";
            this.numeParticipant.Name = "numeParticipant";
            // 
            // varstaParticipant
            // 
            this.varstaParticipant.HeaderText = "Varsta Participant";
            this.varstaParticipant.Name = "varstaParticipant";
            // 
            // proba
            // 
            this.proba.HeaderText = "Proba";
            this.proba.Name = "proba";
            // 
            // label2
            // 
            this.label2.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.label2.Location = new System.Drawing.Point(676, 480);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(342, 33);
            this.label2.TabIndex = 4;
            this.label2.Text = "Lista inscrieri";
            // 
            // sixEightCheckBox
            // 
            this.sixEightCheckBox.Location = new System.Drawing.Point(131, 41);
            this.sixEightCheckBox.Name = "sixEightCheckBox";
            this.sixEightCheckBox.Size = new System.Drawing.Size(183, 42);
            this.sixEightCheckBox.TabIndex = 5;
            this.sixEightCheckBox.Text = "6-8 ani";
            this.sixEightCheckBox.UseVisualStyleBackColor = true;
            // 
            // nineElevenCheckBox
            // 
            this.nineElevenCheckBox.Location = new System.Drawing.Point(131, 101);
            this.nineElevenCheckBox.Name = "nineElevenCheckBox";
            this.nineElevenCheckBox.Size = new System.Drawing.Size(183, 38);
            this.nineElevenCheckBox.TabIndex = 6;
            this.nineElevenCheckBox.Text = "9-11 ani";
            this.nineElevenCheckBox.UseVisualStyleBackColor = true;
            // 
            // twelveFifteenCheckBox
            // 
            this.twelveFifteenCheckBox.Location = new System.Drawing.Point(131, 169);
            this.twelveFifteenCheckBox.Name = "twelveFifteenCheckBox";
            this.twelveFifteenCheckBox.Size = new System.Drawing.Size(183, 42);
            this.twelveFifteenCheckBox.TabIndex = 7;
            this.twelveFifteenCheckBox.Text = "12-15 ani";
            this.twelveFifteenCheckBox.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(12, 34);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(95, 31);
            this.label3.TabIndex = 8;
            this.label3.Text = "Varsta:";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(375, 34);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(121, 23);
            this.label4.TabIndex = 9;
            this.label4.Text = "Proba:";
            // 
            // fiftyCheckBox
            // 
            this.fiftyCheckBox.Location = new System.Drawing.Point(481, 39);
            this.fiftyCheckBox.Name = "fiftyCheckBox";
            this.fiftyCheckBox.Size = new System.Drawing.Size(139, 42);
            this.fiftyCheckBox.TabIndex = 10;
            this.fiftyCheckBox.Text = "50 m";
            this.fiftyCheckBox.UseVisualStyleBackColor = true;
            // 
            // oneHundreadCheckBox
            // 
            this.oneHundreadCheckBox.Location = new System.Drawing.Point(481, 99);
            this.oneHundreadCheckBox.Name = "oneHundreadCheckBox";
            this.oneHundreadCheckBox.Size = new System.Drawing.Size(139, 32);
            this.oneHundreadCheckBox.TabIndex = 11;
            this.oneHundreadCheckBox.Text = "100 m";
            this.oneHundreadCheckBox.UseVisualStyleBackColor = true;
            // 
            // oneThousandCheckBox
            // 
            this.oneThousandCheckBox.Location = new System.Drawing.Point(481, 156);
            this.oneThousandCheckBox.Name = "oneThousandCheckBox";
            this.oneThousandCheckBox.Size = new System.Drawing.Size(139, 37);
            this.oneThousandCheckBox.TabIndex = 12;
            this.oneThousandCheckBox.Text = "1000 m";
            this.oneThousandCheckBox.UseVisualStyleBackColor = true;
            // 
            // fiftyHundreadCheckBox
            // 
            this.fiftyHundreadCheckBox.Location = new System.Drawing.Point(481, 221);
            this.fiftyHundreadCheckBox.Name = "fiftyHundreadCheckBox";
            this.fiftyHundreadCheckBox.Size = new System.Drawing.Size(139, 37);
            this.fiftyHundreadCheckBox.TabIndex = 13;
            this.fiftyHundreadCheckBox.Text = "1500 m";
            this.fiftyHundreadCheckBox.UseVisualStyleBackColor = true;
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(12, 223);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(100, 23);
            this.label5.TabIndex = 14;
            this.label5.Text = "Nume:";
            // 
            // textBoxAdaugareNume
            // 
            this.textBoxAdaugareNume.Location = new System.Drawing.Point(131, 217);
            this.textBoxAdaugareNume.Name = "textBoxAdaugareNume";
            this.textBoxAdaugareNume.Size = new System.Drawing.Size(183, 31);
            this.textBoxAdaugareNume.TabIndex = 15;
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(12, 280);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(113, 23);
            this.label6.TabIndex = 16;
            this.label6.Text = "Nr. probe:";
            // 
            // textBoxAdaugareNrProbe
            // 
            this.textBoxAdaugareNrProbe.Location = new System.Drawing.Point(131, 272);
            this.textBoxAdaugareNrProbe.Name = "textBoxAdaugareNrProbe";
            this.textBoxAdaugareNrProbe.Size = new System.Drawing.Size(183, 31);
            this.textBoxAdaugareNrProbe.TabIndex = 17;
            // 
            // butonInscriereParticipant
            // 
            this.butonInscriereParticipant.Location = new System.Drawing.Point(190, 372);
            this.butonInscriereParticipant.Name = "butonInscriereParticipant";
            this.butonInscriereParticipant.Size = new System.Drawing.Size(241, 45);
            this.butonInscriereParticipant.TabIndex = 18;
            this.butonInscriereParticipant.Text = "Inscriere participant";
            this.butonInscriereParticipant.UseVisualStyleBackColor = true;
            this.butonInscriereParticipant.Click += new System.EventHandler(this.butonInscriereParticipant_Click);
            // 
            // butonCautareParticipanti
            // 
            this.butonCautareParticipanti.Location = new System.Drawing.Point(190, 446);
            this.butonCautareParticipanti.Name = "butonCautareParticipanti";
            this.butonCautareParticipanti.Size = new System.Drawing.Size(241, 48);
            this.butonCautareParticipanti.TabIndex = 19;
            this.butonCautareParticipanti.Text = "Cautare participanti";
            this.butonCautareParticipanti.UseVisualStyleBackColor = true;
            this.butonCautareParticipanti.Click += new System.EventHandler(this.butonCautareParticipanti_Click);
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(29, 556);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(338, 30);
            this.label7.TabIndex = 20;
            this.label7.Text = "Nr. participanti inscrisi la 50m:";
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(29, 639);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(338, 33);
            this.label8.TabIndex = 21;
            this.label8.Text = "Nr. participanti inscrisi la 100m:";
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(29, 717);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(338, 36);
            this.label9.TabIndex = 22;
            this.label9.Text = "Nr. participanti inscrisi la 1000m:";
            // 
            // label10
            // 
            this.label10.Location = new System.Drawing.Point(29, 801);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(338, 31);
            this.label10.TabIndex = 23;
            this.label10.Text = "Nr. participanti inscrisi la 1500m: ";
            // 
            // textBoxNrParticipanti50m
            // 
            this.textBoxNrParticipanti50m.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.textBoxNrParticipanti50m.Location = new System.Drawing.Point(477, 555);
            this.textBoxNrParticipanti50m.Name = "textBoxNrParticipanti50m";
            this.textBoxNrParticipanti50m.Size = new System.Drawing.Size(108, 31);
            this.textBoxNrParticipanti50m.TabIndex = 24;
            // 
            // textBoxNrParticipanti100m
            // 
            this.textBoxNrParticipanti100m.Location = new System.Drawing.Point(477, 636);
            this.textBoxNrParticipanti100m.Name = "textBoxNrParticipanti100m";
            this.textBoxNrParticipanti100m.Size = new System.Drawing.Size(108, 31);
            this.textBoxNrParticipanti100m.TabIndex = 25;
            // 
            // textBoxParticipanti1000m
            // 
            this.textBoxParticipanti1000m.Location = new System.Drawing.Point(477, 714);
            this.textBoxParticipanti1000m.Name = "textBoxParticipanti1000m";
            this.textBoxParticipanti1000m.Size = new System.Drawing.Size(108, 31);
            this.textBoxParticipanti1000m.TabIndex = 26;
            // 
            // textBoxParticipanti1500m
            // 
            this.textBoxParticipanti1500m.Location = new System.Drawing.Point(477, 798);
            this.textBoxParticipanti1500m.Name = "textBoxParticipanti1500m";
            this.textBoxParticipanti1500m.Size = new System.Drawing.Size(108, 31);
            this.textBoxParticipanti1500m.TabIndex = 27;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1668, 1032);
            this.Controls.Add(this.textBoxParticipanti1500m);
            this.Controls.Add(this.textBoxParticipanti1000m);
            this.Controls.Add(this.textBoxNrParticipanti100m);
            this.Controls.Add(this.textBoxNrParticipanti50m);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.butonCautareParticipanti);
            this.Controls.Add(this.butonInscriereParticipant);
            this.Controls.Add(this.textBoxAdaugareNrProbe);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBoxAdaugareNume);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.fiftyHundreadCheckBox);
            this.Controls.Add(this.oneThousandCheckBox);
            this.Controls.Add(this.oneHundreadCheckBox);
            this.Controls.Add(this.fiftyCheckBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.twelveFifteenCheckBox);
            this.Controls.Add(this.nineElevenCheckBox);
            this.Controls.Add(this.sixEightCheckBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.dataGridViewInscrieri);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridViewParticipantiCautati);
            this.Controls.Add(this.logOutButton);
            this.Name = "Form2";
            this.Text = "Form2";
            ((System.ComponentModel.ISupportInitialize) (this.dataGridViewParticipantiCautati)).EndInit();
            ((System.ComponentModel.ISupportInitialize) (this.dataGridViewInscrieri)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private System.Windows.Forms.TextBox textBoxNrParticipanti50m;
        private System.Windows.Forms.TextBox textBoxNrParticipanti100m;
        private System.Windows.Forms.TextBox textBoxParticipanti1000m;
        private System.Windows.Forms.TextBox textBoxParticipanti1500m;

        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;

        private System.Windows.Forms.Label label7;

        private System.Windows.Forms.Button butonInscriereParticipant;
        private System.Windows.Forms.Button butonCautareParticipanti;

        private System.Windows.Forms.Label label6;

        private System.Windows.Forms.CheckBox twelveFifteenCheckBox;
        private System.Windows.Forms.CheckBox nineElevenCheckBox;

        private System.Windows.Forms.TextBox textBoxAdaugareNrProbe;

        private System.Windows.Forms.CheckBox fiftyCheckBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxAdaugareNume;

        private System.Windows.Forms.CheckBox sixEightCheckBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.CheckBox fiftyHundreadCheckBox;

        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.CheckBox oneHundreadCheckBox;
        private System.Windows.Forms.CheckBox oneThousandCheckBox;

        private System.Windows.Forms.Label label2;

        private System.Windows.Forms.DataGridViewTextBoxColumn idInscriere;
        private System.Windows.Forms.DataGridViewTextBoxColumn numeParticipant;
        private System.Windows.Forms.DataGridViewTextBoxColumn varstaParticipant;
        private System.Windows.Forms.DataGridViewTextBoxColumn proba;

        private System.Windows.Forms.DataGridView dataGridViewInscrieri;

        private System.Windows.Forms.DataGridViewTextBoxColumn nume;
        private System.Windows.Forms.DataGridViewTextBoxColumn varsta;
        private System.Windows.Forms.DataGridViewTextBoxColumn nrProbe;

        private System.Windows.Forms.Label label1;
        
        private System.Windows.Forms.DataGridView dataGridViewParticipantiCautati;


        private System.Windows.Forms.Button logOutButton;

        #endregion
    }
}