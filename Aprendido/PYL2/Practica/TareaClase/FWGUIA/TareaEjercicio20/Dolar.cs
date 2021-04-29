using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio20
{
    public class Dolar
    {
        private double cantidad;
        private static double cotizRespectoDolar;

        public Dolar()
        {
            cotizRespectoDolar = 1.00;
        }
        public Dolar(double cantidad) : this()
        {
            this.cantidad = cantidad;
        }

        public Dolar(double cantidad, double cotizacion) : this(cantidad)
        {
            cotizRespectoDolar = cotizacion;
        }

        #region conversores explicit e implicit
        public static explicit operator Euro(Dolar d)
        {
            Euro aux = new Euro(d.cantidad / 1.16);
            return aux;
        }

        public static explicit operator Pesos(Dolar d)
        {
            Pesos aux = new Pesos(d.cantidad * 33.88);
            return aux;
        }

        public static implicit operator Dolar(double d)
        {
            Dolar aux = new Dolar(d);
            return aux;
        }

        #endregion

        public double GetCantidad()
        {
            return this.cantidad;
        }

        #region sobrecargas igualdad
        public static bool operator ==(Dolar d, Euro e)
        {
            Euro aux = new Euro(0);
            double diferencia;
            bool retorno = false;

            aux = (Euro)d;
            diferencia = Math.Abs(e.GetCantidad() - aux.GetCantidad());
            if (diferencia < 0.001)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Dolar d, Euro e)
        {
            return !(d == e);
        }

        public static bool operator ==(Dolar d, Pesos p)
        {
            Pesos aux = new Pesos(0);
            double diferencia;
            bool retorno = false;

            aux = (Pesos)d;
            diferencia = Math.Abs(p.GetCantidad() - aux.GetCantidad());
            if (diferencia < 0.001)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Dolar d, Pesos p)
        {
            return !(d == p);
        }

        public static bool operator ==(Dolar d1, Dolar d2)
        {
            bool retorno = false;
            if (d1.cantidad == d2.cantidad)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Dolar d1, Dolar d2)
        {
            return !(d1 == d2);
        }

        public static Dolar operator +(Dolar d, Euro e)
        {
            Dolar aux = new Dolar(e.GetCantidad() * 1.16);
            Dolar suma = new Dolar(d.cantidad + aux.cantidad);
            return suma;
        }

        public static Dolar operator +(Dolar d, Pesos p)
        {
            Dolar aux = new Dolar(p.GetCantidad() / 33.88);
            Dolar suma = new Dolar(d.cantidad + aux.cantidad);
            return suma;
        }

        public static Dolar operator -(Dolar d, Euro e)
        {
            Dolar aux = new Dolar(e.GetCantidad() * 1.16);
            Dolar resta = new Dolar(d.cantidad - aux.cantidad);
            return resta;
        }

        public static Dolar operator -(Dolar d, Pesos p)
        {
            Dolar aux = new Dolar(p.GetCantidad() / 33.88);
            Dolar resta = new Dolar(d.cantidad - aux.cantidad);
            return resta;
        }








        #endregion


    }
}
