using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio02
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "TareaEjercicio02 Nro02";

            
            Int32 numero;
            double cuadrado = 0;
            double cubo = 0;


            Console.WriteLine("Ingrese un numero distinto de cero:");
            numero = int.Parse(Console.ReadLine());

            while (numero == 0)
            {
                Console.WriteLine("Error!");
                
                Console.WriteLine("Ingrese un numero distinto de cero");
                numero = int.Parse(Console.ReadLine());
            }

            
            
            cuadrado = Math.Pow(numero, 2);
            cubo = Math.Pow(numero, 3);
            

            Console.WriteLine("El numero elegido es: {0}", numero);
            Console.WriteLine("El cuadrado es : {0}", cuadrado);
            Console.WriteLine("El cubo es : {0}", cubo);
            Console.ReadKey();


        }
    }
}
