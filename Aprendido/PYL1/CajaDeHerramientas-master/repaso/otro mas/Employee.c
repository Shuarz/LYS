#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Constructor del empleado.
 *
 * \param void
 * \return Employee* Retorna un puntero del empleado o NULL.
 *
 */
Employee* employee_new(void)
{
    Employee* pEmployee = NULL;
    pEmployee = (Employee *) malloc(sizeof(Employee));
    return pEmployee;
}

/** \brief Constructor parametrizado del empleado.
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* Retorna un puntero del empleado con los datos cargados o NULL.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee = NULL;
    int id;
    int horasTrabajadas;
    int sueldo;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        pEmployee = employee_new();
        if(pEmployee != NULL)
        {
            id = atoi(idStr);
            horasTrabajadas = atoi(horasTrabajadasStr);
            sueldo = atoi(sueldoStr);
            employee_setId(pEmployee, id);
            employee_setNombre(pEmployee, nombreStr);
            employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
            employee_setSueldo(pEmployee, sueldo);
        }

    }
    return pEmployee;
}

/** \brief Elimina un empleado de la memoria.
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief  Establece el id de un empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_setId(Employee* this,int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 0;
    }
    return 1;
}

/** \brief Devuelve el id de un empleado.
 *
 * \param this Employee*
 * \param id int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_getId(Employee* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 0;
    }
    return 1;
}

/** \brief Establece el nombre de un empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        return 0;
    }
    return 1;
}

/** \brief Devuelve el nombre de un empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        return 0;
    }
    return 1;
}

/** \brief Establece la cantidad de horas trabajadas de un empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        return 0;
    }
    return 1;
}

/** \brief Devuelve la cantidad de horas trabajadas de un empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }
    return 1;
}

/** \brief Establece el sueldo de un empleado.
 *
 * \param this Employee*
 * \param sueldo int
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    if(this != NULL)
    {
        this->sueldo = sueldo;
        return 0;
    }
    return 1;
}

/** \brief Devuelve el sueldo de un empleado.
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        return 0;
    }
    return 1;
}

/** \brief Imprime un empleado en pantalla.
 *
 * \param this Employee*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int employee_print(Employee* this)
{
    if(this != NULL)
    {
        printf("%5d | %15s | %16d | %6d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        return 0;
    }
    return 1;
}

/** \brief Compara dos empleados segun su id.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int employee_compareId(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        if(pEmployee->id > pEmployeeDos->id)
        {
            retorno = 1;
        } else if(pEmployee->id < pEmployeeDos->id)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

/** \brief Compara dos empleados segun su nombre.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int employee_compareNombre(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        retorno = strcmp(pEmployee->nombre, pEmployeeDos->nombre);
    }
    return retorno;

}

/** \brief Compara dos empleados segun su cantidad de horas trabajadas.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int employee_compareHorasTrabajadas(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        if(pEmployee->horasTrabajadas > pEmployeeDos->horasTrabajadas)
        {
            retorno = 1;
        } else if(pEmployee->horasTrabajadas < pEmployeeDos->horasTrabajadas)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

/** \brief Compara dos empleados segun su sueldo.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int employee_compareSueldo(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        if(pEmployee->sueldo > pEmployeeDos->sueldo)
        {
            retorno = 1;
        } else if(pEmployee->sueldo < pEmployeeDos->sueldo)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

int employe_filterNombre(void* this)
{
    int retorno = -1;
    Employee* pEmployee = NULL;
    if(this != NULL)
    {
        pEmployee = (Employee *)this;
        if(pEmployee->nombre[0] == 'C')
        {
            retorno = 1;
        }else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int employee_filterHorasTrabajadas(void* this)
{
    int retorno = -1;
    Employee* pEmployee = NULL;
    if(this != NULL)
    {
        pEmployee = (Employee *)this;
        if(pEmployee->horasTrabajadas >= 100)
        {
            retorno = 1;
        }else
        {
            retorno = 0;
        }
    }
    return retorno;
}
