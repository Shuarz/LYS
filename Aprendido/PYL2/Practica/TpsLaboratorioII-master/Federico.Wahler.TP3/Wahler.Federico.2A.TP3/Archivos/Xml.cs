using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

using Excepciones;
namespace Archivos
{
    public class Xml<T> : IArchivo<T>
    {

        /// <summary>
        /// Metodo Guardar ---> De la interfaz IArchivo
        /// </summary>
        /// <param name="archivo"> PATH del archivo </param>
        /// <param name="datos"> Datos a serializar </param>
        /// <returns> TRUE -> Se pudo guardar // FALSE -> No se pudo guardar </returns>
        /// 

        public bool Guardar(string archivo, T datos)
        {
            bool retorno = false;

            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(T));
                XmlTextWriter sw = new XmlTextWriter(archivo, Encoding.UTF8);
                serializer.Serialize(sw, datos);
                sw.Close();
                retorno = true;
            }

            catch (Exception e)
            {
                throw new ArchivosException(e);
            }

            return retorno;

        }

        /// <summary>
        /// Metodo para leer ---> De la interfaz IArchivo
        /// </summary>
        /// <param name="archivo"> PATH del archivo </param>
        /// <param name="datos"> Datos que se van a leer </param>
        /// <returns> TRUE -> Se pudo leer // FALSE -> No se pudo leer </returns>
        /// 

        public bool Leer(string archivo, out T datos)
        {
            bool retorno = false;
            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(T));
                XmlTextReader sr = new XmlTextReader(archivo);
                datos = (T)serializer.Deserialize(sr);
                sr.Close();
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
