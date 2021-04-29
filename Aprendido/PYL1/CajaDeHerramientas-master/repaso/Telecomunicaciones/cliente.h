#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char sexo[5];
    char numeroTelefono[21];
    int importe;
}eCliente;


eCliente* cliente_new();
eCliente* cliente_newParametros(char* idStr,char* nombre, char* sexo, char* numeroTelefono, char* importeStr);
void cliente_delete(eCliente* this);
int cliente_setId(eCliente* this,int id);
int cliente_getId(eCliente* this,int* id);
int cliente_setNombre(eCliente* this,char* nombre);
int cliente_getNombre(eCliente* this,char* nombre);
int cliente_setSexo(eCliente* this,char* sexo);
int cliente_getSexo(eCliente* this,char* sexo);
int cliente_setTelefono(eCliente* this,char* telefono);
int cliente_getTelefono(eCliente* this,char* telefono);
int cliente_setImporte(eCliente* this,int importe);
int cliente_getImporte(eCliente* this,int* importe);


#endif // CLIENTE_H_INCLUDED
