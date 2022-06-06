using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Lab3.model;
using Lab3_Csharp_Interfata.service;

namespace Lab3_Csharp_Interfata
{
    public partial class Form1 : Form
    {
        private Service service;
        public Form1(Service service)
        {
            InitializeComponent();
            this.service = service;
        }

        private Organizator verificaCredentialele(String username, String password)
        {
            return service.verificaCredentialele(username, password);
        }

        private void logInButton_Click(object sender, EventArgs e)
        {
            String username = usernameTextBox.Text;
            String password = passwordTextBox.Text;

            if (verificaCredentialele(username, password) == null)
            {
                usernameTextBox.Text = "";
                passwordTextBox.Text = "";
                MessageBox.Show("Username si/sau parola invalide!", "Credentiale invalide");
            }
            else
            {
                var form2 = new Form2(this.service);
                form2.Size = new Size(740, 600);
                form2.Show();
                this.Hide();
            }
            
        }


        
    }
}