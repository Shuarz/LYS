#include <stdio.h>
#include <stdlib.h>

/*Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efectœe el producto de dichas variables
4. Muestre el resultado pos pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla*/


int main(int argc, char *argv[]) {

	int numeroUno;
	int NumeroDos;
	int producto;
	int cuadrado;

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

	do{
	printf("\nIngrese otro numero: ");
	scanf("%d",&NumeroDos);

	if(NumeroDos==0)
		{
            printf("\nIngrese numero mayor a 0\n");
        }

    }while(NumeroDos==0);

	producto=numeroUno*NumeroDos;
	cuadrado=numeroUno*numeroUno;

	printf("\nEl valor de numero uno es: %d\nEl valor de numero dos es: %d\n\nEl producto es: %d\n\nEl cuadrado del valor %d es: %d \n",numeroUno,NumeroDos,producto,numeroUno,cuadrado);




	return 0;
}
