#include <stdio.h>
#include <stdlib.h>
#include "headerTxt.h"

/*typedef struct
{
    int arrayDeNumeros[10]={1,2,3,4,5,6,7,8,9,10};

}eDato;*/



int main()
{
    int arrayDeNumeros[10]={1,2,3,4,5,6,7,8,9,10};
    int i;
    int x;

    int llamarCargaDeArray = guardarArrayEnTxt(array, tam, nombre);

    //eDato dato;

    while(!feof(pArchivo))
    {
        fgets(arrayDeNumeros, 10, pArchivo);
        i++;
    }

    for(i=0; i<11; i++)
    {
    fwrite(&x, sizeof(x), 1, pArchivo);
    }

    fclose(pArchivo);


    return 0;
}


/** while(!feof(pArchivo))
    {
        fgets(texto[i], 50, pArchivo);
        i++;
    }

    for(i=0; i<3; i++)
    {
        puts(texto[i]);
    }

    fclose(pArchivo);/
