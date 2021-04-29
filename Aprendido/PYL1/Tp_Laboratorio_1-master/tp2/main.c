#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "miBibloteca.h"
#include "menu.h"
#define length_EMPLOYEE 1000
#define length_SECTOR 5

int main()
{
    Employee employees[length_EMPLOYEE];
    Sector sectors[length_SECTOR];

    char seguir = 's';
    int checkArray;
    int index;
    int auxId;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;

    initEmployees(employees, length_EMPLOYEE);
    hardcodeoEmployees(employees);
    hardcodeoSectors(sectors);

    do
    {
        checkArray = checkEmptyArray(employees, length_EMPLOYEE);

        switch(menu())
        {
        case 1:
            system("cls");
            printf("Submenu para ingresar un empleado\n\n");
            index = findFreePlace(employees, length_EMPLOYEE);
            if(index == -1)
            {
                printf("\nNo hay espacio disponible.\n");
            }
            else
            {
                auxId = getNextId(employees, length_EMPLOYEE);
                getValidStringRango("Ingrese nombre: ", "\nError, solo se permite el ingreso de letras.\n", auxName, 51);
                getValidStringRango("Ingrese apellido: ", "\nError, solo se permite el ingreso de letras.\n", auxLastName, 51);
                auxSalary = getValidFloat("Ingrese sueldo: ", "\nError, solo se permite el ingreso de numeros.\n");
                auxSector = selectSector(sectors, length_SECTOR);

                addEmployee(employees, length_EMPLOYEE, auxId, auxName, auxLastName, auxSalary, auxSector, index);
            }
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Submenu para modificar un empleado\n\n");
            if(checkArray == -1)
            {
                printf("No hay empleados dados de alta en el sistema.\n\n");
            }
            else
            {
                auxId = getValidInt("Ingrese ID: ", "\nError, solo se admiten numeros\n");
                index = findEmployeeById(employees, length_EMPLOYEE, auxId);
                if(index == -1)
                {
                    printf("No existen empleados con ese ID.\n\n");
                }
                else
                {
                    modifyEmployee(employees, sectors, length_EMPLOYEE, length_SECTOR, auxId, index);
                }
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("Submenu para eliminar empleado\n\n");
            if(checkArray == -1)
            {
                printf("No hay empleados dados de alta en el sistema.\n\n");
            }
            else
            {
                auxId = getValidInt("Ingrese ID: ", "\nError, solo se admiten numeros\n");
                index = findEmployeeById(employees, length_EMPLOYEE, auxId);
                if(index == -1)
                {
                    printf("No se encuentra empleado con ese ID.\n\n");
                }
                else
                {
                    removeEmployee(employees, sectors, length_EMPLOYEE, length_SECTOR, index);
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            printf("Submenu de listados, elija 1 o 2 para proseguir\n\n");
            if(checkArray == -1)
            {
                printf("No hay empleados dados de alta en el sistema.\n\n");
            }
            else
            {
                listEmployees(employees, sectors, length_EMPLOYEE, length_SECTOR);
            }
            system("pause");
            break;
        case 5:
            seguir = 'n';
            system("cls");
            printf("Usted a salido del programa correctamente, adios.\n");
            break;
        default:
            printf("Opcion incorrecta, ingrese un numero del 1 al 5 por favor.\n\n");
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');

    return 0;
}
