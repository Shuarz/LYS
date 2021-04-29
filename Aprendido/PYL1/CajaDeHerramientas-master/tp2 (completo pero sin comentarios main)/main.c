#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "miBibloteca.h"
#include "menu.h"
#define length_EMPLOYEE 1000
#define length_SECTOR 5

int main()
{
    Employee employees[length_EMPLOYEE]; //Inicializo el array employees.
    Sector sectors[length_SECTOR]; //Inicializo el array sectors.

    char seguir = 's'; //Bandera continuar do-while.
    int checkArray; //Almacena retorno de checkEmptyArray().
    int index; //Indice del empleado.

    //---> Variables auxiliares para el alta
    int auxId;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    //<---Fin variables auxiliares

    initEmployees(employees, length_EMPLOYEE);//Inicializo los estados en EMPTY.
    hardcodeoEmployees(employees); //Harcodea datos de 7 empleados.
    hardcodeoSectors(sectors); //Harcodea datos de 5 sectores. Estos no se pueden modificar, dar de alta ni eliminar.

    do
    {
        checkArray = checkEmptyArray(employees, length_EMPLOYEE); //Asigno a la variable el retorno de la funcion.

        switch(menu()) //El retorno de la funcion menu() es la variable utilizada en el switch.
        {
        case 1:
            system("cls");
            printf("Submenu para ingresar un empleado\n\n");
            index = findFreePlace(employees, length_EMPLOYEE); //Busca la primer posicion libre
            if(index == -1) //Si index es -1 no hay lugares disponibles en el array de empleados y lo informa
            {
                printf("\nNo hay espacio disponible.\n");
            }
            else
            {
                auxId = getNextId(employees, length_EMPLOYEE); //Genera el siguiente id
                getValidStringRango("Ingrese nombre: ", "\nError, solo se permite el ingreso de letras.\n", auxName, 51); //Pide y valida nombre
                getValidStringRango("Ingrese apellido: ", "\nError, solo se permite el ingreso de letras.\n", auxLastName, 51); //Pide y valida apellido
                auxSalary = getValidFloat("Ingrese sueldo: ", "\nError, solo se permite el ingreso de numeros.\n"); //Pide y valida sueldo
                auxSector = selectSector(sectors, length_SECTOR); //Selecciona un sector de una lista

                addEmployee(employees, length_EMPLOYEE, auxId, auxName, auxLastName, auxSalary, auxSector, index); //Carga al nuevo empleado cambiando el estado (isEmpty) a FULL
            }
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Submenu para modificar un empleado\n\n");
            if(checkArray == -1) //Si checkArray() es -1 aun no hay empleados cargados en el sistema, lo informa y no ingresa a modifyEmployee()
            {
                printf("No hay empleados dados de alta en el sistema.\n\n");
            }
            else
            {
                auxId = getValidInt("Ingrese ID: ", "\nError, solo se admiten numeros\n"); //Pide el id del empleado a modificar
                index = findEmployeeById(employees, length_EMPLOYEE, auxId); //Busca al empleado con el id ingresado previamente
                if(index == -1){ //Si el retorno de la funcion es -1 no existe empleado con el id ingresado y lo informa
                    printf("No existen empleados con ese ID.\n\n");
                }
                else{
                    modifyEmployee(employees, sectors, length_EMPLOYEE, length_SECTOR, auxId, index); //Modifica el nombre, apellido, sueldo o sector
                }
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("Submenu para eliminar empleado\n\n");
            if(checkArray == -1) //Si checkArray() es -1 aun no hay empleados cargados en el sistema, lo informa y no ingresa a  removeEmployee()
            {
                printf("No hay empleados dados de alta en el sistema.\n\n");
            }
            else
            {
                auxId = getValidInt("Ingrese ID: ", "\nError, solo se admiten numeros\n"); //Pide el id del empleado a modificar
                index = findEmployeeById(employees, length_EMPLOYEE, auxId); //Busca al empleado con el id ingresado previamente
                if(index == -1) //Si el retorno de la funcion es -1 no existe empleado con el id ingresado y lo informa
                {
                    printf("No se encuentra empleado con ese ID.\n\n");
                }
                else
                {
                    removeEmployee(employees, sectors, length_EMPLOYEE, length_SECTOR, index); //Elimina al empleado
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            printf("Submenu de listados, elija 1 o 2 para proseguir\n\n");
            if(checkArray == -1) //Si checkArray() es -1 aun no hay empleados cargados en el sistema, lo informa y no ingresa a listEmployees()
            {
                printf("No hay empleados dados de alta en el sistema.\n\n");
            }
            else
            {
                listEmployees(employees, sectors, length_EMPLOYEE, length_SECTOR); //Menu de opciones - (1) Lista ordenada o desordenada por apellido y sector, (2) Total de salarios, promedio y cantidad de empleados que superan el promedio
            }
            system("pause");
            break;
        case 5:
            seguir = 'n'; //Cambia el flag "seguir" a 'n' y termina el ciclo do-while
            system("cls");
            printf("Usted a salido del programa correctamente, adios.\n");
            break;
        default:
            printf("Opcion incorrecta, ingrese un numero del 1 al 5 por favor.\n\n"); //En caso de ingresar una opcion incorrecta lo informa
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');

    return 0;
}
