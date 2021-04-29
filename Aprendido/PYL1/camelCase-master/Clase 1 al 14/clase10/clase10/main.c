#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{
    char seguir='s';
    int opcion=0;
    int auxInt;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");



        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                cargarAlumnosEspacioLibre
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 7: modificacion de notas


                /*
                pedir un legajo
                busco ese legajo en los alumnos
                si lo encuentra pide una nueva nota, sino notifico al usuario
                la funcion buscar libre, tambien se usa para buscar legajo
                */
                seguir = 'n';
                break;
        }
    }

    return 0;
}

/*
modifico el estado para eliminar el alumno ingresado
*/

