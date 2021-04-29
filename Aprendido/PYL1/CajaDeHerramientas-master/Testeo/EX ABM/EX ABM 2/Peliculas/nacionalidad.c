#include "nacionalidad.h"


int eNacionalidad_hardcode(eNacionalidad listado[], int limite)
{
    int returnValue = -1;
    char nuevoNacionalidades[5][51] = {"Alemania", "Argentina","Marruecos","Japon","Holanda"};

    int idNacionalidad[5] = {107, 108, 109, 110, 111};
    int i;
    if(limite>=5)
    {
        returnValue = 0;
        for(i = 0; i < 5; i++)
        {
            strcpy(listado[i].Descripcion, nuevoNacionalidades[i]);
            listado[i].idNacionalidad = idNacionalidad[i];
            listado[i].estado = OCUPADO;
        }
    }
    return returnValue;
}
/*int eNacionalidad_siguienteId(eNacionalidad listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idNacionalidad == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}*/

int eNacionalidad_initialize(eNacionalidad listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idNacionalidad= 0;
        }
    }
    return retorno;
}

int eNacionalidad_buscarLugarLibre(eNacionalidad listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idNacionalidad>retorno)
                {
                    retorno=listado[i].idNacionalidad;
                }
            }
        }
    }

    return retorno+1;
}

/*int eNacionalidad_buscarPorId(eNacionalidad listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}*/
/*int eNacionalidad_alta(eNacionalidad  listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eNacionalidad_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = eNacionalidad_siguienteId(listado,limite);
            eNacionalidad_ingresarNombre(&listado[indice], listado, limite);
            listado[indice].idNacionalidad = id;
            listado[indice].estado = OCUPADO;
            eNacionalidad_Mostrar(listado[indice], 1);
            retorno = 0;
        }
    }
    return retorno;
}

int eNacionalidad_baja(eNacionalidad listado[],int limite, char mensaje[])
{
    int retorno = -1;
    char buffer[1024];
    int busqueda = -1;
    int listaEstado;

    listaEstado = eNacionalidad_MostrarListado(listado, limite);
    if(listaEstado == 0)
    {
        if(limite > 0 && listado != NULL)
        {
            putLineInString(buffer, 1024, mensaje);
            RemoveSpaces(buffer);
            busqueda = eNacionalidad_buscarPorString(listado,limite,buffer);
            if(busqueda >= 0 && busqueda < limite)
            {
                retorno = busqueda;
            }
            else
            {
                printf("No se encontro el elemento");
            }
        }
    }
    return retorno;
}*/

int eNacionalidad_Mostrar(eNacionalidad estructura, int isAlone)
{
    int retorno = -1;
    if(isAlone == 1)
    {
        printf("%2s %25s\n", "ID", "NACIONALIDAD");
    }
    printf("%2d %25s\n", estructura.idNacionalidad, estructura.Descripcion);
    retorno = 0;
    return retorno;
}

int eNacionalidad_ingresarNombre(eNacionalidad *estructura, eNacionalidad listado[], int limite)
{
    int retorno = -1;
    int alreadyExist;
    int invalido;
    char buffer[1024];
    do
    {
        putLineInString(buffer, TAMNACIONALIDAD, "Ingrese la nacionalidad del director: ");
        RemoveSpaces(buffer);
        toCamelCase(buffer);
        invalido = validateFormatName(buffer,TAMNACIONALIDAD);
        switch(invalido)
        {
        case -1:
            printf("ERROR: la cadena ingresada es muy corta");
            break;
        case -2:
            printf("ERROR: No se permiten numeros para las naciones");
            break;
        case -3:
            printf("ERROR: La nacionalidad debe empezar con una letra");
            break;
        }
        alreadyExist = eNacionalidad_buscarPorString(listado,limite,buffer);
        if(alreadyExist != -1)
        {
            invalido = -1;
            printf("ERROR: esta nacionalidad ya existe.\n");
        }
    }
    while(invalido!=0);

    strcpy(estructura->Descripcion, buffer);

    return retorno;
}

int eNacionalidad_MostrarListado(eNacionalidad listado[], int limite)
{
    int retorno;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(indice = 0; indice < limite; indice++)
        {

            if(listado[indice].estado == OCUPADO)
            {
                if(retorno == -2)
                {
                    printf("%2s %25s\n", "ID", "NACIONALIDAD");
                }
                eNacionalidad_Mostrar(listado[indice], 0);
                retorno = 0;
            }
        }
    }
    if(retorno == -2)
    {
        printf("No hay nacionalidad en la lista...\n");
    }
    return retorno;
}

int eNacionalidad_confirmacion(char mensaje[], char llave)
{
    int retorno = -1;
    int opcion;
    printf("%s", mensaje);
    fflush(stdin);
    opcion = getchar();
    opcion = tolower(opcion);
    llave = tolower(llave);
    if(opcion == llave)
    {
        retorno = 0;
    }
    return retorno;
}

int eNacionalidad_validarListar(eNacionalidad* lista, int limite)
{
    int returnValue = -1;
    int i;
    if(lista != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                returnValue = 0;
                break;
            }
        }
    }


    return returnValue;

}

int eNacionalidad_buscarPorString(eNacionalidad *listado, int limite, char* Descripcion)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && stricmp(Descripcion, listado[i].Descripcion) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;

}

