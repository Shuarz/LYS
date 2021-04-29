using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadesAbstractas
{
    public abstract class Universitario : Persona
    {
        #region Atributos
    
        // Atributo privado que representa legajo.
        private int legajo;

        #endregion


        #region Constructores
        
        /// <summary>
        /// Constructor por defecto de Universitario.
        /// </summary>

        public Universitario()
            :base()
        {
            this.legajo = 0;
        }

        /// <summary>
        /// Constructor de Universitario con 3 parametros.
        /// Establñece los parametros propios y establece los heredados.
        /// </summary>
        /// <param name="legajo"> Legajo de universitario </param>
        /// <param name="nombre"> Nombre de universitario </param>
        /// <param name="apellido"> Apellido de unviersitario </param>
        /// <param name="dni"> DNI del universitario </param>
        /// <param name="nacionalidad"> Nacionalidad de universitario </param>
        public Universitario(int legajo, string nombre, string apellido, string dni, ENacionalidad nacionalidad) 
            : base(nombre, apellido, dni, nacionalidad)
        {
            this.legajo = legajo;
        }

        #endregion


        #region Metodos

        /// <summary>
        /// Metodo que muestra los datos de Universitaerio.
        /// </summary>
        /// <returns> Datos del universitario </returns>

        protected virtual string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.ToString());
            sb.AppendFormat("LEGAJO NUMERO: {0}", this.legajo);

            return sb.ToString();
        }

        /// <summary>
        /// Metodo abstracto.
        /// </summary>
        protected abstract string ParticiparEnClase();

        #endregion


        #region Sobrecargas

        /// <summary>
        /// Sobrecarga Equals. Compara si 2 son del mismo tipo, y llama a la sobrecarga ==.
        /// </summary> 
        /// <param name="obj"> Objeto que se va a comparar </param>
        /// <returns> True -> Son iguales // False -> No lo son </returns>

        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Universitario)
            {
                rta = this == (Universitario)obj;
            }

            return rta;

        }


        /// <summary>
        /// Sobrecarga del operador ==. Para saber si sus legajos y DNI son iguales.
        /// </summary>
        /// <param name="pg1"> Universitario 1 </param>
        /// <param name="pg2"> Universitario 2 </param>
        /// <returns> True -> Son iguales // False -> No lo son </returns>

        public static bool operator == (Universitario pg1, Universitario pg2)
        {
            bool retorno = false;

            if (pg1.legajo == pg2.legajo || pg1.DNI == pg2.DNI)
            {
                retorno = true;
            }

            return retorno;
        }


        /// <summary>
        /// Sobrecarga del operador !=. Para saber si sus legajos y DNI son distintos.
        /// </summary>
        /// <param name="pg1"> Universitario 1 </param>
        /// <param name="pg2"> Universitario 2 </param>
        /// <returns> True -> Son distintos // False -> No lo son </returns>

        public static bool operator != (Universitario pg1, Universitario pg2)
        {
            return !(pg1 == pg2);
        }


        #endregion


    }

}
