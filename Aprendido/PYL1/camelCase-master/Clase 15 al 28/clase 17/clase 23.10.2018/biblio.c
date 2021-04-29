#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"


///////////////FUNCTIONS////////////////////////////////////////////////////////
sPersona* nuevaPersona()///Construye un espacio en memora para una persona (CONSTRUCTOR)
{
    sPersona* miPersona;
    miPersona=(sPersona*)malloc(sizeof(sPersona));
    if(miPersona!=NULL)
    {
        miPersona->id=0;
        strcpy(miPersona->nombre,"NN");
        miPersona->edad=0;
    }
    //miPersona=calloc(sizeof(sPersona),1);

    return miPersona;//Devuelve el valor del puntero a sPersona
}
void mostrarPersona(sPersona* this)
{
    printf("%d--%s--%d\n",this->id,this->nombre,this->edad);
}
sPersona* initPersona(int id,char* name,int age)
{
    sPersona* miPersona;//declaro un puntero a persona en el stak
    ///miPersona=(sPersona*)malloc(sizeof(sPersona));//asigno lugar en memoria en el heap
    miPersona=nuevaPersona();
    if(miPersona!=NULL)//si el lugar asignado para la variable no es nulo
    {
        miPersona->id=id;//el valor pasado como parametro se guarda en el puntero
        strcpy(miPersona->nombre,name);//el valor pasado como parametro se guarda en el puntero
        miPersona->edad=age;//el valor pasado como parametro se guarda en el puntero
    }
    return miPersona;
}

///SETERS/////////////////////////////////////////////////
int sPersona_setId(sPersona* this,int id)
{
    int estado=0;
    if(this!=NULL)
    {
        estado=1;
        this->id=id;
    }
    return estado;
}
int sPersona_setName(sPersona* this,char* nombre);
{
    int estado=0;
    if(this!=NULL)
    {
        estado=1;
        strcpy(this->nombre,nombre);
    }
    return estado;
}
int sPersona_setAge(sPersona* this,int edad);
{
    int estado=0;
    if(this!=NULL)
    {
        estado=1;
        this->age=edad;
    }
    return estado;
}
///://///////////////////////////////////////////////////

///GETERS////////////////////////////////////////////////
int sPersona_getId(sPersona* this)
{
    int id=-1;
    if(this!=NULL)
    {

        id=this->id;
    }
    return id;
}
char* sPersona_getName(sPersona* this)
{
    char name[50];
    if(this!=NULL)
    {

        name=this->nombre;
    }
    return name;
}
int sPersona_getAge(sPersona* this)
{
    int edad=-1;
    if(this!=NULL)
    {

        edad=this->edad;
    }
    return edad;
}
///://///////////////////////////////////////////////////
