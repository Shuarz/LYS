#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"



int main()
{
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaAbonos = ll_newLinkedList();

    int opcion;

    do
    {
       opcion = menuDeOpciones();

        switch(opcion)
        {
        case 1:
            controller_loadFromText(listaClientes);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            ll_deleteLinkedList(listaClientes);
            puts("\nGRACIAS POR UTILIZAR LA APLICACION\n");
            break;

        default:
            puts("\nNO INGRESO UNA OPCION VALIDA\n");

        }
        system("pause");
        system("cls");
    }
    while(opcion != 5);

    return 0;
}
