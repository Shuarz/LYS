#include <stdio.h>
#include <stdlib.h>

/*Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el área de un círculo
cuyo radio es ingresado por el usuario.
Documentar las funciones al estilo Doxygen. */

float pedirNumero(); //no se lo que me da, pero se que me devuelve un flotante

float calcularAreaDelCirculo(float radio); //se que da un flotante y me devuelve un flotante

int main()
{
    float auxiliarFloat;
    float area;

    auxiliarFloat = pedirNumero(); //al prototipo "pedir" le asigno el valor de "auxiliar"
    area = calcularAreaDelCirculo(auxiliarFloat); //y al area le asigno el propotipo "calcular" y a ese el segundo flotante que esta en main (auxiliar de float que contiene el dato)

    printf("el area del circulo es: %.2f\n", area);

    return 0;
}


float pedirNumero()
{
   float auxiliar; //tengo que declarar un tipo de variante dentro de la funcion para que funcione
   printf("ingrese numero:");
   scanf("%f", &auxiliar);

   return auxiliar; //devuelve el numero que ingreso el usuario
}

float calcularAreaDelCirculo(float radio)
{
    float resultado; //ingreso una variante para saber el resultado
    resultado = 3.14 * radio * radio; //radio esquivale al numero que ingresa el usuario

    return resultado; //devuel el resultado
}
