#include "funcionesExtras.h"

int menuOpciones(){

    int opcion;

    printf("/--- Menu de opciones ---/\n");
    printf("1. Dar de alta empleado\n");
    printf("2. Modificar empleado por id\n");
    printf("3. Dar de baja empleado por id\n");
    printf("4. Informar\n");
    printf("5. Salir\n");

    opcion = getInt("Ingrese opcion: \n");

    system("cls"); //limpio la pantalla despues de seleccionar opcion cada opcion

    return opcion;

}

int getInt(char texto[]){

    int numero;

    printf("%s", texto);
    scanf("%d", &numero);

    return numero;

}
