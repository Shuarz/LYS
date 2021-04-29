using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio12
{
    class Program
    {
        static void Main(string[] args)
        {
            char rta;
            bool validadorRTA;
            Int32 contador = 1;
            Int32 numeroIngresado;
            Int32 acumulador = 0;


            do
            {


                Console.Write("Ingrese el numero {0}: ", contador);
                numeroIngresado = int.Parse(Console.ReadLine());

                acumulador = acumulador + numeroIngresado;

                Console.Write("Desea continuar? (S) o (N): ");
                rta = Convert.ToChar(Console.ReadLine());
                validadorRTA = validarRespuesta.ValidaS_N(rta);

                contador++;

            } while (validadorRTA == true);



            Console.WriteLine("\nLa suma es: {0}", acumulador);
            Console.ReadLine();


        }
    }

    class validarRespuesta
    {
        public static bool ValidaS_N(char c)
        {

            bool validar = false;

            if (c == 's' || c == 'S')
            {
                validar = true;
            }

            return validar;
        }

    }


}
