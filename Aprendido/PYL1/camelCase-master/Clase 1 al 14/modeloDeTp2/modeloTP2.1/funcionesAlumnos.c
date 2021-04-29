#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesAlumnos.h"

void mostrarAlumno(eAlumno unAlumno)
{
    printf("%d--%s--%f--%d\n", unAlumno.legajo, unAlumno.nombre, unAlumno.altura, unAlumno.nota);

    system("pause");
    system("cls");
}

eAlumno cargarAlumno()
{

    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin),
           gets(miAlumno.nombre);

    printf("Ingrese altura: ");
    scanf("%f", &miAlumno.altura);

    printf("Ingrese nota: ");
    scanf("%d", &miAlumno.nota);

    system("cls");


    return miAlumno;
}

void cargarListadoDeAlumnosSecuencialmente(eAlumno listado[], int tam)
{

    int i;
    for(i = 0; i < tam; i++)
    {
        listado[i] = cargarAlumno();
    }
}
void mostrarListadoDeAlumnos(eAlumno listado[], int tam)
{


    int i;
    for(i = 0; i < tam; i++)
    {
        mostrarAlumno(listado[i]);
    }

    system("pause");
    system("cls");

}

void ordenarPorNombre(eAlumno listado[], int tam)
{
    int i;
    int j;

    eAlumno auxAlumno;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(strcmp(listado[i].nombre, listado[j].nombre) > 0)
            {
                auxAlumno=listado[i];
                listado[i]=listado[j];
                listado[j]=auxAlumno;
            }
        }
    }

    printf("%4s %20s %4s %5s\n", "Legajo", "Nombre", "Nota", "Altura");
    mostrarListadoDeAlumnos(listado, tam);

}

void alumnoNombreConP(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].nombre[0] == 'p')
        {
            mostrarAlumno(listado[i]);
        }
    }

    system("pause");
    system("cls");

}

int menuOpciones()
{

    int opcion;

    printf("1-Alta de alumnos \n");
    printf("2-Ver listado de alumnos \n");
    printf("3-Ordenar alfabeticamente \n");
    printf("4-Alumnos aprobados \n");
    printf("5-Alumnos cuyo nombre comienza con P \n");
    printf("6-Alumno/s con nota mas alta \n");
    printf("7-Modificar una nota por legajo: \n");
    printf("8-Salir \n");
    printf("Ingrese opcion: \n");

    scanf("%d", &opcion);

    system("cls");

    return opcion;

}

void inicializarArrayIlogicamenteNota(eAlumno listado[], int tam)
{

    int i;
    for(i = 0; i < tam; i++)
    {
        listado[i].estado = -1;
    }

}

void alumnosAprobados(eAlumno listado[], int tam)
{

    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].nota > 6)
        {
            mostrarAlumno(listado[i]);
        }
    }

    system("pause");
    system("cls");


}
/*
int buscarLibre(eAlumno listado[], int tam, int ilogico)
{
    int index = -1;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i] == ilogico)
        {
            index = i;
            break;
        }
    }

    return index;
}
*/

void modificacionDeNotas(eAlumno listado[], int tam) //esto lo hice yo
{
    int auxInt;
    int i;
    cargo == 0; //hago una bandera con esto
    printf("ingrese un legajo")
    scanf("%d", &auxInt);

    for(i=0; i<T; i++)
    {
        if(listado[i].listado !=VACIO && auxInt == listado[i].legajo) //siempre que hago una busqueda teiene que estar chequado por el estado
        {
            printf("ingrese la nueva nota");
            scanf("%d", &listado[i].nota);
            cargo = 1;
        }
    }

    if(cargo==0)
    {
        printf("legajo inexistente");
    }

}


void alumnosNotaMasAlta(eAlumno listado[], int tam)
{

    int notaMax;

    int i;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].nota > notaMax)
        {
            notaMax = listado[i].nota;
        }
    }

    for(i = 0; i < tam; i++)
    {
        if(listado[i].nota == notaMax)
        {
            mostrarAlumno(listado[i]);
        }
    }

}

void cargarAlumnosEspacioLibre(eAlumno listado[], int tam)
{

    inicializarArrayIlogicamenteNota(listado, tam);

    int i;
    int bandera = 0;
    for(i = 0; i < tam; i++)
    {

        if(listado[i].nota == -1)
        {
            cargarAlumno();
            bandera = 1;
            break;
        }
    }

    if(bandera == 0)
    {
        printf("No hay mas espacio");
    }


}



