using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio18
{
    public class Program
    {
        static void Main(string[] args)
        {
            Punto uno = new Punto(1, 0);
            Punto dos = new Punto(1, 5);
            Punto tres = new Punto(5, 0);
            Punto cuatro = new Punto(5, 5);

            float area;
            float perimetro;


            Rectangulo a = new Rectangulo(uno, tres);
            area = a.Area();
            perimetro = a.Perimetro();
            Console.WriteLine("area : {0} - perimetro: {1}", area, perimetro);
            Console.ReadKey();

            a.Perimetro();


        }
    }
}
