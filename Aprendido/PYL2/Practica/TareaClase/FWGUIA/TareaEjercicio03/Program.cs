using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio03
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "TareaEjercicio03 Nro03";


            double maximoDivisor;
            double divisor;
            bool valorprimo;


            Console.WriteLine("ingrese un numero");
            int numero = int.Parse(Console.ReadLine());


            for(double i = 2; i <= numero; i++)
            {
                valorprimo = true;
                maximoDivisor = Math.Sqrt(i);

                for(divisor = 2; divisor <= maximoDivisor; divisor++)
                {
                    if(i % divisor == 0)
                    {
                        valorprimo = false;
                        break;
                    }
                }

                if(valorprimo)
                {
                    Console.WriteLine("los numeros primos por debajo del numero seleccionado son: {0}",i);
                }

            }

            Console.ReadKey();

        }
    }
}
