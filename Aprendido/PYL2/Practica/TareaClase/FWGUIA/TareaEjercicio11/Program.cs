using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio11
{
    class Program
    {
        static void Main(string[] args)
        {

                Int32 numeroIngresado;
                bool validando;
                Int32 contador = 0;
                Int32 maximo = 0;
                Int32 minimo = 0;
                Int32 acumulador = 0;
                float promedio = 0;

                for (int i = 1; i < 10; i++)
                {

                    Console.Write("Ingrese el numero {0}: ", i);
                    numeroIngresado = int.Parse(Console.ReadLine());

                    validando = Validacion.Validar(numeroIngresado, -100, 100);

                    while (validando == false)
                    {
                        Console.Write("Error. Ingrese el numero {0}: ", i);
                        numeroIngresado = int.Parse(Console.ReadLine());
                    }

                    contador++;

                    if (contador == 1)
                    {
                        minimo = numeroIngresado;
                        maximo = numeroIngresado;
                    }

                    if (numeroIngresado > maximo)
                    { maximo = numeroIngresado; }

                    if (numeroIngresado < minimo)
                    { minimo = numeroIngresado; }


                    acumulador = acumulador + numeroIngresado;
                    promedio = (acumulador / 10);
                }

                Console.WriteLine("El numero maximo es {0}: ", maximo);
                Console.WriteLine("El numero mimino es {0}: ", minimo);
                Console.WriteLine("El promedio es {0:#.00}: ", promedio);


                Console.ReadLine();
            

        }
    }

        public class Validacion
        {

            public static bool Validar(int valor, int min, int max)
            {
                bool validador = false;

                if (valor > min && valor < max)
                { validador = true; }

                return validador;
            }

        }

    
}
