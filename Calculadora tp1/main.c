#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
int main()
{
    float numeroUno = 0, numeroDos = 0;
    int opcion;
    int resultadoFactorUno, resultadoFactorDos;
    float resultadoSuma, resultadoResta, resultadoMult, resultadoDiv;
    char opcionDos;

    do
    {
        opcion = menuOpcion_getNumero(numeroUno, numeroDos, "\n\n Opcion seleccionada: ", "\n Error *-* no es una opcion!");

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("Ingrese el primer operando: ");
            fflush(stdin);
            scanf("%f", &numeroUno);
            break;
        case 2:
            system("cls");
            printf("Ingrese el segundo operando: ");
            fflush(stdin);
            scanf("%f", &numeroDos);
            break;
        case 3:
            resultadoSuma = suma(numeroUno, numeroDos);
            resultadoResta = resta(numeroUno, numeroDos);
            resultadoMult = multiplicar(numeroUno, numeroDos);
            resultadoDiv = division_getFloat(numeroUno, numeroDos, "\n Error! *-* No es posible dividir por cero");
            resultadoFactorUno = factores(numeroUno);
            resultadoFactorDos = factores(numeroDos);

            printf("\n\n\n Calculos realizados con exito! n_n     ");

            system("pause");
             break;
        case 4:
            system("cls");
            printf("Resultados:");
            printf("\n\n El resultado de A+B es: %.2f", resultadoSuma);
            printf("\n El resultado de A-B es: %.2f", resultadoResta);
            printf("\n El resultado de A/B es: %.2f", resultadoDiv);
            printf("\n El resultado de A*B es: %.2f", resultadoMult);
            printf("\n El factorial de A es: %d y El factorial de B es: %d", resultadoFactorUno, resultadoFactorDos);
            printf("\n\n Desea Empezar de nuevo? (s/n) ^.^ ... ");
            fflush(stdin);
            scanf("%c", &opcionDos);

            if(opcionDos == 'n')
            {
                printf("\n Adios! n_n");
                return 0;
            }
            break;
        case 5:
            printf("\n Adios! n_n");
            break;
        }

    }while(opcion != 5);

    return 0;
}
