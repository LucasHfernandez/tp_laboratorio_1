#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "employee.h"


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = emp_menuGetNumero(option, "\n\nOpcion Seleccionada: ", "\nError! No es un dato valido.");

        switch(option)
        {
            case 1:
                emp_controllerEmp("dataCorto.csv", listaEmpleados);
                break;
            case 2:
                emp_controllerSueldo(listaEmpleados);
                break;
            case 3:
                emp_controller_saveAsText("dataCorto.csv", listaEmpleados);
                emp_controller_saveAsBinary("dataCorto.bin", listaEmpleados);
                break;
            case 4:
                emp_listEmp(listaEmpleados);
                break;
            case 5:
                printf("Adios!");
                break;
        }

    }while(option != 5);

    return 0;
}
