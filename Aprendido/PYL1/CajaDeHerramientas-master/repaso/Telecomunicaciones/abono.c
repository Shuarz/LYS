#include <stdio.h>
#include <stdlib.h>

/** \brief Constructor: reserva un espacio en memoria para la estructura e inicializa todos los valores en "0"
 *
 * \return Employee* Puntero a la estructura creada
 *
 */
eAbono* abono_new()
{
    eAbono* pAbono;
    pAbono = (eAbono*) calloc(1, sizeof(eAbono));

    return pAbono;
}


/** \brief Constructor con parámetros: reserva un espacio en memoria y setea los valos iniciales de acuerdo a los parámetros
 *
 * \param idStr char* ID con el que se inicializará la estructura
 * \param nombreStr char* Nombre con el que se inicializará la estructura
 * \param horasTrabajadasStr char* Cantidad de horas trabajadas con las que se inicializará la estructura
 * \return Employee* Puntero a la estructura creada
 *
 */
eAbono* abono_newParametros(int id,int tipo, int idCliente, int importeFinal)
{
    eAbono* pAbono;
    pAbono = abono_new();

    abono_setId(pAbono, idStr);
    abono_setTipo(pAbono, tipo);
    abono_setIdCliente(pAbono, idCliente);
    abono_setImporteFinal(pAbono, importeFinal);

    return pAbano;
}


/** \brief Destructor: libera el espacio en memoria reservado para un empleado y lleva el puntero a NULL
 *
 * \return void
 *
 */
void abono_delete(eAbono* this)
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
int abono_setId(eAbono* this,int id)
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
int abono_getId(eAbono* this,int* id)
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
int abono_setTipo(eAbono* this,int tipo)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->tipo, tipo;
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
int abono_getTipo(eAbono* this,int* tipo)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        *tipo = this->tipo;
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
int abono_setIdCliente(eAbono* this,int idCliente)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->idCliente = idCliente;
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
int abono_getIdCliente(eAbono* this,int* idCliente)
{
    int retorno = -1;
    if(this != NULL && sexo != NULL)
    {
        *idCliente = this->idCliente;
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
int abono_setImporteFinal(eAbono* this,int importeFinal)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->importeFinal = importeFinal;
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
int abono_getImporteFinal(eAbono* this,int* importeFinal)
{
    int retorno = -1;
    if(this != NULL && telefono != NULL)
    {
        *importeFinal = this->importeFinal;
        retorno = 1;
    }
    return retorno;
}

