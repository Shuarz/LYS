using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class OtraCosa
    {
        public static string algo;

        public int entero;
        public int entero2;
        public string cadena;


        public OtraCosa(int entero)
        {
            this.entero = entero;
            this.entero2 = entero * 8;
        }

        public static bool operator ==(OtraCosa oc, ClaseCosa c) //para comparar dos cosas de distintas clases
        {
            bool rta = false;

            if (c.Entero == oc.entero && c.cadena == oc.cadena)
            {
                rta = true;
            }

            return rta;

        }

        public static bool operator !=(OtraCosa oc, ClaseCosa c) 
        {
            

            return !(c == oc);
        }


        public static implicit operator OtraCosa(int n)
        {
            return new OtraCosa(n);
        }


        public static explicit operator OtraCosa(string c)
        {
            OtraCosa oc = new OtraCosa(1);
            oc.cadena = c;
            return oc;
        }


        public static implicit operator string (OtraCosa oc)
        {
            return oc.cadena + "  -  "+ oc.entero +"  -  "+ oc.entero2 + "   -  ";
        }

        public static OtraCosa operator ++(OtraCosa oc)
        {
            oc.entero++;
            oc.entero2++;

            return oc;
        }


    }
}
