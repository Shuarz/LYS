#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#include "header.h"

//vectores paralelos



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
    int cargar;
    int mostrar;

    cargar=cargarAlumnos(legajos, nombres, notas, alturas, T);
    mostrar=mostrarAlumnos(legajos, nombres, notas, alturas, T);



    return 0;
}

