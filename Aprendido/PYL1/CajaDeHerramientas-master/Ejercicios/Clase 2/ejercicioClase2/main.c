#include <stdio.h>
#include <stdlib.h>

/* realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo. */

int main()
{
    int i;
    float numeroUno;
    float acumulador=0;
    float numeroMaximo;
    float numeroMinimo;

     printf("\ningrese un numero:"); //tengo que hacer afuera el primer ingreso, asi defino el numero maximo y minimo con el primer numero
     scanf("%f",&numeroUno);
     numeroMaximo = numeroUno;
     numeroMinimo = numeroUno;
     acumulador = numeroUno;

    for(i=0;i<4;i++)
    {
     printf("\ningrese un numero:");
     scanf("%f",&numeroUno);

     acumulador = acumulador + numeroUno;

     if(numeroUno<numeroMinimo)
     {
         numeroMinimo=numeroUno;
     }

     if(numeroUno>numeroMaximo)
     {
         numeroMaximo=numeroUno;
     }
    }

    printf("\n el promedio fue: %f\n",acumulador/5);
    printf("\n el numero maximo fue: %f\n",numeroMaximo);
    printf("\n el numero minimo fue: %f\n",numeroMinimo);

    return 0;
}
