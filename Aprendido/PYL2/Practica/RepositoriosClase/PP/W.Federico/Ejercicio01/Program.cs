using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio Nro 2"; //le pone titulo a la consola

            Console.Write("hola");
            Console.WriteLine(" mundo."); //la diferencia con el otro es que hace una bajada de linea al final de la frase.

            Console.WriteLine("Ingrese nombre");
            String nombre = Console.ReadLine();

            Console.WriteLine("ingrese edad");
            Int32 edad = int.Parse(Console.ReadLine()); //int32 es el int viejo. el parse me deja convertirlo de string a entero

            Console.WriteLine(nombre);
            Console.WriteLine(edad);



            Console.WriteLine("el nombre es {0} y su edad es {1}", nombre, edad); //el cero es para decir que es lo primero que quiero mostrar, es esta caso el nombre primero, va en la posicion 0

            Console.ReadKey(true); //para parar el codigo, pulsar cualquier tecla para continuar. (este comando toda la ultima tecla que uso el usuario para salir de la consola)

            
        }
    }
}
