using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Excepciones;
using System.IO;


namespace Archivos
{
    public class Texto : IArchivo<string>
    {
        /// <summary>
        /// Metodo para guardar.
        /// </summary>
        /// <param name="archivo"> PATH del archivo </param>
        /// <param name="datos"> Datos que se van a guardar </param>
        /// <returns> True -> Guardo los datos // False -> No los guardo </returns>

        public bool Guardar(string archivo, string datos)
        {
            bool retorno = false;

            try
            {
                    using (StreamWriter sm = new StreamWriter(archivo, false))
                    {
                        sm.WriteLine(datos);
                        retorno = true;
                    }

                retorno = true;

            }

            catch (Exception e)
            {
                throw new ArchivosException(e);
            }

            return retorno;
        }

        /// <summary>
        /// Metodo para leer .
        /// </summary>
        /// <param name="archivo"> PATH del archivo </param>
        /// <param name="datos"> Cadena donde se van a guardar los que se va a leer </param>
        /// <returns> True -> Pudo leer los datos // False -> No pudo leer los datos </returns>
        public bool Leer(string archivo, out string datos)
        {
            bool retorno = false;
            datos = null;
       
            try
            {
                    using (StreamReader sr = new StreamReader(archivo))
                    {
                        datos = sr.ReadToEnd();
                    }
                    retorno = true;
            }

            catch (Exception e)
            {
                throw new ArchivosException(e);
            }
            return retorno;
        }
    }
}
