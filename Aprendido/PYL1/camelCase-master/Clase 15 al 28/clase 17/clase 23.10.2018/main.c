#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

#define T 5
/**::::::::::CLASE 23.10::::::::::::::::::**/


///////////PRINCIPAL*FUNCTION///////////////////////////////////////////////////////////////
int main()
{
    /*
    int* array;//apunta al stak
    int* aux;
    int i;//iterador
    array = (int*)malloc(sizeof(int)*T);//apunta al heap

    if(array!=NULL)
    {   printf("Array de 5");
        for(i=0;i<T;i++)
        {
            *(array+i)=i+1;//obtengo el valor a partir de la direccion de memoria
        }
        for(i=0;i<T;i++){printf("%d\n",*(array+i));}

        aux=realloc(array,sizeof(int)*(T+5));
        printf("Array de 10:\n");
        if(aux!=NULL)
        {
            array=aux;
            for(i=T;i<(T+5);i++)
            {
                *(array+i)=i+1;
            }
            for(i=0;i<T;i++)
            {
                printf("%d\n",*(array+i));
            }

            printf("Array de 3:\n");
            array=realloc(array,sizeof(int)*3);//achico el lugar de espacio en memoria
            //no necesito un if(array!=NULL) en este caso, ya que redujimos el espacio en memoria
            for(i=0;i<T;i++)
            {
                printf("%d\n",*(array+i));
            }
        }
    }

    */
/*
    sPersona* persona;
    persona=nuevaPersona();
    if(persona!=NULL)
    {
        persona->id=98;
        strcpy(persona->nombre,"juan");
        persona->edad=53;*/
/*        mostrarPersona(persona);
    }
    sPersona* personaDos;
    personaDos=initPersona(1,"juan",43);
    if(personaDos!=NULL)
    {
        mostrarPersona(personaDos);
    }
*/
    /*
    sPersona* persona;//Puntero a una estructura
    persona=nuevaPersona();//le asigno al puntero la funcion nueva persona
    int idDeLaPersona;//declaro una variable
    if(sPersona_setId(persona,8))//si la funcion devuelve 1
    {
        idDeLaPersona=sPersona_getId(persona);//le asigno a la variable la funcion getId
        if(idDeLaPersona!=-1)//si el id!=-1
        {
            printf("El id es: %d",idDeLaPersona);//escribo en pantalla
        }
    }
    else//si setId es 0
    {
        printf("Error en el programa!\n");//tira un error de programa
    }
    //mostrarPersona(persona);
    */

    sPersona* arrayPersona;
    ePersona persona;
    int id;
    char nombre[50];
    int edad;
    int i;
    arrayPersona=(sPersona*)malloc(sizeof(sPersona)*5);
    if(arrayPersona!=NULL)
    {
        for(i=0;i<5;i++)
        {
            //pedir datos
            printf("Ingrese id: \n");
            scanf("%d",&id);
            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(nombre);
            printf("Ingrese edad: \n");
            scanf("%d",&edad);

            ePersona_setId(&persona,id);
            ePersona_setName(&persona,nombre);
            ePersona_setAge(&persona,edad);

            *(arrayPersona+i)= persona;

        }
        for(i=0;i<5;i++)
        {
            mostrarPersona(persona);
        }
    }





    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////





