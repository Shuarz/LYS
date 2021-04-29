#include "Peliculas.h"
#include "Nacionalidad.h"



typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    int id;
    char nombre[20];
    eFecha nacimiento;
    char nacionalidad[30];
    int idNacionalidad;
    int estado;

}eDirector;



/** \brief Inicializamos en que posicion vamos a comenzar a ingresar directores
 *
 * \param eDirector Array con la cadena a ser analizada
 * \param int
 * \return int
 *
 */
int inicializarDirector( eDirector listado[],int );



/** \brief Busca si hay lugar libre para seguir ingresando directores.
 *
 * \param eDirector Array con la cadena a ser analizada
 * \param int cantidad con la que vamos a trabajar
 * \return int
 *
 */
int buscarLibreDirector(eDirector listado[],int );


/** \brief Pide y carga los datos del director
 *
 * \param eDirector Array con la cadena a ser analizada
 * \param int cantidad de directores
 * \return int
 *
 */
int cargarDatosDirector(eDirector listado[], int );


/** \brief Funcion para mostrar un director
 *
 * \param eDirector unDirector Array con la cadena a ser analizada
 * \return void
 *
 */
void mostrarUnDirector(eDirector unDirector, eNacionalidad* unaNacionalidad, int lenN);


/** \brief Muestra todos los directores ingresados
 *
 * \param eDirector Array con la cadena a ser analizada
 * \param int
 * \return int
 *
 */
int listadoDirectores(eDirector listado[],int cantidad, eNacionalidad* nacionaliadListado, int lenN);


void darDeBajaDirector(eDirector listado[], int cantidad);

void peliculas_Con_Director(ePelicula* listaPelicula, eDirector* listaDirector, int lenP, int lenD);

int nombre_Repetido(eDirector* miDirector, int lenD, char* nombre);

int contador_Peliculas(ePelicula* listaPelicula, int idDirector, int cantP);

int director_Con_Mas_Peliculas(ePelicula* listaPelicula, eDirector* listaDirector, eNacionalidad* listaNacionalidad, int lenP, int lenD, int lenN);

int peliculas_dirigidas_Por_Director(ePelicula* listaPelicula, eDirector* listaDirector, int lenP, int lenD);

int busca_Nombre_Devuelve_ID(eDirector* listaDirector, char nombre[], int cantidad);

int peliculas_Por_Director(ePelicula* listaPelicula, eDirector* listaDirector, int lenP, int lenD);

int busca_Pelicula_Por_Director(ePelicula* listaPelicula, int directorID, int lenP);

int busca_Descripcion_Devuelve_IDNacionalidad(eNacionalidad* listaNacionalidad, char nombre[], int cantidad);

int cantidad_Peliculas_Por_Nacionalidad(eNacionalidad* listaNacionalidad, ePelicula* listaPelicula, eDirector* listaDirector,
                                       int lenP, int lenD, int lenN);

 int peliculas_Por_Nacionalidad_Director(eNacionalidad* listaNacionalidad, ePelicula* listaPelicula, eDirector* listaDirector,
                                        int lenP, int lenD, int lenN);

int busca_Pelicula_Por_Nacionalidad_Director(eDirector* listaDirector, ePelicula* listaPelicula, int nacionalidadID, int lenP, int lenD);

int contador_Peliculas_Nacionalidad(eDirector* listaDirectores, ePelicula* listaPelicula, int idNacionalidad, int cantP);

void hardcodeo_Directores(eDirector* listadoMainDirectores);


