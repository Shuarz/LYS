#include <stdio.h>
#include <stdlib.h>
#include <string.h> //sirve para manipular esta cadenas de caracteres

int main()
{//strlen, strcpy, strcmp/stricmp
    char cadena[20]="perro "; //esta cadena tiene 20 caracteres
    char cadena2[50]="gato";
    int estado;

    strcat(cadena2,cadena); //esto contatena carecteres

    puts(cadena2);
   /*estado=strcmp(cadena2, "armadillo"); //compara los string

    printf("%d", estado);*/


    /*strcpy(cadena,cadena2);


    cantidad =strlen(cadena); //cuenta la cantidad de caracteres ingresados */

  /*  printf("ingrese texto: ");
    fflush(stdin);
    //scanf("%s", &cadena);
    gets(cadena); //esto lee una cadena de catacteres, esta especializado para eso

    printf("%s",cadena );*/

    return 0;
}
