#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int;
    char;

}eBinario;

int main()
{
    FILE* pArchivo;

    eBinario binario= {1, 'c'};

    pArchivo = fopen("archivo.bin", "wb"); //especificamos que crea un archivo bin (binario)

    fwrite(&binario, sizeof(eBinario), 1, pArchivo);
            /**dato, ,tamaño ,cantidad ,archivo*/ //datos a guardar en el fwrite

    fclose(pArchivo);

    printf("archivo generado");

   // printf("%d", x); */


   /** lectura de bainario en una estructura  */

    FILE* pArchivo;

    eBinario = d

    pArchivo = fopen("archivo.bin", "rb");

    fwrite(&binario, sizeof(eBinario), 1, pArchivo);

    fclose(pArchivo);

    printf("%d - %c", d.a, d.b);

    return 0;
}


/** escribir una estructura int y char que lo escriba y lea */


