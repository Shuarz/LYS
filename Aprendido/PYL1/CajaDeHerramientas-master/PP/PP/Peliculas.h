

typedef struct
{
    char titulo[20];
    int anio;
    char nacionalidad[30];
    int idDirector;
    int identificador;
    int estado;
} ePelicula;



/** \brief Busca si hay lugar libre para seguir ingresando peliculas.
 *
 * \param ePelicula Array con la cadena a ser analizada
 * \param int cantidad con la que vamos a trabajar
 * \return int
 *
 */
int buscarLibrePelicula(ePelicula listado[],int );

/** \brief Pide y carga los datos de la pelicula
 *
 * \param ePelicula Array con la cadena a ser analizada
 * \param int cantidad de peliculas
 * \return int
 *
 */
int cargarDatosPelicula(ePelicula listado[], int );

/** \brief Funcion para mostrar una pelicula
 *
 * \param unaPelicula ePelicula Array con la cadena a ser analizada
 * \return void
 *
 */
void mostrarUnaPelicula(ePelicula unaPelicula);

/** \brief Muestra todas las peliculas ingresadas
 *
 * \param ePelicula Array con la cadena a ser analizada
 * \param int
 * \return int
 *
 */
int listadoPelicula(ePelicula listado[],int );

/** \brief Inicializamos en que posicion vamos a comenzar a ingresar peliculas
 *
 * \param ePelicula Array con la cadena a ser analizada
 * \param cantidad int
 * \return int
 *
 */
int inicializarPelicula( ePelicula listado[],int cantidad);

/** \brief Preguntamos por ID que dato de la pelicula queremos modificar, luego validamos.
 *
 * \param ePelicula Array con la cadena a ser analizada
 * \param cantidad int
 * \return void
 *
 */
void modificarUnaPelicula(ePelicula listado[], int cantidad);


/** \brief Preguntamos por ID que dato vamos a dar de baja
 *
 * \param ePelicula Array con la cadena a ser analizada
 * \param cantidad int
 * \return void
 *
 */
void darDeBajaPelicula(ePelicula listado[], int cantidad);

int peliculas_Mas_Viejas(ePelicula listaPeliculas[], int cantidadP);

void hardcodeo_Peliculas(ePelicula* listadoMainPelicula);
