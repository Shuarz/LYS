using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Vehiculos
    {
        
        protected Fabricante fabricante;
        protected static Random generadorDeVelocidades;
        protected string modelo;
        protected float precio;
        protected int velocidadMaxima;
        

        
        public int VelocidadMaxima
        {
            get
            {
                if (this.velocidadMaxima == 0)
                {
                    this.velocidadMaxima = Vehiculos.generadorDeVelocidades.Next(100, 280);
                }
                return this.velocidadMaxima;
            }
        }
        

        
        static Vehiculos()
        {
            Vehiculos.generadorDeVelocidades = new Random();
        }
        public Vehiculos(float precio, string modelo, Fabricante fabri)
        {
            this.precio = precio;
            this.modelo = modelo;
            this.fabricante = fabri;
            this.velocidadMaxima = this.VelocidadMaxima;
        }
        public Vehiculos(string marca, EPais pais, string modelo, float precio)
            : this(precio, modelo, new Fabricante(marca, pais))
        {
        }
        

        
        private static string Mostrar(Vehiculos v)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat($"{(string)v.fabricante}\n");
            sb.AppendFormat($"MODELO: {v.modelo}\n");
            sb.AppendFormat($"VELOCIDAD MAXIMA: {v.velocidadMaxima}\n");
            sb.AppendFormat($"PRECIO: {v.precio}\n");

            return sb.ToString();
        }
        
        public static bool operator ==(Vehiculos a, Vehiculos b)
        {
            return (a.modelo == b.modelo && a.fabricante == b.fabricante);
        }
        public static bool operator !=(Vehiculos a, Vehiculos b)
        {
            return !(a == b);
        }
        public static explicit operator string(Vehiculos v)
        {
            return Vehiculos.Mostrar(v);
        }
        
    }
}
