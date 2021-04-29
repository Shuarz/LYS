using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Excepciones
{
    public class AlumnoRepetidoException : Exception
    {
        #region Constructores
        public AlumnoRepetidoException() 
            : base("Alumno repetido")
        {

        }

        /// <summary>
        /// Constructor con parametros
        /// </summary>
        /// <param name="mensaje">Mensaje</param>
        /// <param name="e">Excepcion</param>
        public AlumnoRepetidoException(string mensaje, Exception e)
            : base(mensaje)
        {

        }
        #endregion

    }
}
