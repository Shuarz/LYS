#include <stdio.h>
#include <stdlib.h>
#include "biblioEstructura.h"




int main()
{
/*EJEMPLO UNO
    sDato datoUno={1,"c"};//cargo la estructura
    sDato* pDatoUno;
    pDatoUno=&datoUno;
    int x;

    x=(*pDatoUno).a;
    printf("%d",x);//me va a devolver 1
*/
/**ESTA MANERA ES LA LARGA*/
   /* sDato array[2]={{1,'c'},{1,'b'}};//array de la estructura
    sDato* pDato;//Puntero al dato
    pDato=array;//asignacion de array al pDato
    int i;
    for(i=0;i<2;i++)//Itero el array de tipo estructura
    {
        printf("Campo a: %d\t",(*(pDato+i)).a);//muestro el valor del campo a de la estructura
        printf("Campo b: %c\n",(*(pDato+i)).b);//muestro el valor del campo b de la estructura
    }
*/
/**UTILIZANDO EL OPERADOR "->"*/
/*Ejemplo uno utilizando operador ->
    sDato datoUno={1,'c'};//cargo la estructura
    sDato* pDatoUno;
    pDatoUno=&datoUno;

    int x;
    x=pDatoUno->a;
    printf("%d",x);//me va a devolver 1
*/

    /*Ejemplo dos usando el operador ->
    sDato array[2]={{1,'c'},{1,'b'}};//array de la estructura
    sDato* pDato;//Puntero al dato
    pDato=array;//asignacion de array al pDato
    int i;
    for(i=0;i<2;i++)//Itero el array de tipo estructura
    {
        printf("Campo a: %d\t",(pDato+i)->a);//muestro el valor del campo a de la estructura
        printf("Campo b: %c\n",(pDato+i)->b);//muestro el valor del campo b de la estructura
    }*/

    /**UTILIZACION DE LA FUNCION "funcion" */
    /**Este tipo de funciones no son efectivas ya que a al retornar, se libera y tira basura**/
    /*sDato* puntero_1;
    puntero_1=funcion(2,'c');
    printf("Campo a: %d \t Campo b: %c\n",puntero_1->a,puntero_1->b);

    sDato* puntero_2;
    puntero_2=funcion(5,'b');
    printf("Campo a: %d \t Campo b: %c\n",puntero_2->a,puntero_2->b);
    */
    /**Gestion de memoria dinamica*/
    int* pEntero;
    pEntero=(int*)malloc(sizeof(int));
    if(pEntero!=NULL){
        *pEntero=9;
        printf("%d",*pEntero);
    }
    /**Ahora, para un array*/
    int* pArrayEnteros;
    int i;
    pArrayEnteros=(int*)malloc(sizeof(int)*5);//Guarda lugar para un vector de 5 caracteres de valor entero, es decir 4(Bytes)*5=20(Bytes)
    if(pEntero!=NULL){
        for(i=0;i<5;i++)
        {
            printf("Ingrese un valor");
            fflush(stdin);
            scanf("%d",pArrayEnteros+i);
        }
        for(i=0;i<5;i++){
            printf("%d\n",*(pArrayEnteros+i));
        }
    }
    pEntero=realloc(pEntero,sizeof(int)*10);
    return 0;
}
