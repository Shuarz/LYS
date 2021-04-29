using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

using Entidades;

namespace SobrecargaTest
{
    class Program
    {
        /*
        public int entero;
        private float flotante;


        public Program()
        {
            this.entero = 1;
            this.flotante = 1.1f; //la f al final indica que es un flotante
        }


        public Program(int a)
        {
            this.entero = a;
        }

        public Program(float a)
        {
            this.flotante = a;
        }


        public Program(int a, float b)
        {
            this.entero = a;
            this.flotante = b;
        }

        public Program(float a, int b)
        {
            this.entero = b;
            this.flotante = a;
        }



        private static void MetodoSobrecargado()
        {
            Console.WriteLine("sin parametros");
        }


        /// <summary>
        /// esto sirve para documenar que esta haciendo este parametro o funcion
        /// </summary>
        /// <param name="a"></param>
        private static void MetodoSobrecargado(int a)
        {
            Console.WriteLine(a);
        }

        private static void MetodoSobrecargado(string a)
        {
            Console.WriteLine(a);
        }


        private void MetodoSobrecargado(string b, out int a)
        {
            if (int.TryParse(b, out a)) //esto me retorna un boleano para ver si pudo convertirlo o no (si pongo letras, obvimente que no, si pongo numeros, sin problemas)
            {
                Console.WriteLine("se convirtio!!");
                Console.WriteLine("el valor es: {0}" + a);
            }

            else
            {
                Console.WriteLine("no se convirtio!!");
                a = -1;
            }

        }

        private string verValores()
        {
            return this.entero + " - " + this.flotante;
        }


        private static string verValores(Program p)
        {
            return p.verValores();
           // return p.entero + " - " + p.flotante;
        }

        */

        static void Main(string[] args)
        {
            /* Program.MetodoSobrecargado();
             Program.MetodoSobrecargado(2);
             Program.MetodoSobrecargado("hola");

             

            ClaseCosa a = new ClaseCosa();

            ClaseCosa b = new ClaseCosa("hola");

            ClaseCosa c = new ClaseCosa(7, "chau");


            a.establecerValor(1);
            a.establecerValor("la cadena de la cosa");
            a.establecerValor(new DateTime(2020, 09, 31));
            a.mostrar();
             
            Console.ReadKey();


            Program p = new Program();

            int numero = 0;

            p.MetodoSobrecargado("88", out numero);

            Console.WriteLine(numero);

            float valor = 5;

            Program p1 = new Program();
            Program p2 = new Program(5);
            Program p3 = new Program(5, 6f);  //le asignamos el flotante para que sepa a cual llamamos en las funciones de arriba
            Program p4 = new Program(valor, numero);

            Console.WriteLine(p1.verValores());
            Console.WriteLine(p2.verValores());
            Console.WriteLine(p3.verValores());
            Console.WriteLine(p4.verValores());

            Console.WriteLine(Program.verValores(p3));    */


            //ClaseCosa c = new ClaseCosa();
            Entidades.ClaseCosa c1 = new Entidades.ClaseCosa(); //ponemos entidades cuando no ponemos el using arriba

            //ClaseCosa c2 = new ClaseCosa("asdasdasd"); //es lo mismo pero con declarado el using arriba

            OtraCosa c3 = new OtraCosa();

            Entidades.ClaseCosa c2 = new ClaseCosa(2, "hola", DateTime.Now);  //fijate el orden siempre


            if(c1 == c2)
            {

            }

            c3.entero = 2;
            c3.cadena = "hola";


            if (c1 == c3)
            {
                  
            }

            if (c1 == 5)
            {

            }

            if (4 == c1)
            {

            }


            ClaseCosa rta = c1 + c2; //suma dos cosas

            rta = c2 + 99; //sumar entero y cosa


            OtraCosa c5 = new OtraCosa(5);

            OtraCosa c6 = 6; //forma implicita

            OtraCosa c7 = (OtraCosa)"hola";  //forma explicita casteo

        }

    }
}
