#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "cliente.h"


/** \brief
 *
 * \return int
 *
 */
int menuDeOpciones()
{
    int option;

    printf("-------------------MENU DE OPCIONES--------------------------\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. \n");
    printf("3. \n");
    printf("4. \n");
    printf("5. Salir\n");
    printf("Introduzca una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}


/** \brief Carga datos de cleintes desde el archivo de texto.
 *
 * \param path char* Ruta del archivo que contiene los datos
 * \param pArrayListEmployee LinkedList* Puntero a la lista en que serán agregados los datos
 * \return int "-1" si alguno de los punteros pasados es nulo o si no logra abrir el archivo; "1" si logra realizar el parseo
 *
 */
int controller_loadFromText(LinkedList* lista)
{
    int retorno = -1;
    if(lista != NULL)
    {
        char path[128];
        puts("Ingrese la ruta al archivo: ");
        fflush(stdin);
        gets(path);

        FILE* pArchivo;
        pArchivo = fopen(path, "r");

        if(pArchivo != NULL)
        {
            retorno = 1;

            char idStr[4];
            char nombre[51];
            char sexo[5];
            char numeroTelefono[21];
            char importe[6];
            eCliente* pCliente = NULL;
            int datosParseados;
            int cantidadEmpleadosIngresados = 0;

            fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, sexo, numeroTelefono, importe);

            while(!feof(pArchivo))
            {
                datosParseados = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, sexo, numeroTelefono, importe);

                if(datosParseados == 5)
                {
                    pCliente = cliente_newParametros(idStr, nombre, sexo, numeroTelefono, importe);

                    ll_add(lista, pCliente);
                    cantidadEmpleadosIngresados++;
                    printf("%d", cantidadEmpleadosIngresados);

                }
                else
                {
                    puts("\nERROR DE CARGA. SE SUSPENDIO EL PROCESO\n");
                    retorno = 0;
                    break;
                }
            }
            fclose(pArchivo);
        }
        else
        {
            puts("\nERROR. NO SE LOGRO ABRIR EL ARCHIVO\n\n");
        }
    }
    return retorno;
}


int controller_altaAbono(LinkedList* lista)
{

}


int calculaIdAbono(LinkedList* lista)
{
    eAbono* pAbono = NULL;
    int i;
    for(i = 0; i < ll_len())
    pAbono = ll_get(lista)
}
