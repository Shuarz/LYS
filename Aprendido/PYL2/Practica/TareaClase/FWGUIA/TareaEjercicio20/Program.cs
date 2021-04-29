using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio20
{
    class Program
    {
        static void Main(string[] args)
        {
            Dolar d = new Dolar(2);
            Pesos p = new Pesos(33.88);
            Euro e = new Euro(1);

            //Pesos aux = new Pesos(0);
            //aux = p - e;

            Dolar resta = new Dolar(0);
            //suma = (Pesos)d;
            resta = d - p;

            Console.WriteLine(resta.GetCantidad());
            Console.ReadKey();


        }
    }
}
