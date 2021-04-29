#include <stdio.h>
#include <stdlib.h>

#define tam 5

int main()
{
    int* pEntero;
    int i;

    /*esto apunta al heap y esta bien hecho*/
    pEntero = (int*)/*castear a entero*/malloc(sizeof(int)*5); //sizeof me dice la cantiadad de bytes que tiene el entero
                                        /*esto es crear un array (5)*/


    pEntero  = realloc(pEntero, sizeof(int)*(tam+10));

    if(pEntero != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            malloc(sizeof(int)*5);
            printf("\n ingrese un numero:");
            scanf("%d", pEntero+i);
        }

        for(i = 0; i < tam+5; i++)
        {

            printf("%d\nl", *(pEntero+i));
        }

    pEntero  = realloc(pEntero, sizeof(int)*5);

        for(i = 0; i < tam+10; i++)
        {

            printf("%d\nl", *(pEntero+i));
        }

    /**pEntero = 9;

    printf("%d", *pEntero);  */

    }

    return 0;
}

//esto seria para una estructura

/*    for(i=0;i<5;i++)
    {
        *(pListadoEdad+i)=i*11;
    }
      for(i=0;i<10;i++)
    {
         printf("\nla edad ingresada es : %d \n",*(pListadoEdad+i));
    }
*/


/*
pedir 5, mostrar otros 5 tarea hecha en la estructura

el ejerccio de inicia de clases pero con malloc*/
