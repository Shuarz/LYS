using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Excepciones;

namespace EntidadesAbstractas
{
    public abstract class Persona
    {
        #region Enumerados

        public enum ENacionalidad
        {
            Argentino,
            Extranjero,
        }

        #endregion


        #region Atributos
        // Atributo privado que representa apellido.
        private string apellido;
        // Atributo privado que representa DNI.
        private int dni;
        // Atributo privado que representa nacionalidad.
        private ENacionalidad nacionalidad;
        // Atributo privado que representa nombre.
        private string nombre;

        #endregion


        #region Propiedades

        /// <summary>
        /// Propiedad de lectura y escritura que valida que se haya ingresado un APELLIDO.
        /// </summary>
        public string Apellido
        {
            get
            {
                return this.apellido;
            }
            set
            {
                this.apellido = this.ValidarNombreApellido(value);
            }
        }


        /// <summary>
        /// Propiedad de lectura y escritura que valida que se haya ingresado un NOMBRE.
        /// </summary>

        public string Nombre
        {
            get
            {
                return this.nombre;
            }

            set
            {
                this.nombre = this.ValidarNombreApellido(value);
            }
        }


        /// <summary>
        /// Propiedad de lectura y escritura que valida que se haya ingresado un DNI.
        /// </summary>

        public int DNI
        {
            get
            {
                return this.dni;
            }
            set
            {
                this.dni = this.ValidarDni(this.Nacionalidad, value);
            }
        }

        /// <summary>
        /// Propiedad de lectura y escritura para el enumerado Nacionalidad.
        /// </summary>

        public ENacionalidad Nacionalidad
        {
            get
            {
                return this.nacionalidad;
            }
            set
            {
                this.nacionalidad = value;
            }
        }

        /// <summary>
        /// Propiedad de solo escritura para el atributo DNI
        /// </summary>

        public string StringToDni
        {
            set
            {
                this.dni = this.ValidarDni(this.Nacionalidad, value);
            }
        }

        #endregion


        #region Constructores
        /// <summary>
        /// Constructor de Persona, por defecto.
        /// </summary>

        public Persona()
        {

        }
        /// <summary>
        /// Constructor de Persona, con 3 parametros
        /// </summary>
        /// <param name="nombre"> Nombre de la persona </param>
        /// <param name="apellido"> Apellido de la persona </param>
        /// <param name="nacionalidad"> Nacionalidad de persona </param>

        public Persona(string nombre, string apellido, ENacionalidad nacionalidad)
        {
            this.nacionalidad = nacionalidad;
            this.nombre = nombre;
            this.apellido = apellido;
        }

        /// <summary>
        /// Constructor de Persona. Invoca al constructor de 3 parametros
        /// </summary>
        /// <param name="nombre"> Nombre de persona </param>
        /// <param name="apellido"> Apellido de persona </param>
        /// <param name="dni"> Dni de persona </param>
        /// <param name="nacionalidad"> N acionalidad de persona </param>

        public Persona(string nombre, string apellido, int dni, ENacionalidad nacionalidad) : this(nombre, apellido, nacionalidad)
        {
            this.DNI = dni;
        }

        /// <summary>
        /// Constructor de Persona. Invoca al constructor de 3 parametros. Incuye la propiedad StringToDni.
        /// </summary>
        /// <param name="nombre"> Nombre de persona </param>
        /// <param name="apellido"> Apellido de persona </param>
        /// <param name="dni"> Dni de persona </param>
        /// <param name="nacionalidad"> Nacionalidad de persona </param>

        public Persona(string nombre, string apellido, string dni, ENacionalidad nacionalidad) : this(nombre, apellido, nacionalidad)
        {
            this.StringToDni = dni;
        }

        #endregion


        #region Metodos

        /// <summary>
        /// Valida el formato del DNI dependiendo de la Persona.
        /// </summary>
        /// <param name="nacionalidad"> Nacionalidad de la persona </param>
        /// <param name="dato"> Dni a validar </param>
        /// <returns> Retorna el dni  de la person a</returns>

        /// <summary>
        /// Método que valida el DNI (int)
        /// </summary>
        /// <param name="nacionalidad">Nacionalidad de la persona</param>
        /// <param name="dato">DNI pasado como int.</param>
        /// <returns>El DNI validado</returns>
        private int ValidarDni(ENacionalidad nacionalidad, int dato)
        {

            if ((nacionalidad == ENacionalidad.Argentino && dato >= 1 && dato <= 89999999) ||
                nacionalidad == ENacionalidad.Extranjero && dato >= 90000000 && dato <= 99999999)
            {

                return dato;

            }
            else
            {
                throw new NacionalidadInvalidaException("La nacionalidad no coincide con el DNI.");
            }

        }

        /// <summary>
        /// Método para validar el DNI (string)
        /// </summary>
        /// <param name="nacionalidad">Nacionalidad de la persona</param>
        /// <param name="dato">DNI a validar (string) </param>
        /// <returns>DNI Validado</returns>
        private int ValidarDni(ENacionalidad nacionalidad, string dato)
        {

            int numeroDni = -1;

            if (!(int.TryParse(dato, out numeroDni)) || dato.Length < 1 || dato.Length > 8)
            {
                throw new DniInvalidoException("El DNI no coincide con el formato");
            }
            return ValidarDni(nacionalidad, numeroDni);

        }


        /// <summary>
        /// Valida que los nombres tengan solamente caracteres qué sean validos.
        /// </summary>
        /// <param name="dato"> Nombre de persona </param>
        /// <returns> Retorna una cadena que peude ser el nombre o el apellido </returns>

        private string ValidarNombreApellido(string dato)
        {
            bool retorno = true;

            foreach (char item in dato)
            {
                if (!(char.IsLetter(item)))
                {
                    retorno = false;
                    break;
                }
            }

            if (retorno != true)
            {
                // dato = null; // CON ESTO RETORNA NULA LA CADENA. NO ACLARA.
                throw new Exception("ERROR. No se puede cargar el nombre y/o apellido. Error de caracteres.");
            }

            return dato;
        }

        #endregion


        #region SobrecargasMetodos

        /// <summary>
        /// Sobrecarga el metodo ToString().
        /// </summary>
        /// <returns> Retorna una cadena con los datos de la persona </returns>

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("NOMBRE: {0}, {1}\n", this.apellido, this.nombre);
            sb.AppendFormat("NACIONALIDAD: {0}\n", this.nacionalidad);

            return sb.ToString();
        }

        #endregion
    }
}
