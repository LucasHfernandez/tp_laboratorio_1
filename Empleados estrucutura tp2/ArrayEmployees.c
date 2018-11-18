#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

int emp_menuOpcion_getNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\tBienvenido al Menu, que desea realizar?");
    printf("\n\n1.Dar Alta Empleado.");
    printf("\n2.Modificar legajo.");
    printf("\n3.Dar Baja Empleado.");
    printf("\n4.Informes.");
    printf("\n5.Salir.");
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

void emp_initEmployees(eEmpleado empleado[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        empleado[i].isEmpty = 1;
    }
}

int emp_obtenerEspacioLibre(eEmpleado empleado[], int cantidad)
{
    int i, retorno = -1;

    for(i = 0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

/** \brief Generador de Id
 *
 * \return retorna el siguiente ID.
 *
 */

static int generador(void)
{
    static int id = -1;

    return ++id;
}

int emp_bloqueoCargaVacia(eEmpleado empleado[], int cantidad)
{
    int i;
    int flag;

    for(i = 0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

void emp_addEmployee(eEmpleado empleado[], int cantidad)
{
    int index;
    int opcion;

    do
    {
        index = emp_obtenerEspacioLibre(empleado, cantidad);

        if(index != -1)
        {
            empleado[index].id = generador();
            system("cls");

            printf("Alta De los empleados.");

            printf("\n\nIngrese el Apellido: ");
            fflush(stdin);

            fgets(empleado[index].apellido, sizeof(empleado[index].apellido)-2, stdin);
            cantidad = strlen(empleado[index].apellido);
            empleado[index].apellido[cantidad-1] = '\0';
            empleado[index].apellido[0] = toupper(empleado[index].apellido[0]);

            printf("\nIngrese el Nombre: ");

            fgets(empleado[index].nombre, sizeof(empleado[index].nombre)-2, stdin);
            cantidad = strlen(empleado[index].nombre);
            empleado[index].nombre[cantidad-1] = '\0';
            empleado[index].nombre[0] = toupper(empleado[index].nombre[0]);

            printf("\nSectores ");
            printf("\n1.RRHH");
            printf("\t\t2.Administracion");
            printf("\t\t3.Fabrica");
            printf("\n4.Ventas");
            printf("\t5.Tesoreria");
            printf("\n\nIndique el Sector: ");
            scanf("%d", &empleado[index].sector);

            printf("\nIngrese el Salario: ");
            scanf("%f", &empleado[index].salario);

            empleado[index].isEmpty = 0;

            printf("\nEl empleado fue dado de alta. n_n");
            system("pause");
        }

        printf("\n\nDesea ingresar un nuevo empleado? 1= SI 2= NO");
        printf("\nOpcion seleccionada: ");
        fflush(stdin);
        scanf("%d", &opcion);

    }while(opcion != 2);
}

void emp_modifyEmployee(eEmpleado empleado[], int cantidad)
{
    int i;
    int idAux;
    char nombreAux[200];
    char apellidoAux[200];
    int sectorAux;
    float salarioAux;
    int flag;
    int opcionA, opcionB;
    int opcionDos, opcionTres;

    do
    {
        flag = 0;
        system("cls");
        printf("Modificar datos.");
        printf("\n\nIngrese el ID del empleado que desea modificar");
        printf("\n\nID: ");
        scanf("%d", &idAux);

        for(i = 0; i < cantidad; i++)
        {
            if(empleado[i].isEmpty == 0)
            {
                if(idAux == empleado[i].id)
                {
                    flag = 1;
                    printf("\n\nDato Encontrado. n_n");
                    printf("\n\nID: %d - Apellido: %s - Nombre: %s - Sector: %d - Salario: %.2f", empleado[i].id,
                                                                                                  empleado[i].apellido,
                                                                                                  empleado[i].nombre,
                                                                                                  empleado[i].sector,
                                                                                                  empleado[i].salario);
                    printf("\n\nDesea modificar el registro? 1= SI 2= NO");
                    printf("\n\nOpcion Seleccionada: ");
                    fflush(stdin);
                    scanf("%d", &opcionA);

                    while(opcionA > 2 && opcionA < 1)
                    {
                        printf("\nError! No es un dato valido.");
                        printf("\nOpcion Seleccionada: ");
                        fflush(stdin);
                        scanf("%d", &opcionA);
                    }

                    if(opcionA == 1)
                    {
                        do
                        {
                            system("cls");
                            printf("Que datos desea modificar?");
                            printf("\n-------------------------------------------------------");
                            printf("\n\n1.Apellido anterior: %s", empleado[i].apellido);
                            printf("\n\n2.Nombre anterior: %s", empleado[i].nombre);
                            printf("\n\n3.Sector anterior: %d", empleado[i].sector);
                            printf("\n\n4.Salario anterior: %.2f", empleado[i].salario);
                            printf("\n\nOpcion Seleccionada: ");
                            fflush(stdin);
                            scanf("%d", &opcionDos);

                            switch(opcionDos)
                            {
                                case 1:
                                    system("cls");
                                    printf("Por Ingrese el nuevo apellido");
                                    printf("\n\nApellido: ");
                                    fflush(stdin);
                                    fgets(apellidoAux, sizeof(apellidoAux)-2, stdin);
                                    strcpy(empleado[i].apellido, apellidoAux);
                                    printf("\nEl dato fue modificado.");
                                    system("pause");
                                    break;
                                case 2:
                                    system("cls");
                                    printf("Por Ingrese el nuevo nombre");
                                    printf("\n\nNombre: ");
                                    fflush(stdin);
                                    fgets(nombreAux, sizeof(nombreAux)-2, stdin);
                                    strcpy(empleado[i].nombre, nombreAux);
                                    printf("\nEl dato fue modificado.");
                                    system("pause");
                                    break;
                                case 3:
                                    system("cls");
                                    printf("Por Ingrese el nuevo sector");
                                    printf("\nSectores ");
                                    printf("\n1.RRHH");
                                    printf("\t\t2.Administracion");
                                    printf("\t\t3.Fabrica");
                                    printf("\n4.Ventas");
                                    printf("\t5.Tesoreria");
                                    printf("\n\nSector: ");
                                    fflush(stdin);
                                    scanf("%d", &sectorAux);
                                    empleado[i].sector = sectorAux;
                                    printf("\nEl dato fue modificado.");
                                    system("pause");
                                    break;
                                case 4:
                                    system("cls");
                                    printf("Por Ingrese el nuevo salario");
                                    printf("\n\nSalario: ");
                                    fflush(stdin);
                                    scanf("%f", &salarioAux);
                                    empleado[i].salario = salarioAux;
                                    printf("\nEl dato fue modificado.");
                                    system("pause");
                                    break;
                            }

                        printf("\n\nDesea modificar otro dato? 1= SI 2= NO");
                        printf("\nOpcion seleccionada: ");
                        fflush(stdin);
                        scanf("%d", &opcionB);

                    }while(opcionB != 2);

                }
                else if(opcionA == 2)
                {
                    printf("\nLos datos no se modificaran ._.");
                    system("pause");
                }
                    break;
                }
            }
        }

    if(flag == 0)
    {
        printf("Dato inexistente...");
        system("pause");
    }

    printf("\n\nDesea ingresar un nuevo ID? 1= SI 2= NO");
    printf("\nOpcion seleccionada: ");
    fflush(stdin);
    scanf("%d", &opcionTres);

    }while(opcionTres != 2);
}

void emp_removeEmployee(eEmpleado empleado[], int cantidad)
{
    int i;
    int idAux;
    char opcionA;
    int flag;
    int opcionUno;

    do
    {
        flag = 0;
        system("cls");
        printf("Bajas de los Empleados.");
        printf("\n----------------------------------------");
        printf("\nIngrese el ID del empleado que desea dar de baja.");
        printf("\n\nID: ");
        fflush(stdin);
        scanf("%d", &idAux);

        for(i = 0; i < cantidad; i++)
        {
            if(empleado[i].isEmpty == 0)
            {
                if(idAux == empleado[i].id)
                {
                    flag = 1;
                    printf("\n\nDato Encontrado. n_n");
                    printf("\n\nID: %d - Apellido: %s - Nombre: %s - Sector: %d - Salario: %.2f", empleado[i].id,
                                                                                                  empleado[i].apellido,
                                                                                                  empleado[i].nombre,
                                                                                                  empleado[i].sector,
                                                                                                  empleado[i].salario);
                    printf("\n\nDesea eliminar el registro? S= SI N= NO");
                    printf("\n\nOpcion Seleccionada: ");
                    fflush(stdin);
                    scanf("%c", &opcionA);
                    opcionA = toupper(opcionA);

                    while(opcionA != 'S' && opcionA != 'N')
                    {
                        printf("\nError! No es un dato valido.");
                        printf("\nOpcion Seleccionada: ");
                        fflush(stdin);
                        scanf("%c", &opcionA);
                        opcionA = toupper(opcionA);
                    }

                    if(opcionA == 'S')
                    {
                        empleado[i].isEmpty = 1;
                        printf("El registro fue eliminado.");
                        system("pause");
                    }
                    else if(opcionA == 'N')
                    {
                        printf("El registro no sera eliminado ._.");
                        system("pause");
                    }

                    break;
                }
            }
        }

        if(flag == 0)
        {
            printf("Dato inexistente...");
            system("pause");
        }

        printf("\n\nDesea ingresar un nuevo ID? 1= SI 2= NO");
        printf("\nOpcion seleccionada: ");
        fflush(stdin);
        scanf("%d", &opcionUno);

    }while(opcionUno != 2);

}

void emp_sortEmployees(eEmpleado empleado[], int cantidad)
{
    eEmpleado empAux;
    int i, j;

    for(i = 0; i < cantidad; i++){
        for(j = i+1; j < cantidad; j++)
        {
            if(strcmp(empleado[i].apellido, empleado[j].apellido) > 0)
            {
                empAux = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = empAux;
            }
            else if(strcmp(empleado[i].apellido, empleado[j].apellido) == 0 && strcmp(empleado[i].nombre, empleado[j].nombre) > 0)
            {
                empAux = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = empAux;
            }
        }
    }
}

void emp_printEmployees(eEmpleado empleado[], int cantidad)
{
    int i;
    int flag = 0;
    int contadorPromedio = 0;
    int contadorMayorPromedio = 0;
    float promedio;
    float suma = 0;
    system("cls");
    printf("Lista de todos los Empleados.");
    printf("\n-----------------------------------------");

    emp_sortEmployees(empleado, cantidad);

    for(i = 0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            suma = suma + empleado[i].salario;
            printf("\nID: %d  -  Apellido: %s  -  Nombre: %s  -  Sector: %d  -  Salario: %.2f\n", empleado[i].id,
                                                                                                empleado[i].apellido,
                                                                                                empleado[i].nombre,
                                                                                                empleado[i].sector,
                                                                                                empleado[i].salario);
            printf("------------------------------------------------------------------------------------------------------------------------");
            contadorPromedio++;
        }
    }

    promedio = suma / contadorPromedio;

    for(i = 0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 0){
                if(empleado[i].salario >= promedio)
                {
                   contadorMayorPromedio++;
                   flag = 1;
                }
            }
    }

    printf("\n\n||La suma total de todos los salarios es: %.2f||", suma);
    printf("\n||El promedio total es: %.2f||", promedio);

    if(flag == 1)
    {
        printf("\n||La cantidad de empleados que superan el salario promedio es: %d||", contadorMayorPromedio);
    }
    else
    {
        printf("\n||No hay empleados que superen el salario promedio");
    }
    system("pause");
}
