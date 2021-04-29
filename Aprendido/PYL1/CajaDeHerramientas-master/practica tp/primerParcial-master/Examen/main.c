#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "venta.h"
#include "cliente.h"
#include "informes.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_VENTAS 1000
int main()
{
    Cliente clientes[CANTIDAD_CLIENTES];
    Venta ventas[CANTIDAD_VENTAS];
    int salidaDelMenu = 0;
    int elegirOpcion;
    cliente_init(clientes, CANTIDAD_CLIENTES);
    venta_init(ventas, CANTIDAD_VENTAS);

    cliente_ingresoForzado(clientes, CANTIDAD_CLIENTES, "Daniel", "Perez", "20-80444555-2");
    cliente_ingresoForzado(clientes, CANTIDAD_CLIENTES, "Ramon", "Alvarez", "20-90444555-3");
    cliente_ingresoForzado(clientes, CANTIDAD_CLIENTES, "Sara", "Alvarez", "20-80444555-4");
    cliente_ingresoForzado(clientes, CANTIDAD_CLIENTES, "Ramon", "Abila", "20-90444555-3");

    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 0, 20, "imagen.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 0, 200, "imagen2.jpg", ZONA_OESTE, COBRADA);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 0, 100, "imagenes.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 0, 100, "imagenes.jpg", ZONA_SUR, COBRADA);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 1, 59, "imagenadafgads.jpg", CABA, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 1, 32, "imagen2.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 1, 21000, "imagen8.jpg", ZONA_SUR, COBRADA);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 1, 500, "imagen8.jpg", CABA, COBRADA);

    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 2, 40, "imagen.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 2, 400, "image.jpg", CABA, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 2, 200, "imagen2.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 3, 120, "imagen8.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 3, 4000, "imagen.jpg", ZONA_OESTE, A_COBRAR);
    venta_ingresoForzado(ventas, CANTIDAD_VENTAS, 3, 400, "imagen.jpg", CABA, A_COBRAR);

    while(salidaDelMenu == 0)
    {
        system("clear");
        printf("1. Alta  cliente\n"
               "2. Modificar cliente\n"
               "3. Baja cliente\n"
               "4. Venta afiches\n"
               "5. Editar Venta\n"
               "6. Cobrar venta\n"
               "7. Imprimir Clientes\n"
               "8-17 Informes\n"
               "18. Salir\n");
        elegirOpcion = 0;
        utn_getEnteroSoloNumeros(&elegirOpcion, 5, "Seleccione...\n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if(cliente_alta(clientes, CANTIDAD_CLIENTES) != 0)
                {
                    printf("No se pudo dar de alta el cliente\n");
                }
                break;
            case 2:
                if(cliente_modificar(clientes, CANTIDAD_CLIENTES, 2) != 0)
                {
                    printf("No se pudo modificar el cliente\n");
                }
                break;
            case 3:
                if(cliente_baja(clientes, CANTIDAD_CLIENTES, ventas, CANTIDAD_VENTAS, 2) != 0)
                {
                    printf("No se pudo dar de baja el cliente\n");
                }
                break;
            case 4:
                if(venta_alta(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES) != 0)
                {
                    printf("No se pudo dar de alta la venta\n");
                }
                break;
            case 5:
                if(venta_modificar(ventas, CANTIDAD_VENTAS, 2) != 0)
                {
                    printf("No se pudo modificar la venta\n");
                }
                break;
            case 6:
                if(venta_cobrar(ventas, CANTIDAD_VENTAS, clientes,CANTIDAD_CLIENTES, 2) != 0)
                {
                    printf("No se pudo cobrar\n");
                }
                break;
            case 7:
                if(cliente_mostrarVentas(clientes, CANTIDAD_CLIENTES, ventas,CANTIDAD_VENTAS) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 8:
                if(informes_clienteConMasVentasPorEstado(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES, A_COBRAR) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 9:
                if(informes_clienteConMasVentasPorEstado(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES, COBRADA) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 10:
                if(informes_clienteConMasVentas(ventas,CANTIDAD_VENTAS,clientes,CANTIDAD_CLIENTES) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 11:
                if(informes_clienteConMasAfichesACobrar(ventas,CANTIDAD_VENTAS,clientes,CANTIDAD_CLIENTES) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 12:
                if(informes_clienteConMasAfiches(ventas,CANTIDAD_VENTAS,clientes,CANTIDAD_CLIENTES) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 13:
                if(informes_zonaConMenosAfiches(ventas, CANTIDAD_VENTAS) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 14:
                if(informes_clientesConMenosDeTantosAfiches(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES, 1000) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 15:
                if(informes_cantidadAfichesPorZona(ventas, CANTIDAD_VENTAS) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 16:
                if(!informes_listaDeVentasPorZona(ventas, CANTIDAD_VENTAS))
                {
                    venta_mostrar(ventas, CANTIDAD_VENTAS);
                }
                break;
            case 17:
                if(informes_cantidadAfichesPorCliente(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES) != 0)
                {
                    printf("No se pudo mostrar la informacion\n");
                }
                break;
            case 18:
                salidaDelMenu = 1;
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("Pulse Enter para continuar\n");
        __fpurge(stdin);
        getchar();
    }
}
