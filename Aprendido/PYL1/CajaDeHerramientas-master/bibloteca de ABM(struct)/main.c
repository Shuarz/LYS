#include <stdio.h>
#include <stdlib.h>
#include "arrayEmpleados.h"
#include "funcionesExtras.h"
#define CANTIDAD 4

int main()
{

    int opcion;
    eEmpleado listadoDeEmpleados[CANTIDAD];
    char nombre[TAMANIO];
    char apellido[TAMANIO];
    float salario;
    int sector;
    int id;
    int retornoId;
    int retorno;
    int retornoOrden;

    eEmpleado_init(listadoDeEmpleados, CANTIDAD);
    retorno = eEmpleado_buscarLugarLibre(listadoDeEmpleados, CANTIDAD);

do{

    opcion = menuOpciones();


    switch(opcion){

    case 1:
        if(retorno >= 0){
            eEmpleado_ingresarNombre(nombre);
            eEmpleado_ingresarApellido(apellido);
            salario = eEmpleado_ingresarSalario();
            sector = eEmpleado_ingresarSector();
            id = eEmpleado_siguienteId(listadoDeEmpleados, CANTIDAD);
            eEmpleado_alta(listadoDeEmpleados, CANTIDAD, id, nombre, apellido, salario, sector);
        }else{
            printf("No se puede cargar mas empleados!\n");
            system("pause");
        }

        break;
    case 2:
        eEmpleado_modificacion(listadoDeEmpleados, CANTIDAD);
        break;
    case 3:
        retornoId = eEmpleado_ingresarId();
        eEmpleado_baja(listadoDeEmpleados, CANTIDAD, retornoId);
        break;
    case 4:
        retornoOrden = eEmpleado_ingreseAscendenteODescendente();
        eEmpleado_ordenar(listadoDeEmpleados, CANTIDAD, retornoOrden);
        break;
    case 5:
        opcion  = 5;
        break;
    }

}while(opcion != 5);

return 0;

}
