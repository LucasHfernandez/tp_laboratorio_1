#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int utn_menuGetNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\t\t\t Bienvenido al Menu, que desea realizar?");
    printf("\n\n 1. Cargar archivo.");
    printf("\n 2. Imprimir Envios.");
    printf("\n 3. Calcular costos.");
    printf("\n 4. Generar archivo de costos para zona.");
    printf("\n 5. Imprimir lista de zonas.");
    printf("\n 6. Salir.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 6 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro numero: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

