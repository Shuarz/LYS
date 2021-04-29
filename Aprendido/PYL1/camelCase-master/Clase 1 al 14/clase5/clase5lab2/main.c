#include <stdio.h>
#include <stdlib.h>
#define T 10

int main()
{
    int vector[T] ={4,2,3,1,5,34,33,8,9,12}; //le asigino valores (esto es u vector por extension) (sonllaves)



    int i; //mano azul
    int j; //mano amarilla
    int auxiliar;

    for(i=0; i<T-1; i++) //la mano azul tiene que ir uno antes que la mano amarilla
    {
        for(j=i+1; j<T; j++) //for anidado  j=i+1 es poque la mano amarrila, va una iteraccion adelante
        {
            if(vector[i]<vector[j])
            {
                auxiliar=vector[i];  //vector de i le estoy axigando a auxiliar
                vector[i]=vector[j];
                vector[j]=auxiliar;
            }
        }
    }

    for(i=0;i<T;i++)
    {
        printf("%d \n", vector[i]);
    }
    return 0;
    } //fijate de poner bien las llaves

