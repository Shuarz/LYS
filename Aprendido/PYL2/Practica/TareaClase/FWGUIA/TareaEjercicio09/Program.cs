using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio09
{
    class Program
    {
        static void Main(string[] args)
        {
            string mensajeConFormato = "";
            int largoPiramide;
            int i;


            Console.Write("Ingrese el largo de la piramide: ");
            largoPiramide = int.Parse(Console.ReadLine());

            for (i = 0; i < largoPiramide * 2; i++)
            {
                mensajeConFormato += "*";
                if (i % 2 == 0)
                { Console.WriteLine(mensajeConFormato); }

            }

            Console.ReadLine();


        }
    }
}
