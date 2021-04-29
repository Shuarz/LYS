#include <stdio.h>
#include <stdlib.h>
#include "menues.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "abono.h"



void menuPrincipal()
{
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaAbono;
    int i;
    int bandera = 0;

    int option = 0;
    do
    {
        system("cls");
        printf("\r\tBIENVENIDO\n\n");
        printf("1. Alta desde el archivo data.csv (modo texto).\n");
        printf("2. Listar los clientes.\n");
        printf("3. Generar lista de abonos.\n");
        printf("4. Salir.\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&option);


        switch(option)
        {
        case 1:
            if(bandera==0)
            {
            controller_loadFromText("clientes.csv",listaClientes);
            printf("\nEmpleados cargados\n");
            system("pause");
            }
            bandera = 1;
            break;
        case 2:
            if(bandera==1)
            {
            controller_ListClientes(listaClientes);
            system("pause");
            }
            else
            {
                printf("error, primero dar alta\n");
            }
            system("pause");
            break;
        case 3:
            if(bandera==1)
            {
            listaAbono = listarAbonos(listaClientes);
            eAbono* abono;
            printf("ID abono|Tipo |Id Cliente|Importe\n\n");

            for(i =0; i<ll_len(listaAbono); i++)
            {
                abono = ll_get(listaAbono, i);

                printf("%-8d|%-6d|%-10d|$%-8.2f\n",abono->id, abono->tipo, abono->idCliente, abono->importeFinal);
            }
            system("pause");
            }
            else
            {
                printf("error, primero dar alta\n");
            }
            system("pause");
            break;

        case 4:
            printf("\nAdios, tenga buen dia\n\n");
            break;
        default:
            printf("\nerror, por favor ingrese un numero del 1 al 4\n\n");
            system("pause");
            break;
        }
    }
    while(option != 4);

}
