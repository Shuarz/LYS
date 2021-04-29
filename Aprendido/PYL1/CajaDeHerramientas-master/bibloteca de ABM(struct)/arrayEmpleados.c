#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmpleados.h"

int eEmpleado_init(eEmpleado listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estaVacio= LIBRE;
            listado[i].idEmpleado= 0;
        }
    }
    return retorno;
}

int eEmpleado_buscarLugarLibre(eEmpleado listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estaVacio == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eEmpleado_siguienteId(eEmpleado listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estaVacio == LIBRE)
            {
                    if(listado[i].idEmpleado  > retorno)
                    {
                         retorno = listado[i].idEmpleado;
                    }
            }
        }
    }

    return retorno+1;
}


int eEmpleado_buscarPorId(eEmpleado listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estaVacio == OCUPADO && listado[i].idEmpleado == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



void eEmpleado_mostrarUno(eEmpleado unEmpleado)
{
     printf("%d     %s    %s    %.2f    %d\n", unEmpleado.idEmpleado, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector);

}

int eEmpleado_mostrarlistado(eEmpleado listado[],int limite)
{
    int retorno = -1;
    int i;


        retorno = 0;

        printf("Id:     Nombre:    Apellido:    Salario:    Sector:");
        for(i=0; i<limite; i++){
            if(listado[i].estaVacio == OCUPADO)
            {
                eEmpleado_mostrarUno(listado[i]);
            }
        }

    system("pause");
    system("cls");

    return retorno;
}





int eEmpleado_mostrarlistadoConBorrados(eEmpleado listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estaVacio==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eEmpleado_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

int eEmpleado_alta(eEmpleado listado[] ,int limite, int id, char nombre[], char apellido[], float salario, int sector)
{

    int indice;
    int i;

        indice = eEmpleado_buscarLugarLibre(listado,limite);

          for(i = 0; i < limite; i++){

            listado[indice].idEmpleado = id;
            strcpy(listado[indice].nombre, nombre);
            strcpy(listado[indice].apellido, apellido);
            listado[indice].salario = salario;
            listado[indice].sector = sector;
            listado[indice].estaVacio = OCUPADO;

            }

        }



int eEmpleado_modificacion(eEmpleado listado[] , int limite)
{
    int idEmpleado;
    int i;
    int opcion;

    printf("Ingrese id de empleado: \n");
    scanf("%d", &idEmpleado);

    for(i = 0; i < limite; i++){
        if(idEmpleado == listado[i].idEmpleado){
            printf("Id encontrado, que desea modificar?\n");
            printf("1.Nombre\n");
            printf("2.Apellido\n");
            printf("3.Salario\n");
            printf("4.Sector\n");

            opcion = getInt("Ingrese opcion: \n");

            switch(opcion){
                case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(listado[i].nombre);
                        break;
                case 2:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(listado[i].apellido);
                        break;
                case 3:
                        printf("Ingrese salario nuevo: ");
                        scanf("%f", &listado[i].salario);
                        break;
                case 4:
                    printf("Ingrese sector nuevo: ");
                    scanf("%d", &listado[i].sector);
                    break;
                default:
                    printf("Ingrese una opcion valida a modificar!");
                    break;
            }
        }
    }
}

char *eEmpleado_ingresarNombre(char nombre[]){

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(nombre);

        return nombre;

}

char *eEmpleado_ingresarApellido(char apellido[]){

        printf("Ingrese apellido:");
        fflush(stdin);
        gets(apellido);

        return apellido;
}

float eEmpleado_ingresarSalario(){

        float salario;

        printf("Ingrese salario: ");
        scanf("%f", &salario);

        return salario;

}

int eEmpleado_ingresarSector(){

    int sector;

    printf("Ingrese sector: ");
    scanf("%d", &sector);

    return sector;
}

int eEmpleado_baja(eEmpleado listado[] ,int limite, int id){

    char validar;
    int i;

     for(i = 0; i < limite; i++){
        if(id == listado[i].idEmpleado){
            printf("Id encontrado, seguro que desea dar de baja? s/n \n");
            fflush(stdin);
            scanf("%c", &validar);

            if(validar == 's'){
                listado[i].estaVacio = LIBRE;
            }
        }
     }
}

int eEmpleado_ingresarId(){

    int id;
    printf("Ingresar id: ");
    scanf("%d", &id);

    return id;

}

int eEmpleado_ordenar(eEmpleado listado[] ,int limite, int orden){
int i;
        int j;
        char aux[50];

        switch(orden){
            case 1:
            for(i = 0; i < limite-1; i++)
            {
                for(j = i+1; j < limite; j++)
                {
                    if(strcmp(listado[i].apellido, listado[j].apellido)>0)
                    {
                        strcpy(aux, listado[j].apellido);
                        strcpy(listado[j].apellido, listado[i].apellido);
                        strcpy(listado[i].apellido, aux);
                    }
                }
            }
        }
}

int eEmpleado_ingreseAscendenteODescendente(){

    int orden;

    printf("Como desea ordenar los apellidos y sectores?: \n");
    printf("1.Ascendente\n");
    printf("2.Descendente\n");
    scanf("%d", &orden);


    return orden;
}







