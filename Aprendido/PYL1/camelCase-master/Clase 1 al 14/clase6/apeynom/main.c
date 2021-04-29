#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //incluir esto para trabajar con mayusculas


int main()
{
    char cadenaUno[20];
    char cadenaDos[20];
    char apelldoYNombre[41]; //es nombre, mas apellido, mas coma, mas el espacio, el enter(\0)
    char buffer[512]; // es una variable que va aguardar cosas
    int i;


    printf("ingrese nombre: ");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>19)
    {
     printf("reingrese nombre: ");
     fflush(stdin);
     gets(buffer);
    }
    strcpy(cadenaUno, buffer); //paso lo que tenia buffer a cadenaUno, porque tenia basura


    printf("ingrese apellido: ");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>19)
    {
     printf("reingrese apellido: ");
     fflush(stdin);
     gets(buffer);
    }
    strcpy(cadenaDos, buffer);

    puts(cadenaUno);
    puts(cadenaDos);

    strcpy(apelldoYNombre, cadenaDos); //copia lo que tiene cadenaDos(apellido) a apellido y nombre
    strcat(apelldoYNombre, ", ");
    strcat(apelldoYNombre, cadenaUno);

    strlwr(apelldoYNombre); //baja todo a minusculas

    apelldoYNombre[0]=toupper(apelldoYNombre[0]); //le digo a toupper que variable subir una matuscula

    for(i=0; i<strlen(apelldoYNombre); i++)
    {
        if(apelldoYNombre[i]==' ') //pregunto por el espacio
        {
            apelldoYNombre[i+1]=toupper(apelldoYNombre[i+1]); //aca hace que en cada espacio, ponga una mayuscula
        }
    }

    puts(apelldoYNombre);


    return 0;
}

//buscarlo con stleng el numero caracter para el limite de los 20 carecteres
