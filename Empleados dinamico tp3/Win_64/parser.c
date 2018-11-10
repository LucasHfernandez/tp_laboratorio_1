#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char idAux[2000];
    char nombreAux[2000];
    char horasAux[2000];
    char sueldoAux[2000];
    Employee* employeeAux;
    int r, retorno = 0;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux);

    while(!feof(pFile))
    {
         r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux);

          if(r == 4)
          {
              employeeAux = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
                if(employeeAux != NULL)
                {
                    ll_add(pArrayListEmployee, employeeAux);
                    retorno = 1;
                }
          }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* employeeAux;
    int cant, retorno = 0;

    while(!feof(pFile))
    {
        employeeAux = employee_new();
        cant = fread(employeeAux, sizeof(Employee), 1, pFile);

        if(employeeAux != NULL && cant == 1)
        {
            ll_add(pArrayListEmployee, employeeAux);
            retorno = 1;
        }
    }

    return retorno;
}
