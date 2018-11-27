#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[53];
    int horasTrabajadas;
    int sueldo;
}eEmpleado;

//funciones emp.
int emp_menuGetNumero(int opcion, char* mensaje, char* mensajeErrorUno);
int emp_parserEmpleados(LinkedList* listaEmpleados, FILE* pFile);
int emp_controllerEmp(char* fileName, LinkedList* pArrayListEmployee);
eEmpleado* employee_new();
eEmpleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void emp_listEmp(LinkedList* listaEmpleados);
int emp_calculoSueldo(eEmpleado* employee, int* horas);
int emp_controllerSueldo(LinkedList* listaEmpleado);
int emp_empSaveText(char* fileName, LinkedList* pArrayList);
int emp_empSaveBinari(char* fileName, LinkedList* pArrayList);
int emp_controller_saveAsText(char* fileName , LinkedList* pArrayListEmployee);
int emp_controller_saveAsBinary(char* fileName , LinkedList* pArrayListEmployee);


//setters
int emp_setId(eEmpleado* this,int id);
int emp_setNombre(eEmpleado* this,char* nombre);
int emp_setHorasTrabajadas(eEmpleado* this,int horasTrabajadas);
int emp_setSueldo(eEmpleado* this,int sueldo);


//getters
int emp_getId(eEmpleado* this,int* id);
int emp_getNombre(eEmpleado* this,char* nombre);
int emp_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas);
int emp_getSueldo(eEmpleado* this,int* sueldo);

#endif // employee_H_INCLUDED
