using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntidadesAbstractas;

namespace EntidadesInstanciables
{
    public class Alumno : Universitario
    {
        #region Enumerados

        public enum EEstadoCuenta
        {
            AlDia,
            Deudor,
            Becado,
        }

        #endregion

        #region Atributos

        // Atributo privado para clases que toma.
        private Universidad.EClases claseQueToma;
        // Enumerado privado para estado de cuenta.
        private EEstadoCuenta estadoCuenta;

        #endregion

        #region Constructores
       
        /// <summary>
        /// Constructor por defecto
        /// </summary>
        public Alumno()
        {

        }

        /// <summary>
        /// Constructor que setea atributos y tambien los heredados
        /// </summary>
        public Alumno(int id, string nombre, string apellido, string dni, ENacionalidad nacionalidad, Universidad.EClases claseQueToma) 
            : base(id, nombre, apellido, dni, nacionalidad)
        {
            this.claseQueToma = claseQueToma;
        }

        /// <summary>
        /// Constructor que setea atributos y tambien los del this.
        /// </summary>
        public Alumno(int id, string nombre, string apellido, string dni, ENacionalidad nacionalidad, Universidad.EClases claseQueToma, EEstadoCuenta estadoCuenta) 
            : this(id, nombre, apellido, dni, nacionalidad, claseQueToma)
        {
            this.estadoCuenta = estadoCuenta;
        }



        #endregion

        #region Sobrecargas


        /// <summary>
        /// Sobrecarga de metodo MostrarDatos
        /// </summary>
        /// <returns> Retorna los datos del alumno </returns>

        protected override string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.MostrarDatos());

            switch (this.estadoCuenta)
            {
                case EEstadoCuenta.AlDia:
                    sb.AppendLine("ESTADO DE CUENTA: Cuota al dia");
                    break;

                case EEstadoCuenta.Becado:
                    sb.AppendFormat("ESTADO DE CUENTA: {0}\n", this.estadoCuenta);
                    break;

                case EEstadoCuenta.Deudor:
                    sb.AppendFormat("ESTADO DE CUENTA: {0}\n", this.estadoCuenta);
                    break;

                default:
                    break;
            }
            sb.AppendLine(this.ParticiparEnClase());

            return sb.ToString();
        }

        /// <summary>
        /// Sobrecarga de metodo  ParticiparEnClase. 
        /// </summary>
        /// <returns> La clase que toma </returns>

        protected override string ParticiparEnClase()
        {
            return string.Format("TOMA CLASES DE {0}", this.claseQueToma);
        }

        /// <summary>
        /// Sobrecarga de metodo ToStriong()
        /// </summary>
        /// <returns> Retorna los datos del alumno </returns>

        public override string ToString()
        {
            return this.MostrarDatos();
        }




        /// <summary>
        /// Sobrecarga == del alumno y el estado de una clase.
        /// </summary>
        /// <param name="a">alumno a comparar</param>
        /// <param name="clase">clase a comparar</param>
        /// <returns>TRUE -> Son iguales // FALSE -> No lo son </returns>

        public static bool operator ==(Alumno a, Universidad.EClases clase) 
        {
            bool retorno = false;

            if (a.claseQueToma == clase && a.estadoCuenta != EEstadoCuenta.Deudor)
            {
                retorno = true;
            }

            return retorno;
        }


        /// <summary>
        /// Sobrecarga != del alumno y el estado de una clase.
        /// </summary>
        /// <param name="a"></param>
        /// <param name="clase"></param>
        /// <returns>TRUE -> Son distintos // FALSE -> No lo son </returns>

        public static bool operator !=(Alumno a, Universidad.EClases clase)
        {
            bool retorno = false;

            if (a.claseQueToma != clase)
            {
                retorno = true;
            }

            return retorno;
        }


        #endregion
    }
}
