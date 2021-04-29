#include "bibloteca2.h"
#include <stdio.h>


//desarrollo las funciones

//aca cumplo todas las funciones sumar multiplicar, etc



int pedirEntero(char texto[]) //es parametro formal es texto, no cambia
{
    int numero;

    printf("%s", texto); //para mostrar el texto de char
    scanf("%d", &numero);

    return numero;
}

int incrementarValor(int x)
{
    x++;
    return x;
}

