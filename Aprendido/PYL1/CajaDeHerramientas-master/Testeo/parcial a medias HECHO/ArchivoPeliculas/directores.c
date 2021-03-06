#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directores.h"
#include "peliculas.h"




int inicializaListaDirectores(eDirector lista[], int tamano)
{
    int i;
    for(i = 0; i < tamano; i++)
    {
        lista[i].estado= LIBRE;
        lista[i].id = 0;
    }
    return 0;
}

int cargaInicialDirectores(eDirector lista[])
{

    char nombres[4][100] = {"Martin Scorcese", "David Lynch", "Pedro Rodriguez", "Juan Perez"};
    char paises[4][50] = {"EEUU", "EEUU", "Argentina", "Francia"};
    int dias [4] = {2,5,7,23};
    int meses[4] = {12,5, 11,2};
    int anios[4] = {1960, 1954, 1980, 1976};

    int i;
    for(i = 0; i < 4; i++)
    {
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].pais, paises[i]);
        lista[i].nacimiento.dia = dias[i];
        lista[i].nacimiento.mes = meses[i];
        lista[i].nacimiento.anio = anios[i];
        lista[i].id = i+1;
        lista[i].estado = OCUPADO;
    }
    return 0;
}



int buscaLugarLibreDirector(eDirector lista[],int tamano)
{
    int indice = -1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscaIdSiguienteDirector(eDirector lista[],int tamano)
{
    int id_mayor;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(lista[i].id > id_mayor)
            {
                id_mayor = lista[i].id;
            }
        }
    }
    return id_mayor + 1;
}


int altaDirector(eDirector lista[],int tamano)
{
    int indice;
    indice = buscaLugarLibreDirector(lista, tamano);

    int id;
    id = buscaIdSiguienteDirector(lista,tamano);


    if(indice >= 0)
    {
        char buffer[1024];

        puts("Ingrese nombre: ");
        fflush(stdin);
        gets(buffer);
        validaLargoCadena(buffer, 100);
        if(validaNuevoDirector(lista, buffer, tamano) == 1)
        {
            strcpy(lista[indice].nombre, buffer);

            puts("Ingrese pais de origen: ");
            fflush(stdin);
            gets(buffer);
            validaLargoCadena(buffer, 50);
            strcpy(lista[indice].pais, buffer);

            puts("Ingrese dia de nacimiento: ");
            fflush(stdin);
            scanf("%d", &lista[indice].nacimiento.dia);
            lista[indice].nacimiento.dia = validaRango(lista[indice].nacimiento.dia, 31, 1);

            puts("Ingrese mes de nacimiento: ");
            fflush(stdin);
            scanf("%d", &lista[indice].nacimiento.mes);
            lista[indice].nacimiento.mes = validaRango(lista[indice].nacimiento.mes, 12, 1);

            puts("Ingrese anio de nacimiento: ");
            fflush(stdin);
            scanf("%d", &lista[indice].nacimiento.anio);
            lista[indice].nacimiento.anio = validaRango(lista[indice].nacimiento.anio, 2010, 1800);

            lista[indice].id = id;
            lista[indice].estado = OCUPADO;

            puts("Se dio de alta un director");
        }
        else
        {
            puts("El director ya existe");
        }
    }
    else
    {
        puts("No hay mas espacio");
    }
    return 0;
}


int validaNuevoDirector(eDirector lista[], char nombre[], int tamano)
{
    int retorno = 1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && stricmp(lista[i].nombre, nombre)==0)
        {
            printf("*");
            retorno = -1;
            //break;
        }
    }
    return retorno;
}


int bajaDirector(eDirector lista[], int tamano)
{
    mostrarListaDirectores(lista, tamano);

    char nombre[100];
    puts("Ingrese el nombre del director: ");
    fflush(stdin);
    gets(nombre);
    int indice;
    indice = buscaDirectorPorNombre(lista, nombre, tamano);

    if(indice >= 0)
    {
        char comprobacion;
        puts("Se encontro al siguiente director:");
        printf("ID: %d - Nombre: %s - Pais: %s - Fecha de nacimiento: %d-%d-%d \n", lista[indice].id,
               lista[indice].nombre, lista[indice].pais, lista[indice].nacimiento.dia, lista[indice].nacimiento.mes,
               lista[indice].nacimiento.anio);
        puts("Desea continuar? s/n");
        comprobacion = pideYValidaSiNo();
        if(comprobacion == 's')
        {
            lista[indice].estado = LIBRE;
            puts("Se dio de baja al director");
        }
        else
        {
            puts("Accion cancelada");
        }
    }
    else if(indice == -1)
    {
        puts("No se encontro al director");
    }

    return 0;
}


int buscaDirectorPorNombre(eDirector lista[], char nombre[], int tamano)
{
    int indice = -1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(stricmp(lista[i].nombre, nombre)==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscaDirectorPorNombreDevuelveID(eDirector lista[], char nombre[], int tamano)
{
    int id = -1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(stricmp(lista[i].nombre, nombre)==0)
        {
            id = lista[i].id;
            break;
        }
    }
    return id;
}

int mostrarUnDirector(eDirector parametro)
{
    printf("%d - %s - %d-%d-%d - %s \n",parametro.id, parametro.nombre, parametro.nacimiento.dia, parametro.nacimiento.mes,
           parametro.nacimiento.anio, parametro.pais);
    return 0;
}

int mostrarListaDirectores(eDirector lista[],int tamano)
{
    puts("\n---------LISTADO DE DIRECTORES-------------\n");
    puts("ID - NOMBRE - FECHA DE NACIMIENTO - PAIS\n");

    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarUnDirector(lista[i]);
        }
    }
    return 0;
}

int buscaDirectorPorId(eDirector lista[], int id, int tamano)
{
    int bandera = 0;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].id == id)
        {
            bandera = 1;
            break;
        }
    }
    return bandera;
}
