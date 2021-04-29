#include <stdio.h>
#include <stdlib.h>

void mostrar(int);
void otroMostrar(int);
int incrementar(int);

void manejador(void (*pfuncion)(int), int);
void hacerAlgo(int);

int main()
{
    /* void(*pFuncion)(int); //puntero a funcion con el operador de inaceso y el paramatro que recibe

    int(*otroPFuncion)(int); */

    manejador(mostrar, 75);

   /* pFuncion = mostrar;
    pFuncion(45); //sino le paso un valor rompe

    pFuncion = otroMostrar; //separar punteros para poder mostrar distintos resultados
    pFuncion(95); */

   // int x=0;

    /* otroPFuncion = incrementar; //un puntero llamado al contador

    x = otroPFuncion(x); //esto asi no funciona

    printf("el valor es: %d", x); */

    return 0;
}

void manejador(void (*pfuncion)(int), int valor)
{
    printf("estoy en el manejador");
    pfuncion(valor);

}


void mostrar(int x)
{
    printf("hola mundo %d \n",x);
}

void otroMostrar(int r)
{
    printf("hola mundo %d",r);
}

int incrementar(int i)
{
    i++;
    return i;
}

void hacerAlgo(int t)
{
    printf("hola \n");
    t+52;
    printf("chau");

    FILE* miArchivo = fopen("prueba.txt", "w");
    fprintf(miArchivo, "prueba");
    fclose(miArchivo);
}
