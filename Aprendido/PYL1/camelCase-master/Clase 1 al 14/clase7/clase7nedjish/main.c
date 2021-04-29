#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 3


//vectores paralelos

void cargarAlumnos(int[], char[][21]/*la matriz*/, int[], float[], int);/*cantidad de elementos*/)
void mostrarAlumnos(int[], char[][21]/*la matriz*/, int[], float[], int);
void ordenarPorNombres(int[], char[][21]/*la matriz*/, int[], float[], int);

/*ordenar por nombre
que muestre los alumnos aprobados nota tiene que ser mayor a 6
muestre los alumnos que se llaman juan
que muestre los alumnos cuyo nombre comienzan con p
el alumno con mas nota(sabiendo que puede ser mas que uno)
el mas mediocre legajo=100 nota=5 se llama pepe, medir 1.74
ingresar un legajo y permitir, la modificacion de la nota
transformar la carga de alumnos en una carga aleatoria*/


int main()
{
    int legajos[T];
    char nombres[T][21]; //la primera dimension las filas, la segunda dimension columnas, definimos una matriz 10*21
    int notas[T];
    float alturas[T][50];
    int i;

    cargarAlumnos(legajos, nombres, notas, alturas, T);
    mostrarAlumnos(legajos, nombres, notas, alturas, T);
    ordenarPorNombres(legajos, nombres, notas, alturas, T);
    printf("ordenado: \n");
    mostrarAlumnos(legajos, nombres, notas, alturas, T);

    return 0;
}

void cargarAlumnos(intlegajos[], char nombre [][21]/*la matriz*/, int notas[], float altura[], int)
{
    for(i=0; i<T; i++)
    {
        printf("ingrese legajo: \n");
        scanf("%d", &legajos[i]);
        printf("ingrese nombres: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("ingrese nota: ");
        scanf("%d", &notas[i]);
        printf("ingrese altura: ");
        scanf("%f", &alturas[i]);
        fflush(stdin);
    }

}

void mostrarAlumnos(int[legajo], char[nombre][21]/*la matriz*/, int[notas], float[alturas], int)
{
    printf("%4s   %20s   %2s   %5s","legajo","nombre","nota","altura");

    for(i=0; i<T; i++)
    {
        printf("%4d %20s %2d %5f\n", legajos[i], nombres[i], notas[i], alturas[i]);
    }

}

void ordenarPorNombres(int legajos[], char nombres[][21]/*la matriz*/, int notas[], float alturas[], int tam)
{
    int auxInt
    float auxFloat
    char auxString[100] /*los aux guardar un dato a la vez*/

    int i;
    int j; /*variabkles de control*/

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(nombres[i], nombres[j])>0)
            {
                strcpy(auxString,nombres[i]);
                strcpy(auxString[i],nombres[j]);
                strcpy(auxString[j],auxString);

                auxInt = legajos[i];
                lejagos[i]=legajos[j];
                legajos[j]=auxInt;
            }
        }
    }
}
