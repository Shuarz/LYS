#include <stdio.h>
#include <stdlib.h>

int main()
{
    do
    {
        printf("a. alta de alumno\n o. ordenar lista de alumnos\n m. mostrar listado\ s. salir");
        printf("ingrese una opcion");
        opcion = getche(); //guardo la funcion opcion y muestra lo que ingreso

        switch(opcion)
        {
        case 'a':
            cargarListadoDeAlumnos(listadoMain, A);
            break;
        case 'o':
            ordenarListadoDeAlumnos(listadoMain, A);
            break;
        case 'm':
            mostrarListadoDeAlumnos(listadoMain, A);
            break;


        }

    }while(opcion!='s')

    return 0;
}
