#include <stdio.h>
#include <stdlib.h>

int calcularFactorial(int); //declarar el entero

int main()
{
    int numero=3;
    int resultado;

    resultado = calcularFactorial(numero);


    printf("el factorial es: %d", resultado);


    return 0;
}

int calcularFactorial(int numero)

{
    int resultado;

    if(numero == 0)
    {
    resultado = 1;
    }
    else
    {
        resultado = numero * calcularFactorial(numero -1); //calcula el numero anterior al numero
    }



    return resultado;
}
