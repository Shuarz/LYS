using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntidadesAbstractas;

namespace EntidadesInstanciables
{
    public class Profesor : Universitario
    {

                
        #region Atributos
        // Queue privada. 
        private Queue<Universidad.EClases> clasesDelDia;
        // Atributo privado estatico que genera un random.
        private static Random random;


        #endregion


        #region Constructores

        /// <summary>
        /// Constructor estatico. Inicializa el atributo random.
        /// </summary>
        static Profesor()
        {
            Profesor.random = new Random();
        }

        /// <summary>
        /// Constructor por defecto
        /// </summary>
        public Profesor()
            
        {

        }

        /// <summary>
        /// Constructor que inicializa aatributos propios y heredados con base.
        /// </summary>

        public Profesor(int id, string nombre, string apellido, string dni, ENacionalidad nacionalidad) : base(id, nombre, apellido, dni, nacionalidad)
        {
            this.clasesDelDia = new Queue<Universidad.EClases>();
            this._randomClases();
        }
       
        #endregion


        #region Metodos    

        /// <summary>
        /// Metodo que asigna dos clases al atributo clasesDelDia
        /// </summary>
        private void _randomClases()
        {
            int i;

            for (i = 0; i < 2; i++)
            {
                this.clasesDelDia.Enqueue((Universidad.EClases)Profesor.random.Next(0, 3));
            }

        }

        #endregion


        #region Sobrecargas

        /// <summary>
        /// Sobrecarga de metodo ParticiparEnClase()
        /// </summary>
        /// <returns> Retorna el nombre de la clases que da el profesor</returns>
        protected override string ParticiparEnClase()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("CLASES DEL DIA:\n");


            foreach (Universidad.EClases item in this.clasesDelDia)
            {
                sb.AppendLine(item.ToString());
            }

            return sb.ToString();
        }


        /// <summary>
        /// Sobrecarga de metodo MostrarDatos()
        /// </summary>
        /// <returns> Retorna los datos de profesor </returns>
        protected override string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.MostrarDatos());
            sb.AppendLine(this.ParticiparEnClase());
            return sb.ToString();
        }


        /// <summary>
        /// Sobrecara de metodo 
        /// </summary>
        /// <returns> Retorna los datos del profesor </returns>
        public override string ToString()
        {
            return this.MostrarDatos();
        }


        /// <summary>
        /// Sobrecarga operador == El profesor es igual a la clase, si es ese mismo quien la da.
        /// </summary>
        /// <param name="i"> Profesor a comparar </param>
        /// <param name="clase"> Clase a comparar </param>
        /// <returns>TRUE -> Son iguales // False -> No lo son </returns>
        public static bool operator ==(Profesor i, Universidad.EClases clase)
        {
            bool retorno = false;

            foreach (Universidad.EClases item in i.clasesDelDia)
            {
                if (clase == item)
                {
                    retorno = true;
                    break;
                }
            }

            return retorno;
        }

        /// <summary>
        /// Sobrecarga operador == El profesor es distinto a la clase, si es ese mismo quien la da.
        /// </summary>
        /// <param name="i"> Profesor a comparar </param>
        /// <param name="clase"> Clase a comparar </param>
        /// <returns>TRUE -> Son distintos // False -> No lo son </returns>

        public static bool operator !=(Profesor i, Universidad.EClases clase)
        {
            return !(i == clase);
        }




        #endregion

    }
}
