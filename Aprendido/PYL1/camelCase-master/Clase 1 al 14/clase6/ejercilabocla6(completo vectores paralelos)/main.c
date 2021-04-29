#include <stdio.h>
#include <stdlib.h>

void inicializarArray(int[], int, int); //prototipo de la funcion arrays, dentro de el se declarar el tipo de dato int[]
void mostrarArray(int[], int);
void inicializaYMuestra(int[], int, int);

int main()
{
    int cantidad;
    cantidad =5;
    int vector [cantidad]; //se declara el vector y dentro de la cantidad
    int valorDeCarga;
    valorDeCarga = 7;
    inicializaYMuestra(vector, cantidad, valorDeCarga);
    return 0;
}

void inicializarArray(int vector[], int cantidad, int valorDeCarga) //desarrollo de la funcion, declaro los array y la funcion tambien sera void
{
  cantidad--;
  for(;cantidad >=0; cantidad--)
  {
      vector[cantidad] = valorDeCarga; //por cada interaccion se le da un valor
  }
}

void mostrarArray(int vector[], int cantidad)
{
    cantidad--;
    for(;cantidad >=0; cantidad--)
    {
        printf("%d \n", vector[cantidad]);
    }
}

void inicializaYMuestra(int vector[], int cantidad, int valorDeCarga)
{
    inicializarArray(vector, cantidad, valorDeCarga);
    mostrarArray(vector, cantidad);
}
