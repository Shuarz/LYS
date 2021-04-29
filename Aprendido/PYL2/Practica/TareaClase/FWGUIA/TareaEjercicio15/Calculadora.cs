using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio15
{
    class Calculadora
    {
        public static double Calcular(double n1, double n2, char operacion)
        {
            double resultado = 0;

            switch (operacion)
            {
                case '+':
                    resultado = n1 + n2;
                    break;
                case '-':
                    resultado = n1 - n2;
                    break;
                case '*':
                    resultado = n1 * n2;
                    break;
                case '/':
                    if (Calculadora.Validar(n2))
                        resultado = n1 / n2;
                    else
                        Console.WriteLine("El denominador no puede ser 0");
                    break;
            }


            return resultado;
        }

        private static bool Validar(double n2)
        {
            bool esValido = false;
            if (n2 != 0)
                esValido = true;

            return esValido;
        }

    }
}
