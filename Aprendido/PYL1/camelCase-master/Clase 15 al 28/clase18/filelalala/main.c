#include <stdio.h>
#include <stdlib.h>

int main()
{
    /** funcion de crear un archivo */

   // char cadena[50] = "german";

   /* FILE* pArchivo;

    pArchivo = fopen("saludo.txt", "w"); //me da el dierrecion fisica del arhivo y el  segundo parametro es el mode

    fprintf(pArchivo, "hola \n que \n hace");

    //fprintf(pArchivo, "hola %s, como estas? \n todo bien", cadena); //escribe en dentro de un archivo //con el porcentual llego al valor de char

    fclose(pArchivo);

    printf("archivo generado"); */


   /** funcion de leer un archivo*/

    FILE * pArchivo;

    char /** esto era un puntero a char*/ texto[3][50]; //otro[50];
    int i = 0;

    pArchivo = fopen("saludo.txt", "r");

    //fgets(texto,50,pArchivo); //donde guarda la data, con que entencion y despues el archivo
   // fgets(otro,50,pArchivo);

    while(!feof(pArchivo))
    {
        fgets(texto[i], 50, pArchivo);
        i++;
    }

    for(i=0; i<3; i++)
    {
        puts(texto[i]);
    }

    fclose(pArchivo);

   // puts(texto);
   // puts(otro);

    return 0;
}

