#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "parser.h"
#include "utn.h"

/** \brief Alta de empleados
 *
 * \param listaEmpleados Es el LinkedList donde se agregara el empleado
 * \return Retorna 0 si se logra hacer el alta, sino retorna -1
 *
 */
int controller_agregarEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int sueldo;
    int horasTrabajadas;
    char nombre[64];
    if(!utn_getNumero(&sueldo,"Ingrese el sueldo: ","Error,reingrese el sueldo: ",0,99999,2)&&
    !utn_getNumero(&horasTrabajadas,"\nIngrese las horas: ","Error,reingrese las horas: ",0,99999,2)&&
    !utn_getNombre(nombre,64,"\nIngrese el nombre: ","Error,reingrese el nombre: ",2))
    {
        Empleado* empleado = Empleado_new_AI(nombre,horasTrabajadas,sueldo);
        if(empleado != NULL)
        {
            retorno = ll_add(listaEmpleados,empleado);
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param listaEmpleados Es el LinkedList del cual se va a editar un empleado
 * \return Retorna 0 si se logra editar sino retorna -1
 *
 */
int controller_editarEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Empleado* empleado;
    int sueldo;
    int horasTrabajadas;
    char nombre[64];

    if(listaEmpleados != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a modificar: ","\nError,reingrese el id: ",0,99999,2))
        {
            for(i = 0;i< ll_len(listaEmpleados);i++)
            {
               empleado = ll_get(listaEmpleados,i);
               Empleado_getId(empleado,&idAux);
               if(idAux == id)
               {
                    if(!utn_getNumero(&sueldo,"Ingrese el nuevo sueldo: ","Error",0,99999,2)&&
                    !utn_getNumero(&horasTrabajadas,"Ingrese las nuevas horas: ","Error",0,99999,2)&&
                    !utn_getNombre(nombre,64,"Ingrese el nuevo nombre: ","Error",2))
                    {
                        if(
                          !Empleado_setNombre(empleado, nombre)&&
                          !Empleado_setSueldo(empleado, sueldo)&&
                          !Empleado_setHorasTrabajadas(empleado, horasTrabajadas))
                          {
                            retorno = 0;
                            break;
                          }

                    }
                    else{
                        break;
                    }
               }
            }
        }

    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param listaEmpleados Es la LinkedList de empleados
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 *
 */
int controller_borrarEmpleado(LinkedList* listaEmpleados,LinkedList* listaEmpleadosBorrados)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Empleado* empleado;
    Empleado* empleadoBorrado;

    if(listaEmpleados != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a borrar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(listaEmpleados);i++)
            {
               empleado = ll_get(listaEmpleados,i);
               Empleado_getId(empleado,&idAux);

               if(idAux == id)
               {
                    //Empleado_delete(empleado);
                    empleadoBorrado = ll_pop(listaEmpleados,i);
                    ll_add(listaEmpleadosBorrados,empleadoBorrado);
                    printf("\nEl empleado que se acaba de borrar: \n");
                    Empleado_mostrar(empleado);
                    retorno = 0;
                    break;
               }

            }
        }

    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param listaEmpleados Es la LinkedList del cual se desea listar los empleados
 * \return retorna 0 si la LinkedList es diferente a NULL sino retorna -1
 *
 */
int controller_ListarEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Empleado* auxPunteroEmpleado;

    if(listaEmpleados != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(listaEmpleados);i++)
        {
            auxPunteroEmpleado = ll_get(listaEmpleados,i);
            Empleado_getNombre(auxPunteroEmpleado,nombre);
            Empleado_getId(auxPunteroEmpleado,&id);
            Empleado_getSueldo(auxPunteroEmpleado,&sueldo);
            Empleado_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nEl nombre del empleado es: %s",nombre);
            printf("\nEl id del empleado es: %d",id);
            printf("\nEl sueldo del empleado es: %d",sueldo);
            printf("\nLas horas trabajadas del empleado son: %d",horasTrabajadas);
            printf("\n\n");

        }
    }
    return retorno;
}

/** \brief Ordenar empleados por criterio
 *
 * \param listaEmpleados Es la LinkedList que se desea ordenar
 * \return retorna 0 si se logra ordenar sino retorna -1
 *
 */
int controller_ordenarEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;

    if(listaEmpleados != NULL)
    {
        if(!ll_sort(listaEmpleados,Empleado_criterioSortNombre,1))
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Borra todos los empleados de la lista
 * \param listaEmpleados Es la LinkedList de empleados a borrar
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 */

int controller_borrarTodosLosEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;
    if(listaEmpleados != NULL && listaEmpleados->size > 0)
    {
        if(!ll_clear(listaEmpleados))
        {
            printf("\nSe borraron todos los empleados de la lista con existo!");
            retorno = 0;
        }
    }
    else
    {
        printf("Error,la lista no contiene empleado/s a borrar\n");
    }
    return retorno;
}

/** \brief Borra todos los empleados que fueron dados de baja de la lista de empleados borrados y la lista
 * \param listaEmpleadosBorrados Es la LinkedList de empleados a borrar
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 */

int controller_borrarTodaLaLista(LinkedList* listaEmpleadosBorrados)
{
    int retorno = -1;
    if(listaEmpleadosBorrados != NULL)
    {
        if(!ll_deleteLinkedList(listaEmpleadosBorrados))
        {
            printf("\nSe borro la lista con existo!");
            retorno = 0;
        }
    }
    else
    {
        printf("No existe la lista a borrar!\n");
    }
    return retorno;
}

/** \brief Clona lista de empleados
 * \param listaEmpleados LinkedList* lista de empleados que se va a clonar
 * \return listaNuevaDeEmpleados si se pudo clonar y [NULL] si hubo algun error
 */

LinkedList* controller_clonarLista(LinkedList* listaEmpleados)
{
    LinkedList* retornoAux = NULL;
    LinkedList* listaNuevaDeEmpleados = NULL;
    if(listaEmpleados != NULL && listaEmpleados -> size >= 0)
    {
        listaNuevaDeEmpleados = ll_clone(listaEmpleados);
        if(ll_containsAll(listaNuevaDeEmpleados,listaEmpleados))
        {
            printf("\nSe clono la lista con existo!");
            retornoAux = listaNuevaDeEmpleados;
        }
    }
    return retornoAux;
}

/** \brief Verifica si existe un empleado en la lista a partir del id que se ingresa
 * \param listaEmpleados LinkedList* lista de empleados en la que se va a buscar el mismo
 * \return Retorna 0 si se logra realizar la busqueda, sino retorna -1
 */

int controller_existeEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int id;
    if(listaEmpleados != NULL && listaEmpleados -> size > 0)
    {
        utn_getNumero(&id,"Ingrese el id del empleado a buscar.. ","Error! ",0,10000,2);
        pEmpleado = Empleado_getById(listaEmpleados,id);

        if(ll_contains(listaEmpleados,pEmpleado))
        {
            printf("\nEl empleado se encuentra en la lista");
            printf("\nID: %d",pEmpleado->id);
            printf("\nNombre: %s",pEmpleado->nombre);
            printf("\nHoras-Trabajadas: %d",pEmpleado->horasTrabajadas);
            printf("\nSueldo: %d",pEmpleado->sueldo);
            retorno = 0;
        }
        else if(ll_contains(listaEmpleados,pEmpleado)==0)
        {
            printf("El empleado no se encuentra en la lista");
        }
    }
    else
    {
        printf("No hay empleado a buscar\n");
    }
    return retorno;
}

/** \brief Funcion que reingresa, un empleado dado de baja, a la lista
 * \param listaEmpleados LinkedList* lista de empleados en donde se va a realizar el push del empleado dado de baja
 * \param listaEmpleadosBorrados LinkedList* lista de empleados desde donde se va a quitar el empleado de baja para hacer el push
 * \return [0] si se pudo hacer el push y [-1] si hubo algun error
 */

int controller_reingresarEmpleado(LinkedList* listaEmpleados,LinkedList* listaEmpleadosBorrados)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Empleado* empleado;
    Empleado* empleadoAnterior;
    int indexEmpleadoAnterior;

    if(listaEmpleadosBorrados != NULL && listaEmpleados != NULL)
    {
        controller_ListarEmpleados(listaEmpleadosBorrados);
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a reingresar: ","\nError,reingrese el id: ",0,99999,2))
        {
            for(i = 0;i< ll_len(listaEmpleadosBorrados);i++)
            {
               empleado = ll_get(listaEmpleadosBorrados,i);
               Empleado_getId(empleado,&idAux);

               if(idAux == id)
               {
                    empleadoAnterior = Empleado_getById(listaEmpleados,id-1);
                    indexEmpleadoAnterior = ll_indexOf(listaEmpleados,empleadoAnterior);
                    ll_push(listaEmpleados,indexEmpleadoAnterior +1 ,empleado);
                    printf("\nEl empleado que se acaba de reingresar: \n");
                    Empleado_mostrar(empleado);
                    ll_remove(listaEmpleadosBorrados,i);
                    retorno = 0;
                    break;
               }

            }
        }

    }
    return retorno;
}

/** \brief Funcion que permite generar una sub-lista segun el id seleccionado por el usuario
 * \param listaEmpleados LinkedList* desde la cual se va a generar la sub-lista
 * \return [0] Exito y [-1] Error
 */

LinkedList* controller_subLista(LinkedList* listaEmpleados)
{
    LinkedList* retornoAux = NULL;
    LinkedList* nuevaSubLista = NULL;
    int i,j;
    int idComienzo,idAuxComienzo;
    int idFinal,idAuxFinal;
    int indexEmpleadoComienzo;
    int indexEmpleadoFinal;
    Empleado* empleadoComiezo;
    Empleado* empleadoFinal;
    if(listaEmpleados != NULL && listaEmpleados -> size > 0)
    {
        if(!utn_getNumero(&idComienzo,"Ingrese el ID del empleado donde quiere empezar a copiar: ","\nError,reingrese el id: ",0,99999,2))
        {
            for(i = 0;i< ll_len(listaEmpleados);i++)
            {
               empleadoComiezo = ll_get(listaEmpleados,i);
               Empleado_getId(empleadoComiezo,&idAuxComienzo);
               if(idAuxComienzo == idComienzo)
               {
                   indexEmpleadoComienzo = ll_indexOf(listaEmpleados,empleadoComiezo);
                   break;
               }
            }
        }
        if(!utn_getNumero(&idFinal,"Ingrese el ID del empleado donde quiere terminar de copiar: ","Error",0,99999,2))
        {
           for(j = 0;i< ll_len(listaEmpleados);j++)
            {
               empleadoFinal = ll_get(listaEmpleados,j);
               Empleado_getId(empleadoFinal,&idAuxFinal);
               if(idAuxFinal == idFinal)
               {
                   indexEmpleadoFinal = ll_indexOf(listaEmpleados,empleadoFinal);
                   break;
               }
            }
        }
        nuevaSubLista = ll_subList(listaEmpleados,indexEmpleadoComienzo,indexEmpleadoFinal + 1);
        printf("\nSe subdividio la lista con existo!\n");
        retornoAux = nuevaSubLista;
    }
    return retornoAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */

int controller_loadFromText(char* path , LinkedList* listaEmpleados)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,listaEmpleados))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista que se va a guardar
 * \return [0] Exito y [-1] Error
 */

int controller_saveAsText(char* path , LinkedList* listaEmpleados)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,listaEmpleados))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}
