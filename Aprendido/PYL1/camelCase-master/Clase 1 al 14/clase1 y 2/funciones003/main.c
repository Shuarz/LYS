#include <stdio.h>
#include <stdlib.h>

void sumar1 (void);
void sumar2(int, int);


int main()
{
    int numeroUno;
    int numeroDos;

    printf("ingrese el numero: \n");
    scanf("%d",&numeroUno);

    printf("ingrese el numero: ");
    scanf("%d",&numeroDos);

    sumar2(numeroUno, numeroDos);  //a sumar dos le estoy haciendo llamar a numeroUno y numeroDos

    return 0;
}

void sumar2(int numero1, int numero2) //porque aca no estan para que pueda ejecutarse en pantalla
{
    int suma;

    suma=numero1+numero2;

    printf("la suma de los dos numeros fue: %d",suma);

}
