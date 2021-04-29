#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "miBibloteca.h"
#include "menu.h"
#define FULL 0
#define EMPTY 1
#define DELETED 2

void hardcodeoEmployees(Employee* arrayEmployees)
{

    arrayEmployees[0].id = 1;
    arrayEmployees[0].isEmpty = FULL;
    strcpy(arrayEmployees[0].lastName, "Martinez");
    strcpy(arrayEmployees[0].name, "Mariano");
    arrayEmployees[0].salary = 123.45;
    arrayEmployees[0].idSector = 3;

    arrayEmployees[1].id = 2;
    arrayEmployees[1].isEmpty = FULL;
    strcpy(arrayEmployees[1].lastName, "Fernandez");
    strcpy(arrayEmployees[1].name, "Juan Luis");
    arrayEmployees[1].salary = 300.2;
    arrayEmployees[1].idSector = 2;

    arrayEmployees[2].id = 3;
    arrayEmployees[2].isEmpty = FULL;
    strcpy(arrayEmployees[2].lastName, "Alvarez");
    strcpy(arrayEmployees[2].name, "Gabriel");
    arrayEmployees[2].salary = 100.15;
    arrayEmployees[2].idSector = 2;

    arrayEmployees[3].id = 4;
    arrayEmployees[3].isEmpty = FULL;
    strcpy(arrayEmployees[3].lastName, "Fernandez");
    strcpy(arrayEmployees[3].name, "Ramon");
    arrayEmployees[3].salary = 235.15;
    arrayEmployees[3].idSector = 2;

    arrayEmployees[4].id = 5;
    arrayEmployees[4].isEmpty = FULL;
    strcpy(arrayEmployees[4].lastName, "Sulivan");
    strcpy(arrayEmployees[4].name, "Gerardo");
    arrayEmployees[4].salary = 1224.15;
    arrayEmployees[4].idSector = 4;

    arrayEmployees[5].id = 6;
    arrayEmployees[5].isEmpty = FULL;
    strcpy(arrayEmployees[5].lastName, "Di maria");
    strcpy(arrayEmployees[5].name, "Carla");
    arrayEmployees[5].salary = 745.15;
    arrayEmployees[5].idSector = 1;

    arrayEmployees[6].id = 7;
    arrayEmployees[6].isEmpty = FULL;
    strcpy(arrayEmployees[6].lastName, "Muller");
    strcpy(arrayEmployees[6].name, "Marta");
    arrayEmployees[6].salary = 793.15;
    arrayEmployees[6].idSector = 5;
}

void hardcodeoSectors(Sector* arraySectors)
{
    arraySectors[0].id = 1;
    strcpy(arraySectors[0].description, "RRHH");

    arraySectors[1].id = 2;
    strcpy(arraySectors[1].description, "Compras");

    arraySectors[2].id = 3;
    strcpy(arraySectors[2].description, "Ventas");

    arraySectors[3].id = 4;
    strcpy(arraySectors[3].description, "Sistemas");

    arraySectors[4].id = 5;
    strcpy(arraySectors[4].description, "Almacen");
}

int checkEmptyArray(Employee* arrayEmployees, int lengthArray)
{
    int flag = -1;
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmployees[i].isEmpty == FULL)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int initEmployees(Employee* arrayEmployees, int lengthArray)
{
    int flag = -1;
    if(arrayEmployees != NULL && lengthArray > 0)
    {
        flag = 0;
        for(int i=0; i<lengthArray; i++)
        {
            arrayEmployees[i].isEmpty = EMPTY;
        }
    }
    return flag;
}

int getNextId(Employee* arrayEmployees,int lengthArray)
{
    int flag = 0;
    if(arrayEmployees != NULL && lengthArray > 0)
    {
        for(int i=0; i<lengthArray; i++)
        {
            if(arrayEmployees[i].isEmpty == FULL || arrayEmployees[i].isEmpty == DELETED)
            {
                flag++;
            }
        }
    }
    return flag+1;
}

int findFreePlace(Employee* arrayEmployees, int lengthArray)
{
    int flag = -1;
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmployees[i].isEmpty == EMPTY || arrayEmployees[i].isEmpty == DELETED)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

int selectSector(Sector* sectors,int lengthSector)
{
    int idSector= -1;
    printf("\nSeleccion de sector.\n");
    printf("\n ID | DESCRIPCION \n\n");
    for(int i=0; i<lengthSector; i++)
    {
        printf(" %d -> %s\n",sectors[i].id, sectors[i].description);
    }
    idSector = getValidIntRango("\nIngrese sector: ", "\nError, solo se permite el ingreso de numeros.\n", 1, 5);
    return idSector;
}

int addEmployee(Employee* arrayEmployees, int lengthArray, int auxId, char auxName[], char auxLastName[], float auxSalary, int auxSector, int index)
{
    int flag = -1;
    if(arrayEmployees != NULL && lengthArray!=0)
    {
        flag = 0;

        arrayEmployees[index].id = auxId;
        strcpy(arrayEmployees[index].name, auxName);
        strcpy(arrayEmployees[index].lastName, auxLastName);
        arrayEmployees[index].idSector = auxSector;
        arrayEmployees[index].salary = auxSalary;
        arrayEmployees[index].isEmpty = FULL;

        printf("\nSe ha agregado al usuario con exito\n\n");
    }
    return flag;
}

int findEmployeeById(Employee* arrayEmployees, int lengthArray,int id)
{
    int flag = -1;
    if(arrayEmployees != NULL && lengthArray!=0)
    {
        for(int i =0; i<lengthArray; i++)
        {
            if(arrayEmployees[i].id == id && arrayEmployees[i].isEmpty == FULL)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}

void printEmployeeById(Employee* arrayEmployees, int lengthArray, Sector* arraySectors, int lengthSectors, int auxId)
{
    char description[10];
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmployees[i].id == auxId && arrayEmployees[i].isEmpty == FULL)
        {
            uploadDescription(arraySectors, lengthSectors, arrayEmployees[i].idSector, description);
            printf("\t %5d  |%11s |%11s |%11.2f |%11s  |\n", arrayEmployees[i].id, arrayEmployees[i].name, arrayEmployees[i].lastName, arrayEmployees[i].salary, description);
        }
    }
}

void printEmployee(Employee* arrayEmployees, Sector* arraySectors, int lengthSectors, int index)
{
    char description[10];
    uploadDescription(arraySectors, lengthSectors, arrayEmployees[index].idSector, description);
    printf("\t %5d  |%11s |%11s |%11.2f |%11s  |\n", arrayEmployees[index].id, arrayEmployees[index].name, arrayEmployees[index].lastName, arrayEmployees[index].salary, description);
}

void printEmployees(Employee* arrayEmployees, int lengthArray, Sector* arraySectors, int lengthSectors)
{
    printf("\n\t   | ID -     Nombre -   Apellido -    Salario -      Sector |\n\n");
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmployees[i].isEmpty == FULL)
        {
            printEmployee(arrayEmployees, arraySectors, lengthSectors, i);
        }
    }
    printf("\n");
}

void uploadDescription(Sector* sectors, int lengthSector, int idSector, char cadena[])
{
    for(int i=0; i < lengthSector; i++)
    {
        if(sectors[i].id == idSector)
        {
            strcpy(cadena, sectors[i].description);
            break;
        }
    }
}

int modifyEmployee(Employee* arrayEmployees, Sector arraySectors[], int lengthArray, int lengthSectors, int id, int index)
{
    int flag = -1;
    int opcion;
    char confirmacion;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    char newDescription[21]; //Almacena la descripcion actual del sector al que pertenece el empleado
    char oldDescription[21]; //Almacena la nueva descripcion a la cual pertenecera el empleado
    if(arrayEmployees != NULL && lengthArray > 0)
    {
        printf("\nDatos del empleado a modificar.\n\n");
        printf("\t    ID  -    Nombre  -   Apellido -    Salario -    Sector   |\n\n");
        printEmployeeById(arrayEmployees, lengthArray, arraySectors, lengthSectors, id);
        printf("\nModificar...\n\n 1- Nombre\n 2- Apellido\n 3- Sueldo\n 4- Sector\n 5- Salir\n\n");
        opcion = getValidInt("Ingrese la opcion que desee modificar, si se equivoco, presione 5: ", "Error, solo se admiten numeros. Reintente.\n");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\nUsted esta modificando el nombre del empleado\n\n");
            getValidStringRango("Ingrese nuevo nombre: ", "Error, solo se admiten letras.\n", auxName, 51);
            printf("\nEsta seguro de querer modificar  \"%s\" por \"%s\"? (s/n): \n", auxName, arrayEmployees[index].name);
            fflush(stdin);
            confirmacion = getchar();
            confirmacion = tolower(confirmacion);
            while(confirmacion !='n' && confirmacion != 's')
            {
                printf("Error, ingreso una opcion no valida. Reintente por favor\n\n");
                getValidStringRango("Ingrese el nuevo nombre: ", "Error, solo se admiten letras.\n", auxName, 51);
                printf("\nEsta seguro de querer modificar  \"%s\" por \"%s\"? (s/n): \n", auxName, arrayEmployees[index].name);
                confirmacion = getche();
                confirmacion = tolower(confirmacion);
            }
            if(confirmacion == 'n')
            {
                printf("Se ha cancelado la modificacion del nombre.\n\n");
            }
            else
            {
                strcpy(arrayEmployees[index].name, auxName);
                printf("Se ha modificado el nombre con exito.\n\n");
            }
            break;
        case 2:
            printf("\nUsted esta modificando el apellido -->\n\n");
            getValidStringRango("Ingrese nuevo apellido: ", "Error, solo se admiten letras.\n", auxLastName, 51);
            printf("\nEsta seguro de querer modificar \"%s\" por \"%s\"? (s/n): \n", auxLastName, arrayEmployees[index].lastName);
            fflush(stdin);
            confirmacion = getchar();
            confirmacion = tolower(confirmacion);
            while(confirmacion !='n' && confirmacion != 's')
            {
                printf("Error, ingreso una opcion no valida. Reintente\n\n");
                getValidStringRango("Ingrese el nuevo apellido: ", "Error, solo se admiten letras.\n", auxName, 51);
                printf("\nEsta seguro de querer modificar  \"%s\" por \"%s\"? (s/n): \n", auxLastName, arrayEmployees[index].lastName);
                confirmacion = getche();
                confirmacion = tolower(confirmacion);
            }
            if(confirmacion == 'n')
            {
                printf("Se ha cancelado la modificacion del apellido.\n\n");
            }
            else
            {
                strcpy(arrayEmployees[index].lastName, auxLastName);
                printf("Se ha modificado el apellido con exito.\n\n");
            }
            break;
        case 3:
            printf("\nUsted esta modificando el sueldo\n\n");
            auxSalary = getValidFloat("Ingrese el nuevo sueldo: ", "Error, solo se admiten numeros.\n");
            printf("\nEsta seguro de querer modificar %.2f por %.2f? (s/n): \n", auxSalary, arrayEmployees[index].salary);
            fflush(stdin);
            confirmacion = getchar();
            confirmacion = tolower(confirmacion);
            while(confirmacion !='n' && confirmacion != 's')
            {
                printf("Error, ingreso una opcion no valida. Reintente por favor\n\n");
                getValidStringRango("Ingrese el nuevo sueldo: ", "Error, solo se admiten numeros.\n", auxName, 51);
                printf("\nEsta seguro de querer modificar %.2f por %.2f? (s/n): \n", auxSalary, arrayEmployees[index].salary);
                confirmacion = getche();
                confirmacion = tolower(confirmacion);
            }
            if(confirmacion == 'n')
            {
                printf("Se ha cancelado la modificacion del sueldo.\n\n");
            }
            else
            {
                arrayEmployees[index].salary = auxSalary;
                printf("Se ha modificado el sueldo con exito.\n\n");
            }
            break;
        case 4:
            printf("\nUsted esta modificando el sector del empleado\n");
            auxSector = selectSector(arraySectors, lengthSectors);
            uploadDescription(arraySectors, lengthSectors, arrayEmployees[index].idSector, oldDescription); //Actual descripcion
            uploadDescription(arraySectors, lengthSectors, auxSector, newDescription); //Nueva descripcion
            printf("\nEsta seguro de querer modificar %s por %s? (s/n): \n", oldDescription, newDescription);
            fflush(stdin);
            confirmacion = getchar();
            confirmacion = tolower(confirmacion);
            while(confirmacion !='n' && confirmacion != 's')
            {
                printf("Error, ingreso una opcion no valida. Reintente por favor\n\n");
                auxSector = selectSector(arraySectors, lengthSectors);
                uploadDescription(arraySectors, lengthSectors, arrayEmployees[index].idSector, oldDescription); //Actual descripcion
                uploadDescription(arraySectors, lengthSectors, auxSector, newDescription); //Nueva descripcion
                printf("\nEsta seguro de querer modificar %s por %s? (s/n): \n", oldDescription, newDescription);
                fflush(stdin);
                confirmacion = getchar();
                confirmacion = tolower(confirmacion);
            }
            if(confirmacion == 'n')
            {
                printf("Se ha cancelo la modificacion del sector.\n\n");
            }
            else
            {
                arrayEmployees[index].idSector = auxSector;
                printf("Se ha modifico el sector con exito.\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("\nHa ingresado una opcion incorrecta.\n");
        }
        flag = 0;
    }
    return flag;
}

int removeEmployee(Employee* arrayEmployees, Sector* arraySectors, int lengthArray, int lengthSectors, int index)
{
    int flag = -1;
    char confirmacion;
    if(arrayEmployees != NULL && lengthArray > 0)
    {
        printf("\nDatos del empleado a borrar.\n\n");
        printf("\t     ID |     Nombre |   Apellido |    Salario |      Sector |\n\n");
        printEmployee(arrayEmployees, arraySectors, lengthSectors, index);
        confirmacion = getValidChar("\nEsta seguro que quiere eliminar al empleado (s/n)?: \n", "\nError, ingreso un caracter no valido, reintente por favor.", 's', 'n');
        if(confirmacion == 's')
        {
            arrayEmployees[index].isEmpty = DELETED;
            printf("\nSe ha eliminado al empleado correctamente.\n\n");
        }
        else
        {
            printf("\nSe ha cancelo la eliminacion del empleado\n\n");
        }
        flag = 0;
    }
    return flag;
}

void sortEmployees(Employee* arrayEmployees, int lengthArray, int order)
{
    Employee auxPersona;
    for(int i=0; i<lengthArray-1; i++)
    {
        for(int j=i+1; j<lengthArray; j++)
        {
            if(order == 1)
            {
                if(strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) > 0 )//Ascendente
                {
                    auxPersona = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = auxPersona;
                }
                if(strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) == 0  && arrayEmployees[i].idSector > arrayEmployees[j].idSector)
                {
                    auxPersona = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = auxPersona;
                }
            }
            else
            {
                if(strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) < 0 )//Ascendente
                {
                    auxPersona = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = auxPersona;
                }
                if(strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) == 0  && arrayEmployees[i].idSector < arrayEmployees[j].idSector)
                {
                    auxPersona = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = auxPersona;
                }
            }

        }
    }
}

float totalSalaries(Employee* arrayEmpleados, int lengthArray)
{
    float sueldos = 0;
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == FULL)
        {
            sueldos = sueldos + arrayEmpleados[i].salary;
        }
    }
    return sueldos;
}

float averageSalary(Employee* arrayEmployees, int lengthArray, float totalSalaries)
{
    float promedio;
    int contador = 0;
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmployees[i].isEmpty == FULL)
        {
            contador++;
        }
    }
    promedio = totalSalaries/contador;
    return promedio;
}

int employeesSurpassAverage(Employee* arrayEmployees, int lengthArray, int averageSalary)
{
    int cantidadEmpleados = 0;
    for(int i=0; i<lengthArray; i++)
    {
        if(arrayEmployees[i].salary > averageSalary && arrayEmployees[i].isEmpty == FULL)
        {
            cantidadEmpleados++;
        }
    }
    return cantidadEmpleados;
}

int listEmployees(Employee* arrayEmployees, Sector* arraySectors, int lengthArray, int lengthSectors)
{
    int opcion;
    int order;
    float totalSueldos;
    float promedioSueldos;
    int totalSuperanPromedio;
    int flag = -1;
    if(arrayEmployees != NULL && lengthArray > 0)
    {
        printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2- Total y promedio de los salarios y empleados superan el salario promedio.\n\n");
        opcion = getValidIntOpcion("Ingrese opcion: ", "Error al ingresar opcion. Reintente.\n", 1, 2);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("Lista de los empleados ordenados alfabeticamente por Apellido y Sector:\n\n");
            order = getValidIntOpcion("Para ordenar alfabeticamente ingrese 1 de lo contrario ingrese 0: ", "\nError, solo se admiten numeros. Reintente por favor.\n", 0, 1);
            sortEmployees(arrayEmployees, lengthArray, order);
            printEmployees(arrayEmployees, lengthArray, arraySectors, lengthSectors);
            break;
        case 2:
            system("cls");
            printf("Total y promedio de los salarios y empleados superan el salario promedio:\n\n");
            totalSueldos = totalSalaries(arrayEmployees, lengthArray);
            promedioSueldos = averageSalary(arrayEmployees, lengthArray, totalSueldos);
            totalSuperanPromedio = employeesSurpassAverage(arrayEmployees, lengthArray, promedioSueldos);
            printf("El total sueldo es de %.2f\n", totalSueldos);
            printf("El Promedio de los sueldo es de %.2f\n", promedioSueldos);
            printf("La cantidad que superan el promedio son %d.\n\n", totalSuperanPromedio);
            break;
        }
        flag = 0;
    }
    return flag;
}
