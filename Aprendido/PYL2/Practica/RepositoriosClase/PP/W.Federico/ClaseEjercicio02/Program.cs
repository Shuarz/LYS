using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace ClaseEjercicio02
{
    class Program
    {
        static void Main(string[] args)
        {
            ClaseSello.Mensaje = "asdfasdf";

            string str = ClaseSello.Imprimir();  //cada vez que quieras mostar algo, usa estos dos renglones

            Console.WriteLine("El mensaje es: {0}", str);

            ClaseSello.Borrar();

            str = ClaseSello.Imprimir();

            Console.WriteLine("El mensaje es: {0}", str);

           
            
            ClaseSello.Mensaje = "Hola Mundo";

            str = ClaseSello.Imprimir();

            Console.WriteLine("El mensaje es: {0}", str);

            ClaseSello.Color = ConsoleColor.Red;

            ClaseSello.ImprimirEnColor();

            str = ClaseSello.Imprimir();

            Console.WriteLine("El mensaje es: {0}", str);

            
            
            
            ClaseSello.Imprimir();









            /*string mensaje = "asdasdasdasdasdasd";

            int cantidad = mensaje.Length; //me devuele la cantiada de caratesres de esa cadena

            Console.WriteLine(cantidad);


            ConsoleColor color;
            
            color = ConsoleColor.Green;
            
            Console.ForegroundColor = color;*/



            Console.ReadKey(true);

        }
    }
}
