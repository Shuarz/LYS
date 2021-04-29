using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio19
{
    public class Sumador
    {
        private int cantidadSumas;

        #region constructores
        public Sumador(int cantidadSumas)
        {
            this.cantidadSumas = cantidadSumas;
        }

        public Sumador() : this(0)
        {

        }

        #endregion

        #region metodos
        /// <summary>
        /// Suma dos 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public long Sumar(long a, long b)
        {
            this.cantidadSumas++;
            return a + b;
        }

        public string Sumar(string a, string b)
        {

            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("{0}{1}", a, b);
            this.cantidadSumas++;
            return sb.ToString();
        }

        #endregion

        #region sobrecarga operadores

        public static explicit operator int(Sumador s)
        {
            return s.cantidadSumas;
        }

        public static long operator +(Sumador s1, Sumador s2)
        {
            return s1.cantidadSumas + s2.cantidadSumas;
        }

        public static bool operator |(Sumador s1, Sumador s2)
        {
            bool retorno = false;
            if (s1.cantidadSumas == s2.cantidadSumas)
                retorno = true;

            return retorno;
        }

        #endregion

    }
}
