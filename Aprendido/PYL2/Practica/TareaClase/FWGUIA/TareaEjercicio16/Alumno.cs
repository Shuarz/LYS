using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio16
{
    class Alumno
    {
        private byte nota1;
        private byte nota2;
        private float notaFinal;
        public string apellido;
        public int legajo;
        public string nombre;

        public void CalcularFinal()
        {


            if (this.nota1 >= 4 && this.nota2 >= 4)
            {
                Random rd = new Random();
                this.notaFinal = rd.Next(1, 10);
            }

            if (this.notaFinal < 4)
                this.notaFinal = -1;


        }

        public void Estudiar(byte notaUno, byte notaDos)
        {
            this.nota1 = notaUno;
            this.nota2 = notaDos;
        }

        public string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Apellido: {0}", this.apellido);
            sb.AppendFormat("Nombre: {0}", this.nombre);
            sb.AppendFormat("Legajo: {0}", this.legajo);
            sb.AppendFormat("Primer nota: {0}", this.nota1);
            sb.AppendFormat("Segunda nota: {0}", this.nota2);

            if (this.notaFinal != -1)
                sb.AppendFormat("Nota Final: {0} - Alumno Aprobado!!", this.notaFinal);

            else
                sb.AppendFormat("Alumno desaprobado con {0}", this.notaFinal);

            return sb.ToString();
        }


    }
}
