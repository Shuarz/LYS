#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char description[21];
}Sector;

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;
}Employee;

/** \brief Carga el array con 7 empleados
 *
 * \param arrayEmployees Employee* puntero a array de employees
 * \return void
 */
void hardcodeoEmployees(Employee* arrayEmployees);

/** \brief Carga el array con 5 sectores
 *
 * \param arrayEmployees Employee* puntero a array de employees
 * \return void
 */
void hardcodeoSectors(Sector* arraySectors);

/** \brief Para indicar que todas las posiciones en el array están vacías, esta función pone la bandera (isEmpty)
 *         en VACÍO en todas las posiciónes del array
 * \param arrayEmployees Employee* puntero a array de employees
 * \param lengthArray int largo del arrays
 * \return int retorna (-1) si da error [largo invalido o puntero NULL ] - (0) si esta todo Ok
 *
 */
int initEmployees(Employee* arrayEmployees, int lengthArray);

/** \brief chequea si el array fue inicializado
 *
 * \param arrayEmployees employee* puntero a array de punteros
 * \param lengthArray int largo del array
 * \return int retorna (-1)  si el array no fue inicializado - (0) si fue inicializado
 *
 */
int checkEmptyArray(Employee* arrayEmployees, int lengthArray);

/** \brief encuentra el primer id disponible
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param lengthArray int largo del array
 * \return int Retorna (-1)  si el array esta lleno - (i+1) el siguiente if libre
 *
 */
int getNextId(Employee* arrayEmployees,int lengthArray);

/** \brief encuentra la primera posicion de el array con la bandera(isEmpty)
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param lengthArray int largo del Array
 * \return Retorna la indexada posicion de employee o (-1) si [da largo invalido o recibe un puntero a NULL
 * o employee no enontrado]
 *
 */
int findFreePlace(Employee* arrayEmployees, int lengthArray);

/** \brief Opcion menu
 *
 * \return opcion int el numero elegido de opcion
 *
 */

int selectSector(Sector* sectors,int lengthSector);

/** \brief registra al nuevo empleado con las variables validadas tomadas de paramatros
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param lengthArray int largo del array
 * \param auxId int auxiliar id del empleado a cargar
 * \param auxName[] char nombre auxiiar del empleado a cargar
 * \param auxLastName[] char apellido auxuliar del empleado a cargar
 * \param auxSalary float auxuliar salario del empleado a cargar
 * \param auxSector int sector auxiliar del empleado a cargar
 * \param index int posicion  auxuliar del empleado a cargar
 * \return int Retorna (-1) si hay error [largo invalido o puntero NULL] - (0) si esta todo Ok
 *
 */
int addEmployee(Employee* arrayEmployees, int lengthArray, int auxId, char auxName[], char auxLastName[], float auxSalary, int auxSector, int index);

/** \brief encuentra a un empleado por id
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param lengthArray int largo del array
 * \param id int id del empleado a buscar
 * \return Retorna la posicion indexada de employee o (-1) si [el largo es invalido o recibe un puntero NULL
 * o employee no encontrado]
 *
 */
int findEmployeeById(Employee* arrayEmployees, int lengthArray, int id);

/** \brief muestra empleado por id
 *
 * \param arrayEmployees Employee* puntero a array de emplados
 * \param lengthArray int largo del array
 * \param sectors Sector* punero a array de sectores
 * \param lengthSector int largo del array
 * \param auxId int Id del empleado a buscar
 * \return void
 *
 */
void printEmployeeById(Employee* arrayEmployees, int lengthArray, Sector* arraySectors, int lengthSectors, int auxId);

/** \brief muestra a un empleado
 *
 * \param arrayEmployees Employee* punetero a array de empleados
 * \param sectors Sector* punetro a array de sectores
 * \param lengthSector int largo del array
 * \param index int posicion del empleado a mostrar
 * \return void
 */
void printEmployee(Employee* arrayEmployees, Sector* arraySectors, int lengthSectors, int index); //Imprime un empleado

/** \brief muestra a todos los empleados
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param lengthArray int largo del array
 * \param sectors Sector* puntero a array de sectores
 * \param lengthSector int largo del array
 * \return void
 *
 */
void printEmployees(Employee* arrayEmployees, int lengthArray, Sector* arraySectors, int lengthSectors);//Imprime muchos empleados

/** \brief actualiza la discripcion del sector
 *
 * \param sectors Sector* puntero a array de sectores
 * \param lengthSector int largo del array
 * \param idSector int el id de la descripcion a buscar
 * \param cadena[] char donde la descripcion va a ser actualizada
 * \return void
 *
 */
void uploadDescription(Sector* sectors, int lengthSector, int idSector, char cadena[]);

/** \brief modifica los datos del empleado
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param sectors Sector* puntero a array de sectores
 * \param lengthArray int largo del array
 * \param lengthSectors int laro del array
 * \param id el id del empleado a modificar
 * \param index int la posicion del empleado a modificar
 * \return Retorna employee la posicion indexada o (-1) si [el largo es invalido or el puntero recibido es NULL
 * or employee no encontrado]
 *
 */
int modifyEmployee(Employee* arrayEmployees, Sector arraySectors[], int lengthArray, int lengthSectors, int id, int index);

/** \brief elimina a emplouee por id (pone en isEmpty en bandera 2 (delete))
 *
 * \param arrayEmployees Employee* puntero a array de empleados
 * \param arraySectors[] Sector* puntero a array de sectores
 * \param lengthArray int largo de array
 * \param lengthSectors int largo del array
 * \param index int la posicion del empleado
 * \return int Retorna (-1) si da error [el largo es invalido o el puntero da NULL o no puede encontrar al empleado
 * ] - (0) si esta todo Ok
 *
 */
int removeEmployee(Employee* arrayEmployees, Sector* arraySectors, int lengthArray, int lengthSectors, int index);

/** \brief ordena el array de empleados (1) orden ascendete y 0 descenciente
 *
 * \param arrayEmployees Employee*  puntero a array de empleados
 * \param lengthArray int largo del array
 * \param orden int (1) ascendete - (0) desendiente
 * \return void
 *
 */
void sortEmployees(Employee* arrayEmployees, int lengthArray, int order);

/** \brief agrega un salario al employees salario
 *
 * \param arrayEmpleados Employee* puntero a array de empleados
 * \param lengthArray int largo del array
 * \return float total de salarios
 *
 */
float totalSalaries(Employee* arrayEmpleados, int lengthArray);

/** \brief divide el total de salarios por el numero de empleados activos
 *
 * \param arrayEmployees Employee* puneto a array de empleados
 * \param lengthArray int largo del array
 * \param totalSalaries float el total de los salarios
 * \return float el salario promedio
 *
 */
float averageSalary(Employee* arrayEmployees, int lengthArray, float totalSalaries);

/** \brief agrega el numero de empleados que superan el promedio
 *
 * \param arrayEmployees Employee* punero al array de empleados
 * \param lengthArray int  largo del array
 * \param averageSalary int el proedio salarial
 * \return int numero de empleados que superan el promedio
 *
 */
int employeesSurpassAverage(Employee* arrayEmployees, int lengthArray, int averageSalary);

/** \brief
 *
 * \param arrayEmployees Employee*  puntero a array de empleados
 * \param arraySectors Sector*  puntero a array de sectores
 * \param lengthArray int largo del array
 * \param lengthSectors int lardo del array
 * \return Retorna el indice de employee or (-1) si [el largo es invalido o el puntero recibido es nulo o employee no lo encontro]
 *
 */
int listEmployees(Employee* arrayEmployees, Sector* arraySectors, int lengthArray, int lengthSectors);


#endif // ARRAYEMPLOYEES_H_INCLUDED
