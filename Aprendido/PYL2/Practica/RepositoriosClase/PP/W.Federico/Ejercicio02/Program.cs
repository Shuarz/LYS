using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio02
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("ejer 02");

            //estatico nombre de la clase + punto + miembro -> para acceder

            MiClase.entero = 2;
            MiClase.MetodoUno();
            MiClase.MetodoDos("58");

            MiClase obj = new MiClase(); //metodo constructor


            //no estatico nombre del objeto + punto + miembro -> para acceder

            obj.reales = 5;  //aca podes acceder a metodos no estaticos y publicos obviamnete

            obj.MetodoEstatico();


            //mirar la hora 1:37 de la clase 1/9 dice como es la asignacion de memoria y la diferencia entre lo estatico y no y el cambio que tienen cuando le asignan un valor

            MiClase.metodoConParametroObj(obj);


            MiClase.entero = 8;

            MiClase obj2 = new MiClase();

            obj2.reales = 9;

            obj2.MetodoEstatico();



            Console.ReadKey(); 

        }
    }
}

