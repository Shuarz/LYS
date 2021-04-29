#include <stdio.h>
#include <stdlib.h>
#include "biblorepaso.h"

int main()
{
    int* punteroA;
    int* punteroB;
    int auxiliarC, auxiliarD;

    punteroA = &auxiliarC; // Obtenemos la posición de memoria de 'auxiliarC'
    punteroB = &auxiliarD; // Obtenemos la posición de memoria de 'auxiliarD'

    if (punteroA<punteroB)
    {
        printf("\nEl punteroA apunta a una direccion mas baja que punteroB\n");
    }

    else if (punteroA>punteroB)
    {
        printf("\nEl punteroB apunta a una direccion mas baja que punteroA\n");
    }



    return 0;
}
