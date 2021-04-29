#include <stdio.h>
#include <stdlib.h>
#include "biblopunest.h"

#define tam 2


//una version nueva contructor que reciba parametro



int main()
{

    eDato* p;

    //malloc(int*)(sizeof(int)*(tam));

    p = function(1, 3);

    printf("%d -- %d",p->a, p->b);

    printf("\n");

    eDato* q;

   // malloc(int*)(sizeof(int)*(tam));

    q = function(2, 4);

    printf("%d -- %d",q->a, q->b);

    return 0;
}
    //las varibales dinamicas se guardan en el "heap"

 //una funcion que me duvuelva una direccion de memoria (devuelve un puntero), que reciba un entero
   //pedirle una direccion de memoria, cargar

