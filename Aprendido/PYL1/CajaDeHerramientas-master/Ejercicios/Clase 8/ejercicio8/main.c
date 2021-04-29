#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cantidadDePersonas 20

typedef struct
{
    char nombre[50];
    char apellido[50];
    char legajo;
}ePersonas; //a la estrucutura la llamamos personas

void inicializarArrayPersona(ePersonas arrayPersona[], int cantidadDeElementos, int valor);
int buscarPrimerOcurrencia(ePersonas arrayPersona[], int CantidadDeElementos, int valor);
//le pasamos a la estrucuras los parametros de cantidad de elementos y el valor que seria -1

int main()
{

    return 0;
}

/** \brief inicializa un array de personas con el valor recibido
 * \param arrayPersona[] es el array a ser inicializado
 * \param cantidadDeElementos indica la longitud del array
 * \param valor es el valor que sera cargado en cada posicion
 * \return void
 */
void inicializarArrayPersona(ePersonas arrayPersona[], int cantidadDeElementos, int valor)
{
    int i;
    for(i=0; i<cantidadDeElementos ;i++)
    {
        arrayPersona[i].legajo = valor;
        //con el punto llegabamos al campo, en este caso el legajo
    }
}

int buscarPrimerOcurrencia(ePersonas arrayPersona[], int CantidadDeElementos, int valor)
{
    int i;
    for(i=0; i<cantidadDeElementos; i++)
    {
        if(arrayPersona[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}


//es igual al punto 7, menos la parte de ePersonas por legajos
