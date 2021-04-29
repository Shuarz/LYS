#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
#include "Peliculas.h"
#define isActive 0
#define isEmpty 1



static int ultimoId = 0;

static int ultimoID()
{
    ultimoId++;
    return ultimoId;
}

int buscarLibrePelicula(ePelicula listado[],int cantidad)
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

int cargarDatosPelicula(ePelicula listado[], int cantidad)
{
    int index = buscarLibrePelicula(listado, cantidad);
    int anioCorrecto = 0;
    int idCorrecto = 0;

    getchar();
    if(index >=0)
    {
        char buffer[1024];

        ePelicula miPelicula;

        miPelicula.identificador = ultimoID();

        printf("\nID: %d", miPelicula.identificador);

        printf("\nIngrese Titulo: ");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>20)
        {
            printf("Reingrese Titulo: ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(miPelicula.titulo, buffer);

        printf("Ingrese Anio: ");

        while(!anioCorrecto)
        {
            fflush(stdin);
            gets(buffer);
            if(esNumerico(buffer))
            {
                miPelicula.anio = atoi(buffer);
                if (miPelicula.anio < 1900 || miPelicula.anio > 2018)
                {
                    printf("Error! Ingresar anio entre 1900 y 2018: ");
                }
                else
                {
                    anioCorrecto = 1;
                }
            }
            else
            {
                printf("Error! Ingresar anio Numerico: ");
            }
        }
        printf("Ingrese Nacionalidad: ");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>30 || !esSoloLetras(buffer))
        {
            printf("Reingrese Nacionalidad: ");
            fflush(stdin);
            gets(buffer);

        }
        strcpy(miPelicula.nacionalidad, buffer);

        printf("Ingrese ID del director: ");
        while (!idCorrecto)
        {
            fflush(stdin);
            gets(buffer);

            if(esNumerico(buffer))
            {

                miPelicula.idDirector = atoi(buffer);
                if(miPelicula.idDirector < 1 || miPelicula.idDirector > 500)
                {
                    printf("Reingrese ID del director entre un valor de 1 y 500: ");
                }
                else
                {
                    idCorrecto = 1;
                }

            }
            else
            {
                printf("Error! Ingresar ID del director Numerico: ");
            }
        }

        miPelicula.estado = isActive;
        listado[index]= miPelicula;

    }
    else
    {
        printf("\nERROR indice invalido u ocupado.\n");
    }
    return 1;

}
void mostrarUnaPelicula(ePelicula unaPelicula)
{
    printf("%-7d%-14s%-7d%-15s\n", unaPelicula.identificador, unaPelicula.titulo,unaPelicula.anio,unaPelicula.nacionalidad);

}

int listadoPelicula(ePelicula listado[],int cantidad)
{
    int retorno = -1;
    int i;
    if(cantidad > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<cantidad; i++)
        {
            if(listado[i].estado==isActive)
            {

                mostrarUnaPelicula(listado[i]);
            }
        }
    }
    return retorno;
}

int inicializarPelicula( ePelicula listado[],int cantidad)
{

    int retorno = -1;
    int i;
    if(cantidad > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<cantidad; i++)
        {
            listado[i].estado = isEmpty;
            listado[i].identificador= 0;
        }
    }
    return retorno;
}

void modificarUnaPelicula(ePelicula listado[], int cantidad)
{
    ePelicula miPelicula;
    char buffer[1024];
    int identificador;
    char opcion;
    int i;
    int flag = 0;
    int anioCorrecto = 0;
    int idCorrecto = 0;
    printf("Ingrese un ID de Pelicula a buscar: ");
    scanf("%d", &identificador);

    for(i=0; i<cantidad; i++)
    {
        printf("%d", listado[i].identificador);
        if(identificador == listado[i].identificador)
        {

            printf(".ID de la pelicula encontrado presione enter para continuar!!\n");



            opcion=getche();

            do
            {
                printf("\n¿Que cambios desea hacer?");
                printf("\na. Cambiar titulo");
                printf("\nb. Cambiar anio ");
                printf("\nc. Cambiar Nacionalidad");
                printf("\nd. Cambiar ID del director");
                printf("\nz. Ninguno, salir");
                printf("\nIngrese una opcion: \n");
                scanf("%s", &opcion);
                switch(opcion)
                {
                case 'a':
                    printf("\nIngrese el nuevo titulo: ");
                    fflush(stdin);
                    gets(buffer);
                    while(strlen(buffer)>20)
                    {
                        printf("Reingrese Titulo: ");
                        fflush(stdin);
                        gets(buffer);
                    }
                    strcpy(miPelicula.titulo, buffer);

                    printf("¿Esta seguro que desea modificar el titulo? s=si n=no\n ");
                    opcion=getche();
                    if(opcion=='s')
                    {
                        strcpy(listado[i].titulo, miPelicula.titulo);
                        printf("\nTitulo modificado!!\n");
                    }
                    else if(opcion=='n')
                    {
                        printf("El titulo no fue modificado!!\n");
                    }
                    break;
                case 'b':
                    printf("\nIngrese el nuevo anio: ");
                    while(!anioCorrecto)
                    {
                        fflush(stdin);
                        gets(buffer);
                        if(esNumerico(buffer))
                        {
                            miPelicula.anio = atoi(buffer);
                            if (miPelicula.anio < 1900 || miPelicula.anio > 2018)
                            {
                                printf("Error! Ingresar anio entre 1900 y 2018: ");
                            }
                            else
                            {
                                anioCorrecto = 1;
                            }
                        }
                        else
                        {
                            printf("Error! Ingresar anio Numerico: ");
                        }
                    }
                    printf("¿Esta seguro que desea modificar el anio? s=si n=no\n ");
                    opcion=getche();
                    if(opcion=='s')
                    {
                        listado[i].anio = miPelicula.anio;
                        printf("\nEl anio fue modificado!!\n");
                    }
                    else if(opcion=='n')
                    {
                        printf("El anio no fue modificado!!\n");
                    }
                    break;
                case 'c':
                    printf("\nIngrese la nueva nacionalidad: ");
                    fflush(stdin);
                    gets(buffer);
                    while(strlen(buffer)>30 || !esSoloLetras(buffer))
                    {
                        printf("Reingrese Nacionalidad: ");
                        fflush(stdin);
                        gets(buffer);

                    }
                    strcpy(miPelicula.nacionalidad, buffer);

                    printf("¿Esta seguro que desea modificar la nacionalidad? s=si n=no\n ");
                    opcion=getche();
                    if(opcion=='s')
                    {
                        strcpy(listado[i].nacionalidad, miPelicula.nacionalidad);
                        printf("\nNacionalidad modificada!!\n");
                    }
                    else if(opcion=='n')
                    {
                        printf("La nacionalidad no fue modificada!!\n");
                    }
                    break;
                case 'd':
                    printf("\nIngrese el nuevo ID del director: ");
                    while (!idCorrecto)
                    {
                        fflush(stdin);
                        gets(buffer);

                        if(esNumerico(buffer))
                        {

                            miPelicula.idDirector = atoi(buffer);
                            if(miPelicula.idDirector < 1 || miPelicula.idDirector > 500)
                            {
                                printf("Reingrese ID del director entre un valor de 1 y 500: ");
                            }
                            else
                            {
                                idCorrecto = 1;
                            }

                        }
                        else
                        {
                            printf("Error! Ingresar ID del director Numerico: ");
                        }
                    }

                    printf("¿Esta seguro que desea modificar el ID del director? s=si n=no\n ");
                    opcion=getche();
                    if(opcion=='s')
                    {
                        listado[i].idDirector = miPelicula.idDirector;
                        printf("\nID del director modificado!!\n");
                    }
                    else if(opcion=='n')
                    {
                        printf("El ID del director no fue modificado!!\n");
                    }
                    break;
                }
            }
            while(opcion !='z');

            flag=1;
            break;

        }
    }

    if(flag==0)
    {
        printf("ID inexistente, ustede sera devuelto al menu principal\n");
        getch();
    }
}


void darDeBajaPelicula(ePelicula listado[], int cantidad)
{
    int identificador;
    int flag=0;
    int i;
    char opcion;
    printf("Ingrese ID de pelicula a dar de baja: ");
    scanf("%d", &identificador);
    for(i=0; i<cantidad; i++)
    {
        if(identificador==listado[i].identificador)
        {


            printf("\nID de pelicula encontrada!!. ¨Seguro desea dar de baja? s=si n=no\n ");
            opcion=getche();
            if(opcion=='s')
            {
                listado[i].identificador=0;
                listado[i].estado=isEmpty;
                printf("\n­­Registro eliminado!!\n");
            }
            else if(opcion=='n')
            {
                printf("\nEl registro no fue eliminado!!\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("ID inexistente, usted sera devuelto al menu principal\n");
        getch();
    }
}

int peliculas_Mas_Viejas(ePelicula listado[], int cantidadP)
{
    int anioAnterior;
    int flag = 0;
    int i;
    for(i = 0; i < cantidadP; i++)
    {
        if(listado[i].estado==isActive && flag==0)
        {
            anioAnterior = listado[i].anio;
            flag = 1;
        }

        if(listado[i].estado == isActive && listado[i].anio < anioAnterior)
        {
            anioAnterior = listado[i].anio;
        }
    }

    for(i = 0; i < cantidadP ; i++)
    {
        if(listado[i].estado == isActive && listado[i].anio == anioAnterior)
        {
            mostrarUnaPelicula(listado[i]);
        }
    }
    return 0;
}

void hardcodeo_Peliculas(ePelicula* listadoMainPelicula)
{
    listadoMainPelicula[0].anio = 2008;
    listadoMainPelicula[0].idDirector = 1;
    listadoMainPelicula[0].identificador = 0;
    listadoMainPelicula[0].estado = isActive;
    strcpy(listadoMainPelicula[0].nacionalidad,"Peruano");
    strcpy(listadoMainPelicula[0].titulo,"El wachin");

    listadoMainPelicula[1].anio = 2016;
    listadoMainPelicula[1].estado = isActive;
    listadoMainPelicula[1].idDirector = 0;
    listadoMainPelicula[1].identificador = 1;
    strcpy(listadoMainPelicula[1].nacionalidad,"Argentino");
    strcpy(listadoMainPelicula[1].titulo,"El wachin 2");

    ultimoId = 1;
}
