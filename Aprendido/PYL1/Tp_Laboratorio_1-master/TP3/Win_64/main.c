#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "miBibloteca.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("Cargando...\n");
        menu();
        utn_getNumero(&option, " \n ","Ingrese un numero valido\n",1,10,1);
        system("cls");
        switch(option)
        {
        case 1:
            printf("\nSize de la lista: %d \n",ll_len(listaEmpleados));
            if(!controller_loadFromText("data.csv",listaEmpleados))
            {
                flag = 1;
                printf("\nDatos cargados correctamente\n");
               // pause();
            }
            printf("\nSize de la lista: %d \n",ll_len(listaEmpleados));
            break;
        // pause();

        case 2:
            printf("\nSize Linked List %d\n",ll_len(listaEmpleados));
            if(!controller_loadFromBinary("data.bin",listaEmpleados)) //hacer un break despues del feof
            {
                printf("\nDatos cargados\n");
                pause();
            }
            printf("\nSize Linked List %d",ll_len(listaEmpleados));
            break;

        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                printf("\nEmpleado agregado correctamente!\n");
            }
            else
            {
                printf("\nNo se pudo agregar el empleado\n");
            }
            break;


        case 4:

            if(!controller_editEmployee(listaEmpleados))
            {
                printf("\nEmpleado modificado correctamente!\n");
            }
            else
            {
                printf("\nNo se pudo modificar el empleado\n");
            }
            break;


        case 5:
            if(!controller_removeEmployee(listaEmpleados))
            {
                printf("\nEl empleado se borro correctamente\n");
            }
            else
            {
                printf("\nEl empleado no se borro correctamente\n");
            }
            break;
           // pause();

        case 6:
            controller_ListEmployee(listaEmpleados);
            printf("Listando, por favor espere...\n");
            break;
            //pause();

        case 7:
            printf("Ordenando por criterio, por favor espere...\n");
            if(!controller_sortEmployee(listaEmpleados))
            {
                printf("\nSe ordeno correctamente");
            }
            else
            {
                printf("\nNo se pudo ordenar");
            }
            break;


        case 8:
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("\nArchivo guardado.");
            }
            else
            {
                printf("\nNo hay datos cargados");
            }
            break;


        case 9:
            if(!controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("\nArchivo guardado.");
            }
            else
            {
                printf("\nNo se pudo guardar el archivo.");
            }
            break;



        }
        pause();
        limpiarPantalla();

    }
    while(option != 10);

    printf("Adios, que tenga buen dia");

    return 0;
}
