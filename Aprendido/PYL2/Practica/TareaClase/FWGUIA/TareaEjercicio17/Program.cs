using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio17
{
    class Program
    {
        static void Main(string[] args)

            //el 17 no muestra, corregir eso

        {
            short tintaAzul = 100;
            short tintaRoja = 100;


            // Primer manera.
            Boligrafo boligrafoRojo;
            boligrafoRojo = new Boligrafo(tintaRoja, ConsoleColor.Red);


            // Segunda manera.
            Boligrafo boligrafoAzul = new Boligrafo(tintaAzul, ConsoleColor.Blue);



        }
    }

    public class Boligrafo
    {
        public const short cantidadTintaMaxima = 100;
        private short tinta;
        private ConsoleColor color;


        public Boligrafo(short tintaParametro, ConsoleColor colorParametro)
        {
            this.tinta = tintaParametro;
            Console.BackgroundColor = colorParametro;
        }




        public ConsoleColor getColor()
        {
            ConsoleColor colorRetornado = this.color;
            return colorRetornado;
        }




        public short getTinta()
        {
            short tintaRetornada = this.tinta;
            return tintaRetornada;
        }



        //public bool Pintar(int gasto, out string dibujo)
        //{

        //}


        public void recargar()
        {
            this.tinta = Boligrafo.cantidadTintaMaxima;
        }



        private void setTinta(short tintaParametro)
        {
            short nivel = this.tinta;

            if (nivel + tintaParametro >= 0 && (nivel + tintaParametro) <= Boligrafo.cantidadTintaMaxima)

            {
                this.tinta = short.Parse((nivel + tinta).ToString());
            }

        }


    }
}
