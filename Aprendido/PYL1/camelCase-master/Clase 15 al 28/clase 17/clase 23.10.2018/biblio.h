//////STRUCTS//////
typedef struct
{
    int id;
    char nombre[20];
    int edad;
}sPersona;
///////////////////



///////////PROTOTYPES/////////////////


//Perdir la direccion de memoria
sPersona* nuevaPersona();
void mostrarPersona(sPersona*);
sPersona* initPersona(int,char*,int);

///SETER
int sPersona_setId(sPersona*,int);
int sPersona_setName(sPersona* ,char* );
int sPersona_setAge(sPersona*,int);

///GETER
int sPersona_getId(sPersona*);
char* sPersona_getName(sPersona*);
int sPersona_getAge(sPersona*);


//////////////////////////////////////
