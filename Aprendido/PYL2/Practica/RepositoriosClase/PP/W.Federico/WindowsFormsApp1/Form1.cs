using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.textBox1.Text = "hola mundo!!!"; //aca llamo lo que pongo dentro del texto


            this.Text = "no se que hace"; //esto cambia el titulo


            int cantidad = 5;

            int[] vec = new int[cantidad];/*arrays de enteros*/
            vec[0] = 1;


            for (int i = 0; i < vec.Length; i++)
            {
                MessageBox.Show(vec[i].ToString());
            }



            foreach (var item in vec) //no hay items, mas simple
            {
                MessageBox.Show(item.ToString());
            }

            Button[] botones = new Button[2];

            botones[0] = new Button();

            botones.SetValue(new Button(), 1);


            foreach (Button item in botones) //no hay items, mas simple
            {
                MessageBox.Show(item.ToString());
            }

            /*string a = "afdagv";
            a.CompareTo("asd");
            string.Compare();*/

            StringBuilder sb = new StringBuilder();

            sb.Append("hola:   "); //console.write
            sb.AppendLine(" mundo!!!"); //console.wrteline
            sb.AppendFormat("asdasdaasd {0}", "aaaaaaa"); //Console.writeline("adasdasdas {0}", 5)

            string b = sb.ToString();


        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Text = this.textBox1.Text;
            this.BackColor = Color.Blue;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Text = this.textBox1.Text;   //esto captura la accion
            this.BackColor = Color.Red;


        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e) //rayito mas doble clic del formulario abre esto del color del panel o lo que seleccione
        {

        }

        private void Form1_DoubleClick(object sender, EventArgs e) //si hacemos doble clic cuando se esta ejecutando cualquier boton, para el codigo y nos manda donde queremos editar
        {

        }// el comentario de arriba nada que ver con la funcion donde esta el comentario
    }
}
