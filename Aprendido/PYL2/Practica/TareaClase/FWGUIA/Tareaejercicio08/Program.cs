using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tareaejercicio08
{
    class Program
    {
        static void Main(string[] args)
        {
            int valorHora;
            string nombre;
            int antiguedadEnAños;
            int horasTrabajadas;
            int idEmpleado = 1;

            float total;
            float descuentos;
            float neto;

            string acumuladorDeDatos = "";

            string rta;


            do
            {
                Console.WriteLine("\nID de empleado: {0}", idEmpleado);

                Console.Write("Ingrese el valor hora: ");
                valorHora = int.Parse(Console.ReadLine());
                while (valorHora < 0)
                {
                    Console.Write("Ingrese el valor hora, no puede ser negativo: ");
                    valorHora = int.Parse(Console.ReadLine());
                }

                Console.Write("Ingrese el nombre  del empleado: ");
                nombre = Console.ReadLine();

                Console.Write("Ingrese la antiguedad, en años: ");
                antiguedadEnAños = int.Parse(Console.ReadLine());
                while (valorHora < 0)
                {
                    Console.Write("Ingrese la antiguedad, en años. No puede ser negativa: ");
                    antiguedadEnAños = int.Parse(Console.ReadLine());
                }

                Console.Write("Ingrese la cantidad de horas trabajadas: ");
                horasTrabajadas = int.Parse(Console.ReadLine());
                while (horasTrabajadas < 0)
                {
                    Console.Write("Ingrese la cantidad de horas trabajadas, no puede ser negativa: ");
                    horasTrabajadas = int.Parse(Console.ReadLine());
                }

                Console.Write("\nDesea ingresar otro empleado? {{S}} - SI // {{N}} - NO ---> RTA: \n");
                rta = Console.ReadLine();

                idEmpleado++;

                total = ((valorHora * horasTrabajadas) + (antiguedadEnAños * 150));
                descuentos = ((total / 100) * 13);
                neto = total - descuentos;


                acumuladorDeDatos = acumuladorDeDatos + (
                    "ID Empleado: " + idEmpleado +
                    "\nNombre: " + nombre +
                    "\nAntiguedad: " + antiguedadEnAños +
                    "\nValor hora: " + valorHora +
                    "\nTotal: " + total +
                    "\nDescuentos: " + descuentos +
                    "\nNeto: " + neto + "\n\n");


                valorHora = 0;
                nombre = "";
                antiguedadEnAños = 0;
                horasTrabajadas = 0;
                total = 0;
                descuentos = 0;
                neto = 0;

            } while (rta != "n");


            Console.WriteLine(acumuladorDeDatos);
            Console.ReadKey();


        }
    }
}
