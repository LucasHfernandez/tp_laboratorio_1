#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile = fopen(path, "r");

    if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
    {
        printf("Datos cargados satisfactoriamente.");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf("Hubo un error en la carga.");
        system("pause");
    }

    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pBinFile;
    pBinFile = fopen(path, "rb");

    if(pBinFile != NULL && parser_EmployeeFromBinary(pBinFile, pArrayListEmployee) == 1)
    {
        printf("Datos cargados satisfactoriamente.");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf("Hubo un error en la carga.");
        system("pause");
    }

    fclose(pBinFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(employee_empAddNew(pArrayListEmployee) == 1)
    {
        printf("Los datos se guardaron correctamente n_n");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf("Los datos no pudieron ser guardados. :S");
        system("pause");
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    employee_empEdit(pArrayListEmployee);

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    employee_empRemove(pArrayListEmployee);

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_empList(pArrayListEmployee);

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_empOrderList, 1);
        printf("Los datos fueron ordenados por nombre, alfabeticamente.");
        system("pause");
        retorno = 1;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(employee_empSaveText(path, pArrayListEmployee) == 1)
    {
        printf("Los datos fueron guardados en texto n_n");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf("Los datos no pudieron ser guardados :S");
        system("pause");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(employee_empSaveBinari(path, pArrayListEmployee))
    {
        printf("Los datos fueron guardados en Binario n_n");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf("Los datos no pudieron ser guardados :S");
        system("pause");
    }

    return retorno;
}
