using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio15
{
    public class Program
    {
        static void Main(string[] args)
        {
            double resultado;
            double n1;
            double n2;
            char operacion;
            char respuesta;

            do
            {
                Console.WriteLine("Bienvenido!");
                n1 = Program.PedirNumero();


                n2 = Program.PedirNumero();

                Console.WriteLine("Que operacion quiere hacer?");
                operacion = Convert.ToChar(Console.ReadLine());


                resultado = Calculadora.Calcular(n1, n2, operacion);
                Console.WriteLine("El resultado de la operacion es: {0}", resultado);
                Console.WriteLine("Quiere realizar otra operacion?: s/n");
                respuesta = Convert.ToChar(Console.ReadLine());


            } while (respuesta == 's');


        }

        public static double PedirNumero()
        {
            double n1;
            Console.WriteLine("Ingrese el número");
            n1 = double.Parse(Console.ReadLine());


            return n1;
        }
    }
}
