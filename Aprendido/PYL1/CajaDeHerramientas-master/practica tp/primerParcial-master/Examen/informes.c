#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "cliente.h"
#include "venta.h"
/**
* \brief Se utiliza esta funcion para mostrar el cliente con mas ventas(a cobrar o cobradas)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \param estado Se introduce 1 para evaluar las ventas "A Cobrar" o 2 para las ventas "cobradas"
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_clienteConMasVentasPorEstado(  void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes,
                                            int estado)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int arrayCantidadVentasPorCliente[lenClientes];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadVentas = 0;
    int contadorDeVentasCliente;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)

    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeVentasCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if( venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL &&
                        arrayVentas[j].estado == estado)
                    {
                        contadorDeVentasCliente++;
                    }
                }
                arrayCantidadVentasPorCliente[i] = contadorDeVentasCliente;
            }
            if(!arrayClientes[i].isEmpty && arrayCantidadVentasPorCliente[i] > mayorCantidadVentas)
            {
                mayorCantidadVentas = arrayCantidadVentasPorCliente[i];
            }
        }
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty && mayorCantidadVentas == arrayCantidadVentasPorCliente[i])
            {
                cliente_mostrar(&arrayClientes[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para mostrar el cliente con mas ventas(a cobrar y cobradas)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_clienteConMasVentas(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int arrayCantidadVentasPorCliente[lenClientes];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadVentas = 0;
    int contadorDeVentasCliente;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeVentasCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if(venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL)
                    {
                        contadorDeVentasCliente++;
                    }
                }
                arrayCantidadVentasPorCliente[i] = contadorDeVentasCliente;
            }
            if(!arrayClientes[i].isEmpty && arrayCantidadVentasPorCliente[i] > mayorCantidadVentas)
            {
                mayorCantidadVentas = arrayCantidadVentasPorCliente[i];
            }
        }
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty && mayorCantidadVentas == arrayCantidadVentasPorCliente[i])
            {
                cliente_mostrar(&arrayClientes[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para mostrar el cliente con mas afiches a cobrar
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_clienteConMasAfichesACobrar(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int arrayCantidadAfichesPorCliente[lenClientes];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadAfiches = 0;
    int contadorDeAfichesCliente;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeAfichesCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if( venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL &&
                        arrayVentas[i].estado == A_COBRAR)
                    {
                        contadorDeAfichesCliente+=arrayVentas[j].cantidadAfiches;
                    }
                }
                arrayCantidadAfichesPorCliente[i] = contadorDeAfichesCliente;
            }
            if(!arrayClientes[i].isEmpty && arrayCantidadAfichesPorCliente[i] > mayorCantidadAfiches)
            {
                mayorCantidadAfiches = arrayCantidadAfichesPorCliente[i];
            }
        }
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty && mayorCantidadAfiches == arrayCantidadAfichesPorCliente[i])
            {
                cliente_mostrar(&arrayClientes[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para mostrar el cliente con mas afiches (a cobrar y cobrados)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_clienteConMasAfiches(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int arrayCantidadAfichesPorCliente[lenClientes];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadAfiches = 0;
    int contadorDeAfichesCliente;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeAfichesCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if( venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL)
                    {
                        contadorDeAfichesCliente+=arrayVentas[j].cantidadAfiches;
                    }
                }
                arrayCantidadAfichesPorCliente[i] = contadorDeAfichesCliente;
            }
            if(!arrayClientes[i].isEmpty && arrayCantidadAfichesPorCliente[i] > mayorCantidadAfiches)
            {
                mayorCantidadAfiches = arrayCantidadAfichesPorCliente[i];
            }
        }
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty && mayorCantidadAfiches == arrayCantidadAfichesPorCliente[i])
            {
                cliente_mostrar(&arrayClientes[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para mostrar la zona con menos afiches(a cobrar y cobradas)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos,-2 si se produjo un error con las zonas ,si no el retorno es -1.
*/
int informes_zonaConMenosAfiches(void* arrayVentasVoid, int lenVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    int j;
    int menorCantidadDeAfiches;
    int contadorDeAfichesPorZona;
    int zonaConMasAfiches;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        retorno = 0;
        for(i=CABA; i <= ZONA_OESTE; i++)
        {
            contadorDeAfichesPorZona = 0;
            for(j=0; j < lenVentas; j++)
            {
                if(!arrayVentas[j].isEmpty && arrayVentas[j].zona == i)
                {
                    contadorDeAfichesPorZona+=arrayVentas[j].cantidadAfiches;
                }
            }
            if(i == 1)
            {
                menorCantidadDeAfiches = contadorDeAfichesPorZona;
                zonaConMasAfiches = i;
            }
            else if(contadorDeAfichesPorZona < menorCantidadDeAfiches)
            {
                menorCantidadDeAfiches = contadorDeAfichesPorZona;
                zonaConMasAfiches = i;
            }
        }
        if(zonaConMasAfiches == CABA)
        {
            printf("Zona: CABA\n");
        }
        else if(zonaConMasAfiches == ZONA_SUR)
        {
            printf("Zona: Zona Sur\n");
        }
        else if(zonaConMasAfiches == ZONA_OESTE)
        {
            printf("Zona: Zona Oeste\n");
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para mostrar la cantidad de clientes con menos afiches que el numero indicado
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \param cantidadAfiches Es el numero sobre el que se evalua si el cliente tiene menos de esos afiches
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_clientesConMenosDeTantosAfiches(   void* arrayVentasVoid, int lenVentas,
                                                void* arrayClientesVoid, int lenClientes, int cantidadAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno=-1;
    int i;
    int j;
    int contadorDeAfichesCliente;
    int contadorClientesConMenosDeTantosAfiches = 0;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeAfichesCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if( venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL)
                    {
                        contadorDeAfichesCliente+=arrayVentas[j].cantidadAfiches;
                    }
                }
                if(contadorDeAfichesCliente < cantidadAfiches)
                {
                    contadorClientesConMenosDeTantosAfiches++;
                }
            }
        }
        printf("La cantidad de clientes con menos de %d afiches es %d\n" ,cantidadAfiches, contadorClientesConMenosDeTantosAfiches);
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para mostrar la cantidad de afiches por cada zona
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos,si no el retorno es -1.
*/
int informes_cantidadAfichesPorZona(void* arrayVentasVoid, int lenVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    int j;
    int contadorDeAfichesPorZona;
    int cantidadDeAfichesCaba;
    int cantidadDeAfichesZonaSur;
    int cantidadDeAfichesZonaOeste;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=CABA; i <= ZONA_OESTE; i++)
        {
            contadorDeAfichesPorZona = 0;
            for(j=0; j < lenVentas; j++)
            {
                if(!arrayVentas[j].isEmpty && arrayVentas[j].zona == i)
                {
                    contadorDeAfichesPorZona+=arrayVentas[j].cantidadAfiches;
                }
            }
            if(i == 1)
            {
                cantidadDeAfichesCaba = contadorDeAfichesPorZona;
            }
            else if(i == 2)
            {
                cantidadDeAfichesZonaSur = contadorDeAfichesPorZona;
            }
            else
            {
                cantidadDeAfichesZonaOeste = contadorDeAfichesPorZona;
            }
        }
        printf( "Afiches CABA: %d\nAfiches Zona Sur: %d\nAfiches Zona Oeste: %d\n", cantidadDeAfichesCaba,
                cantidadDeAfichesZonaSur, cantidadDeAfichesZonaOeste);
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para ordenar ventas por zona
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos,si no el retorno es -1.
*/
int informes_listaDeVentasPorZona(void* arrayVentasVoid, int lenVentas)
{
    Venta auxiliar;
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    int j;
    if(arrayVentas != NULL && lenVentas > 0 )
    {
        for(i=1; i < lenVentas; i++)
        {
            auxiliar = arrayVentas[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && arrayVentas[j].zona > auxiliar.zona)
                {
                    arrayVentas[j + 1] = arrayVentas[j];
                    j--;
                }
                arrayVentas[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para obtener la cantidad total de afiches
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param cantidadTotalAfiches Se retorna el total con paso por referencia
* \return El retorno es 0 si se mostraron los datos,si no el retorno es -1.
*/
int informes_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalAfiches = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalAfiches+=arrayVentas[i].cantidadAfiches;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para obtener la cantidad de clientes
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \param cantidadTotalClientes Se retorna el total con paso por referencia
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_cantidadTotalClientes(void* arrayClientesVoid, int lenClientes, int *cantidadTotalClientes)
{
    int retorno = -1;
    int i;
    Cliente* arrayClientes = arrayClientesVoid;
    if(arrayClientes != NULL && lenClientes > 0)
    {
        *cantidadTotalClientes = 0;
        for(i=0;i<lenClientes;i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                *cantidadTotalClientes+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Se utiliza esta funcion para obtener el promedio de afiches por clientes
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param arrayClientes Es el array que se recorre
* \param lenClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos,si no el retorno es -1.
*/
int informes_cantidadAfichesPorCliente(void* arrayVentasVoid, int lenVentas, void* arrayClientesVoid, int lenClientes)
{
    int retorno = -1;
    int cantidadAfiches;
    int cantidadClientes;
    int promedio;
    Cliente* arrayClientes = arrayClientesVoid;
    Venta* arrayVentas = arrayVentasVoid;
    if( arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0 &&
        !informes_cantidadTotalDeAfiches(arrayVentas,lenVentas, &cantidadAfiches) &&
        !informes_cantidadTotalClientes(arrayClientes,lenClientes, &cantidadClientes))
    {
        promedio = cantidadAfiches/ cantidadClientes;
        printf("El promedio(afiches/clientes) es %d\n", promedio);
        retorno = 0;
    }
    return retorno;
}
/*
static int comparacionNombreApellido(Cliente* arrayUno, Cliente* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL && !arrayUno->isEmpty && !arrayDos->isEmpty)
    {
        if(strcmp(arrayUno->apellido, arrayDos->apellido)> 0 ||
        (strcmp(arrayUno->apellido, arrayDos->apellido)== 0 && strcmp(arrayUno->nombre, arrayDos->nombre) > 0))
        {
            retorno = 0;
        }
    }
    return retorno;
}
int informar_sortClientePorApellidoNombre(void* arrayClientesVoid, int lenClientes)
{
    Cliente auxiliar;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno=-1;
    int i;
    int j;
    if(arrayClientes != NULL && lenClientes > 0 )
    {
        for(i=1; i < lenClientes; i++)
        {
            auxiliar = arrayClientes[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && !comparacionNombreApellido(&arrayClientes[j], &auxiliar))
                {
                    arrayClientes[j + 1] = arrayClientes[j];
                    j--;
                }
                arrayClientes[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_sortClientePorCuit(void* arrayClientesVoid, int lenClientes)
{
    Cliente auxiliar;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno=-1;
    int i;
    int j;
    if(arrayClientes != NULL && lenClientes > 0 )
    {
        for(i=1; i < lenClientes; i++)
        {
            auxiliar = arrayClientes[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && strcmp(arrayClientes[j].cuit, auxiliar.cuit) > 0)
                {
                    arrayClientes[j + 1] = arrayClientes[j];
                    j--;
                }
                arrayClientes[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_ventasMayorMenorAfichesNumero(void *arrayVentasVoid, int lenVentas, int *cantidadVentas,int mayorMenor, int numeroAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0; i < lenVentas; i++)
        {
            if(mayorMenor == 0 && !arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches > numeroAfiches)
            {
                venta_mostrar(&(arrayVentas[i]), 1);
                *cantidadVentas+=1;
            }
            else if(mayorMenor == 1 && !arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches < numeroAfiches)
            {
                venta_mostrar(&(arrayVentas[i]), 1);
                *cantidadVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalAfiches = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalAfiches+=arrayVentas[i].cantidadAfiches;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_cantidadTotalDeVentas(void* arrayVentasVoid, int lenVentas, int *cantidadTotalVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalVentas = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_promedioAfichesPorVenta(void* arrayVentasVoid, int lenVentas, float *promedio)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int cantidadTotalAfiches;
    int cantidadTotalVentas;
    if( arrayVentas != NULL && lenVentas > 0 &&
        !informar_cantidadTotalDeAfiches(arrayVentas, lenVentas, &cantidadTotalAfiches) &&
        !informar_cantidadTotalDeVentas(arrayVentas, lenVentas, &cantidadTotalVentas))
    {
        *promedio = (float)cantidadTotalAfiches/cantidadTotalVentas;
        retorno = 0;
    }
    return retorno;
}
int informar_ventasSuperaOrNoPromedioAfiches(void* arrayVentasVoid,int lenVentas,int *cantidadVentas,int SuperaOrNo)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    float promedio;
    if( arrayVentas != NULL && lenVentas > 0 &&
        !informar_promedioAfichesPorVenta(arrayVentas, lenVentas, &promedio) &&
        !informar_ventasMayorMenorAfichesNumero(arrayVentas, lenVentas, cantidadVentas, SuperaOrNo, promedio))
    {
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorEstado(void* arrayVentasVoid, int len, int estado)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].estado == estado)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches, arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorZona(void* arrayVentasVoid, int len, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches,
                arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorEstadoAndZona(void* arrayVentasVoid, int len, int estado ,int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona && arrayVentas[i].estado == estado)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches,
                arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_ventaConMasAfiches(void* arrayVentasVoid, int lenVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    int mayorCantidadAfiches;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        mayorCantidadAfiches = arrayVentas[0].cantidadAfiches;
        for(i=1; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches > mayorCantidadAfiches)
            {
                mayorCantidadAfiches = arrayVentas[i].cantidadAfiches;
            }
        }
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty && mayorCantidadAfiches == arrayVentas[i].cantidadAfiches)
            {
                venta_mostrar(&arrayVentas[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarClientesPorZona(void* arrayClientesVoid, int lenClientes, void* arrayVentasVoid, int lenVentas, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0;i<lenClientes;i++)
        {
            if(!arrayClientes[i].isEmpty && venta_getByIdClienteAndZona(arrayVentas,lenVentas,arrayClientes[i].idCliente, zona)!=NULL)
            {
                printf("\nNombre: %s\nApellido: %s\nCuit: %s\nID: %d\n\n",
                arrayClientes[i].nombre, arrayClientes[i].apellido, arrayClientes[i].cuit, arrayClientes[i].idCliente);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_afichesPorZona(void* arrayVentasVoid, int lenVentas, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    int cantidadAfiches = 0;
    if(arrayVentas != NULL && lenVentas > 0 && zona > 0 && zona <=3)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona)
            {
                cantidadAfiches+=arrayVentas[i].cantidadAfiches;
            }
        }
        printf("La cantidad de afiches es %d\n", cantidadAfiches);
        retorno = 0;
    }
    return retorno;
}*/
