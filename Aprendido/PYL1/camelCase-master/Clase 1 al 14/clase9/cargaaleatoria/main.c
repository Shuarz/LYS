#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define T 5

/** \brief buscar espacio disponible
 *
 * \param int[] listado de enteros
 * \param int tamaño del listado
 * \param int el valor ilogio
 * \return int [-1] si no hay espacio, [
 *
 */
int buscarLibre(int[], int, int);

int main()
{
    int vector [T];
    int i;
    char opcion = 's';

    int indice;

    for(i=0; i<T; i++) //lo recorro
    {

        vector[i]=-1; //lo inicializo en -1
    }

    do //busco donde guardar el dato, si encuentra lugar si encuentra lo guardo, sino le digo que no hay esapcio
        //si quiere le digo de ingresar otro
    {
        for(i=0; i<T; i++)
        {
            indice = buscarLibre(vector, T, -1);
            if(indice!=-1)
            {
                printf("ingrese un numero: ");
                scanf("%d", &vector[indice]);
            }
            else
                {
                printf("no hay espcio");
                break;
                }

        }
        printf("\n desea ingresar otro? ");
        opcion=getche();


    }
    while(opcion=='s');


        return 0;
}

int buscarLibre(int numeros[], int tam, int ilogico)
{
    int index;
    int i;
    for(i=0; i<tam; i++)
    {
        if(numeros[i]==ilogico)
        {
            index = i;
            break;
        }
    }
    return index; // con esto se donde hay espacio en un numero
}
