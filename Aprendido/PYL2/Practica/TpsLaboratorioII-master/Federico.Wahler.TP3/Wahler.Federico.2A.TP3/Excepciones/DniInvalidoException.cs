using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Excepciones
{
    public class DniInvalidoException : Exception
    {
        #region Atributos
        // Atributo privado mensaje.
        private string mensaje;

        #endregion

        #region Constructores

        public DniInvalidoException() 
            : base()
        {
        }

        public DniInvalidoException(string message) 
            : base(message)
        {
            this.mensaje = message;
        }


        public DniInvalidoException(Exception e) 
            : base("ERROR. El DNI tiene formato erroneo", e)
        {
        }

        public DniInvalidoException(string message, Exception e) 
            : base(message, e)
        {
            this.mensaje = message;
        }

        #endregion
    }
}

