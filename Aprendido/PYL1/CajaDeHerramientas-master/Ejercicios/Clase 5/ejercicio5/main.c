#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headerEjer.h"

#define Cantidad 5

/* 1) Solicitar al usuario 5 números, permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
 Permitir Modificar el valor de cualquiera de los números cargados indicando el índice del mismo y su nuevo valor. */


int main()
{
    int arrayDeNumeros[Cantidad];
    int numeroIngresado;
    int indiceArray;
    int valorIngresado;
    int opcionMenu = 0;


    for(indiceArray = 0; indiceArray < Cantidad; indiceArray ++)
    {
        numeroIngresado = getInt("ingrese el valor: \n");
        arrayDeNumeros[indiceArray] = numeroIngresado;
    }

    while(opcionMenu !=3)
    {
        opcionMenu  = getInt("\n 1. mostrar \n 2. modificar \3. salir\n"); //al numero ingresado me devuelve un entero y con eso entro a los case

        switch(opcionMenu)
        {
        case 1: //mostrar
            printf("\n\n INDICE - VALOR\n"); //para mostrar solo hace falta otro for
            for(indiceArray = 0; indiceArray < Cantidad; indiceArray++)
            {
                printf("  %d    -   %d\n",indiceArray,arrayDeNumeros[indiceArray]);
            }
            break;

        case 2: //para modificar tenemos que ver si el numero ingresado es mayor a cero y menor cantidad, despues al valor ingresado le asignamos el numero que ingrreso el usuario
            indiceArray = getInt("\n ingrese el indice a modificar: ");
            if(indiceArray >= 0 && indiceArray < Cantidad)
            {
                valorIngresado = getInt("ingrese el valor: \n");
                arrayDeNumeros[indiceArray] = valorIngresado;
            }
            else
            {
                printf("el indice ingresado esta fuera de rango");
            }
            break;

        case 3:

            printf("adios, tenga buen dia");

            break;

        default:
            printf("opcion ingresada no valida");
        }

    }

    return 0;
}
