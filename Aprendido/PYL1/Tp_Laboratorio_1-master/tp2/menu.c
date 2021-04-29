#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "miBibloteca.h"
#define FULL 0
#define EMPTY 1
#define DELETED 2

int menu()
{
    int option;
    system("cls");
    printf("  1- Alta\n");
    printf("  2- Modificar\n");
    printf("  3- Baja\n");
    printf("  4- Informar\n");
    printf("  5- Salir\n");
    option = getInt("Ingrese opcion del 1 al 5 por favor: \n");
    return option;
}
