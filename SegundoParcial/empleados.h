#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "ArrayList.h"
typedef struct
{
int id;
char nombre[20];
char profesion[20];
float sueldo;
int edad;
}eEmpleados;


/** \brief reserva memoria en el heap para la estructura
 *
 * \param
 * \param
 * \return puntero a el espacio en heap
 *
 */

eEmpleados* new_Empleados();


/** \brief setea la edad en la estructura
 *
 * \param la estructura
 * \param la edad
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */

int set_edad(eEmpleados* this, int edad);


/** \brief extrae el valor de edad especifico de la estructura
 *
 * \param la estructura
 * \param
 * \return el valor de edad
 *
 */

int get_edad(eEmpleados* this);


/** \brief guearda un id especifico en la estructura
 *
 * \param la estructura
 * \param el id
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int set_id(eEmpleados* this, int id);


/** \brief extrae un valor de id especifico de la estructura
 *
 * \param la estructura
 * \param
 * \return el id
 *
 */
int get_id(eEmpleados* this);


/** \brief guarda un sueldo especifico en la estructura
 *
 * \param la estructura
 * \param el sueldo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int set_sueldo(eEmpleados* this, float );


/** \brief extrae un valor de sueldo especifico de la estructura
 *
 * \param la estructura
 * \param
 * \return el sueldo
 *
 */
float get_sueldo(eEmpleados* this);


/** \brief guarda un nombre especifico en la estructura
 *
 * \param la estructura
 * \param el nombre
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int set_nombre(eEmpleados* , char* );


/** \brief extrae un nombre especifico de la estructura
 *
 * \param la estructura
 * \param
 * \return el nombre
 *
 */
char* get_nombre(eEmpleados* );


/** \brief guarda una profesion especifica en la estructura
 *
 * \param la profesion
 * \param la estructura
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int set_profesion(eEmpleados* , char* );


/** \brief extrae una profesion especifica de la estructura
 *
 * \param la estructura
 * \param
 * \return la profesion
 *
 */
char* get_profesion (eEmpleados* );


/** \brief muestra los datos de un empleado
 *
 * \param la estructura
 * \param
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int mostrar_Empleadoss (eEmpleados* );


/** \brief compara datos de dos empleados
 *
 * \param el primer empleado
 * \param el segundo empleado
 * \return 0 si son iguales, -1 si el segundo tiene mas prioridad que el primero, 1 si el primero tiene mas prioridad que el segundo
 *
 */
int comparar_Empleadoss(void* , void* );


/** \brief muestra la lista de empleados de un arrayList
 *
 * \param el arrayList
 * \param
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int mostrar_lista_Empleadoss(ArrayList* );


/** \brief extrae los datos de un archivo y los guarda en un arrayList
 *
 * \param el archivo
 * \param el arraylist
 * \param la estructura
 * \param el id
 * \param el nombre
 * \param la edad
 * \param la pprofesion
 * \param el sueldo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int cargar_Archivo(FILE*  ,ArrayList* , eEmpleados* , int , char* , int , char* , float );


/** \brief agrega un empleado nuevo a la lista de empleados
 *
 * \param el archivo
 * \param el arraylist
 * \param la estructura
 * \param el id
 * \param el nombre
 * \param la edad
 * \param la pprofesion
 * \param el sueldo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int agregar_empleados(FILE*  ,ArrayList* , eEmpleados* , int , char* , int , char* , float );


/** \brief crea un archivo con una lista de empleados
 *
 * \param el archivo
 * \param el arrayList
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int crear_pagina(FILE* ,char* ,ArrayList* );


/** \brief carga empleados de la estructura a un arrayList
 *
 * \param el arraylist
 * \param la estructura
 * \param el id
 * \param el nombre
 * \param la edad
 * \param la pprofesion
 * \param el sueldo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int cargar_Empleados(ArrayList* , eEmpleados* , int , char* , int , char* , float );


/** \brief borra un empleado de la lista de empleados
 *
 * \param el archivo
 * \param el arraylist
 * \param la estructura
 * \param el id
 * \param el nombre
 * \param la edad
 * \param la pprofesion
 * \param el sueldo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int borrar_Empleados(FILE*  ,ArrayList* , eEmpleados* , int , char* , int , char* , float );


/** \brief lee un archivo y muestra los datos de los empleados
 *
 * \param el archivo
 * \param el nombre del archivo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int leer_Archivo(FILE* , char* );


/** \brief filtra a los programadores mayores de 30 años
 *
 * \param un empleado del arraylist
 * \param
 * \return 1 si encontro a un empleado que cumpla los requisitos, 0 si no lo hizo
 *
 */
int funcionFilter(void* );


/** \brief guarda los datos de los empleados filtrados en otra lista
 *
 * \param el archivo
 * \param el archivo de empleados filtrados
 * \param el arraylist
 * \param la lista de los empleados filtrados
 * \param la estructura
 * \param el id
 * \param el nombre
 * \param la edad
 * \param la pprofesion
 * \param el sueldo
 * \return 0 si se realizo la operacion, -1 si ocurrio un error
 *
 */
int filtrar_Empleados(FILE*  ,FILE*  ,ArrayList*  ,ArrayList*  , eEmpleados*  , int  , char*  , int  , char*  , float );

#endif
