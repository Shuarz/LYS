using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio20
{
    public class Euro
    {
        private double cantidad;
        private static double cotizRespectoDolar;
        //FALTA UNA VARIABLE PESO DOLAR PARA LAS CONVERSIONES

        #region constructores
        private Euro()
        {
            cotizRespectoDolar = 1 * 1.16;
        }

        public Euro(double cantidad) : this()
        {
            this.cantidad = cantidad;
        }

        public Euro(double cantidad, double cotizacion) : this(cantidad)
        {
            cotizRespectoDolar = cotizacion;
        }

        #endregion

        #region metodos
        public double GetCantidad()
        {
            return this.cantidad;
        }

        public double GetCotizacion()
        {
            return cotizRespectoDolar;
        }
        #endregion

        #region conversiones explicita e implicita
        public static explicit operator Dolar(Euro e)
        {
            Dolar aux = new Dolar(e.cantidad * cotizRespectoDolar);
            return aux;
        }

        //MAL NO PUEDO PONER DENTRO DE UN MÉTODO EL VALOR DE CONVERSION DE UN DOLAR.!!!
        public static explicit operator Pesos(Euro e)
        {
            //Pesos auxPesos = new Pesos(e.cantidad * 1 / cotizRespectoDolar * 1 / 33.88);         
            Pesos auxPesos = new Pesos(e.cantidad * cotizRespectoDolar * 33.88);

            return auxPesos;
        }

        public static implicit operator Euro(double d)
        {
            Euro aux = new Euro(d);
            return aux;
        }

        #endregion


        #region sobrecargas
        public static bool operator ==(Euro e, Pesos p)
        {
            bool retorno = false;
            Pesos auxiliarEurosEnPesos = new Pesos(0);
            auxiliarEurosEnPesos = (Pesos)e;
            double diferencia = (Math.Abs(p.GetCantidad() - auxiliarEurosEnPesos.GetCantidad()));
            if (diferencia < 0.001)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Euro e, Pesos p)
        {
            return !(e == p);
        }

        public static bool operator ==(Euro e, Dolar d)
        {
            bool retorno = false;
            double diferencia = (Math.Abs(d.GetCantidad() - (e.cantidad * cotizRespectoDolar)));
            if (diferencia < 0.001)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Euro e, Dolar d)
        {
            return !(e == d);
        }

        public static bool operator ==(Euro e1, Euro e2)
        {
            bool retorno = false;
            if (e1.cantidad == e2.cantidad)
                retorno = true;

            return retorno;
        }

        public static bool operator !=(Euro e1, Euro e2)
        {
            return !(e1 == e2);
        }

        public static Euro operator +(Euro e, Dolar d)
        {
            Euro suma = new Euro(0);
            suma = e.cantidad + (d.GetCantidad() / cotizRespectoDolar);
            return suma;
        }

        public static Euro operator +(Euro e, Pesos p)
        {
            Euro suma = new Euro(0);
            Euro auxiliarEuros = new Euro(p.GetCantidad() * 1 / cotizRespectoDolar * 1 / 33.88);

            suma = e.cantidad + auxiliarEuros.cantidad;
            return suma;
        }


        #endregion


    }
}
