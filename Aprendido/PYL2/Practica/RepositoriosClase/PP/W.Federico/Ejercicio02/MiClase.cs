using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio02
{
    class MiClase
    {


        //miembros de la clase: atributos y metodos:

        //(*)atributos
        //propiedades
        //constructor
        //(*)metodos
        //sobrecargas


        //estaticos y no estaticos
        private static string cadena;

        public static int entero;

        public static void MetodoUno()
        {
            string algo;
            
            algo = "hola"; //implementacion

            MiClase.cadena = algo;

            Console.WriteLine(algo);
        }

        public static int MetodoDos(string paramUno)
        {
            int valor = int.Parse(paramUno);

            return valor;

            
        }

        public float reales;


        public void MetodoEstatico()
        {
            //en un no estatico se puede usar el this


            Console.WriteLine("no estatico {0} - estatico {1}", this.reales, MiClase.entero); //diferencio lo que es estatico y no estatico, lo que dice clase.entero es estatico, lo otro no
        }                                                       //se usa el termino this para referirnos a un atributo no estatico

        public static void metodoConParametroObj(MiClase obj) //aca puedo poner metodos no estaticos dentro de un estatico
        {
            obj.reales = 99;
            obj.MetodoEstatico();

            MiClase otroObj = new MiClase();

            Console.WriteLine();

            otroObj.reales = 55;

        }

    }
}
