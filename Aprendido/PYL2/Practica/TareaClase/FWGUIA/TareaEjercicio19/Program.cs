using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio19
{
    class Program
    {
        static void Main(string[] args)
        {
            Sumador a = new Sumador(10);
            Sumador b = new Sumador(10);

            long n1 = 4;
            long n2 = 8;
            long resultdo = a.Sumar(5, 7);
            long resultdo2 = a.Sumar(13, 7);
            string numerico = a.Sumar("5", "7");

            Console.WriteLine(numerico);
            Console.WriteLine("cantidad sumas{0} ", (int)a);
            Console.ReadKey();


        }
    }
}
