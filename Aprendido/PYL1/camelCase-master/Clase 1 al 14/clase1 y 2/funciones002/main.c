#include <stdio.h>
#include <stdlib.h>
/*
retorna     recibe
    0           0
    0           1
    1           0
    1           1
*/

void sumar1(void); //si lo dijo vacio, asutme un entero, si lo pongo void no recibe nadas
int main()
{
    sumar1();  //esto llama a la funcion, sino no hace nada void
    return 0;
}
// este propotico, no recibe nada, no hace nada
void sumar1(void)

{
    int numeroUno;
    int numeroDos;
    int suma;

    printf("ingrese el numero: \n");
    scanf("%d",&numeroUno);

    printf("ingrese el numero: ");
    scanf("%d",&numeroDos);

    suma=numeroUno+numeroDos;

    printf("la suma de los dos numeros fue: %d",suma);
}
