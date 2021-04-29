#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

/*int esNumerico(char str[]);
int estelefonico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);*/

void getString(char mensaje[],char input[]); //ennle imput en donde nos va a dejar la infomracion
int getStringLetras(char mensaje[],char input[]); //valida que solo este conformado por letras
int getStringNumerico(char mensaje[],char input[]); //valida que solo este conformado por numeros
/* nos devuelve un entero para saber si es verdadero o falso 1 o 0*/
