using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Moto : Vehiculos
    {
        public ECilindrada cilindrada;


       
        public Moto(string marca, EPais pais, string modelo, float precio, ECilindrada cilindrada)
            : base(marca, pais, modelo, precio)
        {
            this.cilindrada = cilindrada;
        }
       
        public static bool operator ==(Moto a, Moto b)
        {
            return (Vehiculos)a == (Vehiculos)b && a.cilindrada == b.cilindrada;
        }
        public static bool operator !=(Moto a, Moto b)
        {
            return !(a == b);
        }
        public static implicit operator Single(Moto m)
        {
            return m.precio;
        }
        
        public override bool Equals(object obj)
        {
            return (Moto)obj == this;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat($"{(string)this}");
            sb.AppendFormat($"CILINDRADA: {this.cilindrada}\n");

            return sb.ToString();
        }
    }
}
