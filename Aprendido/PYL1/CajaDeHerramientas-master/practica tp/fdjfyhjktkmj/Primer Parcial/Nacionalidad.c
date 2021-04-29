#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
#include "Nacionalidad.h"
#define isActive 0
#define isEmpty 1



int inicializarNacionalidad(eNacionalidad listado[], int cantidad)
{
    int retorno = -1;
    int i;
    if(cantidad > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<cantidad; i++)
        {
            listado[i].estado = isEmpty;
            listado[i].id= 0;
        }
    }
    return retorno;
}
int buscarLibreNacionalidad(eNacionalidad listado[],int cantidad)
{
    int index = -1;
    int i;
    if(cantidad > 0 && listado != NULL)
    {
        index = -2;
        for(i=0; i<cantidad; i++)
        {
            if(listado[i].estado == isEmpty)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

void hardcodeo_Nacionalidad(eNacionalidad* listadoMainNacionalidad)
{
    listadoMainNacionalidad[0].id = 1;
    strcpy(listadoMainNacionalidad[0].descripcion , "Argentino");
    listadoMainNacionalidad[0].estado = isActive;

    listadoMainNacionalidad[1].id = 2;
    strcpy(listadoMainNacionalidad[1].descripcion , "Peruano");
    listadoMainNacionalidad[1].estado = isActive;

    listadoMainNacionalidad[2].id = 3;
    strcpy(listadoMainNacionalidad[2].descripcion , "Brasilero");
    listadoMainNacionalidad[2].estado = isActive;
}
