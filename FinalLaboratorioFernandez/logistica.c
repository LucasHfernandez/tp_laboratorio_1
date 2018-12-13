#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "logistica.h"
#include "parser.h"


eLogica* logica_new()
{
   eLogica* this = malloc(sizeof(eLogica));

   return this;
}

eLogica* logica_newParametros(char* idUnoStr, char* idDosStr, char* nombreStr,char* destinoStr, char* kilometroStr, char* entregaStr)
{
    eLogica* newLogica;
    eLogica* returnLogica;
    int idUno;
    int idDos;
    int kilometros;
    int entregas;

    newLogica = logica_new();

    if(newLogica != NULL)
    {
        idUno = atoi(idUnoStr);
        idDos = atoi(idDosStr);
        kilometros = atoi(kilometroStr);
        entregas = atoi(entregaStr);

        if(logica_setIdEnvio(newLogica, idUno) == 1 &&
           logica_setIdCamion(newLogica, idDos) == 1 &&
           logica_setNombre(newLogica, nombreStr) == 1 &&
           logica_setDestino(newLogica, destinoStr) == 1 &&
           logica_setKilometros(newLogica, kilometros) == 1 &&
           logica_setEntrega(newLogica, entregas) == 1)
        {
            returnLogica = newLogica;
        }
    }

    return returnLogica;
}


int logica_setIdEnvio(eLogica* this,int envio)
{
    int retorno = 0;

    if(this != NULL && envio > 0)
    {
        this->tipoEntrega = envio;
        retorno = 1;
    }

    return retorno;
}

int logica_setIdCamion(eLogica* this,int camion)
{
    int retorno = 0;

    if(this != NULL && camion > -1)
    {
        this->tipoEntrega = camion;
        retorno = 1;
    }

    return retorno;
}

int logica_setNombre(eLogica* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombreProducto, nombre, sizeof(this->nombreProducto));
        retorno = 1;
    }

   return retorno;
}

int logica_setDestino(eLogica* this,char* destino)
{
    int retorno = 0;

    if(this != NULL && destino[0] != '\0')
    {
        strncpy(this->zonaDestino, destino, sizeof(this->zonaDestino));
        retorno = 1;
    }

   return retorno;
}

int logica_setKilometros(eLogica* this,int kilometros)
{
    int retorno = 0;

    if(this != NULL && kilometros > 0)
    {
        this->kilometros = kilometros;
        retorno = 1;
    }

    return retorno;
}

int logica_setEntrega(eLogica* this,int entrega)
{
    int retorno = 0;

    if(this != NULL && entrega > 0)
    {
        this->tipoEntrega = entrega;
        retorno = 1;
    }

    return retorno;
}

int logica_getIdEnvio(eLogica* this,int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->idEnvio;
        retorno = 1;
    }

   return retorno;
}

int logica_getIdCamion(eLogica* this,int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->idCamion;
        retorno = 1;
    }

   return retorno;
}

int logica_getNombre(eLogica* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombreProducto,sizeof(this->nombreProducto));
        retorno = 1;
    }

    return retorno;
}

int logica_getDestino(eLogica* this,char* destino)
{
    int retorno = 0;

    if(this != NULL && destino != NULL)
    {
        strncpy(destino,this->zonaDestino,sizeof(this->zonaDestino));
        retorno = 1;
    }

    return retorno;
}

int logica_getKilometros(eLogica* this,int* kilometros)
{
    int retorno = 0;

    if(this != NULL && kilometros != NULL)
    {
        *kilometros = this->kilometros;
        retorno = 1;
    }

   return retorno;
}

int logica_getEntrega(eLogica* this,int* entrega)
{
    int retorno = 0;

    if(this != NULL && entrega != NULL)
    {
        *entrega = this->tipoEntrega;
        retorno = 1;
    }

   return retorno;
}


int logica_controllerLogica(char* fileName, LinkedList* pArrayListLogica)
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

    if(pFile != NULL && parser_logicaFromText(pFile, pArrayListLogica) == 1)
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

void logica_logicaList(LinkedList* pArrayList)
{
    eLogica* auxLogica;
    int i;
    int idAuxEnvio;
    char nombreAux[2000];
    int idAuxCamion;
    char destinoAux[2000];
    int kilometroAux;
    int entregaAux;

    int cantidad;

    cantidad = ll_len(pArrayList);

    system("cls");
    printf("Lista de todos los envios.");
    printf("\n---------------------------------");

    if(pArrayList != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxLogica = ll_get(pArrayList, i);

              if(logica_getIdEnvio(auxLogica, &idAuxEnvio) == 1 &&
                 logica_getIdCamion(auxLogica, &idAuxCamion) == 1 &&
                 logica_getNombre(auxLogica, nombreAux) == 1 &&
                 logica_getDestino(auxLogica, destinoAux) == 1 &&
                 logica_getKilometros(auxLogica, &kilometroAux) == 1 &&
                 logica_getEntrega(auxLogica, &entregaAux) == 1)
            {
                printf("\nID del Envio: %d   Nombre del producto: %s   ID del camion: %d   Zona de destino: %s\n  Kilometros: %d  Tipo de Entrega: %d", idAuxEnvio,
                                                                                                                                                        nombreAux,
                                                                                                                                                        idAuxCamion,
                                                                                                                                                        destinoAux,
                                                                                                                                                        kilometroAux,
                                                                                                                                                        entregaAux);
                printf("-----------------------------------------------------------------------------------");
            }
        }

        system("pause");
    }
}


int logica_calcularCosto(LinkedList* pArrayLogica, int kilometros, int entregas)
{
    eLogica* auxLogica;
    int i;
    int auxKilometros;
    int auxEntrega;

    auxKilometros = logica_getKilometros((eLogica*))



}
