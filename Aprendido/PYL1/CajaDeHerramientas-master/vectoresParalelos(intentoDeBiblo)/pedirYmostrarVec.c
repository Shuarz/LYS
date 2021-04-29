#include <stdio.h>
#include <stdlib.h>
#define T 3;
#include "header.h"

void cargarAlumnos(int legajos[], char nombre[][21]/*la matriz*/, int notas[], float altura[], int tamanio)
{
    int i;
    for(i=0; i<T; i++)
    {
        printf("ingrese legajo: ");
        scanf("%d", &legajos[i]);
        printf("ingrese nombres: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("ingrese nota: ");
        scanf("%d", &notas[i]);
        printf("ingrese altura: ");
        scanf("%f", &alturas[i]);
    }

}

void mostrarAlumnos(int legajos[], char nombres[][21]/*la matriz*/, int notas[], float alturas[], int tamanio)
{
    printf("%4s   %20s   %2s   %5s","legajo","nombre","nota","altura");

    int i;
    for(i=0; i<T; i++)
    {
        printf("%4d %20s %2d %5f\n", legajos[i], nombres[i], notas[i], alturas[i]);
    }

}

