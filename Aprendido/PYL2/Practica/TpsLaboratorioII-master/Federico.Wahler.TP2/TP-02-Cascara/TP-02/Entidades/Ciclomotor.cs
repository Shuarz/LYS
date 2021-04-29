using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    /// <summary>
    /// Clase publica que hereda de vehículo.
    /// </summary>
    public class Ciclomotor : Vehiculo
    {

        #region "propiedades"
        /// <summary>
        /// solo lectura, las motos son chicas
        /// </summary>
        public override ETamanio Tamanio
        {
            get
            {
                return ETamanio.Chico;
            }
        }
        #endregion

        #region "constructor"
        /// <summary>
        /// constructor tipo ciclomotor
        /// </summary>
        /// <param name="marca">marca de la moto</param>
        /// <param name="chasis">chasis de la moto</param>
        /// <param name="color">color de la moto</param>
        public Ciclomotor(EMarca marca, string chasis, ConsoleColor color)
            :base(chasis, marca, color)
        {

        }
        #endregion

        #region "metodos"
        /// <summary>
        /// metodo sellado, muestra la informacion del ciclomotor con la informacion heredada
        /// </summary>
        /// <returns>cadena con los datos de un ciclomotor</returns>
        public override sealed string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("CICLOMOTOR");
            sb.AppendLine(base.Mostrar());
            sb.AppendFormat("TAMAÑO : {0}", this.Tamanio);
            sb.AppendLine("");
            sb.AppendLine("---------------------");

            return sb.ToString();
        }
        #endregion
    }
}
