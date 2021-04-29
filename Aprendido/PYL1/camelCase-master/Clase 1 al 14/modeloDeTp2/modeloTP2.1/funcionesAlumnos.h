#define VACIO -1
#define LLENO 1
#define OCUPADO 0

typedef struct
{
    int legajo;
    char nombre[50];
    float altura;
    int nota;

} eAlumno;


algo que diferancia
int menuOpciones();

void inicializarArrayIlogicamenteNota(eAlumno[], int);
int buscarLibre(eAlumno[], int, int);

void cargarListadoDeAlumnosSecuencialmente(eAlumno[], int);
void cargarAlumnosEspacioLibre(eAlumno[], int);
void ordenarPorNombre(eAlumno[], int);
void alumnoNombreConP(eAlumno[], int);
void alumnosAprobados(eAlumno[], int);
void alumnosNotaMasAlta(eAlumno [], int);
void modificacionDeNotas(eAlumno [], int);
void mostrarListadoDeAlumnos(eAlumno[], int);
void mostrarAlumno(eAlumno);
eAlumno cargarAlumno();
