#define OCUPADO 1
#define LIBRE 0

//ESTRUCTURA DE DATOS

typedef struct
{
    char titulo[100];
    int anio;
    char nacionalidad[50];
    int director;
    int id;
    int estado;
}ePelicula;

typedef struct
{
    int dia;
    int mes;
    int anio;
    int estado;
}eFechaNacimiento;


typedef struct
{
    char nombre[50];
    eFechaNacimiento listaFecha;
    char pais[50];
}eDirector;

//FUNCIONES
int inicializaLista(ePelicula[], int);

int buscaLugarLibre(ePelicula [],int);

int buscaIdSiguiente(ePelicula [],int);

int altaPelicula(ePelicula [],int);

int mostrarLista(ePelicula[],int);

int mostrarUno(ePelicula parametro);

int menuOpciones();

int buscarPorId(ePelicula [],int );

int baja(ePelicula [], int );

int modificacion(ePelicula [],int );

int cargaDatos(ePelicula[], int);

//FUNCIONES DEL DIRECTOR

/*int nuevoDirector(eDirector[], int);

int bajaDirector(eDirector[], int);

//FUNCIONES FECHA

int buscaLugarLibreDeFecha(eFechaNacimiento[],int);

int buscaIdSiguienteDeFecha(eFechaNacimiento[],int);

int AltaFecha(eFechaNacimiento[],int);

int cargaDatosDeFecha(eFechaNacimiento[],int);

int mostrarUnaFecha(eFechaNacimiento parametro);

int mostrarListaDeFechas(eFechaNacimiento[],int);
*/



