#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


int menuOpcion_getNumero(float, float, char*, char*);
/*Menu de inicio*/

float suma(float, float);
/** \brief Suma de dos valores.
 *
 * \param n°1 El primer numero  que se ingresa.
 * \param n°2 El segundo numero que se ingresa.
 * \return Devuelve la variable resultado, con la suma de ambos valores.
 *
 */

float resta(float, float);
/** \brief Resta de dos valores.
 *
 * \param n°1 El primer numero  que se ingresa.
 * \param n°2 El segundo numero que se ingresa.
 * \return Devuelve la variable resultado, con la resta de ambos valores.
 *
 */

float division_getFloat(float, float, char*);
/** \brief Division de dos valores.
 *
 * \param n°1 El primer numero  que se ingresa.
 * \param n°2 El segundo numero que se ingresa.
 * \return Devuelve la variable resultado, con la division de ambos valores.
 * En caso de error se mostrara un mensaje y retornara 0.
 */

float multiplicar(float, float);
/** \brief Multiplicacion de dos valores.
 *
 * \param n°1 El primer numero  que se ingresa.
 * \param n°2 El segundo numero que se ingresa.
 * \return Devuelve la variable resultado, con la multiplicacion de ambos valores.
 *
 */

int factores(int);
/** \brief Factorizacion de un valor.
 *
 * \param n°1 El primer numero  que se ingresa.
 * \param
 * \return Devuelve la variable resultado, con la factorizacion del valor ingresado.
 * En caso de que el valor sea 1 o 0, el resultado retornara un 1. Pero en caso de que
 * el valor sea un numero negativo, se mostrara un mensaje de error y retornara -1.
 */

#endif
