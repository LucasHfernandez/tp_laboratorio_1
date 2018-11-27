#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "employee.h"

/* Menu de opciones que retornara la opcion que elija el usuario,
    validando que no coloque un numero que no este en la lista*/
int emp_menuGetNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\t\t Bienvenido al Menu, que desea realizar?");
    printf("\n\n 1. Abrir y Leer archivos.");
    printf("\n 2. Calcular sueldos.");
    printf("\n 3. Generar archivos/actualizar.");
    printf("\n 4. Listar empleados.");
    printf("\n 5. Salir");
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

eEmpleado* employee_new()
{
   eEmpleado* this = malloc(sizeof(eEmpleado));

   return this;
}

eEmpleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    eEmpleado* empNew;
    eEmpleado* returnEmp;
    int id, horasTrabajadas;
    empNew = employee_new();

    if(empNew != NULL)
    {
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);

        if(emp_setId(empNew, id) == 1 &&
           emp_setNombre(empNew, nombreStr) == 1 &&
           emp_setHorasTrabajadas(empNew, horasTrabajadas) == 1)
        {
            returnEmp = empNew;
        }
    }

    return returnEmp;
}


/*Abre el archivo si el usuario ingreso el mismo nombre,
    luego llama a la funcion parser para leer todo el archivo*/
int emp_controllerEmp(char* fileName, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char auxFileName[1000];
    FILE* pFile;

    system("cls");
    printf("Ingrese el nombre del archivo que desea leer.");
    printf("\n\nNombre: ");
    fflush(stdin);
    fgets(auxFileName, sizeof(auxFileName)-2, stdin);

    while(strncmp(auxFileName, fileName, 1) != 0)
    {
        printf("\nError, no existe el archivo.");
        printf("\nVuelva a ingresar un nuevo nombre: ");
        fflush(stdin);
        fgets(auxFileName, sizeof(auxFileName)-2, stdin);
    }

    pFile = fopen(fileName, "r");

    if(pFile != NULL && emp_parserEmpleados(pArrayListEmployee, pFile) == 1)
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


/*Parseo de la lista de empleados que pertenecen al archivo*/
int emp_parserEmpleados(LinkedList* listaEmpleados, FILE* pFile)
{
    char idAux[1000];
    char nombreAux[1000];
    char horasAux[1000];
    eEmpleado* employeeAux;
    int r;
    int retorno = 0;

    r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux);

    while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux);

            if(r == 3)
            {
                employeeAux = employee_newParametros(idAux, nombreAux, horasAux);
                if(employeeAux != NULL)
                {
                    ll_add(listaEmpleados, employeeAux);
                    retorno = 1;
                }
            }
        }

    return retorno;
}

void emp_listEmp(LinkedList* listaEmpleados)
{
    eEmpleado* auxEmployee;
    int i;
    int auxId, auxHoras;
    char auxNombre[1000];
    int cantidad;

    cantidad = ll_len(listaEmpleados);

    system("cls");
    printf("Lista de todos los empleados.");
    printf("\n---------------------------------");

    if(listaEmpleados != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = ll_get(listaEmpleados, i);

            if(emp_getId(auxEmployee, &auxId) == 1 &&
                emp_getNombre(auxEmployee, auxNombre) == 1 &&
                emp_getHorasTrabajadas(auxEmployee, &auxHoras) == 1)
            {
                printf("\nID: %d   Nombre: %s   Horas Que Trabaja: %d \n", auxId, auxNombre, auxHoras);
                printf("-----------------------------------------------------------------------------");
            }
        }

        system("pause");
    }
}

int emp_calculoSueldo(eEmpleado* employee, int* horas)
{
    int retorno = 0;
    int auxHoras;

    auxHoras = emp_getHorasTrabajadas((eEmpleado*)horas,(int*)auxHoras);

    if(auxHoras > 0 && auxHoras <= 176)
    {
        employee->sueldo = 180;
        retorno = 1;
    }

    if(auxHoras >= 177 && auxHoras <= 208)
    {
        employee->sueldo = 270;
        retorno = 2;
    }

    if(auxHoras >= 209 && auxHoras <= 240)
    {
        employee->sueldo = 360;
        retorno = 3;
    }

    return retorno;
}


int emp_controllerSueldo(LinkedList* listaEmpleado)
{
    int retorno = 0;

    if(listaEmpleado != NULL)
    {
        ll_map(listaEmpleado, emp_calculoSueldo);
        printf("Los datos fueron calculados correctamente.");
        system("pause");
        retorno = 1;
    }

    return retorno;
}

int emp_empSaveText(char* fileName, LinkedList* pArrayList)
{
    int i, cantidad, retorno = 0;
    FILE* pFile;
    eEmpleado* auxEmployee;

    pFile = fopen(fileName, "w");
    cantidad = ll_len(pArrayList);

    if(pFile != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = ll_get(pArrayList, i);
            fprintf(pFile, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        }

        retorno = 1;
    }

    fclose(pFile);

    return retorno;
}


int emp_empSaveBinari(char* fileName, LinkedList* pArrayList)
{
    int i, cantidad, retorno = 0;
    FILE* pBinFile;
    eEmpleado* auxEmployee;

    pBinFile = fopen(fileName, "wb");
    cantidad = ll_len(pArrayList);

    if(pBinFile != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = ll_get(pArrayList, i);
            fwrite(auxEmployee,sizeof(eEmpleado),1,pBinFile);
        }

        retorno = 1;
    }

    fclose(pBinFile);

    return retorno;
}


int emp_controller_saveAsText(char* fileName , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(emp_empSaveText(fileName, pArrayListEmployee) == 1)
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

int emp_controller_saveAsBinary(char* fileName , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(emp_empSaveBinari(fileName, pArrayListEmployee) == 1)
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


//setters

int emp_setId(eEmpleado* this,int id)
{
    int retorno = 0;
    static int nextId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            nextId++;
            this->id = nextId;
            retorno = 1;
        }else if(id > nextId)
        {
            nextId = id;
            this->id = nextId;
            retorno = 1;
        }
    }
    return retorno;
}

int emp_setNombre(eEmpleado* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 1;
    }

   return retorno;
}

int emp_setHorasTrabajadas(eEmpleado* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}


int emp_setSueldo(eEmpleado* this,int sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;
}


//getters

int emp_getId(eEmpleado* this,int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

   return retorno;
}

int emp_getNombre(eEmpleado* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 1;
    }

    return retorno;
}

int emp_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

   return retorno;
}

int emp_getSueldo(eEmpleado* this,int* sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

   return retorno;
}
