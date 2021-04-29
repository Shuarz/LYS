#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define A 3


int main()
{
    eAlumno listadoMain[A];

    cargarListadosDeAlumnos(listadoMain, A); //asi le paso el array

    mostrarListadosDeAlumnos(listadoMain, A);

    ordenarPorNombres(listadoMain, A);

    printf("\n Ordenado por nombre: \n");

    mostrarListadosDeAlumnos(listadoMain, A);

   // printf("%d\n\n", sizeof(eAlumno));


        //mostrarUnAlumno(miAlumno);

     //otroAlumno = miAlumno; //le asigo el valor a otroAlumno

    return 0;
}



/*
                strcpy(auxString,listado[i].nombre); //con el punto entro al campo de la estrutura
                strcpy(auxString[i],listado[j].nombre);
                strcpy(auxString[j].legajo,auxString);

                auxInt = listado[i].legajo;
                lejago[i]=listado[j].legajo;
                legajo[j].legajo=auxInt;

                auxFloat = altura[i];
                altura[i]=altura[j];
                altura[j]=auxFloat;

                auxInt = nota[i];
                nota[i]=nota[j];
                nota[j]=auxInt;

            }*/


            void modificcarListadoDeAlumnos(sAlumno listado[,itm])

            int legajo;
            ont
            prinft(omgrese lejado)
            scanf(%d, &legajo)

            for(i=0; i<tam; i++)
            {
                if (legajo == listado[i].legajo)
                {
                    //mostrar aluimnos
                    //pida la nueva nota
                    //pregunto si esta segiro
                    //si y hago la asignacion de nota
                    //no y aviso que se cancelo la modiicacion

                }
            }
