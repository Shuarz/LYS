#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

FILE* pArchivo;

    int x = 4;

    pArchivo = fopen("archivo.bin", "wb"); //especificamos que crea un archivo bin (binario)

    fwrite(&x, sizeof(int), 1, pArchivo);
            /**dato, ,tamaño ,cantidad ,archivo*/ //datos a guardar en el fwrite

    fclose(pArchivo);

    printf("archivo generado");

    printf("%d", x); */


    /** lectura de un binario */


    FILE* pArchivo;

    eBinario = d

    pArchivo = fopen("archivo.bin", "rb");

    fwrite(&binario, sizeof(eBinario), 1, pArchivo);

    fclose(pArchivo);

    printf("%d - %c", d.a, d.b);*/
