using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "TareaEjercicio01 Nro01";

            int numero;
            int i;
            int minimo = Int32.MaxValue;
            int maximo = Int32.MinValue;
            float acumulador = 0;
            int contador = 0;
            float promedio;

            for (i = 0; i < 5; i++)
            {
                Console.Write("Ingrese un numero: ");
                numero = int.Parse(Console.ReadLine());

                acumulador += numero;
                contador++;

                if (numero > maximo)
                {
                    maximo = numero;
                }
                if (numero < minimo)
                {
                    minimo = numero;
                }
            }

            promedio = (float)(acumulador / contador);

            Console.WriteLine("Minimo: {0}, Maximo: {1}, Promedio: {2}", minimo, maximo, promedio);
            

            Console.ReadKey();

        }
    }
}
