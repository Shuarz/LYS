#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje); //le paso un valor de tipo char por eso la "s"
    scanf("%f",&auxliar); //y aca guarda el valor del flotante

    return auxiliar;
}


int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje); //le paso un valor de tipo char por eso la "s"
    scanf("%d",&auxliar); //y aca guarda el valor del flotante

    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje); //le paso un valor de tipo char por eso la "s"
    fflush(stdin);
    scanf("%c",&auxliar); //y aca guarda el valor del flotante

    return auxiliar;
}
