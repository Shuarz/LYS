using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;

namespace Entidades
{
    /// <summary>
    /// Clase publica que hereda de vehículo.
    /// </summary>
    public class Sedan : Vehiculo
    {
        #region "enumerados"
        /// <summary>
        /// enum con el tipo de sedan
        /// </summary>
        public enum ETipo 
        { 
            CuatroPuertas, 
            CincoPuertas 
        }
        #endregion

        #region "atributos"
        /// <summary>
        /// atributo privado
        /// </summary>
        private ETipo tipo;
        #endregion

        #region "propiedades"
        /// <summary>
        /// solo lectura, los sedan son medianos
        /// </summary>
        public override ETamanio Tamanio
        {
            get
            {
                return ETamanio.Mediano;
            }
        }
        #endregion

        #region "constructores"
        /// <summary>
        /// constructor de tipo sedan
        /// Por defecto, TIPO será CuatroPuertas
        /// </summary>
        /// <param name="marca">marca del auto</param>
        /// <param name="chasis">marca del auto</param>
        /// <param name="color">marca del auto</param>
        public Sedan(EMarca marca, string chasis, ConsoleColor color, ETipo tipo)
            : base(chasis, marca, color)
        {
            this.tipo = tipo;
        }

        /// <summary>
        /// constructor de tipo sedan, atributo por defecto cuatro puertas
        /// </summary>
        /// <param name="marca">marca del auto</param>
        /// <param name="chasis">marca del auto</param>
        /// <param name="color">marca del auto</param>
        public Sedan(EMarca marca, string chasis, ConsoleColor color)
            : this(marca, chasis, color, ETipo.CuatroPuertas)
        {

        }
        #endregion




        /*
        /// <summary>
        /// Los automoviles son medianos
        /// </summary>
        protected override short Tamanio
        {
            get
            {
                return this.Tamanio;
            }
        }
        */

        #region "metodos"
        /// <summary>
        /// metodo sellado, muestra la informacion del sedan con la informacion heredada
        /// </summary>
        /// <returns>cadena con los datos del sedan>
        public override sealed string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("SEDAN");
            sb.AppendLine(base.Mostrar());
            sb.AppendFormat("TAMAÑO : {0}", this.Tamanio);
            sb.AppendLine("TIPO : " + this.tipo);
            sb.AppendLine("");
            sb.AppendLine("---------------------");

            return sb.ToString();
        }
        #endregion
    }
}
