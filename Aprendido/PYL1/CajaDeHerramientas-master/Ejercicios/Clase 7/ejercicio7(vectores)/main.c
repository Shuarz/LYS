#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headerEjer.h"

#define CantidadClientes 20

void inicializarArrayInt(int array[], int cantidadDeElementos, int valor);
int buscarPrimerOcurrencia(int array[], int CantidadDeElementos, int valor);

int main()
{
    //esto son los array paralelos
    char arrayNombres[CantidadClientes][50];//[cuantas personas van a ser ][la cantidad de caractares dispoibles apra esas personas]
    char arrayApellidos[CantidadClientes][50];
    int arrayLegajos[CantidadClientes];

    //declaramos auxliares que nos van a ayudar a pasar datos cuando modifiquemos

    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    int auxiliarLegajoStr[50];

    int auxiliarlegajo;
    int indiceLugarLibre; //nos dice cual va a ser nuestro lugar libre en el array
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i;
    int j;

    inicializarArrayInt(arrayLegajos,CantidadClientes,-1); //indicamos que en -1 esa posicion esta vacia
    //le pasamos un array, la cantidad de elementos que seria los clientes y la cantidad(que es este caso seria -1)

    while(opcion != 6)
    {
        opcion = getInt("\n\n\n1. alta \n2. baja \n3.modificacion \n4.listar \n6. salir \n\n\n");
        switch(opcion)
        {
        case 1:
            indiceLugarLibre = buscarPrimerOcurrencia(arrayLegajos, CantidadClientes, -1); //ya establecemos como esta conformado indice de luhar libre
                               if(indiceLugarLibre == -1)
            {
                printf("\n\n no quedan lugares libres\n");
                break; // si indice es igual a uno, entra aca y dice que no tiene lugares, con el break salimos
            }

            printf("\nAltA\n");
            if(!getStringLetras("ingrese el nombre: ", auxiliarNombreStr)); //si el nombre ingresado tiene numeros, le tira error, sino no entra
            {
                printf("el nombre debe estar compuesto por letras\n");
                break;
            }

            if(!getStringLetras("ingrese el apellido: ", auxiliarApellidoStr));
            {
                printf("el apellido debe estar compuesto por letras\n");
                break;
            }

            if(!getStringNumerico("ingrese el legajo: ", auxiliarLegajoStr));
            {
                printf("el legajo debe estar compuesto por numeros");
                break;
            }
            auxiliarlegajo = atoi(auxiliarLegajoStr); //atoi lo que hace es pasar de un string a un entero (char a int)

                             if(buscarPrimerOcurrencia(arrayLegajos, CantidadClientes, auxiliarlegajo) != -1)
            {
                printf("\nError, ese legajo ya existe"); //si buscar primera ocurrencia es igual a -1 dado los parametros que le dimos, dice que y existe y sale
                break;
            }

            strcpy(arrayNombres[indiceLugarLibre], auxiliarNombreStr); //aca se hace un strcpy por que es un char
            strcpy(arrayApellidos[indiceLugarLibre], auxiliarApellidoStr); //copiamos lo que tiene el aux a array de apellido
            arrayLegajos[indiceLugarLibre] = auxiliarlegajo; //aca le pasamos el valor auxiliar a array legajos

            break;

        case 2:
            if(!getStringNumerico("ingrese el legajo a dar de baja: ", auxiliarLegajoStr));
            {
                printf("el legajo debe estar compuesto por numeros");
                break;
            }
            indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos, CantidadClientes, atoi(auxiliarLegajoStr));
            //le pasamos los mismos parametros a indice de busqueda

            if(indiceResultadoBusqueda == -1) //si el indice que busca esta en -1, significa que nunca fue dado de alra, por lo tanto no existe
            {
                printf("\n no se encuentra ese legajo\n");
                break;
            }
            arrayLegajos[indiceResultadoBusqueda]=-1;
            break; //si se encuentra el legajo, cambia el numero del array y lo pone en -1 para que la maquina lo tome como nuevo

        case 3:
            if(!getStringNumerico("ingrese el legajo a modificar: ", auxiliarLegajoStr));
            {
                printf("\n el legajo debe estar compuesto por numeros");
                break;
            }

            indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos, CantidadClientes, atoi(auxiliarLegajoStr));
            //lo que tiene auxuliar lo guardamos en indice resultado

            if(indiceResultadoBusqueda = -1)
            {
                printf("\n no se encuentra ese legajo \n");
                break;
            }

            if(!getStringLetras("ingrese el nombre: ", auxiliarNombreStr)); //si el nombre ingresado tiene numeros, le tira error, sino no entra
            {
                printf("el nombre debe estar compuesto por letras\n");
                break;
            }

            if(!getStringLetras("ingrese el apellido: ", auxiliarApellidoStr));
            {
                printf("el apellido debe estar compuesto por letras\n");
                break;
            }

            //el legajo ya lo sabemos, asi que no hace falta pedirlo otra vez

            strcpy(arrayNombres[indiceResultadoBusqueda], auxiliarNombreStr);
            strcpy(arrayApellidos[indiceResultadoBusqueda], auxiliarApellidoStr);
            //parecido al dar de alta, pero usando de indice el resultado de busqueda

            break;

        case 4:
            printf("\n listar \n");

            for(i=0; i < CantidadClientes; i++)
            {
                if(arrayLegajos[i] != -1) //el -1 es para que el programa no me muestre los que se dieron de baja
                {
                    printf("\n %s - %s - %d", arrayNombres[i],arrayApellidos[i],arrayLegajos[i]);
                }//muestra los array en orden a las mascaras puestas
            }
            break;

        case 5:
            printf("\n ordenado \n");

            for(i=0; i < CantidadClientes; i++)
            {
                if(arrayLegajos[i] == -1)
                {
                    continue; //aunque encntrase un -1, sigue interando
                }
                for(j=i+1; j < CantidadClientes; j++)
                {
                    if(arrayLegajos[i] == -1)
                    {
                        continue; //lo mismo para la variante j
                    }

                    if(strcmp(arrayApellidos[i],arrayApellidos[j])) //que compate los array de i y los array de j
                    {
                        strcpy(auxiliarNombreStr,arrayNombres[i]); //el valor del array[i] nombres a auxiliar
                        strcpy(arrayNombres[i],arrayNombres[j]); //el valor del aray[i] a array[j]
                        strcpy(arrayNombres[j],auxiliarNombreStr); //el valor de auxuliar a array[j]

                        strcpy(auxiliarApellidoStr,arrayApellidos[i]);
                        strcpy(arrayApellidos[i],arrayApellidos[j]);
                        strcpy(arrayApellidos[j],auxiliarApellidoStr);

                        auxiliarlegajo = arrayLegajos[i];
                        arrayLegajos[i] = arrayLegajos[j];
                        arrayLegajos[j] = auxiliarlegajo;
                    }

                }

            }
            break;

        }




    }




    return 0;
}

/** \brief inicializa un array de enteros con el valor recibido
 * \param array es el array a ser inicializado
 * \param cantidadDeElementos indica la longitud del array
 * \param valor es el valor que sera vargado en cada posicion
 * \return no me interesa que retorna
 *
 */
void inicializarArrayInt(int array[], int cantidadDeElementos, int valor)
{
    int i;
    for(i=0; i < cantidadDeElementos; i++)
    {
        array[i] = valor;
    }

}

/** \brief busca la primer ocurrencia de un array entero
  * \param array es el array en el cual buscar
 * \param cantidadDeElementos indica la longitud del array
 * \param valor es el valor que se busca
 * \return si no hay ocurrencia (-1) y si lo hay, la posicion de la misma(i)
 *
 */
int buscarPrimerOcurrencia(int array[], int cantidadDeElementos, int valor)
{
    int i;
    for(i=0; i < cantidadDeElementos; i++)
    {
        if(array[i] = valor)
        {
            return i;
        }
    }
    return -1;
}
