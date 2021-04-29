using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace MainHamburgueseria
{
    public partial class FrmPpal : Form
    {
        /// <summary>
        /// Atributo hamburgueseria
        /// </summary>
        private Hamburgueseria hamburgueseria;

        /// <summary>
        /// Crea una instancia del formulario
        /// </summary>
        public FrmPpal()
        {
            InitializeComponent();
            hamburgueseria = new Hamburgueseria();
            PaqueteDAO.DatoCargadoBaseDeDatos += new PaqueteDAO.DelegadoDatoCargado(DatoCargadoBaseDeDatos);            
        }

        /// <summary>
        /// Limpia las listas de paquetes ingresados, en viaje y entregados, y vuelve a cargarlas con las listas actualizadas
        /// </summary>
        private void ActualizarEstados()
        {
            this.PedidoTomado.Items.Clear();
            this.PedidoEnProceso.Items.Clear();
            this.PedidoEntregado.Items.Clear();

            foreach (Paquete p in hamburgueseria.Paquetes)
            {
                if (p.Estado == Paquete.EEstado.Ingresado)
                {
                    this.PedidoTomado.Items.Add(p);
                }
                else if (p.Estado == Paquete.EEstado.EnProceso)
                {
                    this.PedidoEnProceso.Items.Add(p);
                }
                else if (p.Estado == Paquete.EEstado.Entregado)
                {
                    this.PedidoEntregado.Items.Add(p);
                }
            }
        }

        /// <summary>
        /// Crea un nuevo paquete y lo agrega a la lista del hamburgueseria, en caso de que su ID no esté repetido. 
        /// Llama a la función que actualiza las listas
        /// </summary>
        /// <param name="sender">Objeto que originó el evento frente al cual se ejecuta la función</param>
        /// <param name="e">Otros datos sobre el evento</param>
        private void btnAgregar_Click(object sender, EventArgs e)
        {
            Paquete paq = new Paquete(this.txtDireccion.Text, this.mtxtTrackingID.Text);
            paq.InformaEstado += new Paquete.DelegadoEstado(paq_InformaEstado);
            try
            {
                hamburgueseria += paq;
            }
            catch (TrackingIdRepetidoException f)
            {
                MessageBox.Show(f.Message, "Paquete repetido", MessageBoxButtons.OK, MessageBoxIcon.Question);
            }
            this.ActualizarEstados();
        }

        /// <summary>
        /// Muestra una lista de los paquetes con su respectiva información y crea un archivo de texto en el escritorio 
        /// con esa misma información
        /// </summary>
        /// <param name="sender">Objeto que originó el evento frente al cual se ejecuta la función</param>
        /// <param name="e">Otros datos sobre el evento</param>
        private void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion<List<Paquete>>((IMostrar<List<Paquete>>)hamburgueseria);
        }

        /// <summary>
        /// Aborta todos los hilos activos antes de cerrar el formulario
        /// </summary>
        /// <param name="sender">Objeto que originó el evento frente al cual se ejecuta la función</param>
        /// <param name="e">Otros datos sobre el evento</param>
        private void FrmPpal_FormClosing(object sender, FormClosingEventArgs e)
        {
            hamburgueseria.FinEntregas();
        }

        /// <summary>
        /// Muestra información de uno o varios paquetes en el visor del formulario. Crea un archivo de texto en el escritorio 
        /// con esa misma información, o, en caso de existir, agrega información
        /// </summary>
        /// <typeparam name="T">Tipo de dato con el que se implementó la interfaz</typeparam>
        /// <param name="elemento">Objeto del cual se obtiene la información de los paquetes</param>
        private void MostrarInformacion<T>(IMostrar<T> elemento)
        {
            if (elemento != null)
            {
                this.rtbMostrar.Text = elemento.MostrarDatos(elemento);
                elemento.MostrarDatos(elemento).Guardar("salida.txt");
            }
        }

        /// <summary>
        /// Muestra información de un paquete en el visor del formulario. Crea un archivo de texto en el escritorio 
        /// con esa misma información o, en caso de existir, agrega información
        /// </summary>
        /// <param name="sender">Objeto que originó el evento frente al cual se ejecuta la función</param>
        /// <param name="e">Otros datos sobre el evento</param>
        private void mostrarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion<Paquete>((IMostrar<Paquete>)PedidoEntregado.SelectedItem);
        }

        /// <summary>
        /// LLama al actualizador de las listas de paquetes
        /// </summary>
        /// <param name="sender">Objeto que originó el evento frente al cual se ejecuta la función</param>
        /// <param name="e">Otros datos sobre el evento</param>
        private void paq_InformaEstado(object sender, EventArgs e)
        {
            if (this.InvokeRequired)
            {
                Paquete.DelegadoEstado d = new Paquete.DelegadoEstado(paq_InformaEstado);
                this.Invoke(d, new object[] { sender, e });
            }
            else
            {
                this.ActualizarEstados();
            }
        }

        /// <summary>
        /// Imprime un mensaje informando que no se ha podido establecer la conexión con la base de datos
        /// </summary>
        /// <param name="mensaje"></param>
        public void DatoCargadoBaseDeDatos(string mensaje)
        {
            MessageBox.Show(mensaje);
        }

        private void FrmPpal_Load(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void mtxtTrackingID_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }
    }
}
