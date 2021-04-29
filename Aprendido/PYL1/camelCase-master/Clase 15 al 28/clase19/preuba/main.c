#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int arrayDeNumeros[10]={1,2,3,4,5,6,7,8,9,10};
    int i;

    FILE* pArchivo;
    pArchivo = fopen("saludo.txt", "w");

    for(i=0; i<1; i++)
    {
    fprintf(pArchivo, "1,2,3,4,5,6,7,8,9,10");
    }

    fclose(pArchivo);

    //fprintf(pArchivo, "Hola\nque\nhace");
    return 0;
}
