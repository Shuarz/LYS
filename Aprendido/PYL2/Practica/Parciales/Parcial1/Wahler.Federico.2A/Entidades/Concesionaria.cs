using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Concesionaria
    {
        private int capacidad;
        private List<Vehiculos> vehiculos;


        
        public double PrecioDeAutos
        {
            get
            {
                return this.ObtenerPrecio(EVehiculo.PrecioDeAutos);
            }
        }
        public double PrecioDeMotos
        {
            get
            {
                return this.ObtenerPrecio(EVehiculo.PrecioDeMotos);
            }
        }
        public double Preciototal
        {
            get
            {
                return this.ObtenerPrecio(EVehiculo.PrecioTotal);
            }
        }
       
        private Concesionaria()
        {
            this.vehiculos = new List<Vehiculos>();
        }
        private Concesionaria(int capacidad)
            : this()
        {
            this.capacidad = capacidad;
        }
       
        public static string Mostrar(Concesionaria c)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat($"Capacidad: {c.capacidad}\n");
            sb.AppendFormat($"Total por autos: {c.PrecioDeAutos}\n");
            sb.AppendFormat($"Total por motos: {c.PrecioDeMotos}\n");
            sb.AppendFormat($"Total: {c.Preciototal}\n");
            sb.AppendLine("*********************************************");
            sb.AppendLine("Listado de vehículos");
            sb.AppendLine("*********************************************");
            foreach (Vehiculos item in c.vehiculos)
            {
                sb.AppendFormat($"{item.ToString()}\n");
            }

            return sb.ToString();
        }
        private double ObtenerPrecio(EVehiculo tipoVehiculo)
        {
            float acumulador = 0;
            foreach (Vehiculos item in this.vehiculos)
            {
                switch (tipoVehiculo)
                {
                    case EVehiculo.PrecioDeAutos:
                        if (item is Auto)
                            acumulador += (Single)(Auto)item;
                        break;
                    case EVehiculo.PrecioDeMotos:
                        if (item is Moto)
                            acumulador += (Moto)item;
                        break;
                    case EVehiculo.PrecioTotal:
                        if (item is Auto)
                            acumulador += (Single)(Auto)item;
                        if (item is Moto)
                            acumulador += (Moto)item;
                        break;
                }
            }
            return acumulador;
        }
        

    
        public static implicit operator Concesionaria(int capacidad)
        {
            return new Concesionaria(capacidad);
        }
        public static bool operator ==(Concesionaria c, Vehiculos v)
        {
            bool retorno = false;
            foreach (Vehiculos item in c.vehiculos)
            {
                if (item is Auto && v is Auto)
                    retorno = ((Auto)item) == (Auto)v;
                else if (item is Moto && v is Moto)
                    retorno = ((Moto)item) == (Moto)v;
            }

            return retorno;
        }
        public static bool operator !=(Concesionaria c, Vehiculos v)
        {
            return !(c == v);
        }
        public static Concesionaria operator +(Concesionaria c, Vehiculos v)
        {
            if (c.capacidad > c.vehiculos.Count)
            {
                if (c != v)
                    c.vehiculos.Add(v);
                else
                    Console.WriteLine("El vehiculo ya esta en la concesionaria!!!");
            }
            else
                Console.WriteLine("No hay mas lugar en la concesionara!!!");
            return c;
        }
        public static Concesionaria operator -(Concesionaria c, Vehiculos v)
        {
            if (c == v)
                c.vehiculos.Remove(v);
            else
                Console.WriteLine("El vehiculo ya esta en la concesionaria!!!\n");
            return c;
        }
    }
}
