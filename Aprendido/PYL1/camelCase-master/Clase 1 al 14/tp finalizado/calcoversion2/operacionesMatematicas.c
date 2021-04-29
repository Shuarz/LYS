#include <stdio.h>
#include <stdlib.h>
#include "cabecera.h"

int operacionSuma(int numeroUno, int numeroDos)
{
    int suma;
    suma = numeroUno + numeroDos; //recibe dos numeros y realiza la operacion
    return suma; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso suma)
}

int operacionResta(int numeroUno, int numeroDos)
{
    int resta;
    resta = numeroUno - numeroDos; //recibe dos numeros y realiza la operacion
    return resta; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso resta)
}

int operacionMultiplicacion(int numeroUno, int numeroDos)
{
    int multiplicacion;
    multiplicacion = numeroUno * numeroDos; //recibe dos numeros y realiza la operacion
    return multiplicacion; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso multiplicacion)
}

float operacionDivision(int numeroUno, int numeroDos)
{
    float dividir;
    dividir = numeroUno / numeroDos; //recibe dos numeros y realiza la operacion
    return dividir; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso division)
}

float operacionResto(int numeroUno, int numeroDos)
{
    float resto;
    resto = numeroUno % numeroDos; //recibe dos numeros y realiza la operacion
    return resto; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso resto)
}

int operacionFactorialA (int numeroUno)
{
    int factorUno=1; //se le da un valor a la variante que esta en main.c
    int i; // se declara la variante inicialadora
    int numero=numeroUno; //a la variante numero se le asigna el valor ingresado por el usuario de numeroUno

    for(i=1; i<=numero; i++) //se setea el bucle para que haga la cuenta
        factorUno=factorUno*i;

    return factorUno; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso factorUno)
}

int operacionFactorialB (int numeroDos)
{
    int factorDos=1; //se le da un valor a la variante que esta en main.c
    int i; // se declara la variante inicialadora
    int numero=numeroDos; //a la variante numero se le asigna el valor ingresado por el usuario de numeroUno

    for(i=1; i<=numero; i++) //se setea el bucle para que haga la cuenta
        factorDos=factorDos*i;

    return factorDos; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso factorDos)
}

int numeroIngresado(void)
{
    int numero;

    printf("\n Ingrese numero: ");  //pide un valor y lo devuelve
    scanf(" %d", &numero);

    return numero; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso numero)
}

int opcionIngresada(void)
{
    int elegirOpcion;

    printf("\n Ingrese una opcion: "); //pide un valor y lo devuelve
    scanf(" %d", &elegirOpcion);

    return elegirOpcion; // devuelve un valor que se lo pasa a la variable que esta en main.c (en este caso elegirOpcion)
}
