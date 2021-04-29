using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio06
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "TareaEjercicio06 Nro06";

            Int32 añoIngresadoInicio;
            Int32 añoIngresadoFinal;
            Int32 contadorAnios = 0;


            Console.Write("Ingrese un año inicial para calcular: ");
            añoIngresadoInicio = int.Parse(Console.ReadLine());

            Console.Write("Ingrese un año final para calcular: ");
            añoIngresadoFinal = int.Parse(Console.ReadLine());


            if (añoIngresadoInicio >= añoIngresadoFinal)
            {
                Console.WriteLine("ERROR! El año inicial no puede ser mayor o igual al año final");
            }

            else
            {
                Console.Write("Los años bisiestos son: ");

                for (int i = añoIngresadoInicio; i <= añoIngresadoFinal; i++)
                {
                    if ((i % 4) == 0 && (i % 100 != 0 || i % 400 == 0))
                    {
                        Console.Write("{0,7:#,###}", i);
                        contadorAnios++;

                        if (contadorAnios == 10)
                        { Console.WriteLine("\n"); contadorAnios = 0; }
                    }
                }

            }

            Console.ReadLine();


        }
    }
}
