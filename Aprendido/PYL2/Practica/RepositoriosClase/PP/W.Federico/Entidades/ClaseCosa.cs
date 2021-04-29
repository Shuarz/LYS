using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class ClaseCosa
    {
        //estos son instancias
        public int Entero;


        public string cadena;


        private DateTime fecha;

        //y estas son sobrecargas y constructores y las de abajo
        public ClaseCosa()
        {
            this.Entero = 0;
            this.cadena = "la cadena de la cosa esta vacia";

            this.fecha = DateTime.Now;
        }

        public ClaseCosa(string cadena) : this()  //esto solo se usa en instancias como estas
        {
            this.cadena = cadena;
            this.cadena = cadena;
            this.fecha = DateTime.Now;
        }

        public ClaseCosa(int entero, string cadena, DateTime date)
        {
            this.Entero = entero;
            this.cadena = cadena;
            this.fecha = DateTime.Now;
        }

        //metodos

        public void establecerValor(int Entero)
        {
            this.Entero = Entero;
        }

        public void establecerValor(string cadena)
        {
            this.cadena = cadena;
        }

        public void establecerValor(DateTime fecha)
        {
            this.fecha = fecha;
        }

        public void mostrar()
        {
            StringBuilder sb = new StringBuilder();


            sb.AppendFormat("entero: {0}\n", this.Entero);
            sb.AppendFormat("cadena: {0}\n", this.cadena);
            sb.AppendFormat("fecha: {0:d}\n", this.fecha);

            Console.WriteLine(sb.ToString());

        }


        public static bool operator ==(ClaseCosa c, OtraCosa oc) //para comparar dos cosas de distintas clases
        {
            bool rta = false;

            if (c.Entero == oc.entero && c.cadena == oc.cadena)
            {
                rta = true;
            }

            return rta;

        }

        public static bool operator !=(ClaseCosa c, OtraCosa oc) //para distingur dos cosas de distintas clases
        {
            /* bool rta = false;

             if (c.Entero != oc.entero && c.cadena != oc.cadena)
             {
                 rta = true;
             }

             return rta; 

             if(c == oc)
             {
                 return false;
             }
             else
             {
                 return true;
             }

             if(!(c == oc))
             {
                 return true;
             }
             else
             {
                 return false;
             }

             bool rta = !(c == oc);

             return rta; */

            return !(c == oc);
        }

        public static bool operator ==(ClaseCosa c, ClaseCosa c1)
        {

            if (c.Entero == c1.Entero) //if sin llaves puede cuando es un caso asi
                return true;

            return false;
        }

        public static bool operator !=(ClaseCosa c, ClaseCosa c1)
        {
            return !(c == c1);
        }



        public static bool operator ==(ClaseCosa c, int n)   //siempre tiene que haber un igual y abajo un distinto
        {
            return c.Entero == n;
        }

        public static bool operator !=(ClaseCosa c, int n)
        {
            return !(c.Entero == n);
        }

        public static bool operator ==(int n, ClaseCosa c)   //siempre tiene que haber un igual y abajo un distinto
        {
            return n == c.Entero;
        }

        public static bool operator !=(int n, ClaseCosa c)
        {
            return !(n == c.Entero);


        }

        public static ClaseCosa operator +(ClaseCosa c, ClaseCosa c1) //operador suma
        {
            int rta = c.Entero + c1.Entero;

            ClaseCosa crta = new ClaseCosa();

            crta.Entero = rta;

            return crta;
        }

        public static ClaseCosa operator +(ClaseCosa c, int n) //operador suma
        {
            int rta = c.Entero + n;

            ClaseCosa crta = new ClaseCosa();

            crta.Entero = rta;

            return crta;
        }

    }
}
