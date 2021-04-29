using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntidadesAbstractas;
using Excepciones;
using Archivos;

namespace EntidadesInstanciables
{
    public class Universidad
    {
        #region Enumerados

        // Enumerado.
        public enum EClases
        {
            Programacion,
            Laboratorio,
            Legislacion,
            SPD,
        }

        # endregion


        #region Atributos
        // Lista de alumnos.
        private List<Alumno> alumnos;
        // Lista de jornadas.
        private List<Jornada> jornada;
        // Lista de profesores.
        private List<Profesor> profesores;

        #endregion


        #region Propiedades

        /// <summary>
        /// Propiedad de Jornada.
        /// </summary>
        /// <param name="indice"> Indice de la jornada </param>
        /// <returns></returns>
        public Jornada this[int indice]
        {
            get
            {
                if (indice >= 0 && indice < this.jornada.Count)
                {
                    return this.jornada[indice];
                }
                else
                {
                    return null;
                }
            }
            set
            {
                this.jornada[indice] = value;
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

        /// <summary>
        /// Propiedad de lectura y escritura para la lista de profesores.
        /// </summary>
        public List<Profesor> Instructores
        {
            get
            {
                return this.profesores;
            }
            set
            {
                this.profesores = value;
            }
        }

        /// <summary>
        /// Propiedad de lectura y escritura para la lista de jornadas.
        /// </summary>
        public List<Jornada> Jornadas
        {
            get
            {
                return this.jornada;
            }
            set
            {
                this.jornada = value;
            }
        }

        #endregion


        #region Constructores

        /// <summary>
        /// Constructor por defecto que inicializa los atributos de la clase Universidad (Listas).
        /// </summary>

        public Universidad()
        {
            this.jornada = new List<Jornada>();
            this.profesores = new List<Profesor>();
            this.alumnos = new List<Alumno>();
        }

        #endregion


        #region Metodos

        /// <summary>
        /// Metodo estatico para mostrar los datos.
        /// </summary>
        /// <param name="uni"></param>
        /// <returns> Retorna los datos de la clase universidad </returns>

        private static string MostrarDatos(Universidad uni)
        {
            StringBuilder sb = new StringBuilder();

            foreach (Jornada item in uni.jornada)
            {
                sb.AppendLine(item.ToString());
                sb.AppendLine("<--------------------------------------->");
            }

            return sb.ToString();
        }

        /// <summary>
        /// Metodo estatico para serializar los datos de Universidad.
        /// </summary>
        /// <param name="u"> Universidad a seriaslizar </param>
        /// <returns>TRUE --> Se pudo serializar // False -- No se pudo serializar. </returns>

        public static bool Guardar(Universidad u)
        {
            Xml<Universidad> x = new Xml<Universidad>();

            return x.Guardar((AppDomain.CurrentDomain.BaseDirectory) + @"\Universidad.Xml", u);


        }

        /// <summary>
        /// Metodo estatico para leer.
        /// </summary>
        /// <returns> Universidad + archivos serializados </returns>

        public static Universidad Leer()
        {
            Universidad u = new Universidad();

            Xml<Universidad> x = new Xml<Universidad>();
            x.Leer((AppDomain.CurrentDomain.BaseDirectory) + @"\Universidad.Xml", out u);

            return u;
        }

        #endregion


        #region Sobrecargas

        /// <summary>
        /// Sobercarga del metodo toString
        /// </summary>
        /// <returns> Retorna los datos de universidadf </returns>
        public override string ToString()
        {
            return Universidad.MostrarDatos(this);
        }



        /// <summary>
        /// Sobrecarga ==. Compara si una universidad es igual a un alumno si está dentro de la misma 
        /// </summary>
        /// <param name="g"> Universidad a comparar </param>
        /// <param name="a"> Alumno a comparar </param>
        /// <returns>TRUE -> Esta dentro // False -> No está </returns>

        public static bool operator == (Universidad g, Alumno a)
        {
            bool retorno = false;

            foreach (Alumno item in g.alumnos)
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
        /// Sobrecarga ==. Compara si una universidad es distinta a un alumno si está dentro de la misma 
        /// </summary>
        /// <param name="g"> Universidad a comparar </param>
        /// <param name="a"> Alumno a compara </param>
        /// <returns>TRUE -> No esta inscripto // Flase -> Si esta inscripto </returns>
        public static bool operator != (Universidad g, Alumno a)
        {
            return !(g == a);
        }

        /// <summary>
        /// Sobrecarga ==. Compara si una universidad es igual a un profesor si está dentro de la misma 
        /// </summary>
        /// <param name="g"> Unviersidad a comparar </param>
        /// <param name="i"> Profesor a comparar </param>
        /// <returns>TRUE -> Esta dentro // False -> No está </returns>

        public static bool operator == (Universidad g, Profesor i)
        {
            bool retorno = false;

            foreach (Profesor item in g.profesores)
            {
                if (i == item)
                {
                    retorno = true;
                    break;
                }
            }

            return retorno;
        }

        /// <summary>
        /// Sobrecarga ==. Compara si una universidad es distinta a un profesor si está dentro de la misma 
        /// </summary>
        /// <param name="g"> Universidad a comparar </param>
        /// <param name="a"> Profesor a compara </param>
        /// <returns>TRUE -> No esta // Flase -> Si esta </returns>
        public static bool operator != (Universidad g, Profesor i)
        {
            return !(g == i);
        }


        /// <summary>
        /// Sobrecarga == Entre universidad y clase. Se utiliza la sobrecarga  == de profesor
        /// </summary>
        /// <param name="g"> Universidad a comparar </param>
        /// <param name="clase"> Clase a comparar </param>
        /// <returns> REtorna el primer profesor - Sin o una excepcion. </returns>
        public static Profesor operator == (Universidad g, EClases clase)
        {

            Profesor retorno = new Profesor();
            bool bandera = false;
            int i;

            for (i = 0; i < g.profesores.Count; i++)
            {
                if (g.profesores[i] == clase)
                {
                    retorno = g.profesores[i];
                    bandera = true;
                    break;
                }
            }

            if (bandera == false)
            {

                throw new SinProfesorException();
            }
            return retorno;
        }


        /// <summary>
        /// Sobrecarga != Entre universidad y clase. Se utiliza la sobrecarga  == de profesor
        /// </summary>
        /// <param name="g"> Universidad a comparar </param>
        /// <param name="clase"> Clase a comparar </param>
        /// <returns> Retorna el primer profesor - Sinoi una excepcion. </returns>
        /// 

        public static Profesor operator !=(Universidad g, EClases clase)
        {
            Profesor retorno = new Profesor();
            bool bandera = false;
            int i;
            for (i = 0; i < g.profesores.Count; i++)
            {
                if (g.profesores[i] != clase)
                {
                    retorno = g.profesores[i];

                    break;
                }
            }
            if (bandera == false)
            {
                throw new SinProfesorException();
            }
            return retorno;
        }


        /// <summary>
        /// Sobrecarga + en el cual se agrega una clase a una universidad 
        /// </summary>
        /// <param name="g"> Universidad </param>
        /// <param name="clase"> Clase a agregar  </param>
        /// <returns> Universidad con la clase agregada </returns>

        public static Universidad operator + (Universidad g, EClases clase)
        {
            Profesor p = (g == clase);
            Jornada j = new Jornada(clase, p);

            foreach (Alumno item in g.alumnos)
            {
                if (item == clase)
                {
                    j += item;
                }
            }

            g.Jornadas.Add(j);
            return g;
        }

        /// <summary>
        /// Sobrecarga + Agrega un alumno a la universidad.
        /// </summary>
        /// <param name="g"> Universidad </param>
        /// <param name="a"> Alumno a agregar en la universidad </param>
        /// <returns> Retorna universidad con el alumno agregado -- Sino una excepcion </returns>

        public static Universidad operator +(Universidad g, Alumno a)
        {
            if (g != a)
            {
                g.alumnos.Add(a);
            }
            else
            {
                throw new AlumnoRepetidoException();
            }

            return g;
        }


        /// <summary>
        /// Sobrecarga + Agrega un profesor a la universidad.
        /// </summary>
        /// <param name="g"> Universidad </param>
        /// <param name="i"> Profesor a agregar </param>
        /// <returns> Retorna universidad -- Sino, nada. </returns>

        public static Universidad operator +(Universidad g, Profesor i)
        {
            if (g != i)
            {
                g.profesores.Add(i);
            }

            return g;
        }



        #endregion
    }

}
