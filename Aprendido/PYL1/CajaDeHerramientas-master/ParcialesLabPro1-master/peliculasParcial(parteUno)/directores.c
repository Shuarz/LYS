#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "fecNac.h"


int nuevoDirector(eDirector, int TAMANO, eFechaNacimiento, int tamano)
{
    int indice;
    indice = buscaLugarLibre(lista, tamano);

    int id;
    id = buscaIdSiguiente(lista,tamano);


    if(indice < tamano)
    {
        puts("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[indice].titulo);
        while(strlen(lista[indice].titulo) >= 100)
        {
            puts("Nombre demasiado largo. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].titulo);
        }

        puts("Ingrese anio: ");
        fflush(stdin);
        scanf("%d", &lista[indice].anio);
        while(lista[indice].anio < 1900 || lista[indice].anio > 2100)
        {
            puts("Anio fuera de rango. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].anio);
        }

        puts("Ingrese nacionalidad");
        fflush(stdin);
        gets(lista[indice].nacionalidad);
        while(strlen(lista[indice].nacionalidad) >= 50)
        {
            puts("Nombre demasiado largo. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].nacionalidad);
        }

        puts("Ingrese ID director: ");
        fflush(stdin);
        scanf("%d", &lista[indice].director);


        lista[indice].id = id;
        lista[indice].estado = OCUPADO;
    }
    else
    {
        puts("No hay mas espacio");
    }

    return 0;
}


