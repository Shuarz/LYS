#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "cabecera.h"

int main()
{   //Se declaran las variables
    int elegirOpcion;
    int numeroUno;
    int numeroDos;
    float resto;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int factorUno;
    int factorDos;
    int bandera = 0;
    int bandera2 = 0;

    do //Se escriben las sentencias
    {   // Filtramos las opciones entre 1 0 5 para que elija el usuario, si ingresa 2,3 o 4, le da error
        printf( "\n  Bienvenido, presione 1 para comenzar o 5 para salir:   \n" );
        printf( "\n    1. Comenzar.\n");
        printf( "\n    5 Salir.\n" );
        elegirOpcion = opcionIngresada(); //llamo a la funcion que esta en la bibloteca operacionesMatematicas.c

        switch ( elegirOpcion )
        {
        case 1:  //el programa comienza y pide el primer numero, que llama la funcion que esta la biblotecaMatematicas.c
            numeroUno = numeroIngresado();
            bandera = 1;

        case 2:
            if (bandera==0) //si el usuario ingresa el numero 2, la bandera entra da el mensaje de error, ya que bandera vale 0, si vale 1 entra
            {
                printf("\n ERROR!!!, Por favor ingrese 1 para comenzar o 5 para salir \n");
                break;
            }
            else
            {
                numeroDos = numeroIngresado(); //se ingresa el segundo numero, que llama la funcion que esta desarrollada en la biblotecaMatematicas.c
                bandera2 = 1;
            }

        case 3:
            if (bandera==0 && bandera2==0) //aca tambien entra al mensaje si el usuario ingresa el numero 3, ya que bandera (y bandera2) vale 0 y no vale 1
            {
                printf("\n ERROR!!!, Por favor ingrese 1 para comenzar o 5 para salir \n");
                break;
            }
            else
            {
                printf("\n Espere... Calculando... \n"); //mensaje de adorno para que el usuario sepa que esta trabajando la calculadora

                suma=operacionSuma(numeroUno,numeroDos); //con la variable suma llamo a la funcion operacionSuma que esta desarrollada en la bibloteca operacionesMatematicas.c
                resta=operacionResta(numeroUno,numeroDos); //con la variable resta llamo a la funcion operacionResta que esta desarrollada en la bibloteca operacionesMatematicas.c
                multiplicacion=operacionMultiplicacion(numeroUno,numeroDos); //con la variable multiplicacion llamo a la funcion operacionmultipliacion desarrollada que esta en la bibloteca operacionesMatematicas.c
                division=operacionDivision(numeroUno,numeroDos); //con la variable division llamo a la funcion operacionDivision que esta desarrollada en la bibloteca operacionesMatematicas.c
                resto=operacionResto(numeroUno,numeroDos); //con la variable resto llamo a la funcion operacionResto que esta desarrollada en la bibloteca operacionesMatematicas.c
                factorUno=operacionFactorialA(numeroUno); //con la variable factorUno llamo a la funcion operacionFactorialA que esta desarrollada en la bibloteca operacionesMatematicas.c
                factorDos=operacionFactorialB(numeroDos); //con la variable factorDos llamo a la funcion operacionFactorialB que esta desarrollada en la bibloteca operacionesMatematicas.c
            }

        case 4:
            if (bandera==0 && bandera2==0) //se repite el mismo if y el mismo mensaje si el usuario ingresa el numero 4, ya que bandera (y bandera2) vale 0 y no vale 1
            {
                printf("\n ERROR!!!, Por favor ingrese 1 para comenzar o 5 para salir! \n");
                break;
            }
            else // si el usuario ingreso 1 para dar comienzo, se muestran los resultados(y los numeros ingresados), respetando el orden de los case
            {
                printf( "\n   El resultado de: %d + %d = %d\n", numeroUno, numeroDos, suma );

                printf( "\n   El resultado de: %d - %d = %d\n", numeroUno, numeroDos, resta );

                printf( "\n   El resultado de: %d * %d = %d\n", numeroUno, numeroDos, multiplicacion);

                if ( numeroDos != 0 )
                {
                    printf( "\n   El resultado: de %d div %d = %2.f ( Resto = %2.f )\n", numeroUno, numeroDos, division, resto);
                }
                else
                {
                    printf( "\n   ERROR: No se puede dividir entre cero.\n" );
                }

                if (numeroUno < 0)
                {
                printf("\n   ERROR: %d no tiene factorial porque es negativo\n",numeroUno);
                }
                else
                {
                printf("\n   El factorial de %d = %d\n", numeroUno, factorUno);
                }

                if (numeroDos < 0)
                {
                printf("\n   ERROR: %d no tiene factorial porque es negativo\n",numeroUno);
                }
                else
                {
                printf("\n   El factorial de %d = %d\n", numeroDos, factorDos);
                }
                break;
            }

        case 5:
            printf("\n Adios, tenga buen dia!!! \n"); //caso 5 para que el usuario pueda salir y el while de un cierre
            break;

        default: // mensaje para que el usuario este obligado a presionar 1 para comenzar o 5 para salir, sino sale este mensaje
            printf("\n   ERROR: numero ingresado es incorrecto, por favor ingrese el numero 1 o 5 \n");
        }

        __fpurge(stdin); //limpia el buffer y deja limpio para la siguiente accion
        printf("\n Presione ENTER para continuar"); //mensaje para que el usuario sepa que hacer despues de presionar 1 0 5
        getchar(); //frena el codigo hasta presionar una tecla
        system("clear"); //limpia toda la consola e inicia el while de nuevo

    }
    while ( elegirOpcion != 5); //si la opcion elegida es 5, se cierra el bucle y muestra los mensajes de cierre, sino vuelve a iniciar
    {
    }

    return 0;
}



