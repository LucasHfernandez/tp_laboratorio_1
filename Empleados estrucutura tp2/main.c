#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define cant 1000


int main()
{
    int opcion, flag;
    eEmpleado empleado[cant];

    emp_initEmployees(empleado, cant);

    do
    {

        opcion = emp_menuOpcion_getNumero(opcion, "\n\nOpcion Seleccionada: ", "\nError! *-* No es un dato valido.");
        flag = emp_bloqueoCargaVacia(empleado, cant);

        switch(opcion)
        {
        case 1:
            emp_addEmployee(empleado, cant);
            break;
        case 2:
            if(flag == 1)
            {
                emp_modifyEmployee(empleado, cant);
            }
            else
            {
                printf("\nNo hay datos para modificar.");
                system("pause");
            }
            break;
        case 3:
            if(flag == 1)
            {
                emp_removeEmployee(empleado, cant);
            }
            else
            {
                printf("\nNo hay datos para borrar.");
                system("pause");
            }
            break;
        case 4:
            if(flag == 1)
            {
                emp_printEmployees(empleado, cant);
            }
            else
            {
                printf("\nNo hay datos para Informar.");
                system("pause");
            }
            break;
        case 5:
            printf("Adios! n_n");
            break;
        }

    }while(opcion != 5);

    return 0;
}
