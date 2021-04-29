#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"


eAlumno cargarUnAlumno()//no quiero que me devuelba nada por que lo que hace es tomar el dato
{
    eAlumno miAlumno; /*tipo de la variable*/

    printf("ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("ingrese nombres: ");
    fflush(stdin);
    gets(miAlumno.nombre); //cuendo es una matriz se usa esto //no hace fala el & porque es un ventor

    printf("ingrese altura: ");
    scanf("%f", &miAlumno.altura);
    fflush(stdin);

    printf("ingrese nota: ");
    scanf("%d", &miAlumno.nota);

    return miAlumno;
}

void mostrarUnAlumno(eAlumno unAlumno) //el parametro formal, puedo cambiar las variables, que al prototipo de arriba no le interesa
{
    printf("%d--%s--%f--%d\n", unAlumno.legajo, unAlumno.nombre, unAlumno.altura, unAlumno.nota);  /*asi muestro la estrucvtura*/
}

void cargarListadosDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i] = cargarUnAlumno();
    }

}
void mostrarListadosDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
         mostrarUnAlumno(listado[i]);
    }
}
void ordenarPorNombres(eAlumno listado[], int tam)
{
    int i;
    int j; /*variabkles de control*/

    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre, listado[j].nombre)>0)
            {
                auxAlumno=listado[i];
                listado[i]=listado[j];
                listado[j]=auxAlumno; //aca compara toda la esctrucrura

            }
        }
    }
}

