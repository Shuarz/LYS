#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Directores.h"
#include "MenuDeOpciones.h"
#define CANTIDADPELICULAS 500
#define CANTIDADDIRECTORES 500
#define CANTIDADNACIONALIDADES 500


void menuDeOpciones()
{
    ePelicula listadoMainPelicula[CANTIDADPELICULAS];
    eDirector listadoMainDirectores[CANTIDADDIRECTORES];
    eNacionalidad listadMainNacionalidad[CANTIDADNACIONALIDADES];
    inicializarNacionalidad(listadMainNacionalidad, CANTIDADNACIONALIDADES);
    inicializarPelicula( listadoMainPelicula,CANTIDADPELICULAS);
    inicializarDirector( listadoMainDirectores,CANTIDADDIRECTORES);


    hardcodeo_Peliculas(listadoMainPelicula);
    hardcodeo_Directores(listadoMainDirectores);
    hardcodeo_Nacionalidad(listadMainNacionalidad);

    char opcion2;
    int opcion;
    do
    {

        printf("\n1. Alta pelicula.");
        printf("\n2. Modificar datos de una pelicula.");
        printf("\n3. Dar de baja pelicula.");
        printf("\n4. Ingresar Nuevo director.");
        printf("\n5. Dar de baja Director.");
        printf("\n6. Consultar.");
        printf("\n7. Salir.");
        printf("\nIngrese una opcion: \n");
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            cargarDatosPelicula(listadoMainPelicula,CANTIDADPELICULAS);
            break;
        case 2:
            modificarUnaPelicula(listadoMainPelicula, CANTIDADPELICULAS);
            break;
        case 3:
            darDeBajaPelicula(listadoMainPelicula, CANTIDADPELICULAS);
            break;
        case 4:
            cargarDatosDirector(listadoMainDirectores, CANTIDADDIRECTORES);
            break;
        case 5:
            darDeBajaDirector(listadoMainDirectores, CANTIDADDIRECTORES);
            break;
        case 6:

            do
            {
                printf("\na. Peliculas.");
                printf("\nb. Directores.");
                printf("\nc. La/s peliculas mas viejas.");
                printf("\nd. Cada pelicula con el nombre de su director.");
                printf("\ne. Peliculas por director.");
                printf("\nf. Cantidad de peliculas por director.");
                printf("\ng. Director con mas peliculas.");
                printf("\nh. Todas las peliculas cuyo director sea Argentino.");
                printf("\ni. Cantidad de peliculas por nacionalidad.");
                printf("\nj. Salir.");
                printf("\nIngrese una opcion: \n");

                fflush(stdin);
                scanf("%c", &opcion2);

                switch(opcion2)
                {
                case 'a':
                    printf("PELICULAS\n\n");
                    printf("%-7s%-14s%-7s%-15s\n", "ID", "Titulo", "Anio", "Nacionalidad");
                    listadoPelicula(listadoMainPelicula, CANTIDADPELICULAS);
                    break;
                case 'b':
                    printf("\nDIRECTORES: \nID    Nombre         Fecha de Nacimiento    Nacionalidad\n");
                    listadoDirectores(listadoMainDirectores, CANTIDADDIRECTORES, listadMainNacionalidad, CANTIDADNACIONALIDADES);
                    break;
                case 'c':
                    printf("PELICULAS\n\n");
                    printf("%-7s%-14s%-7s%-15s\n", "ID", "Titulo", "Anio", "Nacionalidad");
                    peliculas_Mas_Viejas(listadoMainPelicula, CANTIDADPELICULAS);
                    break;
                case 'd':
                    peliculas_Con_Director(listadoMainPelicula, listadoMainDirectores, CANTIDADPELICULAS, CANTIDADDIRECTORES);
                    break;
                case 'e':
                    peliculas_Por_Director(listadoMainPelicula, listadoMainDirectores, CANTIDADPELICULAS, CANTIDADDIRECTORES);
                    break;
                case 'f':
                    peliculas_dirigidas_Por_Director(listadoMainPelicula, listadoMainDirectores, CANTIDADPELICULAS, CANTIDADDIRECTORES);
                    break;
                case 'g':
                    puts("\nEl siguiente director tiene la mayor cantidad de peliculas: ");
                    printf("\nID    Nombre         Fecha de Nacimiento    Nacionalidad\n");
                    director_Con_Mas_Peliculas(listadoMainPelicula, listadoMainDirectores, listadMainNacionalidad, CANTIDADPELICULAS, CANTIDADDIRECTORES, CANTIDADNACIONALIDADES);
                    break;
                case 'h':
                    busca_Pelicula_Por_Nacionalidad_Director(listadoMainDirectores, listadoMainPelicula, 1, CANTIDADPELICULAS, CANTIDADDIRECTORES);
                    break;
                case 'i':
                    cantidad_Peliculas_Por_Nacionalidad(listadMainNacionalidad, listadoMainPelicula, listadoMainDirectores
                                                        ,CANTIDADPELICULAS,CANTIDADDIRECTORES, CANTIDADNACIONALIDADES);
                    break;
                case 'j':

                    break;
                default:
                    printf("Opcion incorrecta!!");
                    break;
                }


            }
            while(opcion2 !='j');
            break;

        case 7:
            printf("\nAdios tenga buen dia.");
            break;
        default:
            printf("\nOpcion incorrecta, por favor elegir una opcion entre el 1 y 7\n");
        }
    }
    while(opcion !=7);
}


