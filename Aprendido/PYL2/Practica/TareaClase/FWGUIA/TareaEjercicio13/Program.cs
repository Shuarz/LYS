using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio13
{
    class Program
    {
        static void Main(string[] args)
        {
            /*13.Desarrollar una clase llamada Conversor, que posea dos métodos de clase(estáticos):
            string DecimalBinario(double). Convierte un número de entero a binario.
            double BinarioDecimal(string). Convierte un número binario a entero. */



        }
    }

    public class Conversor
    {

        public static string DecimalBinario(int numero)
        {
            string retorno = "";

            do
            {
                if (numero % 2 == 0)
                {
                    retorno = '0' + retorno;

                    else
                        retorno = '1' + retorno;
                        numero = numero / 2;
                }
                if (numero < 2)
                {
                    retorno = '1' + retorno;
                }
            } while (numero > 2);

            return retorno;
        }

        public static int BinarioDecimal(string cadena)
        {
            double numero = 0;
            Int32 retorno;
            Int32 largo;
            Int32 auxiliar = 1;

            for(largo = 0; largo < cadena.Length; largo++)
            {
                if (cadena[largo] == '1')
                {
                    numero = numero + 1 * Math.Pow(2, (cadena.Length - auxiliar));
                    auxiliar++;
                }
                else
                    continue;

            }

            retorno = Conversor.toint32(numero);
            return retorno;
        }

    }

}
