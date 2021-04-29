using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Excepciones;
using Archivos;


namespace EntidadesInstanciables
{
    public class Jornada
    {

        #region Atributos

        // Enumerado Eclase privado.
        private Universidad.EClases clase;
        // Atributo privado de profesor.
        private Profesor instructor;
        // Lista privada de alumnmos.
        private List<Alumno> alumnos;


        #endregion


        #region Propiedades 

      
        /// <summary>
        /// Propìedad de lectura y escritura para el enum Eclase.
        /// </summary>
        public Universidad.EClases Clase
        {
            get
            {
                return this.clase;
            }
            set
            {
                this.clase = value;
            }
        }

        /// <summary>
        /// Propiedad dee lectura y escritura para el Profesor.
        /// </summary>
        public Profesor Instructor
        {
            get
            {
                return this.instructor;
            }
            set
            {
                this.instructor = value;
            }
        }

        /// <summary>
        /// Propiedad de lectura y escritura para la lista de alumnos.
        /// </summary>
        public List<Alumno> Alumnos
        {
            get
            {
                return this.alumnos;
            }
            set
            {
                this.alumnos = value;
            }
        }
        #endregion

    
        #region Constructores
       
        /// <summary>
        /// Constructor que inicializa una nueva listya de alumnos.
        /// </summary>

        private Jornada()
        {
            this.alumnos = new List<Alumno>();
        }

        /// <summary>
        /// constructor que innicializa atributos propios.
        /// </summary>
        /// <param name="clase"> Clase de la jornada </param>
        /// <param name="instructor"> Instructor que da clase </param>

        public Jornada(Universidad.EClases clase, Profesor instructor) : this()
        {
            this.clase = clase;
            this.instructor = instructor;
        }

        #endregion


        #region Metodos


        /// <summary>
        /// Metodo estatico para serializar los datos de la Jornada.
        /// </summary>
        /// <param name="jornada"></param>
        /// <returns>true si pudo guarda , false si no pudo</returns>
        public static bool Guardar(Jornada jornada)
        {

            Texto t = new Texto();

            return t.Guardar((AppDomain.CurrentDomain.BaseDirectory) + @"\Jornada.txt", jornada.ToString());
        }

        /// <summary>
        /// Metodo
        /// </summary>
        /// Metodo estatico para leer los datos de Jornada.
        public static string Leer()
        {
            string retorno;
            Texto t = new Texto();
            t.Leer((AppDomain.CurrentDomain.BaseDirectory) + @"\Jornada.txt", out retorno);

            return retorno;
        }

        #endregion


        #region Sobrecargas

        /// <summary>
        /// Sobrecarga de metodo toSring()
        /// </summary>
        /// <returns> Retorna los datos de la jornada </returns>
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("JORNADA: ");
            sb.AppendLine("CLASE DE " + this.clase + " POR NOMBRE COMPLETO: " + this.instructor);
            sb.AppendLine("ALUMNOS: ");
            foreach (Alumno item in this.alumnos)
            {
                sb.AppendLine(item.ToString());
            }

            return sb.ToString();
        }


        /// <summary>
        /// Sobrecarga operador ==. Entre jornada y alumno.
        /// </summary>
        /// <param name="j"> Jornada a comparar </param>
        /// <param name="a"> Alumno a comparar </param>
        /// <returns>TRUE -> El alumno participo // False -> No lo hizo </returns>

        public static bool operator ==(Jornada j, Alumno a)
        {
            bool retorno = false;

            foreach (Alumno item in j.alumnos)
            {
                if (item == a)
                {
                    retorno = true;
                    break;
                }

            }

            return retorno;
        }

        /// <summary>
        /// Sobrecarga operador !=. Entre jornada y alumno.
        /// </summary>
        /// <param name="j"> Jornada a comparar </param>
        /// <param name="a"> Alumno a comparar </param>
        /// <returns> TRUE -> El alumno no participo // False -> Si lo hizo </returns>

        public static bool operator !=(Jornada j, Alumno a)
        {
            return !(j == a);
        }

        /// <summary>
        /// Agrega un alumno a la jornada.
        /// </summary>
        /// <param name="j"> Jornada </param>
        /// <param name="a"> Alumno a argregar </param>
        /// <returns> JKornada con el alumno ya agregado </returns>

        public static Jornada operator +(Jornada j, Alumno a)
        {
            if (j != a)
            {
                j.alumnos.Add(a);
            }
            else
            {
                throw new AlumnoRepetidoException();
            }

            return j;
        }


        #endregion

    }
}
