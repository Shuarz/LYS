using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Entidades
{
    public class Hamburgueseria : IMostrar<List<Paquete>>
    {
        /// <summary>
        /// Atributos
        /// </summary>
        private List<Thread> mockPaquetes;
        private List<Paquete> paquetes;

        /// <summary>
        /// Propiedad de lectura/escritura del atributo paquetes
        /// </summary>
        public List<Paquete> Paquetes
        {
            get
            {
                return this.paquetes;
            }
            set
            {
                this.paquetes = value;
            }
        }

        /// <summary>
        /// Crea una instancia de la clase Hamburgueseria; inicializa las dos lista de la clase
        /// </summary>
        public Hamburgueseria()
        {
            this.paquetes = new List<Paquete>();
            this.mockPaquetes = new List<Thread>();
        }

        /// <summary>
        /// Permite obtener los datos de una lista de paquetes
        /// </summary>
        /// <param name="elementos">Elemento del cual se busca conocer su lista de paquetes</param>
        /// <returns>Cadena con datos de la lista de paquetes</returns>
        public string MostrarDatos(IMostrar<List<Paquete>> elementos)
        {
            string datos = null;
            Hamburgueseria elementosAux = (Hamburgueseria)elementos;
            foreach (Paquete p in elementosAux.Paquetes)
            {
                datos += string.Format("{0} para {1} ({2})\n", p.TrackingID, p.NumeroPedido, p.Estado.ToString());
            }
            return datos;
        }

        /// <summary>
        /// Agrega una paquete a la lista de paquetes de una hamburgueseria, siempre y cuando no hay un paquete previo con igual ID
        /// Crea e inicia un hilo con el "ciclo de vida" del paquete.
        /// </summary>
        /// <param name="c">Hamburgueseria al cual se agregará el paquete</param>
        /// <param name="p">Paquete a agregar</param>
        /// <returns>Hamburgueseria al cual se intenta agregar el paquete. TrackingIdRepetidoException en caso del que el ID esté repetido</returns>
        public static Hamburgueseria operator +(Hamburgueseria c, Paquete p)
        {
            foreach (Paquete paq in c.Paquetes)
            {
                if (paq == p)
                {
                    throw new TrackingIdRepetidoException("El tracking ID " + p.TrackingID + " ya figura en la lista de envíos");
                }
            }
            c.Paquetes.Add(p);
            Thread hilo = new Thread(p.MockCicloDeVida);
            c.mockPaquetes.Add(hilo);
            hilo.Start();
            return c;
        }

        /// <summary>
        /// Finaliza los hilos que se encuentren activos
        /// </summary>
        public void FinEntregas()
        {
            foreach (Thread hilo in this.mockPaquetes)
            {
                hilo.Abort();
            }
        }

    }
}
