using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio16
{
    class Program
    {
        static void Main(string[] args)
        {
            Alumno a1 = new Alumno();
            Alumno a2 = new Alumno();
            Alumno a3 = new Alumno();

            a1.nombre = "Juan";
            a1.apellido = "Perez";
            a1.legajo = 107979;
            a1.Estudiar(10, 4);
            a1.CalcularFinal();


            a2.nombre = "Pedro";
            a2.apellido = "Rodriguez";
            a2.legajo = 107978;
            a2.Estudiar(10, 4);
            a2.CalcularFinal();

            a3.nombre = "Mateo";
            a3.apellido = "Messi";
            a3.legajo = 107977;
            a3.Estudiar(10, 4);
            a3.CalcularFinal();

            Console.WriteLine(a1.Mostrar());
            Console.WriteLine(a2.Mostrar());
            Console.WriteLine(a3.Mostrar());

            Console.ReadLine();


        }
    }
}
