using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio20
{
    public class Pesos
    {
        private double cantidad;
        private static double cotizRespectoDolar;


        //private static double valorDelDiaDolar;

        private Pesos()
        {
            cotizRespectoDolar = 1 / 38.33;

        }

        public Pesos(double cantidad) : this()
        {
            this.cantidad = cantidad;
        }

        //Inicializa un atributo estático y uno de instancia???
        public Pesos(double cantidad, double cotizacion) : this(cantidad)
        {
            cotizRespectoDolar = cotizacion;
        }

        #region metodos
        public double GetCantidad()
        {
            return this.cantidad;
        }

        public double GetCotizacino()
        {
            return cotizRespectoDolar;
        }
        #endregion

        #region metodos implicit y explicit
        public static explicit operator Dolar(Pesos p)
        {
            Dolar d = new Dolar(p.cantidad * cotizRespectoDolar);
            return d;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="p"></param>

        //Euros es igual a la cantidad de pesos * cotizacion del dolar * 1,16(valor del euro mayor al dolar)
        //Esta mal. No puede estar el valor del euro dentro de una funcion
        public static explicit operator Euro(Pesos p)
        {
            Euro e = new Euro(p.cantidad * cotizRespectoDolar * 1 / 1.16);
            return e;
        }

        /// <summary>
        /// Devuelve pesos.
        /// </summary>
        /// <param name="d"></param>
        public static implicit operator Pesos(double d)
        {
            Pesos aux = new Pesos(d);
            //aux.cantidad = d;
            return aux;

        }

        /// <summary>
        /// Analiza si las cantidades de pesos y las cantidades de dolares son iguales. 
        /// </summary>
        /// <param name="p"></param>
        /// <param name="d"></param>
        /// <returns></returns>
        public static bool operator ==(Pesos p, Dolar d)
        {
            bool retorno = false;
            Dolar nuevoDolarConvertido = new Dolar(0);
            nuevoDolarConvertido = (Dolar)p;
            double diferencia = Math.Abs(d.GetCantidad() - nuevoDolarConvertido.GetCantidad());
            Console.WriteLine(diferencia);
            Console.ReadKey();
            if (diferencia < 0.0001)
                retorno = true;

            return retorno;
        }
        /// <summary>
        /// Analiza si las cantidades de pesos y las cantidades de dolares son iguales. 
        /// </summary>
        /// <param name="p"></param>
        /// <param name="d"></param>
        /// <returns></returns>
        public static bool operator !=(Pesos p, Dolar d)
        {
            return !(p == d);
        }

        public static bool operator ==(Pesos p, Euro e)
        {
            bool retorno = false;
            Euro nuevoEuroConvertido = new Euro(0);
            nuevoEuroConvertido = (Euro)p;
            double diferencia = Math.Abs(e.GetCantidad() - nuevoEuroConvertido.GetCantidad());
            Console.WriteLine(diferencia);
            Console.ReadKey();
            if (diferencia < 0.0001)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Pesos p, Euro e)
        {
            return !(p == e);
        }

        public static bool operator ==(Pesos p1, Pesos p2)
        {
            bool retorno = false;
            if (p1.cantidad == p2.cantidad)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Pesos p1, Pesos p2)
        {
            return !(p1 == p2);
        }

        public static Pesos operator +(Pesos p, Dolar d)
        {
            Pesos aux = new Pesos(d.GetCantidad());
            Pesos suma = new Pesos(p.cantidad + aux.cantidad);

            return suma;
        }

        public static Pesos operator -(Pesos p, Dolar d)
        {
            Pesos aux = new Pesos(d.GetCantidad());
            Pesos resta = new Pesos(p.cantidad - aux.cantidad);
            return resta;
        }

        // ESTO ESTÁ MAL!!! no puedo tener la cotizacion dentro de una funcion.
        public static Pesos operator +(Pesos p, Euro e)
        {
            Pesos aux = new Pesos(e.GetCantidad() * 38.33 * 1.16);
            Pesos suma = new Pesos(p.cantidad + aux.cantidad);
            return suma;
        }

        public static Pesos operator -(Pesos p, Euro e)
        {
            Pesos aux = new Pesos(e.GetCantidad() * 38.33 * 1.16);
            Pesos resta = new Pesos(p.cantidad - aux.cantidad);
            return resta;
        }
        #endregion


    }
}
