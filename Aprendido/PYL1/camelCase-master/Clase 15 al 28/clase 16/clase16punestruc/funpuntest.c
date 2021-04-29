#include <stdio.h>
#include <stdlib.h>
#include "biblopunest.h"

eDato* function (int x, int y)
{
    eDato* pdato;

    eDato datito;

    pdato = &datito;

    pdato->a = x; //con esto le asigno el valor que tiene x al puntero del a

    pdato->b = y;

 /*  int i;

   for(i=0; i < tam; i ++)
   {
         printf("%d", (pdato+i)->a); //el +i tiene que estar, sino no itera
       //printf("%d", (*(pdato+i)).a); esto es la version larga del operador flecha
   }

   printf("\n");


    for(i=0; i < tam; i ++)
   {
       printf("%c", (pdato+i)->b);
   }*/

   return pdato;
}

