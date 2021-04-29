#define cantidadCartas 49

typedef struct cartas
{
    char palo[50];
    int numero;
    float valor;
}eCarta;

void crearMazo(eCarta arrayDeCartas[]);
void mezclarMazo(eCarta arrayDeCartas[]);
