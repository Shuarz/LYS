using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClaseEjercicio02
{
    class ClaseSello
    {
        public static string Mensaje;

        public static ConsoleColor Color;


        public static string Imprimir()  //antes imprimia solo el mensaje hardcodeado, ahora lo hace con el recuadro de asteriscos
        {
            return ClaseSello.FormatoMensaje();
        }

        public static string Borrar() //pisa el anterior mensaje por este espacio en blanco
        {
            return ClaseSello.Mensaje = " ";
        }

        public static void ImprimirEnColor() //le asignamos un color en el main y aca hacemos que vuelva al color origen
        {
            string strs;

            strs = ClaseSello.Imprimir();
            Console.ForegroundColor = ClaseSello.Color;
            Console.WriteLine("El mensaje es: {0}", strs);
            ClaseSello.Color = ConsoleColor.Gray;
            Console.ForegroundColor = ClaseSello.Color;

        }

        private static string FormatoMensaje() //le agrega astericos los necesarios para encuadrar el texto hardcodeado
        {
            string formateo;
            string formato = "";
            int tam;

            tam = ClaseSello.Mensaje.Length;

            for (int i = 0; i <= tam+1; i++)
            {
                formato = formato + "*";
            }

            formateo = $"\n{formato}\n*{ClaseSello.Mensaje}*\n{formato}";

            return formateo;
        }

    }
}
