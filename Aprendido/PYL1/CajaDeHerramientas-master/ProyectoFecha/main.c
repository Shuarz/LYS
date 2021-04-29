#include <stdio.h>
#include <stdlib.h>
#define TAMANO 2
#define OCUPADO 1
#define LIBRE 0


typedef struct
{
    int dia;
    int mes;
    int anio;
    int estado;
    int id;
}eFechaNacimiento;

int buscaLugarLibreDeFecha(eFechaNacimiento[],int);

int buscaIdSiguienteDeFecha(eFechaNacimiento[],int);

int AltaFecha(eFechaNacimiento[],int);

int cargaDatosDeFecha(eFechaNacimiento[],int);

int mostrarUnaFecha(eFechaNacimiento, parametro);

int mostrarListaDeFechas(eFechaNacimiento[],int);


int main()
{



    return 0;
}


int buscaLugarLibreDeFecha(eFechaNacimiento lista[],int tamano)
{
    int retorno;
    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int buscaIdSiguienteDeFecha(eFechaNacimiento lista[],int tamano)
{
    int retorno = -1;
    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(lista[i].id>retorno)
            {
                retorno=lista[i].id;
            }
        }
    }
    return retorno+1;
}

int AltaFecha(eFechaNacimiento lista, int TAMANO)
{
    int indice;
    indice = buscaLugarLibre(lista, tamano);

    int id;
    id = buscaIdSiguiente(lista,tamano);

    puts("Ingrese anio: ");
        fflush(stdin);
        scanf("%d", &lista[indice].anio);
        while(lista[indice].anio < 1800 || lista[indice].anio > 2100)
        {
            puts("Anio fuera de rango. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].anio);
        }

        puts("Ingrese mes: ");
        fflush(stdin);
        scanf("%d", &lista[indice].mes);
        while(lista[indice].mes < 0 || lista[indice].mes > 13)
        {
            puts("mes fuera de rango. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].mes);
        }

        puts("Ingrese dia: ");
        fflush(stdin);
        scanf("%d", &lista[indice].dia);
        while(lista[indice].dia < 0 || lista[indice].dia > 32)
        {
            puts("dia fuera de rango. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].dia);
        }

}

int cargaDatosDeFecha(eFechaNacimiento lista[],int tamano)
{

    int anios[tamano];
    int mes[tamano];
    int dia[tamano];

    int i;
    for(i = 0; i < tamano; i++)
    {
        lista[i]. anio = anios[i];
        lista[i]. mes = mes[i];
        lista[i]. dia = dia[i];
    }
    return 0;
}

int mostrarUnaFecha(eFechaNacimiento lista, parametro, TAMANO)
{
    printf("\n%d - %d - %d \n",parametro.anios,parametro.mes,parametro.dia);
    return 0;
}

int mostrarListaDeFechas(eFechaNacimiento lista[],int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarUnaFecha(lista[i]);
        }
    }
    return 0;
}
