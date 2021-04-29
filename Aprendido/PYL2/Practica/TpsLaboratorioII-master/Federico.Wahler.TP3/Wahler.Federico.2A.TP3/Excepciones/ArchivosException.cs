using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Excepciones
{
    public class ArchivosException : Exception
    {
        #region Constructores
        /// <summary>
        /// constructor por defecto con un mensaje
        /// </summary>
        public ArchivosException() 
            : base("ERROR en el archivo. ")
        {

        }

        /// <summary>
        /// Constructor con un mensaje
        /// </summary>
        /// <param name="mensaje">Mensaje de error</param>
        public ArchivosException(string mensaje) 
            : base(mensaje)
        {

        }

        /// <summary>
        /// Constructor con excepcion
        /// </summary>
        /// <param name="innerException">Excepcion</param>
        public ArchivosException(Exception innerException)
        {

        }
        #endregion

    }
}
