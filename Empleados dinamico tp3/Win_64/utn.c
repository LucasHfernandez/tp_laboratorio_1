#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int utn_menuGetNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\t\t\t Bienvenido al Menu, que desea realizar?");
    printf("\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n 3. Alta de empleado");
    printf("\n 4. Modificar datos de empleado");
    printf("\n 5. Baja de empleado");
    printf("\n 6. Listar empleados");
    printf("\n 7. Ordenar empleados");
    printf("\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
    printf("\n 10. Salir.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 10 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro numero: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

