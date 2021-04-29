#include <stdio.h>
#include <stdlib.h>
#include "biblioEstructura.h"


sDato* funcion(int x,char y)
{
    sDato dato;//creo un dato tipo sDato
    sDato* pDato;//creo un puntero a un elemento a sDato
    pDato=&dato;//Le asigno apdato el lugar de memoria de datto
    pDato->a=x;//se guarda el valor que apunta al campo "a" de la esructura en x
    pDato->b=y;////se guarda el valor que apunta al campo "b" de la esructura en y

    return pDato;//Devuelve el valor del puntero
}
