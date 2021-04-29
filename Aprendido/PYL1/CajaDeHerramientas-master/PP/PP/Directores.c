#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
#include "Directores.h"
#define isActive 0
#define isEmpty 1


static int ultimoId = 0;

static int ultimoID()
{
    ultimoId++;
    return ultimoId;
}

int inicializarDirector( eDirector listado[],int cantidad)
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

int buscarLibreDirector(eDirector listado[],int cantidad)
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


int cargarDatosDirector(eDirector listado[], int cantidad)
{
    int index = buscarLibreDirector(listado, cantidad);
    int anioCorrecto = 0;
    int mesCorrecto = 0;
    int diaCorrecto = 0;
    int idCorrecto = 0;
    getchar();
    if(index >=0)
    {

        char buffer[1024];

        eDirector miDirector;

        miDirector.id = ultimoID();

        printf("\nID: %d", miDirector.id);

        printf("\nIngrese Nombre: ");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>20 || !esSoloLetras(buffer) ||
                nombre_Repetido(listado, cantidad, buffer))
        {
            printf("Reingrese Nombre: ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(miDirector.nombre, buffer);

        printf("Ingrese anio de nacimiento: ");
        while(!anioCorrecto)
        {
            fflush(stdin);
            gets(buffer);
            if(esNumerico(buffer))
            {
                miDirector.nacimiento.anio = atoi(buffer);

                if(miDirector.nacimiento.anio < 1880 || miDirector.nacimiento.anio > 1990)
                {
                    printf("Error! Reingresar anio de nacimiento entre 1880 y 1990: \n");
                }
                else
                {
                    anioCorrecto = 1;
                }
            }
            else
            {
                printf("Error! Ingresar anio de nacimiento Numerico: ");
            }
        }
        printf("Ingrese mes de nacimiento: ");
        while(!mesCorrecto)
        {
            fflush(stdin);
            gets(buffer);
            if(esNumerico(buffer))
            {
                miDirector.nacimiento.mes = atoi(buffer);

                if(miDirector.nacimiento.mes < 1 || miDirector.nacimiento.mes > 12)
                {
                    printf("Error! Reingresar mes de nacimiento entre 1 y 12: \n");
                }
                else
                {
                    mesCorrecto = 1;
                }
            }
            else
            {
                printf("Error! Ingresar mes de nacimiento Numerico: ");
            }

        }
        printf("Ingrese dia de nacimiento: ");
        while(!diaCorrecto)
        {
            fflush(stdin);
            gets(buffer);
            if(esNumerico(buffer))
            {
                miDirector.nacimiento.dia = atoi(buffer);

                if(miDirector.nacimiento.dia < 1 || miDirector.nacimiento.dia > 31)
                {
                    printf("Error! Reingresar dia de nacimiento entre 1 y 31: \n");
                }
                else
                {
                    diaCorrecto = 1;
                }
            }
            else
            {
                printf("Error! Ingresar dia de nacimiento Numerico: ");
            }
        }
        printf("Ingrese ID Nacionalidad: ");
        while (!idCorrecto)
        {
            fflush(stdin);
            gets(buffer);

            if(esNumerico(buffer))
            {

                miDirector.idNacionalidad = atoi(buffer);
                if(miDirector.idNacionalidad < 1 || miDirector.idNacionalidad > 500)
                {
                    printf("Reingrese ID Nacionalidad entre un valor de 1 y 500: ");
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


        miDirector.estado = isActive;
        listado[index]= miDirector;

    }
    else
    {
        printf("\nERROR indice invalido u ocupado.\n");
    }
    return 1;
}

void mostrarUnDirector(eDirector unDirector, eNacionalidad* unaNacionalidad, int lenN)
{
    int i;
    char nacionaliad[500];
    strcpy(nacionaliad, "Nacionalidad no encontrada");
    for(i = 0; i < lenN; i++)
    {
        if(unDirector.idNacionalidad == unaNacionalidad[i].id)
        {
            strcpy(nacionaliad,unaNacionalidad[i].descripcion);
            break;
        }
    }
    printf("\n%-7d%-14s%7d/%d/%d%19s\n ", unDirector.id, unDirector.nombre, unDirector.nacimiento.dia, unDirector.nacimiento.mes, unDirector.nacimiento.anio, nacionaliad);

}


int listadoDirectores(eDirector listado[],int cantidad, eNacionalidad* nacionaliadListado, int lenN)
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
                mostrarUnDirector(listado[i],nacionaliadListado,lenN);
            }
        }
    }
    return retorno;
}

void darDeBajaDirector(eDirector listado[], int cantidad)
{
    int id;
    int flag=0;
    int i;
    char opcion;
    printf("Ingrese ID de director a dar de baja: ");
    scanf("%d", &id);
    for(i=0; i<cantidad; i++)
    {
        if(id==listado[i].id)
        {
            printf("\nID encontrado: \n");
            printf("Nombre: %s\n", listado[i].nombre);
            printf("Nacionalidad: %s\n", listado[i].nacionalidad);
            printf("Fecha de nacimiento: %d/%d/%d\n", listado[i].nacimiento.dia,listado[i].nacimiento.mes, listado[i].nacimiento.anio);



            printf("\n Seguro desea dar de baja? s=si n=no\n ");
            opcion=getche();
            if(opcion=='s')
            {
                listado[i].id=0;
                listado[i].estado=isEmpty;
                printf("\n­­Registro eliminado!!\n");
            }
            else if(opcion=='n')
            {
                printf("\nEl registro no fue eliminado!\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("ID inexistente\n");
        getch();
    }
}

void peliculas_Con_Director(ePelicula* listaPelicula, eDirector* listaDirector, int lenP, int lenD)
{
    int i;
    int j;
    printf("%15s %15s\n", "Titulo", "Director");
    for(i = 0; i<lenP; i++)
    {
        if(listaPelicula[i].estado == isActive)
        {

            for(j = 0; j<lenD; j++)
            {
                if(listaPelicula[i].idDirector == listaDirector[j].id)
                {
                    printf("%15s %15s\n", listaPelicula[i].titulo, listaDirector[j].nombre);
                    break;
                }
            }
        }
    }
}

int nombre_Repetido(eDirector* miDirector, int lenD, char* nombre)
{
    int retorno = 0;
    int i;
    for(i = 0; i < lenD; i++)
    {
        if(strcmp(miDirector[i].nombre, nombre )== 0)
        {
            printf("Nombre ya ingresado, por favor ingrese otro. ");
            retorno = 1;
            break;
        }
    }
    return retorno;
}



int contador_Peliculas(ePelicula* listaPelicula, int idDirector, int cantP)
{
    int contador = 0;
    int i;
    for(i = 0; i < cantP; i++)
    {
        if(listaPelicula[i].estado == isActive && listaPelicula[i].idDirector == idDirector)
        {
            contador++;
        }
    }
    return contador;
}


int director_Con_Mas_Peliculas(ePelicula* listaPelicula, eDirector* listaDirector, eNacionalidad* listaNacionalidad, int lenP, int lenD, int lenN)
{
    int contadorPeliculas;
    int mayorNumeroDePeliculas;
    int bandera = 0;
    int i;
    for(i=0; i<lenD; i++)
    {
        if(listaDirector[i].estado==isActive)
        {
            contadorPeliculas = contador_Peliculas(listaPelicula, listaDirector[i].id, lenP);
        }

        if(bandera == 0)
        {
            mayorNumeroDePeliculas = contadorPeliculas;
            bandera = 1;
        }

        if(contadorPeliculas > mayorNumeroDePeliculas)
        {
            mayorNumeroDePeliculas = contadorPeliculas;
        }
    }

    for(i=0; i<lenD; i++)
    {
        contadorPeliculas = contador_Peliculas(listaPelicula, listaDirector[i].id, lenP);
        if(listaDirector[i].estado==isActive && contadorPeliculas == mayorNumeroDePeliculas)
        {
            mostrarUnDirector(listaDirector[i], listaNacionalidad, lenN);
        }
    }
    return 0;
}

int busca_Nombre_Devuelve_ID(eDirector* listaDirector, char nombre[], int cantidad)
{
    int id = -1;
    int i;
    for(i = 0; i < cantidad; i++)
    {
        if(stricmp(listaDirector[i].nombre, nombre) == 0)
        {
            id = listaDirector[i].id;
            break;
        }
    }
    return id;
}





int peliculas_dirigidas_Por_Director(ePelicula* listaPelicula, eDirector* listaDirector, int lenP, int lenD)
{
    char nombreDirector[20];
    int directorID;
    int contadorDePeliculas;

    puts("Ingrese el nombre del director: ");
    fflush(stdin);
    gets(nombreDirector);
    directorID = busca_Nombre_Devuelve_ID(listaDirector, nombreDirector, lenD);
    if(directorID >= 0)
    {
        contadorDePeliculas = contador_Peliculas(listaPelicula, directorID, lenP);
        printf("%15s %15s\n", "Director", "    Cantidad de Peliculas");
        printf("%15s %15d\n", nombreDirector, contadorDePeliculas);
    }
    else
    {
        puts("\nEl director no existe!!\n");
    }
    return 0;
}
int busca_Pelicula_Por_Director(ePelicula* listaPelicula, int directorID, int lenP)
{
    int flag = 0;
    int i;
    for(i = 0; i < lenP; i++)
    {
        if(listaPelicula[i].estado == isActive && listaPelicula[i].idDirector == directorID)
        {
            printf("\n  %s\n", listaPelicula[i].titulo);
            flag = 1;
        }
    }
    if(flag==0)
    {
        puts("\nNo existen peliculas para mostrar!!\n");
    }
    return 0;
}



int peliculas_Por_Director(ePelicula* listaPelicula, eDirector* listaDirector, int lenP, int lenD)
{
    char nombreDirector[20];
    int directorID;
    puts("Introduzca el nombre del director: ");
    fflush(stdin);
    gets(nombreDirector);
    directorID = busca_Nombre_Devuelve_ID(listaDirector, nombreDirector, lenD);
    if(directorID>=0)
    {
        busca_Pelicula_Por_Director(listaPelicula, directorID, lenP);
    }
    else
    {
        puts("\nEl director no existe!!\n");
    }
    return 0;

}

int cantidad_Peliculas_Por_Nacionalidad(eNacionalidad* listaNacionalidad, ePelicula* listaPelicula, eDirector* listaDirector,
                                        int lenP, int lenD, int lenN)
{
    char nombreNacionalidad[20];
    int contadorDePeliculas;
    int nacionalidadID;

    puts("Ingrese la nacionalidad: ");
    fflush(stdin);
    gets(nombreNacionalidad);

    nacionalidadID = busca_Descripcion_Devuelve_IDNacionalidad(listaNacionalidad, nombreNacionalidad, lenN);
    if(nacionalidadID >= 0)
    {
        contadorDePeliculas = contador_Peliculas_Nacionalidad(listaDirector, listaPelicula, nacionalidadID, lenP);
        printf("%15s %15s\n", "Nacionalidad", "    Cantidad de Peliculas");
        printf("%15s %15d\n", nombreNacionalidad, contadorDePeliculas);
    }
    else
    {
        puts("\nLa nacionalidad no existe!!\n");
    }
    return 0;
}

int contador_Peliculas_Nacionalidad(eDirector* listaDirectores, ePelicula* listaPelicula, int idNacionalidad, int cantP)
{
    int contador = 0;
    int i;
    int j;
    for(i = 0; i < cantP; i++)
    {
        if(listaDirectores[i].estado == isActive && listaDirectores[i].idNacionalidad == idNacionalidad)
        {
            for(j = 0; j < cantP; j++)
            {
                if(listaPelicula[j].estado == isActive && listaPelicula[j].idDirector == listaDirectores[i].id )
                {
                    contador++;
                }
            }
        }
    }
    return contador;
}


int busca_Descripcion_Devuelve_IDNacionalidad(eNacionalidad* listaNacionalidad, char nombre[], int cantidad)
{
    int id = -1;
    int i;
    for(i = 0; i < cantidad; i++)
    {
        if(stricmp(listaNacionalidad[i].descripcion, nombre) == 0)
        {
            id = listaNacionalidad[i].id;
            break;
        }
    }
    return id;
}


int busca_Pelicula_Por_Nacionalidad_Director(eDirector* listaDirector, ePelicula* listaPelicula, int nacionalidadID, int lenP, int lenD)
{
    int flag = 0;
    int i;
    int j;
    for(i = 0; i < lenD; i++)
    {
        if(listaDirector[i].estado == isActive && listaDirector[i].idNacionalidad == nacionalidadID)
        {
            for( j=0; j< lenP; j++)
            {
                if(listaPelicula[j].estado == isActive && listaPelicula[j].idDirector == listaDirector[i].id)
                {
                    printf("\n  %s\n", listaPelicula[j].titulo);
                    flag = 1;
                }
            }

        }
    }
    if(flag==0)
    {
        puts("\nNo existen peliculas para mostrar!!\n");
    }
    return 0;
}

void hardcodeo_Directores(eDirector* listadoMainDirectores)
{
    listadoMainDirectores[0].id = 0;
    listadoMainDirectores[0].nacimiento.anio = 1900;
    listadoMainDirectores[0].nacimiento.mes = 3;
    listadoMainDirectores[0].nacimiento.dia = 2;
    listadoMainDirectores[0].idNacionalidad = 1;
    strcpy(listadoMainDirectores[0].nombre, "Marquitos");
    listadoMainDirectores[0].estado = isActive;

    listadoMainDirectores[1].id = 1;
    listadoMainDirectores[1].nacimiento.anio = 1950;
    listadoMainDirectores[1].nacimiento.mes = 10;
    listadoMainDirectores[1].nacimiento.dia = 30;
    listadoMainDirectores[1].idNacionalidad = 2;
    strcpy(listadoMainDirectores[1].nombre, "Juan");
    listadoMainDirectores[1].estado = isActive;

    ultimoId = 1;
}

