#include <stdio.h>
#include <stdlib.h>

void insercion(int data[], int len); //para saber los carateres, hacemos un strlen

int main()
{
    int vector[5] = {3,5,1,2,6};
    int i;
    insercion(vector, 5);


    return 0;
}


void insercion(int data[], int len)
{
    int i, j;
    int temp;
    for(i=1; i<len; i++)
    {
        temp=data[i];
        j=i-1;
        while(j>=0 && temp<data[j])
        {
            data[j+1] =data[j];
            j--;
        }
        data[j+1]=temp;gh //insercion (cambia el valor de temporal (acordate las manitos)
    }
}

//falta hacerel el for con un printf
