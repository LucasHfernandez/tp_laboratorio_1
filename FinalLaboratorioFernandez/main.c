#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "logistica.h"

int main()
{
    int option;
    LinkedList* listaLogistica = ll_newLinkedList();

    do{

        option = utn_menuGetNumero(option, "\n\nOpcion seleccionada: ", "Error! *-* No es un dato valido.");

        switch(option)
        {
            case 1:
               logica_controllerLogica("DATA_2F.CSV", listaLogistica);
                break;
            case 2:
                logica_logicaList(listaLogistica);
                break;
            /*case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;*/
            case 6:
                printf("Adios! n_n");
                break;
        }
    }while(option != 6);

    return 0;
}
