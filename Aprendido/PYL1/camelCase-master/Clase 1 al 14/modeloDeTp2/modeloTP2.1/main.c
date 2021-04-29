#include <stdio.h>
#include <stdlib.h>
#include "funcionesAlumnos.h"
#define T 3

int main()
{
    eAlumno listado[T];
    int opcion;

    do{

        inicializarArrayIlogocamenteNota(listado, T);
        opcion = menuOpciones();

        switch(opcion){
            case 1:
                cargarAlumnosEspacioLibre(listado, T);
                break;
            case 2:
                mostrarListadoDeAlumnos(listado, T);
                break;
            case 3:
                ordenarPorNombre(listado, T);
                break;
            case 4:
                alumnosAprobados(listado, T);
                break;
            case 5:
                alumnoNombreConP(listado, T);
                break;
            case 6:
                alumnosNotaMasAlta(listado, T);
                break;
            case 7:
                modificacionDeNota(listado, T);
                break;
            case 8:
                opcion = 8;
                break;
            default:
                printf("Ingrese opcion valida");
        }

    }while(opcion != 8);

    return 0;
}
