#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"

#define TAMANO 2


int main()
{
    int opcionMenu;
    ePelicula listaPeliculas[TAMANO];
    //eDirector listaDirector[TAMANO];
    //eFechaNacimiento listaFecha[TAMANO];
    inicializaLista(listaPeliculas, TAMANO);

    cargaDatos(listaPeliculas, TAMANO);

    do
    {
        opcionMenu = menuOpciones();

        switch(opcionMenu)
        {
        case 1:
            altaPelicula(listaPeliculas, TAMANO);
            break;

        case 2:
            modificacion(listaPeliculas, TAMANO);
            break;

        case 3:
             baja(listaPeliculas, TAMANO);
            break;

        case 4:
            //nuevoDirector(listaDirector, TAMANO);
            break;

        case 5:
            //eliminarDirector(listaDirector, TAMANO);
            break;

        case 6:
            mostrarLista(listaPeliculas, TAMANO, listaDirector, TAMANO, listaFecha, TAMANO);
            break;

        case 7:
            printf("tenga un buen dia, adios\n");
            break;
        default:
            printf("ingrese un numero valido\n");
            break;

        }
    system("pause");
    system("cls");

    }
    while(opcionMenu != 7);




    return 0;
}


