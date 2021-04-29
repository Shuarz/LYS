#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menuSystem.h"
#include "texto.h"
#include "director.h"

#define OCUPADO 1


#define TAMNOMBRES 50
#define DESHABILITADO -1
#define LIBRE 0
#define TAMNACIONALIDAD 50



typedef struct
{
    int idNacionalidad;
    char Descripcion[TAMNACIONALIDAD];
    int estado;
}eNacionalidad;

int eNacionalidad_hardcode(eNacionalidad[], int);

/** \brief Crea un id para un elemento de una estructura, en base la posicion en el array.
 *
 * \param eDirector[]   el array de estructura.
 * \param int la longitud del array.
 * \return int  ID generado.
 *
 */
int eNacionalidad_siguienteId(eNacionalidad[], int);

/** \brief Inicializa un array de estructura en un valor de estado libre
 *
 * \param eDirector[]   el array de estructura a inicializar
 * \param int   el tamanio del array
 * \return int  devuelve si se pudo hacer la operacion
 *
 */
int eNacionalidad_initialize(eNacionalidad[], int);

/** \brief Busca un elemento en un array de estructura que tenga el campo estado en LIBRE.
 *
 * \param eDirector[] el array de estructuras donde esta el elemento
 * \param int   el tamanio del array
 * \return int  la posicion dentro del array del elemento libre
 *
 */
int eNacionalidad_buscarLugarLibre(eNacionalidad[],int);

/** \brief busca en un array de estructura en base un identificardor
 *
 * \param eDirector[] array de estructura a buscar
 * \param int el tamanio del array
 * \param int  el identificador que se quiere encontrar
 * \return int la posicion del identificador dentro del array(sino devuelve -1 indicando que no existe)
 *
 */
void eNacionalidad_buscarPorId(eNacionalidad[],int, int);

/** \brief Ingresa la informacion para un elemento de un array de estructuras
 *
 * \param eDirector[] el array donde se guardara el elmento
 * \param int  el tamanio del array
 * \return int
 *
 */
int eNacionalidad_alta(eNacionalidad[],int);

/** \brief
 *
 * \param eDirector[]
 * \param int
 * \param char[]
 * \return int
 *
 */
int eNacionalidad_baja(eNacionalidad[],int, char[]);

/** \brief
 *
 * \param eDirector[]
 * \param int
 * \return int
 *
 */
int eNacionalidad_MostrarListado(eNacionalidad[], int);

/** \brief
 *
 * \param eDirector
 * \param int
 * \return int
 *
 */
int eNacionalidad_Mostrar(eNacionalidad, int);

/** \brief
 *
 * \param eDirector*
 * \param int
 * \return int
 *
 */
int eNacionalidad_ingresarNombre(eNacionalidad*, eNacionalidad[], int);


/** \brief
 *
 * \param eDirector*
 * \param char[]
 * \param int
 * \return void
 *
 */
void eNacionalidad_ingresarIdDirector(eNacionalidad*, char[], int);



/** \brief
 *
 * \param char[]
 * \param char
 * \return int
 *
 */
int eNacionalidad_confirmacion(char[], char);

int eNacionaliadad_validarListar(eNacionalidad*, int);

int eNacionalidad_buscarPorString(eNacionalidad*, int, char*);

int eNacionalidad_validarNombreRepetido(eNacionalidad*, int, char*);

