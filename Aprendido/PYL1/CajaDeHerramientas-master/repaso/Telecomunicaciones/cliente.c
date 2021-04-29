#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

/** \brief Constructor: reserva un espacio en memoria para la estructura e inicializa todos los valores en "0"
 *
 * \return Employee* Puntero a la estructura creada
 *
 */
eCliente* cliente_new()
{
    eCliente* pCliente;
    pCliente = (eCliente*) calloc(1, sizeof(eCliente));

    return pCliente;
}


/** \brief Constructor con parámetros: reserva un espacio en memoria y setea los valos iniciales de acuerdo a los parámetros
 *
 * \param idStr char* ID con el que se inicializará la estructura
 * \param nombreStr char* Nombre con el que se inicializará la estructura
 * \param horasTrabajadasStr char* Cantidad de horas trabajadas con las que se inicializará la estructura
 * \return Employee* Puntero a la estructura creada
 *
 */
eCliente* cliente_newParametros(char* idStr,char* nombre, char* sexo, char* numeroTelefono, char* importeStr)
{
    eCliente* pCliente;
    pCliente = cliente_new();

    cliente_setId(pCliente, atoi(idStr));
    cliente_setNombre(pCliente, nombre);
    cliente_setSexo(pCliente, sexo);
    cliente_setTelefono(pCliente, numeroTelefono);
    cliente_setImporte(pCliente, atoi(importeStr));

    return pCliente;
}


/** \brief Destructor: libera el espacio en memoria reservado para un empleado y lleva el puntero a NULL
 *
 * \return void
 *
 */
void cliente_delete(eCliente* this)
{
    free(this);
    this = NULL;
}


/** \brief Asigna un nuevo valor al campo ID del empleado
 *
 * \param this Employee* Puntero a la estructura empleado a modificar
 * \param id int Nuevo ID
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int cliente_setId(eCliente* this,int id)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->id = id;
    }
    return retorno;
}


/** \brief Permite obtener el valor del ID de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param id int* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int cliente_getId(eCliente* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}


/** \brief Asigna un nuevo nombre al empleado
 *
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Nuevo nombre
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int cliente_setNombre(eCliente* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}


/** \brief Permite obtener el valor del campo Nombre de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param nombre char* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int cliente_getNombre(eCliente* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}



/** \brief Asigna un nuevo valor al campo ID del empleado
 *
 * \param this Employee* Puntero a la estructura empleado a modificar
 * \param id int Nuevo ID
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int cliente_setSexo(eCliente* this,char* sexo)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        strcpy(this->sexo, sexo);
    }
    return retorno;
}


/** \brief Permite obtener el valor del ID de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param id int* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int cliente_getSexo(eCliente* this,char* sexo)
{
    int retorno = -1;
    if(this != NULL && sexo != NULL)
    {
        *sexo = this->sexo;
        retorno = 1;
    }
    return retorno;
}

/** \brief Asigna un nuevo nombre al empleado
 *
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Nuevo nombre
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int cliente_setTelefono(eCliente* this,char* telefono)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        strcpy(this->numeroTelefono, telefono);
    }
    return retorno;
}


/** \brief Permite obtener el valor del campo Nombre de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param nombre char* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int cliente_getTelefono(eCliente* this,char* telefono)
{
    int retorno = -1;
    if(this != NULL && telefono != NULL)
    {
        strcpy(telefono, this->numeroTelefono);
        retorno = 1;
    }
    return retorno;
}


/** \brief Asigna un nuevo nombre al empleado
 *
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Nuevo nombre
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int cliente_setImporte(eCliente* this,int importe)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        strcpy(this->importe, importe);
    }
    return retorno;
}


/** \brief Permite obtener el valor del campo Nombre de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param nombre char* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int cliente_getImporte(eCliente* this,int* importe)
{
    int retorno = -1;
    if(this != NULL && importe != NULL)
    {
        *importe = this->importe;
        retorno = 1;
    }
    return retorno;
}
