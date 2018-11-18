#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;


/** \brief Menu Opciones donde estaran todas las funciones que el usuario pueda hacer.
 *
 * \param opcion int variable que almacenara el dato que ingrese el usuario.
 * \param mensaje char*
 * \param mensajeErrorUno char*
 * \return opcion int
 */

int emp_menuOpcion_getNumero(int, char*, char*);

/** \brief Busca en la estructura un espacio libre para operar
 *
 * \param empleado eEmpleado
 * \param cantidad int
 * \return retornara (-1) si no hay espacio vacio y (1) si encontro un espacio.
 *
 */

int emp_obtenerEspacioLibre(eEmpleado[], int);

/** \brief Bloquea el acceso si no existe ningun dato cargado en la estructura
 *
 * \param empleado eEmpleado
 * \param cantidad int
 * \return retornara la variable flag (0) si hay espacio vacio y (1) si hay dato cargado.
 *
 */

int emp_bloqueoCargaVacia(eEmpleado[], int);

/** \brief Inicializacion de la estructura empleados, colocando 1 como vacio.
 *
 * \param empleado eEmpleado
 * \param cantidad int
 *
 */

void emp_initEmployees(eEmpleado[], int);

/** \brief Funcion que guardara la informacion del empleado que ingrese el usuario en la estructura.
 *
 * \param empleado eEmpleado
 * \param cantidad int
 *
 */

void emp_addEmployee(eEmpleado[], int);

/** \brief Funcion que permitira editar los datos de un empleado, pidiendole previamente al usuario el ID.
 *
 * \param empleado eEmpleado
 * \param cantidad int
 *
 */

void emp_modifyEmployee(eEmpleado[], int);

/** \brief Funcion que permite la baja de un empleado, pidiendole previamente al usuario el ID. (volviendo a colocar 1 en isEmpty).
 *
 * \param empleado eEmpleado
 * \param cantidad int
 *
 */

void emp_removeEmployee(eEmpleado[], int);

/** \brief Funcion que ordena por apellido la lista de los empleados existentes.
 *
 * \param empleado eEmpleado
 * \param cantidad int
 *
 */

void emp_sortEmployees(eEmpleado[], int);

/** \brief Funcion que imprime la lista de los empleados que previamente fue ordenada y mostrara la suma de los salarios y promedio.
 *
 * \param empleado eEmpleado
 * \param cantidad int
 *
 */

void emp_printEmployees(eEmpleado[], int);
#endif
