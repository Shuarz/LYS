 using System;

//using static System.Math; //esto sirve para no poner math todo el tiempo y solo pones la accion que necesitas.

//using static System.Console; //esto sirve para lo mismo de arriba pero para todo lo que haga consola.

namespace ConceptosPOO
{
    class Program
    {
        static void Main(string[] args)
        {
            //realizarTarea();


            var miVariable = new { nombre = "juan", edad = 19 };

            Console.WriteLine(miVariable.nombre + " " + miVariable.edad + " ");

            var otraVariable = new { nombre = "ana", edad = 25 };

            miVariable = otraVariable; 


          /*  double raiz = Sqrt(9);

            double potencia = Pow(3, 4);

            WriteLine(raiz);

            WriteLine(potencia);  */

        }

        static void realizarTarea()
        {

            punto origen = new punto();

            punto destino = new punto(128, 80);

            double distancia = origen.distanciaHasta(destino);

            Console.WriteLine($"la distancia entre dos puntos es de: {distancia}");

            Console.WriteLine($"numero de objeto creados: {punto.contadorDeObjetoss()}");
        }
    }
}
