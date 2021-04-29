#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerEjer.h"
//#include <time.h>

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje); //le paso un valor de tipo char por eso la "s"
    scanf("%f",&auxiliar); //y aca guarda el valor del flotante

    return auxiliar;
}


int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje); //le paso un valor de tipo char por eso la "s"
    scanf("%d",&auxiliar); //y aca guarda el valor del flotante

    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje); //le paso un valor de tipo char por eso la "s"
    fflush(stdin);
    scanf("%c",&auxiliar); //y aca guarda el valor del flotante

    return auxiliar;
}

int esNumerico(char str[])
{
    int i=0;

    while(str[i] != '\0']) //mientras el indice sea distinto a "\o", seguit, de lo contrario contar
    {
        if(str[i] < '0' || str[i] > '9')
            return o;
        i++;
    }
    return 1; //mientras que el numero ingresado sea mayor a cero y menor a 9, devolver cero, sino que devuelva 1
}

int esSoloLetras(char str[])
{
    while(str[i] != '\0']) //mientras el indice sea distinto a "\o", seguit, de lo contrario contar
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return o;
        i++; //lo mismo que arriba, si es a A z minuscula lo acepta y tamnien con mayusculas
    }
    return 1;
}


/** \brief solicita al usuario el tento y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param imput de array es donde se cargara el texto ingresado
 * \return void
 */
void getString(char mensaje[],char imput[]) //con esto ya tenemos la funcion par pedir letra
{
    printf("%s", mensaje);
    scanf("%s", imput);
}


/** \brief solicita la usuario el texto y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param imput de array es donde se cargara el texto ingresado (solo si cumple si es uma letra)
 * \return 1 si el texto contiene solo letra
 *
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux)
        return 1
    }
    return 0;
}

int getStringNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux)
        return 1
    }
    return 0;
}




