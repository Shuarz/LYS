using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Grupo
    {
        //atributos

        private List<Mascota> manada;
        private string nombre;
        private static EtipoManada tipo;


        //propiedades
        public static EtipoManada Tipo
        {
            set
            {
                Grupo.tipo = value;  //propiedad de solo escritura
            }
        }

        //constructores

        static Grupo()
        {
            Grupo.tipo = EtipoManada.Unica;  //iniciar el tipo con el que pidan, en este caso unica
        }

        private Grupo()
        {
            this.manada = new List<Mascota>(); //se inicializa la lista (pedian que sea privado)
        }

        public Grupo(string nombre)
            :this() 
        {
            this.nombre = nombre;
        }

        public Grupo(string nombre, EtipoManada tipo)
            :this(nombre)
        {
            Grupo.tipo = tipo;
        }

        //sobrecarga de operadores

        public static implicit operator string(Grupo g)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat($"Grupo: {g.nombre} - Tipo: {Grupo.tipo.ToString()}\n");
            sb.AppendFormat($"Integrantes: ({g.manada.Count})\n");
            foreach (Mascota item in g.manada)
            {
                sb.AppendFormat($"{item.ToString()}");
                //if (item is Perro)
                //    sb.AppendFormat($"{((Perro)item).ToString()}\n");
                //else if (item is Gato)
                //    sb.AppendFormat($"{((Gato)item).ToString()}\n");
            }

            return sb.ToString();
        }


        public static bool operator ==(Grupo g, Mascota m)
        {
            bool retorno = false;
            foreach (Mascota item in g.manada)
            {
                if (m.Equals(item))
                {
                    retorno = true;
                    break;
                }

                //if(item is Perro && ((Perro)item).Equals(m))
                //{
                //    retorno = true;
                //    break;
                //}
                //else if (item is Gato && ((Gato)item).Equals(m))
                //{
                //    retorno = true;
                //    break;
                //}
            }
            return retorno;
        }
        public static bool operator !=(Grupo g, Mascota m)
        {
            return !(g == m);
        }
        public static Grupo operator +(Grupo g, Mascota m)  //esta sobrecarga es para agregar algo a la lista
        {
            if (g != m)
                g.manada.Add(m);
            else
            {
                Console.WriteLine($"Ya esta '{m.ToString()}' en el grupo");
                //if(m is Perro)
                //    Console.WriteLine($"Ya esta '{((Perro)m).ToString()}' en el grupo");
                //else if(m is Gato)
                //    Console.WriteLine($"Ya esta '{((Gato)m).ToString()}' en el grupo");
            }
            return g;
        }
        public static Grupo operator -(Grupo g, Mascota m) //esta es para comparar
        {
            if (g == m)
                g.manada.Remove(m);
            else
            {
                Console.WriteLine($"No esta '{m.ToString()}' en el grupo");
                //if (m is Perro)
                //    Console.WriteLine($"No esta '{((Perro)m).ToString()}' en el grupo");
                //else if (m is Gato)
                //    Console.WriteLine($"No esta '{((Gato)m).ToString()}' en el grupo");
            }
            return g;
        }

    }
}
