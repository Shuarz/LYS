#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct //asi definimos una reestructuras
{   /*a las variables se las llama camops de la estrucuras (nombre, lejçgajo, edad)*/
    int legajo;
    char nombre[50]; //solo hace falra declarar los carateres que se van a usar, si necesito mas, hago un vector de alumnos
    float altura;
    int nota;
} eAlumno; /*(e de estructura y el nombre de la entidad)*/

/*debajo de la estructuras se delaran las funciones*/

void cargarListadosDeAlumnos(eAlumno[], int);

void mostrarListadosDeAlumnos(eAlumno[], int);

void ordenarPorNombres(eAlumno[], int);

void mostrarUnAlumno(eAlumno);

eAlumno cargarUnAlumno(); //no recibe nada por ahgora la funcion


