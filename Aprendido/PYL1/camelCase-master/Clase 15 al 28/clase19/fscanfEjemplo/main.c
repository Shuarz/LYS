#include <stdio.h>
#include <stdlib.h>

int main()
{
   char name[500];
   char lastName[500];
   char id[500];
   char isEmpty[500];

   int cont=1;

   FILE * pFile;

   pFile = fopen ("data.csv", "r");

   while(!feof(pFile))
   {

       if(cont %250 == 0)
       {
           system("pause");
       }
       cont++;



       fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

       printf("%s - %s, %s - %s\n", id, name, lastName, isEmpty);

   }

   fclose(pFile);

   return(0);
}
