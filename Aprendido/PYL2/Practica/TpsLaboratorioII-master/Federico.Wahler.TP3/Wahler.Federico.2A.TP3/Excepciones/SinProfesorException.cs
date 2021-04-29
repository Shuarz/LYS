using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Excepciones
{
    public class SinProfesorException : Exception
    {
        #region Constructores
        /// <summary>
        /// Constructor por defecto
        /// </summary>
        public SinProfesorException() 
            : base("No hay profesor para la clase.")
        {

        }

        /// <summary>
        /// Constructor con mensaje y excepcion
        /// </summary>
        /// <param name="mensaje">Mensaje de error</param>
        /// <param name="e">Excepcion</param>
        public SinProfesorException(string mensaje, Exception e)
            : base(mensaje)
        {

        }
        #endregion
    }
}
