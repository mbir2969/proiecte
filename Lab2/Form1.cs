using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace Lab2
{
    public partial class Form1 : Form
    {
        SqlConnection sqlConnection = new SqlConnection("Data Source=DESKTOP-B1L5VUV\\SQLEXPRESS;Initial Catalog=Spital;Integrated Security=True");
        SqlDataAdapter adapter = new SqlDataAdapter();
        DataSet parentDataSet = new DataSet();
        DataSet childDataSet = new DataSet();


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void showParentButton_Click(object sender, EventArgs e)
        {
            //string connectionString = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
            try
            {
                //SqlConnection sqlConnection = new SqlConnection(connectionString);
                string parentTable = ConfigurationManager.AppSettings["parentTable"];
                adapter.SelectCommand = new SqlCommand("SELECT * FROM " + parentTable, sqlConnection);
                parentDataSet.Clear();
                adapter.Fill(parentDataSet);
                dataGridView1.DataSource = parentDataSet.Tables[0];
            }
            catch (Exception ex)
            { 
                MessageBox.Show(ex.Message);
            }

        }

        
        private void showChildButton_Click(object sender, EventArgs e)
        {
            //String connectionString = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
            //SqlConnection sqlConnection = new SqlConnection(connectionString);
            try
            {
                String childTable = ConfigurationManager.AppSettings["childTable"];
                String childTableForeignKey = ConfigurationManager.AppSettings["childTableForeignKey"];
                adapter.SelectCommand = new SqlCommand("Select * from " + childTable + " where " + childTableForeignKey + "=@childTableFK", sqlConnection);
                adapter.SelectCommand.Parameters.Add("@childTableFK", SqlDbType.Int).Value = parentDataSet.Tables[0].Rows[dataGridView1.SelectedRows[0].Index][0];
                childDataSet.Clear();
                adapter.Fill(childDataSet);
                dataGridView2.DataSource = childDataSet.Tables[0];
            } catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                sqlConnection.Close();
            }

        }

      
        private void addButton_Click(object sender, EventArgs e)
        {
            //String connectionString = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
            //SqlConnection sqlConnection = new SqlConnection(connectionString);
            try
            {
                String childTable = ConfigurationManager.AppSettings["childTable"];
                String columnNames = ConfigurationManager.AppSettings["ColumnNames"];
                String columnInsertParameters = ConfigurationManager.AppSettings["ColumnNamesInsertParameters"];
                List<String> columnNamesList =
                    new List<String>(ConfigurationManager.AppSettings["ColumnNames"].Split(','));
                SqlCommand sqlCommand =
                    new SqlCommand(
                        "INSERT INTO " + childTable + "(" + columnNames + ") VALUES (" + columnInsertParameters + ")",
                        sqlConnection);
                foreach (String columnName in columnNamesList)
                {
                    TextBox textBox = (TextBox) panel1.Controls[columnName];
                    sqlCommand.Parameters.AddWithValue("@" + columnName, textBox.Text);
                }
                sqlConnection.Open();
                sqlCommand.ExecuteNonQuery();
                childDataSet.Clear();
                adapter.Fill(childDataSet);
                sqlConnection.Close();
                MessageBox.Show("Adaugare realizata cu succes!");
            }catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                sqlConnection.Close();
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            //String connectionString = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
            //SqlConnection sqlConnection = new SqlConnection(connectionString);
            try
            {
                String childTable = ConfigurationManager.AppSettings["childTable"];
                String childTablePrimaryKey = ConfigurationManager.AppSettings["childTablePrimaryKey"];
                SqlCommand sqlCommand =
                    new SqlCommand(" DELETE FROM " + childTable + " WHERE " + childTablePrimaryKey + "=@childTablePK",
                        sqlConnection);
                sqlConnection.Open();
                sqlCommand.Parameters.AddWithValue("@childTablePK",
                    Int32.Parse(dataGridView2.CurrentRow.Cells[childTablePrimaryKey].Value.ToString()));
                sqlCommand.ExecuteNonQuery();
                childDataSet.Clear();
                adapter.Fill(childDataSet);
                sqlConnection.Close();
                MessageBox.Show("Stergere realizata cu succes!");
            }catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
                sqlConnection.Close();
            }
        }

        private void modifyButton_Click(object sender, EventArgs e)
        {
            //String connectionString = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
            //SqlConnection sqlConnection = new SqlConnection(connectionString);
            try
            {
                String childTable = ConfigurationManager.AppSettings["childTable"];
                String childPrimaryKey = ConfigurationManager.AppSettings["childTablePrimaryKey"];
                String columnNames = ConfigurationManager.AppSettings["ColumnNames"];
                List<String> columnNamesList =
                    new List<String>(ConfigurationManager.AppSettings["ColumnNames"].Split(','));
                String updateQuery = ConfigurationManager.AppSettings["UpdateQuery"];
                SqlCommand sqlCommand = new SqlCommand(updateQuery, sqlConnection);
                int childTablePK = Int32.Parse(dataGridView2.CurrentRow.Cells[childPrimaryKey].Value.ToString());
                sqlCommand.Parameters.AddWithValue("@ChildID", childTablePK);
                foreach (String columnName in columnNamesList)
                {
                    TextBox textBox = (TextBox) panel1.Controls[columnName];
                    sqlCommand.Parameters.AddWithValue("@" + columnName, textBox.Text);
                }
                sqlConnection.Open();
                sqlCommand.ExecuteNonQuery();
                childDataSet.Clear();
                adapter.Fill(childDataSet);
                sqlConnection.Close();
                MessageBox.Show("Modificare realizata cu succes!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                sqlConnection.Close();
            }
        }
        
        private void generateTextFieldButton_Click(object sender, EventArgs e)
        {
            try
            {
                List<String> columnNames = new List<String>(ConfigurationManager.AppSettings["ColumnNames"].Split(','));
                int pointX = 30;
                int pointY = 40;
                panel1.Controls.Clear();
                foreach (String columnName in columnNames)
                {
                    TextBox textBox = new TextBox();
                    textBox.Text = columnName;
                    textBox.Name = columnName;
                    textBox.Location = new Point(pointX, pointY);
                    textBox.Visible = true;
                    textBox.Parent = panel1;
                    panel1.Show();
                    pointY += 30;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        
        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            
        }
    }
}