using Microsoft.SqlServer.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Perro : Mascota
    {
        //atributos

        private int edad;
        private bool esAlfa;

        //constructores (la idea de los constructores derivados es sumar lo que ya tenia el anterior a este con las propiedades del anterior)
        public Perro(string nombre, string raza, int edad, bool esAlfa)
            :base(nombre, raza) //llama por herencia al padre  (en el primer constructor se usa el base, en el segundo this)
        {
            this.edad = edad;
            this.esAlfa = esAlfa;
        }

        public Perro(string nombre, string raza)
            :this(nombre, raza, 0, false)
        {

        }

        //metodos

        protected override string Ficha()
        {
            string cadena = null;
            if (this.esAlfa)
                cadena = "Perro - " + base.DatosCompletos() + ", alfa de la manada, edad" + (int)this;
            else
                cadena = "perro - " + base.DatosCompletos() + ", edad" + (int)this;

            return cadena;
        }

        //sobrecarga de operadores

        public static bool operator ==(Perro p1, Perro p2)
        {
            return (Mascota)p1 == (Mascota)p2 && (int)p1 ==(int)p2; //accede por los atributos y no la propiedad (mascota entre parentesis, reutiliza el codigo de comparacion de mascota)
        } //y le agrega la edad del perro

        public static bool operator !=(Perro p1, Perro p2)
        {
            return (p1 == p2);
        }

        public static explicit operator int(Perro p) //esto es para que el int no tire error con una convercion explicita
        {
            return p.edad;
        }


        //sobrecargas de metodos

        public override string ToString()
        {
            return this.Ficha();
        }

        public override bool Equals(object obj) //el equals para comparar cualquier objeto
        {
            bool rta = false;

            if(obj is Perro)
            {
                rta = this == (Perro)obj;
            }

            return rta;
        }



    }
}
