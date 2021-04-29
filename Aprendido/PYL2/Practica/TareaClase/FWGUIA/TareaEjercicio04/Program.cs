using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio04
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "TareaEjercicio04 Nro04";

            int contadorNumerosPerfectos = 0;
            int acumulador = 0;

            Console.Title = "EjercicioNro_04";

            while (contadorNumerosPerfectos < 4)
            {
                for (int i = 0; ; i++)
                {
                    for (int j = 1; j < i; j++)
                    {
                        if (i % j == 0)
                        {
                            acumulador = acumulador + j;
                        }
                    }

                    if (acumulador == i)
                    {
                        if (contadorNumerosPerfectos == 0)
                        {
                            Console.WriteLine("Los primeros 4 numeros perfectos son: \n");
                        }

                        Console.WriteLine("{0:#,###}", i);
                        contadorNumerosPerfectos++;
                    }

                    acumulador = 0;
                    i++;
                }

            }

            Console.ReadKey();
        }
    }
}
