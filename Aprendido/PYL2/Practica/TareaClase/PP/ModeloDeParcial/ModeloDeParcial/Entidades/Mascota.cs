using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Mascota
    {
        
        //atributos en minuscula
        
        private string nombre;
        private string raza;

        //propiedades

        public string Nombre //esto en mayuscula y el get solo lectura en misnucula
        {
            get
            {
                return this.nombre;
            }
        }

        public string Raza
        {
            get
            {
                return this.raza;
            }
        }


        //construcctores


        public Mascota(string nombre, string raza)
        {
            this.nombre = nombre;
            this.raza = raza;
        }


        protected virtual string DatosCompletos()
        {
            return this.nombre + " - " + this.raza;
        }

        protected abstract string Ficha();

        //sobreCargas

        public static bool operator == (Mascota m1, Mascota m2)
        {
            return (m1.nombre == m2.nombre && m1.raza == m2.raza); //accede por los atributos y no la propiedad
        }

        public static bool operator !=(Mascota m1, Mascota m2)
        {
            return (m1 == m2);
        }

    }
}
