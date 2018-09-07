#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

/*La funcion menu, es el principio de toda la calculadora, donde se tomara los datos que ingrese el usuario para luego
realizar las diferentes tareas. La opcion que elija se mostrara en pantalla y en caso de error se le informara para que ingrese
nuevamente un nuevo valor.*/

int menuOpcion_getNumero(float operadorUno, float operadorDos, char* mensaje, char* mensajeErrorUno)
{
    int opcion;

    system("cls");
    printf("Bienvenido al Menu, que desea realizar?");
    printf("\n\n 1. Ingresar el Primer operando: (A = %.2f)", operadorUno);
    printf("\n 2. Ingresar el Segundo operando. (B = %.2f)", operadorDos);
    printf("\n 3. Calcular operaciones.");
    printf("\n 4. Informar Resultados.");
    printf("\n 5. Salir.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 5 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro numero: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

/*La funcion suma tomara los valores que ingreso el usuario y luego sumara dichos valores
y retornara el resultado.*/
float suma(float operadorUno, float operadorDos)
{
    float resultado;

    resultado = operadorUno + operadorDos;

    return resultado;
}

/*La funcion resta tomara los valores que ingreso el usuario y luego restara dichos valores
y retornara el resultado.*/
float resta(float operadorUno, float operadorDos)
{
    float resultado;

    resultado = operadorUno - operadorDos;

    return resultado;
}

/*La funcion multiplicar tomara los valores que ingreso el usuario y luego multiplicara dichos valores
y retornara el resultado.*/
float multiplicar(float operadorUno, float operadorDos)
{
    float resultado;

    resultado = operadorUno * operadorDos;

    return resultado;
}

/*La funcion division tomara los valores que ingreso el usuario y luego dividira dichos valores
y retornara el resultado. En caso de que el segundo numero tomado sea 0, se le informara mediante
un mensaje que no se puede dividir por 0*/
float division_getFloat(float operadorUno, float operadorDos, char* mensajeError)
{
    float resultado;

    if(operadorDos == 0)
    {
        printf(mensajeError);
        return 0;
    }

    resultado = operadorUno / operadorDos;

    return resultado;
}

/*La funcion factores tomara el primer o segundo valor que ingrese el usuario y luego factorizara dicho valor
y retornara el resultado. En caso de que el numero tomado sea 0 o 1, se le retornara un 1, y si el usuario
ingresa un numero negativo, se le dara un mensaje de error.*/
int factores(int operador)
{
    long int resultado;

    if(operador == 1 || operador == 0)
    {
        return 1;
    }
    else if(operador < 0)
    {
        printf("\n Error!! *-* no se puede factorizar un numero negativo.");
        return -1;
    }

    resultado = (int)operador * factores(operador-1);

    return resultado;
}
