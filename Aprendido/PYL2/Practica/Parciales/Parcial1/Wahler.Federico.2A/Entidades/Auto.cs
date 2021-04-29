using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
        public class Auto : Vehiculos
        {
            
            public ETipo tipo;
            

            
            public Auto(string modelo, float precio, Fabricante fabri, ETipo tipo)
                : base(precio, modelo, fabri)
            {
                this.tipo = tipo;
            }
            

            
            public static bool operator ==(Auto a, Auto b)
            {
                return (Vehiculos)a == (Vehiculos)b && a.tipo == b.tipo;
            }
            public static bool operator !=(Auto a, Auto b)
            {
                return !(a == b);
            }
            public static explicit operator Single(Auto a)
            {
                return a.precio;
            }
            

           
            public override bool Equals(object obj)
            {
                return ((Auto)obj) == this;
                
            }
            public override string ToString()
            {
                StringBuilder sb = new StringBuilder();
                sb.AppendFormat($"{(string)this}");
                sb.AppendFormat($"TIPO: {this.tipo}\n");

                return sb.ToString();
            }
            
        }
    
}
