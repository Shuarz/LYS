#include <stdio.h>
#include <stdlib.h>
#define T 7 //la diferecia que tiene con la constate es que esto no carga la memoria, la constante si

//veccor secuencial

int main()

{
    //int const Q = 10; //esto una varaibles constates Q lo puedo usar para remplazar el numero de vectores
    int vector[T] =(1,2,3,4,5,6,7); //le asigino valores (esto es u vector por extension)
    int i;

    /*for(i=0;i<T;i++) //menor a 5 es el limite superior del vector
    {
        printf("ingrese un numero: ");
        scanf("%d", &vector[i]);
        /*cuando lo lea, va a guardar un valor em la vector[1],
        en la siguiente interaccion, suma uno mas (vector[2]) y le asigna otra valor*/
    }
*/
    /* para mostrar los resultados, hacemos otro for*/

    for(i=0;i<T;i++)
    {
        printf("%d \n", vector[i]);
        /*sin el apreson(&) te da los numeros asiganados, sino te da la
        direccion en memoria*/
    }

    printf("TODOS LOS NUMEROS PARES: ");
    for(i=0;i<T;i++)
    {
        if(vector[i]%2==0)
        {
            printf("%d \n", vector[i]); /* esto muestra los impares y con el vector mas el indice (vector[i])
                                           muestro cuales tiene un valor par, ejemplo vector[2] tiene el valor de
                                           4 y lo muestra */
        }
    }

    return 0;
}
