#include <stdio.h>
#include <stdlib.h>

/*
        Limpie la pantalla
        Solicite dos valores numéricos al usuario distintos de cero
        Asigne a las variables numero1 y numero2 los valores obtenidos
        Realice la resta de dichas variables
        Muestre el resultado por pantalla
        Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor
        Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero
 */


int main(int argc, char *argv[])
{

    int numeroUno;
    int NumeroDos;
    int resultado;

    system("pause");

    do
    {
        printf("\nIngrese un numero: ");
        scanf("%d",&numeroUno);

        if(numeroUno==0)
        {
            printf("\nIngrese numero mayor a 0\n");
        }

    }
    while(numeroUno==0);

    do
    {
        printf("\nIngrese otro numero: ");
        scanf("%d",&NumeroDos);

        if(NumeroDos==0)
        {
            printf("\nIngrese numero mayor a 0\n");
        }

    }
    while(NumeroDos==0);

    resultado=numeroUno-NumeroDos;

    printf("\nEl resultado es: %d \n",resultado);

    if(resultado>0)
    {
        printf("\nResultado positivo \n");
    }
    if(resultado<0)
    {
        printf("\nResultado negativo \n");
    }



    return 0;
}
