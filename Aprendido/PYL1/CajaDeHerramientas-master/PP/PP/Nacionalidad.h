


typedef struct
{
    int id;
    char descripcion[20];
    int estado;

}eNacionalidad;

int buscarLibreNacionalidad(eNacionalidad listado[],int cantidad);

int inicializarNacionalidad(eNacionalidad listado[], int cantidad);

void hardcodeo_Nacionalidad(eNacionalidad* listadoMainNacionalidad);
